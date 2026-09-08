"""Persistent local Lean process. Stream every completed repetition to disk."""
import json
import resource
import select
import subprocess
import time

from common import ROOT,HERE


class WorkerFailure(RuntimeError): pass


class Worker:
    def __init__(self,lean,env,log,cfg,worker_path=None):
        self.log=log.open('w');self.buffer=b'';self.peak_kib=0;self.last_check=0
        self.limit=cfg['worker_rss_limit_mib']*1024
        def limits():
            _,hard=resource.getrlimit(resource.RLIMIT_STACK)
            value=cfg['worker_stack_limit_mib']*1024*1024
            resource.setrlimit(resource.RLIMIT_STACK,(min(value,hard) if hard>=0 else value,hard))
        self.p=subprocess.Popen([lean,'--run',str(worker_path or HERE/'Worker.lean')],cwd=ROOT,env=env,
            stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=self.log,preexec_fn=limits)
        try: assert self.read(time.monotonic()+60).get('ready')
        except BaseException:self.close();raise

    def read(self,deadline):
        while True:
            if time.monotonic()-self.last_check>=0.25:
                self.last_check=time.monotonic()
                p=subprocess.run(['ps','-o','rss=','-p',str(self.p.pid)],capture_output=True,text=True)
                if p.returncode and self.p.poll() is None:raise WorkerFailure('RSS monitoring unavailable: '+p.stderr)
                if p.stdout.strip():
                    rss=int(p.stdout.strip());self.peak_kib=max(self.peak_kib,rss)
                    if rss>self.limit:raise WorkerFailure(f'sampled_RSS_limit_kib_{rss}')
            if b'\n' in self.buffer:
                line,self.buffer=self.buffer.split(b'\n',1)
                return json.loads(line)
            if time.monotonic()>=deadline:raise WorkerFailure('request_timeout')
            if select.select([self.p.stdout],[],[],min(.1,max(0,deadline-time.monotonic())))[0]:
                chunk=self.p.stdout.read1(65536)
                if not chunk:raise WorkerFailure('worker_exit_'+str(self.p.poll()))
                self.buffer+=chunk

    def request(self,request,timeout=60,on_event=None):
        start=time.monotonic()
        self.p.stdin.write((json.dumps(request)+'\n').encode());self.p.stdin.flush()
        events=[]
        while True:
            event=self.read(start+timeout)
            if on_event:on_event(event)
            if event.get('event')=='done':
                result=event['result']
                if 'error' in result:raise WorkerFailure(result['error'])
                return result,events
            assert event.get('event')=='sample',event
            events.append(event)

    def configure(self,policies):
        result,_=self.request(dict(cmd='configure',policies=[dict(name=name,policy=p) for name,p in policies.items()]))
        assert result['configured']==len(policies)

    def close(self):
        if self.p.poll() is None:
            self.p.terminate()
            try:self.p.wait(timeout=2)
            except subprocess.TimeoutExpired:self.p.kill();self.p.wait()
        self.log.close()
