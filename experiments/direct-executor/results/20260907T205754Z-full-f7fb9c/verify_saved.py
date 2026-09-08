"""Post-run read-only revalidation; writes a separate audit, never new timings."""
from collections import Counter
import hashlib
import json
from pathlib import Path
import sys

DIRECT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(DIRECT))
from data_protocol import config,variants,evaluate,discover
from proofs import ROOT,hashes,save
from run import validate

D=Path(__file__).resolve().parent
cfg=config()
frozen=json.loads((D/'frozen.json').read_text())
assert hashes()==frozen['sources'] and cfg==frozen['config']
original=[]
for line in (D/'original-files.sha256').read_text().splitlines():
    digest,path=line.split('  ',1)
    assert hashlib.sha256((ROOT/path).read_bytes()).hexdigest()==digest,path
    original.append(path)
assert len(original)==354
rows=[]
sets={}
repetitions=0
for stage,count in [('paired',98),('confirmation',90),('extension',9)]:
    cases=[json.loads(line) for line in (D/f'dataset-{stage}.jsonl').read_text().splitlines()]
    assert len(cases)==count
    case_map={c['id']:c for c in cases}
    assert len(case_map)==count
    sets[stage]={c['input_sha256'] for c in cases}
    records=[json.loads(line) for line in (D/f'observations-{stage}.jsonl').read_text().splitlines()]
    if stage!='extension': assert len(records)==count
    else: assert len(records)==135
    seen=set()
    for record in records:
        case=case_map[record['case_id']]
        req=record['request']
        assert req['input']==case['input'] and req['expected']==sorted(case['input'])
        selected=[tuple(pair) for pair in req['variants']]
        for selected_pair in selected:
            key=(case['id'],selected_pair)
            assert key not in seen
            seen.add(key)
        if stage!='extension': assert selected==variants()
        refs={s:evaluate(s,case['input']) for s in dict.fromkeys(s for s,_ in selected)}
        assert req['expected_costs']==[refs[s]['comparisons'] for s,_ in selected]
        if 'response' in record:
            rows+=validate(case,record['response'],selected,req['rounds'],refs,stage!='extension')
            repetitions+=sum(len(m['samples_ns']) for m in record['response']['measurements'])
        else:
            assert stage=='extension' and record['status']['status']!='ok'
    assert len(seen)==(count*23 if stage!='extension' else 135)
assert not sets['paired']&sets['confirmation']
assert rows==json.loads((D/'rows.json').read_text())
old=[json.loads(line) for line in (ROOT/cfg['paired_data']).read_text().splitlines()]
new=[json.loads(line) for line in (D/'dataset-paired.jsonl').read_text().splitlines()]
assert [(c['id'],c['input']) for c in old]==[(c['id'],c['input']) for c in new]
expected={'merge':58166,'hybrid_8':58471,'fixed_four':54730,'runs_count':49887,'runs_length':47797}
actual={s:sum(r['comparisons'] for r in rows if r['stage']=='paired' and r['strategy']==s and r['mode']=='counted') for s in expected}
assert actual==expected
extension_status=json.loads((D/'extension-status.json').read_text())
assert len(extension_status)==135
status_counts=dict(Counter(r['status'] for r in extension_status))
assert status_counts=={'ok':98,'request_timeout':22,'not_run_total_budget':15}
summary={}
for n in cfg['extension_sizes']:
    er=[r for r in rows if r['stage']=='extension' and r['n']==n]
    complete=[case for case in dict.fromkeys(r['case_id'] for r in er) if sum(r['case_id']==case for r in er)==15]
    summary[n]=dict(complete_input_ids=complete,
        times_ms=None if not complete else {s:{m:sum(r['median_ns'] for r in er if r['case_id'] in complete and r['strategy']==s and r['mode']==m)/1e6 for m in cfg['primary_modes']} for s in cfg['strategies']})
save(D/'extension-pairing-explicit.json',summary)
save(D/'postrun-audit.json',dict(passed=True,original_files_unchanged=len(original),
    frozen_sources_and_config_unchanged=True,saved_rows_reconstructed=len(rows),
    complete_returned_timing_repetitions=repetitions,paired_counts_match_previous_phase=actual,
    independent_confirmation_no_input_overlap=True,extension_status_counts=status_counts,
    extension_empty_pairings_are_missing_not_zero=True,
    timeout_partial_round_times_unavailable=True))
print('post-run audit passed:',len(rows),'rows;',repetitions,'returned repetitions; 354 original files unchanged')
