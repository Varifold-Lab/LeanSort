// Lean compiler output
// Module: experiments.adaptive.Worker
// Imports: public import Init public meta import Init public import LeanSort.Verification.Adaptive.Correctness public import Lean
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
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* lean_io_mono_nanos_now();
lean_object* lean_st_ref_get(lean_object*);
lean_object* lean_st_ref_set(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lean_nat_div(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
lean_object* l_Nat_decEq___boxed(lean_object*, lean_object*);
lean_object* l_List_eraseDupsBy___redArg(lean_object*, lean_object*);
lean_object* lean_array_get_size(lean_object*);
size_t lean_usize_of_nat(lean_object*);
lean_object* l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_Linter_EnvLinter_formatLinterResults_spec__2(lean_object*, size_t, size_t, lean_object*);
lean_object* lp_cslib_Cslib_Algorithms_Lean_TimeM_tick___redArg(lean_object*);
lean_object* l_List_range(lean_object*);
lean_object* lean_array_fget_borrowed(lean_object*, lean_object*);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
lean_object* l_List_drop___redArg(lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
uint8_t l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(lean_object*, lean_object*);
lean_object* l_List_reverse___redArg(lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* lean_array_mk(lean_object*);
lean_object* l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__0(lean_object*);
lean_object* l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(lean_object*, lean_object*);
lean_object* l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(lean_object*, lean_object*);
lean_object* l_Lean_Json_getObjVal_x3f(lean_object*, lean_object*);
uint8_t l_List_elem___at___00Lean_Meta_Grind_Arith_Cutsat_checkElimEqs_spec__0(lean_object*, lean_object*);
lean_object* lean_get_stdin();
lean_object* lean_get_stdout();
lean_object* l_Lean_Json_compress(lean_object*);
lean_object* l_IO_FS_Stream_putStrLn(lean_object*, lean_object*);
lean_object* lean_io_error_to_string(lean_object*);
lean_object* l_Lean_Json_mkObj(lean_object*);
lean_object* lean_string_utf8_byte_size(lean_object*);
lean_object* l_Lean_Json_parse(lean_object*);
lean_object* l_Lean_Json_getObjValD(lean_object*, lean_object*);
uint8_t l_Option_instBEq_beq___at___00Lean_forEachModuleInDir___at___00Lean_Lsp_ImportCompletion_collectAvailableImportsFromSrcSearchPath_spec__0_spec__0(lean_object*, lean_object*);
lean_object* l_Lean_JsonNumber_fromNat(lean_object*);
lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonStackTable_fromJson_spec__0_spec__0(lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* lean_st_mk_ref(lean_object*);
lean_object* l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(lean_object*);
lean_object* lp_LeanSearchClient_Lean_Json_getObjValAs_x3f___at___00LeanSearchClient_getLoogleQueryJson_spec__4(lean_object*, lean_object*);
uint8_t lp_mathlib_List_beq___at___00__private_Mathlib_Tactic_DefEqAbuse_0__Mathlib_Tactic_DefEqAbuse_isIdenticalSidesStr_spec__4(lean_object*, lean_object*);
static const lean_string_object l_AdaptiveExperiment_featureNames___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "length"};
static const lean_object* l_AdaptiveExperiment_featureNames___closed__0 = (const lean_object*)&l_AdaptiveExperiment_featureNames___closed__0_value;
static const lean_string_object l_AdaptiveExperiment_featureNames___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "descent_permille"};
static const lean_object* l_AdaptiveExperiment_featureNames___closed__1 = (const lean_object*)&l_AdaptiveExperiment_featureNames___closed__1_value;
static const lean_string_object l_AdaptiveExperiment_featureNames___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "ascending_runs"};
static const lean_object* l_AdaptiveExperiment_featureNames___closed__2 = (const lean_object*)&l_AdaptiveExperiment_featureNames___closed__2_value;
static const lean_string_object l_AdaptiveExperiment_featureNames___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "adjacent_equal_permille"};
static const lean_object* l_AdaptiveExperiment_featureNames___closed__3 = (const lean_object*)&l_AdaptiveExperiment_featureNames___closed__3_value;
static const lean_string_object l_AdaptiveExperiment_featureNames___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "value_range"};
static const lean_object* l_AdaptiveExperiment_featureNames___closed__4 = (const lean_object*)&l_AdaptiveExperiment_featureNames___closed__4_value;
static const lean_string_object l_AdaptiveExperiment_featureNames___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "prefix_duplicate_permille"};
static const lean_object* l_AdaptiveExperiment_featureNames___closed__5 = (const lean_object*)&l_AdaptiveExperiment_featureNames___closed__5_value;
static const lean_ctor_object l_AdaptiveExperiment_featureNames___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_featureNames___closed__5_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_AdaptiveExperiment_featureNames___closed__6 = (const lean_object*)&l_AdaptiveExperiment_featureNames___closed__6_value;
static const lean_ctor_object l_AdaptiveExperiment_featureNames___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_featureNames___closed__4_value),((lean_object*)&l_AdaptiveExperiment_featureNames___closed__6_value)}};
static const lean_object* l_AdaptiveExperiment_featureNames___closed__7 = (const lean_object*)&l_AdaptiveExperiment_featureNames___closed__7_value;
static const lean_ctor_object l_AdaptiveExperiment_featureNames___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_featureNames___closed__3_value),((lean_object*)&l_AdaptiveExperiment_featureNames___closed__7_value)}};
static const lean_object* l_AdaptiveExperiment_featureNames___closed__8 = (const lean_object*)&l_AdaptiveExperiment_featureNames___closed__8_value;
static const lean_ctor_object l_AdaptiveExperiment_featureNames___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_featureNames___closed__2_value),((lean_object*)&l_AdaptiveExperiment_featureNames___closed__8_value)}};
static const lean_object* l_AdaptiveExperiment_featureNames___closed__9 = (const lean_object*)&l_AdaptiveExperiment_featureNames___closed__9_value;
static const lean_ctor_object l_AdaptiveExperiment_featureNames___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_featureNames___closed__1_value),((lean_object*)&l_AdaptiveExperiment_featureNames___closed__9_value)}};
static const lean_object* l_AdaptiveExperiment_featureNames___closed__10 = (const lean_object*)&l_AdaptiveExperiment_featureNames___closed__10_value;
static const lean_ctor_object l_AdaptiveExperiment_featureNames___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_featureNames___closed__0_value),((lean_object*)&l_AdaptiveExperiment_featureNames___closed__10_value)}};
static const lean_object* l_AdaptiveExperiment_featureNames___closed__11 = (const lean_object*)&l_AdaptiveExperiment_featureNames___closed__11_value;
LEAN_EXPORT const lean_object* l_AdaptiveExperiment_featureNames = (const lean_object*)&l_AdaptiveExperiment_featureNames___closed__11_value;
static const lean_closure_object l_List_eraseDups___at___00AdaptiveExperiment_features_spec__1___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Nat_decEq___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_List_eraseDups___at___00AdaptiveExperiment_features_spec__1___closed__0 = (const lean_object*)&l_List_eraseDups___at___00AdaptiveExperiment_features_spec__1___closed__0_value;
LEAN_EXPORT lean_object* l_List_eraseDups___at___00AdaptiveExperiment_features_spec__1(lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_features_spec__0___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_features_spec__0___redArg___boxed(lean_object*, lean_object*);
static const lean_array_object l_AdaptiveExperiment_features___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_AdaptiveExperiment_features___closed__0 = (const lean_object*)&l_AdaptiveExperiment_features___closed__0_value;
LEAN_EXPORT lean_object* l_AdaptiveExperiment_features(lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_features_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_features_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_AdaptiveExperiment_planJson___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "kind"};
static const lean_object* l_AdaptiveExperiment_planJson___closed__0 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__0_value;
static const lean_string_object l_AdaptiveExperiment_planJson___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "merge"};
static const lean_object* l_AdaptiveExperiment_planJson___closed__1 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__1_value;
static const lean_ctor_object l_AdaptiveExperiment_planJson___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_planJson___closed__1_value)}};
static const lean_object* l_AdaptiveExperiment_planJson___closed__2 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__2_value;
static const lean_ctor_object l_AdaptiveExperiment_planJson___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_planJson___closed__0_value),((lean_object*)&l_AdaptiveExperiment_planJson___closed__2_value)}};
static const lean_object* l_AdaptiveExperiment_planJson___closed__3 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__3_value;
static const lean_ctor_object l_AdaptiveExperiment_planJson___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_planJson___closed__3_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_AdaptiveExperiment_planJson___closed__4 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__4_value;
static lean_once_cell_t l_AdaptiveExperiment_planJson___closed__5_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_AdaptiveExperiment_planJson___closed__5;
static const lean_string_object l_AdaptiveExperiment_planJson___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "insertion"};
static const lean_object* l_AdaptiveExperiment_planJson___closed__6 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__6_value;
static const lean_ctor_object l_AdaptiveExperiment_planJson___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_planJson___closed__6_value)}};
static const lean_object* l_AdaptiveExperiment_planJson___closed__7 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__7_value;
static const lean_ctor_object l_AdaptiveExperiment_planJson___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_planJson___closed__0_value),((lean_object*)&l_AdaptiveExperiment_planJson___closed__7_value)}};
static const lean_object* l_AdaptiveExperiment_planJson___closed__8 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__8_value;
static const lean_ctor_object l_AdaptiveExperiment_planJson___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_planJson___closed__8_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_AdaptiveExperiment_planJson___closed__9 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__9_value;
static lean_once_cell_t l_AdaptiveExperiment_planJson___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_AdaptiveExperiment_planJson___closed__10;
static const lean_string_object l_AdaptiveExperiment_planJson___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "hybrid"};
static const lean_object* l_AdaptiveExperiment_planJson___closed__11 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__11_value;
static const lean_ctor_object l_AdaptiveExperiment_planJson___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_planJson___closed__11_value)}};
static const lean_object* l_AdaptiveExperiment_planJson___closed__12 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__12_value;
static const lean_ctor_object l_AdaptiveExperiment_planJson___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_planJson___closed__0_value),((lean_object*)&l_AdaptiveExperiment_planJson___closed__12_value)}};
static const lean_object* l_AdaptiveExperiment_planJson___closed__13 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__13_value;
static const lean_string_object l_AdaptiveExperiment_planJson___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "threshold"};
static const lean_object* l_AdaptiveExperiment_planJson___closed__14 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__14_value;
static const lean_string_object l_AdaptiveExperiment_planJson___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "split"};
static const lean_object* l_AdaptiveExperiment_planJson___closed__15 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__15_value;
static const lean_ctor_object l_AdaptiveExperiment_planJson___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_planJson___closed__15_value)}};
static const lean_object* l_AdaptiveExperiment_planJson___closed__16 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__16_value;
static const lean_ctor_object l_AdaptiveExperiment_planJson___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_planJson___closed__0_value),((lean_object*)&l_AdaptiveExperiment_planJson___closed__16_value)}};
static const lean_object* l_AdaptiveExperiment_planJson___closed__17 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__17_value;
static const lean_string_object l_AdaptiveExperiment_planJson___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "cut"};
static const lean_object* l_AdaptiveExperiment_planJson___closed__18 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__18_value;
static const lean_string_object l_AdaptiveExperiment_planJson___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "left"};
static const lean_object* l_AdaptiveExperiment_planJson___closed__19 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__19_value;
static const lean_string_object l_AdaptiveExperiment_planJson___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "right"};
static const lean_object* l_AdaptiveExperiment_planJson___closed__20 = (const lean_object*)&l_AdaptiveExperiment_planJson___closed__20_value;
LEAN_EXPORT lean_object* l_AdaptiveExperiment_planJson(lean_object*);
static const lean_string_object l_AdaptiveExperiment_decodePlan___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "plan nesting limit"};
static const lean_object* l_AdaptiveExperiment_decodePlan___closed__0 = (const lean_object*)&l_AdaptiveExperiment_decodePlan___closed__0_value;
static const lean_ctor_object l_AdaptiveExperiment_decodePlan___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_decodePlan___closed__0_value)}};
static const lean_object* l_AdaptiveExperiment_decodePlan___closed__1 = (const lean_object*)&l_AdaptiveExperiment_decodePlan___closed__1_value;
static const lean_string_object l_AdaptiveExperiment_decodePlan___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "unknown plan"};
static const lean_object* l_AdaptiveExperiment_decodePlan___closed__2 = (const lean_object*)&l_AdaptiveExperiment_decodePlan___closed__2_value;
static const lean_ctor_object l_AdaptiveExperiment_decodePlan___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_decodePlan___closed__2_value)}};
static const lean_object* l_AdaptiveExperiment_decodePlan___closed__3 = (const lean_object*)&l_AdaptiveExperiment_decodePlan___closed__3_value;
static const lean_ctor_object l_AdaptiveExperiment_decodePlan___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(64) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_AdaptiveExperiment_decodePlan___closed__4 = (const lean_object*)&l_AdaptiveExperiment_decodePlan___closed__4_value;
static const lean_ctor_object l_AdaptiveExperiment_decodePlan___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(24) << 1) | 1)),((lean_object*)&l_AdaptiveExperiment_decodePlan___closed__4_value)}};
static const lean_object* l_AdaptiveExperiment_decodePlan___closed__5 = (const lean_object*)&l_AdaptiveExperiment_decodePlan___closed__5_value;
static const lean_ctor_object l_AdaptiveExperiment_decodePlan___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(8) << 1) | 1)),((lean_object*)&l_AdaptiveExperiment_decodePlan___closed__5_value)}};
static const lean_object* l_AdaptiveExperiment_decodePlan___closed__6 = (const lean_object*)&l_AdaptiveExperiment_decodePlan___closed__6_value;
static const lean_ctor_object l_AdaptiveExperiment_decodePlan___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)&l_AdaptiveExperiment_decodePlan___closed__6_value)}};
static const lean_object* l_AdaptiveExperiment_decodePlan___closed__7 = (const lean_object*)&l_AdaptiveExperiment_decodePlan___closed__7_value;
static const lean_string_object l_AdaptiveExperiment_decodePlan___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 22, .m_capacity = 22, .m_length = 21, .m_data = "unsupported threshold"};
static const lean_object* l_AdaptiveExperiment_decodePlan___closed__8 = (const lean_object*)&l_AdaptiveExperiment_decodePlan___closed__8_value;
static const lean_ctor_object l_AdaptiveExperiment_decodePlan___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_decodePlan___closed__8_value)}};
static const lean_object* l_AdaptiveExperiment_decodePlan___closed__9 = (const lean_object*)&l_AdaptiveExperiment_decodePlan___closed__9_value;
static const lean_ctor_object l_AdaptiveExperiment_decodePlan___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* l_AdaptiveExperiment_decodePlan___closed__10 = (const lean_object*)&l_AdaptiveExperiment_decodePlan___closed__10_value;
static const lean_ctor_object l_AdaptiveExperiment_decodePlan___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_AdaptiveExperiment_decodePlan___closed__11 = (const lean_object*)&l_AdaptiveExperiment_decodePlan___closed__11_value;
LEAN_EXPORT lean_object* l_AdaptiveExperiment_decodePlan(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_decodePlan___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_ctorIdx(lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_ctorElim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_ctorElim(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_leaf_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_leaf_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_branch_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_branch_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_predict(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_predict___boxed(lean_object*, lean_object*);
static const lean_string_object l_AdaptiveExperiment_decodeTree___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "tree nesting limit"};
static const lean_object* l_AdaptiveExperiment_decodeTree___closed__0 = (const lean_object*)&l_AdaptiveExperiment_decodeTree___closed__0_value;
static const lean_ctor_object l_AdaptiveExperiment_decodeTree___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_decodeTree___closed__0_value)}};
static const lean_object* l_AdaptiveExperiment_decodeTree___closed__1 = (const lean_object*)&l_AdaptiveExperiment_decodeTree___closed__1_value;
static const lean_string_object l_AdaptiveExperiment_decodeTree___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "leaf"};
static const lean_object* l_AdaptiveExperiment_decodeTree___closed__2 = (const lean_object*)&l_AdaptiveExperiment_decodeTree___closed__2_value;
static const lean_string_object l_AdaptiveExperiment_decodeTree___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "branch"};
static const lean_object* l_AdaptiveExperiment_decodeTree___closed__3 = (const lean_object*)&l_AdaptiveExperiment_decodeTree___closed__3_value;
static const lean_string_object l_AdaptiveExperiment_decodeTree___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "unknown tree node"};
static const lean_object* l_AdaptiveExperiment_decodeTree___closed__4 = (const lean_object*)&l_AdaptiveExperiment_decodeTree___closed__4_value;
static const lean_ctor_object l_AdaptiveExperiment_decodeTree___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_decodeTree___closed__4_value)}};
static const lean_object* l_AdaptiveExperiment_decodeTree___closed__5 = (const lean_object*)&l_AdaptiveExperiment_decodeTree___closed__5_value;
static const lean_string_object l_AdaptiveExperiment_decodeTree___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "feature"};
static const lean_object* l_AdaptiveExperiment_decodeTree___closed__6 = (const lean_object*)&l_AdaptiveExperiment_decodeTree___closed__6_value;
static lean_once_cell_t l_AdaptiveExperiment_decodeTree___closed__7_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_AdaptiveExperiment_decodeTree___closed__7;
static const lean_string_object l_AdaptiveExperiment_decodeTree___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "unknown feature"};
static const lean_object* l_AdaptiveExperiment_decodeTree___closed__8 = (const lean_object*)&l_AdaptiveExperiment_decodeTree___closed__8_value;
static const lean_ctor_object l_AdaptiveExperiment_decodeTree___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_decodeTree___closed__8_value)}};
static const lean_object* l_AdaptiveExperiment_decodeTree___closed__9 = (const lean_object*)&l_AdaptiveExperiment_decodeTree___closed__9_value;
static const lean_string_object l_AdaptiveExperiment_decodeTree___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "plan"};
static const lean_object* l_AdaptiveExperiment_decodeTree___closed__10 = (const lean_object*)&l_AdaptiveExperiment_decodeTree___closed__10_value;
LEAN_EXPORT lean_object* l_AdaptiveExperiment_decodeTree(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_decodeTree___boxed(lean_object*, lean_object*);
static const lean_string_object l_AdaptiveExperiment_decodeModel___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "schema_version"};
static const lean_object* l_AdaptiveExperiment_decodeModel___closed__0 = (const lean_object*)&l_AdaptiveExperiment_decodeModel___closed__0_value;
static const lean_string_object l_AdaptiveExperiment_decodeModel___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "model version"};
static const lean_object* l_AdaptiveExperiment_decodeModel___closed__1 = (const lean_object*)&l_AdaptiveExperiment_decodeModel___closed__1_value;
static const lean_ctor_object l_AdaptiveExperiment_decodeModel___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_decodeModel___closed__1_value)}};
static const lean_object* l_AdaptiveExperiment_decodeModel___closed__2 = (const lean_object*)&l_AdaptiveExperiment_decodeModel___closed__2_value;
static const lean_string_object l_AdaptiveExperiment_decodeModel___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "feature_names"};
static const lean_object* l_AdaptiveExperiment_decodeModel___closed__3 = (const lean_object*)&l_AdaptiveExperiment_decodeModel___closed__3_value;
static const lean_string_object l_AdaptiveExperiment_decodeModel___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 24, .m_capacity = 24, .m_length = 23, .m_data = "feature schema mismatch"};
static const lean_object* l_AdaptiveExperiment_decodeModel___closed__4 = (const lean_object*)&l_AdaptiveExperiment_decodeModel___closed__4_value;
static const lean_ctor_object l_AdaptiveExperiment_decodeModel___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_decodeModel___closed__4_value)}};
static const lean_object* l_AdaptiveExperiment_decodeModel___closed__5 = (const lean_object*)&l_AdaptiveExperiment_decodeModel___closed__5_value;
static const lean_string_object l_AdaptiveExperiment_decodeModel___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "tree"};
static const lean_object* l_AdaptiveExperiment_decodeModel___closed__6 = (const lean_object*)&l_AdaptiveExperiment_decodeModel___closed__6_value;
LEAN_EXPORT lean_object* l_AdaptiveExperiment_decodeModel(lean_object*);
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_planJson___closed__1_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__0 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__0_value;
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_planJson___closed__6_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__1 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__1_value;
static const lean_string_object l_AdaptiveExperiment_candidates___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "hybrid-1"};
static const lean_object* l_AdaptiveExperiment_candidates___closed__2 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__2_value;
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 2}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__3 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__3_value;
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_candidates___closed__2_value),((lean_object*)&l_AdaptiveExperiment_candidates___closed__3_value)}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__4 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__4_value;
static const lean_string_object l_AdaptiveExperiment_candidates___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "hybrid-8"};
static const lean_object* l_AdaptiveExperiment_candidates___closed__5 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__5_value;
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 2}, .m_objs = {((lean_object*)(((size_t)(8) << 1) | 1))}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__6 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__6_value;
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_candidates___closed__5_value),((lean_object*)&l_AdaptiveExperiment_candidates___closed__6_value)}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__7 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__7_value;
static const lean_string_object l_AdaptiveExperiment_candidates___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "hybrid-24"};
static const lean_object* l_AdaptiveExperiment_candidates___closed__8 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__8_value;
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 2}, .m_objs = {((lean_object*)(((size_t)(24) << 1) | 1))}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__9 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__9_value;
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_candidates___closed__8_value),((lean_object*)&l_AdaptiveExperiment_candidates___closed__9_value)}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__10 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__10_value;
static const lean_string_object l_AdaptiveExperiment_candidates___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "hybrid-64"};
static const lean_object* l_AdaptiveExperiment_candidates___closed__11 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__11_value;
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 2}, .m_objs = {((lean_object*)(((size_t)(64) << 1) | 1))}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__12 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__12_value;
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_candidates___closed__11_value),((lean_object*)&l_AdaptiveExperiment_candidates___closed__12_value)}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__13 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__13_value;
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_candidates___closed__13_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__14 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__14_value;
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_candidates___closed__10_value),((lean_object*)&l_AdaptiveExperiment_candidates___closed__14_value)}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__15 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__15_value;
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_candidates___closed__7_value),((lean_object*)&l_AdaptiveExperiment_candidates___closed__15_value)}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__16 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__16_value;
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_candidates___closed__4_value),((lean_object*)&l_AdaptiveExperiment_candidates___closed__16_value)}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__17 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__17_value;
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_candidates___closed__1_value),((lean_object*)&l_AdaptiveExperiment_candidates___closed__17_value)}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__18 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__18_value;
static const lean_ctor_object l_AdaptiveExperiment_candidates___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_candidates___closed__0_value),((lean_object*)&l_AdaptiveExperiment_candidates___closed__18_value)}};
static const lean_object* l_AdaptiveExperiment_candidates___closed__19 = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__19_value;
LEAN_EXPORT const lean_object* l_AdaptiveExperiment_candidates = (const lean_object*)&l_AdaptiveExperiment_candidates___closed__19_value;
LEAN_EXPORT lean_object* l_AdaptiveExperiment_manual(lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_manual___boxed(lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_ctorIdx(lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_ctorIdx___boxed(lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_ctorElim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_ctorElim(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_ctorElim___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_fixed_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_fixed_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_rule_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_rule_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_learned_elim___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_learned_elim(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_choose(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_pure___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__8___redArg(lean_object*);
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_bind___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__9___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___lam__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___closed__0;
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___lam__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Insertion_insertTr___at___00LeanSort_Insertion_sortTr___at___00LeanSort_Insertion_insertionSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__3_spec__5_spec__6(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Insertion_sortTr___at___00LeanSort_Insertion_insertionSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__3_spec__5(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Insertion_insertionSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__3(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_HybridMerge_sort___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__4(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_HybridMerge_sort___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__4___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_mergeSort___at___00LeanSort_Merge_mergeSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__2_spec__3___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_mergeSort___at___00LeanSort_Merge_mergeSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__2_spec__3(lean_object*);
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_mergeSort___at___00LeanSort_Merge_mergeSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__2_spec__3___lam__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Merge_mergeSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__2(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_run(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_pure___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__8(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_bind___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__9(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_foldl___at___00AdaptiveExperiment_checksum_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_foldl___at___00AdaptiveExperiment_checksum_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_checksum(lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_checksum___boxed(lean_object*);
static const lean_string_object l_AdaptiveExperiment_checkedRun___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "incorrect sorting output"};
static const lean_object* l_AdaptiveExperiment_checkedRun___closed__0 = (const lean_object*)&l_AdaptiveExperiment_checkedRun___closed__0_value;
static const lean_ctor_object l_AdaptiveExperiment_checkedRun___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_checkedRun___closed__0_value)}};
static const lean_object* l_AdaptiveExperiment_checkedRun___closed__1 = (const lean_object*)&l_AdaptiveExperiment_checkedRun___closed__1_value;
LEAN_EXPORT lean_object* l_AdaptiveExperiment_checkedRun(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_checkedRun___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_timedFeatures(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_timedFeatures___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__5___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__5___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__3(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00AdaptiveExperiment_benchmark_spec__0(lean_object*);
static const lean_string_object l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__7___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "strategy"};
static const lean_object* l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__7___closed__0 = (const lean_object*)&l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__7___closed__0_value;
static const lean_string_object l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__7___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "samples_ns"};
static const lean_object* l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__7___closed__1 = (const lean_object*)&l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__7___closed__1_value;
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__7(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__1(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__2___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__2___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4_spec__4___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4_spec__4___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6___redArg___closed__0_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_benchmark(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_benchmark___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__5(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__5___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4_spec__4(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4_spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00AdaptiveExperiment_getInput_spec__0_spec__0(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00AdaptiveExperiment_getInput_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00AdaptiveExperiment_getInput_spec__0___boxed(lean_object*, lean_object*);
static const lean_string_object l_AdaptiveExperiment_getInput___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "input"};
static const lean_object* l_AdaptiveExperiment_getInput___closed__0 = (const lean_object*)&l_AdaptiveExperiment_getInput___closed__0_value;
LEAN_EXPORT lean_object* l_AdaptiveExperiment_getInput(lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_orError___redArg(lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_orError___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_orError(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_orError___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_handle_spec__1___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_handle_spec__1___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00AdaptiveExperiment_handle_spec__0(lean_object*, lean_object*);
static const lean_string_object l_AdaptiveExperiment_handle___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "manual_plan"};
static const lean_object* l_AdaptiveExperiment_handle___closed__0 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__0_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "all_outputs_correct"};
static const lean_object* l_AdaptiveExperiment_handle___closed__1 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__1_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "cmd"};
static const lean_object* l_AdaptiveExperiment_handle___closed__2 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__2_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "predict"};
static const lean_object* l_AdaptiveExperiment_handle___closed__3 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__3_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "execute"};
static const lean_object* l_AdaptiveExperiment_handle___closed__4 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__4_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "measure"};
static const lean_object* l_AdaptiveExperiment_handle___closed__5 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__5_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "unknown command"};
static const lean_object* l_AdaptiveExperiment_handle___closed__6 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__6_value;
static const lean_ctor_object l_AdaptiveExperiment_handle___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_handle___closed__6_value)}};
static const lean_object* l_AdaptiveExperiment_handle___closed__7 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__7_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "expected"};
static const lean_object* l_AdaptiveExperiment_handle___closed__8 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__8_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "rounds"};
static const lean_object* l_AdaptiveExperiment_handle___closed__9 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__9_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "inner"};
static const lean_object* l_AdaptiveExperiment_handle___closed__10 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__10_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "invalid repetition count"};
static const lean_object* l_AdaptiveExperiment_handle___closed__11 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__11_value;
static const lean_ctor_object l_AdaptiveExperiment_handle___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_handle___closed__11_value)}};
static const lean_object* l_AdaptiveExperiment_handle___closed__12 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__12_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "features"};
static const lean_object* l_AdaptiveExperiment_handle___closed__13 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__13_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "measurements"};
static const lean_object* l_AdaptiveExperiment_handle___closed__14 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__14_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 19, .m_capacity = 19, .m_length = 18, .m_data = "feature_samples_ns"};
static const lean_object* l_AdaptiveExperiment_handle___closed__15 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__15_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "tree_plan"};
static const lean_object* l_AdaptiveExperiment_handle___closed__16 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__16_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "order_seed"};
static const lean_object* l_AdaptiveExperiment_handle___closed__17 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__17_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "invalid stage"};
static const lean_object* l_AdaptiveExperiment_handle___closed__18 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__18_value;
static const lean_ctor_object l_AdaptiveExperiment_handle___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_handle___closed__18_value)}};
static const lean_object* l_AdaptiveExperiment_handle___closed__19 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__19_value;
static lean_once_cell_t l_AdaptiveExperiment_handle___closed__20_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_AdaptiveExperiment_handle___closed__20;
static const lean_string_object l_AdaptiveExperiment_handle___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "test"};
static const lean_object* l_AdaptiveExperiment_handle___closed__21 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__21_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "best_fixed"};
static const lean_object* l_AdaptiveExperiment_handle___closed__22 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__22_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "manual_rule"};
static const lean_object* l_AdaptiveExperiment_handle___closed__23 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__23_value;
static const lean_ctor_object l_AdaptiveExperiment_handle___closed__24_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_handle___closed__23_value),((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* l_AdaptiveExperiment_handle___closed__24 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__24_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__25_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "decision_tree"};
static const lean_object* l_AdaptiveExperiment_handle___closed__25 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__25_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__26_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "tree_plan_only"};
static const lean_object* l_AdaptiveExperiment_handle___closed__26 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__26_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__27_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "stage"};
static const lean_object* l_AdaptiveExperiment_handle___closed__27 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__27_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__28_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "train"};
static const lean_object* l_AdaptiveExperiment_handle___closed__28 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__28_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__29_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "fallback"};
static const lean_object* l_AdaptiveExperiment_handle___closed__29 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__29_value;
static const lean_string_object l_AdaptiveExperiment_handle___closed__30_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "output"};
static const lean_object* l_AdaptiveExperiment_handle___closed__30 = (const lean_object*)&l_AdaptiveExperiment_handle___closed__30_value;
LEAN_EXPORT lean_object* l_AdaptiveExperiment_handle(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_handle___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_handle_spec__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_handle_spec__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_AdaptiveExperiment_loop___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "error"};
static const lean_object* l_AdaptiveExperiment_loop___closed__0 = (const lean_object*)&l_AdaptiveExperiment_loop___closed__0_value;
static const lean_string_object l_AdaptiveExperiment_loop___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "reason"};
static const lean_object* l_AdaptiveExperiment_loop___closed__1 = (const lean_object*)&l_AdaptiveExperiment_loop___closed__1_value;
static const lean_string_object l_AdaptiveExperiment_loop___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 1, .m_capacity = 1, .m_length = 0, .m_data = ""};
static const lean_object* l_AdaptiveExperiment_loop___closed__2 = (const lean_object*)&l_AdaptiveExperiment_loop___closed__2_value;
static const lean_string_object l_AdaptiveExperiment_loop___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "accepted"};
static const lean_object* l_AdaptiveExperiment_loop___closed__3 = (const lean_object*)&l_AdaptiveExperiment_loop___closed__3_value;
static const lean_string_object l_AdaptiveExperiment_loop___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "configure"};
static const lean_object* l_AdaptiveExperiment_loop___closed__4 = (const lean_object*)&l_AdaptiveExperiment_loop___closed__4_value;
static const lean_ctor_object l_AdaptiveExperiment_loop___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)&l_AdaptiveExperiment_loop___closed__4_value)}};
static const lean_object* l_AdaptiveExperiment_loop___closed__5 = (const lean_object*)&l_AdaptiveExperiment_loop___closed__5_value;
static const lean_string_object l_AdaptiveExperiment_loop___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "model"};
static const lean_object* l_AdaptiveExperiment_loop___closed__6 = (const lean_object*)&l_AdaptiveExperiment_loop___closed__6_value;
LEAN_EXPORT lean_object* l_AdaptiveExperiment_loop(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_AdaptiveExperiment_loop___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object l_main___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 56, .m_capacity = 56, .m_length = 55, .m_data = "{\"ready\":true,\"backend\":\"lean--run\",\"schema_version\":1}"};
static const lean_object* l_main___closed__0 = (const lean_object*)&l_main___closed__0_value;
LEAN_EXPORT lean_object* _lean_main();
LEAN_EXPORT lean_object* l_main___boxed(lean_object*);
LEAN_EXPORT lean_object* l_List_eraseDups___at___00AdaptiveExperiment_features_spec__1(lean_object* v_as_27_){
_start:
{
lean_object* v___f_28_; lean_object* v___x_29_; 
v___f_28_ = ((lean_object*)(l_List_eraseDups___at___00AdaptiveExperiment_features_spec__1___closed__0));
v___x_29_ = l_List_eraseDupsBy___redArg(v___f_28_, v_as_27_);
return v___x_29_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_features_spec__0___redArg(lean_object* v_as_x27_30_, lean_object* v_b_31_){
_start:
{
if (lean_obj_tag(v_as_x27_30_) == 0)
{
return v_b_31_;
}
else
{
lean_object* v_head_32_; lean_object* v_tail_33_; lean_object* v___y_35_; lean_object* v___y_36_; lean_object* v___y_37_; lean_object* v___y_38_; lean_object* v___y_39_; lean_object* v_snd_47_; lean_object* v_snd_48_; lean_object* v_snd_49_; lean_object* v_snd_50_; lean_object* v_fst_51_; lean_object* v_fst_52_; lean_object* v_fst_53_; lean_object* v_fst_54_; lean_object* v_fst_55_; lean_object* v_snd_56_; lean_object* v___y_58_; lean_object* v___y_59_; lean_object* v___y_60_; lean_object* v___y_61_; lean_object* v_down_64_; lean_object* v_equal_65_; 
v_head_32_ = lean_ctor_get(v_as_x27_30_, 0);
v_tail_33_ = lean_ctor_get(v_as_x27_30_, 1);
v_snd_47_ = lean_ctor_get(v_b_31_, 1);
lean_inc(v_snd_47_);
v_snd_48_ = lean_ctor_get(v_snd_47_, 1);
lean_inc(v_snd_48_);
v_snd_49_ = lean_ctor_get(v_snd_48_, 1);
lean_inc(v_snd_49_);
v_snd_50_ = lean_ctor_get(v_snd_49_, 1);
lean_inc(v_snd_50_);
v_fst_51_ = lean_ctor_get(v_b_31_, 0);
lean_inc(v_fst_51_);
lean_dec_ref(v_b_31_);
v_fst_52_ = lean_ctor_get(v_snd_47_, 0);
lean_inc(v_fst_52_);
lean_dec(v_snd_47_);
v_fst_53_ = lean_ctor_get(v_snd_48_, 0);
lean_inc(v_fst_53_);
lean_dec(v_snd_48_);
v_fst_54_ = lean_ctor_get(v_snd_49_, 0);
lean_inc(v_fst_54_);
lean_dec(v_snd_49_);
v_fst_55_ = lean_ctor_get(v_snd_50_, 0);
lean_inc(v_fst_55_);
v_snd_56_ = lean_ctor_get(v_snd_50_, 1);
lean_inc(v_snd_56_);
lean_dec(v_snd_50_);
if (lean_obj_tag(v_snd_56_) == 1)
{
lean_object* v_val_69_; lean_object* v_down_71_; uint8_t v___x_75_; 
v_val_69_ = lean_ctor_get(v_snd_56_, 0);
lean_inc(v_val_69_);
lean_dec_ref_known(v_snd_56_, 1);
v___x_75_ = lean_nat_dec_lt(v_head_32_, v_val_69_);
if (v___x_75_ == 0)
{
v_down_71_ = v_fst_52_;
goto v___jp_70_;
}
else
{
lean_object* v___x_76_; lean_object* v___x_77_; 
v___x_76_ = lean_unsigned_to_nat(1u);
v___x_77_ = lean_nat_add(v_fst_52_, v___x_76_);
lean_dec(v_fst_52_);
v_down_71_ = v___x_77_;
goto v___jp_70_;
}
v___jp_70_:
{
uint8_t v___x_72_; 
v___x_72_ = lean_nat_dec_eq(v_val_69_, v_head_32_);
lean_dec(v_val_69_);
if (v___x_72_ == 0)
{
v_down_64_ = v_down_71_;
v_equal_65_ = v_fst_53_;
goto v___jp_63_;
}
else
{
lean_object* v___x_73_; lean_object* v___x_74_; 
v___x_73_ = lean_unsigned_to_nat(1u);
v___x_74_ = lean_nat_add(v_fst_53_, v___x_73_);
lean_dec(v_fst_53_);
v_down_64_ = v_down_71_;
v_equal_65_ = v___x_74_;
goto v___jp_63_;
}
}
}
else
{
lean_dec(v_snd_56_);
v_down_64_ = v_fst_52_;
v_equal_65_ = v_fst_53_;
goto v___jp_63_;
}
v___jp_34_:
{
lean_object* v___x_40_; lean_object* v___x_41_; lean_object* v___x_42_; lean_object* v___x_43_; lean_object* v___x_44_; lean_object* v___x_45_; 
lean_inc(v_head_32_);
v___x_40_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_40_, 0, v_head_32_);
v___x_41_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_41_, 0, v___y_39_);
lean_ctor_set(v___x_41_, 1, v___x_40_);
v___x_42_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_42_, 0, v___y_35_);
lean_ctor_set(v___x_42_, 1, v___x_41_);
v___x_43_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_43_, 0, v___y_36_);
lean_ctor_set(v___x_43_, 1, v___x_42_);
v___x_44_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_44_, 0, v___y_37_);
lean_ctor_set(v___x_44_, 1, v___x_43_);
v___x_45_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_45_, 0, v___y_38_);
lean_ctor_set(v___x_45_, 1, v___x_44_);
v_as_x27_30_ = v_tail_33_;
v_b_31_ = v___x_45_;
goto _start;
}
v___jp_57_:
{
uint8_t v___x_62_; 
v___x_62_ = lean_nat_dec_le(v_fst_55_, v_head_32_);
if (v___x_62_ == 0)
{
v___y_35_ = v___y_61_;
v___y_36_ = v___y_58_;
v___y_37_ = v___y_59_;
v___y_38_ = v___y_60_;
v___y_39_ = v_fst_55_;
goto v___jp_34_;
}
else
{
lean_dec(v_fst_55_);
lean_inc(v_head_32_);
v___y_35_ = v___y_61_;
v___y_36_ = v___y_58_;
v___y_37_ = v___y_59_;
v___y_38_ = v___y_60_;
v___y_39_ = v_head_32_;
goto v___jp_34_;
}
}
v___jp_63_:
{
lean_object* v___x_66_; lean_object* v___x_67_; uint8_t v___x_68_; 
v___x_66_ = lean_unsigned_to_nat(1u);
v___x_67_ = lean_nat_add(v_fst_51_, v___x_66_);
lean_dec(v_fst_51_);
v___x_68_ = lean_nat_dec_le(v_fst_54_, v_head_32_);
if (v___x_68_ == 0)
{
lean_dec(v_fst_54_);
lean_inc(v_head_32_);
v___y_58_ = v_equal_65_;
v___y_59_ = v_down_64_;
v___y_60_ = v___x_67_;
v___y_61_ = v_head_32_;
goto v___jp_57_;
}
else
{
v___y_58_ = v_equal_65_;
v___y_59_ = v_down_64_;
v___y_60_ = v___x_67_;
v___y_61_ = v_fst_54_;
goto v___jp_57_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_features_spec__0___redArg___boxed(lean_object* v_as_x27_78_, lean_object* v_b_79_){
_start:
{
lean_object* v_res_80_; 
v_res_80_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_features_spec__0___redArg(v_as_x27_78_, v_b_79_);
lean_dec(v_as_x27_78_);
return v_res_80_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_features(lean_object* v_xs_83_){
_start:
{
lean_object* v___y_85_; lean_object* v___y_86_; lean_object* v___y_87_; lean_object* v___y_88_; lean_object* v___y_89_; lean_object* v___y_90_; lean_object* v___y_91_; lean_object* v___y_102_; lean_object* v___y_103_; lean_object* v___y_104_; lean_object* v___y_105_; lean_object* v___y_106_; lean_object* v___y_107_; lean_object* v___y_108_; lean_object* v___y_109_; lean_object* v___y_110_; lean_object* v___y_111_; lean_object* v___y_112_; lean_object* v_n_118_; lean_object* v___y_120_; lean_object* v___y_121_; lean_object* v___y_122_; lean_object* v___y_123_; lean_object* v___y_124_; lean_object* v___y_125_; lean_object* v___y_126_; lean_object* v___y_127_; lean_object* v___y_128_; lean_object* v___y_129_; lean_object* v___y_130_; lean_object* v___y_135_; 
v_n_118_ = lean_unsigned_to_nat(0u);
if (lean_obj_tag(v_xs_83_) == 0)
{
v___y_135_ = v_n_118_;
goto v___jp_134_;
}
else
{
lean_object* v_head_164_; 
v_head_164_ = lean_ctor_get(v_xs_83_, 0);
lean_inc(v_head_164_);
v___y_135_ = v_head_164_;
goto v___jp_134_;
}
v___jp_84_:
{
lean_object* v___x_92_; lean_object* v___x_93_; lean_object* v___x_94_; lean_object* v___x_95_; lean_object* v___x_96_; lean_object* v___x_97_; lean_object* v___x_98_; lean_object* v___x_99_; lean_object* v___x_100_; 
v___x_92_ = lean_nat_div(v___y_88_, v___y_91_);
lean_dec(v___y_91_);
lean_dec(v___y_88_);
v___x_93_ = lean_unsigned_to_nat(6u);
v___x_94_ = lean_mk_empty_array_with_capacity(v___x_93_);
v___x_95_ = lean_array_push(v___x_94_, v___y_86_);
v___x_96_ = lean_array_push(v___x_95_, v___y_87_);
v___x_97_ = lean_array_push(v___x_96_, v___y_90_);
v___x_98_ = lean_array_push(v___x_97_, v___y_89_);
v___x_99_ = lean_array_push(v___x_98_, v___y_85_);
v___x_100_ = lean_array_push(v___x_99_, v___x_92_);
return v___x_100_;
}
v___jp_101_:
{
lean_object* v___x_113_; lean_object* v___x_114_; lean_object* v___x_115_; lean_object* v___x_116_; uint8_t v___x_117_; 
v___x_113_ = lean_nat_mul(v___y_111_, v___y_107_);
lean_dec(v___y_107_);
v___x_114_ = lean_nat_div(v___x_113_, v___y_106_);
lean_dec(v___y_106_);
lean_dec(v___x_113_);
v___x_115_ = lean_nat_sub(v___y_110_, v___y_104_);
lean_dec(v___y_104_);
lean_dec(v___y_110_);
v___x_116_ = lean_nat_mul(v___y_111_, v___y_102_);
lean_dec(v___y_102_);
v___x_117_ = lean_nat_dec_le(v___y_103_, v___y_109_);
if (v___x_117_ == 0)
{
lean_dec(v___y_109_);
v___y_85_ = v___x_115_;
v___y_86_ = v___y_105_;
v___y_87_ = v___y_108_;
v___y_88_ = v___x_116_;
v___y_89_ = v___x_114_;
v___y_90_ = v___y_112_;
v___y_91_ = v___y_103_;
goto v___jp_84_;
}
else
{
lean_dec(v___y_103_);
v___y_85_ = v___x_115_;
v___y_86_ = v___y_105_;
v___y_87_ = v___y_108_;
v___y_88_ = v___x_116_;
v___y_89_ = v___x_114_;
v___y_90_ = v___y_112_;
v___y_91_ = v___y_109_;
goto v___jp_84_;
}
}
v___jp_119_:
{
lean_object* v___x_131_; uint8_t v___x_132_; 
v___x_131_ = lean_nat_div(v___y_124_, v___y_130_);
lean_dec(v___y_124_);
v___x_132_ = lean_nat_dec_eq(v___y_123_, v_n_118_);
if (v___x_132_ == 0)
{
lean_object* v___x_133_; 
v___x_133_ = lean_nat_add(v___y_125_, v___y_122_);
lean_dec(v___y_125_);
v___y_102_ = v___y_120_;
v___y_103_ = v___y_122_;
v___y_104_ = v___y_121_;
v___y_105_ = v___y_123_;
v___y_106_ = v___y_130_;
v___y_107_ = v___y_126_;
v___y_108_ = v___x_131_;
v___y_109_ = v___y_128_;
v___y_110_ = v___y_127_;
v___y_111_ = v___y_129_;
v___y_112_ = v___x_133_;
goto v___jp_101_;
}
else
{
lean_dec(v___y_125_);
v___y_102_ = v___y_120_;
v___y_103_ = v___y_122_;
v___y_104_ = v___y_121_;
v___y_105_ = v___y_123_;
v___y_106_ = v___y_130_;
v___y_107_ = v___y_126_;
v___y_108_ = v___x_131_;
v___y_109_ = v___y_128_;
v___y_110_ = v___y_127_;
v___y_111_ = v___y_129_;
v___y_112_ = v_n_118_;
goto v___jp_101_;
}
}
v___jp_134_:
{
lean_object* v_previous_136_; lean_object* v___x_137_; lean_object* v___x_138_; lean_object* v___x_139_; lean_object* v___x_140_; lean_object* v___x_141_; lean_object* v___x_142_; lean_object* v_snd_143_; lean_object* v_snd_144_; lean_object* v_snd_145_; lean_object* v_snd_146_; lean_object* v_fst_147_; lean_object* v_fst_148_; lean_object* v_fst_149_; lean_object* v_fst_150_; lean_object* v_fst_151_; lean_object* v___x_152_; lean_object* v___x_153_; lean_object* v___x_154_; lean_object* v___x_155_; lean_object* v___x_156_; lean_object* v___x_157_; lean_object* v___x_158_; lean_object* v___x_159_; lean_object* v___x_160_; lean_object* v___x_161_; lean_object* v___x_162_; uint8_t v___x_163_; 
v_previous_136_ = lean_box(0);
lean_inc(v___y_135_);
v___x_137_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_137_, 0, v___y_135_);
lean_ctor_set(v___x_137_, 1, v_previous_136_);
v___x_138_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_138_, 0, v___y_135_);
lean_ctor_set(v___x_138_, 1, v___x_137_);
v___x_139_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_139_, 0, v_n_118_);
lean_ctor_set(v___x_139_, 1, v___x_138_);
v___x_140_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_140_, 0, v_n_118_);
lean_ctor_set(v___x_140_, 1, v___x_139_);
v___x_141_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_141_, 0, v_n_118_);
lean_ctor_set(v___x_141_, 1, v___x_140_);
v___x_142_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_features_spec__0___redArg(v_xs_83_, v___x_141_);
v_snd_143_ = lean_ctor_get(v___x_142_, 1);
lean_inc(v_snd_143_);
v_snd_144_ = lean_ctor_get(v_snd_143_, 1);
lean_inc(v_snd_144_);
v_snd_145_ = lean_ctor_get(v_snd_144_, 1);
lean_inc(v_snd_145_);
v_snd_146_ = lean_ctor_get(v_snd_145_, 1);
lean_inc(v_snd_146_);
v_fst_147_ = lean_ctor_get(v___x_142_, 0);
lean_inc(v_fst_147_);
lean_dec_ref(v___x_142_);
v_fst_148_ = lean_ctor_get(v_snd_143_, 0);
lean_inc(v_fst_148_);
lean_dec(v_snd_143_);
v_fst_149_ = lean_ctor_get(v_snd_144_, 0);
lean_inc(v_fst_149_);
lean_dec(v_snd_144_);
v_fst_150_ = lean_ctor_get(v_snd_145_, 0);
lean_inc(v_fst_150_);
lean_dec(v_snd_145_);
v_fst_151_ = lean_ctor_get(v_snd_146_, 0);
lean_inc(v_fst_151_);
lean_dec(v_snd_146_);
v___x_152_ = lean_unsigned_to_nat(32u);
v___x_153_ = ((lean_object*)(l_AdaptiveExperiment_features___closed__0));
lean_inc(v_xs_83_);
v___x_154_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_xs_83_, v_xs_83_, v___x_152_, v___x_153_);
lean_dec(v_xs_83_);
v___x_155_ = l_List_lengthTR___redArg(v___x_154_);
v___x_156_ = l_List_eraseDups___at___00AdaptiveExperiment_features_spec__1(v___x_154_);
v___x_157_ = l_List_lengthTR___redArg(v___x_156_);
lean_dec(v___x_156_);
v___x_158_ = lean_nat_sub(v___x_155_, v___x_157_);
lean_dec(v___x_157_);
v___x_159_ = lean_unsigned_to_nat(1000u);
v___x_160_ = lean_nat_mul(v___x_159_, v_fst_148_);
v___x_161_ = lean_unsigned_to_nat(1u);
v___x_162_ = lean_nat_sub(v_fst_147_, v___x_161_);
v___x_163_ = lean_nat_dec_le(v___x_161_, v___x_162_);
if (v___x_163_ == 0)
{
lean_dec(v___x_162_);
v___y_120_ = v___x_158_;
v___y_121_ = v_fst_150_;
v___y_122_ = v___x_161_;
v___y_123_ = v_fst_147_;
v___y_124_ = v___x_160_;
v___y_125_ = v_fst_148_;
v___y_126_ = v_fst_149_;
v___y_127_ = v_fst_151_;
v___y_128_ = v___x_155_;
v___y_129_ = v___x_159_;
v___y_130_ = v___x_161_;
goto v___jp_119_;
}
else
{
v___y_120_ = v___x_158_;
v___y_121_ = v_fst_150_;
v___y_122_ = v___x_161_;
v___y_123_ = v_fst_147_;
v___y_124_ = v___x_160_;
v___y_125_ = v_fst_148_;
v___y_126_ = v_fst_149_;
v___y_127_ = v_fst_151_;
v___y_128_ = v___x_155_;
v___y_129_ = v___x_159_;
v___y_130_ = v___x_162_;
goto v___jp_119_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_features_spec__0(lean_object* v_as_165_, lean_object* v_as_x27_166_, lean_object* v_b_167_, lean_object* v_a_168_){
_start:
{
lean_object* v___x_169_; 
v___x_169_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_features_spec__0___redArg(v_as_x27_166_, v_b_167_);
return v___x_169_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_features_spec__0___boxed(lean_object* v_as_170_, lean_object* v_as_x27_171_, lean_object* v_b_172_, lean_object* v_a_173_){
_start:
{
lean_object* v_res_174_; 
v_res_174_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_features_spec__0(v_as_170_, v_as_x27_171_, v_b_172_, v_a_173_);
lean_dec(v_as_x27_171_);
lean_dec(v_as_170_);
return v_res_174_;
}
}
static lean_object* _init_l_AdaptiveExperiment_planJson___closed__5(void){
_start:
{
lean_object* v___x_185_; lean_object* v___x_186_; 
v___x_185_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__4));
v___x_186_ = l_Lean_Json_mkObj(v___x_185_);
return v___x_186_;
}
}
static lean_object* _init_l_AdaptiveExperiment_planJson___closed__10(void){
_start:
{
lean_object* v___x_196_; lean_object* v___x_197_; 
v___x_196_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__9));
v___x_197_ = l_Lean_Json_mkObj(v___x_196_);
return v___x_197_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_planJson(lean_object* v_x_214_){
_start:
{
switch(lean_obj_tag(v_x_214_))
{
case 0:
{
lean_object* v___x_215_; 
v___x_215_ = lean_obj_once(&l_AdaptiveExperiment_planJson___closed__5, &l_AdaptiveExperiment_planJson___closed__5_once, _init_l_AdaptiveExperiment_planJson___closed__5);
return v___x_215_;
}
case 1:
{
lean_object* v___x_216_; 
v___x_216_ = lean_obj_once(&l_AdaptiveExperiment_planJson___closed__10, &l_AdaptiveExperiment_planJson___closed__10_once, _init_l_AdaptiveExperiment_planJson___closed__10);
return v___x_216_;
}
case 2:
{
lean_object* v_threshold_217_; lean_object* v___x_219_; uint8_t v_isShared_220_; uint8_t v_isSharedCheck_232_; 
v_threshold_217_ = lean_ctor_get(v_x_214_, 0);
v_isSharedCheck_232_ = !lean_is_exclusive(v_x_214_);
if (v_isSharedCheck_232_ == 0)
{
v___x_219_ = v_x_214_;
v_isShared_220_ = v_isSharedCheck_232_;
goto v_resetjp_218_;
}
else
{
lean_inc(v_threshold_217_);
lean_dec(v_x_214_);
v___x_219_ = lean_box(0);
v_isShared_220_ = v_isSharedCheck_232_;
goto v_resetjp_218_;
}
v_resetjp_218_:
{
lean_object* v___x_221_; lean_object* v___x_222_; lean_object* v___x_223_; lean_object* v___x_225_; 
v___x_221_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__13));
v___x_222_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__14));
v___x_223_ = l_Lean_JsonNumber_fromNat(v_threshold_217_);
if (v_isShared_220_ == 0)
{
lean_ctor_set(v___x_219_, 0, v___x_223_);
v___x_225_ = v___x_219_;
goto v_reusejp_224_;
}
else
{
lean_object* v_reuseFailAlloc_231_; 
v_reuseFailAlloc_231_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_231_, 0, v___x_223_);
v___x_225_ = v_reuseFailAlloc_231_;
goto v_reusejp_224_;
}
v_reusejp_224_:
{
lean_object* v___x_226_; lean_object* v___x_227_; lean_object* v___x_228_; lean_object* v___x_229_; lean_object* v___x_230_; 
v___x_226_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_226_, 0, v___x_222_);
lean_ctor_set(v___x_226_, 1, v___x_225_);
v___x_227_ = lean_box(0);
v___x_228_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_228_, 0, v___x_226_);
lean_ctor_set(v___x_228_, 1, v___x_227_);
v___x_229_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_229_, 0, v___x_221_);
lean_ctor_set(v___x_229_, 1, v___x_228_);
v___x_230_ = l_Lean_Json_mkObj(v___x_229_);
lean_dec_ref_known(v___x_229_, 2);
return v___x_230_;
}
}
}
default: 
{
lean_object* v_cut_233_; lean_object* v_left_234_; lean_object* v_right_235_; lean_object* v___x_236_; lean_object* v___x_237_; lean_object* v___x_238_; lean_object* v___x_239_; lean_object* v___x_240_; lean_object* v___x_241_; lean_object* v___x_242_; lean_object* v___x_243_; lean_object* v___x_244_; lean_object* v___x_245_; lean_object* v___x_246_; lean_object* v___x_247_; lean_object* v___x_248_; lean_object* v___x_249_; lean_object* v___x_250_; lean_object* v___x_251_; lean_object* v___x_252_; 
v_cut_233_ = lean_ctor_get(v_x_214_, 0);
lean_inc(v_cut_233_);
v_left_234_ = lean_ctor_get(v_x_214_, 1);
lean_inc(v_left_234_);
v_right_235_ = lean_ctor_get(v_x_214_, 2);
lean_inc(v_right_235_);
lean_dec_ref_known(v_x_214_, 3);
v___x_236_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__17));
v___x_237_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__18));
v___x_238_ = l_Lean_JsonNumber_fromNat(v_cut_233_);
v___x_239_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_239_, 0, v___x_238_);
v___x_240_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_240_, 0, v___x_237_);
lean_ctor_set(v___x_240_, 1, v___x_239_);
v___x_241_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__19));
v___x_242_ = l_AdaptiveExperiment_planJson(v_left_234_);
v___x_243_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_243_, 0, v___x_241_);
lean_ctor_set(v___x_243_, 1, v___x_242_);
v___x_244_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__20));
v___x_245_ = l_AdaptiveExperiment_planJson(v_right_235_);
v___x_246_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_246_, 0, v___x_244_);
lean_ctor_set(v___x_246_, 1, v___x_245_);
v___x_247_ = lean_box(0);
v___x_248_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_248_, 0, v___x_246_);
lean_ctor_set(v___x_248_, 1, v___x_247_);
v___x_249_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_249_, 0, v___x_243_);
lean_ctor_set(v___x_249_, 1, v___x_248_);
v___x_250_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_250_, 0, v___x_240_);
lean_ctor_set(v___x_250_, 1, v___x_249_);
v___x_251_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_251_, 0, v___x_236_);
lean_ctor_set(v___x_251_, 1, v___x_250_);
v___x_252_ = l_Lean_Json_mkObj(v___x_251_);
lean_dec_ref_known(v___x_251_, 2);
return v___x_252_;
}
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_decodePlan(lean_object* v_x_278_, lean_object* v_x_279_){
_start:
{
lean_object* v_zero_280_; uint8_t v_isZero_281_; 
v_zero_280_ = lean_unsigned_to_nat(0u);
v_isZero_281_ = lean_nat_dec_eq(v_x_278_, v_zero_280_);
if (v_isZero_281_ == 1)
{
lean_object* v___x_282_; 
lean_dec(v_x_279_);
v___x_282_ = ((lean_object*)(l_AdaptiveExperiment_decodePlan___closed__1));
return v___x_282_;
}
else
{
lean_object* v___x_283_; lean_object* v___x_284_; 
v___x_283_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__0));
lean_inc(v_x_279_);
v___x_284_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_x_279_, v___x_283_);
if (lean_obj_tag(v___x_284_) == 0)
{
lean_object* v_a_285_; lean_object* v___x_287_; uint8_t v_isShared_288_; uint8_t v_isSharedCheck_292_; 
lean_dec(v_x_279_);
v_a_285_ = lean_ctor_get(v___x_284_, 0);
v_isSharedCheck_292_ = !lean_is_exclusive(v___x_284_);
if (v_isSharedCheck_292_ == 0)
{
v___x_287_ = v___x_284_;
v_isShared_288_ = v_isSharedCheck_292_;
goto v_resetjp_286_;
}
else
{
lean_inc(v_a_285_);
lean_dec(v___x_284_);
v___x_287_ = lean_box(0);
v_isShared_288_ = v_isSharedCheck_292_;
goto v_resetjp_286_;
}
v_resetjp_286_:
{
lean_object* v___x_290_; 
if (v_isShared_288_ == 0)
{
v___x_290_ = v___x_287_;
goto v_reusejp_289_;
}
else
{
lean_object* v_reuseFailAlloc_291_; 
v_reuseFailAlloc_291_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_291_, 0, v_a_285_);
v___x_290_ = v_reuseFailAlloc_291_;
goto v_reusejp_289_;
}
v_reusejp_289_:
{
return v___x_290_;
}
}
}
else
{
lean_object* v_a_293_; lean_object* v___x_294_; uint8_t v___x_295_; 
v_a_293_ = lean_ctor_get(v___x_284_, 0);
lean_inc(v_a_293_);
lean_dec_ref_known(v___x_284_, 1);
v___x_294_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__1));
v___x_295_ = lean_string_dec_eq(v_a_293_, v___x_294_);
if (v___x_295_ == 0)
{
lean_object* v___x_296_; uint8_t v___x_297_; 
v___x_296_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__6));
v___x_297_ = lean_string_dec_eq(v_a_293_, v___x_296_);
if (v___x_297_ == 0)
{
lean_object* v___x_298_; uint8_t v___x_299_; 
v___x_298_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__11));
v___x_299_ = lean_string_dec_eq(v_a_293_, v___x_298_);
if (v___x_299_ == 0)
{
lean_object* v___x_300_; uint8_t v___x_301_; 
v___x_300_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__15));
v___x_301_ = lean_string_dec_eq(v_a_293_, v___x_300_);
lean_dec(v_a_293_);
if (v___x_301_ == 0)
{
lean_object* v___x_302_; 
lean_dec(v_x_279_);
v___x_302_ = ((lean_object*)(l_AdaptiveExperiment_decodePlan___closed__3));
return v___x_302_;
}
else
{
lean_object* v___x_303_; lean_object* v___x_304_; 
v___x_303_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__18));
lean_inc(v_x_279_);
v___x_304_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_x_279_, v___x_303_);
if (lean_obj_tag(v___x_304_) == 0)
{
lean_object* v_a_305_; lean_object* v___x_307_; uint8_t v_isShared_308_; uint8_t v_isSharedCheck_312_; 
lean_dec(v_x_279_);
v_a_305_ = lean_ctor_get(v___x_304_, 0);
v_isSharedCheck_312_ = !lean_is_exclusive(v___x_304_);
if (v_isSharedCheck_312_ == 0)
{
v___x_307_ = v___x_304_;
v_isShared_308_ = v_isSharedCheck_312_;
goto v_resetjp_306_;
}
else
{
lean_inc(v_a_305_);
lean_dec(v___x_304_);
v___x_307_ = lean_box(0);
v_isShared_308_ = v_isSharedCheck_312_;
goto v_resetjp_306_;
}
v_resetjp_306_:
{
lean_object* v___x_310_; 
if (v_isShared_308_ == 0)
{
v___x_310_ = v___x_307_;
goto v_reusejp_309_;
}
else
{
lean_object* v_reuseFailAlloc_311_; 
v_reuseFailAlloc_311_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_311_, 0, v_a_305_);
v___x_310_ = v_reuseFailAlloc_311_;
goto v_reusejp_309_;
}
v_reusejp_309_:
{
return v___x_310_;
}
}
}
else
{
lean_object* v_a_313_; lean_object* v___x_314_; lean_object* v___x_315_; 
v_a_313_ = lean_ctor_get(v___x_304_, 0);
lean_inc(v_a_313_);
lean_dec_ref_known(v___x_304_, 1);
v___x_314_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__19));
lean_inc(v_x_279_);
v___x_315_ = l_Lean_Json_getObjVal_x3f(v_x_279_, v___x_314_);
if (lean_obj_tag(v___x_315_) == 0)
{
lean_object* v_a_316_; lean_object* v___x_318_; uint8_t v_isShared_319_; uint8_t v_isSharedCheck_323_; 
lean_dec(v_a_313_);
lean_dec(v_x_279_);
v_a_316_ = lean_ctor_get(v___x_315_, 0);
v_isSharedCheck_323_ = !lean_is_exclusive(v___x_315_);
if (v_isSharedCheck_323_ == 0)
{
v___x_318_ = v___x_315_;
v_isShared_319_ = v_isSharedCheck_323_;
goto v_resetjp_317_;
}
else
{
lean_inc(v_a_316_);
lean_dec(v___x_315_);
v___x_318_ = lean_box(0);
v_isShared_319_ = v_isSharedCheck_323_;
goto v_resetjp_317_;
}
v_resetjp_317_:
{
lean_object* v___x_321_; 
if (v_isShared_319_ == 0)
{
v___x_321_ = v___x_318_;
goto v_reusejp_320_;
}
else
{
lean_object* v_reuseFailAlloc_322_; 
v_reuseFailAlloc_322_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_322_, 0, v_a_316_);
v___x_321_ = v_reuseFailAlloc_322_;
goto v_reusejp_320_;
}
v_reusejp_320_:
{
return v___x_321_;
}
}
}
else
{
lean_object* v_a_324_; lean_object* v_one_325_; lean_object* v_n_326_; lean_object* v___x_327_; 
v_a_324_ = lean_ctor_get(v___x_315_, 0);
lean_inc(v_a_324_);
lean_dec_ref_known(v___x_315_, 1);
v_one_325_ = lean_unsigned_to_nat(1u);
v_n_326_ = lean_nat_sub(v_x_278_, v_one_325_);
v___x_327_ = l_AdaptiveExperiment_decodePlan(v_n_326_, v_a_324_);
if (lean_obj_tag(v___x_327_) == 0)
{
lean_dec(v_n_326_);
lean_dec(v_a_313_);
lean_dec(v_x_279_);
return v___x_327_;
}
else
{
lean_object* v_a_328_; lean_object* v___x_329_; lean_object* v___x_330_; 
v_a_328_ = lean_ctor_get(v___x_327_, 0);
lean_inc(v_a_328_);
lean_dec_ref_known(v___x_327_, 1);
v___x_329_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__20));
v___x_330_ = l_Lean_Json_getObjVal_x3f(v_x_279_, v___x_329_);
if (lean_obj_tag(v___x_330_) == 0)
{
lean_object* v_a_331_; lean_object* v___x_333_; uint8_t v_isShared_334_; uint8_t v_isSharedCheck_338_; 
lean_dec(v_a_328_);
lean_dec(v_n_326_);
lean_dec(v_a_313_);
v_a_331_ = lean_ctor_get(v___x_330_, 0);
v_isSharedCheck_338_ = !lean_is_exclusive(v___x_330_);
if (v_isSharedCheck_338_ == 0)
{
v___x_333_ = v___x_330_;
v_isShared_334_ = v_isSharedCheck_338_;
goto v_resetjp_332_;
}
else
{
lean_inc(v_a_331_);
lean_dec(v___x_330_);
v___x_333_ = lean_box(0);
v_isShared_334_ = v_isSharedCheck_338_;
goto v_resetjp_332_;
}
v_resetjp_332_:
{
lean_object* v___x_336_; 
if (v_isShared_334_ == 0)
{
v___x_336_ = v___x_333_;
goto v_reusejp_335_;
}
else
{
lean_object* v_reuseFailAlloc_337_; 
v_reuseFailAlloc_337_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_337_, 0, v_a_331_);
v___x_336_ = v_reuseFailAlloc_337_;
goto v_reusejp_335_;
}
v_reusejp_335_:
{
return v___x_336_;
}
}
}
else
{
lean_object* v_a_339_; lean_object* v___x_340_; 
v_a_339_ = lean_ctor_get(v___x_330_, 0);
lean_inc(v_a_339_);
lean_dec_ref_known(v___x_330_, 1);
v___x_340_ = l_AdaptiveExperiment_decodePlan(v_n_326_, v_a_339_);
lean_dec(v_n_326_);
if (lean_obj_tag(v___x_340_) == 0)
{
lean_dec(v_a_328_);
lean_dec(v_a_313_);
return v___x_340_;
}
else
{
lean_object* v_a_341_; lean_object* v___x_343_; uint8_t v_isShared_344_; uint8_t v_isSharedCheck_349_; 
v_a_341_ = lean_ctor_get(v___x_340_, 0);
v_isSharedCheck_349_ = !lean_is_exclusive(v___x_340_);
if (v_isSharedCheck_349_ == 0)
{
v___x_343_ = v___x_340_;
v_isShared_344_ = v_isSharedCheck_349_;
goto v_resetjp_342_;
}
else
{
lean_inc(v_a_341_);
lean_dec(v___x_340_);
v___x_343_ = lean_box(0);
v_isShared_344_ = v_isSharedCheck_349_;
goto v_resetjp_342_;
}
v_resetjp_342_:
{
lean_object* v___x_345_; lean_object* v___x_347_; 
v___x_345_ = lean_alloc_ctor(3, 3, 0);
lean_ctor_set(v___x_345_, 0, v_a_313_);
lean_ctor_set(v___x_345_, 1, v_a_328_);
lean_ctor_set(v___x_345_, 2, v_a_341_);
if (v_isShared_344_ == 0)
{
lean_ctor_set(v___x_343_, 0, v___x_345_);
v___x_347_ = v___x_343_;
goto v_reusejp_346_;
}
else
{
lean_object* v_reuseFailAlloc_348_; 
v_reuseFailAlloc_348_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_348_, 0, v___x_345_);
v___x_347_ = v_reuseFailAlloc_348_;
goto v_reusejp_346_;
}
v_reusejp_346_:
{
return v___x_347_;
}
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
lean_object* v___x_350_; lean_object* v___x_351_; 
lean_dec(v_a_293_);
v___x_350_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__14));
v___x_351_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_x_279_, v___x_350_);
if (lean_obj_tag(v___x_351_) == 0)
{
lean_object* v_a_352_; lean_object* v___x_354_; uint8_t v_isShared_355_; uint8_t v_isSharedCheck_359_; 
v_a_352_ = lean_ctor_get(v___x_351_, 0);
v_isSharedCheck_359_ = !lean_is_exclusive(v___x_351_);
if (v_isSharedCheck_359_ == 0)
{
v___x_354_ = v___x_351_;
v_isShared_355_ = v_isSharedCheck_359_;
goto v_resetjp_353_;
}
else
{
lean_inc(v_a_352_);
lean_dec(v___x_351_);
v___x_354_ = lean_box(0);
v_isShared_355_ = v_isSharedCheck_359_;
goto v_resetjp_353_;
}
v_resetjp_353_:
{
lean_object* v___x_357_; 
if (v_isShared_355_ == 0)
{
v___x_357_ = v___x_354_;
goto v_reusejp_356_;
}
else
{
lean_object* v_reuseFailAlloc_358_; 
v_reuseFailAlloc_358_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_358_, 0, v_a_352_);
v___x_357_ = v_reuseFailAlloc_358_;
goto v_reusejp_356_;
}
v_reusejp_356_:
{
return v___x_357_;
}
}
}
else
{
lean_object* v_a_360_; lean_object* v___x_362_; uint8_t v_isShared_363_; uint8_t v_isSharedCheck_371_; 
v_a_360_ = lean_ctor_get(v___x_351_, 0);
v_isSharedCheck_371_ = !lean_is_exclusive(v___x_351_);
if (v_isSharedCheck_371_ == 0)
{
v___x_362_ = v___x_351_;
v_isShared_363_ = v_isSharedCheck_371_;
goto v_resetjp_361_;
}
else
{
lean_inc(v_a_360_);
lean_dec(v___x_351_);
v___x_362_ = lean_box(0);
v_isShared_363_ = v_isSharedCheck_371_;
goto v_resetjp_361_;
}
v_resetjp_361_:
{
lean_object* v___x_364_; uint8_t v___x_365_; 
v___x_364_ = ((lean_object*)(l_AdaptiveExperiment_decodePlan___closed__7));
v___x_365_ = l_List_elem___at___00Lean_Meta_Grind_Arith_Cutsat_checkElimEqs_spec__0(v_a_360_, v___x_364_);
if (v___x_365_ == 0)
{
lean_object* v___x_366_; 
lean_del_object(v___x_362_);
lean_dec(v_a_360_);
v___x_366_ = ((lean_object*)(l_AdaptiveExperiment_decodePlan___closed__9));
return v___x_366_;
}
else
{
lean_object* v___x_367_; lean_object* v___x_369_; 
v___x_367_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_367_, 0, v_a_360_);
if (v_isShared_363_ == 0)
{
lean_ctor_set(v___x_362_, 0, v___x_367_);
v___x_369_ = v___x_362_;
goto v_reusejp_368_;
}
else
{
lean_object* v_reuseFailAlloc_370_; 
v_reuseFailAlloc_370_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_370_, 0, v___x_367_);
v___x_369_ = v_reuseFailAlloc_370_;
goto v_reusejp_368_;
}
v_reusejp_368_:
{
return v___x_369_;
}
}
}
}
}
}
else
{
lean_object* v___x_372_; 
lean_dec(v_a_293_);
lean_dec(v_x_279_);
v___x_372_ = ((lean_object*)(l_AdaptiveExperiment_decodePlan___closed__10));
return v___x_372_;
}
}
else
{
lean_object* v___x_373_; 
lean_dec(v_a_293_);
lean_dec(v_x_279_);
v___x_373_ = ((lean_object*)(l_AdaptiveExperiment_decodePlan___closed__11));
return v___x_373_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_decodePlan___boxed(lean_object* v_x_374_, lean_object* v_x_375_){
_start:
{
lean_object* v_res_376_; 
v_res_376_ = l_AdaptiveExperiment_decodePlan(v_x_374_, v_x_375_);
lean_dec(v_x_374_);
return v_res_376_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_ctorIdx(lean_object* v_x_377_){
_start:
{
if (lean_obj_tag(v_x_377_) == 0)
{
lean_object* v___x_378_; 
v___x_378_ = lean_unsigned_to_nat(0u);
return v___x_378_;
}
else
{
lean_object* v___x_379_; 
v___x_379_ = lean_unsigned_to_nat(1u);
return v___x_379_;
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_ctorIdx___boxed(lean_object* v_x_380_){
_start:
{
lean_object* v_res_381_; 
v_res_381_ = l_AdaptiveExperiment_Tree_ctorIdx(v_x_380_);
lean_dec_ref(v_x_380_);
return v_res_381_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_ctorElim___redArg(lean_object* v_t_382_, lean_object* v_k_383_){
_start:
{
if (lean_obj_tag(v_t_382_) == 0)
{
lean_object* v_plan_384_; lean_object* v___x_385_; 
v_plan_384_ = lean_ctor_get(v_t_382_, 0);
lean_inc(v_plan_384_);
lean_dec_ref_known(v_t_382_, 1);
v___x_385_ = lean_apply_1(v_k_383_, v_plan_384_);
return v___x_385_;
}
else
{
lean_object* v_feature_386_; lean_object* v_threshold_387_; lean_object* v_left_388_; lean_object* v_right_389_; lean_object* v___x_390_; 
v_feature_386_ = lean_ctor_get(v_t_382_, 0);
lean_inc(v_feature_386_);
v_threshold_387_ = lean_ctor_get(v_t_382_, 1);
lean_inc(v_threshold_387_);
v_left_388_ = lean_ctor_get(v_t_382_, 2);
lean_inc_ref(v_left_388_);
v_right_389_ = lean_ctor_get(v_t_382_, 3);
lean_inc_ref(v_right_389_);
lean_dec_ref_known(v_t_382_, 4);
v___x_390_ = lean_apply_4(v_k_383_, v_feature_386_, v_threshold_387_, v_left_388_, v_right_389_);
return v___x_390_;
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_ctorElim(lean_object* v_motive_391_, lean_object* v_ctorIdx_392_, lean_object* v_t_393_, lean_object* v_h_394_, lean_object* v_k_395_){
_start:
{
lean_object* v___x_396_; 
v___x_396_ = l_AdaptiveExperiment_Tree_ctorElim___redArg(v_t_393_, v_k_395_);
return v___x_396_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_ctorElim___boxed(lean_object* v_motive_397_, lean_object* v_ctorIdx_398_, lean_object* v_t_399_, lean_object* v_h_400_, lean_object* v_k_401_){
_start:
{
lean_object* v_res_402_; 
v_res_402_ = l_AdaptiveExperiment_Tree_ctorElim(v_motive_397_, v_ctorIdx_398_, v_t_399_, v_h_400_, v_k_401_);
lean_dec(v_ctorIdx_398_);
return v_res_402_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_leaf_elim___redArg(lean_object* v_t_403_, lean_object* v_leaf_404_){
_start:
{
lean_object* v___x_405_; 
v___x_405_ = l_AdaptiveExperiment_Tree_ctorElim___redArg(v_t_403_, v_leaf_404_);
return v___x_405_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_leaf_elim(lean_object* v_motive_406_, lean_object* v_t_407_, lean_object* v_h_408_, lean_object* v_leaf_409_){
_start:
{
lean_object* v___x_410_; 
v___x_410_ = l_AdaptiveExperiment_Tree_ctorElim___redArg(v_t_407_, v_leaf_409_);
return v___x_410_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_branch_elim___redArg(lean_object* v_t_411_, lean_object* v_branch_412_){
_start:
{
lean_object* v___x_413_; 
v___x_413_ = l_AdaptiveExperiment_Tree_ctorElim___redArg(v_t_411_, v_branch_412_);
return v___x_413_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_branch_elim(lean_object* v_motive_414_, lean_object* v_t_415_, lean_object* v_h_416_, lean_object* v_branch_417_){
_start:
{
lean_object* v___x_418_; 
v___x_418_ = l_AdaptiveExperiment_Tree_ctorElim___redArg(v_t_415_, v_branch_417_);
return v___x_418_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_predict(lean_object* v_x_419_, lean_object* v_x_420_){
_start:
{
if (lean_obj_tag(v_x_419_) == 0)
{
lean_object* v_plan_421_; 
v_plan_421_ = lean_ctor_get(v_x_419_, 0);
lean_inc(v_plan_421_);
return v_plan_421_;
}
else
{
lean_object* v_feature_422_; lean_object* v_threshold_423_; lean_object* v_left_424_; lean_object* v_right_425_; lean_object* v___y_427_; lean_object* v___x_431_; uint8_t v___x_432_; 
v_feature_422_ = lean_ctor_get(v_x_419_, 0);
v_threshold_423_ = lean_ctor_get(v_x_419_, 1);
v_left_424_ = lean_ctor_get(v_x_419_, 2);
v_right_425_ = lean_ctor_get(v_x_419_, 3);
v___x_431_ = lean_array_get_size(v_x_420_);
v___x_432_ = lean_nat_dec_lt(v_feature_422_, v___x_431_);
if (v___x_432_ == 0)
{
lean_object* v___x_433_; 
v___x_433_ = lean_unsigned_to_nat(0u);
v___y_427_ = v___x_433_;
goto v___jp_426_;
}
else
{
lean_object* v___x_434_; 
v___x_434_ = lean_array_fget_borrowed(v_x_420_, v_feature_422_);
v___y_427_ = v___x_434_;
goto v___jp_426_;
}
v___jp_426_:
{
uint8_t v___x_428_; 
v___x_428_ = lean_nat_dec_le(v___y_427_, v_threshold_423_);
if (v___x_428_ == 0)
{
v_x_419_ = v_right_425_;
goto _start;
}
else
{
v_x_419_ = v_left_424_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Tree_predict___boxed(lean_object* v_x_435_, lean_object* v_x_436_){
_start:
{
lean_object* v_res_437_; 
v_res_437_ = l_AdaptiveExperiment_Tree_predict(v_x_435_, v_x_436_);
lean_dec_ref(v_x_436_);
lean_dec_ref(v_x_435_);
return v_res_437_;
}
}
static lean_object* _init_l_AdaptiveExperiment_decodeTree___closed__7(void){
_start:
{
lean_object* v___x_447_; lean_object* v___x_448_; 
v___x_447_ = ((lean_object*)(l_AdaptiveExperiment_featureNames));
v___x_448_ = l_List_lengthTR___redArg(v___x_447_);
return v___x_448_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_decodeTree(lean_object* v_x_453_, lean_object* v_x_454_){
_start:
{
lean_object* v_zero_455_; uint8_t v_isZero_456_; 
v_zero_455_ = lean_unsigned_to_nat(0u);
v_isZero_456_ = lean_nat_dec_eq(v_x_453_, v_zero_455_);
if (v_isZero_456_ == 1)
{
lean_object* v___x_457_; 
lean_dec(v_x_454_);
v___x_457_ = ((lean_object*)(l_AdaptiveExperiment_decodeTree___closed__1));
return v___x_457_;
}
else
{
lean_object* v___x_458_; lean_object* v___x_459_; 
v___x_458_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__0));
lean_inc(v_x_454_);
v___x_459_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_x_454_, v___x_458_);
if (lean_obj_tag(v___x_459_) == 0)
{
lean_object* v_a_460_; lean_object* v___x_462_; uint8_t v_isShared_463_; uint8_t v_isSharedCheck_467_; 
lean_dec(v_x_454_);
v_a_460_ = lean_ctor_get(v___x_459_, 0);
v_isSharedCheck_467_ = !lean_is_exclusive(v___x_459_);
if (v_isSharedCheck_467_ == 0)
{
v___x_462_ = v___x_459_;
v_isShared_463_ = v_isSharedCheck_467_;
goto v_resetjp_461_;
}
else
{
lean_inc(v_a_460_);
lean_dec(v___x_459_);
v___x_462_ = lean_box(0);
v_isShared_463_ = v_isSharedCheck_467_;
goto v_resetjp_461_;
}
v_resetjp_461_:
{
lean_object* v___x_465_; 
if (v_isShared_463_ == 0)
{
v___x_465_ = v___x_462_;
goto v_reusejp_464_;
}
else
{
lean_object* v_reuseFailAlloc_466_; 
v_reuseFailAlloc_466_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_466_, 0, v_a_460_);
v___x_465_ = v_reuseFailAlloc_466_;
goto v_reusejp_464_;
}
v_reusejp_464_:
{
return v___x_465_;
}
}
}
else
{
lean_object* v_a_468_; lean_object* v___x_469_; uint8_t v___x_470_; 
v_a_468_ = lean_ctor_get(v___x_459_, 0);
lean_inc(v_a_468_);
lean_dec_ref_known(v___x_459_, 1);
v___x_469_ = ((lean_object*)(l_AdaptiveExperiment_decodeTree___closed__2));
v___x_470_ = lean_string_dec_eq(v_a_468_, v___x_469_);
if (v___x_470_ == 0)
{
lean_object* v___x_471_; uint8_t v___x_472_; 
v___x_471_ = ((lean_object*)(l_AdaptiveExperiment_decodeTree___closed__3));
v___x_472_ = lean_string_dec_eq(v_a_468_, v___x_471_);
lean_dec(v_a_468_);
if (v___x_472_ == 0)
{
lean_object* v___x_473_; 
lean_dec(v_x_454_);
v___x_473_ = ((lean_object*)(l_AdaptiveExperiment_decodeTree___closed__5));
return v___x_473_;
}
else
{
lean_object* v___x_474_; lean_object* v___x_475_; 
v___x_474_ = ((lean_object*)(l_AdaptiveExperiment_decodeTree___closed__6));
lean_inc(v_x_454_);
v___x_475_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_x_454_, v___x_474_);
if (lean_obj_tag(v___x_475_) == 0)
{
lean_object* v_a_476_; lean_object* v___x_478_; uint8_t v_isShared_479_; uint8_t v_isSharedCheck_483_; 
lean_dec(v_x_454_);
v_a_476_ = lean_ctor_get(v___x_475_, 0);
v_isSharedCheck_483_ = !lean_is_exclusive(v___x_475_);
if (v_isSharedCheck_483_ == 0)
{
v___x_478_ = v___x_475_;
v_isShared_479_ = v_isSharedCheck_483_;
goto v_resetjp_477_;
}
else
{
lean_inc(v_a_476_);
lean_dec(v___x_475_);
v___x_478_ = lean_box(0);
v_isShared_479_ = v_isSharedCheck_483_;
goto v_resetjp_477_;
}
v_resetjp_477_:
{
lean_object* v___x_481_; 
if (v_isShared_479_ == 0)
{
v___x_481_ = v___x_478_;
goto v_reusejp_480_;
}
else
{
lean_object* v_reuseFailAlloc_482_; 
v_reuseFailAlloc_482_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_482_, 0, v_a_476_);
v___x_481_ = v_reuseFailAlloc_482_;
goto v_reusejp_480_;
}
v_reusejp_480_:
{
return v___x_481_;
}
}
}
else
{
lean_object* v_a_484_; lean_object* v___x_485_; uint8_t v___x_486_; 
v_a_484_ = lean_ctor_get(v___x_475_, 0);
lean_inc(v_a_484_);
lean_dec_ref_known(v___x_475_, 1);
v___x_485_ = lean_obj_once(&l_AdaptiveExperiment_decodeTree___closed__7, &l_AdaptiveExperiment_decodeTree___closed__7_once, _init_l_AdaptiveExperiment_decodeTree___closed__7);
v___x_486_ = lean_nat_dec_lt(v_a_484_, v___x_485_);
if (v___x_486_ == 0)
{
lean_object* v___x_487_; 
lean_dec(v_a_484_);
lean_dec(v_x_454_);
v___x_487_ = ((lean_object*)(l_AdaptiveExperiment_decodeTree___closed__9));
return v___x_487_;
}
else
{
lean_object* v___x_488_; lean_object* v___x_489_; 
v___x_488_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__14));
lean_inc(v_x_454_);
v___x_489_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_x_454_, v___x_488_);
if (lean_obj_tag(v___x_489_) == 0)
{
lean_object* v_a_490_; lean_object* v___x_492_; uint8_t v_isShared_493_; uint8_t v_isSharedCheck_497_; 
lean_dec(v_a_484_);
lean_dec(v_x_454_);
v_a_490_ = lean_ctor_get(v___x_489_, 0);
v_isSharedCheck_497_ = !lean_is_exclusive(v___x_489_);
if (v_isSharedCheck_497_ == 0)
{
v___x_492_ = v___x_489_;
v_isShared_493_ = v_isSharedCheck_497_;
goto v_resetjp_491_;
}
else
{
lean_inc(v_a_490_);
lean_dec(v___x_489_);
v___x_492_ = lean_box(0);
v_isShared_493_ = v_isSharedCheck_497_;
goto v_resetjp_491_;
}
v_resetjp_491_:
{
lean_object* v___x_495_; 
if (v_isShared_493_ == 0)
{
v___x_495_ = v___x_492_;
goto v_reusejp_494_;
}
else
{
lean_object* v_reuseFailAlloc_496_; 
v_reuseFailAlloc_496_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_496_, 0, v_a_490_);
v___x_495_ = v_reuseFailAlloc_496_;
goto v_reusejp_494_;
}
v_reusejp_494_:
{
return v___x_495_;
}
}
}
else
{
lean_object* v_a_498_; lean_object* v___x_499_; lean_object* v___x_500_; 
v_a_498_ = lean_ctor_get(v___x_489_, 0);
lean_inc(v_a_498_);
lean_dec_ref_known(v___x_489_, 1);
v___x_499_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__19));
lean_inc(v_x_454_);
v___x_500_ = l_Lean_Json_getObjVal_x3f(v_x_454_, v___x_499_);
if (lean_obj_tag(v___x_500_) == 0)
{
lean_object* v_a_501_; lean_object* v___x_503_; uint8_t v_isShared_504_; uint8_t v_isSharedCheck_508_; 
lean_dec(v_a_498_);
lean_dec(v_a_484_);
lean_dec(v_x_454_);
v_a_501_ = lean_ctor_get(v___x_500_, 0);
v_isSharedCheck_508_ = !lean_is_exclusive(v___x_500_);
if (v_isSharedCheck_508_ == 0)
{
v___x_503_ = v___x_500_;
v_isShared_504_ = v_isSharedCheck_508_;
goto v_resetjp_502_;
}
else
{
lean_inc(v_a_501_);
lean_dec(v___x_500_);
v___x_503_ = lean_box(0);
v_isShared_504_ = v_isSharedCheck_508_;
goto v_resetjp_502_;
}
v_resetjp_502_:
{
lean_object* v___x_506_; 
if (v_isShared_504_ == 0)
{
v___x_506_ = v___x_503_;
goto v_reusejp_505_;
}
else
{
lean_object* v_reuseFailAlloc_507_; 
v_reuseFailAlloc_507_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_507_, 0, v_a_501_);
v___x_506_ = v_reuseFailAlloc_507_;
goto v_reusejp_505_;
}
v_reusejp_505_:
{
return v___x_506_;
}
}
}
else
{
lean_object* v_a_509_; lean_object* v_one_510_; lean_object* v_n_511_; lean_object* v___x_512_; 
v_a_509_ = lean_ctor_get(v___x_500_, 0);
lean_inc(v_a_509_);
lean_dec_ref_known(v___x_500_, 1);
v_one_510_ = lean_unsigned_to_nat(1u);
v_n_511_ = lean_nat_sub(v_x_453_, v_one_510_);
v___x_512_ = l_AdaptiveExperiment_decodeTree(v_n_511_, v_a_509_);
if (lean_obj_tag(v___x_512_) == 0)
{
lean_dec(v_n_511_);
lean_dec(v_a_498_);
lean_dec(v_a_484_);
lean_dec(v_x_454_);
return v___x_512_;
}
else
{
lean_object* v_a_513_; lean_object* v___x_514_; lean_object* v___x_515_; 
v_a_513_ = lean_ctor_get(v___x_512_, 0);
lean_inc(v_a_513_);
lean_dec_ref_known(v___x_512_, 1);
v___x_514_ = ((lean_object*)(l_AdaptiveExperiment_planJson___closed__20));
v___x_515_ = l_Lean_Json_getObjVal_x3f(v_x_454_, v___x_514_);
if (lean_obj_tag(v___x_515_) == 0)
{
lean_object* v_a_516_; lean_object* v___x_518_; uint8_t v_isShared_519_; uint8_t v_isSharedCheck_523_; 
lean_dec(v_a_513_);
lean_dec(v_n_511_);
lean_dec(v_a_498_);
lean_dec(v_a_484_);
v_a_516_ = lean_ctor_get(v___x_515_, 0);
v_isSharedCheck_523_ = !lean_is_exclusive(v___x_515_);
if (v_isSharedCheck_523_ == 0)
{
v___x_518_ = v___x_515_;
v_isShared_519_ = v_isSharedCheck_523_;
goto v_resetjp_517_;
}
else
{
lean_inc(v_a_516_);
lean_dec(v___x_515_);
v___x_518_ = lean_box(0);
v_isShared_519_ = v_isSharedCheck_523_;
goto v_resetjp_517_;
}
v_resetjp_517_:
{
lean_object* v___x_521_; 
if (v_isShared_519_ == 0)
{
v___x_521_ = v___x_518_;
goto v_reusejp_520_;
}
else
{
lean_object* v_reuseFailAlloc_522_; 
v_reuseFailAlloc_522_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_522_, 0, v_a_516_);
v___x_521_ = v_reuseFailAlloc_522_;
goto v_reusejp_520_;
}
v_reusejp_520_:
{
return v___x_521_;
}
}
}
else
{
lean_object* v_a_524_; lean_object* v___x_525_; 
v_a_524_ = lean_ctor_get(v___x_515_, 0);
lean_inc(v_a_524_);
lean_dec_ref_known(v___x_515_, 1);
v___x_525_ = l_AdaptiveExperiment_decodeTree(v_n_511_, v_a_524_);
lean_dec(v_n_511_);
if (lean_obj_tag(v___x_525_) == 0)
{
lean_dec(v_a_513_);
lean_dec(v_a_498_);
lean_dec(v_a_484_);
return v___x_525_;
}
else
{
lean_object* v_a_526_; lean_object* v___x_528_; uint8_t v_isShared_529_; uint8_t v_isSharedCheck_534_; 
v_a_526_ = lean_ctor_get(v___x_525_, 0);
v_isSharedCheck_534_ = !lean_is_exclusive(v___x_525_);
if (v_isSharedCheck_534_ == 0)
{
v___x_528_ = v___x_525_;
v_isShared_529_ = v_isSharedCheck_534_;
goto v_resetjp_527_;
}
else
{
lean_inc(v_a_526_);
lean_dec(v___x_525_);
v___x_528_ = lean_box(0);
v_isShared_529_ = v_isSharedCheck_534_;
goto v_resetjp_527_;
}
v_resetjp_527_:
{
lean_object* v___x_530_; lean_object* v___x_532_; 
v___x_530_ = lean_alloc_ctor(1, 4, 0);
lean_ctor_set(v___x_530_, 0, v_a_484_);
lean_ctor_set(v___x_530_, 1, v_a_498_);
lean_ctor_set(v___x_530_, 2, v_a_513_);
lean_ctor_set(v___x_530_, 3, v_a_526_);
if (v_isShared_529_ == 0)
{
lean_ctor_set(v___x_528_, 0, v___x_530_);
v___x_532_ = v___x_528_;
goto v_reusejp_531_;
}
else
{
lean_object* v_reuseFailAlloc_533_; 
v_reuseFailAlloc_533_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_533_, 0, v___x_530_);
v___x_532_ = v_reuseFailAlloc_533_;
goto v_reusejp_531_;
}
v_reusejp_531_:
{
return v___x_532_;
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
}
else
{
lean_object* v___x_535_; lean_object* v___x_536_; 
lean_dec(v_a_468_);
v___x_535_ = ((lean_object*)(l_AdaptiveExperiment_decodeTree___closed__10));
v___x_536_ = l_Lean_Json_getObjVal_x3f(v_x_454_, v___x_535_);
if (lean_obj_tag(v___x_536_) == 0)
{
lean_object* v_a_537_; lean_object* v___x_539_; uint8_t v_isShared_540_; uint8_t v_isSharedCheck_544_; 
v_a_537_ = lean_ctor_get(v___x_536_, 0);
v_isSharedCheck_544_ = !lean_is_exclusive(v___x_536_);
if (v_isSharedCheck_544_ == 0)
{
v___x_539_ = v___x_536_;
v_isShared_540_ = v_isSharedCheck_544_;
goto v_resetjp_538_;
}
else
{
lean_inc(v_a_537_);
lean_dec(v___x_536_);
v___x_539_ = lean_box(0);
v_isShared_540_ = v_isSharedCheck_544_;
goto v_resetjp_538_;
}
v_resetjp_538_:
{
lean_object* v___x_542_; 
if (v_isShared_540_ == 0)
{
v___x_542_ = v___x_539_;
goto v_reusejp_541_;
}
else
{
lean_object* v_reuseFailAlloc_543_; 
v_reuseFailAlloc_543_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_543_, 0, v_a_537_);
v___x_542_ = v_reuseFailAlloc_543_;
goto v_reusejp_541_;
}
v_reusejp_541_:
{
return v___x_542_;
}
}
}
else
{
lean_object* v_a_545_; lean_object* v___x_546_; lean_object* v___x_547_; 
v_a_545_ = lean_ctor_get(v___x_536_, 0);
lean_inc(v_a_545_);
lean_dec_ref_known(v___x_536_, 1);
v___x_546_ = lean_unsigned_to_nat(16u);
v___x_547_ = l_AdaptiveExperiment_decodePlan(v___x_546_, v_a_545_);
if (lean_obj_tag(v___x_547_) == 0)
{
lean_object* v_a_548_; lean_object* v___x_550_; uint8_t v_isShared_551_; uint8_t v_isSharedCheck_555_; 
v_a_548_ = lean_ctor_get(v___x_547_, 0);
v_isSharedCheck_555_ = !lean_is_exclusive(v___x_547_);
if (v_isSharedCheck_555_ == 0)
{
v___x_550_ = v___x_547_;
v_isShared_551_ = v_isSharedCheck_555_;
goto v_resetjp_549_;
}
else
{
lean_inc(v_a_548_);
lean_dec(v___x_547_);
v___x_550_ = lean_box(0);
v_isShared_551_ = v_isSharedCheck_555_;
goto v_resetjp_549_;
}
v_resetjp_549_:
{
lean_object* v___x_553_; 
if (v_isShared_551_ == 0)
{
v___x_553_ = v___x_550_;
goto v_reusejp_552_;
}
else
{
lean_object* v_reuseFailAlloc_554_; 
v_reuseFailAlloc_554_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_554_, 0, v_a_548_);
v___x_553_ = v_reuseFailAlloc_554_;
goto v_reusejp_552_;
}
v_reusejp_552_:
{
return v___x_553_;
}
}
}
else
{
lean_object* v_a_556_; lean_object* v___x_558_; uint8_t v_isShared_559_; uint8_t v_isSharedCheck_564_; 
v_a_556_ = lean_ctor_get(v___x_547_, 0);
v_isSharedCheck_564_ = !lean_is_exclusive(v___x_547_);
if (v_isSharedCheck_564_ == 0)
{
v___x_558_ = v___x_547_;
v_isShared_559_ = v_isSharedCheck_564_;
goto v_resetjp_557_;
}
else
{
lean_inc(v_a_556_);
lean_dec(v___x_547_);
v___x_558_ = lean_box(0);
v_isShared_559_ = v_isSharedCheck_564_;
goto v_resetjp_557_;
}
v_resetjp_557_:
{
lean_object* v___x_560_; lean_object* v___x_562_; 
v___x_560_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_560_, 0, v_a_556_);
if (v_isShared_559_ == 0)
{
lean_ctor_set(v___x_558_, 0, v___x_560_);
v___x_562_ = v___x_558_;
goto v_reusejp_561_;
}
else
{
lean_object* v_reuseFailAlloc_563_; 
v_reuseFailAlloc_563_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_563_, 0, v___x_560_);
v___x_562_ = v_reuseFailAlloc_563_;
goto v_reusejp_561_;
}
v_reusejp_561_:
{
return v___x_562_;
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_decodeTree___boxed(lean_object* v_x_565_, lean_object* v_x_566_){
_start:
{
lean_object* v_res_567_; 
v_res_567_ = l_AdaptiveExperiment_decodeTree(v_x_565_, v_x_566_);
lean_dec(v_x_565_);
return v_res_567_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_decodeModel(lean_object* v_j_577_){
_start:
{
lean_object* v___x_578_; lean_object* v___x_579_; 
v___x_578_ = ((lean_object*)(l_AdaptiveExperiment_decodeModel___closed__0));
lean_inc(v_j_577_);
v___x_579_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_577_, v___x_578_);
if (lean_obj_tag(v___x_579_) == 0)
{
lean_object* v_a_580_; lean_object* v___x_582_; uint8_t v_isShared_583_; uint8_t v_isSharedCheck_587_; 
lean_dec(v_j_577_);
v_a_580_ = lean_ctor_get(v___x_579_, 0);
v_isSharedCheck_587_ = !lean_is_exclusive(v___x_579_);
if (v_isSharedCheck_587_ == 0)
{
v___x_582_ = v___x_579_;
v_isShared_583_ = v_isSharedCheck_587_;
goto v_resetjp_581_;
}
else
{
lean_inc(v_a_580_);
lean_dec(v___x_579_);
v___x_582_ = lean_box(0);
v_isShared_583_ = v_isSharedCheck_587_;
goto v_resetjp_581_;
}
v_resetjp_581_:
{
lean_object* v___x_585_; 
if (v_isShared_583_ == 0)
{
v___x_585_ = v___x_582_;
goto v_reusejp_584_;
}
else
{
lean_object* v_reuseFailAlloc_586_; 
v_reuseFailAlloc_586_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_586_, 0, v_a_580_);
v___x_585_ = v_reuseFailAlloc_586_;
goto v_reusejp_584_;
}
v_reusejp_584_:
{
return v___x_585_;
}
}
}
else
{
lean_object* v_a_588_; lean_object* v___x_589_; uint8_t v___x_590_; 
v_a_588_ = lean_ctor_get(v___x_579_, 0);
lean_inc(v_a_588_);
lean_dec_ref_known(v___x_579_, 1);
v___x_589_ = lean_unsigned_to_nat(1u);
v___x_590_ = lean_nat_dec_eq(v_a_588_, v___x_589_);
lean_dec(v_a_588_);
if (v___x_590_ == 0)
{
lean_object* v___x_591_; 
lean_dec(v_j_577_);
v___x_591_ = ((lean_object*)(l_AdaptiveExperiment_decodeModel___closed__2));
return v___x_591_;
}
else
{
lean_object* v___x_592_; lean_object* v___x_593_; 
v___x_592_ = ((lean_object*)(l_AdaptiveExperiment_decodeModel___closed__3));
lean_inc(v_j_577_);
v___x_593_ = lp_LeanSearchClient_Lean_Json_getObjValAs_x3f___at___00LeanSearchClient_getLoogleQueryJson_spec__4(v_j_577_, v___x_592_);
if (lean_obj_tag(v___x_593_) == 0)
{
lean_object* v_a_594_; lean_object* v___x_596_; uint8_t v_isShared_597_; uint8_t v_isSharedCheck_601_; 
lean_dec(v_j_577_);
v_a_594_ = lean_ctor_get(v___x_593_, 0);
v_isSharedCheck_601_ = !lean_is_exclusive(v___x_593_);
if (v_isSharedCheck_601_ == 0)
{
v___x_596_ = v___x_593_;
v_isShared_597_ = v_isSharedCheck_601_;
goto v_resetjp_595_;
}
else
{
lean_inc(v_a_594_);
lean_dec(v___x_593_);
v___x_596_ = lean_box(0);
v_isShared_597_ = v_isSharedCheck_601_;
goto v_resetjp_595_;
}
v_resetjp_595_:
{
lean_object* v___x_599_; 
if (v_isShared_597_ == 0)
{
v___x_599_ = v___x_596_;
goto v_reusejp_598_;
}
else
{
lean_object* v_reuseFailAlloc_600_; 
v_reuseFailAlloc_600_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_600_, 0, v_a_594_);
v___x_599_ = v_reuseFailAlloc_600_;
goto v_reusejp_598_;
}
v_reusejp_598_:
{
return v___x_599_;
}
}
}
else
{
lean_object* v_a_602_; lean_object* v___x_603_; uint8_t v___x_604_; 
v_a_602_ = lean_ctor_get(v___x_593_, 0);
lean_inc(v_a_602_);
lean_dec_ref_known(v___x_593_, 1);
v___x_603_ = ((lean_object*)(l_AdaptiveExperiment_featureNames));
v___x_604_ = lp_mathlib_List_beq___at___00__private_Mathlib_Tactic_DefEqAbuse_0__Mathlib_Tactic_DefEqAbuse_isIdenticalSidesStr_spec__4(v_a_602_, v___x_603_);
lean_dec(v_a_602_);
if (v___x_604_ == 0)
{
lean_object* v___x_605_; 
lean_dec(v_j_577_);
v___x_605_ = ((lean_object*)(l_AdaptiveExperiment_decodeModel___closed__5));
return v___x_605_;
}
else
{
lean_object* v___x_606_; lean_object* v___x_607_; 
v___x_606_ = ((lean_object*)(l_AdaptiveExperiment_decodeModel___closed__6));
v___x_607_ = l_Lean_Json_getObjVal_x3f(v_j_577_, v___x_606_);
if (lean_obj_tag(v___x_607_) == 0)
{
lean_object* v_a_608_; lean_object* v___x_610_; uint8_t v_isShared_611_; uint8_t v_isSharedCheck_615_; 
v_a_608_ = lean_ctor_get(v___x_607_, 0);
v_isSharedCheck_615_ = !lean_is_exclusive(v___x_607_);
if (v_isSharedCheck_615_ == 0)
{
v___x_610_ = v___x_607_;
v_isShared_611_ = v_isSharedCheck_615_;
goto v_resetjp_609_;
}
else
{
lean_inc(v_a_608_);
lean_dec(v___x_607_);
v___x_610_ = lean_box(0);
v_isShared_611_ = v_isSharedCheck_615_;
goto v_resetjp_609_;
}
v_resetjp_609_:
{
lean_object* v___x_613_; 
if (v_isShared_611_ == 0)
{
v___x_613_ = v___x_610_;
goto v_reusejp_612_;
}
else
{
lean_object* v_reuseFailAlloc_614_; 
v_reuseFailAlloc_614_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_614_, 0, v_a_608_);
v___x_613_ = v_reuseFailAlloc_614_;
goto v_reusejp_612_;
}
v_reusejp_612_:
{
return v___x_613_;
}
}
}
else
{
lean_object* v_a_616_; lean_object* v___x_617_; lean_object* v___x_618_; 
v_a_616_ = lean_ctor_get(v___x_607_, 0);
lean_inc(v_a_616_);
lean_dec_ref_known(v___x_607_, 1);
v___x_617_ = lean_unsigned_to_nat(16u);
v___x_618_ = l_AdaptiveExperiment_decodeTree(v___x_617_, v_a_616_);
return v___x_618_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_manual(lean_object* v_f_668_){
_start:
{
lean_object* v___y_670_; uint8_t v___y_676_; lean_object* v___y_684_; lean_object* v___y_688_; lean_object* v___x_696_; lean_object* v___x_697_; uint8_t v___x_698_; 
v___x_696_ = lean_unsigned_to_nat(0u);
v___x_697_ = lean_array_get_size(v_f_668_);
v___x_698_ = lean_nat_dec_lt(v___x_696_, v___x_697_);
if (v___x_698_ == 0)
{
v___y_688_ = v___x_696_;
goto v___jp_687_;
}
else
{
lean_object* v___x_699_; 
v___x_699_ = lean_array_fget_borrowed(v_f_668_, v___x_696_);
v___y_688_ = v___x_699_;
goto v___jp_687_;
}
v___jp_669_:
{
lean_object* v___x_671_; uint8_t v___x_672_; 
v___x_671_ = lean_unsigned_to_nat(50u);
v___x_672_ = lean_nat_dec_le(v___y_670_, v___x_671_);
if (v___x_672_ == 0)
{
lean_object* v___x_673_; 
v___x_673_ = ((lean_object*)(l_AdaptiveExperiment_candidates___closed__9));
return v___x_673_;
}
else
{
lean_object* v___x_674_; 
v___x_674_ = ((lean_object*)(l_AdaptiveExperiment_candidates___closed__12));
return v___x_674_;
}
}
v___jp_675_:
{
if (v___y_676_ == 0)
{
lean_object* v___x_677_; lean_object* v___x_678_; uint8_t v___x_679_; 
v___x_677_ = lean_unsigned_to_nat(1u);
v___x_678_ = lean_array_get_size(v_f_668_);
v___x_679_ = lean_nat_dec_lt(v___x_677_, v___x_678_);
if (v___x_679_ == 0)
{
lean_object* v___x_680_; 
v___x_680_ = lean_unsigned_to_nat(0u);
v___y_670_ = v___x_680_;
goto v___jp_669_;
}
else
{
lean_object* v___x_681_; 
v___x_681_ = lean_array_fget_borrowed(v_f_668_, v___x_677_);
v___y_670_ = v___x_681_;
goto v___jp_669_;
}
}
else
{
lean_object* v___x_682_; 
v___x_682_ = lean_box(1);
return v___x_682_;
}
}
v___jp_683_:
{
lean_object* v___x_685_; uint8_t v___x_686_; 
v___x_685_ = lean_unsigned_to_nat(0u);
v___x_686_ = lean_nat_dec_eq(v___y_684_, v___x_685_);
v___y_676_ = v___x_686_;
goto v___jp_675_;
}
v___jp_687_:
{
lean_object* v___x_689_; uint8_t v___x_690_; 
v___x_689_ = lean_unsigned_to_nat(32u);
v___x_690_ = lean_nat_dec_le(v___y_688_, v___x_689_);
if (v___x_690_ == 0)
{
lean_object* v___x_691_; lean_object* v___x_692_; uint8_t v___x_693_; 
v___x_691_ = lean_unsigned_to_nat(1u);
v___x_692_ = lean_array_get_size(v_f_668_);
v___x_693_ = lean_nat_dec_lt(v___x_691_, v___x_692_);
if (v___x_693_ == 0)
{
lean_object* v___x_694_; 
v___x_694_ = lean_unsigned_to_nat(0u);
v___y_684_ = v___x_694_;
goto v___jp_683_;
}
else
{
lean_object* v___x_695_; 
v___x_695_ = lean_array_fget_borrowed(v_f_668_, v___x_691_);
v___y_684_ = v___x_695_;
goto v___jp_683_;
}
}
else
{
v___y_676_ = v___x_690_;
goto v___jp_675_;
}
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_manual___boxed(lean_object* v_f_700_){
_start:
{
lean_object* v_res_701_; 
v_res_701_ = l_AdaptiveExperiment_manual(v_f_700_);
lean_dec_ref(v_f_700_);
return v_res_701_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_ctorIdx(lean_object* v_x_702_){
_start:
{
switch(lean_obj_tag(v_x_702_))
{
case 0:
{
lean_object* v___x_703_; 
v___x_703_ = lean_unsigned_to_nat(0u);
return v___x_703_;
}
case 1:
{
lean_object* v___x_704_; 
v___x_704_ = lean_unsigned_to_nat(1u);
return v___x_704_;
}
default: 
{
lean_object* v___x_705_; 
v___x_705_ = lean_unsigned_to_nat(2u);
return v___x_705_;
}
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_ctorIdx___boxed(lean_object* v_x_706_){
_start:
{
lean_object* v_res_707_; 
v_res_707_ = l_AdaptiveExperiment_Strategy_ctorIdx(v_x_706_);
lean_dec(v_x_706_);
return v_res_707_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_ctorElim___redArg(lean_object* v_t_708_, lean_object* v_k_709_){
_start:
{
if (lean_obj_tag(v_t_708_) == 1)
{
return v_k_709_;
}
else
{
lean_object* v_plan_710_; lean_object* v___x_711_; 
v_plan_710_ = lean_ctor_get(v_t_708_, 0);
lean_inc(v_plan_710_);
lean_dec(v_t_708_);
v___x_711_ = lean_apply_1(v_k_709_, v_plan_710_);
return v___x_711_;
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_ctorElim(lean_object* v_motive_712_, lean_object* v_ctorIdx_713_, lean_object* v_t_714_, lean_object* v_h_715_, lean_object* v_k_716_){
_start:
{
lean_object* v___x_717_; 
v___x_717_ = l_AdaptiveExperiment_Strategy_ctorElim___redArg(v_t_714_, v_k_716_);
return v___x_717_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_ctorElim___boxed(lean_object* v_motive_718_, lean_object* v_ctorIdx_719_, lean_object* v_t_720_, lean_object* v_h_721_, lean_object* v_k_722_){
_start:
{
lean_object* v_res_723_; 
v_res_723_ = l_AdaptiveExperiment_Strategy_ctorElim(v_motive_718_, v_ctorIdx_719_, v_t_720_, v_h_721_, v_k_722_);
lean_dec(v_ctorIdx_719_);
return v_res_723_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_fixed_elim___redArg(lean_object* v_t_724_, lean_object* v_fixed_725_){
_start:
{
lean_object* v___x_726_; 
v___x_726_ = l_AdaptiveExperiment_Strategy_ctorElim___redArg(v_t_724_, v_fixed_725_);
return v___x_726_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_fixed_elim(lean_object* v_motive_727_, lean_object* v_t_728_, lean_object* v_h_729_, lean_object* v_fixed_730_){
_start:
{
lean_object* v___x_731_; 
v___x_731_ = l_AdaptiveExperiment_Strategy_ctorElim___redArg(v_t_728_, v_fixed_730_);
return v___x_731_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_rule_elim___redArg(lean_object* v_t_732_, lean_object* v_rule_733_){
_start:
{
lean_object* v___x_734_; 
v___x_734_ = l_AdaptiveExperiment_Strategy_ctorElim___redArg(v_t_732_, v_rule_733_);
return v___x_734_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_rule_elim(lean_object* v_motive_735_, lean_object* v_t_736_, lean_object* v_h_737_, lean_object* v_rule_738_){
_start:
{
lean_object* v___x_739_; 
v___x_739_ = l_AdaptiveExperiment_Strategy_ctorElim___redArg(v_t_736_, v_rule_738_);
return v___x_739_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_learned_elim___redArg(lean_object* v_t_740_, lean_object* v_learned_741_){
_start:
{
lean_object* v___x_742_; 
v___x_742_ = l_AdaptiveExperiment_Strategy_ctorElim___redArg(v_t_740_, v_learned_741_);
return v___x_742_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_learned_elim(lean_object* v_motive_743_, lean_object* v_t_744_, lean_object* v_h_745_, lean_object* v_learned_746_){
_start:
{
lean_object* v___x_747_; 
v___x_747_ = l_AdaptiveExperiment_Strategy_ctorElim___redArg(v_t_744_, v_learned_746_);
return v___x_747_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_choose(lean_object* v_x_748_, lean_object* v_x_749_){
_start:
{
switch(lean_obj_tag(v_x_748_))
{
case 0:
{
lean_object* v_plan_750_; lean_object* v___x_752_; uint8_t v_isShared_753_; uint8_t v_isSharedCheck_757_; 
lean_dec(v_x_749_);
v_plan_750_ = lean_ctor_get(v_x_748_, 0);
v_isSharedCheck_757_ = !lean_is_exclusive(v_x_748_);
if (v_isSharedCheck_757_ == 0)
{
v___x_752_ = v_x_748_;
v_isShared_753_ = v_isSharedCheck_757_;
goto v_resetjp_751_;
}
else
{
lean_inc(v_plan_750_);
lean_dec(v_x_748_);
v___x_752_ = lean_box(0);
v_isShared_753_ = v_isSharedCheck_757_;
goto v_resetjp_751_;
}
v_resetjp_751_:
{
lean_object* v___x_755_; 
if (v_isShared_753_ == 0)
{
lean_ctor_set_tag(v___x_752_, 1);
v___x_755_ = v___x_752_;
goto v_reusejp_754_;
}
else
{
lean_object* v_reuseFailAlloc_756_; 
v_reuseFailAlloc_756_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_756_, 0, v_plan_750_);
v___x_755_ = v_reuseFailAlloc_756_;
goto v_reusejp_754_;
}
v_reusejp_754_:
{
return v___x_755_;
}
}
}
case 1:
{
lean_object* v___x_758_; lean_object* v___x_759_; lean_object* v___x_760_; 
v___x_758_ = l_AdaptiveExperiment_features(v_x_749_);
v___x_759_ = l_AdaptiveExperiment_manual(v___x_758_);
lean_dec_ref(v___x_758_);
v___x_760_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_760_, 0, v___x_759_);
return v___x_760_;
}
default: 
{
lean_object* v_tree_761_; 
v_tree_761_ = lean_ctor_get(v_x_748_, 0);
lean_inc(v_tree_761_);
lean_dec_ref_known(v_x_748_, 1);
if (lean_obj_tag(v_tree_761_) == 0)
{
lean_object* v___x_762_; 
lean_dec(v_x_749_);
v___x_762_ = lean_box(0);
return v___x_762_;
}
else
{
lean_object* v_val_763_; lean_object* v___x_765_; uint8_t v_isShared_766_; uint8_t v_isSharedCheck_772_; 
v_val_763_ = lean_ctor_get(v_tree_761_, 0);
v_isSharedCheck_772_ = !lean_is_exclusive(v_tree_761_);
if (v_isSharedCheck_772_ == 0)
{
v___x_765_ = v_tree_761_;
v_isShared_766_ = v_isSharedCheck_772_;
goto v_resetjp_764_;
}
else
{
lean_inc(v_val_763_);
lean_dec(v_tree_761_);
v___x_765_ = lean_box(0);
v_isShared_766_ = v_isSharedCheck_772_;
goto v_resetjp_764_;
}
v_resetjp_764_:
{
lean_object* v___x_767_; lean_object* v___x_768_; lean_object* v___x_770_; 
v___x_767_ = l_AdaptiveExperiment_features(v_x_749_);
v___x_768_ = l_AdaptiveExperiment_Tree_predict(v_val_763_, v___x_767_);
lean_dec_ref(v___x_767_);
lean_dec(v_val_763_);
if (v_isShared_766_ == 0)
{
lean_ctor_set(v___x_765_, 0, v___x_768_);
v___x_770_ = v___x_765_;
goto v_reusejp_769_;
}
else
{
lean_object* v_reuseFailAlloc_771_; 
v_reuseFailAlloc_771_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_771_, 0, v___x_768_);
v___x_770_ = v_reuseFailAlloc_771_;
goto v_reusejp_769_;
}
v_reusejp_769_:
{
return v___x_770_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_pure___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__8___redArg(lean_object* v_a_773_){
_start:
{
lean_object* v___x_774_; lean_object* v___x_775_; 
v___x_774_ = lean_unsigned_to_nat(0u);
v___x_775_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_775_, 0, v_a_773_);
lean_ctor_set(v___x_775_, 1, v___x_774_);
return v___x_775_;
}
}
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___lam__0(lean_object* v_head_776_, lean_object* v_rest_777_){
_start:
{
lean_object* v___x_778_; lean_object* v___x_779_; 
v___x_778_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_778_, 0, v_head_776_);
lean_ctor_set(v___x_778_, 1, v_rest_777_);
v___x_779_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__8___redArg(v___x_778_);
return v___x_779_;
}
}
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_bind___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__9___redArg(lean_object* v_m_780_, lean_object* v_f_781_){
_start:
{
lean_object* v_ret_782_; lean_object* v_time_783_; lean_object* v_r_784_; lean_object* v_ret_785_; lean_object* v_time_786_; lean_object* v___x_788_; uint8_t v_isShared_789_; uint8_t v_isSharedCheck_794_; 
v_ret_782_ = lean_ctor_get(v_m_780_, 0);
lean_inc(v_ret_782_);
v_time_783_ = lean_ctor_get(v_m_780_, 1);
lean_inc(v_time_783_);
lean_dec_ref(v_m_780_);
v_r_784_ = lean_apply_1(v_f_781_, v_ret_782_);
v_ret_785_ = lean_ctor_get(v_r_784_, 0);
v_time_786_ = lean_ctor_get(v_r_784_, 1);
v_isSharedCheck_794_ = !lean_is_exclusive(v_r_784_);
if (v_isSharedCheck_794_ == 0)
{
v___x_788_ = v_r_784_;
v_isShared_789_ = v_isSharedCheck_794_;
goto v_resetjp_787_;
}
else
{
lean_inc(v_time_786_);
lean_inc(v_ret_785_);
lean_dec(v_r_784_);
v___x_788_ = lean_box(0);
v_isShared_789_ = v_isSharedCheck_794_;
goto v_resetjp_787_;
}
v_resetjp_787_:
{
lean_object* v___x_790_; lean_object* v___x_792_; 
v___x_790_ = lean_nat_add(v_time_783_, v_time_786_);
lean_dec(v_time_786_);
lean_dec(v_time_783_);
if (v_isShared_789_ == 0)
{
lean_ctor_set(v___x_788_, 1, v___x_790_);
v___x_792_ = v___x_788_;
goto v_reusejp_791_;
}
else
{
lean_object* v_reuseFailAlloc_793_; 
v_reuseFailAlloc_793_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_793_, 0, v_ret_785_);
lean_ctor_set(v_reuseFailAlloc_793_, 1, v___x_790_);
v___x_792_ = v_reuseFailAlloc_793_;
goto v_reusejp_791_;
}
v_reusejp_791_:
{
return v___x_792_;
}
}
}
}
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___lam__2___boxed(lean_object* v_head_795_, lean_object* v_head_796_, lean_object* v_x_797_, lean_object* v_tail_798_, lean_object* v___f_799_, lean_object* v_tail_800_, lean_object* v_x_801_, lean_object* v___f_802_, lean_object* v_____r_803_){
_start:
{
lean_object* v_res_804_; 
v_res_804_ = l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___lam__2(v_head_795_, v_head_796_, v_x_797_, v_tail_798_, v___f_799_, v_tail_800_, v_x_801_, v___f_802_, v_____r_803_);
lean_dec(v_head_796_);
lean_dec(v_head_795_);
return v_res_804_;
}
}
static lean_object* _init_l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___closed__0(void){
_start:
{
lean_object* v___x_805_; lean_object* v___x_806_; 
v___x_805_ = lean_unsigned_to_nat(1u);
v___x_806_ = lp_cslib_Cslib_Algorithms_Lean_TimeM_tick___redArg(v___x_805_);
return v___x_806_;
}
}
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5(lean_object* v_x_807_, lean_object* v_x_808_){
_start:
{
if (lean_obj_tag(v_x_807_) == 0)
{
lean_object* v___x_809_; 
v___x_809_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__8___redArg(v_x_808_);
return v___x_809_;
}
else
{
if (lean_obj_tag(v_x_808_) == 0)
{
lean_object* v___x_810_; 
v___x_810_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__8___redArg(v_x_807_);
return v___x_810_;
}
else
{
lean_object* v_head_811_; lean_object* v_tail_812_; lean_object* v_head_813_; lean_object* v_tail_814_; lean_object* v___f_815_; lean_object* v___f_816_; lean_object* v___f_817_; lean_object* v___x_818_; lean_object* v___x_819_; 
v_head_811_ = lean_ctor_get(v_x_807_, 0);
lean_inc_n(v_head_811_, 2);
v_tail_812_ = lean_ctor_get(v_x_807_, 1);
lean_inc(v_tail_812_);
v_head_813_ = lean_ctor_get(v_x_808_, 0);
lean_inc_n(v_head_813_, 2);
v_tail_814_ = lean_ctor_get(v_x_808_, 1);
lean_inc(v_tail_814_);
v___f_815_ = lean_alloc_closure((void*)(l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___lam__0), 2, 1);
lean_closure_set(v___f_815_, 0, v_head_811_);
v___f_816_ = lean_alloc_closure((void*)(l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___lam__0), 2, 1);
lean_closure_set(v___f_816_, 0, v_head_813_);
v___f_817_ = lean_alloc_closure((void*)(l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___lam__2___boxed), 9, 8);
lean_closure_set(v___f_817_, 0, v_head_811_);
lean_closure_set(v___f_817_, 1, v_head_813_);
lean_closure_set(v___f_817_, 2, v_x_807_);
lean_closure_set(v___f_817_, 3, v_tail_814_);
lean_closure_set(v___f_817_, 4, v___f_816_);
lean_closure_set(v___f_817_, 5, v_tail_812_);
lean_closure_set(v___f_817_, 6, v_x_808_);
lean_closure_set(v___f_817_, 7, v___f_815_);
v___x_818_ = lean_obj_once(&l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___closed__0, &l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___closed__0_once, _init_l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___closed__0);
v___x_819_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__9___redArg(v___x_818_, v___f_817_);
return v___x_819_;
}
}
}
}
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5___lam__2(lean_object* v_head_820_, lean_object* v_head_821_, lean_object* v_x_822_, lean_object* v_tail_823_, lean_object* v___f_824_, lean_object* v_tail_825_, lean_object* v_x_826_, lean_object* v___f_827_, lean_object* v_____r_828_){
_start:
{
uint8_t v_c_829_; 
v_c_829_ = lean_nat_dec_le(v_head_820_, v_head_821_);
if (v_c_829_ == 0)
{
lean_object* v___x_830_; lean_object* v___x_831_; 
lean_dec_ref(v___f_827_);
lean_dec(v_x_826_);
lean_dec(v_tail_825_);
v___x_830_ = l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5(v_x_822_, v_tail_823_);
v___x_831_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__9___redArg(v___x_830_, v___f_824_);
return v___x_831_;
}
else
{
lean_object* v___x_832_; lean_object* v___x_833_; 
lean_dec_ref(v___f_824_);
lean_dec(v_tail_823_);
lean_dec(v_x_822_);
v___x_832_ = l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5(v_tail_825_, v_x_826_);
v___x_833_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__9___redArg(v___x_832_, v___f_827_);
return v___x_833_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Insertion_insertTr___at___00LeanSort_Insertion_sortTr___at___00LeanSort_Insertion_insertionSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__3_spec__5_spec__6(lean_object* v_off_834_, lean_object* v_x_835_, lean_object* v_x_836_){
_start:
{
if (lean_obj_tag(v_x_836_) == 0)
{
lean_object* v___x_837_; lean_object* v___x_838_; 
lean_dec(v_off_834_);
v___x_837_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_837_, 0, v_x_835_);
lean_ctor_set(v___x_837_, 1, v_x_836_);
v___x_838_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_838_, 0, v___x_837_);
lean_ctor_set(v___x_838_, 1, v_x_836_);
return v___x_838_;
}
else
{
lean_object* v_head_839_; lean_object* v_tail_840_; uint8_t v___x_841_; 
v_head_839_ = lean_ctor_get(v_x_836_, 0);
v_tail_840_ = lean_ctor_get(v_x_836_, 1);
v___x_841_ = lean_nat_dec_le(v_x_835_, v_head_839_);
if (v___x_841_ == 0)
{
lean_object* v___x_843_; uint8_t v_isShared_844_; uint8_t v_isSharedCheck_861_; 
lean_inc(v_tail_840_);
lean_inc(v_head_839_);
v_isSharedCheck_861_ = !lean_is_exclusive(v_x_836_);
if (v_isSharedCheck_861_ == 0)
{
lean_object* v_unused_862_; lean_object* v_unused_863_; 
v_unused_862_ = lean_ctor_get(v_x_836_, 1);
lean_dec(v_unused_862_);
v_unused_863_ = lean_ctor_get(v_x_836_, 0);
lean_dec(v_unused_863_);
v___x_843_ = v_x_836_;
v_isShared_844_ = v_isSharedCheck_861_;
goto v_resetjp_842_;
}
else
{
lean_dec(v_x_836_);
v___x_843_ = lean_box(0);
v_isShared_844_ = v_isSharedCheck_861_;
goto v_resetjp_842_;
}
v_resetjp_842_:
{
lean_object* v___x_845_; lean_object* v___x_846_; lean_object* v___x_847_; lean_object* v_fst_848_; lean_object* v_snd_849_; lean_object* v___x_851_; uint8_t v_isShared_852_; uint8_t v_isSharedCheck_860_; 
v___x_845_ = lean_unsigned_to_nat(1u);
v___x_846_ = lean_nat_add(v_off_834_, v___x_845_);
v___x_847_ = l_LeanSort_Insertion_insertTr___at___00LeanSort_Insertion_sortTr___at___00LeanSort_Insertion_insertionSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__3_spec__5_spec__6(v___x_846_, v_x_835_, v_tail_840_);
v_fst_848_ = lean_ctor_get(v___x_847_, 0);
v_snd_849_ = lean_ctor_get(v___x_847_, 1);
v_isSharedCheck_860_ = !lean_is_exclusive(v___x_847_);
if (v_isSharedCheck_860_ == 0)
{
v___x_851_ = v___x_847_;
v_isShared_852_ = v_isSharedCheck_860_;
goto v_resetjp_850_;
}
else
{
lean_inc(v_snd_849_);
lean_inc(v_fst_848_);
lean_dec(v___x_847_);
v___x_851_ = lean_box(0);
v_isShared_852_ = v_isSharedCheck_860_;
goto v_resetjp_850_;
}
v_resetjp_850_:
{
lean_object* v___x_854_; 
if (v_isShared_844_ == 0)
{
lean_ctor_set(v___x_843_, 1, v_fst_848_);
v___x_854_ = v___x_843_;
goto v_reusejp_853_;
}
else
{
lean_object* v_reuseFailAlloc_859_; 
v_reuseFailAlloc_859_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_859_, 0, v_head_839_);
lean_ctor_set(v_reuseFailAlloc_859_, 1, v_fst_848_);
v___x_854_ = v_reuseFailAlloc_859_;
goto v_reusejp_853_;
}
v_reusejp_853_:
{
lean_object* v___x_855_; lean_object* v___x_857_; 
v___x_855_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_855_, 0, v_off_834_);
lean_ctor_set(v___x_855_, 1, v_snd_849_);
if (v_isShared_852_ == 0)
{
lean_ctor_set(v___x_851_, 1, v___x_855_);
lean_ctor_set(v___x_851_, 0, v___x_854_);
v___x_857_ = v___x_851_;
goto v_reusejp_856_;
}
else
{
lean_object* v_reuseFailAlloc_858_; 
v_reuseFailAlloc_858_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_858_, 0, v___x_854_);
lean_ctor_set(v_reuseFailAlloc_858_, 1, v___x_855_);
v___x_857_ = v_reuseFailAlloc_858_;
goto v_reusejp_856_;
}
v_reusejp_856_:
{
return v___x_857_;
}
}
}
}
}
else
{
lean_object* v___x_864_; lean_object* v___x_865_; lean_object* v___x_866_; 
lean_dec(v_off_834_);
v___x_864_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_864_, 0, v_x_835_);
lean_ctor_set(v___x_864_, 1, v_x_836_);
v___x_865_ = lean_box(0);
v___x_866_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_866_, 0, v___x_864_);
lean_ctor_set(v___x_866_, 1, v___x_865_);
return v___x_866_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Insertion_sortTr___at___00LeanSort_Insertion_insertionSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__3_spec__5(lean_object* v_off_867_, lean_object* v_x_868_){
_start:
{
if (lean_obj_tag(v_x_868_) == 0)
{
lean_object* v___x_869_; 
lean_dec(v_off_867_);
v___x_869_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_869_, 0, v_x_868_);
lean_ctor_set(v___x_869_, 1, v_x_868_);
return v___x_869_;
}
else
{
lean_object* v_head_870_; lean_object* v_tail_871_; lean_object* v___x_872_; lean_object* v___x_873_; lean_object* v___x_874_; lean_object* v_fst_875_; lean_object* v_snd_876_; lean_object* v___x_877_; lean_object* v_fst_878_; lean_object* v_snd_879_; lean_object* v___x_881_; uint8_t v_isShared_882_; uint8_t v_isSharedCheck_887_; 
v_head_870_ = lean_ctor_get(v_x_868_, 0);
lean_inc(v_head_870_);
v_tail_871_ = lean_ctor_get(v_x_868_, 1);
lean_inc(v_tail_871_);
lean_dec_ref_known(v_x_868_, 2);
v___x_872_ = lean_unsigned_to_nat(1u);
v___x_873_ = lean_nat_add(v_off_867_, v___x_872_);
v___x_874_ = l_LeanSort_Insertion_sortTr___at___00LeanSort_Insertion_insertionSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__3_spec__5(v___x_873_, v_tail_871_);
v_fst_875_ = lean_ctor_get(v___x_874_, 0);
lean_inc(v_fst_875_);
v_snd_876_ = lean_ctor_get(v___x_874_, 1);
lean_inc(v_snd_876_);
lean_dec_ref(v___x_874_);
v___x_877_ = l_LeanSort_Insertion_insertTr___at___00LeanSort_Insertion_sortTr___at___00LeanSort_Insertion_insertionSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__3_spec__5_spec__6(v_off_867_, v_head_870_, v_fst_875_);
v_fst_878_ = lean_ctor_get(v___x_877_, 0);
v_snd_879_ = lean_ctor_get(v___x_877_, 1);
v_isSharedCheck_887_ = !lean_is_exclusive(v___x_877_);
if (v_isSharedCheck_887_ == 0)
{
v___x_881_ = v___x_877_;
v_isShared_882_ = v_isSharedCheck_887_;
goto v_resetjp_880_;
}
else
{
lean_inc(v_snd_879_);
lean_inc(v_fst_878_);
lean_dec(v___x_877_);
v___x_881_ = lean_box(0);
v_isShared_882_ = v_isSharedCheck_887_;
goto v_resetjp_880_;
}
v_resetjp_880_:
{
lean_object* v___x_883_; lean_object* v___x_885_; 
v___x_883_ = l_List_appendTR___redArg(v_snd_876_, v_snd_879_);
if (v_isShared_882_ == 0)
{
lean_ctor_set(v___x_881_, 1, v___x_883_);
v___x_885_ = v___x_881_;
goto v_reusejp_884_;
}
else
{
lean_object* v_reuseFailAlloc_886_; 
v_reuseFailAlloc_886_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_886_, 0, v_fst_878_);
lean_ctor_set(v_reuseFailAlloc_886_, 1, v___x_883_);
v___x_885_ = v_reuseFailAlloc_886_;
goto v_reusejp_884_;
}
v_reusejp_884_:
{
return v___x_885_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Insertion_insertionSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__3(lean_object* v_l_888_){
_start:
{
lean_object* v___x_889_; lean_object* v___x_890_; lean_object* v_fst_891_; 
v___x_889_ = lean_unsigned_to_nat(0u);
v___x_890_ = l_LeanSort_Insertion_sortTr___at___00LeanSort_Insertion_insertionSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__3_spec__5(v___x_889_, v_l_888_);
v_fst_891_ = lean_ctor_get(v___x_890_, 0);
lean_inc(v_fst_891_);
lean_dec_ref(v___x_890_);
return v_fst_891_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_HybridMerge_sort___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__4(lean_object* v_threshold_892_, lean_object* v_xs_893_){
_start:
{
lean_object* v___x_894_; lean_object* v___y_896_; lean_object* v___x_908_; uint8_t v___x_909_; 
v___x_894_ = l_List_lengthTR___redArg(v_xs_893_);
v___x_908_ = lean_unsigned_to_nat(1u);
v___x_909_ = lean_nat_dec_le(v___x_908_, v_threshold_892_);
if (v___x_909_ == 0)
{
v___y_896_ = v___x_908_;
goto v___jp_895_;
}
else
{
v___y_896_ = v_threshold_892_;
goto v___jp_895_;
}
v___jp_895_:
{
uint8_t v___x_897_; 
v___x_897_ = lean_nat_dec_le(v___x_894_, v___y_896_);
if (v___x_897_ == 0)
{
lean_object* v___x_898_; lean_object* v_middle_899_; lean_object* v___x_900_; lean_object* v___x_901_; lean_object* v___x_902_; lean_object* v___x_903_; lean_object* v___x_904_; lean_object* v___x_905_; lean_object* v_ret_906_; 
v___x_898_ = lean_unsigned_to_nat(1u);
v_middle_899_ = lean_nat_shiftr(v___x_894_, v___x_898_);
lean_dec(v___x_894_);
v___x_900_ = ((lean_object*)(l_AdaptiveExperiment_features___closed__0));
lean_inc(v_middle_899_);
lean_inc(v_xs_893_);
v___x_901_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_xs_893_, v_xs_893_, v_middle_899_, v___x_900_);
v___x_902_ = l_LeanSort_HybridMerge_sort___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__4(v_threshold_892_, v___x_901_);
v___x_903_ = l_List_drop___redArg(v_middle_899_, v_xs_893_);
lean_dec(v_xs_893_);
v___x_904_ = l_LeanSort_HybridMerge_sort___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__4(v_threshold_892_, v___x_903_);
v___x_905_ = l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5(v___x_902_, v___x_904_);
v_ret_906_ = lean_ctor_get(v___x_905_, 0);
lean_inc(v_ret_906_);
lean_dec_ref(v___x_905_);
return v_ret_906_;
}
else
{
lean_object* v___x_907_; 
lean_dec(v___x_894_);
v___x_907_ = l_LeanSort_Insertion_insertionSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__3(v_xs_893_);
return v___x_907_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_HybridMerge_sort___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__4___boxed(lean_object* v_threshold_910_, lean_object* v_xs_911_){
_start:
{
lean_object* v_res_912_; 
v_res_912_ = l_LeanSort_HybridMerge_sort___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__4(v_threshold_910_, v_xs_911_);
lean_dec(v_threshold_910_);
return v_res_912_;
}
}
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_mergeSort___at___00LeanSort_Merge_mergeSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__2_spec__3___lam__0(lean_object* v_sortedLeft_913_, lean_object* v_sortedRight_914_){
_start:
{
lean_object* v___x_915_; 
v___x_915_ = l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5(v_sortedLeft_913_, v_sortedRight_914_);
return v___x_915_;
}
}
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_mergeSort___at___00LeanSort_Merge_mergeSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__2_spec__3(lean_object* v_xs_916_){
_start:
{
lean_object* v___x_917_; lean_object* v___x_918_; uint8_t v___x_919_; 
v___x_917_ = l_List_lengthTR___redArg(v_xs_916_);
v___x_918_ = lean_unsigned_to_nat(2u);
v___x_919_ = lean_nat_dec_lt(v___x_917_, v___x_918_);
if (v___x_919_ == 0)
{
lean_object* v___x_920_; lean_object* v_half_921_; lean_object* v___x_922_; lean_object* v_left_923_; lean_object* v_right_924_; lean_object* v___f_925_; lean_object* v___x_926_; lean_object* v___x_927_; 
v___x_920_ = lean_unsigned_to_nat(1u);
v_half_921_ = lean_nat_shiftr(v___x_917_, v___x_920_);
lean_dec(v___x_917_);
v___x_922_ = ((lean_object*)(l_AdaptiveExperiment_features___closed__0));
lean_inc(v_half_921_);
lean_inc(v_xs_916_);
v_left_923_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_xs_916_, v_xs_916_, v_half_921_, v___x_922_);
v_right_924_ = l_List_drop___redArg(v_half_921_, v_xs_916_);
lean_dec(v_xs_916_);
v___f_925_ = lean_alloc_closure((void*)(l_Cslib_Algorithms_Lean_TimeM_mergeSort___at___00LeanSort_Merge_mergeSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__2_spec__3___lam__1), 2, 1);
lean_closure_set(v___f_925_, 0, v_right_924_);
v___x_926_ = l_Cslib_Algorithms_Lean_TimeM_mergeSort___at___00LeanSort_Merge_mergeSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__2_spec__3(v_left_923_);
v___x_927_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__9___redArg(v___x_926_, v___f_925_);
return v___x_927_;
}
else
{
lean_object* v___x_928_; 
lean_dec(v___x_917_);
v___x_928_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__8___redArg(v_xs_916_);
return v___x_928_;
}
}
}
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_mergeSort___at___00LeanSort_Merge_mergeSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__2_spec__3___lam__1(lean_object* v_right_929_, lean_object* v_sortedLeft_930_){
_start:
{
lean_object* v___f_931_; lean_object* v___x_932_; lean_object* v___x_933_; 
v___f_931_ = lean_alloc_closure((void*)(l_Cslib_Algorithms_Lean_TimeM_mergeSort___at___00LeanSort_Merge_mergeSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__2_spec__3___lam__0), 2, 1);
lean_closure_set(v___f_931_, 0, v_sortedLeft_930_);
v___x_932_ = l_Cslib_Algorithms_Lean_TimeM_mergeSort___at___00LeanSort_Merge_mergeSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__2_spec__3(v_right_929_);
v___x_933_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__9___redArg(v___x_932_, v___f_931_);
return v___x_933_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Merge_mergeSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__2(lean_object* v_xs_934_){
_start:
{
lean_object* v___x_935_; lean_object* v_ret_936_; 
v___x_935_ = l_Cslib_Algorithms_Lean_TimeM_mergeSort___at___00LeanSort_Merge_mergeSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__2_spec__3(v_xs_934_);
v_ret_936_ = lean_ctor_get(v___x_935_, 0);
lean_inc(v_ret_936_);
lean_dec_ref(v___x_935_);
return v_ret_936_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1(lean_object* v_x_937_, lean_object* v_x_938_){
_start:
{
switch(lean_obj_tag(v_x_937_))
{
case 0:
{
lean_object* v___x_939_; 
v___x_939_ = l_LeanSort_Merge_mergeSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__2(v_x_938_);
return v___x_939_;
}
case 1:
{
lean_object* v___x_940_; 
v___x_940_ = l_LeanSort_Insertion_insertionSortResult___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__3(v_x_938_);
return v___x_940_;
}
case 2:
{
lean_object* v_threshold_941_; lean_object* v___x_942_; 
v_threshold_941_ = lean_ctor_get(v_x_937_, 0);
lean_inc(v_threshold_941_);
lean_dec_ref_known(v_x_937_, 1);
v___x_942_ = l_LeanSort_HybridMerge_sort___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__4(v_threshold_941_, v_x_938_);
lean_dec(v_threshold_941_);
return v___x_942_;
}
default: 
{
lean_object* v_cut_943_; lean_object* v_left_944_; lean_object* v_right_945_; lean_object* v___x_946_; lean_object* v___x_947_; lean_object* v___x_948_; lean_object* v___x_949_; lean_object* v___x_950_; lean_object* v___x_951_; lean_object* v_ret_952_; 
v_cut_943_ = lean_ctor_get(v_x_937_, 0);
lean_inc_n(v_cut_943_, 2);
v_left_944_ = lean_ctor_get(v_x_937_, 1);
lean_inc(v_left_944_);
v_right_945_ = lean_ctor_get(v_x_937_, 2);
lean_inc(v_right_945_);
lean_dec_ref_known(v_x_937_, 3);
v___x_946_ = ((lean_object*)(l_AdaptiveExperiment_features___closed__0));
lean_inc(v_x_938_);
v___x_947_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_x_938_, v_x_938_, v_cut_943_, v___x_946_);
v___x_948_ = l_LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1(v_left_944_, v___x_947_);
v___x_949_ = l_List_drop___redArg(v_cut_943_, v_x_938_);
lean_dec(v_x_938_);
v___x_950_ = l_LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1(v_right_945_, v___x_949_);
v___x_951_ = l_Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5(v___x_948_, v___x_950_);
v_ret_952_ = lean_ctor_get(v___x_951_, 0);
lean_inc(v_ret_952_);
lean_dec_ref(v___x_951_);
return v_ret_952_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0(lean_object* v_proposal_953_, lean_object* v_xs_954_){
_start:
{
if (lean_obj_tag(v_proposal_953_) == 0)
{
lean_object* v___x_955_; lean_object* v___x_956_; 
v___x_955_ = lean_box(0);
v___x_956_ = l_LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1(v___x_955_, v_xs_954_);
return v___x_956_;
}
else
{
lean_object* v_val_957_; lean_object* v___x_958_; 
v_val_957_ = lean_ctor_get(v_proposal_953_, 0);
lean_inc(v_val_957_);
lean_dec_ref_known(v_proposal_953_, 1);
v___x_958_ = l_LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1(v_val_957_, v_xs_954_);
return v___x_958_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0(lean_object* v_choose_959_, lean_object* v_xs_960_){
_start:
{
lean_object* v___x_961_; lean_object* v___x_962_; 
lean_inc(v_xs_960_);
v___x_961_ = lean_apply_1(v_choose_959_, v_xs_960_);
v___x_962_ = l_LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0(v___x_961_, v_xs_960_);
return v___x_962_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_Strategy_run(lean_object* v_s_963_, lean_object* v_xs_964_){
_start:
{
lean_object* v___x_965_; lean_object* v___x_966_; 
v___x_965_ = lean_alloc_closure((void*)(l_AdaptiveExperiment_Strategy_choose), 2, 1);
lean_closure_set(v___x_965_, 0, v_s_963_);
v___x_966_ = l_LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0(v___x_965_, v_xs_964_);
return v___x_966_;
}
}
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_pure___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__8(lean_object* v_00_u03b1_967_, lean_object* v_a_968_){
_start:
{
lean_object* v___x_969_; 
v___x_969_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__8___redArg(v_a_968_);
return v___x_969_;
}
}
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_bind___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__9(lean_object* v_00_u03b1_970_, lean_object* v_00_u03b2_971_, lean_object* v_m_972_, lean_object* v_f_973_){
_start:
{
lean_object* v___x_974_; 
v___x_974_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00Cslib_Algorithms_Lean_TimeM_merge___at___00LeanSort_Adaptive_Plan_run___at___00LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0_spec__1_spec__5_spec__9___redArg(v_m_972_, v_f_973_);
return v___x_974_;
}
}
LEAN_EXPORT lean_object* l_List_foldl___at___00AdaptiveExperiment_checksum_spec__0(lean_object* v_x_975_, lean_object* v_x_976_){
_start:
{
if (lean_obj_tag(v_x_976_) == 0)
{
return v_x_975_;
}
else
{
lean_object* v_head_977_; lean_object* v_tail_978_; lean_object* v___x_979_; lean_object* v___x_980_; lean_object* v___x_981_; lean_object* v___x_982_; lean_object* v___x_983_; 
v_head_977_ = lean_ctor_get(v_x_976_, 0);
v_tail_978_ = lean_ctor_get(v_x_976_, 1);
v___x_979_ = lean_unsigned_to_nat(33u);
v___x_980_ = lean_nat_mul(v_x_975_, v___x_979_);
lean_dec(v_x_975_);
v___x_981_ = lean_nat_add(v___x_980_, v_head_977_);
lean_dec(v___x_980_);
v___x_982_ = lean_unsigned_to_nat(1000000007u);
v___x_983_ = lean_nat_mod(v___x_981_, v___x_982_);
lean_dec(v___x_981_);
v_x_975_ = v___x_983_;
v_x_976_ = v_tail_978_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_List_foldl___at___00AdaptiveExperiment_checksum_spec__0___boxed(lean_object* v_x_985_, lean_object* v_x_986_){
_start:
{
lean_object* v_res_987_; 
v_res_987_ = l_List_foldl___at___00AdaptiveExperiment_checksum_spec__0(v_x_985_, v_x_986_);
lean_dec(v_x_986_);
return v_res_987_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_checksum(lean_object* v_xs_988_){
_start:
{
lean_object* v___x_989_; lean_object* v___x_990_; 
v___x_989_ = lean_unsigned_to_nat(0u);
v___x_990_ = l_List_foldl___at___00AdaptiveExperiment_checksum_spec__0(v___x_989_, v_xs_988_);
return v___x_990_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_checksum___boxed(lean_object* v_xs_991_){
_start:
{
lean_object* v_res_992_; 
v_res_992_ = l_AdaptiveExperiment_checksum(v_xs_991_);
lean_dec(v_xs_991_);
return v_res_992_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_checkedRun(lean_object* v_sink_996_, lean_object* v_s_997_, lean_object* v_xs_998_, lean_object* v_expected_999_){
_start:
{
lean_object* v___x_1001_; lean_object* v___x_1002_; lean_object* v___x_1003_; lean_object* v___x_1004_; lean_object* v___x_1005_; uint8_t v___x_1006_; 
v___x_1001_ = lean_io_mono_nanos_now();
v___x_1002_ = l_AdaptiveExperiment_Strategy_run(v_s_997_, v_xs_998_);
v___x_1003_ = l_AdaptiveExperiment_checksum(v___x_1002_);
v___x_1004_ = lean_st_ref_set(v_sink_996_, v___x_1003_);
v___x_1005_ = lean_io_mono_nanos_now();
v___x_1006_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v___x_1002_, v_expected_999_);
lean_dec(v___x_1002_);
if (v___x_1006_ == 0)
{
lean_object* v___x_1007_; lean_object* v___x_1008_; 
lean_dec(v___x_1005_);
lean_dec(v___x_1001_);
v___x_1007_ = ((lean_object*)(l_AdaptiveExperiment_checkedRun___closed__1));
v___x_1008_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1008_, 0, v___x_1007_);
return v___x_1008_;
}
else
{
lean_object* v___x_1009_; lean_object* v___x_1010_; 
v___x_1009_ = lean_nat_sub(v___x_1005_, v___x_1001_);
lean_dec(v___x_1001_);
lean_dec(v___x_1005_);
v___x_1010_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1010_, 0, v___x_1009_);
return v___x_1010_;
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_checkedRun___boxed(lean_object* v_sink_1011_, lean_object* v_s_1012_, lean_object* v_xs_1013_, lean_object* v_expected_1014_, lean_object* v_a_1015_){
_start:
{
lean_object* v_res_1016_; 
v_res_1016_ = l_AdaptiveExperiment_checkedRun(v_sink_1011_, v_s_1012_, v_xs_1013_, v_expected_1014_);
lean_dec(v_expected_1014_);
lean_dec(v_sink_1011_);
return v_res_1016_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_timedFeatures(lean_object* v_source_1017_, lean_object* v_sink_1018_){
_start:
{
lean_object* v___x_1020_; lean_object* v___x_1021_; lean_object* v___y_1023_; lean_object* v___x_1028_; lean_object* v___x_1029_; lean_object* v___x_1030_; uint8_t v___x_1031_; 
v___x_1020_ = lean_io_mono_nanos_now();
v___x_1021_ = lean_st_ref_get(v_source_1017_);
v___x_1028_ = lean_unsigned_to_nat(0u);
v___x_1029_ = l_AdaptiveExperiment_features(v___x_1021_);
v___x_1030_ = lean_array_get_size(v___x_1029_);
v___x_1031_ = lean_nat_dec_lt(v___x_1028_, v___x_1030_);
if (v___x_1031_ == 0)
{
lean_dec_ref(v___x_1029_);
v___y_1023_ = v___x_1028_;
goto v___jp_1022_;
}
else
{
uint8_t v___x_1032_; 
v___x_1032_ = lean_nat_dec_le(v___x_1030_, v___x_1030_);
if (v___x_1032_ == 0)
{
if (v___x_1031_ == 0)
{
lean_dec_ref(v___x_1029_);
v___y_1023_ = v___x_1028_;
goto v___jp_1022_;
}
else
{
size_t v___x_1033_; size_t v___x_1034_; lean_object* v___x_1035_; 
v___x_1033_ = ((size_t)0ULL);
v___x_1034_ = lean_usize_of_nat(v___x_1030_);
v___x_1035_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_Linter_EnvLinter_formatLinterResults_spec__2(v___x_1029_, v___x_1033_, v___x_1034_, v___x_1028_);
lean_dec_ref(v___x_1029_);
v___y_1023_ = v___x_1035_;
goto v___jp_1022_;
}
}
else
{
size_t v___x_1036_; size_t v___x_1037_; lean_object* v___x_1038_; 
v___x_1036_ = ((size_t)0ULL);
v___x_1037_ = lean_usize_of_nat(v___x_1030_);
v___x_1038_ = l___private_Init_Data_Array_Basic_0__Array_foldlMUnsafe_fold___at___00Lean_Linter_EnvLinter_formatLinterResults_spec__2(v___x_1029_, v___x_1036_, v___x_1037_, v___x_1028_);
lean_dec_ref(v___x_1029_);
v___y_1023_ = v___x_1038_;
goto v___jp_1022_;
}
}
v___jp_1022_:
{
lean_object* v___x_1024_; lean_object* v___x_1025_; lean_object* v___x_1026_; lean_object* v___x_1027_; 
v___x_1024_ = lean_st_ref_set(v_sink_1018_, v___y_1023_);
v___x_1025_ = lean_io_mono_nanos_now();
v___x_1026_ = lean_nat_sub(v___x_1025_, v___x_1020_);
lean_dec(v___x_1020_);
lean_dec(v___x_1025_);
v___x_1027_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1027_, 0, v___x_1026_);
return v___x_1027_;
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_timedFeatures___boxed(lean_object* v_source_1039_, lean_object* v_sink_1040_, lean_object* v_a_1041_){
_start:
{
lean_object* v_res_1042_; 
v_res_1042_ = l_AdaptiveExperiment_timedFeatures(v_source_1039_, v_sink_1040_);
lean_dec(v_sink_1040_);
lean_dec(v_source_1039_);
return v_res_1042_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__5___redArg(lean_object* v_val_1043_, lean_object* v_xs_1044_, lean_object* v_expected_1045_, lean_object* v_as_x27_1046_, lean_object* v_b_1047_){
_start:
{
if (lean_obj_tag(v_as_x27_1046_) == 0)
{
lean_object* v___x_1049_; 
lean_dec(v_xs_1044_);
v___x_1049_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1049_, 0, v_b_1047_);
return v___x_1049_;
}
else
{
lean_object* v_head_1050_; lean_object* v_tail_1051_; lean_object* v_snd_1052_; lean_object* v___x_1053_; 
v_head_1050_ = lean_ctor_get(v_as_x27_1046_, 0);
v_tail_1051_ = lean_ctor_get(v_as_x27_1046_, 1);
v_snd_1052_ = lean_ctor_get(v_head_1050_, 1);
lean_inc(v_xs_1044_);
lean_inc(v_snd_1052_);
v___x_1053_ = l_AdaptiveExperiment_checkedRun(v_val_1043_, v_snd_1052_, v_xs_1044_, v_expected_1045_);
if (lean_obj_tag(v___x_1053_) == 0)
{
lean_object* v___x_1054_; 
lean_dec_ref_known(v___x_1053_, 1);
v___x_1054_ = lean_box(0);
v_as_x27_1046_ = v_tail_1051_;
v_b_1047_ = v___x_1054_;
goto _start;
}
else
{
lean_object* v_a_1056_; lean_object* v___x_1058_; uint8_t v_isShared_1059_; uint8_t v_isSharedCheck_1063_; 
lean_dec(v_xs_1044_);
v_a_1056_ = lean_ctor_get(v___x_1053_, 0);
v_isSharedCheck_1063_ = !lean_is_exclusive(v___x_1053_);
if (v_isSharedCheck_1063_ == 0)
{
v___x_1058_ = v___x_1053_;
v_isShared_1059_ = v_isSharedCheck_1063_;
goto v_resetjp_1057_;
}
else
{
lean_inc(v_a_1056_);
lean_dec(v___x_1053_);
v___x_1058_ = lean_box(0);
v_isShared_1059_ = v_isSharedCheck_1063_;
goto v_resetjp_1057_;
}
v_resetjp_1057_:
{
lean_object* v___x_1061_; 
if (v_isShared_1059_ == 0)
{
v___x_1061_ = v___x_1058_;
goto v_reusejp_1060_;
}
else
{
lean_object* v_reuseFailAlloc_1062_; 
v_reuseFailAlloc_1062_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1062_, 0, v_a_1056_);
v___x_1061_ = v_reuseFailAlloc_1062_;
goto v_reusejp_1060_;
}
v_reusejp_1060_:
{
return v___x_1061_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__5___redArg___boxed(lean_object* v_val_1064_, lean_object* v_xs_1065_, lean_object* v_expected_1066_, lean_object* v_as_x27_1067_, lean_object* v_b_1068_, lean_object* v___y_1069_){
_start:
{
lean_object* v_res_1070_; 
v_res_1070_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__5___redArg(v_val_1064_, v_xs_1065_, v_expected_1066_, v_as_x27_1067_, v_b_1068_);
lean_dec(v_as_x27_1067_);
lean_dec(v_expected_1066_);
lean_dec(v_val_1064_);
return v_res_1070_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__3(lean_object* v_a_1071_, lean_object* v_a_1072_){
_start:
{
if (lean_obj_tag(v_a_1071_) == 0)
{
lean_object* v___x_1073_; 
v___x_1073_ = l_List_reverse___redArg(v_a_1072_);
return v___x_1073_;
}
else
{
lean_object* v_head_1074_; lean_object* v_tail_1075_; lean_object* v___x_1077_; uint8_t v_isShared_1078_; uint8_t v_isSharedCheck_1093_; 
v_head_1074_ = lean_ctor_get(v_a_1071_, 0);
v_tail_1075_ = lean_ctor_get(v_a_1071_, 1);
v_isSharedCheck_1093_ = !lean_is_exclusive(v_a_1071_);
if (v_isSharedCheck_1093_ == 0)
{
v___x_1077_ = v_a_1071_;
v_isShared_1078_ = v_isSharedCheck_1093_;
goto v_resetjp_1076_;
}
else
{
lean_inc(v_tail_1075_);
lean_inc(v_head_1074_);
lean_dec(v_a_1071_);
v___x_1077_ = lean_box(0);
v_isShared_1078_ = v_isSharedCheck_1093_;
goto v_resetjp_1076_;
}
v_resetjp_1076_:
{
lean_object* v_fst_1079_; lean_object* v___x_1081_; uint8_t v_isShared_1082_; uint8_t v_isSharedCheck_1091_; 
v_fst_1079_ = lean_ctor_get(v_head_1074_, 0);
v_isSharedCheck_1091_ = !lean_is_exclusive(v_head_1074_);
if (v_isSharedCheck_1091_ == 0)
{
lean_object* v_unused_1092_; 
v_unused_1092_ = lean_ctor_get(v_head_1074_, 1);
lean_dec(v_unused_1092_);
v___x_1081_ = v_head_1074_;
v_isShared_1082_ = v_isSharedCheck_1091_;
goto v_resetjp_1080_;
}
else
{
lean_inc(v_fst_1079_);
lean_dec(v_head_1074_);
v___x_1081_ = lean_box(0);
v_isShared_1082_ = v_isSharedCheck_1091_;
goto v_resetjp_1080_;
}
v_resetjp_1080_:
{
lean_object* v___x_1083_; lean_object* v___x_1085_; 
v___x_1083_ = lean_box(0);
if (v_isShared_1082_ == 0)
{
lean_ctor_set(v___x_1081_, 1, v___x_1083_);
v___x_1085_ = v___x_1081_;
goto v_reusejp_1084_;
}
else
{
lean_object* v_reuseFailAlloc_1090_; 
v_reuseFailAlloc_1090_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1090_, 0, v_fst_1079_);
lean_ctor_set(v_reuseFailAlloc_1090_, 1, v___x_1083_);
v___x_1085_ = v_reuseFailAlloc_1090_;
goto v_reusejp_1084_;
}
v_reusejp_1084_:
{
lean_object* v___x_1087_; 
if (v_isShared_1078_ == 0)
{
lean_ctor_set(v___x_1077_, 1, v_a_1072_);
lean_ctor_set(v___x_1077_, 0, v___x_1085_);
v___x_1087_ = v___x_1077_;
goto v_reusejp_1086_;
}
else
{
lean_object* v_reuseFailAlloc_1089_; 
v_reuseFailAlloc_1089_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1089_, 0, v___x_1085_);
lean_ctor_set(v_reuseFailAlloc_1089_, 1, v_a_1072_);
v___x_1087_ = v_reuseFailAlloc_1089_;
goto v_reusejp_1086_;
}
v_reusejp_1086_:
{
v_a_1071_ = v_tail_1075_;
v_a_1072_ = v___x_1087_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00AdaptiveExperiment_benchmark_spec__0(lean_object* v_a_1094_){
_start:
{
lean_object* v___x_1095_; lean_object* v___x_1096_; 
v___x_1095_ = lean_array_mk(v_a_1094_);
v___x_1096_ = l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__0(v___x_1095_);
return v___x_1096_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__7(lean_object* v_a_1099_, lean_object* v_a_1100_){
_start:
{
if (lean_obj_tag(v_a_1099_) == 0)
{
lean_object* v___x_1101_; 
v___x_1101_ = l_List_reverse___redArg(v_a_1100_);
return v___x_1101_;
}
else
{
lean_object* v_head_1102_; lean_object* v_tail_1103_; lean_object* v___x_1105_; uint8_t v_isShared_1106_; uint8_t v_isSharedCheck_1130_; 
v_head_1102_ = lean_ctor_get(v_a_1099_, 0);
v_tail_1103_ = lean_ctor_get(v_a_1099_, 1);
v_isSharedCheck_1130_ = !lean_is_exclusive(v_a_1099_);
if (v_isSharedCheck_1130_ == 0)
{
v___x_1105_ = v_a_1099_;
v_isShared_1106_ = v_isSharedCheck_1130_;
goto v_resetjp_1104_;
}
else
{
lean_inc(v_tail_1103_);
lean_inc(v_head_1102_);
lean_dec(v_a_1099_);
v___x_1105_ = lean_box(0);
v_isShared_1106_ = v_isSharedCheck_1130_;
goto v_resetjp_1104_;
}
v_resetjp_1104_:
{
lean_object* v_fst_1107_; lean_object* v_snd_1108_; lean_object* v___x_1110_; uint8_t v_isShared_1111_; uint8_t v_isSharedCheck_1129_; 
v_fst_1107_ = lean_ctor_get(v_head_1102_, 0);
v_snd_1108_ = lean_ctor_get(v_head_1102_, 1);
v_isSharedCheck_1129_ = !lean_is_exclusive(v_head_1102_);
if (v_isSharedCheck_1129_ == 0)
{
v___x_1110_ = v_head_1102_;
v_isShared_1111_ = v_isSharedCheck_1129_;
goto v_resetjp_1109_;
}
else
{
lean_inc(v_snd_1108_);
lean_inc(v_fst_1107_);
lean_dec(v_head_1102_);
v___x_1110_ = lean_box(0);
v_isShared_1111_ = v_isSharedCheck_1129_;
goto v_resetjp_1109_;
}
v_resetjp_1109_:
{
lean_object* v___x_1112_; lean_object* v___x_1113_; lean_object* v___x_1115_; 
v___x_1112_ = ((lean_object*)(l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__7___closed__0));
v___x_1113_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1113_, 0, v_fst_1107_);
if (v_isShared_1111_ == 0)
{
lean_ctor_set(v___x_1110_, 1, v___x_1113_);
lean_ctor_set(v___x_1110_, 0, v___x_1112_);
v___x_1115_ = v___x_1110_;
goto v_reusejp_1114_;
}
else
{
lean_object* v_reuseFailAlloc_1128_; 
v_reuseFailAlloc_1128_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1128_, 0, v___x_1112_);
lean_ctor_set(v_reuseFailAlloc_1128_, 1, v___x_1113_);
v___x_1115_ = v_reuseFailAlloc_1128_;
goto v_reusejp_1114_;
}
v_reusejp_1114_:
{
lean_object* v___x_1116_; lean_object* v___x_1117_; lean_object* v___x_1118_; lean_object* v___x_1119_; lean_object* v___x_1120_; lean_object* v___x_1122_; 
v___x_1116_ = ((lean_object*)(l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__7___closed__1));
v___x_1117_ = l_List_reverse___redArg(v_snd_1108_);
v___x_1118_ = l_Lean_List_toJson___at___00AdaptiveExperiment_benchmark_spec__0(v___x_1117_);
v___x_1119_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1119_, 0, v___x_1116_);
lean_ctor_set(v___x_1119_, 1, v___x_1118_);
v___x_1120_ = lean_box(0);
if (v_isShared_1106_ == 0)
{
lean_ctor_set(v___x_1105_, 1, v___x_1120_);
lean_ctor_set(v___x_1105_, 0, v___x_1119_);
v___x_1122_ = v___x_1105_;
goto v_reusejp_1121_;
}
else
{
lean_object* v_reuseFailAlloc_1127_; 
v_reuseFailAlloc_1127_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1127_, 0, v___x_1119_);
lean_ctor_set(v_reuseFailAlloc_1127_, 1, v___x_1120_);
v___x_1122_ = v_reuseFailAlloc_1127_;
goto v_reusejp_1121_;
}
v_reusejp_1121_:
{
lean_object* v___x_1123_; lean_object* v___x_1124_; lean_object* v___x_1125_; 
v___x_1123_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1123_, 0, v___x_1115_);
lean_ctor_set(v___x_1123_, 1, v___x_1122_);
v___x_1124_ = l_Lean_Json_mkObj(v___x_1123_);
lean_dec_ref_known(v___x_1123_, 2);
v___x_1125_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1125_, 0, v___x_1124_);
lean_ctor_set(v___x_1125_, 1, v_a_1100_);
v_a_1099_ = v_tail_1103_;
v_a_1100_ = v___x_1125_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__1(lean_object* v_fst_1131_, lean_object* v_a_1132_, lean_object* v_a_1133_, lean_object* v_a_1134_){
_start:
{
if (lean_obj_tag(v_a_1133_) == 0)
{
lean_object* v___x_1135_; 
lean_dec(v_a_1132_);
v___x_1135_ = l_List_reverse___redArg(v_a_1134_);
return v___x_1135_;
}
else
{
lean_object* v_head_1136_; lean_object* v_tail_1137_; lean_object* v___x_1139_; uint8_t v_isShared_1140_; uint8_t v_isSharedCheck_1160_; 
v_head_1136_ = lean_ctor_get(v_a_1133_, 0);
v_tail_1137_ = lean_ctor_get(v_a_1133_, 1);
v_isSharedCheck_1160_ = !lean_is_exclusive(v_a_1133_);
if (v_isSharedCheck_1160_ == 0)
{
v___x_1139_ = v_a_1133_;
v_isShared_1140_ = v_isSharedCheck_1160_;
goto v_resetjp_1138_;
}
else
{
lean_inc(v_tail_1137_);
lean_inc(v_head_1136_);
lean_dec(v_a_1133_);
v___x_1139_ = lean_box(0);
v_isShared_1140_ = v_isSharedCheck_1160_;
goto v_resetjp_1138_;
}
v_resetjp_1138_:
{
lean_object* v___y_1142_; lean_object* v_fst_1147_; lean_object* v_snd_1148_; uint8_t v___x_1149_; 
v_fst_1147_ = lean_ctor_get(v_head_1136_, 0);
v_snd_1148_ = lean_ctor_get(v_head_1136_, 1);
v___x_1149_ = lean_string_dec_eq(v_fst_1131_, v_fst_1147_);
if (v___x_1149_ == 0)
{
v___y_1142_ = v_head_1136_;
goto v___jp_1141_;
}
else
{
lean_object* v___x_1151_; uint8_t v_isShared_1152_; uint8_t v_isSharedCheck_1157_; 
lean_inc(v_snd_1148_);
lean_inc(v_fst_1147_);
v_isSharedCheck_1157_ = !lean_is_exclusive(v_head_1136_);
if (v_isSharedCheck_1157_ == 0)
{
lean_object* v_unused_1158_; lean_object* v_unused_1159_; 
v_unused_1158_ = lean_ctor_get(v_head_1136_, 1);
lean_dec(v_unused_1158_);
v_unused_1159_ = lean_ctor_get(v_head_1136_, 0);
lean_dec(v_unused_1159_);
v___x_1151_ = v_head_1136_;
v_isShared_1152_ = v_isSharedCheck_1157_;
goto v_resetjp_1150_;
}
else
{
lean_dec(v_head_1136_);
v___x_1151_ = lean_box(0);
v_isShared_1152_ = v_isSharedCheck_1157_;
goto v_resetjp_1150_;
}
v_resetjp_1150_:
{
lean_object* v___x_1153_; lean_object* v___x_1155_; 
lean_inc(v_a_1132_);
v___x_1153_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1153_, 0, v_a_1132_);
lean_ctor_set(v___x_1153_, 1, v_snd_1148_);
if (v_isShared_1152_ == 0)
{
lean_ctor_set(v___x_1151_, 1, v___x_1153_);
v___x_1155_ = v___x_1151_;
goto v_reusejp_1154_;
}
else
{
lean_object* v_reuseFailAlloc_1156_; 
v_reuseFailAlloc_1156_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1156_, 0, v_fst_1147_);
lean_ctor_set(v_reuseFailAlloc_1156_, 1, v___x_1153_);
v___x_1155_ = v_reuseFailAlloc_1156_;
goto v_reusejp_1154_;
}
v_reusejp_1154_:
{
v___y_1142_ = v___x_1155_;
goto v___jp_1141_;
}
}
}
v___jp_1141_:
{
lean_object* v___x_1144_; 
if (v_isShared_1140_ == 0)
{
lean_ctor_set(v___x_1139_, 1, v_a_1134_);
lean_ctor_set(v___x_1139_, 0, v___y_1142_);
v___x_1144_ = v___x_1139_;
goto v_reusejp_1143_;
}
else
{
lean_object* v_reuseFailAlloc_1146_; 
v_reuseFailAlloc_1146_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1146_, 0, v___y_1142_);
lean_ctor_set(v_reuseFailAlloc_1146_, 1, v_a_1134_);
v___x_1144_ = v_reuseFailAlloc_1146_;
goto v_reusejp_1143_;
}
v_reusejp_1143_:
{
v_a_1133_ = v_tail_1137_;
v_a_1134_ = v___x_1144_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__1___boxed(lean_object* v_fst_1161_, lean_object* v_a_1162_, lean_object* v_a_1163_, lean_object* v_a_1164_){
_start:
{
lean_object* v_res_1165_; 
v_res_1165_ = l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__1(v_fst_1161_, v_a_1162_, v_a_1163_, v_a_1164_);
lean_dec_ref(v_fst_1161_);
return v_res_1165_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__2___redArg(lean_object* v_val_1166_, lean_object* v_snd_1167_, lean_object* v_xs_1168_, lean_object* v_expected_1169_, lean_object* v_fst_1170_, lean_object* v_as_x27_1171_, lean_object* v_b_1172_){
_start:
{
if (lean_obj_tag(v_as_x27_1171_) == 0)
{
lean_object* v___x_1174_; 
lean_dec(v_xs_1168_);
lean_dec(v_snd_1167_);
v___x_1174_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1174_, 0, v_b_1172_);
return v___x_1174_;
}
else
{
lean_object* v_tail_1175_; lean_object* v___x_1176_; 
v_tail_1175_ = lean_ctor_get(v_as_x27_1171_, 1);
lean_inc(v_xs_1168_);
lean_inc(v_snd_1167_);
v___x_1176_ = l_AdaptiveExperiment_checkedRun(v_val_1166_, v_snd_1167_, v_xs_1168_, v_expected_1169_);
if (lean_obj_tag(v___x_1176_) == 0)
{
lean_object* v_a_1177_; lean_object* v___x_1178_; lean_object* v___x_1179_; 
v_a_1177_ = lean_ctor_get(v___x_1176_, 0);
lean_inc(v_a_1177_);
lean_dec_ref_known(v___x_1176_, 1);
v___x_1178_ = lean_box(0);
v___x_1179_ = l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__1(v_fst_1170_, v_a_1177_, v_b_1172_, v___x_1178_);
v_as_x27_1171_ = v_tail_1175_;
v_b_1172_ = v___x_1179_;
goto _start;
}
else
{
lean_object* v_a_1181_; lean_object* v___x_1183_; uint8_t v_isShared_1184_; uint8_t v_isSharedCheck_1188_; 
lean_dec(v_b_1172_);
lean_dec(v_xs_1168_);
lean_dec(v_snd_1167_);
v_a_1181_ = lean_ctor_get(v___x_1176_, 0);
v_isSharedCheck_1188_ = !lean_is_exclusive(v___x_1176_);
if (v_isSharedCheck_1188_ == 0)
{
v___x_1183_ = v___x_1176_;
v_isShared_1184_ = v_isSharedCheck_1188_;
goto v_resetjp_1182_;
}
else
{
lean_inc(v_a_1181_);
lean_dec(v___x_1176_);
v___x_1183_ = lean_box(0);
v_isShared_1184_ = v_isSharedCheck_1188_;
goto v_resetjp_1182_;
}
v_resetjp_1182_:
{
lean_object* v___x_1186_; 
if (v_isShared_1184_ == 0)
{
v___x_1186_ = v___x_1183_;
goto v_reusejp_1185_;
}
else
{
lean_object* v_reuseFailAlloc_1187_; 
v_reuseFailAlloc_1187_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1187_, 0, v_a_1181_);
v___x_1186_ = v_reuseFailAlloc_1187_;
goto v_reusejp_1185_;
}
v_reusejp_1185_:
{
return v___x_1186_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__2___redArg___boxed(lean_object* v_val_1189_, lean_object* v_snd_1190_, lean_object* v_xs_1191_, lean_object* v_expected_1192_, lean_object* v_fst_1193_, lean_object* v_as_x27_1194_, lean_object* v_b_1195_, lean_object* v___y_1196_){
_start:
{
lean_object* v_res_1197_; 
v_res_1197_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__2___redArg(v_val_1189_, v_snd_1190_, v_xs_1191_, v_expected_1192_, v_fst_1193_, v_as_x27_1194_, v_b_1195_);
lean_dec(v_as_x27_1194_);
lean_dec_ref(v_fst_1193_);
lean_dec(v_expected_1192_);
lean_dec(v_val_1189_);
return v_res_1197_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4_spec__4___redArg(lean_object* v_inner_1198_, lean_object* v_val_1199_, lean_object* v_xs_1200_, lean_object* v_expected_1201_, lean_object* v_as_x27_1202_, lean_object* v_b_1203_){
_start:
{
if (lean_obj_tag(v_as_x27_1202_) == 0)
{
lean_object* v___x_1205_; 
lean_dec(v_xs_1200_);
lean_dec(v_inner_1198_);
v___x_1205_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1205_, 0, v_b_1203_);
return v___x_1205_;
}
else
{
lean_object* v_head_1206_; lean_object* v_tail_1207_; lean_object* v_fst_1208_; lean_object* v_snd_1209_; lean_object* v___x_1210_; lean_object* v___x_1211_; 
v_head_1206_ = lean_ctor_get(v_as_x27_1202_, 0);
v_tail_1207_ = lean_ctor_get(v_as_x27_1202_, 1);
v_fst_1208_ = lean_ctor_get(v_head_1206_, 0);
v_snd_1209_ = lean_ctor_get(v_head_1206_, 1);
lean_inc(v_inner_1198_);
v___x_1210_ = l_List_range(v_inner_1198_);
lean_inc(v_xs_1200_);
lean_inc(v_snd_1209_);
v___x_1211_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__2___redArg(v_val_1199_, v_snd_1209_, v_xs_1200_, v_expected_1201_, v_fst_1208_, v___x_1210_, v_b_1203_);
lean_dec(v___x_1210_);
if (lean_obj_tag(v___x_1211_) == 0)
{
lean_object* v_a_1212_; 
v_a_1212_ = lean_ctor_get(v___x_1211_, 0);
lean_inc(v_a_1212_);
lean_dec_ref_known(v___x_1211_, 1);
v_as_x27_1202_ = v_tail_1207_;
v_b_1203_ = v_a_1212_;
goto _start;
}
else
{
lean_dec(v_xs_1200_);
lean_dec(v_inner_1198_);
return v___x_1211_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4_spec__4___redArg___boxed(lean_object* v_inner_1214_, lean_object* v_val_1215_, lean_object* v_xs_1216_, lean_object* v_expected_1217_, lean_object* v_as_x27_1218_, lean_object* v_b_1219_, lean_object* v___y_1220_){
_start:
{
lean_object* v_res_1221_; 
v_res_1221_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4_spec__4___redArg(v_inner_1214_, v_val_1215_, v_xs_1216_, v_expected_1217_, v_as_x27_1218_, v_b_1219_);
lean_dec(v_as_x27_1218_);
lean_dec(v_expected_1217_);
lean_dec(v_val_1215_);
return v_res_1221_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4___redArg(lean_object* v_val_1222_, lean_object* v_xs_1223_, lean_object* v_expected_1224_, lean_object* v_inner_1225_, lean_object* v_as_1226_, lean_object* v_as_x27_1227_, lean_object* v_b_1228_){
_start:
{
if (lean_obj_tag(v_as_x27_1227_) == 0)
{
lean_object* v___x_1230_; 
lean_dec(v_inner_1225_);
lean_dec(v_xs_1223_);
v___x_1230_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1230_, 0, v_b_1228_);
return v___x_1230_;
}
else
{
lean_object* v_head_1231_; lean_object* v_tail_1232_; lean_object* v_fst_1233_; lean_object* v_snd_1234_; lean_object* v___x_1235_; lean_object* v___x_1236_; 
v_head_1231_ = lean_ctor_get(v_as_x27_1227_, 0);
v_tail_1232_ = lean_ctor_get(v_as_x27_1227_, 1);
v_fst_1233_ = lean_ctor_get(v_head_1231_, 0);
v_snd_1234_ = lean_ctor_get(v_head_1231_, 1);
lean_inc(v_inner_1225_);
v___x_1235_ = l_List_range(v_inner_1225_);
lean_inc(v_xs_1223_);
lean_inc(v_snd_1234_);
v___x_1236_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__2___redArg(v_val_1222_, v_snd_1234_, v_xs_1223_, v_expected_1224_, v_fst_1233_, v___x_1235_, v_b_1228_);
lean_dec(v___x_1235_);
if (lean_obj_tag(v___x_1236_) == 0)
{
lean_object* v_a_1237_; lean_object* v___x_1238_; 
v_a_1237_ = lean_ctor_get(v___x_1236_, 0);
lean_inc(v_a_1237_);
lean_dec_ref_known(v___x_1236_, 1);
v___x_1238_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4_spec__4___redArg(v_inner_1225_, v_val_1222_, v_xs_1223_, v_expected_1224_, v_tail_1232_, v_a_1237_);
return v___x_1238_;
}
else
{
lean_dec(v_inner_1225_);
lean_dec(v_xs_1223_);
return v___x_1236_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4___redArg___boxed(lean_object* v_val_1239_, lean_object* v_xs_1240_, lean_object* v_expected_1241_, lean_object* v_inner_1242_, lean_object* v_as_1243_, lean_object* v_as_x27_1244_, lean_object* v_b_1245_, lean_object* v___y_1246_){
_start:
{
lean_object* v_res_1247_; 
v_res_1247_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4___redArg(v_val_1239_, v_xs_1240_, v_expected_1241_, v_inner_1242_, v_as_1243_, v_as_x27_1244_, v_b_1245_);
lean_dec(v_as_x27_1244_);
lean_dec(v_as_1243_);
lean_dec(v_expected_1241_);
lean_dec(v_val_1239_);
return v_res_1247_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6___redArg(lean_object* v_val_1250_, lean_object* v_xs_1251_, lean_object* v_expected_1252_, lean_object* v_inner_1253_, lean_object* v___x_1254_, lean_object* v_as_x27_1255_, lean_object* v_b_1256_){
_start:
{
if (lean_obj_tag(v_as_x27_1255_) == 0)
{
lean_object* v___x_1258_; 
lean_dec(v___x_1254_);
lean_dec(v_inner_1253_);
lean_dec(v_xs_1251_);
v___x_1258_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1258_, 0, v_b_1256_);
return v___x_1258_;
}
else
{
lean_object* v_head_1259_; lean_object* v_tail_1260_; lean_object* v___y_1262_; lean_object* v___x_1266_; lean_object* v___x_1267_; lean_object* v___x_1268_; lean_object* v___x_1269_; lean_object* v___x_1270_; lean_object* v___x_1271_; lean_object* v___x_1272_; lean_object* v___x_1273_; lean_object* v___x_1274_; uint8_t v___x_1275_; 
v_head_1259_ = lean_ctor_get(v_as_x27_1255_, 0);
v_tail_1260_ = lean_ctor_get(v_as_x27_1255_, 1);
v___x_1266_ = lean_unsigned_to_nat(0u);
v___x_1267_ = l_List_lengthTR___redArg(v___x_1254_);
v___x_1268_ = lean_nat_mod(v_head_1259_, v___x_1267_);
lean_dec(v___x_1267_);
lean_inc(v___x_1268_);
v___x_1269_ = l_List_drop___redArg(v___x_1268_, v___x_1254_);
v___x_1270_ = ((lean_object*)(l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6___redArg___closed__0));
lean_inc(v___x_1254_);
v___x_1271_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v___x_1254_, v___x_1254_, v___x_1268_, v___x_1270_);
v___x_1272_ = l_List_appendTR___redArg(v___x_1269_, v___x_1271_);
v___x_1273_ = lean_unsigned_to_nat(2u);
v___x_1274_ = lean_nat_mod(v_head_1259_, v___x_1273_);
v___x_1275_ = lean_nat_dec_eq(v___x_1274_, v___x_1266_);
lean_dec(v___x_1274_);
if (v___x_1275_ == 0)
{
lean_object* v___x_1276_; 
v___x_1276_ = l_List_reverse___redArg(v___x_1272_);
v___y_1262_ = v___x_1276_;
goto v___jp_1261_;
}
else
{
v___y_1262_ = v___x_1272_;
goto v___jp_1261_;
}
v___jp_1261_:
{
lean_object* v___x_1263_; 
lean_inc(v_inner_1253_);
lean_inc(v_xs_1251_);
v___x_1263_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4___redArg(v_val_1250_, v_xs_1251_, v_expected_1252_, v_inner_1253_, v___y_1262_, v___y_1262_, v_b_1256_);
lean_dec(v___y_1262_);
if (lean_obj_tag(v___x_1263_) == 0)
{
lean_object* v_a_1264_; 
v_a_1264_ = lean_ctor_get(v___x_1263_, 0);
lean_inc(v_a_1264_);
lean_dec_ref_known(v___x_1263_, 1);
v_as_x27_1255_ = v_tail_1260_;
v_b_1256_ = v_a_1264_;
goto _start;
}
else
{
lean_dec(v___x_1254_);
lean_dec(v_inner_1253_);
lean_dec(v_xs_1251_);
return v___x_1263_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6___redArg___boxed(lean_object* v_val_1277_, lean_object* v_xs_1278_, lean_object* v_expected_1279_, lean_object* v_inner_1280_, lean_object* v___x_1281_, lean_object* v_as_x27_1282_, lean_object* v_b_1283_, lean_object* v___y_1284_){
_start:
{
lean_object* v_res_1285_; 
v_res_1285_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6___redArg(v_val_1277_, v_xs_1278_, v_expected_1279_, v_inner_1280_, v___x_1281_, v_as_x27_1282_, v_b_1283_);
lean_dec(v_as_x27_1282_);
lean_dec(v_expected_1279_);
lean_dec(v_val_1277_);
return v_res_1285_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_benchmark(lean_object* v_strategies_1286_, lean_object* v_xs_1287_, lean_object* v_expected_1288_, lean_object* v_rounds_1289_, lean_object* v_inner_1290_, lean_object* v_orderSeed_1291_){
_start:
{
lean_object* v___x_1293_; lean_object* v___x_1294_; lean_object* v___x_1295_; lean_object* v___x_1296_; lean_object* v___x_1297_; lean_object* v___x_1298_; lean_object* v___x_1299_; lean_object* v___x_1300_; lean_object* v___x_1301_; lean_object* v___x_1302_; lean_object* v___x_1303_; lean_object* v___x_1304_; 
v___x_1293_ = lean_unsigned_to_nat(0u);
v___x_1294_ = lean_st_mk_ref(v___x_1293_);
v___x_1295_ = lean_box(0);
lean_inc_n(v_strategies_1286_, 2);
v___x_1296_ = l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__3(v_strategies_1286_, v___x_1295_);
v___x_1297_ = l_List_lengthTR___redArg(v_strategies_1286_);
v___x_1298_ = lean_nat_mod(v_orderSeed_1291_, v___x_1297_);
lean_dec(v___x_1297_);
lean_inc(v___x_1298_);
v___x_1299_ = l_List_drop___redArg(v___x_1298_, v_strategies_1286_);
v___x_1300_ = ((lean_object*)(l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6___redArg___closed__0));
v___x_1301_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_strategies_1286_, v_strategies_1286_, v___x_1298_, v___x_1300_);
lean_dec(v_strategies_1286_);
v___x_1302_ = l_List_appendTR___redArg(v___x_1299_, v___x_1301_);
v___x_1303_ = lean_box(0);
lean_inc(v_xs_1287_);
v___x_1304_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__5___redArg(v___x_1294_, v_xs_1287_, v_expected_1288_, v___x_1302_, v___x_1303_);
if (lean_obj_tag(v___x_1304_) == 0)
{
lean_object* v___x_1305_; lean_object* v___x_1306_; 
lean_dec_ref_known(v___x_1304_, 1);
v___x_1305_ = l_List_range(v_rounds_1289_);
v___x_1306_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6___redArg(v___x_1294_, v_xs_1287_, v_expected_1288_, v_inner_1290_, v___x_1302_, v___x_1305_, v___x_1296_);
lean_dec(v___x_1305_);
lean_dec(v___x_1294_);
if (lean_obj_tag(v___x_1306_) == 0)
{
lean_object* v_a_1307_; lean_object* v___x_1309_; uint8_t v_isShared_1310_; uint8_t v_isSharedCheck_1316_; 
v_a_1307_ = lean_ctor_get(v___x_1306_, 0);
v_isSharedCheck_1316_ = !lean_is_exclusive(v___x_1306_);
if (v_isSharedCheck_1316_ == 0)
{
v___x_1309_ = v___x_1306_;
v_isShared_1310_ = v_isSharedCheck_1316_;
goto v_resetjp_1308_;
}
else
{
lean_inc(v_a_1307_);
lean_dec(v___x_1306_);
v___x_1309_ = lean_box(0);
v_isShared_1310_ = v_isSharedCheck_1316_;
goto v_resetjp_1308_;
}
v_resetjp_1308_:
{
lean_object* v___x_1311_; lean_object* v___x_1312_; lean_object* v___x_1314_; 
v___x_1311_ = l_List_mapTR_loop___at___00AdaptiveExperiment_benchmark_spec__7(v_a_1307_, v___x_1295_);
v___x_1312_ = l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(v___x_1311_);
if (v_isShared_1310_ == 0)
{
lean_ctor_set(v___x_1309_, 0, v___x_1312_);
v___x_1314_ = v___x_1309_;
goto v_reusejp_1313_;
}
else
{
lean_object* v_reuseFailAlloc_1315_; 
v_reuseFailAlloc_1315_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1315_, 0, v___x_1312_);
v___x_1314_ = v_reuseFailAlloc_1315_;
goto v_reusejp_1313_;
}
v_reusejp_1313_:
{
return v___x_1314_;
}
}
}
else
{
lean_object* v_a_1317_; lean_object* v___x_1319_; uint8_t v_isShared_1320_; uint8_t v_isSharedCheck_1324_; 
v_a_1317_ = lean_ctor_get(v___x_1306_, 0);
v_isSharedCheck_1324_ = !lean_is_exclusive(v___x_1306_);
if (v_isSharedCheck_1324_ == 0)
{
v___x_1319_ = v___x_1306_;
v_isShared_1320_ = v_isSharedCheck_1324_;
goto v_resetjp_1318_;
}
else
{
lean_inc(v_a_1317_);
lean_dec(v___x_1306_);
v___x_1319_ = lean_box(0);
v_isShared_1320_ = v_isSharedCheck_1324_;
goto v_resetjp_1318_;
}
v_resetjp_1318_:
{
lean_object* v___x_1322_; 
if (v_isShared_1320_ == 0)
{
v___x_1322_ = v___x_1319_;
goto v_reusejp_1321_;
}
else
{
lean_object* v_reuseFailAlloc_1323_; 
v_reuseFailAlloc_1323_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1323_, 0, v_a_1317_);
v___x_1322_ = v_reuseFailAlloc_1323_;
goto v_reusejp_1321_;
}
v_reusejp_1321_:
{
return v___x_1322_;
}
}
}
}
else
{
lean_object* v_a_1325_; lean_object* v___x_1327_; uint8_t v_isShared_1328_; uint8_t v_isSharedCheck_1332_; 
lean_dec(v___x_1302_);
lean_dec(v___x_1296_);
lean_dec(v___x_1294_);
lean_dec(v_inner_1290_);
lean_dec(v_rounds_1289_);
lean_dec(v_xs_1287_);
v_a_1325_ = lean_ctor_get(v___x_1304_, 0);
v_isSharedCheck_1332_ = !lean_is_exclusive(v___x_1304_);
if (v_isSharedCheck_1332_ == 0)
{
v___x_1327_ = v___x_1304_;
v_isShared_1328_ = v_isSharedCheck_1332_;
goto v_resetjp_1326_;
}
else
{
lean_inc(v_a_1325_);
lean_dec(v___x_1304_);
v___x_1327_ = lean_box(0);
v_isShared_1328_ = v_isSharedCheck_1332_;
goto v_resetjp_1326_;
}
v_resetjp_1326_:
{
lean_object* v___x_1330_; 
if (v_isShared_1328_ == 0)
{
v___x_1330_ = v___x_1327_;
goto v_reusejp_1329_;
}
else
{
lean_object* v_reuseFailAlloc_1331_; 
v_reuseFailAlloc_1331_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1331_, 0, v_a_1325_);
v___x_1330_ = v_reuseFailAlloc_1331_;
goto v_reusejp_1329_;
}
v_reusejp_1329_:
{
return v___x_1330_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_benchmark___boxed(lean_object* v_strategies_1333_, lean_object* v_xs_1334_, lean_object* v_expected_1335_, lean_object* v_rounds_1336_, lean_object* v_inner_1337_, lean_object* v_orderSeed_1338_, lean_object* v_a_1339_){
_start:
{
lean_object* v_res_1340_; 
v_res_1340_ = l_AdaptiveExperiment_benchmark(v_strategies_1333_, v_xs_1334_, v_expected_1335_, v_rounds_1336_, v_inner_1337_, v_orderSeed_1338_);
lean_dec(v_orderSeed_1338_);
lean_dec(v_expected_1335_);
return v_res_1340_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__2(lean_object* v_val_1341_, lean_object* v_snd_1342_, lean_object* v_xs_1343_, lean_object* v_expected_1344_, lean_object* v_fst_1345_, lean_object* v_as_1346_, lean_object* v_as_x27_1347_, lean_object* v_b_1348_, lean_object* v_a_1349_){
_start:
{
lean_object* v___x_1351_; 
v___x_1351_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__2___redArg(v_val_1341_, v_snd_1342_, v_xs_1343_, v_expected_1344_, v_fst_1345_, v_as_x27_1347_, v_b_1348_);
return v___x_1351_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__2___boxed(lean_object* v_val_1352_, lean_object* v_snd_1353_, lean_object* v_xs_1354_, lean_object* v_expected_1355_, lean_object* v_fst_1356_, lean_object* v_as_1357_, lean_object* v_as_x27_1358_, lean_object* v_b_1359_, lean_object* v_a_1360_, lean_object* v___y_1361_){
_start:
{
lean_object* v_res_1362_; 
v_res_1362_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__2(v_val_1352_, v_snd_1353_, v_xs_1354_, v_expected_1355_, v_fst_1356_, v_as_1357_, v_as_x27_1358_, v_b_1359_, v_a_1360_);
lean_dec(v_as_x27_1358_);
lean_dec(v_as_1357_);
lean_dec_ref(v_fst_1356_);
lean_dec(v_expected_1355_);
lean_dec(v_val_1352_);
return v_res_1362_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4(lean_object* v_val_1363_, lean_object* v_xs_1364_, lean_object* v_expected_1365_, lean_object* v_inner_1366_, lean_object* v_as_1367_, lean_object* v_as_x27_1368_, lean_object* v_b_1369_, lean_object* v_a_1370_){
_start:
{
lean_object* v___x_1372_; 
v___x_1372_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4___redArg(v_val_1363_, v_xs_1364_, v_expected_1365_, v_inner_1366_, v_as_1367_, v_as_x27_1368_, v_b_1369_);
return v___x_1372_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4___boxed(lean_object* v_val_1373_, lean_object* v_xs_1374_, lean_object* v_expected_1375_, lean_object* v_inner_1376_, lean_object* v_as_1377_, lean_object* v_as_x27_1378_, lean_object* v_b_1379_, lean_object* v_a_1380_, lean_object* v___y_1381_){
_start:
{
lean_object* v_res_1382_; 
v_res_1382_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4(v_val_1373_, v_xs_1374_, v_expected_1375_, v_inner_1376_, v_as_1377_, v_as_x27_1378_, v_b_1379_, v_a_1380_);
lean_dec(v_as_x27_1378_);
lean_dec(v_as_1377_);
lean_dec(v_expected_1375_);
lean_dec(v_val_1373_);
return v_res_1382_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__5(lean_object* v_val_1383_, lean_object* v_xs_1384_, lean_object* v_expected_1385_, lean_object* v_as_1386_, lean_object* v_as_x27_1387_, lean_object* v_b_1388_, lean_object* v_a_1389_){
_start:
{
lean_object* v___x_1391_; 
v___x_1391_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__5___redArg(v_val_1383_, v_xs_1384_, v_expected_1385_, v_as_x27_1387_, v_b_1388_);
return v___x_1391_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__5___boxed(lean_object* v_val_1392_, lean_object* v_xs_1393_, lean_object* v_expected_1394_, lean_object* v_as_1395_, lean_object* v_as_x27_1396_, lean_object* v_b_1397_, lean_object* v_a_1398_, lean_object* v___y_1399_){
_start:
{
lean_object* v_res_1400_; 
v_res_1400_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__5(v_val_1392_, v_xs_1393_, v_expected_1394_, v_as_1395_, v_as_x27_1396_, v_b_1397_, v_a_1398_);
lean_dec(v_as_x27_1396_);
lean_dec(v_as_1395_);
lean_dec(v_expected_1394_);
lean_dec(v_val_1392_);
return v_res_1400_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6(lean_object* v_val_1401_, lean_object* v_xs_1402_, lean_object* v_expected_1403_, lean_object* v_inner_1404_, lean_object* v___x_1405_, lean_object* v_as_1406_, lean_object* v_as_x27_1407_, lean_object* v_b_1408_, lean_object* v_a_1409_){
_start:
{
lean_object* v___x_1411_; 
v___x_1411_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6___redArg(v_val_1401_, v_xs_1402_, v_expected_1403_, v_inner_1404_, v___x_1405_, v_as_x27_1407_, v_b_1408_);
return v___x_1411_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6___boxed(lean_object* v_val_1412_, lean_object* v_xs_1413_, lean_object* v_expected_1414_, lean_object* v_inner_1415_, lean_object* v___x_1416_, lean_object* v_as_1417_, lean_object* v_as_x27_1418_, lean_object* v_b_1419_, lean_object* v_a_1420_, lean_object* v___y_1421_){
_start:
{
lean_object* v_res_1422_; 
v_res_1422_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__6(v_val_1412_, v_xs_1413_, v_expected_1414_, v_inner_1415_, v___x_1416_, v_as_1417_, v_as_x27_1418_, v_b_1419_, v_a_1420_);
lean_dec(v_as_x27_1418_);
lean_dec(v_as_1417_);
lean_dec(v_expected_1414_);
lean_dec(v_val_1412_);
return v_res_1422_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4_spec__4(lean_object* v_inner_1423_, lean_object* v_val_1424_, lean_object* v_xs_1425_, lean_object* v_expected_1426_, lean_object* v_as_1427_, lean_object* v_as_x27_1428_, lean_object* v_b_1429_, lean_object* v_a_1430_){
_start:
{
lean_object* v___x_1432_; 
v___x_1432_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4_spec__4___redArg(v_inner_1423_, v_val_1424_, v_xs_1425_, v_expected_1426_, v_as_x27_1428_, v_b_1429_);
return v___x_1432_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4_spec__4___boxed(lean_object* v_inner_1433_, lean_object* v_val_1434_, lean_object* v_xs_1435_, lean_object* v_expected_1436_, lean_object* v_as_1437_, lean_object* v_as_x27_1438_, lean_object* v_b_1439_, lean_object* v_a_1440_, lean_object* v___y_1441_){
_start:
{
lean_object* v_res_1442_; 
v_res_1442_ = l_List_forIn_x27_loop___at___00List_forIn_x27_loop___at___00AdaptiveExperiment_benchmark_spec__4_spec__4(v_inner_1433_, v_val_1434_, v_xs_1435_, v_expected_1436_, v_as_1437_, v_as_x27_1438_, v_b_1439_, v_a_1440_);
lean_dec(v_as_x27_1438_);
lean_dec(v_as_1437_);
lean_dec(v_expected_1436_);
lean_dec(v_val_1434_);
return v_res_1442_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00AdaptiveExperiment_getInput_spec__0_spec__0(lean_object* v_j_1443_){
_start:
{
lean_object* v___x_1444_; 
v___x_1444_ = l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonStackTable_fromJson_spec__0_spec__0(v_j_1443_);
if (lean_obj_tag(v___x_1444_) == 0)
{
lean_object* v_a_1445_; lean_object* v___x_1447_; uint8_t v_isShared_1448_; uint8_t v_isSharedCheck_1452_; 
v_a_1445_ = lean_ctor_get(v___x_1444_, 0);
v_isSharedCheck_1452_ = !lean_is_exclusive(v___x_1444_);
if (v_isSharedCheck_1452_ == 0)
{
v___x_1447_ = v___x_1444_;
v_isShared_1448_ = v_isSharedCheck_1452_;
goto v_resetjp_1446_;
}
else
{
lean_inc(v_a_1445_);
lean_dec(v___x_1444_);
v___x_1447_ = lean_box(0);
v_isShared_1448_ = v_isSharedCheck_1452_;
goto v_resetjp_1446_;
}
v_resetjp_1446_:
{
lean_object* v___x_1450_; 
if (v_isShared_1448_ == 0)
{
v___x_1450_ = v___x_1447_;
goto v_reusejp_1449_;
}
else
{
lean_object* v_reuseFailAlloc_1451_; 
v_reuseFailAlloc_1451_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1451_, 0, v_a_1445_);
v___x_1450_ = v_reuseFailAlloc_1451_;
goto v_reusejp_1449_;
}
v_reusejp_1449_:
{
return v___x_1450_;
}
}
}
else
{
lean_object* v_a_1453_; lean_object* v___x_1455_; uint8_t v_isShared_1456_; uint8_t v_isSharedCheck_1461_; 
v_a_1453_ = lean_ctor_get(v___x_1444_, 0);
v_isSharedCheck_1461_ = !lean_is_exclusive(v___x_1444_);
if (v_isSharedCheck_1461_ == 0)
{
v___x_1455_ = v___x_1444_;
v_isShared_1456_ = v_isSharedCheck_1461_;
goto v_resetjp_1454_;
}
else
{
lean_inc(v_a_1453_);
lean_dec(v___x_1444_);
v___x_1455_ = lean_box(0);
v_isShared_1456_ = v_isSharedCheck_1461_;
goto v_resetjp_1454_;
}
v_resetjp_1454_:
{
lean_object* v___x_1457_; lean_object* v___x_1459_; 
v___x_1457_ = lean_array_to_list(v_a_1453_);
if (v_isShared_1456_ == 0)
{
lean_ctor_set(v___x_1455_, 0, v___x_1457_);
v___x_1459_ = v___x_1455_;
goto v_reusejp_1458_;
}
else
{
lean_object* v_reuseFailAlloc_1460_; 
v_reuseFailAlloc_1460_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1460_, 0, v___x_1457_);
v___x_1459_ = v_reuseFailAlloc_1460_;
goto v_reusejp_1458_;
}
v_reusejp_1458_:
{
return v___x_1459_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00AdaptiveExperiment_getInput_spec__0(lean_object* v_j_1462_, lean_object* v_k_1463_){
_start:
{
lean_object* v___x_1464_; lean_object* v___x_1465_; 
v___x_1464_ = l_Lean_Json_getObjValD(v_j_1462_, v_k_1463_);
v___x_1465_ = l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00AdaptiveExperiment_getInput_spec__0_spec__0(v___x_1464_);
return v___x_1465_;
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00AdaptiveExperiment_getInput_spec__0___boxed(lean_object* v_j_1466_, lean_object* v_k_1467_){
_start:
{
lean_object* v_res_1468_; 
v_res_1468_ = l_Lean_Json_getObjValAs_x3f___at___00AdaptiveExperiment_getInput_spec__0(v_j_1466_, v_k_1467_);
lean_dec_ref(v_k_1467_);
return v_res_1468_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_getInput(lean_object* v_j_1470_){
_start:
{
lean_object* v___x_1471_; lean_object* v___x_1472_; 
v___x_1471_ = ((lean_object*)(l_AdaptiveExperiment_getInput___closed__0));
v___x_1472_ = l_Lean_Json_getObjValAs_x3f___at___00AdaptiveExperiment_getInput_spec__0(v_j_1470_, v___x_1471_);
return v___x_1472_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_orError___redArg(lean_object* v_x_1473_){
_start:
{
if (lean_obj_tag(v_x_1473_) == 0)
{
lean_object* v_a_1475_; lean_object* v___x_1477_; uint8_t v_isShared_1478_; uint8_t v_isSharedCheck_1483_; 
v_a_1475_ = lean_ctor_get(v_x_1473_, 0);
v_isSharedCheck_1483_ = !lean_is_exclusive(v_x_1473_);
if (v_isSharedCheck_1483_ == 0)
{
v___x_1477_ = v_x_1473_;
v_isShared_1478_ = v_isSharedCheck_1483_;
goto v_resetjp_1476_;
}
else
{
lean_inc(v_a_1475_);
lean_dec(v_x_1473_);
v___x_1477_ = lean_box(0);
v_isShared_1478_ = v_isSharedCheck_1483_;
goto v_resetjp_1476_;
}
v_resetjp_1476_:
{
lean_object* v___x_1480_; 
if (v_isShared_1478_ == 0)
{
lean_ctor_set_tag(v___x_1477_, 18);
v___x_1480_ = v___x_1477_;
goto v_reusejp_1479_;
}
else
{
lean_object* v_reuseFailAlloc_1482_; 
v_reuseFailAlloc_1482_ = lean_alloc_ctor(18, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1482_, 0, v_a_1475_);
v___x_1480_ = v_reuseFailAlloc_1482_;
goto v_reusejp_1479_;
}
v_reusejp_1479_:
{
lean_object* v___x_1481_; 
v___x_1481_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1481_, 0, v___x_1480_);
return v___x_1481_;
}
}
}
else
{
lean_object* v_a_1484_; lean_object* v___x_1486_; uint8_t v_isShared_1487_; uint8_t v_isSharedCheck_1491_; 
v_a_1484_ = lean_ctor_get(v_x_1473_, 0);
v_isSharedCheck_1491_ = !lean_is_exclusive(v_x_1473_);
if (v_isSharedCheck_1491_ == 0)
{
v___x_1486_ = v_x_1473_;
v_isShared_1487_ = v_isSharedCheck_1491_;
goto v_resetjp_1485_;
}
else
{
lean_inc(v_a_1484_);
lean_dec(v_x_1473_);
v___x_1486_ = lean_box(0);
v_isShared_1487_ = v_isSharedCheck_1491_;
goto v_resetjp_1485_;
}
v_resetjp_1485_:
{
lean_object* v___x_1489_; 
if (v_isShared_1487_ == 0)
{
lean_ctor_set_tag(v___x_1486_, 0);
v___x_1489_ = v___x_1486_;
goto v_reusejp_1488_;
}
else
{
lean_object* v_reuseFailAlloc_1490_; 
v_reuseFailAlloc_1490_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1490_, 0, v_a_1484_);
v___x_1489_ = v_reuseFailAlloc_1490_;
goto v_reusejp_1488_;
}
v_reusejp_1488_:
{
return v___x_1489_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_orError___redArg___boxed(lean_object* v_x_1492_, lean_object* v_a_1493_){
_start:
{
lean_object* v_res_1494_; 
v_res_1494_ = l_AdaptiveExperiment_orError___redArg(v_x_1492_);
return v_res_1494_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_orError(lean_object* v_00_u03b1_1495_, lean_object* v_x_1496_){
_start:
{
lean_object* v___x_1498_; 
v___x_1498_ = l_AdaptiveExperiment_orError___redArg(v_x_1496_);
return v___x_1498_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_orError___boxed(lean_object* v_00_u03b1_1499_, lean_object* v_x_1500_, lean_object* v_a_1501_){
_start:
{
lean_object* v_res_1502_; 
v_res_1502_ = l_AdaptiveExperiment_orError(v_00_u03b1_1499_, v_x_1500_);
return v_res_1502_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_handle_spec__1___redArg(lean_object* v_val_1503_, lean_object* v_val_1504_, lean_object* v_as_x27_1505_, lean_object* v_b_1506_){
_start:
{
if (lean_obj_tag(v_as_x27_1505_) == 0)
{
lean_object* v___x_1508_; 
v___x_1508_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1508_, 0, v_b_1506_);
return v___x_1508_;
}
else
{
lean_object* v_tail_1509_; lean_object* v___x_1510_; lean_object* v_a_1511_; lean_object* v___x_1512_; 
v_tail_1509_ = lean_ctor_get(v_as_x27_1505_, 1);
v___x_1510_ = l_AdaptiveExperiment_timedFeatures(v_val_1503_, v_val_1504_);
v_a_1511_ = lean_ctor_get(v___x_1510_, 0);
lean_inc(v_a_1511_);
lean_dec_ref(v___x_1510_);
v___x_1512_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1512_, 0, v_a_1511_);
lean_ctor_set(v___x_1512_, 1, v_b_1506_);
v_as_x27_1505_ = v_tail_1509_;
v_b_1506_ = v___x_1512_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_handle_spec__1___redArg___boxed(lean_object* v_val_1514_, lean_object* v_val_1515_, lean_object* v_as_x27_1516_, lean_object* v_b_1517_, lean_object* v___y_1518_){
_start:
{
lean_object* v_res_1519_; 
v_res_1519_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_handle_spec__1___redArg(v_val_1514_, v_val_1515_, v_as_x27_1516_, v_b_1517_);
lean_dec(v_as_x27_1516_);
lean_dec(v_val_1515_);
lean_dec(v_val_1514_);
return v_res_1519_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00AdaptiveExperiment_handle_spec__0(lean_object* v_a_1520_, lean_object* v_a_1521_){
_start:
{
if (lean_obj_tag(v_a_1520_) == 0)
{
lean_object* v___x_1522_; 
v___x_1522_ = l_List_reverse___redArg(v_a_1521_);
return v___x_1522_;
}
else
{
lean_object* v_head_1523_; lean_object* v_tail_1524_; lean_object* v___x_1526_; uint8_t v_isShared_1527_; uint8_t v_isSharedCheck_1542_; 
v_head_1523_ = lean_ctor_get(v_a_1520_, 0);
v_tail_1524_ = lean_ctor_get(v_a_1520_, 1);
v_isSharedCheck_1542_ = !lean_is_exclusive(v_a_1520_);
if (v_isSharedCheck_1542_ == 0)
{
v___x_1526_ = v_a_1520_;
v_isShared_1527_ = v_isSharedCheck_1542_;
goto v_resetjp_1525_;
}
else
{
lean_inc(v_tail_1524_);
lean_inc(v_head_1523_);
lean_dec(v_a_1520_);
v___x_1526_ = lean_box(0);
v_isShared_1527_ = v_isSharedCheck_1542_;
goto v_resetjp_1525_;
}
v_resetjp_1525_:
{
lean_object* v_fst_1528_; lean_object* v_snd_1529_; lean_object* v___x_1531_; uint8_t v_isShared_1532_; uint8_t v_isSharedCheck_1541_; 
v_fst_1528_ = lean_ctor_get(v_head_1523_, 0);
v_snd_1529_ = lean_ctor_get(v_head_1523_, 1);
v_isSharedCheck_1541_ = !lean_is_exclusive(v_head_1523_);
if (v_isSharedCheck_1541_ == 0)
{
v___x_1531_ = v_head_1523_;
v_isShared_1532_ = v_isSharedCheck_1541_;
goto v_resetjp_1530_;
}
else
{
lean_inc(v_snd_1529_);
lean_inc(v_fst_1528_);
lean_dec(v_head_1523_);
v___x_1531_ = lean_box(0);
v_isShared_1532_ = v_isSharedCheck_1541_;
goto v_resetjp_1530_;
}
v_resetjp_1530_:
{
lean_object* v___x_1533_; lean_object* v___x_1535_; 
v___x_1533_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1533_, 0, v_snd_1529_);
if (v_isShared_1532_ == 0)
{
lean_ctor_set(v___x_1531_, 1, v___x_1533_);
v___x_1535_ = v___x_1531_;
goto v_reusejp_1534_;
}
else
{
lean_object* v_reuseFailAlloc_1540_; 
v_reuseFailAlloc_1540_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1540_, 0, v_fst_1528_);
lean_ctor_set(v_reuseFailAlloc_1540_, 1, v___x_1533_);
v___x_1535_ = v_reuseFailAlloc_1540_;
goto v_reusejp_1534_;
}
v_reusejp_1534_:
{
lean_object* v___x_1537_; 
if (v_isShared_1527_ == 0)
{
lean_ctor_set(v___x_1526_, 1, v_a_1521_);
lean_ctor_set(v___x_1526_, 0, v___x_1535_);
v___x_1537_ = v___x_1526_;
goto v_reusejp_1536_;
}
else
{
lean_object* v_reuseFailAlloc_1539_; 
v_reuseFailAlloc_1539_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1539_, 0, v___x_1535_);
lean_ctor_set(v_reuseFailAlloc_1539_, 1, v_a_1521_);
v___x_1537_ = v_reuseFailAlloc_1539_;
goto v_reusejp_1536_;
}
v_reusejp_1536_:
{
v_a_1520_ = v_tail_1524_;
v_a_1521_ = v___x_1537_;
goto _start;
}
}
}
}
}
}
}
static lean_object* _init_l_AdaptiveExperiment_handle___closed__20(void){
_start:
{
lean_object* v___x_1566_; lean_object* v___x_1567_; lean_object* v___x_1568_; 
v___x_1566_ = lean_box(0);
v___x_1567_ = ((lean_object*)(l_AdaptiveExperiment_candidates));
v___x_1568_ = l_List_mapTR_loop___at___00AdaptiveExperiment_handle_spec__0(v___x_1567_, v___x_1566_);
return v___x_1568_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_handle(lean_object* v_j_1581_, lean_object* v_model_1582_, lean_object* v_best_1583_){
_start:
{
lean_object* v___y_1586_; lean_object* v___y_1587_; uint8_t v___y_1588_; lean_object* v___y_1589_; lean_object* v___y_1590_; lean_object* v___y_1591_; lean_object* v___y_1592_; lean_object* v___x_1611_; lean_object* v___x_1612_; 
lean_inc(v_j_1581_);
v___x_1611_ = l_AdaptiveExperiment_getInput(v_j_1581_);
v___x_1612_ = l_AdaptiveExperiment_orError___redArg(v___x_1611_);
if (lean_obj_tag(v___x_1612_) == 0)
{
lean_object* v_a_1613_; lean_object* v___x_1614_; lean_object* v___x_1615_; lean_object* v___x_1616_; 
v_a_1613_ = lean_ctor_get(v___x_1612_, 0);
lean_inc(v_a_1613_);
lean_dec_ref_known(v___x_1612_, 1);
v___x_1614_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__2));
lean_inc(v_j_1581_);
v___x_1615_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_j_1581_, v___x_1614_);
v___x_1616_ = l_AdaptiveExperiment_orError___redArg(v___x_1615_);
if (lean_obj_tag(v___x_1616_) == 0)
{
lean_object* v_a_1617_; lean_object* v___x_1619_; uint8_t v_isShared_1620_; uint8_t v_isSharedCheck_1854_; 
v_a_1617_ = lean_ctor_get(v___x_1616_, 0);
v_isSharedCheck_1854_ = !lean_is_exclusive(v___x_1616_);
if (v_isSharedCheck_1854_ == 0)
{
v___x_1619_ = v___x_1616_;
v_isShared_1620_ = v_isSharedCheck_1854_;
goto v_resetjp_1618_;
}
else
{
lean_inc(v_a_1617_);
lean_dec(v___x_1616_);
v___x_1619_ = lean_box(0);
v_isShared_1620_ = v_isSharedCheck_1854_;
goto v_resetjp_1618_;
}
v_resetjp_1618_:
{
lean_object* v___x_1621_; uint8_t v___x_1622_; 
v___x_1621_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__3));
v___x_1622_ = lean_string_dec_eq(v_a_1617_, v___x_1621_);
if (v___x_1622_ == 0)
{
lean_object* v___x_1623_; uint8_t v___x_1624_; 
v___x_1623_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__4));
v___x_1624_ = lean_string_dec_eq(v_a_1617_, v___x_1623_);
if (v___x_1624_ == 0)
{
lean_object* v___x_1625_; uint8_t v___x_1626_; 
v___x_1625_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__5));
v___x_1626_ = lean_string_dec_eq(v_a_1617_, v___x_1625_);
lean_dec(v_a_1617_);
if (v___x_1626_ == 0)
{
lean_object* v___x_1627_; lean_object* v___x_1629_; 
lean_dec(v_a_1613_);
lean_dec(v_best_1583_);
lean_dec(v_model_1582_);
lean_dec(v_j_1581_);
v___x_1627_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__7));
if (v_isShared_1620_ == 0)
{
lean_ctor_set_tag(v___x_1619_, 1);
lean_ctor_set(v___x_1619_, 0, v___x_1627_);
v___x_1629_ = v___x_1619_;
goto v_reusejp_1628_;
}
else
{
lean_object* v_reuseFailAlloc_1630_; 
v_reuseFailAlloc_1630_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1630_, 0, v___x_1627_);
v___x_1629_ = v_reuseFailAlloc_1630_;
goto v_reusejp_1628_;
}
v_reusejp_1628_:
{
return v___x_1629_;
}
}
else
{
lean_object* v___x_1631_; lean_object* v___x_1632_; lean_object* v___x_1633_; 
lean_del_object(v___x_1619_);
v___x_1631_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__8));
lean_inc(v_j_1581_);
v___x_1632_ = l_Lean_Json_getObjValAs_x3f___at___00AdaptiveExperiment_getInput_spec__0(v_j_1581_, v___x_1631_);
v___x_1633_ = l_AdaptiveExperiment_orError___redArg(v___x_1632_);
if (lean_obj_tag(v___x_1633_) == 0)
{
lean_object* v_a_1634_; lean_object* v___x_1635_; lean_object* v___x_1636_; lean_object* v___x_1637_; 
v_a_1634_ = lean_ctor_get(v___x_1633_, 0);
lean_inc(v_a_1634_);
lean_dec_ref_known(v___x_1633_, 1);
v___x_1635_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__9));
lean_inc(v_j_1581_);
v___x_1636_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_1581_, v___x_1635_);
v___x_1637_ = l_AdaptiveExperiment_orError___redArg(v___x_1636_);
if (lean_obj_tag(v___x_1637_) == 0)
{
lean_object* v_a_1638_; lean_object* v___x_1640_; uint8_t v_isShared_1641_; uint8_t v_isSharedCheck_1773_; 
v_a_1638_ = lean_ctor_get(v___x_1637_, 0);
v_isSharedCheck_1773_ = !lean_is_exclusive(v___x_1637_);
if (v_isSharedCheck_1773_ == 0)
{
v___x_1640_ = v___x_1637_;
v_isShared_1641_ = v_isSharedCheck_1773_;
goto v_resetjp_1639_;
}
else
{
lean_inc(v_a_1638_);
lean_dec(v___x_1637_);
v___x_1640_ = lean_box(0);
v_isShared_1641_ = v_isSharedCheck_1773_;
goto v_resetjp_1639_;
}
v_resetjp_1639_:
{
lean_object* v___x_1642_; lean_object* v___x_1643_; lean_object* v___x_1644_; 
v___x_1642_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__10));
lean_inc(v_j_1581_);
v___x_1643_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_1581_, v___x_1642_);
v___x_1644_ = l_AdaptiveExperiment_orError___redArg(v___x_1643_);
if (lean_obj_tag(v___x_1644_) == 0)
{
lean_object* v_a_1645_; lean_object* v___x_1647_; uint8_t v_isShared_1648_; uint8_t v_isSharedCheck_1764_; 
v_a_1645_ = lean_ctor_get(v___x_1644_, 0);
v_isSharedCheck_1764_ = !lean_is_exclusive(v___x_1644_);
if (v_isSharedCheck_1764_ == 0)
{
v___x_1647_ = v___x_1644_;
v_isShared_1648_ = v_isSharedCheck_1764_;
goto v_resetjp_1646_;
}
else
{
lean_inc(v_a_1645_);
lean_dec(v___x_1644_);
v___x_1647_ = lean_box(0);
v_isShared_1648_ = v_isSharedCheck_1764_;
goto v_resetjp_1646_;
}
v_resetjp_1646_:
{
lean_object* v___y_1655_; lean_object* v___y_1656_; uint8_t v___y_1657_; lean_object* v___y_1658_; lean_object* v___y_1692_; uint8_t v___y_1693_; lean_object* v_strategies_1694_; lean_object* v___y_1700_; lean_object* v___y_1701_; lean_object* v___y_1702_; uint8_t v___y_1703_; lean_object* v___y_1704_; lean_object* v___y_1705_; lean_object* v___y_1706_; lean_object* v___y_1707_; lean_object* v___y_1708_; lean_object* v___y_1717_; uint8_t v___y_1718_; uint8_t v___y_1739_; lean_object* v___x_1760_; uint8_t v___x_1761_; 
v___x_1760_ = lean_unsigned_to_nat(1u);
v___x_1761_ = lean_nat_dec_le(v___x_1760_, v_a_1638_);
if (v___x_1761_ == 0)
{
v___y_1739_ = v___x_1761_;
goto v___jp_1738_;
}
else
{
lean_object* v___x_1762_; uint8_t v___x_1763_; 
v___x_1762_ = lean_unsigned_to_nat(21u);
v___x_1763_ = lean_nat_dec_le(v_a_1638_, v___x_1762_);
v___y_1739_ = v___x_1763_;
goto v___jp_1738_;
}
v___jp_1649_:
{
lean_object* v___x_1650_; lean_object* v___x_1652_; 
v___x_1650_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__12));
if (v_isShared_1648_ == 0)
{
lean_ctor_set_tag(v___x_1647_, 1);
lean_ctor_set(v___x_1647_, 0, v___x_1650_);
v___x_1652_ = v___x_1647_;
goto v_reusejp_1651_;
}
else
{
lean_object* v_reuseFailAlloc_1653_; 
v_reuseFailAlloc_1653_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1653_, 0, v___x_1650_);
v___x_1652_ = v_reuseFailAlloc_1653_;
goto v_reusejp_1651_;
}
v_reusejp_1651_:
{
return v___x_1652_;
}
}
v___jp_1654_:
{
lean_object* v___x_1659_; 
lean_inc(v_a_1645_);
lean_inc(v_a_1638_);
lean_inc(v_a_1613_);
v___x_1659_ = l_AdaptiveExperiment_benchmark(v___y_1655_, v_a_1613_, v_a_1634_, v_a_1638_, v_a_1645_, v___y_1658_);
lean_dec(v___y_1658_);
lean_dec(v_a_1634_);
if (lean_obj_tag(v___x_1659_) == 0)
{
lean_object* v_a_1660_; lean_object* v___x_1661_; lean_object* v___x_1662_; lean_object* v___x_1663_; lean_object* v___x_1664_; lean_object* v___x_1665_; lean_object* v___x_1666_; lean_object* v___x_1667_; lean_object* v___x_1668_; 
v_a_1660_ = lean_ctor_get(v___x_1659_, 0);
lean_inc(v_a_1660_);
lean_dec_ref_known(v___x_1659_, 1);
v___x_1661_ = lean_unsigned_to_nat(0u);
v___x_1662_ = lean_st_mk_ref(v___x_1661_);
lean_inc_n(v_a_1613_, 2);
v___x_1663_ = l_AdaptiveExperiment_features(v_a_1613_);
v___x_1664_ = lean_st_mk_ref(v_a_1613_);
v___x_1665_ = lean_box(0);
v___x_1666_ = lean_nat_mul(v_a_1638_, v_a_1645_);
lean_dec(v_a_1645_);
lean_dec(v_a_1638_);
v___x_1667_ = l_List_range(v___x_1666_);
v___x_1668_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_handle_spec__1___redArg(v___x_1664_, v___x_1662_, v___x_1667_, v___x_1665_);
lean_dec(v___x_1667_);
lean_dec(v___x_1662_);
lean_dec(v___x_1664_);
if (lean_obj_tag(v___x_1668_) == 0)
{
lean_object* v_a_1669_; lean_object* v___x_1670_; lean_object* v___x_1671_; lean_object* v___x_1672_; lean_object* v___x_1673_; lean_object* v___x_1674_; lean_object* v___x_1675_; lean_object* v___x_1676_; lean_object* v___x_1677_; lean_object* v___x_1678_; lean_object* v___x_1679_; lean_object* v___x_1680_; 
v_a_1669_ = lean_ctor_get(v___x_1668_, 0);
lean_inc(v_a_1669_);
lean_dec_ref_known(v___x_1668_, 1);
v___x_1670_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__13));
lean_inc_ref(v___x_1663_);
v___x_1671_ = l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__0(v___x_1663_);
v___x_1672_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1672_, 0, v___x_1670_);
lean_ctor_set(v___x_1672_, 1, v___x_1671_);
v___x_1673_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__14));
v___x_1674_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1674_, 0, v___x_1673_);
lean_ctor_set(v___x_1674_, 1, v_a_1660_);
v___x_1675_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__15));
v___x_1676_ = l_List_reverse___redArg(v_a_1669_);
v___x_1677_ = l_Lean_List_toJson___at___00AdaptiveExperiment_benchmark_spec__0(v___x_1676_);
v___x_1678_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1678_, 0, v___x_1675_);
lean_ctor_set(v___x_1678_, 1, v___x_1677_);
v___x_1679_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__16));
v___x_1680_ = l_AdaptiveExperiment_Strategy_choose(v___y_1656_, v_a_1613_);
if (lean_obj_tag(v___x_1680_) == 0)
{
lean_object* v___x_1681_; 
v___x_1681_ = lean_box(0);
v___y_1586_ = v___x_1663_;
v___y_1587_ = v___x_1674_;
v___y_1588_ = v___y_1657_;
v___y_1589_ = v___x_1672_;
v___y_1590_ = v___x_1679_;
v___y_1591_ = v___x_1678_;
v___y_1592_ = v___x_1681_;
goto v___jp_1585_;
}
else
{
lean_object* v_val_1682_; 
v_val_1682_ = lean_ctor_get(v___x_1680_, 0);
lean_inc(v_val_1682_);
lean_dec_ref_known(v___x_1680_, 1);
v___y_1586_ = v___x_1663_;
v___y_1587_ = v___x_1674_;
v___y_1588_ = v___y_1657_;
v___y_1589_ = v___x_1672_;
v___y_1590_ = v___x_1679_;
v___y_1591_ = v___x_1678_;
v___y_1592_ = v_val_1682_;
goto v___jp_1585_;
}
}
else
{
lean_object* v_a_1683_; lean_object* v___x_1685_; uint8_t v_isShared_1686_; uint8_t v_isSharedCheck_1690_; 
lean_dec_ref(v___x_1663_);
lean_dec(v_a_1660_);
lean_dec(v___y_1656_);
lean_dec(v_a_1613_);
v_a_1683_ = lean_ctor_get(v___x_1668_, 0);
v_isSharedCheck_1690_ = !lean_is_exclusive(v___x_1668_);
if (v_isSharedCheck_1690_ == 0)
{
v___x_1685_ = v___x_1668_;
v_isShared_1686_ = v_isSharedCheck_1690_;
goto v_resetjp_1684_;
}
else
{
lean_inc(v_a_1683_);
lean_dec(v___x_1668_);
v___x_1685_ = lean_box(0);
v_isShared_1686_ = v_isSharedCheck_1690_;
goto v_resetjp_1684_;
}
v_resetjp_1684_:
{
lean_object* v___x_1688_; 
if (v_isShared_1686_ == 0)
{
v___x_1688_ = v___x_1685_;
goto v_reusejp_1687_;
}
else
{
lean_object* v_reuseFailAlloc_1689_; 
v_reuseFailAlloc_1689_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1689_, 0, v_a_1683_);
v___x_1688_ = v_reuseFailAlloc_1689_;
goto v_reusejp_1687_;
}
v_reusejp_1687_:
{
return v___x_1688_;
}
}
}
}
else
{
lean_dec(v___y_1656_);
lean_dec(v_a_1645_);
lean_dec(v_a_1638_);
lean_dec(v_a_1613_);
return v___x_1659_;
}
}
v___jp_1691_:
{
lean_object* v___x_1695_; lean_object* v___x_1696_; 
v___x_1695_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__17));
v___x_1696_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_1581_, v___x_1695_);
if (lean_obj_tag(v___x_1696_) == 0)
{
lean_object* v___x_1697_; 
lean_dec_ref_known(v___x_1696_, 1);
v___x_1697_ = lean_unsigned_to_nat(0u);
v___y_1655_ = v_strategies_1694_;
v___y_1656_ = v___y_1692_;
v___y_1657_ = v___y_1693_;
v___y_1658_ = v___x_1697_;
goto v___jp_1654_;
}
else
{
lean_object* v_a_1698_; 
v_a_1698_ = lean_ctor_get(v___x_1696_, 0);
lean_inc(v_a_1698_);
lean_dec_ref_known(v___x_1696_, 1);
v___y_1655_ = v_strategies_1694_;
v___y_1656_ = v___y_1692_;
v___y_1657_ = v___y_1693_;
v___y_1658_ = v_a_1698_;
goto v___jp_1654_;
}
}
v___jp_1699_:
{
lean_object* v___x_1709_; lean_object* v___x_1710_; lean_object* v___x_1711_; lean_object* v___x_1712_; lean_object* v___x_1713_; lean_object* v___x_1714_; lean_object* v___x_1715_; 
v___x_1709_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1709_, 0, v___y_1708_);
lean_inc_ref(v___y_1704_);
v___x_1710_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1710_, 0, v___y_1704_);
lean_ctor_set(v___x_1710_, 1, v___x_1709_);
lean_inc(v___y_1700_);
v___x_1711_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1711_, 0, v___x_1710_);
lean_ctor_set(v___x_1711_, 1, v___y_1700_);
v___x_1712_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1712_, 0, v___y_1705_);
lean_ctor_set(v___x_1712_, 1, v___x_1711_);
lean_inc_ref(v___y_1706_);
v___x_1713_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1713_, 0, v___y_1706_);
lean_ctor_set(v___x_1713_, 1, v___x_1712_);
v___x_1714_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1714_, 0, v___y_1707_);
lean_ctor_set(v___x_1714_, 1, v___x_1713_);
v___x_1715_ = l_List_appendTR___redArg(v___y_1701_, v___x_1714_);
v___y_1692_ = v___y_1702_;
v___y_1693_ = v___y_1703_;
v_strategies_1694_ = v___x_1715_;
goto v___jp_1691_;
}
v___jp_1716_:
{
if (v___y_1718_ == 0)
{
lean_object* v___x_1719_; lean_object* v___x_1721_; 
lean_dec_ref(v___y_1717_);
lean_dec(v_a_1645_);
lean_dec(v_a_1638_);
lean_dec(v_a_1634_);
lean_dec(v_a_1613_);
lean_dec(v_best_1583_);
lean_dec(v_model_1582_);
lean_dec(v_j_1581_);
v___x_1719_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__19));
if (v_isShared_1641_ == 0)
{
lean_ctor_set_tag(v___x_1640_, 1);
lean_ctor_set(v___x_1640_, 0, v___x_1719_);
v___x_1721_ = v___x_1640_;
goto v_reusejp_1720_;
}
else
{
lean_object* v_reuseFailAlloc_1722_; 
v_reuseFailAlloc_1722_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1722_, 0, v___x_1719_);
v___x_1721_ = v_reuseFailAlloc_1722_;
goto v_reusejp_1720_;
}
v_reusejp_1720_:
{
return v___x_1721_;
}
}
else
{
lean_object* v___x_1723_; lean_object* v___x_1724_; lean_object* v___x_1725_; lean_object* v___x_1726_; uint8_t v___x_1727_; 
lean_del_object(v___x_1640_);
v___x_1723_ = lean_box(0);
v___x_1724_ = lean_obj_once(&l_AdaptiveExperiment_handle___closed__20, &l_AdaptiveExperiment_handle___closed__20_once, _init_l_AdaptiveExperiment_handle___closed__20);
v___x_1725_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1725_, 0, v_model_1582_);
v___x_1726_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__21));
v___x_1727_ = lean_string_dec_eq(v___y_1717_, v___x_1726_);
lean_dec_ref(v___y_1717_);
if (v___x_1727_ == 0)
{
lean_dec(v_best_1583_);
v___y_1692_ = v___x_1725_;
v___y_1693_ = v___y_1718_;
v_strategies_1694_ = v___x_1724_;
goto v___jp_1691_;
}
else
{
lean_object* v___x_1728_; lean_object* v___x_1729_; lean_object* v___x_1730_; lean_object* v___x_1731_; lean_object* v___x_1732_; lean_object* v___x_1733_; lean_object* v___x_1734_; lean_object* v___x_1735_; 
v___x_1728_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__22));
v___x_1729_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1729_, 0, v_best_1583_);
v___x_1730_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1730_, 0, v___x_1728_);
lean_ctor_set(v___x_1730_, 1, v___x_1729_);
v___x_1731_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__24));
v___x_1732_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__25));
lean_inc_ref_n(v___x_1725_, 2);
v___x_1733_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1733_, 0, v___x_1732_);
lean_ctor_set(v___x_1733_, 1, v___x_1725_);
v___x_1734_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__26));
lean_inc(v_a_1613_);
v___x_1735_ = l_AdaptiveExperiment_Strategy_choose(v___x_1725_, v_a_1613_);
if (lean_obj_tag(v___x_1735_) == 0)
{
lean_object* v___x_1736_; 
v___x_1736_ = lean_box(0);
v___y_1700_ = v___x_1723_;
v___y_1701_ = v___x_1724_;
v___y_1702_ = v___x_1725_;
v___y_1703_ = v___y_1718_;
v___y_1704_ = v___x_1734_;
v___y_1705_ = v___x_1733_;
v___y_1706_ = v___x_1731_;
v___y_1707_ = v___x_1730_;
v___y_1708_ = v___x_1736_;
goto v___jp_1699_;
}
else
{
lean_object* v_val_1737_; 
v_val_1737_ = lean_ctor_get(v___x_1735_, 0);
lean_inc(v_val_1737_);
lean_dec_ref_known(v___x_1735_, 1);
v___y_1700_ = v___x_1723_;
v___y_1701_ = v___x_1724_;
v___y_1702_ = v___x_1725_;
v___y_1703_ = v___y_1718_;
v___y_1704_ = v___x_1734_;
v___y_1705_ = v___x_1733_;
v___y_1706_ = v___x_1731_;
v___y_1707_ = v___x_1730_;
v___y_1708_ = v_val_1737_;
goto v___jp_1699_;
}
}
}
}
v___jp_1738_:
{
if (v___y_1739_ == 0)
{
lean_dec(v_a_1645_);
lean_del_object(v___x_1640_);
lean_dec(v_a_1638_);
lean_dec(v_a_1634_);
lean_dec(v_a_1613_);
lean_dec(v_best_1583_);
lean_dec(v_model_1582_);
lean_dec(v_j_1581_);
goto v___jp_1649_;
}
else
{
lean_object* v___x_1740_; uint8_t v___x_1741_; 
v___x_1740_ = lean_unsigned_to_nat(1u);
v___x_1741_ = lean_nat_dec_le(v___x_1740_, v_a_1645_);
if (v___x_1741_ == 0)
{
lean_dec(v_a_1645_);
lean_del_object(v___x_1640_);
lean_dec(v_a_1638_);
lean_dec(v_a_1634_);
lean_dec(v_a_1613_);
lean_dec(v_best_1583_);
lean_dec(v_model_1582_);
lean_dec(v_j_1581_);
goto v___jp_1649_;
}
else
{
lean_object* v___x_1742_; uint8_t v___x_1743_; 
v___x_1742_ = lean_unsigned_to_nat(10u);
v___x_1743_ = lean_nat_dec_le(v_a_1645_, v___x_1742_);
if (v___x_1743_ == 0)
{
lean_dec(v_a_1645_);
lean_del_object(v___x_1640_);
lean_dec(v_a_1638_);
lean_dec(v_a_1634_);
lean_dec(v_a_1613_);
lean_dec(v_best_1583_);
lean_dec(v_model_1582_);
lean_dec(v_j_1581_);
goto v___jp_1649_;
}
else
{
lean_object* v___x_1744_; lean_object* v___x_1745_; lean_object* v___x_1746_; 
lean_del_object(v___x_1647_);
v___x_1744_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__27));
lean_inc(v_j_1581_);
v___x_1745_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_j_1581_, v___x_1744_);
v___x_1746_ = l_AdaptiveExperiment_orError___redArg(v___x_1745_);
if (lean_obj_tag(v___x_1746_) == 0)
{
lean_object* v_a_1747_; lean_object* v___x_1748_; uint8_t v___x_1749_; 
v_a_1747_ = lean_ctor_get(v___x_1746_, 0);
lean_inc(v_a_1747_);
lean_dec_ref_known(v___x_1746_, 1);
v___x_1748_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__28));
v___x_1749_ = lean_string_dec_eq(v_a_1747_, v___x_1748_);
if (v___x_1749_ == 0)
{
lean_object* v___x_1750_; uint8_t v___x_1751_; 
v___x_1750_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__21));
v___x_1751_ = lean_string_dec_eq(v_a_1747_, v___x_1750_);
v___y_1717_ = v_a_1747_;
v___y_1718_ = v___x_1751_;
goto v___jp_1716_;
}
else
{
v___y_1717_ = v_a_1747_;
v___y_1718_ = v___x_1749_;
goto v___jp_1716_;
}
}
else
{
lean_object* v_a_1752_; lean_object* v___x_1754_; uint8_t v_isShared_1755_; uint8_t v_isSharedCheck_1759_; 
lean_dec(v_a_1645_);
lean_del_object(v___x_1640_);
lean_dec(v_a_1638_);
lean_dec(v_a_1634_);
lean_dec(v_a_1613_);
lean_dec(v_best_1583_);
lean_dec(v_model_1582_);
lean_dec(v_j_1581_);
v_a_1752_ = lean_ctor_get(v___x_1746_, 0);
v_isSharedCheck_1759_ = !lean_is_exclusive(v___x_1746_);
if (v_isSharedCheck_1759_ == 0)
{
v___x_1754_ = v___x_1746_;
v_isShared_1755_ = v_isSharedCheck_1759_;
goto v_resetjp_1753_;
}
else
{
lean_inc(v_a_1752_);
lean_dec(v___x_1746_);
v___x_1754_ = lean_box(0);
v_isShared_1755_ = v_isSharedCheck_1759_;
goto v_resetjp_1753_;
}
v_resetjp_1753_:
{
lean_object* v___x_1757_; 
if (v_isShared_1755_ == 0)
{
v___x_1757_ = v___x_1754_;
goto v_reusejp_1756_;
}
else
{
lean_object* v_reuseFailAlloc_1758_; 
v_reuseFailAlloc_1758_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1758_, 0, v_a_1752_);
v___x_1757_ = v_reuseFailAlloc_1758_;
goto v_reusejp_1756_;
}
v_reusejp_1756_:
{
return v___x_1757_;
}
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
lean_object* v_a_1765_; lean_object* v___x_1767_; uint8_t v_isShared_1768_; uint8_t v_isSharedCheck_1772_; 
lean_del_object(v___x_1640_);
lean_dec(v_a_1638_);
lean_dec(v_a_1634_);
lean_dec(v_a_1613_);
lean_dec(v_best_1583_);
lean_dec(v_model_1582_);
lean_dec(v_j_1581_);
v_a_1765_ = lean_ctor_get(v___x_1644_, 0);
v_isSharedCheck_1772_ = !lean_is_exclusive(v___x_1644_);
if (v_isSharedCheck_1772_ == 0)
{
v___x_1767_ = v___x_1644_;
v_isShared_1768_ = v_isSharedCheck_1772_;
goto v_resetjp_1766_;
}
else
{
lean_inc(v_a_1765_);
lean_dec(v___x_1644_);
v___x_1767_ = lean_box(0);
v_isShared_1768_ = v_isSharedCheck_1772_;
goto v_resetjp_1766_;
}
v_resetjp_1766_:
{
lean_object* v___x_1770_; 
if (v_isShared_1768_ == 0)
{
v___x_1770_ = v___x_1767_;
goto v_reusejp_1769_;
}
else
{
lean_object* v_reuseFailAlloc_1771_; 
v_reuseFailAlloc_1771_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1771_, 0, v_a_1765_);
v___x_1770_ = v_reuseFailAlloc_1771_;
goto v_reusejp_1769_;
}
v_reusejp_1769_:
{
return v___x_1770_;
}
}
}
}
}
else
{
lean_object* v_a_1774_; lean_object* v___x_1776_; uint8_t v_isShared_1777_; uint8_t v_isSharedCheck_1781_; 
lean_dec(v_a_1634_);
lean_dec(v_a_1613_);
lean_dec(v_best_1583_);
lean_dec(v_model_1582_);
lean_dec(v_j_1581_);
v_a_1774_ = lean_ctor_get(v___x_1637_, 0);
v_isSharedCheck_1781_ = !lean_is_exclusive(v___x_1637_);
if (v_isSharedCheck_1781_ == 0)
{
v___x_1776_ = v___x_1637_;
v_isShared_1777_ = v_isSharedCheck_1781_;
goto v_resetjp_1775_;
}
else
{
lean_inc(v_a_1774_);
lean_dec(v___x_1637_);
v___x_1776_ = lean_box(0);
v_isShared_1777_ = v_isSharedCheck_1781_;
goto v_resetjp_1775_;
}
v_resetjp_1775_:
{
lean_object* v___x_1779_; 
if (v_isShared_1777_ == 0)
{
v___x_1779_ = v___x_1776_;
goto v_reusejp_1778_;
}
else
{
lean_object* v_reuseFailAlloc_1780_; 
v_reuseFailAlloc_1780_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1780_, 0, v_a_1774_);
v___x_1779_ = v_reuseFailAlloc_1780_;
goto v_reusejp_1778_;
}
v_reusejp_1778_:
{
return v___x_1779_;
}
}
}
}
else
{
lean_object* v_a_1782_; lean_object* v___x_1784_; uint8_t v_isShared_1785_; uint8_t v_isSharedCheck_1789_; 
lean_dec(v_a_1613_);
lean_dec(v_best_1583_);
lean_dec(v_model_1582_);
lean_dec(v_j_1581_);
v_a_1782_ = lean_ctor_get(v___x_1633_, 0);
v_isSharedCheck_1789_ = !lean_is_exclusive(v___x_1633_);
if (v_isSharedCheck_1789_ == 0)
{
v___x_1784_ = v___x_1633_;
v_isShared_1785_ = v_isSharedCheck_1789_;
goto v_resetjp_1783_;
}
else
{
lean_inc(v_a_1782_);
lean_dec(v___x_1633_);
v___x_1784_ = lean_box(0);
v_isShared_1785_ = v_isSharedCheck_1789_;
goto v_resetjp_1783_;
}
v_resetjp_1783_:
{
lean_object* v___x_1787_; 
if (v_isShared_1785_ == 0)
{
v___x_1787_ = v___x_1784_;
goto v_reusejp_1786_;
}
else
{
lean_object* v_reuseFailAlloc_1788_; 
v_reuseFailAlloc_1788_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1788_, 0, v_a_1782_);
v___x_1787_ = v_reuseFailAlloc_1788_;
goto v_reusejp_1786_;
}
v_reusejp_1786_:
{
return v___x_1787_;
}
}
}
}
}
else
{
lean_object* v___x_1790_; lean_object* v___x_1791_; lean_object* v___x_1792_; lean_object* v___x_1793_; lean_object* v___x_1794_; lean_object* v___y_1796_; uint8_t v___y_1797_; 
lean_dec(v_a_1617_);
lean_dec(v_best_1583_);
lean_dec(v_model_1582_);
v___x_1790_ = lean_unsigned_to_nat(16u);
v___x_1791_ = ((lean_object*)(l_AdaptiveExperiment_decodeTree___closed__10));
v___x_1792_ = l_Lean_Json_getObjValD(v_j_1581_, v___x_1791_);
v___x_1793_ = l_AdaptiveExperiment_decodePlan(v___x_1790_, v___x_1792_);
v___x_1794_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__29));
if (lean_obj_tag(v___x_1793_) == 0)
{
lean_object* v___x_1811_; 
lean_dec_ref_known(v___x_1793_, 1);
v___x_1811_ = lean_box(0);
v___y_1796_ = v___x_1811_;
v___y_1797_ = v___x_1624_;
goto v___jp_1795_;
}
else
{
lean_object* v_a_1812_; lean_object* v___x_1814_; uint8_t v_isShared_1815_; uint8_t v_isSharedCheck_1819_; 
v_a_1812_ = lean_ctor_get(v___x_1793_, 0);
v_isSharedCheck_1819_ = !lean_is_exclusive(v___x_1793_);
if (v_isSharedCheck_1819_ == 0)
{
v___x_1814_ = v___x_1793_;
v_isShared_1815_ = v_isSharedCheck_1819_;
goto v_resetjp_1813_;
}
else
{
lean_inc(v_a_1812_);
lean_dec(v___x_1793_);
v___x_1814_ = lean_box(0);
v_isShared_1815_ = v_isSharedCheck_1819_;
goto v_resetjp_1813_;
}
v_resetjp_1813_:
{
lean_object* v___x_1817_; 
if (v_isShared_1815_ == 0)
{
v___x_1817_ = v___x_1814_;
goto v_reusejp_1816_;
}
else
{
lean_object* v_reuseFailAlloc_1818_; 
v_reuseFailAlloc_1818_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1818_, 0, v_a_1812_);
v___x_1817_ = v_reuseFailAlloc_1818_;
goto v_reusejp_1816_;
}
v_reusejp_1816_:
{
v___y_1796_ = v___x_1817_;
v___y_1797_ = v___x_1622_;
goto v___jp_1795_;
}
}
}
v___jp_1795_:
{
lean_object* v___x_1798_; lean_object* v___x_1799_; lean_object* v___x_1800_; lean_object* v___x_1801_; lean_object* v___x_1802_; lean_object* v___x_1803_; lean_object* v___x_1804_; lean_object* v___x_1805_; lean_object* v___x_1806_; lean_object* v___x_1807_; lean_object* v___x_1809_; 
v___x_1798_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_1798_, 0, v___y_1797_);
v___x_1799_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1799_, 0, v___x_1794_);
lean_ctor_set(v___x_1799_, 1, v___x_1798_);
v___x_1800_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__30));
v___x_1801_ = l_LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0(v___y_1796_, v_a_1613_);
v___x_1802_ = l_Lean_List_toJson___at___00AdaptiveExperiment_benchmark_spec__0(v___x_1801_);
v___x_1803_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1803_, 0, v___x_1800_);
lean_ctor_set(v___x_1803_, 1, v___x_1802_);
v___x_1804_ = lean_box(0);
v___x_1805_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1805_, 0, v___x_1803_);
lean_ctor_set(v___x_1805_, 1, v___x_1804_);
v___x_1806_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1806_, 0, v___x_1799_);
lean_ctor_set(v___x_1806_, 1, v___x_1805_);
v___x_1807_ = l_Lean_Json_mkObj(v___x_1806_);
lean_dec_ref_known(v___x_1806_, 2);
if (v_isShared_1620_ == 0)
{
lean_ctor_set(v___x_1619_, 0, v___x_1807_);
v___x_1809_ = v___x_1619_;
goto v_reusejp_1808_;
}
else
{
lean_object* v_reuseFailAlloc_1810_; 
v_reuseFailAlloc_1810_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1810_, 0, v___x_1807_);
v___x_1809_ = v_reuseFailAlloc_1810_;
goto v_reusejp_1808_;
}
v_reusejp_1808_:
{
return v___x_1809_;
}
}
}
}
else
{
lean_object* v___x_1820_; lean_object* v___x_1821_; lean_object* v___x_1822_; lean_object* v___x_1823_; lean_object* v___x_1824_; lean_object* v___x_1825_; lean_object* v___y_1827_; lean_object* v___y_1828_; uint8_t v___y_1829_; lean_object* v___x_1845_; lean_object* v___y_1847_; 
lean_dec(v_a_1617_);
lean_dec(v_best_1583_);
lean_dec(v_j_1581_);
v___x_1820_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1820_, 0, v_model_1582_);
lean_inc_n(v_a_1613_, 2);
v___x_1821_ = l_AdaptiveExperiment_Strategy_choose(v___x_1820_, v_a_1613_);
v___x_1822_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__13));
v___x_1823_ = l_AdaptiveExperiment_features(v_a_1613_);
v___x_1824_ = l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__0(v___x_1823_);
v___x_1825_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1825_, 0, v___x_1822_);
lean_ctor_set(v___x_1825_, 1, v___x_1824_);
v___x_1845_ = ((lean_object*)(l_AdaptiveExperiment_decodeTree___closed__10));
if (lean_obj_tag(v___x_1821_) == 0)
{
lean_object* v___x_1852_; 
v___x_1852_ = lean_box(0);
v___y_1847_ = v___x_1852_;
goto v___jp_1846_;
}
else
{
lean_object* v_val_1853_; 
v_val_1853_ = lean_ctor_get(v___x_1821_, 0);
lean_inc(v_val_1853_);
v___y_1847_ = v_val_1853_;
goto v___jp_1846_;
}
v___jp_1826_:
{
lean_object* v___x_1830_; lean_object* v___x_1831_; lean_object* v___x_1832_; lean_object* v___x_1833_; lean_object* v___x_1834_; lean_object* v___x_1835_; lean_object* v___x_1836_; lean_object* v___x_1837_; lean_object* v___x_1838_; lean_object* v___x_1839_; lean_object* v___x_1840_; lean_object* v___x_1841_; lean_object* v___x_1843_; 
v___x_1830_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_1830_, 0, v___y_1829_);
lean_inc_ref(v___y_1828_);
v___x_1831_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1831_, 0, v___y_1828_);
lean_ctor_set(v___x_1831_, 1, v___x_1830_);
v___x_1832_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__30));
v___x_1833_ = l_LeanSort_Adaptive_execute___at___00LeanSort_Adaptive_selectAndRun___at___00AdaptiveExperiment_Strategy_run_spec__0_spec__0(v___x_1821_, v_a_1613_);
v___x_1834_ = l_Lean_List_toJson___at___00AdaptiveExperiment_benchmark_spec__0(v___x_1833_);
v___x_1835_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1835_, 0, v___x_1832_);
lean_ctor_set(v___x_1835_, 1, v___x_1834_);
v___x_1836_ = lean_box(0);
v___x_1837_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1837_, 0, v___x_1835_);
lean_ctor_set(v___x_1837_, 1, v___x_1836_);
v___x_1838_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1838_, 0, v___x_1831_);
lean_ctor_set(v___x_1838_, 1, v___x_1837_);
v___x_1839_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1839_, 0, v___y_1827_);
lean_ctor_set(v___x_1839_, 1, v___x_1838_);
v___x_1840_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1840_, 0, v___x_1825_);
lean_ctor_set(v___x_1840_, 1, v___x_1839_);
v___x_1841_ = l_Lean_Json_mkObj(v___x_1840_);
lean_dec_ref_known(v___x_1840_, 2);
if (v_isShared_1620_ == 0)
{
lean_ctor_set(v___x_1619_, 0, v___x_1841_);
v___x_1843_ = v___x_1619_;
goto v_reusejp_1842_;
}
else
{
lean_object* v_reuseFailAlloc_1844_; 
v_reuseFailAlloc_1844_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1844_, 0, v___x_1841_);
v___x_1843_ = v_reuseFailAlloc_1844_;
goto v_reusejp_1842_;
}
v_reusejp_1842_:
{
return v___x_1843_;
}
}
v___jp_1846_:
{
lean_object* v___x_1848_; lean_object* v___x_1849_; lean_object* v___x_1850_; 
v___x_1848_ = l_AdaptiveExperiment_planJson(v___y_1847_);
v___x_1849_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1849_, 0, v___x_1845_);
lean_ctor_set(v___x_1849_, 1, v___x_1848_);
v___x_1850_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__29));
if (lean_obj_tag(v___x_1821_) == 0)
{
v___y_1827_ = v___x_1849_;
v___y_1828_ = v___x_1850_;
v___y_1829_ = v___x_1622_;
goto v___jp_1826_;
}
else
{
uint8_t v___x_1851_; 
v___x_1851_ = 0;
v___y_1827_ = v___x_1849_;
v___y_1828_ = v___x_1850_;
v___y_1829_ = v___x_1851_;
goto v___jp_1826_;
}
}
}
}
}
else
{
lean_object* v_a_1855_; lean_object* v___x_1857_; uint8_t v_isShared_1858_; uint8_t v_isSharedCheck_1862_; 
lean_dec(v_a_1613_);
lean_dec(v_best_1583_);
lean_dec(v_model_1582_);
lean_dec(v_j_1581_);
v_a_1855_ = lean_ctor_get(v___x_1616_, 0);
v_isSharedCheck_1862_ = !lean_is_exclusive(v___x_1616_);
if (v_isSharedCheck_1862_ == 0)
{
v___x_1857_ = v___x_1616_;
v_isShared_1858_ = v_isSharedCheck_1862_;
goto v_resetjp_1856_;
}
else
{
lean_inc(v_a_1855_);
lean_dec(v___x_1616_);
v___x_1857_ = lean_box(0);
v_isShared_1858_ = v_isSharedCheck_1862_;
goto v_resetjp_1856_;
}
v_resetjp_1856_:
{
lean_object* v___x_1860_; 
if (v_isShared_1858_ == 0)
{
v___x_1860_ = v___x_1857_;
goto v_reusejp_1859_;
}
else
{
lean_object* v_reuseFailAlloc_1861_; 
v_reuseFailAlloc_1861_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1861_, 0, v_a_1855_);
v___x_1860_ = v_reuseFailAlloc_1861_;
goto v_reusejp_1859_;
}
v_reusejp_1859_:
{
return v___x_1860_;
}
}
}
}
else
{
lean_object* v_a_1863_; lean_object* v___x_1865_; uint8_t v_isShared_1866_; uint8_t v_isSharedCheck_1870_; 
lean_dec(v_best_1583_);
lean_dec(v_model_1582_);
lean_dec(v_j_1581_);
v_a_1863_ = lean_ctor_get(v___x_1612_, 0);
v_isSharedCheck_1870_ = !lean_is_exclusive(v___x_1612_);
if (v_isSharedCheck_1870_ == 0)
{
v___x_1865_ = v___x_1612_;
v_isShared_1866_ = v_isSharedCheck_1870_;
goto v_resetjp_1864_;
}
else
{
lean_inc(v_a_1863_);
lean_dec(v___x_1612_);
v___x_1865_ = lean_box(0);
v_isShared_1866_ = v_isSharedCheck_1870_;
goto v_resetjp_1864_;
}
v_resetjp_1864_:
{
lean_object* v___x_1868_; 
if (v_isShared_1866_ == 0)
{
v___x_1868_ = v___x_1865_;
goto v_reusejp_1867_;
}
else
{
lean_object* v_reuseFailAlloc_1869_; 
v_reuseFailAlloc_1869_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1869_, 0, v_a_1863_);
v___x_1868_ = v_reuseFailAlloc_1869_;
goto v_reusejp_1867_;
}
v_reusejp_1867_:
{
return v___x_1868_;
}
}
}
v___jp_1585_:
{
lean_object* v___x_1593_; lean_object* v___x_1594_; lean_object* v___x_1595_; lean_object* v___x_1596_; lean_object* v___x_1597_; lean_object* v___x_1598_; lean_object* v___x_1599_; lean_object* v___x_1600_; lean_object* v___x_1601_; lean_object* v___x_1602_; lean_object* v___x_1603_; lean_object* v___x_1604_; lean_object* v___x_1605_; lean_object* v___x_1606_; lean_object* v___x_1607_; lean_object* v___x_1608_; lean_object* v___x_1609_; lean_object* v___x_1610_; 
v___x_1593_ = l_AdaptiveExperiment_planJson(v___y_1592_);
lean_inc_ref(v___y_1590_);
v___x_1594_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1594_, 0, v___y_1590_);
lean_ctor_set(v___x_1594_, 1, v___x_1593_);
v___x_1595_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__0));
v___x_1596_ = l_AdaptiveExperiment_manual(v___y_1586_);
lean_dec_ref(v___y_1586_);
v___x_1597_ = l_AdaptiveExperiment_planJson(v___x_1596_);
v___x_1598_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1598_, 0, v___x_1595_);
lean_ctor_set(v___x_1598_, 1, v___x_1597_);
v___x_1599_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__1));
v___x_1600_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_1600_, 0, v___y_1588_);
v___x_1601_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1601_, 0, v___x_1599_);
lean_ctor_set(v___x_1601_, 1, v___x_1600_);
v___x_1602_ = lean_box(0);
v___x_1603_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1603_, 0, v___x_1601_);
lean_ctor_set(v___x_1603_, 1, v___x_1602_);
v___x_1604_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1604_, 0, v___x_1598_);
lean_ctor_set(v___x_1604_, 1, v___x_1603_);
v___x_1605_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1605_, 0, v___x_1594_);
lean_ctor_set(v___x_1605_, 1, v___x_1604_);
v___x_1606_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1606_, 0, v___y_1591_);
lean_ctor_set(v___x_1606_, 1, v___x_1605_);
v___x_1607_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1607_, 0, v___y_1587_);
lean_ctor_set(v___x_1607_, 1, v___x_1606_);
v___x_1608_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1608_, 0, v___y_1589_);
lean_ctor_set(v___x_1608_, 1, v___x_1607_);
v___x_1609_ = l_Lean_Json_mkObj(v___x_1608_);
lean_dec_ref_known(v___x_1608_, 2);
v___x_1610_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1610_, 0, v___x_1609_);
return v___x_1610_;
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_handle___boxed(lean_object* v_j_1871_, lean_object* v_model_1872_, lean_object* v_best_1873_, lean_object* v_a_1874_){
_start:
{
lean_object* v_res_1875_; 
v_res_1875_ = l_AdaptiveExperiment_handle(v_j_1871_, v_model_1872_, v_best_1873_);
return v_res_1875_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_handle_spec__1(lean_object* v_val_1876_, lean_object* v_val_1877_, lean_object* v_as_1878_, lean_object* v_as_x27_1879_, lean_object* v_b_1880_, lean_object* v_a_1881_){
_start:
{
lean_object* v___x_1883_; 
v___x_1883_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_handle_spec__1___redArg(v_val_1876_, v_val_1877_, v_as_x27_1879_, v_b_1880_);
return v___x_1883_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00AdaptiveExperiment_handle_spec__1___boxed(lean_object* v_val_1884_, lean_object* v_val_1885_, lean_object* v_as_1886_, lean_object* v_as_x27_1887_, lean_object* v_b_1888_, lean_object* v_a_1889_, lean_object* v___y_1890_){
_start:
{
lean_object* v_res_1891_; 
v_res_1891_ = l_List_forIn_x27_loop___at___00AdaptiveExperiment_handle_spec__1(v_val_1884_, v_val_1885_, v_as_1886_, v_as_x27_1887_, v_b_1888_, v_a_1889_);
lean_dec(v_as_x27_1887_);
lean_dec(v_as_1886_);
lean_dec(v_val_1885_);
lean_dec(v_val_1884_);
return v_res_1891_;
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_loop(lean_object* v_model_1900_, lean_object* v_best_1901_){
_start:
{
lean_object* v___x_1903_; lean_object* v___x_1904_; lean_object* v_fst_1906_; lean_object* v_snd_1907_; lean_object* v_a_1916_; lean_object* v_getLine_1925_; lean_object* v___x_1926_; 
v___x_1903_ = lean_get_stdin();
v___x_1904_ = lean_get_stdout();
v_getLine_1925_ = lean_ctor_get(v___x_1903_, 3);
lean_inc_ref(v_getLine_1925_);
lean_dec_ref(v___x_1903_);
v___x_1926_ = lean_apply_1(v_getLine_1925_, lean_box(0));
if (lean_obj_tag(v___x_1926_) == 0)
{
lean_object* v_a_1927_; lean_object* v___x_1929_; uint8_t v_isShared_1930_; uint8_t v_isSharedCheck_2026_; 
v_a_1927_ = lean_ctor_get(v___x_1926_, 0);
v_isSharedCheck_2026_ = !lean_is_exclusive(v___x_1926_);
if (v_isSharedCheck_2026_ == 0)
{
v___x_1929_ = v___x_1926_;
v_isShared_1930_ = v_isSharedCheck_2026_;
goto v_resetjp_1928_;
}
else
{
lean_inc(v_a_1927_);
lean_dec(v___x_1926_);
v___x_1929_ = lean_box(0);
v_isShared_1930_ = v_isSharedCheck_2026_;
goto v_resetjp_1928_;
}
v_resetjp_1928_:
{
lean_object* v___x_1931_; lean_object* v___x_1932_; uint8_t v___x_1933_; 
v___x_1931_ = lean_string_utf8_byte_size(v_a_1927_);
v___x_1932_ = lean_unsigned_to_nat(0u);
v___x_1933_ = lean_nat_dec_eq(v___x_1931_, v___x_1932_);
if (v___x_1933_ == 0)
{
lean_object* v___x_1934_; lean_object* v___x_1935_; 
lean_del_object(v___x_1929_);
v___x_1934_ = l_Lean_Json_parse(v_a_1927_);
v___x_1935_ = l_AdaptiveExperiment_orError___redArg(v___x_1934_);
if (lean_obj_tag(v___x_1935_) == 0)
{
lean_object* v_a_1936_; lean_object* v___x_1938_; uint8_t v_isShared_1939_; uint8_t v_isSharedCheck_2020_; 
v_a_1936_ = lean_ctor_get(v___x_1935_, 0);
v_isSharedCheck_2020_ = !lean_is_exclusive(v___x_1935_);
if (v_isSharedCheck_2020_ == 0)
{
v___x_1938_ = v___x_1935_;
v_isShared_1939_ = v_isSharedCheck_2020_;
goto v_resetjp_1937_;
}
else
{
lean_inc(v_a_1936_);
lean_dec(v___x_1935_);
v___x_1938_ = lean_box(0);
v_isShared_1939_ = v_isSharedCheck_2020_;
goto v_resetjp_1937_;
}
v_resetjp_1937_:
{
lean_object* v___y_1941_; lean_object* v___y_1942_; lean_object* v___y_1943_; lean_object* v___y_1944_; lean_object* v___y_1945_; lean_object* v___y_1946_; lean_object* v___y_1958_; lean_object* v___y_1959_; lean_object* v___y_1960_; lean_object* v___y_1961_; lean_object* v___y_1962_; uint8_t v___y_1963_; lean_object* v___y_1970_; lean_object* v___y_1971_; uint8_t v___y_1972_; lean_object* v___y_1973_; lean_object* v___y_1974_; uint8_t v___y_1975_; uint8_t v___y_1980_; lean_object* v___y_1981_; lean_object* v___y_1982_; lean_object* v___y_1983_; uint8_t v___y_1986_; lean_object* v___y_1987_; lean_object* v___y_1988_; lean_object* v___y_1996_; lean_object* v___x_2009_; lean_object* v___x_2010_; 
v___x_2009_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__2));
lean_inc(v_a_1936_);
v___x_2010_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_a_1936_, v___x_2009_);
if (lean_obj_tag(v___x_2010_) == 0)
{
lean_object* v___x_2011_; 
lean_dec_ref_known(v___x_2010_, 1);
v___x_2011_ = lean_box(0);
v___y_1996_ = v___x_2011_;
goto v___jp_1995_;
}
else
{
lean_object* v_a_2012_; lean_object* v___x_2014_; uint8_t v_isShared_2015_; uint8_t v_isSharedCheck_2019_; 
v_a_2012_ = lean_ctor_get(v___x_2010_, 0);
v_isSharedCheck_2019_ = !lean_is_exclusive(v___x_2010_);
if (v_isSharedCheck_2019_ == 0)
{
v___x_2014_ = v___x_2010_;
v_isShared_2015_ = v_isSharedCheck_2019_;
goto v_resetjp_2013_;
}
else
{
lean_inc(v_a_2012_);
lean_dec(v___x_2010_);
v___x_2014_ = lean_box(0);
v_isShared_2015_ = v_isSharedCheck_2019_;
goto v_resetjp_2013_;
}
v_resetjp_2013_:
{
lean_object* v___x_2017_; 
if (v_isShared_2015_ == 0)
{
v___x_2017_ = v___x_2014_;
goto v_reusejp_2016_;
}
else
{
lean_object* v_reuseFailAlloc_2018_; 
v_reuseFailAlloc_2018_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2018_, 0, v_a_2012_);
v___x_2017_ = v_reuseFailAlloc_2018_;
goto v_reusejp_2016_;
}
v_reusejp_2016_:
{
v___y_1996_ = v___x_2017_;
goto v___jp_1995_;
}
}
}
v___jp_1940_:
{
lean_object* v___x_1948_; 
if (v_isShared_1939_ == 0)
{
lean_ctor_set_tag(v___x_1938_, 3);
lean_ctor_set(v___x_1938_, 0, v___y_1946_);
v___x_1948_ = v___x_1938_;
goto v_reusejp_1947_;
}
else
{
lean_object* v_reuseFailAlloc_1956_; 
v_reuseFailAlloc_1956_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1956_, 0, v___y_1946_);
v___x_1948_ = v_reuseFailAlloc_1956_;
goto v_reusejp_1947_;
}
v_reusejp_1947_:
{
lean_object* v___x_1949_; lean_object* v___x_1950_; lean_object* v___x_1951_; lean_object* v___x_1952_; lean_object* v___x_1953_; lean_object* v___x_1954_; lean_object* v___x_1955_; 
lean_inc_ref(v___y_1943_);
v___x_1949_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1949_, 0, v___y_1943_);
lean_ctor_set(v___x_1949_, 1, v___x_1948_);
v___x_1950_ = lean_box(0);
v___x_1951_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1951_, 0, v___x_1949_);
lean_ctor_set(v___x_1951_, 1, v___x_1950_);
v___x_1952_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1952_, 0, v___y_1941_);
lean_ctor_set(v___x_1952_, 1, v___x_1951_);
v___x_1953_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1953_, 0, v___y_1945_);
lean_ctor_set(v___x_1953_, 1, v___x_1952_);
v___x_1954_ = l_Lean_Json_mkObj(v___x_1953_);
lean_dec_ref_known(v___x_1953_, 2);
v___x_1955_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1955_, 0, v___y_1944_);
lean_ctor_set(v___x_1955_, 1, v___y_1942_);
v_fst_1906_ = v___x_1954_;
v_snd_1907_ = v___x_1955_;
goto v___jp_1905_;
}
}
v___jp_1957_:
{
lean_object* v___x_1964_; lean_object* v___x_1965_; lean_object* v___x_1966_; 
v___x_1964_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_1964_, 0, v___y_1963_);
lean_inc_ref(v___y_1958_);
v___x_1965_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1965_, 0, v___y_1958_);
lean_ctor_set(v___x_1965_, 1, v___x_1964_);
v___x_1966_ = ((lean_object*)(l_AdaptiveExperiment_loop___closed__1));
if (lean_obj_tag(v___y_1961_) == 0)
{
lean_object* v_a_1967_; 
v_a_1967_ = lean_ctor_get(v___y_1961_, 0);
lean_inc(v_a_1967_);
lean_dec_ref_known(v___y_1961_, 1);
v___y_1941_ = v___x_1965_;
v___y_1942_ = v___y_1959_;
v___y_1943_ = v___x_1966_;
v___y_1944_ = v___y_1960_;
v___y_1945_ = v___y_1962_;
v___y_1946_ = v_a_1967_;
goto v___jp_1940_;
}
else
{
lean_object* v___x_1968_; 
lean_dec_ref_known(v___y_1961_, 1);
v___x_1968_ = ((lean_object*)(l_AdaptiveExperiment_loop___closed__2));
v___y_1941_ = v___x_1965_;
v___y_1942_ = v___y_1959_;
v___y_1943_ = v___x_1966_;
v___y_1944_ = v___y_1960_;
v___y_1945_ = v___y_1962_;
v___y_1946_ = v___x_1968_;
goto v___jp_1940_;
}
}
v___jp_1969_:
{
lean_object* v___x_1976_; lean_object* v___x_1977_; lean_object* v___x_1978_; 
v___x_1976_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_1976_, 0, v___y_1975_);
lean_inc_ref(v___y_1971_);
v___x_1977_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1977_, 0, v___y_1971_);
lean_ctor_set(v___x_1977_, 1, v___x_1976_);
v___x_1978_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__29));
if (lean_obj_tag(v___y_1973_) == 0)
{
v___y_1958_ = v___x_1978_;
v___y_1959_ = v___y_1970_;
v___y_1960_ = v___y_1973_;
v___y_1961_ = v___y_1974_;
v___y_1962_ = v___x_1977_;
v___y_1963_ = v___y_1972_;
goto v___jp_1957_;
}
else
{
v___y_1958_ = v___x_1978_;
v___y_1959_ = v___y_1970_;
v___y_1960_ = v___y_1973_;
v___y_1961_ = v___y_1974_;
v___y_1962_ = v___x_1977_;
v___y_1963_ = v___x_1933_;
goto v___jp_1957_;
}
}
v___jp_1979_:
{
lean_object* v___x_1984_; 
v___x_1984_ = ((lean_object*)(l_AdaptiveExperiment_loop___closed__3));
if (lean_obj_tag(v___y_1981_) == 0)
{
v___y_1970_ = v___y_1983_;
v___y_1971_ = v___x_1984_;
v___y_1972_ = v___y_1980_;
v___y_1973_ = v___y_1981_;
v___y_1974_ = v___y_1982_;
v___y_1975_ = v___x_1933_;
goto v___jp_1969_;
}
else
{
v___y_1970_ = v___y_1983_;
v___y_1971_ = v___x_1984_;
v___y_1972_ = v___y_1980_;
v___y_1973_ = v___y_1981_;
v___y_1974_ = v___y_1982_;
v___y_1975_ = v___y_1980_;
goto v___jp_1969_;
}
}
v___jp_1985_:
{
lean_object* v___x_1989_; lean_object* v___x_1990_; lean_object* v___x_1991_; lean_object* v___x_1992_; 
v___x_1989_ = lean_unsigned_to_nat(16u);
v___x_1990_ = ((lean_object*)(l_AdaptiveExperiment_handle___closed__22));
v___x_1991_ = l_Lean_Json_getObjValD(v_a_1936_, v___x_1990_);
v___x_1992_ = l_AdaptiveExperiment_decodePlan(v___x_1989_, v___x_1991_);
if (lean_obj_tag(v___x_1992_) == 0)
{
lean_object* v___x_1993_; 
lean_dec_ref_known(v___x_1992_, 1);
v___x_1993_ = lean_box(0);
v___y_1980_ = v___y_1986_;
v___y_1981_ = v___y_1988_;
v___y_1982_ = v___y_1987_;
v___y_1983_ = v___x_1993_;
goto v___jp_1979_;
}
else
{
lean_object* v_a_1994_; 
v_a_1994_ = lean_ctor_get(v___x_1992_, 0);
lean_inc(v_a_1994_);
lean_dec_ref_known(v___x_1992_, 1);
v___y_1980_ = v___y_1986_;
v___y_1981_ = v___y_1988_;
v___y_1982_ = v___y_1987_;
v___y_1983_ = v_a_1994_;
goto v___jp_1979_;
}
}
v___jp_1995_:
{
lean_object* v___x_1997_; uint8_t v___x_1998_; 
v___x_1997_ = ((lean_object*)(l_AdaptiveExperiment_loop___closed__5));
v___x_1998_ = l_Option_instBEq_beq___at___00Lean_forEachModuleInDir___at___00Lean_Lsp_ImportCompletion_collectAvailableImportsFromSrcSearchPath_spec__0_spec__0(v___y_1996_, v___x_1997_);
lean_dec(v___y_1996_);
if (v___x_1998_ == 0)
{
lean_object* v___x_1999_; 
lean_del_object(v___x_1938_);
lean_inc(v_best_1901_);
lean_inc(v_model_1900_);
v___x_1999_ = l_AdaptiveExperiment_handle(v_a_1936_, v_model_1900_, v_best_1901_);
if (lean_obj_tag(v___x_1999_) == 0)
{
lean_object* v_a_2000_; lean_object* v___x_2001_; 
v_a_2000_ = lean_ctor_get(v___x_1999_, 0);
lean_inc(v_a_2000_);
lean_dec_ref_known(v___x_1999_, 1);
v___x_2001_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2001_, 0, v_model_1900_);
lean_ctor_set(v___x_2001_, 1, v_best_1901_);
v_fst_1906_ = v_a_2000_;
v_snd_1907_ = v___x_2001_;
goto v___jp_1905_;
}
else
{
lean_object* v_a_2002_; 
v_a_2002_ = lean_ctor_get(v___x_1999_, 0);
lean_inc(v_a_2002_);
lean_dec_ref_known(v___x_1999_, 1);
v_a_1916_ = v_a_2002_;
goto v___jp_1915_;
}
}
else
{
lean_object* v___x_2003_; lean_object* v___x_2004_; lean_object* v___x_2005_; 
lean_dec(v_best_1901_);
lean_dec(v_model_1900_);
v___x_2003_ = ((lean_object*)(l_AdaptiveExperiment_loop___closed__6));
lean_inc(v_a_1936_);
v___x_2004_ = l_Lean_Json_getObjValD(v_a_1936_, v___x_2003_);
v___x_2005_ = l_AdaptiveExperiment_decodeModel(v___x_2004_);
if (lean_obj_tag(v___x_2005_) == 0)
{
lean_object* v___x_2006_; 
v___x_2006_ = lean_box(0);
v___y_1986_ = v___x_1998_;
v___y_1987_ = v___x_2005_;
v___y_1988_ = v___x_2006_;
goto v___jp_1985_;
}
else
{
lean_object* v_a_2007_; lean_object* v___x_2008_; 
v_a_2007_ = lean_ctor_get(v___x_2005_, 0);
lean_inc(v_a_2007_);
v___x_2008_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2008_, 0, v_a_2007_);
v___y_1986_ = v___x_1998_;
v___y_1987_ = v___x_2005_;
v___y_1988_ = v___x_2008_;
goto v___jp_1985_;
}
}
}
}
}
else
{
lean_object* v_a_2021_; 
v_a_2021_ = lean_ctor_get(v___x_1935_, 0);
lean_inc(v_a_2021_);
lean_dec_ref_known(v___x_1935_, 1);
v_a_1916_ = v_a_2021_;
goto v___jp_1915_;
}
}
else
{
lean_object* v___x_2022_; lean_object* v___x_2024_; 
lean_dec(v_a_1927_);
lean_dec_ref(v___x_1904_);
lean_dec(v_best_1901_);
lean_dec(v_model_1900_);
v___x_2022_ = lean_box(0);
if (v_isShared_1930_ == 0)
{
lean_ctor_set(v___x_1929_, 0, v___x_2022_);
v___x_2024_ = v___x_1929_;
goto v_reusejp_2023_;
}
else
{
lean_object* v_reuseFailAlloc_2025_; 
v_reuseFailAlloc_2025_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2025_, 0, v___x_2022_);
v___x_2024_ = v_reuseFailAlloc_2025_;
goto v_reusejp_2023_;
}
v_reusejp_2023_:
{
return v___x_2024_;
}
}
}
}
else
{
lean_object* v_a_2027_; lean_object* v___x_2029_; uint8_t v_isShared_2030_; uint8_t v_isSharedCheck_2034_; 
lean_dec_ref(v___x_1904_);
lean_dec(v_best_1901_);
lean_dec(v_model_1900_);
v_a_2027_ = lean_ctor_get(v___x_1926_, 0);
v_isSharedCheck_2034_ = !lean_is_exclusive(v___x_1926_);
if (v_isSharedCheck_2034_ == 0)
{
v___x_2029_ = v___x_1926_;
v_isShared_2030_ = v_isSharedCheck_2034_;
goto v_resetjp_2028_;
}
else
{
lean_inc(v_a_2027_);
lean_dec(v___x_1926_);
v___x_2029_ = lean_box(0);
v_isShared_2030_ = v_isSharedCheck_2034_;
goto v_resetjp_2028_;
}
v_resetjp_2028_:
{
lean_object* v___x_2032_; 
if (v_isShared_2030_ == 0)
{
v___x_2032_ = v___x_2029_;
goto v_reusejp_2031_;
}
else
{
lean_object* v_reuseFailAlloc_2033_; 
v_reuseFailAlloc_2033_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2033_, 0, v_a_2027_);
v___x_2032_ = v_reuseFailAlloc_2033_;
goto v_reusejp_2031_;
}
v_reusejp_2031_:
{
return v___x_2032_;
}
}
}
v___jp_1905_:
{
lean_object* v___x_1908_; lean_object* v___x_1909_; 
v___x_1908_ = l_Lean_Json_compress(v_fst_1906_);
lean_inc_ref(v___x_1904_);
v___x_1909_ = l_IO_FS_Stream_putStrLn(v___x_1904_, v___x_1908_);
if (lean_obj_tag(v___x_1909_) == 0)
{
lean_object* v_flush_1910_; lean_object* v___x_1911_; 
lean_dec_ref_known(v___x_1909_, 1);
v_flush_1910_ = lean_ctor_get(v___x_1904_, 0);
lean_inc_ref(v_flush_1910_);
lean_dec_ref(v___x_1904_);
v___x_1911_ = lean_apply_1(v_flush_1910_, lean_box(0));
if (lean_obj_tag(v___x_1911_) == 0)
{
lean_object* v_fst_1912_; lean_object* v_snd_1913_; 
lean_dec_ref_known(v___x_1911_, 1);
v_fst_1912_ = lean_ctor_get(v_snd_1907_, 0);
lean_inc(v_fst_1912_);
v_snd_1913_ = lean_ctor_get(v_snd_1907_, 1);
lean_inc(v_snd_1913_);
lean_dec(v_snd_1907_);
v_model_1900_ = v_fst_1912_;
v_best_1901_ = v_snd_1913_;
goto _start;
}
else
{
lean_dec(v_snd_1907_);
return v___x_1911_;
}
}
else
{
lean_dec(v_snd_1907_);
lean_dec_ref(v___x_1904_);
return v___x_1909_;
}
}
v___jp_1915_:
{
lean_object* v___x_1917_; lean_object* v___x_1918_; lean_object* v___x_1919_; lean_object* v___x_1920_; lean_object* v___x_1921_; lean_object* v___x_1922_; lean_object* v___x_1923_; lean_object* v___x_1924_; 
v___x_1917_ = ((lean_object*)(l_AdaptiveExperiment_loop___closed__0));
v___x_1918_ = lean_io_error_to_string(v_a_1916_);
v___x_1919_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1919_, 0, v___x_1918_);
v___x_1920_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1920_, 0, v___x_1917_);
lean_ctor_set(v___x_1920_, 1, v___x_1919_);
v___x_1921_ = lean_box(0);
v___x_1922_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1922_, 0, v___x_1920_);
lean_ctor_set(v___x_1922_, 1, v___x_1921_);
v___x_1923_ = l_Lean_Json_mkObj(v___x_1922_);
lean_dec_ref_known(v___x_1922_, 2);
v___x_1924_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1924_, 0, v_model_1900_);
lean_ctor_set(v___x_1924_, 1, v_best_1901_);
v_fst_1906_ = v___x_1923_;
v_snd_1907_ = v___x_1924_;
goto v___jp_1905_;
}
}
}
LEAN_EXPORT lean_object* l_AdaptiveExperiment_loop___boxed(lean_object* v_model_2035_, lean_object* v_best_2036_, lean_object* v_a_2037_){
_start:
{
lean_object* v_res_2038_; 
v_res_2038_ = l_AdaptiveExperiment_loop(v_model_2035_, v_best_2036_);
return v_res_2038_;
}
}
LEAN_EXPORT lean_object* _lean_main(){
_start:
{
lean_object* v___x_2041_; lean_object* v___x_2042_; lean_object* v___x_2043_; 
v___x_2041_ = lean_get_stdout();
v___x_2042_ = ((lean_object*)(l_main___closed__0));
lean_inc_ref(v___x_2041_);
v___x_2043_ = l_IO_FS_Stream_putStrLn(v___x_2041_, v___x_2042_);
if (lean_obj_tag(v___x_2043_) == 0)
{
lean_object* v_flush_2044_; lean_object* v___x_2045_; 
lean_dec_ref_known(v___x_2043_, 1);
v_flush_2044_ = lean_ctor_get(v___x_2041_, 0);
lean_inc_ref(v_flush_2044_);
lean_dec_ref(v___x_2041_);
v___x_2045_ = lean_apply_1(v_flush_2044_, lean_box(0));
if (lean_obj_tag(v___x_2045_) == 0)
{
lean_object* v___x_2046_; lean_object* v___x_2047_; lean_object* v___x_2048_; 
lean_dec_ref_known(v___x_2045_, 1);
v___x_2046_ = lean_box(0);
v___x_2047_ = lean_box(0);
v___x_2048_ = l_AdaptiveExperiment_loop(v___x_2046_, v___x_2047_);
return v___x_2048_;
}
else
{
return v___x_2045_;
}
}
else
{
lean_dec_ref(v___x_2041_);
return v___x_2043_;
}
}
}
LEAN_EXPORT lean_object* l_main___boxed(lean_object* v_a_2049_){
_start:
{
lean_object* v_res_2050_; 
v_res_2050_ = _lean_main();
return v_res_2050_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_leansort_LeanSort_Verification_Adaptive_Correctness(uint8_t builtin);
lean_object* initialize_Lean(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_experiments_adaptive_Worker(uint8_t builtin) {
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
res = initialize_leansort_LeanSort_Verification_Adaptive_Correctness(builtin);
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
  res = initialize_experiments_adaptive_Worker(1 /* builtin */);
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
