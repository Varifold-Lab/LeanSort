"""Local CPU worker with retained stderr, request deadlines and sampled RSS cap."""
import json
import resource
import select
import subprocess
import time

from data_protocol import ROOT
from proofs import HERE


class WorkerFailure(RuntimeError):
    pass


class Worker:
    def __init__(self,lean,env,log,config,startup_timeout=45):
        self.log=log.open('w')
        self.limit=config['worker_rss_limit_mib']*1024
        self.peak_kib=0
        self.last_check=0
        self.buffer=b''
        def limits():
            _,hard=resource.getrlimit(resource.RLIMIT_STACK)
            soft=config['worker_stack_limit_mib']*1024*1024
            resource.setrlimit(resource.RLIMIT_STACK,(min(soft,hard) if hard>=0 else soft,hard))
        self.p=subprocess.Popen([lean,'--run',str(HERE/'Worker.lean')],cwd=ROOT,env=env,
            stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=self.log,preexec_fn=limits)
        try:
            if not self.read(startup_timeout).get('ready'):
                raise WorkerFailure('bad greeting')
        except BaseException:
            self.close()
            raise

    def rss(self):
        if time.monotonic()-self.last_check<0.25: return
        self.last_check=time.monotonic()
        p=subprocess.run(['ps','-o','rss=','-p',str(self.p.pid)],text=True,capture_output=True)
        if p.returncode and self.p.poll() is None:
            raise WorkerFailure('RSS monitoring unavailable: '+p.stderr)
        value=p.stdout.strip()
        if value:
            self.peak_kib=max(self.peak_kib,int(value))
            if int(value)>self.limit: raise WorkerFailure('sampled_RSS_limit_kib_'+str(value))

    def read(self,timeout):
        deadline=time.monotonic()+timeout
        while True:
            self.rss()
            if b'\n' in self.buffer:
                line,self.buffer=self.buffer.split(b'\n',1)
                return json.loads(line)
            if time.monotonic()>=deadline: raise WorkerFailure('request_timeout')
            if select.select([self.p.stdout],[],[],min(0.1,max(0,deadline-time.monotonic())))[0]:
                chunk=self.p.stdout.read1(65536)
                if not chunk: raise WorkerFailure('worker_exit_'+str(self.p.poll()))
                self.buffer+=chunk

    def request(self,request,timeout):
        self.p.stdin.write((json.dumps(request)+'\n').encode())
        self.p.stdin.flush()
        response=self.read(timeout)
        if 'error' in response: raise WorkerFailure('worker_error: '+response['error'])
        return response

    def close(self):
        if self.p.poll() is None:
            self.p.terminate()
            try: self.p.wait(timeout=2)
            except subprocess.TimeoutExpired:
                self.p.kill();self.p.wait()
        self.log.close()
