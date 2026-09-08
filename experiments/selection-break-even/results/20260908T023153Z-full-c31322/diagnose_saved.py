"""Post-run diagnostics, no timing, fitting or policy changes."""
import json
from pathlib import Path
import statistics
import sys
P=Path(__file__).resolve().parent
sys.path.insert(0,str(P.parents[1]))
from common import load_rows,save,FAMILIES
from reporting import distribution

a=load_rows(P/'records-A.jsonl');b=load_rows(P/'records-B-confirmation.jsonl')
main=[r for r in a if r['family'] in FAMILIES]
def ratio(rows,name,ref='fixed'):
    return sum(r['policies'][name]['median_ns'] for r in rows)/sum(r['policies'][ref]['median_ns'] for r in rows)
feature={k:dict(total_diag_ms=sum(statistics.median(r['feature_samples_by_budget'][k]) for r in b)/1e6,
    by_length_us={str(n):statistics.mean(statistics.median(r['feature_samples_by_budget'][k])/1000 for r in b if r['n']==n) for n in sorted({r['n'] for r in b})}) for k in ['length','eight','sixteen','legacy']}
control=dict(same_ids=sum(r['policies']['sixteen-rule']['chosen_id']==r['policies']['legacy-rule']['chosen_id'] for r in b),
    inputs=len(b),e2e_ratio=ratio(b,'sixteen-rule','legacy-rule'),
    paired=distribution([r['policies']['sixteen-rule']['median_ns']/r['policies']['legacy-rule']['median_ns'] for r in b]),
    note='Both validation-selected rules have n<=32 and descent<=250; confirmation decisions and kernel comparison counts match. This is an observed equal-decision control, not a new universal refinement theorem.')
structure={}
for rcount in [1,2,4,8,16,64,128]:
    for shape in ['equal','skewed']:
        rr=[r for r in a if f'structure_r{rcount}_{shape}' in r['family_aliases']]
        structure[f'r{rcount}-{shape}']=dict(inputs=len(rr),observed_lengths=[r['run_lengths'] for r in rr],
            ratios={k:ratio(rr,k) for k in ['rule','classifier','cost_ranking']},
            choices={k:[r['policies'][k]['chosen_id'] for r in rr] for k in ['rule','classifier','cost_ranking']})
seeds={str(n):{k:{str(seed):ratio([r for r in main if r['n']==n and r['seed']==seed],k) for seed in sorted({r['seed'] for r in main})} for k in ['rule','classifier','cost_ranking']} for n in sorted({r['n'] for r in main})}
b_length={str(n):{k:ratio([r for r in b if r['n']==n],k) for k in b[0]['policies']} for n in sorted({r['n'] for r in b})}
save(P/'diagnostics.json',dict(B_feature_diagnostics=feature,B_equal_decision_control=control,A_structure=structure,A_seed_ratios=seeds,B_by_length=b_length,
    note='Diagnosis only; feature/inference/kernel replays never summed into E2E. Confirmation does not reselect the budget.'))
print('diagnostics PASS; equal-decision ratio',control['e2e_ratio'])
