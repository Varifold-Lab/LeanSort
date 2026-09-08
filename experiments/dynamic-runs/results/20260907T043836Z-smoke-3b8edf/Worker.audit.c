// Lean compiler output
// Module: experiments.«dynamic-runs».Worker
// Imports: public import Init public meta import Init public import LeanSort.Verification.RunAdaptive.Strategy public import Lean
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
lean_object* lean_io_mono_nanos_now();
lean_object* lean_st_ref_get(lean_object*);
lean_object* l_LeanSort_RunAdaptive_Strategy_program___redArg(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* lean_st_ref_set(lean_object*, lean_object*);
uint8_t l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
lean_object* l_List_drop___redArg(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* l_LeanSort_RunAdaptive_discover___redArg(lean_object*);
lean_object* l_LeanSort_RunAdaptive_MergeTree_budget___redArg(lean_object*);
lean_object* l_LeanSort_RunAdaptive_MergeTree_weight___redArg(lean_object*);
lean_object* l_LeanSort_RunAdaptive_MergeTree_program___redArg(lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* l_List_foldl___at___00Array_appendList_spec__0___redArg(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_CostedPlan_Cut_position(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_ComparisonSort_checkSorted___redArg(lean_object*);
lean_object* lp_leansort_LeanSort_CostedPlan_Schema_upper(lean_object*, lean_object*);
lean_object* l_LeanSort_RunAdaptive_upper(lean_object*, lean_object*);
lean_object* l_LeanSort_RunAdaptive_lengthPlan___redArg(lean_object*);
lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonStackTable_fromJson_spec__0_spec__0(lean_object*);
lean_object* l_Lean_JsonNumber_fromNat(lean_object*);
lean_object* l_Lean_Option_toJson___at___00Lean_Json_toStructured_x3f___at___00Lean_Server_FileWorker_sendServerRequest___at___00Lean_Server_FileWorker_runRefreshTasks_spec__0_spec__1_spec__3(lean_object*);
lean_object* l_Lean_Json_mkObj(lean_object*);
lean_object* lp_leansort_LeanSort_CostedPlan_Schema_checkProgram___redArg(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_CostedPlan_instReprSchema_repr(lean_object*, lean_object*);
lean_object* l_Std_Format_pretty(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_CostedPlan_Schema_readyUpper(lean_object*, lean_object*);
lean_object* l_LeanSort_RunAdaptive_countPlan___redArg(lean_object*);
lean_object* lean_array_mk(lean_object*);
lean_object* l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__0(lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* lean_get_stdout();
lean_object* l_IO_FS_Stream_putStrLn(lean_object*, lean_object*);
lean_object* lean_get_stdin();
lean_object* l_Lean_Json_compress(lean_object*);
lean_object* lean_io_error_to_string(lean_object*);
lean_object* lean_string_utf8_byte_size(lean_object*);
lean_object* l_Lean_Json_parse(lean_object*);
lean_object* l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(lean_object*);
lean_object* l_Lean_Json_getObjValD(lean_object*, lean_object*);
lean_object* lp_LeanSearchClient_Lean_Json_getObjValAs_x3f___at___00LeanSearchClient_getLoogleQueryJson_spec__4(lean_object*, lean_object*);
lean_object* l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(lean_object*, lean_object*);
uint8_t l_List_isEmpty___redArg(lean_object*);
uint8_t lean_string_memcmp(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_String_Slice_Pos_nextn(lean_object*, lean_object*, lean_object*);
lean_object* l_String_Slice_toString(lean_object*);
lean_object* l_String_Slice_toNat_x3f(lean_object*);
uint8_t l_List_elem___at___00Lean_Meta_Grind_Arith_Cutsat_checkElimEqs_spec__0(lean_object*, lean_object*);
lean_object* lean_st_mk_ref(lean_object*);
lean_object* l_List_range(lean_object*);
lean_object* l_LeanSort_RunAdaptive_countPlan(lean_object*, lean_object*);
lean_object* l_LeanSort_RunAdaptive_lengthPlan(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_orError___redArg(lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_orError___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_orError(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_orError___boxed(lean_object*, lean_object*, lean_object*);
static const lean_ctor_object l_RunExperiment_checkedMerge___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_RunExperiment_checkedMerge___closed__0 = (const lean_object*)&l_RunExperiment_checkedMerge___closed__0_value;
static const lean_ctor_object l_RunExperiment_checkedMerge___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 2}, .m_objs = {((lean_object*)&l_RunExperiment_checkedMerge___closed__0_value)}};
static const lean_object* l_RunExperiment_checkedMerge___closed__1 = (const lean_object*)&l_RunExperiment_checkedMerge___closed__1_value;
LEAN_EXPORT const lean_object* l_RunExperiment_checkedMerge = (const lean_object*)&l_RunExperiment_checkedMerge___closed__1_value;
static const lean_ctor_object l_RunExperiment_fixedTwo___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)(((size_t)(2) << 1) | 1))}};
static const lean_object* l_RunExperiment_fixedTwo___closed__0 = (const lean_object*)&l_RunExperiment_fixedTwo___closed__0_value;
static const lean_ctor_object l_RunExperiment_fixedTwo___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 1}, .m_objs = {((lean_object*)&l_RunExperiment_fixedTwo___closed__0_value),((lean_object*)&l_RunExperiment_checkedMerge___closed__1_value),((lean_object*)&l_RunExperiment_checkedMerge___closed__1_value)}};
static const lean_object* l_RunExperiment_fixedTwo___closed__1 = (const lean_object*)&l_RunExperiment_fixedTwo___closed__1_value;
LEAN_EXPORT const lean_object* l_RunExperiment_fixedTwo = (const lean_object*)&l_RunExperiment_fixedTwo___closed__1_value;
static const lean_ctor_object l_RunExperiment_fixedThree___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)(((size_t)(3) << 1) | 1))}};
static const lean_object* l_RunExperiment_fixedThree___closed__0 = (const lean_object*)&l_RunExperiment_fixedThree___closed__0_value;
static const lean_ctor_object l_RunExperiment_fixedThree___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 1}, .m_objs = {((lean_object*)&l_RunExperiment_fixedThree___closed__0_value),((lean_object*)&l_RunExperiment_checkedMerge___closed__1_value),((lean_object*)&l_RunExperiment_fixedTwo___closed__1_value)}};
static const lean_object* l_RunExperiment_fixedThree___closed__1 = (const lean_object*)&l_RunExperiment_fixedThree___closed__1_value;
LEAN_EXPORT const lean_object* l_RunExperiment_fixedThree = (const lean_object*)&l_RunExperiment_fixedThree___closed__1_value;
static const lean_ctor_object l_RunExperiment_fixedFour___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*3 + 0, .m_other = 3, .m_tag = 1}, .m_objs = {((lean_object*)&l_RunExperiment_fixedTwo___closed__0_value),((lean_object*)&l_RunExperiment_fixedTwo___closed__1_value),((lean_object*)&l_RunExperiment_fixedTwo___closed__1_value)}};
static const lean_object* l_RunExperiment_fixedFour___closed__0 = (const lean_object*)&l_RunExperiment_fixedFour___closed__0_value;
LEAN_EXPORT const lean_object* l_RunExperiment_fixedFour = (const lean_object*)&l_RunExperiment_fixedFour___closed__0_value;
static const lean_string_object l_RunExperiment_decode___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "unknown strategy"};
static const lean_object* l_RunExperiment_decode___closed__0 = (const lean_object*)&l_RunExperiment_decode___closed__0_value;
static const lean_ctor_object l_RunExperiment_decode___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_RunExperiment_decode___closed__0_value)}};
static const lean_object* l_RunExperiment_decode___closed__1 = (const lean_object*)&l_RunExperiment_decode___closed__1_value;
static const lean_string_object l_RunExperiment_decode___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "merge"};
static const lean_object* l_RunExperiment_decode___closed__2 = (const lean_object*)&l_RunExperiment_decode___closed__2_value;
static const lean_string_object l_RunExperiment_decode___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "fixed_two"};
static const lean_object* l_RunExperiment_decode___closed__3 = (const lean_object*)&l_RunExperiment_decode___closed__3_value;
static const lean_string_object l_RunExperiment_decode___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "fixed_three"};
static const lean_object* l_RunExperiment_decode___closed__4 = (const lean_object*)&l_RunExperiment_decode___closed__4_value;
static const lean_string_object l_RunExperiment_decode___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "fixed_four"};
static const lean_object* l_RunExperiment_decode___closed__5 = (const lean_object*)&l_RunExperiment_decode___closed__5_value;
static const lean_string_object l_RunExperiment_decode___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "runs_count"};
static const lean_object* l_RunExperiment_decode___closed__6 = (const lean_object*)&l_RunExperiment_decode___closed__6_value;
static const lean_string_object l_RunExperiment_decode___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "runs_length"};
static const lean_object* l_RunExperiment_decode___closed__7 = (const lean_object*)&l_RunExperiment_decode___closed__7_value;
static const lean_string_object l_RunExperiment_decode___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "hybrid_"};
static const lean_object* l_RunExperiment_decode___closed__8 = (const lean_object*)&l_RunExperiment_decode___closed__8_value;
static lean_once_cell_t l_RunExperiment_decode___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_RunExperiment_decode___closed__9;
static const lean_string_object l_RunExperiment_decode___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "bad threshold"};
static const lean_object* l_RunExperiment_decode___closed__10 = (const lean_object*)&l_RunExperiment_decode___closed__10_value;
static const lean_ctor_object l_RunExperiment_decode___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_RunExperiment_decode___closed__10_value)}};
static const lean_object* l_RunExperiment_decode___closed__11 = (const lean_object*)&l_RunExperiment_decode___closed__11_value;
static const lean_ctor_object l_RunExperiment_decode___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(64) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_RunExperiment_decode___closed__12 = (const lean_object*)&l_RunExperiment_decode___closed__12_value;
static const lean_ctor_object l_RunExperiment_decode___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(24) << 1) | 1)),((lean_object*)&l_RunExperiment_decode___closed__12_value)}};
static const lean_object* l_RunExperiment_decode___closed__13 = (const lean_object*)&l_RunExperiment_decode___closed__13_value;
static const lean_ctor_object l_RunExperiment_decode___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(16) << 1) | 1)),((lean_object*)&l_RunExperiment_decode___closed__13_value)}};
static const lean_object* l_RunExperiment_decode___closed__14 = (const lean_object*)&l_RunExperiment_decode___closed__14_value;
static const lean_ctor_object l_RunExperiment_decode___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(8) << 1) | 1)),((lean_object*)&l_RunExperiment_decode___closed__14_value)}};
static const lean_object* l_RunExperiment_decode___closed__15 = (const lean_object*)&l_RunExperiment_decode___closed__15_value;
static const lean_ctor_object l_RunExperiment_decode___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(4) << 1) | 1)),((lean_object*)&l_RunExperiment_decode___closed__15_value)}};
static const lean_object* l_RunExperiment_decode___closed__16 = (const lean_object*)&l_RunExperiment_decode___closed__16_value;
static const lean_ctor_object l_RunExperiment_decode___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)&l_RunExperiment_decode___closed__16_value)}};
static const lean_object* l_RunExperiment_decode___closed__17 = (const lean_object*)&l_RunExperiment_decode___closed__17_value;
static const lean_string_object l_RunExperiment_decode___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 29, .m_capacity = 29, .m_length = 28, .m_data = "unsupported frozen threshold"};
static const lean_object* l_RunExperiment_decode___closed__18 = (const lean_object*)&l_RunExperiment_decode___closed__18_value;
static const lean_ctor_object l_RunExperiment_decode___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_RunExperiment_decode___closed__18_value)}};
static const lean_object* l_RunExperiment_decode___closed__19 = (const lean_object*)&l_RunExperiment_decode___closed__19_value;
static const lean_ctor_object l_RunExperiment_decode___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(2) << 1) | 1))}};
static const lean_object* l_RunExperiment_decode___closed__20 = (const lean_object*)&l_RunExperiment_decode___closed__20_value;
static const lean_ctor_object l_RunExperiment_decode___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* l_RunExperiment_decode___closed__21 = (const lean_object*)&l_RunExperiment_decode___closed__21_value;
static const lean_ctor_object l_RunExperiment_decode___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_RunExperiment_fixedFour___closed__0_value)}};
static const lean_object* l_RunExperiment_decode___closed__22 = (const lean_object*)&l_RunExperiment_decode___closed__22_value;
static const lean_ctor_object l_RunExperiment_decode___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)&l_RunExperiment_decode___closed__22_value)}};
static const lean_object* l_RunExperiment_decode___closed__23 = (const lean_object*)&l_RunExperiment_decode___closed__23_value;
static const lean_ctor_object l_RunExperiment_decode___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_RunExperiment_fixedThree___closed__1_value)}};
static const lean_object* l_RunExperiment_decode___closed__24 = (const lean_object*)&l_RunExperiment_decode___closed__24_value;
static const lean_ctor_object l_RunExperiment_decode___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)&l_RunExperiment_decode___closed__24_value)}};
static const lean_object* l_RunExperiment_decode___closed__25 = (const lean_object*)&l_RunExperiment_decode___closed__25_value;
static const lean_ctor_object l_RunExperiment_decode___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_RunExperiment_fixedTwo___closed__1_value)}};
static const lean_object* l_RunExperiment_decode___closed__26 = (const lean_object*)&l_RunExperiment_decode___closed__26_value;
static const lean_ctor_object l_RunExperiment_decode___closed__27_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)&l_RunExperiment_decode___closed__26_value)}};
static const lean_object* l_RunExperiment_decode___closed__27 = (const lean_object*)&l_RunExperiment_decode___closed__27_value;
static const lean_ctor_object l_RunExperiment_decode___closed__28_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_RunExperiment_checkedMerge___closed__0_value)}};
static const lean_object* l_RunExperiment_decode___closed__28 = (const lean_object*)&l_RunExperiment_decode___closed__28_value;
static const lean_ctor_object l_RunExperiment_decode___closed__29_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)&l_RunExperiment_decode___closed__28_value)}};
static const lean_object* l_RunExperiment_decode___closed__29 = (const lean_object*)&l_RunExperiment_decode___closed__29_value;
LEAN_EXPORT lean_object* l_RunExperiment_decode(lean_object*);
LEAN_EXPORT lean_object* l_List_foldl___at___00RunExperiment_checksum_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_foldl___at___00RunExperiment_checksum_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_checksum(lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_checksum___boxed(lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00RunExperiment_shape_spec__0(lean_object*);
static lean_once_cell_t l_RunExperiment_shape___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_RunExperiment_shape___closed__0;
LEAN_EXPORT lean_object* l_RunExperiment_shape(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0(lean_object*, lean_object*);
static const lean_string_object l_RunExperiment_timedRun___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 28, .m_capacity = 28, .m_length = 27, .m_data = "incorrect deployment output"};
static const lean_object* l_RunExperiment_timedRun___closed__0 = (const lean_object*)&l_RunExperiment_timedRun___closed__0_value;
static const lean_ctor_object l_RunExperiment_timedRun___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_RunExperiment_timedRun___closed__0_value)}};
static const lean_object* l_RunExperiment_timedRun___closed__1 = (const lean_object*)&l_RunExperiment_timedRun___closed__1_value;
LEAN_EXPORT lean_object* l_RunExperiment_timedRun(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_timedRun___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_foldl___at___00RunExperiment_timedScan_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_foldl___at___00RunExperiment_timedScan_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_timedScan(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_timedScan___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_timedPlan(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_timedPlan___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_RunExperiment_timedMerge___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 28, .m_capacity = 28, .m_length = 27, .m_data = "incorrect merge-only output"};
static const lean_object* l_RunExperiment_timedMerge___closed__0 = (const lean_object*)&l_RunExperiment_timedMerge___closed__0_value;
static const lean_ctor_object l_RunExperiment_timedMerge___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_RunExperiment_timedMerge___closed__0_value)}};
static const lean_object* l_RunExperiment_timedMerge___closed__1 = (const lean_object*)&l_RunExperiment_timedMerge___closed__1_value;
LEAN_EXPORT lean_object* l_RunExperiment_timedMerge(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_timedMerge___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_diagnostics_spec__0___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_diagnostics_spec__0___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_ctor_object l_RunExperiment_diagnostics___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_RunExperiment_diagnostics___closed__0 = (const lean_object*)&l_RunExperiment_diagnostics___closed__0_value;
static const lean_ctor_object l_RunExperiment_diagnostics___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_RunExperiment_diagnostics___closed__0_value)}};
static const lean_object* l_RunExperiment_diagnostics___closed__1 = (const lean_object*)&l_RunExperiment_diagnostics___closed__1_value;
static const lean_string_object l_RunExperiment_diagnostics___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "scan_ns"};
static const lean_object* l_RunExperiment_diagnostics___closed__2 = (const lean_object*)&l_RunExperiment_diagnostics___closed__2_value;
static const lean_string_object l_RunExperiment_diagnostics___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "plan_with_consumption_ns"};
static const lean_object* l_RunExperiment_diagnostics___closed__3 = (const lean_object*)&l_RunExperiment_diagnostics___closed__3_value;
static const lean_string_object l_RunExperiment_diagnostics___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "merge_only_ns"};
static const lean_object* l_RunExperiment_diagnostics___closed__4 = (const lean_object*)&l_RunExperiment_diagnostics___closed__4_value;
LEAN_EXPORT lean_object* l_RunExperiment_diagnostics(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_diagnostics___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_diagnostics_spec__0(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_diagnostics_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object l_LeanSort_CostedPlan_Schema_readyCheck___at___00RunExperiment_profile_spec__1___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_LeanSort_CostedPlan_Schema_readyCheck___at___00RunExperiment_profile_spec__1___closed__0 = (const lean_object*)&l_LeanSort_CostedPlan_Schema_readyCheck___at___00RunExperiment_profile_spec__1___closed__0_value;
LEAN_EXPORT uint8_t l_LeanSort_CostedPlan_Schema_readyCheck___at___00RunExperiment_profile_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_CostedPlan_Schema_readyCheck___at___00RunExperiment_profile_spec__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_RunAdaptive_runCount___at___00LeanSort_RunAdaptive_Strategy_bound___at___00RunExperiment_profile_spec__0_spec__0(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_RunAdaptive_Strategy_bound___at___00RunExperiment_profile_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_RunAdaptive_Strategy_bound___at___00RunExperiment_profile_spec__0___boxed(lean_object*, lean_object*);
static const lean_string_object l_RunExperiment_profile___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "comparisons"};
static const lean_object* l_RunExperiment_profile___closed__0 = (const lean_object*)&l_RunExperiment_profile___closed__0_value;
static const lean_string_object l_RunExperiment_profile___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "check_comparisons"};
static const lean_object* l_RunExperiment_profile___closed__1 = (const lean_object*)&l_RunExperiment_profile___closed__1_value;
static const lean_string_object l_RunExperiment_profile___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "merge_or_sort_comparisons"};
static const lean_object* l_RunExperiment_profile___closed__2 = (const lean_object*)&l_RunExperiment_profile___closed__2_value;
static const lean_string_object l_RunExperiment_profile___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "bound"};
static const lean_object* l_RunExperiment_profile___closed__3 = (const lean_object*)&l_RunExperiment_profile___closed__3_value;
static const lean_string_object l_RunExperiment_profile___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "tree_budget"};
static const lean_object* l_RunExperiment_profile___closed__4 = (const lean_object*)&l_RunExperiment_profile___closed__4_value;
static const lean_string_object l_RunExperiment_profile___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "conditional_applicable"};
static const lean_object* l_RunExperiment_profile___closed__5 = (const lean_object*)&l_RunExperiment_profile___closed__5_value;
static const lean_string_object l_RunExperiment_profile___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "conditional_bound"};
static const lean_object* l_RunExperiment_profile___closed__6 = (const lean_object*)&l_RunExperiment_profile___closed__6_value;
static const lean_string_object l_RunExperiment_profile___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "plan"};
static const lean_object* l_RunExperiment_profile___closed__7 = (const lean_object*)&l_RunExperiment_profile___closed__7_value;
static const lean_string_object l_RunExperiment_profile___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "cost inequality failed"};
static const lean_object* l_RunExperiment_profile___closed__8 = (const lean_object*)&l_RunExperiment_profile___closed__8_value;
static const lean_ctor_object l_RunExperiment_profile___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_RunExperiment_profile___closed__8_value)}};
static const lean_object* l_RunExperiment_profile___closed__9 = (const lean_object*)&l_RunExperiment_profile___closed__9_value;
static const lean_string_object l_RunExperiment_profile___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 38, .m_capacity = 38, .m_length = 37, .m_data = "inapplicable/failed conditional bound"};
static const lean_object* l_RunExperiment_profile___closed__10 = (const lean_object*)&l_RunExperiment_profile___closed__10_value;
static const lean_ctor_object l_RunExperiment_profile___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_RunExperiment_profile___closed__10_value)}};
static const lean_object* l_RunExperiment_profile___closed__11 = (const lean_object*)&l_RunExperiment_profile___closed__11_value;
static const lean_string_object l_RunExperiment_profile___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "incorrect profiled output"};
static const lean_object* l_RunExperiment_profile___closed__12 = (const lean_object*)&l_RunExperiment_profile___closed__12_value;
static const lean_ctor_object l_RunExperiment_profile___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_RunExperiment_profile___closed__12_value)}};
static const lean_object* l_RunExperiment_profile___closed__13 = (const lean_object*)&l_RunExperiment_profile___closed__13_value;
LEAN_EXPORT lean_object* l_RunExperiment_profile(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_profile___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00RunExperiment_handle_spec__2(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00RunExperiment_handle_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__3___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__3___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6___redArg___closed__0_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_List_all___at___00RunExperiment_handle_spec__11(uint8_t, uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_List_all___at___00RunExperiment_handle_spec__11___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_find_x3f___at___00RunExperiment_handle_spec__7(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_find_x3f___at___00RunExperiment_handle_spec__7___boxed(lean_object*, lean_object*);
static const lean_string_object l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "strategy"};
static const lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__0_value;
static const lean_string_object l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "samples_ns"};
static const lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__1 = (const lean_object*)&l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__1_value;
static const lean_string_object l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "profile"};
static const lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__2 = (const lean_object*)&l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__2_value;
static const lean_string_object l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "diagnostics"};
static const lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__3 = (const lean_object*)&l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__3_value;
static const lean_closure_object l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_LeanSort_RunAdaptive_countPlan, .m_arity = 2, .m_num_fixed = 1, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))} };
static const lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__4 = (const lean_object*)&l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__4_value;
static const lean_closure_object l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_LeanSort_RunAdaptive_lengthPlan, .m_arity = 2, .m_num_fixed = 1, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))} };
static const lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__5 = (const lean_object*)&l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__5_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00RunExperiment_handle_spec__5(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00RunExperiment_handle_spec__10(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00RunExperiment_handle_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00RunExperiment_handle_spec__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__4___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__4___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00RunExperiment_handle_spec__9(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00RunExperiment_handle_spec__0_spec__0(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00RunExperiment_handle_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00RunExperiment_handle_spec__0___boxed(lean_object*, lean_object*);
static const lean_string_object l_RunExperiment_handle___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 48, .m_capacity = 48, .m_length = 47, .m_data = "discovered runs failed independent finite check"};
static const lean_object* l_RunExperiment_handle___closed__0 = (const lean_object*)&l_RunExperiment_handle___closed__0_value;
static const lean_ctor_object l_RunExperiment_handle___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_RunExperiment_handle___closed__0_value)}};
static const lean_object* l_RunExperiment_handle___closed__1 = (const lean_object*)&l_RunExperiment_handle___closed__1_value;
static const lean_string_object l_RunExperiment_handle___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "run_lengths"};
static const lean_object* l_RunExperiment_handle___closed__2 = (const lean_object*)&l_RunExperiment_handle___closed__2_value;
static const lean_string_object l_RunExperiment_handle___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "run_count"};
static const lean_object* l_RunExperiment_handle___closed__3 = (const lean_object*)&l_RunExperiment_handle___closed__3_value;
static const lean_string_object l_RunExperiment_handle___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "scan_comparisons"};
static const lean_object* l_RunExperiment_handle___closed__4 = (const lean_object*)&l_RunExperiment_handle___closed__4_value;
static const lean_string_object l_RunExperiment_handle___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "measurements"};
static const lean_object* l_RunExperiment_handle___closed__5 = (const lean_object*)&l_RunExperiment_handle___closed__5_value;
static const lean_string_object l_RunExperiment_handle___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "all_outputs_correct"};
static const lean_object* l_RunExperiment_handle___closed__6 = (const lean_object*)&l_RunExperiment_handle___closed__6_value;
static const lean_string_object l_RunExperiment_handle___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "input"};
static const lean_object* l_RunExperiment_handle___closed__7 = (const lean_object*)&l_RunExperiment_handle___closed__7_value;
static const lean_string_object l_RunExperiment_handle___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "expected"};
static const lean_object* l_RunExperiment_handle___closed__8 = (const lean_object*)&l_RunExperiment_handle___closed__8_value;
static const lean_string_object l_RunExperiment_handle___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "strategies"};
static const lean_object* l_RunExperiment_handle___closed__9 = (const lean_object*)&l_RunExperiment_handle___closed__9_value;
static const lean_string_object l_RunExperiment_handle___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "rounds"};
static const lean_object* l_RunExperiment_handle___closed__10 = (const lean_object*)&l_RunExperiment_handle___closed__10_value;
static const lean_string_object l_RunExperiment_handle___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "order_seed"};
static const lean_object* l_RunExperiment_handle___closed__11 = (const lean_object*)&l_RunExperiment_handle___closed__11_value;
static const lean_string_object l_RunExperiment_handle___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 29, .m_capacity = 29, .m_length = 28, .m_data = "invalid measurement settings"};
static const lean_object* l_RunExperiment_handle___closed__12 = (const lean_object*)&l_RunExperiment_handle___closed__12_value;
static const lean_ctor_object l_RunExperiment_handle___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_RunExperiment_handle___closed__12_value)}};
static const lean_object* l_RunExperiment_handle___closed__13 = (const lean_object*)&l_RunExperiment_handle___closed__13_value;
LEAN_EXPORT lean_object* l_RunExperiment_handle(lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_handle___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__3(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__4(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_RunExperiment_loop___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "error"};
static const lean_object* l_RunExperiment_loop___closed__0 = (const lean_object*)&l_RunExperiment_loop___closed__0_value;
LEAN_EXPORT lean_object* l_RunExperiment_loop();
LEAN_EXPORT lean_object* l_RunExperiment_loop___boxed(lean_object*);
static const lean_string_object l_main___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 56, .m_capacity = 56, .m_length = 55, .m_data = "{\"ready\":true,\"backend\":\"lean--run/comparison-program\"}"};
static const lean_object* l_main___closed__0 = (const lean_object*)&l_main___closed__0_value;
LEAN_EXPORT lean_object* _lean_main();
LEAN_EXPORT lean_object* l_main___boxed(lean_object*);
LEAN_EXPORT lean_object* l_RunExperiment_orError___redArg(lean_object* v_x_1_){
_start:
{
if (lean_obj_tag(v_x_1_) == 0)
{
lean_object* v_a_3_; lean_object* v___x_5_; uint8_t v_isShared_6_; uint8_t v_isSharedCheck_11_; 
v_a_3_ = lean_ctor_get(v_x_1_, 0);
v_isSharedCheck_11_ = !lean_is_exclusive(v_x_1_);
if (v_isSharedCheck_11_ == 0)
{
v___x_5_ = v_x_1_;
v_isShared_6_ = v_isSharedCheck_11_;
goto v_resetjp_4_;
}
else
{
lean_inc(v_a_3_);
lean_dec(v_x_1_);
v___x_5_ = lean_box(0);
v_isShared_6_ = v_isSharedCheck_11_;
goto v_resetjp_4_;
}
v_resetjp_4_:
{
lean_object* v___x_8_; 
if (v_isShared_6_ == 0)
{
lean_ctor_set_tag(v___x_5_, 18);
v___x_8_ = v___x_5_;
goto v_reusejp_7_;
}
else
{
lean_object* v_reuseFailAlloc_10_; 
v_reuseFailAlloc_10_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v_reuseFailAlloc_10_, 0, v_a_3_);
v___x_8_ = v_reuseFailAlloc_10_;
goto v_reusejp_7_;
}
v_reusejp_7_:
{
lean_object* v___x_9_; 
v___x_9_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_9_, 0, v___x_8_);
return v___x_9_;
}
}
}
else
{
lean_object* v_a_12_; lean_object* v___x_14_; uint8_t v_isShared_15_; uint8_t v_isSharedCheck_19_; 
v_a_12_ = lean_ctor_get(v_x_1_, 0);
v_isSharedCheck_19_ = !lean_is_exclusive(v_x_1_);
if (v_isSharedCheck_19_ == 0)
{
v___x_14_ = v_x_1_;
v_isShared_15_ = v_isSharedCheck_19_;
goto v_resetjp_13_;
}
else
{
lean_inc(v_a_12_);
lean_dec(v_x_1_);
v___x_14_ = lean_box(0);
v_isShared_15_ = v_isSharedCheck_19_;
goto v_resetjp_13_;
}
v_resetjp_13_:
{
lean_object* v___x_17_; 
if (v_isShared_15_ == 0)
{
lean_ctor_set_tag(v___x_14_, 0);
v___x_17_ = v___x_14_;
goto v_reusejp_16_;
}
else
{
lean_object* v_reuseFailAlloc_18_; 
v_reuseFailAlloc_18_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_18_, 0, v_a_12_);
v___x_17_ = v_reuseFailAlloc_18_;
goto v_reusejp_16_;
}
v_reusejp_16_:
{
return v___x_17_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_RunExperiment_orError___redArg___boxed(lean_object* v_x_20_, lean_object* v_a_21_){
_start:
{
lean_object* v_res_22_; 
v_res_22_ = l_RunExperiment_orError___redArg(v_x_20_);
return v_res_22_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_orError(lean_object* v_00_u03b1_23_, lean_object* v_x_24_){
_start:
{
lean_object* v___x_26_; 
v___x_26_ = l_RunExperiment_orError___redArg(v_x_24_);
return v___x_26_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_orError___boxed(lean_object* v_00_u03b1_27_, lean_object* v_x_28_, lean_object* v_a_29_){
_start:
{
lean_object* v_res_30_; 
v_res_30_ = l_RunExperiment_orError(v_00_u03b1_27_, v_x_28_);
return v_res_30_;
}
}
static lean_object* _init_l_RunExperiment_decode___closed__9(void){
_start:
{
lean_object* v___x_65_; lean_object* v___x_66_; 
v___x_65_ = ((lean_object*)(l_RunExperiment_decode___closed__8));
v___x_66_ = lean_string_utf8_byte_size(v___x_65_);
return v___x_66_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_decode(lean_object* v_name_111_){
_start:
{
lean_object* v___x_114_; uint8_t v___x_115_; 
v___x_114_ = ((lean_object*)(l_RunExperiment_decode___closed__2));
v___x_115_ = lean_string_dec_eq(v_name_111_, v___x_114_);
if (v___x_115_ == 0)
{
lean_object* v___x_116_; uint8_t v___x_117_; 
v___x_116_ = ((lean_object*)(l_RunExperiment_decode___closed__3));
v___x_117_ = lean_string_dec_eq(v_name_111_, v___x_116_);
if (v___x_117_ == 0)
{
lean_object* v___x_118_; uint8_t v___x_119_; 
v___x_118_ = ((lean_object*)(l_RunExperiment_decode___closed__4));
v___x_119_ = lean_string_dec_eq(v_name_111_, v___x_118_);
if (v___x_119_ == 0)
{
lean_object* v___x_120_; uint8_t v___x_121_; 
v___x_120_ = ((lean_object*)(l_RunExperiment_decode___closed__5));
v___x_121_ = lean_string_dec_eq(v_name_111_, v___x_120_);
if (v___x_121_ == 0)
{
lean_object* v___x_122_; uint8_t v___x_123_; 
v___x_122_ = ((lean_object*)(l_RunExperiment_decode___closed__6));
v___x_123_ = lean_string_dec_eq(v_name_111_, v___x_122_);
if (v___x_123_ == 0)
{
lean_object* v___x_124_; uint8_t v___x_125_; 
v___x_124_ = ((lean_object*)(l_RunExperiment_decode___closed__7));
v___x_125_ = lean_string_dec_eq(v_name_111_, v___x_124_);
if (v___x_125_ == 0)
{
lean_object* v___x_126_; lean_object* v___x_127_; lean_object* v___x_128_; uint8_t v___x_129_; 
v___x_126_ = ((lean_object*)(l_RunExperiment_decode___closed__8));
v___x_127_ = lean_string_utf8_byte_size(v_name_111_);
v___x_128_ = lean_obj_once(&l_RunExperiment_decode___closed__9, &l_RunExperiment_decode___closed__9_once, _init_l_RunExperiment_decode___closed__9);
v___x_129_ = lean_nat_dec_le(v___x_128_, v___x_127_);
if (v___x_129_ == 0)
{
lean_dec_ref(v_name_111_);
goto v___jp_112_;
}
else
{
lean_object* v___x_130_; uint8_t v___x_131_; 
v___x_130_ = lean_unsigned_to_nat(0u);
v___x_131_ = lean_string_memcmp(v_name_111_, v___x_126_, v___x_130_, v___x_130_, v___x_128_);
if (v___x_131_ == 0)
{
lean_dec_ref(v_name_111_);
goto v___jp_112_;
}
else
{
lean_object* v___x_132_; lean_object* v___x_133_; lean_object* v___x_134_; lean_object* v___x_135_; lean_object* v___x_136_; lean_object* v___x_137_; lean_object* v___x_138_; lean_object* v___x_139_; 
v___x_132_ = lean_unsigned_to_nat(7u);
lean_inc_ref(v_name_111_);
v___x_133_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_133_, 0, v_name_111_);
lean_ctor_set(v___x_133_, 1, v___x_130_);
lean_ctor_set(v___x_133_, 2, v___x_127_);
v___x_134_ = l_String_Slice_Pos_nextn(v___x_133_, v___x_130_, v___x_132_);
lean_dec_ref_known(v___x_133_, 3);
v___x_135_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_135_, 0, v_name_111_);
lean_ctor_set(v___x_135_, 1, v___x_134_);
lean_ctor_set(v___x_135_, 2, v___x_127_);
v___x_136_ = l_String_Slice_toString(v___x_135_);
lean_dec_ref_known(v___x_135_, 3);
v___x_137_ = lean_string_utf8_byte_size(v___x_136_);
v___x_138_ = lean_alloc_ctor(0, 3, 0);
lean_ctor_set(v___x_138_, 0, v___x_136_);
lean_ctor_set(v___x_138_, 1, v___x_130_);
lean_ctor_set(v___x_138_, 2, v___x_137_);
v___x_139_ = l_String_Slice_toNat_x3f(v___x_138_);
lean_dec_ref_known(v___x_138_, 3);
if (lean_obj_tag(v___x_139_) == 0)
{
lean_object* v___x_140_; 
v___x_140_ = ((lean_object*)(l_RunExperiment_decode___closed__11));
return v___x_140_;
}
else
{
lean_object* v_val_141_; lean_object* v___x_143_; uint8_t v_isShared_144_; uint8_t v_isSharedCheck_154_; 
v_val_141_ = lean_ctor_get(v___x_139_, 0);
v_isSharedCheck_154_ = !lean_is_exclusive(v___x_139_);
if (v_isSharedCheck_154_ == 0)
{
v___x_143_ = v___x_139_;
v_isShared_144_ = v_isSharedCheck_154_;
goto v_resetjp_142_;
}
else
{
lean_inc(v_val_141_);
lean_dec(v___x_139_);
v___x_143_ = lean_box(0);
v_isShared_144_ = v_isSharedCheck_154_;
goto v_resetjp_142_;
}
v_resetjp_142_:
{
lean_object* v___x_145_; uint8_t v___x_146_; 
v___x_145_ = ((lean_object*)(l_RunExperiment_decode___closed__17));
v___x_146_ = l_List_elem___at___00Lean_Meta_Grind_Arith_Cutsat_checkElimEqs_spec__0(v_val_141_, v___x_145_);
if (v___x_146_ == 0)
{
lean_object* v___x_147_; 
lean_del_object(v___x_143_);
lean_dec(v_val_141_);
v___x_147_ = ((lean_object*)(l_RunExperiment_decode___closed__19));
return v___x_147_;
}
else
{
lean_object* v___x_149_; 
if (v_isShared_144_ == 0)
{
lean_ctor_set_tag(v___x_143_, 2);
v___x_149_ = v___x_143_;
goto v_reusejp_148_;
}
else
{
lean_object* v_reuseFailAlloc_153_; 
v_reuseFailAlloc_153_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_153_, 0, v_val_141_);
v___x_149_ = v_reuseFailAlloc_153_;
goto v_reusejp_148_;
}
v_reusejp_148_:
{
lean_object* v___x_150_; lean_object* v___x_151_; lean_object* v___x_152_; 
v___x_150_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_150_, 0, v___x_149_);
v___x_151_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_151_, 0, v___x_150_);
v___x_152_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_152_, 0, v___x_151_);
return v___x_152_;
}
}
}
}
}
}
}
else
{
lean_object* v___x_155_; 
lean_dec_ref(v_name_111_);
v___x_155_ = ((lean_object*)(l_RunExperiment_decode___closed__20));
return v___x_155_;
}
}
else
{
lean_object* v___x_156_; 
lean_dec_ref(v_name_111_);
v___x_156_ = ((lean_object*)(l_RunExperiment_decode___closed__21));
return v___x_156_;
}
}
else
{
lean_object* v___x_157_; 
lean_dec_ref(v_name_111_);
v___x_157_ = ((lean_object*)(l_RunExperiment_decode___closed__23));
return v___x_157_;
}
}
else
{
lean_object* v___x_158_; 
lean_dec_ref(v_name_111_);
v___x_158_ = ((lean_object*)(l_RunExperiment_decode___closed__25));
return v___x_158_;
}
}
else
{
lean_object* v___x_159_; 
lean_dec_ref(v_name_111_);
v___x_159_ = ((lean_object*)(l_RunExperiment_decode___closed__27));
return v___x_159_;
}
}
else
{
lean_object* v___x_160_; 
lean_dec_ref(v_name_111_);
v___x_160_ = ((lean_object*)(l_RunExperiment_decode___closed__29));
return v___x_160_;
}
v___jp_112_:
{
lean_object* v___x_113_; 
v___x_113_ = ((lean_object*)(l_RunExperiment_decode___closed__1));
return v___x_113_;
}
}
}
LEAN_EXPORT lean_object* l_List_foldl___at___00RunExperiment_checksum_spec__0(lean_object* v_x_161_, lean_object* v_x_162_){
_start:
{
if (lean_obj_tag(v_x_162_) == 0)
{
return v_x_161_;
}
else
{
lean_object* v_head_163_; lean_object* v_tail_164_; lean_object* v___x_165_; lean_object* v___x_166_; lean_object* v___x_167_; lean_object* v___x_168_; lean_object* v___x_169_; 
v_head_163_ = lean_ctor_get(v_x_162_, 0);
v_tail_164_ = lean_ctor_get(v_x_162_, 1);
v___x_165_ = lean_unsigned_to_nat(33u);
v___x_166_ = lean_nat_mul(v_x_161_, v___x_165_);
lean_dec(v_x_161_);
v___x_167_ = lean_nat_add(v___x_166_, v_head_163_);
lean_dec(v___x_166_);
v___x_168_ = lean_unsigned_to_nat(1000000007u);
v___x_169_ = lean_nat_mod(v___x_167_, v___x_168_);
lean_dec(v___x_167_);
v_x_161_ = v___x_169_;
v_x_162_ = v_tail_164_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_List_foldl___at___00RunExperiment_checksum_spec__0___boxed(lean_object* v_x_171_, lean_object* v_x_172_){
_start:
{
lean_object* v_res_173_; 
v_res_173_ = l_List_foldl___at___00RunExperiment_checksum_spec__0(v_x_171_, v_x_172_);
lean_dec(v_x_172_);
return v_res_173_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_checksum(lean_object* v_xs_174_){
_start:
{
lean_object* v___x_175_; lean_object* v___x_176_; 
v___x_175_ = lean_unsigned_to_nat(0u);
v___x_176_ = l_List_foldl___at___00RunExperiment_checksum_spec__0(v___x_175_, v_xs_174_);
return v___x_176_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_checksum___boxed(lean_object* v_xs_177_){
_start:
{
lean_object* v_res_178_; 
v_res_178_ = l_RunExperiment_checksum(v_xs_177_);
lean_dec(v_xs_177_);
return v_res_178_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00RunExperiment_shape_spec__0(lean_object* v_a_179_){
_start:
{
lean_object* v___x_180_; lean_object* v___x_181_; 
v___x_180_ = lean_array_mk(v_a_179_);
v___x_181_ = l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__0(v___x_180_);
return v___x_181_;
}
}
static lean_object* _init_l_RunExperiment_shape___closed__0(void){
_start:
{
lean_object* v___x_182_; lean_object* v___x_183_; 
v___x_182_ = lean_box(0);
v___x_183_ = l_Lean_List_toJson___at___00RunExperiment_shape_spec__0(v___x_182_);
return v___x_183_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_shape(lean_object* v_x_184_){
_start:
{
switch(lean_obj_tag(v_x_184_))
{
case 0:
{
lean_object* v___x_185_; 
v___x_185_ = lean_obj_once(&l_RunExperiment_shape___closed__0, &l_RunExperiment_shape___closed__0_once, _init_l_RunExperiment_shape___closed__0);
return v___x_185_;
}
case 1:
{
lean_object* v_run_186_; lean_object* v___x_188_; uint8_t v_isShared_189_; uint8_t v_isSharedCheck_195_; 
v_run_186_ = lean_ctor_get(v_x_184_, 0);
v_isSharedCheck_195_ = !lean_is_exclusive(v_x_184_);
if (v_isSharedCheck_195_ == 0)
{
v___x_188_ = v_x_184_;
v_isShared_189_ = v_isSharedCheck_195_;
goto v_resetjp_187_;
}
else
{
lean_inc(v_run_186_);
lean_dec(v_x_184_);
v___x_188_ = lean_box(0);
v_isShared_189_ = v_isSharedCheck_195_;
goto v_resetjp_187_;
}
v_resetjp_187_:
{
lean_object* v___x_190_; lean_object* v___x_191_; lean_object* v___x_193_; 
v___x_190_ = l_List_lengthTR___redArg(v_run_186_);
lean_dec(v_run_186_);
v___x_191_ = l_Lean_JsonNumber_fromNat(v___x_190_);
if (v_isShared_189_ == 0)
{
lean_ctor_set_tag(v___x_188_, 2);
lean_ctor_set(v___x_188_, 0, v___x_191_);
v___x_193_ = v___x_188_;
goto v_reusejp_192_;
}
else
{
lean_object* v_reuseFailAlloc_194_; 
v_reuseFailAlloc_194_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_194_, 0, v___x_191_);
v___x_193_ = v_reuseFailAlloc_194_;
goto v_reusejp_192_;
}
v_reusejp_192_:
{
return v___x_193_;
}
}
}
default: 
{
lean_object* v_left_196_; lean_object* v_right_197_; lean_object* v___x_198_; lean_object* v___x_199_; lean_object* v___x_200_; lean_object* v___x_201_; lean_object* v___x_202_; lean_object* v___x_203_; lean_object* v___x_204_; 
v_left_196_ = lean_ctor_get(v_x_184_, 0);
lean_inc(v_left_196_);
v_right_197_ = lean_ctor_get(v_x_184_, 1);
lean_inc(v_right_197_);
lean_dec_ref_known(v_x_184_, 2);
v___x_198_ = l_RunExperiment_shape(v_left_196_);
v___x_199_ = l_RunExperiment_shape(v_right_197_);
v___x_200_ = lean_unsigned_to_nat(2u);
v___x_201_ = lean_mk_empty_array_with_capacity(v___x_200_);
v___x_202_ = lean_array_push(v___x_201_, v___x_198_);
v___x_203_ = lean_array_push(v___x_202_, v___x_199_);
v___x_204_ = lean_alloc_ctor(4, 1, 0);
lean_ctor_set(v___x_204_, 0, v___x_203_);
return v___x_204_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(lean_object* v_x_205_){
_start:
{
if (lean_obj_tag(v_x_205_) == 0)
{
lean_object* v_value_206_; lean_object* v___x_207_; lean_object* v___x_208_; 
v_value_206_ = lean_ctor_get(v_x_205_, 0);
lean_inc(v_value_206_);
lean_dec_ref_known(v_x_205_, 1);
v___x_207_ = lean_unsigned_to_nat(0u);
v___x_208_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_208_, 0, v_value_206_);
lean_ctor_set(v___x_208_, 1, v___x_207_);
return v___x_208_;
}
else
{
lean_object* v_left_209_; lean_object* v_right_210_; lean_object* v_next_211_; uint8_t v___x_212_; lean_object* v___x_213_; lean_object* v___x_214_; lean_object* v_rest_215_; lean_object* v_ret_216_; lean_object* v_time_217_; lean_object* v___x_219_; uint8_t v_isShared_220_; uint8_t v_isSharedCheck_226_; 
v_left_209_ = lean_ctor_get(v_x_205_, 0);
lean_inc(v_left_209_);
v_right_210_ = lean_ctor_get(v_x_205_, 1);
lean_inc(v_right_210_);
v_next_211_ = lean_ctor_get(v_x_205_, 2);
lean_inc_ref(v_next_211_);
lean_dec_ref_known(v_x_205_, 3);
v___x_212_ = lean_nat_dec_le(v_left_209_, v_right_210_);
lean_dec(v_right_210_);
lean_dec(v_left_209_);
v___x_213_ = lean_box(v___x_212_);
v___x_214_ = lean_apply_1(v_next_211_, v___x_213_);
v_rest_215_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(v___x_214_);
v_ret_216_ = lean_ctor_get(v_rest_215_, 0);
v_time_217_ = lean_ctor_get(v_rest_215_, 1);
v_isSharedCheck_226_ = !lean_is_exclusive(v_rest_215_);
if (v_isSharedCheck_226_ == 0)
{
v___x_219_ = v_rest_215_;
v_isShared_220_ = v_isSharedCheck_226_;
goto v_resetjp_218_;
}
else
{
lean_inc(v_time_217_);
lean_inc(v_ret_216_);
lean_dec(v_rest_215_);
v___x_219_ = lean_box(0);
v_isShared_220_ = v_isSharedCheck_226_;
goto v_resetjp_218_;
}
v_resetjp_218_:
{
lean_object* v___x_221_; lean_object* v___x_222_; lean_object* v___x_224_; 
v___x_221_ = lean_unsigned_to_nat(1u);
v___x_222_ = lean_nat_add(v_time_217_, v___x_221_);
lean_dec(v_time_217_);
if (v_isShared_220_ == 0)
{
lean_ctor_set(v___x_219_, 1, v___x_222_);
v___x_224_ = v___x_219_;
goto v_reusejp_223_;
}
else
{
lean_object* v_reuseFailAlloc_225_; 
v_reuseFailAlloc_225_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_225_, 0, v_ret_216_);
lean_ctor_set(v_reuseFailAlloc_225_, 1, v___x_222_);
v___x_224_ = v_reuseFailAlloc_225_;
goto v_reusejp_223_;
}
v_reusejp_223_:
{
return v___x_224_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0(lean_object* v_s_227_, lean_object* v_xs_228_){
_start:
{
lean_object* v___x_229_; lean_object* v___x_230_; lean_object* v_ret_231_; 
v___x_229_ = l_LeanSort_RunAdaptive_Strategy_program___redArg(v_s_227_, v_xs_228_);
v___x_230_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(v___x_229_);
v_ret_231_ = lean_ctor_get(v___x_230_, 0);
lean_inc(v_ret_231_);
lean_dec_ref(v___x_230_);
return v_ret_231_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_timedRun(lean_object* v_s_235_, lean_object* v_source_236_, lean_object* v_sink_237_, lean_object* v_expected_238_){
_start:
{
lean_object* v___x_240_; lean_object* v___x_241_; lean_object* v___x_242_; lean_object* v___x_243_; lean_object* v___x_244_; lean_object* v___x_245_; uint8_t v___x_246_; 
v___x_240_ = lean_io_mono_nanos_now();
v___x_241_ = lean_st_ref_get(v_source_236_);
v___x_242_ = l_LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0(v_s_235_, v___x_241_);
v___x_243_ = l_RunExperiment_checksum(v___x_242_);
v___x_244_ = lean_st_ref_set(v_sink_237_, v___x_243_);
v___x_245_ = lean_io_mono_nanos_now();
v___x_246_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v___x_242_, v_expected_238_);
lean_dec(v___x_242_);
if (v___x_246_ == 0)
{
lean_object* v___x_247_; lean_object* v___x_248_; 
lean_dec(v___x_245_);
lean_dec(v___x_240_);
v___x_247_ = ((lean_object*)(l_RunExperiment_timedRun___closed__1));
v___x_248_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_248_, 0, v___x_247_);
return v___x_248_;
}
else
{
lean_object* v___x_249_; lean_object* v___x_250_; 
v___x_249_ = lean_nat_sub(v___x_245_, v___x_240_);
lean_dec(v___x_240_);
lean_dec(v___x_245_);
v___x_250_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_250_, 0, v___x_249_);
return v___x_250_;
}
}
}
LEAN_EXPORT lean_object* l_RunExperiment_timedRun___boxed(lean_object* v_s_251_, lean_object* v_source_252_, lean_object* v_sink_253_, lean_object* v_expected_254_, lean_object* v_a_255_){
_start:
{
lean_object* v_res_256_; 
v_res_256_ = l_RunExperiment_timedRun(v_s_251_, v_source_252_, v_sink_253_, v_expected_254_);
lean_dec(v_expected_254_);
lean_dec(v_sink_253_);
lean_dec(v_source_252_);
return v_res_256_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0(lean_object* v_00_u03b2_257_, lean_object* v_x_258_){
_start:
{
lean_object* v___x_259_; 
v___x_259_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(v_x_258_);
return v___x_259_;
}
}
LEAN_EXPORT lean_object* l_List_foldl___at___00RunExperiment_timedScan_spec__0(lean_object* v_x_260_, lean_object* v_x_261_){
_start:
{
if (lean_obj_tag(v_x_261_) == 0)
{
return v_x_260_;
}
else
{
lean_object* v_head_262_; lean_object* v_tail_263_; lean_object* v___x_264_; lean_object* v___x_265_; 
v_head_262_ = lean_ctor_get(v_x_261_, 0);
v_tail_263_ = lean_ctor_get(v_x_261_, 1);
v___x_264_ = l_RunExperiment_checksum(v_head_262_);
v___x_265_ = lean_nat_add(v_x_260_, v___x_264_);
lean_dec(v___x_264_);
lean_dec(v_x_260_);
v_x_260_ = v___x_265_;
v_x_261_ = v_tail_263_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_List_foldl___at___00RunExperiment_timedScan_spec__0___boxed(lean_object* v_x_267_, lean_object* v_x_268_){
_start:
{
lean_object* v_res_269_; 
v_res_269_ = l_List_foldl___at___00RunExperiment_timedScan_spec__0(v_x_267_, v_x_268_);
lean_dec(v_x_268_);
return v_res_269_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_timedScan(lean_object* v_source_270_, lean_object* v_sink_271_){
_start:
{
lean_object* v___x_273_; lean_object* v___x_274_; lean_object* v___x_275_; lean_object* v___x_276_; lean_object* v_ret_277_; lean_object* v___x_278_; lean_object* v___x_279_; lean_object* v___x_280_; lean_object* v___x_281_; lean_object* v___x_282_; lean_object* v___x_283_; 
v___x_273_ = lean_io_mono_nanos_now();
v___x_274_ = lean_st_ref_get(v_source_270_);
v___x_275_ = l_LeanSort_RunAdaptive_discover___redArg(v___x_274_);
v___x_276_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(v___x_275_);
v_ret_277_ = lean_ctor_get(v___x_276_, 0);
lean_inc(v_ret_277_);
lean_dec_ref(v___x_276_);
v___x_278_ = lean_unsigned_to_nat(0u);
v___x_279_ = l_List_foldl___at___00RunExperiment_timedScan_spec__0(v___x_278_, v_ret_277_);
lean_dec(v_ret_277_);
v___x_280_ = lean_st_ref_set(v_sink_271_, v___x_279_);
v___x_281_ = lean_io_mono_nanos_now();
v___x_282_ = lean_nat_sub(v___x_281_, v___x_273_);
lean_dec(v___x_273_);
lean_dec(v___x_281_);
v___x_283_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_283_, 0, v___x_282_);
return v___x_283_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_timedScan___boxed(lean_object* v_source_284_, lean_object* v_sink_285_, lean_object* v_a_286_){
_start:
{
lean_object* v_res_287_; 
v_res_287_ = l_RunExperiment_timedScan(v_source_284_, v_sink_285_);
lean_dec(v_sink_285_);
lean_dec(v_source_284_);
return v_res_287_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_timedPlan(lean_object* v_planner_288_, lean_object* v_source_289_, lean_object* v_sink_290_){
_start:
{
lean_object* v___x_292_; lean_object* v___x_293_; lean_object* v___x_294_; lean_object* v___x_295_; lean_object* v___x_296_; lean_object* v___x_297_; lean_object* v___x_298_; lean_object* v___x_299_; lean_object* v___x_300_; lean_object* v___x_301_; 
v___x_292_ = lean_io_mono_nanos_now();
v___x_293_ = lean_st_ref_get(v_source_289_);
v___x_294_ = lean_apply_1(v_planner_288_, v___x_293_);
v___x_295_ = l_LeanSort_RunAdaptive_MergeTree_budget___redArg(v___x_294_);
v___x_296_ = l_LeanSort_RunAdaptive_MergeTree_weight___redArg(v___x_294_);
lean_dec(v___x_294_);
v___x_297_ = lean_nat_add(v___x_295_, v___x_296_);
lean_dec(v___x_296_);
lean_dec(v___x_295_);
v___x_298_ = lean_st_ref_set(v_sink_290_, v___x_297_);
v___x_299_ = lean_io_mono_nanos_now();
v___x_300_ = lean_nat_sub(v___x_299_, v___x_292_);
lean_dec(v___x_292_);
lean_dec(v___x_299_);
v___x_301_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_301_, 0, v___x_300_);
return v___x_301_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_timedPlan___boxed(lean_object* v_planner_302_, lean_object* v_source_303_, lean_object* v_sink_304_, lean_object* v_a_305_){
_start:
{
lean_object* v_res_306_; 
v_res_306_ = l_RunExperiment_timedPlan(v_planner_302_, v_source_303_, v_sink_304_);
lean_dec(v_sink_304_);
lean_dec(v_source_303_);
return v_res_306_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_timedMerge(lean_object* v_source_310_, lean_object* v_sink_311_, lean_object* v_expected_312_){
_start:
{
lean_object* v___x_314_; lean_object* v___x_315_; lean_object* v___x_316_; lean_object* v___x_317_; lean_object* v_ret_318_; lean_object* v___x_319_; lean_object* v___x_320_; lean_object* v___x_321_; uint8_t v___x_322_; 
v___x_314_ = lean_io_mono_nanos_now();
v___x_315_ = lean_st_ref_get(v_source_310_);
v___x_316_ = l_LeanSort_RunAdaptive_MergeTree_program___redArg(v___x_315_);
v___x_317_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(v___x_316_);
v_ret_318_ = lean_ctor_get(v___x_317_, 0);
lean_inc(v_ret_318_);
lean_dec_ref(v___x_317_);
v___x_319_ = l_RunExperiment_checksum(v_ret_318_);
v___x_320_ = lean_st_ref_set(v_sink_311_, v___x_319_);
v___x_321_ = lean_io_mono_nanos_now();
v___x_322_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v_ret_318_, v_expected_312_);
lean_dec(v_ret_318_);
if (v___x_322_ == 0)
{
lean_object* v___x_323_; lean_object* v___x_324_; 
lean_dec(v___x_321_);
lean_dec(v___x_314_);
v___x_323_ = ((lean_object*)(l_RunExperiment_timedMerge___closed__1));
v___x_324_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_324_, 0, v___x_323_);
return v___x_324_;
}
else
{
lean_object* v___x_325_; lean_object* v___x_326_; 
v___x_325_ = lean_nat_sub(v___x_321_, v___x_314_);
lean_dec(v___x_314_);
lean_dec(v___x_321_);
v___x_326_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_326_, 0, v___x_325_);
return v___x_326_;
}
}
}
LEAN_EXPORT lean_object* l_RunExperiment_timedMerge___boxed(lean_object* v_source_327_, lean_object* v_sink_328_, lean_object* v_expected_329_, lean_object* v_a_330_){
_start:
{
lean_object* v_res_331_; 
v_res_331_ = l_RunExperiment_timedMerge(v_source_327_, v_sink_328_, v_expected_329_);
lean_dec(v_expected_329_);
lean_dec(v_sink_328_);
lean_dec(v_source_327_);
return v_res_331_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_diagnostics_spec__0___redArg(lean_object* v_val_332_, lean_object* v_val_333_, lean_object* v_planner_334_, lean_object* v_val_335_, lean_object* v_val_336_, lean_object* v_expected_337_, lean_object* v_as_x27_338_, lean_object* v_b_339_){
_start:
{
if (lean_obj_tag(v_as_x27_338_) == 0)
{
lean_object* v___x_341_; 
lean_dec_ref(v_planner_334_);
v___x_341_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_341_, 0, v_b_339_);
return v___x_341_;
}
else
{
lean_object* v_tail_342_; lean_object* v___x_343_; lean_object* v_a_344_; lean_object* v___x_345_; lean_object* v_a_346_; lean_object* v___x_347_; 
v_tail_342_ = lean_ctor_get(v_as_x27_338_, 1);
v___x_343_ = l_RunExperiment_timedScan(v_val_332_, v_val_333_);
v_a_344_ = lean_ctor_get(v___x_343_, 0);
lean_inc(v_a_344_);
lean_dec_ref(v___x_343_);
lean_inc_ref(v_planner_334_);
v___x_345_ = l_RunExperiment_timedPlan(v_planner_334_, v_val_335_, v_val_333_);
v_a_346_ = lean_ctor_get(v___x_345_, 0);
lean_inc(v_a_346_);
lean_dec_ref(v___x_345_);
v___x_347_ = l_RunExperiment_timedMerge(v_val_336_, v_val_333_, v_expected_337_);
if (lean_obj_tag(v___x_347_) == 0)
{
lean_object* v_snd_348_; lean_object* v_a_349_; lean_object* v_fst_350_; lean_object* v___x_352_; uint8_t v_isShared_353_; uint8_t v_isSharedCheck_370_; 
v_snd_348_ = lean_ctor_get(v_b_339_, 1);
lean_inc(v_snd_348_);
v_a_349_ = lean_ctor_get(v___x_347_, 0);
lean_inc(v_a_349_);
lean_dec_ref_known(v___x_347_, 1);
v_fst_350_ = lean_ctor_get(v_b_339_, 0);
v_isSharedCheck_370_ = !lean_is_exclusive(v_b_339_);
if (v_isSharedCheck_370_ == 0)
{
lean_object* v_unused_371_; 
v_unused_371_ = lean_ctor_get(v_b_339_, 1);
lean_dec(v_unused_371_);
v___x_352_ = v_b_339_;
v_isShared_353_ = v_isSharedCheck_370_;
goto v_resetjp_351_;
}
else
{
lean_inc(v_fst_350_);
lean_dec(v_b_339_);
v___x_352_ = lean_box(0);
v_isShared_353_ = v_isSharedCheck_370_;
goto v_resetjp_351_;
}
v_resetjp_351_:
{
lean_object* v_fst_354_; lean_object* v_snd_355_; lean_object* v___x_357_; uint8_t v_isShared_358_; uint8_t v_isSharedCheck_369_; 
v_fst_354_ = lean_ctor_get(v_snd_348_, 0);
v_snd_355_ = lean_ctor_get(v_snd_348_, 1);
v_isSharedCheck_369_ = !lean_is_exclusive(v_snd_348_);
if (v_isSharedCheck_369_ == 0)
{
v___x_357_ = v_snd_348_;
v_isShared_358_ = v_isSharedCheck_369_;
goto v_resetjp_356_;
}
else
{
lean_inc(v_snd_355_);
lean_inc(v_fst_354_);
lean_dec(v_snd_348_);
v___x_357_ = lean_box(0);
v_isShared_358_ = v_isSharedCheck_369_;
goto v_resetjp_356_;
}
v_resetjp_356_:
{
lean_object* v___x_359_; lean_object* v___x_360_; lean_object* v___x_361_; lean_object* v___x_363_; 
v___x_359_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_359_, 0, v_a_344_);
lean_ctor_set(v___x_359_, 1, v_fst_350_);
v___x_360_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_360_, 0, v_a_346_);
lean_ctor_set(v___x_360_, 1, v_fst_354_);
v___x_361_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_361_, 0, v_a_349_);
lean_ctor_set(v___x_361_, 1, v_snd_355_);
if (v_isShared_358_ == 0)
{
lean_ctor_set(v___x_357_, 1, v___x_361_);
lean_ctor_set(v___x_357_, 0, v___x_360_);
v___x_363_ = v___x_357_;
goto v_reusejp_362_;
}
else
{
lean_object* v_reuseFailAlloc_368_; 
v_reuseFailAlloc_368_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_368_, 0, v___x_360_);
lean_ctor_set(v_reuseFailAlloc_368_, 1, v___x_361_);
v___x_363_ = v_reuseFailAlloc_368_;
goto v_reusejp_362_;
}
v_reusejp_362_:
{
lean_object* v___x_365_; 
if (v_isShared_353_ == 0)
{
lean_ctor_set(v___x_352_, 1, v___x_363_);
lean_ctor_set(v___x_352_, 0, v___x_359_);
v___x_365_ = v___x_352_;
goto v_reusejp_364_;
}
else
{
lean_object* v_reuseFailAlloc_367_; 
v_reuseFailAlloc_367_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_367_, 0, v___x_359_);
lean_ctor_set(v_reuseFailAlloc_367_, 1, v___x_363_);
v___x_365_ = v_reuseFailAlloc_367_;
goto v_reusejp_364_;
}
v_reusejp_364_:
{
v_as_x27_338_ = v_tail_342_;
v_b_339_ = v___x_365_;
goto _start;
}
}
}
}
}
else
{
lean_object* v_a_372_; lean_object* v___x_374_; uint8_t v_isShared_375_; uint8_t v_isSharedCheck_379_; 
lean_dec(v_a_346_);
lean_dec(v_a_344_);
lean_dec_ref(v_b_339_);
lean_dec_ref(v_planner_334_);
v_a_372_ = lean_ctor_get(v___x_347_, 0);
v_isSharedCheck_379_ = !lean_is_exclusive(v___x_347_);
if (v_isSharedCheck_379_ == 0)
{
v___x_374_ = v___x_347_;
v_isShared_375_ = v_isSharedCheck_379_;
goto v_resetjp_373_;
}
else
{
lean_inc(v_a_372_);
lean_dec(v___x_347_);
v___x_374_ = lean_box(0);
v_isShared_375_ = v_isSharedCheck_379_;
goto v_resetjp_373_;
}
v_resetjp_373_:
{
lean_object* v___x_377_; 
if (v_isShared_375_ == 0)
{
v___x_377_ = v___x_374_;
goto v_reusejp_376_;
}
else
{
lean_object* v_reuseFailAlloc_378_; 
v_reuseFailAlloc_378_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_378_, 0, v_a_372_);
v___x_377_ = v_reuseFailAlloc_378_;
goto v_reusejp_376_;
}
v_reusejp_376_:
{
return v___x_377_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_diagnostics_spec__0___redArg___boxed(lean_object* v_val_380_, lean_object* v_val_381_, lean_object* v_planner_382_, lean_object* v_val_383_, lean_object* v_val_384_, lean_object* v_expected_385_, lean_object* v_as_x27_386_, lean_object* v_b_387_, lean_object* v___y_388_){
_start:
{
lean_object* v_res_389_; 
v_res_389_ = l_List_forIn_x27_loop___at___00RunExperiment_diagnostics_spec__0___redArg(v_val_380_, v_val_381_, v_planner_382_, v_val_383_, v_val_384_, v_expected_385_, v_as_x27_386_, v_b_387_);
lean_dec(v_as_x27_386_);
lean_dec(v_expected_385_);
lean_dec(v_val_384_);
lean_dec(v_val_383_);
lean_dec(v_val_381_);
lean_dec(v_val_380_);
return v_res_389_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_diagnostics(lean_object* v_planner_398_, lean_object* v_xs_399_, lean_object* v_expected_400_, lean_object* v_rounds_401_){
_start:
{
lean_object* v___x_403_; lean_object* v___x_404_; lean_object* v___x_405_; lean_object* v_ret_406_; lean_object* v___x_408_; uint8_t v_isShared_409_; uint8_t v_isSharedCheck_469_; 
lean_inc(v_xs_399_);
v___x_403_ = lean_st_mk_ref(v_xs_399_);
v___x_404_ = l_LeanSort_RunAdaptive_discover___redArg(v_xs_399_);
v___x_405_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(v___x_404_);
v_ret_406_ = lean_ctor_get(v___x_405_, 0);
v_isSharedCheck_469_ = !lean_is_exclusive(v___x_405_);
if (v_isSharedCheck_469_ == 0)
{
lean_object* v_unused_470_; 
v_unused_470_ = lean_ctor_get(v___x_405_, 1);
lean_dec(v_unused_470_);
v___x_408_ = v___x_405_;
v_isShared_409_ = v_isSharedCheck_469_;
goto v_resetjp_407_;
}
else
{
lean_inc(v_ret_406_);
lean_dec(v___x_405_);
v___x_408_ = lean_box(0);
v_isShared_409_ = v_isSharedCheck_469_;
goto v_resetjp_407_;
}
v_resetjp_407_:
{
lean_object* v___x_410_; lean_object* v___x_411_; lean_object* v___x_412_; lean_object* v___x_413_; lean_object* v___x_414_; lean_object* v___x_415_; lean_object* v___x_416_; lean_object* v___x_417_; lean_object* v___x_418_; 
lean_inc_ref(v_planner_398_);
lean_inc(v_ret_406_);
v___x_410_ = lean_apply_1(v_planner_398_, v_ret_406_);
v___x_411_ = lean_st_mk_ref(v_ret_406_);
v___x_412_ = lean_st_mk_ref(v___x_410_);
v___x_413_ = lean_unsigned_to_nat(0u);
v___x_414_ = lean_st_mk_ref(v___x_413_);
v___x_415_ = lean_box(0);
v___x_416_ = l_List_range(v_rounds_401_);
v___x_417_ = ((lean_object*)(l_RunExperiment_diagnostics___closed__1));
v___x_418_ = l_List_forIn_x27_loop___at___00RunExperiment_diagnostics_spec__0___redArg(v___x_403_, v___x_414_, v_planner_398_, v___x_411_, v___x_412_, v_expected_400_, v___x_416_, v___x_417_);
lean_dec(v___x_416_);
lean_dec(v___x_412_);
lean_dec(v___x_411_);
lean_dec(v___x_414_);
lean_dec(v___x_403_);
if (lean_obj_tag(v___x_418_) == 0)
{
lean_object* v_a_419_; lean_object* v___x_421_; uint8_t v_isShared_422_; uint8_t v_isSharedCheck_460_; 
v_a_419_ = lean_ctor_get(v___x_418_, 0);
v_isSharedCheck_460_ = !lean_is_exclusive(v___x_418_);
if (v_isSharedCheck_460_ == 0)
{
v___x_421_ = v___x_418_;
v_isShared_422_ = v_isSharedCheck_460_;
goto v_resetjp_420_;
}
else
{
lean_inc(v_a_419_);
lean_dec(v___x_418_);
v___x_421_ = lean_box(0);
v_isShared_422_ = v_isSharedCheck_460_;
goto v_resetjp_420_;
}
v_resetjp_420_:
{
lean_object* v_snd_423_; lean_object* v_fst_424_; lean_object* v___x_426_; uint8_t v_isShared_427_; uint8_t v_isSharedCheck_459_; 
v_snd_423_ = lean_ctor_get(v_a_419_, 1);
v_fst_424_ = lean_ctor_get(v_a_419_, 0);
v_isSharedCheck_459_ = !lean_is_exclusive(v_a_419_);
if (v_isSharedCheck_459_ == 0)
{
v___x_426_ = v_a_419_;
v_isShared_427_ = v_isSharedCheck_459_;
goto v_resetjp_425_;
}
else
{
lean_inc(v_snd_423_);
lean_inc(v_fst_424_);
lean_dec(v_a_419_);
v___x_426_ = lean_box(0);
v_isShared_427_ = v_isSharedCheck_459_;
goto v_resetjp_425_;
}
v_resetjp_425_:
{
lean_object* v_fst_428_; lean_object* v_snd_429_; lean_object* v___x_431_; uint8_t v_isShared_432_; uint8_t v_isSharedCheck_458_; 
v_fst_428_ = lean_ctor_get(v_snd_423_, 0);
v_snd_429_ = lean_ctor_get(v_snd_423_, 1);
v_isSharedCheck_458_ = !lean_is_exclusive(v_snd_423_);
if (v_isSharedCheck_458_ == 0)
{
v___x_431_ = v_snd_423_;
v_isShared_432_ = v_isSharedCheck_458_;
goto v_resetjp_430_;
}
else
{
lean_inc(v_snd_429_);
lean_inc(v_fst_428_);
lean_dec(v_snd_423_);
v___x_431_ = lean_box(0);
v_isShared_432_ = v_isSharedCheck_458_;
goto v_resetjp_430_;
}
v_resetjp_430_:
{
lean_object* v___x_433_; lean_object* v___x_434_; lean_object* v___x_435_; lean_object* v___x_437_; 
v___x_433_ = ((lean_object*)(l_RunExperiment_diagnostics___closed__2));
v___x_434_ = l_List_reverse___redArg(v_fst_424_);
v___x_435_ = l_Lean_List_toJson___at___00RunExperiment_shape_spec__0(v___x_434_);
if (v_isShared_432_ == 0)
{
lean_ctor_set(v___x_431_, 1, v___x_435_);
lean_ctor_set(v___x_431_, 0, v___x_433_);
v___x_437_ = v___x_431_;
goto v_reusejp_436_;
}
else
{
lean_object* v_reuseFailAlloc_457_; 
v_reuseFailAlloc_457_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_457_, 0, v___x_433_);
lean_ctor_set(v_reuseFailAlloc_457_, 1, v___x_435_);
v___x_437_ = v_reuseFailAlloc_457_;
goto v_reusejp_436_;
}
v_reusejp_436_:
{
lean_object* v___x_438_; lean_object* v___x_439_; lean_object* v___x_440_; lean_object* v___x_442_; 
v___x_438_ = ((lean_object*)(l_RunExperiment_diagnostics___closed__3));
v___x_439_ = l_List_reverse___redArg(v_fst_428_);
v___x_440_ = l_Lean_List_toJson___at___00RunExperiment_shape_spec__0(v___x_439_);
if (v_isShared_427_ == 0)
{
lean_ctor_set(v___x_426_, 1, v___x_440_);
lean_ctor_set(v___x_426_, 0, v___x_438_);
v___x_442_ = v___x_426_;
goto v_reusejp_441_;
}
else
{
lean_object* v_reuseFailAlloc_456_; 
v_reuseFailAlloc_456_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_456_, 0, v___x_438_);
lean_ctor_set(v_reuseFailAlloc_456_, 1, v___x_440_);
v___x_442_ = v_reuseFailAlloc_456_;
goto v_reusejp_441_;
}
v_reusejp_441_:
{
lean_object* v___x_443_; lean_object* v___x_444_; lean_object* v___x_445_; lean_object* v___x_447_; 
v___x_443_ = ((lean_object*)(l_RunExperiment_diagnostics___closed__4));
v___x_444_ = l_List_reverse___redArg(v_snd_429_);
v___x_445_ = l_Lean_List_toJson___at___00RunExperiment_shape_spec__0(v___x_444_);
if (v_isShared_409_ == 0)
{
lean_ctor_set(v___x_408_, 1, v___x_445_);
lean_ctor_set(v___x_408_, 0, v___x_443_);
v___x_447_ = v___x_408_;
goto v_reusejp_446_;
}
else
{
lean_object* v_reuseFailAlloc_455_; 
v_reuseFailAlloc_455_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_455_, 0, v___x_443_);
lean_ctor_set(v_reuseFailAlloc_455_, 1, v___x_445_);
v___x_447_ = v_reuseFailAlloc_455_;
goto v_reusejp_446_;
}
v_reusejp_446_:
{
lean_object* v___x_448_; lean_object* v___x_449_; lean_object* v___x_450_; lean_object* v___x_451_; lean_object* v___x_453_; 
v___x_448_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_448_, 0, v___x_447_);
lean_ctor_set(v___x_448_, 1, v___x_415_);
v___x_449_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_449_, 0, v___x_442_);
lean_ctor_set(v___x_449_, 1, v___x_448_);
v___x_450_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_450_, 0, v___x_437_);
lean_ctor_set(v___x_450_, 1, v___x_449_);
v___x_451_ = l_Lean_Json_mkObj(v___x_450_);
lean_dec_ref_known(v___x_450_, 2);
if (v_isShared_422_ == 0)
{
lean_ctor_set(v___x_421_, 0, v___x_451_);
v___x_453_ = v___x_421_;
goto v_reusejp_452_;
}
else
{
lean_object* v_reuseFailAlloc_454_; 
v_reuseFailAlloc_454_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_454_, 0, v___x_451_);
v___x_453_ = v_reuseFailAlloc_454_;
goto v_reusejp_452_;
}
v_reusejp_452_:
{
return v___x_453_;
}
}
}
}
}
}
}
}
else
{
lean_object* v_a_461_; lean_object* v___x_463_; uint8_t v_isShared_464_; uint8_t v_isSharedCheck_468_; 
lean_del_object(v___x_408_);
v_a_461_ = lean_ctor_get(v___x_418_, 0);
v_isSharedCheck_468_ = !lean_is_exclusive(v___x_418_);
if (v_isSharedCheck_468_ == 0)
{
v___x_463_ = v___x_418_;
v_isShared_464_ = v_isSharedCheck_468_;
goto v_resetjp_462_;
}
else
{
lean_inc(v_a_461_);
lean_dec(v___x_418_);
v___x_463_ = lean_box(0);
v_isShared_464_ = v_isSharedCheck_468_;
goto v_resetjp_462_;
}
v_resetjp_462_:
{
lean_object* v___x_466_; 
if (v_isShared_464_ == 0)
{
v___x_466_ = v___x_463_;
goto v_reusejp_465_;
}
else
{
lean_object* v_reuseFailAlloc_467_; 
v_reuseFailAlloc_467_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_467_, 0, v_a_461_);
v___x_466_ = v_reuseFailAlloc_467_;
goto v_reusejp_465_;
}
v_reusejp_465_:
{
return v___x_466_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_RunExperiment_diagnostics___boxed(lean_object* v_planner_471_, lean_object* v_xs_472_, lean_object* v_expected_473_, lean_object* v_rounds_474_, lean_object* v_a_475_){
_start:
{
lean_object* v_res_476_; 
v_res_476_ = l_RunExperiment_diagnostics(v_planner_471_, v_xs_472_, v_expected_473_, v_rounds_474_);
lean_dec(v_expected_473_);
return v_res_476_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_diagnostics_spec__0(lean_object* v_val_477_, lean_object* v_val_478_, lean_object* v_planner_479_, lean_object* v_val_480_, lean_object* v_val_481_, lean_object* v_expected_482_, lean_object* v_as_483_, lean_object* v_as_x27_484_, lean_object* v_b_485_, lean_object* v_a_486_){
_start:
{
lean_object* v___x_488_; 
v___x_488_ = l_List_forIn_x27_loop___at___00RunExperiment_diagnostics_spec__0___redArg(v_val_477_, v_val_478_, v_planner_479_, v_val_480_, v_val_481_, v_expected_482_, v_as_x27_484_, v_b_485_);
return v___x_488_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_diagnostics_spec__0___boxed(lean_object* v_val_489_, lean_object* v_val_490_, lean_object* v_planner_491_, lean_object* v_val_492_, lean_object* v_val_493_, lean_object* v_expected_494_, lean_object* v_as_495_, lean_object* v_as_x27_496_, lean_object* v_b_497_, lean_object* v_a_498_, lean_object* v___y_499_){
_start:
{
lean_object* v_res_500_; 
v_res_500_ = l_List_forIn_x27_loop___at___00RunExperiment_diagnostics_spec__0(v_val_489_, v_val_490_, v_planner_491_, v_val_492_, v_val_493_, v_expected_494_, v_as_495_, v_as_x27_496_, v_b_497_, v_a_498_);
lean_dec(v_as_x27_496_);
lean_dec(v_as_495_);
lean_dec(v_expected_494_);
lean_dec(v_val_493_);
lean_dec(v_val_492_);
lean_dec(v_val_490_);
lean_dec(v_val_489_);
return v_res_500_;
}
}
LEAN_EXPORT uint8_t l_LeanSort_CostedPlan_Schema_readyCheck___at___00RunExperiment_profile_spec__1(lean_object* v_x_503_, lean_object* v_x_504_){
_start:
{
switch(lean_obj_tag(v_x_503_))
{
case 0:
{
uint8_t v___x_505_; 
lean_dec(v_x_504_);
v___x_505_ = 1;
return v___x_505_;
}
case 1:
{
lean_object* v_cut_506_; lean_object* v_left_507_; lean_object* v_right_508_; lean_object* v___x_509_; lean_object* v___x_510_; lean_object* v___x_511_; lean_object* v___x_512_; uint8_t v___x_513_; 
v_cut_506_ = lean_ctor_get(v_x_503_, 0);
v_left_507_ = lean_ctor_get(v_x_503_, 1);
v_right_508_ = lean_ctor_get(v_x_503_, 2);
v___x_509_ = l_List_lengthTR___redArg(v_x_504_);
v___x_510_ = lp_leansort_LeanSort_CostedPlan_Cut_position(v_cut_506_, v___x_509_);
lean_dec(v___x_509_);
v___x_511_ = ((lean_object*)(l_LeanSort_CostedPlan_Schema_readyCheck___at___00RunExperiment_profile_spec__1___closed__0));
lean_inc(v___x_510_);
lean_inc(v_x_504_);
v___x_512_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_x_504_, v_x_504_, v___x_510_, v___x_511_);
v___x_513_ = l_LeanSort_CostedPlan_Schema_readyCheck___at___00RunExperiment_profile_spec__1(v_left_507_, v___x_512_);
if (v___x_513_ == 0)
{
lean_dec(v___x_510_);
lean_dec(v_x_504_);
return v___x_513_;
}
else
{
lean_object* v___x_514_; 
v___x_514_ = l_List_drop___redArg(v___x_510_, v_x_504_);
lean_dec(v_x_504_);
v_x_503_ = v_right_508_;
v_x_504_ = v___x_514_;
goto _start;
}
}
default: 
{
lean_object* v___x_516_; lean_object* v___x_517_; lean_object* v_ret_518_; uint8_t v___x_519_; 
v___x_516_ = lp_leansort_LeanSort_ComparisonSort_checkSorted___redArg(v_x_504_);
v___x_517_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(v___x_516_);
v_ret_518_ = lean_ctor_get(v___x_517_, 0);
lean_inc(v_ret_518_);
lean_dec_ref(v___x_517_);
v___x_519_ = lean_unbox(v_ret_518_);
lean_dec(v_ret_518_);
return v___x_519_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_CostedPlan_Schema_readyCheck___at___00RunExperiment_profile_spec__1___boxed(lean_object* v_x_520_, lean_object* v_x_521_){
_start:
{
uint8_t v_res_522_; lean_object* v_r_523_; 
v_res_522_ = l_LeanSort_CostedPlan_Schema_readyCheck___at___00RunExperiment_profile_spec__1(v_x_520_, v_x_521_);
lean_dec_ref(v_x_520_);
v_r_523_ = lean_box(v_res_522_);
return v_r_523_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_RunAdaptive_runCount___at___00LeanSort_RunAdaptive_Strategy_bound___at___00RunExperiment_profile_spec__0_spec__0(lean_object* v_xs_524_){
_start:
{
lean_object* v___x_525_; lean_object* v___x_526_; lean_object* v_ret_527_; lean_object* v___x_528_; 
v___x_525_ = l_LeanSort_RunAdaptive_discover___redArg(v_xs_524_);
v___x_526_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(v___x_525_);
v_ret_527_ = lean_ctor_get(v___x_526_, 0);
lean_inc(v_ret_527_);
lean_dec_ref(v___x_526_);
v___x_528_ = l_List_lengthTR___redArg(v_ret_527_);
lean_dec(v_ret_527_);
return v___x_528_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_RunAdaptive_Strategy_bound___at___00RunExperiment_profile_spec__0(lean_object* v_x_529_, lean_object* v_x_530_){
_start:
{
switch(lean_obj_tag(v_x_529_))
{
case 0:
{
lean_object* v_schema_531_; lean_object* v___x_532_; lean_object* v___x_533_; 
v_schema_531_ = lean_ctor_get(v_x_529_, 0);
v___x_532_ = l_List_lengthTR___redArg(v_x_530_);
lean_dec(v_x_530_);
v___x_533_ = lp_leansort_LeanSort_CostedPlan_Schema_upper(v_schema_531_, v___x_532_);
lean_dec(v___x_532_);
return v___x_533_;
}
case 1:
{
lean_object* v___x_534_; lean_object* v___x_535_; lean_object* v___x_536_; 
v___x_534_ = l_List_lengthTR___redArg(v_x_530_);
v___x_535_ = l_LeanSort_RunAdaptive_runCount___at___00LeanSort_RunAdaptive_Strategy_bound___at___00RunExperiment_profile_spec__0_spec__0(v_x_530_);
v___x_536_ = l_LeanSort_RunAdaptive_upper(v___x_534_, v___x_535_);
lean_dec(v___x_535_);
lean_dec(v___x_534_);
return v___x_536_;
}
default: 
{
lean_object* v___x_537_; lean_object* v___x_538_; lean_object* v___x_539_; lean_object* v_ret_540_; lean_object* v___x_541_; lean_object* v___x_542_; lean_object* v___x_543_; lean_object* v___x_544_; lean_object* v___x_545_; 
v___x_537_ = l_List_lengthTR___redArg(v_x_530_);
v___x_538_ = l_LeanSort_RunAdaptive_discover___redArg(v_x_530_);
v___x_539_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(v___x_538_);
v_ret_540_ = lean_ctor_get(v___x_539_, 0);
lean_inc(v_ret_540_);
lean_dec_ref(v___x_539_);
v___x_541_ = lean_unsigned_to_nat(1u);
v___x_542_ = lean_nat_sub(v___x_537_, v___x_541_);
lean_dec(v___x_537_);
v___x_543_ = l_LeanSort_RunAdaptive_lengthPlan___redArg(v_ret_540_);
v___x_544_ = l_LeanSort_RunAdaptive_MergeTree_budget___redArg(v___x_543_);
lean_dec(v___x_543_);
v___x_545_ = lean_nat_add(v___x_542_, v___x_544_);
lean_dec(v___x_544_);
lean_dec(v___x_542_);
return v___x_545_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_RunAdaptive_Strategy_bound___at___00RunExperiment_profile_spec__0___boxed(lean_object* v_x_546_, lean_object* v_x_547_){
_start:
{
lean_object* v_res_548_; 
v_res_548_ = l_LeanSort_RunAdaptive_Strategy_bound___at___00RunExperiment_profile_spec__0(v_x_546_, v_x_547_);
lean_dec(v_x_546_);
return v_res_548_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_profile(lean_object* v_s_566_, lean_object* v_xs_567_, lean_object* v_expected_568_){
_start:
{
lean_object* v___x_570_; lean_object* v_result_571_; lean_object* v___y_573_; lean_object* v___y_574_; lean_object* v___y_575_; lean_object* v___y_576_; lean_object* v___y_577_; uint8_t v___y_578_; lean_object* v___y_627_; lean_object* v___y_628_; lean_object* v___y_629_; lean_object* v___y_630_; lean_object* v___y_631_; uint8_t v___y_632_; uint8_t v___y_633_; lean_object* v_fst_649_; lean_object* v_fst_650_; lean_object* v_fst_651_; uint8_t v_fst_652_; lean_object* v_snd_653_; lean_object* v_ret_658_; uint8_t v___x_659_; 
lean_inc(v_xs_567_);
lean_inc(v_s_566_);
v___x_570_ = l_LeanSort_RunAdaptive_Strategy_program___redArg(v_s_566_, v_xs_567_);
v_result_571_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(v___x_570_);
v_ret_658_ = lean_ctor_get(v_result_571_, 0);
lean_inc(v_ret_658_);
v___x_659_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v_ret_658_, v_expected_568_);
lean_dec(v_ret_658_);
if (v___x_659_ == 0)
{
lean_object* v___x_660_; lean_object* v___x_661_; 
lean_dec_ref(v_result_571_);
lean_dec(v_xs_567_);
lean_dec(v_s_566_);
v___x_660_ = ((lean_object*)(l_RunExperiment_profile___closed__13));
v___x_661_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_661_, 0, v___x_660_);
return v___x_661_;
}
else
{
lean_object* v___x_662_; lean_object* v___x_663_; 
lean_inc(v_xs_567_);
v___x_662_ = l_LeanSort_RunAdaptive_discover___redArg(v_xs_567_);
v___x_663_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(v___x_662_);
switch(lean_obj_tag(v_s_566_))
{
case 0:
{
lean_object* v_schema_664_; lean_object* v___x_665_; lean_object* v___x_666_; lean_object* v_time_667_; lean_object* v___x_668_; lean_object* v___x_669_; lean_object* v___x_670_; lean_object* v___x_671_; lean_object* v___x_672_; lean_object* v___x_673_; uint8_t v___x_674_; lean_object* v___x_675_; lean_object* v___x_676_; lean_object* v___x_677_; 
lean_dec_ref(v___x_663_);
v_schema_664_ = lean_ctor_get(v_s_566_, 0);
lean_inc_n(v_xs_567_, 2);
lean_inc_ref_n(v_schema_664_, 2);
v___x_665_ = lp_leansort_LeanSort_CostedPlan_Schema_checkProgram___redArg(v_schema_664_, v_xs_567_);
v___x_666_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(v___x_665_);
v_time_667_ = lean_ctor_get(v___x_666_, 1);
lean_inc(v_time_667_);
lean_dec_ref(v___x_666_);
v___x_668_ = lean_unsigned_to_nat(0u);
v___x_669_ = lp_leansort_LeanSort_CostedPlan_instReprSchema_repr(v_schema_664_, v___x_668_);
v___x_670_ = lean_unsigned_to_nat(120u);
v___x_671_ = l_Std_Format_pretty(v___x_669_, v___x_670_, v___x_668_, v___x_668_);
v___x_672_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_672_, 0, v___x_671_);
v___x_673_ = lean_box(0);
v___x_674_ = l_LeanSort_CostedPlan_Schema_readyCheck___at___00RunExperiment_profile_spec__1(v_schema_664_, v_xs_567_);
v___x_675_ = l_List_lengthTR___redArg(v_xs_567_);
v___x_676_ = lp_leansort_LeanSort_CostedPlan_Schema_readyUpper(v_schema_664_, v___x_675_);
lean_dec(v___x_675_);
v___x_677_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_677_, 0, v___x_676_);
v_fst_649_ = v_time_667_;
v_fst_650_ = v___x_672_;
v_fst_651_ = v___x_673_;
v_fst_652_ = v___x_674_;
v_snd_653_ = v___x_677_;
goto v___jp_648_;
}
case 1:
{
lean_object* v_ret_678_; lean_object* v___x_679_; lean_object* v___x_680_; lean_object* v___x_681_; lean_object* v___x_682_; lean_object* v___x_683_; lean_object* v___x_684_; lean_object* v___x_685_; uint8_t v___x_686_; lean_object* v___x_687_; 
v_ret_678_ = lean_ctor_get(v___x_663_, 0);
lean_inc(v_ret_678_);
lean_dec_ref(v___x_663_);
v___x_679_ = l_List_lengthTR___redArg(v_xs_567_);
v___x_680_ = lean_unsigned_to_nat(1u);
v___x_681_ = lean_nat_sub(v___x_679_, v___x_680_);
lean_dec(v___x_679_);
v___x_682_ = l_LeanSort_RunAdaptive_countPlan___redArg(v_ret_678_);
lean_inc(v___x_682_);
v___x_683_ = l_RunExperiment_shape(v___x_682_);
v___x_684_ = l_LeanSort_RunAdaptive_MergeTree_budget___redArg(v___x_682_);
lean_dec(v___x_682_);
v___x_685_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_685_, 0, v___x_684_);
v___x_686_ = 0;
v___x_687_ = lean_box(0);
v_fst_649_ = v___x_681_;
v_fst_650_ = v___x_683_;
v_fst_651_ = v___x_685_;
v_fst_652_ = v___x_686_;
v_snd_653_ = v___x_687_;
goto v___jp_648_;
}
default: 
{
lean_object* v_ret_688_; lean_object* v___x_689_; lean_object* v___x_690_; lean_object* v___x_691_; lean_object* v___x_692_; lean_object* v___x_693_; lean_object* v___x_694_; lean_object* v___x_695_; uint8_t v___x_696_; lean_object* v___x_697_; 
v_ret_688_ = lean_ctor_get(v___x_663_, 0);
lean_inc(v_ret_688_);
lean_dec_ref(v___x_663_);
v___x_689_ = l_List_lengthTR___redArg(v_xs_567_);
v___x_690_ = lean_unsigned_to_nat(1u);
v___x_691_ = lean_nat_sub(v___x_689_, v___x_690_);
lean_dec(v___x_689_);
v___x_692_ = l_LeanSort_RunAdaptive_lengthPlan___redArg(v_ret_688_);
lean_inc(v___x_692_);
v___x_693_ = l_RunExperiment_shape(v___x_692_);
v___x_694_ = l_LeanSort_RunAdaptive_MergeTree_budget___redArg(v___x_692_);
lean_dec(v___x_692_);
v___x_695_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_695_, 0, v___x_694_);
v___x_696_ = 0;
v___x_697_ = lean_box(0);
v_fst_649_ = v___x_691_;
v_fst_650_ = v___x_693_;
v_fst_651_ = v___x_695_;
v_fst_652_ = v___x_696_;
v_snd_653_ = v___x_697_;
goto v___jp_648_;
}
}
}
v___jp_572_:
{
lean_object* v_time_579_; lean_object* v___x_581_; uint8_t v_isShared_582_; uint8_t v_isSharedCheck_624_; 
v_time_579_ = lean_ctor_get(v_result_571_, 1);
v_isSharedCheck_624_ = !lean_is_exclusive(v_result_571_);
if (v_isSharedCheck_624_ == 0)
{
lean_object* v_unused_625_; 
v_unused_625_ = lean_ctor_get(v_result_571_, 0);
lean_dec(v_unused_625_);
v___x_581_ = v_result_571_;
v_isShared_582_ = v_isSharedCheck_624_;
goto v_resetjp_580_;
}
else
{
lean_inc(v_time_579_);
lean_dec(v_result_571_);
v___x_581_ = lean_box(0);
v_isShared_582_ = v_isSharedCheck_624_;
goto v_resetjp_580_;
}
v_resetjp_580_:
{
lean_object* v___x_583_; lean_object* v___x_584_; lean_object* v___x_585_; lean_object* v___x_587_; 
v___x_583_ = ((lean_object*)(l_RunExperiment_profile___closed__0));
lean_inc(v_time_579_);
v___x_584_ = l_Lean_JsonNumber_fromNat(v_time_579_);
v___x_585_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_585_, 0, v___x_584_);
if (v_isShared_582_ == 0)
{
lean_ctor_set(v___x_581_, 1, v___x_585_);
lean_ctor_set(v___x_581_, 0, v___x_583_);
v___x_587_ = v___x_581_;
goto v_reusejp_586_;
}
else
{
lean_object* v_reuseFailAlloc_623_; 
v_reuseFailAlloc_623_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_623_, 0, v___x_583_);
lean_ctor_set(v_reuseFailAlloc_623_, 1, v___x_585_);
v___x_587_ = v_reuseFailAlloc_623_;
goto v_reusejp_586_;
}
v_reusejp_586_:
{
lean_object* v___x_588_; lean_object* v___x_589_; lean_object* v___x_590_; lean_object* v___x_591_; lean_object* v___x_592_; lean_object* v___x_593_; lean_object* v___x_594_; lean_object* v___x_595_; lean_object* v___x_596_; lean_object* v___x_597_; lean_object* v___x_598_; lean_object* v___x_599_; lean_object* v___x_600_; lean_object* v___x_601_; lean_object* v___x_602_; lean_object* v___x_603_; lean_object* v___x_604_; lean_object* v___x_605_; lean_object* v___x_606_; lean_object* v___x_607_; lean_object* v___x_608_; lean_object* v___x_609_; lean_object* v___x_610_; lean_object* v___x_611_; lean_object* v___x_612_; lean_object* v___x_613_; lean_object* v___x_614_; lean_object* v___x_615_; lean_object* v___x_616_; lean_object* v___x_617_; lean_object* v___x_618_; lean_object* v___x_619_; lean_object* v___x_620_; lean_object* v___x_621_; lean_object* v___x_622_; 
v___x_588_ = ((lean_object*)(l_RunExperiment_profile___closed__1));
lean_inc(v___y_575_);
v___x_589_ = l_Lean_JsonNumber_fromNat(v___y_575_);
v___x_590_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_590_, 0, v___x_589_);
v___x_591_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_591_, 0, v___x_588_);
lean_ctor_set(v___x_591_, 1, v___x_590_);
v___x_592_ = ((lean_object*)(l_RunExperiment_profile___closed__2));
v___x_593_ = lean_nat_sub(v_time_579_, v___y_575_);
lean_dec(v___y_575_);
lean_dec(v_time_579_);
v___x_594_ = l_Lean_JsonNumber_fromNat(v___x_593_);
v___x_595_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_595_, 0, v___x_594_);
v___x_596_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_596_, 0, v___x_592_);
lean_ctor_set(v___x_596_, 1, v___x_595_);
v___x_597_ = ((lean_object*)(l_RunExperiment_profile___closed__3));
v___x_598_ = l_Lean_JsonNumber_fromNat(v___y_576_);
v___x_599_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_599_, 0, v___x_598_);
v___x_600_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_600_, 0, v___x_597_);
lean_ctor_set(v___x_600_, 1, v___x_599_);
v___x_601_ = ((lean_object*)(l_RunExperiment_profile___closed__4));
v___x_602_ = l_Lean_Option_toJson___at___00Lean_Json_toStructured_x3f___at___00Lean_Server_FileWorker_sendServerRequest___at___00Lean_Server_FileWorker_runRefreshTasks_spec__0_spec__1_spec__3(v___y_574_);
v___x_603_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_603_, 0, v___x_601_);
lean_ctor_set(v___x_603_, 1, v___x_602_);
v___x_604_ = ((lean_object*)(l_RunExperiment_profile___closed__5));
v___x_605_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_605_, 0, v___y_578_);
v___x_606_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_606_, 0, v___x_604_);
lean_ctor_set(v___x_606_, 1, v___x_605_);
v___x_607_ = ((lean_object*)(l_RunExperiment_profile___closed__6));
v___x_608_ = l_Lean_Option_toJson___at___00Lean_Json_toStructured_x3f___at___00Lean_Server_FileWorker_sendServerRequest___at___00Lean_Server_FileWorker_runRefreshTasks_spec__0_spec__1_spec__3(v___y_577_);
v___x_609_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_609_, 0, v___x_607_);
lean_ctor_set(v___x_609_, 1, v___x_608_);
v___x_610_ = ((lean_object*)(l_RunExperiment_profile___closed__7));
v___x_611_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_611_, 0, v___x_610_);
lean_ctor_set(v___x_611_, 1, v___y_573_);
v___x_612_ = lean_box(0);
v___x_613_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_613_, 0, v___x_611_);
lean_ctor_set(v___x_613_, 1, v___x_612_);
v___x_614_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_614_, 0, v___x_609_);
lean_ctor_set(v___x_614_, 1, v___x_613_);
v___x_615_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_615_, 0, v___x_606_);
lean_ctor_set(v___x_615_, 1, v___x_614_);
v___x_616_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_616_, 0, v___x_603_);
lean_ctor_set(v___x_616_, 1, v___x_615_);
v___x_617_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_617_, 0, v___x_600_);
lean_ctor_set(v___x_617_, 1, v___x_616_);
v___x_618_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_618_, 0, v___x_596_);
lean_ctor_set(v___x_618_, 1, v___x_617_);
v___x_619_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_619_, 0, v___x_591_);
lean_ctor_set(v___x_619_, 1, v___x_618_);
v___x_620_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_620_, 0, v___x_587_);
lean_ctor_set(v___x_620_, 1, v___x_619_);
v___x_621_ = l_Lean_Json_mkObj(v___x_620_);
lean_dec_ref_known(v___x_620_, 2);
v___x_622_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_622_, 0, v___x_621_);
return v___x_622_;
}
}
}
v___jp_626_:
{
if (v___y_633_ == 0)
{
lean_object* v___x_634_; lean_object* v___x_635_; 
lean_dec(v___y_631_);
lean_dec(v___y_630_);
lean_dec(v___y_629_);
lean_dec(v___y_628_);
lean_dec(v___y_627_);
lean_dec_ref(v_result_571_);
v___x_634_ = ((lean_object*)(l_RunExperiment_profile___closed__9));
v___x_635_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_635_, 0, v___x_634_);
return v___x_635_;
}
else
{
if (v___y_632_ == 0)
{
v___y_573_ = v___y_627_;
v___y_574_ = v___y_628_;
v___y_575_ = v___y_629_;
v___y_576_ = v___y_630_;
v___y_577_ = v___y_631_;
v___y_578_ = v___y_632_;
goto v___jp_572_;
}
else
{
if (lean_obj_tag(v___y_631_) == 1)
{
lean_object* v_val_636_; lean_object* v_time_637_; uint8_t v___x_638_; 
v_val_636_ = lean_ctor_get(v___y_631_, 0);
v_time_637_ = lean_ctor_get(v_result_571_, 1);
lean_inc(v_time_637_);
v___x_638_ = lean_nat_dec_le(v_time_637_, v_val_636_);
lean_dec(v_time_637_);
if (v___x_638_ == 0)
{
lean_object* v___x_640_; uint8_t v_isShared_641_; uint8_t v_isSharedCheck_646_; 
lean_dec(v___y_630_);
lean_dec(v___y_629_);
lean_dec(v___y_628_);
lean_dec(v___y_627_);
lean_dec_ref(v_result_571_);
v_isSharedCheck_646_ = !lean_is_exclusive(v___y_631_);
if (v_isSharedCheck_646_ == 0)
{
lean_object* v_unused_647_; 
v_unused_647_ = lean_ctor_get(v___y_631_, 0);
lean_dec(v_unused_647_);
v___x_640_ = v___y_631_;
v_isShared_641_ = v_isSharedCheck_646_;
goto v_resetjp_639_;
}
else
{
lean_dec(v___y_631_);
v___x_640_ = lean_box(0);
v_isShared_641_ = v_isSharedCheck_646_;
goto v_resetjp_639_;
}
v_resetjp_639_:
{
lean_object* v___x_642_; lean_object* v___x_644_; 
v___x_642_ = ((lean_object*)(l_RunExperiment_profile___closed__11));
if (v_isShared_641_ == 0)
{
lean_ctor_set(v___x_640_, 0, v___x_642_);
v___x_644_ = v___x_640_;
goto v_reusejp_643_;
}
else
{
lean_object* v_reuseFailAlloc_645_; 
v_reuseFailAlloc_645_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_645_, 0, v___x_642_);
v___x_644_ = v_reuseFailAlloc_645_;
goto v_reusejp_643_;
}
v_reusejp_643_:
{
return v___x_644_;
}
}
}
else
{
v___y_573_ = v___y_627_;
v___y_574_ = v___y_628_;
v___y_575_ = v___y_629_;
v___y_576_ = v___y_630_;
v___y_577_ = v___y_631_;
v___y_578_ = v___y_632_;
goto v___jp_572_;
}
}
else
{
v___y_573_ = v___y_627_;
v___y_574_ = v___y_628_;
v___y_575_ = v___y_629_;
v___y_576_ = v___y_630_;
v___y_577_ = v___y_631_;
v___y_578_ = v___y_632_;
goto v___jp_572_;
}
}
}
}
v___jp_648_:
{
lean_object* v_time_654_; lean_object* v_bound_655_; uint8_t v___x_656_; 
v_time_654_ = lean_ctor_get(v_result_571_, 1);
lean_inc(v_time_654_);
v_bound_655_ = l_LeanSort_RunAdaptive_Strategy_bound___at___00RunExperiment_profile_spec__0(v_s_566_, v_xs_567_);
lean_dec(v_s_566_);
v___x_656_ = lean_nat_dec_le(v_fst_649_, v_time_654_);
if (v___x_656_ == 0)
{
lean_dec(v_time_654_);
v___y_627_ = v_fst_650_;
v___y_628_ = v_fst_651_;
v___y_629_ = v_fst_649_;
v___y_630_ = v_bound_655_;
v___y_631_ = v_snd_653_;
v___y_632_ = v_fst_652_;
v___y_633_ = v___x_656_;
goto v___jp_626_;
}
else
{
uint8_t v___x_657_; 
v___x_657_ = lean_nat_dec_le(v_time_654_, v_bound_655_);
lean_dec(v_time_654_);
v___y_627_ = v_fst_650_;
v___y_628_ = v_fst_651_;
v___y_629_ = v_fst_649_;
v___y_630_ = v_bound_655_;
v___y_631_ = v_snd_653_;
v___y_632_ = v_fst_652_;
v___y_633_ = v___x_657_;
goto v___jp_626_;
}
}
}
}
LEAN_EXPORT lean_object* l_RunExperiment_profile___boxed(lean_object* v_s_698_, lean_object* v_xs_699_, lean_object* v_expected_700_, lean_object* v_a_701_){
_start:
{
lean_object* v_res_702_; 
v_res_702_ = l_RunExperiment_profile(v_s_698_, v_xs_699_, v_expected_700_);
lean_dec(v_expected_700_);
return v_res_702_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00RunExperiment_handle_spec__2(lean_object* v_fst_703_, lean_object* v_a_704_, lean_object* v_a_705_, lean_object* v_a_706_){
_start:
{
if (lean_obj_tag(v_a_705_) == 0)
{
lean_object* v___x_707_; 
lean_dec(v_a_704_);
v___x_707_ = l_List_reverse___redArg(v_a_706_);
return v___x_707_;
}
else
{
lean_object* v_head_708_; lean_object* v_tail_709_; lean_object* v___x_711_; uint8_t v_isShared_712_; uint8_t v_isSharedCheck_732_; 
v_head_708_ = lean_ctor_get(v_a_705_, 0);
v_tail_709_ = lean_ctor_get(v_a_705_, 1);
v_isSharedCheck_732_ = !lean_is_exclusive(v_a_705_);
if (v_isSharedCheck_732_ == 0)
{
v___x_711_ = v_a_705_;
v_isShared_712_ = v_isSharedCheck_732_;
goto v_resetjp_710_;
}
else
{
lean_inc(v_tail_709_);
lean_inc(v_head_708_);
lean_dec(v_a_705_);
v___x_711_ = lean_box(0);
v_isShared_712_ = v_isSharedCheck_732_;
goto v_resetjp_710_;
}
v_resetjp_710_:
{
lean_object* v___y_714_; lean_object* v_fst_719_; lean_object* v_snd_720_; uint8_t v___x_721_; 
v_fst_719_ = lean_ctor_get(v_head_708_, 0);
v_snd_720_ = lean_ctor_get(v_head_708_, 1);
v___x_721_ = lean_string_dec_eq(v_fst_703_, v_fst_719_);
if (v___x_721_ == 0)
{
v___y_714_ = v_head_708_;
goto v___jp_713_;
}
else
{
lean_object* v___x_723_; uint8_t v_isShared_724_; uint8_t v_isSharedCheck_729_; 
lean_inc(v_snd_720_);
lean_inc(v_fst_719_);
v_isSharedCheck_729_ = !lean_is_exclusive(v_head_708_);
if (v_isSharedCheck_729_ == 0)
{
lean_object* v_unused_730_; lean_object* v_unused_731_; 
v_unused_730_ = lean_ctor_get(v_head_708_, 1);
lean_dec(v_unused_730_);
v_unused_731_ = lean_ctor_get(v_head_708_, 0);
lean_dec(v_unused_731_);
v___x_723_ = v_head_708_;
v_isShared_724_ = v_isSharedCheck_729_;
goto v_resetjp_722_;
}
else
{
lean_dec(v_head_708_);
v___x_723_ = lean_box(0);
v_isShared_724_ = v_isSharedCheck_729_;
goto v_resetjp_722_;
}
v_resetjp_722_:
{
lean_object* v___x_725_; lean_object* v___x_727_; 
lean_inc(v_a_704_);
v___x_725_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_725_, 0, v_a_704_);
lean_ctor_set(v___x_725_, 1, v_snd_720_);
if (v_isShared_724_ == 0)
{
lean_ctor_set(v___x_723_, 1, v___x_725_);
v___x_727_ = v___x_723_;
goto v_reusejp_726_;
}
else
{
lean_object* v_reuseFailAlloc_728_; 
v_reuseFailAlloc_728_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_728_, 0, v_fst_719_);
lean_ctor_set(v_reuseFailAlloc_728_, 1, v___x_725_);
v___x_727_ = v_reuseFailAlloc_728_;
goto v_reusejp_726_;
}
v_reusejp_726_:
{
v___y_714_ = v___x_727_;
goto v___jp_713_;
}
}
}
v___jp_713_:
{
lean_object* v___x_716_; 
if (v_isShared_712_ == 0)
{
lean_ctor_set(v___x_711_, 1, v_a_706_);
lean_ctor_set(v___x_711_, 0, v___y_714_);
v___x_716_ = v___x_711_;
goto v_reusejp_715_;
}
else
{
lean_object* v_reuseFailAlloc_718_; 
v_reuseFailAlloc_718_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_718_, 0, v___y_714_);
lean_ctor_set(v_reuseFailAlloc_718_, 1, v_a_706_);
v___x_716_ = v_reuseFailAlloc_718_;
goto v_reusejp_715_;
}
v_reusejp_715_:
{
v_a_705_ = v_tail_709_;
v_a_706_ = v___x_716_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00RunExperiment_handle_spec__2___boxed(lean_object* v_fst_733_, lean_object* v_a_734_, lean_object* v_a_735_, lean_object* v_a_736_){
_start:
{
lean_object* v_res_737_; 
v_res_737_ = l_List_mapTR_loop___at___00RunExperiment_handle_spec__2(v_fst_733_, v_a_734_, v_a_735_, v_a_736_);
lean_dec_ref(v_fst_733_);
return v_res_737_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__3___redArg(lean_object* v_val_738_, lean_object* v_val_739_, lean_object* v_a_740_, lean_object* v_as_x27_741_, lean_object* v_b_742_){
_start:
{
if (lean_obj_tag(v_as_x27_741_) == 0)
{
lean_object* v___x_744_; 
v___x_744_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_744_, 0, v_b_742_);
return v___x_744_;
}
else
{
lean_object* v_head_745_; lean_object* v_tail_746_; lean_object* v_fst_747_; lean_object* v_snd_748_; lean_object* v___x_749_; 
v_head_745_ = lean_ctor_get(v_as_x27_741_, 0);
v_tail_746_ = lean_ctor_get(v_as_x27_741_, 1);
v_fst_747_ = lean_ctor_get(v_head_745_, 0);
v_snd_748_ = lean_ctor_get(v_head_745_, 1);
lean_inc(v_snd_748_);
v___x_749_ = l_RunExperiment_timedRun(v_snd_748_, v_val_738_, v_val_739_, v_a_740_);
if (lean_obj_tag(v___x_749_) == 0)
{
lean_object* v_a_750_; lean_object* v___x_751_; lean_object* v___x_752_; 
v_a_750_ = lean_ctor_get(v___x_749_, 0);
lean_inc(v_a_750_);
lean_dec_ref_known(v___x_749_, 1);
v___x_751_ = lean_box(0);
v___x_752_ = l_List_mapTR_loop___at___00RunExperiment_handle_spec__2(v_fst_747_, v_a_750_, v_b_742_, v___x_751_);
v_as_x27_741_ = v_tail_746_;
v_b_742_ = v___x_752_;
goto _start;
}
else
{
lean_object* v_a_754_; lean_object* v___x_756_; uint8_t v_isShared_757_; uint8_t v_isSharedCheck_761_; 
lean_dec(v_b_742_);
v_a_754_ = lean_ctor_get(v___x_749_, 0);
v_isSharedCheck_761_ = !lean_is_exclusive(v___x_749_);
if (v_isSharedCheck_761_ == 0)
{
v___x_756_ = v___x_749_;
v_isShared_757_ = v_isSharedCheck_761_;
goto v_resetjp_755_;
}
else
{
lean_inc(v_a_754_);
lean_dec(v___x_749_);
v___x_756_ = lean_box(0);
v_isShared_757_ = v_isSharedCheck_761_;
goto v_resetjp_755_;
}
v_resetjp_755_:
{
lean_object* v___x_759_; 
if (v_isShared_757_ == 0)
{
v___x_759_ = v___x_756_;
goto v_reusejp_758_;
}
else
{
lean_object* v_reuseFailAlloc_760_; 
v_reuseFailAlloc_760_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_760_, 0, v_a_754_);
v___x_759_ = v_reuseFailAlloc_760_;
goto v_reusejp_758_;
}
v_reusejp_758_:
{
return v___x_759_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__3___redArg___boxed(lean_object* v_val_762_, lean_object* v_val_763_, lean_object* v_a_764_, lean_object* v_as_x27_765_, lean_object* v_b_766_, lean_object* v___y_767_){
_start:
{
lean_object* v_res_768_; 
v_res_768_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__3___redArg(v_val_762_, v_val_763_, v_a_764_, v_as_x27_765_, v_b_766_);
lean_dec(v_as_x27_765_);
lean_dec(v_a_764_);
lean_dec(v_val_763_);
lean_dec(v_val_762_);
return v_res_768_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6___redArg(lean_object* v_val_771_, lean_object* v_val_772_, lean_object* v_a_773_, lean_object* v_a_774_, lean_object* v_a_775_, lean_object* v_as_x27_776_, lean_object* v_b_777_){
_start:
{
if (lean_obj_tag(v_as_x27_776_) == 0)
{
lean_object* v___x_779_; 
lean_dec(v_a_775_);
v___x_779_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_779_, 0, v_b_777_);
return v___x_779_;
}
else
{
lean_object* v_head_780_; lean_object* v_tail_781_; lean_object* v___y_783_; lean_object* v___x_787_; lean_object* v___x_788_; lean_object* v___x_789_; lean_object* v___x_790_; lean_object* v___x_791_; lean_object* v___x_792_; lean_object* v___x_793_; lean_object* v___x_794_; lean_object* v___x_795_; lean_object* v___x_796_; uint8_t v___x_797_; 
v_head_780_ = lean_ctor_get(v_as_x27_776_, 0);
v_tail_781_ = lean_ctor_get(v_as_x27_776_, 1);
v___x_787_ = lean_unsigned_to_nat(0u);
v___x_788_ = lean_nat_add(v_a_774_, v_head_780_);
v___x_789_ = l_List_lengthTR___redArg(v_a_775_);
v___x_790_ = lean_nat_mod(v___x_788_, v___x_789_);
lean_dec(v___x_789_);
lean_dec(v___x_788_);
lean_inc(v___x_790_);
v___x_791_ = l_List_drop___redArg(v___x_790_, v_a_775_);
v___x_792_ = ((lean_object*)(l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6___redArg___closed__0));
lean_inc(v_a_775_);
v___x_793_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_a_775_, v_a_775_, v___x_790_, v___x_792_);
v___x_794_ = l_List_appendTR___redArg(v___x_791_, v___x_793_);
v___x_795_ = lean_unsigned_to_nat(2u);
v___x_796_ = lean_nat_mod(v_head_780_, v___x_795_);
v___x_797_ = lean_nat_dec_eq(v___x_796_, v___x_787_);
lean_dec(v___x_796_);
if (v___x_797_ == 0)
{
lean_object* v___x_798_; 
v___x_798_ = l_List_reverse___redArg(v___x_794_);
v___y_783_ = v___x_798_;
goto v___jp_782_;
}
else
{
v___y_783_ = v___x_794_;
goto v___jp_782_;
}
v___jp_782_:
{
lean_object* v___x_784_; 
v___x_784_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__3___redArg(v_val_771_, v_val_772_, v_a_773_, v___y_783_, v_b_777_);
lean_dec(v___y_783_);
if (lean_obj_tag(v___x_784_) == 0)
{
lean_object* v_a_785_; 
v_a_785_ = lean_ctor_get(v___x_784_, 0);
lean_inc(v_a_785_);
lean_dec_ref_known(v___x_784_, 1);
v_as_x27_776_ = v_tail_781_;
v_b_777_ = v_a_785_;
goto _start;
}
else
{
lean_dec(v_a_775_);
return v___x_784_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6___redArg___boxed(lean_object* v_val_799_, lean_object* v_val_800_, lean_object* v_a_801_, lean_object* v_a_802_, lean_object* v_a_803_, lean_object* v_as_x27_804_, lean_object* v_b_805_, lean_object* v___y_806_){
_start:
{
lean_object* v_res_807_; 
v_res_807_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6___redArg(v_val_799_, v_val_800_, v_a_801_, v_a_802_, v_a_803_, v_as_x27_804_, v_b_805_);
lean_dec(v_as_x27_804_);
lean_dec(v_a_802_);
lean_dec(v_a_801_);
lean_dec(v_val_800_);
lean_dec(v_val_799_);
return v_res_807_;
}
}
LEAN_EXPORT uint8_t l_List_all___at___00RunExperiment_handle_spec__11(uint8_t v___x_808_, uint8_t v___x_809_, lean_object* v_x_810_){
_start:
{
if (lean_obj_tag(v_x_810_) == 0)
{
uint8_t v___x_811_; 
v___x_811_ = 1;
return v___x_811_;
}
else
{
lean_object* v_head_812_; lean_object* v_tail_813_; uint8_t v___y_815_; uint8_t v___x_817_; 
v_head_812_ = lean_ctor_get(v_x_810_, 0);
lean_inc(v_head_812_);
v_tail_813_ = lean_ctor_get(v_x_810_, 1);
lean_inc(v_tail_813_);
lean_dec_ref_known(v_x_810_, 2);
v___x_817_ = l_List_isEmpty___redArg(v_head_812_);
if (v___x_817_ == 0)
{
if (v___x_808_ == 0)
{
lean_dec(v_tail_813_);
lean_dec(v_head_812_);
return v___x_808_;
}
else
{
lean_object* v___x_818_; lean_object* v___x_819_; lean_object* v_ret_820_; uint8_t v___x_821_; 
v___x_818_ = lp_leansort_LeanSort_ComparisonSort_checkSorted___redArg(v_head_812_);
v___x_819_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(v___x_818_);
v_ret_820_ = lean_ctor_get(v___x_819_, 0);
lean_inc(v_ret_820_);
lean_dec_ref(v___x_819_);
v___x_821_ = lean_unbox(v_ret_820_);
lean_dec(v_ret_820_);
v___y_815_ = v___x_821_;
goto v___jp_814_;
}
}
else
{
lean_dec(v_head_812_);
v___y_815_ = v___x_809_;
goto v___jp_814_;
}
v___jp_814_:
{
if (v___y_815_ == 0)
{
lean_dec(v_tail_813_);
return v___y_815_;
}
else
{
v_x_810_ = v_tail_813_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_all___at___00RunExperiment_handle_spec__11___boxed(lean_object* v___x_822_, lean_object* v___x_823_, lean_object* v_x_824_){
_start:
{
uint8_t v___x_7018__boxed_825_; uint8_t v___x_7019__boxed_826_; uint8_t v_res_827_; lean_object* v_r_828_; 
v___x_7018__boxed_825_ = lean_unbox(v___x_822_);
v___x_7019__boxed_826_ = lean_unbox(v___x_823_);
v_res_827_ = l_List_all___at___00RunExperiment_handle_spec__11(v___x_7018__boxed_825_, v___x_7019__boxed_826_, v_x_824_);
v_r_828_ = lean_box(v_res_827_);
return v_r_828_;
}
}
LEAN_EXPORT lean_object* l_List_find_x3f___at___00RunExperiment_handle_spec__7(lean_object* v_fst_829_, lean_object* v_x_830_){
_start:
{
if (lean_obj_tag(v_x_830_) == 0)
{
lean_object* v___x_831_; 
v___x_831_ = lean_box(0);
return v___x_831_;
}
else
{
lean_object* v_head_832_; lean_object* v_tail_833_; lean_object* v_fst_834_; uint8_t v___x_835_; 
v_head_832_ = lean_ctor_get(v_x_830_, 0);
v_tail_833_ = lean_ctor_get(v_x_830_, 1);
v_fst_834_ = lean_ctor_get(v_head_832_, 0);
v___x_835_ = lean_string_dec_eq(v_fst_834_, v_fst_829_);
if (v___x_835_ == 0)
{
v_x_830_ = v_tail_833_;
goto _start;
}
else
{
lean_object* v___x_837_; 
lean_inc(v_head_832_);
v___x_837_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_837_, 0, v_head_832_);
return v___x_837_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_find_x3f___at___00RunExperiment_handle_spec__7___boxed(lean_object* v_fst_838_, lean_object* v_x_839_){
_start:
{
lean_object* v_res_840_; 
v_res_840_ = l_List_find_x3f___at___00RunExperiment_handle_spec__7(v_fst_838_, v_x_839_);
lean_dec(v_x_839_);
lean_dec_ref(v_fst_838_);
return v_res_840_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg(lean_object* v_a_847_, lean_object* v_a_848_, lean_object* v_a_849_, lean_object* v_a_850_, lean_object* v_as_x27_851_, lean_object* v_b_852_){
_start:
{
if (lean_obj_tag(v_as_x27_851_) == 0)
{
lean_object* v___x_854_; 
lean_dec(v_a_850_);
lean_dec(v_a_847_);
v___x_854_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_854_, 0, v_b_852_);
return v___x_854_;
}
else
{
lean_object* v_head_855_; lean_object* v_tail_856_; lean_object* v_fst_857_; lean_object* v_snd_858_; lean_object* v___x_859_; lean_object* v___y_861_; lean_object* v___y_862_; lean_object* v_diag_901_; 
v_head_855_ = lean_ctor_get(v_as_x27_851_, 0);
v_tail_856_ = lean_ctor_get(v_as_x27_851_, 1);
v_fst_857_ = lean_ctor_get(v_head_855_, 0);
v_snd_858_ = lean_ctor_get(v_head_855_, 1);
v___x_859_ = lean_box(0);
switch(lean_obj_tag(v_snd_858_))
{
case 0:
{
lean_object* v___x_905_; 
v___x_905_ = lean_box(0);
v_diag_901_ = v___x_905_;
goto v___jp_900_;
}
case 1:
{
lean_object* v___x_906_; lean_object* v___x_907_; 
v___x_906_ = ((lean_object*)(l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__4));
lean_inc(v_a_850_);
lean_inc(v_a_847_);
v___x_907_ = l_RunExperiment_diagnostics(v___x_906_, v_a_847_, v_a_848_, v_a_850_);
if (lean_obj_tag(v___x_907_) == 0)
{
lean_object* v_a_908_; 
v_a_908_ = lean_ctor_get(v___x_907_, 0);
lean_inc(v_a_908_);
lean_dec_ref_known(v___x_907_, 1);
v_diag_901_ = v_a_908_;
goto v___jp_900_;
}
else
{
lean_object* v_a_909_; lean_object* v___x_911_; uint8_t v_isShared_912_; uint8_t v_isSharedCheck_916_; 
lean_dec(v_b_852_);
lean_dec(v_a_850_);
lean_dec(v_a_847_);
v_a_909_ = lean_ctor_get(v___x_907_, 0);
v_isSharedCheck_916_ = !lean_is_exclusive(v___x_907_);
if (v_isSharedCheck_916_ == 0)
{
v___x_911_ = v___x_907_;
v_isShared_912_ = v_isSharedCheck_916_;
goto v_resetjp_910_;
}
else
{
lean_inc(v_a_909_);
lean_dec(v___x_907_);
v___x_911_ = lean_box(0);
v_isShared_912_ = v_isSharedCheck_916_;
goto v_resetjp_910_;
}
v_resetjp_910_:
{
lean_object* v___x_914_; 
if (v_isShared_912_ == 0)
{
v___x_914_ = v___x_911_;
goto v_reusejp_913_;
}
else
{
lean_object* v_reuseFailAlloc_915_; 
v_reuseFailAlloc_915_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_915_, 0, v_a_909_);
v___x_914_ = v_reuseFailAlloc_915_;
goto v_reusejp_913_;
}
v_reusejp_913_:
{
return v___x_914_;
}
}
}
}
default: 
{
lean_object* v___x_917_; lean_object* v___x_918_; 
v___x_917_ = ((lean_object*)(l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__5));
lean_inc(v_a_850_);
lean_inc(v_a_847_);
v___x_918_ = l_RunExperiment_diagnostics(v___x_917_, v_a_847_, v_a_848_, v_a_850_);
if (lean_obj_tag(v___x_918_) == 0)
{
lean_object* v_a_919_; 
v_a_919_ = lean_ctor_get(v___x_918_, 0);
lean_inc(v_a_919_);
lean_dec_ref_known(v___x_918_, 1);
v_diag_901_ = v_a_919_;
goto v___jp_900_;
}
else
{
lean_object* v_a_920_; lean_object* v___x_922_; uint8_t v_isShared_923_; uint8_t v_isSharedCheck_927_; 
lean_dec(v_b_852_);
lean_dec(v_a_850_);
lean_dec(v_a_847_);
v_a_920_ = lean_ctor_get(v___x_918_, 0);
v_isSharedCheck_927_ = !lean_is_exclusive(v___x_918_);
if (v_isSharedCheck_927_ == 0)
{
v___x_922_ = v___x_918_;
v_isShared_923_ = v_isSharedCheck_927_;
goto v_resetjp_921_;
}
else
{
lean_inc(v_a_920_);
lean_dec(v___x_918_);
v___x_922_ = lean_box(0);
v_isShared_923_ = v_isSharedCheck_927_;
goto v_resetjp_921_;
}
v_resetjp_921_:
{
lean_object* v___x_925_; 
if (v_isShared_923_ == 0)
{
v___x_925_ = v___x_922_;
goto v_reusejp_924_;
}
else
{
lean_object* v_reuseFailAlloc_926_; 
v_reuseFailAlloc_926_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_926_, 0, v_a_920_);
v___x_925_ = v_reuseFailAlloc_926_;
goto v_reusejp_924_;
}
v_reusejp_924_:
{
return v___x_925_;
}
}
}
}
}
v___jp_860_:
{
lean_object* v___x_863_; 
lean_inc(v_a_847_);
lean_inc(v_snd_858_);
v___x_863_ = l_RunExperiment_profile(v_snd_858_, v_a_847_, v_a_848_);
if (lean_obj_tag(v___x_863_) == 0)
{
lean_object* v_a_864_; lean_object* v_snd_865_; lean_object* v___x_867_; uint8_t v_isShared_868_; uint8_t v_isSharedCheck_890_; 
v_a_864_ = lean_ctor_get(v___x_863_, 0);
lean_inc(v_a_864_);
lean_dec_ref_known(v___x_863_, 1);
v_snd_865_ = lean_ctor_get(v___y_862_, 1);
v_isSharedCheck_890_ = !lean_is_exclusive(v___y_862_);
if (v_isSharedCheck_890_ == 0)
{
lean_object* v_unused_891_; 
v_unused_891_ = lean_ctor_get(v___y_862_, 0);
lean_dec(v_unused_891_);
v___x_867_ = v___y_862_;
v_isShared_868_ = v_isSharedCheck_890_;
goto v_resetjp_866_;
}
else
{
lean_inc(v_snd_865_);
lean_dec(v___y_862_);
v___x_867_ = lean_box(0);
v_isShared_868_ = v_isSharedCheck_890_;
goto v_resetjp_866_;
}
v_resetjp_866_:
{
lean_object* v___x_869_; lean_object* v___x_870_; lean_object* v___x_871_; lean_object* v___x_873_; 
v___x_869_ = l_List_reverse___redArg(v_snd_865_);
v___x_870_ = ((lean_object*)(l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__0));
lean_inc(v_fst_857_);
v___x_871_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_871_, 0, v_fst_857_);
if (v_isShared_868_ == 0)
{
lean_ctor_set(v___x_867_, 1, v___x_871_);
lean_ctor_set(v___x_867_, 0, v___x_870_);
v___x_873_ = v___x_867_;
goto v_reusejp_872_;
}
else
{
lean_object* v_reuseFailAlloc_889_; 
v_reuseFailAlloc_889_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_889_, 0, v___x_870_);
lean_ctor_set(v_reuseFailAlloc_889_, 1, v___x_871_);
v___x_873_ = v_reuseFailAlloc_889_;
goto v_reusejp_872_;
}
v_reusejp_872_:
{
lean_object* v___x_874_; lean_object* v___x_875_; lean_object* v___x_876_; lean_object* v___x_877_; lean_object* v___x_878_; lean_object* v___x_879_; lean_object* v___x_880_; lean_object* v___x_881_; lean_object* v___x_882_; lean_object* v___x_883_; lean_object* v___x_884_; lean_object* v___x_885_; lean_object* v___x_886_; lean_object* v___x_887_; 
v___x_874_ = ((lean_object*)(l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__1));
v___x_875_ = l_Lean_List_toJson___at___00RunExperiment_shape_spec__0(v___x_869_);
v___x_876_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_876_, 0, v___x_874_);
lean_ctor_set(v___x_876_, 1, v___x_875_);
v___x_877_ = ((lean_object*)(l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__2));
v___x_878_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_878_, 0, v___x_877_);
lean_ctor_set(v___x_878_, 1, v_a_864_);
v___x_879_ = ((lean_object*)(l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___closed__3));
v___x_880_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_880_, 0, v___x_879_);
lean_ctor_set(v___x_880_, 1, v___y_861_);
v___x_881_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_881_, 0, v___x_880_);
lean_ctor_set(v___x_881_, 1, v___x_859_);
v___x_882_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_882_, 0, v___x_878_);
lean_ctor_set(v___x_882_, 1, v___x_881_);
v___x_883_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_883_, 0, v___x_876_);
lean_ctor_set(v___x_883_, 1, v___x_882_);
v___x_884_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_884_, 0, v___x_873_);
lean_ctor_set(v___x_884_, 1, v___x_883_);
v___x_885_ = l_Lean_Json_mkObj(v___x_884_);
lean_dec_ref_known(v___x_884_, 2);
v___x_886_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_886_, 0, v___x_885_);
lean_ctor_set(v___x_886_, 1, v___x_859_);
v___x_887_ = l_List_appendTR___redArg(v_b_852_, v___x_886_);
v_as_x27_851_ = v_tail_856_;
v_b_852_ = v___x_887_;
goto _start;
}
}
}
else
{
lean_object* v_a_892_; lean_object* v___x_894_; uint8_t v_isShared_895_; uint8_t v_isSharedCheck_899_; 
lean_dec_ref(v___y_862_);
lean_dec(v___y_861_);
lean_dec(v_b_852_);
lean_dec(v_a_850_);
lean_dec(v_a_847_);
v_a_892_ = lean_ctor_get(v___x_863_, 0);
v_isSharedCheck_899_ = !lean_is_exclusive(v___x_863_);
if (v_isSharedCheck_899_ == 0)
{
v___x_894_ = v___x_863_;
v_isShared_895_ = v_isSharedCheck_899_;
goto v_resetjp_893_;
}
else
{
lean_inc(v_a_892_);
lean_dec(v___x_863_);
v___x_894_ = lean_box(0);
v_isShared_895_ = v_isSharedCheck_899_;
goto v_resetjp_893_;
}
v_resetjp_893_:
{
lean_object* v___x_897_; 
if (v_isShared_895_ == 0)
{
v___x_897_ = v___x_894_;
goto v_reusejp_896_;
}
else
{
lean_object* v_reuseFailAlloc_898_; 
v_reuseFailAlloc_898_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_898_, 0, v_a_892_);
v___x_897_ = v_reuseFailAlloc_898_;
goto v_reusejp_896_;
}
v_reusejp_896_:
{
return v___x_897_;
}
}
}
}
v___jp_900_:
{
lean_object* v___x_902_; 
v___x_902_ = l_List_find_x3f___at___00RunExperiment_handle_spec__7(v_fst_857_, v_a_849_);
if (lean_obj_tag(v___x_902_) == 0)
{
lean_object* v___x_903_; 
lean_inc(v_fst_857_);
v___x_903_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_903_, 0, v_fst_857_);
lean_ctor_set(v___x_903_, 1, v___x_859_);
v___y_861_ = v_diag_901_;
v___y_862_ = v___x_903_;
goto v___jp_860_;
}
else
{
lean_object* v_val_904_; 
v_val_904_ = lean_ctor_get(v___x_902_, 0);
lean_inc(v_val_904_);
lean_dec_ref_known(v___x_902_, 1);
v___y_861_ = v_diag_901_;
v___y_862_ = v_val_904_;
goto v___jp_860_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg___boxed(lean_object* v_a_928_, lean_object* v_a_929_, lean_object* v_a_930_, lean_object* v_a_931_, lean_object* v_as_x27_932_, lean_object* v_b_933_, lean_object* v___y_934_){
_start:
{
lean_object* v_res_935_; 
v_res_935_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg(v_a_928_, v_a_929_, v_a_930_, v_a_931_, v_as_x27_932_, v_b_933_);
lean_dec(v_as_x27_932_);
lean_dec(v_a_930_);
lean_dec(v_a_929_);
return v_res_935_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00RunExperiment_handle_spec__5(lean_object* v_a_936_, lean_object* v_a_937_){
_start:
{
if (lean_obj_tag(v_a_936_) == 0)
{
lean_object* v___x_938_; 
v___x_938_ = l_List_reverse___redArg(v_a_937_);
return v___x_938_;
}
else
{
lean_object* v_head_939_; lean_object* v_tail_940_; lean_object* v___x_942_; uint8_t v_isShared_943_; uint8_t v_isSharedCheck_958_; 
v_head_939_ = lean_ctor_get(v_a_936_, 0);
v_tail_940_ = lean_ctor_get(v_a_936_, 1);
v_isSharedCheck_958_ = !lean_is_exclusive(v_a_936_);
if (v_isSharedCheck_958_ == 0)
{
v___x_942_ = v_a_936_;
v_isShared_943_ = v_isSharedCheck_958_;
goto v_resetjp_941_;
}
else
{
lean_inc(v_tail_940_);
lean_inc(v_head_939_);
lean_dec(v_a_936_);
v___x_942_ = lean_box(0);
v_isShared_943_ = v_isSharedCheck_958_;
goto v_resetjp_941_;
}
v_resetjp_941_:
{
lean_object* v_fst_944_; lean_object* v___x_946_; uint8_t v_isShared_947_; uint8_t v_isSharedCheck_956_; 
v_fst_944_ = lean_ctor_get(v_head_939_, 0);
v_isSharedCheck_956_ = !lean_is_exclusive(v_head_939_);
if (v_isSharedCheck_956_ == 0)
{
lean_object* v_unused_957_; 
v_unused_957_ = lean_ctor_get(v_head_939_, 1);
lean_dec(v_unused_957_);
v___x_946_ = v_head_939_;
v_isShared_947_ = v_isSharedCheck_956_;
goto v_resetjp_945_;
}
else
{
lean_inc(v_fst_944_);
lean_dec(v_head_939_);
v___x_946_ = lean_box(0);
v_isShared_947_ = v_isSharedCheck_956_;
goto v_resetjp_945_;
}
v_resetjp_945_:
{
lean_object* v___x_948_; lean_object* v___x_950_; 
v___x_948_ = lean_box(0);
if (v_isShared_947_ == 0)
{
lean_ctor_set(v___x_946_, 1, v___x_948_);
v___x_950_ = v___x_946_;
goto v_reusejp_949_;
}
else
{
lean_object* v_reuseFailAlloc_955_; 
v_reuseFailAlloc_955_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_955_, 0, v_fst_944_);
lean_ctor_set(v_reuseFailAlloc_955_, 1, v___x_948_);
v___x_950_ = v_reuseFailAlloc_955_;
goto v_reusejp_949_;
}
v_reusejp_949_:
{
lean_object* v___x_952_; 
if (v_isShared_943_ == 0)
{
lean_ctor_set(v___x_942_, 1, v_a_937_);
lean_ctor_set(v___x_942_, 0, v___x_950_);
v___x_952_ = v___x_942_;
goto v_reusejp_951_;
}
else
{
lean_object* v_reuseFailAlloc_954_; 
v_reuseFailAlloc_954_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_954_, 0, v___x_950_);
lean_ctor_set(v_reuseFailAlloc_954_, 1, v_a_937_);
v___x_952_ = v_reuseFailAlloc_954_;
goto v_reusejp_951_;
}
v_reusejp_951_:
{
v_a_936_ = v_tail_940_;
v_a_937_ = v___x_952_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00RunExperiment_handle_spec__10(lean_object* v_a_959_, lean_object* v_a_960_){
_start:
{
if (lean_obj_tag(v_a_959_) == 0)
{
lean_object* v___x_961_; 
v___x_961_ = lean_array_to_list(v_a_960_);
return v___x_961_;
}
else
{
lean_object* v_head_962_; lean_object* v_tail_963_; lean_object* v___x_964_; 
v_head_962_ = lean_ctor_get(v_a_959_, 0);
lean_inc(v_head_962_);
v_tail_963_ = lean_ctor_get(v_a_959_, 1);
lean_inc(v_tail_963_);
lean_dec_ref_known(v_a_959_, 2);
v___x_964_ = l_List_foldl___at___00Array_appendList_spec__0___redArg(v_a_960_, v_head_962_);
v_a_959_ = v_tail_963_;
v_a_960_ = v___x_964_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00RunExperiment_handle_spec__1(lean_object* v_x_966_, lean_object* v_x_967_){
_start:
{
if (lean_obj_tag(v_x_966_) == 0)
{
lean_object* v___x_969_; lean_object* v___x_970_; 
v___x_969_ = l_List_reverse___redArg(v_x_967_);
v___x_970_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_970_, 0, v___x_969_);
return v___x_970_;
}
else
{
lean_object* v_head_971_; lean_object* v_tail_972_; lean_object* v___x_974_; uint8_t v_isShared_975_; uint8_t v_isSharedCheck_992_; 
v_head_971_ = lean_ctor_get(v_x_966_, 0);
v_tail_972_ = lean_ctor_get(v_x_966_, 1);
v_isSharedCheck_992_ = !lean_is_exclusive(v_x_966_);
if (v_isSharedCheck_992_ == 0)
{
v___x_974_ = v_x_966_;
v_isShared_975_ = v_isSharedCheck_992_;
goto v_resetjp_973_;
}
else
{
lean_inc(v_tail_972_);
lean_inc(v_head_971_);
lean_dec(v_x_966_);
v___x_974_ = lean_box(0);
v_isShared_975_ = v_isSharedCheck_992_;
goto v_resetjp_973_;
}
v_resetjp_973_:
{
lean_object* v___x_976_; lean_object* v___x_977_; 
lean_inc(v_head_971_);
v___x_976_ = l_RunExperiment_decode(v_head_971_);
v___x_977_ = l_RunExperiment_orError___redArg(v___x_976_);
if (lean_obj_tag(v___x_977_) == 0)
{
lean_object* v_a_978_; lean_object* v___x_979_; lean_object* v___x_981_; 
v_a_978_ = lean_ctor_get(v___x_977_, 0);
lean_inc(v_a_978_);
lean_dec_ref_known(v___x_977_, 1);
v___x_979_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_979_, 0, v_head_971_);
lean_ctor_set(v___x_979_, 1, v_a_978_);
if (v_isShared_975_ == 0)
{
lean_ctor_set(v___x_974_, 1, v_x_967_);
lean_ctor_set(v___x_974_, 0, v___x_979_);
v___x_981_ = v___x_974_;
goto v_reusejp_980_;
}
else
{
lean_object* v_reuseFailAlloc_983_; 
v_reuseFailAlloc_983_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_983_, 0, v___x_979_);
lean_ctor_set(v_reuseFailAlloc_983_, 1, v_x_967_);
v___x_981_ = v_reuseFailAlloc_983_;
goto v_reusejp_980_;
}
v_reusejp_980_:
{
v_x_966_ = v_tail_972_;
v_x_967_ = v___x_981_;
goto _start;
}
}
else
{
lean_object* v_a_984_; lean_object* v___x_986_; uint8_t v_isShared_987_; uint8_t v_isSharedCheck_991_; 
lean_del_object(v___x_974_);
lean_dec(v_tail_972_);
lean_dec(v_head_971_);
lean_dec(v_x_967_);
v_a_984_ = lean_ctor_get(v___x_977_, 0);
v_isSharedCheck_991_ = !lean_is_exclusive(v___x_977_);
if (v_isSharedCheck_991_ == 0)
{
v___x_986_ = v___x_977_;
v_isShared_987_ = v_isSharedCheck_991_;
goto v_resetjp_985_;
}
else
{
lean_inc(v_a_984_);
lean_dec(v___x_977_);
v___x_986_ = lean_box(0);
v_isShared_987_ = v_isSharedCheck_991_;
goto v_resetjp_985_;
}
v_resetjp_985_:
{
lean_object* v___x_989_; 
if (v_isShared_987_ == 0)
{
v___x_989_ = v___x_986_;
goto v_reusejp_988_;
}
else
{
lean_object* v_reuseFailAlloc_990_; 
v_reuseFailAlloc_990_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_990_, 0, v_a_984_);
v___x_989_ = v_reuseFailAlloc_990_;
goto v_reusejp_988_;
}
v_reusejp_988_:
{
return v___x_989_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00RunExperiment_handle_spec__1___boxed(lean_object* v_x_993_, lean_object* v_x_994_, lean_object* v___y_995_){
_start:
{
lean_object* v_res_996_; 
v_res_996_ = l_List_mapM_loop___at___00RunExperiment_handle_spec__1(v_x_993_, v_x_994_);
return v_res_996_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__4___redArg(lean_object* v_val_997_, lean_object* v_val_998_, lean_object* v_a_999_, lean_object* v_as_x27_1000_, lean_object* v_b_1001_){
_start:
{
if (lean_obj_tag(v_as_x27_1000_) == 0)
{
lean_object* v___x_1003_; 
v___x_1003_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1003_, 0, v_b_1001_);
return v___x_1003_;
}
else
{
lean_object* v_head_1004_; lean_object* v_tail_1005_; lean_object* v_snd_1006_; lean_object* v___x_1007_; 
v_head_1004_ = lean_ctor_get(v_as_x27_1000_, 0);
v_tail_1005_ = lean_ctor_get(v_as_x27_1000_, 1);
v_snd_1006_ = lean_ctor_get(v_head_1004_, 1);
lean_inc(v_snd_1006_);
v___x_1007_ = l_RunExperiment_timedRun(v_snd_1006_, v_val_997_, v_val_998_, v_a_999_);
if (lean_obj_tag(v___x_1007_) == 0)
{
lean_object* v___x_1008_; 
lean_dec_ref_known(v___x_1007_, 1);
v___x_1008_ = lean_box(0);
v_as_x27_1000_ = v_tail_1005_;
v_b_1001_ = v___x_1008_;
goto _start;
}
else
{
lean_object* v_a_1010_; lean_object* v___x_1012_; uint8_t v_isShared_1013_; uint8_t v_isSharedCheck_1017_; 
v_a_1010_ = lean_ctor_get(v___x_1007_, 0);
v_isSharedCheck_1017_ = !lean_is_exclusive(v___x_1007_);
if (v_isSharedCheck_1017_ == 0)
{
v___x_1012_ = v___x_1007_;
v_isShared_1013_ = v_isSharedCheck_1017_;
goto v_resetjp_1011_;
}
else
{
lean_inc(v_a_1010_);
lean_dec(v___x_1007_);
v___x_1012_ = lean_box(0);
v_isShared_1013_ = v_isSharedCheck_1017_;
goto v_resetjp_1011_;
}
v_resetjp_1011_:
{
lean_object* v___x_1015_; 
if (v_isShared_1013_ == 0)
{
v___x_1015_ = v___x_1012_;
goto v_reusejp_1014_;
}
else
{
lean_object* v_reuseFailAlloc_1016_; 
v_reuseFailAlloc_1016_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1016_, 0, v_a_1010_);
v___x_1015_ = v_reuseFailAlloc_1016_;
goto v_reusejp_1014_;
}
v_reusejp_1014_:
{
return v___x_1015_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__4___redArg___boxed(lean_object* v_val_1018_, lean_object* v_val_1019_, lean_object* v_a_1020_, lean_object* v_as_x27_1021_, lean_object* v_b_1022_, lean_object* v___y_1023_){
_start:
{
lean_object* v_res_1024_; 
v_res_1024_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__4___redArg(v_val_1018_, v_val_1019_, v_a_1020_, v_as_x27_1021_, v_b_1022_);
lean_dec(v_as_x27_1021_);
lean_dec(v_a_1020_);
lean_dec(v_val_1019_);
lean_dec(v_val_1018_);
return v_res_1024_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00RunExperiment_handle_spec__9(lean_object* v_a_1025_, lean_object* v_a_1026_){
_start:
{
if (lean_obj_tag(v_a_1025_) == 0)
{
lean_object* v___x_1027_; 
v___x_1027_ = l_List_reverse___redArg(v_a_1026_);
return v___x_1027_;
}
else
{
lean_object* v_head_1028_; lean_object* v_tail_1029_; lean_object* v___x_1031_; uint8_t v_isShared_1032_; uint8_t v_isSharedCheck_1038_; 
v_head_1028_ = lean_ctor_get(v_a_1025_, 0);
v_tail_1029_ = lean_ctor_get(v_a_1025_, 1);
v_isSharedCheck_1038_ = !lean_is_exclusive(v_a_1025_);
if (v_isSharedCheck_1038_ == 0)
{
v___x_1031_ = v_a_1025_;
v_isShared_1032_ = v_isSharedCheck_1038_;
goto v_resetjp_1030_;
}
else
{
lean_inc(v_tail_1029_);
lean_inc(v_head_1028_);
lean_dec(v_a_1025_);
v___x_1031_ = lean_box(0);
v_isShared_1032_ = v_isSharedCheck_1038_;
goto v_resetjp_1030_;
}
v_resetjp_1030_:
{
lean_object* v___x_1033_; lean_object* v___x_1035_; 
v___x_1033_ = l_List_lengthTR___redArg(v_head_1028_);
lean_dec(v_head_1028_);
if (v_isShared_1032_ == 0)
{
lean_ctor_set(v___x_1031_, 1, v_a_1026_);
lean_ctor_set(v___x_1031_, 0, v___x_1033_);
v___x_1035_ = v___x_1031_;
goto v_reusejp_1034_;
}
else
{
lean_object* v_reuseFailAlloc_1037_; 
v_reuseFailAlloc_1037_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1037_, 0, v___x_1033_);
lean_ctor_set(v_reuseFailAlloc_1037_, 1, v_a_1026_);
v___x_1035_ = v_reuseFailAlloc_1037_;
goto v_reusejp_1034_;
}
v_reusejp_1034_:
{
v_a_1025_ = v_tail_1029_;
v_a_1026_ = v___x_1035_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00RunExperiment_handle_spec__0_spec__0(lean_object* v_j_1039_){
_start:
{
lean_object* v___x_1040_; 
v___x_1040_ = l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonStackTable_fromJson_spec__0_spec__0(v_j_1039_);
if (lean_obj_tag(v___x_1040_) == 0)
{
lean_object* v_a_1041_; lean_object* v___x_1043_; uint8_t v_isShared_1044_; uint8_t v_isSharedCheck_1048_; 
v_a_1041_ = lean_ctor_get(v___x_1040_, 0);
v_isSharedCheck_1048_ = !lean_is_exclusive(v___x_1040_);
if (v_isSharedCheck_1048_ == 0)
{
v___x_1043_ = v___x_1040_;
v_isShared_1044_ = v_isSharedCheck_1048_;
goto v_resetjp_1042_;
}
else
{
lean_inc(v_a_1041_);
lean_dec(v___x_1040_);
v___x_1043_ = lean_box(0);
v_isShared_1044_ = v_isSharedCheck_1048_;
goto v_resetjp_1042_;
}
v_resetjp_1042_:
{
lean_object* v___x_1046_; 
if (v_isShared_1044_ == 0)
{
v___x_1046_ = v___x_1043_;
goto v_reusejp_1045_;
}
else
{
lean_object* v_reuseFailAlloc_1047_; 
v_reuseFailAlloc_1047_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1047_, 0, v_a_1041_);
v___x_1046_ = v_reuseFailAlloc_1047_;
goto v_reusejp_1045_;
}
v_reusejp_1045_:
{
return v___x_1046_;
}
}
}
else
{
lean_object* v_a_1049_; lean_object* v___x_1051_; uint8_t v_isShared_1052_; uint8_t v_isSharedCheck_1057_; 
v_a_1049_ = lean_ctor_get(v___x_1040_, 0);
v_isSharedCheck_1057_ = !lean_is_exclusive(v___x_1040_);
if (v_isSharedCheck_1057_ == 0)
{
v___x_1051_ = v___x_1040_;
v_isShared_1052_ = v_isSharedCheck_1057_;
goto v_resetjp_1050_;
}
else
{
lean_inc(v_a_1049_);
lean_dec(v___x_1040_);
v___x_1051_ = lean_box(0);
v_isShared_1052_ = v_isSharedCheck_1057_;
goto v_resetjp_1050_;
}
v_resetjp_1050_:
{
lean_object* v___x_1053_; lean_object* v___x_1055_; 
v___x_1053_ = lean_array_to_list(v_a_1049_);
if (v_isShared_1052_ == 0)
{
lean_ctor_set(v___x_1051_, 0, v___x_1053_);
v___x_1055_ = v___x_1051_;
goto v_reusejp_1054_;
}
else
{
lean_object* v_reuseFailAlloc_1056_; 
v_reuseFailAlloc_1056_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1056_, 0, v___x_1053_);
v___x_1055_ = v_reuseFailAlloc_1056_;
goto v_reusejp_1054_;
}
v_reusejp_1054_:
{
return v___x_1055_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00RunExperiment_handle_spec__0(lean_object* v_j_1058_, lean_object* v_k_1059_){
_start:
{
lean_object* v___x_1060_; lean_object* v___x_1061_; 
v___x_1060_ = l_Lean_Json_getObjValD(v_j_1058_, v_k_1059_);
v___x_1061_ = l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00RunExperiment_handle_spec__0_spec__0(v___x_1060_);
return v___x_1061_;
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00RunExperiment_handle_spec__0___boxed(lean_object* v_j_1062_, lean_object* v_k_1063_){
_start:
{
lean_object* v_res_1064_; 
v_res_1064_ = l_Lean_Json_getObjValAs_x3f___at___00RunExperiment_handle_spec__0(v_j_1062_, v_k_1063_);
lean_dec_ref(v_k_1063_);
return v_res_1064_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_handle(lean_object* v_j_1081_){
_start:
{
lean_object* v___y_1084_; lean_object* v___y_1085_; lean_object* v___y_1086_; uint8_t v___y_1087_; lean_object* v___x_1117_; lean_object* v___x_1118_; lean_object* v___x_1119_; 
v___x_1117_ = ((lean_object*)(l_RunExperiment_handle___closed__7));
lean_inc(v_j_1081_);
v___x_1118_ = l_Lean_Json_getObjValAs_x3f___at___00RunExperiment_handle_spec__0(v_j_1081_, v___x_1117_);
v___x_1119_ = l_RunExperiment_orError___redArg(v___x_1118_);
if (lean_obj_tag(v___x_1119_) == 0)
{
lean_object* v_a_1120_; lean_object* v___x_1121_; lean_object* v___x_1122_; lean_object* v___x_1123_; 
v_a_1120_ = lean_ctor_get(v___x_1119_, 0);
lean_inc(v_a_1120_);
lean_dec_ref_known(v___x_1119_, 1);
v___x_1121_ = ((lean_object*)(l_RunExperiment_handle___closed__8));
lean_inc(v_j_1081_);
v___x_1122_ = l_Lean_Json_getObjValAs_x3f___at___00RunExperiment_handle_spec__0(v_j_1081_, v___x_1121_);
v___x_1123_ = l_RunExperiment_orError___redArg(v___x_1122_);
if (lean_obj_tag(v___x_1123_) == 0)
{
lean_object* v_a_1124_; lean_object* v___x_1125_; lean_object* v___x_1126_; lean_object* v___x_1127_; 
v_a_1124_ = lean_ctor_get(v___x_1123_, 0);
lean_inc(v_a_1124_);
lean_dec_ref_known(v___x_1123_, 1);
v___x_1125_ = ((lean_object*)(l_RunExperiment_handle___closed__9));
lean_inc(v_j_1081_);
v___x_1126_ = lp_LeanSearchClient_Lean_Json_getObjValAs_x3f___at___00LeanSearchClient_getLoogleQueryJson_spec__4(v_j_1081_, v___x_1125_);
v___x_1127_ = l_RunExperiment_orError___redArg(v___x_1126_);
if (lean_obj_tag(v___x_1127_) == 0)
{
lean_object* v_a_1128_; lean_object* v___x_1129_; lean_object* v___x_1130_; lean_object* v___x_1131_; 
v_a_1128_ = lean_ctor_get(v___x_1127_, 0);
lean_inc(v_a_1128_);
lean_dec_ref_known(v___x_1127_, 1);
v___x_1129_ = ((lean_object*)(l_RunExperiment_handle___closed__10));
lean_inc(v_j_1081_);
v___x_1130_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_1081_, v___x_1129_);
v___x_1131_ = l_RunExperiment_orError___redArg(v___x_1130_);
if (lean_obj_tag(v___x_1131_) == 0)
{
lean_object* v_a_1132_; lean_object* v___x_1133_; lean_object* v___x_1134_; lean_object* v___x_1135_; 
v_a_1132_ = lean_ctor_get(v___x_1131_, 0);
lean_inc(v_a_1132_);
lean_dec_ref_known(v___x_1131_, 1);
v___x_1133_ = ((lean_object*)(l_RunExperiment_handle___closed__11));
v___x_1134_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_1081_, v___x_1133_);
v___x_1135_ = l_RunExperiment_orError___redArg(v___x_1134_);
if (lean_obj_tag(v___x_1135_) == 0)
{
lean_object* v_a_1136_; lean_object* v___x_1138_; uint8_t v_isShared_1139_; uint8_t v_isSharedCheck_1206_; 
v_a_1136_ = lean_ctor_get(v___x_1135_, 0);
v_isSharedCheck_1206_ = !lean_is_exclusive(v___x_1135_);
if (v_isSharedCheck_1206_ == 0)
{
v___x_1138_ = v___x_1135_;
v_isShared_1139_ = v_isSharedCheck_1206_;
goto v_resetjp_1137_;
}
else
{
lean_inc(v_a_1136_);
lean_dec(v___x_1135_);
v___x_1138_ = lean_box(0);
v_isShared_1139_ = v_isSharedCheck_1206_;
goto v_resetjp_1137_;
}
v_resetjp_1137_:
{
uint8_t v___y_1146_; lean_object* v___x_1202_; uint8_t v___x_1203_; 
v___x_1202_ = lean_unsigned_to_nat(1u);
v___x_1203_ = lean_nat_dec_le(v___x_1202_, v_a_1132_);
if (v___x_1203_ == 0)
{
v___y_1146_ = v___x_1203_;
goto v___jp_1145_;
}
else
{
lean_object* v___x_1204_; uint8_t v___x_1205_; 
v___x_1204_ = lean_unsigned_to_nat(21u);
v___x_1205_ = lean_nat_dec_le(v_a_1132_, v___x_1204_);
v___y_1146_ = v___x_1205_;
goto v___jp_1145_;
}
v___jp_1140_:
{
lean_object* v___x_1141_; lean_object* v___x_1143_; 
v___x_1141_ = ((lean_object*)(l_RunExperiment_handle___closed__13));
if (v_isShared_1139_ == 0)
{
lean_ctor_set_tag(v___x_1138_, 1);
lean_ctor_set(v___x_1138_, 0, v___x_1141_);
v___x_1143_ = v___x_1138_;
goto v_reusejp_1142_;
}
else
{
lean_object* v_reuseFailAlloc_1144_; 
v_reuseFailAlloc_1144_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1144_, 0, v___x_1141_);
v___x_1143_ = v_reuseFailAlloc_1144_;
goto v_reusejp_1142_;
}
v_reusejp_1142_:
{
return v___x_1143_;
}
}
v___jp_1145_:
{
if (v___y_1146_ == 0)
{
lean_dec(v_a_1136_);
lean_dec(v_a_1132_);
lean_dec(v_a_1128_);
lean_dec(v_a_1124_);
lean_dec(v_a_1120_);
goto v___jp_1140_;
}
else
{
uint8_t v___x_1147_; 
v___x_1147_ = l_List_isEmpty___redArg(v_a_1128_);
if (v___x_1147_ == 0)
{
lean_object* v___x_1148_; lean_object* v___x_1149_; 
lean_del_object(v___x_1138_);
v___x_1148_ = lean_box(0);
v___x_1149_ = l_List_mapM_loop___at___00RunExperiment_handle_spec__1(v_a_1128_, v___x_1148_);
if (lean_obj_tag(v___x_1149_) == 0)
{
lean_object* v_a_1150_; lean_object* v___x_1151_; lean_object* v___x_1152_; lean_object* v___x_1153_; lean_object* v___x_1154_; lean_object* v___x_1155_; 
v_a_1150_ = lean_ctor_get(v___x_1149_, 0);
lean_inc(v_a_1150_);
lean_dec_ref_known(v___x_1149_, 1);
lean_inc(v_a_1120_);
v___x_1151_ = lean_st_mk_ref(v_a_1120_);
v___x_1152_ = lean_unsigned_to_nat(0u);
v___x_1153_ = lean_st_mk_ref(v___x_1152_);
v___x_1154_ = lean_box(0);
v___x_1155_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__4___redArg(v___x_1151_, v___x_1153_, v_a_1124_, v_a_1150_, v___x_1154_);
if (lean_obj_tag(v___x_1155_) == 0)
{
lean_object* v___x_1156_; lean_object* v___x_1157_; lean_object* v___x_1158_; 
lean_dec_ref_known(v___x_1155_, 1);
lean_inc_n(v_a_1150_, 2);
v___x_1156_ = l_List_mapTR_loop___at___00RunExperiment_handle_spec__5(v_a_1150_, v___x_1148_);
lean_inc(v_a_1132_);
v___x_1157_ = l_List_range(v_a_1132_);
v___x_1158_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6___redArg(v___x_1151_, v___x_1153_, v_a_1124_, v_a_1136_, v_a_1150_, v___x_1157_, v___x_1156_);
lean_dec(v___x_1157_);
lean_dec(v_a_1136_);
lean_dec(v___x_1153_);
lean_dec(v___x_1151_);
if (lean_obj_tag(v___x_1158_) == 0)
{
lean_object* v_a_1159_; lean_object* v___x_1160_; 
v_a_1159_ = lean_ctor_get(v___x_1158_, 0);
lean_inc(v_a_1159_);
lean_dec_ref_known(v___x_1158_, 1);
lean_inc(v_a_1120_);
v___x_1160_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg(v_a_1120_, v_a_1124_, v_a_1159_, v_a_1132_, v_a_1150_, v___x_1148_);
lean_dec(v_a_1150_);
lean_dec(v_a_1159_);
lean_dec(v_a_1124_);
if (lean_obj_tag(v___x_1160_) == 0)
{
lean_object* v_a_1161_; lean_object* v___x_1162_; lean_object* v___x_1163_; lean_object* v_ret_1164_; lean_object* v_time_1165_; lean_object* v___x_1166_; lean_object* v___x_1167_; uint8_t v___x_1168_; 
v_a_1161_ = lean_ctor_get(v___x_1160_, 0);
lean_inc(v_a_1161_);
lean_dec_ref_known(v___x_1160_, 1);
lean_inc(v_a_1120_);
v___x_1162_ = l_LeanSort_RunAdaptive_discover___redArg(v_a_1120_);
v___x_1163_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_RunAdaptive_Strategy_run___at___00RunExperiment_timedRun_spec__0_spec__0___redArg(v___x_1162_);
v_ret_1164_ = lean_ctor_get(v___x_1163_, 0);
lean_inc_n(v_ret_1164_, 2);
v_time_1165_ = lean_ctor_get(v___x_1163_, 1);
lean_inc(v_time_1165_);
lean_dec_ref(v___x_1163_);
v___x_1166_ = ((lean_object*)(l_LeanSort_CostedPlan_Schema_readyCheck___at___00RunExperiment_profile_spec__1___closed__0));
v___x_1167_ = l___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00RunExperiment_handle_spec__10(v_ret_1164_, v___x_1166_);
v___x_1168_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v___x_1167_, v_a_1120_);
lean_dec(v_a_1120_);
lean_dec(v___x_1167_);
if (v___x_1168_ == 0)
{
v___y_1084_ = v_a_1161_;
v___y_1085_ = v_ret_1164_;
v___y_1086_ = v_time_1165_;
v___y_1087_ = v___x_1168_;
goto v___jp_1083_;
}
else
{
uint8_t v___x_1169_; 
lean_inc(v_ret_1164_);
v___x_1169_ = l_List_all___at___00RunExperiment_handle_spec__11(v___x_1168_, v___x_1147_, v_ret_1164_);
v___y_1084_ = v_a_1161_;
v___y_1085_ = v_ret_1164_;
v___y_1086_ = v_time_1165_;
v___y_1087_ = v___x_1169_;
goto v___jp_1083_;
}
}
else
{
lean_object* v_a_1170_; lean_object* v___x_1172_; uint8_t v_isShared_1173_; uint8_t v_isSharedCheck_1177_; 
lean_dec(v_a_1120_);
v_a_1170_ = lean_ctor_get(v___x_1160_, 0);
v_isSharedCheck_1177_ = !lean_is_exclusive(v___x_1160_);
if (v_isSharedCheck_1177_ == 0)
{
v___x_1172_ = v___x_1160_;
v_isShared_1173_ = v_isSharedCheck_1177_;
goto v_resetjp_1171_;
}
else
{
lean_inc(v_a_1170_);
lean_dec(v___x_1160_);
v___x_1172_ = lean_box(0);
v_isShared_1173_ = v_isSharedCheck_1177_;
goto v_resetjp_1171_;
}
v_resetjp_1171_:
{
lean_object* v___x_1175_; 
if (v_isShared_1173_ == 0)
{
v___x_1175_ = v___x_1172_;
goto v_reusejp_1174_;
}
else
{
lean_object* v_reuseFailAlloc_1176_; 
v_reuseFailAlloc_1176_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1176_, 0, v_a_1170_);
v___x_1175_ = v_reuseFailAlloc_1176_;
goto v_reusejp_1174_;
}
v_reusejp_1174_:
{
return v___x_1175_;
}
}
}
}
else
{
lean_object* v_a_1178_; lean_object* v___x_1180_; uint8_t v_isShared_1181_; uint8_t v_isSharedCheck_1185_; 
lean_dec(v_a_1150_);
lean_dec(v_a_1132_);
lean_dec(v_a_1124_);
lean_dec(v_a_1120_);
v_a_1178_ = lean_ctor_get(v___x_1158_, 0);
v_isSharedCheck_1185_ = !lean_is_exclusive(v___x_1158_);
if (v_isSharedCheck_1185_ == 0)
{
v___x_1180_ = v___x_1158_;
v_isShared_1181_ = v_isSharedCheck_1185_;
goto v_resetjp_1179_;
}
else
{
lean_inc(v_a_1178_);
lean_dec(v___x_1158_);
v___x_1180_ = lean_box(0);
v_isShared_1181_ = v_isSharedCheck_1185_;
goto v_resetjp_1179_;
}
v_resetjp_1179_:
{
lean_object* v___x_1183_; 
if (v_isShared_1181_ == 0)
{
v___x_1183_ = v___x_1180_;
goto v_reusejp_1182_;
}
else
{
lean_object* v_reuseFailAlloc_1184_; 
v_reuseFailAlloc_1184_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1184_, 0, v_a_1178_);
v___x_1183_ = v_reuseFailAlloc_1184_;
goto v_reusejp_1182_;
}
v_reusejp_1182_:
{
return v___x_1183_;
}
}
}
}
else
{
lean_object* v_a_1186_; lean_object* v___x_1188_; uint8_t v_isShared_1189_; uint8_t v_isSharedCheck_1193_; 
lean_dec(v___x_1153_);
lean_dec(v___x_1151_);
lean_dec(v_a_1150_);
lean_dec(v_a_1136_);
lean_dec(v_a_1132_);
lean_dec(v_a_1124_);
lean_dec(v_a_1120_);
v_a_1186_ = lean_ctor_get(v___x_1155_, 0);
v_isSharedCheck_1193_ = !lean_is_exclusive(v___x_1155_);
if (v_isSharedCheck_1193_ == 0)
{
v___x_1188_ = v___x_1155_;
v_isShared_1189_ = v_isSharedCheck_1193_;
goto v_resetjp_1187_;
}
else
{
lean_inc(v_a_1186_);
lean_dec(v___x_1155_);
v___x_1188_ = lean_box(0);
v_isShared_1189_ = v_isSharedCheck_1193_;
goto v_resetjp_1187_;
}
v_resetjp_1187_:
{
lean_object* v___x_1191_; 
if (v_isShared_1189_ == 0)
{
v___x_1191_ = v___x_1188_;
goto v_reusejp_1190_;
}
else
{
lean_object* v_reuseFailAlloc_1192_; 
v_reuseFailAlloc_1192_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1192_, 0, v_a_1186_);
v___x_1191_ = v_reuseFailAlloc_1192_;
goto v_reusejp_1190_;
}
v_reusejp_1190_:
{
return v___x_1191_;
}
}
}
}
else
{
lean_object* v_a_1194_; lean_object* v___x_1196_; uint8_t v_isShared_1197_; uint8_t v_isSharedCheck_1201_; 
lean_dec(v_a_1136_);
lean_dec(v_a_1132_);
lean_dec(v_a_1124_);
lean_dec(v_a_1120_);
v_a_1194_ = lean_ctor_get(v___x_1149_, 0);
v_isSharedCheck_1201_ = !lean_is_exclusive(v___x_1149_);
if (v_isSharedCheck_1201_ == 0)
{
v___x_1196_ = v___x_1149_;
v_isShared_1197_ = v_isSharedCheck_1201_;
goto v_resetjp_1195_;
}
else
{
lean_inc(v_a_1194_);
lean_dec(v___x_1149_);
v___x_1196_ = lean_box(0);
v_isShared_1197_ = v_isSharedCheck_1201_;
goto v_resetjp_1195_;
}
v_resetjp_1195_:
{
lean_object* v___x_1199_; 
if (v_isShared_1197_ == 0)
{
v___x_1199_ = v___x_1196_;
goto v_reusejp_1198_;
}
else
{
lean_object* v_reuseFailAlloc_1200_; 
v_reuseFailAlloc_1200_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1200_, 0, v_a_1194_);
v___x_1199_ = v_reuseFailAlloc_1200_;
goto v_reusejp_1198_;
}
v_reusejp_1198_:
{
return v___x_1199_;
}
}
}
}
else
{
lean_dec(v_a_1136_);
lean_dec(v_a_1132_);
lean_dec(v_a_1128_);
lean_dec(v_a_1124_);
lean_dec(v_a_1120_);
goto v___jp_1140_;
}
}
}
}
}
else
{
lean_object* v_a_1207_; lean_object* v___x_1209_; uint8_t v_isShared_1210_; uint8_t v_isSharedCheck_1214_; 
lean_dec(v_a_1132_);
lean_dec(v_a_1128_);
lean_dec(v_a_1124_);
lean_dec(v_a_1120_);
v_a_1207_ = lean_ctor_get(v___x_1135_, 0);
v_isSharedCheck_1214_ = !lean_is_exclusive(v___x_1135_);
if (v_isSharedCheck_1214_ == 0)
{
v___x_1209_ = v___x_1135_;
v_isShared_1210_ = v_isSharedCheck_1214_;
goto v_resetjp_1208_;
}
else
{
lean_inc(v_a_1207_);
lean_dec(v___x_1135_);
v___x_1209_ = lean_box(0);
v_isShared_1210_ = v_isSharedCheck_1214_;
goto v_resetjp_1208_;
}
v_resetjp_1208_:
{
lean_object* v___x_1212_; 
if (v_isShared_1210_ == 0)
{
v___x_1212_ = v___x_1209_;
goto v_reusejp_1211_;
}
else
{
lean_object* v_reuseFailAlloc_1213_; 
v_reuseFailAlloc_1213_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1213_, 0, v_a_1207_);
v___x_1212_ = v_reuseFailAlloc_1213_;
goto v_reusejp_1211_;
}
v_reusejp_1211_:
{
return v___x_1212_;
}
}
}
}
else
{
lean_object* v_a_1215_; lean_object* v___x_1217_; uint8_t v_isShared_1218_; uint8_t v_isSharedCheck_1222_; 
lean_dec(v_a_1128_);
lean_dec(v_a_1124_);
lean_dec(v_a_1120_);
lean_dec(v_j_1081_);
v_a_1215_ = lean_ctor_get(v___x_1131_, 0);
v_isSharedCheck_1222_ = !lean_is_exclusive(v___x_1131_);
if (v_isSharedCheck_1222_ == 0)
{
v___x_1217_ = v___x_1131_;
v_isShared_1218_ = v_isSharedCheck_1222_;
goto v_resetjp_1216_;
}
else
{
lean_inc(v_a_1215_);
lean_dec(v___x_1131_);
v___x_1217_ = lean_box(0);
v_isShared_1218_ = v_isSharedCheck_1222_;
goto v_resetjp_1216_;
}
v_resetjp_1216_:
{
lean_object* v___x_1220_; 
if (v_isShared_1218_ == 0)
{
v___x_1220_ = v___x_1217_;
goto v_reusejp_1219_;
}
else
{
lean_object* v_reuseFailAlloc_1221_; 
v_reuseFailAlloc_1221_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1221_, 0, v_a_1215_);
v___x_1220_ = v_reuseFailAlloc_1221_;
goto v_reusejp_1219_;
}
v_reusejp_1219_:
{
return v___x_1220_;
}
}
}
}
else
{
lean_object* v_a_1223_; lean_object* v___x_1225_; uint8_t v_isShared_1226_; uint8_t v_isSharedCheck_1230_; 
lean_dec(v_a_1124_);
lean_dec(v_a_1120_);
lean_dec(v_j_1081_);
v_a_1223_ = lean_ctor_get(v___x_1127_, 0);
v_isSharedCheck_1230_ = !lean_is_exclusive(v___x_1127_);
if (v_isSharedCheck_1230_ == 0)
{
v___x_1225_ = v___x_1127_;
v_isShared_1226_ = v_isSharedCheck_1230_;
goto v_resetjp_1224_;
}
else
{
lean_inc(v_a_1223_);
lean_dec(v___x_1127_);
v___x_1225_ = lean_box(0);
v_isShared_1226_ = v_isSharedCheck_1230_;
goto v_resetjp_1224_;
}
v_resetjp_1224_:
{
lean_object* v___x_1228_; 
if (v_isShared_1226_ == 0)
{
v___x_1228_ = v___x_1225_;
goto v_reusejp_1227_;
}
else
{
lean_object* v_reuseFailAlloc_1229_; 
v_reuseFailAlloc_1229_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1229_, 0, v_a_1223_);
v___x_1228_ = v_reuseFailAlloc_1229_;
goto v_reusejp_1227_;
}
v_reusejp_1227_:
{
return v___x_1228_;
}
}
}
}
else
{
lean_object* v_a_1231_; lean_object* v___x_1233_; uint8_t v_isShared_1234_; uint8_t v_isSharedCheck_1238_; 
lean_dec(v_a_1120_);
lean_dec(v_j_1081_);
v_a_1231_ = lean_ctor_get(v___x_1123_, 0);
v_isSharedCheck_1238_ = !lean_is_exclusive(v___x_1123_);
if (v_isSharedCheck_1238_ == 0)
{
v___x_1233_ = v___x_1123_;
v_isShared_1234_ = v_isSharedCheck_1238_;
goto v_resetjp_1232_;
}
else
{
lean_inc(v_a_1231_);
lean_dec(v___x_1123_);
v___x_1233_ = lean_box(0);
v_isShared_1234_ = v_isSharedCheck_1238_;
goto v_resetjp_1232_;
}
v_resetjp_1232_:
{
lean_object* v___x_1236_; 
if (v_isShared_1234_ == 0)
{
v___x_1236_ = v___x_1233_;
goto v_reusejp_1235_;
}
else
{
lean_object* v_reuseFailAlloc_1237_; 
v_reuseFailAlloc_1237_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1237_, 0, v_a_1231_);
v___x_1236_ = v_reuseFailAlloc_1237_;
goto v_reusejp_1235_;
}
v_reusejp_1235_:
{
return v___x_1236_;
}
}
}
}
else
{
lean_object* v_a_1239_; lean_object* v___x_1241_; uint8_t v_isShared_1242_; uint8_t v_isSharedCheck_1246_; 
lean_dec(v_j_1081_);
v_a_1239_ = lean_ctor_get(v___x_1119_, 0);
v_isSharedCheck_1246_ = !lean_is_exclusive(v___x_1119_);
if (v_isSharedCheck_1246_ == 0)
{
v___x_1241_ = v___x_1119_;
v_isShared_1242_ = v_isSharedCheck_1246_;
goto v_resetjp_1240_;
}
else
{
lean_inc(v_a_1239_);
lean_dec(v___x_1119_);
v___x_1241_ = lean_box(0);
v_isShared_1242_ = v_isSharedCheck_1246_;
goto v_resetjp_1240_;
}
v_resetjp_1240_:
{
lean_object* v___x_1244_; 
if (v_isShared_1242_ == 0)
{
v___x_1244_ = v___x_1241_;
goto v_reusejp_1243_;
}
else
{
lean_object* v_reuseFailAlloc_1245_; 
v_reuseFailAlloc_1245_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1245_, 0, v_a_1239_);
v___x_1244_ = v_reuseFailAlloc_1245_;
goto v_reusejp_1243_;
}
v_reusejp_1243_:
{
return v___x_1244_;
}
}
}
v___jp_1083_:
{
if (v___y_1087_ == 0)
{
lean_object* v___x_1088_; lean_object* v___x_1089_; 
lean_dec(v___y_1086_);
lean_dec(v___y_1085_);
lean_dec(v___y_1084_);
v___x_1088_ = ((lean_object*)(l_RunExperiment_handle___closed__1));
v___x_1089_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1089_, 0, v___x_1088_);
return v___x_1089_;
}
else
{
lean_object* v___x_1090_; lean_object* v___x_1091_; lean_object* v___x_1092_; lean_object* v___x_1093_; lean_object* v___x_1094_; lean_object* v___x_1095_; lean_object* v___x_1096_; lean_object* v___x_1097_; lean_object* v___x_1098_; lean_object* v___x_1099_; lean_object* v___x_1100_; lean_object* v___x_1101_; lean_object* v___x_1102_; lean_object* v___x_1103_; lean_object* v___x_1104_; lean_object* v___x_1105_; lean_object* v___x_1106_; lean_object* v___x_1107_; lean_object* v___x_1108_; lean_object* v___x_1109_; lean_object* v___x_1110_; lean_object* v___x_1111_; lean_object* v___x_1112_; lean_object* v___x_1113_; lean_object* v___x_1114_; lean_object* v___x_1115_; lean_object* v___x_1116_; 
v___x_1090_ = ((lean_object*)(l_RunExperiment_handle___closed__2));
v___x_1091_ = lean_box(0);
lean_inc(v___y_1085_);
v___x_1092_ = l_List_mapTR_loop___at___00RunExperiment_handle_spec__9(v___y_1085_, v___x_1091_);
v___x_1093_ = l_Lean_List_toJson___at___00RunExperiment_shape_spec__0(v___x_1092_);
v___x_1094_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1094_, 0, v___x_1090_);
lean_ctor_set(v___x_1094_, 1, v___x_1093_);
v___x_1095_ = ((lean_object*)(l_RunExperiment_handle___closed__3));
v___x_1096_ = l_List_lengthTR___redArg(v___y_1085_);
lean_dec(v___y_1085_);
v___x_1097_ = l_Lean_JsonNumber_fromNat(v___x_1096_);
v___x_1098_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1098_, 0, v___x_1097_);
v___x_1099_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1099_, 0, v___x_1095_);
lean_ctor_set(v___x_1099_, 1, v___x_1098_);
v___x_1100_ = ((lean_object*)(l_RunExperiment_handle___closed__4));
v___x_1101_ = l_Lean_JsonNumber_fromNat(v___y_1086_);
v___x_1102_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1102_, 0, v___x_1101_);
v___x_1103_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1103_, 0, v___x_1100_);
lean_ctor_set(v___x_1103_, 1, v___x_1102_);
v___x_1104_ = ((lean_object*)(l_RunExperiment_handle___closed__5));
v___x_1105_ = l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(v___y_1084_);
v___x_1106_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1106_, 0, v___x_1104_);
lean_ctor_set(v___x_1106_, 1, v___x_1105_);
v___x_1107_ = ((lean_object*)(l_RunExperiment_handle___closed__6));
v___x_1108_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_1108_, 0, v___y_1087_);
v___x_1109_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1109_, 0, v___x_1107_);
lean_ctor_set(v___x_1109_, 1, v___x_1108_);
v___x_1110_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1110_, 0, v___x_1109_);
lean_ctor_set(v___x_1110_, 1, v___x_1091_);
v___x_1111_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1111_, 0, v___x_1106_);
lean_ctor_set(v___x_1111_, 1, v___x_1110_);
v___x_1112_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1112_, 0, v___x_1103_);
lean_ctor_set(v___x_1112_, 1, v___x_1111_);
v___x_1113_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1113_, 0, v___x_1099_);
lean_ctor_set(v___x_1113_, 1, v___x_1112_);
v___x_1114_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1114_, 0, v___x_1094_);
lean_ctor_set(v___x_1114_, 1, v___x_1113_);
v___x_1115_ = l_Lean_Json_mkObj(v___x_1114_);
lean_dec_ref_known(v___x_1114_, 2);
v___x_1116_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1116_, 0, v___x_1115_);
return v___x_1116_;
}
}
}
}
LEAN_EXPORT lean_object* l_RunExperiment_handle___boxed(lean_object* v_j_1247_, lean_object* v_a_1248_){
_start:
{
lean_object* v_res_1249_; 
v_res_1249_ = l_RunExperiment_handle(v_j_1247_);
return v_res_1249_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__3(lean_object* v_val_1250_, lean_object* v_val_1251_, lean_object* v_a_1252_, lean_object* v_as_1253_, lean_object* v_as_x27_1254_, lean_object* v_b_1255_, lean_object* v_a_1256_){
_start:
{
lean_object* v___x_1258_; 
v___x_1258_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__3___redArg(v_val_1250_, v_val_1251_, v_a_1252_, v_as_x27_1254_, v_b_1255_);
return v___x_1258_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__3___boxed(lean_object* v_val_1259_, lean_object* v_val_1260_, lean_object* v_a_1261_, lean_object* v_as_1262_, lean_object* v_as_x27_1263_, lean_object* v_b_1264_, lean_object* v_a_1265_, lean_object* v___y_1266_){
_start:
{
lean_object* v_res_1267_; 
v_res_1267_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__3(v_val_1259_, v_val_1260_, v_a_1261_, v_as_1262_, v_as_x27_1263_, v_b_1264_, v_a_1265_);
lean_dec(v_as_x27_1263_);
lean_dec(v_as_1262_);
lean_dec(v_a_1261_);
lean_dec(v_val_1260_);
lean_dec(v_val_1259_);
return v_res_1267_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__4(lean_object* v_val_1268_, lean_object* v_val_1269_, lean_object* v_a_1270_, lean_object* v_as_1271_, lean_object* v_as_x27_1272_, lean_object* v_b_1273_, lean_object* v_a_1274_){
_start:
{
lean_object* v___x_1276_; 
v___x_1276_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__4___redArg(v_val_1268_, v_val_1269_, v_a_1270_, v_as_x27_1272_, v_b_1273_);
return v___x_1276_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__4___boxed(lean_object* v_val_1277_, lean_object* v_val_1278_, lean_object* v_a_1279_, lean_object* v_as_1280_, lean_object* v_as_x27_1281_, lean_object* v_b_1282_, lean_object* v_a_1283_, lean_object* v___y_1284_){
_start:
{
lean_object* v_res_1285_; 
v_res_1285_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__4(v_val_1277_, v_val_1278_, v_a_1279_, v_as_1280_, v_as_x27_1281_, v_b_1282_, v_a_1283_);
lean_dec(v_as_x27_1281_);
lean_dec(v_as_1280_);
lean_dec(v_a_1279_);
lean_dec(v_val_1278_);
lean_dec(v_val_1277_);
return v_res_1285_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6(lean_object* v_val_1286_, lean_object* v_val_1287_, lean_object* v_a_1288_, lean_object* v_a_1289_, lean_object* v_a_1290_, lean_object* v_as_1291_, lean_object* v_as_x27_1292_, lean_object* v_b_1293_, lean_object* v_a_1294_){
_start:
{
lean_object* v___x_1296_; 
v___x_1296_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6___redArg(v_val_1286_, v_val_1287_, v_a_1288_, v_a_1289_, v_a_1290_, v_as_x27_1292_, v_b_1293_);
return v___x_1296_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6___boxed(lean_object* v_val_1297_, lean_object* v_val_1298_, lean_object* v_a_1299_, lean_object* v_a_1300_, lean_object* v_a_1301_, lean_object* v_as_1302_, lean_object* v_as_x27_1303_, lean_object* v_b_1304_, lean_object* v_a_1305_, lean_object* v___y_1306_){
_start:
{
lean_object* v_res_1307_; 
v_res_1307_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__6(v_val_1297_, v_val_1298_, v_a_1299_, v_a_1300_, v_a_1301_, v_as_1302_, v_as_x27_1303_, v_b_1304_, v_a_1305_);
lean_dec(v_as_x27_1303_);
lean_dec(v_as_1302_);
lean_dec(v_a_1300_);
lean_dec(v_a_1299_);
lean_dec(v_val_1298_);
lean_dec(v_val_1297_);
return v_res_1307_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8(lean_object* v_a_1308_, lean_object* v_a_1309_, lean_object* v_a_1310_, lean_object* v_a_1311_, lean_object* v_as_1312_, lean_object* v_as_x27_1313_, lean_object* v_b_1314_, lean_object* v_a_1315_){
_start:
{
lean_object* v___x_1317_; 
v___x_1317_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___redArg(v_a_1308_, v_a_1309_, v_a_1310_, v_a_1311_, v_as_x27_1313_, v_b_1314_);
return v___x_1317_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8___boxed(lean_object* v_a_1318_, lean_object* v_a_1319_, lean_object* v_a_1320_, lean_object* v_a_1321_, lean_object* v_as_1322_, lean_object* v_as_x27_1323_, lean_object* v_b_1324_, lean_object* v_a_1325_, lean_object* v___y_1326_){
_start:
{
lean_object* v_res_1327_; 
v_res_1327_ = l_List_forIn_x27_loop___at___00RunExperiment_handle_spec__8(v_a_1318_, v_a_1319_, v_a_1320_, v_a_1321_, v_as_1322_, v_as_x27_1323_, v_b_1324_, v_a_1325_);
lean_dec(v_as_x27_1323_);
lean_dec(v_as_1322_);
lean_dec(v_a_1320_);
lean_dec(v_a_1319_);
return v_res_1327_;
}
}
LEAN_EXPORT lean_object* l_RunExperiment_loop(){
_start:
{
lean_object* v___x_1330_; lean_object* v___x_1331_; lean_object* v_a_1333_; lean_object* v___y_1340_; lean_object* v_getLine_1356_; lean_object* v___x_1357_; 
v___x_1330_ = lean_get_stdin();
v___x_1331_ = lean_get_stdout();
v_getLine_1356_ = lean_ctor_get(v___x_1330_, 3);
lean_inc_ref(v_getLine_1356_);
lean_dec_ref(v___x_1330_);
v___x_1357_ = lean_apply_1(v_getLine_1356_, lean_box(0));
if (lean_obj_tag(v___x_1357_) == 0)
{
lean_object* v_a_1358_; lean_object* v___x_1360_; uint8_t v_isShared_1361_; uint8_t v_isSharedCheck_1373_; 
v_a_1358_ = lean_ctor_get(v___x_1357_, 0);
v_isSharedCheck_1373_ = !lean_is_exclusive(v___x_1357_);
if (v_isSharedCheck_1373_ == 0)
{
v___x_1360_ = v___x_1357_;
v_isShared_1361_ = v_isSharedCheck_1373_;
goto v_resetjp_1359_;
}
else
{
lean_inc(v_a_1358_);
lean_dec(v___x_1357_);
v___x_1360_ = lean_box(0);
v_isShared_1361_ = v_isSharedCheck_1373_;
goto v_resetjp_1359_;
}
v_resetjp_1359_:
{
lean_object* v___x_1362_; lean_object* v___x_1363_; uint8_t v___x_1364_; 
v___x_1362_ = lean_string_utf8_byte_size(v_a_1358_);
v___x_1363_ = lean_unsigned_to_nat(0u);
v___x_1364_ = lean_nat_dec_eq(v___x_1362_, v___x_1363_);
if (v___x_1364_ == 0)
{
lean_object* v___x_1365_; lean_object* v___x_1366_; 
lean_del_object(v___x_1360_);
v___x_1365_ = l_Lean_Json_parse(v_a_1358_);
v___x_1366_ = l_RunExperiment_orError___redArg(v___x_1365_);
if (lean_obj_tag(v___x_1366_) == 0)
{
lean_object* v_a_1367_; lean_object* v___x_1368_; 
v_a_1367_ = lean_ctor_get(v___x_1366_, 0);
lean_inc(v_a_1367_);
lean_dec_ref_known(v___x_1366_, 1);
v___x_1368_ = l_RunExperiment_handle(v_a_1367_);
v___y_1340_ = v___x_1368_;
goto v___jp_1339_;
}
else
{
v___y_1340_ = v___x_1366_;
goto v___jp_1339_;
}
}
else
{
lean_object* v___x_1369_; lean_object* v___x_1371_; 
lean_dec(v_a_1358_);
lean_dec_ref(v___x_1331_);
v___x_1369_ = lean_box(0);
if (v_isShared_1361_ == 0)
{
lean_ctor_set(v___x_1360_, 0, v___x_1369_);
v___x_1371_ = v___x_1360_;
goto v_reusejp_1370_;
}
else
{
lean_object* v_reuseFailAlloc_1372_; 
v_reuseFailAlloc_1372_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1372_, 0, v___x_1369_);
v___x_1371_ = v_reuseFailAlloc_1372_;
goto v_reusejp_1370_;
}
v_reusejp_1370_:
{
return v___x_1371_;
}
}
}
}
else
{
lean_object* v_a_1374_; lean_object* v___x_1376_; uint8_t v_isShared_1377_; uint8_t v_isSharedCheck_1381_; 
lean_dec_ref(v___x_1331_);
v_a_1374_ = lean_ctor_get(v___x_1357_, 0);
v_isSharedCheck_1381_ = !lean_is_exclusive(v___x_1357_);
if (v_isSharedCheck_1381_ == 0)
{
v___x_1376_ = v___x_1357_;
v_isShared_1377_ = v_isSharedCheck_1381_;
goto v_resetjp_1375_;
}
else
{
lean_inc(v_a_1374_);
lean_dec(v___x_1357_);
v___x_1376_ = lean_box(0);
v_isShared_1377_ = v_isSharedCheck_1381_;
goto v_resetjp_1375_;
}
v_resetjp_1375_:
{
lean_object* v___x_1379_; 
if (v_isShared_1377_ == 0)
{
v___x_1379_ = v___x_1376_;
goto v_reusejp_1378_;
}
else
{
lean_object* v_reuseFailAlloc_1380_; 
v_reuseFailAlloc_1380_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1380_, 0, v_a_1374_);
v___x_1379_ = v_reuseFailAlloc_1380_;
goto v_reusejp_1378_;
}
v_reusejp_1378_:
{
return v___x_1379_;
}
}
}
v___jp_1332_:
{
lean_object* v___x_1334_; lean_object* v___x_1335_; 
v___x_1334_ = l_Lean_Json_compress(v_a_1333_);
lean_inc_ref(v___x_1331_);
v___x_1335_ = l_IO_FS_Stream_putStrLn(v___x_1331_, v___x_1334_);
if (lean_obj_tag(v___x_1335_) == 0)
{
lean_object* v_flush_1336_; lean_object* v___x_1337_; 
lean_dec_ref_known(v___x_1335_, 1);
v_flush_1336_ = lean_ctor_get(v___x_1331_, 0);
lean_inc_ref(v_flush_1336_);
lean_dec_ref(v___x_1331_);
v___x_1337_ = lean_apply_1(v_flush_1336_, lean_box(0));
if (lean_obj_tag(v___x_1337_) == 0)
{
lean_dec_ref_known(v___x_1337_, 1);
goto _start;
}
else
{
return v___x_1337_;
}
}
else
{
lean_dec_ref(v___x_1331_);
return v___x_1335_;
}
}
v___jp_1339_:
{
if (lean_obj_tag(v___y_1340_) == 0)
{
lean_object* v_a_1341_; 
v_a_1341_ = lean_ctor_get(v___y_1340_, 0);
lean_inc(v_a_1341_);
lean_dec_ref_known(v___y_1340_, 1);
v_a_1333_ = v_a_1341_;
goto v___jp_1332_;
}
else
{
lean_object* v_a_1342_; lean_object* v___x_1344_; uint8_t v_isShared_1345_; uint8_t v_isSharedCheck_1355_; 
v_a_1342_ = lean_ctor_get(v___y_1340_, 0);
v_isSharedCheck_1355_ = !lean_is_exclusive(v___y_1340_);
if (v_isSharedCheck_1355_ == 0)
{
v___x_1344_ = v___y_1340_;
v_isShared_1345_ = v_isSharedCheck_1355_;
goto v_resetjp_1343_;
}
else
{
lean_inc(v_a_1342_);
lean_dec(v___y_1340_);
v___x_1344_ = lean_box(0);
v_isShared_1345_ = v_isSharedCheck_1355_;
goto v_resetjp_1343_;
}
v_resetjp_1343_:
{
lean_object* v___x_1346_; lean_object* v___x_1347_; lean_object* v___x_1349_; 
v___x_1346_ = ((lean_object*)(l_RunExperiment_loop___closed__0));
v___x_1347_ = lean_io_error_to_string(v_a_1342_);
if (v_isShared_1345_ == 0)
{
lean_ctor_set_tag(v___x_1344_, 3);
lean_ctor_set(v___x_1344_, 0, v___x_1347_);
v___x_1349_ = v___x_1344_;
goto v_reusejp_1348_;
}
else
{
lean_object* v_reuseFailAlloc_1354_; 
v_reuseFailAlloc_1354_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1354_, 0, v___x_1347_);
v___x_1349_ = v_reuseFailAlloc_1354_;
goto v_reusejp_1348_;
}
v_reusejp_1348_:
{
lean_object* v___x_1350_; lean_object* v___x_1351_; lean_object* v___x_1352_; lean_object* v___x_1353_; 
v___x_1350_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1350_, 0, v___x_1346_);
lean_ctor_set(v___x_1350_, 1, v___x_1349_);
v___x_1351_ = lean_box(0);
v___x_1352_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1352_, 0, v___x_1350_);
lean_ctor_set(v___x_1352_, 1, v___x_1351_);
v___x_1353_ = l_Lean_Json_mkObj(v___x_1352_);
lean_dec_ref_known(v___x_1352_, 2);
v_a_1333_ = v___x_1353_;
goto v___jp_1332_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_RunExperiment_loop___boxed(lean_object* v_a_1382_){
_start:
{
lean_object* v_res_1383_; 
v_res_1383_ = l_RunExperiment_loop();
return v_res_1383_;
}
}
LEAN_EXPORT lean_object* _lean_main(){
_start:
{
lean_object* v___x_1386_; lean_object* v___x_1387_; lean_object* v___x_1388_; 
v___x_1386_ = lean_get_stdout();
v___x_1387_ = ((lean_object*)(l_main___closed__0));
lean_inc_ref(v___x_1386_);
v___x_1388_ = l_IO_FS_Stream_putStrLn(v___x_1386_, v___x_1387_);
if (lean_obj_tag(v___x_1388_) == 0)
{
lean_object* v_flush_1389_; lean_object* v___x_1390_; 
lean_dec_ref_known(v___x_1388_, 1);
v_flush_1389_ = lean_ctor_get(v___x_1386_, 0);
lean_inc_ref(v_flush_1389_);
lean_dec_ref(v___x_1386_);
v___x_1390_ = lean_apply_1(v_flush_1389_, lean_box(0));
if (lean_obj_tag(v___x_1390_) == 0)
{
lean_object* v___x_1391_; 
lean_dec_ref_known(v___x_1390_, 1);
v___x_1391_ = l_RunExperiment_loop();
return v___x_1391_;
}
else
{
return v___x_1390_;
}
}
else
{
lean_dec_ref(v___x_1386_);
return v___x_1388_;
}
}
}
LEAN_EXPORT lean_object* l_main___boxed(lean_object* v_a_1392_){
_start:
{
lean_object* v_res_1393_; 
v_res_1393_ = _lean_main();
return v_res_1393_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_LeanSort_Verification_RunAdaptive_Strategy(uint8_t builtin);
lean_object* initialize_Lean(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_experiments_dynamic_x2druns_Worker(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
lean_initialize();
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_LeanSort_Verification_RunAdaptive_Strategy(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Lean(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
char ** lean_setup_args(int argc, char ** argv);
#if defined(WIN32) || defined(_WIN32)
#include <windows.h>
#endif
lean_object* run_main(int argc, char ** argv) {
    return _lean_main();
}
int main(int argc, char ** argv) {
#if defined(WIN32) || defined(_WIN32)
  SetErrorMode(SEM_FAILCRITICALERRORS);
  SetConsoleOutputCP(CP_UTF8);
#endif
  lean_object* res;
  argv = lean_setup_args(argc, argv);
  res = initialize_experiments_dynamic_x2druns_Worker(1 /* builtin */);
  lean_io_mark_end_initialization();
  if (lean_io_result_is_ok(res)) {
    lean_dec_ref(res);
    lean_init_task_manager();
    res = lean_run_main(&run_main, argc, argv);
  }
  lean_finalize_task_manager();
  if (lean_io_result_is_ok(res)) {
    int ret = 0;
    lean_dec_ref(res);
    return ret;
  } else {
    lean_io_result_show_error(res);
    lean_dec_ref(res);
    return 1;
  }
}
#ifdef __cplusplus
}
#endif
