// Lean compiler output
// Module: experiments.«cost-plans».Worker
// Imports: public import Init public meta import Init public import Generated.Algorithms public import LeanSort.Verification.CostedPlan.ChecksCost public import Lean
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
lean_object* lp_leansort_LeanSort_CostedPlan_Schema_checkProgram___redArg(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_st_ref_set(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* l_List_drop___redArg(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_array_mk(lean_object*);
lean_object* l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__0(lean_object*);
lean_object* l_Lean_Json_mkObj(lean_object*);
lean_object* lp_leansort_LeanSort_CostedPlan_Schema_program___redArg(lean_object*, lean_object*);
uint8_t l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(lean_object*, lean_object*);
lean_object* lean_st_mk_ref(lean_object*);
lean_object* lp_leansort_LeanSort_CostedPlan_Cut_position(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_ComparisonSort_checkSorted___redArg(lean_object*);
lean_object* lp_leansort_LeanSort_CostedPlan_Schema_upper(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_CostedPlan_Schema_readyUpper(lean_object*, lean_object*);
lean_object* l_Lean_JsonNumber_fromNat(lean_object*);
lean_object* l_Lean_Json_compress(lean_object*);
lean_object* lean_string_utf8_byte_size(lean_object*);
lean_object* lean_get_stdout();
lean_object* l_IO_FS_Stream_putStrLn(lean_object*, lean_object*);
lean_object* lean_get_stdin();
lean_object* lean_io_error_to_string(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* l_Lean_Json_parse(lean_object*);
lean_object* l_Lean_Json_getObjValD(lean_object*, lean_object*);
lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonStackTable_fromJson_spec__0_spec__0(lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* lp_LeanSearchClient_Lean_Json_getObjValAs_x3f___at___00LeanSearchClient_getLoogleQueryJson_spec__4(lean_object*, lean_object*);
lean_object* l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(lean_object*, lean_object*);
extern lean_object* l_CostPlanGenerated_entries;
uint8_t l_List_isEmpty___redArg(lean_object*);
lean_object* l_List_range(lean_object*);
lean_object* l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(lean_object*);
LEAN_EXPORT lean_object* l_CostPlanExperiment_orError___redArg(lean_object*);
LEAN_EXPORT lean_object* l_CostPlanExperiment_orError___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_CostPlanExperiment_orError(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_CostPlanExperiment_orError___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_foldl___at___00CostPlanExperiment_checksum_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_foldl___at___00CostPlanExperiment_checksum_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_CostPlanExperiment_checksum(lean_object*);
LEAN_EXPORT lean_object* l_CostPlanExperiment_checksum___boxed(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_eval___at___00LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0_spec__0_spec__1___redArg(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_CostedPlan_Schema_eval___at___00LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0(lean_object*, lean_object*);
static const lean_string_object l_CostPlanExperiment_timedRun___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 28, .m_capacity = 28, .m_length = 27, .m_data = "incorrect deployment output"};
static const lean_object* l_CostPlanExperiment_timedRun___closed__0 = (const lean_object*)&l_CostPlanExperiment_timedRun___closed__0_value;
static const lean_ctor_object l_CostPlanExperiment_timedRun___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_CostPlanExperiment_timedRun___closed__0_value)}};
static const lean_object* l_CostPlanExperiment_timedRun___closed__1 = (const lean_object*)&l_CostPlanExperiment_timedRun___closed__1_value;
LEAN_EXPORT lean_object* l_CostPlanExperiment_timedRun(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_CostPlanExperiment_timedRun___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_eval___at___00LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0_spec__0_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_CostPlanExperiment_timedChecks(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_CostPlanExperiment_timedChecks___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object l_LeanSort_CostedPlan_Schema_readyCheck___at___00CostPlanExperiment_profile_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_LeanSort_CostedPlan_Schema_readyCheck___at___00CostPlanExperiment_profile_spec__0___closed__0 = (const lean_object*)&l_LeanSort_CostedPlan_Schema_readyCheck___at___00CostPlanExperiment_profile_spec__0___closed__0_value;
LEAN_EXPORT uint8_t l_LeanSort_CostedPlan_Schema_readyCheck___at___00CostPlanExperiment_profile_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_CostedPlan_Schema_readyCheck___at___00CostPlanExperiment_profile_spec__0___boxed(lean_object*, lean_object*);
static const lean_string_object l_CostPlanExperiment_profile___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "incorrect profile output"};
static const lean_object* l_CostPlanExperiment_profile___closed__0 = (const lean_object*)&l_CostPlanExperiment_profile___closed__0_value;
static const lean_ctor_object l_CostPlanExperiment_profile___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_CostPlanExperiment_profile___closed__0_value)}};
static const lean_object* l_CostPlanExperiment_profile___closed__1 = (const lean_object*)&l_CostPlanExperiment_profile___closed__1_value;
static const lean_string_object l_CostPlanExperiment_profile___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "strategy"};
static const lean_object* l_CostPlanExperiment_profile___closed__2 = (const lean_object*)&l_CostPlanExperiment_profile___closed__2_value;
static const lean_string_object l_CostPlanExperiment_profile___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "comparisons"};
static const lean_object* l_CostPlanExperiment_profile___closed__3 = (const lean_object*)&l_CostPlanExperiment_profile___closed__3_value;
static const lean_string_object l_CostPlanExperiment_profile___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "check_comparisons"};
static const lean_object* l_CostPlanExperiment_profile___closed__4 = (const lean_object*)&l_CostPlanExperiment_profile___closed__4_value;
static const lean_string_object l_CostPlanExperiment_profile___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "sorting_comparisons"};
static const lean_object* l_CostPlanExperiment_profile___closed__5 = (const lean_object*)&l_CostPlanExperiment_profile___closed__5_value;
static const lean_string_object l_CostPlanExperiment_profile___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "ready"};
static const lean_object* l_CostPlanExperiment_profile___closed__6 = (const lean_object*)&l_CostPlanExperiment_profile___closed__6_value;
static const lean_string_object l_CostPlanExperiment_profile___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "upper"};
static const lean_object* l_CostPlanExperiment_profile___closed__7 = (const lean_object*)&l_CostPlanExperiment_profile___closed__7_value;
static const lean_string_object l_CostPlanExperiment_profile___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "conditional_upper"};
static const lean_object* l_CostPlanExperiment_profile___closed__8 = (const lean_object*)&l_CostPlanExperiment_profile___closed__8_value;
static const lean_string_object l_CostPlanExperiment_profile___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "profile"};
static const lean_object* l_CostPlanExperiment_profile___closed__9 = (const lean_object*)&l_CostPlanExperiment_profile___closed__9_value;
static const lean_string_object l_CostPlanExperiment_profile___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "offline_profile_ns"};
static const lean_object* l_CostPlanExperiment_profile___closed__10 = (const lean_object*)&l_CostPlanExperiment_profile___closed__10_value;
static const lean_string_object l_CostPlanExperiment_profile___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "forced_bytes"};
static const lean_object* l_CostPlanExperiment_profile___closed__11 = (const lean_object*)&l_CostPlanExperiment_profile___closed__11_value;
static const lean_string_object l_CostPlanExperiment_profile___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 35, .m_capacity = 35, .m_length = 34, .m_data = "conditional certificate regression"};
static const lean_object* l_CostPlanExperiment_profile___closed__12 = (const lean_object*)&l_CostPlanExperiment_profile___closed__12_value;
static const lean_ctor_object l_CostPlanExperiment_profile___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_CostPlanExperiment_profile___closed__12_value)}};
static const lean_object* l_CostPlanExperiment_profile___closed__13 = (const lean_object*)&l_CostPlanExperiment_profile___closed__13_value;
static const lean_string_object l_CostPlanExperiment_profile___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 28, .m_capacity = 28, .m_length = 27, .m_data = "cost certificate regression"};
static const lean_object* l_CostPlanExperiment_profile___closed__14 = (const lean_object*)&l_CostPlanExperiment_profile___closed__14_value;
static const lean_ctor_object l_CostPlanExperiment_profile___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_CostPlanExperiment_profile___closed__14_value)}};
static const lean_object* l_CostPlanExperiment_profile___closed__15 = (const lean_object*)&l_CostPlanExperiment_profile___closed__15_value;
LEAN_EXPORT lean_object* l_CostPlanExperiment_profile(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_CostPlanExperiment_profile___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_find_x3f___at___00CostPlanExperiment_handle_spec__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_find_x3f___at___00CostPlanExperiment_handle_spec__2___boxed(lean_object*, lean_object*);
static const lean_string_object l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 45, .m_capacity = 45, .m_length = 44, .m_data = "unknown certified algorithm ID; no execution"};
static const lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___redArg___closed__0_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___redArg___closed__0_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___redArg___closed__1 = (const lean_object*)&l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___redArg___closed__1_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__12___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__12___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__4(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__5___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__5___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11___redArg___closed__0_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__6(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__6___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__7___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__7___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__10___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__10___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00CostPlanExperiment_handle_spec__1_spec__1(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00CostPlanExperiment_handle_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00CostPlanExperiment_handle_spec__1___boxed(lean_object*, lean_object*);
static const lean_ctor_object l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__9___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__9___closed__0 = (const lean_object*)&l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__9___closed__0_value;
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__9(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00CostPlanExperiment_handle_spec__0(lean_object*);
static const lean_string_object l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__13___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "e2e_samples_ns"};
static const lean_object* l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__13___closed__0 = (const lean_object*)&l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__13___closed__0_value;
static const lean_string_object l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__13___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "check_replay_samples_ns"};
static const lean_object* l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__13___closed__1 = (const lean_object*)&l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__13___closed__1_value;
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__13(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__8___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__8___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_CostPlanExperiment_handle___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "input"};
static const lean_object* l_CostPlanExperiment_handle___closed__0 = (const lean_object*)&l_CostPlanExperiment_handle___closed__0_value;
static const lean_string_object l_CostPlanExperiment_handle___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "expected"};
static const lean_object* l_CostPlanExperiment_handle___closed__1 = (const lean_object*)&l_CostPlanExperiment_handle___closed__1_value;
static const lean_string_object l_CostPlanExperiment_handle___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "strategies"};
static const lean_object* l_CostPlanExperiment_handle___closed__2 = (const lean_object*)&l_CostPlanExperiment_handle___closed__2_value;
static const lean_string_object l_CostPlanExperiment_handle___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "rounds"};
static const lean_object* l_CostPlanExperiment_handle___closed__3 = (const lean_object*)&l_CostPlanExperiment_handle___closed__3_value;
static const lean_string_object l_CostPlanExperiment_handle___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "order_seed"};
static const lean_object* l_CostPlanExperiment_handle___closed__4 = (const lean_object*)&l_CostPlanExperiment_handle___closed__4_value;
static const lean_string_object l_CostPlanExperiment_handle___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "invalid repetition count"};
static const lean_object* l_CostPlanExperiment_handle___closed__5 = (const lean_object*)&l_CostPlanExperiment_handle___closed__5_value;
static const lean_ctor_object l_CostPlanExperiment_handle___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_CostPlanExperiment_handle___closed__5_value)}};
static const lean_object* l_CostPlanExperiment_handle___closed__6 = (const lean_object*)&l_CostPlanExperiment_handle___closed__6_value;
static const lean_string_object l_CostPlanExperiment_handle___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "measurements"};
static const lean_object* l_CostPlanExperiment_handle___closed__7 = (const lean_object*)&l_CostPlanExperiment_handle___closed__7_value;
static const lean_string_object l_CostPlanExperiment_handle___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "profiles"};
static const lean_object* l_CostPlanExperiment_handle___closed__8 = (const lean_object*)&l_CostPlanExperiment_handle___closed__8_value;
static const lean_string_object l_CostPlanExperiment_handle___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "all_outputs_correct"};
static const lean_object* l_CostPlanExperiment_handle___closed__9 = (const lean_object*)&l_CostPlanExperiment_handle___closed__9_value;
static const lean_string_object l_CostPlanExperiment_handle___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "empty shortlist"};
static const lean_object* l_CostPlanExperiment_handle___closed__10 = (const lean_object*)&l_CostPlanExperiment_handle___closed__10_value;
static const lean_ctor_object l_CostPlanExperiment_handle___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_CostPlanExperiment_handle___closed__10_value)}};
static const lean_object* l_CostPlanExperiment_handle___closed__11 = (const lean_object*)&l_CostPlanExperiment_handle___closed__11_value;
LEAN_EXPORT lean_object* l_CostPlanExperiment_handle(lean_object*);
LEAN_EXPORT lean_object* l_CostPlanExperiment_handle___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__5(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__5___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__7(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__7___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__8(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__8___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__10(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__10___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__12(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__12___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_CostPlanExperiment_loop___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "error"};
static const lean_object* l_CostPlanExperiment_loop___closed__0 = (const lean_object*)&l_CostPlanExperiment_loop___closed__0_value;
LEAN_EXPORT lean_object* l_CostPlanExperiment_loop();
LEAN_EXPORT lean_object* l_CostPlanExperiment_loop___boxed(lean_object*);
static const lean_string_object l_main___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 56, .m_capacity = 56, .m_length = 55, .m_data = "{\"ready\":true,\"backend\":\"lean--run/comparison-program\"}"};
static const lean_object* l_main___closed__0 = (const lean_object*)&l_main___closed__0_value;
LEAN_EXPORT lean_object* _lean_main();
LEAN_EXPORT lean_object* l_main___boxed(lean_object*);
LEAN_EXPORT lean_object* l_CostPlanExperiment_orError___redArg(lean_object* v_x_1_){
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
LEAN_EXPORT lean_object* l_CostPlanExperiment_orError___redArg___boxed(lean_object* v_x_20_, lean_object* v_a_21_){
_start:
{
lean_object* v_res_22_; 
v_res_22_ = l_CostPlanExperiment_orError___redArg(v_x_20_);
return v_res_22_;
}
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_orError(lean_object* v_00_u03b1_23_, lean_object* v_x_24_){
_start:
{
lean_object* v___x_26_; 
v___x_26_ = l_CostPlanExperiment_orError___redArg(v_x_24_);
return v___x_26_;
}
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_orError___boxed(lean_object* v_00_u03b1_27_, lean_object* v_x_28_, lean_object* v_a_29_){
_start:
{
lean_object* v_res_30_; 
v_res_30_ = l_CostPlanExperiment_orError(v_00_u03b1_27_, v_x_28_);
return v_res_30_;
}
}
LEAN_EXPORT lean_object* l_List_foldl___at___00CostPlanExperiment_checksum_spec__0(lean_object* v_x_31_, lean_object* v_x_32_){
_start:
{
if (lean_obj_tag(v_x_32_) == 0)
{
return v_x_31_;
}
else
{
lean_object* v_head_33_; lean_object* v_tail_34_; lean_object* v___x_35_; lean_object* v___x_36_; lean_object* v___x_37_; lean_object* v___x_38_; lean_object* v___x_39_; 
v_head_33_ = lean_ctor_get(v_x_32_, 0);
v_tail_34_ = lean_ctor_get(v_x_32_, 1);
v___x_35_ = lean_unsigned_to_nat(33u);
v___x_36_ = lean_nat_mul(v_x_31_, v___x_35_);
lean_dec(v_x_31_);
v___x_37_ = lean_nat_add(v___x_36_, v_head_33_);
lean_dec(v___x_36_);
v___x_38_ = lean_unsigned_to_nat(1000000007u);
v___x_39_ = lean_nat_mod(v___x_37_, v___x_38_);
lean_dec(v___x_37_);
v_x_31_ = v___x_39_;
v_x_32_ = v_tail_34_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_List_foldl___at___00CostPlanExperiment_checksum_spec__0___boxed(lean_object* v_x_41_, lean_object* v_x_42_){
_start:
{
lean_object* v_res_43_; 
v_res_43_ = l_List_foldl___at___00CostPlanExperiment_checksum_spec__0(v_x_41_, v_x_42_);
lean_dec(v_x_42_);
return v_res_43_;
}
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_checksum(lean_object* v_xs_44_){
_start:
{
lean_object* v___x_45_; lean_object* v___x_46_; 
v___x_45_ = lean_unsigned_to_nat(0u);
v___x_46_ = l_List_foldl___at___00CostPlanExperiment_checksum_spec__0(v___x_45_, v_xs_44_);
return v___x_46_;
}
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_checksum___boxed(lean_object* v_xs_47_){
_start:
{
lean_object* v_res_48_; 
v_res_48_ = l_CostPlanExperiment_checksum(v_xs_47_);
lean_dec(v_xs_47_);
return v_res_48_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_eval___at___00LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0_spec__0_spec__1___redArg(lean_object* v_x_49_){
_start:
{
if (lean_obj_tag(v_x_49_) == 0)
{
lean_object* v_value_50_; lean_object* v___x_51_; lean_object* v___x_52_; 
v_value_50_ = lean_ctor_get(v_x_49_, 0);
lean_inc(v_value_50_);
lean_dec_ref_known(v_x_49_, 1);
v___x_51_ = lean_unsigned_to_nat(0u);
v___x_52_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_52_, 0, v_value_50_);
lean_ctor_set(v___x_52_, 1, v___x_51_);
return v___x_52_;
}
else
{
lean_object* v_left_53_; lean_object* v_right_54_; lean_object* v_next_55_; uint8_t v___x_56_; lean_object* v___x_57_; lean_object* v___x_58_; lean_object* v_rest_59_; lean_object* v_ret_60_; lean_object* v_time_61_; lean_object* v___x_63_; uint8_t v_isShared_64_; uint8_t v_isSharedCheck_70_; 
v_left_53_ = lean_ctor_get(v_x_49_, 0);
lean_inc(v_left_53_);
v_right_54_ = lean_ctor_get(v_x_49_, 1);
lean_inc(v_right_54_);
v_next_55_ = lean_ctor_get(v_x_49_, 2);
lean_inc_ref(v_next_55_);
lean_dec_ref_known(v_x_49_, 3);
v___x_56_ = lean_nat_dec_le(v_left_53_, v_right_54_);
lean_dec(v_right_54_);
lean_dec(v_left_53_);
v___x_57_ = lean_box(v___x_56_);
v___x_58_ = lean_apply_1(v_next_55_, v___x_57_);
v_rest_59_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_eval___at___00LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0_spec__0_spec__1___redArg(v___x_58_);
v_ret_60_ = lean_ctor_get(v_rest_59_, 0);
v_time_61_ = lean_ctor_get(v_rest_59_, 1);
v_isSharedCheck_70_ = !lean_is_exclusive(v_rest_59_);
if (v_isSharedCheck_70_ == 0)
{
v___x_63_ = v_rest_59_;
v_isShared_64_ = v_isSharedCheck_70_;
goto v_resetjp_62_;
}
else
{
lean_inc(v_time_61_);
lean_inc(v_ret_60_);
lean_dec(v_rest_59_);
v___x_63_ = lean_box(0);
v_isShared_64_ = v_isSharedCheck_70_;
goto v_resetjp_62_;
}
v_resetjp_62_:
{
lean_object* v___x_65_; lean_object* v___x_66_; lean_object* v___x_68_; 
v___x_65_ = lean_unsigned_to_nat(1u);
v___x_66_ = lean_nat_add(v_time_61_, v___x_65_);
lean_dec(v_time_61_);
if (v_isShared_64_ == 0)
{
lean_ctor_set(v___x_63_, 1, v___x_66_);
v___x_68_ = v___x_63_;
goto v_reusejp_67_;
}
else
{
lean_object* v_reuseFailAlloc_69_; 
v_reuseFailAlloc_69_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_69_, 0, v_ret_60_);
lean_ctor_set(v_reuseFailAlloc_69_, 1, v___x_66_);
v___x_68_ = v_reuseFailAlloc_69_;
goto v_reusejp_67_;
}
v_reusejp_67_:
{
return v___x_68_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_CostedPlan_Schema_eval___at___00LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0_spec__0(lean_object* v_p_71_, lean_object* v_xs_72_){
_start:
{
lean_object* v___x_73_; lean_object* v___x_74_; 
v___x_73_ = lp_leansort_LeanSort_CostedPlan_Schema_program___redArg(v_p_71_, v_xs_72_);
v___x_74_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_eval___at___00LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0_spec__0_spec__1___redArg(v___x_73_);
return v___x_74_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0(lean_object* v_p_75_, lean_object* v_xs_76_){
_start:
{
lean_object* v___x_77_; lean_object* v_ret_78_; 
v___x_77_ = l_LeanSort_CostedPlan_Schema_eval___at___00LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0_spec__0(v_p_75_, v_xs_76_);
v_ret_78_ = lean_ctor_get(v___x_77_, 0);
lean_inc(v_ret_78_);
lean_dec_ref(v___x_77_);
return v_ret_78_;
}
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_timedRun(lean_object* v_p_82_, lean_object* v_source_83_, lean_object* v_sink_84_, lean_object* v_expected_85_){
_start:
{
lean_object* v___x_87_; lean_object* v___x_88_; lean_object* v___x_89_; lean_object* v___x_90_; lean_object* v___x_91_; lean_object* v___x_92_; uint8_t v___x_93_; 
v___x_87_ = lean_io_mono_nanos_now();
v___x_88_ = lean_st_ref_get(v_source_83_);
v___x_89_ = l_LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0(v_p_82_, v___x_88_);
v___x_90_ = l_CostPlanExperiment_checksum(v___x_89_);
v___x_91_ = lean_st_ref_set(v_sink_84_, v___x_90_);
v___x_92_ = lean_io_mono_nanos_now();
v___x_93_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v___x_89_, v_expected_85_);
lean_dec(v___x_89_);
if (v___x_93_ == 0)
{
lean_object* v___x_94_; lean_object* v___x_95_; 
lean_dec(v___x_92_);
lean_dec(v___x_87_);
v___x_94_ = ((lean_object*)(l_CostPlanExperiment_timedRun___closed__1));
v___x_95_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_95_, 0, v___x_94_);
return v___x_95_;
}
else
{
lean_object* v___x_96_; lean_object* v___x_97_; 
v___x_96_ = lean_nat_sub(v___x_92_, v___x_87_);
lean_dec(v___x_87_);
lean_dec(v___x_92_);
v___x_97_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_97_, 0, v___x_96_);
return v___x_97_;
}
}
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_timedRun___boxed(lean_object* v_p_98_, lean_object* v_source_99_, lean_object* v_sink_100_, lean_object* v_expected_101_, lean_object* v_a_102_){
_start:
{
lean_object* v_res_103_; 
v_res_103_ = l_CostPlanExperiment_timedRun(v_p_98_, v_source_99_, v_sink_100_, v_expected_101_);
lean_dec(v_expected_101_);
lean_dec(v_sink_100_);
lean_dec(v_source_99_);
return v_res_103_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_eval___at___00LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0_spec__0_spec__1(lean_object* v_00_u03b2_104_, lean_object* v_x_105_){
_start:
{
lean_object* v___x_106_; 
v___x_106_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_eval___at___00LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0_spec__0_spec__1___redArg(v_x_105_);
return v___x_106_;
}
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_timedChecks(lean_object* v_p_107_, lean_object* v_source_108_, lean_object* v_sink_109_){
_start:
{
lean_object* v___x_111_; lean_object* v___x_112_; lean_object* v___x_113_; lean_object* v___x_114_; lean_object* v_time_115_; lean_object* v___x_116_; lean_object* v___x_117_; lean_object* v___x_118_; lean_object* v___x_119_; 
v___x_111_ = lean_io_mono_nanos_now();
v___x_112_ = lean_st_ref_get(v_source_108_);
v___x_113_ = lp_leansort_LeanSort_CostedPlan_Schema_checkProgram___redArg(v_p_107_, v___x_112_);
v___x_114_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_eval___at___00LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0_spec__0_spec__1___redArg(v___x_113_);
v_time_115_ = lean_ctor_get(v___x_114_, 1);
lean_inc(v_time_115_);
lean_dec_ref(v___x_114_);
v___x_116_ = lean_st_ref_set(v_sink_109_, v_time_115_);
v___x_117_ = lean_io_mono_nanos_now();
v___x_118_ = lean_nat_sub(v___x_117_, v___x_111_);
lean_dec(v___x_111_);
lean_dec(v___x_117_);
v___x_119_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_119_, 0, v___x_118_);
return v___x_119_;
}
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_timedChecks___boxed(lean_object* v_p_120_, lean_object* v_source_121_, lean_object* v_sink_122_, lean_object* v_a_123_){
_start:
{
lean_object* v_res_124_; 
v_res_124_ = l_CostPlanExperiment_timedChecks(v_p_120_, v_source_121_, v_sink_122_);
lean_dec(v_sink_122_);
lean_dec(v_source_121_);
return v_res_124_;
}
}
LEAN_EXPORT uint8_t l_LeanSort_CostedPlan_Schema_readyCheck___at___00CostPlanExperiment_profile_spec__0(lean_object* v_x_127_, lean_object* v_x_128_){
_start:
{
switch(lean_obj_tag(v_x_127_))
{
case 0:
{
uint8_t v___x_129_; 
lean_dec(v_x_128_);
v___x_129_ = 1;
return v___x_129_;
}
case 1:
{
lean_object* v_cut_130_; lean_object* v_left_131_; lean_object* v_right_132_; lean_object* v___x_133_; lean_object* v___x_134_; lean_object* v___x_135_; lean_object* v___x_136_; uint8_t v___x_137_; 
v_cut_130_ = lean_ctor_get(v_x_127_, 0);
v_left_131_ = lean_ctor_get(v_x_127_, 1);
v_right_132_ = lean_ctor_get(v_x_127_, 2);
v___x_133_ = l_List_lengthTR___redArg(v_x_128_);
v___x_134_ = lp_leansort_LeanSort_CostedPlan_Cut_position(v_cut_130_, v___x_133_);
lean_dec(v___x_133_);
v___x_135_ = ((lean_object*)(l_LeanSort_CostedPlan_Schema_readyCheck___at___00CostPlanExperiment_profile_spec__0___closed__0));
lean_inc(v___x_134_);
lean_inc(v_x_128_);
v___x_136_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_x_128_, v_x_128_, v___x_134_, v___x_135_);
v___x_137_ = l_LeanSort_CostedPlan_Schema_readyCheck___at___00CostPlanExperiment_profile_spec__0(v_left_131_, v___x_136_);
if (v___x_137_ == 0)
{
lean_dec(v___x_134_);
lean_dec(v_x_128_);
return v___x_137_;
}
else
{
lean_object* v___x_138_; 
v___x_138_ = l_List_drop___redArg(v___x_134_, v_x_128_);
lean_dec(v_x_128_);
v_x_127_ = v_right_132_;
v_x_128_ = v___x_138_;
goto _start;
}
}
default: 
{
lean_object* v___x_140_; lean_object* v___x_141_; lean_object* v_ret_142_; uint8_t v___x_143_; 
v___x_140_ = lp_leansort_LeanSort_ComparisonSort_checkSorted___redArg(v_x_128_);
v___x_141_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_eval___at___00LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0_spec__0_spec__1___redArg(v___x_140_);
v_ret_142_ = lean_ctor_get(v___x_141_, 0);
lean_inc(v_ret_142_);
lean_dec_ref(v___x_141_);
v___x_143_ = lean_unbox(v_ret_142_);
lean_dec(v_ret_142_);
return v___x_143_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_CostedPlan_Schema_readyCheck___at___00CostPlanExperiment_profile_spec__0___boxed(lean_object* v_x_144_, lean_object* v_x_145_){
_start:
{
uint8_t v_res_146_; lean_object* v_r_147_; 
v_res_146_ = l_LeanSort_CostedPlan_Schema_readyCheck___at___00CostPlanExperiment_profile_spec__0(v_x_144_, v_x_145_);
lean_dec_ref(v_x_144_);
v_r_147_ = lean_box(v_res_146_);
return v_r_147_;
}
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_profile(lean_object* v_name_167_, lean_object* v_p_168_, lean_object* v_source_169_, lean_object* v_expected_170_){
_start:
{
lean_object* v___x_172_; lean_object* v___x_173_; lean_object* v___x_174_; lean_object* v___x_175_; lean_object* v___x_176_; lean_object* v_ret_177_; lean_object* v_time_178_; lean_object* v___x_180_; uint8_t v_isShared_181_; uint8_t v_isSharedCheck_269_; 
v___x_172_ = lean_unsigned_to_nat(0u);
v___x_173_ = lean_st_mk_ref(v___x_172_);
v___x_174_ = lean_io_mono_nanos_now();
v___x_175_ = lean_st_ref_get(v_source_169_);
lean_inc(v___x_175_);
lean_inc_ref(v_p_168_);
v___x_176_ = l_LeanSort_CostedPlan_Schema_eval___at___00LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0_spec__0(v_p_168_, v___x_175_);
v_ret_177_ = lean_ctor_get(v___x_176_, 0);
v_time_178_ = lean_ctor_get(v___x_176_, 1);
v_isSharedCheck_269_ = !lean_is_exclusive(v___x_176_);
if (v_isSharedCheck_269_ == 0)
{
v___x_180_ = v___x_176_;
v_isShared_181_ = v_isSharedCheck_269_;
goto v_resetjp_179_;
}
else
{
lean_inc(v_time_178_);
lean_inc(v_ret_177_);
lean_dec(v___x_176_);
v___x_180_ = lean_box(0);
v_isShared_181_ = v_isSharedCheck_269_;
goto v_resetjp_179_;
}
v_resetjp_179_:
{
uint8_t v___x_182_; 
v___x_182_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v_ret_177_, v_expected_170_);
lean_dec(v_ret_177_);
if (v___x_182_ == 0)
{
lean_object* v___x_183_; lean_object* v___x_184_; 
lean_del_object(v___x_180_);
lean_dec(v_time_178_);
lean_dec(v___x_175_);
lean_dec(v___x_174_);
lean_dec(v___x_173_);
lean_dec_ref(v_p_168_);
lean_dec_ref(v_name_167_);
v___x_183_ = ((lean_object*)(l_CostPlanExperiment_profile___closed__1));
v___x_184_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_184_, 0, v___x_183_);
return v___x_184_;
}
else
{
lean_object* v___x_185_; lean_object* v___x_186_; lean_object* v_time_187_; lean_object* v___x_189_; uint8_t v_isShared_190_; uint8_t v_isSharedCheck_267_; 
lean_inc(v___x_175_);
lean_inc_ref(v_p_168_);
v___x_185_ = lp_leansort_LeanSort_CostedPlan_Schema_checkProgram___redArg(v_p_168_, v___x_175_);
v___x_186_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_eval___at___00LeanSort_CostedPlan_Schema_run___at___00CostPlanExperiment_timedRun_spec__0_spec__0_spec__1___redArg(v___x_185_);
v_time_187_ = lean_ctor_get(v___x_186_, 1);
v_isSharedCheck_267_ = !lean_is_exclusive(v___x_186_);
if (v_isSharedCheck_267_ == 0)
{
lean_object* v_unused_268_; 
v_unused_268_ = lean_ctor_get(v___x_186_, 0);
lean_dec(v_unused_268_);
v___x_189_ = v___x_186_;
v_isShared_190_ = v_isSharedCheck_267_;
goto v_resetjp_188_;
}
else
{
lean_inc(v_time_187_);
lean_dec(v___x_186_);
v___x_189_ = lean_box(0);
v_isShared_190_ = v_isSharedCheck_267_;
goto v_resetjp_188_;
}
v_resetjp_188_:
{
uint8_t v___x_191_; lean_object* v___x_192_; lean_object* v___x_193_; lean_object* v___x_194_; uint8_t v___y_261_; uint8_t v___x_265_; 
lean_inc(v___x_175_);
v___x_191_ = l_LeanSort_CostedPlan_Schema_readyCheck___at___00CostPlanExperiment_profile_spec__0(v_p_168_, v___x_175_);
v___x_192_ = l_List_lengthTR___redArg(v___x_175_);
lean_dec(v___x_175_);
v___x_193_ = lp_leansort_LeanSort_CostedPlan_Schema_upper(v_p_168_, v___x_192_);
v___x_194_ = lp_leansort_LeanSort_CostedPlan_Schema_readyUpper(v_p_168_, v___x_192_);
lean_dec(v___x_192_);
lean_dec_ref(v_p_168_);
v___x_265_ = lean_nat_dec_le(v_time_187_, v_time_178_);
if (v___x_265_ == 0)
{
v___y_261_ = v___x_265_;
goto v___jp_260_;
}
else
{
uint8_t v___x_266_; 
v___x_266_ = lean_nat_dec_le(v_time_178_, v___x_193_);
v___y_261_ = v___x_266_;
goto v___jp_260_;
}
v___jp_195_:
{
lean_object* v___x_196_; lean_object* v___x_197_; lean_object* v___x_199_; 
v___x_196_ = ((lean_object*)(l_CostPlanExperiment_profile___closed__2));
v___x_197_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_197_, 0, v_name_167_);
if (v_isShared_190_ == 0)
{
lean_ctor_set(v___x_189_, 1, v___x_197_);
lean_ctor_set(v___x_189_, 0, v___x_196_);
v___x_199_ = v___x_189_;
goto v_reusejp_198_;
}
else
{
lean_object* v_reuseFailAlloc_256_; 
v_reuseFailAlloc_256_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_256_, 0, v___x_196_);
lean_ctor_set(v_reuseFailAlloc_256_, 1, v___x_197_);
v___x_199_ = v_reuseFailAlloc_256_;
goto v_reusejp_198_;
}
v_reusejp_198_:
{
lean_object* v___x_200_; lean_object* v___x_201_; lean_object* v___x_202_; lean_object* v___x_204_; 
v___x_200_ = ((lean_object*)(l_CostPlanExperiment_profile___closed__3));
lean_inc(v_time_178_);
v___x_201_ = l_Lean_JsonNumber_fromNat(v_time_178_);
v___x_202_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_202_, 0, v___x_201_);
if (v_isShared_181_ == 0)
{
lean_ctor_set(v___x_180_, 1, v___x_202_);
lean_ctor_set(v___x_180_, 0, v___x_200_);
v___x_204_ = v___x_180_;
goto v_reusejp_203_;
}
else
{
lean_object* v_reuseFailAlloc_255_; 
v_reuseFailAlloc_255_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_255_, 0, v___x_200_);
lean_ctor_set(v_reuseFailAlloc_255_, 1, v___x_202_);
v___x_204_ = v_reuseFailAlloc_255_;
goto v_reusejp_203_;
}
v_reusejp_203_:
{
lean_object* v___x_205_; lean_object* v___x_206_; lean_object* v___x_207_; lean_object* v___x_208_; lean_object* v___x_209_; lean_object* v___x_210_; lean_object* v___x_211_; lean_object* v___x_212_; lean_object* v___x_213_; lean_object* v___x_214_; lean_object* v___x_215_; lean_object* v___x_216_; lean_object* v___x_217_; lean_object* v___x_218_; lean_object* v___x_219_; lean_object* v___x_220_; lean_object* v___x_221_; lean_object* v___x_222_; lean_object* v___x_223_; lean_object* v___x_224_; lean_object* v___x_225_; lean_object* v___x_226_; lean_object* v___x_227_; lean_object* v___x_228_; lean_object* v___x_229_; lean_object* v___x_230_; lean_object* v___x_231_; lean_object* v___x_232_; lean_object* v___x_233_; lean_object* v___x_234_; lean_object* v___x_235_; lean_object* v___x_236_; lean_object* v___x_237_; lean_object* v___x_238_; lean_object* v___x_239_; lean_object* v___x_240_; lean_object* v___x_241_; lean_object* v___x_242_; lean_object* v___x_243_; lean_object* v___x_244_; lean_object* v___x_245_; lean_object* v___x_246_; lean_object* v___x_247_; lean_object* v___x_248_; lean_object* v___x_249_; lean_object* v___x_250_; lean_object* v___x_251_; lean_object* v___x_252_; lean_object* v___x_253_; lean_object* v___x_254_; 
v___x_205_ = ((lean_object*)(l_CostPlanExperiment_profile___closed__4));
lean_inc(v_time_187_);
v___x_206_ = l_Lean_JsonNumber_fromNat(v_time_187_);
v___x_207_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_207_, 0, v___x_206_);
v___x_208_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_208_, 0, v___x_205_);
lean_ctor_set(v___x_208_, 1, v___x_207_);
v___x_209_ = ((lean_object*)(l_CostPlanExperiment_profile___closed__5));
v___x_210_ = lean_nat_sub(v_time_178_, v_time_187_);
lean_dec(v_time_187_);
lean_dec(v_time_178_);
v___x_211_ = l_Lean_JsonNumber_fromNat(v___x_210_);
v___x_212_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_212_, 0, v___x_211_);
v___x_213_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_213_, 0, v___x_209_);
lean_ctor_set(v___x_213_, 1, v___x_212_);
v___x_214_ = ((lean_object*)(l_CostPlanExperiment_profile___closed__6));
v___x_215_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_215_, 0, v___x_191_);
v___x_216_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_216_, 0, v___x_214_);
lean_ctor_set(v___x_216_, 1, v___x_215_);
v___x_217_ = ((lean_object*)(l_CostPlanExperiment_profile___closed__7));
v___x_218_ = l_Lean_JsonNumber_fromNat(v___x_193_);
v___x_219_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_219_, 0, v___x_218_);
v___x_220_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_220_, 0, v___x_217_);
lean_ctor_set(v___x_220_, 1, v___x_219_);
v___x_221_ = ((lean_object*)(l_CostPlanExperiment_profile___closed__8));
v___x_222_ = l_Lean_JsonNumber_fromNat(v___x_194_);
v___x_223_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_223_, 0, v___x_222_);
v___x_224_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_224_, 0, v___x_221_);
lean_ctor_set(v___x_224_, 1, v___x_223_);
v___x_225_ = lean_box(0);
v___x_226_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_226_, 0, v___x_224_);
lean_ctor_set(v___x_226_, 1, v___x_225_);
v___x_227_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_227_, 0, v___x_220_);
lean_ctor_set(v___x_227_, 1, v___x_226_);
v___x_228_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_228_, 0, v___x_216_);
lean_ctor_set(v___x_228_, 1, v___x_227_);
v___x_229_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_229_, 0, v___x_213_);
lean_ctor_set(v___x_229_, 1, v___x_228_);
v___x_230_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_230_, 0, v___x_208_);
lean_ctor_set(v___x_230_, 1, v___x_229_);
v___x_231_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_231_, 0, v___x_204_);
lean_ctor_set(v___x_231_, 1, v___x_230_);
v___x_232_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_232_, 0, v___x_199_);
lean_ctor_set(v___x_232_, 1, v___x_231_);
v___x_233_ = l_Lean_Json_mkObj(v___x_232_);
lean_dec_ref_known(v___x_232_, 2);
lean_inc(v___x_233_);
v___x_234_ = l_Lean_Json_compress(v___x_233_);
v___x_235_ = lean_string_utf8_byte_size(v___x_234_);
lean_dec_ref(v___x_234_);
v___x_236_ = lean_st_ref_set(v___x_173_, v___x_235_);
v___x_237_ = lean_st_ref_get(v___x_173_);
lean_dec(v___x_173_);
v___x_238_ = lean_io_mono_nanos_now();
v___x_239_ = lean_nat_sub(v___x_238_, v___x_174_);
lean_dec(v___x_174_);
lean_dec(v___x_238_);
v___x_240_ = ((lean_object*)(l_CostPlanExperiment_profile___closed__9));
v___x_241_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_241_, 0, v___x_240_);
lean_ctor_set(v___x_241_, 1, v___x_233_);
v___x_242_ = ((lean_object*)(l_CostPlanExperiment_profile___closed__10));
v___x_243_ = l_Lean_JsonNumber_fromNat(v___x_239_);
v___x_244_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_244_, 0, v___x_243_);
v___x_245_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_245_, 0, v___x_242_);
lean_ctor_set(v___x_245_, 1, v___x_244_);
v___x_246_ = ((lean_object*)(l_CostPlanExperiment_profile___closed__11));
v___x_247_ = l_Lean_JsonNumber_fromNat(v___x_237_);
v___x_248_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_248_, 0, v___x_247_);
v___x_249_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_249_, 0, v___x_246_);
lean_ctor_set(v___x_249_, 1, v___x_248_);
v___x_250_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_250_, 0, v___x_249_);
lean_ctor_set(v___x_250_, 1, v___x_225_);
v___x_251_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_251_, 0, v___x_245_);
lean_ctor_set(v___x_251_, 1, v___x_250_);
v___x_252_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_252_, 0, v___x_241_);
lean_ctor_set(v___x_252_, 1, v___x_251_);
v___x_253_ = l_Lean_Json_mkObj(v___x_252_);
lean_dec_ref_known(v___x_252_, 2);
v___x_254_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_254_, 0, v___x_253_);
return v___x_254_;
}
}
}
v___jp_257_:
{
if (v___x_191_ == 0)
{
goto v___jp_195_;
}
else
{
lean_object* v___x_258_; lean_object* v___x_259_; 
lean_dec(v___x_194_);
lean_dec(v___x_193_);
lean_del_object(v___x_189_);
lean_dec(v_time_187_);
lean_del_object(v___x_180_);
lean_dec(v_time_178_);
lean_dec(v___x_174_);
lean_dec(v___x_173_);
lean_dec_ref(v_name_167_);
v___x_258_ = ((lean_object*)(l_CostPlanExperiment_profile___closed__13));
v___x_259_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_259_, 0, v___x_258_);
return v___x_259_;
}
}
v___jp_260_:
{
if (v___y_261_ == 0)
{
lean_object* v___x_262_; lean_object* v___x_263_; 
lean_dec(v___x_194_);
lean_dec(v___x_193_);
lean_del_object(v___x_189_);
lean_dec(v_time_187_);
lean_del_object(v___x_180_);
lean_dec(v_time_178_);
lean_dec(v___x_174_);
lean_dec(v___x_173_);
lean_dec_ref(v_name_167_);
v___x_262_ = ((lean_object*)(l_CostPlanExperiment_profile___closed__15));
v___x_263_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_263_, 0, v___x_262_);
return v___x_263_;
}
else
{
if (v___x_191_ == 0)
{
goto v___jp_257_;
}
else
{
uint8_t v___x_264_; 
v___x_264_ = lean_nat_dec_le(v_time_178_, v___x_194_);
if (v___x_264_ == 0)
{
goto v___jp_257_;
}
else
{
goto v___jp_195_;
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_profile___boxed(lean_object* v_name_270_, lean_object* v_p_271_, lean_object* v_source_272_, lean_object* v_expected_273_, lean_object* v_a_274_){
_start:
{
lean_object* v_res_275_; 
v_res_275_ = l_CostPlanExperiment_profile(v_name_270_, v_p_271_, v_source_272_, v_expected_273_);
lean_dec(v_expected_273_);
lean_dec(v_source_272_);
return v_res_275_;
}
}
LEAN_EXPORT lean_object* l_List_find_x3f___at___00CostPlanExperiment_handle_spec__2(lean_object* v_a_276_, lean_object* v_x_277_){
_start:
{
if (lean_obj_tag(v_x_277_) == 0)
{
lean_object* v___x_278_; 
v___x_278_ = lean_box(0);
return v___x_278_;
}
else
{
lean_object* v_head_279_; lean_object* v_tail_280_; lean_object* v_fst_281_; uint8_t v___x_282_; 
v_head_279_ = lean_ctor_get(v_x_277_, 0);
v_tail_280_ = lean_ctor_get(v_x_277_, 1);
v_fst_281_ = lean_ctor_get(v_head_279_, 0);
v___x_282_ = lean_string_dec_eq(v_fst_281_, v_a_276_);
if (v___x_282_ == 0)
{
v_x_277_ = v_tail_280_;
goto _start;
}
else
{
lean_object* v___x_284_; 
lean_inc(v_head_279_);
v___x_284_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_284_, 0, v_head_279_);
return v___x_284_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_find_x3f___at___00CostPlanExperiment_handle_spec__2___boxed(lean_object* v_a_285_, lean_object* v_x_286_){
_start:
{
lean_object* v_res_287_; 
v_res_287_ = l_List_find_x3f___at___00CostPlanExperiment_handle_spec__2(v_a_285_, v_x_286_);
lean_dec(v_x_286_);
lean_dec_ref(v_a_285_);
return v_res_287_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___redArg(lean_object* v_as_x27_291_, lean_object* v_b_292_){
_start:
{
if (lean_obj_tag(v_as_x27_291_) == 0)
{
lean_object* v___x_294_; 
v___x_294_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_294_, 0, v_b_292_);
return v___x_294_;
}
else
{
lean_object* v_head_295_; lean_object* v_tail_296_; lean_object* v___x_297_; lean_object* v___x_298_; 
v_head_295_ = lean_ctor_get(v_as_x27_291_, 0);
v_tail_296_ = lean_ctor_get(v_as_x27_291_, 1);
v___x_297_ = l_CostPlanGenerated_entries;
v___x_298_ = l_List_find_x3f___at___00CostPlanExperiment_handle_spec__2(v_head_295_, v___x_297_);
if (lean_obj_tag(v___x_298_) == 0)
{
lean_object* v___x_299_; lean_object* v___x_300_; 
lean_dec(v_b_292_);
v___x_299_ = ((lean_object*)(l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___redArg___closed__1));
v___x_300_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_300_, 0, v___x_299_);
return v___x_300_;
}
else
{
lean_object* v_val_301_; lean_object* v___x_302_; lean_object* v___x_303_; lean_object* v___x_304_; 
v_val_301_ = lean_ctor_get(v___x_298_, 0);
lean_inc(v_val_301_);
lean_dec_ref_known(v___x_298_, 1);
v___x_302_ = lean_box(0);
v___x_303_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_303_, 0, v_val_301_);
lean_ctor_set(v___x_303_, 1, v___x_302_);
v___x_304_ = l_List_appendTR___redArg(v_b_292_, v___x_303_);
v_as_x27_291_ = v_tail_296_;
v_b_292_ = v___x_304_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___redArg___boxed(lean_object* v_as_x27_306_, lean_object* v_b_307_, lean_object* v___y_308_){
_start:
{
lean_object* v_res_309_; 
v_res_309_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___redArg(v_as_x27_306_, v_b_307_);
lean_dec(v_as_x27_306_);
return v_res_309_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__12___redArg(lean_object* v_val_310_, lean_object* v_a_311_, lean_object* v_as_x27_312_, lean_object* v_b_313_){
_start:
{
if (lean_obj_tag(v_as_x27_312_) == 0)
{
lean_object* v___x_315_; 
v___x_315_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_315_, 0, v_b_313_);
return v___x_315_;
}
else
{
lean_object* v_head_316_; lean_object* v_tail_317_; lean_object* v_fst_318_; lean_object* v_snd_319_; lean_object* v___x_320_; 
v_head_316_ = lean_ctor_get(v_as_x27_312_, 0);
v_tail_317_ = lean_ctor_get(v_as_x27_312_, 1);
v_fst_318_ = lean_ctor_get(v_head_316_, 0);
v_snd_319_ = lean_ctor_get(v_head_316_, 1);
lean_inc(v_snd_319_);
lean_inc(v_fst_318_);
v___x_320_ = l_CostPlanExperiment_profile(v_fst_318_, v_snd_319_, v_val_310_, v_a_311_);
if (lean_obj_tag(v___x_320_) == 0)
{
lean_object* v_a_321_; lean_object* v___x_322_; lean_object* v___x_323_; lean_object* v___x_324_; 
v_a_321_ = lean_ctor_get(v___x_320_, 0);
lean_inc(v_a_321_);
lean_dec_ref_known(v___x_320_, 1);
v___x_322_ = lean_box(0);
v___x_323_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_323_, 0, v_a_321_);
lean_ctor_set(v___x_323_, 1, v___x_322_);
v___x_324_ = l_List_appendTR___redArg(v_b_313_, v___x_323_);
v_as_x27_312_ = v_tail_317_;
v_b_313_ = v___x_324_;
goto _start;
}
else
{
lean_object* v_a_326_; lean_object* v___x_328_; uint8_t v_isShared_329_; uint8_t v_isSharedCheck_333_; 
lean_dec(v_b_313_);
v_a_326_ = lean_ctor_get(v___x_320_, 0);
v_isSharedCheck_333_ = !lean_is_exclusive(v___x_320_);
if (v_isSharedCheck_333_ == 0)
{
v___x_328_ = v___x_320_;
v_isShared_329_ = v_isSharedCheck_333_;
goto v_resetjp_327_;
}
else
{
lean_inc(v_a_326_);
lean_dec(v___x_320_);
v___x_328_ = lean_box(0);
v_isShared_329_ = v_isSharedCheck_333_;
goto v_resetjp_327_;
}
v_resetjp_327_:
{
lean_object* v___x_331_; 
if (v_isShared_329_ == 0)
{
v___x_331_ = v___x_328_;
goto v_reusejp_330_;
}
else
{
lean_object* v_reuseFailAlloc_332_; 
v_reuseFailAlloc_332_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_332_, 0, v_a_326_);
v___x_331_ = v_reuseFailAlloc_332_;
goto v_reusejp_330_;
}
v_reusejp_330_:
{
return v___x_331_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__12___redArg___boxed(lean_object* v_val_334_, lean_object* v_a_335_, lean_object* v_as_x27_336_, lean_object* v_b_337_, lean_object* v___y_338_){
_start:
{
lean_object* v_res_339_; 
v_res_339_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__12___redArg(v_val_334_, v_a_335_, v_as_x27_336_, v_b_337_);
lean_dec(v_as_x27_336_);
lean_dec(v_a_335_);
lean_dec(v_val_334_);
return v_res_339_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__4(lean_object* v_fst_340_, lean_object* v_a_341_, lean_object* v_a_342_, lean_object* v_a_343_){
_start:
{
if (lean_obj_tag(v_a_342_) == 0)
{
lean_object* v___x_344_; 
lean_dec(v_a_341_);
v___x_344_ = l_List_reverse___redArg(v_a_343_);
return v___x_344_;
}
else
{
lean_object* v_head_345_; lean_object* v_snd_346_; lean_object* v_tail_347_; lean_object* v___x_349_; uint8_t v_isShared_350_; uint8_t v_isSharedCheck_377_; 
v_head_345_ = lean_ctor_get(v_a_342_, 0);
lean_inc(v_head_345_);
v_snd_346_ = lean_ctor_get(v_head_345_, 1);
lean_inc(v_snd_346_);
v_tail_347_ = lean_ctor_get(v_a_342_, 1);
v_isSharedCheck_377_ = !lean_is_exclusive(v_a_342_);
if (v_isSharedCheck_377_ == 0)
{
lean_object* v_unused_378_; 
v_unused_378_ = lean_ctor_get(v_a_342_, 0);
lean_dec(v_unused_378_);
v___x_349_ = v_a_342_;
v_isShared_350_ = v_isSharedCheck_377_;
goto v_resetjp_348_;
}
else
{
lean_inc(v_tail_347_);
lean_dec(v_a_342_);
v___x_349_ = lean_box(0);
v_isShared_350_ = v_isSharedCheck_377_;
goto v_resetjp_348_;
}
v_resetjp_348_:
{
lean_object* v_fst_351_; lean_object* v___x_353_; uint8_t v_isShared_354_; uint8_t v_isSharedCheck_375_; 
v_fst_351_ = lean_ctor_get(v_head_345_, 0);
v_isSharedCheck_375_ = !lean_is_exclusive(v_head_345_);
if (v_isSharedCheck_375_ == 0)
{
lean_object* v_unused_376_; 
v_unused_376_ = lean_ctor_get(v_head_345_, 1);
lean_dec(v_unused_376_);
v___x_353_ = v_head_345_;
v_isShared_354_ = v_isSharedCheck_375_;
goto v_resetjp_352_;
}
else
{
lean_inc(v_fst_351_);
lean_dec(v_head_345_);
v___x_353_ = lean_box(0);
v_isShared_354_ = v_isSharedCheck_375_;
goto v_resetjp_352_;
}
v_resetjp_352_:
{
lean_object* v_fst_355_; lean_object* v_snd_356_; lean_object* v___x_358_; uint8_t v_isShared_359_; uint8_t v_isSharedCheck_374_; 
v_fst_355_ = lean_ctor_get(v_snd_346_, 0);
v_snd_356_ = lean_ctor_get(v_snd_346_, 1);
v_isSharedCheck_374_ = !lean_is_exclusive(v_snd_346_);
if (v_isSharedCheck_374_ == 0)
{
v___x_358_ = v_snd_346_;
v_isShared_359_ = v_isSharedCheck_374_;
goto v_resetjp_357_;
}
else
{
lean_inc(v_snd_356_);
lean_inc(v_fst_355_);
lean_dec(v_snd_346_);
v___x_358_ = lean_box(0);
v_isShared_359_ = v_isSharedCheck_374_;
goto v_resetjp_357_;
}
v_resetjp_357_:
{
lean_object* v___y_361_; uint8_t v___x_372_; 
v___x_372_ = lean_string_dec_eq(v_fst_351_, v_fst_340_);
if (v___x_372_ == 0)
{
v___y_361_ = v_snd_356_;
goto v___jp_360_;
}
else
{
lean_object* v___x_373_; 
lean_inc(v_a_341_);
v___x_373_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_373_, 0, v_a_341_);
lean_ctor_set(v___x_373_, 1, v_snd_356_);
v___y_361_ = v___x_373_;
goto v___jp_360_;
}
v___jp_360_:
{
lean_object* v___x_363_; 
if (v_isShared_359_ == 0)
{
lean_ctor_set(v___x_358_, 1, v___y_361_);
v___x_363_ = v___x_358_;
goto v_reusejp_362_;
}
else
{
lean_object* v_reuseFailAlloc_371_; 
v_reuseFailAlloc_371_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_371_, 0, v_fst_355_);
lean_ctor_set(v_reuseFailAlloc_371_, 1, v___y_361_);
v___x_363_ = v_reuseFailAlloc_371_;
goto v_reusejp_362_;
}
v_reusejp_362_:
{
lean_object* v___x_365_; 
if (v_isShared_354_ == 0)
{
lean_ctor_set(v___x_353_, 1, v___x_363_);
v___x_365_ = v___x_353_;
goto v_reusejp_364_;
}
else
{
lean_object* v_reuseFailAlloc_370_; 
v_reuseFailAlloc_370_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_370_, 0, v_fst_351_);
lean_ctor_set(v_reuseFailAlloc_370_, 1, v___x_363_);
v___x_365_ = v_reuseFailAlloc_370_;
goto v_reusejp_364_;
}
v_reusejp_364_:
{
lean_object* v___x_367_; 
if (v_isShared_350_ == 0)
{
lean_ctor_set(v___x_349_, 1, v_a_343_);
lean_ctor_set(v___x_349_, 0, v___x_365_);
v___x_367_ = v___x_349_;
goto v_reusejp_366_;
}
else
{
lean_object* v_reuseFailAlloc_369_; 
v_reuseFailAlloc_369_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_369_, 0, v___x_365_);
lean_ctor_set(v_reuseFailAlloc_369_, 1, v_a_343_);
v___x_367_ = v_reuseFailAlloc_369_;
goto v_reusejp_366_;
}
v_reusejp_366_:
{
v_a_342_ = v_tail_347_;
v_a_343_ = v___x_367_;
goto _start;
}
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__4___boxed(lean_object* v_fst_379_, lean_object* v_a_380_, lean_object* v_a_381_, lean_object* v_a_382_){
_start:
{
lean_object* v_res_383_; 
v_res_383_ = l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__4(v_fst_379_, v_a_380_, v_a_381_, v_a_382_);
lean_dec_ref(v_fst_379_);
return v_res_383_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__5___redArg(lean_object* v_val_384_, lean_object* v_val_385_, lean_object* v_as_x27_386_, lean_object* v_b_387_){
_start:
{
if (lean_obj_tag(v_as_x27_386_) == 0)
{
lean_object* v___x_389_; 
v___x_389_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_389_, 0, v_b_387_);
return v___x_389_;
}
else
{
lean_object* v_head_390_; lean_object* v_tail_391_; lean_object* v_fst_392_; lean_object* v_snd_393_; lean_object* v___x_394_; lean_object* v_a_395_; lean_object* v___x_396_; lean_object* v___x_397_; 
v_head_390_ = lean_ctor_get(v_as_x27_386_, 0);
v_tail_391_ = lean_ctor_get(v_as_x27_386_, 1);
v_fst_392_ = lean_ctor_get(v_head_390_, 0);
v_snd_393_ = lean_ctor_get(v_head_390_, 1);
lean_inc(v_snd_393_);
v___x_394_ = l_CostPlanExperiment_timedChecks(v_snd_393_, v_val_384_, v_val_385_);
v_a_395_ = lean_ctor_get(v___x_394_, 0);
lean_inc(v_a_395_);
lean_dec_ref(v___x_394_);
v___x_396_ = lean_box(0);
v___x_397_ = l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__4(v_fst_392_, v_a_395_, v_b_387_, v___x_396_);
v_as_x27_386_ = v_tail_391_;
v_b_387_ = v___x_397_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__5___redArg___boxed(lean_object* v_val_399_, lean_object* v_val_400_, lean_object* v_as_x27_401_, lean_object* v_b_402_, lean_object* v___y_403_){
_start:
{
lean_object* v_res_404_; 
v_res_404_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__5___redArg(v_val_399_, v_val_400_, v_as_x27_401_, v_b_402_);
lean_dec(v_as_x27_401_);
lean_dec(v_val_400_);
lean_dec(v_val_399_);
return v_res_404_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11___redArg(lean_object* v_a_407_, lean_object* v_a_408_, lean_object* v_val_409_, lean_object* v_val_410_, lean_object* v_as_x27_411_, lean_object* v_b_412_){
_start:
{
if (lean_obj_tag(v_as_x27_411_) == 0)
{
lean_object* v___x_414_; 
lean_dec(v_a_408_);
v___x_414_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_414_, 0, v_b_412_);
return v___x_414_;
}
else
{
lean_object* v_head_415_; lean_object* v_tail_416_; lean_object* v___x_417_; lean_object* v___x_418_; lean_object* v___x_419_; lean_object* v___x_420_; lean_object* v___x_421_; lean_object* v___x_422_; lean_object* v___x_423_; lean_object* v___x_424_; 
v_head_415_ = lean_ctor_get(v_as_x27_411_, 0);
v_tail_416_ = lean_ctor_get(v_as_x27_411_, 1);
v___x_417_ = lean_nat_add(v_a_407_, v_head_415_);
v___x_418_ = l_List_lengthTR___redArg(v_a_408_);
v___x_419_ = lean_nat_mod(v___x_417_, v___x_418_);
lean_dec(v___x_418_);
lean_dec(v___x_417_);
lean_inc(v___x_419_);
v___x_420_ = l_List_drop___redArg(v___x_419_, v_a_408_);
v___x_421_ = ((lean_object*)(l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11___redArg___closed__0));
lean_inc(v_a_408_);
v___x_422_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_a_408_, v_a_408_, v___x_419_, v___x_421_);
v___x_423_ = l_List_appendTR___redArg(v___x_420_, v___x_422_);
v___x_424_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__5___redArg(v_val_409_, v_val_410_, v___x_423_, v_b_412_);
lean_dec(v___x_423_);
if (lean_obj_tag(v___x_424_) == 0)
{
lean_object* v_a_425_; 
v_a_425_ = lean_ctor_get(v___x_424_, 0);
lean_inc(v_a_425_);
lean_dec_ref_known(v___x_424_, 1);
v_as_x27_411_ = v_tail_416_;
v_b_412_ = v_a_425_;
goto _start;
}
else
{
lean_dec(v_a_408_);
return v___x_424_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11___redArg___boxed(lean_object* v_a_427_, lean_object* v_a_428_, lean_object* v_val_429_, lean_object* v_val_430_, lean_object* v_as_x27_431_, lean_object* v_b_432_, lean_object* v___y_433_){
_start:
{
lean_object* v_res_434_; 
v_res_434_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11___redArg(v_a_427_, v_a_428_, v_val_429_, v_val_430_, v_as_x27_431_, v_b_432_);
lean_dec(v_as_x27_431_);
lean_dec(v_val_430_);
lean_dec(v_val_429_);
lean_dec(v_a_427_);
return v_res_434_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__6(lean_object* v_fst_435_, lean_object* v_a_436_, lean_object* v_a_437_, lean_object* v_a_438_){
_start:
{
if (lean_obj_tag(v_a_437_) == 0)
{
lean_object* v___x_439_; 
lean_dec(v_a_436_);
v___x_439_ = l_List_reverse___redArg(v_a_438_);
return v___x_439_;
}
else
{
lean_object* v_head_440_; lean_object* v_snd_441_; lean_object* v_tail_442_; lean_object* v___x_444_; uint8_t v_isShared_445_; uint8_t v_isSharedCheck_472_; 
v_head_440_ = lean_ctor_get(v_a_437_, 0);
lean_inc(v_head_440_);
v_snd_441_ = lean_ctor_get(v_head_440_, 1);
lean_inc(v_snd_441_);
v_tail_442_ = lean_ctor_get(v_a_437_, 1);
v_isSharedCheck_472_ = !lean_is_exclusive(v_a_437_);
if (v_isSharedCheck_472_ == 0)
{
lean_object* v_unused_473_; 
v_unused_473_ = lean_ctor_get(v_a_437_, 0);
lean_dec(v_unused_473_);
v___x_444_ = v_a_437_;
v_isShared_445_ = v_isSharedCheck_472_;
goto v_resetjp_443_;
}
else
{
lean_inc(v_tail_442_);
lean_dec(v_a_437_);
v___x_444_ = lean_box(0);
v_isShared_445_ = v_isSharedCheck_472_;
goto v_resetjp_443_;
}
v_resetjp_443_:
{
lean_object* v_fst_446_; lean_object* v___x_448_; uint8_t v_isShared_449_; uint8_t v_isSharedCheck_470_; 
v_fst_446_ = lean_ctor_get(v_head_440_, 0);
v_isSharedCheck_470_ = !lean_is_exclusive(v_head_440_);
if (v_isSharedCheck_470_ == 0)
{
lean_object* v_unused_471_; 
v_unused_471_ = lean_ctor_get(v_head_440_, 1);
lean_dec(v_unused_471_);
v___x_448_ = v_head_440_;
v_isShared_449_ = v_isSharedCheck_470_;
goto v_resetjp_447_;
}
else
{
lean_inc(v_fst_446_);
lean_dec(v_head_440_);
v___x_448_ = lean_box(0);
v_isShared_449_ = v_isSharedCheck_470_;
goto v_resetjp_447_;
}
v_resetjp_447_:
{
lean_object* v_fst_450_; lean_object* v_snd_451_; lean_object* v___x_453_; uint8_t v_isShared_454_; uint8_t v_isSharedCheck_469_; 
v_fst_450_ = lean_ctor_get(v_snd_441_, 0);
v_snd_451_ = lean_ctor_get(v_snd_441_, 1);
v_isSharedCheck_469_ = !lean_is_exclusive(v_snd_441_);
if (v_isSharedCheck_469_ == 0)
{
v___x_453_ = v_snd_441_;
v_isShared_454_ = v_isSharedCheck_469_;
goto v_resetjp_452_;
}
else
{
lean_inc(v_snd_451_);
lean_inc(v_fst_450_);
lean_dec(v_snd_441_);
v___x_453_ = lean_box(0);
v_isShared_454_ = v_isSharedCheck_469_;
goto v_resetjp_452_;
}
v_resetjp_452_:
{
lean_object* v___y_456_; uint8_t v___x_467_; 
v___x_467_ = lean_string_dec_eq(v_fst_446_, v_fst_435_);
if (v___x_467_ == 0)
{
v___y_456_ = v_fst_450_;
goto v___jp_455_;
}
else
{
lean_object* v___x_468_; 
lean_inc(v_a_436_);
v___x_468_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_468_, 0, v_a_436_);
lean_ctor_set(v___x_468_, 1, v_fst_450_);
v___y_456_ = v___x_468_;
goto v___jp_455_;
}
v___jp_455_:
{
lean_object* v___x_458_; 
if (v_isShared_454_ == 0)
{
lean_ctor_set(v___x_453_, 0, v___y_456_);
v___x_458_ = v___x_453_;
goto v_reusejp_457_;
}
else
{
lean_object* v_reuseFailAlloc_466_; 
v_reuseFailAlloc_466_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_466_, 0, v___y_456_);
lean_ctor_set(v_reuseFailAlloc_466_, 1, v_snd_451_);
v___x_458_ = v_reuseFailAlloc_466_;
goto v_reusejp_457_;
}
v_reusejp_457_:
{
lean_object* v___x_460_; 
if (v_isShared_449_ == 0)
{
lean_ctor_set(v___x_448_, 1, v___x_458_);
v___x_460_ = v___x_448_;
goto v_reusejp_459_;
}
else
{
lean_object* v_reuseFailAlloc_465_; 
v_reuseFailAlloc_465_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_465_, 0, v_fst_446_);
lean_ctor_set(v_reuseFailAlloc_465_, 1, v___x_458_);
v___x_460_ = v_reuseFailAlloc_465_;
goto v_reusejp_459_;
}
v_reusejp_459_:
{
lean_object* v___x_462_; 
if (v_isShared_445_ == 0)
{
lean_ctor_set(v___x_444_, 1, v_a_438_);
lean_ctor_set(v___x_444_, 0, v___x_460_);
v___x_462_ = v___x_444_;
goto v_reusejp_461_;
}
else
{
lean_object* v_reuseFailAlloc_464_; 
v_reuseFailAlloc_464_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_464_, 0, v___x_460_);
lean_ctor_set(v_reuseFailAlloc_464_, 1, v_a_438_);
v___x_462_ = v_reuseFailAlloc_464_;
goto v_reusejp_461_;
}
v_reusejp_461_:
{
v_a_437_ = v_tail_442_;
v_a_438_ = v___x_462_;
goto _start;
}
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__6___boxed(lean_object* v_fst_474_, lean_object* v_a_475_, lean_object* v_a_476_, lean_object* v_a_477_){
_start:
{
lean_object* v_res_478_; 
v_res_478_ = l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__6(v_fst_474_, v_a_475_, v_a_476_, v_a_477_);
lean_dec_ref(v_fst_474_);
return v_res_478_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__7___redArg(lean_object* v_val_479_, lean_object* v_val_480_, lean_object* v_a_481_, lean_object* v_as_x27_482_, lean_object* v_b_483_){
_start:
{
if (lean_obj_tag(v_as_x27_482_) == 0)
{
lean_object* v___x_485_; 
v___x_485_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_485_, 0, v_b_483_);
return v___x_485_;
}
else
{
lean_object* v_head_486_; lean_object* v_tail_487_; lean_object* v_fst_488_; lean_object* v_snd_489_; lean_object* v___x_490_; 
v_head_486_ = lean_ctor_get(v_as_x27_482_, 0);
v_tail_487_ = lean_ctor_get(v_as_x27_482_, 1);
v_fst_488_ = lean_ctor_get(v_head_486_, 0);
v_snd_489_ = lean_ctor_get(v_head_486_, 1);
lean_inc(v_snd_489_);
v___x_490_ = l_CostPlanExperiment_timedRun(v_snd_489_, v_val_479_, v_val_480_, v_a_481_);
if (lean_obj_tag(v___x_490_) == 0)
{
lean_object* v_a_491_; lean_object* v___x_492_; lean_object* v___x_493_; 
v_a_491_ = lean_ctor_get(v___x_490_, 0);
lean_inc(v_a_491_);
lean_dec_ref_known(v___x_490_, 1);
v___x_492_ = lean_box(0);
v___x_493_ = l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__6(v_fst_488_, v_a_491_, v_b_483_, v___x_492_);
v_as_x27_482_ = v_tail_487_;
v_b_483_ = v___x_493_;
goto _start;
}
else
{
lean_object* v_a_495_; lean_object* v___x_497_; uint8_t v_isShared_498_; uint8_t v_isSharedCheck_502_; 
lean_dec(v_b_483_);
v_a_495_ = lean_ctor_get(v___x_490_, 0);
v_isSharedCheck_502_ = !lean_is_exclusive(v___x_490_);
if (v_isSharedCheck_502_ == 0)
{
v___x_497_ = v___x_490_;
v_isShared_498_ = v_isSharedCheck_502_;
goto v_resetjp_496_;
}
else
{
lean_inc(v_a_495_);
lean_dec(v___x_490_);
v___x_497_ = lean_box(0);
v_isShared_498_ = v_isSharedCheck_502_;
goto v_resetjp_496_;
}
v_resetjp_496_:
{
lean_object* v___x_500_; 
if (v_isShared_498_ == 0)
{
v___x_500_ = v___x_497_;
goto v_reusejp_499_;
}
else
{
lean_object* v_reuseFailAlloc_501_; 
v_reuseFailAlloc_501_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_501_, 0, v_a_495_);
v___x_500_ = v_reuseFailAlloc_501_;
goto v_reusejp_499_;
}
v_reusejp_499_:
{
return v___x_500_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__7___redArg___boxed(lean_object* v_val_503_, lean_object* v_val_504_, lean_object* v_a_505_, lean_object* v_as_x27_506_, lean_object* v_b_507_, lean_object* v___y_508_){
_start:
{
lean_object* v_res_509_; 
v_res_509_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__7___redArg(v_val_503_, v_val_504_, v_a_505_, v_as_x27_506_, v_b_507_);
lean_dec(v_as_x27_506_);
lean_dec(v_a_505_);
lean_dec(v_val_504_);
lean_dec(v_val_503_);
return v_res_509_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__10___redArg(lean_object* v_val_510_, lean_object* v_val_511_, lean_object* v_a_512_, lean_object* v_a_513_, lean_object* v_a_514_, lean_object* v_as_x27_515_, lean_object* v_b_516_){
_start:
{
if (lean_obj_tag(v_as_x27_515_) == 0)
{
lean_object* v___x_518_; 
lean_dec(v_a_514_);
v___x_518_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_518_, 0, v_b_516_);
return v___x_518_;
}
else
{
lean_object* v_head_519_; lean_object* v_tail_520_; lean_object* v___y_522_; lean_object* v___x_526_; lean_object* v___x_527_; lean_object* v___x_528_; lean_object* v___x_529_; lean_object* v___x_530_; lean_object* v___x_531_; lean_object* v___x_532_; lean_object* v___x_533_; lean_object* v___x_534_; lean_object* v___x_535_; uint8_t v___x_536_; 
v_head_519_ = lean_ctor_get(v_as_x27_515_, 0);
v_tail_520_ = lean_ctor_get(v_as_x27_515_, 1);
v___x_526_ = lean_unsigned_to_nat(0u);
v___x_527_ = lean_nat_add(v_a_513_, v_head_519_);
v___x_528_ = l_List_lengthTR___redArg(v_a_514_);
v___x_529_ = lean_nat_mod(v___x_527_, v___x_528_);
lean_dec(v___x_528_);
lean_dec(v___x_527_);
lean_inc(v___x_529_);
v___x_530_ = l_List_drop___redArg(v___x_529_, v_a_514_);
v___x_531_ = ((lean_object*)(l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11___redArg___closed__0));
lean_inc(v_a_514_);
v___x_532_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_a_514_, v_a_514_, v___x_529_, v___x_531_);
v___x_533_ = l_List_appendTR___redArg(v___x_530_, v___x_532_);
v___x_534_ = lean_unsigned_to_nat(2u);
v___x_535_ = lean_nat_mod(v_head_519_, v___x_534_);
v___x_536_ = lean_nat_dec_eq(v___x_535_, v___x_526_);
lean_dec(v___x_535_);
if (v___x_536_ == 0)
{
lean_object* v___x_537_; 
v___x_537_ = l_List_reverse___redArg(v___x_533_);
v___y_522_ = v___x_537_;
goto v___jp_521_;
}
else
{
v___y_522_ = v___x_533_;
goto v___jp_521_;
}
v___jp_521_:
{
lean_object* v___x_523_; 
v___x_523_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__7___redArg(v_val_510_, v_val_511_, v_a_512_, v___y_522_, v_b_516_);
lean_dec(v___y_522_);
if (lean_obj_tag(v___x_523_) == 0)
{
lean_object* v_a_524_; 
v_a_524_ = lean_ctor_get(v___x_523_, 0);
lean_inc(v_a_524_);
lean_dec_ref_known(v___x_523_, 1);
v_as_x27_515_ = v_tail_520_;
v_b_516_ = v_a_524_;
goto _start;
}
else
{
lean_dec(v_a_514_);
return v___x_523_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__10___redArg___boxed(lean_object* v_val_538_, lean_object* v_val_539_, lean_object* v_a_540_, lean_object* v_a_541_, lean_object* v_a_542_, lean_object* v_as_x27_543_, lean_object* v_b_544_, lean_object* v___y_545_){
_start:
{
lean_object* v_res_546_; 
v_res_546_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__10___redArg(v_val_538_, v_val_539_, v_a_540_, v_a_541_, v_a_542_, v_as_x27_543_, v_b_544_);
lean_dec(v_as_x27_543_);
lean_dec(v_a_541_);
lean_dec(v_a_540_);
lean_dec(v_val_539_);
lean_dec(v_val_538_);
return v_res_546_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00CostPlanExperiment_handle_spec__1_spec__1(lean_object* v_j_547_){
_start:
{
lean_object* v___x_548_; 
v___x_548_ = l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonStackTable_fromJson_spec__0_spec__0(v_j_547_);
if (lean_obj_tag(v___x_548_) == 0)
{
lean_object* v_a_549_; lean_object* v___x_551_; uint8_t v_isShared_552_; uint8_t v_isSharedCheck_556_; 
v_a_549_ = lean_ctor_get(v___x_548_, 0);
v_isSharedCheck_556_ = !lean_is_exclusive(v___x_548_);
if (v_isSharedCheck_556_ == 0)
{
v___x_551_ = v___x_548_;
v_isShared_552_ = v_isSharedCheck_556_;
goto v_resetjp_550_;
}
else
{
lean_inc(v_a_549_);
lean_dec(v___x_548_);
v___x_551_ = lean_box(0);
v_isShared_552_ = v_isSharedCheck_556_;
goto v_resetjp_550_;
}
v_resetjp_550_:
{
lean_object* v___x_554_; 
if (v_isShared_552_ == 0)
{
v___x_554_ = v___x_551_;
goto v_reusejp_553_;
}
else
{
lean_object* v_reuseFailAlloc_555_; 
v_reuseFailAlloc_555_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_555_, 0, v_a_549_);
v___x_554_ = v_reuseFailAlloc_555_;
goto v_reusejp_553_;
}
v_reusejp_553_:
{
return v___x_554_;
}
}
}
else
{
lean_object* v_a_557_; lean_object* v___x_559_; uint8_t v_isShared_560_; uint8_t v_isSharedCheck_565_; 
v_a_557_ = lean_ctor_get(v___x_548_, 0);
v_isSharedCheck_565_ = !lean_is_exclusive(v___x_548_);
if (v_isSharedCheck_565_ == 0)
{
v___x_559_ = v___x_548_;
v_isShared_560_ = v_isSharedCheck_565_;
goto v_resetjp_558_;
}
else
{
lean_inc(v_a_557_);
lean_dec(v___x_548_);
v___x_559_ = lean_box(0);
v_isShared_560_ = v_isSharedCheck_565_;
goto v_resetjp_558_;
}
v_resetjp_558_:
{
lean_object* v___x_561_; lean_object* v___x_563_; 
v___x_561_ = lean_array_to_list(v_a_557_);
if (v_isShared_560_ == 0)
{
lean_ctor_set(v___x_559_, 0, v___x_561_);
v___x_563_ = v___x_559_;
goto v_reusejp_562_;
}
else
{
lean_object* v_reuseFailAlloc_564_; 
v_reuseFailAlloc_564_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_564_, 0, v___x_561_);
v___x_563_ = v_reuseFailAlloc_564_;
goto v_reusejp_562_;
}
v_reusejp_562_:
{
return v___x_563_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00CostPlanExperiment_handle_spec__1(lean_object* v_j_566_, lean_object* v_k_567_){
_start:
{
lean_object* v___x_568_; lean_object* v___x_569_; 
v___x_568_ = l_Lean_Json_getObjValD(v_j_566_, v_k_567_);
v___x_569_ = l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00CostPlanExperiment_handle_spec__1_spec__1(v___x_568_);
return v___x_569_;
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00CostPlanExperiment_handle_spec__1___boxed(lean_object* v_j_570_, lean_object* v_k_571_){
_start:
{
lean_object* v_res_572_; 
v_res_572_ = l_Lean_Json_getObjValAs_x3f___at___00CostPlanExperiment_handle_spec__1(v_j_570_, v_k_571_);
lean_dec_ref(v_k_571_);
return v_res_572_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__9(lean_object* v_a_575_, lean_object* v_a_576_){
_start:
{
if (lean_obj_tag(v_a_575_) == 0)
{
lean_object* v___x_577_; 
v___x_577_ = l_List_reverse___redArg(v_a_576_);
return v___x_577_;
}
else
{
lean_object* v_head_578_; lean_object* v_tail_579_; lean_object* v___x_581_; uint8_t v_isShared_582_; uint8_t v_isSharedCheck_597_; 
v_head_578_ = lean_ctor_get(v_a_575_, 0);
v_tail_579_ = lean_ctor_get(v_a_575_, 1);
v_isSharedCheck_597_ = !lean_is_exclusive(v_a_575_);
if (v_isSharedCheck_597_ == 0)
{
v___x_581_ = v_a_575_;
v_isShared_582_ = v_isSharedCheck_597_;
goto v_resetjp_580_;
}
else
{
lean_inc(v_tail_579_);
lean_inc(v_head_578_);
lean_dec(v_a_575_);
v___x_581_ = lean_box(0);
v_isShared_582_ = v_isSharedCheck_597_;
goto v_resetjp_580_;
}
v_resetjp_580_:
{
lean_object* v_fst_583_; lean_object* v___x_585_; uint8_t v_isShared_586_; uint8_t v_isSharedCheck_595_; 
v_fst_583_ = lean_ctor_get(v_head_578_, 0);
v_isSharedCheck_595_ = !lean_is_exclusive(v_head_578_);
if (v_isSharedCheck_595_ == 0)
{
lean_object* v_unused_596_; 
v_unused_596_ = lean_ctor_get(v_head_578_, 1);
lean_dec(v_unused_596_);
v___x_585_ = v_head_578_;
v_isShared_586_ = v_isSharedCheck_595_;
goto v_resetjp_584_;
}
else
{
lean_inc(v_fst_583_);
lean_dec(v_head_578_);
v___x_585_ = lean_box(0);
v_isShared_586_ = v_isSharedCheck_595_;
goto v_resetjp_584_;
}
v_resetjp_584_:
{
lean_object* v___x_587_; lean_object* v___x_589_; 
v___x_587_ = ((lean_object*)(l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__9___closed__0));
if (v_isShared_586_ == 0)
{
lean_ctor_set(v___x_585_, 1, v___x_587_);
v___x_589_ = v___x_585_;
goto v_reusejp_588_;
}
else
{
lean_object* v_reuseFailAlloc_594_; 
v_reuseFailAlloc_594_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_594_, 0, v_fst_583_);
lean_ctor_set(v_reuseFailAlloc_594_, 1, v___x_587_);
v___x_589_ = v_reuseFailAlloc_594_;
goto v_reusejp_588_;
}
v_reusejp_588_:
{
lean_object* v___x_591_; 
if (v_isShared_582_ == 0)
{
lean_ctor_set(v___x_581_, 1, v_a_576_);
lean_ctor_set(v___x_581_, 0, v___x_589_);
v___x_591_ = v___x_581_;
goto v_reusejp_590_;
}
else
{
lean_object* v_reuseFailAlloc_593_; 
v_reuseFailAlloc_593_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_593_, 0, v___x_589_);
lean_ctor_set(v_reuseFailAlloc_593_, 1, v_a_576_);
v___x_591_ = v_reuseFailAlloc_593_;
goto v_reusejp_590_;
}
v_reusejp_590_:
{
v_a_575_ = v_tail_579_;
v_a_576_ = v___x_591_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00CostPlanExperiment_handle_spec__0(lean_object* v_a_598_){
_start:
{
lean_object* v___x_599_; lean_object* v___x_600_; 
v___x_599_ = lean_array_mk(v_a_598_);
v___x_600_ = l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__0(v___x_599_);
return v___x_600_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__13(lean_object* v_a_603_, lean_object* v_a_604_){
_start:
{
if (lean_obj_tag(v_a_603_) == 0)
{
lean_object* v___x_605_; 
v___x_605_ = l_List_reverse___redArg(v_a_604_);
return v___x_605_;
}
else
{
lean_object* v_head_606_; lean_object* v_snd_607_; lean_object* v_tail_608_; lean_object* v___x_610_; uint8_t v_isShared_611_; uint8_t v_isSharedCheck_648_; 
v_head_606_ = lean_ctor_get(v_a_603_, 0);
lean_inc(v_head_606_);
v_snd_607_ = lean_ctor_get(v_head_606_, 1);
lean_inc(v_snd_607_);
v_tail_608_ = lean_ctor_get(v_a_603_, 1);
v_isSharedCheck_648_ = !lean_is_exclusive(v_a_603_);
if (v_isSharedCheck_648_ == 0)
{
lean_object* v_unused_649_; 
v_unused_649_ = lean_ctor_get(v_a_603_, 0);
lean_dec(v_unused_649_);
v___x_610_ = v_a_603_;
v_isShared_611_ = v_isSharedCheck_648_;
goto v_resetjp_609_;
}
else
{
lean_inc(v_tail_608_);
lean_dec(v_a_603_);
v___x_610_ = lean_box(0);
v_isShared_611_ = v_isSharedCheck_648_;
goto v_resetjp_609_;
}
v_resetjp_609_:
{
lean_object* v_fst_612_; lean_object* v___x_614_; uint8_t v_isShared_615_; uint8_t v_isSharedCheck_646_; 
v_fst_612_ = lean_ctor_get(v_head_606_, 0);
v_isSharedCheck_646_ = !lean_is_exclusive(v_head_606_);
if (v_isSharedCheck_646_ == 0)
{
lean_object* v_unused_647_; 
v_unused_647_ = lean_ctor_get(v_head_606_, 1);
lean_dec(v_unused_647_);
v___x_614_ = v_head_606_;
v_isShared_615_ = v_isSharedCheck_646_;
goto v_resetjp_613_;
}
else
{
lean_inc(v_fst_612_);
lean_dec(v_head_606_);
v___x_614_ = lean_box(0);
v_isShared_615_ = v_isSharedCheck_646_;
goto v_resetjp_613_;
}
v_resetjp_613_:
{
lean_object* v_fst_616_; lean_object* v_snd_617_; lean_object* v___x_619_; uint8_t v_isShared_620_; uint8_t v_isSharedCheck_645_; 
v_fst_616_ = lean_ctor_get(v_snd_607_, 0);
v_snd_617_ = lean_ctor_get(v_snd_607_, 1);
v_isSharedCheck_645_ = !lean_is_exclusive(v_snd_607_);
if (v_isSharedCheck_645_ == 0)
{
v___x_619_ = v_snd_607_;
v_isShared_620_ = v_isSharedCheck_645_;
goto v_resetjp_618_;
}
else
{
lean_inc(v_snd_617_);
lean_inc(v_fst_616_);
lean_dec(v_snd_607_);
v___x_619_ = lean_box(0);
v_isShared_620_ = v_isSharedCheck_645_;
goto v_resetjp_618_;
}
v_resetjp_618_:
{
lean_object* v___x_621_; lean_object* v___x_622_; lean_object* v___x_624_; 
v___x_621_ = ((lean_object*)(l_CostPlanExperiment_profile___closed__2));
v___x_622_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_622_, 0, v_fst_612_);
if (v_isShared_620_ == 0)
{
lean_ctor_set(v___x_619_, 1, v___x_622_);
lean_ctor_set(v___x_619_, 0, v___x_621_);
v___x_624_ = v___x_619_;
goto v_reusejp_623_;
}
else
{
lean_object* v_reuseFailAlloc_644_; 
v_reuseFailAlloc_644_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_644_, 0, v___x_621_);
lean_ctor_set(v_reuseFailAlloc_644_, 1, v___x_622_);
v___x_624_ = v_reuseFailAlloc_644_;
goto v_reusejp_623_;
}
v_reusejp_623_:
{
lean_object* v___x_625_; lean_object* v___x_626_; lean_object* v___x_627_; lean_object* v___x_629_; 
v___x_625_ = ((lean_object*)(l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__13___closed__0));
v___x_626_ = l_List_reverse___redArg(v_fst_616_);
v___x_627_ = l_Lean_List_toJson___at___00CostPlanExperiment_handle_spec__0(v___x_626_);
if (v_isShared_615_ == 0)
{
lean_ctor_set(v___x_614_, 1, v___x_627_);
lean_ctor_set(v___x_614_, 0, v___x_625_);
v___x_629_ = v___x_614_;
goto v_reusejp_628_;
}
else
{
lean_object* v_reuseFailAlloc_643_; 
v_reuseFailAlloc_643_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_643_, 0, v___x_625_);
lean_ctor_set(v_reuseFailAlloc_643_, 1, v___x_627_);
v___x_629_ = v_reuseFailAlloc_643_;
goto v_reusejp_628_;
}
v_reusejp_628_:
{
lean_object* v___x_630_; lean_object* v___x_631_; lean_object* v___x_632_; lean_object* v___x_633_; lean_object* v___x_634_; lean_object* v___x_636_; 
v___x_630_ = ((lean_object*)(l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__13___closed__1));
v___x_631_ = l_List_reverse___redArg(v_snd_617_);
v___x_632_ = l_Lean_List_toJson___at___00CostPlanExperiment_handle_spec__0(v___x_631_);
v___x_633_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_633_, 0, v___x_630_);
lean_ctor_set(v___x_633_, 1, v___x_632_);
v___x_634_ = lean_box(0);
if (v_isShared_611_ == 0)
{
lean_ctor_set(v___x_610_, 1, v___x_634_);
lean_ctor_set(v___x_610_, 0, v___x_633_);
v___x_636_ = v___x_610_;
goto v_reusejp_635_;
}
else
{
lean_object* v_reuseFailAlloc_642_; 
v_reuseFailAlloc_642_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_642_, 0, v___x_633_);
lean_ctor_set(v_reuseFailAlloc_642_, 1, v___x_634_);
v___x_636_ = v_reuseFailAlloc_642_;
goto v_reusejp_635_;
}
v_reusejp_635_:
{
lean_object* v___x_637_; lean_object* v___x_638_; lean_object* v___x_639_; lean_object* v___x_640_; 
v___x_637_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_637_, 0, v___x_629_);
lean_ctor_set(v___x_637_, 1, v___x_636_);
v___x_638_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_638_, 0, v___x_624_);
lean_ctor_set(v___x_638_, 1, v___x_637_);
v___x_639_ = l_Lean_Json_mkObj(v___x_638_);
lean_dec_ref_known(v___x_638_, 2);
v___x_640_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_640_, 0, v___x_639_);
lean_ctor_set(v___x_640_, 1, v_a_604_);
v_a_603_ = v_tail_608_;
v_a_604_ = v___x_640_;
goto _start;
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__8___redArg(lean_object* v_val_650_, lean_object* v_val_651_, lean_object* v_a_652_, lean_object* v_as_x27_653_, lean_object* v_b_654_){
_start:
{
if (lean_obj_tag(v_as_x27_653_) == 0)
{
lean_object* v___x_656_; 
v___x_656_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_656_, 0, v_b_654_);
return v___x_656_;
}
else
{
lean_object* v_head_657_; lean_object* v_tail_658_; lean_object* v_snd_659_; lean_object* v___x_660_; 
v_head_657_ = lean_ctor_get(v_as_x27_653_, 0);
v_tail_658_ = lean_ctor_get(v_as_x27_653_, 1);
v_snd_659_ = lean_ctor_get(v_head_657_, 1);
lean_inc(v_snd_659_);
v___x_660_ = l_CostPlanExperiment_timedRun(v_snd_659_, v_val_650_, v_val_651_, v_a_652_);
if (lean_obj_tag(v___x_660_) == 0)
{
lean_object* v___x_661_; 
lean_dec_ref_known(v___x_660_, 1);
v___x_661_ = lean_box(0);
v_as_x27_653_ = v_tail_658_;
v_b_654_ = v___x_661_;
goto _start;
}
else
{
lean_object* v_a_663_; lean_object* v___x_665_; uint8_t v_isShared_666_; uint8_t v_isSharedCheck_670_; 
v_a_663_ = lean_ctor_get(v___x_660_, 0);
v_isSharedCheck_670_ = !lean_is_exclusive(v___x_660_);
if (v_isSharedCheck_670_ == 0)
{
v___x_665_ = v___x_660_;
v_isShared_666_ = v_isSharedCheck_670_;
goto v_resetjp_664_;
}
else
{
lean_inc(v_a_663_);
lean_dec(v___x_660_);
v___x_665_ = lean_box(0);
v_isShared_666_ = v_isSharedCheck_670_;
goto v_resetjp_664_;
}
v_resetjp_664_:
{
lean_object* v___x_668_; 
if (v_isShared_666_ == 0)
{
v___x_668_ = v___x_665_;
goto v_reusejp_667_;
}
else
{
lean_object* v_reuseFailAlloc_669_; 
v_reuseFailAlloc_669_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_669_, 0, v_a_663_);
v___x_668_ = v_reuseFailAlloc_669_;
goto v_reusejp_667_;
}
v_reusejp_667_:
{
return v___x_668_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__8___redArg___boxed(lean_object* v_val_671_, lean_object* v_val_672_, lean_object* v_a_673_, lean_object* v_as_x27_674_, lean_object* v_b_675_, lean_object* v___y_676_){
_start:
{
lean_object* v_res_677_; 
v_res_677_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__8___redArg(v_val_671_, v_val_672_, v_a_673_, v_as_x27_674_, v_b_675_);
lean_dec(v_as_x27_674_);
lean_dec(v_a_673_);
lean_dec(v_val_672_);
lean_dec(v_val_671_);
return v_res_677_;
}
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_handle(lean_object* v_j_692_){
_start:
{
lean_object* v___x_694_; lean_object* v___x_695_; lean_object* v___x_696_; 
v___x_694_ = ((lean_object*)(l_CostPlanExperiment_handle___closed__0));
lean_inc(v_j_692_);
v___x_695_ = l_Lean_Json_getObjValAs_x3f___at___00CostPlanExperiment_handle_spec__1(v_j_692_, v___x_694_);
v___x_696_ = l_CostPlanExperiment_orError___redArg(v___x_695_);
if (lean_obj_tag(v___x_696_) == 0)
{
lean_object* v_a_697_; lean_object* v___x_698_; lean_object* v___x_699_; lean_object* v___x_700_; 
v_a_697_ = lean_ctor_get(v___x_696_, 0);
lean_inc(v_a_697_);
lean_dec_ref_known(v___x_696_, 1);
v___x_698_ = ((lean_object*)(l_CostPlanExperiment_handle___closed__1));
lean_inc(v_j_692_);
v___x_699_ = l_Lean_Json_getObjValAs_x3f___at___00CostPlanExperiment_handle_spec__1(v_j_692_, v___x_698_);
v___x_700_ = l_CostPlanExperiment_orError___redArg(v___x_699_);
if (lean_obj_tag(v___x_700_) == 0)
{
lean_object* v_a_701_; lean_object* v___x_702_; lean_object* v___x_703_; lean_object* v___x_704_; 
v_a_701_ = lean_ctor_get(v___x_700_, 0);
lean_inc(v_a_701_);
lean_dec_ref_known(v___x_700_, 1);
v___x_702_ = ((lean_object*)(l_CostPlanExperiment_handle___closed__2));
lean_inc(v_j_692_);
v___x_703_ = lp_LeanSearchClient_Lean_Json_getObjValAs_x3f___at___00LeanSearchClient_getLoogleQueryJson_spec__4(v_j_692_, v___x_702_);
v___x_704_ = l_CostPlanExperiment_orError___redArg(v___x_703_);
if (lean_obj_tag(v___x_704_) == 0)
{
lean_object* v_a_705_; lean_object* v___x_706_; lean_object* v___x_707_; lean_object* v___x_708_; 
v_a_705_ = lean_ctor_get(v___x_704_, 0);
lean_inc(v_a_705_);
lean_dec_ref_known(v___x_704_, 1);
v___x_706_ = ((lean_object*)(l_CostPlanExperiment_handle___closed__3));
lean_inc(v_j_692_);
v___x_707_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_692_, v___x_706_);
v___x_708_ = l_CostPlanExperiment_orError___redArg(v___x_707_);
if (lean_obj_tag(v___x_708_) == 0)
{
lean_object* v_a_709_; lean_object* v___x_710_; lean_object* v___x_711_; lean_object* v___x_712_; 
v_a_709_ = lean_ctor_get(v___x_708_, 0);
lean_inc(v_a_709_);
lean_dec_ref_known(v___x_708_, 1);
v___x_710_ = ((lean_object*)(l_CostPlanExperiment_handle___closed__4));
v___x_711_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_692_, v___x_710_);
v___x_712_ = l_CostPlanExperiment_orError___redArg(v___x_711_);
if (lean_obj_tag(v___x_712_) == 0)
{
lean_object* v_a_713_; lean_object* v___x_715_; uint8_t v_isShared_716_; uint8_t v_isSharedCheck_813_; 
v_a_713_ = lean_ctor_get(v___x_712_, 0);
v_isSharedCheck_813_ = !lean_is_exclusive(v___x_712_);
if (v_isSharedCheck_813_ == 0)
{
v___x_715_ = v___x_712_;
v_isShared_716_ = v_isSharedCheck_813_;
goto v_resetjp_714_;
}
else
{
lean_inc(v_a_713_);
lean_dec(v___x_712_);
v___x_715_ = lean_box(0);
v_isShared_716_ = v_isSharedCheck_813_;
goto v_resetjp_714_;
}
v_resetjp_714_:
{
uint8_t v___y_718_; lean_object* v___x_809_; uint8_t v___x_810_; 
v___x_809_ = lean_unsigned_to_nat(1u);
v___x_810_ = lean_nat_dec_le(v___x_809_, v_a_709_);
if (v___x_810_ == 0)
{
v___y_718_ = v___x_810_;
goto v___jp_717_;
}
else
{
lean_object* v___x_811_; uint8_t v___x_812_; 
v___x_811_ = lean_unsigned_to_nat(21u);
v___x_812_ = lean_nat_dec_le(v_a_709_, v___x_811_);
v___y_718_ = v___x_812_;
goto v___jp_717_;
}
v___jp_717_:
{
if (v___y_718_ == 0)
{
lean_object* v___x_719_; lean_object* v___x_721_; 
lean_dec(v_a_713_);
lean_dec(v_a_709_);
lean_dec(v_a_705_);
lean_dec(v_a_701_);
lean_dec(v_a_697_);
v___x_719_ = ((lean_object*)(l_CostPlanExperiment_handle___closed__6));
if (v_isShared_716_ == 0)
{
lean_ctor_set_tag(v___x_715_, 1);
lean_ctor_set(v___x_715_, 0, v___x_719_);
v___x_721_ = v___x_715_;
goto v_reusejp_720_;
}
else
{
lean_object* v_reuseFailAlloc_722_; 
v_reuseFailAlloc_722_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_722_, 0, v___x_719_);
v___x_721_ = v_reuseFailAlloc_722_;
goto v_reusejp_720_;
}
v_reusejp_720_:
{
return v___x_721_;
}
}
else
{
lean_object* v___x_723_; lean_object* v___x_724_; 
lean_del_object(v___x_715_);
v___x_723_ = lean_box(0);
v___x_724_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___redArg(v_a_705_, v___x_723_);
lean_dec(v_a_705_);
if (lean_obj_tag(v___x_724_) == 0)
{
lean_object* v_a_725_; lean_object* v___x_727_; uint8_t v_isShared_728_; uint8_t v_isSharedCheck_800_; 
v_a_725_ = lean_ctor_get(v___x_724_, 0);
v_isSharedCheck_800_ = !lean_is_exclusive(v___x_724_);
if (v_isSharedCheck_800_ == 0)
{
v___x_727_ = v___x_724_;
v_isShared_728_ = v_isSharedCheck_800_;
goto v_resetjp_726_;
}
else
{
lean_inc(v_a_725_);
lean_dec(v___x_724_);
v___x_727_ = lean_box(0);
v_isShared_728_ = v_isSharedCheck_800_;
goto v_resetjp_726_;
}
v_resetjp_726_:
{
uint8_t v___x_729_; 
v___x_729_ = l_List_isEmpty___redArg(v_a_725_);
if (v___x_729_ == 0)
{
lean_object* v___x_730_; lean_object* v___x_731_; lean_object* v___x_732_; lean_object* v___x_733_; lean_object* v___x_734_; 
lean_del_object(v___x_727_);
v___x_730_ = lean_st_mk_ref(v_a_697_);
v___x_731_ = lean_unsigned_to_nat(0u);
v___x_732_ = lean_st_mk_ref(v___x_731_);
v___x_733_ = lean_box(0);
v___x_734_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__8___redArg(v___x_730_, v___x_732_, v_a_701_, v_a_725_, v___x_733_);
if (lean_obj_tag(v___x_734_) == 0)
{
lean_object* v___x_735_; lean_object* v___x_736_; lean_object* v___x_737_; 
lean_dec_ref_known(v___x_734_, 1);
lean_inc_n(v_a_725_, 2);
v___x_735_ = l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__9(v_a_725_, v___x_723_);
v___x_736_ = l_List_range(v_a_709_);
v___x_737_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__10___redArg(v___x_730_, v___x_732_, v_a_701_, v_a_713_, v_a_725_, v___x_736_, v___x_735_);
if (lean_obj_tag(v___x_737_) == 0)
{
lean_object* v_a_738_; lean_object* v___x_739_; 
v_a_738_ = lean_ctor_get(v___x_737_, 0);
lean_inc(v_a_738_);
lean_dec_ref_known(v___x_737_, 1);
lean_inc(v_a_725_);
v___x_739_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11___redArg(v_a_713_, v_a_725_, v___x_730_, v___x_732_, v___x_736_, v_a_738_);
lean_dec(v___x_736_);
lean_dec(v___x_732_);
lean_dec(v_a_713_);
if (lean_obj_tag(v___x_739_) == 0)
{
lean_object* v_a_740_; lean_object* v___x_741_; 
v_a_740_ = lean_ctor_get(v___x_739_, 0);
lean_inc(v_a_740_);
lean_dec_ref_known(v___x_739_, 1);
v___x_741_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__12___redArg(v___x_730_, v_a_701_, v_a_725_, v___x_723_);
lean_dec(v_a_725_);
lean_dec(v_a_701_);
lean_dec(v___x_730_);
if (lean_obj_tag(v___x_741_) == 0)
{
lean_object* v_a_742_; lean_object* v___x_744_; uint8_t v_isShared_745_; uint8_t v_isSharedCheck_763_; 
v_a_742_ = lean_ctor_get(v___x_741_, 0);
v_isSharedCheck_763_ = !lean_is_exclusive(v___x_741_);
if (v_isSharedCheck_763_ == 0)
{
v___x_744_ = v___x_741_;
v_isShared_745_ = v_isSharedCheck_763_;
goto v_resetjp_743_;
}
else
{
lean_inc(v_a_742_);
lean_dec(v___x_741_);
v___x_744_ = lean_box(0);
v_isShared_745_ = v_isSharedCheck_763_;
goto v_resetjp_743_;
}
v_resetjp_743_:
{
lean_object* v___x_746_; lean_object* v___x_747_; lean_object* v___x_748_; lean_object* v___x_749_; lean_object* v___x_750_; lean_object* v___x_751_; lean_object* v___x_752_; lean_object* v___x_753_; lean_object* v___x_754_; lean_object* v___x_755_; lean_object* v___x_756_; lean_object* v___x_757_; lean_object* v___x_758_; lean_object* v___x_759_; lean_object* v___x_761_; 
v___x_746_ = ((lean_object*)(l_CostPlanExperiment_handle___closed__7));
v___x_747_ = l_List_mapTR_loop___at___00CostPlanExperiment_handle_spec__13(v_a_740_, v___x_723_);
v___x_748_ = l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(v___x_747_);
v___x_749_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_749_, 0, v___x_746_);
lean_ctor_set(v___x_749_, 1, v___x_748_);
v___x_750_ = ((lean_object*)(l_CostPlanExperiment_handle___closed__8));
v___x_751_ = l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(v_a_742_);
v___x_752_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_752_, 0, v___x_750_);
lean_ctor_set(v___x_752_, 1, v___x_751_);
v___x_753_ = ((lean_object*)(l_CostPlanExperiment_handle___closed__9));
v___x_754_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_754_, 0, v___y_718_);
v___x_755_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_755_, 0, v___x_753_);
lean_ctor_set(v___x_755_, 1, v___x_754_);
v___x_756_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_756_, 0, v___x_755_);
lean_ctor_set(v___x_756_, 1, v___x_723_);
v___x_757_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_757_, 0, v___x_752_);
lean_ctor_set(v___x_757_, 1, v___x_756_);
v___x_758_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_758_, 0, v___x_749_);
lean_ctor_set(v___x_758_, 1, v___x_757_);
v___x_759_ = l_Lean_Json_mkObj(v___x_758_);
lean_dec_ref_known(v___x_758_, 2);
if (v_isShared_745_ == 0)
{
lean_ctor_set(v___x_744_, 0, v___x_759_);
v___x_761_ = v___x_744_;
goto v_reusejp_760_;
}
else
{
lean_object* v_reuseFailAlloc_762_; 
v_reuseFailAlloc_762_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_762_, 0, v___x_759_);
v___x_761_ = v_reuseFailAlloc_762_;
goto v_reusejp_760_;
}
v_reusejp_760_:
{
return v___x_761_;
}
}
}
else
{
lean_object* v_a_764_; lean_object* v___x_766_; uint8_t v_isShared_767_; uint8_t v_isSharedCheck_771_; 
lean_dec(v_a_740_);
v_a_764_ = lean_ctor_get(v___x_741_, 0);
v_isSharedCheck_771_ = !lean_is_exclusive(v___x_741_);
if (v_isSharedCheck_771_ == 0)
{
v___x_766_ = v___x_741_;
v_isShared_767_ = v_isSharedCheck_771_;
goto v_resetjp_765_;
}
else
{
lean_inc(v_a_764_);
lean_dec(v___x_741_);
v___x_766_ = lean_box(0);
v_isShared_767_ = v_isSharedCheck_771_;
goto v_resetjp_765_;
}
v_resetjp_765_:
{
lean_object* v___x_769_; 
if (v_isShared_767_ == 0)
{
v___x_769_ = v___x_766_;
goto v_reusejp_768_;
}
else
{
lean_object* v_reuseFailAlloc_770_; 
v_reuseFailAlloc_770_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_770_, 0, v_a_764_);
v___x_769_ = v_reuseFailAlloc_770_;
goto v_reusejp_768_;
}
v_reusejp_768_:
{
return v___x_769_;
}
}
}
}
else
{
lean_object* v_a_772_; lean_object* v___x_774_; uint8_t v_isShared_775_; uint8_t v_isSharedCheck_779_; 
lean_dec(v___x_730_);
lean_dec(v_a_725_);
lean_dec(v_a_701_);
v_a_772_ = lean_ctor_get(v___x_739_, 0);
v_isSharedCheck_779_ = !lean_is_exclusive(v___x_739_);
if (v_isSharedCheck_779_ == 0)
{
v___x_774_ = v___x_739_;
v_isShared_775_ = v_isSharedCheck_779_;
goto v_resetjp_773_;
}
else
{
lean_inc(v_a_772_);
lean_dec(v___x_739_);
v___x_774_ = lean_box(0);
v_isShared_775_ = v_isSharedCheck_779_;
goto v_resetjp_773_;
}
v_resetjp_773_:
{
lean_object* v___x_777_; 
if (v_isShared_775_ == 0)
{
v___x_777_ = v___x_774_;
goto v_reusejp_776_;
}
else
{
lean_object* v_reuseFailAlloc_778_; 
v_reuseFailAlloc_778_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_778_, 0, v_a_772_);
v___x_777_ = v_reuseFailAlloc_778_;
goto v_reusejp_776_;
}
v_reusejp_776_:
{
return v___x_777_;
}
}
}
}
else
{
lean_object* v_a_780_; lean_object* v___x_782_; uint8_t v_isShared_783_; uint8_t v_isSharedCheck_787_; 
lean_dec(v___x_736_);
lean_dec(v___x_732_);
lean_dec(v___x_730_);
lean_dec(v_a_725_);
lean_dec(v_a_713_);
lean_dec(v_a_701_);
v_a_780_ = lean_ctor_get(v___x_737_, 0);
v_isSharedCheck_787_ = !lean_is_exclusive(v___x_737_);
if (v_isSharedCheck_787_ == 0)
{
v___x_782_ = v___x_737_;
v_isShared_783_ = v_isSharedCheck_787_;
goto v_resetjp_781_;
}
else
{
lean_inc(v_a_780_);
lean_dec(v___x_737_);
v___x_782_ = lean_box(0);
v_isShared_783_ = v_isSharedCheck_787_;
goto v_resetjp_781_;
}
v_resetjp_781_:
{
lean_object* v___x_785_; 
if (v_isShared_783_ == 0)
{
v___x_785_ = v___x_782_;
goto v_reusejp_784_;
}
else
{
lean_object* v_reuseFailAlloc_786_; 
v_reuseFailAlloc_786_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_786_, 0, v_a_780_);
v___x_785_ = v_reuseFailAlloc_786_;
goto v_reusejp_784_;
}
v_reusejp_784_:
{
return v___x_785_;
}
}
}
}
else
{
lean_object* v_a_788_; lean_object* v___x_790_; uint8_t v_isShared_791_; uint8_t v_isSharedCheck_795_; 
lean_dec(v___x_732_);
lean_dec(v___x_730_);
lean_dec(v_a_725_);
lean_dec(v_a_713_);
lean_dec(v_a_709_);
lean_dec(v_a_701_);
v_a_788_ = lean_ctor_get(v___x_734_, 0);
v_isSharedCheck_795_ = !lean_is_exclusive(v___x_734_);
if (v_isSharedCheck_795_ == 0)
{
v___x_790_ = v___x_734_;
v_isShared_791_ = v_isSharedCheck_795_;
goto v_resetjp_789_;
}
else
{
lean_inc(v_a_788_);
lean_dec(v___x_734_);
v___x_790_ = lean_box(0);
v_isShared_791_ = v_isSharedCheck_795_;
goto v_resetjp_789_;
}
v_resetjp_789_:
{
lean_object* v___x_793_; 
if (v_isShared_791_ == 0)
{
v___x_793_ = v___x_790_;
goto v_reusejp_792_;
}
else
{
lean_object* v_reuseFailAlloc_794_; 
v_reuseFailAlloc_794_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_794_, 0, v_a_788_);
v___x_793_ = v_reuseFailAlloc_794_;
goto v_reusejp_792_;
}
v_reusejp_792_:
{
return v___x_793_;
}
}
}
}
else
{
lean_object* v___x_796_; lean_object* v___x_798_; 
lean_dec(v_a_725_);
lean_dec(v_a_713_);
lean_dec(v_a_709_);
lean_dec(v_a_701_);
lean_dec(v_a_697_);
v___x_796_ = ((lean_object*)(l_CostPlanExperiment_handle___closed__11));
if (v_isShared_728_ == 0)
{
lean_ctor_set_tag(v___x_727_, 1);
lean_ctor_set(v___x_727_, 0, v___x_796_);
v___x_798_ = v___x_727_;
goto v_reusejp_797_;
}
else
{
lean_object* v_reuseFailAlloc_799_; 
v_reuseFailAlloc_799_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_799_, 0, v___x_796_);
v___x_798_ = v_reuseFailAlloc_799_;
goto v_reusejp_797_;
}
v_reusejp_797_:
{
return v___x_798_;
}
}
}
}
else
{
lean_object* v_a_801_; lean_object* v___x_803_; uint8_t v_isShared_804_; uint8_t v_isSharedCheck_808_; 
lean_dec(v_a_713_);
lean_dec(v_a_709_);
lean_dec(v_a_701_);
lean_dec(v_a_697_);
v_a_801_ = lean_ctor_get(v___x_724_, 0);
v_isSharedCheck_808_ = !lean_is_exclusive(v___x_724_);
if (v_isSharedCheck_808_ == 0)
{
v___x_803_ = v___x_724_;
v_isShared_804_ = v_isSharedCheck_808_;
goto v_resetjp_802_;
}
else
{
lean_inc(v_a_801_);
lean_dec(v___x_724_);
v___x_803_ = lean_box(0);
v_isShared_804_ = v_isSharedCheck_808_;
goto v_resetjp_802_;
}
v_resetjp_802_:
{
lean_object* v___x_806_; 
if (v_isShared_804_ == 0)
{
v___x_806_ = v___x_803_;
goto v_reusejp_805_;
}
else
{
lean_object* v_reuseFailAlloc_807_; 
v_reuseFailAlloc_807_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_807_, 0, v_a_801_);
v___x_806_ = v_reuseFailAlloc_807_;
goto v_reusejp_805_;
}
v_reusejp_805_:
{
return v___x_806_;
}
}
}
}
}
}
}
else
{
lean_object* v_a_814_; lean_object* v___x_816_; uint8_t v_isShared_817_; uint8_t v_isSharedCheck_821_; 
lean_dec(v_a_709_);
lean_dec(v_a_705_);
lean_dec(v_a_701_);
lean_dec(v_a_697_);
v_a_814_ = lean_ctor_get(v___x_712_, 0);
v_isSharedCheck_821_ = !lean_is_exclusive(v___x_712_);
if (v_isSharedCheck_821_ == 0)
{
v___x_816_ = v___x_712_;
v_isShared_817_ = v_isSharedCheck_821_;
goto v_resetjp_815_;
}
else
{
lean_inc(v_a_814_);
lean_dec(v___x_712_);
v___x_816_ = lean_box(0);
v_isShared_817_ = v_isSharedCheck_821_;
goto v_resetjp_815_;
}
v_resetjp_815_:
{
lean_object* v___x_819_; 
if (v_isShared_817_ == 0)
{
v___x_819_ = v___x_816_;
goto v_reusejp_818_;
}
else
{
lean_object* v_reuseFailAlloc_820_; 
v_reuseFailAlloc_820_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_820_, 0, v_a_814_);
v___x_819_ = v_reuseFailAlloc_820_;
goto v_reusejp_818_;
}
v_reusejp_818_:
{
return v___x_819_;
}
}
}
}
else
{
lean_object* v_a_822_; lean_object* v___x_824_; uint8_t v_isShared_825_; uint8_t v_isSharedCheck_829_; 
lean_dec(v_a_705_);
lean_dec(v_a_701_);
lean_dec(v_a_697_);
lean_dec(v_j_692_);
v_a_822_ = lean_ctor_get(v___x_708_, 0);
v_isSharedCheck_829_ = !lean_is_exclusive(v___x_708_);
if (v_isSharedCheck_829_ == 0)
{
v___x_824_ = v___x_708_;
v_isShared_825_ = v_isSharedCheck_829_;
goto v_resetjp_823_;
}
else
{
lean_inc(v_a_822_);
lean_dec(v___x_708_);
v___x_824_ = lean_box(0);
v_isShared_825_ = v_isSharedCheck_829_;
goto v_resetjp_823_;
}
v_resetjp_823_:
{
lean_object* v___x_827_; 
if (v_isShared_825_ == 0)
{
v___x_827_ = v___x_824_;
goto v_reusejp_826_;
}
else
{
lean_object* v_reuseFailAlloc_828_; 
v_reuseFailAlloc_828_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_828_, 0, v_a_822_);
v___x_827_ = v_reuseFailAlloc_828_;
goto v_reusejp_826_;
}
v_reusejp_826_:
{
return v___x_827_;
}
}
}
}
else
{
lean_object* v_a_830_; lean_object* v___x_832_; uint8_t v_isShared_833_; uint8_t v_isSharedCheck_837_; 
lean_dec(v_a_701_);
lean_dec(v_a_697_);
lean_dec(v_j_692_);
v_a_830_ = lean_ctor_get(v___x_704_, 0);
v_isSharedCheck_837_ = !lean_is_exclusive(v___x_704_);
if (v_isSharedCheck_837_ == 0)
{
v___x_832_ = v___x_704_;
v_isShared_833_ = v_isSharedCheck_837_;
goto v_resetjp_831_;
}
else
{
lean_inc(v_a_830_);
lean_dec(v___x_704_);
v___x_832_ = lean_box(0);
v_isShared_833_ = v_isSharedCheck_837_;
goto v_resetjp_831_;
}
v_resetjp_831_:
{
lean_object* v___x_835_; 
if (v_isShared_833_ == 0)
{
v___x_835_ = v___x_832_;
goto v_reusejp_834_;
}
else
{
lean_object* v_reuseFailAlloc_836_; 
v_reuseFailAlloc_836_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_836_, 0, v_a_830_);
v___x_835_ = v_reuseFailAlloc_836_;
goto v_reusejp_834_;
}
v_reusejp_834_:
{
return v___x_835_;
}
}
}
}
else
{
lean_object* v_a_838_; lean_object* v___x_840_; uint8_t v_isShared_841_; uint8_t v_isSharedCheck_845_; 
lean_dec(v_a_697_);
lean_dec(v_j_692_);
v_a_838_ = lean_ctor_get(v___x_700_, 0);
v_isSharedCheck_845_ = !lean_is_exclusive(v___x_700_);
if (v_isSharedCheck_845_ == 0)
{
v___x_840_ = v___x_700_;
v_isShared_841_ = v_isSharedCheck_845_;
goto v_resetjp_839_;
}
else
{
lean_inc(v_a_838_);
lean_dec(v___x_700_);
v___x_840_ = lean_box(0);
v_isShared_841_ = v_isSharedCheck_845_;
goto v_resetjp_839_;
}
v_resetjp_839_:
{
lean_object* v___x_843_; 
if (v_isShared_841_ == 0)
{
v___x_843_ = v___x_840_;
goto v_reusejp_842_;
}
else
{
lean_object* v_reuseFailAlloc_844_; 
v_reuseFailAlloc_844_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_844_, 0, v_a_838_);
v___x_843_ = v_reuseFailAlloc_844_;
goto v_reusejp_842_;
}
v_reusejp_842_:
{
return v___x_843_;
}
}
}
}
else
{
lean_object* v_a_846_; lean_object* v___x_848_; uint8_t v_isShared_849_; uint8_t v_isSharedCheck_853_; 
lean_dec(v_j_692_);
v_a_846_ = lean_ctor_get(v___x_696_, 0);
v_isSharedCheck_853_ = !lean_is_exclusive(v___x_696_);
if (v_isSharedCheck_853_ == 0)
{
v___x_848_ = v___x_696_;
v_isShared_849_ = v_isSharedCheck_853_;
goto v_resetjp_847_;
}
else
{
lean_inc(v_a_846_);
lean_dec(v___x_696_);
v___x_848_ = lean_box(0);
v_isShared_849_ = v_isSharedCheck_853_;
goto v_resetjp_847_;
}
v_resetjp_847_:
{
lean_object* v___x_851_; 
if (v_isShared_849_ == 0)
{
v___x_851_ = v___x_848_;
goto v_reusejp_850_;
}
else
{
lean_object* v_reuseFailAlloc_852_; 
v_reuseFailAlloc_852_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_852_, 0, v_a_846_);
v___x_851_ = v_reuseFailAlloc_852_;
goto v_reusejp_850_;
}
v_reusejp_850_:
{
return v___x_851_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_handle___boxed(lean_object* v_j_854_, lean_object* v_a_855_){
_start:
{
lean_object* v_res_856_; 
v_res_856_ = l_CostPlanExperiment_handle(v_j_854_);
return v_res_856_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3(lean_object* v_as_857_, lean_object* v_as_x27_858_, lean_object* v_b_859_, lean_object* v_a_860_){
_start:
{
lean_object* v___x_862_; 
v___x_862_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___redArg(v_as_x27_858_, v_b_859_);
return v___x_862_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3___boxed(lean_object* v_as_863_, lean_object* v_as_x27_864_, lean_object* v_b_865_, lean_object* v_a_866_, lean_object* v___y_867_){
_start:
{
lean_object* v_res_868_; 
v_res_868_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__3(v_as_863_, v_as_x27_864_, v_b_865_, v_a_866_);
lean_dec(v_as_x27_864_);
lean_dec(v_as_863_);
return v_res_868_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__5(lean_object* v_val_869_, lean_object* v_val_870_, lean_object* v_as_871_, lean_object* v_as_x27_872_, lean_object* v_b_873_, lean_object* v_a_874_){
_start:
{
lean_object* v___x_876_; 
v___x_876_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__5___redArg(v_val_869_, v_val_870_, v_as_x27_872_, v_b_873_);
return v___x_876_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__5___boxed(lean_object* v_val_877_, lean_object* v_val_878_, lean_object* v_as_879_, lean_object* v_as_x27_880_, lean_object* v_b_881_, lean_object* v_a_882_, lean_object* v___y_883_){
_start:
{
lean_object* v_res_884_; 
v_res_884_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__5(v_val_877_, v_val_878_, v_as_879_, v_as_x27_880_, v_b_881_, v_a_882_);
lean_dec(v_as_x27_880_);
lean_dec(v_as_879_);
lean_dec(v_val_878_);
lean_dec(v_val_877_);
return v_res_884_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__7(lean_object* v_val_885_, lean_object* v_val_886_, lean_object* v_a_887_, lean_object* v_as_888_, lean_object* v_as_x27_889_, lean_object* v_b_890_, lean_object* v_a_891_){
_start:
{
lean_object* v___x_893_; 
v___x_893_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__7___redArg(v_val_885_, v_val_886_, v_a_887_, v_as_x27_889_, v_b_890_);
return v___x_893_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__7___boxed(lean_object* v_val_894_, lean_object* v_val_895_, lean_object* v_a_896_, lean_object* v_as_897_, lean_object* v_as_x27_898_, lean_object* v_b_899_, lean_object* v_a_900_, lean_object* v___y_901_){
_start:
{
lean_object* v_res_902_; 
v_res_902_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__7(v_val_894_, v_val_895_, v_a_896_, v_as_897_, v_as_x27_898_, v_b_899_, v_a_900_);
lean_dec(v_as_x27_898_);
lean_dec(v_as_897_);
lean_dec(v_a_896_);
lean_dec(v_val_895_);
lean_dec(v_val_894_);
return v_res_902_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__8(lean_object* v_val_903_, lean_object* v_val_904_, lean_object* v_a_905_, lean_object* v_as_906_, lean_object* v_as_x27_907_, lean_object* v_b_908_, lean_object* v_a_909_){
_start:
{
lean_object* v___x_911_; 
v___x_911_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__8___redArg(v_val_903_, v_val_904_, v_a_905_, v_as_x27_907_, v_b_908_);
return v___x_911_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__8___boxed(lean_object* v_val_912_, lean_object* v_val_913_, lean_object* v_a_914_, lean_object* v_as_915_, lean_object* v_as_x27_916_, lean_object* v_b_917_, lean_object* v_a_918_, lean_object* v___y_919_){
_start:
{
lean_object* v_res_920_; 
v_res_920_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__8(v_val_912_, v_val_913_, v_a_914_, v_as_915_, v_as_x27_916_, v_b_917_, v_a_918_);
lean_dec(v_as_x27_916_);
lean_dec(v_as_915_);
lean_dec(v_a_914_);
lean_dec(v_val_913_);
lean_dec(v_val_912_);
return v_res_920_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__10(lean_object* v_val_921_, lean_object* v_val_922_, lean_object* v_a_923_, lean_object* v_a_924_, lean_object* v_a_925_, lean_object* v_as_926_, lean_object* v_as_x27_927_, lean_object* v_b_928_, lean_object* v_a_929_){
_start:
{
lean_object* v___x_931_; 
v___x_931_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__10___redArg(v_val_921_, v_val_922_, v_a_923_, v_a_924_, v_a_925_, v_as_x27_927_, v_b_928_);
return v___x_931_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__10___boxed(lean_object* v_val_932_, lean_object* v_val_933_, lean_object* v_a_934_, lean_object* v_a_935_, lean_object* v_a_936_, lean_object* v_as_937_, lean_object* v_as_x27_938_, lean_object* v_b_939_, lean_object* v_a_940_, lean_object* v___y_941_){
_start:
{
lean_object* v_res_942_; 
v_res_942_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__10(v_val_932_, v_val_933_, v_a_934_, v_a_935_, v_a_936_, v_as_937_, v_as_x27_938_, v_b_939_, v_a_940_);
lean_dec(v_as_x27_938_);
lean_dec(v_as_937_);
lean_dec(v_a_935_);
lean_dec(v_a_934_);
lean_dec(v_val_933_);
lean_dec(v_val_932_);
return v_res_942_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11(lean_object* v_a_943_, lean_object* v_a_944_, lean_object* v_val_945_, lean_object* v_val_946_, lean_object* v_as_947_, lean_object* v_as_x27_948_, lean_object* v_b_949_, lean_object* v_a_950_){
_start:
{
lean_object* v___x_952_; 
v___x_952_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11___redArg(v_a_943_, v_a_944_, v_val_945_, v_val_946_, v_as_x27_948_, v_b_949_);
return v___x_952_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11___boxed(lean_object* v_a_953_, lean_object* v_a_954_, lean_object* v_val_955_, lean_object* v_val_956_, lean_object* v_as_957_, lean_object* v_as_x27_958_, lean_object* v_b_959_, lean_object* v_a_960_, lean_object* v___y_961_){
_start:
{
lean_object* v_res_962_; 
v_res_962_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__11(v_a_953_, v_a_954_, v_val_955_, v_val_956_, v_as_957_, v_as_x27_958_, v_b_959_, v_a_960_);
lean_dec(v_as_x27_958_);
lean_dec(v_as_957_);
lean_dec(v_val_956_);
lean_dec(v_val_955_);
lean_dec(v_a_953_);
return v_res_962_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__12(lean_object* v_val_963_, lean_object* v_a_964_, lean_object* v_as_965_, lean_object* v_as_x27_966_, lean_object* v_b_967_, lean_object* v_a_968_){
_start:
{
lean_object* v___x_970_; 
v___x_970_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__12___redArg(v_val_963_, v_a_964_, v_as_x27_966_, v_b_967_);
return v___x_970_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__12___boxed(lean_object* v_val_971_, lean_object* v_a_972_, lean_object* v_as_973_, lean_object* v_as_x27_974_, lean_object* v_b_975_, lean_object* v_a_976_, lean_object* v___y_977_){
_start:
{
lean_object* v_res_978_; 
v_res_978_ = l_List_forIn_x27_loop___at___00CostPlanExperiment_handle_spec__12(v_val_971_, v_a_972_, v_as_973_, v_as_x27_974_, v_b_975_, v_a_976_);
lean_dec(v_as_x27_974_);
lean_dec(v_as_973_);
lean_dec(v_a_972_);
lean_dec(v_val_971_);
return v_res_978_;
}
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_loop(){
_start:
{
lean_object* v___x_981_; lean_object* v___x_982_; lean_object* v_a_984_; lean_object* v___y_991_; lean_object* v_getLine_1007_; lean_object* v___x_1008_; 
v___x_981_ = lean_get_stdin();
v___x_982_ = lean_get_stdout();
v_getLine_1007_ = lean_ctor_get(v___x_981_, 3);
lean_inc_ref(v_getLine_1007_);
lean_dec_ref(v___x_981_);
v___x_1008_ = lean_apply_1(v_getLine_1007_, lean_box(0));
if (lean_obj_tag(v___x_1008_) == 0)
{
lean_object* v_a_1009_; lean_object* v___x_1011_; uint8_t v_isShared_1012_; uint8_t v_isSharedCheck_1024_; 
v_a_1009_ = lean_ctor_get(v___x_1008_, 0);
v_isSharedCheck_1024_ = !lean_is_exclusive(v___x_1008_);
if (v_isSharedCheck_1024_ == 0)
{
v___x_1011_ = v___x_1008_;
v_isShared_1012_ = v_isSharedCheck_1024_;
goto v_resetjp_1010_;
}
else
{
lean_inc(v_a_1009_);
lean_dec(v___x_1008_);
v___x_1011_ = lean_box(0);
v_isShared_1012_ = v_isSharedCheck_1024_;
goto v_resetjp_1010_;
}
v_resetjp_1010_:
{
lean_object* v___x_1013_; lean_object* v___x_1014_; uint8_t v___x_1015_; 
v___x_1013_ = lean_string_utf8_byte_size(v_a_1009_);
v___x_1014_ = lean_unsigned_to_nat(0u);
v___x_1015_ = lean_nat_dec_eq(v___x_1013_, v___x_1014_);
if (v___x_1015_ == 0)
{
lean_object* v___x_1016_; lean_object* v___x_1017_; 
lean_del_object(v___x_1011_);
v___x_1016_ = l_Lean_Json_parse(v_a_1009_);
v___x_1017_ = l_CostPlanExperiment_orError___redArg(v___x_1016_);
if (lean_obj_tag(v___x_1017_) == 0)
{
lean_object* v_a_1018_; lean_object* v___x_1019_; 
v_a_1018_ = lean_ctor_get(v___x_1017_, 0);
lean_inc(v_a_1018_);
lean_dec_ref_known(v___x_1017_, 1);
v___x_1019_ = l_CostPlanExperiment_handle(v_a_1018_);
v___y_991_ = v___x_1019_;
goto v___jp_990_;
}
else
{
v___y_991_ = v___x_1017_;
goto v___jp_990_;
}
}
else
{
lean_object* v___x_1020_; lean_object* v___x_1022_; 
lean_dec(v_a_1009_);
lean_dec_ref(v___x_982_);
v___x_1020_ = lean_box(0);
if (v_isShared_1012_ == 0)
{
lean_ctor_set(v___x_1011_, 0, v___x_1020_);
v___x_1022_ = v___x_1011_;
goto v_reusejp_1021_;
}
else
{
lean_object* v_reuseFailAlloc_1023_; 
v_reuseFailAlloc_1023_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1023_, 0, v___x_1020_);
v___x_1022_ = v_reuseFailAlloc_1023_;
goto v_reusejp_1021_;
}
v_reusejp_1021_:
{
return v___x_1022_;
}
}
}
}
else
{
lean_object* v_a_1025_; lean_object* v___x_1027_; uint8_t v_isShared_1028_; uint8_t v_isSharedCheck_1032_; 
lean_dec_ref(v___x_982_);
v_a_1025_ = lean_ctor_get(v___x_1008_, 0);
v_isSharedCheck_1032_ = !lean_is_exclusive(v___x_1008_);
if (v_isSharedCheck_1032_ == 0)
{
v___x_1027_ = v___x_1008_;
v_isShared_1028_ = v_isSharedCheck_1032_;
goto v_resetjp_1026_;
}
else
{
lean_inc(v_a_1025_);
lean_dec(v___x_1008_);
v___x_1027_ = lean_box(0);
v_isShared_1028_ = v_isSharedCheck_1032_;
goto v_resetjp_1026_;
}
v_resetjp_1026_:
{
lean_object* v___x_1030_; 
if (v_isShared_1028_ == 0)
{
v___x_1030_ = v___x_1027_;
goto v_reusejp_1029_;
}
else
{
lean_object* v_reuseFailAlloc_1031_; 
v_reuseFailAlloc_1031_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1031_, 0, v_a_1025_);
v___x_1030_ = v_reuseFailAlloc_1031_;
goto v_reusejp_1029_;
}
v_reusejp_1029_:
{
return v___x_1030_;
}
}
}
v___jp_983_:
{
lean_object* v___x_985_; lean_object* v___x_986_; 
v___x_985_ = l_Lean_Json_compress(v_a_984_);
lean_inc_ref(v___x_982_);
v___x_986_ = l_IO_FS_Stream_putStrLn(v___x_982_, v___x_985_);
if (lean_obj_tag(v___x_986_) == 0)
{
lean_object* v_flush_987_; lean_object* v___x_988_; 
lean_dec_ref_known(v___x_986_, 1);
v_flush_987_ = lean_ctor_get(v___x_982_, 0);
lean_inc_ref(v_flush_987_);
lean_dec_ref(v___x_982_);
v___x_988_ = lean_apply_1(v_flush_987_, lean_box(0));
if (lean_obj_tag(v___x_988_) == 0)
{
lean_dec_ref_known(v___x_988_, 1);
goto _start;
}
else
{
return v___x_988_;
}
}
else
{
lean_dec_ref(v___x_982_);
return v___x_986_;
}
}
v___jp_990_:
{
if (lean_obj_tag(v___y_991_) == 0)
{
lean_object* v_a_992_; 
v_a_992_ = lean_ctor_get(v___y_991_, 0);
lean_inc(v_a_992_);
lean_dec_ref_known(v___y_991_, 1);
v_a_984_ = v_a_992_;
goto v___jp_983_;
}
else
{
lean_object* v_a_993_; lean_object* v___x_995_; uint8_t v_isShared_996_; uint8_t v_isSharedCheck_1006_; 
v_a_993_ = lean_ctor_get(v___y_991_, 0);
v_isSharedCheck_1006_ = !lean_is_exclusive(v___y_991_);
if (v_isSharedCheck_1006_ == 0)
{
v___x_995_ = v___y_991_;
v_isShared_996_ = v_isSharedCheck_1006_;
goto v_resetjp_994_;
}
else
{
lean_inc(v_a_993_);
lean_dec(v___y_991_);
v___x_995_ = lean_box(0);
v_isShared_996_ = v_isSharedCheck_1006_;
goto v_resetjp_994_;
}
v_resetjp_994_:
{
lean_object* v___x_997_; lean_object* v___x_998_; lean_object* v___x_1000_; 
v___x_997_ = ((lean_object*)(l_CostPlanExperiment_loop___closed__0));
v___x_998_ = lean_io_error_to_string(v_a_993_);
if (v_isShared_996_ == 0)
{
lean_ctor_set_tag(v___x_995_, 3);
lean_ctor_set(v___x_995_, 0, v___x_998_);
v___x_1000_ = v___x_995_;
goto v_reusejp_999_;
}
else
{
lean_object* v_reuseFailAlloc_1005_; 
v_reuseFailAlloc_1005_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1005_, 0, v___x_998_);
v___x_1000_ = v_reuseFailAlloc_1005_;
goto v_reusejp_999_;
}
v_reusejp_999_:
{
lean_object* v___x_1001_; lean_object* v___x_1002_; lean_object* v___x_1003_; lean_object* v___x_1004_; 
v___x_1001_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1001_, 0, v___x_997_);
lean_ctor_set(v___x_1001_, 1, v___x_1000_);
v___x_1002_ = lean_box(0);
v___x_1003_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1003_, 0, v___x_1001_);
lean_ctor_set(v___x_1003_, 1, v___x_1002_);
v___x_1004_ = l_Lean_Json_mkObj(v___x_1003_);
lean_dec_ref_known(v___x_1003_, 2);
v_a_984_ = v___x_1004_;
goto v___jp_983_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_CostPlanExperiment_loop___boxed(lean_object* v_a_1033_){
_start:
{
lean_object* v_res_1034_; 
v_res_1034_ = l_CostPlanExperiment_loop();
return v_res_1034_;
}
}
LEAN_EXPORT lean_object* _lean_main(){
_start:
{
lean_object* v___x_1037_; lean_object* v___x_1038_; lean_object* v___x_1039_; 
v___x_1037_ = lean_get_stdout();
v___x_1038_ = ((lean_object*)(l_main___closed__0));
lean_inc_ref(v___x_1037_);
v___x_1039_ = l_IO_FS_Stream_putStrLn(v___x_1037_, v___x_1038_);
if (lean_obj_tag(v___x_1039_) == 0)
{
lean_object* v_flush_1040_; lean_object* v___x_1041_; 
lean_dec_ref_known(v___x_1039_, 1);
v_flush_1040_ = lean_ctor_get(v___x_1037_, 0);
lean_inc_ref(v_flush_1040_);
lean_dec_ref(v___x_1037_);
v___x_1041_ = lean_apply_1(v_flush_1040_, lean_box(0));
if (lean_obj_tag(v___x_1041_) == 0)
{
lean_object* v___x_1042_; 
lean_dec_ref_known(v___x_1041_, 1);
v___x_1042_ = l_CostPlanExperiment_loop();
return v___x_1042_;
}
else
{
return v___x_1041_;
}
}
else
{
lean_dec_ref(v___x_1037_);
return v___x_1039_;
}
}
}
LEAN_EXPORT lean_object* l_main___boxed(lean_object* v_a_1043_){
_start:
{
lean_object* v_res_1044_; 
v_res_1044_ = _lean_main();
return v_res_1044_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Generated_Algorithms(uint8_t builtin);
lean_object* initialize_leansort_LeanSort_Verification_CostedPlan_ChecksCost(uint8_t builtin);
lean_object* initialize_Lean(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_experiments_cost_x2dplans_Worker(uint8_t builtin) {
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
res = initialize_Generated_Algorithms(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_leansort_LeanSort_Verification_CostedPlan_ChecksCost(builtin);
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
  res = initialize_experiments_cost_x2dplans_Worker(1 /* builtin */);
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
