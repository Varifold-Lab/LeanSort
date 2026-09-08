// Lean compiler output
// Module: experiments.«selection-break-even».Worker
// Imports: public import Init public meta import Init public import LeanSort.Algorithm.BudgetSelection.Features public import Lean
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
lean_object* lp_leansort_LeanSort_RunAdaptive_lengthPlan___redArg(lean_object*);
lean_object* l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(lean_object*);
lean_object* l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
uint8_t lp_leansort_LeanSort_Comparison_instDecidableEqPhase(uint8_t, uint8_t);
lean_object* l_List_reverse___redArg(lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* l_List_drop___redArg(lean_object*, lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_CostedPlan_Cut_position(lean_object*, lean_object*);
lean_object* lean_nat_to_int(lean_object*);
lean_object* l_Lean_JsonNumber_fromInt(lean_object*);
lean_object* l_Lean_JsonNumber_fromNat(lean_object*);
lean_object* l_Lean_Json_mkObj(lean_object*);
lean_object* lean_get_stdout();
lean_object* l_Lean_Json_compress(lean_object*);
lean_object* l_IO_FS_Stream_putStrLn(lean_object*, lean_object*);
lean_object* lean_io_mono_nanos_now();
lean_object* lean_st_ref_get(lean_object*);
lean_object* l_LeanSort_BudgetSelection_select(lean_object*, lean_object*);
lean_object* l_LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* lean_st_ref_set(lean_object*, lean_object*);
lean_object* l_LeanSort_LearnedSelection_resolve(lean_object*);
uint8_t l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* l_LeanSort_BudgetSelection_choose(lean_object*, lean_object*);
lean_object* l_LeanSort_BudgetSelection_features(uint8_t, lean_object*);
lean_object* lean_array_mk(lean_object*);
lean_object* l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonFuncTable_toJson_spec__0(lean_object*);
lean_object* l_LeanSort_LearnedSelection_Tree_eval(lean_object*, lean_object*);
lean_object* l_LeanSort_LearnedSelection_candidate(lean_object*);
lean_object* lp_leansort_LeanSort_RunAdaptive_countPlan___redArg(lean_object*);
lean_object* lp_leansort_LeanSort_CostedPlan_Schema_upper(lean_object*, lean_object*);
lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_run___at___00LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0_spec__0_spec__1_spec__3_spec__7(lean_object*);
lean_object* lp_mathlib_Nat_clog(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_RunAdaptive_MergeTree_budget___redArg(lean_object*);
lean_object* l_Lean_Option_toJson___at___00Lean_Json_toStructured_x3f___at___00Lean_Server_FileWorker_sendServerRequest___at___00Lean_Server_FileWorker_runRefreshTasks_spec__0_spec__1_spec__3(lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_ComparisonSort_checkSorted___redArg(lean_object*);
lean_object* lp_leansort_LeanSort_CostedPlan_Schema_readyUpper(lean_object*, lean_object*);
lean_object* l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(lean_object*, lean_object*);
lean_object* l_List_get_x3fInternal___redArg(lean_object*, lean_object*);
size_t lean_array_size(lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonStackTable_fromJson_spec__0_spec__0(lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* lean_array_uset(lean_object*, size_t, lean_object*);
size_t lean_usize_add(size_t, size_t);
lean_object* l_Lean_Json_pretty(lean_object*, lean_object*);
lean_object* lean_string_append(lean_object*, lean_object*);
lean_object* lean_st_mk_ref(lean_object*);
lean_object* l_List_range(lean_object*);
lean_object* l_Nat_reprFast(lean_object*);
lean_object* l_LeanSort_BudgetSelection_Engine_feature___at___00LeanSort_BudgetSelection_counted_spec__0(uint8_t, lean_object*);
lean_object* lean_array_uget(lean_object*, size_t);
lean_object* l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__0(lean_object*);
lean_object* l_LeanSort_BudgetSelection_FeatureSet_budget(uint8_t);
lean_object* lean_io_error_to_string(lean_object*);
lean_object* lean_get_stdin();
lean_object* lean_string_utf8_byte_size(lean_object*);
lean_object* l_Lean_Json_parse(lean_object*);
lean_object* l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(lean_object*, lean_object*);
lean_object* l_Lean_Json_getObjValD(lean_object*, lean_object*);
lean_object* l_LeanSort_BudgetSelection_run(lean_object*, lean_object*);
lean_object* l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(lean_object*);
lean_object* lp_LeanSearchClient_Lean_Json_getObjValAs_x3f___at___00LeanSearchClient_getLoogleQueryJson_spec__4(lean_object*, lean_object*);
lean_object* lean_int_neg(lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_Widget_instRpcEncodableStrictOrLazy_dec_00___x40_Lean_Widget_InteractiveDiagnostic_2157017296____hygCtx___hyg_1____at___00Lean_Widget_instRpcEncodableHighlightedMsgEmbed_dec_00___x40_Lean_Server_FileWorker_WidgetRequests_2377472685____hygCtx___hyg_1__spec__2_spec__3(lean_object*);
lean_object* l_Lean_Json_getObjVal_x3f(lean_object*, lean_object*);
lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonFuncTable_fromJson_spec__0_spec__0(lean_object*);
lean_object* l_Lean_Json_getObjValAs_x3f___at___00Lean_IO_FS_Stream_readRequestAs___at___00Lean_IO_FS_Stream_readLspRequestAs___at___00Lean_Server_FileWorker_initAndRunWorker_spec__0_spec__0_spec__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_orError___redArg(lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_orError___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_orError(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_orError___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_decodeTree_spec__0_spec__0(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_decodeTree_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_decodeTree_spec__0___boxed(lean_object*, lean_object*);
static const lean_string_object l_BudgetWorker_decodeTree___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 32, .m_capacity = 32, .m_length = 31, .m_data = "model tree exceeds depth budget"};
static const lean_object* l_BudgetWorker_decodeTree___closed__0 = (const lean_object*)&l_BudgetWorker_decodeTree___closed__0_value;
static const lean_ctor_object l_BudgetWorker_decodeTree___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_BudgetWorker_decodeTree___closed__0_value)}};
static const lean_object* l_BudgetWorker_decodeTree___closed__1 = (const lean_object*)&l_BudgetWorker_decodeTree___closed__1_value;
static const lean_string_object l_BudgetWorker_decodeTree___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "kind"};
static const lean_object* l_BudgetWorker_decodeTree___closed__2 = (const lean_object*)&l_BudgetWorker_decodeTree___closed__2_value;
static const lean_string_object l_BudgetWorker_decodeTree___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "leaf"};
static const lean_object* l_BudgetWorker_decodeTree___closed__3 = (const lean_object*)&l_BudgetWorker_decodeTree___closed__3_value;
static const lean_string_object l_BudgetWorker_decodeTree___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "branch"};
static const lean_object* l_BudgetWorker_decodeTree___closed__4 = (const lean_object*)&l_BudgetWorker_decodeTree___closed__4_value;
static const lean_string_object l_BudgetWorker_decodeTree___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "unsupported tree"};
static const lean_object* l_BudgetWorker_decodeTree___closed__5 = (const lean_object*)&l_BudgetWorker_decodeTree___closed__5_value;
static const lean_ctor_object l_BudgetWorker_decodeTree___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_BudgetWorker_decodeTree___closed__5_value)}};
static const lean_object* l_BudgetWorker_decodeTree___closed__6 = (const lean_object*)&l_BudgetWorker_decodeTree___closed__6_value;
static const lean_string_object l_BudgetWorker_decodeTree___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "feature"};
static const lean_object* l_BudgetWorker_decodeTree___closed__7 = (const lean_object*)&l_BudgetWorker_decodeTree___closed__7_value;
static const lean_string_object l_BudgetWorker_decodeTree___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "threshold"};
static const lean_object* l_BudgetWorker_decodeTree___closed__8 = (const lean_object*)&l_BudgetWorker_decodeTree___closed__8_value;
static const lean_string_object l_BudgetWorker_decodeTree___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "left"};
static const lean_object* l_BudgetWorker_decodeTree___closed__9 = (const lean_object*)&l_BudgetWorker_decodeTree___closed__9_value;
static const lean_string_object l_BudgetWorker_decodeTree___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "right"};
static const lean_object* l_BudgetWorker_decodeTree___closed__10 = (const lean_object*)&l_BudgetWorker_decodeTree___closed__10_value;
static const lean_string_object l_BudgetWorker_decodeTree___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "values"};
static const lean_object* l_BudgetWorker_decodeTree___closed__11 = (const lean_object*)&l_BudgetWorker_decodeTree___closed__11_value;
static const lean_string_object l_BudgetWorker_decodeTree___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "leaf too wide"};
static const lean_object* l_BudgetWorker_decodeTree___closed__12 = (const lean_object*)&l_BudgetWorker_decodeTree___closed__12_value;
static const lean_ctor_object l_BudgetWorker_decodeTree___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_BudgetWorker_decodeTree___closed__12_value)}};
static const lean_object* l_BudgetWorker_decodeTree___closed__13 = (const lean_object*)&l_BudgetWorker_decodeTree___closed__13_value;
LEAN_EXPORT lean_object* l_BudgetWorker_decodeTree(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_decodeTree___boxed(lean_object*, lean_object*);
static const lean_string_object l_BudgetWorker_kindName___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "length"};
static const lean_object* l_BudgetWorker_kindName___closed__0 = (const lean_object*)&l_BudgetWorker_kindName___closed__0_value;
static const lean_string_object l_BudgetWorker_kindName___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "eight"};
static const lean_object* l_BudgetWorker_kindName___closed__1 = (const lean_object*)&l_BudgetWorker_kindName___closed__1_value;
static const lean_string_object l_BudgetWorker_kindName___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "sixteen"};
static const lean_object* l_BudgetWorker_kindName___closed__2 = (const lean_object*)&l_BudgetWorker_kindName___closed__2_value;
static const lean_string_object l_BudgetWorker_kindName___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "legacy"};
static const lean_object* l_BudgetWorker_kindName___closed__3 = (const lean_object*)&l_BudgetWorker_kindName___closed__3_value;
LEAN_EXPORT lean_object* l_BudgetWorker_kindName(uint8_t);
LEAN_EXPORT lean_object* l_BudgetWorker_kindName___boxed(lean_object*);
static const lean_string_object l_BudgetWorker_decodeKind___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "unknown feature budget"};
static const lean_object* l_BudgetWorker_decodeKind___closed__0 = (const lean_object*)&l_BudgetWorker_decodeKind___closed__0_value;
static const lean_ctor_object l_BudgetWorker_decodeKind___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_BudgetWorker_decodeKind___closed__0_value)}};
static const lean_object* l_BudgetWorker_decodeKind___closed__1 = (const lean_object*)&l_BudgetWorker_decodeKind___closed__1_value;
static const lean_ctor_object l_BudgetWorker_decodeKind___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(3) << 1) | 1))}};
static const lean_object* l_BudgetWorker_decodeKind___closed__2 = (const lean_object*)&l_BudgetWorker_decodeKind___closed__2_value;
static const lean_ctor_object l_BudgetWorker_decodeKind___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(2) << 1) | 1))}};
static const lean_object* l_BudgetWorker_decodeKind___closed__3 = (const lean_object*)&l_BudgetWorker_decodeKind___closed__3_value;
static const lean_ctor_object l_BudgetWorker_decodeKind___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1))}};
static const lean_object* l_BudgetWorker_decodeKind___closed__4 = (const lean_object*)&l_BudgetWorker_decodeKind___closed__4_value;
static const lean_ctor_object l_BudgetWorker_decodeKind___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_BudgetWorker_decodeKind___closed__5 = (const lean_object*)&l_BudgetWorker_decodeKind___closed__5_value;
LEAN_EXPORT lean_object* l_BudgetWorker_decodeKind(lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_decodeKind___boxed(lean_object*);
static const lean_ctor_object l_BudgetWorker_kinds___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(3) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_BudgetWorker_kinds___closed__0 = (const lean_object*)&l_BudgetWorker_kinds___closed__0_value;
static const lean_ctor_object l_BudgetWorker_kinds___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(2) << 1) | 1)),((lean_object*)&l_BudgetWorker_kinds___closed__0_value)}};
static const lean_object* l_BudgetWorker_kinds___closed__1 = (const lean_object*)&l_BudgetWorker_kinds___closed__1_value;
static const lean_ctor_object l_BudgetWorker_kinds___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(1) << 1) | 1)),((lean_object*)&l_BudgetWorker_kinds___closed__1_value)}};
static const lean_object* l_BudgetWorker_kinds___closed__2 = (const lean_object*)&l_BudgetWorker_kinds___closed__2_value;
static const lean_ctor_object l_BudgetWorker_kinds___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1)),((lean_object*)&l_BudgetWorker_kinds___closed__2_value)}};
static const lean_object* l_BudgetWorker_kinds___closed__3 = (const lean_object*)&l_BudgetWorker_kinds___closed__3_value;
LEAN_EXPORT const lean_object* l_BudgetWorker_kinds = (const lean_object*)&l_BudgetWorker_kinds___closed__3_value;
static const lean_string_object l_BudgetWorker_decodeModel___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "schema_version"};
static const lean_object* l_BudgetWorker_decodeModel___closed__0 = (const lean_object*)&l_BudgetWorker_decodeModel___closed__0_value;
static const lean_string_object l_BudgetWorker_decodeModel___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "candidate_version"};
static const lean_object* l_BudgetWorker_decodeModel___closed__1 = (const lean_object*)&l_BudgetWorker_decodeModel___closed__1_value;
static const lean_string_object l_BudgetWorker_decodeModel___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "feature_version"};
static const lean_object* l_BudgetWorker_decodeModel___closed__2 = (const lean_object*)&l_BudgetWorker_decodeModel___closed__2_value;
static const lean_string_object l_BudgetWorker_decodeModel___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "budget-"};
static const lean_object* l_BudgetWorker_decodeModel___closed__3 = (const lean_object*)&l_BudgetWorker_decodeModel___closed__3_value;
static const lean_string_object l_BudgetWorker_decodeModel___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "-v1"};
static const lean_object* l_BudgetWorker_decodeModel___closed__4 = (const lean_object*)&l_BudgetWorker_decodeModel___closed__4_value;
static const lean_string_object l_BudgetWorker_decodeModel___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "tree"};
static const lean_object* l_BudgetWorker_decodeModel___closed__5 = (const lean_object*)&l_BudgetWorker_decodeModel___closed__5_value;
static const lean_string_object l_BudgetWorker_decodeModel___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "classifier"};
static const lean_object* l_BudgetWorker_decodeModel___closed__6 = (const lean_object*)&l_BudgetWorker_decodeModel___closed__6_value;
static const lean_string_object l_BudgetWorker_decodeModel___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "cost_ranking"};
static const lean_object* l_BudgetWorker_decodeModel___closed__7 = (const lean_object*)&l_BudgetWorker_decodeModel___closed__7_value;
static const lean_string_object l_BudgetWorker_decodeModel___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "verified-direct-seven-v1"};
static const lean_object* l_BudgetWorker_decodeModel___closed__8 = (const lean_object*)&l_BudgetWorker_decodeModel___closed__8_value;
LEAN_EXPORT lean_object* l_BudgetWorker_decodeModel(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_decodeModel___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_decodePolicy___lam__0(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_decodePolicy___lam__0___boxed(lean_object*, lean_object*);
static const lean_ctor_object l_BudgetWorker_decodePolicy___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 2}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_BudgetWorker_decodePolicy___closed__0 = (const lean_object*)&l_BudgetWorker_decodePolicy___closed__0_value;
static const lean_ctor_object l_BudgetWorker_decodePolicy___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 8, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_BudgetWorker_decodePolicy___closed__0_value),LEAN_SCALAR_PTR_LITERAL(0, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* l_BudgetWorker_decodePolicy___closed__1 = (const lean_object*)&l_BudgetWorker_decodePolicy___closed__1_value;
static const lean_string_object l_BudgetWorker_decodePolicy___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "feature_kind"};
static const lean_object* l_BudgetWorker_decodePolicy___closed__2 = (const lean_object*)&l_BudgetWorker_decodePolicy___closed__2_value;
static const lean_string_object l_BudgetWorker_decodePolicy___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "fixed"};
static const lean_object* l_BudgetWorker_decodePolicy___closed__3 = (const lean_object*)&l_BudgetWorker_decodePolicy___closed__3_value;
static const lean_string_object l_BudgetWorker_decodePolicy___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "rule"};
static const lean_object* l_BudgetWorker_decodePolicy___closed__4 = (const lean_object*)&l_BudgetWorker_decodePolicy___closed__4_value;
static const lean_string_object l_BudgetWorker_decodePolicy___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "learned"};
static const lean_object* l_BudgetWorker_decodePolicy___closed__5 = (const lean_object*)&l_BudgetWorker_decodePolicy___closed__5_value;
static const lean_string_object l_BudgetWorker_decodePolicy___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "model"};
static const lean_object* l_BudgetWorker_decodePolicy___closed__6 = (const lean_object*)&l_BudgetWorker_decodePolicy___closed__6_value;
static const lean_string_object l_BudgetWorker_decodePolicy___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "length_cut"};
static const lean_object* l_BudgetWorker_decodePolicy___closed__7 = (const lean_object*)&l_BudgetWorker_decodePolicy___closed__7_value;
static const lean_string_object l_BudgetWorker_decodePolicy___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "descent_cut"};
static const lean_object* l_BudgetWorker_decodePolicy___closed__8 = (const lean_object*)&l_BudgetWorker_decodePolicy___closed__8_value;
static const lean_string_object l_BudgetWorker_decodePolicy___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "id"};
static const lean_object* l_BudgetWorker_decodePolicy___closed__9 = (const lean_object*)&l_BudgetWorker_decodePolicy___closed__9_value;
LEAN_EXPORT lean_object* l_BudgetWorker_decodePolicy(lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_featureSelect(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_featureSelect___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_BudgetWorker_usesFeatures(lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_usesFeatures___boxed(lean_object*);
LEAN_EXPORT lean_object* l_List_foldl___at___00BudgetWorker_checksum_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_foldl___at___00BudgetWorker_checksum_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_checksum(lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_checksum___boxed(lean_object*);
static const lean_string_object l_BudgetWorker_timedKernel___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "kernel output mismatch"};
static const lean_object* l_BudgetWorker_timedKernel___closed__0 = (const lean_object*)&l_BudgetWorker_timedKernel___closed__0_value;
static const lean_ctor_object l_BudgetWorker_timedKernel___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_BudgetWorker_timedKernel___closed__0_value)}};
static const lean_object* l_BudgetWorker_timedKernel___closed__1 = (const lean_object*)&l_BudgetWorker_timedKernel___closed__1_value;
LEAN_EXPORT lean_object* l_BudgetWorker_timedKernel(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_timedKernel___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_BudgetWorker_timedPolicy___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "policy output mismatch"};
static const lean_object* l_BudgetWorker_timedPolicy___closed__0 = (const lean_object*)&l_BudgetWorker_timedPolicy___closed__0_value;
static const lean_ctor_object l_BudgetWorker_timedPolicy___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_BudgetWorker_timedPolicy___closed__0_value)}};
static const lean_object* l_BudgetWorker_timedPolicy___closed__1 = (const lean_object*)&l_BudgetWorker_timedPolicy___closed__1_value;
LEAN_EXPORT lean_object* l_BudgetWorker_timedPolicy(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_timedPolicy___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_timedFeatures(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_timedFeatures___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_timedDecision(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_timedDecision___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_emit(lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_emit___boxed(lean_object*, lean_object*);
static const lean_string_object l_BudgetWorker_sampleEvent___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "event"};
static const lean_object* l_BudgetWorker_sampleEvent___closed__0 = (const lean_object*)&l_BudgetWorker_sampleEvent___closed__0_value;
static const lean_string_object l_BudgetWorker_sampleEvent___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "sample"};
static const lean_object* l_BudgetWorker_sampleEvent___closed__1 = (const lean_object*)&l_BudgetWorker_sampleEvent___closed__1_value;
static const lean_ctor_object l_BudgetWorker_sampleEvent___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&l_BudgetWorker_sampleEvent___closed__1_value)}};
static const lean_object* l_BudgetWorker_sampleEvent___closed__2 = (const lean_object*)&l_BudgetWorker_sampleEvent___closed__2_value;
static const lean_ctor_object l_BudgetWorker_sampleEvent___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_BudgetWorker_sampleEvent___closed__0_value),((lean_object*)&l_BudgetWorker_sampleEvent___closed__2_value)}};
static const lean_object* l_BudgetWorker_sampleEvent___closed__3 = (const lean_object*)&l_BudgetWorker_sampleEvent___closed__3_value;
static const lean_string_object l_BudgetWorker_sampleEvent___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "category"};
static const lean_object* l_BudgetWorker_sampleEvent___closed__4 = (const lean_object*)&l_BudgetWorker_sampleEvent___closed__4_value;
static const lean_string_object l_BudgetWorker_sampleEvent___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "name"};
static const lean_object* l_BudgetWorker_sampleEvent___closed__5 = (const lean_object*)&l_BudgetWorker_sampleEvent___closed__5_value;
static const lean_string_object l_BudgetWorker_sampleEvent___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "round"};
static const lean_object* l_BudgetWorker_sampleEvent___closed__6 = (const lean_object*)&l_BudgetWorker_sampleEvent___closed__6_value;
static const lean_string_object l_BudgetWorker_sampleEvent___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "ns"};
static const lean_object* l_BudgetWorker_sampleEvent___closed__7 = (const lean_object*)&l_BudgetWorker_sampleEvent___closed__7_value;
static const lean_string_object l_BudgetWorker_sampleEvent___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "chosen_id"};
static const lean_object* l_BudgetWorker_sampleEvent___closed__8 = (const lean_object*)&l_BudgetWorker_sampleEvent___closed__8_value;
LEAN_EXPORT lean_object* l_BudgetWorker_sampleEvent(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_sampleEvent___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00BudgetWorker_kernelProfile_spec__2_spec__5(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00BudgetWorker_kernelProfile_spec__2_spec__5___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_LearnedSelection_kernelBound___at___00BudgetWorker_kernelProfile_spec__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_LearnedSelection_kernelBound___at___00BudgetWorker_kernelProfile_spec__2___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__0(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__1(lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___lam__0(lean_object*, lean_object*);
static lean_once_cell_t l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0;
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__0(lean_object*, lean_object*);
static lean_once_cell_t l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0;
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___lam__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__3___lam__0(lean_object*);
static const lean_closure_object l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__3___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__3___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__3___closed__0 = (const lean_object*)&l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__3___closed__0_value;
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__3(lean_object*);
static lean_once_cell_t l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0;
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___lam__0(lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__1___boxed(lean_object*, lean_object*, lean_object*);
static const lean_array_object l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___closed__0 = (const lean_object*)&l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___closed__0_value;
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__1(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18___lam__1(lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12___lam__1(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__2(lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__2___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__1(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2___lam__0(lean_object*);
static const lean_closure_object l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2___closed__0 = (const lean_object*)&l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2___closed__0_value;
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_readyCheck___at___00BudgetWorker_kernelProfile_spec__3_spec__7___redArg(lean_object*);
LEAN_EXPORT uint8_t l_LeanSort_CostedPlan_Schema_readyCheck___at___00BudgetWorker_kernelProfile_spec__3(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_CostedPlan_Schema_readyCheck___at___00BudgetWorker_kernelProfile_spec__3___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__2(uint8_t, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___lam__1(lean_object*, uint8_t, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___lam__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___lam__2(uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__0(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___lam__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___lam__1(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__9___lam__0(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__9___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__9(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__9___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___lam__0(uint8_t, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__0(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__1(uint8_t, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___lam__1(uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___lam__0(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___lam__1(uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__2(uint8_t, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__1(uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8___lam__0(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object l_BudgetWorker_kernelProfile___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 33, .m_capacity = 33, .m_length = 32, .m_data = "kernel phase/count/bound failure"};
static const lean_object* l_BudgetWorker_kernelProfile___closed__0 = (const lean_object*)&l_BudgetWorker_kernelProfile___closed__0_value;
static const lean_ctor_object l_BudgetWorker_kernelProfile___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_BudgetWorker_kernelProfile___closed__0_value)}};
static const lean_object* l_BudgetWorker_kernelProfile___closed__1 = (const lean_object*)&l_BudgetWorker_kernelProfile___closed__1_value;
static const lean_string_object l_BudgetWorker_kernelProfile___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "comparisons"};
static const lean_object* l_BudgetWorker_kernelProfile___closed__2 = (const lean_object*)&l_BudgetWorker_kernelProfile___closed__2_value;
static const lean_string_object l_BudgetWorker_kernelProfile___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "check_comparisons"};
static const lean_object* l_BudgetWorker_kernelProfile___closed__3 = (const lean_object*)&l_BudgetWorker_kernelProfile___closed__3_value;
static const lean_string_object l_BudgetWorker_kernelProfile___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "sort_comparisons"};
static const lean_object* l_BudgetWorker_kernelProfile___closed__4 = (const lean_object*)&l_BudgetWorker_kernelProfile___closed__4_value;
static const lean_string_object l_BudgetWorker_kernelProfile___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "bound"};
static const lean_object* l_BudgetWorker_kernelProfile___closed__5 = (const lean_object*)&l_BudgetWorker_kernelProfile___closed__5_value;
static const lean_string_object l_BudgetWorker_kernelProfile___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "conditional_applicable"};
static const lean_object* l_BudgetWorker_kernelProfile___closed__6 = (const lean_object*)&l_BudgetWorker_kernelProfile___closed__6_value;
static const lean_string_object l_BudgetWorker_kernelProfile___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "conditional_bound"};
static const lean_object* l_BudgetWorker_kernelProfile___closed__7 = (const lean_object*)&l_BudgetWorker_kernelProfile___closed__7_value;
static const lean_string_object l_BudgetWorker_kernelProfile___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 40, .m_capacity = 40, .m_length = 39, .m_data = "conditional theorem domain/cost failure"};
static const lean_object* l_BudgetWorker_kernelProfile___closed__8 = (const lean_object*)&l_BudgetWorker_kernelProfile___closed__8_value;
static const lean_ctor_object l_BudgetWorker_kernelProfile___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_BudgetWorker_kernelProfile___closed__8_value)}};
static const lean_object* l_BudgetWorker_kernelProfile___closed__9 = (const lean_object*)&l_BudgetWorker_kernelProfile___closed__9_value;
LEAN_EXPORT lean_object* l_BudgetWorker_kernelProfile(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_kernelProfile___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_readyCheck___at___00BudgetWorker_kernelProfile_spec__3_spec__7(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_scan___at___00LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00BudgetWorker_kernelProfile_spec__2_spec__5_spec__12(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Option_toJson___at___00BudgetWorker_bench_spec__2(lean_object*);
static const lean_string_object l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "kernel"};
static const lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__0_value;
static lean_once_cell_t l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__1;
static lean_once_cell_t l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__2;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__23(lean_object*, lean_object*);
static const lean_string_object l_List_mapTR_loop___at___00BudgetWorker_bench_spec__9___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "policy"};
static const lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__9___closed__0 = (const lean_object*)&l_List_mapTR_loop___at___00BudgetWorker_bench_spec__9___closed__0_value;
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__9(lean_object*, lean_object*);
static const lean_string_object l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "features"};
static const lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11___redArg___closed__0_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__10___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__10___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13___redArg___closed__0_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__8(lean_object*, lean_object*);
static const lean_string_object l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 39, .m_capacity = 39, .m_length = 38, .m_data = "feature instrumentation/bound mismatch"};
static const lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___redArg___closed__0_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___redArg___closed__0_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___redArg___closed__1 = (const lean_object*)&l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___redArg___closed__1_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__7___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__7___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "decision"};
static const lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12___redArg___closed__0_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__17___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__17___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_find_x3f___at___00BudgetWorker_bench_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_find_x3f___at___00BudgetWorker_bench_spec__0___boxed(lean_object*, lean_object*);
static const lean_string_object l_List_mapM_loop___at___00BudgetWorker_bench_spec__5___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "unconfigured policy"};
static const lean_object* l_List_mapM_loop___at___00BudgetWorker_bench_spec__5___closed__0 = (const lean_object*)&l_List_mapM_loop___at___00BudgetWorker_bench_spec__5___closed__0_value;
static const lean_ctor_object l_List_mapM_loop___at___00BudgetWorker_bench_spec__5___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_List_mapM_loop___at___00BudgetWorker_bench_spec__5___closed__0_value)}};
static const lean_object* l_List_mapM_loop___at___00BudgetWorker_bench_spec__5___closed__1 = (const lean_object*)&l_List_mapM_loop___at___00BudgetWorker_bench_spec__5___closed__1_value;
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00BudgetWorker_bench_spec__5(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00BudgetWorker_bench_spec__5___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__14(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__14___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object l_List_mapM_loop___at___00BudgetWorker_bench_spec__18___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 42, .m_capacity = 42, .m_length = 41, .m_data = "independent key-comparison count mismatch"};
static const lean_object* l_List_mapM_loop___at___00BudgetWorker_bench_spec__18___closed__0 = (const lean_object*)&l_List_mapM_loop___at___00BudgetWorker_bench_spec__18___closed__0_value;
static const lean_ctor_object l_List_mapM_loop___at___00BudgetWorker_bench_spec__18___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_List_mapM_loop___at___00BudgetWorker_bench_spec__18___closed__0_value)}};
static const lean_object* l_List_mapM_loop___at___00BudgetWorker_bench_spec__18___closed__1 = (const lean_object*)&l_List_mapM_loop___at___00BudgetWorker_bench_spec__18___closed__1_value;
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00BudgetWorker_bench_spec__18(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00BudgetWorker_bench_spec__18___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00Lean_Option_toJson___at___00BudgetWorker_bench_spec__3_spec__4(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Option_toJson___at___00BudgetWorker_bench_spec__3(lean_object*);
static const lean_string_object l_List_mapTR_loop___at___00BudgetWorker_bench_spec__20___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "raw_id"};
static const lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__20___closed__0 = (const lean_object*)&l_List_mapTR_loop___at___00BudgetWorker_bench_spec__20___closed__0_value;
static const lean_string_object l_List_mapTR_loop___at___00BudgetWorker_bench_spec__20___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "uses_features"};
static const lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__20___closed__1 = (const lean_object*)&l_List_mapTR_loop___at___00BudgetWorker_bench_spec__20___closed__1_value;
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__20(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__20___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_List_beq___at___00BudgetWorker_bench_spec__15(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_beq___at___00BudgetWorker_bench_spec__15___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__1_spec__1(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00BudgetWorker_bench_spec__22(lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__19(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__19___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00BudgetWorker_bench_spec__21_spec__24_spec__26(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00BudgetWorker_bench_spec__21_spec__24_spec__26___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Array_toJson___at___00Lean_List_toJson___at___00BudgetWorker_bench_spec__21_spec__24(lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00BudgetWorker_bench_spec__21(lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7_spec__27(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7_spec__27___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object l_Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 27, .m_capacity = 27, .m_length = 26, .m_data = "expected JSON array, got '"};
static const lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7___closed__0 = (const lean_object*)&l_Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7___closed__0_value;
static const lean_string_object l_Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "'"};
static const lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7___closed__1 = (const lean_object*)&l_Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7___closed__1_value;
LEAN_EXPORT lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7(lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4___boxed(lean_object*, lean_object*);
static const lean_string_object l_BudgetWorker_bench___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "input"};
static const lean_object* l_BudgetWorker_bench___closed__0 = (const lean_object*)&l_BudgetWorker_bench___closed__0_value;
static const lean_string_object l_BudgetWorker_bench___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "expected"};
static const lean_object* l_BudgetWorker_bench___closed__1 = (const lean_object*)&l_BudgetWorker_bench___closed__1_value;
static const lean_string_object l_BudgetWorker_bench___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "expected_features"};
static const lean_object* l_BudgetWorker_bench___closed__2 = (const lean_object*)&l_BudgetWorker_bench___closed__2_value;
static const lean_string_object l_BudgetWorker_bench___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "expected_costs"};
static const lean_object* l_BudgetWorker_bench___closed__3 = (const lean_object*)&l_BudgetWorker_bench___closed__3_value;
static const lean_string_object l_BudgetWorker_bench___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "policies"};
static const lean_object* l_BudgetWorker_bench___closed__4 = (const lean_object*)&l_BudgetWorker_bench___closed__4_value;
static const lean_string_object l_BudgetWorker_bench___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "rounds"};
static const lean_object* l_BudgetWorker_bench___closed__5 = (const lean_object*)&l_BudgetWorker_bench___closed__5_value;
static const lean_string_object l_BudgetWorker_bench___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "order_seed"};
static const lean_object* l_BudgetWorker_bench___closed__6 = (const lean_object*)&l_BudgetWorker_bench___closed__6_value;
static const lean_string_object l_BudgetWorker_bench___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 34, .m_capacity = 34, .m_length = 33, .m_data = "invalid measurement configuration"};
static const lean_object* l_BudgetWorker_bench___closed__7 = (const lean_object*)&l_BudgetWorker_bench___closed__7_value;
static const lean_ctor_object l_BudgetWorker_bench___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_BudgetWorker_bench___closed__7_value)}};
static const lean_object* l_BudgetWorker_bench___closed__8 = (const lean_object*)&l_BudgetWorker_bench___closed__8_value;
static lean_once_cell_t l_BudgetWorker_bench___closed__9_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_BudgetWorker_bench___closed__9;
static lean_once_cell_t l_BudgetWorker_bench___closed__10_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_BudgetWorker_bench___closed__10;
static const lean_string_object l_BudgetWorker_bench___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 29, .m_capacity = 29, .m_length = 28, .m_data = "Python/Lean feature mismatch"};
static const lean_object* l_BudgetWorker_bench___closed__11 = (const lean_object*)&l_BudgetWorker_bench___closed__11_value;
static const lean_ctor_object l_BudgetWorker_bench___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_BudgetWorker_bench___closed__11_value)}};
static const lean_object* l_BudgetWorker_bench___closed__12 = (const lean_object*)&l_BudgetWorker_bench___closed__12_value;
static const lean_string_object l_BudgetWorker_bench___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "feature_comparisons"};
static const lean_object* l_BudgetWorker_bench___closed__13 = (const lean_object*)&l_BudgetWorker_bench___closed__13_value;
static const lean_string_object l_BudgetWorker_bench___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "kernel_profiles"};
static const lean_object* l_BudgetWorker_bench___closed__14 = (const lean_object*)&l_BudgetWorker_bench___closed__14_value;
static const lean_string_object l_BudgetWorker_bench___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "predictions"};
static const lean_object* l_BudgetWorker_bench___closed__15 = (const lean_object*)&l_BudgetWorker_bench___closed__15_value;
static const lean_string_object l_BudgetWorker_bench___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "run_lengths"};
static const lean_object* l_BudgetWorker_bench___closed__16 = (const lean_object*)&l_BudgetWorker_bench___closed__16_value;
static const lean_string_object l_BudgetWorker_bench___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "all_outputs_correct"};
static const lean_object* l_BudgetWorker_bench___closed__17 = (const lean_object*)&l_BudgetWorker_bench___closed__17_value;
LEAN_EXPORT lean_object* l_BudgetWorker_bench(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_bench___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__7(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__7___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__10(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__10___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__17(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__17___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_List_mapTR_loop___at___00BudgetWorker_handle_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "output"};
static const lean_object* l_List_mapTR_loop___at___00BudgetWorker_handle_spec__0___closed__0 = (const lean_object*)&l_List_mapTR_loop___at___00BudgetWorker_handle_spec__0___closed__0_value;
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_handle_spec__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_handle_spec__1_spec__1(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_handle_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_handle_spec__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00BudgetWorker_handle_spec__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00BudgetWorker_handle_spec__2___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object l_BudgetWorker_handle___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "cmd"};
static const lean_object* l_BudgetWorker_handle___closed__0 = (const lean_object*)&l_BudgetWorker_handle___closed__0_value;
static const lean_string_object l_BudgetWorker_handle___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "configure"};
static const lean_object* l_BudgetWorker_handle___closed__1 = (const lean_object*)&l_BudgetWorker_handle___closed__1_value;
static const lean_string_object l_BudgetWorker_handle___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "bench"};
static const lean_object* l_BudgetWorker_handle___closed__2 = (const lean_object*)&l_BudgetWorker_handle___closed__2_value;
static const lean_string_object l_BudgetWorker_handle___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "infer"};
static const lean_object* l_BudgetWorker_handle___closed__3 = (const lean_object*)&l_BudgetWorker_handle___closed__3_value;
static const lean_string_object l_BudgetWorker_handle___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "unknown command"};
static const lean_object* l_BudgetWorker_handle___closed__4 = (const lean_object*)&l_BudgetWorker_handle___closed__4_value;
static const lean_ctor_object l_BudgetWorker_handle___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_BudgetWorker_handle___closed__4_value)}};
static const lean_object* l_BudgetWorker_handle___closed__5 = (const lean_object*)&l_BudgetWorker_handle___closed__5_value;
static const lean_string_object l_BudgetWorker_handle___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "outputs"};
static const lean_object* l_BudgetWorker_handle___closed__6 = (const lean_object*)&l_BudgetWorker_handle___closed__6_value;
static const lean_string_object l_BudgetWorker_handle___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "configured"};
static const lean_object* l_BudgetWorker_handle___closed__7 = (const lean_object*)&l_BudgetWorker_handle___closed__7_value;
LEAN_EXPORT lean_object* l_BudgetWorker_handle(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_handle___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object l_BudgetWorker_loop___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "done"};
static const lean_object* l_BudgetWorker_loop___closed__0 = (const lean_object*)&l_BudgetWorker_loop___closed__0_value;
static const lean_ctor_object l_BudgetWorker_loop___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&l_BudgetWorker_loop___closed__0_value)}};
static const lean_object* l_BudgetWorker_loop___closed__1 = (const lean_object*)&l_BudgetWorker_loop___closed__1_value;
static const lean_ctor_object l_BudgetWorker_loop___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_BudgetWorker_sampleEvent___closed__0_value),((lean_object*)&l_BudgetWorker_loop___closed__1_value)}};
static const lean_object* l_BudgetWorker_loop___closed__2 = (const lean_object*)&l_BudgetWorker_loop___closed__2_value;
static const lean_string_object l_BudgetWorker_loop___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "result"};
static const lean_object* l_BudgetWorker_loop___closed__3 = (const lean_object*)&l_BudgetWorker_loop___closed__3_value;
static const lean_string_object l_BudgetWorker_loop___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "error"};
static const lean_object* l_BudgetWorker_loop___closed__4 = (const lean_object*)&l_BudgetWorker_loop___closed__4_value;
LEAN_EXPORT lean_object* l_BudgetWorker_loop(lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_loop___boxed(lean_object*, lean_object*);
static const lean_string_object l_main___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "ready"};
static const lean_object* l_main___closed__0 = (const lean_object*)&l_main___closed__0_value;
static const lean_ctor_object l_main___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*0 + 8, .m_other = 0, .m_tag = 1}, .m_objs = {LEAN_SCALAR_PTR_LITERAL(1, 0, 0, 0, 0, 0, 0, 0)}};
static const lean_object* l_main___closed__1 = (const lean_object*)&l_main___closed__1_value;
static const lean_ctor_object l_main___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_main___closed__0_value),((lean_object*)&l_main___closed__1_value)}};
static const lean_object* l_main___closed__2 = (const lean_object*)&l_main___closed__2_value;
static const lean_ctor_object l_main___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&l_main___closed__2_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_main___closed__3 = (const lean_object*)&l_main___closed__3_value;
static lean_once_cell_t l_main___closed__4_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_main___closed__4;
LEAN_EXPORT lean_object* _lean_main();
LEAN_EXPORT lean_object* l_main___boxed(lean_object*);
LEAN_EXPORT lean_object* l_BudgetWorker_orError___redArg(lean_object* v_x_1_){
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
LEAN_EXPORT lean_object* l_BudgetWorker_orError___redArg___boxed(lean_object* v_x_20_, lean_object* v_a_21_){
_start:
{
lean_object* v_res_22_; 
v_res_22_ = l_BudgetWorker_orError___redArg(v_x_20_);
return v_res_22_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_orError(lean_object* v_00_u03b1_23_, lean_object* v_x_24_){
_start:
{
lean_object* v___x_26_; 
v___x_26_ = l_BudgetWorker_orError___redArg(v_x_24_);
return v___x_26_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_orError___boxed(lean_object* v_00_u03b1_27_, lean_object* v_x_28_, lean_object* v_a_29_){
_start:
{
lean_object* v_res_30_; 
v_res_30_ = l_BudgetWorker_orError(v_00_u03b1_27_, v_x_28_);
return v_res_30_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_decodeTree_spec__0_spec__0(lean_object* v_j_31_){
_start:
{
lean_object* v___x_32_; 
v___x_32_ = l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonFuncTable_fromJson_spec__0_spec__0(v_j_31_);
if (lean_obj_tag(v___x_32_) == 0)
{
lean_object* v_a_33_; lean_object* v___x_35_; uint8_t v_isShared_36_; uint8_t v_isSharedCheck_40_; 
v_a_33_ = lean_ctor_get(v___x_32_, 0);
v_isSharedCheck_40_ = !lean_is_exclusive(v___x_32_);
if (v_isSharedCheck_40_ == 0)
{
v___x_35_ = v___x_32_;
v_isShared_36_ = v_isSharedCheck_40_;
goto v_resetjp_34_;
}
else
{
lean_inc(v_a_33_);
lean_dec(v___x_32_);
v___x_35_ = lean_box(0);
v_isShared_36_ = v_isSharedCheck_40_;
goto v_resetjp_34_;
}
v_resetjp_34_:
{
lean_object* v___x_38_; 
if (v_isShared_36_ == 0)
{
v___x_38_ = v___x_35_;
goto v_reusejp_37_;
}
else
{
lean_object* v_reuseFailAlloc_39_; 
v_reuseFailAlloc_39_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_39_, 0, v_a_33_);
v___x_38_ = v_reuseFailAlloc_39_;
goto v_reusejp_37_;
}
v_reusejp_37_:
{
return v___x_38_;
}
}
}
else
{
lean_object* v_a_41_; lean_object* v___x_43_; uint8_t v_isShared_44_; uint8_t v_isSharedCheck_49_; 
v_a_41_ = lean_ctor_get(v___x_32_, 0);
v_isSharedCheck_49_ = !lean_is_exclusive(v___x_32_);
if (v_isSharedCheck_49_ == 0)
{
v___x_43_ = v___x_32_;
v_isShared_44_ = v_isSharedCheck_49_;
goto v_resetjp_42_;
}
else
{
lean_inc(v_a_41_);
lean_dec(v___x_32_);
v___x_43_ = lean_box(0);
v_isShared_44_ = v_isSharedCheck_49_;
goto v_resetjp_42_;
}
v_resetjp_42_:
{
lean_object* v___x_45_; lean_object* v___x_47_; 
v___x_45_ = lean_array_to_list(v_a_41_);
if (v_isShared_44_ == 0)
{
lean_ctor_set(v___x_43_, 0, v___x_45_);
v___x_47_ = v___x_43_;
goto v_reusejp_46_;
}
else
{
lean_object* v_reuseFailAlloc_48_; 
v_reuseFailAlloc_48_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_48_, 0, v___x_45_);
v___x_47_ = v_reuseFailAlloc_48_;
goto v_reusejp_46_;
}
v_reusejp_46_:
{
return v___x_47_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_decodeTree_spec__0(lean_object* v_j_50_, lean_object* v_k_51_){
_start:
{
lean_object* v___x_52_; lean_object* v___x_53_; 
v___x_52_ = l_Lean_Json_getObjValD(v_j_50_, v_k_51_);
v___x_53_ = l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_decodeTree_spec__0_spec__0(v___x_52_);
return v___x_53_;
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_decodeTree_spec__0___boxed(lean_object* v_j_54_, lean_object* v_k_55_){
_start:
{
lean_object* v_res_56_; 
v_res_56_ = l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_decodeTree_spec__0(v_j_54_, v_k_55_);
lean_dec_ref(v_k_55_);
return v_res_56_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_decodeTree(lean_object* v_x_74_, lean_object* v_x_75_){
_start:
{
lean_object* v_zero_76_; uint8_t v_isZero_77_; 
v_zero_76_ = lean_unsigned_to_nat(0u);
v_isZero_77_ = lean_nat_dec_eq(v_x_74_, v_zero_76_);
if (v_isZero_77_ == 1)
{
lean_object* v___x_78_; 
lean_dec(v_x_75_);
v___x_78_ = ((lean_object*)(l_BudgetWorker_decodeTree___closed__1));
return v___x_78_;
}
else
{
lean_object* v___x_79_; lean_object* v___x_80_; 
v___x_79_ = ((lean_object*)(l_BudgetWorker_decodeTree___closed__2));
lean_inc(v_x_75_);
v___x_80_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_x_75_, v___x_79_);
if (lean_obj_tag(v___x_80_) == 0)
{
lean_object* v_a_81_; lean_object* v___x_83_; uint8_t v_isShared_84_; uint8_t v_isSharedCheck_88_; 
lean_dec(v_x_75_);
v_a_81_ = lean_ctor_get(v___x_80_, 0);
v_isSharedCheck_88_ = !lean_is_exclusive(v___x_80_);
if (v_isSharedCheck_88_ == 0)
{
v___x_83_ = v___x_80_;
v_isShared_84_ = v_isSharedCheck_88_;
goto v_resetjp_82_;
}
else
{
lean_inc(v_a_81_);
lean_dec(v___x_80_);
v___x_83_ = lean_box(0);
v_isShared_84_ = v_isSharedCheck_88_;
goto v_resetjp_82_;
}
v_resetjp_82_:
{
lean_object* v___x_86_; 
if (v_isShared_84_ == 0)
{
v___x_86_ = v___x_83_;
goto v_reusejp_85_;
}
else
{
lean_object* v_reuseFailAlloc_87_; 
v_reuseFailAlloc_87_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_87_, 0, v_a_81_);
v___x_86_ = v_reuseFailAlloc_87_;
goto v_reusejp_85_;
}
v_reusejp_85_:
{
return v___x_86_;
}
}
}
else
{
lean_object* v_a_89_; lean_object* v___x_90_; uint8_t v___x_91_; 
v_a_89_ = lean_ctor_get(v___x_80_, 0);
lean_inc(v_a_89_);
lean_dec_ref_known(v___x_80_, 1);
v___x_90_ = ((lean_object*)(l_BudgetWorker_decodeTree___closed__3));
v___x_91_ = lean_string_dec_eq(v_a_89_, v___x_90_);
if (v___x_91_ == 0)
{
lean_object* v___x_92_; uint8_t v___x_93_; 
v___x_92_ = ((lean_object*)(l_BudgetWorker_decodeTree___closed__4));
v___x_93_ = lean_string_dec_eq(v_a_89_, v___x_92_);
lean_dec(v_a_89_);
if (v___x_93_ == 0)
{
lean_object* v___x_94_; 
lean_dec(v_x_75_);
v___x_94_ = ((lean_object*)(l_BudgetWorker_decodeTree___closed__6));
return v___x_94_;
}
else
{
lean_object* v___x_95_; lean_object* v___x_96_; 
v___x_95_ = ((lean_object*)(l_BudgetWorker_decodeTree___closed__7));
lean_inc(v_x_75_);
v___x_96_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_x_75_, v___x_95_);
if (lean_obj_tag(v___x_96_) == 0)
{
lean_object* v_a_97_; lean_object* v___x_99_; uint8_t v_isShared_100_; uint8_t v_isSharedCheck_104_; 
lean_dec(v_x_75_);
v_a_97_ = lean_ctor_get(v___x_96_, 0);
v_isSharedCheck_104_ = !lean_is_exclusive(v___x_96_);
if (v_isSharedCheck_104_ == 0)
{
v___x_99_ = v___x_96_;
v_isShared_100_ = v_isSharedCheck_104_;
goto v_resetjp_98_;
}
else
{
lean_inc(v_a_97_);
lean_dec(v___x_96_);
v___x_99_ = lean_box(0);
v_isShared_100_ = v_isSharedCheck_104_;
goto v_resetjp_98_;
}
v_resetjp_98_:
{
lean_object* v___x_102_; 
if (v_isShared_100_ == 0)
{
v___x_102_ = v___x_99_;
goto v_reusejp_101_;
}
else
{
lean_object* v_reuseFailAlloc_103_; 
v_reuseFailAlloc_103_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_103_, 0, v_a_97_);
v___x_102_ = v_reuseFailAlloc_103_;
goto v_reusejp_101_;
}
v_reusejp_101_:
{
return v___x_102_;
}
}
}
else
{
lean_object* v_a_105_; lean_object* v___x_106_; lean_object* v___x_107_; 
v_a_105_ = lean_ctor_get(v___x_96_, 0);
lean_inc(v_a_105_);
lean_dec_ref_known(v___x_96_, 1);
v___x_106_ = ((lean_object*)(l_BudgetWorker_decodeTree___closed__8));
lean_inc(v_x_75_);
v___x_107_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_x_75_, v___x_106_);
if (lean_obj_tag(v___x_107_) == 0)
{
lean_object* v_a_108_; lean_object* v___x_110_; uint8_t v_isShared_111_; uint8_t v_isSharedCheck_115_; 
lean_dec(v_a_105_);
lean_dec(v_x_75_);
v_a_108_ = lean_ctor_get(v___x_107_, 0);
v_isSharedCheck_115_ = !lean_is_exclusive(v___x_107_);
if (v_isSharedCheck_115_ == 0)
{
v___x_110_ = v___x_107_;
v_isShared_111_ = v_isSharedCheck_115_;
goto v_resetjp_109_;
}
else
{
lean_inc(v_a_108_);
lean_dec(v___x_107_);
v___x_110_ = lean_box(0);
v_isShared_111_ = v_isSharedCheck_115_;
goto v_resetjp_109_;
}
v_resetjp_109_:
{
lean_object* v___x_113_; 
if (v_isShared_111_ == 0)
{
v___x_113_ = v___x_110_;
goto v_reusejp_112_;
}
else
{
lean_object* v_reuseFailAlloc_114_; 
v_reuseFailAlloc_114_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_114_, 0, v_a_108_);
v___x_113_ = v_reuseFailAlloc_114_;
goto v_reusejp_112_;
}
v_reusejp_112_:
{
return v___x_113_;
}
}
}
else
{
lean_object* v_a_116_; lean_object* v___x_117_; lean_object* v___x_118_; 
v_a_116_ = lean_ctor_get(v___x_107_, 0);
lean_inc(v_a_116_);
lean_dec_ref_known(v___x_107_, 1);
v___x_117_ = ((lean_object*)(l_BudgetWorker_decodeTree___closed__9));
lean_inc(v_x_75_);
v___x_118_ = l_Lean_Json_getObjVal_x3f(v_x_75_, v___x_117_);
if (lean_obj_tag(v___x_118_) == 0)
{
lean_object* v_a_119_; lean_object* v___x_121_; uint8_t v_isShared_122_; uint8_t v_isSharedCheck_126_; 
lean_dec(v_a_116_);
lean_dec(v_a_105_);
lean_dec(v_x_75_);
v_a_119_ = lean_ctor_get(v___x_118_, 0);
v_isSharedCheck_126_ = !lean_is_exclusive(v___x_118_);
if (v_isSharedCheck_126_ == 0)
{
v___x_121_ = v___x_118_;
v_isShared_122_ = v_isSharedCheck_126_;
goto v_resetjp_120_;
}
else
{
lean_inc(v_a_119_);
lean_dec(v___x_118_);
v___x_121_ = lean_box(0);
v_isShared_122_ = v_isSharedCheck_126_;
goto v_resetjp_120_;
}
v_resetjp_120_:
{
lean_object* v___x_124_; 
if (v_isShared_122_ == 0)
{
v___x_124_ = v___x_121_;
goto v_reusejp_123_;
}
else
{
lean_object* v_reuseFailAlloc_125_; 
v_reuseFailAlloc_125_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_125_, 0, v_a_119_);
v___x_124_ = v_reuseFailAlloc_125_;
goto v_reusejp_123_;
}
v_reusejp_123_:
{
return v___x_124_;
}
}
}
else
{
lean_object* v_a_127_; lean_object* v_one_128_; lean_object* v_n_129_; lean_object* v___x_130_; 
v_a_127_ = lean_ctor_get(v___x_118_, 0);
lean_inc(v_a_127_);
lean_dec_ref_known(v___x_118_, 1);
v_one_128_ = lean_unsigned_to_nat(1u);
v_n_129_ = lean_nat_sub(v_x_74_, v_one_128_);
v___x_130_ = l_BudgetWorker_decodeTree(v_n_129_, v_a_127_);
if (lean_obj_tag(v___x_130_) == 0)
{
lean_dec(v_n_129_);
lean_dec(v_a_116_);
lean_dec(v_a_105_);
lean_dec(v_x_75_);
return v___x_130_;
}
else
{
lean_object* v_a_131_; lean_object* v___x_132_; lean_object* v___x_133_; 
v_a_131_ = lean_ctor_get(v___x_130_, 0);
lean_inc(v_a_131_);
lean_dec_ref_known(v___x_130_, 1);
v___x_132_ = ((lean_object*)(l_BudgetWorker_decodeTree___closed__10));
v___x_133_ = l_Lean_Json_getObjVal_x3f(v_x_75_, v___x_132_);
if (lean_obj_tag(v___x_133_) == 0)
{
lean_object* v_a_134_; lean_object* v___x_136_; uint8_t v_isShared_137_; uint8_t v_isSharedCheck_141_; 
lean_dec(v_a_131_);
lean_dec(v_n_129_);
lean_dec(v_a_116_);
lean_dec(v_a_105_);
v_a_134_ = lean_ctor_get(v___x_133_, 0);
v_isSharedCheck_141_ = !lean_is_exclusive(v___x_133_);
if (v_isSharedCheck_141_ == 0)
{
v___x_136_ = v___x_133_;
v_isShared_137_ = v_isSharedCheck_141_;
goto v_resetjp_135_;
}
else
{
lean_inc(v_a_134_);
lean_dec(v___x_133_);
v___x_136_ = lean_box(0);
v_isShared_137_ = v_isSharedCheck_141_;
goto v_resetjp_135_;
}
v_resetjp_135_:
{
lean_object* v___x_139_; 
if (v_isShared_137_ == 0)
{
v___x_139_ = v___x_136_;
goto v_reusejp_138_;
}
else
{
lean_object* v_reuseFailAlloc_140_; 
v_reuseFailAlloc_140_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_140_, 0, v_a_134_);
v___x_139_ = v_reuseFailAlloc_140_;
goto v_reusejp_138_;
}
v_reusejp_138_:
{
return v___x_139_;
}
}
}
else
{
lean_object* v_a_142_; lean_object* v___x_143_; 
v_a_142_ = lean_ctor_get(v___x_133_, 0);
lean_inc(v_a_142_);
lean_dec_ref_known(v___x_133_, 1);
v___x_143_ = l_BudgetWorker_decodeTree(v_n_129_, v_a_142_);
lean_dec(v_n_129_);
if (lean_obj_tag(v___x_143_) == 0)
{
lean_dec(v_a_131_);
lean_dec(v_a_116_);
lean_dec(v_a_105_);
return v___x_143_;
}
else
{
lean_object* v_a_144_; lean_object* v___x_146_; uint8_t v_isShared_147_; uint8_t v_isSharedCheck_152_; 
v_a_144_ = lean_ctor_get(v___x_143_, 0);
v_isSharedCheck_152_ = !lean_is_exclusive(v___x_143_);
if (v_isSharedCheck_152_ == 0)
{
v___x_146_ = v___x_143_;
v_isShared_147_ = v_isSharedCheck_152_;
goto v_resetjp_145_;
}
else
{
lean_inc(v_a_144_);
lean_dec(v___x_143_);
v___x_146_ = lean_box(0);
v_isShared_147_ = v_isSharedCheck_152_;
goto v_resetjp_145_;
}
v_resetjp_145_:
{
lean_object* v___x_148_; lean_object* v___x_150_; 
v___x_148_ = lean_alloc_ctor(1, 4, 0);
lean_ctor_set(v___x_148_, 0, v_a_105_);
lean_ctor_set(v___x_148_, 1, v_a_116_);
lean_ctor_set(v___x_148_, 2, v_a_131_);
lean_ctor_set(v___x_148_, 3, v_a_144_);
if (v_isShared_147_ == 0)
{
lean_ctor_set(v___x_146_, 0, v___x_148_);
v___x_150_ = v___x_146_;
goto v_reusejp_149_;
}
else
{
lean_object* v_reuseFailAlloc_151_; 
v_reuseFailAlloc_151_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_151_, 0, v___x_148_);
v___x_150_ = v_reuseFailAlloc_151_;
goto v_reusejp_149_;
}
v_reusejp_149_:
{
return v___x_150_;
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
lean_object* v___x_153_; lean_object* v___x_154_; 
lean_dec(v_a_89_);
v___x_153_ = ((lean_object*)(l_BudgetWorker_decodeTree___closed__11));
v___x_154_ = l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_decodeTree_spec__0(v_x_75_, v___x_153_);
if (lean_obj_tag(v___x_154_) == 0)
{
lean_object* v_a_155_; lean_object* v___x_157_; uint8_t v_isShared_158_; uint8_t v_isSharedCheck_162_; 
v_a_155_ = lean_ctor_get(v___x_154_, 0);
v_isSharedCheck_162_ = !lean_is_exclusive(v___x_154_);
if (v_isSharedCheck_162_ == 0)
{
v___x_157_ = v___x_154_;
v_isShared_158_ = v_isSharedCheck_162_;
goto v_resetjp_156_;
}
else
{
lean_inc(v_a_155_);
lean_dec(v___x_154_);
v___x_157_ = lean_box(0);
v_isShared_158_ = v_isSharedCheck_162_;
goto v_resetjp_156_;
}
v_resetjp_156_:
{
lean_object* v___x_160_; 
if (v_isShared_158_ == 0)
{
v___x_160_ = v___x_157_;
goto v_reusejp_159_;
}
else
{
lean_object* v_reuseFailAlloc_161_; 
v_reuseFailAlloc_161_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_161_, 0, v_a_155_);
v___x_160_ = v_reuseFailAlloc_161_;
goto v_reusejp_159_;
}
v_reusejp_159_:
{
return v___x_160_;
}
}
}
else
{
lean_object* v_a_163_; lean_object* v___x_165_; uint8_t v_isShared_166_; uint8_t v_isSharedCheck_175_; 
v_a_163_ = lean_ctor_get(v___x_154_, 0);
v_isSharedCheck_175_ = !lean_is_exclusive(v___x_154_);
if (v_isSharedCheck_175_ == 0)
{
v___x_165_ = v___x_154_;
v_isShared_166_ = v_isSharedCheck_175_;
goto v_resetjp_164_;
}
else
{
lean_inc(v_a_163_);
lean_dec(v___x_154_);
v___x_165_ = lean_box(0);
v_isShared_166_ = v_isSharedCheck_175_;
goto v_resetjp_164_;
}
v_resetjp_164_:
{
lean_object* v___x_167_; lean_object* v___x_168_; uint8_t v___x_169_; 
v___x_167_ = l_List_lengthTR___redArg(v_a_163_);
v___x_168_ = lean_unsigned_to_nat(7u);
v___x_169_ = lean_nat_dec_le(v___x_167_, v___x_168_);
lean_dec(v___x_167_);
if (v___x_169_ == 0)
{
lean_object* v___x_170_; 
lean_del_object(v___x_165_);
lean_dec(v_a_163_);
v___x_170_ = ((lean_object*)(l_BudgetWorker_decodeTree___closed__13));
return v___x_170_;
}
else
{
lean_object* v___x_171_; lean_object* v___x_173_; 
v___x_171_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_171_, 0, v_a_163_);
if (v_isShared_166_ == 0)
{
lean_ctor_set(v___x_165_, 0, v___x_171_);
v___x_173_ = v___x_165_;
goto v_reusejp_172_;
}
else
{
lean_object* v_reuseFailAlloc_174_; 
v_reuseFailAlloc_174_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_174_, 0, v___x_171_);
v___x_173_ = v_reuseFailAlloc_174_;
goto v_reusejp_172_;
}
v_reusejp_172_:
{
return v___x_173_;
}
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_decodeTree___boxed(lean_object* v_x_176_, lean_object* v_x_177_){
_start:
{
lean_object* v_res_178_; 
v_res_178_ = l_BudgetWorker_decodeTree(v_x_176_, v_x_177_);
lean_dec(v_x_176_);
return v_res_178_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_kindName(uint8_t v_x_183_){
_start:
{
switch(v_x_183_)
{
case 0:
{
lean_object* v___x_184_; 
v___x_184_ = ((lean_object*)(l_BudgetWorker_kindName___closed__0));
return v___x_184_;
}
case 1:
{
lean_object* v___x_185_; 
v___x_185_ = ((lean_object*)(l_BudgetWorker_kindName___closed__1));
return v___x_185_;
}
case 2:
{
lean_object* v___x_186_; 
v___x_186_ = ((lean_object*)(l_BudgetWorker_kindName___closed__2));
return v___x_186_;
}
default: 
{
lean_object* v___x_187_; 
v___x_187_ = ((lean_object*)(l_BudgetWorker_kindName___closed__3));
return v___x_187_;
}
}
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_kindName___boxed(lean_object* v_x_188_){
_start:
{
uint8_t v_x_40__boxed_189_; lean_object* v_res_190_; 
v_x_40__boxed_189_ = lean_unbox(v_x_188_);
v_res_190_ = l_BudgetWorker_kindName(v_x_40__boxed_189_);
return v_res_190_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_decodeKind(lean_object* v_s_206_){
_start:
{
lean_object* v___x_207_; uint8_t v___x_208_; 
v___x_207_ = ((lean_object*)(l_BudgetWorker_kindName___closed__0));
v___x_208_ = lean_string_dec_eq(v_s_206_, v___x_207_);
if (v___x_208_ == 0)
{
lean_object* v___x_209_; uint8_t v___x_210_; 
v___x_209_ = ((lean_object*)(l_BudgetWorker_kindName___closed__1));
v___x_210_ = lean_string_dec_eq(v_s_206_, v___x_209_);
if (v___x_210_ == 0)
{
lean_object* v___x_211_; uint8_t v___x_212_; 
v___x_211_ = ((lean_object*)(l_BudgetWorker_kindName___closed__2));
v___x_212_ = lean_string_dec_eq(v_s_206_, v___x_211_);
if (v___x_212_ == 0)
{
lean_object* v___x_213_; uint8_t v___x_214_; 
v___x_213_ = ((lean_object*)(l_BudgetWorker_kindName___closed__3));
v___x_214_ = lean_string_dec_eq(v_s_206_, v___x_213_);
if (v___x_214_ == 0)
{
lean_object* v___x_215_; 
v___x_215_ = ((lean_object*)(l_BudgetWorker_decodeKind___closed__1));
return v___x_215_;
}
else
{
lean_object* v___x_216_; 
v___x_216_ = ((lean_object*)(l_BudgetWorker_decodeKind___closed__2));
return v___x_216_;
}
}
else
{
lean_object* v___x_217_; 
v___x_217_ = ((lean_object*)(l_BudgetWorker_decodeKind___closed__3));
return v___x_217_;
}
}
else
{
lean_object* v___x_218_; 
v___x_218_ = ((lean_object*)(l_BudgetWorker_decodeKind___closed__4));
return v___x_218_;
}
}
else
{
lean_object* v___x_219_; 
v___x_219_ = ((lean_object*)(l_BudgetWorker_decodeKind___closed__5));
return v___x_219_;
}
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_decodeKind___boxed(lean_object* v_s_220_){
_start:
{
lean_object* v_res_221_; 
v_res_221_ = l_BudgetWorker_decodeKind(v_s_220_);
lean_dec_ref(v_s_220_);
return v_res_221_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_decodeModel(uint8_t v_kind_248_, lean_object* v_j_249_){
_start:
{
lean_object* v___x_250_; lean_object* v___x_251_; 
v___x_250_ = ((lean_object*)(l_BudgetWorker_decodeModel___closed__0));
lean_inc(v_j_249_);
v___x_251_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_249_, v___x_250_);
if (lean_obj_tag(v___x_251_) == 0)
{
lean_object* v___x_252_; 
lean_dec_ref_known(v___x_251_, 1);
lean_dec(v_j_249_);
v___x_252_ = lean_box(0);
return v___x_252_;
}
else
{
lean_object* v_a_253_; lean_object* v___x_254_; lean_object* v___x_255_; 
v_a_253_ = lean_ctor_get(v___x_251_, 0);
lean_inc(v_a_253_);
lean_dec_ref_known(v___x_251_, 1);
v___x_254_ = ((lean_object*)(l_BudgetWorker_decodeModel___closed__1));
lean_inc(v_j_249_);
v___x_255_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_j_249_, v___x_254_);
if (lean_obj_tag(v___x_255_) == 0)
{
lean_object* v___x_256_; 
lean_dec_ref_known(v___x_255_, 1);
lean_dec(v_a_253_);
lean_dec(v_j_249_);
v___x_256_ = lean_box(0);
return v___x_256_;
}
else
{
lean_object* v_a_257_; lean_object* v___x_258_; lean_object* v___x_259_; 
v_a_257_ = lean_ctor_get(v___x_255_, 0);
lean_inc(v_a_257_);
lean_dec_ref_known(v___x_255_, 1);
v___x_258_ = ((lean_object*)(l_BudgetWorker_decodeModel___closed__2));
lean_inc(v_j_249_);
v___x_259_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_j_249_, v___x_258_);
if (lean_obj_tag(v___x_259_) == 0)
{
lean_object* v___x_260_; 
lean_dec_ref_known(v___x_259_, 1);
lean_dec(v_a_257_);
lean_dec(v_a_253_);
lean_dec(v_j_249_);
v___x_260_ = lean_box(0);
return v___x_260_;
}
else
{
lean_object* v_a_261_; uint8_t v___y_263_; lean_object* v___x_299_; uint8_t v___x_300_; 
v_a_261_ = lean_ctor_get(v___x_259_, 0);
lean_inc(v_a_261_);
lean_dec_ref_known(v___x_259_, 1);
v___x_299_ = lean_unsigned_to_nat(1u);
v___x_300_ = lean_nat_dec_eq(v_a_253_, v___x_299_);
lean_dec(v_a_253_);
if (v___x_300_ == 0)
{
lean_dec(v_a_257_);
v___y_263_ = v___x_300_;
goto v___jp_262_;
}
else
{
lean_object* v___x_301_; uint8_t v___x_302_; 
v___x_301_ = ((lean_object*)(l_BudgetWorker_decodeModel___closed__8));
v___x_302_ = lean_string_dec_eq(v_a_257_, v___x_301_);
lean_dec(v_a_257_);
v___y_263_ = v___x_302_;
goto v___jp_262_;
}
v___jp_262_:
{
if (v___y_263_ == 0)
{
lean_object* v___x_264_; 
lean_dec(v_a_261_);
lean_dec(v_j_249_);
v___x_264_ = lean_box(0);
return v___x_264_;
}
else
{
lean_object* v___x_265_; lean_object* v___x_266_; lean_object* v___x_267_; lean_object* v___x_268_; lean_object* v___x_269_; uint8_t v___x_270_; 
v___x_265_ = ((lean_object*)(l_BudgetWorker_decodeModel___closed__3));
v___x_266_ = l_BudgetWorker_kindName(v_kind_248_);
v___x_267_ = lean_string_append(v___x_265_, v___x_266_);
lean_dec_ref(v___x_266_);
v___x_268_ = ((lean_object*)(l_BudgetWorker_decodeModel___closed__4));
v___x_269_ = lean_string_append(v___x_267_, v___x_268_);
v___x_270_ = lean_string_dec_eq(v_a_261_, v___x_269_);
lean_dec_ref(v___x_269_);
lean_dec(v_a_261_);
if (v___x_270_ == 0)
{
lean_object* v___x_271_; 
lean_dec(v_j_249_);
v___x_271_ = lean_box(0);
return v___x_271_;
}
else
{
lean_object* v___x_272_; lean_object* v___x_273_; 
v___x_272_ = ((lean_object*)(l_BudgetWorker_decodeModel___closed__5));
lean_inc(v_j_249_);
v___x_273_ = l_Lean_Json_getObjVal_x3f(v_j_249_, v___x_272_);
if (lean_obj_tag(v___x_273_) == 0)
{
lean_object* v___x_274_; 
lean_dec_ref_known(v___x_273_, 1);
lean_dec(v_j_249_);
v___x_274_ = lean_box(0);
return v___x_274_;
}
else
{
lean_object* v_a_275_; lean_object* v___x_276_; lean_object* v___x_277_; 
v_a_275_ = lean_ctor_get(v___x_273_, 0);
lean_inc(v_a_275_);
lean_dec_ref_known(v___x_273_, 1);
v___x_276_ = lean_unsigned_to_nat(9u);
v___x_277_ = l_BudgetWorker_decodeTree(v___x_276_, v_a_275_);
if (lean_obj_tag(v___x_277_) == 0)
{
lean_object* v___x_278_; 
lean_dec_ref_known(v___x_277_, 1);
lean_dec(v_j_249_);
v___x_278_ = lean_box(0);
return v___x_278_;
}
else
{
lean_object* v_a_279_; lean_object* v___x_280_; lean_object* v___x_281_; 
v_a_279_ = lean_ctor_get(v___x_277_, 0);
lean_inc(v_a_279_);
lean_dec_ref_known(v___x_277_, 1);
v___x_280_ = ((lean_object*)(l_BudgetWorker_decodeTree___closed__2));
v___x_281_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_j_249_, v___x_280_);
if (lean_obj_tag(v___x_281_) == 0)
{
lean_object* v___x_282_; 
lean_dec_ref_known(v___x_281_, 1);
lean_dec(v_a_279_);
v___x_282_ = lean_box(0);
return v___x_282_;
}
else
{
lean_object* v_a_283_; lean_object* v___x_285_; uint8_t v_isShared_286_; uint8_t v_isSharedCheck_298_; 
v_a_283_ = lean_ctor_get(v___x_281_, 0);
v_isSharedCheck_298_ = !lean_is_exclusive(v___x_281_);
if (v_isSharedCheck_298_ == 0)
{
v___x_285_ = v___x_281_;
v_isShared_286_ = v_isSharedCheck_298_;
goto v_resetjp_284_;
}
else
{
lean_inc(v_a_283_);
lean_dec(v___x_281_);
v___x_285_ = lean_box(0);
v_isShared_286_ = v_isSharedCheck_298_;
goto v_resetjp_284_;
}
v_resetjp_284_:
{
lean_object* v___x_287_; uint8_t v___x_288_; 
v___x_287_ = ((lean_object*)(l_BudgetWorker_decodeModel___closed__6));
v___x_288_ = lean_string_dec_eq(v_a_283_, v___x_287_);
if (v___x_288_ == 0)
{
lean_object* v___x_289_; uint8_t v___x_290_; 
v___x_289_ = ((lean_object*)(l_BudgetWorker_decodeModel___closed__7));
v___x_290_ = lean_string_dec_eq(v_a_283_, v___x_289_);
lean_dec(v_a_283_);
if (v___x_290_ == 0)
{
lean_object* v___x_291_; 
lean_del_object(v___x_285_);
lean_dec(v_a_279_);
v___x_291_ = lean_box(0);
return v___x_291_;
}
else
{
lean_object* v___x_293_; 
if (v_isShared_286_ == 0)
{
lean_ctor_set_tag(v___x_285_, 2);
lean_ctor_set(v___x_285_, 0, v_a_279_);
v___x_293_ = v___x_285_;
goto v_reusejp_292_;
}
else
{
lean_object* v_reuseFailAlloc_294_; 
v_reuseFailAlloc_294_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_294_, 0, v_a_279_);
v___x_293_ = v_reuseFailAlloc_294_;
goto v_reusejp_292_;
}
v_reusejp_292_:
{
return v___x_293_;
}
}
}
else
{
lean_object* v___x_296_; 
lean_dec(v_a_283_);
if (v_isShared_286_ == 0)
{
lean_ctor_set(v___x_285_, 0, v_a_279_);
v___x_296_ = v___x_285_;
goto v_reusejp_295_;
}
else
{
lean_object* v_reuseFailAlloc_297_; 
v_reuseFailAlloc_297_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_297_, 0, v_a_279_);
v___x_296_ = v_reuseFailAlloc_297_;
goto v_reusejp_295_;
}
v_reusejp_295_:
{
return v___x_296_;
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
}
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_decodeModel___boxed(lean_object* v_kind_303_, lean_object* v_j_304_){
_start:
{
uint8_t v_kind_boxed_305_; lean_object* v_res_306_; 
v_kind_boxed_305_ = lean_unbox(v_kind_303_);
v_res_306_ = l_BudgetWorker_decodeModel(v_kind_boxed_305_, v_j_304_);
return v_res_306_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_decodePolicy___lam__0(uint8_t v_a_307_, lean_object* v_choice_308_){
_start:
{
lean_object* v___x_309_; lean_object* v___x_310_; 
v___x_309_ = lean_alloc_ctor(0, 1, 1);
lean_ctor_set(v___x_309_, 0, v_choice_308_);
lean_ctor_set_uint8(v___x_309_, sizeof(void*)*1, v_a_307_);
v___x_310_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_310_, 0, v___x_309_);
return v___x_310_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_decodePolicy___lam__0___boxed(lean_object* v_a_311_, lean_object* v_choice_312_){
_start:
{
uint8_t v_a_666__boxed_313_; lean_object* v_res_314_; 
v_a_666__boxed_313_ = lean_unbox(v_a_311_);
v_res_314_ = l_BudgetWorker_decodePolicy___lam__0(v_a_666__boxed_313_, v_choice_312_);
return v_res_314_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_decodePolicy(lean_object* v_j_328_){
_start:
{
lean_object* v___y_332_; lean_object* v___x_334_; lean_object* v___x_335_; 
v___x_334_ = ((lean_object*)(l_BudgetWorker_decodePolicy___closed__2));
lean_inc(v_j_328_);
v___x_335_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_j_328_, v___x_334_);
if (lean_obj_tag(v___x_335_) == 0)
{
lean_dec_ref_known(v___x_335_, 1);
lean_dec(v_j_328_);
goto v___jp_329_;
}
else
{
lean_object* v_a_336_; lean_object* v___x_337_; 
v_a_336_ = lean_ctor_get(v___x_335_, 0);
lean_inc(v_a_336_);
lean_dec_ref_known(v___x_335_, 1);
v___x_337_ = l_BudgetWorker_decodeKind(v_a_336_);
lean_dec(v_a_336_);
if (lean_obj_tag(v___x_337_) == 0)
{
lean_dec_ref_known(v___x_337_, 1);
lean_dec(v_j_328_);
goto v___jp_329_;
}
else
{
lean_object* v_a_338_; lean_object* v___x_339_; lean_object* v___x_340_; 
v_a_338_ = lean_ctor_get(v___x_337_, 0);
lean_inc(v_a_338_);
lean_dec_ref_known(v___x_337_, 1);
v___x_339_ = ((lean_object*)(l_BudgetWorker_decodeTree___closed__2));
lean_inc(v_j_328_);
v___x_340_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_j_328_, v___x_339_);
if (lean_obj_tag(v___x_340_) == 0)
{
lean_dec_ref_known(v___x_340_, 1);
lean_dec(v_a_338_);
lean_dec(v_j_328_);
goto v___jp_329_;
}
else
{
lean_object* v_a_341_; lean_object* v___x_342_; uint8_t v___x_343_; 
v_a_341_ = lean_ctor_get(v___x_340_, 0);
lean_inc(v_a_341_);
lean_dec_ref_known(v___x_340_, 1);
v___x_342_ = ((lean_object*)(l_BudgetWorker_decodePolicy___closed__3));
v___x_343_ = lean_string_dec_eq(v_a_341_, v___x_342_);
if (v___x_343_ == 0)
{
lean_object* v___x_344_; uint8_t v___x_345_; 
v___x_344_ = ((lean_object*)(l_BudgetWorker_decodePolicy___closed__4));
v___x_345_ = lean_string_dec_eq(v_a_341_, v___x_344_);
if (v___x_345_ == 0)
{
lean_object* v___x_346_; uint8_t v___x_347_; 
v___x_346_ = ((lean_object*)(l_BudgetWorker_decodePolicy___closed__5));
v___x_347_ = lean_string_dec_eq(v_a_341_, v___x_346_);
lean_dec(v_a_341_);
if (v___x_347_ == 0)
{
lean_dec(v_a_338_);
lean_dec(v_j_328_);
goto v___jp_329_;
}
else
{
lean_object* v___x_348_; lean_object* v___x_349_; 
v___x_348_ = ((lean_object*)(l_BudgetWorker_decodePolicy___closed__6));
v___x_349_ = l_Lean_Json_getObjVal_x3f(v_j_328_, v___x_348_);
if (lean_obj_tag(v___x_349_) == 0)
{
lean_dec_ref_known(v___x_349_, 1);
lean_dec(v_a_338_);
goto v___jp_329_;
}
else
{
lean_object* v_a_350_; lean_object* v___x_352_; uint8_t v_isShared_353_; uint8_t v_isSharedCheck_361_; 
v_a_350_ = lean_ctor_get(v___x_349_, 0);
v_isSharedCheck_361_ = !lean_is_exclusive(v___x_349_);
if (v_isSharedCheck_361_ == 0)
{
v___x_352_ = v___x_349_;
v_isShared_353_ = v_isSharedCheck_361_;
goto v_resetjp_351_;
}
else
{
lean_inc(v_a_350_);
lean_dec(v___x_349_);
v___x_352_ = lean_box(0);
v_isShared_353_ = v_isSharedCheck_361_;
goto v_resetjp_351_;
}
v_resetjp_351_:
{
uint8_t v___x_354_; lean_object* v___x_355_; lean_object* v___x_357_; 
v___x_354_ = lean_unbox(v_a_338_);
v___x_355_ = l_BudgetWorker_decodeModel(v___x_354_, v_a_350_);
if (v_isShared_353_ == 0)
{
lean_ctor_set_tag(v___x_352_, 2);
lean_ctor_set(v___x_352_, 0, v___x_355_);
v___x_357_ = v___x_352_;
goto v_reusejp_356_;
}
else
{
lean_object* v_reuseFailAlloc_360_; 
v_reuseFailAlloc_360_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_360_, 0, v___x_355_);
v___x_357_ = v_reuseFailAlloc_360_;
goto v_reusejp_356_;
}
v_reusejp_356_:
{
uint8_t v___x_358_; lean_object* v___x_359_; 
v___x_358_ = lean_unbox(v_a_338_);
lean_dec(v_a_338_);
v___x_359_ = l_BudgetWorker_decodePolicy___lam__0(v___x_358_, v___x_357_);
v___y_332_ = v___x_359_;
goto v___jp_331_;
}
}
}
}
}
else
{
lean_object* v___x_362_; lean_object* v___x_363_; 
lean_dec(v_a_341_);
v___x_362_ = ((lean_object*)(l_BudgetWorker_decodePolicy___closed__7));
lean_inc(v_j_328_);
v___x_363_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_328_, v___x_362_);
if (lean_obj_tag(v___x_363_) == 0)
{
lean_dec_ref_known(v___x_363_, 1);
lean_dec(v_a_338_);
lean_dec(v_j_328_);
goto v___jp_329_;
}
else
{
lean_object* v_a_364_; lean_object* v___x_365_; lean_object* v___x_366_; 
v_a_364_ = lean_ctor_get(v___x_363_, 0);
lean_inc(v_a_364_);
lean_dec_ref_known(v___x_363_, 1);
v___x_365_ = ((lean_object*)(l_BudgetWorker_decodePolicy___closed__8));
v___x_366_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_328_, v___x_365_);
if (lean_obj_tag(v___x_366_) == 0)
{
lean_dec_ref_known(v___x_366_, 1);
lean_dec(v_a_364_);
lean_dec(v_a_338_);
goto v___jp_329_;
}
else
{
lean_object* v_a_367_; lean_object* v___x_368_; uint8_t v___x_369_; lean_object* v___x_370_; 
v_a_367_ = lean_ctor_get(v___x_366_, 0);
lean_inc(v_a_367_);
lean_dec_ref_known(v___x_366_, 1);
v___x_368_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_368_, 0, v_a_364_);
lean_ctor_set(v___x_368_, 1, v_a_367_);
v___x_369_ = lean_unbox(v_a_338_);
lean_dec(v_a_338_);
v___x_370_ = l_BudgetWorker_decodePolicy___lam__0(v___x_369_, v___x_368_);
v___y_332_ = v___x_370_;
goto v___jp_331_;
}
}
}
}
else
{
lean_object* v___x_371_; lean_object* v___x_372_; 
lean_dec(v_a_341_);
v___x_371_ = ((lean_object*)(l_BudgetWorker_decodePolicy___closed__9));
v___x_372_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_IO_FS_Stream_readRequestAs___at___00Lean_IO_FS_Stream_readLspRequestAs___at___00Lean_Server_FileWorker_initAndRunWorker_spec__0_spec__0_spec__2(v_j_328_, v___x_371_);
if (lean_obj_tag(v___x_372_) == 0)
{
lean_dec_ref_known(v___x_372_, 1);
lean_dec(v_a_338_);
goto v___jp_329_;
}
else
{
lean_object* v_a_373_; lean_object* v___x_375_; uint8_t v_isShared_376_; uint8_t v_isSharedCheck_382_; 
v_a_373_ = lean_ctor_get(v___x_372_, 0);
v_isSharedCheck_382_ = !lean_is_exclusive(v___x_372_);
if (v_isSharedCheck_382_ == 0)
{
v___x_375_ = v___x_372_;
v_isShared_376_ = v_isSharedCheck_382_;
goto v_resetjp_374_;
}
else
{
lean_inc(v_a_373_);
lean_dec(v___x_372_);
v___x_375_ = lean_box(0);
v_isShared_376_ = v_isSharedCheck_382_;
goto v_resetjp_374_;
}
v_resetjp_374_:
{
lean_object* v___x_378_; 
if (v_isShared_376_ == 0)
{
lean_ctor_set_tag(v___x_375_, 0);
v___x_378_ = v___x_375_;
goto v_reusejp_377_;
}
else
{
lean_object* v_reuseFailAlloc_381_; 
v_reuseFailAlloc_381_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_381_, 0, v_a_373_);
v___x_378_ = v_reuseFailAlloc_381_;
goto v_reusejp_377_;
}
v_reusejp_377_:
{
uint8_t v___x_379_; lean_object* v___x_380_; 
v___x_379_ = lean_unbox(v_a_338_);
lean_dec(v_a_338_);
v___x_380_ = l_BudgetWorker_decodePolicy___lam__0(v___x_379_, v___x_378_);
v___y_332_ = v___x_380_;
goto v___jp_331_;
}
}
}
}
}
}
}
v___jp_329_:
{
lean_object* v___x_330_; 
v___x_330_ = ((lean_object*)(l_BudgetWorker_decodePolicy___closed__1));
return v___x_330_;
}
v___jp_331_:
{
lean_object* v_a_333_; 
v_a_333_ = lean_ctor_get(v___y_332_, 0);
lean_inc(v_a_333_);
lean_dec_ref(v___y_332_);
return v_a_333_;
}
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_featureSelect(lean_object* v_p_383_, lean_object* v_fs_384_){
_start:
{
lean_object* v_choice_385_; lean_object* v___x_386_; 
v_choice_385_ = lean_ctor_get(v_p_383_, 0);
lean_inc_ref(v_choice_385_);
lean_dec_ref(v_p_383_);
v___x_386_ = l_LeanSort_BudgetSelection_choose(v_choice_385_, v_fs_384_);
return v___x_386_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_featureSelect___boxed(lean_object* v_p_387_, lean_object* v_fs_388_){
_start:
{
lean_object* v_res_389_; 
v_res_389_ = l_BudgetWorker_featureSelect(v_p_387_, v_fs_388_);
lean_dec(v_fs_388_);
return v_res_389_;
}
}
LEAN_EXPORT uint8_t l_BudgetWorker_usesFeatures(lean_object* v_p_390_){
_start:
{
lean_object* v_choice_391_; 
v_choice_391_ = lean_ctor_get(v_p_390_, 0);
if (lean_obj_tag(v_choice_391_) == 0)
{
uint8_t v___x_392_; 
v___x_392_ = 0;
return v___x_392_;
}
else
{
uint8_t v___x_393_; 
v___x_393_ = 1;
return v___x_393_;
}
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_usesFeatures___boxed(lean_object* v_p_394_){
_start:
{
uint8_t v_res_395_; lean_object* v_r_396_; 
v_res_395_ = l_BudgetWorker_usesFeatures(v_p_394_);
lean_dec_ref(v_p_394_);
v_r_396_ = lean_box(v_res_395_);
return v_r_396_;
}
}
LEAN_EXPORT lean_object* l_List_foldl___at___00BudgetWorker_checksum_spec__0(lean_object* v_x_397_, lean_object* v_x_398_){
_start:
{
if (lean_obj_tag(v_x_398_) == 0)
{
return v_x_397_;
}
else
{
lean_object* v_head_399_; lean_object* v_tail_400_; lean_object* v___x_401_; lean_object* v___x_402_; lean_object* v___x_403_; lean_object* v___x_404_; lean_object* v___x_405_; 
v_head_399_ = lean_ctor_get(v_x_398_, 0);
v_tail_400_ = lean_ctor_get(v_x_398_, 1);
v___x_401_ = lean_unsigned_to_nat(33u);
v___x_402_ = lean_nat_mul(v_x_397_, v___x_401_);
lean_dec(v_x_397_);
v___x_403_ = lean_nat_add(v___x_402_, v_head_399_);
lean_dec(v___x_402_);
v___x_404_ = lean_unsigned_to_nat(1000000007u);
v___x_405_ = lean_nat_mod(v___x_403_, v___x_404_);
lean_dec(v___x_403_);
v_x_397_ = v___x_405_;
v_x_398_ = v_tail_400_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_List_foldl___at___00BudgetWorker_checksum_spec__0___boxed(lean_object* v_x_407_, lean_object* v_x_408_){
_start:
{
lean_object* v_res_409_; 
v_res_409_ = l_List_foldl___at___00BudgetWorker_checksum_spec__0(v_x_407_, v_x_408_);
lean_dec(v_x_408_);
return v_res_409_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_checksum(lean_object* v_xs_410_){
_start:
{
lean_object* v___x_411_; lean_object* v___x_412_; 
v___x_411_ = lean_unsigned_to_nat(0u);
v___x_412_ = l_List_foldl___at___00BudgetWorker_checksum_spec__0(v___x_411_, v_xs_410_);
return v___x_412_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_checksum___boxed(lean_object* v_xs_413_){
_start:
{
lean_object* v_res_414_; 
v_res_414_ = l_BudgetWorker_checksum(v_xs_413_);
lean_dec(v_xs_413_);
return v_res_414_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_timedKernel(lean_object* v_id_418_, lean_object* v_source_419_, lean_object* v_outSink_420_, lean_object* v_idSink_421_, lean_object* v_expected_422_){
_start:
{
lean_object* v___x_424_; lean_object* v___x_425_; lean_object* v___x_426_; lean_object* v___x_427_; lean_object* v___x_428_; lean_object* v___x_429_; lean_object* v___x_430_; lean_object* v___x_431_; lean_object* v___x_432_; uint8_t v___x_433_; 
v___x_424_ = lean_io_mono_nanos_now();
v___x_425_ = lean_st_ref_get(v_source_419_);
lean_inc_n(v_id_418_, 2);
v___x_426_ = lean_nat_to_int(v_id_418_);
v___x_427_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_427_, 0, v___x_426_);
v___x_428_ = l_LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0(v___x_427_, v___x_425_);
lean_dec_ref_known(v___x_427_, 1);
v___x_429_ = l_BudgetWorker_checksum(v___x_428_);
v___x_430_ = lean_st_ref_set(v_outSink_420_, v___x_429_);
v___x_431_ = lean_st_ref_set(v_idSink_421_, v_id_418_);
v___x_432_ = lean_io_mono_nanos_now();
v___x_433_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v___x_428_, v_expected_422_);
lean_dec(v___x_428_);
if (v___x_433_ == 0)
{
lean_object* v___x_434_; lean_object* v___x_435_; 
lean_dec(v___x_432_);
lean_dec(v___x_424_);
lean_dec(v_id_418_);
v___x_434_ = ((lean_object*)(l_BudgetWorker_timedKernel___closed__1));
v___x_435_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_435_, 0, v___x_434_);
return v___x_435_;
}
else
{
lean_object* v___x_436_; lean_object* v___x_437_; lean_object* v___x_438_; 
v___x_436_ = lean_nat_sub(v___x_432_, v___x_424_);
lean_dec(v___x_424_);
lean_dec(v___x_432_);
v___x_437_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_437_, 0, v___x_436_);
lean_ctor_set(v___x_437_, 1, v_id_418_);
v___x_438_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_438_, 0, v___x_437_);
return v___x_438_;
}
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_timedKernel___boxed(lean_object* v_id_439_, lean_object* v_source_440_, lean_object* v_outSink_441_, lean_object* v_idSink_442_, lean_object* v_expected_443_, lean_object* v_a_444_){
_start:
{
lean_object* v_res_445_; 
v_res_445_ = l_BudgetWorker_timedKernel(v_id_439_, v_source_440_, v_outSink_441_, v_idSink_442_, v_expected_443_);
lean_dec(v_expected_443_);
lean_dec(v_idSink_442_);
lean_dec(v_outSink_441_);
lean_dec(v_source_440_);
return v_res_445_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_timedPolicy(lean_object* v_p_449_, lean_object* v_source_450_, lean_object* v_outSink_451_, lean_object* v_idSink_452_, lean_object* v_expected_453_){
_start:
{
lean_object* v___x_455_; lean_object* v___x_456_; lean_object* v___x_457_; lean_object* v___x_458_; lean_object* v___x_459_; lean_object* v___x_460_; lean_object* v___x_461_; lean_object* v___x_462_; lean_object* v___x_463_; uint8_t v___x_464_; 
v___x_455_ = lean_io_mono_nanos_now();
v___x_456_ = lean_st_ref_get(v_source_450_);
v___x_457_ = l_LeanSort_BudgetSelection_select(v_p_449_, v___x_456_);
v___x_458_ = l_LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0(v___x_457_, v___x_456_);
v___x_459_ = l_BudgetWorker_checksum(v___x_458_);
v___x_460_ = lean_st_ref_set(v_outSink_451_, v___x_459_);
v___x_461_ = l_LeanSort_LearnedSelection_resolve(v___x_457_);
lean_dec(v___x_457_);
lean_inc(v___x_461_);
v___x_462_ = lean_st_ref_set(v_idSink_452_, v___x_461_);
v___x_463_ = lean_io_mono_nanos_now();
v___x_464_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v___x_458_, v_expected_453_);
lean_dec(v___x_458_);
if (v___x_464_ == 0)
{
lean_object* v___x_465_; lean_object* v___x_466_; 
lean_dec(v___x_463_);
lean_dec(v___x_461_);
lean_dec(v___x_455_);
v___x_465_ = ((lean_object*)(l_BudgetWorker_timedPolicy___closed__1));
v___x_466_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_466_, 0, v___x_465_);
return v___x_466_;
}
else
{
lean_object* v___x_467_; lean_object* v___x_468_; lean_object* v___x_469_; 
v___x_467_ = lean_nat_sub(v___x_463_, v___x_455_);
lean_dec(v___x_455_);
lean_dec(v___x_463_);
v___x_468_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_468_, 0, v___x_467_);
lean_ctor_set(v___x_468_, 1, v___x_461_);
v___x_469_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_469_, 0, v___x_468_);
return v___x_469_;
}
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_timedPolicy___boxed(lean_object* v_p_470_, lean_object* v_source_471_, lean_object* v_outSink_472_, lean_object* v_idSink_473_, lean_object* v_expected_474_, lean_object* v_a_475_){
_start:
{
lean_object* v_res_476_; 
v_res_476_ = l_BudgetWorker_timedPolicy(v_p_470_, v_source_471_, v_outSink_472_, v_idSink_473_, v_expected_474_);
lean_dec(v_expected_474_);
lean_dec(v_idSink_473_);
lean_dec(v_outSink_472_);
lean_dec(v_source_471_);
return v_res_476_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_timedFeatures(uint8_t v_kind_477_, lean_object* v_source_478_, lean_object* v_sink_479_){
_start:
{
lean_object* v___x_481_; lean_object* v___x_482_; lean_object* v___x_483_; lean_object* v___x_484_; lean_object* v___x_485_; lean_object* v___x_486_; lean_object* v___x_487_; lean_object* v___x_488_; 
v___x_481_ = lean_io_mono_nanos_now();
v___x_482_ = lean_st_ref_get(v_source_478_);
v___x_483_ = l_LeanSort_BudgetSelection_features(v_kind_477_, v___x_482_);
lean_dec(v___x_482_);
v___x_484_ = l_BudgetWorker_checksum(v___x_483_);
lean_dec(v___x_483_);
v___x_485_ = lean_st_ref_set(v_sink_479_, v___x_484_);
v___x_486_ = lean_io_mono_nanos_now();
v___x_487_ = lean_nat_sub(v___x_486_, v___x_481_);
lean_dec(v___x_481_);
lean_dec(v___x_486_);
v___x_488_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_488_, 0, v___x_487_);
return v___x_488_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_timedFeatures___boxed(lean_object* v_kind_489_, lean_object* v_source_490_, lean_object* v_sink_491_, lean_object* v_a_492_){
_start:
{
uint8_t v_kind_boxed_493_; lean_object* v_res_494_; 
v_kind_boxed_493_ = lean_unbox(v_kind_489_);
v_res_494_ = l_BudgetWorker_timedFeatures(v_kind_boxed_493_, v_source_490_, v_sink_491_);
lean_dec(v_sink_491_);
lean_dec(v_source_490_);
return v_res_494_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_timedDecision(lean_object* v_p_495_, lean_object* v_source_496_, lean_object* v_sink_497_){
_start:
{
lean_object* v___x_499_; lean_object* v___x_500_; lean_object* v___x_501_; lean_object* v___x_502_; lean_object* v___x_503_; lean_object* v___x_504_; lean_object* v___x_505_; lean_object* v___x_506_; 
v___x_499_ = lean_io_mono_nanos_now();
v___x_500_ = lean_st_ref_get(v_source_496_);
v___x_501_ = l_BudgetWorker_featureSelect(v_p_495_, v___x_500_);
lean_dec(v___x_500_);
v___x_502_ = l_LeanSort_LearnedSelection_resolve(v___x_501_);
lean_dec(v___x_501_);
v___x_503_ = lean_st_ref_set(v_sink_497_, v___x_502_);
v___x_504_ = lean_io_mono_nanos_now();
v___x_505_ = lean_nat_sub(v___x_504_, v___x_499_);
lean_dec(v___x_499_);
lean_dec(v___x_504_);
v___x_506_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_506_, 0, v___x_505_);
return v___x_506_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_timedDecision___boxed(lean_object* v_p_507_, lean_object* v_source_508_, lean_object* v_sink_509_, lean_object* v_a_510_){
_start:
{
lean_object* v_res_511_; 
v_res_511_ = l_BudgetWorker_timedDecision(v_p_507_, v_source_508_, v_sink_509_);
lean_dec(v_sink_509_);
lean_dec(v_source_508_);
return v_res_511_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_emit(lean_object* v_j_512_){
_start:
{
lean_object* v___x_514_; lean_object* v___x_515_; lean_object* v___x_516_; 
v___x_514_ = lean_get_stdout();
v___x_515_ = l_Lean_Json_compress(v_j_512_);
lean_inc_ref(v___x_514_);
v___x_516_ = l_IO_FS_Stream_putStrLn(v___x_514_, v___x_515_);
if (lean_obj_tag(v___x_516_) == 0)
{
lean_object* v_flush_517_; lean_object* v___x_518_; 
lean_dec_ref_known(v___x_516_, 1);
v_flush_517_ = lean_ctor_get(v___x_514_, 0);
lean_inc_ref(v_flush_517_);
lean_dec_ref(v___x_514_);
v___x_518_ = lean_apply_1(v_flush_517_, lean_box(0));
return v___x_518_;
}
else
{
lean_dec_ref(v___x_514_);
return v___x_516_;
}
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_emit___boxed(lean_object* v_j_519_, lean_object* v_a_520_){
_start:
{
lean_object* v_res_521_; 
v_res_521_ = l_BudgetWorker_emit(v_j_519_);
return v_res_521_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_sampleEvent(lean_object* v_category_534_, lean_object* v_name_535_, lean_object* v_round_536_, lean_object* v_ns_537_, lean_object* v_id_538_){
_start:
{
lean_object* v___x_540_; lean_object* v___x_541_; lean_object* v___x_542_; lean_object* v___x_543_; lean_object* v___x_544_; lean_object* v___x_545_; lean_object* v___x_546_; lean_object* v___x_547_; lean_object* v___x_548_; lean_object* v___x_549_; lean_object* v___x_550_; lean_object* v___x_551_; lean_object* v___x_552_; lean_object* v___x_553_; lean_object* v___x_554_; lean_object* v___x_555_; lean_object* v___x_556_; lean_object* v___x_557_; lean_object* v___x_558_; lean_object* v___x_559_; lean_object* v___x_560_; lean_object* v___x_561_; lean_object* v___x_562_; lean_object* v___x_563_; lean_object* v___x_564_; lean_object* v___x_565_; lean_object* v___x_566_; lean_object* v___x_567_; 
v___x_540_ = ((lean_object*)(l_BudgetWorker_sampleEvent___closed__3));
v___x_541_ = ((lean_object*)(l_BudgetWorker_sampleEvent___closed__4));
v___x_542_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_542_, 0, v_category_534_);
v___x_543_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_543_, 0, v___x_541_);
lean_ctor_set(v___x_543_, 1, v___x_542_);
v___x_544_ = ((lean_object*)(l_BudgetWorker_sampleEvent___closed__5));
v___x_545_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_545_, 0, v_name_535_);
v___x_546_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_546_, 0, v___x_544_);
lean_ctor_set(v___x_546_, 1, v___x_545_);
v___x_547_ = ((lean_object*)(l_BudgetWorker_sampleEvent___closed__6));
v___x_548_ = l_Lean_JsonNumber_fromInt(v_round_536_);
v___x_549_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_549_, 0, v___x_548_);
v___x_550_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_550_, 0, v___x_547_);
lean_ctor_set(v___x_550_, 1, v___x_549_);
v___x_551_ = ((lean_object*)(l_BudgetWorker_sampleEvent___closed__7));
v___x_552_ = l_Lean_JsonNumber_fromNat(v_ns_537_);
v___x_553_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_553_, 0, v___x_552_);
v___x_554_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_554_, 0, v___x_551_);
lean_ctor_set(v___x_554_, 1, v___x_553_);
v___x_555_ = ((lean_object*)(l_BudgetWorker_sampleEvent___closed__8));
v___x_556_ = l_Lean_JsonNumber_fromNat(v_id_538_);
v___x_557_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_557_, 0, v___x_556_);
v___x_558_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_558_, 0, v___x_555_);
lean_ctor_set(v___x_558_, 1, v___x_557_);
v___x_559_ = lean_box(0);
v___x_560_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_560_, 0, v___x_558_);
lean_ctor_set(v___x_560_, 1, v___x_559_);
v___x_561_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_561_, 0, v___x_554_);
lean_ctor_set(v___x_561_, 1, v___x_560_);
v___x_562_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_562_, 0, v___x_550_);
lean_ctor_set(v___x_562_, 1, v___x_561_);
v___x_563_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_563_, 0, v___x_546_);
lean_ctor_set(v___x_563_, 1, v___x_562_);
v___x_564_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_564_, 0, v___x_543_);
lean_ctor_set(v___x_564_, 1, v___x_563_);
v___x_565_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_565_, 0, v___x_540_);
lean_ctor_set(v___x_565_, 1, v___x_564_);
v___x_566_ = l_Lean_Json_mkObj(v___x_565_);
lean_dec_ref_known(v___x_565_, 2);
v___x_567_ = l_BudgetWorker_emit(v___x_566_);
return v___x_567_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_sampleEvent___boxed(lean_object* v_category_568_, lean_object* v_name_569_, lean_object* v_round_570_, lean_object* v_ns_571_, lean_object* v_id_572_, lean_object* v_a_573_){
_start:
{
lean_object* v_res_574_; 
v_res_574_ = l_BudgetWorker_sampleEvent(v_category_568_, v_name_569_, v_round_570_, v_ns_571_, v_id_572_);
return v_res_574_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00BudgetWorker_kernelProfile_spec__2_spec__5(lean_object* v_x_575_, lean_object* v_x_576_){
_start:
{
switch(lean_obj_tag(v_x_575_))
{
case 0:
{
lean_object* v_schema_577_; lean_object* v___x_578_; lean_object* v___x_579_; 
v_schema_577_ = lean_ctor_get(v_x_575_, 0);
v___x_578_ = l_List_lengthTR___redArg(v_x_576_);
lean_dec(v_x_576_);
v___x_579_ = lp_leansort_LeanSort_CostedPlan_Schema_upper(v_schema_577_, v___x_578_);
lean_dec(v___x_578_);
return v___x_579_;
}
case 1:
{
lean_object* v___x_580_; lean_object* v___x_581_; lean_object* v___x_582_; lean_object* v___x_583_; lean_object* v___x_584_; lean_object* v___x_585_; lean_object* v___x_586_; lean_object* v___x_587_; lean_object* v___x_588_; 
v___x_580_ = l_List_lengthTR___redArg(v_x_576_);
v___x_581_ = lean_unsigned_to_nat(1u);
v___x_582_ = lean_nat_sub(v___x_580_, v___x_581_);
v___x_583_ = lean_unsigned_to_nat(2u);
v___x_584_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_run___at___00LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0_spec__0_spec__1_spec__3_spec__7(v_x_576_);
v___x_585_ = l_List_lengthTR___redArg(v___x_584_);
lean_dec(v___x_584_);
v___x_586_ = lp_mathlib_Nat_clog(v___x_583_, v___x_585_);
lean_dec(v___x_585_);
v___x_587_ = lean_nat_mul(v___x_580_, v___x_586_);
lean_dec(v___x_586_);
lean_dec(v___x_580_);
v___x_588_ = lean_nat_add(v___x_582_, v___x_587_);
lean_dec(v___x_587_);
lean_dec(v___x_582_);
return v___x_588_;
}
default: 
{
lean_object* v___x_589_; lean_object* v___x_590_; lean_object* v___x_591_; lean_object* v___x_592_; lean_object* v___x_593_; lean_object* v___x_594_; lean_object* v___x_595_; 
v___x_589_ = l_List_lengthTR___redArg(v_x_576_);
v___x_590_ = lean_unsigned_to_nat(1u);
v___x_591_ = lean_nat_sub(v___x_589_, v___x_590_);
lean_dec(v___x_589_);
v___x_592_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_run___at___00LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0_spec__0_spec__1_spec__3_spec__7(v_x_576_);
v___x_593_ = lp_leansort_LeanSort_RunAdaptive_lengthPlan___redArg(v___x_592_);
v___x_594_ = lp_leansort_LeanSort_RunAdaptive_MergeTree_budget___redArg(v___x_593_);
lean_dec(v___x_593_);
v___x_595_ = lean_nat_add(v___x_591_, v___x_594_);
lean_dec(v___x_594_);
lean_dec(v___x_591_);
return v___x_595_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00BudgetWorker_kernelProfile_spec__2_spec__5___boxed(lean_object* v_x_596_, lean_object* v_x_597_){
_start:
{
lean_object* v_res_598_; 
v_res_598_ = l_LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00BudgetWorker_kernelProfile_spec__2_spec__5(v_x_596_, v_x_597_);
lean_dec(v_x_596_);
return v_res_598_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_LearnedSelection_kernelBound___at___00BudgetWorker_kernelProfile_spec__2(lean_object* v_id_599_, lean_object* v_xs_600_){
_start:
{
lean_object* v___x_601_; lean_object* v___x_602_; lean_object* v___x_603_; 
v___x_601_ = l_LeanSort_LearnedSelection_resolve(v_id_599_);
v___x_602_ = l_LeanSort_LearnedSelection_candidate(v___x_601_);
lean_dec(v___x_601_);
v___x_603_ = l_LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00BudgetWorker_kernelProfile_spec__2_spec__5(v___x_602_, v_xs_600_);
lean_dec(v___x_602_);
return v___x_603_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_LearnedSelection_kernelBound___at___00BudgetWorker_kernelProfile_spec__2___boxed(lean_object* v_id_604_, lean_object* v_xs_605_){
_start:
{
lean_object* v_res_606_; 
v_res_606_ = l_LeanSort_LearnedSelection_kernelBound___at___00BudgetWorker_kernelProfile_spec__2(v_id_604_, v_xs_605_);
lean_dec(v_id_604_);
return v_res_606_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__0(uint8_t v_ascending_607_, lean_object* v_head_608_, lean_object* v_____x_609_){
_start:
{
if (v_ascending_607_ == 0)
{
lean_object* v_fst_610_; lean_object* v_snd_611_; lean_object* v___x_613_; uint8_t v_isShared_614_; uint8_t v_isSharedCheck_622_; 
v_fst_610_ = lean_ctor_get(v_____x_609_, 0);
v_snd_611_ = lean_ctor_get(v_____x_609_, 1);
v_isSharedCheck_622_ = !lean_is_exclusive(v_____x_609_);
if (v_isSharedCheck_622_ == 0)
{
v___x_613_ = v_____x_609_;
v_isShared_614_ = v_isSharedCheck_622_;
goto v_resetjp_612_;
}
else
{
lean_inc(v_snd_611_);
lean_inc(v_fst_610_);
lean_dec(v_____x_609_);
v___x_613_ = lean_box(0);
v_isShared_614_ = v_isSharedCheck_622_;
goto v_resetjp_612_;
}
v_resetjp_612_:
{
lean_object* v___x_615_; lean_object* v___x_616_; lean_object* v___x_617_; lean_object* v___x_619_; 
v___x_615_ = lean_box(0);
v___x_616_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_616_, 0, v_head_608_);
lean_ctor_set(v___x_616_, 1, v_fst_610_);
v___x_617_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_617_, 0, v___x_616_);
lean_ctor_set(v___x_617_, 1, v_snd_611_);
if (v_isShared_614_ == 0)
{
lean_ctor_set(v___x_613_, 1, v___x_617_);
lean_ctor_set(v___x_613_, 0, v___x_615_);
v___x_619_ = v___x_613_;
goto v_reusejp_618_;
}
else
{
lean_object* v_reuseFailAlloc_621_; 
v_reuseFailAlloc_621_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_621_, 0, v___x_615_);
lean_ctor_set(v_reuseFailAlloc_621_, 1, v___x_617_);
v___x_619_ = v_reuseFailAlloc_621_;
goto v_reusejp_618_;
}
v_reusejp_618_:
{
lean_object* v___x_620_; 
v___x_620_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_619_);
return v___x_620_;
}
}
}
else
{
lean_object* v_fst_623_; lean_object* v_snd_624_; lean_object* v___x_626_; uint8_t v_isShared_627_; uint8_t v_isSharedCheck_633_; 
v_fst_623_ = lean_ctor_get(v_____x_609_, 0);
v_snd_624_ = lean_ctor_get(v_____x_609_, 1);
v_isSharedCheck_633_ = !lean_is_exclusive(v_____x_609_);
if (v_isSharedCheck_633_ == 0)
{
v___x_626_ = v_____x_609_;
v_isShared_627_ = v_isSharedCheck_633_;
goto v_resetjp_625_;
}
else
{
lean_inc(v_snd_624_);
lean_inc(v_fst_623_);
lean_dec(v_____x_609_);
v___x_626_ = lean_box(0);
v_isShared_627_ = v_isSharedCheck_633_;
goto v_resetjp_625_;
}
v_resetjp_625_:
{
lean_object* v___x_628_; lean_object* v___x_630_; 
v___x_628_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_628_, 0, v_head_608_);
lean_ctor_set(v___x_628_, 1, v_fst_623_);
if (v_isShared_627_ == 0)
{
lean_ctor_set(v___x_626_, 0, v___x_628_);
v___x_630_ = v___x_626_;
goto v_reusejp_629_;
}
else
{
lean_object* v_reuseFailAlloc_632_; 
v_reuseFailAlloc_632_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_632_, 0, v___x_628_);
lean_ctor_set(v_reuseFailAlloc_632_, 1, v_snd_624_);
v___x_630_ = v_reuseFailAlloc_632_;
goto v_reusejp_629_;
}
v_reusejp_629_:
{
lean_object* v___x_631_; 
v___x_631_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_630_);
return v___x_631_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__0___boxed(lean_object* v_ascending_634_, lean_object* v_head_635_, lean_object* v_____x_636_){
_start:
{
uint8_t v_ascending_boxed_637_; lean_object* v_res_638_; 
v_ascending_boxed_637_ = lean_unbox(v_ascending_634_);
v_res_638_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__0(v_ascending_boxed_637_, v_head_635_, v_____x_636_);
return v_res_638_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__1___boxed(lean_object* v_head_639_, lean_object* v_tail_640_, lean_object* v_ascending_641_){
_start:
{
uint8_t v_ascending_boxed_642_; lean_object* v_res_643_; 
v_ascending_boxed_642_ = lean_unbox(v_ascending_641_);
v_res_643_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__1(v_head_639_, v_tail_640_, v_ascending_boxed_642_);
return v_res_643_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18(lean_object* v_x_644_, lean_object* v_x_645_){
_start:
{
if (lean_obj_tag(v_x_645_) == 0)
{
lean_object* v___x_646_; lean_object* v___x_647_; lean_object* v___x_648_; 
v___x_646_ = lean_box(0);
v___x_647_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_647_, 0, v_x_645_);
lean_ctor_set(v___x_647_, 1, v___x_646_);
v___x_648_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_647_);
return v___x_648_;
}
else
{
lean_object* v_head_649_; lean_object* v_tail_650_; lean_object* v___x_652_; uint8_t v_isShared_653_; uint8_t v_isSharedCheck_662_; 
v_head_649_ = lean_ctor_get(v_x_645_, 0);
v_tail_650_ = lean_ctor_get(v_x_645_, 1);
v_isSharedCheck_662_ = !lean_is_exclusive(v_x_645_);
if (v_isSharedCheck_662_ == 0)
{
v___x_652_ = v_x_645_;
v_isShared_653_ = v_isSharedCheck_662_;
goto v_resetjp_651_;
}
else
{
lean_inc(v_tail_650_);
lean_inc(v_head_649_);
lean_dec(v_x_645_);
v___x_652_ = lean_box(0);
v_isShared_653_ = v_isSharedCheck_662_;
goto v_resetjp_651_;
}
v_resetjp_651_:
{
lean_object* v___f_654_; uint8_t v___x_655_; lean_object* v___x_656_; lean_object* v___x_657_; lean_object* v___x_659_; 
lean_inc(v_head_649_);
v___f_654_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__1___boxed), 3, 2);
lean_closure_set(v___f_654_, 0, v_head_649_);
lean_closure_set(v___f_654_, 1, v_tail_650_);
v___x_655_ = lean_nat_dec_le(v_x_644_, v_head_649_);
lean_dec(v_head_649_);
v___x_656_ = lean_unsigned_to_nat(1u);
v___x_657_ = lean_box(v___x_655_);
if (v_isShared_653_ == 0)
{
lean_ctor_set_tag(v___x_652_, 0);
lean_ctor_set(v___x_652_, 1, v___x_656_);
lean_ctor_set(v___x_652_, 0, v___x_657_);
v___x_659_ = v___x_652_;
goto v_reusejp_658_;
}
else
{
lean_object* v_reuseFailAlloc_661_; 
v_reuseFailAlloc_661_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_661_, 0, v___x_657_);
lean_ctor_set(v_reuseFailAlloc_661_, 1, v___x_656_);
v___x_659_ = v_reuseFailAlloc_661_;
goto v_reusejp_658_;
}
v_reusejp_658_:
{
lean_object* v___x_660_; 
v___x_660_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_659_, v___f_654_);
return v___x_660_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__1(lean_object* v_head_663_, lean_object* v_tail_664_, uint8_t v_ascending_665_){
_start:
{
lean_object* v___x_666_; lean_object* v___f_667_; lean_object* v___x_668_; lean_object* v___x_669_; 
v___x_666_ = lean_box(v_ascending_665_);
lean_inc(v_head_663_);
v___f_667_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__0___boxed), 3, 2);
lean_closure_set(v___f_667_, 0, v___x_666_);
lean_closure_set(v___f_667_, 1, v_head_663_);
v___x_668_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18(v_head_663_, v_tail_664_);
lean_dec(v_head_663_);
v___x_669_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_668_, v___f_667_);
return v___x_669_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___boxed(lean_object* v_x_670_, lean_object* v_x_671_){
_start:
{
lean_object* v_res_672_; 
v_res_672_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18(v_x_670_, v_x_671_);
lean_dec(v_x_670_);
return v_res_672_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___lam__0(lean_object* v_head_673_, lean_object* v_____x_674_){
_start:
{
lean_object* v_fst_675_; lean_object* v_snd_676_; lean_object* v___x_678_; uint8_t v_isShared_679_; uint8_t v_isSharedCheck_685_; 
v_fst_675_ = lean_ctor_get(v_____x_674_, 0);
v_snd_676_ = lean_ctor_get(v_____x_674_, 1);
v_isSharedCheck_685_ = !lean_is_exclusive(v_____x_674_);
if (v_isSharedCheck_685_ == 0)
{
v___x_678_ = v_____x_674_;
v_isShared_679_ = v_isSharedCheck_685_;
goto v_resetjp_677_;
}
else
{
lean_inc(v_snd_676_);
lean_inc(v_fst_675_);
lean_dec(v_____x_674_);
v___x_678_ = lean_box(0);
v_isShared_679_ = v_isSharedCheck_685_;
goto v_resetjp_677_;
}
v_resetjp_677_:
{
lean_object* v___x_681_; 
if (v_isShared_679_ == 0)
{
lean_ctor_set_tag(v___x_678_, 1);
lean_ctor_set(v___x_678_, 1, v_fst_675_);
lean_ctor_set(v___x_678_, 0, v_head_673_);
v___x_681_ = v___x_678_;
goto v_reusejp_680_;
}
else
{
lean_object* v_reuseFailAlloc_684_; 
v_reuseFailAlloc_684_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_684_, 0, v_head_673_);
lean_ctor_set(v_reuseFailAlloc_684_, 1, v_fst_675_);
v___x_681_ = v_reuseFailAlloc_684_;
goto v_reusejp_680_;
}
v_reusejp_680_:
{
lean_object* v___x_682_; lean_object* v___x_683_; 
v___x_682_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_682_, 0, v___x_681_);
lean_ctor_set(v___x_682_, 1, v_snd_676_);
v___x_683_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_682_);
return v___x_683_;
}
}
}
}
static lean_object* _init_l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0(void){
_start:
{
lean_object* v___x_686_; lean_object* v___x_687_; 
v___x_686_ = lean_box(0);
v___x_687_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_686_);
return v___x_687_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11(lean_object* v_x_688_){
_start:
{
if (lean_obj_tag(v_x_688_) == 0)
{
lean_object* v___x_689_; 
v___x_689_ = lean_obj_once(&l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0, &l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0_once, _init_l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0);
return v___x_689_;
}
else
{
lean_object* v_head_690_; lean_object* v_tail_691_; lean_object* v___f_692_; lean_object* v___x_693_; lean_object* v___x_694_; 
v_head_690_ = lean_ctor_get(v_x_688_, 0);
lean_inc_n(v_head_690_, 2);
v_tail_691_ = lean_ctor_get(v_x_688_, 1);
lean_inc(v_tail_691_);
lean_dec_ref_known(v_x_688_, 2);
v___f_692_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___lam__0), 2, 1);
lean_closure_set(v___f_692_, 0, v_head_690_);
v___x_693_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18(v_head_690_, v_tail_691_);
lean_dec(v_head_690_);
v___x_694_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_693_, v___f_692_);
return v___x_694_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0(lean_object* v_head_695_, lean_object* v_rest_696_){
_start:
{
lean_object* v___x_697_; lean_object* v___x_698_; 
v___x_697_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_697_, 0, v_head_695_);
lean_ctor_set(v___x_697_, 1, v_rest_696_);
v___x_698_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_697_);
return v___x_698_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__2___boxed(lean_object* v_x_699_, lean_object* v_tail_700_, lean_object* v___f_701_, lean_object* v_tail_702_, lean_object* v_x_703_, lean_object* v___f_704_, lean_object* v_smaller_705_){
_start:
{
uint8_t v_smaller_boxed_706_; lean_object* v_res_707_; 
v_smaller_boxed_706_ = lean_unbox(v_smaller_705_);
v_res_707_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__2(v_x_699_, v_tail_700_, v___f_701_, v_tail_702_, v_x_703_, v___f_704_, v_smaller_boxed_706_);
return v_res_707_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7(lean_object* v_x_708_, lean_object* v_x_709_){
_start:
{
if (lean_obj_tag(v_x_708_) == 0)
{
lean_object* v___x_710_; 
v___x_710_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_709_);
return v___x_710_;
}
else
{
if (lean_obj_tag(v_x_709_) == 0)
{
lean_object* v___x_711_; 
v___x_711_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_708_);
return v___x_711_;
}
else
{
lean_object* v_head_712_; lean_object* v_tail_713_; lean_object* v_head_714_; lean_object* v_tail_715_; lean_object* v___f_716_; lean_object* v___f_717_; lean_object* v___f_718_; uint8_t v___x_719_; lean_object* v___x_720_; lean_object* v___x_721_; lean_object* v___x_722_; lean_object* v___x_723_; 
v_head_712_ = lean_ctor_get(v_x_708_, 0);
lean_inc_n(v_head_712_, 2);
v_tail_713_ = lean_ctor_get(v_x_708_, 1);
lean_inc(v_tail_713_);
v_head_714_ = lean_ctor_get(v_x_709_, 0);
lean_inc_n(v_head_714_, 2);
v_tail_715_ = lean_ctor_get(v_x_709_, 1);
lean_inc(v_tail_715_);
v___f_716_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0), 2, 1);
lean_closure_set(v___f_716_, 0, v_head_712_);
v___f_717_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0), 2, 1);
lean_closure_set(v___f_717_, 0, v_head_714_);
v___f_718_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__2___boxed), 7, 6);
lean_closure_set(v___f_718_, 0, v_x_708_);
lean_closure_set(v___f_718_, 1, v_tail_715_);
lean_closure_set(v___f_718_, 2, v___f_717_);
lean_closure_set(v___f_718_, 3, v_tail_713_);
lean_closure_set(v___f_718_, 4, v_x_709_);
lean_closure_set(v___f_718_, 5, v___f_716_);
v___x_719_ = lean_nat_dec_le(v_head_712_, v_head_714_);
lean_dec(v_head_714_);
lean_dec(v_head_712_);
v___x_720_ = lean_unsigned_to_nat(1u);
v___x_721_ = lean_box(v___x_719_);
v___x_722_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_722_, 0, v___x_721_);
lean_ctor_set(v___x_722_, 1, v___x_720_);
v___x_723_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_722_, v___f_718_);
return v___x_723_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__2(lean_object* v_x_724_, lean_object* v_tail_725_, lean_object* v___f_726_, lean_object* v_tail_727_, lean_object* v_x_728_, lean_object* v___f_729_, uint8_t v_smaller_730_){
_start:
{
if (v_smaller_730_ == 0)
{
lean_object* v___x_731_; lean_object* v___x_732_; 
lean_dec_ref(v___f_729_);
lean_dec(v_x_728_);
lean_dec(v_tail_727_);
v___x_731_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7(v_x_724_, v_tail_725_);
v___x_732_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_731_, v___f_726_);
return v___x_732_;
}
else
{
lean_object* v___x_733_; lean_object* v___x_734_; 
lean_dec_ref(v___f_726_);
lean_dec(v_tail_725_);
lean_dec(v_x_724_);
v___x_733_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7(v_tail_727_, v_x_728_);
v___x_734_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_733_, v___f_729_);
return v___x_734_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__0(lean_object* v_ls_735_, lean_object* v_rs_736_){
_start:
{
lean_object* v___x_737_; 
v___x_737_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7(v_ls_735_, v_rs_736_);
return v___x_737_;
}
}
static lean_object* _init_l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0(void){
_start:
{
lean_object* v___x_738_; lean_object* v___x_739_; 
v___x_738_ = lean_box(0);
v___x_739_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_738_);
return v___x_739_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10(lean_object* v_x_740_){
_start:
{
switch(lean_obj_tag(v_x_740_))
{
case 0:
{
lean_object* v___x_741_; 
v___x_741_ = lean_obj_once(&l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0, &l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0_once, _init_l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0);
return v___x_741_;
}
case 1:
{
lean_object* v_run_742_; lean_object* v___x_743_; 
v_run_742_ = lean_ctor_get(v_x_740_, 0);
lean_inc(v_run_742_);
lean_dec_ref_known(v_x_740_, 1);
v___x_743_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_run_742_);
return v___x_743_;
}
default: 
{
lean_object* v_left_744_; lean_object* v_right_745_; lean_object* v___f_746_; lean_object* v___x_747_; lean_object* v___x_748_; 
v_left_744_ = lean_ctor_get(v_x_740_, 0);
lean_inc(v_left_744_);
v_right_745_ = lean_ctor_get(v_x_740_, 1);
lean_inc(v_right_745_);
lean_dec_ref_known(v_x_740_, 2);
v___f_746_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___lam__1), 2, 1);
lean_closure_set(v___f_746_, 0, v_right_745_);
v___x_747_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10(v_left_744_);
v___x_748_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_747_, v___f_746_);
return v___x_748_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___lam__1(lean_object* v_right_749_, lean_object* v_ls_750_){
_start:
{
lean_object* v___f_751_; lean_object* v___x_752_; lean_object* v___x_753_; 
v___f_751_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__0), 2, 1);
lean_closure_set(v___f_751_, 0, v_ls_750_);
v___x_752_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10(v_right_749_);
v___x_753_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_752_, v___f_751_);
return v___x_753_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__3___lam__0(lean_object* v_runs_754_){
_start:
{
lean_object* v___x_755_; lean_object* v___x_756_; 
v___x_755_ = lp_leansort_LeanSort_RunAdaptive_lengthPlan___redArg(v_runs_754_);
v___x_756_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10(v___x_755_);
return v___x_756_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__3(lean_object* v_xs_758_){
_start:
{
lean_object* v___f_759_; lean_object* v___x_760_; lean_object* v___x_761_; 
v___f_759_ = ((lean_object*)(l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__3___closed__0));
v___x_760_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11(v_xs_758_);
v___x_761_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_760_, v___f_759_);
return v___x_761_;
}
}
static lean_object* _init_l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0(void){
_start:
{
uint8_t v___x_762_; lean_object* v___x_763_; lean_object* v___x_764_; 
v___x_762_ = 1;
v___x_763_ = lean_box(v___x_762_);
v___x_764_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_763_);
return v___x_764_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___lam__0___boxed(lean_object* v_tail_765_, lean_object* v_smaller_766_){
_start:
{
uint8_t v_smaller_boxed_767_; lean_object* v_res_768_; 
v_smaller_boxed_767_ = lean_unbox(v_smaller_766_);
v_res_768_ = l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___lam__0(v_tail_765_, v_smaller_boxed_767_);
return v_res_768_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8(lean_object* v_x_769_){
_start:
{
if (lean_obj_tag(v_x_769_) == 0)
{
lean_object* v___x_770_; 
v___x_770_ = lean_obj_once(&l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0, &l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0_once, _init_l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0);
return v___x_770_;
}
else
{
lean_object* v_tail_771_; 
v_tail_771_ = lean_ctor_get(v_x_769_, 1);
lean_inc(v_tail_771_);
if (lean_obj_tag(v_tail_771_) == 0)
{
lean_object* v___x_772_; 
lean_dec_ref_known(v_x_769_, 2);
v___x_772_ = lean_obj_once(&l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0, &l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0_once, _init_l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0);
return v___x_772_;
}
else
{
lean_object* v_head_773_; lean_object* v___x_775_; uint8_t v_isShared_776_; uint8_t v_isSharedCheck_786_; 
v_head_773_ = lean_ctor_get(v_x_769_, 0);
v_isSharedCheck_786_ = !lean_is_exclusive(v_x_769_);
if (v_isSharedCheck_786_ == 0)
{
lean_object* v_unused_787_; 
v_unused_787_ = lean_ctor_get(v_x_769_, 1);
lean_dec(v_unused_787_);
v___x_775_ = v_x_769_;
v_isShared_776_ = v_isSharedCheck_786_;
goto v_resetjp_774_;
}
else
{
lean_inc(v_head_773_);
lean_dec(v_x_769_);
v___x_775_ = lean_box(0);
v_isShared_776_ = v_isSharedCheck_786_;
goto v_resetjp_774_;
}
v_resetjp_774_:
{
lean_object* v_head_777_; lean_object* v___f_778_; uint8_t v___x_779_; lean_object* v___x_780_; lean_object* v___x_781_; lean_object* v___x_783_; 
v_head_777_ = lean_ctor_get(v_tail_771_, 0);
lean_inc(v_head_777_);
v___f_778_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___lam__0___boxed), 2, 1);
lean_closure_set(v___f_778_, 0, v_tail_771_);
v___x_779_ = lean_nat_dec_le(v_head_773_, v_head_777_);
lean_dec(v_head_777_);
lean_dec(v_head_773_);
v___x_780_ = lean_unsigned_to_nat(1u);
v___x_781_ = lean_box(v___x_779_);
if (v_isShared_776_ == 0)
{
lean_ctor_set_tag(v___x_775_, 0);
lean_ctor_set(v___x_775_, 1, v___x_780_);
lean_ctor_set(v___x_775_, 0, v___x_781_);
v___x_783_ = v___x_775_;
goto v_reusejp_782_;
}
else
{
lean_object* v_reuseFailAlloc_785_; 
v_reuseFailAlloc_785_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_785_, 0, v___x_781_);
lean_ctor_set(v_reuseFailAlloc_785_, 1, v___x_780_);
v___x_783_ = v_reuseFailAlloc_785_;
goto v_reusejp_782_;
}
v_reusejp_782_:
{
lean_object* v___x_784_; 
v___x_784_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_783_, v___f_778_);
return v___x_784_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___lam__0(lean_object* v_tail_788_, uint8_t v_smaller_789_){
_start:
{
if (v_smaller_789_ == 0)
{
lean_object* v___x_790_; lean_object* v___x_791_; 
lean_dec(v_tail_788_);
v___x_790_ = lean_box(v_smaller_789_);
v___x_791_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_790_);
return v___x_791_;
}
else
{
lean_object* v___x_792_; 
v___x_792_ = l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8(v_tail_788_);
return v___x_792_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__0(lean_object* v_left_793_, lean_object* v_right_794_){
_start:
{
lean_object* v___x_795_; 
v___x_795_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7(v_left_793_, v_right_794_);
return v___x_795_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__1___boxed(lean_object* v___x_796_, lean_object* v_xs_797_, lean_object* v_left_798_){
_start:
{
lean_object* v_res_799_; 
v_res_799_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__1(v___x_796_, v_xs_797_, v_left_798_);
lean_dec(v_xs_797_);
return v_res_799_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10(lean_object* v_xs_802_){
_start:
{
lean_object* v___x_803_; lean_object* v___x_804_; uint8_t v___x_805_; 
v___x_803_ = l_List_lengthTR___redArg(v_xs_802_);
v___x_804_ = lean_unsigned_to_nat(2u);
v___x_805_ = lean_nat_dec_lt(v___x_803_, v___x_804_);
if (v___x_805_ == 0)
{
lean_object* v___x_806_; lean_object* v___x_807_; lean_object* v___f_808_; lean_object* v___x_809_; lean_object* v___x_810_; lean_object* v___x_811_; lean_object* v___x_812_; 
v___x_806_ = lean_unsigned_to_nat(1u);
v___x_807_ = lean_nat_shiftr(v___x_803_, v___x_806_);
lean_dec(v___x_803_);
lean_inc_n(v_xs_802_, 2);
lean_inc(v___x_807_);
v___f_808_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__1___boxed), 3, 2);
lean_closure_set(v___f_808_, 0, v___x_807_);
lean_closure_set(v___f_808_, 1, v_xs_802_);
v___x_809_ = ((lean_object*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___closed__0));
v___x_810_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_xs_802_, v_xs_802_, v___x_807_, v___x_809_);
lean_dec(v_xs_802_);
v___x_811_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10(v___x_810_);
v___x_812_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_811_, v___f_808_);
return v___x_812_;
}
else
{
lean_object* v___x_813_; 
lean_dec(v___x_803_);
v___x_813_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_xs_802_);
return v___x_813_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__1(lean_object* v___x_814_, lean_object* v_xs_815_, lean_object* v_left_816_){
_start:
{
lean_object* v___f_817_; lean_object* v___x_818_; lean_object* v___x_819_; lean_object* v___x_820_; 
v___f_817_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__0), 2, 1);
lean_closure_set(v___f_817_, 0, v_left_816_);
v___x_818_ = l_List_drop___redArg(v___x_814_, v_xs_815_);
v___x_819_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10(v___x_818_);
v___x_820_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_819_, v___f_817_);
return v___x_820_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18___lam__1___boxed(lean_object* v_x_821_, lean_object* v_tail_822_, lean_object* v___f_823_, lean_object* v_x_824_, lean_object* v_smaller_825_){
_start:
{
uint8_t v_smaller_boxed_826_; lean_object* v_res_827_; 
v_smaller_boxed_826_ = lean_unbox(v_smaller_825_);
v_res_827_ = l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18___lam__1(v_x_821_, v_tail_822_, v___f_823_, v_x_824_, v_smaller_boxed_826_);
return v_res_827_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18(lean_object* v_x_828_, lean_object* v_x_829_){
_start:
{
if (lean_obj_tag(v_x_829_) == 0)
{
lean_object* v___x_830_; lean_object* v___x_831_; 
v___x_830_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_830_, 0, v_x_828_);
lean_ctor_set(v___x_830_, 1, v_x_829_);
v___x_831_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_830_);
return v___x_831_;
}
else
{
lean_object* v_head_832_; lean_object* v_tail_833_; lean_object* v___f_834_; lean_object* v___f_835_; uint8_t v___x_836_; lean_object* v___x_837_; lean_object* v___x_838_; lean_object* v___x_839_; lean_object* v___x_840_; 
v_head_832_ = lean_ctor_get(v_x_829_, 0);
lean_inc_n(v_head_832_, 2);
v_tail_833_ = lean_ctor_get(v_x_829_, 1);
lean_inc(v_tail_833_);
v___f_834_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0), 2, 1);
lean_closure_set(v___f_834_, 0, v_head_832_);
lean_inc(v_x_828_);
v___f_835_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18___lam__1___boxed), 5, 4);
lean_closure_set(v___f_835_, 0, v_x_828_);
lean_closure_set(v___f_835_, 1, v_tail_833_);
lean_closure_set(v___f_835_, 2, v___f_834_);
lean_closure_set(v___f_835_, 3, v_x_829_);
v___x_836_ = lean_nat_dec_le(v_x_828_, v_head_832_);
lean_dec(v_head_832_);
lean_dec(v_x_828_);
v___x_837_ = lean_unsigned_to_nat(1u);
v___x_838_ = lean_box(v___x_836_);
v___x_839_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_839_, 0, v___x_838_);
lean_ctor_set(v___x_839_, 1, v___x_837_);
v___x_840_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_839_, v___f_835_);
return v___x_840_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18___lam__1(lean_object* v_x_841_, lean_object* v_tail_842_, lean_object* v___f_843_, lean_object* v_x_844_, uint8_t v_smaller_845_){
_start:
{
if (v_smaller_845_ == 0)
{
lean_object* v___x_846_; lean_object* v___x_847_; 
lean_dec(v_x_844_);
v___x_846_ = l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18(v_x_841_, v_tail_842_);
v___x_847_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_846_, v___f_843_);
return v___x_847_;
}
else
{
lean_object* v___x_848_; lean_object* v___x_849_; 
lean_dec_ref(v___f_843_);
lean_dec(v_tail_842_);
v___x_848_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_848_, 0, v_x_841_);
lean_ctor_set(v___x_848_, 1, v_x_844_);
v___x_849_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_848_);
return v___x_849_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11___lam__0(lean_object* v_head_850_, lean_object* v_rest_851_){
_start:
{
lean_object* v___x_852_; 
v___x_852_ = l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18(v_head_850_, v_rest_851_);
return v___x_852_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11(lean_object* v_x_853_){
_start:
{
if (lean_obj_tag(v_x_853_) == 0)
{
lean_object* v___x_854_; 
v___x_854_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_853_);
return v___x_854_;
}
else
{
lean_object* v_head_855_; lean_object* v_tail_856_; lean_object* v___f_857_; lean_object* v___x_858_; lean_object* v___x_859_; 
v_head_855_ = lean_ctor_get(v_x_853_, 0);
lean_inc(v_head_855_);
v_tail_856_ = lean_ctor_get(v_x_853_, 1);
lean_inc(v_tail_856_);
lean_dec_ref_known(v_x_853_, 2);
v___f_857_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11___lam__0), 2, 1);
lean_closure_set(v___f_857_, 0, v_head_855_);
v___x_858_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11(v_tail_856_);
v___x_859_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_858_, v___f_857_);
return v___x_859_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12___lam__1___boxed(lean_object* v___x_860_, lean_object* v_xs_861_, lean_object* v_threshold_862_, lean_object* v_left_863_){
_start:
{
lean_object* v_res_864_; 
v_res_864_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12___lam__1(v___x_860_, v_xs_861_, v_threshold_862_, v_left_863_);
lean_dec(v_xs_861_);
return v_res_864_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12(lean_object* v_threshold_865_, lean_object* v_xs_866_){
_start:
{
lean_object* v___x_867_; lean_object* v___y_869_; lean_object* v___x_879_; uint8_t v___x_880_; 
v___x_867_ = l_List_lengthTR___redArg(v_xs_866_);
v___x_879_ = lean_unsigned_to_nat(1u);
v___x_880_ = lean_nat_dec_le(v___x_879_, v_threshold_865_);
if (v___x_880_ == 0)
{
v___y_869_ = v___x_879_;
goto v___jp_868_;
}
else
{
lean_inc(v_threshold_865_);
v___y_869_ = v_threshold_865_;
goto v___jp_868_;
}
v___jp_868_:
{
uint8_t v___x_870_; 
v___x_870_ = lean_nat_dec_le(v___x_867_, v___y_869_);
lean_dec(v___y_869_);
if (v___x_870_ == 0)
{
lean_object* v___x_871_; lean_object* v___x_872_; lean_object* v___f_873_; lean_object* v___x_874_; lean_object* v___x_875_; lean_object* v___x_876_; lean_object* v___x_877_; 
v___x_871_ = lean_unsigned_to_nat(1u);
v___x_872_ = lean_nat_shiftr(v___x_867_, v___x_871_);
lean_dec(v___x_867_);
lean_inc(v_threshold_865_);
lean_inc_n(v_xs_866_, 2);
lean_inc(v___x_872_);
v___f_873_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12___lam__1___boxed), 4, 3);
lean_closure_set(v___f_873_, 0, v___x_872_);
lean_closure_set(v___f_873_, 1, v_xs_866_);
lean_closure_set(v___f_873_, 2, v_threshold_865_);
v___x_874_ = ((lean_object*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___closed__0));
v___x_875_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_xs_866_, v_xs_866_, v___x_872_, v___x_874_);
lean_dec(v_xs_866_);
v___x_876_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12(v_threshold_865_, v___x_875_);
v___x_877_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_876_, v___f_873_);
return v___x_877_;
}
else
{
lean_object* v___x_878_; 
lean_dec(v___x_867_);
lean_dec(v_threshold_865_);
v___x_878_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11(v_xs_866_);
return v___x_878_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12___lam__1(lean_object* v___x_881_, lean_object* v_xs_882_, lean_object* v_threshold_883_, lean_object* v_left_884_){
_start:
{
lean_object* v___f_885_; lean_object* v___x_886_; lean_object* v___x_887_; lean_object* v___x_888_; 
v___f_885_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__0), 2, 1);
lean_closure_set(v___f_885_, 0, v_left_884_);
v___x_886_ = l_List_drop___redArg(v___x_881_, v_xs_882_);
v___x_887_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12(v_threshold_883_, v___x_886_);
v___x_888_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_887_, v___f_885_);
return v___x_888_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6(lean_object* v_x_889_, lean_object* v_x_890_){
_start:
{
switch(lean_obj_tag(v_x_889_))
{
case 0:
{
lean_object* v___x_891_; 
v___x_891_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10(v_x_890_);
return v___x_891_;
}
case 1:
{
lean_object* v___x_892_; 
v___x_892_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11(v_x_890_);
return v___x_892_;
}
default: 
{
lean_object* v_threshold_893_; lean_object* v___x_894_; 
v_threshold_893_ = lean_ctor_get(v_x_889_, 0);
lean_inc(v_threshold_893_);
lean_dec_ref_known(v_x_889_, 1);
v___x_894_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12(v_threshold_893_, v_x_890_);
return v___x_894_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__1___boxed(lean_object* v___x_895_, lean_object* v_x_896_, lean_object* v_right_897_, lean_object* v_ls_898_){
_start:
{
lean_object* v_res_899_; 
v_res_899_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__1(v___x_895_, v_x_896_, v_right_897_, v_ls_898_);
lean_dec(v_x_896_);
return v_res_899_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__2(lean_object* v_fallback_900_, lean_object* v_x_901_, uint8_t v_sorted_902_){
_start:
{
if (v_sorted_902_ == 0)
{
lean_object* v___x_903_; 
v___x_903_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1(v_fallback_900_, v_x_901_);
return v___x_903_;
}
else
{
lean_object* v___x_904_; 
lean_dec_ref(v_fallback_900_);
v___x_904_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_901_);
return v___x_904_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__2___boxed(lean_object* v_fallback_905_, lean_object* v_x_906_, lean_object* v_sorted_907_){
_start:
{
uint8_t v_sorted_boxed_908_; lean_object* v_res_909_; 
v_sorted_boxed_908_ = lean_unbox(v_sorted_907_);
v_res_909_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__2(v_fallback_905_, v_x_906_, v_sorted_boxed_908_);
return v_res_909_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1(lean_object* v_x_910_, lean_object* v_x_911_){
_start:
{
switch(lean_obj_tag(v_x_910_))
{
case 0:
{
lean_object* v_component_912_; lean_object* v___x_913_; 
v_component_912_ = lean_ctor_get(v_x_910_, 0);
lean_inc(v_component_912_);
lean_dec_ref_known(v_x_910_, 1);
v___x_913_ = l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6(v_component_912_, v_x_911_);
return v___x_913_;
}
case 1:
{
lean_object* v_cut_914_; lean_object* v_left_915_; lean_object* v_right_916_; lean_object* v___x_917_; lean_object* v___x_918_; lean_object* v___f_919_; lean_object* v___x_920_; lean_object* v___x_921_; lean_object* v___x_922_; lean_object* v___x_923_; 
v_cut_914_ = lean_ctor_get(v_x_910_, 0);
lean_inc_ref(v_cut_914_);
v_left_915_ = lean_ctor_get(v_x_910_, 1);
lean_inc_ref(v_left_915_);
v_right_916_ = lean_ctor_get(v_x_910_, 2);
lean_inc_ref(v_right_916_);
lean_dec_ref_known(v_x_910_, 3);
v___x_917_ = l_List_lengthTR___redArg(v_x_911_);
v___x_918_ = lp_leansort_LeanSort_CostedPlan_Cut_position(v_cut_914_, v___x_917_);
lean_dec(v___x_917_);
lean_dec_ref(v_cut_914_);
lean_inc_n(v_x_911_, 2);
lean_inc(v___x_918_);
v___f_919_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__1___boxed), 4, 3);
lean_closure_set(v___f_919_, 0, v___x_918_);
lean_closure_set(v___f_919_, 1, v_x_911_);
lean_closure_set(v___f_919_, 2, v_right_916_);
v___x_920_ = ((lean_object*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___closed__0));
v___x_921_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_x_911_, v_x_911_, v___x_918_, v___x_920_);
lean_dec(v_x_911_);
v___x_922_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1(v_left_915_, v___x_921_);
v___x_923_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_922_, v___f_919_);
return v___x_923_;
}
default: 
{
lean_object* v_fallback_924_; lean_object* v___f_925_; lean_object* v___x_926_; lean_object* v___x_927_; 
v_fallback_924_ = lean_ctor_get(v_x_910_, 0);
lean_inc_ref(v_fallback_924_);
lean_dec_ref_known(v_x_910_, 1);
lean_inc(v_x_911_);
v___f_925_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__2___boxed), 3, 2);
lean_closure_set(v___f_925_, 0, v_fallback_924_);
lean_closure_set(v___f_925_, 1, v_x_911_);
v___x_926_ = l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8(v_x_911_);
v___x_927_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_926_, v___f_925_);
return v___x_927_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__1(lean_object* v___x_928_, lean_object* v_x_929_, lean_object* v_right_930_, lean_object* v_ls_931_){
_start:
{
lean_object* v___f_932_; lean_object* v___x_933_; lean_object* v___x_934_; lean_object* v___x_935_; 
v___f_932_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1___lam__0), 2, 1);
lean_closure_set(v___f_932_, 0, v_ls_931_);
v___x_933_ = l_List_drop___redArg(v___x_928_, v_x_929_);
v___x_934_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1(v_right_930_, v___x_933_);
v___x_935_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_934_, v___f_932_);
return v___x_935_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2___lam__0(lean_object* v_runs_936_){
_start:
{
lean_object* v___x_937_; lean_object* v___x_938_; 
v___x_937_ = lp_leansort_LeanSort_RunAdaptive_countPlan___redArg(v_runs_936_);
v___x_938_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10(v___x_937_);
return v___x_938_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2(lean_object* v_xs_940_){
_start:
{
lean_object* v___f_941_; lean_object* v___x_942_; lean_object* v___x_943_; 
v___f_941_ = ((lean_object*)(l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2___closed__0));
v___x_942_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11(v_xs_940_);
v___x_943_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_942_, v___f_941_);
return v___x_943_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0(lean_object* v_x_944_, lean_object* v_x_945_){
_start:
{
switch(lean_obj_tag(v_x_944_))
{
case 0:
{
lean_object* v_schema_946_; lean_object* v___x_947_; 
v_schema_946_ = lean_ctor_get(v_x_944_, 0);
lean_inc_ref(v_schema_946_);
lean_dec_ref_known(v_x_944_, 1);
v___x_947_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1(v_schema_946_, v_x_945_);
return v___x_947_;
}
case 1:
{
lean_object* v___x_948_; 
v___x_948_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2(v_x_945_);
return v___x_948_;
}
default: 
{
lean_object* v___x_949_; 
v___x_949_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__3(v_x_945_);
return v___x_949_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_readyCheck___at___00BudgetWorker_kernelProfile_spec__3_spec__7___redArg(lean_object* v_x_950_){
_start:
{
if (lean_obj_tag(v_x_950_) == 0)
{
lean_object* v_value_951_; lean_object* v___x_952_; lean_object* v___x_953_; 
v_value_951_ = lean_ctor_get(v_x_950_, 0);
lean_inc(v_value_951_);
lean_dec_ref_known(v_x_950_, 1);
v___x_952_ = lean_unsigned_to_nat(0u);
v___x_953_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_953_, 0, v_value_951_);
lean_ctor_set(v___x_953_, 1, v___x_952_);
return v___x_953_;
}
else
{
lean_object* v_left_954_; lean_object* v_right_955_; lean_object* v_next_956_; uint8_t v___x_957_; lean_object* v___x_958_; lean_object* v___x_959_; lean_object* v_rest_960_; lean_object* v_ret_961_; lean_object* v_time_962_; lean_object* v___x_964_; uint8_t v_isShared_965_; uint8_t v_isSharedCheck_971_; 
v_left_954_ = lean_ctor_get(v_x_950_, 0);
lean_inc(v_left_954_);
v_right_955_ = lean_ctor_get(v_x_950_, 1);
lean_inc(v_right_955_);
v_next_956_ = lean_ctor_get(v_x_950_, 2);
lean_inc_ref(v_next_956_);
lean_dec_ref_known(v_x_950_, 3);
v___x_957_ = lean_nat_dec_le(v_left_954_, v_right_955_);
lean_dec(v_right_955_);
lean_dec(v_left_954_);
v___x_958_ = lean_box(v___x_957_);
v___x_959_ = lean_apply_1(v_next_956_, v___x_958_);
v_rest_960_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_readyCheck___at___00BudgetWorker_kernelProfile_spec__3_spec__7___redArg(v___x_959_);
v_ret_961_ = lean_ctor_get(v_rest_960_, 0);
v_time_962_ = lean_ctor_get(v_rest_960_, 1);
v_isSharedCheck_971_ = !lean_is_exclusive(v_rest_960_);
if (v_isSharedCheck_971_ == 0)
{
v___x_964_ = v_rest_960_;
v_isShared_965_ = v_isSharedCheck_971_;
goto v_resetjp_963_;
}
else
{
lean_inc(v_time_962_);
lean_inc(v_ret_961_);
lean_dec(v_rest_960_);
v___x_964_ = lean_box(0);
v_isShared_965_ = v_isSharedCheck_971_;
goto v_resetjp_963_;
}
v_resetjp_963_:
{
lean_object* v___x_966_; lean_object* v___x_967_; lean_object* v___x_969_; 
v___x_966_ = lean_unsigned_to_nat(1u);
v___x_967_ = lean_nat_add(v_time_962_, v___x_966_);
lean_dec(v_time_962_);
if (v_isShared_965_ == 0)
{
lean_ctor_set(v___x_964_, 1, v___x_967_);
v___x_969_ = v___x_964_;
goto v_reusejp_968_;
}
else
{
lean_object* v_reuseFailAlloc_970_; 
v_reuseFailAlloc_970_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_970_, 0, v_ret_961_);
lean_ctor_set(v_reuseFailAlloc_970_, 1, v___x_967_);
v___x_969_ = v_reuseFailAlloc_970_;
goto v_reusejp_968_;
}
v_reusejp_968_:
{
return v___x_969_;
}
}
}
}
}
LEAN_EXPORT uint8_t l_LeanSort_CostedPlan_Schema_readyCheck___at___00BudgetWorker_kernelProfile_spec__3(lean_object* v_x_972_, lean_object* v_x_973_){
_start:
{
switch(lean_obj_tag(v_x_972_))
{
case 0:
{
uint8_t v___x_974_; 
lean_dec(v_x_973_);
v___x_974_ = 1;
return v___x_974_;
}
case 1:
{
lean_object* v_cut_975_; lean_object* v_left_976_; lean_object* v_right_977_; lean_object* v___x_978_; lean_object* v___x_979_; lean_object* v___x_980_; lean_object* v___x_981_; uint8_t v___x_982_; 
v_cut_975_ = lean_ctor_get(v_x_972_, 0);
v_left_976_ = lean_ctor_get(v_x_972_, 1);
v_right_977_ = lean_ctor_get(v_x_972_, 2);
v___x_978_ = l_List_lengthTR___redArg(v_x_973_);
v___x_979_ = lp_leansort_LeanSort_CostedPlan_Cut_position(v_cut_975_, v___x_978_);
lean_dec(v___x_978_);
v___x_980_ = ((lean_object*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___closed__0));
lean_inc(v___x_979_);
lean_inc(v_x_973_);
v___x_981_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_x_973_, v_x_973_, v___x_979_, v___x_980_);
v___x_982_ = l_LeanSort_CostedPlan_Schema_readyCheck___at___00BudgetWorker_kernelProfile_spec__3(v_left_976_, v___x_981_);
if (v___x_982_ == 0)
{
lean_dec(v___x_979_);
lean_dec(v_x_973_);
return v___x_982_;
}
else
{
lean_object* v___x_983_; 
v___x_983_ = l_List_drop___redArg(v___x_979_, v_x_973_);
lean_dec(v_x_973_);
v_x_972_ = v_right_977_;
v_x_973_ = v___x_983_;
goto _start;
}
}
default: 
{
lean_object* v___x_985_; lean_object* v___x_986_; lean_object* v_ret_987_; uint8_t v___x_988_; 
v___x_985_ = lp_leansort_LeanSort_ComparisonSort_checkSorted___redArg(v_x_973_);
v___x_986_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_readyCheck___at___00BudgetWorker_kernelProfile_spec__3_spec__7___redArg(v___x_985_);
v_ret_987_ = lean_ctor_get(v___x_986_, 0);
lean_inc(v_ret_987_);
lean_dec_ref(v___x_986_);
v___x_988_ = lean_unbox(v_ret_987_);
lean_dec(v_ret_987_);
return v___x_988_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_CostedPlan_Schema_readyCheck___at___00BudgetWorker_kernelProfile_spec__3___boxed(lean_object* v_x_989_, lean_object* v_x_990_){
_start:
{
uint8_t v_res_991_; lean_object* v_r_992_; 
v_res_991_ = l_LeanSort_CostedPlan_Schema_readyCheck___at___00BudgetWorker_kernelProfile_spec__3(v_x_989_, v_x_990_);
lean_dec_ref(v_x_989_);
v_r_992_ = lean_box(v_res_991_);
return v_r_992_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__2(uint8_t v_selected_993_, uint8_t v_phase_994_, lean_object* v_x_995_, lean_object* v_y_996_){
_start:
{
uint8_t v___x_997_; uint8_t v___x_998_; 
v___x_997_ = lean_nat_dec_le(v_x_995_, v_y_996_);
v___x_998_ = lp_leansort_LeanSort_Comparison_instDecidableEqPhase(v_phase_994_, v_selected_993_);
if (v___x_998_ == 0)
{
lean_object* v___x_999_; lean_object* v___x_1000_; lean_object* v___x_1001_; 
v___x_999_ = lean_unsigned_to_nat(0u);
v___x_1000_ = lean_box(v___x_997_);
v___x_1001_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1001_, 0, v___x_1000_);
lean_ctor_set(v___x_1001_, 1, v___x_999_);
return v___x_1001_;
}
else
{
lean_object* v___x_1002_; lean_object* v___x_1003_; lean_object* v___x_1004_; 
v___x_1002_ = lean_unsigned_to_nat(1u);
v___x_1003_ = lean_box(v___x_997_);
v___x_1004_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1004_, 0, v___x_1003_);
lean_ctor_set(v___x_1004_, 1, v___x_1002_);
return v___x_1004_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__2___boxed(lean_object* v_selected_1005_, lean_object* v_phase_1006_, lean_object* v_x_1007_, lean_object* v_y_1008_){
_start:
{
uint8_t v_selected_boxed_1009_; uint8_t v_phase_boxed_1010_; lean_object* v_res_1011_; 
v_selected_boxed_1009_ = lean_unbox(v_selected_1005_);
v_phase_boxed_1010_ = lean_unbox(v_phase_1006_);
v_res_1011_ = l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__2(v_selected_boxed_1009_, v_phase_boxed_1010_, v_x_1007_, v_y_1008_);
lean_dec(v_y_1008_);
lean_dec(v_x_1007_);
return v_res_1011_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___lam__1___boxed(lean_object* v_head_1012_, lean_object* v_phase_1013_, lean_object* v_tail_1014_, lean_object* v_ascending_1015_){
_start:
{
uint8_t v_phase_boxed_1016_; uint8_t v_ascending_boxed_1017_; lean_object* v_res_1018_; 
v_phase_boxed_1016_ = lean_unbox(v_phase_1013_);
v_ascending_boxed_1017_ = lean_unbox(v_ascending_1015_);
v_res_1018_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___lam__1(v_head_1012_, v_phase_boxed_1016_, v_tail_1014_, v_ascending_boxed_1017_);
return v_res_1018_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30(uint8_t v_phase_1019_, lean_object* v_x_1020_, lean_object* v_x_1021_){
_start:
{
if (lean_obj_tag(v_x_1021_) == 0)
{
lean_object* v___x_1022_; lean_object* v___x_1023_; lean_object* v___x_1024_; 
v___x_1022_ = lean_box(0);
v___x_1023_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1023_, 0, v_x_1021_);
lean_ctor_set(v___x_1023_, 1, v___x_1022_);
v___x_1024_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_1023_);
return v___x_1024_;
}
else
{
lean_object* v_head_1025_; lean_object* v_tail_1026_; lean_object* v___x_1027_; lean_object* v___f_1028_; uint8_t v___x_1029_; lean_object* v___x_1030_; lean_object* v___x_1031_; 
v_head_1025_ = lean_ctor_get(v_x_1021_, 0);
lean_inc_n(v_head_1025_, 2);
v_tail_1026_ = lean_ctor_get(v_x_1021_, 1);
lean_inc(v_tail_1026_);
lean_dec_ref_known(v_x_1021_, 2);
v___x_1027_ = lean_box(v_phase_1019_);
v___f_1028_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___lam__1___boxed), 4, 3);
lean_closure_set(v___f_1028_, 0, v_head_1025_);
lean_closure_set(v___f_1028_, 1, v___x_1027_);
lean_closure_set(v___f_1028_, 2, v_tail_1026_);
v___x_1029_ = 0;
v___x_1030_ = l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__2(v_phase_1019_, v___x_1029_, v_x_1020_, v_head_1025_);
lean_dec(v_head_1025_);
v___x_1031_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1030_, v___f_1028_);
return v___x_1031_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___lam__1(lean_object* v_head_1032_, uint8_t v_phase_1033_, lean_object* v_tail_1034_, uint8_t v_ascending_1035_){
_start:
{
lean_object* v___x_1036_; lean_object* v___f_1037_; lean_object* v___x_1038_; lean_object* v___x_1039_; 
v___x_1036_ = lean_box(v_ascending_1035_);
lean_inc(v_head_1032_);
v___f_1037_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__0___boxed), 3, 2);
lean_closure_set(v___f_1037_, 0, v___x_1036_);
lean_closure_set(v___f_1037_, 1, v_head_1032_);
v___x_1038_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30(v_phase_1033_, v_head_1032_, v_tail_1034_);
lean_dec(v_head_1032_);
v___x_1039_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1038_, v___f_1037_);
return v___x_1039_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___boxed(lean_object* v_phase_1040_, lean_object* v_x_1041_, lean_object* v_x_1042_){
_start:
{
uint8_t v_phase_boxed_1043_; lean_object* v_res_1044_; 
v_phase_boxed_1043_ = lean_unbox(v_phase_1040_);
v_res_1044_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30(v_phase_boxed_1043_, v_x_1041_, v_x_1042_);
lean_dec(v_x_1041_);
return v_res_1044_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20(uint8_t v_phase_1045_, lean_object* v_x_1046_){
_start:
{
if (lean_obj_tag(v_x_1046_) == 0)
{
lean_object* v___x_1047_; 
v___x_1047_ = lean_obj_once(&l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0, &l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0_once, _init_l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0);
return v___x_1047_;
}
else
{
lean_object* v_head_1048_; lean_object* v_tail_1049_; lean_object* v___f_1050_; lean_object* v___x_1051_; lean_object* v___x_1052_; 
v_head_1048_ = lean_ctor_get(v_x_1046_, 0);
lean_inc_n(v_head_1048_, 2);
v_tail_1049_ = lean_ctor_get(v_x_1046_, 1);
lean_inc(v_tail_1049_);
lean_dec_ref_known(v_x_1046_, 2);
v___f_1050_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___lam__0), 2, 1);
lean_closure_set(v___f_1050_, 0, v_head_1048_);
v___x_1051_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30(v_phase_1045_, v_head_1048_, v_tail_1049_);
lean_dec(v_head_1048_);
v___x_1052_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1051_, v___f_1050_);
return v___x_1052_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20___boxed(lean_object* v_phase_1053_, lean_object* v_x_1054_){
_start:
{
uint8_t v_phase_boxed_1055_; lean_object* v_res_1056_; 
v_phase_boxed_1055_ = lean_unbox(v_phase_1053_);
v_res_1056_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20(v_phase_boxed_1055_, v_x_1054_);
return v_res_1056_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___lam__2___boxed(lean_object* v_phase_1057_, lean_object* v_x_1058_, lean_object* v_tail_1059_, lean_object* v___f_1060_, lean_object* v_tail_1061_, lean_object* v_x_1062_, lean_object* v___f_1063_, lean_object* v_smaller_1064_){
_start:
{
uint8_t v_phase_boxed_1065_; uint8_t v_smaller_boxed_1066_; lean_object* v_res_1067_; 
v_phase_boxed_1065_ = lean_unbox(v_phase_1057_);
v_smaller_boxed_1066_ = lean_unbox(v_smaller_1064_);
v_res_1067_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___lam__2(v_phase_boxed_1065_, v_x_1058_, v_tail_1059_, v___f_1060_, v_tail_1061_, v_x_1062_, v___f_1063_, v_smaller_boxed_1066_);
return v_res_1067_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16(uint8_t v_phase_1068_, lean_object* v_x_1069_, lean_object* v_x_1070_){
_start:
{
if (lean_obj_tag(v_x_1069_) == 0)
{
lean_object* v___x_1071_; 
v___x_1071_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_1070_);
return v___x_1071_;
}
else
{
if (lean_obj_tag(v_x_1070_) == 0)
{
lean_object* v___x_1072_; 
v___x_1072_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_1069_);
return v___x_1072_;
}
else
{
lean_object* v_head_1073_; lean_object* v_tail_1074_; lean_object* v_head_1075_; lean_object* v_tail_1076_; lean_object* v___f_1077_; lean_object* v___f_1078_; lean_object* v___x_1079_; lean_object* v___f_1080_; uint8_t v___x_1081_; lean_object* v___x_1082_; lean_object* v___x_1083_; 
v_head_1073_ = lean_ctor_get(v_x_1069_, 0);
lean_inc_n(v_head_1073_, 2);
v_tail_1074_ = lean_ctor_get(v_x_1069_, 1);
lean_inc(v_tail_1074_);
v_head_1075_ = lean_ctor_get(v_x_1070_, 0);
lean_inc_n(v_head_1075_, 2);
v_tail_1076_ = lean_ctor_get(v_x_1070_, 1);
lean_inc(v_tail_1076_);
v___f_1077_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0), 2, 1);
lean_closure_set(v___f_1077_, 0, v_head_1073_);
v___f_1078_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0), 2, 1);
lean_closure_set(v___f_1078_, 0, v_head_1075_);
v___x_1079_ = lean_box(v_phase_1068_);
v___f_1080_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___lam__2___boxed), 8, 7);
lean_closure_set(v___f_1080_, 0, v___x_1079_);
lean_closure_set(v___f_1080_, 1, v_x_1069_);
lean_closure_set(v___f_1080_, 2, v_tail_1076_);
lean_closure_set(v___f_1080_, 3, v___f_1078_);
lean_closure_set(v___f_1080_, 4, v_tail_1074_);
lean_closure_set(v___f_1080_, 5, v_x_1070_);
lean_closure_set(v___f_1080_, 6, v___f_1077_);
v___x_1081_ = 1;
v___x_1082_ = l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__2(v_phase_1068_, v___x_1081_, v_head_1073_, v_head_1075_);
lean_dec(v_head_1075_);
lean_dec(v_head_1073_);
v___x_1083_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1082_, v___f_1080_);
return v___x_1083_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___lam__2(uint8_t v_phase_1084_, lean_object* v_x_1085_, lean_object* v_tail_1086_, lean_object* v___f_1087_, lean_object* v_tail_1088_, lean_object* v_x_1089_, lean_object* v___f_1090_, uint8_t v_smaller_1091_){
_start:
{
if (v_smaller_1091_ == 0)
{
lean_object* v___x_1092_; lean_object* v___x_1093_; 
lean_dec_ref(v___f_1090_);
lean_dec(v_x_1089_);
lean_dec(v_tail_1088_);
v___x_1092_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16(v_phase_1084_, v_x_1085_, v_tail_1086_);
v___x_1093_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1092_, v___f_1087_);
return v___x_1093_;
}
else
{
lean_object* v___x_1094_; lean_object* v___x_1095_; 
lean_dec_ref(v___f_1087_);
lean_dec(v_tail_1086_);
lean_dec(v_x_1085_);
v___x_1094_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16(v_phase_1084_, v_tail_1088_, v_x_1089_);
v___x_1095_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1094_, v___f_1090_);
return v___x_1095_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___boxed(lean_object* v_phase_1096_, lean_object* v_x_1097_, lean_object* v_x_1098_){
_start:
{
uint8_t v_phase_boxed_1099_; lean_object* v_res_1100_; 
v_phase_boxed_1099_ = lean_unbox(v_phase_1096_);
v_res_1100_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16(v_phase_boxed_1099_, v_x_1097_, v_x_1098_);
return v_res_1100_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__0(uint8_t v_phase_1101_, lean_object* v_ls_1102_, lean_object* v_rs_1103_){
_start:
{
lean_object* v___x_1104_; 
v___x_1104_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16(v_phase_1101_, v_ls_1102_, v_rs_1103_);
return v___x_1104_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__0___boxed(lean_object* v_phase_1105_, lean_object* v_ls_1106_, lean_object* v_rs_1107_){
_start:
{
uint8_t v_phase_boxed_1108_; lean_object* v_res_1109_; 
v_phase_boxed_1108_ = lean_unbox(v_phase_1105_);
v_res_1109_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__0(v_phase_boxed_1108_, v_ls_1106_, v_rs_1107_);
return v_res_1109_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___lam__1___boxed(lean_object* v_phase_1110_, lean_object* v_right_1111_, lean_object* v_ls_1112_){
_start:
{
uint8_t v_phase_boxed_1113_; lean_object* v_res_1114_; 
v_phase_boxed_1113_ = lean_unbox(v_phase_1110_);
v_res_1114_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___lam__1(v_phase_boxed_1113_, v_right_1111_, v_ls_1112_);
return v_res_1114_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19(uint8_t v_phase_1115_, lean_object* v_x_1116_){
_start:
{
switch(lean_obj_tag(v_x_1116_))
{
case 0:
{
lean_object* v___x_1117_; 
v___x_1117_ = lean_obj_once(&l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0, &l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0_once, _init_l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0);
return v___x_1117_;
}
case 1:
{
lean_object* v_run_1118_; lean_object* v___x_1119_; 
v_run_1118_ = lean_ctor_get(v_x_1116_, 0);
lean_inc(v_run_1118_);
lean_dec_ref_known(v_x_1116_, 1);
v___x_1119_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_run_1118_);
return v___x_1119_;
}
default: 
{
lean_object* v_left_1120_; lean_object* v_right_1121_; lean_object* v___x_1122_; lean_object* v___f_1123_; lean_object* v___x_1124_; lean_object* v___x_1125_; 
v_left_1120_ = lean_ctor_get(v_x_1116_, 0);
lean_inc(v_left_1120_);
v_right_1121_ = lean_ctor_get(v_x_1116_, 1);
lean_inc(v_right_1121_);
lean_dec_ref_known(v_x_1116_, 2);
v___x_1122_ = lean_box(v_phase_1115_);
v___f_1123_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___lam__1___boxed), 3, 2);
lean_closure_set(v___f_1123_, 0, v___x_1122_);
lean_closure_set(v___f_1123_, 1, v_right_1121_);
v___x_1124_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19(v_phase_1115_, v_left_1120_);
v___x_1125_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1124_, v___f_1123_);
return v___x_1125_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___lam__1(uint8_t v_phase_1126_, lean_object* v_right_1127_, lean_object* v_ls_1128_){
_start:
{
lean_object* v___x_1129_; lean_object* v___f_1130_; lean_object* v___x_1131_; lean_object* v___x_1132_; 
v___x_1129_ = lean_box(v_phase_1126_);
v___f_1130_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__0___boxed), 3, 2);
lean_closure_set(v___f_1130_, 0, v___x_1129_);
lean_closure_set(v___f_1130_, 1, v_ls_1128_);
v___x_1131_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19(v_phase_1126_, v_right_1127_);
v___x_1132_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1131_, v___f_1130_);
return v___x_1132_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___boxed(lean_object* v_phase_1133_, lean_object* v_x_1134_){
_start:
{
uint8_t v_phase_boxed_1135_; lean_object* v_res_1136_; 
v_phase_boxed_1135_ = lean_unbox(v_phase_1133_);
v_res_1136_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19(v_phase_boxed_1135_, v_x_1134_);
return v_res_1136_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__9___lam__0(uint8_t v_phase_1137_, lean_object* v_runs_1138_){
_start:
{
lean_object* v___x_1139_; lean_object* v___x_1140_; 
v___x_1139_ = lp_leansort_LeanSort_RunAdaptive_lengthPlan___redArg(v_runs_1138_);
v___x_1140_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19(v_phase_1137_, v___x_1139_);
return v___x_1140_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__9___lam__0___boxed(lean_object* v_phase_1141_, lean_object* v_runs_1142_){
_start:
{
uint8_t v_phase_boxed_1143_; lean_object* v_res_1144_; 
v_phase_boxed_1143_ = lean_unbox(v_phase_1141_);
v_res_1144_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__9___lam__0(v_phase_boxed_1143_, v_runs_1142_);
return v_res_1144_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__9(uint8_t v_phase_1145_, lean_object* v_xs_1146_){
_start:
{
lean_object* v___x_1147_; lean_object* v___f_1148_; lean_object* v___x_1149_; lean_object* v___x_1150_; 
v___x_1147_ = lean_box(v_phase_1145_);
v___f_1148_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__9___lam__0___boxed), 2, 1);
lean_closure_set(v___f_1148_, 0, v___x_1147_);
v___x_1149_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20(v_phase_1145_, v_xs_1146_);
v___x_1150_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1149_, v___f_1148_);
return v___x_1150_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__9___boxed(lean_object* v_phase_1151_, lean_object* v_xs_1152_){
_start:
{
uint8_t v_phase_boxed_1153_; lean_object* v_res_1154_; 
v_phase_boxed_1153_ = lean_unbox(v_phase_1151_);
v_res_1154_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__9(v_phase_boxed_1153_, v_xs_1152_);
return v_res_1154_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___lam__0___boxed(lean_object* v_phase_1155_, lean_object* v_tail_1156_, lean_object* v_smaller_1157_){
_start:
{
uint8_t v_phase_boxed_1158_; uint8_t v_smaller_boxed_1159_; lean_object* v_res_1160_; 
v_phase_boxed_1158_ = lean_unbox(v_phase_1155_);
v_smaller_boxed_1159_ = lean_unbox(v_smaller_1157_);
v_res_1160_ = l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___lam__0(v_phase_boxed_1158_, v_tail_1156_, v_smaller_boxed_1159_);
return v_res_1160_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17(uint8_t v_phase_1161_, lean_object* v_x_1162_){
_start:
{
if (lean_obj_tag(v_x_1162_) == 0)
{
lean_object* v___x_1163_; 
v___x_1163_ = lean_obj_once(&l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0, &l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0_once, _init_l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0);
return v___x_1163_;
}
else
{
lean_object* v_tail_1164_; 
v_tail_1164_ = lean_ctor_get(v_x_1162_, 1);
lean_inc(v_tail_1164_);
if (lean_obj_tag(v_tail_1164_) == 0)
{
lean_object* v___x_1165_; 
lean_dec_ref_known(v_x_1162_, 2);
v___x_1165_ = lean_obj_once(&l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0, &l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0_once, _init_l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0);
return v___x_1165_;
}
else
{
lean_object* v_head_1166_; lean_object* v_head_1167_; lean_object* v___x_1168_; lean_object* v___f_1169_; uint8_t v___x_1170_; lean_object* v___x_1171_; lean_object* v___x_1172_; 
v_head_1166_ = lean_ctor_get(v_x_1162_, 0);
lean_inc(v_head_1166_);
lean_dec_ref_known(v_x_1162_, 2);
v_head_1167_ = lean_ctor_get(v_tail_1164_, 0);
lean_inc(v_head_1167_);
v___x_1168_ = lean_box(v_phase_1161_);
v___f_1169_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___lam__0___boxed), 3, 2);
lean_closure_set(v___f_1169_, 0, v___x_1168_);
lean_closure_set(v___f_1169_, 1, v_tail_1164_);
v___x_1170_ = 0;
v___x_1171_ = l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__2(v_phase_1161_, v___x_1170_, v_head_1166_, v_head_1167_);
lean_dec(v_head_1167_);
lean_dec(v_head_1166_);
v___x_1172_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1171_, v___f_1169_);
return v___x_1172_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___lam__0(uint8_t v_phase_1173_, lean_object* v_tail_1174_, uint8_t v_smaller_1175_){
_start:
{
if (v_smaller_1175_ == 0)
{
lean_object* v___x_1176_; lean_object* v___x_1177_; 
lean_dec(v_tail_1174_);
v___x_1176_ = lean_box(v_smaller_1175_);
v___x_1177_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_1176_);
return v___x_1177_;
}
else
{
lean_object* v___x_1178_; 
v___x_1178_ = l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17(v_phase_1173_, v_tail_1174_);
return v___x_1178_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___boxed(lean_object* v_phase_1179_, lean_object* v_x_1180_){
_start:
{
uint8_t v_phase_boxed_1181_; lean_object* v_res_1182_; 
v_phase_boxed_1181_ = lean_unbox(v_phase_1179_);
v_res_1182_ = l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17(v_phase_boxed_1181_, v_x_1180_);
return v_res_1182_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__0(uint8_t v_phase_1183_, lean_object* v_left_1184_, lean_object* v_right_1185_){
_start:
{
lean_object* v___x_1186_; 
v___x_1186_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16(v_phase_1183_, v_left_1184_, v_right_1185_);
return v___x_1186_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__0___boxed(lean_object* v_phase_1187_, lean_object* v_left_1188_, lean_object* v_right_1189_){
_start:
{
uint8_t v_phase_boxed_1190_; lean_object* v_res_1191_; 
v_phase_boxed_1190_ = lean_unbox(v_phase_1187_);
v_res_1191_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__0(v_phase_boxed_1190_, v_left_1188_, v_right_1189_);
return v_res_1191_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__1___boxed(lean_object* v_phase_1192_, lean_object* v___x_1193_, lean_object* v_xs_1194_, lean_object* v_left_1195_){
_start:
{
uint8_t v_phase_boxed_1196_; lean_object* v_res_1197_; 
v_phase_boxed_1196_ = lean_unbox(v_phase_1192_);
v_res_1197_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__1(v_phase_boxed_1196_, v___x_1193_, v_xs_1194_, v_left_1195_);
lean_dec(v_xs_1194_);
return v_res_1197_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22(uint8_t v_phase_1198_, lean_object* v_xs_1199_){
_start:
{
lean_object* v___x_1200_; lean_object* v___x_1201_; uint8_t v___x_1202_; 
v___x_1200_ = l_List_lengthTR___redArg(v_xs_1199_);
v___x_1201_ = lean_unsigned_to_nat(2u);
v___x_1202_ = lean_nat_dec_lt(v___x_1200_, v___x_1201_);
if (v___x_1202_ == 0)
{
lean_object* v___x_1203_; lean_object* v___x_1204_; lean_object* v___x_1205_; lean_object* v___f_1206_; lean_object* v___x_1207_; lean_object* v___x_1208_; lean_object* v___x_1209_; lean_object* v___x_1210_; 
v___x_1203_ = lean_unsigned_to_nat(1u);
v___x_1204_ = lean_nat_shiftr(v___x_1200_, v___x_1203_);
lean_dec(v___x_1200_);
v___x_1205_ = lean_box(v_phase_1198_);
lean_inc_n(v_xs_1199_, 2);
lean_inc(v___x_1204_);
v___f_1206_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__1___boxed), 4, 3);
lean_closure_set(v___f_1206_, 0, v___x_1205_);
lean_closure_set(v___f_1206_, 1, v___x_1204_);
lean_closure_set(v___f_1206_, 2, v_xs_1199_);
v___x_1207_ = ((lean_object*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___closed__0));
v___x_1208_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_xs_1199_, v_xs_1199_, v___x_1204_, v___x_1207_);
lean_dec(v_xs_1199_);
v___x_1209_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22(v_phase_1198_, v___x_1208_);
v___x_1210_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1209_, v___f_1206_);
return v___x_1210_;
}
else
{
lean_object* v___x_1211_; 
lean_dec(v___x_1200_);
v___x_1211_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_xs_1199_);
return v___x_1211_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__1(uint8_t v_phase_1212_, lean_object* v___x_1213_, lean_object* v_xs_1214_, lean_object* v_left_1215_){
_start:
{
lean_object* v___x_1216_; lean_object* v___f_1217_; lean_object* v___x_1218_; lean_object* v___x_1219_; lean_object* v___x_1220_; 
v___x_1216_ = lean_box(v_phase_1212_);
v___f_1217_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__0___boxed), 3, 2);
lean_closure_set(v___f_1217_, 0, v___x_1216_);
lean_closure_set(v___f_1217_, 1, v_left_1215_);
v___x_1218_ = l_List_drop___redArg(v___x_1213_, v_xs_1214_);
v___x_1219_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22(v_phase_1212_, v___x_1218_);
v___x_1220_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1219_, v___f_1217_);
return v___x_1220_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___boxed(lean_object* v_phase_1221_, lean_object* v_xs_1222_){
_start:
{
uint8_t v_phase_boxed_1223_; lean_object* v_res_1224_; 
v_phase_boxed_1223_ = lean_unbox(v_phase_1221_);
v_res_1224_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22(v_phase_boxed_1223_, v_xs_1222_);
return v_res_1224_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___lam__1___boxed(lean_object* v_phase_1225_, lean_object* v_x_1226_, lean_object* v_tail_1227_, lean_object* v___f_1228_, lean_object* v_x_1229_, lean_object* v_smaller_1230_){
_start:
{
uint8_t v_phase_boxed_1231_; uint8_t v_smaller_boxed_1232_; lean_object* v_res_1233_; 
v_phase_boxed_1231_ = lean_unbox(v_phase_1225_);
v_smaller_boxed_1232_ = lean_unbox(v_smaller_1230_);
v_res_1233_ = l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___lam__1(v_phase_boxed_1231_, v_x_1226_, v_tail_1227_, v___f_1228_, v_x_1229_, v_smaller_boxed_1232_);
return v_res_1233_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28(uint8_t v_phase_1234_, lean_object* v_x_1235_, lean_object* v_x_1236_){
_start:
{
if (lean_obj_tag(v_x_1236_) == 0)
{
lean_object* v___x_1237_; lean_object* v___x_1238_; 
v___x_1237_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1237_, 0, v_x_1235_);
lean_ctor_set(v___x_1237_, 1, v_x_1236_);
v___x_1238_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_1237_);
return v___x_1238_;
}
else
{
lean_object* v_head_1239_; lean_object* v_tail_1240_; lean_object* v___f_1241_; lean_object* v___x_1242_; lean_object* v___f_1243_; uint8_t v___x_1244_; lean_object* v___x_1245_; lean_object* v___x_1246_; 
v_head_1239_ = lean_ctor_get(v_x_1236_, 0);
lean_inc_n(v_head_1239_, 2);
v_tail_1240_ = lean_ctor_get(v_x_1236_, 1);
lean_inc(v_tail_1240_);
v___f_1241_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0), 2, 1);
lean_closure_set(v___f_1241_, 0, v_head_1239_);
v___x_1242_ = lean_box(v_phase_1234_);
lean_inc(v_x_1235_);
v___f_1243_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___lam__1___boxed), 6, 5);
lean_closure_set(v___f_1243_, 0, v___x_1242_);
lean_closure_set(v___f_1243_, 1, v_x_1235_);
lean_closure_set(v___f_1243_, 2, v_tail_1240_);
lean_closure_set(v___f_1243_, 3, v___f_1241_);
lean_closure_set(v___f_1243_, 4, v_x_1236_);
v___x_1244_ = 1;
v___x_1245_ = l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__2(v_phase_1234_, v___x_1244_, v_x_1235_, v_head_1239_);
lean_dec(v_head_1239_);
lean_dec(v_x_1235_);
v___x_1246_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1245_, v___f_1243_);
return v___x_1246_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___lam__1(uint8_t v_phase_1247_, lean_object* v_x_1248_, lean_object* v_tail_1249_, lean_object* v___f_1250_, lean_object* v_x_1251_, uint8_t v_smaller_1252_){
_start:
{
if (v_smaller_1252_ == 0)
{
lean_object* v___x_1253_; lean_object* v___x_1254_; 
lean_dec(v_x_1251_);
v___x_1253_ = l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28(v_phase_1247_, v_x_1248_, v_tail_1249_);
v___x_1254_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1253_, v___f_1250_);
return v___x_1254_;
}
else
{
lean_object* v___x_1255_; lean_object* v___x_1256_; 
lean_dec_ref(v___f_1250_);
lean_dec(v_tail_1249_);
v___x_1255_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1255_, 0, v_x_1248_);
lean_ctor_set(v___x_1255_, 1, v_x_1251_);
v___x_1256_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_1255_);
return v___x_1256_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___boxed(lean_object* v_phase_1257_, lean_object* v_x_1258_, lean_object* v_x_1259_){
_start:
{
uint8_t v_phase_boxed_1260_; lean_object* v_res_1261_; 
v_phase_boxed_1260_ = lean_unbox(v_phase_1257_);
v_res_1261_ = l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28(v_phase_boxed_1260_, v_x_1258_, v_x_1259_);
return v_res_1261_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___lam__0(uint8_t v_phase_1262_, lean_object* v_head_1263_, lean_object* v_rest_1264_){
_start:
{
lean_object* v___x_1265_; 
v___x_1265_ = l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28(v_phase_1262_, v_head_1263_, v_rest_1264_);
return v___x_1265_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___lam__0___boxed(lean_object* v_phase_1266_, lean_object* v_head_1267_, lean_object* v_rest_1268_){
_start:
{
uint8_t v_phase_boxed_1269_; lean_object* v_res_1270_; 
v_phase_boxed_1269_ = lean_unbox(v_phase_1266_);
v_res_1270_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___lam__0(v_phase_boxed_1269_, v_head_1267_, v_rest_1268_);
return v_res_1270_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23(uint8_t v_phase_1271_, lean_object* v_x_1272_){
_start:
{
if (lean_obj_tag(v_x_1272_) == 0)
{
lean_object* v___x_1273_; 
v___x_1273_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_1272_);
return v___x_1273_;
}
else
{
lean_object* v_head_1274_; lean_object* v_tail_1275_; lean_object* v___x_1276_; lean_object* v___f_1277_; lean_object* v___x_1278_; lean_object* v___x_1279_; 
v_head_1274_ = lean_ctor_get(v_x_1272_, 0);
lean_inc(v_head_1274_);
v_tail_1275_ = lean_ctor_get(v_x_1272_, 1);
lean_inc(v_tail_1275_);
lean_dec_ref_known(v_x_1272_, 2);
v___x_1276_ = lean_box(v_phase_1271_);
v___f_1277_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___lam__0___boxed), 3, 2);
lean_closure_set(v___f_1277_, 0, v___x_1276_);
lean_closure_set(v___f_1277_, 1, v_head_1274_);
v___x_1278_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23(v_phase_1271_, v_tail_1275_);
v___x_1279_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1278_, v___f_1277_);
return v___x_1279_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___boxed(lean_object* v_phase_1280_, lean_object* v_x_1281_){
_start:
{
uint8_t v_phase_boxed_1282_; lean_object* v_res_1283_; 
v_phase_boxed_1282_ = lean_unbox(v_phase_1280_);
v_res_1283_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23(v_phase_boxed_1282_, v_x_1281_);
return v_res_1283_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___lam__1___boxed(lean_object* v_phase_1284_, lean_object* v___x_1285_, lean_object* v_xs_1286_, lean_object* v_threshold_1287_, lean_object* v_left_1288_){
_start:
{
uint8_t v_phase_boxed_1289_; lean_object* v_res_1290_; 
v_phase_boxed_1289_ = lean_unbox(v_phase_1284_);
v_res_1290_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___lam__1(v_phase_boxed_1289_, v___x_1285_, v_xs_1286_, v_threshold_1287_, v_left_1288_);
lean_dec(v_xs_1286_);
return v_res_1290_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24(uint8_t v_phase_1291_, lean_object* v_threshold_1292_, lean_object* v_xs_1293_){
_start:
{
lean_object* v___x_1294_; lean_object* v___y_1296_; lean_object* v___x_1307_; uint8_t v___x_1308_; 
v___x_1294_ = l_List_lengthTR___redArg(v_xs_1293_);
v___x_1307_ = lean_unsigned_to_nat(1u);
v___x_1308_ = lean_nat_dec_le(v___x_1307_, v_threshold_1292_);
if (v___x_1308_ == 0)
{
v___y_1296_ = v___x_1307_;
goto v___jp_1295_;
}
else
{
lean_inc(v_threshold_1292_);
v___y_1296_ = v_threshold_1292_;
goto v___jp_1295_;
}
v___jp_1295_:
{
uint8_t v___x_1297_; 
v___x_1297_ = lean_nat_dec_le(v___x_1294_, v___y_1296_);
lean_dec(v___y_1296_);
if (v___x_1297_ == 0)
{
lean_object* v___x_1298_; lean_object* v___x_1299_; lean_object* v___x_1300_; lean_object* v___f_1301_; lean_object* v___x_1302_; lean_object* v___x_1303_; lean_object* v___x_1304_; lean_object* v___x_1305_; 
v___x_1298_ = lean_unsigned_to_nat(1u);
v___x_1299_ = lean_nat_shiftr(v___x_1294_, v___x_1298_);
lean_dec(v___x_1294_);
v___x_1300_ = lean_box(v_phase_1291_);
lean_inc(v_threshold_1292_);
lean_inc_n(v_xs_1293_, 2);
lean_inc(v___x_1299_);
v___f_1301_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___lam__1___boxed), 5, 4);
lean_closure_set(v___f_1301_, 0, v___x_1300_);
lean_closure_set(v___f_1301_, 1, v___x_1299_);
lean_closure_set(v___f_1301_, 2, v_xs_1293_);
lean_closure_set(v___f_1301_, 3, v_threshold_1292_);
v___x_1302_ = ((lean_object*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___closed__0));
v___x_1303_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_xs_1293_, v_xs_1293_, v___x_1299_, v___x_1302_);
lean_dec(v_xs_1293_);
v___x_1304_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24(v_phase_1291_, v_threshold_1292_, v___x_1303_);
v___x_1305_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1304_, v___f_1301_);
return v___x_1305_;
}
else
{
lean_object* v___x_1306_; 
lean_dec(v___x_1294_);
lean_dec(v_threshold_1292_);
v___x_1306_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23(v_phase_1291_, v_xs_1293_);
return v___x_1306_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___lam__1(uint8_t v_phase_1309_, lean_object* v___x_1310_, lean_object* v_xs_1311_, lean_object* v_threshold_1312_, lean_object* v_left_1313_){
_start:
{
lean_object* v___x_1314_; lean_object* v___f_1315_; lean_object* v___x_1316_; lean_object* v___x_1317_; lean_object* v___x_1318_; 
v___x_1314_ = lean_box(v_phase_1309_);
v___f_1315_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__0___boxed), 3, 2);
lean_closure_set(v___f_1315_, 0, v___x_1314_);
lean_closure_set(v___f_1315_, 1, v_left_1313_);
v___x_1316_ = l_List_drop___redArg(v___x_1310_, v_xs_1311_);
v___x_1317_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24(v_phase_1309_, v_threshold_1312_, v___x_1316_);
v___x_1318_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1317_, v___f_1315_);
return v___x_1318_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___boxed(lean_object* v_phase_1319_, lean_object* v_threshold_1320_, lean_object* v_xs_1321_){
_start:
{
uint8_t v_phase_boxed_1322_; lean_object* v_res_1323_; 
v_phase_boxed_1322_ = lean_unbox(v_phase_1319_);
v_res_1323_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24(v_phase_boxed_1322_, v_threshold_1320_, v_xs_1321_);
return v_res_1323_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15(uint8_t v_phase_1324_, lean_object* v_x_1325_, lean_object* v_x_1326_){
_start:
{
switch(lean_obj_tag(v_x_1325_))
{
case 0:
{
lean_object* v___x_1327_; 
v___x_1327_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22(v_phase_1324_, v_x_1326_);
return v___x_1327_;
}
case 1:
{
lean_object* v___x_1328_; 
v___x_1328_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23(v_phase_1324_, v_x_1326_);
return v___x_1328_;
}
default: 
{
lean_object* v_threshold_1329_; lean_object* v___x_1330_; 
v_threshold_1329_ = lean_ctor_get(v_x_1325_, 0);
lean_inc(v_threshold_1329_);
lean_dec_ref_known(v_x_1325_, 1);
v___x_1330_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24(v_phase_1324_, v_threshold_1329_, v_x_1326_);
return v___x_1330_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15___boxed(lean_object* v_phase_1331_, lean_object* v_x_1332_, lean_object* v_x_1333_){
_start:
{
uint8_t v_phase_boxed_1334_; lean_object* v_res_1335_; 
v_phase_boxed_1334_ = lean_unbox(v_phase_1331_);
v_res_1335_ = l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15(v_phase_boxed_1334_, v_x_1332_, v_x_1333_);
return v_res_1335_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__1___boxed(lean_object* v_phase_1336_, lean_object* v___x_1337_, lean_object* v_x_1338_, lean_object* v_right_1339_, lean_object* v_ls_1340_){
_start:
{
uint8_t v_phase_boxed_1341_; lean_object* v_res_1342_; 
v_phase_boxed_1341_ = lean_unbox(v_phase_1336_);
v_res_1342_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__1(v_phase_boxed_1341_, v___x_1337_, v_x_1338_, v_right_1339_, v_ls_1340_);
lean_dec(v_x_1338_);
return v_res_1342_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__2(uint8_t v_phase_1343_, lean_object* v_fallback_1344_, lean_object* v_x_1345_, uint8_t v_sorted_1346_){
_start:
{
if (v_sorted_1346_ == 0)
{
lean_object* v___x_1347_; 
v___x_1347_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7(v_phase_1343_, v_fallback_1344_, v_x_1345_);
return v___x_1347_;
}
else
{
lean_object* v___x_1348_; 
lean_dec_ref(v_fallback_1344_);
v___x_1348_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_1345_);
return v___x_1348_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__2___boxed(lean_object* v_phase_1349_, lean_object* v_fallback_1350_, lean_object* v_x_1351_, lean_object* v_sorted_1352_){
_start:
{
uint8_t v_phase_boxed_1353_; uint8_t v_sorted_boxed_1354_; lean_object* v_res_1355_; 
v_phase_boxed_1353_ = lean_unbox(v_phase_1349_);
v_sorted_boxed_1354_ = lean_unbox(v_sorted_1352_);
v_res_1355_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__2(v_phase_boxed_1353_, v_fallback_1350_, v_x_1351_, v_sorted_boxed_1354_);
return v_res_1355_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7(uint8_t v_phase_1356_, lean_object* v_x_1357_, lean_object* v_x_1358_){
_start:
{
switch(lean_obj_tag(v_x_1357_))
{
case 0:
{
lean_object* v_component_1359_; lean_object* v___x_1360_; 
v_component_1359_ = lean_ctor_get(v_x_1357_, 0);
lean_inc(v_component_1359_);
lean_dec_ref_known(v_x_1357_, 1);
v___x_1360_ = l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15(v_phase_1356_, v_component_1359_, v_x_1358_);
return v___x_1360_;
}
case 1:
{
lean_object* v_cut_1361_; lean_object* v_left_1362_; lean_object* v_right_1363_; lean_object* v___x_1364_; lean_object* v___x_1365_; lean_object* v___x_1366_; lean_object* v___f_1367_; lean_object* v___x_1368_; lean_object* v___x_1369_; lean_object* v___x_1370_; lean_object* v___x_1371_; 
v_cut_1361_ = lean_ctor_get(v_x_1357_, 0);
lean_inc_ref(v_cut_1361_);
v_left_1362_ = lean_ctor_get(v_x_1357_, 1);
lean_inc_ref(v_left_1362_);
v_right_1363_ = lean_ctor_get(v_x_1357_, 2);
lean_inc_ref(v_right_1363_);
lean_dec_ref_known(v_x_1357_, 3);
v___x_1364_ = l_List_lengthTR___redArg(v_x_1358_);
v___x_1365_ = lp_leansort_LeanSort_CostedPlan_Cut_position(v_cut_1361_, v___x_1364_);
lean_dec(v___x_1364_);
lean_dec_ref(v_cut_1361_);
v___x_1366_ = lean_box(v_phase_1356_);
lean_inc_n(v_x_1358_, 2);
lean_inc(v___x_1365_);
v___f_1367_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__1___boxed), 5, 4);
lean_closure_set(v___f_1367_, 0, v___x_1366_);
lean_closure_set(v___f_1367_, 1, v___x_1365_);
lean_closure_set(v___f_1367_, 2, v_x_1358_);
lean_closure_set(v___f_1367_, 3, v_right_1363_);
v___x_1368_ = ((lean_object*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___closed__0));
v___x_1369_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_x_1358_, v_x_1358_, v___x_1365_, v___x_1368_);
lean_dec(v_x_1358_);
v___x_1370_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7(v_phase_1356_, v_left_1362_, v___x_1369_);
v___x_1371_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1370_, v___f_1367_);
return v___x_1371_;
}
default: 
{
lean_object* v_fallback_1372_; lean_object* v___x_1373_; lean_object* v___f_1374_; lean_object* v___x_1375_; lean_object* v___x_1376_; 
v_fallback_1372_ = lean_ctor_get(v_x_1357_, 0);
lean_inc_ref(v_fallback_1372_);
lean_dec_ref_known(v_x_1357_, 1);
v___x_1373_ = lean_box(v_phase_1356_);
lean_inc(v_x_1358_);
v___f_1374_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__2___boxed), 4, 3);
lean_closure_set(v___f_1374_, 0, v___x_1373_);
lean_closure_set(v___f_1374_, 1, v_fallback_1372_);
lean_closure_set(v___f_1374_, 2, v_x_1358_);
v___x_1375_ = l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17(v_phase_1356_, v_x_1358_);
v___x_1376_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1375_, v___f_1374_);
return v___x_1376_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__1(uint8_t v_phase_1377_, lean_object* v___x_1378_, lean_object* v_x_1379_, lean_object* v_right_1380_, lean_object* v_ls_1381_){
_start:
{
lean_object* v___x_1382_; lean_object* v___f_1383_; lean_object* v___x_1384_; lean_object* v___x_1385_; lean_object* v___x_1386_; 
v___x_1382_ = lean_box(v_phase_1377_);
v___f_1383_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___lam__0___boxed), 3, 2);
lean_closure_set(v___f_1383_, 0, v___x_1382_);
lean_closure_set(v___f_1383_, 1, v_ls_1381_);
v___x_1384_ = l_List_drop___redArg(v___x_1378_, v_x_1379_);
v___x_1385_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7(v_phase_1377_, v_right_1380_, v___x_1384_);
v___x_1386_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1385_, v___f_1383_);
return v___x_1386_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7___boxed(lean_object* v_phase_1387_, lean_object* v_x_1388_, lean_object* v_x_1389_){
_start:
{
uint8_t v_phase_boxed_1390_; lean_object* v_res_1391_; 
v_phase_boxed_1390_ = lean_unbox(v_phase_1387_);
v_res_1391_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7(v_phase_boxed_1390_, v_x_1388_, v_x_1389_);
return v_res_1391_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8___lam__0(uint8_t v_phase_1392_, lean_object* v_runs_1393_){
_start:
{
lean_object* v___x_1394_; lean_object* v___x_1395_; 
v___x_1394_ = lp_leansort_LeanSort_RunAdaptive_countPlan___redArg(v_runs_1393_);
v___x_1395_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19(v_phase_1392_, v___x_1394_);
return v___x_1395_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8___lam__0___boxed(lean_object* v_phase_1396_, lean_object* v_runs_1397_){
_start:
{
uint8_t v_phase_boxed_1398_; lean_object* v_res_1399_; 
v_phase_boxed_1398_ = lean_unbox(v_phase_1396_);
v_res_1399_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8___lam__0(v_phase_boxed_1398_, v_runs_1397_);
return v_res_1399_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8(uint8_t v_phase_1400_, lean_object* v_xs_1401_){
_start:
{
lean_object* v___x_1402_; lean_object* v___f_1403_; lean_object* v___x_1404_; lean_object* v___x_1405_; 
v___x_1402_ = lean_box(v_phase_1400_);
v___f_1403_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8___lam__0___boxed), 2, 1);
lean_closure_set(v___f_1403_, 0, v___x_1402_);
v___x_1404_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20(v_phase_1400_, v_xs_1401_);
v___x_1405_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1404_, v___f_1403_);
return v___x_1405_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8___boxed(lean_object* v_phase_1406_, lean_object* v_xs_1407_){
_start:
{
uint8_t v_phase_boxed_1408_; lean_object* v_res_1409_; 
v_phase_boxed_1408_ = lean_unbox(v_phase_1406_);
v_res_1409_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8(v_phase_boxed_1408_, v_xs_1407_);
return v_res_1409_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3(uint8_t v_phase_1410_, lean_object* v_x_1411_, lean_object* v_x_1412_){
_start:
{
switch(lean_obj_tag(v_x_1411_))
{
case 0:
{
lean_object* v_schema_1413_; lean_object* v___x_1414_; 
v_schema_1413_ = lean_ctor_get(v_x_1411_, 0);
lean_inc_ref(v_schema_1413_);
lean_dec_ref_known(v_x_1411_, 1);
v___x_1414_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__7(v_phase_1410_, v_schema_1413_, v_x_1412_);
return v___x_1414_;
}
case 1:
{
lean_object* v___x_1415_; 
v___x_1415_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__8(v_phase_1410_, v_x_1412_);
return v___x_1415_;
}
default: 
{
lean_object* v___x_1416_; 
v___x_1416_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3_spec__9(v_phase_1410_, v_x_1412_);
return v___x_1416_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3___boxed(lean_object* v_phase_1417_, lean_object* v_x_1418_, lean_object* v_x_1419_){
_start:
{
uint8_t v_phase_boxed_1420_; lean_object* v_res_1421_; 
v_phase_boxed_1420_ = lean_unbox(v_phase_1417_);
v_res_1421_ = l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3(v_phase_boxed_1420_, v_x_1418_, v_x_1419_);
return v_res_1421_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_kernelProfile(lean_object* v_id_1434_, lean_object* v_xs_1435_, lean_object* v_expected_1436_){
_start:
{
lean_object* v_s_1441_; lean_object* v_result_1442_; lean_object* v_ret_1443_; uint8_t v___x_1444_; lean_object* v_checks_1445_; uint8_t v___x_1446_; lean_object* v_sorting_1447_; uint8_t v___y_1449_; lean_object* v___y_1450_; uint8_t v___y_1515_; uint8_t v___x_1544_; 
v_s_1441_ = l_LeanSort_LearnedSelection_candidate(v_id_1434_);
lean_inc_n(v_xs_1435_, 3);
lean_inc_n(v_s_1441_, 3);
v_result_1442_ = l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0(v_s_1441_, v_xs_1435_);
v_ret_1443_ = lean_ctor_get(v_result_1442_, 0);
lean_inc(v_ret_1443_);
v___x_1444_ = 0;
v_checks_1445_ = l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3(v___x_1444_, v_s_1441_, v_xs_1435_);
v___x_1446_ = 1;
v_sorting_1447_ = l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3(v___x_1446_, v_s_1441_, v_xs_1435_);
v___x_1544_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v_ret_1443_, v_expected_1436_);
lean_dec(v_ret_1443_);
if (v___x_1544_ == 0)
{
v___y_1515_ = v___x_1544_;
goto v___jp_1514_;
}
else
{
lean_object* v_ret_1545_; uint8_t v___x_1546_; 
v_ret_1545_ = lean_ctor_get(v_checks_1445_, 0);
lean_inc(v_ret_1545_);
v___x_1546_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v_ret_1545_, v_expected_1436_);
lean_dec(v_ret_1545_);
v___y_1515_ = v___x_1546_;
goto v___jp_1514_;
}
v___jp_1438_:
{
lean_object* v___x_1439_; lean_object* v___x_1440_; 
v___x_1439_ = ((lean_object*)(l_BudgetWorker_kernelProfile___closed__1));
v___x_1440_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1440_, 0, v___x_1439_);
return v___x_1440_;
}
v___jp_1448_:
{
lean_object* v_time_1451_; lean_object* v___x_1453_; uint8_t v_isShared_1454_; uint8_t v_isSharedCheck_1512_; 
v_time_1451_ = lean_ctor_get(v_result_1442_, 1);
v_isSharedCheck_1512_ = !lean_is_exclusive(v_result_1442_);
if (v_isSharedCheck_1512_ == 0)
{
lean_object* v_unused_1513_; 
v_unused_1513_ = lean_ctor_get(v_result_1442_, 0);
lean_dec(v_unused_1513_);
v___x_1453_ = v_result_1442_;
v_isShared_1454_ = v_isSharedCheck_1512_;
goto v_resetjp_1452_;
}
else
{
lean_inc(v_time_1451_);
lean_dec(v_result_1442_);
v___x_1453_ = lean_box(0);
v_isShared_1454_ = v_isSharedCheck_1512_;
goto v_resetjp_1452_;
}
v_resetjp_1452_:
{
lean_object* v_time_1455_; lean_object* v___x_1457_; uint8_t v_isShared_1458_; uint8_t v_isSharedCheck_1510_; 
v_time_1455_ = lean_ctor_get(v_checks_1445_, 1);
v_isSharedCheck_1510_ = !lean_is_exclusive(v_checks_1445_);
if (v_isSharedCheck_1510_ == 0)
{
lean_object* v_unused_1511_; 
v_unused_1511_ = lean_ctor_get(v_checks_1445_, 0);
lean_dec(v_unused_1511_);
v___x_1457_ = v_checks_1445_;
v_isShared_1458_ = v_isSharedCheck_1510_;
goto v_resetjp_1456_;
}
else
{
lean_inc(v_time_1455_);
lean_dec(v_checks_1445_);
v___x_1457_ = lean_box(0);
v_isShared_1458_ = v_isSharedCheck_1510_;
goto v_resetjp_1456_;
}
v_resetjp_1456_:
{
lean_object* v_time_1459_; lean_object* v___x_1461_; uint8_t v_isShared_1462_; uint8_t v_isSharedCheck_1508_; 
v_time_1459_ = lean_ctor_get(v_sorting_1447_, 1);
v_isSharedCheck_1508_ = !lean_is_exclusive(v_sorting_1447_);
if (v_isSharedCheck_1508_ == 0)
{
lean_object* v_unused_1509_; 
v_unused_1509_ = lean_ctor_get(v_sorting_1447_, 0);
lean_dec(v_unused_1509_);
v___x_1461_ = v_sorting_1447_;
v_isShared_1462_ = v_isSharedCheck_1508_;
goto v_resetjp_1460_;
}
else
{
lean_inc(v_time_1459_);
lean_dec(v_sorting_1447_);
v___x_1461_ = lean_box(0);
v_isShared_1462_ = v_isSharedCheck_1508_;
goto v_resetjp_1460_;
}
v_resetjp_1460_:
{
lean_object* v___x_1463_; lean_object* v___x_1464_; lean_object* v___x_1465_; lean_object* v___x_1467_; 
v___x_1463_ = ((lean_object*)(l_BudgetWorker_decodePolicy___closed__9));
lean_inc(v_id_1434_);
v___x_1464_ = l_Lean_JsonNumber_fromNat(v_id_1434_);
v___x_1465_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1465_, 0, v___x_1464_);
if (v_isShared_1462_ == 0)
{
lean_ctor_set(v___x_1461_, 1, v___x_1465_);
lean_ctor_set(v___x_1461_, 0, v___x_1463_);
v___x_1467_ = v___x_1461_;
goto v_reusejp_1466_;
}
else
{
lean_object* v_reuseFailAlloc_1507_; 
v_reuseFailAlloc_1507_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1507_, 0, v___x_1463_);
lean_ctor_set(v_reuseFailAlloc_1507_, 1, v___x_1465_);
v___x_1467_ = v_reuseFailAlloc_1507_;
goto v_reusejp_1466_;
}
v_reusejp_1466_:
{
lean_object* v___x_1468_; lean_object* v___x_1469_; lean_object* v___x_1470_; lean_object* v___x_1472_; 
v___x_1468_ = ((lean_object*)(l_BudgetWorker_kernelProfile___closed__2));
v___x_1469_ = l_Lean_JsonNumber_fromNat(v_time_1451_);
v___x_1470_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1470_, 0, v___x_1469_);
if (v_isShared_1458_ == 0)
{
lean_ctor_set(v___x_1457_, 1, v___x_1470_);
lean_ctor_set(v___x_1457_, 0, v___x_1468_);
v___x_1472_ = v___x_1457_;
goto v_reusejp_1471_;
}
else
{
lean_object* v_reuseFailAlloc_1506_; 
v_reuseFailAlloc_1506_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1506_, 0, v___x_1468_);
lean_ctor_set(v_reuseFailAlloc_1506_, 1, v___x_1470_);
v___x_1472_ = v_reuseFailAlloc_1506_;
goto v_reusejp_1471_;
}
v_reusejp_1471_:
{
lean_object* v___x_1473_; lean_object* v___x_1474_; lean_object* v___x_1475_; lean_object* v___x_1477_; 
v___x_1473_ = ((lean_object*)(l_BudgetWorker_kernelProfile___closed__3));
v___x_1474_ = l_Lean_JsonNumber_fromNat(v_time_1455_);
v___x_1475_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1475_, 0, v___x_1474_);
if (v_isShared_1454_ == 0)
{
lean_ctor_set(v___x_1453_, 1, v___x_1475_);
lean_ctor_set(v___x_1453_, 0, v___x_1473_);
v___x_1477_ = v___x_1453_;
goto v_reusejp_1476_;
}
else
{
lean_object* v_reuseFailAlloc_1505_; 
v_reuseFailAlloc_1505_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1505_, 0, v___x_1473_);
lean_ctor_set(v_reuseFailAlloc_1505_, 1, v___x_1475_);
v___x_1477_ = v_reuseFailAlloc_1505_;
goto v_reusejp_1476_;
}
v_reusejp_1476_:
{
lean_object* v___x_1478_; lean_object* v___x_1479_; lean_object* v___x_1480_; lean_object* v___x_1481_; lean_object* v___x_1482_; lean_object* v___x_1483_; lean_object* v___x_1484_; lean_object* v___x_1485_; lean_object* v___x_1486_; lean_object* v___x_1487_; lean_object* v___x_1488_; lean_object* v___x_1489_; lean_object* v___x_1490_; lean_object* v___x_1491_; lean_object* v___x_1492_; lean_object* v___x_1493_; lean_object* v___x_1494_; lean_object* v___x_1495_; lean_object* v___x_1496_; lean_object* v___x_1497_; lean_object* v___x_1498_; lean_object* v___x_1499_; lean_object* v___x_1500_; lean_object* v___x_1501_; lean_object* v___x_1502_; lean_object* v___x_1503_; lean_object* v___x_1504_; 
v___x_1478_ = ((lean_object*)(l_BudgetWorker_kernelProfile___closed__4));
v___x_1479_ = l_Lean_JsonNumber_fromNat(v_time_1459_);
v___x_1480_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1480_, 0, v___x_1479_);
v___x_1481_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1481_, 0, v___x_1478_);
lean_ctor_set(v___x_1481_, 1, v___x_1480_);
v___x_1482_ = ((lean_object*)(l_BudgetWorker_kernelProfile___closed__5));
v___x_1483_ = lean_nat_to_int(v_id_1434_);
v___x_1484_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1484_, 0, v___x_1483_);
v___x_1485_ = l_LeanSort_LearnedSelection_kernelBound___at___00BudgetWorker_kernelProfile_spec__2(v___x_1484_, v_xs_1435_);
lean_dec_ref_known(v___x_1484_, 1);
v___x_1486_ = l_Lean_JsonNumber_fromNat(v___x_1485_);
v___x_1487_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1487_, 0, v___x_1486_);
v___x_1488_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1488_, 0, v___x_1482_);
lean_ctor_set(v___x_1488_, 1, v___x_1487_);
v___x_1489_ = ((lean_object*)(l_BudgetWorker_kernelProfile___closed__6));
v___x_1490_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_1490_, 0, v___y_1449_);
v___x_1491_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1491_, 0, v___x_1489_);
lean_ctor_set(v___x_1491_, 1, v___x_1490_);
v___x_1492_ = ((lean_object*)(l_BudgetWorker_kernelProfile___closed__7));
v___x_1493_ = l_Lean_Option_toJson___at___00Lean_Json_toStructured_x3f___at___00Lean_Server_FileWorker_sendServerRequest___at___00Lean_Server_FileWorker_runRefreshTasks_spec__0_spec__1_spec__3(v___y_1450_);
v___x_1494_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1494_, 0, v___x_1492_);
lean_ctor_set(v___x_1494_, 1, v___x_1493_);
v___x_1495_ = lean_box(0);
v___x_1496_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1496_, 0, v___x_1494_);
lean_ctor_set(v___x_1496_, 1, v___x_1495_);
v___x_1497_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1497_, 0, v___x_1491_);
lean_ctor_set(v___x_1497_, 1, v___x_1496_);
v___x_1498_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1498_, 0, v___x_1488_);
lean_ctor_set(v___x_1498_, 1, v___x_1497_);
v___x_1499_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1499_, 0, v___x_1481_);
lean_ctor_set(v___x_1499_, 1, v___x_1498_);
v___x_1500_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1500_, 0, v___x_1477_);
lean_ctor_set(v___x_1500_, 1, v___x_1499_);
v___x_1501_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1501_, 0, v___x_1472_);
lean_ctor_set(v___x_1501_, 1, v___x_1500_);
v___x_1502_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1502_, 0, v___x_1467_);
lean_ctor_set(v___x_1502_, 1, v___x_1501_);
v___x_1503_ = l_Lean_Json_mkObj(v___x_1502_);
lean_dec_ref_known(v___x_1502_, 2);
v___x_1504_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1504_, 0, v___x_1503_);
return v___x_1504_;
}
}
}
}
}
}
}
v___jp_1514_:
{
if (v___y_1515_ == 0)
{
lean_dec_ref(v_sorting_1447_);
lean_dec_ref(v_checks_1445_);
lean_dec_ref(v_result_1442_);
lean_dec(v_s_1441_);
lean_dec(v_xs_1435_);
lean_dec(v_id_1434_);
goto v___jp_1438_;
}
else
{
lean_object* v_ret_1516_; lean_object* v_time_1517_; uint8_t v___x_1518_; 
v_ret_1516_ = lean_ctor_get(v_sorting_1447_, 0);
lean_inc(v_ret_1516_);
v_time_1517_ = lean_ctor_get(v_sorting_1447_, 1);
lean_inc(v_time_1517_);
v___x_1518_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v_ret_1516_, v_expected_1436_);
lean_dec(v_ret_1516_);
if (v___x_1518_ == 0)
{
lean_dec(v_time_1517_);
lean_dec_ref(v_sorting_1447_);
lean_dec_ref(v_checks_1445_);
lean_dec_ref(v_result_1442_);
lean_dec(v_s_1441_);
lean_dec(v_xs_1435_);
lean_dec(v_id_1434_);
goto v___jp_1438_;
}
else
{
lean_object* v_time_1519_; lean_object* v_time_1520_; lean_object* v___x_1521_; uint8_t v___x_1522_; 
v_time_1519_ = lean_ctor_get(v_checks_1445_, 1);
lean_inc(v_time_1519_);
v_time_1520_ = lean_ctor_get(v_result_1442_, 1);
lean_inc(v_time_1520_);
v___x_1521_ = lean_nat_add(v_time_1519_, v_time_1517_);
lean_dec(v_time_1517_);
lean_dec(v_time_1519_);
v___x_1522_ = lean_nat_dec_eq(v___x_1521_, v_time_1520_);
lean_dec(v___x_1521_);
if (v___x_1522_ == 0)
{
lean_dec(v_time_1520_);
lean_dec_ref(v_sorting_1447_);
lean_dec_ref(v_checks_1445_);
lean_dec_ref(v_result_1442_);
lean_dec(v_s_1441_);
lean_dec(v_xs_1435_);
lean_dec(v_id_1434_);
goto v___jp_1438_;
}
else
{
lean_object* v___x_1523_; lean_object* v___x_1524_; lean_object* v___x_1525_; uint8_t v___x_1526_; 
lean_inc(v_id_1434_);
v___x_1523_ = lean_nat_to_int(v_id_1434_);
v___x_1524_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1524_, 0, v___x_1523_);
lean_inc(v_xs_1435_);
v___x_1525_ = l_LeanSort_LearnedSelection_kernelBound___at___00BudgetWorker_kernelProfile_spec__2(v___x_1524_, v_xs_1435_);
lean_dec_ref_known(v___x_1524_, 1);
v___x_1526_ = lean_nat_dec_le(v_time_1520_, v___x_1525_);
lean_dec(v___x_1525_);
lean_dec(v_time_1520_);
if (v___x_1526_ == 0)
{
lean_dec_ref(v_sorting_1447_);
lean_dec_ref(v_checks_1445_);
lean_dec_ref(v_result_1442_);
lean_dec(v_s_1441_);
lean_dec(v_xs_1435_);
lean_dec(v_id_1434_);
goto v___jp_1438_;
}
else
{
if (lean_obj_tag(v_s_1441_) == 0)
{
lean_object* v_schema_1527_; lean_object* v___x_1529_; uint8_t v_isShared_1530_; uint8_t v_isSharedCheck_1541_; 
v_schema_1527_ = lean_ctor_get(v_s_1441_, 0);
v_isSharedCheck_1541_ = !lean_is_exclusive(v_s_1441_);
if (v_isSharedCheck_1541_ == 0)
{
v___x_1529_ = v_s_1441_;
v_isShared_1530_ = v_isSharedCheck_1541_;
goto v_resetjp_1528_;
}
else
{
lean_inc(v_schema_1527_);
lean_dec(v_s_1441_);
v___x_1529_ = lean_box(0);
v_isShared_1530_ = v_isSharedCheck_1541_;
goto v_resetjp_1528_;
}
v_resetjp_1528_:
{
uint8_t v___x_1531_; lean_object* v___x_1532_; lean_object* v___x_1533_; lean_object* v___x_1535_; 
lean_inc(v_xs_1435_);
v___x_1531_ = l_LeanSort_CostedPlan_Schema_readyCheck___at___00BudgetWorker_kernelProfile_spec__3(v_schema_1527_, v_xs_1435_);
v___x_1532_ = l_List_lengthTR___redArg(v_xs_1435_);
v___x_1533_ = lp_leansort_LeanSort_CostedPlan_Schema_readyUpper(v_schema_1527_, v___x_1532_);
lean_dec(v___x_1532_);
lean_dec_ref(v_schema_1527_);
lean_inc(v___x_1533_);
if (v_isShared_1530_ == 0)
{
lean_ctor_set_tag(v___x_1529_, 1);
lean_ctor_set(v___x_1529_, 0, v___x_1533_);
v___x_1535_ = v___x_1529_;
goto v_reusejp_1534_;
}
else
{
lean_object* v_reuseFailAlloc_1540_; 
v_reuseFailAlloc_1540_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1540_, 0, v___x_1533_);
v___x_1535_ = v_reuseFailAlloc_1540_;
goto v_reusejp_1534_;
}
v_reusejp_1534_:
{
if (v___x_1531_ == 0)
{
lean_dec(v___x_1533_);
v___y_1449_ = v___x_1531_;
v___y_1450_ = v___x_1535_;
goto v___jp_1448_;
}
else
{
lean_object* v_time_1536_; uint8_t v___x_1537_; 
v_time_1536_ = lean_ctor_get(v_result_1442_, 1);
lean_inc(v_time_1536_);
v___x_1537_ = lean_nat_dec_le(v_time_1536_, v___x_1533_);
lean_dec(v___x_1533_);
lean_dec(v_time_1536_);
if (v___x_1537_ == 0)
{
lean_object* v___x_1538_; lean_object* v___x_1539_; 
lean_dec_ref(v___x_1535_);
lean_dec_ref(v_sorting_1447_);
lean_dec_ref(v_checks_1445_);
lean_dec_ref(v_result_1442_);
lean_dec(v_xs_1435_);
lean_dec(v_id_1434_);
v___x_1538_ = ((lean_object*)(l_BudgetWorker_kernelProfile___closed__9));
v___x_1539_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1539_, 0, v___x_1538_);
return v___x_1539_;
}
else
{
v___y_1449_ = v___x_1531_;
v___y_1450_ = v___x_1535_;
goto v___jp_1448_;
}
}
}
}
}
else
{
uint8_t v___x_1542_; lean_object* v___x_1543_; 
lean_dec(v_s_1441_);
v___x_1542_ = 0;
v___x_1543_ = lean_box(0);
v___y_1449_ = v___x_1542_;
v___y_1450_ = v___x_1543_;
goto v___jp_1448_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_kernelProfile___boxed(lean_object* v_id_1547_, lean_object* v_xs_1548_, lean_object* v_expected_1549_, lean_object* v_a_1550_){
_start:
{
lean_object* v_res_1551_; 
v_res_1551_ = l_BudgetWorker_kernelProfile(v_id_1547_, v_xs_1548_, v_expected_1549_);
lean_dec(v_expected_1549_);
return v_res_1551_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0(lean_object* v_s_1552_, lean_object* v_xs_1553_){
_start:
{
lean_object* v___x_1554_; 
v___x_1554_ = l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00BudgetWorker_kernelProfile_spec__0_spec__0(v_s_1552_, v_xs_1553_);
return v___x_1554_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1(uint8_t v_phase_1555_, lean_object* v_s_1556_, lean_object* v_xs_1557_){
_start:
{
lean_object* v___x_1558_; 
v___x_1558_ = l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1_spec__3(v_phase_1555_, v_s_1556_, v_xs_1557_);
return v___x_1558_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1___boxed(lean_object* v_phase_1559_, lean_object* v_s_1560_, lean_object* v_xs_1561_){
_start:
{
uint8_t v_phase_boxed_1562_; lean_object* v_res_1563_; 
v_phase_boxed_1562_ = lean_unbox(v_phase_1559_);
v_res_1563_ = l_LeanSort_Direct_runPhase___at___00BudgetWorker_kernelProfile_spec__1(v_phase_boxed_1562_, v_s_1560_, v_xs_1561_);
return v_res_1563_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_readyCheck___at___00BudgetWorker_kernelProfile_spec__3_spec__7(lean_object* v_00_u03b2_1564_, lean_object* v_x_1565_){
_start:
{
lean_object* v___x_1566_; 
v___x_1566_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_readyCheck___at___00BudgetWorker_kernelProfile_spec__3_spec__7___redArg(v_x_1565_);
return v___x_1566_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_scan___at___00LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00BudgetWorker_kernelProfile_spec__2_spec__5_spec__12(lean_object* v_xs_1567_){
_start:
{
lean_object* v___x_1568_; 
v___x_1568_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_run___at___00LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0_spec__0_spec__1_spec__3_spec__7(v_xs_1567_);
return v___x_1568_;
}
}
LEAN_EXPORT lean_object* l_Lean_Option_toJson___at___00BudgetWorker_bench_spec__2(lean_object* v_x_1569_){
_start:
{
if (lean_obj_tag(v_x_1569_) == 0)
{
lean_object* v___x_1570_; 
v___x_1570_ = lean_box(0);
return v___x_1570_;
}
else
{
lean_object* v_val_1571_; lean_object* v___x_1573_; uint8_t v_isShared_1574_; uint8_t v_isSharedCheck_1579_; 
v_val_1571_ = lean_ctor_get(v_x_1569_, 0);
v_isSharedCheck_1579_ = !lean_is_exclusive(v_x_1569_);
if (v_isSharedCheck_1579_ == 0)
{
v___x_1573_ = v_x_1569_;
v_isShared_1574_ = v_isSharedCheck_1579_;
goto v_resetjp_1572_;
}
else
{
lean_inc(v_val_1571_);
lean_dec(v_x_1569_);
v___x_1573_ = lean_box(0);
v_isShared_1574_ = v_isSharedCheck_1579_;
goto v_resetjp_1572_;
}
v_resetjp_1572_:
{
lean_object* v___x_1575_; lean_object* v___x_1577_; 
v___x_1575_ = l_Lean_JsonNumber_fromInt(v_val_1571_);
if (v_isShared_1574_ == 0)
{
lean_ctor_set_tag(v___x_1573_, 2);
lean_ctor_set(v___x_1573_, 0, v___x_1575_);
v___x_1577_ = v___x_1573_;
goto v_reusejp_1576_;
}
else
{
lean_object* v_reuseFailAlloc_1578_; 
v_reuseFailAlloc_1578_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1578_, 0, v___x_1575_);
v___x_1577_ = v_reuseFailAlloc_1578_;
goto v_reusejp_1576_;
}
v_reusejp_1576_:
{
return v___x_1577_;
}
}
}
}
}
static lean_object* _init_l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__1(void){
_start:
{
lean_object* v___x_1581_; lean_object* v___x_1582_; 
v___x_1581_ = lean_unsigned_to_nat(1u);
v___x_1582_ = lean_nat_to_int(v___x_1581_);
return v___x_1582_;
}
}
static lean_object* _init_l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__2(void){
_start:
{
lean_object* v___x_1583_; lean_object* v___x_1584_; 
v___x_1583_ = lean_obj_once(&l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__1, &l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__1_once, _init_l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__1);
v___x_1584_ = lean_int_neg(v___x_1583_);
return v___x_1584_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg(lean_object* v_val_1585_, lean_object* v_val_1586_, lean_object* v_val_1587_, lean_object* v_a_1588_, lean_object* v_as_x27_1589_, lean_object* v_b_1590_){
_start:
{
if (lean_obj_tag(v_as_x27_1589_) == 0)
{
lean_object* v___x_1592_; 
v___x_1592_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1592_, 0, v_b_1590_);
return v___x_1592_;
}
else
{
lean_object* v_head_1593_; lean_object* v_tail_1594_; lean_object* v___x_1595_; 
v_head_1593_ = lean_ctor_get(v_as_x27_1589_, 0);
v_tail_1594_ = lean_ctor_get(v_as_x27_1589_, 1);
lean_inc(v_head_1593_);
v___x_1595_ = l_BudgetWorker_timedKernel(v_head_1593_, v_val_1585_, v_val_1586_, v_val_1587_, v_a_1588_);
if (lean_obj_tag(v___x_1595_) == 0)
{
lean_object* v_a_1596_; lean_object* v_fst_1597_; lean_object* v_snd_1598_; lean_object* v___x_1599_; lean_object* v___x_1600_; lean_object* v___x_1601_; lean_object* v___x_1602_; 
v_a_1596_ = lean_ctor_get(v___x_1595_, 0);
lean_inc(v_a_1596_);
lean_dec_ref_known(v___x_1595_, 1);
v_fst_1597_ = lean_ctor_get(v_a_1596_, 0);
lean_inc(v_fst_1597_);
v_snd_1598_ = lean_ctor_get(v_a_1596_, 1);
lean_inc(v_snd_1598_);
lean_dec(v_a_1596_);
v___x_1599_ = ((lean_object*)(l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__0));
lean_inc(v_head_1593_);
v___x_1600_ = l_Nat_reprFast(v_head_1593_);
v___x_1601_ = lean_obj_once(&l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__2, &l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__2_once, _init_l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__2);
v___x_1602_ = l_BudgetWorker_sampleEvent(v___x_1599_, v___x_1600_, v___x_1601_, v_fst_1597_, v_snd_1598_);
if (lean_obj_tag(v___x_1602_) == 0)
{
lean_object* v___x_1603_; 
lean_dec_ref_known(v___x_1602_, 1);
v___x_1603_ = lean_box(0);
v_as_x27_1589_ = v_tail_1594_;
v_b_1590_ = v___x_1603_;
goto _start;
}
else
{
return v___x_1602_;
}
}
else
{
lean_object* v_a_1605_; lean_object* v___x_1607_; uint8_t v_isShared_1608_; uint8_t v_isSharedCheck_1612_; 
v_a_1605_ = lean_ctor_get(v___x_1595_, 0);
v_isSharedCheck_1612_ = !lean_is_exclusive(v___x_1595_);
if (v_isSharedCheck_1612_ == 0)
{
v___x_1607_ = v___x_1595_;
v_isShared_1608_ = v_isSharedCheck_1612_;
goto v_resetjp_1606_;
}
else
{
lean_inc(v_a_1605_);
lean_dec(v___x_1595_);
v___x_1607_ = lean_box(0);
v_isShared_1608_ = v_isSharedCheck_1612_;
goto v_resetjp_1606_;
}
v_resetjp_1606_:
{
lean_object* v___x_1610_; 
if (v_isShared_1608_ == 0)
{
v___x_1610_ = v___x_1607_;
goto v_reusejp_1609_;
}
else
{
lean_object* v_reuseFailAlloc_1611_; 
v_reuseFailAlloc_1611_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1611_, 0, v_a_1605_);
v___x_1610_ = v_reuseFailAlloc_1611_;
goto v_reusejp_1609_;
}
v_reusejp_1609_:
{
return v___x_1610_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___boxed(lean_object* v_val_1613_, lean_object* v_val_1614_, lean_object* v_val_1615_, lean_object* v_a_1616_, lean_object* v_as_x27_1617_, lean_object* v_b_1618_, lean_object* v___y_1619_){
_start:
{
lean_object* v_res_1620_; 
v_res_1620_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg(v_val_1613_, v_val_1614_, v_val_1615_, v_a_1616_, v_as_x27_1617_, v_b_1618_);
lean_dec(v_as_x27_1617_);
lean_dec(v_a_1616_);
lean_dec(v_val_1615_);
lean_dec(v_val_1614_);
lean_dec(v_val_1613_);
return v_res_1620_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__23(lean_object* v_a_1621_, lean_object* v_a_1622_){
_start:
{
if (lean_obj_tag(v_a_1621_) == 0)
{
lean_object* v___x_1623_; 
v___x_1623_ = l_List_reverse___redArg(v_a_1622_);
return v___x_1623_;
}
else
{
lean_object* v_head_1624_; lean_object* v_tail_1625_; lean_object* v___x_1627_; uint8_t v_isShared_1628_; uint8_t v_isSharedCheck_1634_; 
v_head_1624_ = lean_ctor_get(v_a_1621_, 0);
v_tail_1625_ = lean_ctor_get(v_a_1621_, 1);
v_isSharedCheck_1634_ = !lean_is_exclusive(v_a_1621_);
if (v_isSharedCheck_1634_ == 0)
{
v___x_1627_ = v_a_1621_;
v_isShared_1628_ = v_isSharedCheck_1634_;
goto v_resetjp_1626_;
}
else
{
lean_inc(v_tail_1625_);
lean_inc(v_head_1624_);
lean_dec(v_a_1621_);
v___x_1627_ = lean_box(0);
v_isShared_1628_ = v_isSharedCheck_1634_;
goto v_resetjp_1626_;
}
v_resetjp_1626_:
{
lean_object* v___x_1629_; lean_object* v___x_1631_; 
v___x_1629_ = l_List_lengthTR___redArg(v_head_1624_);
lean_dec(v_head_1624_);
if (v_isShared_1628_ == 0)
{
lean_ctor_set(v___x_1627_, 1, v_a_1622_);
lean_ctor_set(v___x_1627_, 0, v___x_1629_);
v___x_1631_ = v___x_1627_;
goto v_reusejp_1630_;
}
else
{
lean_object* v_reuseFailAlloc_1633_; 
v_reuseFailAlloc_1633_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1633_, 0, v___x_1629_);
lean_ctor_set(v_reuseFailAlloc_1633_, 1, v_a_1622_);
v___x_1631_ = v_reuseFailAlloc_1633_;
goto v_reusejp_1630_;
}
v_reusejp_1630_:
{
v_a_1621_ = v_tail_1625_;
v_a_1622_ = v___x_1631_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__9(lean_object* v_a_1636_, lean_object* v_a_1637_){
_start:
{
if (lean_obj_tag(v_a_1636_) == 0)
{
lean_object* v___x_1638_; 
v___x_1638_ = l_List_reverse___redArg(v_a_1637_);
return v___x_1638_;
}
else
{
lean_object* v_head_1639_; lean_object* v_tail_1640_; lean_object* v___x_1642_; uint8_t v_isShared_1643_; uint8_t v_isSharedCheck_1650_; 
v_head_1639_ = lean_ctor_get(v_a_1636_, 0);
v_tail_1640_ = lean_ctor_get(v_a_1636_, 1);
v_isSharedCheck_1650_ = !lean_is_exclusive(v_a_1636_);
if (v_isSharedCheck_1650_ == 0)
{
v___x_1642_ = v_a_1636_;
v_isShared_1643_ = v_isSharedCheck_1650_;
goto v_resetjp_1641_;
}
else
{
lean_inc(v_tail_1640_);
lean_inc(v_head_1639_);
lean_dec(v_a_1636_);
v___x_1642_ = lean_box(0);
v_isShared_1643_ = v_isSharedCheck_1650_;
goto v_resetjp_1641_;
}
v_resetjp_1641_:
{
lean_object* v___x_1644_; lean_object* v___x_1645_; lean_object* v___x_1647_; 
v___x_1644_ = ((lean_object*)(l_List_mapTR_loop___at___00BudgetWorker_bench_spec__9___closed__0));
v___x_1645_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1645_, 0, v___x_1644_);
lean_ctor_set(v___x_1645_, 1, v_head_1639_);
if (v_isShared_1643_ == 0)
{
lean_ctor_set(v___x_1642_, 1, v_a_1637_);
lean_ctor_set(v___x_1642_, 0, v___x_1645_);
v___x_1647_ = v___x_1642_;
goto v_reusejp_1646_;
}
else
{
lean_object* v_reuseFailAlloc_1649_; 
v_reuseFailAlloc_1649_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1649_, 0, v___x_1645_);
lean_ctor_set(v_reuseFailAlloc_1649_, 1, v_a_1637_);
v___x_1647_ = v_reuseFailAlloc_1649_;
goto v_reusejp_1646_;
}
v_reusejp_1646_:
{
v_a_1636_ = v_tail_1640_;
v_a_1637_ = v___x_1647_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11___redArg(lean_object* v_val_1652_, lean_object* v_val_1653_, lean_object* v_a_1654_, lean_object* v_as_x27_1655_, lean_object* v_b_1656_){
_start:
{
if (lean_obj_tag(v_as_x27_1655_) == 0)
{
lean_object* v___x_1658_; 
lean_dec(v_a_1654_);
v___x_1658_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1658_, 0, v_b_1656_);
return v___x_1658_;
}
else
{
lean_object* v_head_1659_; lean_object* v_tail_1660_; uint8_t v___x_1661_; lean_object* v___x_1662_; lean_object* v_a_1663_; lean_object* v___x_1664_; lean_object* v___x_1665_; uint8_t v___x_1666_; lean_object* v___x_1667_; lean_object* v___x_1668_; lean_object* v___x_1669_; 
v_head_1659_ = lean_ctor_get(v_as_x27_1655_, 0);
v_tail_1660_ = lean_ctor_get(v_as_x27_1655_, 1);
v___x_1661_ = lean_unbox(v_head_1659_);
v___x_1662_ = l_BudgetWorker_timedFeatures(v___x_1661_, v_val_1652_, v_val_1653_);
v_a_1663_ = lean_ctor_get(v___x_1662_, 0);
lean_inc(v_a_1663_);
lean_dec_ref(v___x_1662_);
v___x_1664_ = lean_unsigned_to_nat(0u);
v___x_1665_ = ((lean_object*)(l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11___redArg___closed__0));
v___x_1666_ = lean_unbox(v_head_1659_);
v___x_1667_ = l_BudgetWorker_kindName(v___x_1666_);
lean_inc(v_a_1654_);
v___x_1668_ = lean_nat_to_int(v_a_1654_);
v___x_1669_ = l_BudgetWorker_sampleEvent(v___x_1665_, v___x_1667_, v___x_1668_, v_a_1663_, v___x_1664_);
if (lean_obj_tag(v___x_1669_) == 0)
{
lean_object* v___x_1670_; 
lean_dec_ref_known(v___x_1669_, 1);
v___x_1670_ = lean_box(0);
v_as_x27_1655_ = v_tail_1660_;
v_b_1656_ = v___x_1670_;
goto _start;
}
else
{
lean_dec(v_a_1654_);
return v___x_1669_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11___redArg___boxed(lean_object* v_val_1672_, lean_object* v_val_1673_, lean_object* v_a_1674_, lean_object* v_as_x27_1675_, lean_object* v_b_1676_, lean_object* v___y_1677_){
_start:
{
lean_object* v_res_1678_; 
v_res_1678_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11___redArg(v_val_1672_, v_val_1673_, v_a_1674_, v_as_x27_1675_, v_b_1676_);
lean_dec(v_as_x27_1675_);
lean_dec(v_val_1673_);
lean_dec(v_val_1672_);
return v_res_1678_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__10___redArg(lean_object* v_a_1679_, lean_object* v_val_1680_, lean_object* v_val_1681_, lean_object* v_val_1682_, lean_object* v_a_1683_, lean_object* v_as_x27_1684_, lean_object* v_b_1685_){
_start:
{
if (lean_obj_tag(v_as_x27_1684_) == 0)
{
lean_object* v___x_1687_; 
lean_dec(v_a_1679_);
v___x_1687_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1687_, 0, v_b_1685_);
return v___x_1687_;
}
else
{
lean_object* v_head_1688_; lean_object* v_snd_1689_; lean_object* v_tail_1690_; lean_object* v_fst_1691_; lean_object* v_fst_1692_; lean_object* v_snd_1693_; lean_object* v___x_1694_; lean_object* v_____x_1696_; lean_object* v___x_1702_; uint8_t v___x_1703_; 
v_head_1688_ = lean_ctor_get(v_as_x27_1684_, 0);
v_snd_1689_ = lean_ctor_get(v_head_1688_, 1);
v_tail_1690_ = lean_ctor_get(v_as_x27_1684_, 1);
v_fst_1691_ = lean_ctor_get(v_head_1688_, 0);
v_fst_1692_ = lean_ctor_get(v_snd_1689_, 0);
v_snd_1693_ = lean_ctor_get(v_snd_1689_, 1);
v___x_1694_ = lean_box(0);
v___x_1702_ = ((lean_object*)(l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__0));
v___x_1703_ = lean_string_dec_eq(v_fst_1691_, v___x_1702_);
if (v___x_1703_ == 0)
{
lean_object* v___x_1704_; 
lean_inc(v_snd_1693_);
v___x_1704_ = l_BudgetWorker_timedPolicy(v_snd_1693_, v_val_1680_, v_val_1681_, v_val_1682_, v_a_1683_);
if (lean_obj_tag(v___x_1704_) == 0)
{
lean_object* v_a_1705_; 
v_a_1705_ = lean_ctor_get(v___x_1704_, 0);
lean_inc(v_a_1705_);
lean_dec_ref_known(v___x_1704_, 1);
v_____x_1696_ = v_a_1705_;
goto v___jp_1695_;
}
else
{
lean_object* v_a_1706_; lean_object* v___x_1708_; uint8_t v_isShared_1709_; uint8_t v_isSharedCheck_1713_; 
lean_dec(v_a_1679_);
v_a_1706_ = lean_ctor_get(v___x_1704_, 0);
v_isSharedCheck_1713_ = !lean_is_exclusive(v___x_1704_);
if (v_isSharedCheck_1713_ == 0)
{
v___x_1708_ = v___x_1704_;
v_isShared_1709_ = v_isSharedCheck_1713_;
goto v_resetjp_1707_;
}
else
{
lean_inc(v_a_1706_);
lean_dec(v___x_1704_);
v___x_1708_ = lean_box(0);
v_isShared_1709_ = v_isSharedCheck_1713_;
goto v_resetjp_1707_;
}
v_resetjp_1707_:
{
lean_object* v___x_1711_; 
if (v_isShared_1709_ == 0)
{
v___x_1711_ = v___x_1708_;
goto v_reusejp_1710_;
}
else
{
lean_object* v_reuseFailAlloc_1712_; 
v_reuseFailAlloc_1712_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1712_, 0, v_a_1706_);
v___x_1711_ = v_reuseFailAlloc_1712_;
goto v_reusejp_1710_;
}
v_reusejp_1710_:
{
return v___x_1711_;
}
}
}
}
else
{
lean_object* v___x_1714_; lean_object* v___x_1715_; lean_object* v___x_1716_; lean_object* v___x_1717_; 
v___x_1714_ = lean_box(0);
lean_inc(v_snd_1693_);
v___x_1715_ = l_BudgetWorker_featureSelect(v_snd_1693_, v___x_1714_);
v___x_1716_ = l_LeanSort_LearnedSelection_resolve(v___x_1715_);
lean_dec(v___x_1715_);
v___x_1717_ = l_BudgetWorker_timedKernel(v___x_1716_, v_val_1680_, v_val_1681_, v_val_1682_, v_a_1683_);
if (lean_obj_tag(v___x_1717_) == 0)
{
lean_object* v_a_1718_; 
v_a_1718_ = lean_ctor_get(v___x_1717_, 0);
lean_inc(v_a_1718_);
lean_dec_ref_known(v___x_1717_, 1);
v_____x_1696_ = v_a_1718_;
goto v___jp_1695_;
}
else
{
lean_object* v_a_1719_; lean_object* v___x_1721_; uint8_t v_isShared_1722_; uint8_t v_isSharedCheck_1726_; 
lean_dec(v_a_1679_);
v_a_1719_ = lean_ctor_get(v___x_1717_, 0);
v_isSharedCheck_1726_ = !lean_is_exclusive(v___x_1717_);
if (v_isSharedCheck_1726_ == 0)
{
v___x_1721_ = v___x_1717_;
v_isShared_1722_ = v_isSharedCheck_1726_;
goto v_resetjp_1720_;
}
else
{
lean_inc(v_a_1719_);
lean_dec(v___x_1717_);
v___x_1721_ = lean_box(0);
v_isShared_1722_ = v_isSharedCheck_1726_;
goto v_resetjp_1720_;
}
v_resetjp_1720_:
{
lean_object* v___x_1724_; 
if (v_isShared_1722_ == 0)
{
v___x_1724_ = v___x_1721_;
goto v_reusejp_1723_;
}
else
{
lean_object* v_reuseFailAlloc_1725_; 
v_reuseFailAlloc_1725_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1725_, 0, v_a_1719_);
v___x_1724_ = v_reuseFailAlloc_1725_;
goto v_reusejp_1723_;
}
v_reusejp_1723_:
{
return v___x_1724_;
}
}
}
}
v___jp_1695_:
{
lean_object* v_fst_1697_; lean_object* v_snd_1698_; lean_object* v___x_1699_; lean_object* v___x_1700_; 
v_fst_1697_ = lean_ctor_get(v_____x_1696_, 0);
lean_inc(v_fst_1697_);
v_snd_1698_ = lean_ctor_get(v_____x_1696_, 1);
lean_inc(v_snd_1698_);
lean_dec_ref(v_____x_1696_);
lean_inc(v_a_1679_);
v___x_1699_ = lean_nat_to_int(v_a_1679_);
lean_inc(v_fst_1692_);
lean_inc(v_fst_1691_);
v___x_1700_ = l_BudgetWorker_sampleEvent(v_fst_1691_, v_fst_1692_, v___x_1699_, v_fst_1697_, v_snd_1698_);
if (lean_obj_tag(v___x_1700_) == 0)
{
lean_dec_ref_known(v___x_1700_, 1);
v_as_x27_1684_ = v_tail_1690_;
v_b_1685_ = v___x_1694_;
goto _start;
}
else
{
lean_dec(v_a_1679_);
return v___x_1700_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__10___redArg___boxed(lean_object* v_a_1727_, lean_object* v_val_1728_, lean_object* v_val_1729_, lean_object* v_val_1730_, lean_object* v_a_1731_, lean_object* v_as_x27_1732_, lean_object* v_b_1733_, lean_object* v___y_1734_){
_start:
{
lean_object* v_res_1735_; 
v_res_1735_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__10___redArg(v_a_1727_, v_val_1728_, v_val_1729_, v_val_1730_, v_a_1731_, v_as_x27_1732_, v_b_1733_);
lean_dec(v_as_x27_1732_);
lean_dec(v_a_1731_);
lean_dec(v_val_1730_);
lean_dec(v_val_1729_);
lean_dec(v_val_1728_);
return v_res_1735_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13___redArg(lean_object* v_val_1738_, lean_object* v_val_1739_, lean_object* v_val_1740_, lean_object* v_a_1741_, lean_object* v_a_1742_, lean_object* v___x_1743_, lean_object* v_as_x27_1744_, lean_object* v_b_1745_){
_start:
{
if (lean_obj_tag(v_as_x27_1744_) == 0)
{
lean_object* v___x_1747_; 
lean_dec(v___x_1743_);
v___x_1747_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1747_, 0, v_b_1745_);
return v___x_1747_;
}
else
{
lean_object* v_head_1748_; lean_object* v_tail_1749_; lean_object* v___x_1750_; lean_object* v___y_1752_; lean_object* v___x_1757_; lean_object* v___x_1758_; lean_object* v___x_1759_; lean_object* v___x_1760_; lean_object* v___x_1761_; lean_object* v___x_1762_; lean_object* v___x_1763_; lean_object* v___x_1764_; lean_object* v___x_1765_; lean_object* v___x_1766_; uint8_t v___x_1767_; 
v_head_1748_ = lean_ctor_get(v_as_x27_1744_, 0);
v_tail_1749_ = lean_ctor_get(v_as_x27_1744_, 1);
v___x_1750_ = lean_box(0);
v___x_1757_ = lean_unsigned_to_nat(0u);
v___x_1758_ = lean_nat_add(v_a_1742_, v_head_1748_);
v___x_1759_ = l_List_lengthTR___redArg(v___x_1743_);
v___x_1760_ = lean_nat_mod(v___x_1758_, v___x_1759_);
lean_dec(v___x_1759_);
lean_dec(v___x_1758_);
lean_inc(v___x_1760_);
v___x_1761_ = l_List_drop___redArg(v___x_1760_, v___x_1743_);
v___x_1762_ = ((lean_object*)(l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13___redArg___closed__0));
lean_inc(v___x_1743_);
v___x_1763_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v___x_1743_, v___x_1743_, v___x_1760_, v___x_1762_);
v___x_1764_ = l_List_appendTR___redArg(v___x_1761_, v___x_1763_);
v___x_1765_ = lean_unsigned_to_nat(2u);
v___x_1766_ = lean_nat_mod(v_head_1748_, v___x_1765_);
v___x_1767_ = lean_nat_dec_eq(v___x_1766_, v___x_1757_);
lean_dec(v___x_1766_);
if (v___x_1767_ == 0)
{
lean_object* v___x_1768_; 
v___x_1768_ = l_List_reverse___redArg(v___x_1764_);
v___y_1752_ = v___x_1768_;
goto v___jp_1751_;
}
else
{
v___y_1752_ = v___x_1764_;
goto v___jp_1751_;
}
v___jp_1751_:
{
lean_object* v___x_1753_; 
lean_inc(v_head_1748_);
v___x_1753_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__10___redArg(v_head_1748_, v_val_1738_, v_val_1739_, v_val_1740_, v_a_1741_, v___y_1752_, v___x_1750_);
lean_dec(v___y_1752_);
if (lean_obj_tag(v___x_1753_) == 0)
{
lean_object* v___x_1754_; lean_object* v___x_1755_; 
lean_dec_ref_known(v___x_1753_, 1);
v___x_1754_ = ((lean_object*)(l_BudgetWorker_kinds));
lean_inc(v_head_1748_);
v___x_1755_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11___redArg(v_val_1738_, v_val_1739_, v_head_1748_, v___x_1754_, v___x_1750_);
if (lean_obj_tag(v___x_1755_) == 0)
{
lean_dec_ref_known(v___x_1755_, 1);
v_as_x27_1744_ = v_tail_1749_;
v_b_1745_ = v___x_1750_;
goto _start;
}
else
{
lean_dec(v___x_1743_);
return v___x_1755_;
}
}
else
{
lean_dec(v___x_1743_);
return v___x_1753_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13___redArg___boxed(lean_object* v_val_1769_, lean_object* v_val_1770_, lean_object* v_val_1771_, lean_object* v_a_1772_, lean_object* v_a_1773_, lean_object* v___x_1774_, lean_object* v_as_x27_1775_, lean_object* v_b_1776_, lean_object* v___y_1777_){
_start:
{
lean_object* v_res_1778_; 
v_res_1778_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13___redArg(v_val_1769_, v_val_1770_, v_val_1771_, v_a_1772_, v_a_1773_, v___x_1774_, v_as_x27_1775_, v_b_1776_);
lean_dec(v_as_x27_1775_);
lean_dec(v_a_1773_);
lean_dec(v_a_1772_);
lean_dec(v_val_1771_);
lean_dec(v_val_1770_);
lean_dec(v_val_1769_);
return v_res_1778_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__8(lean_object* v_a_1779_, lean_object* v_a_1780_){
_start:
{
if (lean_obj_tag(v_a_1779_) == 0)
{
lean_object* v___x_1781_; 
v___x_1781_ = l_List_reverse___redArg(v_a_1780_);
return v___x_1781_;
}
else
{
lean_object* v_head_1782_; lean_object* v_tail_1783_; lean_object* v___x_1785_; uint8_t v_isShared_1786_; uint8_t v_isSharedCheck_1799_; 
v_head_1782_ = lean_ctor_get(v_a_1779_, 0);
v_tail_1783_ = lean_ctor_get(v_a_1779_, 1);
v_isSharedCheck_1799_ = !lean_is_exclusive(v_a_1779_);
if (v_isSharedCheck_1799_ == 0)
{
v___x_1785_ = v_a_1779_;
v_isShared_1786_ = v_isSharedCheck_1799_;
goto v_resetjp_1784_;
}
else
{
lean_inc(v_tail_1783_);
lean_inc(v_head_1782_);
lean_dec(v_a_1779_);
v___x_1785_ = lean_box(0);
v_isShared_1786_ = v_isSharedCheck_1799_;
goto v_resetjp_1784_;
}
v_resetjp_1784_:
{
lean_object* v___x_1787_; lean_object* v___x_1788_; uint8_t v___x_1789_; lean_object* v___x_1790_; lean_object* v___x_1791_; lean_object* v___x_1792_; lean_object* v___x_1793_; lean_object* v___x_1794_; lean_object* v___x_1796_; 
v___x_1787_ = ((lean_object*)(l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__0));
lean_inc(v_head_1782_);
v___x_1788_ = l_Nat_reprFast(v_head_1782_);
v___x_1789_ = 0;
v___x_1790_ = lean_nat_to_int(v_head_1782_);
v___x_1791_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1791_, 0, v___x_1790_);
v___x_1792_ = lean_alloc_ctor(0, 1, 1);
lean_ctor_set(v___x_1792_, 0, v___x_1791_);
lean_ctor_set_uint8(v___x_1792_, sizeof(void*)*1, v___x_1789_);
v___x_1793_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1793_, 0, v___x_1788_);
lean_ctor_set(v___x_1793_, 1, v___x_1792_);
v___x_1794_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1794_, 0, v___x_1787_);
lean_ctor_set(v___x_1794_, 1, v___x_1793_);
if (v_isShared_1786_ == 0)
{
lean_ctor_set(v___x_1785_, 1, v_a_1780_);
lean_ctor_set(v___x_1785_, 0, v___x_1794_);
v___x_1796_ = v___x_1785_;
goto v_reusejp_1795_;
}
else
{
lean_object* v_reuseFailAlloc_1798_; 
v_reuseFailAlloc_1798_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1798_, 0, v___x_1794_);
lean_ctor_set(v_reuseFailAlloc_1798_, 1, v_a_1780_);
v___x_1796_ = v_reuseFailAlloc_1798_;
goto v_reusejp_1795_;
}
v_reusejp_1795_:
{
v_a_1779_ = v_tail_1783_;
v_a_1780_ = v___x_1796_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___redArg(lean_object* v_a_1803_, lean_object* v_as_x27_1804_, lean_object* v_b_1805_){
_start:
{
if (lean_obj_tag(v_as_x27_1804_) == 0)
{
lean_object* v___x_1807_; 
v___x_1807_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1807_, 0, v_b_1805_);
return v___x_1807_;
}
else
{
lean_object* v_head_1808_; lean_object* v_tail_1809_; uint8_t v___x_1810_; lean_object* v___x_1811_; lean_object* v_ret_1812_; lean_object* v_time_1813_; lean_object* v___x_1814_; uint8_t v___y_1816_; uint8_t v___x_1820_; lean_object* v___x_1821_; uint8_t v___x_1822_; 
v_head_1808_ = lean_ctor_get(v_as_x27_1804_, 0);
v_tail_1809_ = lean_ctor_get(v_as_x27_1804_, 1);
v___x_1810_ = lean_unbox(v_head_1808_);
v___x_1811_ = l_LeanSort_BudgetSelection_Engine_feature___at___00LeanSort_BudgetSelection_counted_spec__0(v___x_1810_, v_a_1803_);
v_ret_1812_ = lean_ctor_get(v___x_1811_, 0);
lean_inc(v_ret_1812_);
v_time_1813_ = lean_ctor_get(v___x_1811_, 1);
lean_inc(v_time_1813_);
lean_dec_ref(v___x_1811_);
v___x_1814_ = lean_box(0);
v___x_1820_ = lean_unbox(v_head_1808_);
v___x_1821_ = l_LeanSort_BudgetSelection_features(v___x_1820_, v_a_1803_);
v___x_1822_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v_ret_1812_, v___x_1821_);
lean_dec(v___x_1821_);
lean_dec(v_ret_1812_);
if (v___x_1822_ == 0)
{
lean_dec(v_time_1813_);
v___y_1816_ = v___x_1822_;
goto v___jp_1815_;
}
else
{
uint8_t v___x_1823_; lean_object* v___x_1824_; uint8_t v___x_1825_; 
v___x_1823_ = lean_unbox(v_head_1808_);
v___x_1824_ = l_LeanSort_BudgetSelection_FeatureSet_budget(v___x_1823_);
v___x_1825_ = lean_nat_dec_le(v_time_1813_, v___x_1824_);
lean_dec(v___x_1824_);
lean_dec(v_time_1813_);
v___y_1816_ = v___x_1825_;
goto v___jp_1815_;
}
v___jp_1815_:
{
if (v___y_1816_ == 0)
{
lean_object* v___x_1817_; lean_object* v___x_1818_; 
v___x_1817_ = ((lean_object*)(l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___redArg___closed__1));
v___x_1818_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1818_, 0, v___x_1817_);
return v___x_1818_;
}
else
{
v_as_x27_1804_ = v_tail_1809_;
v_b_1805_ = v___x_1814_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___redArg___boxed(lean_object* v_a_1826_, lean_object* v_as_x27_1827_, lean_object* v_b_1828_, lean_object* v___y_1829_){
_start:
{
lean_object* v_res_1830_; 
v_res_1830_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___redArg(v_a_1826_, v_as_x27_1827_, v_b_1828_);
lean_dec(v_as_x27_1827_);
lean_dec(v_a_1826_);
return v_res_1830_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__7___redArg(lean_object* v_val_1831_, lean_object* v_val_1832_, lean_object* v_val_1833_, lean_object* v_a_1834_, lean_object* v_as_x27_1835_, lean_object* v_b_1836_){
_start:
{
if (lean_obj_tag(v_as_x27_1835_) == 0)
{
lean_object* v___x_1838_; 
v___x_1838_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1838_, 0, v_b_1836_);
return v___x_1838_;
}
else
{
lean_object* v_head_1839_; lean_object* v_tail_1840_; lean_object* v_fst_1841_; lean_object* v_snd_1842_; lean_object* v___x_1843_; 
v_head_1839_ = lean_ctor_get(v_as_x27_1835_, 0);
v_tail_1840_ = lean_ctor_get(v_as_x27_1835_, 1);
v_fst_1841_ = lean_ctor_get(v_head_1839_, 0);
v_snd_1842_ = lean_ctor_get(v_head_1839_, 1);
lean_inc(v_snd_1842_);
v___x_1843_ = l_BudgetWorker_timedPolicy(v_snd_1842_, v_val_1831_, v_val_1832_, v_val_1833_, v_a_1834_);
if (lean_obj_tag(v___x_1843_) == 0)
{
lean_object* v_a_1844_; lean_object* v_fst_1845_; lean_object* v_snd_1846_; lean_object* v___x_1847_; lean_object* v___x_1848_; lean_object* v___x_1849_; 
v_a_1844_ = lean_ctor_get(v___x_1843_, 0);
lean_inc(v_a_1844_);
lean_dec_ref_known(v___x_1843_, 1);
v_fst_1845_ = lean_ctor_get(v_a_1844_, 0);
lean_inc(v_fst_1845_);
v_snd_1846_ = lean_ctor_get(v_a_1844_, 1);
lean_inc(v_snd_1846_);
lean_dec(v_a_1844_);
v___x_1847_ = ((lean_object*)(l_List_mapTR_loop___at___00BudgetWorker_bench_spec__9___closed__0));
v___x_1848_ = lean_obj_once(&l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__2, &l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__2_once, _init_l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg___closed__2);
lean_inc(v_fst_1841_);
v___x_1849_ = l_BudgetWorker_sampleEvent(v___x_1847_, v_fst_1841_, v___x_1848_, v_fst_1845_, v_snd_1846_);
if (lean_obj_tag(v___x_1849_) == 0)
{
lean_object* v___x_1850_; 
lean_dec_ref_known(v___x_1849_, 1);
v___x_1850_ = lean_box(0);
v_as_x27_1835_ = v_tail_1840_;
v_b_1836_ = v___x_1850_;
goto _start;
}
else
{
return v___x_1849_;
}
}
else
{
lean_object* v_a_1852_; lean_object* v___x_1854_; uint8_t v_isShared_1855_; uint8_t v_isSharedCheck_1859_; 
v_a_1852_ = lean_ctor_get(v___x_1843_, 0);
v_isSharedCheck_1859_ = !lean_is_exclusive(v___x_1843_);
if (v_isSharedCheck_1859_ == 0)
{
v___x_1854_ = v___x_1843_;
v_isShared_1855_ = v_isSharedCheck_1859_;
goto v_resetjp_1853_;
}
else
{
lean_inc(v_a_1852_);
lean_dec(v___x_1843_);
v___x_1854_ = lean_box(0);
v_isShared_1855_ = v_isSharedCheck_1859_;
goto v_resetjp_1853_;
}
v_resetjp_1853_:
{
lean_object* v___x_1857_; 
if (v_isShared_1855_ == 0)
{
v___x_1857_ = v___x_1854_;
goto v_reusejp_1856_;
}
else
{
lean_object* v_reuseFailAlloc_1858_; 
v_reuseFailAlloc_1858_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1858_, 0, v_a_1852_);
v___x_1857_ = v_reuseFailAlloc_1858_;
goto v_reusejp_1856_;
}
v_reusejp_1856_:
{
return v___x_1857_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__7___redArg___boxed(lean_object* v_val_1860_, lean_object* v_val_1861_, lean_object* v_val_1862_, lean_object* v_a_1863_, lean_object* v_as_x27_1864_, lean_object* v_b_1865_, lean_object* v___y_1866_){
_start:
{
lean_object* v_res_1867_; 
v_res_1867_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__7___redArg(v_val_1860_, v_val_1861_, v_val_1862_, v_a_1863_, v_as_x27_1864_, v_b_1865_);
lean_dec(v_as_x27_1864_);
lean_dec(v_a_1863_);
lean_dec(v_val_1862_);
lean_dec(v_val_1861_);
lean_dec(v_val_1860_);
return v_res_1867_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12___redArg(lean_object* v_snd_1869_, lean_object* v_val_1870_, lean_object* v_val_1871_, lean_object* v___x_1872_, lean_object* v_fst_1873_, lean_object* v_as_x27_1874_, lean_object* v_b_1875_){
_start:
{
if (lean_obj_tag(v_as_x27_1874_) == 0)
{
lean_object* v___x_1877_; 
lean_dec_ref(v_fst_1873_);
lean_dec_ref(v_snd_1869_);
v___x_1877_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1877_, 0, v_b_1875_);
return v___x_1877_;
}
else
{
lean_object* v_head_1878_; lean_object* v_tail_1879_; lean_object* v___x_1880_; lean_object* v_a_1881_; lean_object* v___x_1882_; lean_object* v___x_1883_; lean_object* v___x_1884_; lean_object* v___x_1885_; lean_object* v___x_1886_; 
v_head_1878_ = lean_ctor_get(v_as_x27_1874_, 0);
v_tail_1879_ = lean_ctor_get(v_as_x27_1874_, 1);
lean_inc_ref_n(v_snd_1869_, 2);
v___x_1880_ = l_BudgetWorker_timedDecision(v_snd_1869_, v_val_1870_, v_val_1871_);
v_a_1881_ = lean_ctor_get(v___x_1880_, 0);
lean_inc(v_a_1881_);
lean_dec_ref(v___x_1880_);
v___x_1882_ = ((lean_object*)(l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12___redArg___closed__0));
lean_inc(v_head_1878_);
v___x_1883_ = lean_nat_to_int(v_head_1878_);
v___x_1884_ = l_BudgetWorker_featureSelect(v_snd_1869_, v___x_1872_);
v___x_1885_ = l_LeanSort_LearnedSelection_resolve(v___x_1884_);
lean_dec(v___x_1884_);
lean_inc_ref(v_fst_1873_);
v___x_1886_ = l_BudgetWorker_sampleEvent(v___x_1882_, v_fst_1873_, v___x_1883_, v_a_1881_, v___x_1885_);
if (lean_obj_tag(v___x_1886_) == 0)
{
lean_object* v___x_1887_; 
lean_dec_ref_known(v___x_1886_, 1);
v___x_1887_ = lean_box(0);
v_as_x27_1874_ = v_tail_1879_;
v_b_1875_ = v___x_1887_;
goto _start;
}
else
{
lean_dec_ref(v_fst_1873_);
lean_dec_ref(v_snd_1869_);
return v___x_1886_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12___redArg___boxed(lean_object* v_snd_1889_, lean_object* v_val_1890_, lean_object* v_val_1891_, lean_object* v___x_1892_, lean_object* v_fst_1893_, lean_object* v_as_x27_1894_, lean_object* v_b_1895_, lean_object* v___y_1896_){
_start:
{
lean_object* v_res_1897_; 
v_res_1897_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12___redArg(v_snd_1889_, v_val_1890_, v_val_1891_, v___x_1892_, v_fst_1893_, v_as_x27_1894_, v_b_1895_);
lean_dec(v_as_x27_1894_);
lean_dec(v___x_1892_);
lean_dec(v_val_1891_);
lean_dec(v_val_1890_);
return v_res_1897_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__17___redArg(lean_object* v_a_1898_, lean_object* v_val_1899_, lean_object* v___x_1900_, lean_object* v_as_x27_1901_, lean_object* v_b_1902_){
_start:
{
if (lean_obj_tag(v_as_x27_1901_) == 0)
{
lean_object* v___x_1904_; 
v___x_1904_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1904_, 0, v_b_1902_);
return v___x_1904_;
}
else
{
lean_object* v_head_1905_; lean_object* v_snd_1906_; lean_object* v_tail_1907_; lean_object* v_fst_1908_; uint8_t v_featureSet_1909_; lean_object* v___x_1910_; lean_object* v___x_1911_; lean_object* v___x_1912_; lean_object* v___x_1913_; 
v_head_1905_ = lean_ctor_get(v_as_x27_1901_, 0);
v_snd_1906_ = lean_ctor_get(v_head_1905_, 1);
v_tail_1907_ = lean_ctor_get(v_as_x27_1901_, 1);
v_fst_1908_ = lean_ctor_get(v_head_1905_, 0);
v_featureSet_1909_ = lean_ctor_get_uint8(v_snd_1906_, sizeof(void*)*1);
v___x_1910_ = l_LeanSort_BudgetSelection_features(v_featureSet_1909_, v_a_1898_);
lean_inc(v___x_1910_);
v___x_1911_ = lean_st_mk_ref(v___x_1910_);
v___x_1912_ = lean_box(0);
lean_inc(v_fst_1908_);
lean_inc(v_snd_1906_);
v___x_1913_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12___redArg(v_snd_1906_, v___x_1911_, v_val_1899_, v___x_1910_, v_fst_1908_, v___x_1900_, v___x_1912_);
lean_dec(v___x_1910_);
lean_dec(v___x_1911_);
if (lean_obj_tag(v___x_1913_) == 0)
{
lean_dec_ref_known(v___x_1913_, 1);
v_as_x27_1901_ = v_tail_1907_;
v_b_1902_ = v___x_1912_;
goto _start;
}
else
{
return v___x_1913_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__17___redArg___boxed(lean_object* v_a_1915_, lean_object* v_val_1916_, lean_object* v___x_1917_, lean_object* v_as_x27_1918_, lean_object* v_b_1919_, lean_object* v___y_1920_){
_start:
{
lean_object* v_res_1921_; 
v_res_1921_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__17___redArg(v_a_1915_, v_val_1916_, v___x_1917_, v_as_x27_1918_, v_b_1919_);
lean_dec(v_as_x27_1918_);
lean_dec(v___x_1917_);
lean_dec(v_val_1916_);
lean_dec(v_a_1915_);
return v_res_1921_;
}
}
LEAN_EXPORT lean_object* l_List_find_x3f___at___00BudgetWorker_bench_spec__0(lean_object* v_name_1922_, lean_object* v_x_1923_){
_start:
{
if (lean_obj_tag(v_x_1923_) == 0)
{
lean_object* v___x_1924_; 
v___x_1924_ = lean_box(0);
return v___x_1924_;
}
else
{
lean_object* v_head_1925_; lean_object* v_tail_1926_; lean_object* v_fst_1927_; uint8_t v___x_1928_; 
v_head_1925_ = lean_ctor_get(v_x_1923_, 0);
v_tail_1926_ = lean_ctor_get(v_x_1923_, 1);
v_fst_1927_ = lean_ctor_get(v_head_1925_, 0);
v___x_1928_ = lean_string_dec_eq(v_fst_1927_, v_name_1922_);
if (v___x_1928_ == 0)
{
v_x_1923_ = v_tail_1926_;
goto _start;
}
else
{
lean_object* v___x_1930_; 
lean_inc(v_head_1925_);
v___x_1930_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1930_, 0, v_head_1925_);
return v___x_1930_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_find_x3f___at___00BudgetWorker_bench_spec__0___boxed(lean_object* v_name_1931_, lean_object* v_x_1932_){
_start:
{
lean_object* v_res_1933_; 
v_res_1933_ = l_List_find_x3f___at___00BudgetWorker_bench_spec__0(v_name_1931_, v_x_1932_);
lean_dec(v_x_1932_);
lean_dec_ref(v_name_1931_);
return v_res_1933_;
}
}
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00BudgetWorker_bench_spec__5(lean_object* v_registry_1937_, lean_object* v_x_1938_, lean_object* v_x_1939_){
_start:
{
if (lean_obj_tag(v_x_1938_) == 0)
{
lean_object* v___x_1941_; lean_object* v___x_1942_; 
v___x_1941_ = l_List_reverse___redArg(v_x_1939_);
v___x_1942_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1942_, 0, v___x_1941_);
return v___x_1942_;
}
else
{
lean_object* v_head_1943_; lean_object* v_tail_1944_; lean_object* v___x_1946_; uint8_t v_isShared_1947_; uint8_t v_isSharedCheck_1965_; 
v_head_1943_ = lean_ctor_get(v_x_1938_, 0);
v_tail_1944_ = lean_ctor_get(v_x_1938_, 1);
v_isSharedCheck_1965_ = !lean_is_exclusive(v_x_1938_);
if (v_isSharedCheck_1965_ == 0)
{
v___x_1946_ = v_x_1938_;
v_isShared_1947_ = v_isSharedCheck_1965_;
goto v_resetjp_1945_;
}
else
{
lean_inc(v_tail_1944_);
lean_inc(v_head_1943_);
lean_dec(v_x_1938_);
v___x_1946_ = lean_box(0);
v_isShared_1947_ = v_isSharedCheck_1965_;
goto v_resetjp_1945_;
}
v_resetjp_1945_:
{
lean_object* v___x_1948_; 
v___x_1948_ = l_List_find_x3f___at___00BudgetWorker_bench_spec__0(v_head_1943_, v_registry_1937_);
if (lean_obj_tag(v___x_1948_) == 0)
{
lean_object* v___x_1949_; lean_object* v___x_1950_; 
lean_del_object(v___x_1946_);
lean_dec(v_tail_1944_);
lean_dec(v_head_1943_);
lean_dec(v_x_1939_);
v___x_1949_ = ((lean_object*)(l_List_mapM_loop___at___00BudgetWorker_bench_spec__5___closed__1));
v___x_1950_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1950_, 0, v___x_1949_);
return v___x_1950_;
}
else
{
lean_object* v_val_1951_; lean_object* v_snd_1952_; lean_object* v___x_1954_; uint8_t v_isShared_1955_; uint8_t v_isSharedCheck_1963_; 
v_val_1951_ = lean_ctor_get(v___x_1948_, 0);
lean_inc(v_val_1951_);
lean_dec_ref_known(v___x_1948_, 1);
v_snd_1952_ = lean_ctor_get(v_val_1951_, 1);
v_isSharedCheck_1963_ = !lean_is_exclusive(v_val_1951_);
if (v_isSharedCheck_1963_ == 0)
{
lean_object* v_unused_1964_; 
v_unused_1964_ = lean_ctor_get(v_val_1951_, 0);
lean_dec(v_unused_1964_);
v___x_1954_ = v_val_1951_;
v_isShared_1955_ = v_isSharedCheck_1963_;
goto v_resetjp_1953_;
}
else
{
lean_inc(v_snd_1952_);
lean_dec(v_val_1951_);
v___x_1954_ = lean_box(0);
v_isShared_1955_ = v_isSharedCheck_1963_;
goto v_resetjp_1953_;
}
v_resetjp_1953_:
{
lean_object* v___x_1957_; 
if (v_isShared_1955_ == 0)
{
lean_ctor_set(v___x_1954_, 0, v_head_1943_);
v___x_1957_ = v___x_1954_;
goto v_reusejp_1956_;
}
else
{
lean_object* v_reuseFailAlloc_1962_; 
v_reuseFailAlloc_1962_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1962_, 0, v_head_1943_);
lean_ctor_set(v_reuseFailAlloc_1962_, 1, v_snd_1952_);
v___x_1957_ = v_reuseFailAlloc_1962_;
goto v_reusejp_1956_;
}
v_reusejp_1956_:
{
lean_object* v___x_1959_; 
if (v_isShared_1947_ == 0)
{
lean_ctor_set(v___x_1946_, 1, v_x_1939_);
lean_ctor_set(v___x_1946_, 0, v___x_1957_);
v___x_1959_ = v___x_1946_;
goto v_reusejp_1958_;
}
else
{
lean_object* v_reuseFailAlloc_1961_; 
v_reuseFailAlloc_1961_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1961_, 0, v___x_1957_);
lean_ctor_set(v_reuseFailAlloc_1961_, 1, v_x_1939_);
v___x_1959_ = v_reuseFailAlloc_1961_;
goto v_reusejp_1958_;
}
v_reusejp_1958_:
{
v_x_1938_ = v_tail_1944_;
v_x_1939_ = v___x_1959_;
goto _start;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00BudgetWorker_bench_spec__5___boxed(lean_object* v_registry_1966_, lean_object* v_x_1967_, lean_object* v_x_1968_, lean_object* v___y_1969_){
_start:
{
lean_object* v_res_1970_; 
v_res_1970_ = l_List_mapM_loop___at___00BudgetWorker_bench_spec__5(v_registry_1966_, v_x_1967_, v_x_1968_);
lean_dec(v_registry_1966_);
return v_res_1970_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__14(lean_object* v_a_1971_, lean_object* v_a_1972_, lean_object* v_a_1973_){
_start:
{
if (lean_obj_tag(v_a_1972_) == 0)
{
lean_object* v___x_1974_; 
v___x_1974_ = l_List_reverse___redArg(v_a_1973_);
return v___x_1974_;
}
else
{
lean_object* v_head_1975_; lean_object* v_tail_1976_; lean_object* v___x_1978_; uint8_t v_isShared_1979_; uint8_t v_isSharedCheck_1986_; 
v_head_1975_ = lean_ctor_get(v_a_1972_, 0);
v_tail_1976_ = lean_ctor_get(v_a_1972_, 1);
v_isSharedCheck_1986_ = !lean_is_exclusive(v_a_1972_);
if (v_isSharedCheck_1986_ == 0)
{
v___x_1978_ = v_a_1972_;
v_isShared_1979_ = v_isSharedCheck_1986_;
goto v_resetjp_1977_;
}
else
{
lean_inc(v_tail_1976_);
lean_inc(v_head_1975_);
lean_dec(v_a_1972_);
v___x_1978_ = lean_box(0);
v_isShared_1979_ = v_isSharedCheck_1986_;
goto v_resetjp_1977_;
}
v_resetjp_1977_:
{
uint8_t v___x_1980_; lean_object* v___x_1981_; lean_object* v___x_1983_; 
v___x_1980_ = lean_unbox(v_head_1975_);
lean_dec(v_head_1975_);
v___x_1981_ = l_LeanSort_BudgetSelection_features(v___x_1980_, v_a_1971_);
if (v_isShared_1979_ == 0)
{
lean_ctor_set(v___x_1978_, 1, v_a_1973_);
lean_ctor_set(v___x_1978_, 0, v___x_1981_);
v___x_1983_ = v___x_1978_;
goto v_reusejp_1982_;
}
else
{
lean_object* v_reuseFailAlloc_1985_; 
v_reuseFailAlloc_1985_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1985_, 0, v___x_1981_);
lean_ctor_set(v_reuseFailAlloc_1985_, 1, v_a_1973_);
v___x_1983_ = v_reuseFailAlloc_1985_;
goto v_reusejp_1982_;
}
v_reusejp_1982_:
{
v_a_1972_ = v_tail_1976_;
v_a_1973_ = v___x_1983_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__14___boxed(lean_object* v_a_1987_, lean_object* v_a_1988_, lean_object* v_a_1989_){
_start:
{
lean_object* v_res_1990_; 
v_res_1990_ = l_List_mapTR_loop___at___00BudgetWorker_bench_spec__14(v_a_1987_, v_a_1988_, v_a_1989_);
lean_dec(v_a_1987_);
return v_res_1990_;
}
}
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00BudgetWorker_bench_spec__18(lean_object* v_a_1994_, lean_object* v_a_1995_, lean_object* v_a_1996_, lean_object* v_x_1997_, lean_object* v_x_1998_){
_start:
{
if (lean_obj_tag(v_x_1997_) == 0)
{
lean_object* v___x_2000_; lean_object* v___x_2001_; 
lean_dec(v_a_1994_);
v___x_2000_ = l_List_reverse___redArg(v_x_1998_);
v___x_2001_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2001_, 0, v___x_2000_);
return v___x_2001_;
}
else
{
lean_object* v_head_2002_; lean_object* v_tail_2003_; lean_object* v___x_2005_; uint8_t v_isShared_2006_; uint8_t v_isSharedCheck_2050_; 
v_head_2002_ = lean_ctor_get(v_x_1997_, 0);
v_tail_2003_ = lean_ctor_get(v_x_1997_, 1);
v_isSharedCheck_2050_ = !lean_is_exclusive(v_x_1997_);
if (v_isSharedCheck_2050_ == 0)
{
v___x_2005_ = v_x_1997_;
v_isShared_2006_ = v_isSharedCheck_2050_;
goto v_resetjp_2004_;
}
else
{
lean_inc(v_tail_2003_);
lean_inc(v_head_2002_);
lean_dec(v_x_1997_);
v___x_2005_ = lean_box(0);
v_isShared_2006_ = v_isSharedCheck_2050_;
goto v_resetjp_2004_;
}
v_resetjp_2004_:
{
lean_object* v_a_2008_; lean_object* v___x_2013_; 
lean_inc(v_a_1994_);
lean_inc(v_head_2002_);
v___x_2013_ = l_BudgetWorker_kernelProfile(v_head_2002_, v_a_1994_, v_a_1995_);
if (lean_obj_tag(v___x_2013_) == 0)
{
lean_object* v_a_2014_; lean_object* v___x_2015_; lean_object* v___x_2016_; lean_object* v___x_2017_; 
v_a_2014_ = lean_ctor_get(v___x_2013_, 0);
lean_inc_n(v_a_2014_, 2);
lean_dec_ref_known(v___x_2013_, 1);
v___x_2015_ = ((lean_object*)(l_BudgetWorker_kernelProfile___closed__2));
v___x_2016_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_a_2014_, v___x_2015_);
v___x_2017_ = l_BudgetWorker_orError___redArg(v___x_2016_);
if (lean_obj_tag(v___x_2017_) == 0)
{
lean_object* v_a_2018_; lean_object* v___x_2020_; uint8_t v_isShared_2021_; uint8_t v_isSharedCheck_2032_; 
v_a_2018_ = lean_ctor_get(v___x_2017_, 0);
v_isSharedCheck_2032_ = !lean_is_exclusive(v___x_2017_);
if (v_isSharedCheck_2032_ == 0)
{
v___x_2020_ = v___x_2017_;
v_isShared_2021_ = v_isSharedCheck_2032_;
goto v_resetjp_2019_;
}
else
{
lean_inc(v_a_2018_);
lean_dec(v___x_2017_);
v___x_2020_ = lean_box(0);
v_isShared_2021_ = v_isSharedCheck_2032_;
goto v_resetjp_2019_;
}
v_resetjp_2019_:
{
lean_object* v___y_2023_; lean_object* v___x_2029_; 
v___x_2029_ = l_List_get_x3fInternal___redArg(v_a_1996_, v_head_2002_);
if (lean_obj_tag(v___x_2029_) == 0)
{
lean_object* v___x_2030_; 
v___x_2030_ = lean_unsigned_to_nat(0u);
v___y_2023_ = v___x_2030_;
goto v___jp_2022_;
}
else
{
lean_object* v_val_2031_; 
v_val_2031_ = lean_ctor_get(v___x_2029_, 0);
lean_inc(v_val_2031_);
lean_dec_ref_known(v___x_2029_, 1);
v___y_2023_ = v_val_2031_;
goto v___jp_2022_;
}
v___jp_2022_:
{
uint8_t v___x_2024_; 
v___x_2024_ = lean_nat_dec_eq(v_a_2018_, v___y_2023_);
lean_dec(v___y_2023_);
lean_dec(v_a_2018_);
if (v___x_2024_ == 0)
{
lean_object* v___x_2025_; lean_object* v___x_2027_; 
lean_dec(v_a_2014_);
lean_del_object(v___x_2005_);
lean_dec(v_tail_2003_);
lean_dec(v_x_1998_);
lean_dec(v_a_1994_);
v___x_2025_ = ((lean_object*)(l_List_mapM_loop___at___00BudgetWorker_bench_spec__18___closed__1));
if (v_isShared_2021_ == 0)
{
lean_ctor_set_tag(v___x_2020_, 1);
lean_ctor_set(v___x_2020_, 0, v___x_2025_);
v___x_2027_ = v___x_2020_;
goto v_reusejp_2026_;
}
else
{
lean_object* v_reuseFailAlloc_2028_; 
v_reuseFailAlloc_2028_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2028_, 0, v___x_2025_);
v___x_2027_ = v_reuseFailAlloc_2028_;
goto v_reusejp_2026_;
}
v_reusejp_2026_:
{
return v___x_2027_;
}
}
else
{
lean_del_object(v___x_2020_);
v_a_2008_ = v_a_2014_;
goto v___jp_2007_;
}
}
}
}
else
{
lean_object* v_a_2033_; lean_object* v___x_2035_; uint8_t v_isShared_2036_; uint8_t v_isSharedCheck_2040_; 
lean_dec(v_a_2014_);
lean_del_object(v___x_2005_);
lean_dec(v_tail_2003_);
lean_dec(v_head_2002_);
lean_dec(v_x_1998_);
lean_dec(v_a_1994_);
v_a_2033_ = lean_ctor_get(v___x_2017_, 0);
v_isSharedCheck_2040_ = !lean_is_exclusive(v___x_2017_);
if (v_isSharedCheck_2040_ == 0)
{
v___x_2035_ = v___x_2017_;
v_isShared_2036_ = v_isSharedCheck_2040_;
goto v_resetjp_2034_;
}
else
{
lean_inc(v_a_2033_);
lean_dec(v___x_2017_);
v___x_2035_ = lean_box(0);
v_isShared_2036_ = v_isSharedCheck_2040_;
goto v_resetjp_2034_;
}
v_resetjp_2034_:
{
lean_object* v___x_2038_; 
if (v_isShared_2036_ == 0)
{
v___x_2038_ = v___x_2035_;
goto v_reusejp_2037_;
}
else
{
lean_object* v_reuseFailAlloc_2039_; 
v_reuseFailAlloc_2039_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2039_, 0, v_a_2033_);
v___x_2038_ = v_reuseFailAlloc_2039_;
goto v_reusejp_2037_;
}
v_reusejp_2037_:
{
return v___x_2038_;
}
}
}
}
else
{
lean_dec(v_head_2002_);
if (lean_obj_tag(v___x_2013_) == 0)
{
lean_object* v_a_2041_; 
v_a_2041_ = lean_ctor_get(v___x_2013_, 0);
lean_inc(v_a_2041_);
lean_dec_ref_known(v___x_2013_, 1);
v_a_2008_ = v_a_2041_;
goto v___jp_2007_;
}
else
{
lean_object* v_a_2042_; lean_object* v___x_2044_; uint8_t v_isShared_2045_; uint8_t v_isSharedCheck_2049_; 
lean_del_object(v___x_2005_);
lean_dec(v_tail_2003_);
lean_dec(v_x_1998_);
lean_dec(v_a_1994_);
v_a_2042_ = lean_ctor_get(v___x_2013_, 0);
v_isSharedCheck_2049_ = !lean_is_exclusive(v___x_2013_);
if (v_isSharedCheck_2049_ == 0)
{
v___x_2044_ = v___x_2013_;
v_isShared_2045_ = v_isSharedCheck_2049_;
goto v_resetjp_2043_;
}
else
{
lean_inc(v_a_2042_);
lean_dec(v___x_2013_);
v___x_2044_ = lean_box(0);
v_isShared_2045_ = v_isSharedCheck_2049_;
goto v_resetjp_2043_;
}
v_resetjp_2043_:
{
lean_object* v___x_2047_; 
if (v_isShared_2045_ == 0)
{
v___x_2047_ = v___x_2044_;
goto v_reusejp_2046_;
}
else
{
lean_object* v_reuseFailAlloc_2048_; 
v_reuseFailAlloc_2048_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2048_, 0, v_a_2042_);
v___x_2047_ = v_reuseFailAlloc_2048_;
goto v_reusejp_2046_;
}
v_reusejp_2046_:
{
return v___x_2047_;
}
}
}
}
v___jp_2007_:
{
lean_object* v___x_2010_; 
if (v_isShared_2006_ == 0)
{
lean_ctor_set(v___x_2005_, 1, v_x_1998_);
lean_ctor_set(v___x_2005_, 0, v_a_2008_);
v___x_2010_ = v___x_2005_;
goto v_reusejp_2009_;
}
else
{
lean_object* v_reuseFailAlloc_2012_; 
v_reuseFailAlloc_2012_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2012_, 0, v_a_2008_);
lean_ctor_set(v_reuseFailAlloc_2012_, 1, v_x_1998_);
v___x_2010_ = v_reuseFailAlloc_2012_;
goto v_reusejp_2009_;
}
v_reusejp_2009_:
{
v_x_1997_ = v_tail_2003_;
v_x_1998_ = v___x_2010_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00BudgetWorker_bench_spec__18___boxed(lean_object* v_a_2051_, lean_object* v_a_2052_, lean_object* v_a_2053_, lean_object* v_x_2054_, lean_object* v_x_2055_, lean_object* v___y_2056_){
_start:
{
lean_object* v_res_2057_; 
v_res_2057_ = l_List_mapM_loop___at___00BudgetWorker_bench_spec__18(v_a_2051_, v_a_2052_, v_a_2053_, v_x_2054_, v_x_2055_);
lean_dec(v_a_2053_);
lean_dec(v_a_2052_);
return v_res_2057_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00Lean_Option_toJson___at___00BudgetWorker_bench_spec__3_spec__4(lean_object* v_a_2058_){
_start:
{
lean_object* v___x_2059_; lean_object* v___x_2060_; 
v___x_2059_ = lean_array_mk(v_a_2058_);
v___x_2060_ = l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonFuncTable_toJson_spec__0(v___x_2059_);
return v___x_2060_;
}
}
LEAN_EXPORT lean_object* l_Lean_Option_toJson___at___00BudgetWorker_bench_spec__3(lean_object* v_x_2061_){
_start:
{
if (lean_obj_tag(v_x_2061_) == 0)
{
lean_object* v___x_2062_; 
v___x_2062_ = lean_box(0);
return v___x_2062_;
}
else
{
lean_object* v_val_2063_; lean_object* v___x_2064_; 
v_val_2063_ = lean_ctor_get(v_x_2061_, 0);
lean_inc(v_val_2063_);
lean_dec_ref_known(v_x_2061_, 1);
v___x_2064_ = l_Lean_List_toJson___at___00Lean_Option_toJson___at___00BudgetWorker_bench_spec__3_spec__4(v_val_2063_);
return v___x_2064_;
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__20(lean_object* v_a_2067_, lean_object* v_a_2068_, lean_object* v_a_2069_){
_start:
{
if (lean_obj_tag(v_a_2068_) == 0)
{
lean_object* v___x_2070_; 
v___x_2070_ = l_List_reverse___redArg(v_a_2069_);
return v___x_2070_;
}
else
{
lean_object* v_head_2071_; lean_object* v_snd_2072_; lean_object* v_tail_2073_; lean_object* v___x_2075_; uint8_t v_isShared_2076_; uint8_t v_isSharedCheck_2127_; 
v_head_2071_ = lean_ctor_get(v_a_2068_, 0);
lean_inc(v_head_2071_);
v_snd_2072_ = lean_ctor_get(v_head_2071_, 1);
lean_inc(v_snd_2072_);
v_tail_2073_ = lean_ctor_get(v_a_2068_, 1);
v_isSharedCheck_2127_ = !lean_is_exclusive(v_a_2068_);
if (v_isSharedCheck_2127_ == 0)
{
lean_object* v_unused_2128_; 
v_unused_2128_ = lean_ctor_get(v_a_2068_, 0);
lean_dec(v_unused_2128_);
v___x_2075_ = v_a_2068_;
v_isShared_2076_ = v_isSharedCheck_2127_;
goto v_resetjp_2074_;
}
else
{
lean_inc(v_tail_2073_);
lean_dec(v_a_2068_);
v___x_2075_ = lean_box(0);
v_isShared_2076_ = v_isSharedCheck_2127_;
goto v_resetjp_2074_;
}
v_resetjp_2074_:
{
lean_object* v_fst_2077_; lean_object* v___x_2079_; uint8_t v_isShared_2080_; uint8_t v_isSharedCheck_2125_; 
v_fst_2077_ = lean_ctor_get(v_head_2071_, 0);
v_isSharedCheck_2125_ = !lean_is_exclusive(v_head_2071_);
if (v_isSharedCheck_2125_ == 0)
{
lean_object* v_unused_2126_; 
v_unused_2126_ = lean_ctor_get(v_head_2071_, 1);
lean_dec(v_unused_2126_);
v___x_2079_ = v_head_2071_;
v_isShared_2080_ = v_isSharedCheck_2125_;
goto v_resetjp_2078_;
}
else
{
lean_inc(v_fst_2077_);
lean_dec(v_head_2071_);
v___x_2079_ = lean_box(0);
v_isShared_2080_ = v_isSharedCheck_2125_;
goto v_resetjp_2078_;
}
v_resetjp_2078_:
{
uint8_t v_featureSet_2081_; lean_object* v_choice_2082_; lean_object* v___x_2083_; lean_object* v___x_2084_; lean_object* v___x_2085_; lean_object* v___x_2087_; 
v_featureSet_2081_ = lean_ctor_get_uint8(v_snd_2072_, sizeof(void*)*1);
v_choice_2082_ = lean_ctor_get(v_snd_2072_, 0);
lean_inc_ref(v_choice_2082_);
v___x_2083_ = l_LeanSort_BudgetSelection_features(v_featureSet_2081_, v_a_2067_);
v___x_2084_ = ((lean_object*)(l_BudgetWorker_sampleEvent___closed__5));
v___x_2085_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_2085_, 0, v_fst_2077_);
if (v_isShared_2080_ == 0)
{
lean_ctor_set(v___x_2079_, 1, v___x_2085_);
lean_ctor_set(v___x_2079_, 0, v___x_2084_);
v___x_2087_ = v___x_2079_;
goto v_reusejp_2086_;
}
else
{
lean_object* v_reuseFailAlloc_2124_; 
v_reuseFailAlloc_2124_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2124_, 0, v___x_2084_);
lean_ctor_set(v_reuseFailAlloc_2124_, 1, v___x_2085_);
v___x_2087_ = v_reuseFailAlloc_2124_;
goto v_reusejp_2086_;
}
v_reusejp_2086_:
{
lean_object* v___x_2088_; lean_object* v___x_2089_; lean_object* v___x_2090_; lean_object* v___x_2091_; lean_object* v___x_2092_; lean_object* v___x_2093_; lean_object* v___x_2094_; lean_object* v___x_2095_; lean_object* v___x_2096_; lean_object* v___x_2097_; uint8_t v___x_2098_; lean_object* v___x_2099_; lean_object* v___x_2100_; lean_object* v___x_2101_; lean_object* v___y_2103_; 
v___x_2088_ = ((lean_object*)(l_List_mapTR_loop___at___00BudgetWorker_bench_spec__20___closed__0));
lean_inc(v_snd_2072_);
v___x_2089_ = l_BudgetWorker_featureSelect(v_snd_2072_, v___x_2083_);
lean_inc(v___x_2089_);
v___x_2090_ = l_Lean_Option_toJson___at___00BudgetWorker_bench_spec__2(v___x_2089_);
v___x_2091_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2091_, 0, v___x_2088_);
lean_ctor_set(v___x_2091_, 1, v___x_2090_);
v___x_2092_ = ((lean_object*)(l_BudgetWorker_sampleEvent___closed__8));
v___x_2093_ = l_LeanSort_LearnedSelection_resolve(v___x_2089_);
lean_dec(v___x_2089_);
v___x_2094_ = l_Lean_JsonNumber_fromNat(v___x_2093_);
v___x_2095_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2095_, 0, v___x_2094_);
v___x_2096_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2096_, 0, v___x_2092_);
lean_ctor_set(v___x_2096_, 1, v___x_2095_);
v___x_2097_ = ((lean_object*)(l_List_mapTR_loop___at___00BudgetWorker_bench_spec__20___closed__1));
v___x_2098_ = l_BudgetWorker_usesFeatures(v_snd_2072_);
lean_dec(v_snd_2072_);
v___x_2099_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_2099_, 0, v___x_2098_);
v___x_2100_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2100_, 0, v___x_2097_);
lean_ctor_set(v___x_2100_, 1, v___x_2099_);
v___x_2101_ = ((lean_object*)(l_BudgetWorker_decodeTree___closed__11));
if (lean_obj_tag(v_choice_2082_) == 2)
{
lean_object* v_model_2117_; 
v_model_2117_ = lean_ctor_get(v_choice_2082_, 0);
lean_inc(v_model_2117_);
lean_dec_ref_known(v_choice_2082_, 1);
switch(lean_obj_tag(v_model_2117_))
{
case 1:
{
lean_object* v_tree_2118_; lean_object* v___x_2119_; 
v_tree_2118_ = lean_ctor_get(v_model_2117_, 0);
lean_inc_ref(v_tree_2118_);
lean_dec_ref_known(v_model_2117_, 1);
v___x_2119_ = l_LeanSort_LearnedSelection_Tree_eval(v_tree_2118_, v___x_2083_);
lean_dec(v___x_2083_);
v___y_2103_ = v___x_2119_;
goto v___jp_2102_;
}
case 2:
{
lean_object* v_tree_2120_; lean_object* v___x_2121_; 
v_tree_2120_ = lean_ctor_get(v_model_2117_, 0);
lean_inc_ref(v_tree_2120_);
lean_dec_ref_known(v_model_2117_, 1);
v___x_2121_ = l_LeanSort_LearnedSelection_Tree_eval(v_tree_2120_, v___x_2083_);
lean_dec(v___x_2083_);
v___y_2103_ = v___x_2121_;
goto v___jp_2102_;
}
default: 
{
lean_object* v___x_2122_; 
lean_dec(v_model_2117_);
lean_dec(v___x_2083_);
v___x_2122_ = lean_box(0);
v___y_2103_ = v___x_2122_;
goto v___jp_2102_;
}
}
}
else
{
lean_object* v___x_2123_; 
lean_dec(v___x_2083_);
lean_dec_ref(v_choice_2082_);
v___x_2123_ = lean_box(0);
v___y_2103_ = v___x_2123_;
goto v___jp_2102_;
}
v___jp_2102_:
{
lean_object* v___x_2104_; lean_object* v___x_2105_; lean_object* v___x_2106_; lean_object* v___x_2108_; 
v___x_2104_ = l_Lean_Option_toJson___at___00BudgetWorker_bench_spec__3(v___y_2103_);
v___x_2105_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2105_, 0, v___x_2101_);
lean_ctor_set(v___x_2105_, 1, v___x_2104_);
v___x_2106_ = lean_box(0);
if (v_isShared_2076_ == 0)
{
lean_ctor_set(v___x_2075_, 1, v___x_2106_);
lean_ctor_set(v___x_2075_, 0, v___x_2105_);
v___x_2108_ = v___x_2075_;
goto v_reusejp_2107_;
}
else
{
lean_object* v_reuseFailAlloc_2116_; 
v_reuseFailAlloc_2116_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2116_, 0, v___x_2105_);
lean_ctor_set(v_reuseFailAlloc_2116_, 1, v___x_2106_);
v___x_2108_ = v_reuseFailAlloc_2116_;
goto v_reusejp_2107_;
}
v_reusejp_2107_:
{
lean_object* v___x_2109_; lean_object* v___x_2110_; lean_object* v___x_2111_; lean_object* v___x_2112_; lean_object* v___x_2113_; lean_object* v___x_2114_; 
v___x_2109_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2109_, 0, v___x_2100_);
lean_ctor_set(v___x_2109_, 1, v___x_2108_);
v___x_2110_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2110_, 0, v___x_2096_);
lean_ctor_set(v___x_2110_, 1, v___x_2109_);
v___x_2111_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2111_, 0, v___x_2091_);
lean_ctor_set(v___x_2111_, 1, v___x_2110_);
v___x_2112_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2112_, 0, v___x_2087_);
lean_ctor_set(v___x_2112_, 1, v___x_2111_);
v___x_2113_ = l_Lean_Json_mkObj(v___x_2112_);
lean_dec_ref_known(v___x_2112_, 2);
v___x_2114_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2114_, 0, v___x_2113_);
lean_ctor_set(v___x_2114_, 1, v_a_2069_);
v_a_2068_ = v_tail_2073_;
v_a_2069_ = v___x_2114_;
goto _start;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__20___boxed(lean_object* v_a_2129_, lean_object* v_a_2130_, lean_object* v_a_2131_){
_start:
{
lean_object* v_res_2132_; 
v_res_2132_ = l_List_mapTR_loop___at___00BudgetWorker_bench_spec__20(v_a_2129_, v_a_2130_, v_a_2131_);
lean_dec(v_a_2129_);
return v_res_2132_;
}
}
LEAN_EXPORT uint8_t l_List_beq___at___00BudgetWorker_bench_spec__15(lean_object* v_x_2133_, lean_object* v_x_2134_){
_start:
{
if (lean_obj_tag(v_x_2133_) == 0)
{
if (lean_obj_tag(v_x_2134_) == 0)
{
uint8_t v___x_2135_; 
v___x_2135_ = 1;
return v___x_2135_;
}
else
{
uint8_t v___x_2136_; 
v___x_2136_ = 0;
return v___x_2136_;
}
}
else
{
if (lean_obj_tag(v_x_2134_) == 0)
{
uint8_t v___x_2137_; 
v___x_2137_ = 0;
return v___x_2137_;
}
else
{
lean_object* v_head_2138_; lean_object* v_tail_2139_; lean_object* v_head_2140_; lean_object* v_tail_2141_; uint8_t v___x_2142_; 
v_head_2138_ = lean_ctor_get(v_x_2133_, 0);
v_tail_2139_ = lean_ctor_get(v_x_2133_, 1);
v_head_2140_ = lean_ctor_get(v_x_2134_, 0);
v_tail_2141_ = lean_ctor_get(v_x_2134_, 1);
v___x_2142_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v_head_2138_, v_head_2140_);
if (v___x_2142_ == 0)
{
return v___x_2142_;
}
else
{
v_x_2133_ = v_tail_2139_;
v_x_2134_ = v_tail_2141_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_beq___at___00BudgetWorker_bench_spec__15___boxed(lean_object* v_x_2144_, lean_object* v_x_2145_){
_start:
{
uint8_t v_res_2146_; lean_object* v_r_2147_; 
v_res_2146_ = l_List_beq___at___00BudgetWorker_bench_spec__15(v_x_2144_, v_x_2145_);
lean_dec(v_x_2145_);
lean_dec(v_x_2144_);
v_r_2147_ = lean_box(v_res_2146_);
return v_r_2147_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__1_spec__1(lean_object* v_j_2148_){
_start:
{
lean_object* v___x_2149_; 
v___x_2149_ = l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonStackTable_fromJson_spec__0_spec__0(v_j_2148_);
if (lean_obj_tag(v___x_2149_) == 0)
{
lean_object* v_a_2150_; lean_object* v___x_2152_; uint8_t v_isShared_2153_; uint8_t v_isSharedCheck_2157_; 
v_a_2150_ = lean_ctor_get(v___x_2149_, 0);
v_isSharedCheck_2157_ = !lean_is_exclusive(v___x_2149_);
if (v_isSharedCheck_2157_ == 0)
{
v___x_2152_ = v___x_2149_;
v_isShared_2153_ = v_isSharedCheck_2157_;
goto v_resetjp_2151_;
}
else
{
lean_inc(v_a_2150_);
lean_dec(v___x_2149_);
v___x_2152_ = lean_box(0);
v_isShared_2153_ = v_isSharedCheck_2157_;
goto v_resetjp_2151_;
}
v_resetjp_2151_:
{
lean_object* v___x_2155_; 
if (v_isShared_2153_ == 0)
{
v___x_2155_ = v___x_2152_;
goto v_reusejp_2154_;
}
else
{
lean_object* v_reuseFailAlloc_2156_; 
v_reuseFailAlloc_2156_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2156_, 0, v_a_2150_);
v___x_2155_ = v_reuseFailAlloc_2156_;
goto v_reusejp_2154_;
}
v_reusejp_2154_:
{
return v___x_2155_;
}
}
}
else
{
lean_object* v_a_2158_; lean_object* v___x_2160_; uint8_t v_isShared_2161_; uint8_t v_isSharedCheck_2166_; 
v_a_2158_ = lean_ctor_get(v___x_2149_, 0);
v_isSharedCheck_2166_ = !lean_is_exclusive(v___x_2149_);
if (v_isSharedCheck_2166_ == 0)
{
v___x_2160_ = v___x_2149_;
v_isShared_2161_ = v_isSharedCheck_2166_;
goto v_resetjp_2159_;
}
else
{
lean_inc(v_a_2158_);
lean_dec(v___x_2149_);
v___x_2160_ = lean_box(0);
v_isShared_2161_ = v_isSharedCheck_2166_;
goto v_resetjp_2159_;
}
v_resetjp_2159_:
{
lean_object* v___x_2162_; lean_object* v___x_2164_; 
v___x_2162_ = lean_array_to_list(v_a_2158_);
if (v_isShared_2161_ == 0)
{
lean_ctor_set(v___x_2160_, 0, v___x_2162_);
v___x_2164_ = v___x_2160_;
goto v_reusejp_2163_;
}
else
{
lean_object* v_reuseFailAlloc_2165_; 
v_reuseFailAlloc_2165_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2165_, 0, v___x_2162_);
v___x_2164_ = v_reuseFailAlloc_2165_;
goto v_reusejp_2163_;
}
v_reusejp_2163_:
{
return v___x_2164_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__1(lean_object* v_j_2167_, lean_object* v_k_2168_){
_start:
{
lean_object* v___x_2169_; lean_object* v___x_2170_; 
v___x_2169_ = l_Lean_Json_getObjValD(v_j_2167_, v_k_2168_);
v___x_2170_ = l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__1_spec__1(v___x_2169_);
return v___x_2170_;
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__1___boxed(lean_object* v_j_2171_, lean_object* v_k_2172_){
_start:
{
lean_object* v_res_2173_; 
v_res_2173_ = l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__1(v_j_2171_, v_k_2172_);
lean_dec_ref(v_k_2172_);
return v_res_2173_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00BudgetWorker_bench_spec__22(lean_object* v_a_2174_){
_start:
{
lean_object* v___x_2175_; lean_object* v___x_2176_; 
v___x_2175_ = lean_array_mk(v_a_2174_);
v___x_2176_ = l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__0(v___x_2175_);
return v___x_2176_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__19(lean_object* v_a_2177_, lean_object* v_a_2178_, lean_object* v_a_2179_){
_start:
{
if (lean_obj_tag(v_a_2178_) == 0)
{
lean_object* v___x_2180_; 
v___x_2180_ = l_List_reverse___redArg(v_a_2179_);
return v___x_2180_;
}
else
{
lean_object* v_head_2181_; lean_object* v_tail_2182_; lean_object* v___x_2184_; uint8_t v_isShared_2185_; uint8_t v_isSharedCheck_2193_; 
v_head_2181_ = lean_ctor_get(v_a_2178_, 0);
v_tail_2182_ = lean_ctor_get(v_a_2178_, 1);
v_isSharedCheck_2193_ = !lean_is_exclusive(v_a_2178_);
if (v_isSharedCheck_2193_ == 0)
{
v___x_2184_ = v_a_2178_;
v_isShared_2185_ = v_isSharedCheck_2193_;
goto v_resetjp_2183_;
}
else
{
lean_inc(v_tail_2182_);
lean_inc(v_head_2181_);
lean_dec(v_a_2178_);
v___x_2184_ = lean_box(0);
v_isShared_2185_ = v_isSharedCheck_2193_;
goto v_resetjp_2183_;
}
v_resetjp_2183_:
{
uint8_t v___x_2186_; lean_object* v___x_2187_; lean_object* v_time_2188_; lean_object* v___x_2190_; 
v___x_2186_ = lean_unbox(v_head_2181_);
lean_dec(v_head_2181_);
v___x_2187_ = l_LeanSort_BudgetSelection_Engine_feature___at___00LeanSort_BudgetSelection_counted_spec__0(v___x_2186_, v_a_2177_);
v_time_2188_ = lean_ctor_get(v___x_2187_, 1);
lean_inc(v_time_2188_);
lean_dec_ref(v___x_2187_);
if (v_isShared_2185_ == 0)
{
lean_ctor_set(v___x_2184_, 1, v_a_2179_);
lean_ctor_set(v___x_2184_, 0, v_time_2188_);
v___x_2190_ = v___x_2184_;
goto v_reusejp_2189_;
}
else
{
lean_object* v_reuseFailAlloc_2192_; 
v_reuseFailAlloc_2192_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2192_, 0, v_time_2188_);
lean_ctor_set(v_reuseFailAlloc_2192_, 1, v_a_2179_);
v___x_2190_ = v_reuseFailAlloc_2192_;
goto v_reusejp_2189_;
}
v_reusejp_2189_:
{
v_a_2178_ = v_tail_2182_;
v_a_2179_ = v___x_2190_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_bench_spec__19___boxed(lean_object* v_a_2194_, lean_object* v_a_2195_, lean_object* v_a_2196_){
_start:
{
lean_object* v_res_2197_; 
v_res_2197_ = l_List_mapTR_loop___at___00BudgetWorker_bench_spec__19(v_a_2194_, v_a_2195_, v_a_2196_);
lean_dec(v_a_2194_);
return v_res_2197_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00BudgetWorker_bench_spec__21_spec__24_spec__26(size_t v_sz_2198_, size_t v_i_2199_, lean_object* v_bs_2200_){
_start:
{
uint8_t v___x_2201_; 
v___x_2201_ = lean_usize_dec_lt(v_i_2199_, v_sz_2198_);
if (v___x_2201_ == 0)
{
return v_bs_2200_;
}
else
{
lean_object* v_v_2202_; lean_object* v___x_2203_; lean_object* v_bs_x27_2204_; lean_object* v___x_2205_; size_t v___x_2206_; size_t v___x_2207_; lean_object* v___x_2208_; 
v_v_2202_ = lean_array_uget(v_bs_2200_, v_i_2199_);
v___x_2203_ = lean_unsigned_to_nat(0u);
v_bs_x27_2204_ = lean_array_uset(v_bs_2200_, v_i_2199_, v___x_2203_);
v___x_2205_ = l_Lean_List_toJson___at___00BudgetWorker_bench_spec__22(v_v_2202_);
v___x_2206_ = ((size_t)1ULL);
v___x_2207_ = lean_usize_add(v_i_2199_, v___x_2206_);
v___x_2208_ = lean_array_uset(v_bs_x27_2204_, v_i_2199_, v___x_2205_);
v_i_2199_ = v___x_2207_;
v_bs_2200_ = v___x_2208_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00BudgetWorker_bench_spec__21_spec__24_spec__26___boxed(lean_object* v_sz_2210_, lean_object* v_i_2211_, lean_object* v_bs_2212_){
_start:
{
size_t v_sz_boxed_2213_; size_t v_i_boxed_2214_; lean_object* v_res_2215_; 
v_sz_boxed_2213_ = lean_unbox_usize(v_sz_2210_);
lean_dec(v_sz_2210_);
v_i_boxed_2214_ = lean_unbox_usize(v_i_2211_);
lean_dec(v_i_2211_);
v_res_2215_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00BudgetWorker_bench_spec__21_spec__24_spec__26(v_sz_boxed_2213_, v_i_boxed_2214_, v_bs_2212_);
return v_res_2215_;
}
}
LEAN_EXPORT lean_object* l_Lean_Array_toJson___at___00Lean_List_toJson___at___00BudgetWorker_bench_spec__21_spec__24(lean_object* v_a_2216_){
_start:
{
size_t v_sz_2217_; size_t v___x_2218_; lean_object* v___x_2219_; lean_object* v___x_2220_; 
v_sz_2217_ = lean_array_size(v_a_2216_);
v___x_2218_ = ((size_t)0ULL);
v___x_2219_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00BudgetWorker_bench_spec__21_spec__24_spec__26(v_sz_2217_, v___x_2218_, v_a_2216_);
v___x_2220_ = lean_alloc_ctor(4, 1, 0);
lean_ctor_set(v___x_2220_, 0, v___x_2219_);
return v___x_2220_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00BudgetWorker_bench_spec__21(lean_object* v_a_2221_){
_start:
{
lean_object* v___x_2222_; lean_object* v___x_2223_; 
v___x_2222_ = lean_array_mk(v_a_2221_);
v___x_2223_ = l_Lean_Array_toJson___at___00Lean_List_toJson___at___00BudgetWorker_bench_spec__21_spec__24(v___x_2222_);
return v___x_2223_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7_spec__27(size_t v_sz_2224_, size_t v_i_2225_, lean_object* v_bs_2226_){
_start:
{
uint8_t v___x_2227_; 
v___x_2227_ = lean_usize_dec_lt(v_i_2225_, v_sz_2224_);
if (v___x_2227_ == 0)
{
lean_object* v___x_2228_; 
v___x_2228_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_2228_, 0, v_bs_2226_);
return v___x_2228_;
}
else
{
lean_object* v_v_2229_; lean_object* v___x_2230_; 
v_v_2229_ = lean_array_uget_borrowed(v_bs_2226_, v_i_2225_);
lean_inc(v_v_2229_);
v___x_2230_ = l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__1_spec__1(v_v_2229_);
if (lean_obj_tag(v___x_2230_) == 0)
{
lean_object* v_a_2231_; lean_object* v___x_2233_; uint8_t v_isShared_2234_; uint8_t v_isSharedCheck_2238_; 
lean_dec_ref(v_bs_2226_);
v_a_2231_ = lean_ctor_get(v___x_2230_, 0);
v_isSharedCheck_2238_ = !lean_is_exclusive(v___x_2230_);
if (v_isSharedCheck_2238_ == 0)
{
v___x_2233_ = v___x_2230_;
v_isShared_2234_ = v_isSharedCheck_2238_;
goto v_resetjp_2232_;
}
else
{
lean_inc(v_a_2231_);
lean_dec(v___x_2230_);
v___x_2233_ = lean_box(0);
v_isShared_2234_ = v_isSharedCheck_2238_;
goto v_resetjp_2232_;
}
v_resetjp_2232_:
{
lean_object* v___x_2236_; 
if (v_isShared_2234_ == 0)
{
v___x_2236_ = v___x_2233_;
goto v_reusejp_2235_;
}
else
{
lean_object* v_reuseFailAlloc_2237_; 
v_reuseFailAlloc_2237_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2237_, 0, v_a_2231_);
v___x_2236_ = v_reuseFailAlloc_2237_;
goto v_reusejp_2235_;
}
v_reusejp_2235_:
{
return v___x_2236_;
}
}
}
else
{
lean_object* v_a_2239_; lean_object* v___x_2240_; lean_object* v_bs_x27_2241_; size_t v___x_2242_; size_t v___x_2243_; lean_object* v___x_2244_; 
v_a_2239_ = lean_ctor_get(v___x_2230_, 0);
lean_inc(v_a_2239_);
lean_dec_ref_known(v___x_2230_, 1);
v___x_2240_ = lean_unsigned_to_nat(0u);
v_bs_x27_2241_ = lean_array_uset(v_bs_2226_, v_i_2225_, v___x_2240_);
v___x_2242_ = ((size_t)1ULL);
v___x_2243_ = lean_usize_add(v_i_2225_, v___x_2242_);
v___x_2244_ = lean_array_uset(v_bs_x27_2241_, v_i_2225_, v_a_2239_);
v_i_2225_ = v___x_2243_;
v_bs_2226_ = v___x_2244_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7_spec__27___boxed(lean_object* v_sz_2246_, lean_object* v_i_2247_, lean_object* v_bs_2248_){
_start:
{
size_t v_sz_boxed_2249_; size_t v_i_boxed_2250_; lean_object* v_res_2251_; 
v_sz_boxed_2249_ = lean_unbox_usize(v_sz_2246_);
lean_dec(v_sz_2246_);
v_i_boxed_2250_ = lean_unbox_usize(v_i_2247_);
lean_dec(v_i_2247_);
v_res_2251_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7_spec__27(v_sz_boxed_2249_, v_i_boxed_2250_, v_bs_2248_);
return v_res_2251_;
}
}
LEAN_EXPORT lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7(lean_object* v_x_2254_){
_start:
{
if (lean_obj_tag(v_x_2254_) == 4)
{
lean_object* v_elems_2255_; size_t v_sz_2256_; size_t v___x_2257_; lean_object* v___x_2258_; 
v_elems_2255_ = lean_ctor_get(v_x_2254_, 0);
lean_inc_ref(v_elems_2255_);
lean_dec_ref_known(v_x_2254_, 1);
v_sz_2256_ = lean_array_size(v_elems_2255_);
v___x_2257_ = ((size_t)0ULL);
v___x_2258_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7_spec__27(v_sz_2256_, v___x_2257_, v_elems_2255_);
return v___x_2258_;
}
else
{
lean_object* v___x_2259_; lean_object* v___x_2260_; lean_object* v___x_2261_; lean_object* v___x_2262_; lean_object* v___x_2263_; lean_object* v___x_2264_; lean_object* v___x_2265_; 
v___x_2259_ = ((lean_object*)(l_Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7___closed__0));
v___x_2260_ = lean_unsigned_to_nat(80u);
v___x_2261_ = l_Lean_Json_pretty(v_x_2254_, v___x_2260_);
v___x_2262_ = lean_string_append(v___x_2259_, v___x_2261_);
lean_dec_ref(v___x_2261_);
v___x_2263_ = ((lean_object*)(l_Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7___closed__1));
v___x_2264_ = lean_string_append(v___x_2262_, v___x_2263_);
v___x_2265_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2265_, 0, v___x_2264_);
return v___x_2265_;
}
}
}
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6(lean_object* v_j_2266_){
_start:
{
lean_object* v___x_2267_; 
v___x_2267_ = l_Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6_spec__7(v_j_2266_);
if (lean_obj_tag(v___x_2267_) == 0)
{
lean_object* v_a_2268_; lean_object* v___x_2270_; uint8_t v_isShared_2271_; uint8_t v_isSharedCheck_2275_; 
v_a_2268_ = lean_ctor_get(v___x_2267_, 0);
v_isSharedCheck_2275_ = !lean_is_exclusive(v___x_2267_);
if (v_isSharedCheck_2275_ == 0)
{
v___x_2270_ = v___x_2267_;
v_isShared_2271_ = v_isSharedCheck_2275_;
goto v_resetjp_2269_;
}
else
{
lean_inc(v_a_2268_);
lean_dec(v___x_2267_);
v___x_2270_ = lean_box(0);
v_isShared_2271_ = v_isSharedCheck_2275_;
goto v_resetjp_2269_;
}
v_resetjp_2269_:
{
lean_object* v___x_2273_; 
if (v_isShared_2271_ == 0)
{
v___x_2273_ = v___x_2270_;
goto v_reusejp_2272_;
}
else
{
lean_object* v_reuseFailAlloc_2274_; 
v_reuseFailAlloc_2274_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2274_, 0, v_a_2268_);
v___x_2273_ = v_reuseFailAlloc_2274_;
goto v_reusejp_2272_;
}
v_reusejp_2272_:
{
return v___x_2273_;
}
}
}
else
{
lean_object* v_a_2276_; lean_object* v___x_2278_; uint8_t v_isShared_2279_; uint8_t v_isSharedCheck_2284_; 
v_a_2276_ = lean_ctor_get(v___x_2267_, 0);
v_isSharedCheck_2284_ = !lean_is_exclusive(v___x_2267_);
if (v_isSharedCheck_2284_ == 0)
{
v___x_2278_ = v___x_2267_;
v_isShared_2279_ = v_isSharedCheck_2284_;
goto v_resetjp_2277_;
}
else
{
lean_inc(v_a_2276_);
lean_dec(v___x_2267_);
v___x_2278_ = lean_box(0);
v_isShared_2279_ = v_isSharedCheck_2284_;
goto v_resetjp_2277_;
}
v_resetjp_2277_:
{
lean_object* v___x_2280_; lean_object* v___x_2282_; 
v___x_2280_ = lean_array_to_list(v_a_2276_);
if (v_isShared_2279_ == 0)
{
lean_ctor_set(v___x_2278_, 0, v___x_2280_);
v___x_2282_ = v___x_2278_;
goto v_reusejp_2281_;
}
else
{
lean_object* v_reuseFailAlloc_2283_; 
v_reuseFailAlloc_2283_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2283_, 0, v___x_2280_);
v___x_2282_ = v_reuseFailAlloc_2283_;
goto v_reusejp_2281_;
}
v_reusejp_2281_:
{
return v___x_2282_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4(lean_object* v_j_2285_, lean_object* v_k_2286_){
_start:
{
lean_object* v___x_2287_; lean_object* v___x_2288_; 
v___x_2287_ = l_Lean_Json_getObjValD(v_j_2285_, v_k_2286_);
v___x_2288_ = l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4_spec__6(v___x_2287_);
return v___x_2288_;
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4___boxed(lean_object* v_j_2289_, lean_object* v_k_2290_){
_start:
{
lean_object* v_res_2291_; 
v_res_2291_ = l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4(v_j_2289_, v_k_2290_);
lean_dec_ref(v_k_2290_);
return v_res_2291_;
}
}
static lean_object* _init_l_BudgetWorker_bench___closed__9(void){
_start:
{
lean_object* v___x_2302_; lean_object* v___x_2303_; 
v___x_2302_ = lean_unsigned_to_nat(7u);
v___x_2303_ = l_List_range(v___x_2302_);
return v___x_2303_;
}
}
static lean_object* _init_l_BudgetWorker_bench___closed__10(void){
_start:
{
lean_object* v___x_2304_; lean_object* v___x_2305_; lean_object* v___x_2306_; 
v___x_2304_ = lean_box(0);
v___x_2305_ = lean_obj_once(&l_BudgetWorker_bench___closed__9, &l_BudgetWorker_bench___closed__9_once, _init_l_BudgetWorker_bench___closed__9);
v___x_2306_ = l_List_mapTR_loop___at___00BudgetWorker_bench_spec__8(v___x_2305_, v___x_2304_);
return v___x_2306_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_bench(lean_object* v_registry_2315_, lean_object* v_j_2316_){
_start:
{
lean_object* v___x_2318_; lean_object* v___x_2319_; lean_object* v___x_2320_; 
v___x_2318_ = ((lean_object*)(l_BudgetWorker_bench___closed__0));
lean_inc(v_j_2316_);
v___x_2319_ = l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__1(v_j_2316_, v___x_2318_);
v___x_2320_ = l_BudgetWorker_orError___redArg(v___x_2319_);
if (lean_obj_tag(v___x_2320_) == 0)
{
lean_object* v_a_2321_; lean_object* v___x_2322_; lean_object* v___x_2323_; lean_object* v___x_2324_; 
v_a_2321_ = lean_ctor_get(v___x_2320_, 0);
lean_inc(v_a_2321_);
lean_dec_ref_known(v___x_2320_, 1);
v___x_2322_ = ((lean_object*)(l_BudgetWorker_bench___closed__1));
lean_inc(v_j_2316_);
v___x_2323_ = l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__1(v_j_2316_, v___x_2322_);
v___x_2324_ = l_BudgetWorker_orError___redArg(v___x_2323_);
if (lean_obj_tag(v___x_2324_) == 0)
{
lean_object* v_a_2325_; lean_object* v___x_2326_; lean_object* v___x_2327_; lean_object* v___x_2328_; 
v_a_2325_ = lean_ctor_get(v___x_2324_, 0);
lean_inc(v_a_2325_);
lean_dec_ref_known(v___x_2324_, 1);
v___x_2326_ = ((lean_object*)(l_BudgetWorker_bench___closed__2));
lean_inc(v_j_2316_);
v___x_2327_ = l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__4(v_j_2316_, v___x_2326_);
v___x_2328_ = l_BudgetWorker_orError___redArg(v___x_2327_);
if (lean_obj_tag(v___x_2328_) == 0)
{
lean_object* v_a_2329_; lean_object* v___x_2330_; lean_object* v___x_2331_; lean_object* v___x_2332_; 
v_a_2329_ = lean_ctor_get(v___x_2328_, 0);
lean_inc(v_a_2329_);
lean_dec_ref_known(v___x_2328_, 1);
v___x_2330_ = ((lean_object*)(l_BudgetWorker_bench___closed__3));
lean_inc(v_j_2316_);
v___x_2331_ = l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__1(v_j_2316_, v___x_2330_);
v___x_2332_ = l_BudgetWorker_orError___redArg(v___x_2331_);
if (lean_obj_tag(v___x_2332_) == 0)
{
lean_object* v_a_2333_; lean_object* v___x_2334_; lean_object* v___x_2335_; lean_object* v___x_2336_; 
v_a_2333_ = lean_ctor_get(v___x_2332_, 0);
lean_inc(v_a_2333_);
lean_dec_ref_known(v___x_2332_, 1);
v___x_2334_ = ((lean_object*)(l_BudgetWorker_bench___closed__4));
lean_inc(v_j_2316_);
v___x_2335_ = lp_LeanSearchClient_Lean_Json_getObjValAs_x3f___at___00LeanSearchClient_getLoogleQueryJson_spec__4(v_j_2316_, v___x_2334_);
v___x_2336_ = l_BudgetWorker_orError___redArg(v___x_2335_);
if (lean_obj_tag(v___x_2336_) == 0)
{
lean_object* v_a_2337_; lean_object* v___x_2338_; lean_object* v___x_2339_; lean_object* v___x_2340_; 
v_a_2337_ = lean_ctor_get(v___x_2336_, 0);
lean_inc(v_a_2337_);
lean_dec_ref_known(v___x_2336_, 1);
v___x_2338_ = ((lean_object*)(l_BudgetWorker_bench___closed__5));
lean_inc(v_j_2316_);
v___x_2339_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_2316_, v___x_2338_);
v___x_2340_ = l_BudgetWorker_orError___redArg(v___x_2339_);
if (lean_obj_tag(v___x_2340_) == 0)
{
lean_object* v_a_2341_; lean_object* v___x_2342_; lean_object* v___x_2343_; lean_object* v___x_2344_; 
v_a_2341_ = lean_ctor_get(v___x_2340_, 0);
lean_inc(v_a_2341_);
lean_dec_ref_known(v___x_2340_, 1);
v___x_2342_ = ((lean_object*)(l_BudgetWorker_bench___closed__6));
v___x_2343_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_2316_, v___x_2342_);
v___x_2344_ = l_BudgetWorker_orError___redArg(v___x_2343_);
if (lean_obj_tag(v___x_2344_) == 0)
{
lean_object* v_a_2345_; lean_object* v___x_2347_; uint8_t v_isShared_2348_; uint8_t v_isSharedCheck_2487_; 
v_a_2345_ = lean_ctor_get(v___x_2344_, 0);
v_isSharedCheck_2487_ = !lean_is_exclusive(v___x_2344_);
if (v_isSharedCheck_2487_ == 0)
{
v___x_2347_ = v___x_2344_;
v_isShared_2348_ = v_isSharedCheck_2487_;
goto v_resetjp_2346_;
}
else
{
lean_inc(v_a_2345_);
lean_dec(v___x_2344_);
v___x_2347_ = lean_box(0);
v_isShared_2348_ = v_isSharedCheck_2487_;
goto v_resetjp_2346_;
}
v_resetjp_2346_:
{
uint8_t v___y_2355_; lean_object* v___x_2483_; uint8_t v___x_2484_; 
v___x_2483_ = lean_unsigned_to_nat(1u);
v___x_2484_ = lean_nat_dec_le(v___x_2483_, v_a_2341_);
if (v___x_2484_ == 0)
{
v___y_2355_ = v___x_2484_;
goto v___jp_2354_;
}
else
{
lean_object* v___x_2485_; uint8_t v___x_2486_; 
v___x_2485_ = lean_unsigned_to_nat(9u);
v___x_2486_ = lean_nat_dec_le(v_a_2341_, v___x_2485_);
v___y_2355_ = v___x_2486_;
goto v___jp_2354_;
}
v___jp_2349_:
{
lean_object* v___x_2350_; lean_object* v___x_2352_; 
v___x_2350_ = ((lean_object*)(l_BudgetWorker_bench___closed__8));
if (v_isShared_2348_ == 0)
{
lean_ctor_set_tag(v___x_2347_, 1);
lean_ctor_set(v___x_2347_, 0, v___x_2350_);
v___x_2352_ = v___x_2347_;
goto v_reusejp_2351_;
}
else
{
lean_object* v_reuseFailAlloc_2353_; 
v_reuseFailAlloc_2353_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2353_, 0, v___x_2350_);
v___x_2352_ = v_reuseFailAlloc_2353_;
goto v_reusejp_2351_;
}
v_reusejp_2351_:
{
return v___x_2352_;
}
}
v___jp_2354_:
{
if (v___y_2355_ == 0)
{
lean_dec(v_a_2345_);
lean_dec(v_a_2341_);
lean_dec(v_a_2337_);
lean_dec(v_a_2333_);
lean_dec(v_a_2329_);
lean_dec(v_a_2325_);
lean_dec(v_a_2321_);
goto v___jp_2349_;
}
else
{
lean_object* v___x_2356_; lean_object* v___x_2357_; uint8_t v___x_2358_; 
v___x_2356_ = l_List_lengthTR___redArg(v_a_2333_);
v___x_2357_ = lean_unsigned_to_nat(7u);
v___x_2358_ = lean_nat_dec_eq(v___x_2356_, v___x_2357_);
lean_dec(v___x_2356_);
if (v___x_2358_ == 0)
{
lean_dec(v_a_2345_);
lean_dec(v_a_2341_);
lean_dec(v_a_2337_);
lean_dec(v_a_2333_);
lean_dec(v_a_2329_);
lean_dec(v_a_2325_);
lean_dec(v_a_2321_);
goto v___jp_2349_;
}
else
{
lean_object* v___x_2359_; lean_object* v___x_2360_; 
lean_del_object(v___x_2347_);
v___x_2359_ = lean_box(0);
v___x_2360_ = l_List_mapM_loop___at___00BudgetWorker_bench_spec__5(v_registry_2315_, v_a_2337_, v___x_2359_);
if (lean_obj_tag(v___x_2360_) == 0)
{
lean_object* v_a_2361_; lean_object* v___x_2362_; lean_object* v___x_2363_; lean_object* v___x_2364_; lean_object* v___x_2365_; lean_object* v___x_2366_; lean_object* v___x_2367_; lean_object* v___x_2368_; 
v_a_2361_ = lean_ctor_get(v___x_2360_, 0);
lean_inc(v_a_2361_);
lean_dec_ref_known(v___x_2360_, 1);
lean_inc(v_a_2321_);
v___x_2362_ = lean_st_mk_ref(v_a_2321_);
v___x_2363_ = lean_unsigned_to_nat(0u);
v___x_2364_ = lean_st_mk_ref(v___x_2363_);
v___x_2365_ = lean_st_mk_ref(v___x_2363_);
v___x_2366_ = lean_obj_once(&l_BudgetWorker_bench___closed__9, &l_BudgetWorker_bench___closed__9_once, _init_l_BudgetWorker_bench___closed__9);
v___x_2367_ = lean_box(0);
v___x_2368_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg(v___x_2362_, v___x_2364_, v___x_2365_, v_a_2325_, v___x_2366_, v___x_2367_);
if (lean_obj_tag(v___x_2368_) == 0)
{
lean_object* v___x_2369_; 
lean_dec_ref_known(v___x_2368_, 1);
v___x_2369_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__7___redArg(v___x_2362_, v___x_2364_, v___x_2365_, v_a_2325_, v_a_2361_, v___x_2367_);
if (lean_obj_tag(v___x_2369_) == 0)
{
lean_object* v___x_2370_; lean_object* v___x_2371_; lean_object* v___x_2372_; lean_object* v___x_2373_; lean_object* v___x_2374_; 
lean_dec_ref_known(v___x_2369_, 1);
v___x_2370_ = lean_obj_once(&l_BudgetWorker_bench___closed__10, &l_BudgetWorker_bench___closed__10_once, _init_l_BudgetWorker_bench___closed__10);
lean_inc(v_a_2361_);
v___x_2371_ = l_List_mapTR_loop___at___00BudgetWorker_bench_spec__9(v_a_2361_, v___x_2359_);
v___x_2372_ = l_List_appendTR___redArg(v___x_2370_, v___x_2371_);
v___x_2373_ = l_List_range(v_a_2341_);
v___x_2374_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13___redArg(v___x_2362_, v___x_2364_, v___x_2365_, v_a_2325_, v_a_2345_, v___x_2372_, v___x_2373_, v___x_2367_);
lean_dec(v_a_2345_);
lean_dec(v___x_2364_);
lean_dec(v___x_2362_);
if (lean_obj_tag(v___x_2374_) == 0)
{
lean_object* v___x_2376_; uint8_t v_isShared_2377_; uint8_t v_isSharedCheck_2449_; 
v_isSharedCheck_2449_ = !lean_is_exclusive(v___x_2374_);
if (v_isSharedCheck_2449_ == 0)
{
lean_object* v_unused_2450_; 
v_unused_2450_ = lean_ctor_get(v___x_2374_, 0);
lean_dec(v_unused_2450_);
v___x_2376_ = v___x_2374_;
v_isShared_2377_ = v_isSharedCheck_2449_;
goto v_resetjp_2375_;
}
else
{
lean_dec(v___x_2374_);
v___x_2376_ = lean_box(0);
v_isShared_2377_ = v_isSharedCheck_2449_;
goto v_resetjp_2375_;
}
v_resetjp_2375_:
{
lean_object* v___x_2378_; lean_object* v___x_2379_; uint8_t v___x_2380_; 
v___x_2378_ = ((lean_object*)(l_BudgetWorker_kinds));
v___x_2379_ = l_List_mapTR_loop___at___00BudgetWorker_bench_spec__14(v_a_2321_, v___x_2378_, v___x_2359_);
v___x_2380_ = l_List_beq___at___00BudgetWorker_bench_spec__15(v___x_2379_, v_a_2329_);
lean_dec(v_a_2329_);
if (v___x_2380_ == 0)
{
lean_object* v___x_2381_; lean_object* v___x_2383_; 
lean_dec(v___x_2379_);
lean_dec(v___x_2373_);
lean_dec(v___x_2365_);
lean_dec(v_a_2361_);
lean_dec(v_a_2333_);
lean_dec(v_a_2325_);
lean_dec(v_a_2321_);
v___x_2381_ = ((lean_object*)(l_BudgetWorker_bench___closed__12));
if (v_isShared_2377_ == 0)
{
lean_ctor_set_tag(v___x_2376_, 1);
lean_ctor_set(v___x_2376_, 0, v___x_2381_);
v___x_2383_ = v___x_2376_;
goto v_reusejp_2382_;
}
else
{
lean_object* v_reuseFailAlloc_2384_; 
v_reuseFailAlloc_2384_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2384_, 0, v___x_2381_);
v___x_2383_ = v_reuseFailAlloc_2384_;
goto v_reusejp_2382_;
}
v_reusejp_2382_:
{
return v___x_2383_;
}
}
else
{
lean_object* v___x_2385_; 
lean_del_object(v___x_2376_);
v___x_2385_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___redArg(v_a_2321_, v___x_2378_, v___x_2367_);
if (lean_obj_tag(v___x_2385_) == 0)
{
lean_object* v___x_2386_; 
lean_dec_ref_known(v___x_2385_, 1);
v___x_2386_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__17___redArg(v_a_2321_, v___x_2365_, v___x_2373_, v_a_2361_, v___x_2367_);
lean_dec(v___x_2373_);
lean_dec(v___x_2365_);
if (lean_obj_tag(v___x_2386_) == 0)
{
lean_object* v___x_2387_; 
lean_dec_ref_known(v___x_2386_, 1);
lean_inc(v_a_2321_);
v___x_2387_ = l_List_mapM_loop___at___00BudgetWorker_bench_spec__18(v_a_2321_, v_a_2325_, v_a_2333_, v___x_2366_, v___x_2359_);
lean_dec(v_a_2333_);
lean_dec(v_a_2325_);
if (lean_obj_tag(v___x_2387_) == 0)
{
lean_object* v_a_2388_; lean_object* v___x_2390_; uint8_t v_isShared_2391_; uint8_t v_isSharedCheck_2424_; 
v_a_2388_ = lean_ctor_get(v___x_2387_, 0);
v_isSharedCheck_2424_ = !lean_is_exclusive(v___x_2387_);
if (v_isSharedCheck_2424_ == 0)
{
v___x_2390_ = v___x_2387_;
v_isShared_2391_ = v_isSharedCheck_2424_;
goto v_resetjp_2389_;
}
else
{
lean_inc(v_a_2388_);
lean_dec(v___x_2387_);
v___x_2390_ = lean_box(0);
v_isShared_2391_ = v_isSharedCheck_2424_;
goto v_resetjp_2389_;
}
v_resetjp_2389_:
{
lean_object* v___x_2392_; lean_object* v___x_2393_; lean_object* v___x_2394_; lean_object* v___x_2395_; lean_object* v___x_2396_; lean_object* v___x_2397_; lean_object* v___x_2398_; lean_object* v___x_2399_; lean_object* v___x_2400_; lean_object* v___x_2401_; lean_object* v___x_2402_; lean_object* v___x_2403_; lean_object* v___x_2404_; lean_object* v___x_2405_; lean_object* v___x_2406_; lean_object* v___x_2407_; lean_object* v___x_2408_; lean_object* v___x_2409_; lean_object* v___x_2410_; lean_object* v___x_2411_; lean_object* v___x_2412_; lean_object* v___x_2413_; lean_object* v___x_2414_; lean_object* v___x_2415_; lean_object* v___x_2416_; lean_object* v___x_2417_; lean_object* v___x_2418_; lean_object* v___x_2419_; lean_object* v___x_2420_; lean_object* v___x_2422_; 
v___x_2392_ = l_List_mapTR_loop___at___00BudgetWorker_bench_spec__19(v_a_2321_, v___x_2378_, v___x_2359_);
lean_inc(v_a_2321_);
v___x_2393_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_run___at___00LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0_spec__0_spec__1_spec__3_spec__7(v_a_2321_);
v___x_2394_ = l_List_mapTR_loop___at___00BudgetWorker_bench_spec__20(v_a_2321_, v_a_2361_, v___x_2359_);
lean_dec(v_a_2321_);
v___x_2395_ = ((lean_object*)(l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11___redArg___closed__0));
v___x_2396_ = l_Lean_List_toJson___at___00BudgetWorker_bench_spec__21(v___x_2379_);
v___x_2397_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2397_, 0, v___x_2395_);
lean_ctor_set(v___x_2397_, 1, v___x_2396_);
v___x_2398_ = ((lean_object*)(l_BudgetWorker_bench___closed__13));
v___x_2399_ = l_Lean_List_toJson___at___00BudgetWorker_bench_spec__22(v___x_2392_);
v___x_2400_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2400_, 0, v___x_2398_);
lean_ctor_set(v___x_2400_, 1, v___x_2399_);
v___x_2401_ = ((lean_object*)(l_BudgetWorker_bench___closed__14));
v___x_2402_ = l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(v_a_2388_);
v___x_2403_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2403_, 0, v___x_2401_);
lean_ctor_set(v___x_2403_, 1, v___x_2402_);
v___x_2404_ = ((lean_object*)(l_BudgetWorker_bench___closed__15));
v___x_2405_ = l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(v___x_2394_);
v___x_2406_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2406_, 0, v___x_2404_);
lean_ctor_set(v___x_2406_, 1, v___x_2405_);
v___x_2407_ = ((lean_object*)(l_BudgetWorker_bench___closed__16));
v___x_2408_ = l_List_mapTR_loop___at___00BudgetWorker_bench_spec__23(v___x_2393_, v___x_2359_);
v___x_2409_ = l_Lean_List_toJson___at___00BudgetWorker_bench_spec__22(v___x_2408_);
v___x_2410_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2410_, 0, v___x_2407_);
lean_ctor_set(v___x_2410_, 1, v___x_2409_);
v___x_2411_ = ((lean_object*)(l_BudgetWorker_bench___closed__17));
v___x_2412_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_2412_, 0, v___x_2380_);
v___x_2413_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2413_, 0, v___x_2411_);
lean_ctor_set(v___x_2413_, 1, v___x_2412_);
v___x_2414_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2414_, 0, v___x_2413_);
lean_ctor_set(v___x_2414_, 1, v___x_2359_);
v___x_2415_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2415_, 0, v___x_2410_);
lean_ctor_set(v___x_2415_, 1, v___x_2414_);
v___x_2416_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2416_, 0, v___x_2406_);
lean_ctor_set(v___x_2416_, 1, v___x_2415_);
v___x_2417_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2417_, 0, v___x_2403_);
lean_ctor_set(v___x_2417_, 1, v___x_2416_);
v___x_2418_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2418_, 0, v___x_2400_);
lean_ctor_set(v___x_2418_, 1, v___x_2417_);
v___x_2419_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2419_, 0, v___x_2397_);
lean_ctor_set(v___x_2419_, 1, v___x_2418_);
v___x_2420_ = l_Lean_Json_mkObj(v___x_2419_);
lean_dec_ref_known(v___x_2419_, 2);
if (v_isShared_2391_ == 0)
{
lean_ctor_set(v___x_2390_, 0, v___x_2420_);
v___x_2422_ = v___x_2390_;
goto v_reusejp_2421_;
}
else
{
lean_object* v_reuseFailAlloc_2423_; 
v_reuseFailAlloc_2423_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2423_, 0, v___x_2420_);
v___x_2422_ = v_reuseFailAlloc_2423_;
goto v_reusejp_2421_;
}
v_reusejp_2421_:
{
return v___x_2422_;
}
}
}
else
{
lean_object* v_a_2425_; lean_object* v___x_2427_; uint8_t v_isShared_2428_; uint8_t v_isSharedCheck_2432_; 
lean_dec(v___x_2379_);
lean_dec(v_a_2361_);
lean_dec(v_a_2321_);
v_a_2425_ = lean_ctor_get(v___x_2387_, 0);
v_isSharedCheck_2432_ = !lean_is_exclusive(v___x_2387_);
if (v_isSharedCheck_2432_ == 0)
{
v___x_2427_ = v___x_2387_;
v_isShared_2428_ = v_isSharedCheck_2432_;
goto v_resetjp_2426_;
}
else
{
lean_inc(v_a_2425_);
lean_dec(v___x_2387_);
v___x_2427_ = lean_box(0);
v_isShared_2428_ = v_isSharedCheck_2432_;
goto v_resetjp_2426_;
}
v_resetjp_2426_:
{
lean_object* v___x_2430_; 
if (v_isShared_2428_ == 0)
{
v___x_2430_ = v___x_2427_;
goto v_reusejp_2429_;
}
else
{
lean_object* v_reuseFailAlloc_2431_; 
v_reuseFailAlloc_2431_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2431_, 0, v_a_2425_);
v___x_2430_ = v_reuseFailAlloc_2431_;
goto v_reusejp_2429_;
}
v_reusejp_2429_:
{
return v___x_2430_;
}
}
}
}
else
{
lean_object* v_a_2433_; lean_object* v___x_2435_; uint8_t v_isShared_2436_; uint8_t v_isSharedCheck_2440_; 
lean_dec(v___x_2379_);
lean_dec(v_a_2361_);
lean_dec(v_a_2333_);
lean_dec(v_a_2325_);
lean_dec(v_a_2321_);
v_a_2433_ = lean_ctor_get(v___x_2386_, 0);
v_isSharedCheck_2440_ = !lean_is_exclusive(v___x_2386_);
if (v_isSharedCheck_2440_ == 0)
{
v___x_2435_ = v___x_2386_;
v_isShared_2436_ = v_isSharedCheck_2440_;
goto v_resetjp_2434_;
}
else
{
lean_inc(v_a_2433_);
lean_dec(v___x_2386_);
v___x_2435_ = lean_box(0);
v_isShared_2436_ = v_isSharedCheck_2440_;
goto v_resetjp_2434_;
}
v_resetjp_2434_:
{
lean_object* v___x_2438_; 
if (v_isShared_2436_ == 0)
{
v___x_2438_ = v___x_2435_;
goto v_reusejp_2437_;
}
else
{
lean_object* v_reuseFailAlloc_2439_; 
v_reuseFailAlloc_2439_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2439_, 0, v_a_2433_);
v___x_2438_ = v_reuseFailAlloc_2439_;
goto v_reusejp_2437_;
}
v_reusejp_2437_:
{
return v___x_2438_;
}
}
}
}
else
{
lean_object* v_a_2441_; lean_object* v___x_2443_; uint8_t v_isShared_2444_; uint8_t v_isSharedCheck_2448_; 
lean_dec(v___x_2379_);
lean_dec(v___x_2373_);
lean_dec(v___x_2365_);
lean_dec(v_a_2361_);
lean_dec(v_a_2333_);
lean_dec(v_a_2325_);
lean_dec(v_a_2321_);
v_a_2441_ = lean_ctor_get(v___x_2385_, 0);
v_isSharedCheck_2448_ = !lean_is_exclusive(v___x_2385_);
if (v_isSharedCheck_2448_ == 0)
{
v___x_2443_ = v___x_2385_;
v_isShared_2444_ = v_isSharedCheck_2448_;
goto v_resetjp_2442_;
}
else
{
lean_inc(v_a_2441_);
lean_dec(v___x_2385_);
v___x_2443_ = lean_box(0);
v_isShared_2444_ = v_isSharedCheck_2448_;
goto v_resetjp_2442_;
}
v_resetjp_2442_:
{
lean_object* v___x_2446_; 
if (v_isShared_2444_ == 0)
{
v___x_2446_ = v___x_2443_;
goto v_reusejp_2445_;
}
else
{
lean_object* v_reuseFailAlloc_2447_; 
v_reuseFailAlloc_2447_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2447_, 0, v_a_2441_);
v___x_2446_ = v_reuseFailAlloc_2447_;
goto v_reusejp_2445_;
}
v_reusejp_2445_:
{
return v___x_2446_;
}
}
}
}
}
}
else
{
lean_object* v_a_2451_; lean_object* v___x_2453_; uint8_t v_isShared_2454_; uint8_t v_isSharedCheck_2458_; 
lean_dec(v___x_2373_);
lean_dec(v___x_2365_);
lean_dec(v_a_2361_);
lean_dec(v_a_2333_);
lean_dec(v_a_2329_);
lean_dec(v_a_2325_);
lean_dec(v_a_2321_);
v_a_2451_ = lean_ctor_get(v___x_2374_, 0);
v_isSharedCheck_2458_ = !lean_is_exclusive(v___x_2374_);
if (v_isSharedCheck_2458_ == 0)
{
v___x_2453_ = v___x_2374_;
v_isShared_2454_ = v_isSharedCheck_2458_;
goto v_resetjp_2452_;
}
else
{
lean_inc(v_a_2451_);
lean_dec(v___x_2374_);
v___x_2453_ = lean_box(0);
v_isShared_2454_ = v_isSharedCheck_2458_;
goto v_resetjp_2452_;
}
v_resetjp_2452_:
{
lean_object* v___x_2456_; 
if (v_isShared_2454_ == 0)
{
v___x_2456_ = v___x_2453_;
goto v_reusejp_2455_;
}
else
{
lean_object* v_reuseFailAlloc_2457_; 
v_reuseFailAlloc_2457_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2457_, 0, v_a_2451_);
v___x_2456_ = v_reuseFailAlloc_2457_;
goto v_reusejp_2455_;
}
v_reusejp_2455_:
{
return v___x_2456_;
}
}
}
}
else
{
lean_object* v_a_2459_; lean_object* v___x_2461_; uint8_t v_isShared_2462_; uint8_t v_isSharedCheck_2466_; 
lean_dec(v___x_2365_);
lean_dec(v___x_2364_);
lean_dec(v___x_2362_);
lean_dec(v_a_2361_);
lean_dec(v_a_2345_);
lean_dec(v_a_2341_);
lean_dec(v_a_2333_);
lean_dec(v_a_2329_);
lean_dec(v_a_2325_);
lean_dec(v_a_2321_);
v_a_2459_ = lean_ctor_get(v___x_2369_, 0);
v_isSharedCheck_2466_ = !lean_is_exclusive(v___x_2369_);
if (v_isSharedCheck_2466_ == 0)
{
v___x_2461_ = v___x_2369_;
v_isShared_2462_ = v_isSharedCheck_2466_;
goto v_resetjp_2460_;
}
else
{
lean_inc(v_a_2459_);
lean_dec(v___x_2369_);
v___x_2461_ = lean_box(0);
v_isShared_2462_ = v_isSharedCheck_2466_;
goto v_resetjp_2460_;
}
v_resetjp_2460_:
{
lean_object* v___x_2464_; 
if (v_isShared_2462_ == 0)
{
v___x_2464_ = v___x_2461_;
goto v_reusejp_2463_;
}
else
{
lean_object* v_reuseFailAlloc_2465_; 
v_reuseFailAlloc_2465_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2465_, 0, v_a_2459_);
v___x_2464_ = v_reuseFailAlloc_2465_;
goto v_reusejp_2463_;
}
v_reusejp_2463_:
{
return v___x_2464_;
}
}
}
}
else
{
lean_object* v_a_2467_; lean_object* v___x_2469_; uint8_t v_isShared_2470_; uint8_t v_isSharedCheck_2474_; 
lean_dec(v___x_2365_);
lean_dec(v___x_2364_);
lean_dec(v___x_2362_);
lean_dec(v_a_2361_);
lean_dec(v_a_2345_);
lean_dec(v_a_2341_);
lean_dec(v_a_2333_);
lean_dec(v_a_2329_);
lean_dec(v_a_2325_);
lean_dec(v_a_2321_);
v_a_2467_ = lean_ctor_get(v___x_2368_, 0);
v_isSharedCheck_2474_ = !lean_is_exclusive(v___x_2368_);
if (v_isSharedCheck_2474_ == 0)
{
v___x_2469_ = v___x_2368_;
v_isShared_2470_ = v_isSharedCheck_2474_;
goto v_resetjp_2468_;
}
else
{
lean_inc(v_a_2467_);
lean_dec(v___x_2368_);
v___x_2469_ = lean_box(0);
v_isShared_2470_ = v_isSharedCheck_2474_;
goto v_resetjp_2468_;
}
v_resetjp_2468_:
{
lean_object* v___x_2472_; 
if (v_isShared_2470_ == 0)
{
v___x_2472_ = v___x_2469_;
goto v_reusejp_2471_;
}
else
{
lean_object* v_reuseFailAlloc_2473_; 
v_reuseFailAlloc_2473_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2473_, 0, v_a_2467_);
v___x_2472_ = v_reuseFailAlloc_2473_;
goto v_reusejp_2471_;
}
v_reusejp_2471_:
{
return v___x_2472_;
}
}
}
}
else
{
lean_object* v_a_2475_; lean_object* v___x_2477_; uint8_t v_isShared_2478_; uint8_t v_isSharedCheck_2482_; 
lean_dec(v_a_2345_);
lean_dec(v_a_2341_);
lean_dec(v_a_2333_);
lean_dec(v_a_2329_);
lean_dec(v_a_2325_);
lean_dec(v_a_2321_);
v_a_2475_ = lean_ctor_get(v___x_2360_, 0);
v_isSharedCheck_2482_ = !lean_is_exclusive(v___x_2360_);
if (v_isSharedCheck_2482_ == 0)
{
v___x_2477_ = v___x_2360_;
v_isShared_2478_ = v_isSharedCheck_2482_;
goto v_resetjp_2476_;
}
else
{
lean_inc(v_a_2475_);
lean_dec(v___x_2360_);
v___x_2477_ = lean_box(0);
v_isShared_2478_ = v_isSharedCheck_2482_;
goto v_resetjp_2476_;
}
v_resetjp_2476_:
{
lean_object* v___x_2480_; 
if (v_isShared_2478_ == 0)
{
v___x_2480_ = v___x_2477_;
goto v_reusejp_2479_;
}
else
{
lean_object* v_reuseFailAlloc_2481_; 
v_reuseFailAlloc_2481_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2481_, 0, v_a_2475_);
v___x_2480_ = v_reuseFailAlloc_2481_;
goto v_reusejp_2479_;
}
v_reusejp_2479_:
{
return v___x_2480_;
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
lean_object* v_a_2488_; lean_object* v___x_2490_; uint8_t v_isShared_2491_; uint8_t v_isSharedCheck_2495_; 
lean_dec(v_a_2341_);
lean_dec(v_a_2337_);
lean_dec(v_a_2333_);
lean_dec(v_a_2329_);
lean_dec(v_a_2325_);
lean_dec(v_a_2321_);
v_a_2488_ = lean_ctor_get(v___x_2344_, 0);
v_isSharedCheck_2495_ = !lean_is_exclusive(v___x_2344_);
if (v_isSharedCheck_2495_ == 0)
{
v___x_2490_ = v___x_2344_;
v_isShared_2491_ = v_isSharedCheck_2495_;
goto v_resetjp_2489_;
}
else
{
lean_inc(v_a_2488_);
lean_dec(v___x_2344_);
v___x_2490_ = lean_box(0);
v_isShared_2491_ = v_isSharedCheck_2495_;
goto v_resetjp_2489_;
}
v_resetjp_2489_:
{
lean_object* v___x_2493_; 
if (v_isShared_2491_ == 0)
{
v___x_2493_ = v___x_2490_;
goto v_reusejp_2492_;
}
else
{
lean_object* v_reuseFailAlloc_2494_; 
v_reuseFailAlloc_2494_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2494_, 0, v_a_2488_);
v___x_2493_ = v_reuseFailAlloc_2494_;
goto v_reusejp_2492_;
}
v_reusejp_2492_:
{
return v___x_2493_;
}
}
}
}
else
{
lean_object* v_a_2496_; lean_object* v___x_2498_; uint8_t v_isShared_2499_; uint8_t v_isSharedCheck_2503_; 
lean_dec(v_a_2337_);
lean_dec(v_a_2333_);
lean_dec(v_a_2329_);
lean_dec(v_a_2325_);
lean_dec(v_a_2321_);
lean_dec(v_j_2316_);
v_a_2496_ = lean_ctor_get(v___x_2340_, 0);
v_isSharedCheck_2503_ = !lean_is_exclusive(v___x_2340_);
if (v_isSharedCheck_2503_ == 0)
{
v___x_2498_ = v___x_2340_;
v_isShared_2499_ = v_isSharedCheck_2503_;
goto v_resetjp_2497_;
}
else
{
lean_inc(v_a_2496_);
lean_dec(v___x_2340_);
v___x_2498_ = lean_box(0);
v_isShared_2499_ = v_isSharedCheck_2503_;
goto v_resetjp_2497_;
}
v_resetjp_2497_:
{
lean_object* v___x_2501_; 
if (v_isShared_2499_ == 0)
{
v___x_2501_ = v___x_2498_;
goto v_reusejp_2500_;
}
else
{
lean_object* v_reuseFailAlloc_2502_; 
v_reuseFailAlloc_2502_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2502_, 0, v_a_2496_);
v___x_2501_ = v_reuseFailAlloc_2502_;
goto v_reusejp_2500_;
}
v_reusejp_2500_:
{
return v___x_2501_;
}
}
}
}
else
{
lean_object* v_a_2504_; lean_object* v___x_2506_; uint8_t v_isShared_2507_; uint8_t v_isSharedCheck_2511_; 
lean_dec(v_a_2333_);
lean_dec(v_a_2329_);
lean_dec(v_a_2325_);
lean_dec(v_a_2321_);
lean_dec(v_j_2316_);
v_a_2504_ = lean_ctor_get(v___x_2336_, 0);
v_isSharedCheck_2511_ = !lean_is_exclusive(v___x_2336_);
if (v_isSharedCheck_2511_ == 0)
{
v___x_2506_ = v___x_2336_;
v_isShared_2507_ = v_isSharedCheck_2511_;
goto v_resetjp_2505_;
}
else
{
lean_inc(v_a_2504_);
lean_dec(v___x_2336_);
v___x_2506_ = lean_box(0);
v_isShared_2507_ = v_isSharedCheck_2511_;
goto v_resetjp_2505_;
}
v_resetjp_2505_:
{
lean_object* v___x_2509_; 
if (v_isShared_2507_ == 0)
{
v___x_2509_ = v___x_2506_;
goto v_reusejp_2508_;
}
else
{
lean_object* v_reuseFailAlloc_2510_; 
v_reuseFailAlloc_2510_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2510_, 0, v_a_2504_);
v___x_2509_ = v_reuseFailAlloc_2510_;
goto v_reusejp_2508_;
}
v_reusejp_2508_:
{
return v___x_2509_;
}
}
}
}
else
{
lean_object* v_a_2512_; lean_object* v___x_2514_; uint8_t v_isShared_2515_; uint8_t v_isSharedCheck_2519_; 
lean_dec(v_a_2329_);
lean_dec(v_a_2325_);
lean_dec(v_a_2321_);
lean_dec(v_j_2316_);
v_a_2512_ = lean_ctor_get(v___x_2332_, 0);
v_isSharedCheck_2519_ = !lean_is_exclusive(v___x_2332_);
if (v_isSharedCheck_2519_ == 0)
{
v___x_2514_ = v___x_2332_;
v_isShared_2515_ = v_isSharedCheck_2519_;
goto v_resetjp_2513_;
}
else
{
lean_inc(v_a_2512_);
lean_dec(v___x_2332_);
v___x_2514_ = lean_box(0);
v_isShared_2515_ = v_isSharedCheck_2519_;
goto v_resetjp_2513_;
}
v_resetjp_2513_:
{
lean_object* v___x_2517_; 
if (v_isShared_2515_ == 0)
{
v___x_2517_ = v___x_2514_;
goto v_reusejp_2516_;
}
else
{
lean_object* v_reuseFailAlloc_2518_; 
v_reuseFailAlloc_2518_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2518_, 0, v_a_2512_);
v___x_2517_ = v_reuseFailAlloc_2518_;
goto v_reusejp_2516_;
}
v_reusejp_2516_:
{
return v___x_2517_;
}
}
}
}
else
{
lean_object* v_a_2520_; lean_object* v___x_2522_; uint8_t v_isShared_2523_; uint8_t v_isSharedCheck_2527_; 
lean_dec(v_a_2325_);
lean_dec(v_a_2321_);
lean_dec(v_j_2316_);
v_a_2520_ = lean_ctor_get(v___x_2328_, 0);
v_isSharedCheck_2527_ = !lean_is_exclusive(v___x_2328_);
if (v_isSharedCheck_2527_ == 0)
{
v___x_2522_ = v___x_2328_;
v_isShared_2523_ = v_isSharedCheck_2527_;
goto v_resetjp_2521_;
}
else
{
lean_inc(v_a_2520_);
lean_dec(v___x_2328_);
v___x_2522_ = lean_box(0);
v_isShared_2523_ = v_isSharedCheck_2527_;
goto v_resetjp_2521_;
}
v_resetjp_2521_:
{
lean_object* v___x_2525_; 
if (v_isShared_2523_ == 0)
{
v___x_2525_ = v___x_2522_;
goto v_reusejp_2524_;
}
else
{
lean_object* v_reuseFailAlloc_2526_; 
v_reuseFailAlloc_2526_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2526_, 0, v_a_2520_);
v___x_2525_ = v_reuseFailAlloc_2526_;
goto v_reusejp_2524_;
}
v_reusejp_2524_:
{
return v___x_2525_;
}
}
}
}
else
{
lean_object* v_a_2528_; lean_object* v___x_2530_; uint8_t v_isShared_2531_; uint8_t v_isSharedCheck_2535_; 
lean_dec(v_a_2321_);
lean_dec(v_j_2316_);
v_a_2528_ = lean_ctor_get(v___x_2324_, 0);
v_isSharedCheck_2535_ = !lean_is_exclusive(v___x_2324_);
if (v_isSharedCheck_2535_ == 0)
{
v___x_2530_ = v___x_2324_;
v_isShared_2531_ = v_isSharedCheck_2535_;
goto v_resetjp_2529_;
}
else
{
lean_inc(v_a_2528_);
lean_dec(v___x_2324_);
v___x_2530_ = lean_box(0);
v_isShared_2531_ = v_isSharedCheck_2535_;
goto v_resetjp_2529_;
}
v_resetjp_2529_:
{
lean_object* v___x_2533_; 
if (v_isShared_2531_ == 0)
{
v___x_2533_ = v___x_2530_;
goto v_reusejp_2532_;
}
else
{
lean_object* v_reuseFailAlloc_2534_; 
v_reuseFailAlloc_2534_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2534_, 0, v_a_2528_);
v___x_2533_ = v_reuseFailAlloc_2534_;
goto v_reusejp_2532_;
}
v_reusejp_2532_:
{
return v___x_2533_;
}
}
}
}
else
{
lean_object* v_a_2536_; lean_object* v___x_2538_; uint8_t v_isShared_2539_; uint8_t v_isSharedCheck_2543_; 
lean_dec(v_j_2316_);
v_a_2536_ = lean_ctor_get(v___x_2320_, 0);
v_isSharedCheck_2543_ = !lean_is_exclusive(v___x_2320_);
if (v_isSharedCheck_2543_ == 0)
{
v___x_2538_ = v___x_2320_;
v_isShared_2539_ = v_isSharedCheck_2543_;
goto v_resetjp_2537_;
}
else
{
lean_inc(v_a_2536_);
lean_dec(v___x_2320_);
v___x_2538_ = lean_box(0);
v_isShared_2539_ = v_isSharedCheck_2543_;
goto v_resetjp_2537_;
}
v_resetjp_2537_:
{
lean_object* v___x_2541_; 
if (v_isShared_2539_ == 0)
{
v___x_2541_ = v___x_2538_;
goto v_reusejp_2540_;
}
else
{
lean_object* v_reuseFailAlloc_2542_; 
v_reuseFailAlloc_2542_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2542_, 0, v_a_2536_);
v___x_2541_ = v_reuseFailAlloc_2542_;
goto v_reusejp_2540_;
}
v_reusejp_2540_:
{
return v___x_2541_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_bench___boxed(lean_object* v_registry_2544_, lean_object* v_j_2545_, lean_object* v_a_2546_){
_start:
{
lean_object* v_res_2547_; 
v_res_2547_ = l_BudgetWorker_bench(v_registry_2544_, v_j_2545_);
lean_dec(v_registry_2544_);
return v_res_2547_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6(lean_object* v_val_2548_, lean_object* v_val_2549_, lean_object* v_val_2550_, lean_object* v_a_2551_, lean_object* v_as_2552_, lean_object* v_as_x27_2553_, lean_object* v_b_2554_, lean_object* v_a_2555_){
_start:
{
lean_object* v___x_2557_; 
v___x_2557_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___redArg(v_val_2548_, v_val_2549_, v_val_2550_, v_a_2551_, v_as_x27_2553_, v_b_2554_);
return v___x_2557_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6___boxed(lean_object* v_val_2558_, lean_object* v_val_2559_, lean_object* v_val_2560_, lean_object* v_a_2561_, lean_object* v_as_2562_, lean_object* v_as_x27_2563_, lean_object* v_b_2564_, lean_object* v_a_2565_, lean_object* v___y_2566_){
_start:
{
lean_object* v_res_2567_; 
v_res_2567_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__6(v_val_2558_, v_val_2559_, v_val_2560_, v_a_2561_, v_as_2562_, v_as_x27_2563_, v_b_2564_, v_a_2565_);
lean_dec(v_as_x27_2563_);
lean_dec(v_as_2562_);
lean_dec(v_a_2561_);
lean_dec(v_val_2560_);
lean_dec(v_val_2559_);
lean_dec(v_val_2558_);
return v_res_2567_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__7(lean_object* v_val_2568_, lean_object* v_val_2569_, lean_object* v_val_2570_, lean_object* v_a_2571_, lean_object* v_as_2572_, lean_object* v_as_x27_2573_, lean_object* v_b_2574_, lean_object* v_a_2575_){
_start:
{
lean_object* v___x_2577_; 
v___x_2577_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__7___redArg(v_val_2568_, v_val_2569_, v_val_2570_, v_a_2571_, v_as_x27_2573_, v_b_2574_);
return v___x_2577_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__7___boxed(lean_object* v_val_2578_, lean_object* v_val_2579_, lean_object* v_val_2580_, lean_object* v_a_2581_, lean_object* v_as_2582_, lean_object* v_as_x27_2583_, lean_object* v_b_2584_, lean_object* v_a_2585_, lean_object* v___y_2586_){
_start:
{
lean_object* v_res_2587_; 
v_res_2587_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__7(v_val_2578_, v_val_2579_, v_val_2580_, v_a_2581_, v_as_2582_, v_as_x27_2583_, v_b_2584_, v_a_2585_);
lean_dec(v_as_x27_2583_);
lean_dec(v_as_2582_);
lean_dec(v_a_2581_);
lean_dec(v_val_2580_);
lean_dec(v_val_2579_);
lean_dec(v_val_2578_);
return v_res_2587_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__10(lean_object* v_a_2588_, lean_object* v_val_2589_, lean_object* v_val_2590_, lean_object* v_val_2591_, lean_object* v_a_2592_, lean_object* v_as_2593_, lean_object* v_as_x27_2594_, lean_object* v_b_2595_, lean_object* v_a_2596_){
_start:
{
lean_object* v___x_2598_; 
v___x_2598_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__10___redArg(v_a_2588_, v_val_2589_, v_val_2590_, v_val_2591_, v_a_2592_, v_as_x27_2594_, v_b_2595_);
return v___x_2598_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__10___boxed(lean_object* v_a_2599_, lean_object* v_val_2600_, lean_object* v_val_2601_, lean_object* v_val_2602_, lean_object* v_a_2603_, lean_object* v_as_2604_, lean_object* v_as_x27_2605_, lean_object* v_b_2606_, lean_object* v_a_2607_, lean_object* v___y_2608_){
_start:
{
lean_object* v_res_2609_; 
v_res_2609_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__10(v_a_2599_, v_val_2600_, v_val_2601_, v_val_2602_, v_a_2603_, v_as_2604_, v_as_x27_2605_, v_b_2606_, v_a_2607_);
lean_dec(v_as_x27_2605_);
lean_dec(v_as_2604_);
lean_dec(v_a_2603_);
lean_dec(v_val_2602_);
lean_dec(v_val_2601_);
lean_dec(v_val_2600_);
return v_res_2609_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11(lean_object* v_val_2610_, lean_object* v_val_2611_, lean_object* v_a_2612_, lean_object* v_as_2613_, lean_object* v_as_x27_2614_, lean_object* v_b_2615_, lean_object* v_a_2616_){
_start:
{
lean_object* v___x_2618_; 
v___x_2618_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11___redArg(v_val_2610_, v_val_2611_, v_a_2612_, v_as_x27_2614_, v_b_2615_);
return v___x_2618_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11___boxed(lean_object* v_val_2619_, lean_object* v_val_2620_, lean_object* v_a_2621_, lean_object* v_as_2622_, lean_object* v_as_x27_2623_, lean_object* v_b_2624_, lean_object* v_a_2625_, lean_object* v___y_2626_){
_start:
{
lean_object* v_res_2627_; 
v_res_2627_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11(v_val_2619_, v_val_2620_, v_a_2621_, v_as_2622_, v_as_x27_2623_, v_b_2624_, v_a_2625_);
lean_dec(v_as_x27_2623_);
lean_dec(v_as_2622_);
lean_dec(v_val_2620_);
lean_dec(v_val_2619_);
return v_res_2627_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12(lean_object* v_snd_2628_, lean_object* v_val_2629_, lean_object* v_val_2630_, lean_object* v___x_2631_, lean_object* v_fst_2632_, lean_object* v_as_2633_, lean_object* v_as_x27_2634_, lean_object* v_b_2635_, lean_object* v_a_2636_){
_start:
{
lean_object* v___x_2638_; 
v___x_2638_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12___redArg(v_snd_2628_, v_val_2629_, v_val_2630_, v___x_2631_, v_fst_2632_, v_as_x27_2634_, v_b_2635_);
return v___x_2638_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12___boxed(lean_object* v_snd_2639_, lean_object* v_val_2640_, lean_object* v_val_2641_, lean_object* v___x_2642_, lean_object* v_fst_2643_, lean_object* v_as_2644_, lean_object* v_as_x27_2645_, lean_object* v_b_2646_, lean_object* v_a_2647_, lean_object* v___y_2648_){
_start:
{
lean_object* v_res_2649_; 
v_res_2649_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__12(v_snd_2639_, v_val_2640_, v_val_2641_, v___x_2642_, v_fst_2643_, v_as_2644_, v_as_x27_2645_, v_b_2646_, v_a_2647_);
lean_dec(v_as_x27_2645_);
lean_dec(v_as_2644_);
lean_dec(v___x_2642_);
lean_dec(v_val_2641_);
lean_dec(v_val_2640_);
return v_res_2649_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13(lean_object* v_val_2650_, lean_object* v_val_2651_, lean_object* v_val_2652_, lean_object* v_a_2653_, lean_object* v_a_2654_, lean_object* v___x_2655_, lean_object* v_as_2656_, lean_object* v_as_x27_2657_, lean_object* v_b_2658_, lean_object* v_a_2659_){
_start:
{
lean_object* v___x_2661_; 
v___x_2661_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13___redArg(v_val_2650_, v_val_2651_, v_val_2652_, v_a_2653_, v_a_2654_, v___x_2655_, v_as_x27_2657_, v_b_2658_);
return v___x_2661_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13___boxed(lean_object* v_val_2662_, lean_object* v_val_2663_, lean_object* v_val_2664_, lean_object* v_a_2665_, lean_object* v_a_2666_, lean_object* v___x_2667_, lean_object* v_as_2668_, lean_object* v_as_x27_2669_, lean_object* v_b_2670_, lean_object* v_a_2671_, lean_object* v___y_2672_){
_start:
{
lean_object* v_res_2673_; 
v_res_2673_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__13(v_val_2662_, v_val_2663_, v_val_2664_, v_a_2665_, v_a_2666_, v___x_2667_, v_as_2668_, v_as_x27_2669_, v_b_2670_, v_a_2671_);
lean_dec(v_as_x27_2669_);
lean_dec(v_as_2668_);
lean_dec(v_a_2666_);
lean_dec(v_a_2665_);
lean_dec(v_val_2664_);
lean_dec(v_val_2663_);
lean_dec(v_val_2662_);
return v_res_2673_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16(lean_object* v_a_2674_, lean_object* v_as_2675_, lean_object* v_as_x27_2676_, lean_object* v_b_2677_, lean_object* v_a_2678_){
_start:
{
lean_object* v___x_2680_; 
v___x_2680_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___redArg(v_a_2674_, v_as_x27_2676_, v_b_2677_);
return v___x_2680_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16___boxed(lean_object* v_a_2681_, lean_object* v_as_2682_, lean_object* v_as_x27_2683_, lean_object* v_b_2684_, lean_object* v_a_2685_, lean_object* v___y_2686_){
_start:
{
lean_object* v_res_2687_; 
v_res_2687_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__16(v_a_2681_, v_as_2682_, v_as_x27_2683_, v_b_2684_, v_a_2685_);
lean_dec(v_as_x27_2683_);
lean_dec(v_as_2682_);
lean_dec(v_a_2681_);
return v_res_2687_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__17(lean_object* v_a_2688_, lean_object* v_val_2689_, lean_object* v___x_2690_, lean_object* v_as_2691_, lean_object* v_as_x27_2692_, lean_object* v_b_2693_, lean_object* v_a_2694_){
_start:
{
lean_object* v___x_2696_; 
v___x_2696_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__17___redArg(v_a_2688_, v_val_2689_, v___x_2690_, v_as_x27_2692_, v_b_2693_);
return v___x_2696_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__17___boxed(lean_object* v_a_2697_, lean_object* v_val_2698_, lean_object* v___x_2699_, lean_object* v_as_2700_, lean_object* v_as_x27_2701_, lean_object* v_b_2702_, lean_object* v_a_2703_, lean_object* v___y_2704_){
_start:
{
lean_object* v_res_2705_; 
v_res_2705_ = l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__17(v_a_2697_, v_val_2698_, v___x_2699_, v_as_2700_, v_as_x27_2701_, v_b_2702_, v_a_2703_);
lean_dec(v_as_x27_2701_);
lean_dec(v_as_2700_);
lean_dec(v___x_2699_);
lean_dec(v_val_2698_);
lean_dec(v_a_2697_);
return v_res_2705_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00BudgetWorker_handle_spec__0(lean_object* v_a_2707_, lean_object* v_a_2708_, lean_object* v_a_2709_){
_start:
{
if (lean_obj_tag(v_a_2708_) == 0)
{
lean_object* v___x_2710_; 
lean_dec(v_a_2707_);
v___x_2710_ = l_List_reverse___redArg(v_a_2709_);
return v___x_2710_;
}
else
{
lean_object* v_head_2711_; lean_object* v_snd_2712_; lean_object* v_tail_2713_; lean_object* v___x_2715_; uint8_t v_isShared_2716_; uint8_t v_isSharedCheck_2771_; 
v_head_2711_ = lean_ctor_get(v_a_2708_, 0);
lean_inc(v_head_2711_);
v_snd_2712_ = lean_ctor_get(v_head_2711_, 1);
lean_inc(v_snd_2712_);
v_tail_2713_ = lean_ctor_get(v_a_2708_, 1);
v_isSharedCheck_2771_ = !lean_is_exclusive(v_a_2708_);
if (v_isSharedCheck_2771_ == 0)
{
lean_object* v_unused_2772_; 
v_unused_2772_ = lean_ctor_get(v_a_2708_, 0);
lean_dec(v_unused_2772_);
v___x_2715_ = v_a_2708_;
v_isShared_2716_ = v_isSharedCheck_2771_;
goto v_resetjp_2714_;
}
else
{
lean_inc(v_tail_2713_);
lean_dec(v_a_2708_);
v___x_2715_ = lean_box(0);
v_isShared_2716_ = v_isSharedCheck_2771_;
goto v_resetjp_2714_;
}
v_resetjp_2714_:
{
lean_object* v_fst_2717_; lean_object* v___x_2719_; uint8_t v_isShared_2720_; uint8_t v_isSharedCheck_2769_; 
v_fst_2717_ = lean_ctor_get(v_head_2711_, 0);
v_isSharedCheck_2769_ = !lean_is_exclusive(v_head_2711_);
if (v_isSharedCheck_2769_ == 0)
{
lean_object* v_unused_2770_; 
v_unused_2770_ = lean_ctor_get(v_head_2711_, 1);
lean_dec(v_unused_2770_);
v___x_2719_ = v_head_2711_;
v_isShared_2720_ = v_isSharedCheck_2769_;
goto v_resetjp_2718_;
}
else
{
lean_inc(v_fst_2717_);
lean_dec(v_head_2711_);
v___x_2719_ = lean_box(0);
v_isShared_2720_ = v_isSharedCheck_2769_;
goto v_resetjp_2718_;
}
v_resetjp_2718_:
{
uint8_t v_featureSet_2721_; lean_object* v_choice_2722_; lean_object* v___x_2723_; lean_object* v___x_2724_; lean_object* v___x_2725_; lean_object* v___x_2727_; 
v_featureSet_2721_ = lean_ctor_get_uint8(v_snd_2712_, sizeof(void*)*1);
v_choice_2722_ = lean_ctor_get(v_snd_2712_, 0);
lean_inc_ref(v_choice_2722_);
v___x_2723_ = l_LeanSort_BudgetSelection_features(v_featureSet_2721_, v_a_2707_);
v___x_2724_ = ((lean_object*)(l_BudgetWorker_sampleEvent___closed__5));
v___x_2725_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_2725_, 0, v_fst_2717_);
if (v_isShared_2720_ == 0)
{
lean_ctor_set(v___x_2719_, 1, v___x_2725_);
lean_ctor_set(v___x_2719_, 0, v___x_2724_);
v___x_2727_ = v___x_2719_;
goto v_reusejp_2726_;
}
else
{
lean_object* v_reuseFailAlloc_2768_; 
v_reuseFailAlloc_2768_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2768_, 0, v___x_2724_);
lean_ctor_set(v_reuseFailAlloc_2768_, 1, v___x_2725_);
v___x_2727_ = v_reuseFailAlloc_2768_;
goto v_reusejp_2726_;
}
v_reusejp_2726_:
{
lean_object* v___x_2728_; lean_object* v___x_2729_; lean_object* v___x_2730_; lean_object* v___x_2731_; lean_object* v___x_2732_; lean_object* v___x_2733_; lean_object* v___x_2734_; lean_object* v___x_2735_; lean_object* v___x_2736_; lean_object* v___x_2737_; lean_object* v___x_2738_; lean_object* v___x_2739_; lean_object* v___x_2740_; lean_object* v___x_2741_; lean_object* v___x_2742_; lean_object* v___x_2743_; lean_object* v___x_2744_; lean_object* v___y_2746_; 
v___x_2728_ = ((lean_object*)(l_List_forIn_x27_loop___at___00BudgetWorker_bench_spec__11___redArg___closed__0));
lean_inc(v___x_2723_);
v___x_2729_ = l_Lean_List_toJson___at___00BudgetWorker_bench_spec__22(v___x_2723_);
v___x_2730_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2730_, 0, v___x_2728_);
lean_ctor_set(v___x_2730_, 1, v___x_2729_);
v___x_2731_ = ((lean_object*)(l_List_mapTR_loop___at___00BudgetWorker_bench_spec__20___closed__0));
lean_inc(v_snd_2712_);
v___x_2732_ = l_LeanSort_BudgetSelection_select(v_snd_2712_, v_a_2707_);
lean_inc(v___x_2732_);
v___x_2733_ = l_Lean_Option_toJson___at___00BudgetWorker_bench_spec__2(v___x_2732_);
v___x_2734_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2734_, 0, v___x_2731_);
lean_ctor_set(v___x_2734_, 1, v___x_2733_);
v___x_2735_ = ((lean_object*)(l_BudgetWorker_sampleEvent___closed__8));
v___x_2736_ = l_LeanSort_LearnedSelection_resolve(v___x_2732_);
lean_dec(v___x_2732_);
v___x_2737_ = l_Lean_JsonNumber_fromNat(v___x_2736_);
v___x_2738_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2738_, 0, v___x_2737_);
v___x_2739_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2739_, 0, v___x_2735_);
lean_ctor_set(v___x_2739_, 1, v___x_2738_);
v___x_2740_ = ((lean_object*)(l_List_mapTR_loop___at___00BudgetWorker_handle_spec__0___closed__0));
lean_inc(v_a_2707_);
v___x_2741_ = l_LeanSort_BudgetSelection_run(v_snd_2712_, v_a_2707_);
v___x_2742_ = l_Lean_List_toJson___at___00BudgetWorker_bench_spec__22(v___x_2741_);
v___x_2743_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2743_, 0, v___x_2740_);
lean_ctor_set(v___x_2743_, 1, v___x_2742_);
v___x_2744_ = ((lean_object*)(l_BudgetWorker_decodeTree___closed__11));
if (lean_obj_tag(v_choice_2722_) == 2)
{
lean_object* v_model_2761_; 
v_model_2761_ = lean_ctor_get(v_choice_2722_, 0);
lean_inc(v_model_2761_);
lean_dec_ref_known(v_choice_2722_, 1);
switch(lean_obj_tag(v_model_2761_))
{
case 1:
{
lean_object* v_tree_2762_; lean_object* v___x_2763_; 
v_tree_2762_ = lean_ctor_get(v_model_2761_, 0);
lean_inc_ref(v_tree_2762_);
lean_dec_ref_known(v_model_2761_, 1);
v___x_2763_ = l_LeanSort_LearnedSelection_Tree_eval(v_tree_2762_, v___x_2723_);
lean_dec(v___x_2723_);
v___y_2746_ = v___x_2763_;
goto v___jp_2745_;
}
case 2:
{
lean_object* v_tree_2764_; lean_object* v___x_2765_; 
v_tree_2764_ = lean_ctor_get(v_model_2761_, 0);
lean_inc_ref(v_tree_2764_);
lean_dec_ref_known(v_model_2761_, 1);
v___x_2765_ = l_LeanSort_LearnedSelection_Tree_eval(v_tree_2764_, v___x_2723_);
lean_dec(v___x_2723_);
v___y_2746_ = v___x_2765_;
goto v___jp_2745_;
}
default: 
{
lean_object* v___x_2766_; 
lean_dec(v_model_2761_);
lean_dec(v___x_2723_);
v___x_2766_ = lean_box(0);
v___y_2746_ = v___x_2766_;
goto v___jp_2745_;
}
}
}
else
{
lean_object* v___x_2767_; 
lean_dec(v___x_2723_);
lean_dec_ref(v_choice_2722_);
v___x_2767_ = lean_box(0);
v___y_2746_ = v___x_2767_;
goto v___jp_2745_;
}
v___jp_2745_:
{
lean_object* v___x_2747_; lean_object* v___x_2748_; lean_object* v___x_2749_; lean_object* v___x_2751_; 
v___x_2747_ = l_Lean_Option_toJson___at___00BudgetWorker_bench_spec__3(v___y_2746_);
v___x_2748_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2748_, 0, v___x_2744_);
lean_ctor_set(v___x_2748_, 1, v___x_2747_);
v___x_2749_ = lean_box(0);
if (v_isShared_2716_ == 0)
{
lean_ctor_set(v___x_2715_, 1, v___x_2749_);
lean_ctor_set(v___x_2715_, 0, v___x_2748_);
v___x_2751_ = v___x_2715_;
goto v_reusejp_2750_;
}
else
{
lean_object* v_reuseFailAlloc_2760_; 
v_reuseFailAlloc_2760_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2760_, 0, v___x_2748_);
lean_ctor_set(v_reuseFailAlloc_2760_, 1, v___x_2749_);
v___x_2751_ = v_reuseFailAlloc_2760_;
goto v_reusejp_2750_;
}
v_reusejp_2750_:
{
lean_object* v___x_2752_; lean_object* v___x_2753_; lean_object* v___x_2754_; lean_object* v___x_2755_; lean_object* v___x_2756_; lean_object* v___x_2757_; lean_object* v___x_2758_; 
v___x_2752_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2752_, 0, v___x_2743_);
lean_ctor_set(v___x_2752_, 1, v___x_2751_);
v___x_2753_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2753_, 0, v___x_2739_);
lean_ctor_set(v___x_2753_, 1, v___x_2752_);
v___x_2754_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2754_, 0, v___x_2734_);
lean_ctor_set(v___x_2754_, 1, v___x_2753_);
v___x_2755_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2755_, 0, v___x_2730_);
lean_ctor_set(v___x_2755_, 1, v___x_2754_);
v___x_2756_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2756_, 0, v___x_2727_);
lean_ctor_set(v___x_2756_, 1, v___x_2755_);
v___x_2757_ = l_Lean_Json_mkObj(v___x_2756_);
lean_dec_ref_known(v___x_2756_, 2);
v___x_2758_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2758_, 0, v___x_2757_);
lean_ctor_set(v___x_2758_, 1, v_a_2709_);
v_a_2708_ = v_tail_2713_;
v_a_2709_ = v___x_2758_;
goto _start;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_handle_spec__1_spec__1(lean_object* v_j_2773_){
_start:
{
lean_object* v___x_2774_; 
v___x_2774_ = l_Lean_Array_fromJson_x3f___at___00Lean_Widget_instRpcEncodableStrictOrLazy_dec_00___x40_Lean_Widget_InteractiveDiagnostic_2157017296____hygCtx___hyg_1____at___00Lean_Widget_instRpcEncodableHighlightedMsgEmbed_dec_00___x40_Lean_Server_FileWorker_WidgetRequests_2377472685____hygCtx___hyg_1__spec__2_spec__3(v_j_2773_);
if (lean_obj_tag(v___x_2774_) == 0)
{
lean_object* v_a_2775_; lean_object* v___x_2777_; uint8_t v_isShared_2778_; uint8_t v_isSharedCheck_2782_; 
v_a_2775_ = lean_ctor_get(v___x_2774_, 0);
v_isSharedCheck_2782_ = !lean_is_exclusive(v___x_2774_);
if (v_isSharedCheck_2782_ == 0)
{
v___x_2777_ = v___x_2774_;
v_isShared_2778_ = v_isSharedCheck_2782_;
goto v_resetjp_2776_;
}
else
{
lean_inc(v_a_2775_);
lean_dec(v___x_2774_);
v___x_2777_ = lean_box(0);
v_isShared_2778_ = v_isSharedCheck_2782_;
goto v_resetjp_2776_;
}
v_resetjp_2776_:
{
lean_object* v___x_2780_; 
if (v_isShared_2778_ == 0)
{
v___x_2780_ = v___x_2777_;
goto v_reusejp_2779_;
}
else
{
lean_object* v_reuseFailAlloc_2781_; 
v_reuseFailAlloc_2781_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2781_, 0, v_a_2775_);
v___x_2780_ = v_reuseFailAlloc_2781_;
goto v_reusejp_2779_;
}
v_reusejp_2779_:
{
return v___x_2780_;
}
}
}
else
{
lean_object* v_a_2783_; lean_object* v___x_2785_; uint8_t v_isShared_2786_; uint8_t v_isSharedCheck_2791_; 
v_a_2783_ = lean_ctor_get(v___x_2774_, 0);
v_isSharedCheck_2791_ = !lean_is_exclusive(v___x_2774_);
if (v_isSharedCheck_2791_ == 0)
{
v___x_2785_ = v___x_2774_;
v_isShared_2786_ = v_isSharedCheck_2791_;
goto v_resetjp_2784_;
}
else
{
lean_inc(v_a_2783_);
lean_dec(v___x_2774_);
v___x_2785_ = lean_box(0);
v_isShared_2786_ = v_isSharedCheck_2791_;
goto v_resetjp_2784_;
}
v_resetjp_2784_:
{
lean_object* v___x_2787_; lean_object* v___x_2789_; 
v___x_2787_ = lean_array_to_list(v_a_2783_);
if (v_isShared_2786_ == 0)
{
lean_ctor_set(v___x_2785_, 0, v___x_2787_);
v___x_2789_ = v___x_2785_;
goto v_reusejp_2788_;
}
else
{
lean_object* v_reuseFailAlloc_2790_; 
v_reuseFailAlloc_2790_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2790_, 0, v___x_2787_);
v___x_2789_ = v_reuseFailAlloc_2790_;
goto v_reusejp_2788_;
}
v_reusejp_2788_:
{
return v___x_2789_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_handle_spec__1(lean_object* v_j_2792_, lean_object* v_k_2793_){
_start:
{
lean_object* v___x_2794_; lean_object* v___x_2795_; 
v___x_2794_ = l_Lean_Json_getObjValD(v_j_2792_, v_k_2793_);
v___x_2795_ = l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00BudgetWorker_handle_spec__1_spec__1(v___x_2794_);
return v___x_2795_;
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_handle_spec__1___boxed(lean_object* v_j_2796_, lean_object* v_k_2797_){
_start:
{
lean_object* v_res_2798_; 
v_res_2798_ = l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_handle_spec__1(v_j_2796_, v_k_2797_);
lean_dec_ref(v_k_2797_);
return v_res_2798_;
}
}
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00BudgetWorker_handle_spec__2(lean_object* v_x_2799_, lean_object* v_x_2800_){
_start:
{
if (lean_obj_tag(v_x_2799_) == 0)
{
lean_object* v___x_2802_; lean_object* v___x_2803_; 
v___x_2802_ = l_List_reverse___redArg(v_x_2800_);
v___x_2803_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2803_, 0, v___x_2802_);
return v___x_2803_;
}
else
{
lean_object* v_head_2804_; lean_object* v_tail_2805_; lean_object* v___x_2807_; uint8_t v_isShared_2808_; uint8_t v_isSharedCheck_2839_; 
v_head_2804_ = lean_ctor_get(v_x_2799_, 0);
v_tail_2805_ = lean_ctor_get(v_x_2799_, 1);
v_isSharedCheck_2839_ = !lean_is_exclusive(v_x_2799_);
if (v_isSharedCheck_2839_ == 0)
{
v___x_2807_ = v_x_2799_;
v_isShared_2808_ = v_isSharedCheck_2839_;
goto v_resetjp_2806_;
}
else
{
lean_inc(v_tail_2805_);
lean_inc(v_head_2804_);
lean_dec(v_x_2799_);
v___x_2807_ = lean_box(0);
v_isShared_2808_ = v_isSharedCheck_2839_;
goto v_resetjp_2806_;
}
v_resetjp_2806_:
{
lean_object* v___x_2809_; lean_object* v___x_2810_; lean_object* v___x_2811_; 
v___x_2809_ = ((lean_object*)(l_BudgetWorker_sampleEvent___closed__5));
lean_inc(v_head_2804_);
v___x_2810_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_head_2804_, v___x_2809_);
v___x_2811_ = l_BudgetWorker_orError___redArg(v___x_2810_);
if (lean_obj_tag(v___x_2811_) == 0)
{
lean_object* v_a_2812_; lean_object* v___x_2813_; lean_object* v___x_2814_; lean_object* v___x_2815_; 
v_a_2812_ = lean_ctor_get(v___x_2811_, 0);
lean_inc(v_a_2812_);
lean_dec_ref_known(v___x_2811_, 1);
v___x_2813_ = ((lean_object*)(l_List_mapTR_loop___at___00BudgetWorker_bench_spec__9___closed__0));
v___x_2814_ = l_Lean_Json_getObjVal_x3f(v_head_2804_, v___x_2813_);
v___x_2815_ = l_BudgetWorker_orError___redArg(v___x_2814_);
if (lean_obj_tag(v___x_2815_) == 0)
{
lean_object* v_a_2816_; lean_object* v___x_2817_; lean_object* v___x_2818_; lean_object* v___x_2820_; 
v_a_2816_ = lean_ctor_get(v___x_2815_, 0);
lean_inc(v_a_2816_);
lean_dec_ref_known(v___x_2815_, 1);
v___x_2817_ = l_BudgetWorker_decodePolicy(v_a_2816_);
v___x_2818_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2818_, 0, v_a_2812_);
lean_ctor_set(v___x_2818_, 1, v___x_2817_);
if (v_isShared_2808_ == 0)
{
lean_ctor_set(v___x_2807_, 1, v_x_2800_);
lean_ctor_set(v___x_2807_, 0, v___x_2818_);
v___x_2820_ = v___x_2807_;
goto v_reusejp_2819_;
}
else
{
lean_object* v_reuseFailAlloc_2822_; 
v_reuseFailAlloc_2822_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2822_, 0, v___x_2818_);
lean_ctor_set(v_reuseFailAlloc_2822_, 1, v_x_2800_);
v___x_2820_ = v_reuseFailAlloc_2822_;
goto v_reusejp_2819_;
}
v_reusejp_2819_:
{
v_x_2799_ = v_tail_2805_;
v_x_2800_ = v___x_2820_;
goto _start;
}
}
else
{
lean_object* v_a_2823_; lean_object* v___x_2825_; uint8_t v_isShared_2826_; uint8_t v_isSharedCheck_2830_; 
lean_dec(v_a_2812_);
lean_del_object(v___x_2807_);
lean_dec(v_tail_2805_);
lean_dec(v_x_2800_);
v_a_2823_ = lean_ctor_get(v___x_2815_, 0);
v_isSharedCheck_2830_ = !lean_is_exclusive(v___x_2815_);
if (v_isSharedCheck_2830_ == 0)
{
v___x_2825_ = v___x_2815_;
v_isShared_2826_ = v_isSharedCheck_2830_;
goto v_resetjp_2824_;
}
else
{
lean_inc(v_a_2823_);
lean_dec(v___x_2815_);
v___x_2825_ = lean_box(0);
v_isShared_2826_ = v_isSharedCheck_2830_;
goto v_resetjp_2824_;
}
v_resetjp_2824_:
{
lean_object* v___x_2828_; 
if (v_isShared_2826_ == 0)
{
v___x_2828_ = v___x_2825_;
goto v_reusejp_2827_;
}
else
{
lean_object* v_reuseFailAlloc_2829_; 
v_reuseFailAlloc_2829_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2829_, 0, v_a_2823_);
v___x_2828_ = v_reuseFailAlloc_2829_;
goto v_reusejp_2827_;
}
v_reusejp_2827_:
{
return v___x_2828_;
}
}
}
}
else
{
lean_object* v_a_2831_; lean_object* v___x_2833_; uint8_t v_isShared_2834_; uint8_t v_isSharedCheck_2838_; 
lean_del_object(v___x_2807_);
lean_dec(v_tail_2805_);
lean_dec(v_head_2804_);
lean_dec(v_x_2800_);
v_a_2831_ = lean_ctor_get(v___x_2811_, 0);
v_isSharedCheck_2838_ = !lean_is_exclusive(v___x_2811_);
if (v_isSharedCheck_2838_ == 0)
{
v___x_2833_ = v___x_2811_;
v_isShared_2834_ = v_isSharedCheck_2838_;
goto v_resetjp_2832_;
}
else
{
lean_inc(v_a_2831_);
lean_dec(v___x_2811_);
v___x_2833_ = lean_box(0);
v_isShared_2834_ = v_isSharedCheck_2838_;
goto v_resetjp_2832_;
}
v_resetjp_2832_:
{
lean_object* v___x_2836_; 
if (v_isShared_2834_ == 0)
{
v___x_2836_ = v___x_2833_;
goto v_reusejp_2835_;
}
else
{
lean_object* v_reuseFailAlloc_2837_; 
v_reuseFailAlloc_2837_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2837_, 0, v_a_2831_);
v___x_2836_ = v_reuseFailAlloc_2837_;
goto v_reusejp_2835_;
}
v_reusejp_2835_:
{
return v___x_2836_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00BudgetWorker_handle_spec__2___boxed(lean_object* v_x_2840_, lean_object* v_x_2841_, lean_object* v___y_2842_){
_start:
{
lean_object* v_res_2843_; 
v_res_2843_ = l_List_mapM_loop___at___00BudgetWorker_handle_spec__2(v_x_2840_, v_x_2841_);
return v_res_2843_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_handle(lean_object* v_state_2853_, lean_object* v_j_2854_){
_start:
{
lean_object* v___x_2856_; lean_object* v___x_2857_; lean_object* v___x_2858_; 
v___x_2856_ = ((lean_object*)(l_BudgetWorker_handle___closed__0));
lean_inc(v_j_2854_);
v___x_2857_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_j_2854_, v___x_2856_);
v___x_2858_ = l_BudgetWorker_orError___redArg(v___x_2857_);
if (lean_obj_tag(v___x_2858_) == 0)
{
lean_object* v_a_2859_; lean_object* v___x_2861_; uint8_t v_isShared_2862_; uint8_t v_isSharedCheck_2940_; 
v_a_2859_ = lean_ctor_get(v___x_2858_, 0);
v_isSharedCheck_2940_ = !lean_is_exclusive(v___x_2858_);
if (v_isSharedCheck_2940_ == 0)
{
v___x_2861_ = v___x_2858_;
v_isShared_2862_ = v_isSharedCheck_2940_;
goto v_resetjp_2860_;
}
else
{
lean_inc(v_a_2859_);
lean_dec(v___x_2858_);
v___x_2861_ = lean_box(0);
v_isShared_2862_ = v_isSharedCheck_2940_;
goto v_resetjp_2860_;
}
v_resetjp_2860_:
{
lean_object* v___x_2863_; uint8_t v___x_2864_; 
v___x_2863_ = ((lean_object*)(l_BudgetWorker_handle___closed__1));
v___x_2864_ = lean_string_dec_eq(v_a_2859_, v___x_2863_);
if (v___x_2864_ == 0)
{
lean_object* v___x_2865_; uint8_t v___x_2866_; 
v___x_2865_ = ((lean_object*)(l_BudgetWorker_handle___closed__2));
v___x_2866_ = lean_string_dec_eq(v_a_2859_, v___x_2865_);
if (v___x_2866_ == 0)
{
lean_object* v___x_2867_; uint8_t v___x_2868_; 
v___x_2867_ = ((lean_object*)(l_BudgetWorker_handle___closed__3));
v___x_2868_ = lean_string_dec_eq(v_a_2859_, v___x_2867_);
lean_dec(v_a_2859_);
if (v___x_2868_ == 0)
{
lean_object* v___x_2869_; lean_object* v___x_2871_; 
lean_dec(v_j_2854_);
v___x_2869_ = ((lean_object*)(l_BudgetWorker_handle___closed__5));
if (v_isShared_2862_ == 0)
{
lean_ctor_set_tag(v___x_2861_, 1);
lean_ctor_set(v___x_2861_, 0, v___x_2869_);
v___x_2871_ = v___x_2861_;
goto v_reusejp_2870_;
}
else
{
lean_object* v_reuseFailAlloc_2872_; 
v_reuseFailAlloc_2872_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2872_, 0, v___x_2869_);
v___x_2871_ = v_reuseFailAlloc_2872_;
goto v_reusejp_2870_;
}
v_reusejp_2870_:
{
return v___x_2871_;
}
}
else
{
lean_object* v___x_2873_; lean_object* v___x_2874_; lean_object* v___x_2875_; 
lean_del_object(v___x_2861_);
v___x_2873_ = ((lean_object*)(l_BudgetWorker_bench___closed__0));
v___x_2874_ = l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_bench_spec__1(v_j_2854_, v___x_2873_);
v___x_2875_ = l_BudgetWorker_orError___redArg(v___x_2874_);
if (lean_obj_tag(v___x_2875_) == 0)
{
lean_object* v_a_2876_; lean_object* v___x_2878_; uint8_t v_isShared_2879_; uint8_t v_isSharedCheck_2891_; 
v_a_2876_ = lean_ctor_get(v___x_2875_, 0);
v_isSharedCheck_2891_ = !lean_is_exclusive(v___x_2875_);
if (v_isSharedCheck_2891_ == 0)
{
v___x_2878_ = v___x_2875_;
v_isShared_2879_ = v_isSharedCheck_2891_;
goto v_resetjp_2877_;
}
else
{
lean_inc(v_a_2876_);
lean_dec(v___x_2875_);
v___x_2878_ = lean_box(0);
v_isShared_2879_ = v_isSharedCheck_2891_;
goto v_resetjp_2877_;
}
v_resetjp_2877_:
{
lean_object* v___x_2880_; lean_object* v___x_2881_; lean_object* v___x_2882_; lean_object* v___x_2883_; lean_object* v___x_2884_; lean_object* v___x_2885_; lean_object* v___x_2886_; lean_object* v___x_2887_; lean_object* v___x_2889_; 
v___x_2880_ = lean_st_ref_get(v_state_2853_);
v___x_2881_ = lean_box(0);
v___x_2882_ = l_List_mapTR_loop___at___00BudgetWorker_handle_spec__0(v_a_2876_, v___x_2880_, v___x_2881_);
v___x_2883_ = ((lean_object*)(l_BudgetWorker_handle___closed__6));
v___x_2884_ = l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(v___x_2882_);
v___x_2885_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2885_, 0, v___x_2883_);
lean_ctor_set(v___x_2885_, 1, v___x_2884_);
v___x_2886_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2886_, 0, v___x_2885_);
lean_ctor_set(v___x_2886_, 1, v___x_2881_);
v___x_2887_ = l_Lean_Json_mkObj(v___x_2886_);
lean_dec_ref_known(v___x_2886_, 2);
if (v_isShared_2879_ == 0)
{
lean_ctor_set(v___x_2878_, 0, v___x_2887_);
v___x_2889_ = v___x_2878_;
goto v_reusejp_2888_;
}
else
{
lean_object* v_reuseFailAlloc_2890_; 
v_reuseFailAlloc_2890_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2890_, 0, v___x_2887_);
v___x_2889_ = v_reuseFailAlloc_2890_;
goto v_reusejp_2888_;
}
v_reusejp_2888_:
{
return v___x_2889_;
}
}
}
else
{
lean_object* v_a_2892_; lean_object* v___x_2894_; uint8_t v_isShared_2895_; uint8_t v_isSharedCheck_2899_; 
v_a_2892_ = lean_ctor_get(v___x_2875_, 0);
v_isSharedCheck_2899_ = !lean_is_exclusive(v___x_2875_);
if (v_isSharedCheck_2899_ == 0)
{
v___x_2894_ = v___x_2875_;
v_isShared_2895_ = v_isSharedCheck_2899_;
goto v_resetjp_2893_;
}
else
{
lean_inc(v_a_2892_);
lean_dec(v___x_2875_);
v___x_2894_ = lean_box(0);
v_isShared_2895_ = v_isSharedCheck_2899_;
goto v_resetjp_2893_;
}
v_resetjp_2893_:
{
lean_object* v___x_2897_; 
if (v_isShared_2895_ == 0)
{
v___x_2897_ = v___x_2894_;
goto v_reusejp_2896_;
}
else
{
lean_object* v_reuseFailAlloc_2898_; 
v_reuseFailAlloc_2898_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2898_, 0, v_a_2892_);
v___x_2897_ = v_reuseFailAlloc_2898_;
goto v_reusejp_2896_;
}
v_reusejp_2896_:
{
return v___x_2897_;
}
}
}
}
}
else
{
lean_object* v___x_2900_; lean_object* v___x_2901_; 
lean_del_object(v___x_2861_);
lean_dec(v_a_2859_);
v___x_2900_ = lean_st_ref_get(v_state_2853_);
v___x_2901_ = l_BudgetWorker_bench(v___x_2900_, v_j_2854_);
lean_dec(v___x_2900_);
return v___x_2901_;
}
}
else
{
lean_object* v___x_2902_; lean_object* v___x_2903_; lean_object* v___x_2904_; 
lean_del_object(v___x_2861_);
lean_dec(v_a_2859_);
v___x_2902_ = ((lean_object*)(l_BudgetWorker_bench___closed__4));
v___x_2903_ = l_Lean_Json_getObjValAs_x3f___at___00BudgetWorker_handle_spec__1(v_j_2854_, v___x_2902_);
v___x_2904_ = l_BudgetWorker_orError___redArg(v___x_2903_);
if (lean_obj_tag(v___x_2904_) == 0)
{
lean_object* v_a_2905_; lean_object* v___x_2906_; lean_object* v___x_2907_; 
v_a_2905_ = lean_ctor_get(v___x_2904_, 0);
lean_inc(v_a_2905_);
lean_dec_ref_known(v___x_2904_, 1);
v___x_2906_ = lean_box(0);
v___x_2907_ = l_List_mapM_loop___at___00BudgetWorker_handle_spec__2(v_a_2905_, v___x_2906_);
if (lean_obj_tag(v___x_2907_) == 0)
{
lean_object* v_a_2908_; lean_object* v___x_2910_; uint8_t v_isShared_2911_; uint8_t v_isSharedCheck_2923_; 
v_a_2908_ = lean_ctor_get(v___x_2907_, 0);
v_isSharedCheck_2923_ = !lean_is_exclusive(v___x_2907_);
if (v_isSharedCheck_2923_ == 0)
{
v___x_2910_ = v___x_2907_;
v_isShared_2911_ = v_isSharedCheck_2923_;
goto v_resetjp_2909_;
}
else
{
lean_inc(v_a_2908_);
lean_dec(v___x_2907_);
v___x_2910_ = lean_box(0);
v_isShared_2911_ = v_isSharedCheck_2923_;
goto v_resetjp_2909_;
}
v_resetjp_2909_:
{
lean_object* v___x_2912_; lean_object* v___x_2913_; lean_object* v___x_2914_; lean_object* v___x_2915_; lean_object* v___x_2916_; lean_object* v___x_2917_; lean_object* v___x_2918_; lean_object* v___x_2919_; lean_object* v___x_2921_; 
lean_inc(v_a_2908_);
v___x_2912_ = lean_st_ref_set(v_state_2853_, v_a_2908_);
v___x_2913_ = ((lean_object*)(l_BudgetWorker_handle___closed__7));
v___x_2914_ = l_List_lengthTR___redArg(v_a_2908_);
lean_dec(v_a_2908_);
v___x_2915_ = l_Lean_JsonNumber_fromNat(v___x_2914_);
v___x_2916_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2916_, 0, v___x_2915_);
v___x_2917_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2917_, 0, v___x_2913_);
lean_ctor_set(v___x_2917_, 1, v___x_2916_);
v___x_2918_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2918_, 0, v___x_2917_);
lean_ctor_set(v___x_2918_, 1, v___x_2906_);
v___x_2919_ = l_Lean_Json_mkObj(v___x_2918_);
lean_dec_ref_known(v___x_2918_, 2);
if (v_isShared_2911_ == 0)
{
lean_ctor_set(v___x_2910_, 0, v___x_2919_);
v___x_2921_ = v___x_2910_;
goto v_reusejp_2920_;
}
else
{
lean_object* v_reuseFailAlloc_2922_; 
v_reuseFailAlloc_2922_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2922_, 0, v___x_2919_);
v___x_2921_ = v_reuseFailAlloc_2922_;
goto v_reusejp_2920_;
}
v_reusejp_2920_:
{
return v___x_2921_;
}
}
}
else
{
lean_object* v_a_2924_; lean_object* v___x_2926_; uint8_t v_isShared_2927_; uint8_t v_isSharedCheck_2931_; 
v_a_2924_ = lean_ctor_get(v___x_2907_, 0);
v_isSharedCheck_2931_ = !lean_is_exclusive(v___x_2907_);
if (v_isSharedCheck_2931_ == 0)
{
v___x_2926_ = v___x_2907_;
v_isShared_2927_ = v_isSharedCheck_2931_;
goto v_resetjp_2925_;
}
else
{
lean_inc(v_a_2924_);
lean_dec(v___x_2907_);
v___x_2926_ = lean_box(0);
v_isShared_2927_ = v_isSharedCheck_2931_;
goto v_resetjp_2925_;
}
v_resetjp_2925_:
{
lean_object* v___x_2929_; 
if (v_isShared_2927_ == 0)
{
v___x_2929_ = v___x_2926_;
goto v_reusejp_2928_;
}
else
{
lean_object* v_reuseFailAlloc_2930_; 
v_reuseFailAlloc_2930_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2930_, 0, v_a_2924_);
v___x_2929_ = v_reuseFailAlloc_2930_;
goto v_reusejp_2928_;
}
v_reusejp_2928_:
{
return v___x_2929_;
}
}
}
}
else
{
lean_object* v_a_2932_; lean_object* v___x_2934_; uint8_t v_isShared_2935_; uint8_t v_isSharedCheck_2939_; 
v_a_2932_ = lean_ctor_get(v___x_2904_, 0);
v_isSharedCheck_2939_ = !lean_is_exclusive(v___x_2904_);
if (v_isSharedCheck_2939_ == 0)
{
v___x_2934_ = v___x_2904_;
v_isShared_2935_ = v_isSharedCheck_2939_;
goto v_resetjp_2933_;
}
else
{
lean_inc(v_a_2932_);
lean_dec(v___x_2904_);
v___x_2934_ = lean_box(0);
v_isShared_2935_ = v_isSharedCheck_2939_;
goto v_resetjp_2933_;
}
v_resetjp_2933_:
{
lean_object* v___x_2937_; 
if (v_isShared_2935_ == 0)
{
v___x_2937_ = v___x_2934_;
goto v_reusejp_2936_;
}
else
{
lean_object* v_reuseFailAlloc_2938_; 
v_reuseFailAlloc_2938_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2938_, 0, v_a_2932_);
v___x_2937_ = v_reuseFailAlloc_2938_;
goto v_reusejp_2936_;
}
v_reusejp_2936_:
{
return v___x_2937_;
}
}
}
}
}
}
else
{
lean_object* v_a_2941_; lean_object* v___x_2943_; uint8_t v_isShared_2944_; uint8_t v_isSharedCheck_2948_; 
lean_dec(v_j_2854_);
v_a_2941_ = lean_ctor_get(v___x_2858_, 0);
v_isSharedCheck_2948_ = !lean_is_exclusive(v___x_2858_);
if (v_isSharedCheck_2948_ == 0)
{
v___x_2943_ = v___x_2858_;
v_isShared_2944_ = v_isSharedCheck_2948_;
goto v_resetjp_2942_;
}
else
{
lean_inc(v_a_2941_);
lean_dec(v___x_2858_);
v___x_2943_ = lean_box(0);
v_isShared_2944_ = v_isSharedCheck_2948_;
goto v_resetjp_2942_;
}
v_resetjp_2942_:
{
lean_object* v___x_2946_; 
if (v_isShared_2944_ == 0)
{
v___x_2946_ = v___x_2943_;
goto v_reusejp_2945_;
}
else
{
lean_object* v_reuseFailAlloc_2947_; 
v_reuseFailAlloc_2947_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2947_, 0, v_a_2941_);
v___x_2946_ = v_reuseFailAlloc_2947_;
goto v_reusejp_2945_;
}
v_reusejp_2945_:
{
return v___x_2946_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_handle___boxed(lean_object* v_state_2949_, lean_object* v_j_2950_, lean_object* v_a_2951_){
_start:
{
lean_object* v_res_2952_; 
v_res_2952_ = l_BudgetWorker_handle(v_state_2949_, v_j_2950_);
lean_dec(v_state_2949_);
return v_res_2952_;
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_loop(lean_object* v_state_2961_){
_start:
{
lean_object* v_a_2964_; lean_object* v___y_2975_; lean_object* v___x_2991_; lean_object* v_getLine_2992_; lean_object* v___x_2993_; 
v___x_2991_ = lean_get_stdin();
v_getLine_2992_ = lean_ctor_get(v___x_2991_, 3);
lean_inc_ref(v_getLine_2992_);
lean_dec_ref(v___x_2991_);
v___x_2993_ = lean_apply_1(v_getLine_2992_, lean_box(0));
if (lean_obj_tag(v___x_2993_) == 0)
{
lean_object* v_a_2994_; lean_object* v___x_2996_; uint8_t v_isShared_2997_; uint8_t v_isSharedCheck_3009_; 
v_a_2994_ = lean_ctor_get(v___x_2993_, 0);
v_isSharedCheck_3009_ = !lean_is_exclusive(v___x_2993_);
if (v_isSharedCheck_3009_ == 0)
{
v___x_2996_ = v___x_2993_;
v_isShared_2997_ = v_isSharedCheck_3009_;
goto v_resetjp_2995_;
}
else
{
lean_inc(v_a_2994_);
lean_dec(v___x_2993_);
v___x_2996_ = lean_box(0);
v_isShared_2997_ = v_isSharedCheck_3009_;
goto v_resetjp_2995_;
}
v_resetjp_2995_:
{
lean_object* v___x_2998_; lean_object* v___x_2999_; uint8_t v___x_3000_; 
v___x_2998_ = lean_string_utf8_byte_size(v_a_2994_);
v___x_2999_ = lean_unsigned_to_nat(0u);
v___x_3000_ = lean_nat_dec_eq(v___x_2998_, v___x_2999_);
if (v___x_3000_ == 0)
{
lean_object* v___x_3001_; lean_object* v___x_3002_; 
lean_del_object(v___x_2996_);
v___x_3001_ = l_Lean_Json_parse(v_a_2994_);
v___x_3002_ = l_BudgetWorker_orError___redArg(v___x_3001_);
if (lean_obj_tag(v___x_3002_) == 0)
{
lean_object* v_a_3003_; lean_object* v___x_3004_; 
v_a_3003_ = lean_ctor_get(v___x_3002_, 0);
lean_inc(v_a_3003_);
lean_dec_ref_known(v___x_3002_, 1);
v___x_3004_ = l_BudgetWorker_handle(v_state_2961_, v_a_3003_);
v___y_2975_ = v___x_3004_;
goto v___jp_2974_;
}
else
{
v___y_2975_ = v___x_3002_;
goto v___jp_2974_;
}
}
else
{
lean_object* v___x_3005_; lean_object* v___x_3007_; 
lean_dec(v_a_2994_);
v___x_3005_ = lean_box(0);
if (v_isShared_2997_ == 0)
{
lean_ctor_set(v___x_2996_, 0, v___x_3005_);
v___x_3007_ = v___x_2996_;
goto v_reusejp_3006_;
}
else
{
lean_object* v_reuseFailAlloc_3008_; 
v_reuseFailAlloc_3008_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3008_, 0, v___x_3005_);
v___x_3007_ = v_reuseFailAlloc_3008_;
goto v_reusejp_3006_;
}
v_reusejp_3006_:
{
return v___x_3007_;
}
}
}
}
else
{
lean_object* v_a_3010_; lean_object* v___x_3012_; uint8_t v_isShared_3013_; uint8_t v_isSharedCheck_3017_; 
v_a_3010_ = lean_ctor_get(v___x_2993_, 0);
v_isSharedCheck_3017_ = !lean_is_exclusive(v___x_2993_);
if (v_isSharedCheck_3017_ == 0)
{
v___x_3012_ = v___x_2993_;
v_isShared_3013_ = v_isSharedCheck_3017_;
goto v_resetjp_3011_;
}
else
{
lean_inc(v_a_3010_);
lean_dec(v___x_2993_);
v___x_3012_ = lean_box(0);
v_isShared_3013_ = v_isSharedCheck_3017_;
goto v_resetjp_3011_;
}
v_resetjp_3011_:
{
lean_object* v___x_3015_; 
if (v_isShared_3013_ == 0)
{
v___x_3015_ = v___x_3012_;
goto v_reusejp_3014_;
}
else
{
lean_object* v_reuseFailAlloc_3016_; 
v_reuseFailAlloc_3016_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_3016_, 0, v_a_3010_);
v___x_3015_ = v_reuseFailAlloc_3016_;
goto v_reusejp_3014_;
}
v_reusejp_3014_:
{
return v___x_3015_;
}
}
}
v___jp_2963_:
{
lean_object* v___x_2965_; lean_object* v___x_2966_; lean_object* v___x_2967_; lean_object* v___x_2968_; lean_object* v___x_2969_; lean_object* v___x_2970_; lean_object* v___x_2971_; lean_object* v___x_2972_; 
v___x_2965_ = ((lean_object*)(l_BudgetWorker_loop___closed__2));
v___x_2966_ = ((lean_object*)(l_BudgetWorker_loop___closed__3));
v___x_2967_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2967_, 0, v___x_2966_);
lean_ctor_set(v___x_2967_, 1, v_a_2964_);
v___x_2968_ = lean_box(0);
v___x_2969_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2969_, 0, v___x_2967_);
lean_ctor_set(v___x_2969_, 1, v___x_2968_);
v___x_2970_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2970_, 0, v___x_2965_);
lean_ctor_set(v___x_2970_, 1, v___x_2969_);
v___x_2971_ = l_Lean_Json_mkObj(v___x_2970_);
lean_dec_ref_known(v___x_2970_, 2);
v___x_2972_ = l_BudgetWorker_emit(v___x_2971_);
if (lean_obj_tag(v___x_2972_) == 0)
{
lean_dec_ref_known(v___x_2972_, 1);
goto _start;
}
else
{
return v___x_2972_;
}
}
v___jp_2974_:
{
if (lean_obj_tag(v___y_2975_) == 0)
{
lean_object* v_a_2976_; 
v_a_2976_ = lean_ctor_get(v___y_2975_, 0);
lean_inc(v_a_2976_);
lean_dec_ref_known(v___y_2975_, 1);
v_a_2964_ = v_a_2976_;
goto v___jp_2963_;
}
else
{
lean_object* v_a_2977_; lean_object* v___x_2979_; uint8_t v_isShared_2980_; uint8_t v_isSharedCheck_2990_; 
v_a_2977_ = lean_ctor_get(v___y_2975_, 0);
v_isSharedCheck_2990_ = !lean_is_exclusive(v___y_2975_);
if (v_isSharedCheck_2990_ == 0)
{
v___x_2979_ = v___y_2975_;
v_isShared_2980_ = v_isSharedCheck_2990_;
goto v_resetjp_2978_;
}
else
{
lean_inc(v_a_2977_);
lean_dec(v___y_2975_);
v___x_2979_ = lean_box(0);
v_isShared_2980_ = v_isSharedCheck_2990_;
goto v_resetjp_2978_;
}
v_resetjp_2978_:
{
lean_object* v___x_2981_; lean_object* v___x_2982_; lean_object* v___x_2984_; 
v___x_2981_ = ((lean_object*)(l_BudgetWorker_loop___closed__4));
v___x_2982_ = lean_io_error_to_string(v_a_2977_);
if (v_isShared_2980_ == 0)
{
lean_ctor_set_tag(v___x_2979_, 3);
lean_ctor_set(v___x_2979_, 0, v___x_2982_);
v___x_2984_ = v___x_2979_;
goto v_reusejp_2983_;
}
else
{
lean_object* v_reuseFailAlloc_2989_; 
v_reuseFailAlloc_2989_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2989_, 0, v___x_2982_);
v___x_2984_ = v_reuseFailAlloc_2989_;
goto v_reusejp_2983_;
}
v_reusejp_2983_:
{
lean_object* v___x_2985_; lean_object* v___x_2986_; lean_object* v___x_2987_; lean_object* v___x_2988_; 
v___x_2985_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2985_, 0, v___x_2981_);
lean_ctor_set(v___x_2985_, 1, v___x_2984_);
v___x_2986_ = lean_box(0);
v___x_2987_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2987_, 0, v___x_2985_);
lean_ctor_set(v___x_2987_, 1, v___x_2986_);
v___x_2988_ = l_Lean_Json_mkObj(v___x_2987_);
lean_dec_ref_known(v___x_2987_, 2);
v_a_2964_ = v___x_2988_;
goto v___jp_2963_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_BudgetWorker_loop___boxed(lean_object* v_state_3018_, lean_object* v_a_3019_){
_start:
{
lean_object* v_res_3020_; 
v_res_3020_ = l_BudgetWorker_loop(v_state_3018_);
lean_dec(v_state_3018_);
return v_res_3020_;
}
}
static lean_object* _init_l_main___closed__4(void){
_start:
{
lean_object* v___x_3030_; lean_object* v___x_3031_; 
v___x_3030_ = ((lean_object*)(l_main___closed__3));
v___x_3031_ = l_Lean_Json_mkObj(v___x_3030_);
return v___x_3031_;
}
}
LEAN_EXPORT lean_object* _lean_main(){
_start:
{
lean_object* v___x_3033_; lean_object* v___x_3034_; lean_object* v___x_3035_; 
v___x_3033_ = lean_box(0);
v___x_3034_ = lean_obj_once(&l_main___closed__4, &l_main___closed__4_once, _init_l_main___closed__4);
v___x_3035_ = l_BudgetWorker_emit(v___x_3034_);
if (lean_obj_tag(v___x_3035_) == 0)
{
lean_object* v___x_3036_; lean_object* v___x_3037_; 
lean_dec_ref_known(v___x_3035_, 1);
v___x_3036_ = lean_st_mk_ref(v___x_3033_);
v___x_3037_ = l_BudgetWorker_loop(v___x_3036_);
lean_dec(v___x_3036_);
return v___x_3037_;
}
else
{
return v___x_3035_;
}
}
}
LEAN_EXPORT lean_object* l_main___boxed(lean_object* v_a_3038_){
_start:
{
lean_object* v_res_3039_; 
v_res_3039_ = _lean_main();
return v_res_3039_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_LeanSort_Algorithm_BudgetSelection_Features(uint8_t builtin);
lean_object* initialize_Lean(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_experiments_selection_x2dbreak_x2deven_Worker(uint8_t builtin) {
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
res = initialize_LeanSort_Algorithm_BudgetSelection_Features(builtin);
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
  res = initialize_experiments_selection_x2dbreak_x2deven_Worker(1 /* builtin */);
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
