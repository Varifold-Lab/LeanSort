"""Syntactic code-generation checks; not a verified compiler or machine model."""
import re


def functions(source):
    result={}
    for match in re.finditer(r'(?:LEAN_EXPORT |static )?(?:lean_object\*|uint8_t) ([A-Za-z0-9_]+)\([^;{}]*\)\s*\{',source):
        start=match.end()-1
        depth=1
        end=start+1
        while depth and end<len(source):
            depth+=(source[end]=='{')-(source[end]=='}')
            end+=1
        result[match.group(1)]=source[start:end]
    return result


def body(source, suffix):
    hits=[b for name,b in functions(source).items() if name.endswith(suffix)]
    if len(hits)!=1:
        raise ValueError(f'expected exactly one function: {suffix}, got {len(hits)}')
    return hits[0]


def timer_audit(source):
    bodies={}
    for name,operation in [('Reference','RunAdaptive_Strategy_program'),
                           ('Counted','Direct_runCounted'),('Plain','Direct_run___'),
                           ('Staged','Direct_staged')]:
        b=body(source,'DirectExperiment_timed'+name)
        clocks=[m.start() for m in re.finditer('lean_io_mono_nanos_now\\(',b)]
        ops=['lean_st_ref_get(',operation,'DirectExperiment_checksum(','lean_st_ref_set(']
        positions=[b.index(op) for op in ops]
        sinks=[m.start() for m in re.finditer('lean_st_ref_set\\(',b)]
        if len(clocks)!=2 or len(sinks)!=2 or positions!=sorted(positions) or not (
            clocks[0]<positions[0] and max(positions+sinks)<clocks[1]):
            raise ValueError('timer placement: '+name)
        if name=='Plain' and any(x in b for x in ['runCounted','Program_eval','TimeM']):
            raise ValueError('counted path inside plain timer')
        bodies[name]=b
    return bodies


def executor_audit(executor, engine):
    saved={}
    for name,core in [('scan','discover'),('merge','merge'),('tree','tree'),('run','strategy')]:
        b=body(executor,'Direct_'+name+'___redArg')
        assert 'Direct_plainCompare___boxed' in b and 'Direct_Engine_'+core in b
        assert 'Direct_scan___redArg___closed__9' in b
        assert not any(x in b for x in ['Counted','TimeM','Program_eval','Program_bind'])
        saved[name]=b
        c=body(executor,'Direct_'+name+'Counted___redArg')
        assert 'Direct_countedCompare___boxed' in c and 'Direct_Engine_'+core in c
        assert 'Direct_scanCounted___redArg___closed__2' in c
        saved[name+'Counted']=c
    # The selected plain dictionary's transitive closed constants are all Id methods.
    constants=[line for line in executor.splitlines() if 'static const' in line and
               'Direct_scan___redArg___closed__' in line and '_value =' in line]
    assert len(constants)==10 and sum('Id_instMonad' in line for line in constants)==7
    assert not any('TimeM' in line or 'Counted' in line for line in constants)
    plain=body(engine,'Direct_plainCompare___redArg')
    counted=body(engine,'Direct_countedCompare___redArg')
    assert 'lean_alloc_ctor' not in plain and 'lean_nat_add' not in plain
    assert 'lean_alloc_ctor(0, 2, 0)' in counted and 'lean_unsigned_to_nat(1u)' in counted
    generic={n:b for n,b in functions(engine).items() if 'Direct_Engine_' in n}
    assert generic
    assert not any(x in b for b in generic.values() for x in ['Comparison_Program','TimeM','countedCompare'])
    return dict(bodies=saved,plain_dictionary=constants,plain_compare=plain,counted_compare=counted,
                generic_functions=len(generic),ordinary_closures_remain=any('lean_alloc_closure' in b for b in generic.values()))


def specialized_plain_audit(worker):
    selected={n:b for n,b in functions(worker).items() if 'Direct_run___at___00DirectExperiment_timedPlain' in n}
    assert selected, 'missing actual plain deployment specializations'
    assert not any(x in b for b in selected.values() for x in ['TimeM','Comparison_Program','lean_alloc_closure','lean_apply_'])
    # Constant deduplication may name a shared EMPTY array after the counted
    # function which first introduced it. Verify its initializer, not its name.
    reused=set(re.findall(r'\b\w*runCounted\w*\b','\n'.join(selected.values())))
    for symbol in reused:
        assert '___closed__' in symbol
        lines=[line for line in worker.splitlines() if 'static const lean_array_object '+symbol+'_value =' in line]
        assert len(lines)==1 and '.m_size = 0' in lines[0] and '.m_capacity = 0' in lines[0]
    assert any('lean_nat_dec_le' in b for b in selected.values())
    return dict(functions=len(selected),no_TimeM_or_Program=True,no_dynamic_apply_or_closure_alloc_in_these_bodies=True,bodies=selected)


def audit(worker, executor, engine):
    return dict(specialized_plain=specialized_plain_audit(worker),timer_bodies=timer_audit(worker),executor=executor_audit(executor,engine),
                scope='C emitted from checked Lean source: syntactic regression/inspection only; timed backend is lean --run, not native C')
