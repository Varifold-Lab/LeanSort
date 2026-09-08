// Lean compiler output
// Module: experiments.«direct-cost-learning».Worker
// Imports: public import Init public meta import Init public import LeanSort.Algorithm.LearnedSelection.Model public import Lean
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
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(lean_object*, lean_object*);
lean_object* l_Lean_Json_getObjVal_x3f(lean_object*, lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
lean_object* l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* l_Lean_Json_getObjValD(lean_object*, lean_object*);
lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonFuncTable_fromJson_spec__0_spec__0(lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* l_Lean_Json_getObjValAs_x3f___at___00Lean_IO_FS_Stream_readRequestAs___at___00Lean_IO_FS_Stream_readLspRequestAs___at___00Lean_Server_FileWorker_initAndRunWorker_spec__0_spec__0_spec__2(lean_object*, lean_object*);
lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonStackTable_fromJson_spec__0_spec__0(lean_object*);
lean_object* lean_st_mk_ref(lean_object*);
lean_object* lean_io_mono_nanos_now();
lean_object* lean_st_ref_get(lean_object*);
lean_object* lean_nat_to_int(lean_object*);
lean_object* l_LeanSort_LearnedSelection_sampleRule(lean_object*);
lean_object* l_List_get_x3fInternal___redArg(lean_object*, lean_object*);
lean_object* l_LeanSort_LearnedSelection_Model_predict(lean_object*, lean_object*);
lean_object* l_LeanSort_LearnedSelection_resolve(lean_object*);
lean_object* lean_st_ref_set(lean_object*, lean_object*);
lean_object* l_Lean_JsonNumber_fromInt(lean_object*);
lean_object* l_Lean_JsonNumber_fromNat(lean_object*);
lean_object* l_Lean_Json_mkObj(lean_object*);
lean_object* lean_get_stdout();
lean_object* l_Lean_Json_compress(lean_object*);
lean_object* l_IO_FS_Stream_putStrLn(lean_object*, lean_object*);
lean_object* l_LeanSort_LearnedSelection_candidate(lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
lean_object* l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(lean_object*);
lean_object* l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(lean_object*, lean_object*);
lean_object* l_List_drop___redArg(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_CostedPlan_Cut_position(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_RunAdaptive_countPlan___redArg(lean_object*);
lean_object* lp_leansort_LeanSort_RunAdaptive_lengthPlan___redArg(lean_object*);
uint8_t lp_leansort_LeanSort_Comparison_instDecidableEqPhase(uint8_t, uint8_t);
lean_object* lp_leansort_LeanSort_CostedPlan_Schema_upper(lean_object*, lean_object*);
lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_run___at___00LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0_spec__0_spec__1_spec__3_spec__7(lean_object*);
lean_object* lp_mathlib_Nat_clog(lean_object*, lean_object*);
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_RunAdaptive_MergeTree_budget___redArg(lean_object*);
lean_object* l_Lean_Option_toJson___at___00Lean_Json_toStructured_x3f___at___00Lean_Server_FileWorker_sendServerRequest___at___00Lean_Server_FileWorker_runRefreshTasks_spec__0_spec__1_spec__3(lean_object*);
uint8_t l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_ComparisonSort_checkSorted___redArg(lean_object*);
lean_object* lp_leansort_LeanSort_CostedPlan_Schema_readyUpper(lean_object*, lean_object*);
lean_object* lean_array_mk(lean_object*);
lean_object* l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonFuncTable_toJson_spec__0(lean_object*);
lean_object* l_LeanSort_LearnedSelection_Tree_eval(lean_object*, lean_object*);
lean_object* l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__0(lean_object*);
lean_object* l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(lean_object*);
lean_object* lp_LeanSearchClient_Lean_Json_getObjValAs_x3f___at___00LeanSearchClient_getLoogleQueryJson_spec__4(lean_object*, lean_object*);
lean_object* l_List_range(lean_object*);
lean_object* l_LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0(lean_object*, lean_object*);
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* l_Nat_reprFast(lean_object*);
lean_object* lean_int_neg(lean_object*);
lean_object* l_LeanSort_LearnedSelection_select(lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
lean_object* l_LeanSort_LearnedSelection_features(lean_object*);
lean_object* l_LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0(lean_object*);
lean_object* lean_io_error_to_string(lean_object*);
lean_object* lean_get_stdin();
lean_object* lean_string_utf8_byte_size(lean_object*);
lean_object* l_Lean_Json_parse(lean_object*);
lean_object* l_LeanSort_LearnedSelection_run(lean_object*, lean_object*);
lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_Widget_instRpcEncodableStrictOrLazy_dec_00___x40_Lean_Widget_InteractiveDiagnostic_2157017296____hygCtx___hyg_1____at___00Lean_Widget_instRpcEncodableHighlightedMsgEmbed_dec_00___x40_Lean_Server_FileWorker_WidgetRequests_2377472685____hygCtx___hyg_1__spec__2_spec__3(lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_orError___redArg(lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_orError___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_orError(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_orError___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00LearningWorker_decodeTree_spec__0_spec__0(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_decodeTree_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_decodeTree_spec__0___boxed(lean_object*, lean_object*);
static const lean_string_object l_LearningWorker_decodeTree___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 32, .m_capacity = 32, .m_length = 31, .m_data = "model tree exceeds depth budget"};
static const lean_object* l_LearningWorker_decodeTree___closed__0 = (const lean_object*)&l_LearningWorker_decodeTree___closed__0_value;
static const lean_ctor_object l_LearningWorker_decodeTree___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_LearningWorker_decodeTree___closed__0_value)}};
static const lean_object* l_LearningWorker_decodeTree___closed__1 = (const lean_object*)&l_LearningWorker_decodeTree___closed__1_value;
static const lean_string_object l_LearningWorker_decodeTree___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "kind"};
static const lean_object* l_LearningWorker_decodeTree___closed__2 = (const lean_object*)&l_LearningWorker_decodeTree___closed__2_value;
static const lean_string_object l_LearningWorker_decodeTree___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "leaf"};
static const lean_object* l_LearningWorker_decodeTree___closed__3 = (const lean_object*)&l_LearningWorker_decodeTree___closed__3_value;
static const lean_string_object l_LearningWorker_decodeTree___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "branch"};
static const lean_object* l_LearningWorker_decodeTree___closed__4 = (const lean_object*)&l_LearningWorker_decodeTree___closed__4_value;
static const lean_string_object l_LearningWorker_decodeTree___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "unsupported tree"};
static const lean_object* l_LearningWorker_decodeTree___closed__5 = (const lean_object*)&l_LearningWorker_decodeTree___closed__5_value;
static const lean_ctor_object l_LearningWorker_decodeTree___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_LearningWorker_decodeTree___closed__5_value)}};
static const lean_object* l_LearningWorker_decodeTree___closed__6 = (const lean_object*)&l_LearningWorker_decodeTree___closed__6_value;
static const lean_string_object l_LearningWorker_decodeTree___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "feature"};
static const lean_object* l_LearningWorker_decodeTree___closed__7 = (const lean_object*)&l_LearningWorker_decodeTree___closed__7_value;
static const lean_string_object l_LearningWorker_decodeTree___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "threshold"};
static const lean_object* l_LearningWorker_decodeTree___closed__8 = (const lean_object*)&l_LearningWorker_decodeTree___closed__8_value;
static const lean_string_object l_LearningWorker_decodeTree___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "left"};
static const lean_object* l_LearningWorker_decodeTree___closed__9 = (const lean_object*)&l_LearningWorker_decodeTree___closed__9_value;
static const lean_string_object l_LearningWorker_decodeTree___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "right"};
static const lean_object* l_LearningWorker_decodeTree___closed__10 = (const lean_object*)&l_LearningWorker_decodeTree___closed__10_value;
static const lean_string_object l_LearningWorker_decodeTree___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "values"};
static const lean_object* l_LearningWorker_decodeTree___closed__11 = (const lean_object*)&l_LearningWorker_decodeTree___closed__11_value;
static const lean_string_object l_LearningWorker_decodeTree___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "leaf too wide"};
static const lean_object* l_LearningWorker_decodeTree___closed__12 = (const lean_object*)&l_LearningWorker_decodeTree___closed__12_value;
static const lean_ctor_object l_LearningWorker_decodeTree___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_LearningWorker_decodeTree___closed__12_value)}};
static const lean_object* l_LearningWorker_decodeTree___closed__13 = (const lean_object*)&l_LearningWorker_decodeTree___closed__13_value;
LEAN_EXPORT lean_object* l_LearningWorker_decodeTree(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_decodeTree___boxed(lean_object*, lean_object*);
static const lean_string_object l_LearningWorker_decodeModel___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "schema_version"};
static const lean_object* l_LearningWorker_decodeModel___closed__0 = (const lean_object*)&l_LearningWorker_decodeModel___closed__0_value;
static const lean_string_object l_LearningWorker_decodeModel___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "candidate_version"};
static const lean_object* l_LearningWorker_decodeModel___closed__1 = (const lean_object*)&l_LearningWorker_decodeModel___closed__1_value;
static const lean_string_object l_LearningWorker_decodeModel___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "feature_version"};
static const lean_object* l_LearningWorker_decodeModel___closed__2 = (const lean_object*)&l_LearningWorker_decodeModel___closed__2_value;
static const lean_string_object l_LearningWorker_decodeModel___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 21, .m_capacity = 21, .m_length = 20, .m_data = "spread-adjacent16-v1"};
static const lean_object* l_LearningWorker_decodeModel___closed__3 = (const lean_object*)&l_LearningWorker_decodeModel___closed__3_value;
static const lean_string_object l_LearningWorker_decodeModel___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "tree"};
static const lean_object* l_LearningWorker_decodeModel___closed__4 = (const lean_object*)&l_LearningWorker_decodeModel___closed__4_value;
static const lean_string_object l_LearningWorker_decodeModel___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "classifier"};
static const lean_object* l_LearningWorker_decodeModel___closed__5 = (const lean_object*)&l_LearningWorker_decodeModel___closed__5_value;
static const lean_string_object l_LearningWorker_decodeModel___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 13, .m_capacity = 13, .m_length = 12, .m_data = "cost_ranking"};
static const lean_object* l_LearningWorker_decodeModel___closed__6 = (const lean_object*)&l_LearningWorker_decodeModel___closed__6_value;
static const lean_string_object l_LearningWorker_decodeModel___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 25, .m_capacity = 25, .m_length = 24, .m_data = "verified-direct-seven-v1"};
static const lean_object* l_LearningWorker_decodeModel___closed__7 = (const lean_object*)&l_LearningWorker_decodeModel___closed__7_value;
LEAN_EXPORT lean_object* l_LearningWorker_decodeModel(lean_object*);
static const lean_ctor_object l_LearningWorker_decodePolicy___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_LearningWorker_decodePolicy___closed__0 = (const lean_object*)&l_LearningWorker_decodePolicy___closed__0_value;
static const lean_string_object l_LearningWorker_decodePolicy___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "fixed"};
static const lean_object* l_LearningWorker_decodePolicy___closed__1 = (const lean_object*)&l_LearningWorker_decodePolicy___closed__1_value;
static const lean_string_object l_LearningWorker_decodePolicy___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "sample_rule"};
static const lean_object* l_LearningWorker_decodePolicy___closed__2 = (const lean_object*)&l_LearningWorker_decodePolicy___closed__2_value;
static const lean_string_object l_LearningWorker_decodePolicy___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "length_rule"};
static const lean_object* l_LearningWorker_decodePolicy___closed__3 = (const lean_object*)&l_LearningWorker_decodePolicy___closed__3_value;
static const lean_string_object l_LearningWorker_decodePolicy___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "learned"};
static const lean_object* l_LearningWorker_decodePolicy___closed__4 = (const lean_object*)&l_LearningWorker_decodePolicy___closed__4_value;
static const lean_string_object l_LearningWorker_decodePolicy___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "model"};
static const lean_object* l_LearningWorker_decodePolicy___closed__5 = (const lean_object*)&l_LearningWorker_decodePolicy___closed__5_value;
static const lean_string_object l_LearningWorker_decodePolicy___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "id"};
static const lean_object* l_LearningWorker_decodePolicy___closed__6 = (const lean_object*)&l_LearningWorker_decodePolicy___closed__6_value;
LEAN_EXPORT lean_object* l_LearningWorker_decodePolicy(lean_object*);
static lean_once_cell_t l_LearningWorker_featureSelect___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LearningWorker_featureSelect___closed__0;
static lean_once_cell_t l_LearningWorker_featureSelect___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LearningWorker_featureSelect___closed__1;
static lean_once_cell_t l_LearningWorker_featureSelect___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LearningWorker_featureSelect___closed__2;
static lean_once_cell_t l_LearningWorker_featureSelect___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LearningWorker_featureSelect___closed__3;
LEAN_EXPORT lean_object* l_LearningWorker_featureSelect(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_featureSelect___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_LearningWorker_usesFeatures(lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_usesFeatures___boxed(lean_object*);
LEAN_EXPORT lean_object* l_List_foldl___at___00LearningWorker_checksum_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_foldl___at___00LearningWorker_checksum_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_checksum(lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_checksum___boxed(lean_object*);
static const lean_string_object l_LearningWorker_timedKernel___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "kernel output mismatch"};
static const lean_object* l_LearningWorker_timedKernel___closed__0 = (const lean_object*)&l_LearningWorker_timedKernel___closed__0_value;
static const lean_ctor_object l_LearningWorker_timedKernel___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_LearningWorker_timedKernel___closed__0_value)}};
static const lean_object* l_LearningWorker_timedKernel___closed__1 = (const lean_object*)&l_LearningWorker_timedKernel___closed__1_value;
LEAN_EXPORT lean_object* l_LearningWorker_timedKernel(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_timedKernel___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_LearningWorker_timedPolicy___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "policy output mismatch"};
static const lean_object* l_LearningWorker_timedPolicy___closed__0 = (const lean_object*)&l_LearningWorker_timedPolicy___closed__0_value;
static const lean_ctor_object l_LearningWorker_timedPolicy___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_LearningWorker_timedPolicy___closed__0_value)}};
static const lean_object* l_LearningWorker_timedPolicy___closed__1 = (const lean_object*)&l_LearningWorker_timedPolicy___closed__1_value;
LEAN_EXPORT lean_object* l_LearningWorker_timedPolicy(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_timedPolicy___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_timedFeatures(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_timedFeatures___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_timedDecision(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_timedDecision___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_emit(lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_emit___boxed(lean_object*, lean_object*);
static const lean_string_object l_LearningWorker_sampleEvent___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "event"};
static const lean_object* l_LearningWorker_sampleEvent___closed__0 = (const lean_object*)&l_LearningWorker_sampleEvent___closed__0_value;
static const lean_string_object l_LearningWorker_sampleEvent___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "sample"};
static const lean_object* l_LearningWorker_sampleEvent___closed__1 = (const lean_object*)&l_LearningWorker_sampleEvent___closed__1_value;
static const lean_ctor_object l_LearningWorker_sampleEvent___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&l_LearningWorker_sampleEvent___closed__1_value)}};
static const lean_object* l_LearningWorker_sampleEvent___closed__2 = (const lean_object*)&l_LearningWorker_sampleEvent___closed__2_value;
static const lean_ctor_object l_LearningWorker_sampleEvent___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_LearningWorker_sampleEvent___closed__0_value),((lean_object*)&l_LearningWorker_sampleEvent___closed__2_value)}};
static const lean_object* l_LearningWorker_sampleEvent___closed__3 = (const lean_object*)&l_LearningWorker_sampleEvent___closed__3_value;
static const lean_string_object l_LearningWorker_sampleEvent___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "category"};
static const lean_object* l_LearningWorker_sampleEvent___closed__4 = (const lean_object*)&l_LearningWorker_sampleEvent___closed__4_value;
static const lean_string_object l_LearningWorker_sampleEvent___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "name"};
static const lean_object* l_LearningWorker_sampleEvent___closed__5 = (const lean_object*)&l_LearningWorker_sampleEvent___closed__5_value;
static const lean_string_object l_LearningWorker_sampleEvent___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "round"};
static const lean_object* l_LearningWorker_sampleEvent___closed__6 = (const lean_object*)&l_LearningWorker_sampleEvent___closed__6_value;
static const lean_string_object l_LearningWorker_sampleEvent___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 3, .m_capacity = 3, .m_length = 2, .m_data = "ns"};
static const lean_object* l_LearningWorker_sampleEvent___closed__7 = (const lean_object*)&l_LearningWorker_sampleEvent___closed__7_value;
static const lean_string_object l_LearningWorker_sampleEvent___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "chosen_id"};
static const lean_object* l_LearningWorker_sampleEvent___closed__8 = (const lean_object*)&l_LearningWorker_sampleEvent___closed__8_value;
LEAN_EXPORT lean_object* l_LearningWorker_sampleEvent(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_sampleEvent___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3_spec__7___redArg(lean_object*);
static const lean_array_object l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3___closed__0 = (const lean_object*)&l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3___closed__0_value;
LEAN_EXPORT uint8_t l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__0(lean_object*, lean_object*);
static lean_once_cell_t l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0;
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___lam__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__3___lam__0(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__0(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__1(lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___lam__0(lean_object*, lean_object*);
static lean_once_cell_t l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0;
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11(lean_object*);
static const lean_closure_object l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__3___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__3___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__3___closed__0 = (const lean_object*)&l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__3___closed__0_value;
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__3(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2___lam__0(lean_object*);
static const lean_closure_object l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2___closed__0 = (const lean_object*)&l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2___closed__0_value;
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2(lean_object*);
static lean_once_cell_t l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0;
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___lam__0(lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18___lam__1(lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12___lam__1(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__1(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__2(lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__2___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__1(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__2(uint8_t, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___lam__1(lean_object*, uint8_t, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___lam__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___lam__2(uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__0(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___lam__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___lam__1(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__9___lam__0(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__9___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__9(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__9___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___lam__0(uint8_t, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__0(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___lam__1(uint8_t, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___lam__0(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___lam__0___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___lam__1(uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__1(uint8_t, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__2(uint8_t, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__1(uint8_t, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8___lam__0(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8___lam__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8(uint8_t, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00LearningWorker_kernelProfile_spec__2_spec__5(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00LearningWorker_kernelProfile_spec__2_spec__5___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_LearnedSelection_kernelBound___at___00LearningWorker_kernelProfile_spec__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_LearnedSelection_kernelBound___at___00LearningWorker_kernelProfile_spec__2___boxed(lean_object*, lean_object*);
static const lean_string_object l_LearningWorker_kernelProfile___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 33, .m_capacity = 33, .m_length = 32, .m_data = "kernel phase/count/bound failure"};
static const lean_object* l_LearningWorker_kernelProfile___closed__0 = (const lean_object*)&l_LearningWorker_kernelProfile___closed__0_value;
static const lean_ctor_object l_LearningWorker_kernelProfile___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_LearningWorker_kernelProfile___closed__0_value)}};
static const lean_object* l_LearningWorker_kernelProfile___closed__1 = (const lean_object*)&l_LearningWorker_kernelProfile___closed__1_value;
static const lean_string_object l_LearningWorker_kernelProfile___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "comparisons"};
static const lean_object* l_LearningWorker_kernelProfile___closed__2 = (const lean_object*)&l_LearningWorker_kernelProfile___closed__2_value;
static const lean_string_object l_LearningWorker_kernelProfile___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "check_comparisons"};
static const lean_object* l_LearningWorker_kernelProfile___closed__3 = (const lean_object*)&l_LearningWorker_kernelProfile___closed__3_value;
static const lean_string_object l_LearningWorker_kernelProfile___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "sort_comparisons"};
static const lean_object* l_LearningWorker_kernelProfile___closed__4 = (const lean_object*)&l_LearningWorker_kernelProfile___closed__4_value;
static const lean_string_object l_LearningWorker_kernelProfile___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "bound"};
static const lean_object* l_LearningWorker_kernelProfile___closed__5 = (const lean_object*)&l_LearningWorker_kernelProfile___closed__5_value;
static const lean_string_object l_LearningWorker_kernelProfile___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 23, .m_capacity = 23, .m_length = 22, .m_data = "conditional_applicable"};
static const lean_object* l_LearningWorker_kernelProfile___closed__6 = (const lean_object*)&l_LearningWorker_kernelProfile___closed__6_value;
static const lean_string_object l_LearningWorker_kernelProfile___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "conditional_bound"};
static const lean_object* l_LearningWorker_kernelProfile___closed__7 = (const lean_object*)&l_LearningWorker_kernelProfile___closed__7_value;
static const lean_string_object l_LearningWorker_kernelProfile___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 40, .m_capacity = 40, .m_length = 39, .m_data = "conditional theorem domain/cost failure"};
static const lean_object* l_LearningWorker_kernelProfile___closed__8 = (const lean_object*)&l_LearningWorker_kernelProfile___closed__8_value;
static const lean_ctor_object l_LearningWorker_kernelProfile___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_LearningWorker_kernelProfile___closed__8_value)}};
static const lean_object* l_LearningWorker_kernelProfile___closed__9 = (const lean_object*)&l_LearningWorker_kernelProfile___closed__9_value;
LEAN_EXPORT lean_object* l_LearningWorker_kernelProfile(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_kernelProfile___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3_spec__7(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_scan___at___00LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00LearningWorker_kernelProfile_spec__2_spec__5_spec__12(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Option_toJson___at___00LearningWorker_bench_spec__9(lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00Lean_Option_toJson___at___00LearningWorker_bench_spec__10_spec__11(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Option_toJson___at___00LearningWorker_bench_spec__10(lean_object*);
static const lean_string_object l_List_mapTR_loop___at___00LearningWorker_bench_spec__14___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "raw_id"};
static const lean_object* l_List_mapTR_loop___at___00LearningWorker_bench_spec__14___closed__0 = (const lean_object*)&l_List_mapTR_loop___at___00LearningWorker_bench_spec__14___closed__0_value;
static const lean_string_object l_List_mapTR_loop___at___00LearningWorker_bench_spec__14___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "uses_features"};
static const lean_object* l_List_mapTR_loop___at___00LearningWorker_bench_spec__14___closed__1 = (const lean_object*)&l_List_mapTR_loop___at___00LearningWorker_bench_spec__14___closed__1_value;
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00LearningWorker_bench_spec__14(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00LearningWorker_bench_spec__14___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00LearningWorker_bench_spec__16(lean_object*, lean_object*);
static const lean_string_object l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "decision"};
static const lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11___redArg___closed__0_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__12___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__12___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00LearningWorker_bench_spec__1_spec__1(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_bench_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_bench_spec__1___boxed(lean_object*, lean_object*);
static const lean_string_object l_List_mapTR_loop___at___00LearningWorker_bench_spec__6___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "policy"};
static const lean_object* l_List_mapTR_loop___at___00LearningWorker_bench_spec__6___closed__0 = (const lean_object*)&l_List_mapTR_loop___at___00LearningWorker_bench_spec__6___closed__0_value;
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00LearningWorker_bench_spec__6(lean_object*, lean_object*);
static const lean_string_object l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "kernel"};
static const lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7___redArg___closed__0_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "features"};
static const lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg___closed__0_value;
static const lean_array_object l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg___closed__1 = (const lean_object*)&l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg___closed__1_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00LearningWorker_bench_spec__15(lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00LearningWorker_bench_spec__5(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_find_x3f___at___00LearningWorker_bench_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_find_x3f___at___00LearningWorker_bench_spec__0___boxed(lean_object*, lean_object*);
static const lean_string_object l_List_mapM_loop___at___00LearningWorker_bench_spec__2___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "unconfigured policy"};
static const lean_object* l_List_mapM_loop___at___00LearningWorker_bench_spec__2___closed__0 = (const lean_object*)&l_List_mapM_loop___at___00LearningWorker_bench_spec__2___closed__0_value;
static const lean_ctor_object l_List_mapM_loop___at___00LearningWorker_bench_spec__2___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_List_mapM_loop___at___00LearningWorker_bench_spec__2___closed__0_value)}};
static const lean_object* l_List_mapM_loop___at___00LearningWorker_bench_spec__2___closed__1 = (const lean_object*)&l_List_mapM_loop___at___00LearningWorker_bench_spec__2___closed__1_value;
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00LearningWorker_bench_spec__2(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00LearningWorker_bench_spec__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_List_mapM_loop___at___00LearningWorker_bench_spec__13___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 42, .m_capacity = 42, .m_length = 41, .m_data = "independent key-comparison count mismatch"};
static const lean_object* l_List_mapM_loop___at___00LearningWorker_bench_spec__13___closed__0 = (const lean_object*)&l_List_mapM_loop___at___00LearningWorker_bench_spec__13___closed__0_value;
static const lean_ctor_object l_List_mapM_loop___at___00LearningWorker_bench_spec__13___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_List_mapM_loop___at___00LearningWorker_bench_spec__13___closed__0_value)}};
static const lean_object* l_List_mapM_loop___at___00LearningWorker_bench_spec__13___closed__1 = (const lean_object*)&l_List_mapM_loop___at___00LearningWorker_bench_spec__13___closed__1_value;
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00LearningWorker_bench_spec__13(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00LearningWorker_bench_spec__13___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static lean_once_cell_t l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg___closed__0;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__4___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__4___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_LearningWorker_bench___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "input"};
static const lean_object* l_LearningWorker_bench___closed__0 = (const lean_object*)&l_LearningWorker_bench___closed__0_value;
static const lean_string_object l_LearningWorker_bench___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "expected"};
static const lean_object* l_LearningWorker_bench___closed__1 = (const lean_object*)&l_LearningWorker_bench___closed__1_value;
static const lean_string_object l_LearningWorker_bench___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 18, .m_capacity = 18, .m_length = 17, .m_data = "expected_features"};
static const lean_object* l_LearningWorker_bench___closed__2 = (const lean_object*)&l_LearningWorker_bench___closed__2_value;
static const lean_string_object l_LearningWorker_bench___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "expected_costs"};
static const lean_object* l_LearningWorker_bench___closed__3 = (const lean_object*)&l_LearningWorker_bench___closed__3_value;
static const lean_string_object l_LearningWorker_bench___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 37, .m_capacity = 37, .m_length = 36, .m_data = "training/deployment feature mismatch"};
static const lean_object* l_LearningWorker_bench___closed__4 = (const lean_object*)&l_LearningWorker_bench___closed__4_value;
static const lean_ctor_object l_LearningWorker_bench___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_LearningWorker_bench___closed__4_value)}};
static const lean_object* l_LearningWorker_bench___closed__5 = (const lean_object*)&l_LearningWorker_bench___closed__5_value;
static const lean_string_object l_LearningWorker_bench___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "feature_comparisons"};
static const lean_object* l_LearningWorker_bench___closed__6 = (const lean_object*)&l_LearningWorker_bench___closed__6_value;
static const lean_string_object l_LearningWorker_bench___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "kernel_profiles"};
static const lean_object* l_LearningWorker_bench___closed__7 = (const lean_object*)&l_LearningWorker_bench___closed__7_value;
static const lean_string_object l_LearningWorker_bench___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "predictions"};
static const lean_object* l_LearningWorker_bench___closed__8 = (const lean_object*)&l_LearningWorker_bench___closed__8_value;
static const lean_string_object l_LearningWorker_bench___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "run_lengths"};
static const lean_object* l_LearningWorker_bench___closed__9 = (const lean_object*)&l_LearningWorker_bench___closed__9_value;
static const lean_string_object l_LearningWorker_bench___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 20, .m_capacity = 20, .m_length = 19, .m_data = "all_outputs_correct"};
static const lean_object* l_LearningWorker_bench___closed__10 = (const lean_object*)&l_LearningWorker_bench___closed__10_value;
static const lean_string_object l_LearningWorker_bench___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "policies"};
static const lean_object* l_LearningWorker_bench___closed__11 = (const lean_object*)&l_LearningWorker_bench___closed__11_value;
static const lean_string_object l_LearningWorker_bench___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "rounds"};
static const lean_object* l_LearningWorker_bench___closed__12 = (const lean_object*)&l_LearningWorker_bench___closed__12_value;
static const lean_string_object l_LearningWorker_bench___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "order_seed"};
static const lean_object* l_LearningWorker_bench___closed__13 = (const lean_object*)&l_LearningWorker_bench___closed__13_value;
static const lean_string_object l_LearningWorker_bench___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 34, .m_capacity = 34, .m_length = 33, .m_data = "invalid measurement configuration"};
static const lean_object* l_LearningWorker_bench___closed__14 = (const lean_object*)&l_LearningWorker_bench___closed__14_value;
static const lean_ctor_object l_LearningWorker_bench___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_LearningWorker_bench___closed__14_value)}};
static const lean_object* l_LearningWorker_bench___closed__15 = (const lean_object*)&l_LearningWorker_bench___closed__15_value;
static lean_once_cell_t l_LearningWorker_bench___closed__16_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LearningWorker_bench___closed__16;
static lean_once_cell_t l_LearningWorker_bench___closed__17_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LearningWorker_bench___closed__17;
LEAN_EXPORT lean_object* l_LearningWorker_bench(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_bench___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__4(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__12(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__12___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_List_mapTR_loop___at___00LearningWorker_handle_spec__0___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "output"};
static const lean_object* l_List_mapTR_loop___at___00LearningWorker_handle_spec__0___closed__0 = (const lean_object*)&l_List_mapTR_loop___at___00LearningWorker_handle_spec__0___closed__0_value;
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00LearningWorker_handle_spec__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00LearningWorker_handle_spec__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00LearningWorker_handle_spec__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00LearningWorker_handle_spec__2___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00LearningWorker_handle_spec__1_spec__1(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_handle_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_handle_spec__1___boxed(lean_object*, lean_object*);
static const lean_string_object l_LearningWorker_handle___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 4, .m_capacity = 4, .m_length = 3, .m_data = "cmd"};
static const lean_object* l_LearningWorker_handle___closed__0 = (const lean_object*)&l_LearningWorker_handle___closed__0_value;
static const lean_string_object l_LearningWorker_handle___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 10, .m_capacity = 10, .m_length = 9, .m_data = "configure"};
static const lean_object* l_LearningWorker_handle___closed__1 = (const lean_object*)&l_LearningWorker_handle___closed__1_value;
static const lean_string_object l_LearningWorker_handle___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "bench"};
static const lean_object* l_LearningWorker_handle___closed__2 = (const lean_object*)&l_LearningWorker_handle___closed__2_value;
static const lean_string_object l_LearningWorker_handle___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "infer"};
static const lean_object* l_LearningWorker_handle___closed__3 = (const lean_object*)&l_LearningWorker_handle___closed__3_value;
static const lean_string_object l_LearningWorker_handle___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "unknown command"};
static const lean_object* l_LearningWorker_handle___closed__4 = (const lean_object*)&l_LearningWorker_handle___closed__4_value;
static const lean_ctor_object l_LearningWorker_handle___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_LearningWorker_handle___closed__4_value)}};
static const lean_object* l_LearningWorker_handle___closed__5 = (const lean_object*)&l_LearningWorker_handle___closed__5_value;
static const lean_string_object l_LearningWorker_handle___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "outputs"};
static const lean_object* l_LearningWorker_handle___closed__6 = (const lean_object*)&l_LearningWorker_handle___closed__6_value;
static const lean_string_object l_LearningWorker_handle___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "configured"};
static const lean_object* l_LearningWorker_handle___closed__7 = (const lean_object*)&l_LearningWorker_handle___closed__7_value;
LEAN_EXPORT lean_object* l_LearningWorker_handle(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_handle___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object l_LearningWorker_loop___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "done"};
static const lean_object* l_LearningWorker_loop___closed__0 = (const lean_object*)&l_LearningWorker_loop___closed__0_value;
static const lean_ctor_object l_LearningWorker_loop___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 3}, .m_objs = {((lean_object*)&l_LearningWorker_loop___closed__0_value)}};
static const lean_object* l_LearningWorker_loop___closed__1 = (const lean_object*)&l_LearningWorker_loop___closed__1_value;
static const lean_ctor_object l_LearningWorker_loop___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_LearningWorker_sampleEvent___closed__0_value),((lean_object*)&l_LearningWorker_loop___closed__1_value)}};
static const lean_object* l_LearningWorker_loop___closed__2 = (const lean_object*)&l_LearningWorker_loop___closed__2_value;
static const lean_string_object l_LearningWorker_loop___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "result"};
static const lean_object* l_LearningWorker_loop___closed__3 = (const lean_object*)&l_LearningWorker_loop___closed__3_value;
static const lean_string_object l_LearningWorker_loop___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "error"};
static const lean_object* l_LearningWorker_loop___closed__4 = (const lean_object*)&l_LearningWorker_loop___closed__4_value;
LEAN_EXPORT lean_object* l_LearningWorker_loop(lean_object*);
LEAN_EXPORT lean_object* l_LearningWorker_loop___boxed(lean_object*, lean_object*);
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
LEAN_EXPORT lean_object* l_LearningWorker_orError___redArg(lean_object* v_x_1_){
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
LEAN_EXPORT lean_object* l_LearningWorker_orError___redArg___boxed(lean_object* v_x_20_, lean_object* v_a_21_){
_start:
{
lean_object* v_res_22_; 
v_res_22_ = l_LearningWorker_orError___redArg(v_x_20_);
return v_res_22_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_orError(lean_object* v_00_u03b1_23_, lean_object* v_x_24_){
_start:
{
lean_object* v___x_26_; 
v___x_26_ = l_LearningWorker_orError___redArg(v_x_24_);
return v___x_26_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_orError___boxed(lean_object* v_00_u03b1_27_, lean_object* v_x_28_, lean_object* v_a_29_){
_start:
{
lean_object* v_res_30_; 
v_res_30_ = l_LearningWorker_orError(v_00_u03b1_27_, v_x_28_);
return v_res_30_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00LearningWorker_decodeTree_spec__0_spec__0(lean_object* v_j_31_){
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
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_decodeTree_spec__0(lean_object* v_j_50_, lean_object* v_k_51_){
_start:
{
lean_object* v___x_52_; lean_object* v___x_53_; 
v___x_52_ = l_Lean_Json_getObjValD(v_j_50_, v_k_51_);
v___x_53_ = l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00LearningWorker_decodeTree_spec__0_spec__0(v___x_52_);
return v___x_53_;
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_decodeTree_spec__0___boxed(lean_object* v_j_54_, lean_object* v_k_55_){
_start:
{
lean_object* v_res_56_; 
v_res_56_ = l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_decodeTree_spec__0(v_j_54_, v_k_55_);
lean_dec_ref(v_k_55_);
return v_res_56_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_decodeTree(lean_object* v_x_74_, lean_object* v_x_75_){
_start:
{
lean_object* v_zero_76_; uint8_t v_isZero_77_; 
v_zero_76_ = lean_unsigned_to_nat(0u);
v_isZero_77_ = lean_nat_dec_eq(v_x_74_, v_zero_76_);
if (v_isZero_77_ == 1)
{
lean_object* v___x_78_; 
lean_dec(v_x_75_);
v___x_78_ = ((lean_object*)(l_LearningWorker_decodeTree___closed__1));
return v___x_78_;
}
else
{
lean_object* v___x_79_; lean_object* v___x_80_; 
v___x_79_ = ((lean_object*)(l_LearningWorker_decodeTree___closed__2));
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
v___x_90_ = ((lean_object*)(l_LearningWorker_decodeTree___closed__3));
v___x_91_ = lean_string_dec_eq(v_a_89_, v___x_90_);
if (v___x_91_ == 0)
{
lean_object* v___x_92_; uint8_t v___x_93_; 
v___x_92_ = ((lean_object*)(l_LearningWorker_decodeTree___closed__4));
v___x_93_ = lean_string_dec_eq(v_a_89_, v___x_92_);
lean_dec(v_a_89_);
if (v___x_93_ == 0)
{
lean_object* v___x_94_; 
lean_dec(v_x_75_);
v___x_94_ = ((lean_object*)(l_LearningWorker_decodeTree___closed__6));
return v___x_94_;
}
else
{
lean_object* v___x_95_; lean_object* v___x_96_; 
v___x_95_ = ((lean_object*)(l_LearningWorker_decodeTree___closed__7));
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
v___x_106_ = ((lean_object*)(l_LearningWorker_decodeTree___closed__8));
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
v___x_117_ = ((lean_object*)(l_LearningWorker_decodeTree___closed__9));
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
v___x_130_ = l_LearningWorker_decodeTree(v_n_129_, v_a_127_);
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
v___x_132_ = ((lean_object*)(l_LearningWorker_decodeTree___closed__10));
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
v___x_143_ = l_LearningWorker_decodeTree(v_n_129_, v_a_142_);
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
v___x_153_ = ((lean_object*)(l_LearningWorker_decodeTree___closed__11));
v___x_154_ = l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_decodeTree_spec__0(v_x_75_, v___x_153_);
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
v___x_170_ = ((lean_object*)(l_LearningWorker_decodeTree___closed__13));
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
LEAN_EXPORT lean_object* l_LearningWorker_decodeTree___boxed(lean_object* v_x_176_, lean_object* v_x_177_){
_start:
{
lean_object* v_res_178_; 
v_res_178_ = l_LearningWorker_decodeTree(v_x_176_, v_x_177_);
lean_dec(v_x_176_);
return v_res_178_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_decodeModel(lean_object* v_j_187_){
_start:
{
lean_object* v___x_188_; lean_object* v___x_189_; 
v___x_188_ = ((lean_object*)(l_LearningWorker_decodeModel___closed__0));
lean_inc(v_j_187_);
v___x_189_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_187_, v___x_188_);
if (lean_obj_tag(v___x_189_) == 0)
{
lean_object* v___x_190_; 
lean_dec_ref_known(v___x_189_, 1);
lean_dec(v_j_187_);
v___x_190_ = lean_box(0);
return v___x_190_;
}
else
{
lean_object* v_a_191_; lean_object* v___x_192_; lean_object* v___x_193_; 
v_a_191_ = lean_ctor_get(v___x_189_, 0);
lean_inc(v_a_191_);
lean_dec_ref_known(v___x_189_, 1);
v___x_192_ = ((lean_object*)(l_LearningWorker_decodeModel___closed__1));
lean_inc(v_j_187_);
v___x_193_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_j_187_, v___x_192_);
if (lean_obj_tag(v___x_193_) == 0)
{
lean_object* v___x_194_; 
lean_dec_ref_known(v___x_193_, 1);
lean_dec(v_a_191_);
lean_dec(v_j_187_);
v___x_194_ = lean_box(0);
return v___x_194_;
}
else
{
lean_object* v_a_195_; lean_object* v___x_196_; lean_object* v___x_197_; 
v_a_195_ = lean_ctor_get(v___x_193_, 0);
lean_inc(v_a_195_);
lean_dec_ref_known(v___x_193_, 1);
v___x_196_ = ((lean_object*)(l_LearningWorker_decodeModel___closed__2));
lean_inc(v_j_187_);
v___x_197_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_j_187_, v___x_196_);
if (lean_obj_tag(v___x_197_) == 0)
{
lean_object* v___x_198_; 
lean_dec_ref_known(v___x_197_, 1);
lean_dec(v_a_195_);
lean_dec(v_a_191_);
lean_dec(v_j_187_);
v___x_198_ = lean_box(0);
return v___x_198_;
}
else
{
lean_object* v_a_199_; uint8_t v___y_201_; lean_object* v___x_233_; uint8_t v___x_234_; 
v_a_199_ = lean_ctor_get(v___x_197_, 0);
lean_inc(v_a_199_);
lean_dec_ref_known(v___x_197_, 1);
v___x_233_ = lean_unsigned_to_nat(1u);
v___x_234_ = lean_nat_dec_eq(v_a_191_, v___x_233_);
lean_dec(v_a_191_);
if (v___x_234_ == 0)
{
lean_dec(v_a_195_);
v___y_201_ = v___x_234_;
goto v___jp_200_;
}
else
{
lean_object* v___x_235_; uint8_t v___x_236_; 
v___x_235_ = ((lean_object*)(l_LearningWorker_decodeModel___closed__7));
v___x_236_ = lean_string_dec_eq(v_a_195_, v___x_235_);
lean_dec(v_a_195_);
v___y_201_ = v___x_236_;
goto v___jp_200_;
}
v___jp_200_:
{
if (v___y_201_ == 0)
{
lean_object* v___x_202_; 
lean_dec(v_a_199_);
lean_dec(v_j_187_);
v___x_202_ = lean_box(0);
return v___x_202_;
}
else
{
lean_object* v___x_203_; uint8_t v___x_204_; 
v___x_203_ = ((lean_object*)(l_LearningWorker_decodeModel___closed__3));
v___x_204_ = lean_string_dec_eq(v_a_199_, v___x_203_);
lean_dec(v_a_199_);
if (v___x_204_ == 0)
{
lean_object* v___x_205_; 
lean_dec(v_j_187_);
v___x_205_ = lean_box(0);
return v___x_205_;
}
else
{
lean_object* v___x_206_; lean_object* v___x_207_; 
v___x_206_ = ((lean_object*)(l_LearningWorker_decodeModel___closed__4));
lean_inc(v_j_187_);
v___x_207_ = l_Lean_Json_getObjVal_x3f(v_j_187_, v___x_206_);
if (lean_obj_tag(v___x_207_) == 0)
{
lean_object* v___x_208_; 
lean_dec_ref_known(v___x_207_, 1);
lean_dec(v_j_187_);
v___x_208_ = lean_box(0);
return v___x_208_;
}
else
{
lean_object* v_a_209_; lean_object* v___x_210_; lean_object* v___x_211_; 
v_a_209_ = lean_ctor_get(v___x_207_, 0);
lean_inc(v_a_209_);
lean_dec_ref_known(v___x_207_, 1);
v___x_210_ = lean_unsigned_to_nat(9u);
v___x_211_ = l_LearningWorker_decodeTree(v___x_210_, v_a_209_);
if (lean_obj_tag(v___x_211_) == 0)
{
lean_object* v___x_212_; 
lean_dec_ref_known(v___x_211_, 1);
lean_dec(v_j_187_);
v___x_212_ = lean_box(0);
return v___x_212_;
}
else
{
lean_object* v_a_213_; lean_object* v___x_214_; lean_object* v___x_215_; 
v_a_213_ = lean_ctor_get(v___x_211_, 0);
lean_inc(v_a_213_);
lean_dec_ref_known(v___x_211_, 1);
v___x_214_ = ((lean_object*)(l_LearningWorker_decodeTree___closed__2));
v___x_215_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_j_187_, v___x_214_);
if (lean_obj_tag(v___x_215_) == 0)
{
lean_object* v___x_216_; 
lean_dec_ref_known(v___x_215_, 1);
lean_dec(v_a_213_);
v___x_216_ = lean_box(0);
return v___x_216_;
}
else
{
lean_object* v_a_217_; lean_object* v___x_219_; uint8_t v_isShared_220_; uint8_t v_isSharedCheck_232_; 
v_a_217_ = lean_ctor_get(v___x_215_, 0);
v_isSharedCheck_232_ = !lean_is_exclusive(v___x_215_);
if (v_isSharedCheck_232_ == 0)
{
v___x_219_ = v___x_215_;
v_isShared_220_ = v_isSharedCheck_232_;
goto v_resetjp_218_;
}
else
{
lean_inc(v_a_217_);
lean_dec(v___x_215_);
v___x_219_ = lean_box(0);
v_isShared_220_ = v_isSharedCheck_232_;
goto v_resetjp_218_;
}
v_resetjp_218_:
{
lean_object* v___x_221_; uint8_t v___x_222_; 
v___x_221_ = ((lean_object*)(l_LearningWorker_decodeModel___closed__5));
v___x_222_ = lean_string_dec_eq(v_a_217_, v___x_221_);
if (v___x_222_ == 0)
{
lean_object* v___x_223_; uint8_t v___x_224_; 
v___x_223_ = ((lean_object*)(l_LearningWorker_decodeModel___closed__6));
v___x_224_ = lean_string_dec_eq(v_a_217_, v___x_223_);
lean_dec(v_a_217_);
if (v___x_224_ == 0)
{
lean_object* v___x_225_; 
lean_del_object(v___x_219_);
lean_dec(v_a_213_);
v___x_225_ = lean_box(0);
return v___x_225_;
}
else
{
lean_object* v___x_227_; 
if (v_isShared_220_ == 0)
{
lean_ctor_set_tag(v___x_219_, 2);
lean_ctor_set(v___x_219_, 0, v_a_213_);
v___x_227_ = v___x_219_;
goto v_reusejp_226_;
}
else
{
lean_object* v_reuseFailAlloc_228_; 
v_reuseFailAlloc_228_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_228_, 0, v_a_213_);
v___x_227_ = v_reuseFailAlloc_228_;
goto v_reusejp_226_;
}
v_reusejp_226_:
{
return v___x_227_;
}
}
}
else
{
lean_object* v___x_230_; 
lean_dec(v_a_217_);
if (v_isShared_220_ == 0)
{
lean_ctor_set(v___x_219_, 0, v_a_213_);
v___x_230_ = v___x_219_;
goto v_reusejp_229_;
}
else
{
lean_object* v_reuseFailAlloc_231_; 
v_reuseFailAlloc_231_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_231_, 0, v_a_213_);
v___x_230_ = v_reuseFailAlloc_231_;
goto v_reusejp_229_;
}
v_reusejp_229_:
{
return v___x_230_;
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
LEAN_EXPORT lean_object* l_LearningWorker_decodePolicy(lean_object* v_j_245_){
_start:
{
lean_object* v___x_248_; lean_object* v___x_249_; 
v___x_248_ = ((lean_object*)(l_LearningWorker_decodeTree___closed__2));
lean_inc(v_j_245_);
v___x_249_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_j_245_, v___x_248_);
if (lean_obj_tag(v___x_249_) == 0)
{
lean_dec_ref_known(v___x_249_, 1);
lean_dec(v_j_245_);
goto v___jp_246_;
}
else
{
lean_object* v_a_250_; lean_object* v___x_251_; uint8_t v___x_252_; 
v_a_250_ = lean_ctor_get(v___x_249_, 0);
lean_inc(v_a_250_);
lean_dec_ref_known(v___x_249_, 1);
v___x_251_ = ((lean_object*)(l_LearningWorker_decodePolicy___closed__1));
v___x_252_ = lean_string_dec_eq(v_a_250_, v___x_251_);
if (v___x_252_ == 0)
{
lean_object* v___x_253_; uint8_t v___x_254_; 
v___x_253_ = ((lean_object*)(l_LearningWorker_decodePolicy___closed__2));
v___x_254_ = lean_string_dec_eq(v_a_250_, v___x_253_);
if (v___x_254_ == 0)
{
lean_object* v___x_255_; uint8_t v___x_256_; 
v___x_255_ = ((lean_object*)(l_LearningWorker_decodePolicy___closed__3));
v___x_256_ = lean_string_dec_eq(v_a_250_, v___x_255_);
if (v___x_256_ == 0)
{
lean_object* v___x_257_; uint8_t v___x_258_; 
v___x_257_ = ((lean_object*)(l_LearningWorker_decodePolicy___closed__4));
v___x_258_ = lean_string_dec_eq(v_a_250_, v___x_257_);
lean_dec(v_a_250_);
if (v___x_258_ == 0)
{
lean_dec(v_j_245_);
goto v___jp_246_;
}
else
{
lean_object* v___x_259_; lean_object* v___x_260_; 
v___x_259_ = ((lean_object*)(l_LearningWorker_decodePolicy___closed__5));
v___x_260_ = l_Lean_Json_getObjVal_x3f(v_j_245_, v___x_259_);
if (lean_obj_tag(v___x_260_) == 0)
{
lean_dec_ref_known(v___x_260_, 1);
goto v___jp_246_;
}
else
{
lean_object* v_a_261_; lean_object* v___x_263_; uint8_t v_isShared_264_; uint8_t v_isSharedCheck_269_; 
v_a_261_ = lean_ctor_get(v___x_260_, 0);
v_isSharedCheck_269_ = !lean_is_exclusive(v___x_260_);
if (v_isSharedCheck_269_ == 0)
{
v___x_263_ = v___x_260_;
v_isShared_264_ = v_isSharedCheck_269_;
goto v_resetjp_262_;
}
else
{
lean_inc(v_a_261_);
lean_dec(v___x_260_);
v___x_263_ = lean_box(0);
v_isShared_264_ = v_isSharedCheck_269_;
goto v_resetjp_262_;
}
v_resetjp_262_:
{
lean_object* v___x_265_; lean_object* v___x_267_; 
v___x_265_ = l_LearningWorker_decodeModel(v_a_261_);
if (v_isShared_264_ == 0)
{
lean_ctor_set_tag(v___x_263_, 3);
lean_ctor_set(v___x_263_, 0, v___x_265_);
v___x_267_ = v___x_263_;
goto v_reusejp_266_;
}
else
{
lean_object* v_reuseFailAlloc_268_; 
v_reuseFailAlloc_268_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_268_, 0, v___x_265_);
v___x_267_ = v_reuseFailAlloc_268_;
goto v_reusejp_266_;
}
v_reusejp_266_:
{
return v___x_267_;
}
}
}
}
}
else
{
lean_object* v___x_270_; 
lean_dec(v_a_250_);
lean_dec(v_j_245_);
v___x_270_ = lean_box(2);
return v___x_270_;
}
}
else
{
lean_object* v___x_271_; 
lean_dec(v_a_250_);
lean_dec(v_j_245_);
v___x_271_ = lean_box(1);
return v___x_271_;
}
}
else
{
lean_object* v___x_272_; lean_object* v___x_273_; 
lean_dec(v_a_250_);
v___x_272_ = ((lean_object*)(l_LearningWorker_decodePolicy___closed__6));
v___x_273_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_IO_FS_Stream_readRequestAs___at___00Lean_IO_FS_Stream_readLspRequestAs___at___00Lean_Server_FileWorker_initAndRunWorker_spec__0_spec__0_spec__2(v_j_245_, v___x_272_);
if (lean_obj_tag(v___x_273_) == 0)
{
lean_dec_ref_known(v___x_273_, 1);
goto v___jp_246_;
}
else
{
lean_object* v_a_274_; lean_object* v___x_276_; uint8_t v_isShared_277_; uint8_t v_isSharedCheck_281_; 
v_a_274_ = lean_ctor_get(v___x_273_, 0);
v_isSharedCheck_281_ = !lean_is_exclusive(v___x_273_);
if (v_isSharedCheck_281_ == 0)
{
v___x_276_ = v___x_273_;
v_isShared_277_ = v_isSharedCheck_281_;
goto v_resetjp_275_;
}
else
{
lean_inc(v_a_274_);
lean_dec(v___x_273_);
v___x_276_ = lean_box(0);
v_isShared_277_ = v_isSharedCheck_281_;
goto v_resetjp_275_;
}
v_resetjp_275_:
{
lean_object* v___x_279_; 
if (v_isShared_277_ == 0)
{
lean_ctor_set_tag(v___x_276_, 0);
v___x_279_ = v___x_276_;
goto v_reusejp_278_;
}
else
{
lean_object* v_reuseFailAlloc_280_; 
v_reuseFailAlloc_280_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_280_, 0, v_a_274_);
v___x_279_ = v_reuseFailAlloc_280_;
goto v_reusejp_278_;
}
v_reusejp_278_:
{
return v___x_279_;
}
}
}
}
}
v___jp_246_:
{
lean_object* v___x_247_; 
v___x_247_ = ((lean_object*)(l_LearningWorker_decodePolicy___closed__0));
return v___x_247_;
}
}
}
static lean_object* _init_l_LearningWorker_featureSelect___closed__0(void){
_start:
{
lean_object* v___x_282_; lean_object* v___x_283_; 
v___x_282_ = lean_unsigned_to_nat(5u);
v___x_283_ = lean_nat_to_int(v___x_282_);
return v___x_283_;
}
}
static lean_object* _init_l_LearningWorker_featureSelect___closed__1(void){
_start:
{
lean_object* v___x_284_; lean_object* v___x_285_; 
v___x_284_ = lean_obj_once(&l_LearningWorker_featureSelect___closed__0, &l_LearningWorker_featureSelect___closed__0_once, _init_l_LearningWorker_featureSelect___closed__0);
v___x_285_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_285_, 0, v___x_284_);
return v___x_285_;
}
}
static lean_object* _init_l_LearningWorker_featureSelect___closed__2(void){
_start:
{
lean_object* v___x_286_; lean_object* v___x_287_; 
v___x_286_ = lean_unsigned_to_nat(1u);
v___x_287_ = lean_nat_to_int(v___x_286_);
return v___x_287_;
}
}
static lean_object* _init_l_LearningWorker_featureSelect___closed__3(void){
_start:
{
lean_object* v___x_288_; lean_object* v___x_289_; 
v___x_288_ = lean_obj_once(&l_LearningWorker_featureSelect___closed__2, &l_LearningWorker_featureSelect___closed__2_once, _init_l_LearningWorker_featureSelect___closed__2);
v___x_289_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_289_, 0, v___x_288_);
return v___x_289_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_featureSelect(lean_object* v_p_290_, lean_object* v_fs_291_){
_start:
{
lean_object* v___y_293_; 
switch(lean_obj_tag(v_p_290_))
{
case 0:
{
lean_object* v_id_298_; lean_object* v___x_300_; uint8_t v_isShared_301_; uint8_t v_isSharedCheck_305_; 
v_id_298_ = lean_ctor_get(v_p_290_, 0);
v_isSharedCheck_305_ = !lean_is_exclusive(v_p_290_);
if (v_isSharedCheck_305_ == 0)
{
v___x_300_ = v_p_290_;
v_isShared_301_ = v_isSharedCheck_305_;
goto v_resetjp_299_;
}
else
{
lean_inc(v_id_298_);
lean_dec(v_p_290_);
v___x_300_ = lean_box(0);
v_isShared_301_ = v_isSharedCheck_305_;
goto v_resetjp_299_;
}
v_resetjp_299_:
{
lean_object* v___x_303_; 
if (v_isShared_301_ == 0)
{
lean_ctor_set_tag(v___x_300_, 1);
v___x_303_ = v___x_300_;
goto v_reusejp_302_;
}
else
{
lean_object* v_reuseFailAlloc_304_; 
v_reuseFailAlloc_304_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_304_, 0, v_id_298_);
v___x_303_ = v_reuseFailAlloc_304_;
goto v_reusejp_302_;
}
v_reusejp_302_:
{
return v___x_303_;
}
}
}
case 1:
{
lean_object* v___x_306_; 
v___x_306_ = l_LeanSort_LearnedSelection_sampleRule(v_fs_291_);
return v___x_306_;
}
case 2:
{
lean_object* v___x_307_; lean_object* v___x_308_; 
v___x_307_ = lean_unsigned_to_nat(0u);
v___x_308_ = l_List_get_x3fInternal___redArg(v_fs_291_, v___x_307_);
if (lean_obj_tag(v___x_308_) == 0)
{
v___y_293_ = v___x_307_;
goto v___jp_292_;
}
else
{
lean_object* v_val_309_; 
v_val_309_ = lean_ctor_get(v___x_308_, 0);
lean_inc(v_val_309_);
lean_dec_ref_known(v___x_308_, 1);
v___y_293_ = v_val_309_;
goto v___jp_292_;
}
}
default: 
{
lean_object* v_model_310_; lean_object* v___x_311_; 
v_model_310_ = lean_ctor_get(v_p_290_, 0);
lean_inc(v_model_310_);
lean_dec_ref_known(v_p_290_, 1);
v___x_311_ = l_LeanSort_LearnedSelection_Model_predict(v_model_310_, v_fs_291_);
return v___x_311_;
}
}
v___jp_292_:
{
lean_object* v___x_294_; uint8_t v___x_295_; 
v___x_294_ = lean_unsigned_to_nat(32u);
v___x_295_ = lean_nat_dec_le(v___y_293_, v___x_294_);
lean_dec(v___y_293_);
if (v___x_295_ == 0)
{
lean_object* v___x_296_; 
v___x_296_ = lean_obj_once(&l_LearningWorker_featureSelect___closed__1, &l_LearningWorker_featureSelect___closed__1_once, _init_l_LearningWorker_featureSelect___closed__1);
return v___x_296_;
}
else
{
lean_object* v___x_297_; 
v___x_297_ = lean_obj_once(&l_LearningWorker_featureSelect___closed__3, &l_LearningWorker_featureSelect___closed__3_once, _init_l_LearningWorker_featureSelect___closed__3);
return v___x_297_;
}
}
}
}
LEAN_EXPORT lean_object* l_LearningWorker_featureSelect___boxed(lean_object* v_p_312_, lean_object* v_fs_313_){
_start:
{
lean_object* v_res_314_; 
v_res_314_ = l_LearningWorker_featureSelect(v_p_312_, v_fs_313_);
lean_dec(v_fs_313_);
return v_res_314_;
}
}
LEAN_EXPORT uint8_t l_LearningWorker_usesFeatures(lean_object* v_x_315_){
_start:
{
switch(lean_obj_tag(v_x_315_))
{
case 1:
{
uint8_t v___x_316_; 
v___x_316_ = 1;
return v___x_316_;
}
case 3:
{
uint8_t v___x_317_; 
v___x_317_ = 1;
return v___x_317_;
}
default: 
{
uint8_t v___x_318_; 
v___x_318_ = 0;
return v___x_318_;
}
}
}
}
LEAN_EXPORT lean_object* l_LearningWorker_usesFeatures___boxed(lean_object* v_x_319_){
_start:
{
uint8_t v_res_320_; lean_object* v_r_321_; 
v_res_320_ = l_LearningWorker_usesFeatures(v_x_319_);
lean_dec(v_x_319_);
v_r_321_ = lean_box(v_res_320_);
return v_r_321_;
}
}
LEAN_EXPORT lean_object* l_List_foldl___at___00LearningWorker_checksum_spec__0(lean_object* v_x_322_, lean_object* v_x_323_){
_start:
{
if (lean_obj_tag(v_x_323_) == 0)
{
return v_x_322_;
}
else
{
lean_object* v_head_324_; lean_object* v_tail_325_; lean_object* v___x_326_; lean_object* v___x_327_; lean_object* v___x_328_; lean_object* v___x_329_; lean_object* v___x_330_; 
v_head_324_ = lean_ctor_get(v_x_323_, 0);
v_tail_325_ = lean_ctor_get(v_x_323_, 1);
v___x_326_ = lean_unsigned_to_nat(33u);
v___x_327_ = lean_nat_mul(v_x_322_, v___x_326_);
lean_dec(v_x_322_);
v___x_328_ = lean_nat_add(v___x_327_, v_head_324_);
lean_dec(v___x_327_);
v___x_329_ = lean_unsigned_to_nat(1000000007u);
v___x_330_ = lean_nat_mod(v___x_328_, v___x_329_);
lean_dec(v___x_328_);
v_x_322_ = v___x_330_;
v_x_323_ = v_tail_325_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_List_foldl___at___00LearningWorker_checksum_spec__0___boxed(lean_object* v_x_332_, lean_object* v_x_333_){
_start:
{
lean_object* v_res_334_; 
v_res_334_ = l_List_foldl___at___00LearningWorker_checksum_spec__0(v_x_332_, v_x_333_);
lean_dec(v_x_333_);
return v_res_334_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_checksum(lean_object* v_xs_335_){
_start:
{
lean_object* v___x_336_; lean_object* v___x_337_; 
v___x_336_ = lean_unsigned_to_nat(0u);
v___x_337_ = l_List_foldl___at___00LearningWorker_checksum_spec__0(v___x_336_, v_xs_335_);
return v___x_337_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_checksum___boxed(lean_object* v_xs_338_){
_start:
{
lean_object* v_res_339_; 
v_res_339_ = l_LearningWorker_checksum(v_xs_338_);
lean_dec(v_xs_338_);
return v_res_339_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_timedKernel(lean_object* v_id_343_, lean_object* v_source_344_, lean_object* v_outSink_345_, lean_object* v_idSink_346_, lean_object* v_expected_347_){
_start:
{
lean_object* v___x_349_; lean_object* v___x_350_; lean_object* v___x_351_; lean_object* v___x_352_; lean_object* v___x_353_; lean_object* v___x_354_; lean_object* v___x_355_; lean_object* v___x_356_; lean_object* v___x_357_; uint8_t v___x_358_; 
v___x_349_ = lean_io_mono_nanos_now();
v___x_350_ = lean_st_ref_get(v_source_344_);
lean_inc_n(v_id_343_, 2);
v___x_351_ = lean_nat_to_int(v_id_343_);
v___x_352_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_352_, 0, v___x_351_);
v___x_353_ = l_LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0(v___x_352_, v___x_350_);
lean_dec_ref_known(v___x_352_, 1);
v___x_354_ = l_LearningWorker_checksum(v___x_353_);
v___x_355_ = lean_st_ref_set(v_outSink_345_, v___x_354_);
v___x_356_ = lean_st_ref_set(v_idSink_346_, v_id_343_);
v___x_357_ = lean_io_mono_nanos_now();
v___x_358_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v___x_353_, v_expected_347_);
lean_dec(v___x_353_);
if (v___x_358_ == 0)
{
lean_object* v___x_359_; lean_object* v___x_360_; 
lean_dec(v___x_357_);
lean_dec(v___x_349_);
lean_dec(v_id_343_);
v___x_359_ = ((lean_object*)(l_LearningWorker_timedKernel___closed__1));
v___x_360_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_360_, 0, v___x_359_);
return v___x_360_;
}
else
{
lean_object* v___x_361_; lean_object* v___x_362_; lean_object* v___x_363_; 
v___x_361_ = lean_nat_sub(v___x_357_, v___x_349_);
lean_dec(v___x_349_);
lean_dec(v___x_357_);
v___x_362_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_362_, 0, v___x_361_);
lean_ctor_set(v___x_362_, 1, v_id_343_);
v___x_363_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_363_, 0, v___x_362_);
return v___x_363_;
}
}
}
LEAN_EXPORT lean_object* l_LearningWorker_timedKernel___boxed(lean_object* v_id_364_, lean_object* v_source_365_, lean_object* v_outSink_366_, lean_object* v_idSink_367_, lean_object* v_expected_368_, lean_object* v_a_369_){
_start:
{
lean_object* v_res_370_; 
v_res_370_ = l_LearningWorker_timedKernel(v_id_364_, v_source_365_, v_outSink_366_, v_idSink_367_, v_expected_368_);
lean_dec(v_expected_368_);
lean_dec(v_idSink_367_);
lean_dec(v_outSink_366_);
lean_dec(v_source_365_);
return v_res_370_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_timedPolicy(lean_object* v_p_374_, lean_object* v_source_375_, lean_object* v_outSink_376_, lean_object* v_idSink_377_, lean_object* v_expected_378_){
_start:
{
lean_object* v___x_380_; lean_object* v___x_381_; lean_object* v___x_382_; lean_object* v___x_383_; lean_object* v___x_384_; lean_object* v___x_385_; lean_object* v___x_386_; lean_object* v___x_387_; lean_object* v___x_388_; uint8_t v___x_389_; 
v___x_380_ = lean_io_mono_nanos_now();
v___x_381_ = lean_st_ref_get(v_source_375_);
v___x_382_ = l_LeanSort_LearnedSelection_select(v_p_374_, v___x_381_);
v___x_383_ = l_LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0(v___x_382_, v___x_381_);
v___x_384_ = l_LearningWorker_checksum(v___x_383_);
v___x_385_ = lean_st_ref_set(v_outSink_376_, v___x_384_);
v___x_386_ = l_LeanSort_LearnedSelection_resolve(v___x_382_);
lean_dec(v___x_382_);
lean_inc(v___x_386_);
v___x_387_ = lean_st_ref_set(v_idSink_377_, v___x_386_);
v___x_388_ = lean_io_mono_nanos_now();
v___x_389_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v___x_383_, v_expected_378_);
lean_dec(v___x_383_);
if (v___x_389_ == 0)
{
lean_object* v___x_390_; lean_object* v___x_391_; 
lean_dec(v___x_388_);
lean_dec(v___x_386_);
lean_dec(v___x_380_);
v___x_390_ = ((lean_object*)(l_LearningWorker_timedPolicy___closed__1));
v___x_391_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_391_, 0, v___x_390_);
return v___x_391_;
}
else
{
lean_object* v___x_392_; lean_object* v___x_393_; lean_object* v___x_394_; 
v___x_392_ = lean_nat_sub(v___x_388_, v___x_380_);
lean_dec(v___x_380_);
lean_dec(v___x_388_);
v___x_393_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_393_, 0, v___x_392_);
lean_ctor_set(v___x_393_, 1, v___x_386_);
v___x_394_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_394_, 0, v___x_393_);
return v___x_394_;
}
}
}
LEAN_EXPORT lean_object* l_LearningWorker_timedPolicy___boxed(lean_object* v_p_395_, lean_object* v_source_396_, lean_object* v_outSink_397_, lean_object* v_idSink_398_, lean_object* v_expected_399_, lean_object* v_a_400_){
_start:
{
lean_object* v_res_401_; 
v_res_401_ = l_LearningWorker_timedPolicy(v_p_395_, v_source_396_, v_outSink_397_, v_idSink_398_, v_expected_399_);
lean_dec(v_expected_399_);
lean_dec(v_idSink_398_);
lean_dec(v_outSink_397_);
lean_dec(v_source_396_);
return v_res_401_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_timedFeatures(lean_object* v_source_402_, lean_object* v_sink_403_){
_start:
{
lean_object* v___x_405_; lean_object* v___x_406_; lean_object* v___x_407_; lean_object* v___x_408_; lean_object* v___x_409_; lean_object* v___x_410_; lean_object* v___x_411_; lean_object* v___x_412_; 
v___x_405_ = lean_io_mono_nanos_now();
v___x_406_ = lean_st_ref_get(v_source_402_);
v___x_407_ = l_LeanSort_LearnedSelection_features(v___x_406_);
lean_dec(v___x_406_);
v___x_408_ = l_LearningWorker_checksum(v___x_407_);
lean_dec(v___x_407_);
v___x_409_ = lean_st_ref_set(v_sink_403_, v___x_408_);
v___x_410_ = lean_io_mono_nanos_now();
v___x_411_ = lean_nat_sub(v___x_410_, v___x_405_);
lean_dec(v___x_405_);
lean_dec(v___x_410_);
v___x_412_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_412_, 0, v___x_411_);
return v___x_412_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_timedFeatures___boxed(lean_object* v_source_413_, lean_object* v_sink_414_, lean_object* v_a_415_){
_start:
{
lean_object* v_res_416_; 
v_res_416_ = l_LearningWorker_timedFeatures(v_source_413_, v_sink_414_);
lean_dec(v_sink_414_);
lean_dec(v_source_413_);
return v_res_416_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_timedDecision(lean_object* v_p_417_, lean_object* v_source_418_, lean_object* v_sink_419_){
_start:
{
lean_object* v___x_421_; lean_object* v___x_422_; lean_object* v___x_423_; lean_object* v___x_424_; lean_object* v___x_425_; lean_object* v___x_426_; lean_object* v___x_427_; lean_object* v___x_428_; 
v___x_421_ = lean_io_mono_nanos_now();
v___x_422_ = lean_st_ref_get(v_source_418_);
v___x_423_ = l_LearningWorker_featureSelect(v_p_417_, v___x_422_);
lean_dec(v___x_422_);
v___x_424_ = l_LeanSort_LearnedSelection_resolve(v___x_423_);
lean_dec(v___x_423_);
v___x_425_ = lean_st_ref_set(v_sink_419_, v___x_424_);
v___x_426_ = lean_io_mono_nanos_now();
v___x_427_ = lean_nat_sub(v___x_426_, v___x_421_);
lean_dec(v___x_421_);
lean_dec(v___x_426_);
v___x_428_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_428_, 0, v___x_427_);
return v___x_428_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_timedDecision___boxed(lean_object* v_p_429_, lean_object* v_source_430_, lean_object* v_sink_431_, lean_object* v_a_432_){
_start:
{
lean_object* v_res_433_; 
v_res_433_ = l_LearningWorker_timedDecision(v_p_429_, v_source_430_, v_sink_431_);
lean_dec(v_sink_431_);
lean_dec(v_source_430_);
return v_res_433_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_emit(lean_object* v_j_434_){
_start:
{
lean_object* v___x_436_; lean_object* v___x_437_; lean_object* v___x_438_; 
v___x_436_ = lean_get_stdout();
v___x_437_ = l_Lean_Json_compress(v_j_434_);
lean_inc_ref(v___x_436_);
v___x_438_ = l_IO_FS_Stream_putStrLn(v___x_436_, v___x_437_);
if (lean_obj_tag(v___x_438_) == 0)
{
lean_object* v_flush_439_; lean_object* v___x_440_; 
lean_dec_ref_known(v___x_438_, 1);
v_flush_439_ = lean_ctor_get(v___x_436_, 0);
lean_inc_ref(v_flush_439_);
lean_dec_ref(v___x_436_);
v___x_440_ = lean_apply_1(v_flush_439_, lean_box(0));
return v___x_440_;
}
else
{
lean_dec_ref(v___x_436_);
return v___x_438_;
}
}
}
LEAN_EXPORT lean_object* l_LearningWorker_emit___boxed(lean_object* v_j_441_, lean_object* v_a_442_){
_start:
{
lean_object* v_res_443_; 
v_res_443_ = l_LearningWorker_emit(v_j_441_);
return v_res_443_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_sampleEvent(lean_object* v_category_456_, lean_object* v_name_457_, lean_object* v_round_458_, lean_object* v_ns_459_, lean_object* v_id_460_){
_start:
{
lean_object* v___x_462_; lean_object* v___x_463_; lean_object* v___x_464_; lean_object* v___x_465_; lean_object* v___x_466_; lean_object* v___x_467_; lean_object* v___x_468_; lean_object* v___x_469_; lean_object* v___x_470_; lean_object* v___x_471_; lean_object* v___x_472_; lean_object* v___x_473_; lean_object* v___x_474_; lean_object* v___x_475_; lean_object* v___x_476_; lean_object* v___x_477_; lean_object* v___x_478_; lean_object* v___x_479_; lean_object* v___x_480_; lean_object* v___x_481_; lean_object* v___x_482_; lean_object* v___x_483_; lean_object* v___x_484_; lean_object* v___x_485_; lean_object* v___x_486_; lean_object* v___x_487_; lean_object* v___x_488_; lean_object* v___x_489_; 
v___x_462_ = ((lean_object*)(l_LearningWorker_sampleEvent___closed__3));
v___x_463_ = ((lean_object*)(l_LearningWorker_sampleEvent___closed__4));
v___x_464_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_464_, 0, v_category_456_);
v___x_465_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_465_, 0, v___x_463_);
lean_ctor_set(v___x_465_, 1, v___x_464_);
v___x_466_ = ((lean_object*)(l_LearningWorker_sampleEvent___closed__5));
v___x_467_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_467_, 0, v_name_457_);
v___x_468_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_468_, 0, v___x_466_);
lean_ctor_set(v___x_468_, 1, v___x_467_);
v___x_469_ = ((lean_object*)(l_LearningWorker_sampleEvent___closed__6));
v___x_470_ = l_Lean_JsonNumber_fromInt(v_round_458_);
v___x_471_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_471_, 0, v___x_470_);
v___x_472_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_472_, 0, v___x_469_);
lean_ctor_set(v___x_472_, 1, v___x_471_);
v___x_473_ = ((lean_object*)(l_LearningWorker_sampleEvent___closed__7));
v___x_474_ = l_Lean_JsonNumber_fromNat(v_ns_459_);
v___x_475_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_475_, 0, v___x_474_);
v___x_476_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_476_, 0, v___x_473_);
lean_ctor_set(v___x_476_, 1, v___x_475_);
v___x_477_ = ((lean_object*)(l_LearningWorker_sampleEvent___closed__8));
v___x_478_ = l_Lean_JsonNumber_fromNat(v_id_460_);
v___x_479_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_479_, 0, v___x_478_);
v___x_480_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_480_, 0, v___x_477_);
lean_ctor_set(v___x_480_, 1, v___x_479_);
v___x_481_ = lean_box(0);
v___x_482_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_482_, 0, v___x_480_);
lean_ctor_set(v___x_482_, 1, v___x_481_);
v___x_483_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_483_, 0, v___x_476_);
lean_ctor_set(v___x_483_, 1, v___x_482_);
v___x_484_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_484_, 0, v___x_472_);
lean_ctor_set(v___x_484_, 1, v___x_483_);
v___x_485_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_485_, 0, v___x_468_);
lean_ctor_set(v___x_485_, 1, v___x_484_);
v___x_486_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_486_, 0, v___x_465_);
lean_ctor_set(v___x_486_, 1, v___x_485_);
v___x_487_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_487_, 0, v___x_462_);
lean_ctor_set(v___x_487_, 1, v___x_486_);
v___x_488_ = l_Lean_Json_mkObj(v___x_487_);
lean_dec_ref_known(v___x_487_, 2);
v___x_489_ = l_LearningWorker_emit(v___x_488_);
return v___x_489_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_sampleEvent___boxed(lean_object* v_category_490_, lean_object* v_name_491_, lean_object* v_round_492_, lean_object* v_ns_493_, lean_object* v_id_494_, lean_object* v_a_495_){
_start:
{
lean_object* v_res_496_; 
v_res_496_ = l_LearningWorker_sampleEvent(v_category_490_, v_name_491_, v_round_492_, v_ns_493_, v_id_494_);
return v_res_496_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3_spec__7___redArg(lean_object* v_x_497_){
_start:
{
if (lean_obj_tag(v_x_497_) == 0)
{
lean_object* v_value_498_; lean_object* v___x_499_; lean_object* v___x_500_; 
v_value_498_ = lean_ctor_get(v_x_497_, 0);
lean_inc(v_value_498_);
lean_dec_ref_known(v_x_497_, 1);
v___x_499_ = lean_unsigned_to_nat(0u);
v___x_500_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_500_, 0, v_value_498_);
lean_ctor_set(v___x_500_, 1, v___x_499_);
return v___x_500_;
}
else
{
lean_object* v_left_501_; lean_object* v_right_502_; lean_object* v_next_503_; uint8_t v___x_504_; lean_object* v___x_505_; lean_object* v___x_506_; lean_object* v_rest_507_; lean_object* v_ret_508_; lean_object* v_time_509_; lean_object* v___x_511_; uint8_t v_isShared_512_; uint8_t v_isSharedCheck_518_; 
v_left_501_ = lean_ctor_get(v_x_497_, 0);
lean_inc(v_left_501_);
v_right_502_ = lean_ctor_get(v_x_497_, 1);
lean_inc(v_right_502_);
v_next_503_ = lean_ctor_get(v_x_497_, 2);
lean_inc_ref(v_next_503_);
lean_dec_ref_known(v_x_497_, 3);
v___x_504_ = lean_nat_dec_le(v_left_501_, v_right_502_);
lean_dec(v_right_502_);
lean_dec(v_left_501_);
v___x_505_ = lean_box(v___x_504_);
v___x_506_ = lean_apply_1(v_next_503_, v___x_505_);
v_rest_507_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3_spec__7___redArg(v___x_506_);
v_ret_508_ = lean_ctor_get(v_rest_507_, 0);
v_time_509_ = lean_ctor_get(v_rest_507_, 1);
v_isSharedCheck_518_ = !lean_is_exclusive(v_rest_507_);
if (v_isSharedCheck_518_ == 0)
{
v___x_511_ = v_rest_507_;
v_isShared_512_ = v_isSharedCheck_518_;
goto v_resetjp_510_;
}
else
{
lean_inc(v_time_509_);
lean_inc(v_ret_508_);
lean_dec(v_rest_507_);
v___x_511_ = lean_box(0);
v_isShared_512_ = v_isSharedCheck_518_;
goto v_resetjp_510_;
}
v_resetjp_510_:
{
lean_object* v___x_513_; lean_object* v___x_514_; lean_object* v___x_516_; 
v___x_513_ = lean_unsigned_to_nat(1u);
v___x_514_ = lean_nat_add(v_time_509_, v___x_513_);
lean_dec(v_time_509_);
if (v_isShared_512_ == 0)
{
lean_ctor_set(v___x_511_, 1, v___x_514_);
v___x_516_ = v___x_511_;
goto v_reusejp_515_;
}
else
{
lean_object* v_reuseFailAlloc_517_; 
v_reuseFailAlloc_517_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_517_, 0, v_ret_508_);
lean_ctor_set(v_reuseFailAlloc_517_, 1, v___x_514_);
v___x_516_ = v_reuseFailAlloc_517_;
goto v_reusejp_515_;
}
v_reusejp_515_:
{
return v___x_516_;
}
}
}
}
}
LEAN_EXPORT uint8_t l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3(lean_object* v_x_521_, lean_object* v_x_522_){
_start:
{
switch(lean_obj_tag(v_x_521_))
{
case 0:
{
uint8_t v___x_523_; 
lean_dec(v_x_522_);
v___x_523_ = 1;
return v___x_523_;
}
case 1:
{
lean_object* v_cut_524_; lean_object* v_left_525_; lean_object* v_right_526_; lean_object* v___x_527_; lean_object* v___x_528_; lean_object* v___x_529_; lean_object* v___x_530_; uint8_t v___x_531_; 
v_cut_524_ = lean_ctor_get(v_x_521_, 0);
v_left_525_ = lean_ctor_get(v_x_521_, 1);
v_right_526_ = lean_ctor_get(v_x_521_, 2);
v___x_527_ = l_List_lengthTR___redArg(v_x_522_);
v___x_528_ = lp_leansort_LeanSort_CostedPlan_Cut_position(v_cut_524_, v___x_527_);
lean_dec(v___x_527_);
v___x_529_ = ((lean_object*)(l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3___closed__0));
lean_inc(v___x_528_);
lean_inc(v_x_522_);
v___x_530_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_x_522_, v_x_522_, v___x_528_, v___x_529_);
v___x_531_ = l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3(v_left_525_, v___x_530_);
if (v___x_531_ == 0)
{
lean_dec(v___x_528_);
lean_dec(v_x_522_);
return v___x_531_;
}
else
{
lean_object* v___x_532_; 
v___x_532_ = l_List_drop___redArg(v___x_528_, v_x_522_);
lean_dec(v_x_522_);
v_x_521_ = v_right_526_;
v_x_522_ = v___x_532_;
goto _start;
}
}
default: 
{
lean_object* v___x_534_; lean_object* v___x_535_; lean_object* v_ret_536_; uint8_t v___x_537_; 
v___x_534_ = lp_leansort_LeanSort_ComparisonSort_checkSorted___redArg(v_x_522_);
v___x_535_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3_spec__7___redArg(v___x_534_);
v_ret_536_ = lean_ctor_get(v___x_535_, 0);
lean_inc(v_ret_536_);
lean_dec_ref(v___x_535_);
v___x_537_ = lean_unbox(v_ret_536_);
lean_dec(v_ret_536_);
return v___x_537_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3___boxed(lean_object* v_x_538_, lean_object* v_x_539_){
_start:
{
uint8_t v_res_540_; lean_object* v_r_541_; 
v_res_540_ = l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3(v_x_538_, v_x_539_);
lean_dec_ref(v_x_538_);
v_r_541_ = lean_box(v_res_540_);
return v_r_541_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0(lean_object* v_head_542_, lean_object* v_rest_543_){
_start:
{
lean_object* v___x_544_; lean_object* v___x_545_; 
v___x_544_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_544_, 0, v_head_542_);
lean_ctor_set(v___x_544_, 1, v_rest_543_);
v___x_545_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_544_);
return v___x_545_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__2___boxed(lean_object* v_x_546_, lean_object* v_tail_547_, lean_object* v___f_548_, lean_object* v_tail_549_, lean_object* v_x_550_, lean_object* v___f_551_, lean_object* v_smaller_552_){
_start:
{
uint8_t v_smaller_boxed_553_; lean_object* v_res_554_; 
v_smaller_boxed_553_ = lean_unbox(v_smaller_552_);
v_res_554_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__2(v_x_546_, v_tail_547_, v___f_548_, v_tail_549_, v_x_550_, v___f_551_, v_smaller_boxed_553_);
return v_res_554_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7(lean_object* v_x_555_, lean_object* v_x_556_){
_start:
{
if (lean_obj_tag(v_x_555_) == 0)
{
lean_object* v___x_557_; 
v___x_557_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_556_);
return v___x_557_;
}
else
{
if (lean_obj_tag(v_x_556_) == 0)
{
lean_object* v___x_558_; 
v___x_558_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_555_);
return v___x_558_;
}
else
{
lean_object* v_head_559_; lean_object* v_tail_560_; lean_object* v_head_561_; lean_object* v_tail_562_; lean_object* v___f_563_; lean_object* v___f_564_; lean_object* v___f_565_; uint8_t v___x_566_; lean_object* v___x_567_; lean_object* v___x_568_; lean_object* v___x_569_; lean_object* v___x_570_; 
v_head_559_ = lean_ctor_get(v_x_555_, 0);
lean_inc_n(v_head_559_, 2);
v_tail_560_ = lean_ctor_get(v_x_555_, 1);
lean_inc(v_tail_560_);
v_head_561_ = lean_ctor_get(v_x_556_, 0);
lean_inc_n(v_head_561_, 2);
v_tail_562_ = lean_ctor_get(v_x_556_, 1);
lean_inc(v_tail_562_);
v___f_563_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0), 2, 1);
lean_closure_set(v___f_563_, 0, v_head_559_);
v___f_564_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0), 2, 1);
lean_closure_set(v___f_564_, 0, v_head_561_);
v___f_565_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__2___boxed), 7, 6);
lean_closure_set(v___f_565_, 0, v_x_555_);
lean_closure_set(v___f_565_, 1, v_tail_562_);
lean_closure_set(v___f_565_, 2, v___f_564_);
lean_closure_set(v___f_565_, 3, v_tail_560_);
lean_closure_set(v___f_565_, 4, v_x_556_);
lean_closure_set(v___f_565_, 5, v___f_563_);
v___x_566_ = lean_nat_dec_le(v_head_559_, v_head_561_);
lean_dec(v_head_561_);
lean_dec(v_head_559_);
v___x_567_ = lean_unsigned_to_nat(1u);
v___x_568_ = lean_box(v___x_566_);
v___x_569_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_569_, 0, v___x_568_);
lean_ctor_set(v___x_569_, 1, v___x_567_);
v___x_570_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_569_, v___f_565_);
return v___x_570_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__2(lean_object* v_x_571_, lean_object* v_tail_572_, lean_object* v___f_573_, lean_object* v_tail_574_, lean_object* v_x_575_, lean_object* v___f_576_, uint8_t v_smaller_577_){
_start:
{
if (v_smaller_577_ == 0)
{
lean_object* v___x_578_; lean_object* v___x_579_; 
lean_dec_ref(v___f_576_);
lean_dec(v_x_575_);
lean_dec(v_tail_574_);
v___x_578_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7(v_x_571_, v_tail_572_);
v___x_579_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_578_, v___f_573_);
return v___x_579_;
}
else
{
lean_object* v___x_580_; lean_object* v___x_581_; 
lean_dec_ref(v___f_573_);
lean_dec(v_tail_572_);
lean_dec(v_x_571_);
v___x_580_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7(v_tail_574_, v_x_575_);
v___x_581_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_580_, v___f_576_);
return v___x_581_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__0(lean_object* v_ls_582_, lean_object* v_rs_583_){
_start:
{
lean_object* v___x_584_; 
v___x_584_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7(v_ls_582_, v_rs_583_);
return v___x_584_;
}
}
static lean_object* _init_l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0(void){
_start:
{
lean_object* v___x_585_; lean_object* v___x_586_; 
v___x_585_ = lean_box(0);
v___x_586_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_585_);
return v___x_586_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10(lean_object* v_x_587_){
_start:
{
switch(lean_obj_tag(v_x_587_))
{
case 0:
{
lean_object* v___x_588_; 
v___x_588_ = lean_obj_once(&l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0, &l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0_once, _init_l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0);
return v___x_588_;
}
case 1:
{
lean_object* v_run_589_; lean_object* v___x_590_; 
v_run_589_ = lean_ctor_get(v_x_587_, 0);
lean_inc(v_run_589_);
lean_dec_ref_known(v_x_587_, 1);
v___x_590_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_run_589_);
return v___x_590_;
}
default: 
{
lean_object* v_left_591_; lean_object* v_right_592_; lean_object* v___f_593_; lean_object* v___x_594_; lean_object* v___x_595_; 
v_left_591_ = lean_ctor_get(v_x_587_, 0);
lean_inc(v_left_591_);
v_right_592_ = lean_ctor_get(v_x_587_, 1);
lean_inc(v_right_592_);
lean_dec_ref_known(v_x_587_, 2);
v___f_593_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___lam__1), 2, 1);
lean_closure_set(v___f_593_, 0, v_right_592_);
v___x_594_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10(v_left_591_);
v___x_595_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_594_, v___f_593_);
return v___x_595_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___lam__1(lean_object* v_right_596_, lean_object* v_ls_597_){
_start:
{
lean_object* v___f_598_; lean_object* v___x_599_; lean_object* v___x_600_; 
v___f_598_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__0), 2, 1);
lean_closure_set(v___f_598_, 0, v_ls_597_);
v___x_599_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10(v_right_596_);
v___x_600_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_599_, v___f_598_);
return v___x_600_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__3___lam__0(lean_object* v_runs_601_){
_start:
{
lean_object* v___x_602_; lean_object* v___x_603_; 
v___x_602_ = lp_leansort_LeanSort_RunAdaptive_lengthPlan___redArg(v_runs_601_);
v___x_603_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10(v___x_602_);
return v___x_603_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__0(uint8_t v_ascending_604_, lean_object* v_head_605_, lean_object* v_____x_606_){
_start:
{
if (v_ascending_604_ == 0)
{
lean_object* v_fst_607_; lean_object* v_snd_608_; lean_object* v___x_610_; uint8_t v_isShared_611_; uint8_t v_isSharedCheck_619_; 
v_fst_607_ = lean_ctor_get(v_____x_606_, 0);
v_snd_608_ = lean_ctor_get(v_____x_606_, 1);
v_isSharedCheck_619_ = !lean_is_exclusive(v_____x_606_);
if (v_isSharedCheck_619_ == 0)
{
v___x_610_ = v_____x_606_;
v_isShared_611_ = v_isSharedCheck_619_;
goto v_resetjp_609_;
}
else
{
lean_inc(v_snd_608_);
lean_inc(v_fst_607_);
lean_dec(v_____x_606_);
v___x_610_ = lean_box(0);
v_isShared_611_ = v_isSharedCheck_619_;
goto v_resetjp_609_;
}
v_resetjp_609_:
{
lean_object* v___x_612_; lean_object* v___x_613_; lean_object* v___x_614_; lean_object* v___x_616_; 
v___x_612_ = lean_box(0);
v___x_613_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_613_, 0, v_head_605_);
lean_ctor_set(v___x_613_, 1, v_fst_607_);
v___x_614_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_614_, 0, v___x_613_);
lean_ctor_set(v___x_614_, 1, v_snd_608_);
if (v_isShared_611_ == 0)
{
lean_ctor_set(v___x_610_, 1, v___x_614_);
lean_ctor_set(v___x_610_, 0, v___x_612_);
v___x_616_ = v___x_610_;
goto v_reusejp_615_;
}
else
{
lean_object* v_reuseFailAlloc_618_; 
v_reuseFailAlloc_618_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_618_, 0, v___x_612_);
lean_ctor_set(v_reuseFailAlloc_618_, 1, v___x_614_);
v___x_616_ = v_reuseFailAlloc_618_;
goto v_reusejp_615_;
}
v_reusejp_615_:
{
lean_object* v___x_617_; 
v___x_617_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_616_);
return v___x_617_;
}
}
}
else
{
lean_object* v_fst_620_; lean_object* v_snd_621_; lean_object* v___x_623_; uint8_t v_isShared_624_; uint8_t v_isSharedCheck_630_; 
v_fst_620_ = lean_ctor_get(v_____x_606_, 0);
v_snd_621_ = lean_ctor_get(v_____x_606_, 1);
v_isSharedCheck_630_ = !lean_is_exclusive(v_____x_606_);
if (v_isSharedCheck_630_ == 0)
{
v___x_623_ = v_____x_606_;
v_isShared_624_ = v_isSharedCheck_630_;
goto v_resetjp_622_;
}
else
{
lean_inc(v_snd_621_);
lean_inc(v_fst_620_);
lean_dec(v_____x_606_);
v___x_623_ = lean_box(0);
v_isShared_624_ = v_isSharedCheck_630_;
goto v_resetjp_622_;
}
v_resetjp_622_:
{
lean_object* v___x_625_; lean_object* v___x_627_; 
v___x_625_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_625_, 0, v_head_605_);
lean_ctor_set(v___x_625_, 1, v_fst_620_);
if (v_isShared_624_ == 0)
{
lean_ctor_set(v___x_623_, 0, v___x_625_);
v___x_627_ = v___x_623_;
goto v_reusejp_626_;
}
else
{
lean_object* v_reuseFailAlloc_629_; 
v_reuseFailAlloc_629_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_629_, 0, v___x_625_);
lean_ctor_set(v_reuseFailAlloc_629_, 1, v_snd_621_);
v___x_627_ = v_reuseFailAlloc_629_;
goto v_reusejp_626_;
}
v_reusejp_626_:
{
lean_object* v___x_628_; 
v___x_628_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_627_);
return v___x_628_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__0___boxed(lean_object* v_ascending_631_, lean_object* v_head_632_, lean_object* v_____x_633_){
_start:
{
uint8_t v_ascending_boxed_634_; lean_object* v_res_635_; 
v_ascending_boxed_634_ = lean_unbox(v_ascending_631_);
v_res_635_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__0(v_ascending_boxed_634_, v_head_632_, v_____x_633_);
return v_res_635_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__1___boxed(lean_object* v_head_636_, lean_object* v_tail_637_, lean_object* v_ascending_638_){
_start:
{
uint8_t v_ascending_boxed_639_; lean_object* v_res_640_; 
v_ascending_boxed_639_ = lean_unbox(v_ascending_638_);
v_res_640_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__1(v_head_636_, v_tail_637_, v_ascending_boxed_639_);
return v_res_640_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18(lean_object* v_x_641_, lean_object* v_x_642_){
_start:
{
if (lean_obj_tag(v_x_642_) == 0)
{
lean_object* v___x_643_; lean_object* v___x_644_; lean_object* v___x_645_; 
v___x_643_ = lean_box(0);
v___x_644_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_644_, 0, v_x_642_);
lean_ctor_set(v___x_644_, 1, v___x_643_);
v___x_645_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_644_);
return v___x_645_;
}
else
{
lean_object* v_head_646_; lean_object* v_tail_647_; lean_object* v___x_649_; uint8_t v_isShared_650_; uint8_t v_isSharedCheck_659_; 
v_head_646_ = lean_ctor_get(v_x_642_, 0);
v_tail_647_ = lean_ctor_get(v_x_642_, 1);
v_isSharedCheck_659_ = !lean_is_exclusive(v_x_642_);
if (v_isSharedCheck_659_ == 0)
{
v___x_649_ = v_x_642_;
v_isShared_650_ = v_isSharedCheck_659_;
goto v_resetjp_648_;
}
else
{
lean_inc(v_tail_647_);
lean_inc(v_head_646_);
lean_dec(v_x_642_);
v___x_649_ = lean_box(0);
v_isShared_650_ = v_isSharedCheck_659_;
goto v_resetjp_648_;
}
v_resetjp_648_:
{
lean_object* v___f_651_; uint8_t v___x_652_; lean_object* v___x_653_; lean_object* v___x_654_; lean_object* v___x_656_; 
lean_inc(v_head_646_);
v___f_651_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__1___boxed), 3, 2);
lean_closure_set(v___f_651_, 0, v_head_646_);
lean_closure_set(v___f_651_, 1, v_tail_647_);
v___x_652_ = lean_nat_dec_le(v_x_641_, v_head_646_);
lean_dec(v_head_646_);
v___x_653_ = lean_unsigned_to_nat(1u);
v___x_654_ = lean_box(v___x_652_);
if (v_isShared_650_ == 0)
{
lean_ctor_set_tag(v___x_649_, 0);
lean_ctor_set(v___x_649_, 1, v___x_653_);
lean_ctor_set(v___x_649_, 0, v___x_654_);
v___x_656_ = v___x_649_;
goto v_reusejp_655_;
}
else
{
lean_object* v_reuseFailAlloc_658_; 
v_reuseFailAlloc_658_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_658_, 0, v___x_654_);
lean_ctor_set(v_reuseFailAlloc_658_, 1, v___x_653_);
v___x_656_ = v_reuseFailAlloc_658_;
goto v_reusejp_655_;
}
v_reusejp_655_:
{
lean_object* v___x_657_; 
v___x_657_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_656_, v___f_651_);
return v___x_657_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__1(lean_object* v_head_660_, lean_object* v_tail_661_, uint8_t v_ascending_662_){
_start:
{
lean_object* v___x_663_; lean_object* v___f_664_; lean_object* v___x_665_; lean_object* v___x_666_; 
v___x_663_ = lean_box(v_ascending_662_);
lean_inc(v_head_660_);
v___f_664_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__0___boxed), 3, 2);
lean_closure_set(v___f_664_, 0, v___x_663_);
lean_closure_set(v___f_664_, 1, v_head_660_);
v___x_665_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18(v_head_660_, v_tail_661_);
lean_dec(v_head_660_);
v___x_666_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_665_, v___f_664_);
return v___x_666_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___boxed(lean_object* v_x_667_, lean_object* v_x_668_){
_start:
{
lean_object* v_res_669_; 
v_res_669_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18(v_x_667_, v_x_668_);
lean_dec(v_x_667_);
return v_res_669_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___lam__0(lean_object* v_head_670_, lean_object* v_____x_671_){
_start:
{
lean_object* v_fst_672_; lean_object* v_snd_673_; lean_object* v___x_675_; uint8_t v_isShared_676_; uint8_t v_isSharedCheck_682_; 
v_fst_672_ = lean_ctor_get(v_____x_671_, 0);
v_snd_673_ = lean_ctor_get(v_____x_671_, 1);
v_isSharedCheck_682_ = !lean_is_exclusive(v_____x_671_);
if (v_isSharedCheck_682_ == 0)
{
v___x_675_ = v_____x_671_;
v_isShared_676_ = v_isSharedCheck_682_;
goto v_resetjp_674_;
}
else
{
lean_inc(v_snd_673_);
lean_inc(v_fst_672_);
lean_dec(v_____x_671_);
v___x_675_ = lean_box(0);
v_isShared_676_ = v_isSharedCheck_682_;
goto v_resetjp_674_;
}
v_resetjp_674_:
{
lean_object* v___x_678_; 
if (v_isShared_676_ == 0)
{
lean_ctor_set_tag(v___x_675_, 1);
lean_ctor_set(v___x_675_, 1, v_fst_672_);
lean_ctor_set(v___x_675_, 0, v_head_670_);
v___x_678_ = v___x_675_;
goto v_reusejp_677_;
}
else
{
lean_object* v_reuseFailAlloc_681_; 
v_reuseFailAlloc_681_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_681_, 0, v_head_670_);
lean_ctor_set(v_reuseFailAlloc_681_, 1, v_fst_672_);
v___x_678_ = v_reuseFailAlloc_681_;
goto v_reusejp_677_;
}
v_reusejp_677_:
{
lean_object* v___x_679_; lean_object* v___x_680_; 
v___x_679_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_679_, 0, v___x_678_);
lean_ctor_set(v___x_679_, 1, v_snd_673_);
v___x_680_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_679_);
return v___x_680_;
}
}
}
}
static lean_object* _init_l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0(void){
_start:
{
lean_object* v___x_683_; lean_object* v___x_684_; 
v___x_683_ = lean_box(0);
v___x_684_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_683_);
return v___x_684_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11(lean_object* v_x_685_){
_start:
{
if (lean_obj_tag(v_x_685_) == 0)
{
lean_object* v___x_686_; 
v___x_686_ = lean_obj_once(&l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0, &l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0_once, _init_l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0);
return v___x_686_;
}
else
{
lean_object* v_head_687_; lean_object* v_tail_688_; lean_object* v___f_689_; lean_object* v___x_690_; lean_object* v___x_691_; 
v_head_687_ = lean_ctor_get(v_x_685_, 0);
lean_inc_n(v_head_687_, 2);
v_tail_688_ = lean_ctor_get(v_x_685_, 1);
lean_inc(v_tail_688_);
lean_dec_ref_known(v_x_685_, 2);
v___f_689_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___lam__0), 2, 1);
lean_closure_set(v___f_689_, 0, v_head_687_);
v___x_690_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18(v_head_687_, v_tail_688_);
lean_dec(v_head_687_);
v___x_691_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_690_, v___f_689_);
return v___x_691_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__3(lean_object* v_xs_693_){
_start:
{
lean_object* v___f_694_; lean_object* v___x_695_; lean_object* v___x_696_; 
v___f_694_ = ((lean_object*)(l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__3___closed__0));
v___x_695_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11(v_xs_693_);
v___x_696_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_695_, v___f_694_);
return v___x_696_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2___lam__0(lean_object* v_runs_697_){
_start:
{
lean_object* v___x_698_; lean_object* v___x_699_; 
v___x_698_ = lp_leansort_LeanSort_RunAdaptive_countPlan___redArg(v_runs_697_);
v___x_699_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10(v___x_698_);
return v___x_699_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2(lean_object* v_xs_701_){
_start:
{
lean_object* v___f_702_; lean_object* v___x_703_; lean_object* v___x_704_; 
v___f_702_ = ((lean_object*)(l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2___closed__0));
v___x_703_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11(v_xs_701_);
v___x_704_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_703_, v___f_702_);
return v___x_704_;
}
}
static lean_object* _init_l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0(void){
_start:
{
uint8_t v___x_705_; lean_object* v___x_706_; lean_object* v___x_707_; 
v___x_705_ = 1;
v___x_706_ = lean_box(v___x_705_);
v___x_707_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_706_);
return v___x_707_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___lam__0___boxed(lean_object* v_tail_708_, lean_object* v_smaller_709_){
_start:
{
uint8_t v_smaller_boxed_710_; lean_object* v_res_711_; 
v_smaller_boxed_710_ = lean_unbox(v_smaller_709_);
v_res_711_ = l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___lam__0(v_tail_708_, v_smaller_boxed_710_);
return v_res_711_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8(lean_object* v_x_712_){
_start:
{
if (lean_obj_tag(v_x_712_) == 0)
{
lean_object* v___x_713_; 
v___x_713_ = lean_obj_once(&l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0, &l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0_once, _init_l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0);
return v___x_713_;
}
else
{
lean_object* v_tail_714_; 
v_tail_714_ = lean_ctor_get(v_x_712_, 1);
lean_inc(v_tail_714_);
if (lean_obj_tag(v_tail_714_) == 0)
{
lean_object* v___x_715_; 
lean_dec_ref_known(v_x_712_, 2);
v___x_715_ = lean_obj_once(&l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0, &l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0_once, _init_l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0);
return v___x_715_;
}
else
{
lean_object* v_head_716_; lean_object* v___x_718_; uint8_t v_isShared_719_; uint8_t v_isSharedCheck_729_; 
v_head_716_ = lean_ctor_get(v_x_712_, 0);
v_isSharedCheck_729_ = !lean_is_exclusive(v_x_712_);
if (v_isSharedCheck_729_ == 0)
{
lean_object* v_unused_730_; 
v_unused_730_ = lean_ctor_get(v_x_712_, 1);
lean_dec(v_unused_730_);
v___x_718_ = v_x_712_;
v_isShared_719_ = v_isSharedCheck_729_;
goto v_resetjp_717_;
}
else
{
lean_inc(v_head_716_);
lean_dec(v_x_712_);
v___x_718_ = lean_box(0);
v_isShared_719_ = v_isSharedCheck_729_;
goto v_resetjp_717_;
}
v_resetjp_717_:
{
lean_object* v_head_720_; lean_object* v___f_721_; uint8_t v___x_722_; lean_object* v___x_723_; lean_object* v___x_724_; lean_object* v___x_726_; 
v_head_720_ = lean_ctor_get(v_tail_714_, 0);
lean_inc(v_head_720_);
v___f_721_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___lam__0___boxed), 2, 1);
lean_closure_set(v___f_721_, 0, v_tail_714_);
v___x_722_ = lean_nat_dec_le(v_head_716_, v_head_720_);
lean_dec(v_head_720_);
lean_dec(v_head_716_);
v___x_723_ = lean_unsigned_to_nat(1u);
v___x_724_ = lean_box(v___x_722_);
if (v_isShared_719_ == 0)
{
lean_ctor_set_tag(v___x_718_, 0);
lean_ctor_set(v___x_718_, 1, v___x_723_);
lean_ctor_set(v___x_718_, 0, v___x_724_);
v___x_726_ = v___x_718_;
goto v_reusejp_725_;
}
else
{
lean_object* v_reuseFailAlloc_728_; 
v_reuseFailAlloc_728_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_728_, 0, v___x_724_);
lean_ctor_set(v_reuseFailAlloc_728_, 1, v___x_723_);
v___x_726_ = v_reuseFailAlloc_728_;
goto v_reusejp_725_;
}
v_reusejp_725_:
{
lean_object* v___x_727_; 
v___x_727_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_726_, v___f_721_);
return v___x_727_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___lam__0(lean_object* v_tail_731_, uint8_t v_smaller_732_){
_start:
{
if (v_smaller_732_ == 0)
{
lean_object* v___x_733_; lean_object* v___x_734_; 
lean_dec(v_tail_731_);
v___x_733_ = lean_box(v_smaller_732_);
v___x_734_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_733_);
return v___x_734_;
}
else
{
lean_object* v___x_735_; 
v___x_735_ = l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8(v_tail_731_);
return v___x_735_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18___lam__1___boxed(lean_object* v_x_736_, lean_object* v_tail_737_, lean_object* v___f_738_, lean_object* v_x_739_, lean_object* v_smaller_740_){
_start:
{
uint8_t v_smaller_boxed_741_; lean_object* v_res_742_; 
v_smaller_boxed_741_ = lean_unbox(v_smaller_740_);
v_res_742_ = l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18___lam__1(v_x_736_, v_tail_737_, v___f_738_, v_x_739_, v_smaller_boxed_741_);
return v_res_742_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18(lean_object* v_x_743_, lean_object* v_x_744_){
_start:
{
if (lean_obj_tag(v_x_744_) == 0)
{
lean_object* v___x_745_; lean_object* v___x_746_; 
v___x_745_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_745_, 0, v_x_743_);
lean_ctor_set(v___x_745_, 1, v_x_744_);
v___x_746_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_745_);
return v___x_746_;
}
else
{
lean_object* v_head_747_; lean_object* v_tail_748_; lean_object* v___f_749_; lean_object* v___f_750_; uint8_t v___x_751_; lean_object* v___x_752_; lean_object* v___x_753_; lean_object* v___x_754_; lean_object* v___x_755_; 
v_head_747_ = lean_ctor_get(v_x_744_, 0);
lean_inc_n(v_head_747_, 2);
v_tail_748_ = lean_ctor_get(v_x_744_, 1);
lean_inc(v_tail_748_);
v___f_749_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0), 2, 1);
lean_closure_set(v___f_749_, 0, v_head_747_);
lean_inc(v_x_743_);
v___f_750_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18___lam__1___boxed), 5, 4);
lean_closure_set(v___f_750_, 0, v_x_743_);
lean_closure_set(v___f_750_, 1, v_tail_748_);
lean_closure_set(v___f_750_, 2, v___f_749_);
lean_closure_set(v___f_750_, 3, v_x_744_);
v___x_751_ = lean_nat_dec_le(v_x_743_, v_head_747_);
lean_dec(v_head_747_);
lean_dec(v_x_743_);
v___x_752_ = lean_unsigned_to_nat(1u);
v___x_753_ = lean_box(v___x_751_);
v___x_754_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_754_, 0, v___x_753_);
lean_ctor_set(v___x_754_, 1, v___x_752_);
v___x_755_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_754_, v___f_750_);
return v___x_755_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18___lam__1(lean_object* v_x_756_, lean_object* v_tail_757_, lean_object* v___f_758_, lean_object* v_x_759_, uint8_t v_smaller_760_){
_start:
{
if (v_smaller_760_ == 0)
{
lean_object* v___x_761_; lean_object* v___x_762_; 
lean_dec(v_x_759_);
v___x_761_ = l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18(v_x_756_, v_tail_757_);
v___x_762_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_761_, v___f_758_);
return v___x_762_;
}
else
{
lean_object* v___x_763_; lean_object* v___x_764_; 
lean_dec_ref(v___f_758_);
lean_dec(v_tail_757_);
v___x_763_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_763_, 0, v_x_756_);
lean_ctor_set(v___x_763_, 1, v_x_759_);
v___x_764_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_763_);
return v___x_764_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11___lam__0(lean_object* v_head_765_, lean_object* v_rest_766_){
_start:
{
lean_object* v___x_767_; 
v___x_767_ = l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11_spec__18(v_head_765_, v_rest_766_);
return v___x_767_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11(lean_object* v_x_768_){
_start:
{
if (lean_obj_tag(v_x_768_) == 0)
{
lean_object* v___x_769_; 
v___x_769_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_768_);
return v___x_769_;
}
else
{
lean_object* v_head_770_; lean_object* v_tail_771_; lean_object* v___f_772_; lean_object* v___x_773_; lean_object* v___x_774_; 
v_head_770_ = lean_ctor_get(v_x_768_, 0);
lean_inc(v_head_770_);
v_tail_771_ = lean_ctor_get(v_x_768_, 1);
lean_inc(v_tail_771_);
lean_dec_ref_known(v_x_768_, 2);
v___f_772_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11___lam__0), 2, 1);
lean_closure_set(v___f_772_, 0, v_head_770_);
v___x_773_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11(v_tail_771_);
v___x_774_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_773_, v___f_772_);
return v___x_774_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__0(lean_object* v_left_775_, lean_object* v_right_776_){
_start:
{
lean_object* v___x_777_; 
v___x_777_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7(v_left_775_, v_right_776_);
return v___x_777_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12___lam__1___boxed(lean_object* v___x_778_, lean_object* v_xs_779_, lean_object* v_threshold_780_, lean_object* v_left_781_){
_start:
{
lean_object* v_res_782_; 
v_res_782_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12___lam__1(v___x_778_, v_xs_779_, v_threshold_780_, v_left_781_);
lean_dec(v_xs_779_);
return v_res_782_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12(lean_object* v_threshold_783_, lean_object* v_xs_784_){
_start:
{
lean_object* v___x_785_; lean_object* v___y_787_; lean_object* v___x_797_; uint8_t v___x_798_; 
v___x_785_ = l_List_lengthTR___redArg(v_xs_784_);
v___x_797_ = lean_unsigned_to_nat(1u);
v___x_798_ = lean_nat_dec_le(v___x_797_, v_threshold_783_);
if (v___x_798_ == 0)
{
v___y_787_ = v___x_797_;
goto v___jp_786_;
}
else
{
lean_inc(v_threshold_783_);
v___y_787_ = v_threshold_783_;
goto v___jp_786_;
}
v___jp_786_:
{
uint8_t v___x_788_; 
v___x_788_ = lean_nat_dec_le(v___x_785_, v___y_787_);
lean_dec(v___y_787_);
if (v___x_788_ == 0)
{
lean_object* v___x_789_; lean_object* v___x_790_; lean_object* v___f_791_; lean_object* v___x_792_; lean_object* v___x_793_; lean_object* v___x_794_; lean_object* v___x_795_; 
v___x_789_ = lean_unsigned_to_nat(1u);
v___x_790_ = lean_nat_shiftr(v___x_785_, v___x_789_);
lean_dec(v___x_785_);
lean_inc(v_threshold_783_);
lean_inc_n(v_xs_784_, 2);
lean_inc(v___x_790_);
v___f_791_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12___lam__1___boxed), 4, 3);
lean_closure_set(v___f_791_, 0, v___x_790_);
lean_closure_set(v___f_791_, 1, v_xs_784_);
lean_closure_set(v___f_791_, 2, v_threshold_783_);
v___x_792_ = ((lean_object*)(l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3___closed__0));
v___x_793_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_xs_784_, v_xs_784_, v___x_790_, v___x_792_);
lean_dec(v_xs_784_);
v___x_794_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12(v_threshold_783_, v___x_793_);
v___x_795_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_794_, v___f_791_);
return v___x_795_;
}
else
{
lean_object* v___x_796_; 
lean_dec(v___x_785_);
lean_dec(v_threshold_783_);
v___x_796_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11(v_xs_784_);
return v___x_796_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12___lam__1(lean_object* v___x_799_, lean_object* v_xs_800_, lean_object* v_threshold_801_, lean_object* v_left_802_){
_start:
{
lean_object* v___f_803_; lean_object* v___x_804_; lean_object* v___x_805_; lean_object* v___x_806_; 
v___f_803_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__0), 2, 1);
lean_closure_set(v___f_803_, 0, v_left_802_);
v___x_804_ = l_List_drop___redArg(v___x_799_, v_xs_800_);
v___x_805_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12(v_threshold_801_, v___x_804_);
v___x_806_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_805_, v___f_803_);
return v___x_806_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__1___boxed(lean_object* v___x_807_, lean_object* v_xs_808_, lean_object* v_left_809_){
_start:
{
lean_object* v_res_810_; 
v_res_810_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__1(v___x_807_, v_xs_808_, v_left_809_);
lean_dec(v_xs_808_);
return v_res_810_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10(lean_object* v_xs_811_){
_start:
{
lean_object* v___x_812_; lean_object* v___x_813_; uint8_t v___x_814_; 
v___x_812_ = l_List_lengthTR___redArg(v_xs_811_);
v___x_813_ = lean_unsigned_to_nat(2u);
v___x_814_ = lean_nat_dec_lt(v___x_812_, v___x_813_);
if (v___x_814_ == 0)
{
lean_object* v___x_815_; lean_object* v___x_816_; lean_object* v___f_817_; lean_object* v___x_818_; lean_object* v___x_819_; lean_object* v___x_820_; lean_object* v___x_821_; 
v___x_815_ = lean_unsigned_to_nat(1u);
v___x_816_ = lean_nat_shiftr(v___x_812_, v___x_815_);
lean_dec(v___x_812_);
lean_inc_n(v_xs_811_, 2);
lean_inc(v___x_816_);
v___f_817_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__1___boxed), 3, 2);
lean_closure_set(v___f_817_, 0, v___x_816_);
lean_closure_set(v___f_817_, 1, v_xs_811_);
v___x_818_ = ((lean_object*)(l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3___closed__0));
v___x_819_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_xs_811_, v_xs_811_, v___x_816_, v___x_818_);
lean_dec(v_xs_811_);
v___x_820_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10(v___x_819_);
v___x_821_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_820_, v___f_817_);
return v___x_821_;
}
else
{
lean_object* v___x_822_; 
lean_dec(v___x_812_);
v___x_822_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_xs_811_);
return v___x_822_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__1(lean_object* v___x_823_, lean_object* v_xs_824_, lean_object* v_left_825_){
_start:
{
lean_object* v___f_826_; lean_object* v___x_827_; lean_object* v___x_828_; lean_object* v___x_829_; 
v___f_826_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10___lam__0), 2, 1);
lean_closure_set(v___f_826_, 0, v_left_825_);
v___x_827_ = l_List_drop___redArg(v___x_823_, v_xs_824_);
v___x_828_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10(v___x_827_);
v___x_829_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_828_, v___f_826_);
return v___x_829_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6(lean_object* v_x_830_, lean_object* v_x_831_){
_start:
{
switch(lean_obj_tag(v_x_830_))
{
case 0:
{
lean_object* v___x_832_; 
v___x_832_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__10(v_x_831_);
return v___x_832_;
}
case 1:
{
lean_object* v___x_833_; 
v___x_833_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__11(v_x_831_);
return v___x_833_;
}
default: 
{
lean_object* v_threshold_834_; lean_object* v___x_835_; 
v_threshold_834_ = lean_ctor_get(v_x_830_, 0);
lean_inc(v_threshold_834_);
lean_dec_ref_known(v_x_830_, 1);
v___x_835_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6_spec__12(v_threshold_834_, v_x_831_);
return v___x_835_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__1___boxed(lean_object* v___x_836_, lean_object* v_x_837_, lean_object* v_right_838_, lean_object* v_ls_839_){
_start:
{
lean_object* v_res_840_; 
v_res_840_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__1(v___x_836_, v_x_837_, v_right_838_, v_ls_839_);
lean_dec(v_x_837_);
return v_res_840_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__2(lean_object* v_fallback_841_, lean_object* v_x_842_, uint8_t v_sorted_843_){
_start:
{
if (v_sorted_843_ == 0)
{
lean_object* v___x_844_; 
v___x_844_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1(v_fallback_841_, v_x_842_);
return v___x_844_;
}
else
{
lean_object* v___x_845_; 
lean_dec_ref(v_fallback_841_);
v___x_845_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_842_);
return v___x_845_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__2___boxed(lean_object* v_fallback_846_, lean_object* v_x_847_, lean_object* v_sorted_848_){
_start:
{
uint8_t v_sorted_boxed_849_; lean_object* v_res_850_; 
v_sorted_boxed_849_ = lean_unbox(v_sorted_848_);
v_res_850_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__2(v_fallback_846_, v_x_847_, v_sorted_boxed_849_);
return v_res_850_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1(lean_object* v_x_851_, lean_object* v_x_852_){
_start:
{
switch(lean_obj_tag(v_x_851_))
{
case 0:
{
lean_object* v_component_853_; lean_object* v___x_854_; 
v_component_853_ = lean_ctor_get(v_x_851_, 0);
lean_inc(v_component_853_);
lean_dec_ref_known(v_x_851_, 1);
v___x_854_ = l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__6(v_component_853_, v_x_852_);
return v___x_854_;
}
case 1:
{
lean_object* v_cut_855_; lean_object* v_left_856_; lean_object* v_right_857_; lean_object* v___x_858_; lean_object* v___x_859_; lean_object* v___f_860_; lean_object* v___x_861_; lean_object* v___x_862_; lean_object* v___x_863_; lean_object* v___x_864_; 
v_cut_855_ = lean_ctor_get(v_x_851_, 0);
lean_inc_ref(v_cut_855_);
v_left_856_ = lean_ctor_get(v_x_851_, 1);
lean_inc_ref(v_left_856_);
v_right_857_ = lean_ctor_get(v_x_851_, 2);
lean_inc_ref(v_right_857_);
lean_dec_ref_known(v_x_851_, 3);
v___x_858_ = l_List_lengthTR___redArg(v_x_852_);
v___x_859_ = lp_leansort_LeanSort_CostedPlan_Cut_position(v_cut_855_, v___x_858_);
lean_dec(v___x_858_);
lean_dec_ref(v_cut_855_);
lean_inc_n(v_x_852_, 2);
lean_inc(v___x_859_);
v___f_860_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__1___boxed), 4, 3);
lean_closure_set(v___f_860_, 0, v___x_859_);
lean_closure_set(v___f_860_, 1, v_x_852_);
lean_closure_set(v___f_860_, 2, v_right_857_);
v___x_861_ = ((lean_object*)(l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3___closed__0));
v___x_862_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_x_852_, v_x_852_, v___x_859_, v___x_861_);
lean_dec(v_x_852_);
v___x_863_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1(v_left_856_, v___x_862_);
v___x_864_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_863_, v___f_860_);
return v___x_864_;
}
default: 
{
lean_object* v_fallback_865_; lean_object* v___f_866_; lean_object* v___x_867_; lean_object* v___x_868_; 
v_fallback_865_ = lean_ctor_get(v_x_851_, 0);
lean_inc_ref(v_fallback_865_);
lean_dec_ref_known(v_x_851_, 1);
lean_inc(v_x_852_);
v___f_866_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__2___boxed), 3, 2);
lean_closure_set(v___f_866_, 0, v_fallback_865_);
lean_closure_set(v___f_866_, 1, v_x_852_);
v___x_867_ = l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8(v_x_852_);
v___x_868_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_867_, v___f_866_);
return v___x_868_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__1(lean_object* v___x_869_, lean_object* v_x_870_, lean_object* v_right_871_, lean_object* v_ls_872_){
_start:
{
lean_object* v___f_873_; lean_object* v___x_874_; lean_object* v___x_875_; lean_object* v___x_876_; 
v___f_873_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1___lam__0), 2, 1);
lean_closure_set(v___f_873_, 0, v_ls_872_);
v___x_874_ = l_List_drop___redArg(v___x_869_, v_x_870_);
v___x_875_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1(v_right_871_, v___x_874_);
v___x_876_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_875_, v___f_873_);
return v___x_876_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0(lean_object* v_x_877_, lean_object* v_x_878_){
_start:
{
switch(lean_obj_tag(v_x_877_))
{
case 0:
{
lean_object* v_schema_879_; lean_object* v___x_880_; 
v_schema_879_ = lean_ctor_get(v_x_877_, 0);
lean_inc_ref(v_schema_879_);
lean_dec_ref_known(v_x_877_, 1);
v___x_880_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1(v_schema_879_, v_x_878_);
return v___x_880_;
}
case 1:
{
lean_object* v___x_881_; 
v___x_881_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2(v_x_878_);
return v___x_881_;
}
default: 
{
lean_object* v___x_882_; 
v___x_882_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__3(v_x_878_);
return v___x_882_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__2(uint8_t v_selected_883_, uint8_t v_phase_884_, lean_object* v_x_885_, lean_object* v_y_886_){
_start:
{
uint8_t v___x_887_; uint8_t v___x_888_; 
v___x_887_ = lean_nat_dec_le(v_x_885_, v_y_886_);
v___x_888_ = lp_leansort_LeanSort_Comparison_instDecidableEqPhase(v_phase_884_, v_selected_883_);
if (v___x_888_ == 0)
{
lean_object* v___x_889_; lean_object* v___x_890_; lean_object* v___x_891_; 
v___x_889_ = lean_unsigned_to_nat(0u);
v___x_890_ = lean_box(v___x_887_);
v___x_891_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_891_, 0, v___x_890_);
lean_ctor_set(v___x_891_, 1, v___x_889_);
return v___x_891_;
}
else
{
lean_object* v___x_892_; lean_object* v___x_893_; lean_object* v___x_894_; 
v___x_892_ = lean_unsigned_to_nat(1u);
v___x_893_ = lean_box(v___x_887_);
v___x_894_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_894_, 0, v___x_893_);
lean_ctor_set(v___x_894_, 1, v___x_892_);
return v___x_894_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__2___boxed(lean_object* v_selected_895_, lean_object* v_phase_896_, lean_object* v_x_897_, lean_object* v_y_898_){
_start:
{
uint8_t v_selected_boxed_899_; uint8_t v_phase_boxed_900_; lean_object* v_res_901_; 
v_selected_boxed_899_ = lean_unbox(v_selected_895_);
v_phase_boxed_900_ = lean_unbox(v_phase_896_);
v_res_901_ = l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__2(v_selected_boxed_899_, v_phase_boxed_900_, v_x_897_, v_y_898_);
lean_dec(v_y_898_);
lean_dec(v_x_897_);
return v_res_901_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___lam__1___boxed(lean_object* v_head_902_, lean_object* v_phase_903_, lean_object* v_tail_904_, lean_object* v_ascending_905_){
_start:
{
uint8_t v_phase_boxed_906_; uint8_t v_ascending_boxed_907_; lean_object* v_res_908_; 
v_phase_boxed_906_ = lean_unbox(v_phase_903_);
v_ascending_boxed_907_ = lean_unbox(v_ascending_905_);
v_res_908_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___lam__1(v_head_902_, v_phase_boxed_906_, v_tail_904_, v_ascending_boxed_907_);
return v_res_908_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30(uint8_t v_phase_909_, lean_object* v_x_910_, lean_object* v_x_911_){
_start:
{
if (lean_obj_tag(v_x_911_) == 0)
{
lean_object* v___x_912_; lean_object* v___x_913_; lean_object* v___x_914_; 
v___x_912_ = lean_box(0);
v___x_913_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_913_, 0, v_x_911_);
lean_ctor_set(v___x_913_, 1, v___x_912_);
v___x_914_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_913_);
return v___x_914_;
}
else
{
lean_object* v_head_915_; lean_object* v_tail_916_; lean_object* v___x_917_; lean_object* v___f_918_; uint8_t v___x_919_; lean_object* v___x_920_; lean_object* v___x_921_; 
v_head_915_ = lean_ctor_get(v_x_911_, 0);
lean_inc_n(v_head_915_, 2);
v_tail_916_ = lean_ctor_get(v_x_911_, 1);
lean_inc(v_tail_916_);
lean_dec_ref_known(v_x_911_, 2);
v___x_917_ = lean_box(v_phase_909_);
v___f_918_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___lam__1___boxed), 4, 3);
lean_closure_set(v___f_918_, 0, v_head_915_);
lean_closure_set(v___f_918_, 1, v___x_917_);
lean_closure_set(v___f_918_, 2, v_tail_916_);
v___x_919_ = 0;
v___x_920_ = l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__2(v_phase_909_, v___x_919_, v_x_910_, v_head_915_);
lean_dec(v_head_915_);
v___x_921_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_920_, v___f_918_);
return v___x_921_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___lam__1(lean_object* v_head_922_, uint8_t v_phase_923_, lean_object* v_tail_924_, uint8_t v_ascending_925_){
_start:
{
lean_object* v___x_926_; lean_object* v___f_927_; lean_object* v___x_928_; lean_object* v___x_929_; 
v___x_926_ = lean_box(v_ascending_925_);
lean_inc(v_head_922_);
v___f_927_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11_spec__18___lam__0___boxed), 3, 2);
lean_closure_set(v___f_927_, 0, v___x_926_);
lean_closure_set(v___f_927_, 1, v_head_922_);
v___x_928_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30(v_phase_923_, v_head_922_, v_tail_924_);
lean_dec(v_head_922_);
v___x_929_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_928_, v___f_927_);
return v___x_929_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30___boxed(lean_object* v_phase_930_, lean_object* v_x_931_, lean_object* v_x_932_){
_start:
{
uint8_t v_phase_boxed_933_; lean_object* v_res_934_; 
v_phase_boxed_933_ = lean_unbox(v_phase_930_);
v_res_934_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30(v_phase_boxed_933_, v_x_931_, v_x_932_);
lean_dec(v_x_931_);
return v_res_934_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20(uint8_t v_phase_935_, lean_object* v_x_936_){
_start:
{
if (lean_obj_tag(v_x_936_) == 0)
{
lean_object* v___x_937_; 
v___x_937_ = lean_obj_once(&l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0, &l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0_once, _init_l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___closed__0);
return v___x_937_;
}
else
{
lean_object* v_head_938_; lean_object* v_tail_939_; lean_object* v___f_940_; lean_object* v___x_941_; lean_object* v___x_942_; 
v_head_938_ = lean_ctor_get(v_x_936_, 0);
lean_inc_n(v_head_938_, 2);
v_tail_939_ = lean_ctor_get(v_x_936_, 1);
lean_inc(v_tail_939_);
lean_dec_ref_known(v_x_936_, 2);
v___f_940_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__11___lam__0), 2, 1);
lean_closure_set(v___f_940_, 0, v_head_938_);
v___x_941_ = l_LeanSort_Direct_Engine_scanTail___at___00LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20_spec__30(v_phase_935_, v_head_938_, v_tail_939_);
lean_dec(v_head_938_);
v___x_942_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_941_, v___f_940_);
return v___x_942_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20___boxed(lean_object* v_phase_943_, lean_object* v_x_944_){
_start:
{
uint8_t v_phase_boxed_945_; lean_object* v_res_946_; 
v_phase_boxed_945_ = lean_unbox(v_phase_943_);
v_res_946_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20(v_phase_boxed_945_, v_x_944_);
return v_res_946_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___lam__2___boxed(lean_object* v_phase_947_, lean_object* v_x_948_, lean_object* v_tail_949_, lean_object* v___f_950_, lean_object* v_tail_951_, lean_object* v_x_952_, lean_object* v___f_953_, lean_object* v_smaller_954_){
_start:
{
uint8_t v_phase_boxed_955_; uint8_t v_smaller_boxed_956_; lean_object* v_res_957_; 
v_phase_boxed_955_ = lean_unbox(v_phase_947_);
v_smaller_boxed_956_ = lean_unbox(v_smaller_954_);
v_res_957_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___lam__2(v_phase_boxed_955_, v_x_948_, v_tail_949_, v___f_950_, v_tail_951_, v_x_952_, v___f_953_, v_smaller_boxed_956_);
return v_res_957_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16(uint8_t v_phase_958_, lean_object* v_x_959_, lean_object* v_x_960_){
_start:
{
if (lean_obj_tag(v_x_959_) == 0)
{
lean_object* v___x_961_; 
v___x_961_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_960_);
return v___x_961_;
}
else
{
if (lean_obj_tag(v_x_960_) == 0)
{
lean_object* v___x_962_; 
v___x_962_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_959_);
return v___x_962_;
}
else
{
lean_object* v_head_963_; lean_object* v_tail_964_; lean_object* v_head_965_; lean_object* v_tail_966_; lean_object* v___f_967_; lean_object* v___f_968_; lean_object* v___x_969_; lean_object* v___f_970_; uint8_t v___x_971_; lean_object* v___x_972_; lean_object* v___x_973_; 
v_head_963_ = lean_ctor_get(v_x_959_, 0);
lean_inc_n(v_head_963_, 2);
v_tail_964_ = lean_ctor_get(v_x_959_, 1);
lean_inc(v_tail_964_);
v_head_965_ = lean_ctor_get(v_x_960_, 0);
lean_inc_n(v_head_965_, 2);
v_tail_966_ = lean_ctor_get(v_x_960_, 1);
lean_inc(v_tail_966_);
v___f_967_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0), 2, 1);
lean_closure_set(v___f_967_, 0, v_head_963_);
v___f_968_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0), 2, 1);
lean_closure_set(v___f_968_, 0, v_head_965_);
v___x_969_ = lean_box(v_phase_958_);
v___f_970_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___lam__2___boxed), 8, 7);
lean_closure_set(v___f_970_, 0, v___x_969_);
lean_closure_set(v___f_970_, 1, v_x_959_);
lean_closure_set(v___f_970_, 2, v_tail_966_);
lean_closure_set(v___f_970_, 3, v___f_968_);
lean_closure_set(v___f_970_, 4, v_tail_964_);
lean_closure_set(v___f_970_, 5, v_x_960_);
lean_closure_set(v___f_970_, 6, v___f_967_);
v___x_971_ = 1;
v___x_972_ = l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__2(v_phase_958_, v___x_971_, v_head_963_, v_head_965_);
lean_dec(v_head_965_);
lean_dec(v_head_963_);
v___x_973_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_972_, v___f_970_);
return v___x_973_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___lam__2(uint8_t v_phase_974_, lean_object* v_x_975_, lean_object* v_tail_976_, lean_object* v___f_977_, lean_object* v_tail_978_, lean_object* v_x_979_, lean_object* v___f_980_, uint8_t v_smaller_981_){
_start:
{
if (v_smaller_981_ == 0)
{
lean_object* v___x_982_; lean_object* v___x_983_; 
lean_dec_ref(v___f_980_);
lean_dec(v_x_979_);
lean_dec(v_tail_978_);
v___x_982_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16(v_phase_974_, v_x_975_, v_tail_976_);
v___x_983_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_982_, v___f_977_);
return v___x_983_;
}
else
{
lean_object* v___x_984_; lean_object* v___x_985_; 
lean_dec_ref(v___f_977_);
lean_dec(v_tail_976_);
lean_dec(v_x_975_);
v___x_984_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16(v_phase_974_, v_tail_978_, v_x_979_);
v___x_985_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_984_, v___f_980_);
return v___x_985_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16___boxed(lean_object* v_phase_986_, lean_object* v_x_987_, lean_object* v_x_988_){
_start:
{
uint8_t v_phase_boxed_989_; lean_object* v_res_990_; 
v_phase_boxed_989_ = lean_unbox(v_phase_986_);
v_res_990_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16(v_phase_boxed_989_, v_x_987_, v_x_988_);
return v_res_990_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__0(uint8_t v_phase_991_, lean_object* v_ls_992_, lean_object* v_rs_993_){
_start:
{
lean_object* v___x_994_; 
v___x_994_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16(v_phase_991_, v_ls_992_, v_rs_993_);
return v___x_994_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__0___boxed(lean_object* v_phase_995_, lean_object* v_ls_996_, lean_object* v_rs_997_){
_start:
{
uint8_t v_phase_boxed_998_; lean_object* v_res_999_; 
v_phase_boxed_998_ = lean_unbox(v_phase_995_);
v_res_999_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__0(v_phase_boxed_998_, v_ls_996_, v_rs_997_);
return v_res_999_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___lam__1___boxed(lean_object* v_phase_1000_, lean_object* v_right_1001_, lean_object* v_ls_1002_){
_start:
{
uint8_t v_phase_boxed_1003_; lean_object* v_res_1004_; 
v_phase_boxed_1003_ = lean_unbox(v_phase_1000_);
v_res_1004_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___lam__1(v_phase_boxed_1003_, v_right_1001_, v_ls_1002_);
return v_res_1004_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19(uint8_t v_phase_1005_, lean_object* v_x_1006_){
_start:
{
switch(lean_obj_tag(v_x_1006_))
{
case 0:
{
lean_object* v___x_1007_; 
v___x_1007_ = lean_obj_once(&l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0, &l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0_once, _init_l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__2_spec__10___closed__0);
return v___x_1007_;
}
case 1:
{
lean_object* v_run_1008_; lean_object* v___x_1009_; 
v_run_1008_ = lean_ctor_get(v_x_1006_, 0);
lean_inc(v_run_1008_);
lean_dec_ref_known(v_x_1006_, 1);
v___x_1009_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_run_1008_);
return v___x_1009_;
}
default: 
{
lean_object* v_left_1010_; lean_object* v_right_1011_; lean_object* v___x_1012_; lean_object* v___f_1013_; lean_object* v___x_1014_; lean_object* v___x_1015_; 
v_left_1010_ = lean_ctor_get(v_x_1006_, 0);
lean_inc(v_left_1010_);
v_right_1011_ = lean_ctor_get(v_x_1006_, 1);
lean_inc(v_right_1011_);
lean_dec_ref_known(v_x_1006_, 2);
v___x_1012_ = lean_box(v_phase_1005_);
v___f_1013_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___lam__1___boxed), 3, 2);
lean_closure_set(v___f_1013_, 0, v___x_1012_);
lean_closure_set(v___f_1013_, 1, v_right_1011_);
v___x_1014_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19(v_phase_1005_, v_left_1010_);
v___x_1015_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1014_, v___f_1013_);
return v___x_1015_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___lam__1(uint8_t v_phase_1016_, lean_object* v_right_1017_, lean_object* v_ls_1018_){
_start:
{
lean_object* v___x_1019_; lean_object* v___f_1020_; lean_object* v___x_1021_; lean_object* v___x_1022_; 
v___x_1019_ = lean_box(v_phase_1016_);
v___f_1020_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__0___boxed), 3, 2);
lean_closure_set(v___f_1020_, 0, v___x_1019_);
lean_closure_set(v___f_1020_, 1, v_ls_1018_);
v___x_1021_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19(v_phase_1016_, v_right_1017_);
v___x_1022_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1021_, v___f_1020_);
return v___x_1022_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19___boxed(lean_object* v_phase_1023_, lean_object* v_x_1024_){
_start:
{
uint8_t v_phase_boxed_1025_; lean_object* v_res_1026_; 
v_phase_boxed_1025_ = lean_unbox(v_phase_1023_);
v_res_1026_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19(v_phase_boxed_1025_, v_x_1024_);
return v_res_1026_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__9___lam__0(uint8_t v_phase_1027_, lean_object* v_runs_1028_){
_start:
{
lean_object* v___x_1029_; lean_object* v___x_1030_; 
v___x_1029_ = lp_leansort_LeanSort_RunAdaptive_lengthPlan___redArg(v_runs_1028_);
v___x_1030_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19(v_phase_1027_, v___x_1029_);
return v___x_1030_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__9___lam__0___boxed(lean_object* v_phase_1031_, lean_object* v_runs_1032_){
_start:
{
uint8_t v_phase_boxed_1033_; lean_object* v_res_1034_; 
v_phase_boxed_1033_ = lean_unbox(v_phase_1031_);
v_res_1034_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__9___lam__0(v_phase_boxed_1033_, v_runs_1032_);
return v_res_1034_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__9(uint8_t v_phase_1035_, lean_object* v_xs_1036_){
_start:
{
lean_object* v___x_1037_; lean_object* v___f_1038_; lean_object* v___x_1039_; lean_object* v___x_1040_; 
v___x_1037_ = lean_box(v_phase_1035_);
v___f_1038_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__9___lam__0___boxed), 2, 1);
lean_closure_set(v___f_1038_, 0, v___x_1037_);
v___x_1039_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20(v_phase_1035_, v_xs_1036_);
v___x_1040_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1039_, v___f_1038_);
return v___x_1040_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__9___boxed(lean_object* v_phase_1041_, lean_object* v_xs_1042_){
_start:
{
uint8_t v_phase_boxed_1043_; lean_object* v_res_1044_; 
v_phase_boxed_1043_ = lean_unbox(v_phase_1041_);
v_res_1044_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__9(v_phase_boxed_1043_, v_xs_1042_);
return v_res_1044_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___lam__0___boxed(lean_object* v_phase_1045_, lean_object* v_tail_1046_, lean_object* v_smaller_1047_){
_start:
{
uint8_t v_phase_boxed_1048_; uint8_t v_smaller_boxed_1049_; lean_object* v_res_1050_; 
v_phase_boxed_1048_ = lean_unbox(v_phase_1045_);
v_smaller_boxed_1049_ = lean_unbox(v_smaller_1047_);
v_res_1050_ = l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___lam__0(v_phase_boxed_1048_, v_tail_1046_, v_smaller_boxed_1049_);
return v_res_1050_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17(uint8_t v_phase_1051_, lean_object* v_x_1052_){
_start:
{
if (lean_obj_tag(v_x_1052_) == 0)
{
lean_object* v___x_1053_; 
v___x_1053_ = lean_obj_once(&l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0, &l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0_once, _init_l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0);
return v___x_1053_;
}
else
{
lean_object* v_tail_1054_; 
v_tail_1054_ = lean_ctor_get(v_x_1052_, 1);
lean_inc(v_tail_1054_);
if (lean_obj_tag(v_tail_1054_) == 0)
{
lean_object* v___x_1055_; 
lean_dec_ref_known(v_x_1052_, 2);
v___x_1055_ = lean_obj_once(&l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0, &l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0_once, _init_l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__8___closed__0);
return v___x_1055_;
}
else
{
lean_object* v_head_1056_; lean_object* v_head_1057_; lean_object* v___x_1058_; lean_object* v___f_1059_; uint8_t v___x_1060_; lean_object* v___x_1061_; lean_object* v___x_1062_; 
v_head_1056_ = lean_ctor_get(v_x_1052_, 0);
lean_inc(v_head_1056_);
lean_dec_ref_known(v_x_1052_, 2);
v_head_1057_ = lean_ctor_get(v_tail_1054_, 0);
lean_inc(v_head_1057_);
v___x_1058_ = lean_box(v_phase_1051_);
v___f_1059_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___lam__0___boxed), 3, 2);
lean_closure_set(v___f_1059_, 0, v___x_1058_);
lean_closure_set(v___f_1059_, 1, v_tail_1054_);
v___x_1060_ = 0;
v___x_1061_ = l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__2(v_phase_1051_, v___x_1060_, v_head_1056_, v_head_1057_);
lean_dec(v_head_1057_);
lean_dec(v_head_1056_);
v___x_1062_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1061_, v___f_1059_);
return v___x_1062_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___lam__0(uint8_t v_phase_1063_, lean_object* v_tail_1064_, uint8_t v_smaller_1065_){
_start:
{
if (v_smaller_1065_ == 0)
{
lean_object* v___x_1066_; lean_object* v___x_1067_; 
lean_dec(v_tail_1064_);
v___x_1066_ = lean_box(v_smaller_1065_);
v___x_1067_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_1066_);
return v___x_1067_;
}
else
{
lean_object* v___x_1068_; 
v___x_1068_ = l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17(v_phase_1063_, v_tail_1064_);
return v___x_1068_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17___boxed(lean_object* v_phase_1069_, lean_object* v_x_1070_){
_start:
{
uint8_t v_phase_boxed_1071_; lean_object* v_res_1072_; 
v_phase_boxed_1071_ = lean_unbox(v_phase_1069_);
v_res_1072_ = l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17(v_phase_boxed_1071_, v_x_1070_);
return v_res_1072_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__0(uint8_t v_phase_1073_, lean_object* v_left_1074_, lean_object* v_right_1075_){
_start:
{
lean_object* v___x_1076_; 
v___x_1076_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__16(v_phase_1073_, v_left_1074_, v_right_1075_);
return v___x_1076_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__0___boxed(lean_object* v_phase_1077_, lean_object* v_left_1078_, lean_object* v_right_1079_){
_start:
{
uint8_t v_phase_boxed_1080_; lean_object* v_res_1081_; 
v_phase_boxed_1080_ = lean_unbox(v_phase_1077_);
v_res_1081_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__0(v_phase_boxed_1080_, v_left_1078_, v_right_1079_);
return v_res_1081_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___lam__1___boxed(lean_object* v_phase_1082_, lean_object* v_x_1083_, lean_object* v_tail_1084_, lean_object* v___f_1085_, lean_object* v_x_1086_, lean_object* v_smaller_1087_){
_start:
{
uint8_t v_phase_boxed_1088_; uint8_t v_smaller_boxed_1089_; lean_object* v_res_1090_; 
v_phase_boxed_1088_ = lean_unbox(v_phase_1082_);
v_smaller_boxed_1089_ = lean_unbox(v_smaller_1087_);
v_res_1090_ = l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___lam__1(v_phase_boxed_1088_, v_x_1083_, v_tail_1084_, v___f_1085_, v_x_1086_, v_smaller_boxed_1089_);
return v_res_1090_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28(uint8_t v_phase_1091_, lean_object* v_x_1092_, lean_object* v_x_1093_){
_start:
{
if (lean_obj_tag(v_x_1093_) == 0)
{
lean_object* v___x_1094_; lean_object* v___x_1095_; 
v___x_1094_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1094_, 0, v_x_1092_);
lean_ctor_set(v___x_1094_, 1, v_x_1093_);
v___x_1095_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_1094_);
return v___x_1095_;
}
else
{
lean_object* v_head_1096_; lean_object* v_tail_1097_; lean_object* v___f_1098_; lean_object* v___x_1099_; lean_object* v___f_1100_; uint8_t v___x_1101_; lean_object* v___x_1102_; lean_object* v___x_1103_; 
v_head_1096_ = lean_ctor_get(v_x_1093_, 0);
lean_inc_n(v_head_1096_, 2);
v_tail_1097_ = lean_ctor_get(v_x_1093_, 1);
lean_inc(v_tail_1097_);
v___f_1098_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0_spec__1_spec__7___lam__0), 2, 1);
lean_closure_set(v___f_1098_, 0, v_head_1096_);
v___x_1099_ = lean_box(v_phase_1091_);
lean_inc(v_x_1092_);
v___f_1100_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___lam__1___boxed), 6, 5);
lean_closure_set(v___f_1100_, 0, v___x_1099_);
lean_closure_set(v___f_1100_, 1, v_x_1092_);
lean_closure_set(v___f_1100_, 2, v_tail_1097_);
lean_closure_set(v___f_1100_, 3, v___f_1098_);
lean_closure_set(v___f_1100_, 4, v_x_1093_);
v___x_1101_ = 1;
v___x_1102_ = l_LeanSort_Direct_phaseCompare___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__2(v_phase_1091_, v___x_1101_, v_x_1092_, v_head_1096_);
lean_dec(v_head_1096_);
lean_dec(v_x_1092_);
v___x_1103_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1102_, v___f_1100_);
return v___x_1103_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___lam__1(uint8_t v_phase_1104_, lean_object* v_x_1105_, lean_object* v_tail_1106_, lean_object* v___f_1107_, lean_object* v_x_1108_, uint8_t v_smaller_1109_){
_start:
{
if (v_smaller_1109_ == 0)
{
lean_object* v___x_1110_; lean_object* v___x_1111_; 
lean_dec(v_x_1108_);
v___x_1110_ = l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28(v_phase_1104_, v_x_1105_, v_tail_1106_);
v___x_1111_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1110_, v___f_1107_);
return v___x_1111_;
}
else
{
lean_object* v___x_1112_; lean_object* v___x_1113_; 
lean_dec_ref(v___f_1107_);
lean_dec(v_tail_1106_);
v___x_1112_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1112_, 0, v_x_1105_);
lean_ctor_set(v___x_1112_, 1, v_x_1108_);
v___x_1113_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v___x_1112_);
return v___x_1113_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28___boxed(lean_object* v_phase_1114_, lean_object* v_x_1115_, lean_object* v_x_1116_){
_start:
{
uint8_t v_phase_boxed_1117_; lean_object* v_res_1118_; 
v_phase_boxed_1117_ = lean_unbox(v_phase_1114_);
v_res_1118_ = l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28(v_phase_boxed_1117_, v_x_1115_, v_x_1116_);
return v_res_1118_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___lam__0(uint8_t v_phase_1119_, lean_object* v_head_1120_, lean_object* v_rest_1121_){
_start:
{
lean_object* v___x_1122_; 
v___x_1122_ = l_LeanSort_Direct_Engine_insert___at___00LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23_spec__28(v_phase_1119_, v_head_1120_, v_rest_1121_);
return v___x_1122_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___lam__0___boxed(lean_object* v_phase_1123_, lean_object* v_head_1124_, lean_object* v_rest_1125_){
_start:
{
uint8_t v_phase_boxed_1126_; lean_object* v_res_1127_; 
v_phase_boxed_1126_ = lean_unbox(v_phase_1123_);
v_res_1127_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___lam__0(v_phase_boxed_1126_, v_head_1124_, v_rest_1125_);
return v_res_1127_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23(uint8_t v_phase_1128_, lean_object* v_x_1129_){
_start:
{
if (lean_obj_tag(v_x_1129_) == 0)
{
lean_object* v___x_1130_; 
v___x_1130_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_1129_);
return v___x_1130_;
}
else
{
lean_object* v_head_1131_; lean_object* v_tail_1132_; lean_object* v___x_1133_; lean_object* v___f_1134_; lean_object* v___x_1135_; lean_object* v___x_1136_; 
v_head_1131_ = lean_ctor_get(v_x_1129_, 0);
lean_inc(v_head_1131_);
v_tail_1132_ = lean_ctor_get(v_x_1129_, 1);
lean_inc(v_tail_1132_);
lean_dec_ref_known(v_x_1129_, 2);
v___x_1133_ = lean_box(v_phase_1128_);
v___f_1134_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___lam__0___boxed), 3, 2);
lean_closure_set(v___f_1134_, 0, v___x_1133_);
lean_closure_set(v___f_1134_, 1, v_head_1131_);
v___x_1135_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23(v_phase_1128_, v_tail_1132_);
v___x_1136_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1135_, v___f_1134_);
return v___x_1136_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23___boxed(lean_object* v_phase_1137_, lean_object* v_x_1138_){
_start:
{
uint8_t v_phase_boxed_1139_; lean_object* v_res_1140_; 
v_phase_boxed_1139_ = lean_unbox(v_phase_1137_);
v_res_1140_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23(v_phase_boxed_1139_, v_x_1138_);
return v_res_1140_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___lam__1___boxed(lean_object* v_phase_1141_, lean_object* v___x_1142_, lean_object* v_xs_1143_, lean_object* v_threshold_1144_, lean_object* v_left_1145_){
_start:
{
uint8_t v_phase_boxed_1146_; lean_object* v_res_1147_; 
v_phase_boxed_1146_ = lean_unbox(v_phase_1141_);
v_res_1147_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___lam__1(v_phase_boxed_1146_, v___x_1142_, v_xs_1143_, v_threshold_1144_, v_left_1145_);
lean_dec(v_xs_1143_);
return v_res_1147_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24(uint8_t v_phase_1148_, lean_object* v_threshold_1149_, lean_object* v_xs_1150_){
_start:
{
lean_object* v___x_1151_; lean_object* v___y_1153_; lean_object* v___x_1164_; uint8_t v___x_1165_; 
v___x_1151_ = l_List_lengthTR___redArg(v_xs_1150_);
v___x_1164_ = lean_unsigned_to_nat(1u);
v___x_1165_ = lean_nat_dec_le(v___x_1164_, v_threshold_1149_);
if (v___x_1165_ == 0)
{
v___y_1153_ = v___x_1164_;
goto v___jp_1152_;
}
else
{
lean_inc(v_threshold_1149_);
v___y_1153_ = v_threshold_1149_;
goto v___jp_1152_;
}
v___jp_1152_:
{
uint8_t v___x_1154_; 
v___x_1154_ = lean_nat_dec_le(v___x_1151_, v___y_1153_);
lean_dec(v___y_1153_);
if (v___x_1154_ == 0)
{
lean_object* v___x_1155_; lean_object* v___x_1156_; lean_object* v___x_1157_; lean_object* v___f_1158_; lean_object* v___x_1159_; lean_object* v___x_1160_; lean_object* v___x_1161_; lean_object* v___x_1162_; 
v___x_1155_ = lean_unsigned_to_nat(1u);
v___x_1156_ = lean_nat_shiftr(v___x_1151_, v___x_1155_);
lean_dec(v___x_1151_);
v___x_1157_ = lean_box(v_phase_1148_);
lean_inc(v_threshold_1149_);
lean_inc_n(v_xs_1150_, 2);
lean_inc(v___x_1156_);
v___f_1158_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___lam__1___boxed), 5, 4);
lean_closure_set(v___f_1158_, 0, v___x_1157_);
lean_closure_set(v___f_1158_, 1, v___x_1156_);
lean_closure_set(v___f_1158_, 2, v_xs_1150_);
lean_closure_set(v___f_1158_, 3, v_threshold_1149_);
v___x_1159_ = ((lean_object*)(l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3___closed__0));
v___x_1160_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_xs_1150_, v_xs_1150_, v___x_1156_, v___x_1159_);
lean_dec(v_xs_1150_);
v___x_1161_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24(v_phase_1148_, v_threshold_1149_, v___x_1160_);
v___x_1162_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1161_, v___f_1158_);
return v___x_1162_;
}
else
{
lean_object* v___x_1163_; 
lean_dec(v___x_1151_);
lean_dec(v_threshold_1149_);
v___x_1163_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23(v_phase_1148_, v_xs_1150_);
return v___x_1163_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___lam__1(uint8_t v_phase_1166_, lean_object* v___x_1167_, lean_object* v_xs_1168_, lean_object* v_threshold_1169_, lean_object* v_left_1170_){
_start:
{
lean_object* v___x_1171_; lean_object* v___f_1172_; lean_object* v___x_1173_; lean_object* v___x_1174_; lean_object* v___x_1175_; 
v___x_1171_ = lean_box(v_phase_1166_);
v___f_1172_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__0___boxed), 3, 2);
lean_closure_set(v___f_1172_, 0, v___x_1171_);
lean_closure_set(v___f_1172_, 1, v_left_1170_);
v___x_1173_ = l_List_drop___redArg(v___x_1167_, v_xs_1168_);
v___x_1174_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24(v_phase_1166_, v_threshold_1169_, v___x_1173_);
v___x_1175_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1174_, v___f_1172_);
return v___x_1175_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24___boxed(lean_object* v_phase_1176_, lean_object* v_threshold_1177_, lean_object* v_xs_1178_){
_start:
{
uint8_t v_phase_boxed_1179_; lean_object* v_res_1180_; 
v_phase_boxed_1179_ = lean_unbox(v_phase_1176_);
v_res_1180_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24(v_phase_boxed_1179_, v_threshold_1177_, v_xs_1178_);
return v_res_1180_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__1___boxed(lean_object* v_phase_1181_, lean_object* v___x_1182_, lean_object* v_xs_1183_, lean_object* v_left_1184_){
_start:
{
uint8_t v_phase_boxed_1185_; lean_object* v_res_1186_; 
v_phase_boxed_1185_ = lean_unbox(v_phase_1181_);
v_res_1186_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__1(v_phase_boxed_1185_, v___x_1182_, v_xs_1183_, v_left_1184_);
lean_dec(v_xs_1183_);
return v_res_1186_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22(uint8_t v_phase_1187_, lean_object* v_xs_1188_){
_start:
{
lean_object* v___x_1189_; lean_object* v___x_1190_; uint8_t v___x_1191_; 
v___x_1189_ = l_List_lengthTR___redArg(v_xs_1188_);
v___x_1190_ = lean_unsigned_to_nat(2u);
v___x_1191_ = lean_nat_dec_lt(v___x_1189_, v___x_1190_);
if (v___x_1191_ == 0)
{
lean_object* v___x_1192_; lean_object* v___x_1193_; lean_object* v___x_1194_; lean_object* v___f_1195_; lean_object* v___x_1196_; lean_object* v___x_1197_; lean_object* v___x_1198_; lean_object* v___x_1199_; 
v___x_1192_ = lean_unsigned_to_nat(1u);
v___x_1193_ = lean_nat_shiftr(v___x_1189_, v___x_1192_);
lean_dec(v___x_1189_);
v___x_1194_ = lean_box(v_phase_1187_);
lean_inc_n(v_xs_1188_, 2);
lean_inc(v___x_1193_);
v___f_1195_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__1___boxed), 4, 3);
lean_closure_set(v___f_1195_, 0, v___x_1194_);
lean_closure_set(v___f_1195_, 1, v___x_1193_);
lean_closure_set(v___f_1195_, 2, v_xs_1188_);
v___x_1196_ = ((lean_object*)(l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3___closed__0));
v___x_1197_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_xs_1188_, v_xs_1188_, v___x_1193_, v___x_1196_);
lean_dec(v_xs_1188_);
v___x_1198_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22(v_phase_1187_, v___x_1197_);
v___x_1199_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1198_, v___f_1195_);
return v___x_1199_;
}
else
{
lean_object* v___x_1200_; 
lean_dec(v___x_1189_);
v___x_1200_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_xs_1188_);
return v___x_1200_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__1(uint8_t v_phase_1201_, lean_object* v___x_1202_, lean_object* v_xs_1203_, lean_object* v_left_1204_){
_start:
{
lean_object* v___x_1205_; lean_object* v___f_1206_; lean_object* v___x_1207_; lean_object* v___x_1208_; lean_object* v___x_1209_; 
v___x_1205_ = lean_box(v_phase_1201_);
v___f_1206_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___lam__0___boxed), 3, 2);
lean_closure_set(v___f_1206_, 0, v___x_1205_);
lean_closure_set(v___f_1206_, 1, v_left_1204_);
v___x_1207_ = l_List_drop___redArg(v___x_1202_, v_xs_1203_);
v___x_1208_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22(v_phase_1201_, v___x_1207_);
v___x_1209_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1208_, v___f_1206_);
return v___x_1209_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22___boxed(lean_object* v_phase_1210_, lean_object* v_xs_1211_){
_start:
{
uint8_t v_phase_boxed_1212_; lean_object* v_res_1213_; 
v_phase_boxed_1212_ = lean_unbox(v_phase_1210_);
v_res_1213_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22(v_phase_boxed_1212_, v_xs_1211_);
return v_res_1213_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15(uint8_t v_phase_1214_, lean_object* v_x_1215_, lean_object* v_x_1216_){
_start:
{
switch(lean_obj_tag(v_x_1215_))
{
case 0:
{
lean_object* v___x_1217_; 
v___x_1217_ = l_LeanSort_Direct_Engine_mergeSort___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__22(v_phase_1214_, v_x_1216_);
return v___x_1217_;
}
case 1:
{
lean_object* v___x_1218_; 
v___x_1218_ = l_LeanSort_Direct_Engine_insertion___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__23(v_phase_1214_, v_x_1216_);
return v___x_1218_;
}
default: 
{
lean_object* v_threshold_1219_; lean_object* v___x_1220_; 
v_threshold_1219_ = lean_ctor_get(v_x_1215_, 0);
lean_inc(v_threshold_1219_);
lean_dec_ref_known(v_x_1215_, 1);
v___x_1220_ = l_LeanSort_Direct_Engine_hybrid___at___00LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15_spec__24(v_phase_1214_, v_threshold_1219_, v_x_1216_);
return v___x_1220_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15___boxed(lean_object* v_phase_1221_, lean_object* v_x_1222_, lean_object* v_x_1223_){
_start:
{
uint8_t v_phase_boxed_1224_; lean_object* v_res_1225_; 
v_phase_boxed_1224_ = lean_unbox(v_phase_1221_);
v_res_1225_ = l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15(v_phase_boxed_1224_, v_x_1222_, v_x_1223_);
return v_res_1225_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__1___boxed(lean_object* v_phase_1226_, lean_object* v___x_1227_, lean_object* v_x_1228_, lean_object* v_right_1229_, lean_object* v_ls_1230_){
_start:
{
uint8_t v_phase_boxed_1231_; lean_object* v_res_1232_; 
v_phase_boxed_1231_ = lean_unbox(v_phase_1226_);
v_res_1232_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__1(v_phase_boxed_1231_, v___x_1227_, v_x_1228_, v_right_1229_, v_ls_1230_);
lean_dec(v_x_1228_);
return v_res_1232_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__2(uint8_t v_phase_1233_, lean_object* v_fallback_1234_, lean_object* v_x_1235_, uint8_t v_sorted_1236_){
_start:
{
if (v_sorted_1236_ == 0)
{
lean_object* v___x_1237_; 
v___x_1237_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7(v_phase_1233_, v_fallback_1234_, v_x_1235_);
return v___x_1237_;
}
else
{
lean_object* v___x_1238_; 
lean_dec_ref(v_fallback_1234_);
v___x_1238_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__1___redArg(v_x_1235_);
return v___x_1238_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__2___boxed(lean_object* v_phase_1239_, lean_object* v_fallback_1240_, lean_object* v_x_1241_, lean_object* v_sorted_1242_){
_start:
{
uint8_t v_phase_boxed_1243_; uint8_t v_sorted_boxed_1244_; lean_object* v_res_1245_; 
v_phase_boxed_1243_ = lean_unbox(v_phase_1239_);
v_sorted_boxed_1244_ = lean_unbox(v_sorted_1242_);
v_res_1245_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__2(v_phase_boxed_1243_, v_fallback_1240_, v_x_1241_, v_sorted_boxed_1244_);
return v_res_1245_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7(uint8_t v_phase_1246_, lean_object* v_x_1247_, lean_object* v_x_1248_){
_start:
{
switch(lean_obj_tag(v_x_1247_))
{
case 0:
{
lean_object* v_component_1249_; lean_object* v___x_1250_; 
v_component_1249_ = lean_ctor_get(v_x_1247_, 0);
lean_inc(v_component_1249_);
lean_dec_ref_known(v_x_1247_, 1);
v___x_1250_ = l_LeanSort_Direct_Engine_component___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__15(v_phase_1246_, v_component_1249_, v_x_1248_);
return v___x_1250_;
}
case 1:
{
lean_object* v_cut_1251_; lean_object* v_left_1252_; lean_object* v_right_1253_; lean_object* v___x_1254_; lean_object* v___x_1255_; lean_object* v___x_1256_; lean_object* v___f_1257_; lean_object* v___x_1258_; lean_object* v___x_1259_; lean_object* v___x_1260_; lean_object* v___x_1261_; 
v_cut_1251_ = lean_ctor_get(v_x_1247_, 0);
lean_inc_ref(v_cut_1251_);
v_left_1252_ = lean_ctor_get(v_x_1247_, 1);
lean_inc_ref(v_left_1252_);
v_right_1253_ = lean_ctor_get(v_x_1247_, 2);
lean_inc_ref(v_right_1253_);
lean_dec_ref_known(v_x_1247_, 3);
v___x_1254_ = l_List_lengthTR___redArg(v_x_1248_);
v___x_1255_ = lp_leansort_LeanSort_CostedPlan_Cut_position(v_cut_1251_, v___x_1254_);
lean_dec(v___x_1254_);
lean_dec_ref(v_cut_1251_);
v___x_1256_ = lean_box(v_phase_1246_);
lean_inc_n(v_x_1248_, 2);
lean_inc(v___x_1255_);
v___f_1257_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__1___boxed), 5, 4);
lean_closure_set(v___f_1257_, 0, v___x_1256_);
lean_closure_set(v___f_1257_, 1, v___x_1255_);
lean_closure_set(v___f_1257_, 2, v_x_1248_);
lean_closure_set(v___f_1257_, 3, v_right_1253_);
v___x_1258_ = ((lean_object*)(l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3___closed__0));
v___x_1259_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_x_1248_, v_x_1248_, v___x_1255_, v___x_1258_);
lean_dec(v_x_1248_);
v___x_1260_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7(v_phase_1246_, v_left_1252_, v___x_1259_);
v___x_1261_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1260_, v___f_1257_);
return v___x_1261_;
}
default: 
{
lean_object* v_fallback_1262_; lean_object* v___x_1263_; lean_object* v___f_1264_; lean_object* v___x_1265_; lean_object* v___x_1266_; 
v_fallback_1262_ = lean_ctor_get(v_x_1247_, 0);
lean_inc_ref(v_fallback_1262_);
lean_dec_ref_known(v_x_1247_, 1);
v___x_1263_ = lean_box(v_phase_1246_);
lean_inc(v_x_1248_);
v___f_1264_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__2___boxed), 4, 3);
lean_closure_set(v___f_1264_, 0, v___x_1263_);
lean_closure_set(v___f_1264_, 1, v_fallback_1262_);
lean_closure_set(v___f_1264_, 2, v_x_1248_);
v___x_1265_ = l_LeanSort_Direct_Engine_checkSorted___at___00LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7_spec__17(v_phase_1246_, v_x_1248_);
v___x_1266_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1265_, v___f_1264_);
return v___x_1266_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__1(uint8_t v_phase_1267_, lean_object* v___x_1268_, lean_object* v_x_1269_, lean_object* v_right_1270_, lean_object* v_ls_1271_){
_start:
{
lean_object* v___x_1272_; lean_object* v___f_1273_; lean_object* v___x_1274_; lean_object* v___x_1275_; lean_object* v___x_1276_; 
v___x_1272_ = lean_box(v_phase_1267_);
v___f_1273_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___lam__0___boxed), 3, 2);
lean_closure_set(v___f_1273_, 0, v___x_1272_);
lean_closure_set(v___f_1273_, 1, v_ls_1271_);
v___x_1274_ = l_List_drop___redArg(v___x_1268_, v_x_1269_);
v___x_1275_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7(v_phase_1267_, v_right_1270_, v___x_1274_);
v___x_1276_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1275_, v___f_1273_);
return v___x_1276_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7___boxed(lean_object* v_phase_1277_, lean_object* v_x_1278_, lean_object* v_x_1279_){
_start:
{
uint8_t v_phase_boxed_1280_; lean_object* v_res_1281_; 
v_phase_boxed_1280_ = lean_unbox(v_phase_1277_);
v_res_1281_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7(v_phase_boxed_1280_, v_x_1278_, v_x_1279_);
return v_res_1281_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8___lam__0(uint8_t v_phase_1282_, lean_object* v_runs_1283_){
_start:
{
lean_object* v___x_1284_; lean_object* v___x_1285_; 
v___x_1284_ = lp_leansort_LeanSort_RunAdaptive_countPlan___redArg(v_runs_1283_);
v___x_1285_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__19(v_phase_1282_, v___x_1284_);
return v___x_1285_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8___lam__0___boxed(lean_object* v_phase_1286_, lean_object* v_runs_1287_){
_start:
{
uint8_t v_phase_boxed_1288_; lean_object* v_res_1289_; 
v_phase_boxed_1288_ = lean_unbox(v_phase_1286_);
v_res_1289_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8___lam__0(v_phase_boxed_1288_, v_runs_1287_);
return v_res_1289_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8(uint8_t v_phase_1290_, lean_object* v_xs_1291_){
_start:
{
lean_object* v___x_1292_; lean_object* v___f_1293_; lean_object* v___x_1294_; lean_object* v___x_1295_; 
v___x_1292_ = lean_box(v_phase_1290_);
v___f_1293_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8___lam__0___boxed), 2, 1);
lean_closure_set(v___f_1293_, 0, v___x_1292_);
v___x_1294_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8_spec__20(v_phase_1290_, v_xs_1291_);
v___x_1295_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0_spec__2___redArg(v___x_1294_, v___f_1293_);
return v___x_1295_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8___boxed(lean_object* v_phase_1296_, lean_object* v_xs_1297_){
_start:
{
uint8_t v_phase_boxed_1298_; lean_object* v_res_1299_; 
v_phase_boxed_1298_ = lean_unbox(v_phase_1296_);
v_res_1299_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8(v_phase_boxed_1298_, v_xs_1297_);
return v_res_1299_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3(uint8_t v_phase_1300_, lean_object* v_x_1301_, lean_object* v_x_1302_){
_start:
{
switch(lean_obj_tag(v_x_1301_))
{
case 0:
{
lean_object* v_schema_1303_; lean_object* v___x_1304_; 
v_schema_1303_ = lean_ctor_get(v_x_1301_, 0);
lean_inc_ref(v_schema_1303_);
lean_dec_ref_known(v_x_1301_, 1);
v___x_1304_ = l_LeanSort_Direct_Engine_schema___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__7(v_phase_1300_, v_schema_1303_, v_x_1302_);
return v___x_1304_;
}
case 1:
{
lean_object* v___x_1305_; 
v___x_1305_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__8(v_phase_1300_, v_x_1302_);
return v___x_1305_;
}
default: 
{
lean_object* v___x_1306_; 
v___x_1306_ = l_LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3_spec__9(v_phase_1300_, v_x_1302_);
return v___x_1306_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3___boxed(lean_object* v_phase_1307_, lean_object* v_x_1308_, lean_object* v_x_1309_){
_start:
{
uint8_t v_phase_boxed_1310_; lean_object* v_res_1311_; 
v_phase_boxed_1310_ = lean_unbox(v_phase_1307_);
v_res_1311_ = l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3(v_phase_boxed_1310_, v_x_1308_, v_x_1309_);
return v_res_1311_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00LearningWorker_kernelProfile_spec__2_spec__5(lean_object* v_x_1312_, lean_object* v_x_1313_){
_start:
{
switch(lean_obj_tag(v_x_1312_))
{
case 0:
{
lean_object* v_schema_1314_; lean_object* v___x_1315_; lean_object* v___x_1316_; 
v_schema_1314_ = lean_ctor_get(v_x_1312_, 0);
v___x_1315_ = l_List_lengthTR___redArg(v_x_1313_);
lean_dec(v_x_1313_);
v___x_1316_ = lp_leansort_LeanSort_CostedPlan_Schema_upper(v_schema_1314_, v___x_1315_);
lean_dec(v___x_1315_);
return v___x_1316_;
}
case 1:
{
lean_object* v___x_1317_; lean_object* v___x_1318_; lean_object* v___x_1319_; lean_object* v___x_1320_; lean_object* v___x_1321_; lean_object* v___x_1322_; lean_object* v___x_1323_; lean_object* v___x_1324_; lean_object* v___x_1325_; 
v___x_1317_ = l_List_lengthTR___redArg(v_x_1313_);
v___x_1318_ = lean_unsigned_to_nat(1u);
v___x_1319_ = lean_nat_sub(v___x_1317_, v___x_1318_);
v___x_1320_ = lean_unsigned_to_nat(2u);
v___x_1321_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_run___at___00LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0_spec__0_spec__1_spec__3_spec__7(v_x_1313_);
v___x_1322_ = l_List_lengthTR___redArg(v___x_1321_);
lean_dec(v___x_1321_);
v___x_1323_ = lp_mathlib_Nat_clog(v___x_1320_, v___x_1322_);
lean_dec(v___x_1322_);
v___x_1324_ = lean_nat_mul(v___x_1317_, v___x_1323_);
lean_dec(v___x_1323_);
lean_dec(v___x_1317_);
v___x_1325_ = lean_nat_add(v___x_1319_, v___x_1324_);
lean_dec(v___x_1324_);
lean_dec(v___x_1319_);
return v___x_1325_;
}
default: 
{
lean_object* v___x_1326_; lean_object* v___x_1327_; lean_object* v___x_1328_; lean_object* v___x_1329_; lean_object* v___x_1330_; lean_object* v___x_1331_; lean_object* v___x_1332_; 
v___x_1326_ = l_List_lengthTR___redArg(v_x_1313_);
v___x_1327_ = lean_unsigned_to_nat(1u);
v___x_1328_ = lean_nat_sub(v___x_1326_, v___x_1327_);
lean_dec(v___x_1326_);
v___x_1329_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_run___at___00LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0_spec__0_spec__1_spec__3_spec__7(v_x_1313_);
v___x_1330_ = lp_leansort_LeanSort_RunAdaptive_lengthPlan___redArg(v___x_1329_);
v___x_1331_ = lp_leansort_LeanSort_RunAdaptive_MergeTree_budget___redArg(v___x_1330_);
lean_dec(v___x_1330_);
v___x_1332_ = lean_nat_add(v___x_1328_, v___x_1331_);
lean_dec(v___x_1331_);
lean_dec(v___x_1328_);
return v___x_1332_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00LearningWorker_kernelProfile_spec__2_spec__5___boxed(lean_object* v_x_1333_, lean_object* v_x_1334_){
_start:
{
lean_object* v_res_1335_; 
v_res_1335_ = l_LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00LearningWorker_kernelProfile_spec__2_spec__5(v_x_1333_, v_x_1334_);
lean_dec(v_x_1333_);
return v_res_1335_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_LearnedSelection_kernelBound___at___00LearningWorker_kernelProfile_spec__2(lean_object* v_id_1336_, lean_object* v_xs_1337_){
_start:
{
lean_object* v___x_1338_; lean_object* v___x_1339_; lean_object* v___x_1340_; 
v___x_1338_ = l_LeanSort_LearnedSelection_resolve(v_id_1336_);
v___x_1339_ = l_LeanSort_LearnedSelection_candidate(v___x_1338_);
lean_dec(v___x_1338_);
v___x_1340_ = l_LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00LearningWorker_kernelProfile_spec__2_spec__5(v___x_1339_, v_xs_1337_);
lean_dec(v___x_1339_);
return v___x_1340_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_LearnedSelection_kernelBound___at___00LearningWorker_kernelProfile_spec__2___boxed(lean_object* v_id_1341_, lean_object* v_xs_1342_){
_start:
{
lean_object* v_res_1343_; 
v_res_1343_ = l_LeanSort_LearnedSelection_kernelBound___at___00LearningWorker_kernelProfile_spec__2(v_id_1341_, v_xs_1342_);
lean_dec(v_id_1341_);
return v_res_1343_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_kernelProfile(lean_object* v_id_1356_, lean_object* v_xs_1357_, lean_object* v_expected_1358_){
_start:
{
lean_object* v_s_1363_; lean_object* v_result_1364_; lean_object* v_ret_1365_; uint8_t v___x_1366_; lean_object* v_checks_1367_; uint8_t v___x_1368_; lean_object* v_sorting_1369_; uint8_t v___y_1371_; lean_object* v___y_1372_; uint8_t v___y_1437_; uint8_t v___x_1466_; 
v_s_1363_ = l_LeanSort_LearnedSelection_candidate(v_id_1356_);
lean_inc_n(v_xs_1357_, 3);
lean_inc_n(v_s_1363_, 3);
v_result_1364_ = l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0(v_s_1363_, v_xs_1357_);
v_ret_1365_ = lean_ctor_get(v_result_1364_, 0);
lean_inc(v_ret_1365_);
v___x_1366_ = 0;
v_checks_1367_ = l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3(v___x_1366_, v_s_1363_, v_xs_1357_);
v___x_1368_ = 1;
v_sorting_1369_ = l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3(v___x_1368_, v_s_1363_, v_xs_1357_);
v___x_1466_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v_ret_1365_, v_expected_1358_);
lean_dec(v_ret_1365_);
if (v___x_1466_ == 0)
{
v___y_1437_ = v___x_1466_;
goto v___jp_1436_;
}
else
{
lean_object* v_ret_1467_; uint8_t v___x_1468_; 
v_ret_1467_ = lean_ctor_get(v_checks_1367_, 0);
lean_inc(v_ret_1467_);
v___x_1468_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v_ret_1467_, v_expected_1358_);
lean_dec(v_ret_1467_);
v___y_1437_ = v___x_1468_;
goto v___jp_1436_;
}
v___jp_1360_:
{
lean_object* v___x_1361_; lean_object* v___x_1362_; 
v___x_1361_ = ((lean_object*)(l_LearningWorker_kernelProfile___closed__1));
v___x_1362_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1362_, 0, v___x_1361_);
return v___x_1362_;
}
v___jp_1370_:
{
lean_object* v_time_1373_; lean_object* v___x_1375_; uint8_t v_isShared_1376_; uint8_t v_isSharedCheck_1434_; 
v_time_1373_ = lean_ctor_get(v_result_1364_, 1);
v_isSharedCheck_1434_ = !lean_is_exclusive(v_result_1364_);
if (v_isSharedCheck_1434_ == 0)
{
lean_object* v_unused_1435_; 
v_unused_1435_ = lean_ctor_get(v_result_1364_, 0);
lean_dec(v_unused_1435_);
v___x_1375_ = v_result_1364_;
v_isShared_1376_ = v_isSharedCheck_1434_;
goto v_resetjp_1374_;
}
else
{
lean_inc(v_time_1373_);
lean_dec(v_result_1364_);
v___x_1375_ = lean_box(0);
v_isShared_1376_ = v_isSharedCheck_1434_;
goto v_resetjp_1374_;
}
v_resetjp_1374_:
{
lean_object* v_time_1377_; lean_object* v___x_1379_; uint8_t v_isShared_1380_; uint8_t v_isSharedCheck_1432_; 
v_time_1377_ = lean_ctor_get(v_checks_1367_, 1);
v_isSharedCheck_1432_ = !lean_is_exclusive(v_checks_1367_);
if (v_isSharedCheck_1432_ == 0)
{
lean_object* v_unused_1433_; 
v_unused_1433_ = lean_ctor_get(v_checks_1367_, 0);
lean_dec(v_unused_1433_);
v___x_1379_ = v_checks_1367_;
v_isShared_1380_ = v_isSharedCheck_1432_;
goto v_resetjp_1378_;
}
else
{
lean_inc(v_time_1377_);
lean_dec(v_checks_1367_);
v___x_1379_ = lean_box(0);
v_isShared_1380_ = v_isSharedCheck_1432_;
goto v_resetjp_1378_;
}
v_resetjp_1378_:
{
lean_object* v_time_1381_; lean_object* v___x_1383_; uint8_t v_isShared_1384_; uint8_t v_isSharedCheck_1430_; 
v_time_1381_ = lean_ctor_get(v_sorting_1369_, 1);
v_isSharedCheck_1430_ = !lean_is_exclusive(v_sorting_1369_);
if (v_isSharedCheck_1430_ == 0)
{
lean_object* v_unused_1431_; 
v_unused_1431_ = lean_ctor_get(v_sorting_1369_, 0);
lean_dec(v_unused_1431_);
v___x_1383_ = v_sorting_1369_;
v_isShared_1384_ = v_isSharedCheck_1430_;
goto v_resetjp_1382_;
}
else
{
lean_inc(v_time_1381_);
lean_dec(v_sorting_1369_);
v___x_1383_ = lean_box(0);
v_isShared_1384_ = v_isSharedCheck_1430_;
goto v_resetjp_1382_;
}
v_resetjp_1382_:
{
lean_object* v___x_1385_; lean_object* v___x_1386_; lean_object* v___x_1387_; lean_object* v___x_1389_; 
v___x_1385_ = ((lean_object*)(l_LearningWorker_decodePolicy___closed__6));
lean_inc(v_id_1356_);
v___x_1386_ = l_Lean_JsonNumber_fromNat(v_id_1356_);
v___x_1387_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1387_, 0, v___x_1386_);
if (v_isShared_1384_ == 0)
{
lean_ctor_set(v___x_1383_, 1, v___x_1387_);
lean_ctor_set(v___x_1383_, 0, v___x_1385_);
v___x_1389_ = v___x_1383_;
goto v_reusejp_1388_;
}
else
{
lean_object* v_reuseFailAlloc_1429_; 
v_reuseFailAlloc_1429_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1429_, 0, v___x_1385_);
lean_ctor_set(v_reuseFailAlloc_1429_, 1, v___x_1387_);
v___x_1389_ = v_reuseFailAlloc_1429_;
goto v_reusejp_1388_;
}
v_reusejp_1388_:
{
lean_object* v___x_1390_; lean_object* v___x_1391_; lean_object* v___x_1392_; lean_object* v___x_1394_; 
v___x_1390_ = ((lean_object*)(l_LearningWorker_kernelProfile___closed__2));
v___x_1391_ = l_Lean_JsonNumber_fromNat(v_time_1373_);
v___x_1392_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1392_, 0, v___x_1391_);
if (v_isShared_1380_ == 0)
{
lean_ctor_set(v___x_1379_, 1, v___x_1392_);
lean_ctor_set(v___x_1379_, 0, v___x_1390_);
v___x_1394_ = v___x_1379_;
goto v_reusejp_1393_;
}
else
{
lean_object* v_reuseFailAlloc_1428_; 
v_reuseFailAlloc_1428_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1428_, 0, v___x_1390_);
lean_ctor_set(v_reuseFailAlloc_1428_, 1, v___x_1392_);
v___x_1394_ = v_reuseFailAlloc_1428_;
goto v_reusejp_1393_;
}
v_reusejp_1393_:
{
lean_object* v___x_1395_; lean_object* v___x_1396_; lean_object* v___x_1397_; lean_object* v___x_1399_; 
v___x_1395_ = ((lean_object*)(l_LearningWorker_kernelProfile___closed__3));
v___x_1396_ = l_Lean_JsonNumber_fromNat(v_time_1377_);
v___x_1397_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1397_, 0, v___x_1396_);
if (v_isShared_1376_ == 0)
{
lean_ctor_set(v___x_1375_, 1, v___x_1397_);
lean_ctor_set(v___x_1375_, 0, v___x_1395_);
v___x_1399_ = v___x_1375_;
goto v_reusejp_1398_;
}
else
{
lean_object* v_reuseFailAlloc_1427_; 
v_reuseFailAlloc_1427_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1427_, 0, v___x_1395_);
lean_ctor_set(v_reuseFailAlloc_1427_, 1, v___x_1397_);
v___x_1399_ = v_reuseFailAlloc_1427_;
goto v_reusejp_1398_;
}
v_reusejp_1398_:
{
lean_object* v___x_1400_; lean_object* v___x_1401_; lean_object* v___x_1402_; lean_object* v___x_1403_; lean_object* v___x_1404_; lean_object* v___x_1405_; lean_object* v___x_1406_; lean_object* v___x_1407_; lean_object* v___x_1408_; lean_object* v___x_1409_; lean_object* v___x_1410_; lean_object* v___x_1411_; lean_object* v___x_1412_; lean_object* v___x_1413_; lean_object* v___x_1414_; lean_object* v___x_1415_; lean_object* v___x_1416_; lean_object* v___x_1417_; lean_object* v___x_1418_; lean_object* v___x_1419_; lean_object* v___x_1420_; lean_object* v___x_1421_; lean_object* v___x_1422_; lean_object* v___x_1423_; lean_object* v___x_1424_; lean_object* v___x_1425_; lean_object* v___x_1426_; 
v___x_1400_ = ((lean_object*)(l_LearningWorker_kernelProfile___closed__4));
v___x_1401_ = l_Lean_JsonNumber_fromNat(v_time_1381_);
v___x_1402_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1402_, 0, v___x_1401_);
v___x_1403_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1403_, 0, v___x_1400_);
lean_ctor_set(v___x_1403_, 1, v___x_1402_);
v___x_1404_ = ((lean_object*)(l_LearningWorker_kernelProfile___closed__5));
v___x_1405_ = lean_nat_to_int(v_id_1356_);
v___x_1406_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1406_, 0, v___x_1405_);
v___x_1407_ = l_LeanSort_LearnedSelection_kernelBound___at___00LearningWorker_kernelProfile_spec__2(v___x_1406_, v_xs_1357_);
lean_dec_ref_known(v___x_1406_, 1);
v___x_1408_ = l_Lean_JsonNumber_fromNat(v___x_1407_);
v___x_1409_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1409_, 0, v___x_1408_);
v___x_1410_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1410_, 0, v___x_1404_);
lean_ctor_set(v___x_1410_, 1, v___x_1409_);
v___x_1411_ = ((lean_object*)(l_LearningWorker_kernelProfile___closed__6));
v___x_1412_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_1412_, 0, v___y_1371_);
v___x_1413_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1413_, 0, v___x_1411_);
lean_ctor_set(v___x_1413_, 1, v___x_1412_);
v___x_1414_ = ((lean_object*)(l_LearningWorker_kernelProfile___closed__7));
v___x_1415_ = l_Lean_Option_toJson___at___00Lean_Json_toStructured_x3f___at___00Lean_Server_FileWorker_sendServerRequest___at___00Lean_Server_FileWorker_runRefreshTasks_spec__0_spec__1_spec__3(v___y_1372_);
v___x_1416_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1416_, 0, v___x_1414_);
lean_ctor_set(v___x_1416_, 1, v___x_1415_);
v___x_1417_ = lean_box(0);
v___x_1418_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1418_, 0, v___x_1416_);
lean_ctor_set(v___x_1418_, 1, v___x_1417_);
v___x_1419_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1419_, 0, v___x_1413_);
lean_ctor_set(v___x_1419_, 1, v___x_1418_);
v___x_1420_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1420_, 0, v___x_1410_);
lean_ctor_set(v___x_1420_, 1, v___x_1419_);
v___x_1421_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1421_, 0, v___x_1403_);
lean_ctor_set(v___x_1421_, 1, v___x_1420_);
v___x_1422_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1422_, 0, v___x_1399_);
lean_ctor_set(v___x_1422_, 1, v___x_1421_);
v___x_1423_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1423_, 0, v___x_1394_);
lean_ctor_set(v___x_1423_, 1, v___x_1422_);
v___x_1424_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1424_, 0, v___x_1389_);
lean_ctor_set(v___x_1424_, 1, v___x_1423_);
v___x_1425_ = l_Lean_Json_mkObj(v___x_1424_);
lean_dec_ref_known(v___x_1424_, 2);
v___x_1426_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1426_, 0, v___x_1425_);
return v___x_1426_;
}
}
}
}
}
}
}
v___jp_1436_:
{
if (v___y_1437_ == 0)
{
lean_dec_ref(v_sorting_1369_);
lean_dec_ref(v_checks_1367_);
lean_dec_ref(v_result_1364_);
lean_dec(v_s_1363_);
lean_dec(v_xs_1357_);
lean_dec(v_id_1356_);
goto v___jp_1360_;
}
else
{
lean_object* v_ret_1438_; lean_object* v_time_1439_; uint8_t v___x_1440_; 
v_ret_1438_ = lean_ctor_get(v_sorting_1369_, 0);
lean_inc(v_ret_1438_);
v_time_1439_ = lean_ctor_get(v_sorting_1369_, 1);
lean_inc(v_time_1439_);
v___x_1440_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v_ret_1438_, v_expected_1358_);
lean_dec(v_ret_1438_);
if (v___x_1440_ == 0)
{
lean_dec(v_time_1439_);
lean_dec_ref(v_sorting_1369_);
lean_dec_ref(v_checks_1367_);
lean_dec_ref(v_result_1364_);
lean_dec(v_s_1363_);
lean_dec(v_xs_1357_);
lean_dec(v_id_1356_);
goto v___jp_1360_;
}
else
{
lean_object* v_time_1441_; lean_object* v_time_1442_; lean_object* v___x_1443_; uint8_t v___x_1444_; 
v_time_1441_ = lean_ctor_get(v_checks_1367_, 1);
lean_inc(v_time_1441_);
v_time_1442_ = lean_ctor_get(v_result_1364_, 1);
lean_inc(v_time_1442_);
v___x_1443_ = lean_nat_add(v_time_1441_, v_time_1439_);
lean_dec(v_time_1439_);
lean_dec(v_time_1441_);
v___x_1444_ = lean_nat_dec_eq(v___x_1443_, v_time_1442_);
lean_dec(v___x_1443_);
if (v___x_1444_ == 0)
{
lean_dec(v_time_1442_);
lean_dec_ref(v_sorting_1369_);
lean_dec_ref(v_checks_1367_);
lean_dec_ref(v_result_1364_);
lean_dec(v_s_1363_);
lean_dec(v_xs_1357_);
lean_dec(v_id_1356_);
goto v___jp_1360_;
}
else
{
lean_object* v___x_1445_; lean_object* v___x_1446_; lean_object* v___x_1447_; uint8_t v___x_1448_; 
lean_inc(v_id_1356_);
v___x_1445_ = lean_nat_to_int(v_id_1356_);
v___x_1446_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1446_, 0, v___x_1445_);
lean_inc(v_xs_1357_);
v___x_1447_ = l_LeanSort_LearnedSelection_kernelBound___at___00LearningWorker_kernelProfile_spec__2(v___x_1446_, v_xs_1357_);
lean_dec_ref_known(v___x_1446_, 1);
v___x_1448_ = lean_nat_dec_le(v_time_1442_, v___x_1447_);
lean_dec(v___x_1447_);
lean_dec(v_time_1442_);
if (v___x_1448_ == 0)
{
lean_dec_ref(v_sorting_1369_);
lean_dec_ref(v_checks_1367_);
lean_dec_ref(v_result_1364_);
lean_dec(v_s_1363_);
lean_dec(v_xs_1357_);
lean_dec(v_id_1356_);
goto v___jp_1360_;
}
else
{
if (lean_obj_tag(v_s_1363_) == 0)
{
lean_object* v_schema_1449_; lean_object* v___x_1451_; uint8_t v_isShared_1452_; uint8_t v_isSharedCheck_1463_; 
v_schema_1449_ = lean_ctor_get(v_s_1363_, 0);
v_isSharedCheck_1463_ = !lean_is_exclusive(v_s_1363_);
if (v_isSharedCheck_1463_ == 0)
{
v___x_1451_ = v_s_1363_;
v_isShared_1452_ = v_isSharedCheck_1463_;
goto v_resetjp_1450_;
}
else
{
lean_inc(v_schema_1449_);
lean_dec(v_s_1363_);
v___x_1451_ = lean_box(0);
v_isShared_1452_ = v_isSharedCheck_1463_;
goto v_resetjp_1450_;
}
v_resetjp_1450_:
{
uint8_t v___x_1453_; lean_object* v___x_1454_; lean_object* v___x_1455_; lean_object* v___x_1457_; 
lean_inc(v_xs_1357_);
v___x_1453_ = l_LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3(v_schema_1449_, v_xs_1357_);
v___x_1454_ = l_List_lengthTR___redArg(v_xs_1357_);
v___x_1455_ = lp_leansort_LeanSort_CostedPlan_Schema_readyUpper(v_schema_1449_, v___x_1454_);
lean_dec(v___x_1454_);
lean_dec_ref(v_schema_1449_);
lean_inc(v___x_1455_);
if (v_isShared_1452_ == 0)
{
lean_ctor_set_tag(v___x_1451_, 1);
lean_ctor_set(v___x_1451_, 0, v___x_1455_);
v___x_1457_ = v___x_1451_;
goto v_reusejp_1456_;
}
else
{
lean_object* v_reuseFailAlloc_1462_; 
v_reuseFailAlloc_1462_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1462_, 0, v___x_1455_);
v___x_1457_ = v_reuseFailAlloc_1462_;
goto v_reusejp_1456_;
}
v_reusejp_1456_:
{
if (v___x_1453_ == 0)
{
lean_dec(v___x_1455_);
v___y_1371_ = v___x_1453_;
v___y_1372_ = v___x_1457_;
goto v___jp_1370_;
}
else
{
lean_object* v_time_1458_; uint8_t v___x_1459_; 
v_time_1458_ = lean_ctor_get(v_result_1364_, 1);
lean_inc(v_time_1458_);
v___x_1459_ = lean_nat_dec_le(v_time_1458_, v___x_1455_);
lean_dec(v___x_1455_);
lean_dec(v_time_1458_);
if (v___x_1459_ == 0)
{
lean_object* v___x_1460_; lean_object* v___x_1461_; 
lean_dec_ref(v___x_1457_);
lean_dec_ref(v_sorting_1369_);
lean_dec_ref(v_checks_1367_);
lean_dec_ref(v_result_1364_);
lean_dec(v_xs_1357_);
lean_dec(v_id_1356_);
v___x_1460_ = ((lean_object*)(l_LearningWorker_kernelProfile___closed__9));
v___x_1461_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1461_, 0, v___x_1460_);
return v___x_1461_;
}
else
{
v___y_1371_ = v___x_1453_;
v___y_1372_ = v___x_1457_;
goto v___jp_1370_;
}
}
}
}
}
else
{
uint8_t v___x_1464_; lean_object* v___x_1465_; 
lean_dec(v_s_1363_);
v___x_1464_ = 0;
v___x_1465_ = lean_box(0);
v___y_1371_ = v___x_1464_;
v___y_1372_ = v___x_1465_;
goto v___jp_1370_;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_LearningWorker_kernelProfile___boxed(lean_object* v_id_1469_, lean_object* v_xs_1470_, lean_object* v_expected_1471_, lean_object* v_a_1472_){
_start:
{
lean_object* v_res_1473_; 
v_res_1473_ = l_LearningWorker_kernelProfile(v_id_1469_, v_xs_1470_, v_expected_1471_);
lean_dec(v_expected_1471_);
return v_res_1473_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0(lean_object* v_s_1474_, lean_object* v_xs_1475_){
_start:
{
lean_object* v___x_1476_; 
v___x_1476_ = l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runCounted___at___00LearningWorker_kernelProfile_spec__0_spec__0(v_s_1474_, v_xs_1475_);
return v___x_1476_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1(uint8_t v_phase_1477_, lean_object* v_s_1478_, lean_object* v_xs_1479_){
_start:
{
lean_object* v___x_1480_; 
v___x_1480_ = l_LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1_spec__3(v_phase_1477_, v_s_1478_, v_xs_1479_);
return v___x_1480_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1___boxed(lean_object* v_phase_1481_, lean_object* v_s_1482_, lean_object* v_xs_1483_){
_start:
{
uint8_t v_phase_boxed_1484_; lean_object* v_res_1485_; 
v_phase_boxed_1484_ = lean_unbox(v_phase_1481_);
v_res_1485_ = l_LeanSort_Direct_runPhase___at___00LearningWorker_kernelProfile_spec__1(v_phase_boxed_1484_, v_s_1482_, v_xs_1483_);
return v_res_1485_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3_spec__7(lean_object* v_00_u03b2_1486_, lean_object* v_x_1487_){
_start:
{
lean_object* v___x_1488_; 
v___x_1488_ = l_LeanSort_Comparison_Program_eval___at___00LeanSort_CostedPlan_Schema_readyCheck___at___00LearningWorker_kernelProfile_spec__3_spec__7___redArg(v_x_1487_);
return v___x_1488_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_scan___at___00LeanSort_Direct_diagnosticBound___at___00LeanSort_LearnedSelection_kernelBound___at___00LearningWorker_kernelProfile_spec__2_spec__5_spec__12(lean_object* v_xs_1489_){
_start:
{
lean_object* v___x_1490_; 
v___x_1490_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_run___at___00LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0_spec__0_spec__1_spec__3_spec__7(v_xs_1489_);
return v___x_1490_;
}
}
LEAN_EXPORT lean_object* l_Lean_Option_toJson___at___00LearningWorker_bench_spec__9(lean_object* v_x_1491_){
_start:
{
if (lean_obj_tag(v_x_1491_) == 0)
{
lean_object* v___x_1492_; 
v___x_1492_ = lean_box(0);
return v___x_1492_;
}
else
{
lean_object* v_val_1493_; lean_object* v___x_1495_; uint8_t v_isShared_1496_; uint8_t v_isSharedCheck_1501_; 
v_val_1493_ = lean_ctor_get(v_x_1491_, 0);
v_isSharedCheck_1501_ = !lean_is_exclusive(v_x_1491_);
if (v_isSharedCheck_1501_ == 0)
{
v___x_1495_ = v_x_1491_;
v_isShared_1496_ = v_isSharedCheck_1501_;
goto v_resetjp_1494_;
}
else
{
lean_inc(v_val_1493_);
lean_dec(v_x_1491_);
v___x_1495_ = lean_box(0);
v_isShared_1496_ = v_isSharedCheck_1501_;
goto v_resetjp_1494_;
}
v_resetjp_1494_:
{
lean_object* v___x_1497_; lean_object* v___x_1499_; 
v___x_1497_ = l_Lean_JsonNumber_fromInt(v_val_1493_);
if (v_isShared_1496_ == 0)
{
lean_ctor_set_tag(v___x_1495_, 2);
lean_ctor_set(v___x_1495_, 0, v___x_1497_);
v___x_1499_ = v___x_1495_;
goto v_reusejp_1498_;
}
else
{
lean_object* v_reuseFailAlloc_1500_; 
v_reuseFailAlloc_1500_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1500_, 0, v___x_1497_);
v___x_1499_ = v_reuseFailAlloc_1500_;
goto v_reusejp_1498_;
}
v_reusejp_1498_:
{
return v___x_1499_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00Lean_Option_toJson___at___00LearningWorker_bench_spec__10_spec__11(lean_object* v_a_1502_){
_start:
{
lean_object* v___x_1503_; lean_object* v___x_1504_; 
v___x_1503_ = lean_array_mk(v_a_1502_);
v___x_1504_ = l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonFuncTable_toJson_spec__0(v___x_1503_);
return v___x_1504_;
}
}
LEAN_EXPORT lean_object* l_Lean_Option_toJson___at___00LearningWorker_bench_spec__10(lean_object* v_x_1505_){
_start:
{
if (lean_obj_tag(v_x_1505_) == 0)
{
lean_object* v___x_1506_; 
v___x_1506_ = lean_box(0);
return v___x_1506_;
}
else
{
lean_object* v_val_1507_; lean_object* v___x_1508_; 
v_val_1507_ = lean_ctor_get(v_x_1505_, 0);
lean_inc(v_val_1507_);
lean_dec_ref_known(v_x_1505_, 1);
v___x_1508_ = l_Lean_List_toJson___at___00Lean_Option_toJson___at___00LearningWorker_bench_spec__10_spec__11(v_val_1507_);
return v___x_1508_;
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00LearningWorker_bench_spec__14(lean_object* v___x_1511_, lean_object* v_a_1512_, lean_object* v_a_1513_){
_start:
{
if (lean_obj_tag(v_a_1512_) == 0)
{
lean_object* v___x_1514_; 
v___x_1514_ = l_List_reverse___redArg(v_a_1513_);
return v___x_1514_;
}
else
{
lean_object* v_head_1515_; lean_object* v_tail_1516_; lean_object* v___x_1518_; uint8_t v_isShared_1519_; uint8_t v_isSharedCheck_1567_; 
v_head_1515_ = lean_ctor_get(v_a_1512_, 0);
v_tail_1516_ = lean_ctor_get(v_a_1512_, 1);
v_isSharedCheck_1567_ = !lean_is_exclusive(v_a_1512_);
if (v_isSharedCheck_1567_ == 0)
{
v___x_1518_ = v_a_1512_;
v_isShared_1519_ = v_isSharedCheck_1567_;
goto v_resetjp_1517_;
}
else
{
lean_inc(v_tail_1516_);
lean_inc(v_head_1515_);
lean_dec(v_a_1512_);
v___x_1518_ = lean_box(0);
v_isShared_1519_ = v_isSharedCheck_1567_;
goto v_resetjp_1517_;
}
v_resetjp_1517_:
{
lean_object* v_fst_1520_; lean_object* v_snd_1521_; lean_object* v___x_1523_; uint8_t v_isShared_1524_; uint8_t v_isSharedCheck_1566_; 
v_fst_1520_ = lean_ctor_get(v_head_1515_, 0);
v_snd_1521_ = lean_ctor_get(v_head_1515_, 1);
v_isSharedCheck_1566_ = !lean_is_exclusive(v_head_1515_);
if (v_isSharedCheck_1566_ == 0)
{
v___x_1523_ = v_head_1515_;
v_isShared_1524_ = v_isSharedCheck_1566_;
goto v_resetjp_1522_;
}
else
{
lean_inc(v_snd_1521_);
lean_inc(v_fst_1520_);
lean_dec(v_head_1515_);
v___x_1523_ = lean_box(0);
v_isShared_1524_ = v_isSharedCheck_1566_;
goto v_resetjp_1522_;
}
v_resetjp_1522_:
{
lean_object* v___x_1525_; lean_object* v___x_1526_; lean_object* v___x_1528_; 
v___x_1525_ = ((lean_object*)(l_LearningWorker_sampleEvent___closed__5));
v___x_1526_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_1526_, 0, v_fst_1520_);
if (v_isShared_1524_ == 0)
{
lean_ctor_set(v___x_1523_, 1, v___x_1526_);
lean_ctor_set(v___x_1523_, 0, v___x_1525_);
v___x_1528_ = v___x_1523_;
goto v_reusejp_1527_;
}
else
{
lean_object* v_reuseFailAlloc_1565_; 
v_reuseFailAlloc_1565_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1565_, 0, v___x_1525_);
lean_ctor_set(v_reuseFailAlloc_1565_, 1, v___x_1526_);
v___x_1528_ = v_reuseFailAlloc_1565_;
goto v_reusejp_1527_;
}
v_reusejp_1527_:
{
lean_object* v___x_1529_; lean_object* v___x_1530_; lean_object* v___x_1531_; lean_object* v___x_1532_; lean_object* v___x_1533_; lean_object* v___x_1534_; lean_object* v___x_1535_; lean_object* v___x_1536_; lean_object* v___x_1537_; lean_object* v___x_1538_; uint8_t v___x_1539_; lean_object* v___x_1540_; lean_object* v___x_1541_; lean_object* v___x_1542_; lean_object* v___y_1544_; 
v___x_1529_ = ((lean_object*)(l_List_mapTR_loop___at___00LearningWorker_bench_spec__14___closed__0));
lean_inc(v_snd_1521_);
v___x_1530_ = l_LearningWorker_featureSelect(v_snd_1521_, v___x_1511_);
lean_inc(v___x_1530_);
v___x_1531_ = l_Lean_Option_toJson___at___00LearningWorker_bench_spec__9(v___x_1530_);
v___x_1532_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1532_, 0, v___x_1529_);
lean_ctor_set(v___x_1532_, 1, v___x_1531_);
v___x_1533_ = ((lean_object*)(l_LearningWorker_sampleEvent___closed__8));
v___x_1534_ = l_LeanSort_LearnedSelection_resolve(v___x_1530_);
lean_dec(v___x_1530_);
v___x_1535_ = l_Lean_JsonNumber_fromNat(v___x_1534_);
v___x_1536_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_1536_, 0, v___x_1535_);
v___x_1537_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1537_, 0, v___x_1533_);
lean_ctor_set(v___x_1537_, 1, v___x_1536_);
v___x_1538_ = ((lean_object*)(l_List_mapTR_loop___at___00LearningWorker_bench_spec__14___closed__1));
v___x_1539_ = l_LearningWorker_usesFeatures(v_snd_1521_);
v___x_1540_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_1540_, 0, v___x_1539_);
v___x_1541_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1541_, 0, v___x_1538_);
lean_ctor_set(v___x_1541_, 1, v___x_1540_);
v___x_1542_ = ((lean_object*)(l_LearningWorker_decodeTree___closed__11));
if (lean_obj_tag(v_snd_1521_) == 3)
{
lean_object* v_model_1558_; 
v_model_1558_ = lean_ctor_get(v_snd_1521_, 0);
lean_inc(v_model_1558_);
lean_dec_ref_known(v_snd_1521_, 1);
switch(lean_obj_tag(v_model_1558_))
{
case 1:
{
lean_object* v_tree_1559_; lean_object* v___x_1560_; 
v_tree_1559_ = lean_ctor_get(v_model_1558_, 0);
lean_inc_ref(v_tree_1559_);
lean_dec_ref_known(v_model_1558_, 1);
v___x_1560_ = l_LeanSort_LearnedSelection_Tree_eval(v_tree_1559_, v___x_1511_);
v___y_1544_ = v___x_1560_;
goto v___jp_1543_;
}
case 2:
{
lean_object* v_tree_1561_; lean_object* v___x_1562_; 
v_tree_1561_ = lean_ctor_get(v_model_1558_, 0);
lean_inc_ref(v_tree_1561_);
lean_dec_ref_known(v_model_1558_, 1);
v___x_1562_ = l_LeanSort_LearnedSelection_Tree_eval(v_tree_1561_, v___x_1511_);
v___y_1544_ = v___x_1562_;
goto v___jp_1543_;
}
default: 
{
lean_object* v___x_1563_; 
lean_dec(v_model_1558_);
v___x_1563_ = lean_box(0);
v___y_1544_ = v___x_1563_;
goto v___jp_1543_;
}
}
}
else
{
lean_object* v___x_1564_; 
lean_dec(v_snd_1521_);
v___x_1564_ = lean_box(0);
v___y_1544_ = v___x_1564_;
goto v___jp_1543_;
}
v___jp_1543_:
{
lean_object* v___x_1545_; lean_object* v___x_1546_; lean_object* v___x_1547_; lean_object* v___x_1549_; 
v___x_1545_ = l_Lean_Option_toJson___at___00LearningWorker_bench_spec__10(v___y_1544_);
v___x_1546_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1546_, 0, v___x_1542_);
lean_ctor_set(v___x_1546_, 1, v___x_1545_);
v___x_1547_ = lean_box(0);
if (v_isShared_1519_ == 0)
{
lean_ctor_set(v___x_1518_, 1, v___x_1547_);
lean_ctor_set(v___x_1518_, 0, v___x_1546_);
v___x_1549_ = v___x_1518_;
goto v_reusejp_1548_;
}
else
{
lean_object* v_reuseFailAlloc_1557_; 
v_reuseFailAlloc_1557_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1557_, 0, v___x_1546_);
lean_ctor_set(v_reuseFailAlloc_1557_, 1, v___x_1547_);
v___x_1549_ = v_reuseFailAlloc_1557_;
goto v_reusejp_1548_;
}
v_reusejp_1548_:
{
lean_object* v___x_1550_; lean_object* v___x_1551_; lean_object* v___x_1552_; lean_object* v___x_1553_; lean_object* v___x_1554_; lean_object* v___x_1555_; 
v___x_1550_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1550_, 0, v___x_1541_);
lean_ctor_set(v___x_1550_, 1, v___x_1549_);
v___x_1551_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1551_, 0, v___x_1537_);
lean_ctor_set(v___x_1551_, 1, v___x_1550_);
v___x_1552_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1552_, 0, v___x_1532_);
lean_ctor_set(v___x_1552_, 1, v___x_1551_);
v___x_1553_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1553_, 0, v___x_1528_);
lean_ctor_set(v___x_1553_, 1, v___x_1552_);
v___x_1554_ = l_Lean_Json_mkObj(v___x_1553_);
lean_dec_ref_known(v___x_1553_, 2);
v___x_1555_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1555_, 0, v___x_1554_);
lean_ctor_set(v___x_1555_, 1, v_a_1513_);
v_a_1512_ = v_tail_1516_;
v_a_1513_ = v___x_1555_;
goto _start;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00LearningWorker_bench_spec__14___boxed(lean_object* v___x_1568_, lean_object* v_a_1569_, lean_object* v_a_1570_){
_start:
{
lean_object* v_res_1571_; 
v_res_1571_ = l_List_mapTR_loop___at___00LearningWorker_bench_spec__14(v___x_1568_, v_a_1569_, v_a_1570_);
lean_dec(v___x_1568_);
return v_res_1571_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00LearningWorker_bench_spec__16(lean_object* v_a_1572_, lean_object* v_a_1573_){
_start:
{
if (lean_obj_tag(v_a_1572_) == 0)
{
lean_object* v___x_1574_; 
v___x_1574_ = l_List_reverse___redArg(v_a_1573_);
return v___x_1574_;
}
else
{
lean_object* v_head_1575_; lean_object* v_tail_1576_; lean_object* v___x_1578_; uint8_t v_isShared_1579_; uint8_t v_isSharedCheck_1585_; 
v_head_1575_ = lean_ctor_get(v_a_1572_, 0);
v_tail_1576_ = lean_ctor_get(v_a_1572_, 1);
v_isSharedCheck_1585_ = !lean_is_exclusive(v_a_1572_);
if (v_isSharedCheck_1585_ == 0)
{
v___x_1578_ = v_a_1572_;
v_isShared_1579_ = v_isSharedCheck_1585_;
goto v_resetjp_1577_;
}
else
{
lean_inc(v_tail_1576_);
lean_inc(v_head_1575_);
lean_dec(v_a_1572_);
v___x_1578_ = lean_box(0);
v_isShared_1579_ = v_isSharedCheck_1585_;
goto v_resetjp_1577_;
}
v_resetjp_1577_:
{
lean_object* v___x_1580_; lean_object* v___x_1582_; 
v___x_1580_ = l_List_lengthTR___redArg(v_head_1575_);
lean_dec(v_head_1575_);
if (v_isShared_1579_ == 0)
{
lean_ctor_set(v___x_1578_, 1, v_a_1573_);
lean_ctor_set(v___x_1578_, 0, v___x_1580_);
v___x_1582_ = v___x_1578_;
goto v_reusejp_1581_;
}
else
{
lean_object* v_reuseFailAlloc_1584_; 
v_reuseFailAlloc_1584_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1584_, 0, v___x_1580_);
lean_ctor_set(v_reuseFailAlloc_1584_, 1, v_a_1573_);
v___x_1582_ = v_reuseFailAlloc_1584_;
goto v_reusejp_1581_;
}
v_reusejp_1581_:
{
v_a_1572_ = v_tail_1576_;
v_a_1573_ = v___x_1582_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11___redArg(lean_object* v_val_1587_, lean_object* v_val_1588_, lean_object* v_a_1589_, lean_object* v___x_1590_, lean_object* v_as_x27_1591_, lean_object* v_b_1592_){
_start:
{
if (lean_obj_tag(v_as_x27_1591_) == 0)
{
lean_object* v___x_1594_; 
lean_dec(v_a_1589_);
v___x_1594_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1594_, 0, v_b_1592_);
return v___x_1594_;
}
else
{
lean_object* v_head_1595_; lean_object* v_tail_1596_; lean_object* v_fst_1597_; lean_object* v_snd_1598_; lean_object* v___x_1599_; lean_object* v_a_1600_; lean_object* v___x_1601_; lean_object* v___x_1602_; lean_object* v___x_1603_; lean_object* v___x_1604_; lean_object* v___x_1605_; 
v_head_1595_ = lean_ctor_get(v_as_x27_1591_, 0);
v_tail_1596_ = lean_ctor_get(v_as_x27_1591_, 1);
v_fst_1597_ = lean_ctor_get(v_head_1595_, 0);
v_snd_1598_ = lean_ctor_get(v_head_1595_, 1);
lean_inc_n(v_snd_1598_, 2);
v___x_1599_ = l_LearningWorker_timedDecision(v_snd_1598_, v_val_1587_, v_val_1588_);
v_a_1600_ = lean_ctor_get(v___x_1599_, 0);
lean_inc(v_a_1600_);
lean_dec_ref(v___x_1599_);
v___x_1601_ = ((lean_object*)(l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11___redArg___closed__0));
lean_inc(v_a_1589_);
v___x_1602_ = lean_nat_to_int(v_a_1589_);
v___x_1603_ = l_LearningWorker_featureSelect(v_snd_1598_, v___x_1590_);
v___x_1604_ = l_LeanSort_LearnedSelection_resolve(v___x_1603_);
lean_dec(v___x_1603_);
lean_inc(v_fst_1597_);
v___x_1605_ = l_LearningWorker_sampleEvent(v___x_1601_, v_fst_1597_, v___x_1602_, v_a_1600_, v___x_1604_);
if (lean_obj_tag(v___x_1605_) == 0)
{
lean_object* v___x_1606_; 
lean_dec_ref_known(v___x_1605_, 1);
v___x_1606_ = lean_box(0);
v_as_x27_1591_ = v_tail_1596_;
v_b_1592_ = v___x_1606_;
goto _start;
}
else
{
lean_dec(v_a_1589_);
return v___x_1605_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11___redArg___boxed(lean_object* v_val_1608_, lean_object* v_val_1609_, lean_object* v_a_1610_, lean_object* v___x_1611_, lean_object* v_as_x27_1612_, lean_object* v_b_1613_, lean_object* v___y_1614_){
_start:
{
lean_object* v_res_1615_; 
v_res_1615_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11___redArg(v_val_1608_, v_val_1609_, v_a_1610_, v___x_1611_, v_as_x27_1612_, v_b_1613_);
lean_dec(v_as_x27_1612_);
lean_dec(v___x_1611_);
lean_dec(v_val_1609_);
lean_dec(v_val_1608_);
return v_res_1615_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__12___redArg(lean_object* v_val_1616_, lean_object* v_val_1617_, lean_object* v___x_1618_, lean_object* v_a_1619_, lean_object* v_as_x27_1620_, lean_object* v_b_1621_){
_start:
{
if (lean_obj_tag(v_as_x27_1620_) == 0)
{
lean_object* v___x_1623_; 
v___x_1623_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1623_, 0, v_b_1621_);
return v___x_1623_;
}
else
{
lean_object* v_head_1624_; lean_object* v_tail_1625_; lean_object* v___x_1626_; lean_object* v___x_1627_; 
v_head_1624_ = lean_ctor_get(v_as_x27_1620_, 0);
v_tail_1625_ = lean_ctor_get(v_as_x27_1620_, 1);
v___x_1626_ = lean_box(0);
lean_inc(v_head_1624_);
v___x_1627_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11___redArg(v_val_1616_, v_val_1617_, v_head_1624_, v___x_1618_, v_a_1619_, v___x_1626_);
if (lean_obj_tag(v___x_1627_) == 0)
{
lean_dec_ref_known(v___x_1627_, 1);
v_as_x27_1620_ = v_tail_1625_;
v_b_1621_ = v___x_1626_;
goto _start;
}
else
{
return v___x_1627_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__12___redArg___boxed(lean_object* v_val_1629_, lean_object* v_val_1630_, lean_object* v___x_1631_, lean_object* v_a_1632_, lean_object* v_as_x27_1633_, lean_object* v_b_1634_, lean_object* v___y_1635_){
_start:
{
lean_object* v_res_1636_; 
v_res_1636_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__12___redArg(v_val_1629_, v_val_1630_, v___x_1631_, v_a_1632_, v_as_x27_1633_, v_b_1634_);
lean_dec(v_as_x27_1633_);
lean_dec(v_a_1632_);
lean_dec(v___x_1631_);
lean_dec(v_val_1630_);
lean_dec(v_val_1629_);
return v_res_1636_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00LearningWorker_bench_spec__1_spec__1(lean_object* v_j_1637_){
_start:
{
lean_object* v___x_1638_; 
v___x_1638_ = l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonStackTable_fromJson_spec__0_spec__0(v_j_1637_);
if (lean_obj_tag(v___x_1638_) == 0)
{
lean_object* v_a_1639_; lean_object* v___x_1641_; uint8_t v_isShared_1642_; uint8_t v_isSharedCheck_1646_; 
v_a_1639_ = lean_ctor_get(v___x_1638_, 0);
v_isSharedCheck_1646_ = !lean_is_exclusive(v___x_1638_);
if (v_isSharedCheck_1646_ == 0)
{
v___x_1641_ = v___x_1638_;
v_isShared_1642_ = v_isSharedCheck_1646_;
goto v_resetjp_1640_;
}
else
{
lean_inc(v_a_1639_);
lean_dec(v___x_1638_);
v___x_1641_ = lean_box(0);
v_isShared_1642_ = v_isSharedCheck_1646_;
goto v_resetjp_1640_;
}
v_resetjp_1640_:
{
lean_object* v___x_1644_; 
if (v_isShared_1642_ == 0)
{
v___x_1644_ = v___x_1641_;
goto v_reusejp_1643_;
}
else
{
lean_object* v_reuseFailAlloc_1645_; 
v_reuseFailAlloc_1645_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1645_, 0, v_a_1639_);
v___x_1644_ = v_reuseFailAlloc_1645_;
goto v_reusejp_1643_;
}
v_reusejp_1643_:
{
return v___x_1644_;
}
}
}
else
{
lean_object* v_a_1647_; lean_object* v___x_1649_; uint8_t v_isShared_1650_; uint8_t v_isSharedCheck_1655_; 
v_a_1647_ = lean_ctor_get(v___x_1638_, 0);
v_isSharedCheck_1655_ = !lean_is_exclusive(v___x_1638_);
if (v_isSharedCheck_1655_ == 0)
{
v___x_1649_ = v___x_1638_;
v_isShared_1650_ = v_isSharedCheck_1655_;
goto v_resetjp_1648_;
}
else
{
lean_inc(v_a_1647_);
lean_dec(v___x_1638_);
v___x_1649_ = lean_box(0);
v_isShared_1650_ = v_isSharedCheck_1655_;
goto v_resetjp_1648_;
}
v_resetjp_1648_:
{
lean_object* v___x_1651_; lean_object* v___x_1653_; 
v___x_1651_ = lean_array_to_list(v_a_1647_);
if (v_isShared_1650_ == 0)
{
lean_ctor_set(v___x_1649_, 0, v___x_1651_);
v___x_1653_ = v___x_1649_;
goto v_reusejp_1652_;
}
else
{
lean_object* v_reuseFailAlloc_1654_; 
v_reuseFailAlloc_1654_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1654_, 0, v___x_1651_);
v___x_1653_ = v_reuseFailAlloc_1654_;
goto v_reusejp_1652_;
}
v_reusejp_1652_:
{
return v___x_1653_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_bench_spec__1(lean_object* v_j_1656_, lean_object* v_k_1657_){
_start:
{
lean_object* v___x_1658_; lean_object* v___x_1659_; 
v___x_1658_ = l_Lean_Json_getObjValD(v_j_1656_, v_k_1657_);
v___x_1659_ = l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00LearningWorker_bench_spec__1_spec__1(v___x_1658_);
return v___x_1659_;
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_bench_spec__1___boxed(lean_object* v_j_1660_, lean_object* v_k_1661_){
_start:
{
lean_object* v_res_1662_; 
v_res_1662_ = l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_bench_spec__1(v_j_1660_, v_k_1661_);
lean_dec_ref(v_k_1661_);
return v_res_1662_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00LearningWorker_bench_spec__6(lean_object* v_a_1664_, lean_object* v_a_1665_){
_start:
{
if (lean_obj_tag(v_a_1664_) == 0)
{
lean_object* v___x_1666_; 
v___x_1666_ = l_List_reverse___redArg(v_a_1665_);
return v___x_1666_;
}
else
{
lean_object* v_head_1667_; lean_object* v_tail_1668_; lean_object* v___x_1670_; uint8_t v_isShared_1671_; uint8_t v_isSharedCheck_1678_; 
v_head_1667_ = lean_ctor_get(v_a_1664_, 0);
v_tail_1668_ = lean_ctor_get(v_a_1664_, 1);
v_isSharedCheck_1678_ = !lean_is_exclusive(v_a_1664_);
if (v_isSharedCheck_1678_ == 0)
{
v___x_1670_ = v_a_1664_;
v_isShared_1671_ = v_isSharedCheck_1678_;
goto v_resetjp_1669_;
}
else
{
lean_inc(v_tail_1668_);
lean_inc(v_head_1667_);
lean_dec(v_a_1664_);
v___x_1670_ = lean_box(0);
v_isShared_1671_ = v_isSharedCheck_1678_;
goto v_resetjp_1669_;
}
v_resetjp_1669_:
{
lean_object* v___x_1672_; lean_object* v___x_1673_; lean_object* v___x_1675_; 
v___x_1672_ = ((lean_object*)(l_List_mapTR_loop___at___00LearningWorker_bench_spec__6___closed__0));
v___x_1673_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1673_, 0, v___x_1672_);
lean_ctor_set(v___x_1673_, 1, v_head_1667_);
if (v_isShared_1671_ == 0)
{
lean_ctor_set(v___x_1670_, 1, v_a_1665_);
lean_ctor_set(v___x_1670_, 0, v___x_1673_);
v___x_1675_ = v___x_1670_;
goto v_reusejp_1674_;
}
else
{
lean_object* v_reuseFailAlloc_1677_; 
v_reuseFailAlloc_1677_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1677_, 0, v___x_1673_);
lean_ctor_set(v_reuseFailAlloc_1677_, 1, v_a_1665_);
v___x_1675_ = v_reuseFailAlloc_1677_;
goto v_reusejp_1674_;
}
v_reusejp_1674_:
{
v_a_1664_ = v_tail_1668_;
v_a_1665_ = v___x_1675_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7___redArg(lean_object* v_a_1680_, lean_object* v_val_1681_, lean_object* v_val_1682_, lean_object* v_val_1683_, lean_object* v_a_1684_, lean_object* v_as_x27_1685_, lean_object* v_b_1686_){
_start:
{
if (lean_obj_tag(v_as_x27_1685_) == 0)
{
lean_object* v___x_1688_; 
lean_dec(v_a_1680_);
v___x_1688_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1688_, 0, v_b_1686_);
return v___x_1688_;
}
else
{
lean_object* v_head_1689_; lean_object* v_snd_1690_; lean_object* v_tail_1691_; lean_object* v_fst_1692_; lean_object* v_fst_1693_; lean_object* v_snd_1694_; lean_object* v___x_1695_; lean_object* v_____x_1697_; lean_object* v___x_1703_; uint8_t v___x_1704_; 
v_head_1689_ = lean_ctor_get(v_as_x27_1685_, 0);
v_snd_1690_ = lean_ctor_get(v_head_1689_, 1);
v_tail_1691_ = lean_ctor_get(v_as_x27_1685_, 1);
v_fst_1692_ = lean_ctor_get(v_head_1689_, 0);
v_fst_1693_ = lean_ctor_get(v_snd_1690_, 0);
v_snd_1694_ = lean_ctor_get(v_snd_1690_, 1);
v___x_1695_ = lean_box(0);
v___x_1703_ = ((lean_object*)(l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7___redArg___closed__0));
v___x_1704_ = lean_string_dec_eq(v_fst_1692_, v___x_1703_);
if (v___x_1704_ == 0)
{
lean_object* v___x_1705_; 
lean_inc(v_snd_1694_);
v___x_1705_ = l_LearningWorker_timedPolicy(v_snd_1694_, v_val_1681_, v_val_1682_, v_val_1683_, v_a_1684_);
if (lean_obj_tag(v___x_1705_) == 0)
{
lean_object* v_a_1706_; 
v_a_1706_ = lean_ctor_get(v___x_1705_, 0);
lean_inc(v_a_1706_);
lean_dec_ref_known(v___x_1705_, 1);
v_____x_1697_ = v_a_1706_;
goto v___jp_1696_;
}
else
{
lean_object* v_a_1707_; lean_object* v___x_1709_; uint8_t v_isShared_1710_; uint8_t v_isSharedCheck_1714_; 
lean_dec(v_a_1680_);
v_a_1707_ = lean_ctor_get(v___x_1705_, 0);
v_isSharedCheck_1714_ = !lean_is_exclusive(v___x_1705_);
if (v_isSharedCheck_1714_ == 0)
{
v___x_1709_ = v___x_1705_;
v_isShared_1710_ = v_isSharedCheck_1714_;
goto v_resetjp_1708_;
}
else
{
lean_inc(v_a_1707_);
lean_dec(v___x_1705_);
v___x_1709_ = lean_box(0);
v_isShared_1710_ = v_isSharedCheck_1714_;
goto v_resetjp_1708_;
}
v_resetjp_1708_:
{
lean_object* v___x_1712_; 
if (v_isShared_1710_ == 0)
{
v___x_1712_ = v___x_1709_;
goto v_reusejp_1711_;
}
else
{
lean_object* v_reuseFailAlloc_1713_; 
v_reuseFailAlloc_1713_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1713_, 0, v_a_1707_);
v___x_1712_ = v_reuseFailAlloc_1713_;
goto v_reusejp_1711_;
}
v_reusejp_1711_:
{
return v___x_1712_;
}
}
}
}
else
{
lean_object* v___x_1715_; lean_object* v___x_1716_; lean_object* v___x_1717_; lean_object* v___x_1718_; 
v___x_1715_ = lean_box(0);
lean_inc(v_snd_1694_);
v___x_1716_ = l_LearningWorker_featureSelect(v_snd_1694_, v___x_1715_);
v___x_1717_ = l_LeanSort_LearnedSelection_resolve(v___x_1716_);
lean_dec(v___x_1716_);
v___x_1718_ = l_LearningWorker_timedKernel(v___x_1717_, v_val_1681_, v_val_1682_, v_val_1683_, v_a_1684_);
if (lean_obj_tag(v___x_1718_) == 0)
{
lean_object* v_a_1719_; 
v_a_1719_ = lean_ctor_get(v___x_1718_, 0);
lean_inc(v_a_1719_);
lean_dec_ref_known(v___x_1718_, 1);
v_____x_1697_ = v_a_1719_;
goto v___jp_1696_;
}
else
{
lean_object* v_a_1720_; lean_object* v___x_1722_; uint8_t v_isShared_1723_; uint8_t v_isSharedCheck_1727_; 
lean_dec(v_a_1680_);
v_a_1720_ = lean_ctor_get(v___x_1718_, 0);
v_isSharedCheck_1727_ = !lean_is_exclusive(v___x_1718_);
if (v_isSharedCheck_1727_ == 0)
{
v___x_1722_ = v___x_1718_;
v_isShared_1723_ = v_isSharedCheck_1727_;
goto v_resetjp_1721_;
}
else
{
lean_inc(v_a_1720_);
lean_dec(v___x_1718_);
v___x_1722_ = lean_box(0);
v_isShared_1723_ = v_isSharedCheck_1727_;
goto v_resetjp_1721_;
}
v_resetjp_1721_:
{
lean_object* v___x_1725_; 
if (v_isShared_1723_ == 0)
{
v___x_1725_ = v___x_1722_;
goto v_reusejp_1724_;
}
else
{
lean_object* v_reuseFailAlloc_1726_; 
v_reuseFailAlloc_1726_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1726_, 0, v_a_1720_);
v___x_1725_ = v_reuseFailAlloc_1726_;
goto v_reusejp_1724_;
}
v_reusejp_1724_:
{
return v___x_1725_;
}
}
}
}
v___jp_1696_:
{
lean_object* v_fst_1698_; lean_object* v_snd_1699_; lean_object* v___x_1700_; lean_object* v___x_1701_; 
v_fst_1698_ = lean_ctor_get(v_____x_1697_, 0);
lean_inc(v_fst_1698_);
v_snd_1699_ = lean_ctor_get(v_____x_1697_, 1);
lean_inc(v_snd_1699_);
lean_dec_ref(v_____x_1697_);
lean_inc(v_a_1680_);
v___x_1700_ = lean_nat_to_int(v_a_1680_);
lean_inc(v_fst_1693_);
lean_inc(v_fst_1692_);
v___x_1701_ = l_LearningWorker_sampleEvent(v_fst_1692_, v_fst_1693_, v___x_1700_, v_fst_1698_, v_snd_1699_);
if (lean_obj_tag(v___x_1701_) == 0)
{
lean_dec_ref_known(v___x_1701_, 1);
v_as_x27_1685_ = v_tail_1691_;
v_b_1686_ = v___x_1695_;
goto _start;
}
else
{
lean_dec(v_a_1680_);
return v___x_1701_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7___redArg___boxed(lean_object* v_a_1728_, lean_object* v_val_1729_, lean_object* v_val_1730_, lean_object* v_val_1731_, lean_object* v_a_1732_, lean_object* v_as_x27_1733_, lean_object* v_b_1734_, lean_object* v___y_1735_){
_start:
{
lean_object* v_res_1736_; 
v_res_1736_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7___redArg(v_a_1728_, v_val_1729_, v_val_1730_, v_val_1731_, v_a_1732_, v_as_x27_1733_, v_b_1734_);
lean_dec(v_as_x27_1733_);
lean_dec(v_a_1732_);
lean_dec(v_val_1731_);
lean_dec(v_val_1730_);
lean_dec(v_val_1729_);
return v_res_1736_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg(lean_object* v_val_1740_, lean_object* v_val_1741_, lean_object* v_val_1742_, lean_object* v_a_1743_, lean_object* v_a_1744_, lean_object* v___x_1745_, lean_object* v_as_x27_1746_, lean_object* v_b_1747_){
_start:
{
if (lean_obj_tag(v_as_x27_1746_) == 0)
{
lean_object* v___x_1749_; 
lean_dec(v___x_1745_);
v___x_1749_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1749_, 0, v_b_1747_);
return v___x_1749_;
}
else
{
lean_object* v_head_1750_; lean_object* v_tail_1751_; lean_object* v___x_1752_; lean_object* v___x_1753_; lean_object* v___y_1755_; lean_object* v___x_1763_; lean_object* v___x_1764_; lean_object* v___x_1765_; lean_object* v___x_1766_; lean_object* v___x_1767_; lean_object* v___x_1768_; lean_object* v___x_1769_; lean_object* v___x_1770_; lean_object* v___x_1771_; uint8_t v___x_1772_; 
v_head_1750_ = lean_ctor_get(v_as_x27_1746_, 0);
v_tail_1751_ = lean_ctor_get(v_as_x27_1746_, 1);
v___x_1752_ = lean_box(0);
v___x_1753_ = lean_unsigned_to_nat(0u);
v___x_1763_ = lean_nat_add(v_a_1744_, v_head_1750_);
v___x_1764_ = l_List_lengthTR___redArg(v___x_1745_);
v___x_1765_ = lean_nat_mod(v___x_1763_, v___x_1764_);
lean_dec(v___x_1764_);
lean_dec(v___x_1763_);
lean_inc(v___x_1765_);
v___x_1766_ = l_List_drop___redArg(v___x_1765_, v___x_1745_);
v___x_1767_ = ((lean_object*)(l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg___closed__1));
lean_inc(v___x_1745_);
v___x_1768_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v___x_1745_, v___x_1745_, v___x_1765_, v___x_1767_);
v___x_1769_ = l_List_appendTR___redArg(v___x_1766_, v___x_1768_);
v___x_1770_ = lean_unsigned_to_nat(2u);
v___x_1771_ = lean_nat_mod(v_head_1750_, v___x_1770_);
v___x_1772_ = lean_nat_dec_eq(v___x_1771_, v___x_1753_);
lean_dec(v___x_1771_);
if (v___x_1772_ == 0)
{
lean_object* v___x_1773_; 
v___x_1773_ = l_List_reverse___redArg(v___x_1769_);
v___y_1755_ = v___x_1773_;
goto v___jp_1754_;
}
else
{
v___y_1755_ = v___x_1769_;
goto v___jp_1754_;
}
v___jp_1754_:
{
lean_object* v___x_1756_; 
lean_inc(v_head_1750_);
v___x_1756_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7___redArg(v_head_1750_, v_val_1740_, v_val_1741_, v_val_1742_, v_a_1743_, v___y_1755_, v___x_1752_);
lean_dec(v___y_1755_);
if (lean_obj_tag(v___x_1756_) == 0)
{
lean_object* v___x_1757_; lean_object* v_a_1758_; lean_object* v___x_1759_; lean_object* v___x_1760_; lean_object* v___x_1761_; 
lean_dec_ref_known(v___x_1756_, 1);
v___x_1757_ = l_LearningWorker_timedFeatures(v_val_1740_, v_val_1741_);
v_a_1758_ = lean_ctor_get(v___x_1757_, 0);
lean_inc(v_a_1758_);
lean_dec_ref(v___x_1757_);
v___x_1759_ = ((lean_object*)(l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg___closed__0));
lean_inc(v_head_1750_);
v___x_1760_ = lean_nat_to_int(v_head_1750_);
v___x_1761_ = l_LearningWorker_sampleEvent(v___x_1759_, v___x_1759_, v___x_1760_, v_a_1758_, v___x_1753_);
if (lean_obj_tag(v___x_1761_) == 0)
{
lean_dec_ref_known(v___x_1761_, 1);
v_as_x27_1746_ = v_tail_1751_;
v_b_1747_ = v___x_1752_;
goto _start;
}
else
{
lean_dec(v___x_1745_);
return v___x_1761_;
}
}
else
{
lean_dec(v___x_1745_);
return v___x_1756_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg___boxed(lean_object* v_val_1774_, lean_object* v_val_1775_, lean_object* v_val_1776_, lean_object* v_a_1777_, lean_object* v_a_1778_, lean_object* v___x_1779_, lean_object* v_as_x27_1780_, lean_object* v_b_1781_, lean_object* v___y_1782_){
_start:
{
lean_object* v_res_1783_; 
v_res_1783_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg(v_val_1774_, v_val_1775_, v_val_1776_, v_a_1777_, v_a_1778_, v___x_1779_, v_as_x27_1780_, v_b_1781_);
lean_dec(v_as_x27_1780_);
lean_dec(v_a_1778_);
lean_dec(v_a_1777_);
lean_dec(v_val_1776_);
lean_dec(v_val_1775_);
lean_dec(v_val_1774_);
return v_res_1783_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00LearningWorker_bench_spec__15(lean_object* v_a_1784_){
_start:
{
lean_object* v___x_1785_; lean_object* v___x_1786_; 
v___x_1785_ = lean_array_mk(v_a_1784_);
v___x_1786_ = l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__0(v___x_1785_);
return v___x_1786_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00LearningWorker_bench_spec__5(lean_object* v_a_1787_, lean_object* v_a_1788_){
_start:
{
if (lean_obj_tag(v_a_1787_) == 0)
{
lean_object* v___x_1789_; 
v___x_1789_ = l_List_reverse___redArg(v_a_1788_);
return v___x_1789_;
}
else
{
lean_object* v_head_1790_; lean_object* v_tail_1791_; lean_object* v___x_1793_; uint8_t v_isShared_1794_; uint8_t v_isSharedCheck_1805_; 
v_head_1790_ = lean_ctor_get(v_a_1787_, 0);
v_tail_1791_ = lean_ctor_get(v_a_1787_, 1);
v_isSharedCheck_1805_ = !lean_is_exclusive(v_a_1787_);
if (v_isSharedCheck_1805_ == 0)
{
v___x_1793_ = v_a_1787_;
v_isShared_1794_ = v_isSharedCheck_1805_;
goto v_resetjp_1792_;
}
else
{
lean_inc(v_tail_1791_);
lean_inc(v_head_1790_);
lean_dec(v_a_1787_);
v___x_1793_ = lean_box(0);
v_isShared_1794_ = v_isSharedCheck_1805_;
goto v_resetjp_1792_;
}
v_resetjp_1792_:
{
lean_object* v___x_1795_; lean_object* v___x_1796_; lean_object* v___x_1797_; lean_object* v___x_1798_; lean_object* v___x_1799_; lean_object* v___x_1800_; lean_object* v___x_1802_; 
v___x_1795_ = ((lean_object*)(l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7___redArg___closed__0));
lean_inc(v_head_1790_);
v___x_1796_ = l_Nat_reprFast(v_head_1790_);
v___x_1797_ = lean_nat_to_int(v_head_1790_);
v___x_1798_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1798_, 0, v___x_1797_);
v___x_1799_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1799_, 0, v___x_1796_);
lean_ctor_set(v___x_1799_, 1, v___x_1798_);
v___x_1800_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1800_, 0, v___x_1795_);
lean_ctor_set(v___x_1800_, 1, v___x_1799_);
if (v_isShared_1794_ == 0)
{
lean_ctor_set(v___x_1793_, 1, v_a_1788_);
lean_ctor_set(v___x_1793_, 0, v___x_1800_);
v___x_1802_ = v___x_1793_;
goto v_reusejp_1801_;
}
else
{
lean_object* v_reuseFailAlloc_1804_; 
v_reuseFailAlloc_1804_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1804_, 0, v___x_1800_);
lean_ctor_set(v_reuseFailAlloc_1804_, 1, v_a_1788_);
v___x_1802_ = v_reuseFailAlloc_1804_;
goto v_reusejp_1801_;
}
v_reusejp_1801_:
{
v_a_1787_ = v_tail_1791_;
v_a_1788_ = v___x_1802_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_find_x3f___at___00LearningWorker_bench_spec__0(lean_object* v_name_1806_, lean_object* v_x_1807_){
_start:
{
if (lean_obj_tag(v_x_1807_) == 0)
{
lean_object* v___x_1808_; 
v___x_1808_ = lean_box(0);
return v___x_1808_;
}
else
{
lean_object* v_head_1809_; lean_object* v_tail_1810_; lean_object* v_fst_1811_; uint8_t v___x_1812_; 
v_head_1809_ = lean_ctor_get(v_x_1807_, 0);
v_tail_1810_ = lean_ctor_get(v_x_1807_, 1);
v_fst_1811_ = lean_ctor_get(v_head_1809_, 0);
v___x_1812_ = lean_string_dec_eq(v_fst_1811_, v_name_1806_);
if (v___x_1812_ == 0)
{
v_x_1807_ = v_tail_1810_;
goto _start;
}
else
{
lean_object* v___x_1814_; 
lean_inc(v_head_1809_);
v___x_1814_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1814_, 0, v_head_1809_);
return v___x_1814_;
}
}
}
}
LEAN_EXPORT lean_object* l_List_find_x3f___at___00LearningWorker_bench_spec__0___boxed(lean_object* v_name_1815_, lean_object* v_x_1816_){
_start:
{
lean_object* v_res_1817_; 
v_res_1817_ = l_List_find_x3f___at___00LearningWorker_bench_spec__0(v_name_1815_, v_x_1816_);
lean_dec(v_x_1816_);
lean_dec_ref(v_name_1815_);
return v_res_1817_;
}
}
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00LearningWorker_bench_spec__2(lean_object* v_registry_1821_, lean_object* v_x_1822_, lean_object* v_x_1823_){
_start:
{
if (lean_obj_tag(v_x_1822_) == 0)
{
lean_object* v___x_1825_; lean_object* v___x_1826_; 
v___x_1825_ = l_List_reverse___redArg(v_x_1823_);
v___x_1826_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1826_, 0, v___x_1825_);
return v___x_1826_;
}
else
{
lean_object* v_head_1827_; lean_object* v_tail_1828_; lean_object* v___x_1830_; uint8_t v_isShared_1831_; uint8_t v_isSharedCheck_1849_; 
v_head_1827_ = lean_ctor_get(v_x_1822_, 0);
v_tail_1828_ = lean_ctor_get(v_x_1822_, 1);
v_isSharedCheck_1849_ = !lean_is_exclusive(v_x_1822_);
if (v_isSharedCheck_1849_ == 0)
{
v___x_1830_ = v_x_1822_;
v_isShared_1831_ = v_isSharedCheck_1849_;
goto v_resetjp_1829_;
}
else
{
lean_inc(v_tail_1828_);
lean_inc(v_head_1827_);
lean_dec(v_x_1822_);
v___x_1830_ = lean_box(0);
v_isShared_1831_ = v_isSharedCheck_1849_;
goto v_resetjp_1829_;
}
v_resetjp_1829_:
{
lean_object* v___x_1832_; 
v___x_1832_ = l_List_find_x3f___at___00LearningWorker_bench_spec__0(v_head_1827_, v_registry_1821_);
if (lean_obj_tag(v___x_1832_) == 0)
{
lean_object* v___x_1833_; lean_object* v___x_1834_; 
lean_del_object(v___x_1830_);
lean_dec(v_tail_1828_);
lean_dec(v_head_1827_);
lean_dec(v_x_1823_);
v___x_1833_ = ((lean_object*)(l_List_mapM_loop___at___00LearningWorker_bench_spec__2___closed__1));
v___x_1834_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1834_, 0, v___x_1833_);
return v___x_1834_;
}
else
{
lean_object* v_val_1835_; lean_object* v_snd_1836_; lean_object* v___x_1838_; uint8_t v_isShared_1839_; uint8_t v_isSharedCheck_1847_; 
v_val_1835_ = lean_ctor_get(v___x_1832_, 0);
lean_inc(v_val_1835_);
lean_dec_ref_known(v___x_1832_, 1);
v_snd_1836_ = lean_ctor_get(v_val_1835_, 1);
v_isSharedCheck_1847_ = !lean_is_exclusive(v_val_1835_);
if (v_isSharedCheck_1847_ == 0)
{
lean_object* v_unused_1848_; 
v_unused_1848_ = lean_ctor_get(v_val_1835_, 0);
lean_dec(v_unused_1848_);
v___x_1838_ = v_val_1835_;
v_isShared_1839_ = v_isSharedCheck_1847_;
goto v_resetjp_1837_;
}
else
{
lean_inc(v_snd_1836_);
lean_dec(v_val_1835_);
v___x_1838_ = lean_box(0);
v_isShared_1839_ = v_isSharedCheck_1847_;
goto v_resetjp_1837_;
}
v_resetjp_1837_:
{
lean_object* v___x_1841_; 
if (v_isShared_1839_ == 0)
{
lean_ctor_set(v___x_1838_, 0, v_head_1827_);
v___x_1841_ = v___x_1838_;
goto v_reusejp_1840_;
}
else
{
lean_object* v_reuseFailAlloc_1846_; 
v_reuseFailAlloc_1846_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1846_, 0, v_head_1827_);
lean_ctor_set(v_reuseFailAlloc_1846_, 1, v_snd_1836_);
v___x_1841_ = v_reuseFailAlloc_1846_;
goto v_reusejp_1840_;
}
v_reusejp_1840_:
{
lean_object* v___x_1843_; 
if (v_isShared_1831_ == 0)
{
lean_ctor_set(v___x_1830_, 1, v_x_1823_);
lean_ctor_set(v___x_1830_, 0, v___x_1841_);
v___x_1843_ = v___x_1830_;
goto v_reusejp_1842_;
}
else
{
lean_object* v_reuseFailAlloc_1845_; 
v_reuseFailAlloc_1845_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1845_, 0, v___x_1841_);
lean_ctor_set(v_reuseFailAlloc_1845_, 1, v_x_1823_);
v___x_1843_ = v_reuseFailAlloc_1845_;
goto v_reusejp_1842_;
}
v_reusejp_1842_:
{
v_x_1822_ = v_tail_1828_;
v_x_1823_ = v___x_1843_;
goto _start;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00LearningWorker_bench_spec__2___boxed(lean_object* v_registry_1850_, lean_object* v_x_1851_, lean_object* v_x_1852_, lean_object* v___y_1853_){
_start:
{
lean_object* v_res_1854_; 
v_res_1854_ = l_List_mapM_loop___at___00LearningWorker_bench_spec__2(v_registry_1850_, v_x_1851_, v_x_1852_);
lean_dec(v_registry_1850_);
return v_res_1854_;
}
}
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00LearningWorker_bench_spec__13(lean_object* v_a_1858_, lean_object* v_a_1859_, lean_object* v_a_1860_, lean_object* v_x_1861_, lean_object* v_x_1862_){
_start:
{
if (lean_obj_tag(v_x_1861_) == 0)
{
lean_object* v___x_1864_; lean_object* v___x_1865_; 
lean_dec(v_a_1858_);
v___x_1864_ = l_List_reverse___redArg(v_x_1862_);
v___x_1865_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1865_, 0, v___x_1864_);
return v___x_1865_;
}
else
{
lean_object* v_head_1866_; lean_object* v_tail_1867_; lean_object* v___x_1869_; uint8_t v_isShared_1870_; uint8_t v_isSharedCheck_1914_; 
v_head_1866_ = lean_ctor_get(v_x_1861_, 0);
v_tail_1867_ = lean_ctor_get(v_x_1861_, 1);
v_isSharedCheck_1914_ = !lean_is_exclusive(v_x_1861_);
if (v_isSharedCheck_1914_ == 0)
{
v___x_1869_ = v_x_1861_;
v_isShared_1870_ = v_isSharedCheck_1914_;
goto v_resetjp_1868_;
}
else
{
lean_inc(v_tail_1867_);
lean_inc(v_head_1866_);
lean_dec(v_x_1861_);
v___x_1869_ = lean_box(0);
v_isShared_1870_ = v_isSharedCheck_1914_;
goto v_resetjp_1868_;
}
v_resetjp_1868_:
{
lean_object* v_a_1872_; lean_object* v___x_1877_; 
lean_inc(v_a_1858_);
lean_inc(v_head_1866_);
v___x_1877_ = l_LearningWorker_kernelProfile(v_head_1866_, v_a_1858_, v_a_1859_);
if (lean_obj_tag(v___x_1877_) == 0)
{
lean_object* v_a_1878_; lean_object* v___x_1879_; lean_object* v___x_1880_; lean_object* v___x_1881_; 
v_a_1878_ = lean_ctor_get(v___x_1877_, 0);
lean_inc_n(v_a_1878_, 2);
lean_dec_ref_known(v___x_1877_, 1);
v___x_1879_ = ((lean_object*)(l_LearningWorker_kernelProfile___closed__2));
v___x_1880_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_a_1878_, v___x_1879_);
v___x_1881_ = l_LearningWorker_orError___redArg(v___x_1880_);
if (lean_obj_tag(v___x_1881_) == 0)
{
lean_object* v_a_1882_; lean_object* v___x_1884_; uint8_t v_isShared_1885_; uint8_t v_isSharedCheck_1896_; 
v_a_1882_ = lean_ctor_get(v___x_1881_, 0);
v_isSharedCheck_1896_ = !lean_is_exclusive(v___x_1881_);
if (v_isSharedCheck_1896_ == 0)
{
v___x_1884_ = v___x_1881_;
v_isShared_1885_ = v_isSharedCheck_1896_;
goto v_resetjp_1883_;
}
else
{
lean_inc(v_a_1882_);
lean_dec(v___x_1881_);
v___x_1884_ = lean_box(0);
v_isShared_1885_ = v_isSharedCheck_1896_;
goto v_resetjp_1883_;
}
v_resetjp_1883_:
{
lean_object* v___y_1887_; lean_object* v___x_1893_; 
v___x_1893_ = l_List_get_x3fInternal___redArg(v_a_1860_, v_head_1866_);
if (lean_obj_tag(v___x_1893_) == 0)
{
lean_object* v___x_1894_; 
v___x_1894_ = lean_unsigned_to_nat(0u);
v___y_1887_ = v___x_1894_;
goto v___jp_1886_;
}
else
{
lean_object* v_val_1895_; 
v_val_1895_ = lean_ctor_get(v___x_1893_, 0);
lean_inc(v_val_1895_);
lean_dec_ref_known(v___x_1893_, 1);
v___y_1887_ = v_val_1895_;
goto v___jp_1886_;
}
v___jp_1886_:
{
uint8_t v___x_1888_; 
v___x_1888_ = lean_nat_dec_eq(v_a_1882_, v___y_1887_);
lean_dec(v___y_1887_);
lean_dec(v_a_1882_);
if (v___x_1888_ == 0)
{
lean_object* v___x_1889_; lean_object* v___x_1891_; 
lean_dec(v_a_1878_);
lean_del_object(v___x_1869_);
lean_dec(v_tail_1867_);
lean_dec(v_x_1862_);
lean_dec(v_a_1858_);
v___x_1889_ = ((lean_object*)(l_List_mapM_loop___at___00LearningWorker_bench_spec__13___closed__1));
if (v_isShared_1885_ == 0)
{
lean_ctor_set_tag(v___x_1884_, 1);
lean_ctor_set(v___x_1884_, 0, v___x_1889_);
v___x_1891_ = v___x_1884_;
goto v_reusejp_1890_;
}
else
{
lean_object* v_reuseFailAlloc_1892_; 
v_reuseFailAlloc_1892_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1892_, 0, v___x_1889_);
v___x_1891_ = v_reuseFailAlloc_1892_;
goto v_reusejp_1890_;
}
v_reusejp_1890_:
{
return v___x_1891_;
}
}
else
{
lean_del_object(v___x_1884_);
v_a_1872_ = v_a_1878_;
goto v___jp_1871_;
}
}
}
}
else
{
lean_object* v_a_1897_; lean_object* v___x_1899_; uint8_t v_isShared_1900_; uint8_t v_isSharedCheck_1904_; 
lean_dec(v_a_1878_);
lean_del_object(v___x_1869_);
lean_dec(v_tail_1867_);
lean_dec(v_head_1866_);
lean_dec(v_x_1862_);
lean_dec(v_a_1858_);
v_a_1897_ = lean_ctor_get(v___x_1881_, 0);
v_isSharedCheck_1904_ = !lean_is_exclusive(v___x_1881_);
if (v_isSharedCheck_1904_ == 0)
{
v___x_1899_ = v___x_1881_;
v_isShared_1900_ = v_isSharedCheck_1904_;
goto v_resetjp_1898_;
}
else
{
lean_inc(v_a_1897_);
lean_dec(v___x_1881_);
v___x_1899_ = lean_box(0);
v_isShared_1900_ = v_isSharedCheck_1904_;
goto v_resetjp_1898_;
}
v_resetjp_1898_:
{
lean_object* v___x_1902_; 
if (v_isShared_1900_ == 0)
{
v___x_1902_ = v___x_1899_;
goto v_reusejp_1901_;
}
else
{
lean_object* v_reuseFailAlloc_1903_; 
v_reuseFailAlloc_1903_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1903_, 0, v_a_1897_);
v___x_1902_ = v_reuseFailAlloc_1903_;
goto v_reusejp_1901_;
}
v_reusejp_1901_:
{
return v___x_1902_;
}
}
}
}
else
{
lean_dec(v_head_1866_);
if (lean_obj_tag(v___x_1877_) == 0)
{
lean_object* v_a_1905_; 
v_a_1905_ = lean_ctor_get(v___x_1877_, 0);
lean_inc(v_a_1905_);
lean_dec_ref_known(v___x_1877_, 1);
v_a_1872_ = v_a_1905_;
goto v___jp_1871_;
}
else
{
lean_object* v_a_1906_; lean_object* v___x_1908_; uint8_t v_isShared_1909_; uint8_t v_isSharedCheck_1913_; 
lean_del_object(v___x_1869_);
lean_dec(v_tail_1867_);
lean_dec(v_x_1862_);
lean_dec(v_a_1858_);
v_a_1906_ = lean_ctor_get(v___x_1877_, 0);
v_isSharedCheck_1913_ = !lean_is_exclusive(v___x_1877_);
if (v_isSharedCheck_1913_ == 0)
{
v___x_1908_ = v___x_1877_;
v_isShared_1909_ = v_isSharedCheck_1913_;
goto v_resetjp_1907_;
}
else
{
lean_inc(v_a_1906_);
lean_dec(v___x_1877_);
v___x_1908_ = lean_box(0);
v_isShared_1909_ = v_isSharedCheck_1913_;
goto v_resetjp_1907_;
}
v_resetjp_1907_:
{
lean_object* v___x_1911_; 
if (v_isShared_1909_ == 0)
{
v___x_1911_ = v___x_1908_;
goto v_reusejp_1910_;
}
else
{
lean_object* v_reuseFailAlloc_1912_; 
v_reuseFailAlloc_1912_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1912_, 0, v_a_1906_);
v___x_1911_ = v_reuseFailAlloc_1912_;
goto v_reusejp_1910_;
}
v_reusejp_1910_:
{
return v___x_1911_;
}
}
}
}
v___jp_1871_:
{
lean_object* v___x_1874_; 
if (v_isShared_1870_ == 0)
{
lean_ctor_set(v___x_1869_, 1, v_x_1862_);
lean_ctor_set(v___x_1869_, 0, v_a_1872_);
v___x_1874_ = v___x_1869_;
goto v_reusejp_1873_;
}
else
{
lean_object* v_reuseFailAlloc_1876_; 
v_reuseFailAlloc_1876_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_1876_, 0, v_a_1872_);
lean_ctor_set(v_reuseFailAlloc_1876_, 1, v_x_1862_);
v___x_1874_ = v_reuseFailAlloc_1876_;
goto v_reusejp_1873_;
}
v_reusejp_1873_:
{
v_x_1861_ = v_tail_1867_;
v_x_1862_ = v___x_1874_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00LearningWorker_bench_spec__13___boxed(lean_object* v_a_1915_, lean_object* v_a_1916_, lean_object* v_a_1917_, lean_object* v_x_1918_, lean_object* v_x_1919_, lean_object* v___y_1920_){
_start:
{
lean_object* v_res_1921_; 
v_res_1921_ = l_List_mapM_loop___at___00LearningWorker_bench_spec__13(v_a_1915_, v_a_1916_, v_a_1917_, v_x_1918_, v_x_1919_);
lean_dec(v_a_1917_);
lean_dec(v_a_1916_);
return v_res_1921_;
}
}
static lean_object* _init_l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg___closed__0(void){
_start:
{
lean_object* v___x_1922_; lean_object* v___x_1923_; 
v___x_1922_ = lean_obj_once(&l_LearningWorker_featureSelect___closed__2, &l_LearningWorker_featureSelect___closed__2_once, _init_l_LearningWorker_featureSelect___closed__2);
v___x_1923_ = lean_int_neg(v___x_1922_);
return v___x_1923_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg(lean_object* v_val_1924_, lean_object* v_val_1925_, lean_object* v_val_1926_, lean_object* v_a_1927_, lean_object* v_as_x27_1928_, lean_object* v_b_1929_){
_start:
{
if (lean_obj_tag(v_as_x27_1928_) == 0)
{
lean_object* v___x_1931_; 
v___x_1931_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1931_, 0, v_b_1929_);
return v___x_1931_;
}
else
{
lean_object* v_head_1932_; lean_object* v_tail_1933_; lean_object* v___x_1934_; 
v_head_1932_ = lean_ctor_get(v_as_x27_1928_, 0);
v_tail_1933_ = lean_ctor_get(v_as_x27_1928_, 1);
lean_inc(v_head_1932_);
v___x_1934_ = l_LearningWorker_timedKernel(v_head_1932_, v_val_1924_, v_val_1925_, v_val_1926_, v_a_1927_);
if (lean_obj_tag(v___x_1934_) == 0)
{
lean_object* v_a_1935_; lean_object* v_fst_1936_; lean_object* v_snd_1937_; lean_object* v___x_1938_; lean_object* v___x_1939_; lean_object* v___x_1940_; lean_object* v___x_1941_; 
v_a_1935_ = lean_ctor_get(v___x_1934_, 0);
lean_inc(v_a_1935_);
lean_dec_ref_known(v___x_1934_, 1);
v_fst_1936_ = lean_ctor_get(v_a_1935_, 0);
lean_inc(v_fst_1936_);
v_snd_1937_ = lean_ctor_get(v_a_1935_, 1);
lean_inc(v_snd_1937_);
lean_dec(v_a_1935_);
v___x_1938_ = ((lean_object*)(l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7___redArg___closed__0));
lean_inc(v_head_1932_);
v___x_1939_ = l_Nat_reprFast(v_head_1932_);
v___x_1940_ = lean_obj_once(&l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg___closed__0, &l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg___closed__0_once, _init_l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg___closed__0);
v___x_1941_ = l_LearningWorker_sampleEvent(v___x_1938_, v___x_1939_, v___x_1940_, v_fst_1936_, v_snd_1937_);
if (lean_obj_tag(v___x_1941_) == 0)
{
lean_object* v___x_1942_; 
lean_dec_ref_known(v___x_1941_, 1);
v___x_1942_ = lean_box(0);
v_as_x27_1928_ = v_tail_1933_;
v_b_1929_ = v___x_1942_;
goto _start;
}
else
{
return v___x_1941_;
}
}
else
{
lean_object* v_a_1944_; lean_object* v___x_1946_; uint8_t v_isShared_1947_; uint8_t v_isSharedCheck_1951_; 
v_a_1944_ = lean_ctor_get(v___x_1934_, 0);
v_isSharedCheck_1951_ = !lean_is_exclusive(v___x_1934_);
if (v_isSharedCheck_1951_ == 0)
{
v___x_1946_ = v___x_1934_;
v_isShared_1947_ = v_isSharedCheck_1951_;
goto v_resetjp_1945_;
}
else
{
lean_inc(v_a_1944_);
lean_dec(v___x_1934_);
v___x_1946_ = lean_box(0);
v_isShared_1947_ = v_isSharedCheck_1951_;
goto v_resetjp_1945_;
}
v_resetjp_1945_:
{
lean_object* v___x_1949_; 
if (v_isShared_1947_ == 0)
{
v___x_1949_ = v___x_1946_;
goto v_reusejp_1948_;
}
else
{
lean_object* v_reuseFailAlloc_1950_; 
v_reuseFailAlloc_1950_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1950_, 0, v_a_1944_);
v___x_1949_ = v_reuseFailAlloc_1950_;
goto v_reusejp_1948_;
}
v_reusejp_1948_:
{
return v___x_1949_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg___boxed(lean_object* v_val_1952_, lean_object* v_val_1953_, lean_object* v_val_1954_, lean_object* v_a_1955_, lean_object* v_as_x27_1956_, lean_object* v_b_1957_, lean_object* v___y_1958_){
_start:
{
lean_object* v_res_1959_; 
v_res_1959_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg(v_val_1952_, v_val_1953_, v_val_1954_, v_a_1955_, v_as_x27_1956_, v_b_1957_);
lean_dec(v_as_x27_1956_);
lean_dec(v_a_1955_);
lean_dec(v_val_1954_);
lean_dec(v_val_1953_);
lean_dec(v_val_1952_);
return v_res_1959_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__4___redArg(lean_object* v_val_1960_, lean_object* v_val_1961_, lean_object* v_val_1962_, lean_object* v_a_1963_, lean_object* v_as_x27_1964_, lean_object* v_b_1965_){
_start:
{
if (lean_obj_tag(v_as_x27_1964_) == 0)
{
lean_object* v___x_1967_; 
v___x_1967_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_1967_, 0, v_b_1965_);
return v___x_1967_;
}
else
{
lean_object* v_head_1968_; lean_object* v_tail_1969_; lean_object* v_fst_1970_; lean_object* v_snd_1971_; lean_object* v___x_1972_; 
v_head_1968_ = lean_ctor_get(v_as_x27_1964_, 0);
v_tail_1969_ = lean_ctor_get(v_as_x27_1964_, 1);
v_fst_1970_ = lean_ctor_get(v_head_1968_, 0);
v_snd_1971_ = lean_ctor_get(v_head_1968_, 1);
lean_inc(v_snd_1971_);
v___x_1972_ = l_LearningWorker_timedPolicy(v_snd_1971_, v_val_1960_, v_val_1961_, v_val_1962_, v_a_1963_);
if (lean_obj_tag(v___x_1972_) == 0)
{
lean_object* v_a_1973_; lean_object* v_fst_1974_; lean_object* v_snd_1975_; lean_object* v___x_1976_; lean_object* v___x_1977_; lean_object* v___x_1978_; 
v_a_1973_ = lean_ctor_get(v___x_1972_, 0);
lean_inc(v_a_1973_);
lean_dec_ref_known(v___x_1972_, 1);
v_fst_1974_ = lean_ctor_get(v_a_1973_, 0);
lean_inc(v_fst_1974_);
v_snd_1975_ = lean_ctor_get(v_a_1973_, 1);
lean_inc(v_snd_1975_);
lean_dec(v_a_1973_);
v___x_1976_ = ((lean_object*)(l_List_mapTR_loop___at___00LearningWorker_bench_spec__6___closed__0));
v___x_1977_ = lean_obj_once(&l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg___closed__0, &l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg___closed__0_once, _init_l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg___closed__0);
lean_inc(v_fst_1970_);
v___x_1978_ = l_LearningWorker_sampleEvent(v___x_1976_, v_fst_1970_, v___x_1977_, v_fst_1974_, v_snd_1975_);
if (lean_obj_tag(v___x_1978_) == 0)
{
lean_object* v___x_1979_; 
lean_dec_ref_known(v___x_1978_, 1);
v___x_1979_ = lean_box(0);
v_as_x27_1964_ = v_tail_1969_;
v_b_1965_ = v___x_1979_;
goto _start;
}
else
{
return v___x_1978_;
}
}
else
{
lean_object* v_a_1981_; lean_object* v___x_1983_; uint8_t v_isShared_1984_; uint8_t v_isSharedCheck_1988_; 
v_a_1981_ = lean_ctor_get(v___x_1972_, 0);
v_isSharedCheck_1988_ = !lean_is_exclusive(v___x_1972_);
if (v_isSharedCheck_1988_ == 0)
{
v___x_1983_ = v___x_1972_;
v_isShared_1984_ = v_isSharedCheck_1988_;
goto v_resetjp_1982_;
}
else
{
lean_inc(v_a_1981_);
lean_dec(v___x_1972_);
v___x_1983_ = lean_box(0);
v_isShared_1984_ = v_isSharedCheck_1988_;
goto v_resetjp_1982_;
}
v_resetjp_1982_:
{
lean_object* v___x_1986_; 
if (v_isShared_1984_ == 0)
{
v___x_1986_ = v___x_1983_;
goto v_reusejp_1985_;
}
else
{
lean_object* v_reuseFailAlloc_1987_; 
v_reuseFailAlloc_1987_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1987_, 0, v_a_1981_);
v___x_1986_ = v_reuseFailAlloc_1987_;
goto v_reusejp_1985_;
}
v_reusejp_1985_:
{
return v___x_1986_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__4___redArg___boxed(lean_object* v_val_1989_, lean_object* v_val_1990_, lean_object* v_val_1991_, lean_object* v_a_1992_, lean_object* v_as_x27_1993_, lean_object* v_b_1994_, lean_object* v___y_1995_){
_start:
{
lean_object* v_res_1996_; 
v_res_1996_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__4___redArg(v_val_1989_, v_val_1990_, v_val_1991_, v_a_1992_, v_as_x27_1993_, v_b_1994_);
lean_dec(v_as_x27_1993_);
lean_dec(v_a_1992_);
lean_dec(v_val_1991_);
lean_dec(v_val_1990_);
lean_dec(v_val_1989_);
return v_res_1996_;
}
}
static lean_object* _init_l_LearningWorker_bench___closed__16(void){
_start:
{
lean_object* v___x_2015_; lean_object* v___x_2016_; 
v___x_2015_ = lean_unsigned_to_nat(7u);
v___x_2016_ = l_List_range(v___x_2015_);
return v___x_2016_;
}
}
static lean_object* _init_l_LearningWorker_bench___closed__17(void){
_start:
{
lean_object* v___x_2017_; lean_object* v___x_2018_; lean_object* v___x_2019_; 
v___x_2017_ = lean_box(0);
v___x_2018_ = lean_obj_once(&l_LearningWorker_bench___closed__16, &l_LearningWorker_bench___closed__16_once, _init_l_LearningWorker_bench___closed__16);
v___x_2019_ = l_List_mapTR_loop___at___00LearningWorker_bench_spec__5(v___x_2018_, v___x_2017_);
return v___x_2019_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_bench(lean_object* v_registry_2020_, lean_object* v_j_2021_){
_start:
{
lean_object* v___x_2023_; lean_object* v___x_2024_; lean_object* v___x_2025_; 
v___x_2023_ = ((lean_object*)(l_LearningWorker_bench___closed__0));
lean_inc(v_j_2021_);
v___x_2024_ = l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_bench_spec__1(v_j_2021_, v___x_2023_);
v___x_2025_ = l_LearningWorker_orError___redArg(v___x_2024_);
if (lean_obj_tag(v___x_2025_) == 0)
{
lean_object* v_a_2026_; lean_object* v___x_2027_; lean_object* v___x_2028_; lean_object* v___x_2029_; 
v_a_2026_ = lean_ctor_get(v___x_2025_, 0);
lean_inc(v_a_2026_);
lean_dec_ref_known(v___x_2025_, 1);
v___x_2027_ = ((lean_object*)(l_LearningWorker_bench___closed__1));
lean_inc(v_j_2021_);
v___x_2028_ = l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_bench_spec__1(v_j_2021_, v___x_2027_);
v___x_2029_ = l_LearningWorker_orError___redArg(v___x_2028_);
if (lean_obj_tag(v___x_2029_) == 0)
{
lean_object* v_a_2030_; lean_object* v___x_2031_; lean_object* v___x_2032_; lean_object* v___x_2033_; 
v_a_2030_ = lean_ctor_get(v___x_2029_, 0);
lean_inc(v_a_2030_);
lean_dec_ref_known(v___x_2029_, 1);
v___x_2031_ = ((lean_object*)(l_LearningWorker_bench___closed__2));
lean_inc(v_j_2021_);
v___x_2032_ = l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_bench_spec__1(v_j_2021_, v___x_2031_);
v___x_2033_ = l_LearningWorker_orError___redArg(v___x_2032_);
if (lean_obj_tag(v___x_2033_) == 0)
{
lean_object* v_a_2034_; lean_object* v___x_2035_; lean_object* v___x_2036_; lean_object* v___x_2037_; 
v_a_2034_ = lean_ctor_get(v___x_2033_, 0);
lean_inc(v_a_2034_);
lean_dec_ref_known(v___x_2033_, 1);
v___x_2035_ = ((lean_object*)(l_LearningWorker_bench___closed__3));
lean_inc(v_j_2021_);
v___x_2036_ = l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_bench_spec__1(v_j_2021_, v___x_2035_);
v___x_2037_ = l_LearningWorker_orError___redArg(v___x_2036_);
if (lean_obj_tag(v___x_2037_) == 0)
{
lean_object* v_a_2038_; lean_object* v___x_2040_; uint8_t v_isShared_2041_; uint8_t v_isSharedCheck_2227_; 
v_a_2038_ = lean_ctor_get(v___x_2037_, 0);
v_isSharedCheck_2227_ = !lean_is_exclusive(v___x_2037_);
if (v_isSharedCheck_2227_ == 0)
{
v___x_2040_ = v___x_2037_;
v_isShared_2041_ = v_isSharedCheck_2227_;
goto v_resetjp_2039_;
}
else
{
lean_inc(v_a_2038_);
lean_dec(v___x_2037_);
v___x_2040_ = lean_box(0);
v_isShared_2041_ = v_isSharedCheck_2227_;
goto v_resetjp_2039_;
}
v_resetjp_2039_:
{
lean_object* v___y_2043_; lean_object* v___y_2044_; lean_object* v___y_2045_; lean_object* v___y_2046_; lean_object* v___y_2047_; lean_object* v___y_2048_; lean_object* v___y_2049_; uint8_t v___y_2050_; lean_object* v___x_2120_; lean_object* v___x_2121_; lean_object* v___x_2122_; 
v___x_2120_ = ((lean_object*)(l_LearningWorker_bench___closed__11));
lean_inc(v_j_2021_);
v___x_2121_ = lp_LeanSearchClient_Lean_Json_getObjValAs_x3f___at___00LeanSearchClient_getLoogleQueryJson_spec__4(v_j_2021_, v___x_2120_);
v___x_2122_ = l_LearningWorker_orError___redArg(v___x_2121_);
if (lean_obj_tag(v___x_2122_) == 0)
{
lean_object* v_a_2123_; lean_object* v___x_2124_; lean_object* v___x_2125_; lean_object* v___x_2126_; 
v_a_2123_ = lean_ctor_get(v___x_2122_, 0);
lean_inc(v_a_2123_);
lean_dec_ref_known(v___x_2122_, 1);
v___x_2124_ = ((lean_object*)(l_LearningWorker_bench___closed__12));
lean_inc(v_j_2021_);
v___x_2125_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_2021_, v___x_2124_);
v___x_2126_ = l_LearningWorker_orError___redArg(v___x_2125_);
if (lean_obj_tag(v___x_2126_) == 0)
{
lean_object* v_a_2127_; lean_object* v___x_2128_; lean_object* v___x_2129_; lean_object* v___x_2130_; 
v_a_2127_ = lean_ctor_get(v___x_2126_, 0);
lean_inc(v_a_2127_);
lean_dec_ref_known(v___x_2126_, 1);
v___x_2128_ = ((lean_object*)(l_LearningWorker_bench___closed__13));
v___x_2129_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonProfileMeta_fromJson_spec__2(v_j_2021_, v___x_2128_);
v___x_2130_ = l_LearningWorker_orError___redArg(v___x_2129_);
if (lean_obj_tag(v___x_2130_) == 0)
{
lean_object* v_a_2131_; lean_object* v___x_2133_; uint8_t v_isShared_2134_; uint8_t v_isSharedCheck_2202_; 
v_a_2131_ = lean_ctor_get(v___x_2130_, 0);
v_isSharedCheck_2202_ = !lean_is_exclusive(v___x_2130_);
if (v_isSharedCheck_2202_ == 0)
{
v___x_2133_ = v___x_2130_;
v_isShared_2134_ = v_isSharedCheck_2202_;
goto v_resetjp_2132_;
}
else
{
lean_inc(v_a_2131_);
lean_dec(v___x_2130_);
v___x_2133_ = lean_box(0);
v_isShared_2134_ = v_isSharedCheck_2202_;
goto v_resetjp_2132_;
}
v_resetjp_2132_:
{
uint8_t v___y_2141_; lean_object* v___x_2198_; uint8_t v___x_2199_; 
v___x_2198_ = lean_unsigned_to_nat(1u);
v___x_2199_ = lean_nat_dec_le(v___x_2198_, v_a_2127_);
if (v___x_2199_ == 0)
{
v___y_2141_ = v___x_2199_;
goto v___jp_2140_;
}
else
{
lean_object* v___x_2200_; uint8_t v___x_2201_; 
v___x_2200_ = lean_unsigned_to_nat(9u);
v___x_2201_ = lean_nat_dec_le(v_a_2127_, v___x_2200_);
v___y_2141_ = v___x_2201_;
goto v___jp_2140_;
}
v___jp_2135_:
{
lean_object* v___x_2136_; lean_object* v___x_2138_; 
v___x_2136_ = ((lean_object*)(l_LearningWorker_bench___closed__15));
if (v_isShared_2134_ == 0)
{
lean_ctor_set_tag(v___x_2133_, 1);
lean_ctor_set(v___x_2133_, 0, v___x_2136_);
v___x_2138_ = v___x_2133_;
goto v_reusejp_2137_;
}
else
{
lean_object* v_reuseFailAlloc_2139_; 
v_reuseFailAlloc_2139_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2139_, 0, v___x_2136_);
v___x_2138_ = v_reuseFailAlloc_2139_;
goto v_reusejp_2137_;
}
v_reusejp_2137_:
{
return v___x_2138_;
}
}
v___jp_2140_:
{
if (v___y_2141_ == 0)
{
lean_dec(v_a_2131_);
lean_dec(v_a_2127_);
lean_dec(v_a_2123_);
lean_del_object(v___x_2040_);
lean_dec(v_a_2038_);
lean_dec(v_a_2034_);
lean_dec(v_a_2030_);
lean_dec(v_a_2026_);
goto v___jp_2135_;
}
else
{
lean_object* v___x_2142_; lean_object* v___x_2143_; uint8_t v___x_2144_; 
v___x_2142_ = l_List_lengthTR___redArg(v_a_2038_);
v___x_2143_ = lean_unsigned_to_nat(7u);
v___x_2144_ = lean_nat_dec_eq(v___x_2142_, v___x_2143_);
lean_dec(v___x_2142_);
if (v___x_2144_ == 0)
{
lean_dec(v_a_2131_);
lean_dec(v_a_2127_);
lean_dec(v_a_2123_);
lean_del_object(v___x_2040_);
lean_dec(v_a_2038_);
lean_dec(v_a_2034_);
lean_dec(v_a_2030_);
lean_dec(v_a_2026_);
goto v___jp_2135_;
}
else
{
lean_object* v___x_2145_; lean_object* v___x_2146_; 
lean_del_object(v___x_2133_);
v___x_2145_ = lean_box(0);
v___x_2146_ = l_List_mapM_loop___at___00LearningWorker_bench_spec__2(v_registry_2020_, v_a_2123_, v___x_2145_);
if (lean_obj_tag(v___x_2146_) == 0)
{
lean_object* v_a_2147_; lean_object* v___x_2148_; lean_object* v___x_2149_; lean_object* v___x_2150_; lean_object* v___x_2151_; lean_object* v___x_2152_; lean_object* v___x_2153_; lean_object* v___x_2154_; 
v_a_2147_ = lean_ctor_get(v___x_2146_, 0);
lean_inc(v_a_2147_);
lean_dec_ref_known(v___x_2146_, 1);
lean_inc(v_a_2026_);
v___x_2148_ = lean_st_mk_ref(v_a_2026_);
v___x_2149_ = lean_unsigned_to_nat(0u);
v___x_2150_ = lean_st_mk_ref(v___x_2149_);
v___x_2151_ = lean_st_mk_ref(v___x_2149_);
v___x_2152_ = lean_obj_once(&l_LearningWorker_bench___closed__16, &l_LearningWorker_bench___closed__16_once, _init_l_LearningWorker_bench___closed__16);
v___x_2153_ = lean_box(0);
v___x_2154_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg(v___x_2148_, v___x_2150_, v___x_2151_, v_a_2030_, v___x_2152_, v___x_2153_);
if (lean_obj_tag(v___x_2154_) == 0)
{
lean_object* v___x_2155_; 
lean_dec_ref_known(v___x_2154_, 1);
v___x_2155_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__4___redArg(v___x_2148_, v___x_2150_, v___x_2151_, v_a_2030_, v_a_2147_, v___x_2153_);
if (lean_obj_tag(v___x_2155_) == 0)
{
lean_object* v___x_2156_; lean_object* v___x_2157_; lean_object* v___x_2158_; lean_object* v___x_2159_; lean_object* v___x_2160_; 
lean_dec_ref_known(v___x_2155_, 1);
v___x_2156_ = lean_obj_once(&l_LearningWorker_bench___closed__17, &l_LearningWorker_bench___closed__17_once, _init_l_LearningWorker_bench___closed__17);
lean_inc(v_a_2147_);
v___x_2157_ = l_List_mapTR_loop___at___00LearningWorker_bench_spec__6(v_a_2147_, v___x_2145_);
v___x_2158_ = l_List_appendTR___redArg(v___x_2156_, v___x_2157_);
v___x_2159_ = l_List_range(v_a_2127_);
v___x_2160_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg(v___x_2148_, v___x_2150_, v___x_2151_, v_a_2030_, v_a_2131_, v___x_2158_, v___x_2159_, v___x_2153_);
lean_dec(v_a_2131_);
lean_dec(v___x_2150_);
lean_dec(v___x_2148_);
if (lean_obj_tag(v___x_2160_) == 0)
{
lean_object* v___x_2161_; lean_object* v___x_2162_; uint8_t v___x_2163_; 
lean_dec_ref_known(v___x_2160_, 1);
v___x_2161_ = l_LeanSort_LearnedSelection_features(v_a_2026_);
v___x_2162_ = l_LeanSort_LearnedSelection_FeatureEngine_extract___at___00LeanSort_LearnedSelection_countedFeatures_spec__0(v_a_2026_);
v___x_2163_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v___x_2161_, v_a_2034_);
lean_dec(v_a_2034_);
if (v___x_2163_ == 0)
{
v___y_2043_ = v___x_2153_;
v___y_2044_ = v___x_2151_;
v___y_2045_ = v___x_2162_;
v___y_2046_ = v___x_2159_;
v___y_2047_ = v___x_2152_;
v___y_2048_ = v_a_2147_;
v___y_2049_ = v___x_2161_;
v___y_2050_ = v___x_2163_;
goto v___jp_2042_;
}
else
{
lean_object* v_ret_2164_; uint8_t v___x_2165_; 
v_ret_2164_ = lean_ctor_get(v___x_2162_, 0);
lean_inc(v_ret_2164_);
v___x_2165_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v_ret_2164_, v___x_2161_);
lean_dec(v_ret_2164_);
v___y_2043_ = v___x_2153_;
v___y_2044_ = v___x_2151_;
v___y_2045_ = v___x_2162_;
v___y_2046_ = v___x_2159_;
v___y_2047_ = v___x_2152_;
v___y_2048_ = v_a_2147_;
v___y_2049_ = v___x_2161_;
v___y_2050_ = v___x_2165_;
goto v___jp_2042_;
}
}
else
{
lean_object* v_a_2166_; lean_object* v___x_2168_; uint8_t v_isShared_2169_; uint8_t v_isSharedCheck_2173_; 
lean_dec(v___x_2159_);
lean_dec(v___x_2151_);
lean_dec(v_a_2147_);
lean_del_object(v___x_2040_);
lean_dec(v_a_2038_);
lean_dec(v_a_2034_);
lean_dec(v_a_2030_);
lean_dec(v_a_2026_);
v_a_2166_ = lean_ctor_get(v___x_2160_, 0);
v_isSharedCheck_2173_ = !lean_is_exclusive(v___x_2160_);
if (v_isSharedCheck_2173_ == 0)
{
v___x_2168_ = v___x_2160_;
v_isShared_2169_ = v_isSharedCheck_2173_;
goto v_resetjp_2167_;
}
else
{
lean_inc(v_a_2166_);
lean_dec(v___x_2160_);
v___x_2168_ = lean_box(0);
v_isShared_2169_ = v_isSharedCheck_2173_;
goto v_resetjp_2167_;
}
v_resetjp_2167_:
{
lean_object* v___x_2171_; 
if (v_isShared_2169_ == 0)
{
v___x_2171_ = v___x_2168_;
goto v_reusejp_2170_;
}
else
{
lean_object* v_reuseFailAlloc_2172_; 
v_reuseFailAlloc_2172_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2172_, 0, v_a_2166_);
v___x_2171_ = v_reuseFailAlloc_2172_;
goto v_reusejp_2170_;
}
v_reusejp_2170_:
{
return v___x_2171_;
}
}
}
}
else
{
lean_object* v_a_2174_; lean_object* v___x_2176_; uint8_t v_isShared_2177_; uint8_t v_isSharedCheck_2181_; 
lean_dec(v___x_2151_);
lean_dec(v___x_2150_);
lean_dec(v___x_2148_);
lean_dec(v_a_2147_);
lean_dec(v_a_2131_);
lean_dec(v_a_2127_);
lean_del_object(v___x_2040_);
lean_dec(v_a_2038_);
lean_dec(v_a_2034_);
lean_dec(v_a_2030_);
lean_dec(v_a_2026_);
v_a_2174_ = lean_ctor_get(v___x_2155_, 0);
v_isSharedCheck_2181_ = !lean_is_exclusive(v___x_2155_);
if (v_isSharedCheck_2181_ == 0)
{
v___x_2176_ = v___x_2155_;
v_isShared_2177_ = v_isSharedCheck_2181_;
goto v_resetjp_2175_;
}
else
{
lean_inc(v_a_2174_);
lean_dec(v___x_2155_);
v___x_2176_ = lean_box(0);
v_isShared_2177_ = v_isSharedCheck_2181_;
goto v_resetjp_2175_;
}
v_resetjp_2175_:
{
lean_object* v___x_2179_; 
if (v_isShared_2177_ == 0)
{
v___x_2179_ = v___x_2176_;
goto v_reusejp_2178_;
}
else
{
lean_object* v_reuseFailAlloc_2180_; 
v_reuseFailAlloc_2180_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2180_, 0, v_a_2174_);
v___x_2179_ = v_reuseFailAlloc_2180_;
goto v_reusejp_2178_;
}
v_reusejp_2178_:
{
return v___x_2179_;
}
}
}
}
else
{
lean_object* v_a_2182_; lean_object* v___x_2184_; uint8_t v_isShared_2185_; uint8_t v_isSharedCheck_2189_; 
lean_dec(v___x_2151_);
lean_dec(v___x_2150_);
lean_dec(v___x_2148_);
lean_dec(v_a_2147_);
lean_dec(v_a_2131_);
lean_dec(v_a_2127_);
lean_del_object(v___x_2040_);
lean_dec(v_a_2038_);
lean_dec(v_a_2034_);
lean_dec(v_a_2030_);
lean_dec(v_a_2026_);
v_a_2182_ = lean_ctor_get(v___x_2154_, 0);
v_isSharedCheck_2189_ = !lean_is_exclusive(v___x_2154_);
if (v_isSharedCheck_2189_ == 0)
{
v___x_2184_ = v___x_2154_;
v_isShared_2185_ = v_isSharedCheck_2189_;
goto v_resetjp_2183_;
}
else
{
lean_inc(v_a_2182_);
lean_dec(v___x_2154_);
v___x_2184_ = lean_box(0);
v_isShared_2185_ = v_isSharedCheck_2189_;
goto v_resetjp_2183_;
}
v_resetjp_2183_:
{
lean_object* v___x_2187_; 
if (v_isShared_2185_ == 0)
{
v___x_2187_ = v___x_2184_;
goto v_reusejp_2186_;
}
else
{
lean_object* v_reuseFailAlloc_2188_; 
v_reuseFailAlloc_2188_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2188_, 0, v_a_2182_);
v___x_2187_ = v_reuseFailAlloc_2188_;
goto v_reusejp_2186_;
}
v_reusejp_2186_:
{
return v___x_2187_;
}
}
}
}
else
{
lean_object* v_a_2190_; lean_object* v___x_2192_; uint8_t v_isShared_2193_; uint8_t v_isSharedCheck_2197_; 
lean_dec(v_a_2131_);
lean_dec(v_a_2127_);
lean_del_object(v___x_2040_);
lean_dec(v_a_2038_);
lean_dec(v_a_2034_);
lean_dec(v_a_2030_);
lean_dec(v_a_2026_);
v_a_2190_ = lean_ctor_get(v___x_2146_, 0);
v_isSharedCheck_2197_ = !lean_is_exclusive(v___x_2146_);
if (v_isSharedCheck_2197_ == 0)
{
v___x_2192_ = v___x_2146_;
v_isShared_2193_ = v_isSharedCheck_2197_;
goto v_resetjp_2191_;
}
else
{
lean_inc(v_a_2190_);
lean_dec(v___x_2146_);
v___x_2192_ = lean_box(0);
v_isShared_2193_ = v_isSharedCheck_2197_;
goto v_resetjp_2191_;
}
v_resetjp_2191_:
{
lean_object* v___x_2195_; 
if (v_isShared_2193_ == 0)
{
v___x_2195_ = v___x_2192_;
goto v_reusejp_2194_;
}
else
{
lean_object* v_reuseFailAlloc_2196_; 
v_reuseFailAlloc_2196_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2196_, 0, v_a_2190_);
v___x_2195_ = v_reuseFailAlloc_2196_;
goto v_reusejp_2194_;
}
v_reusejp_2194_:
{
return v___x_2195_;
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
lean_object* v_a_2203_; lean_object* v___x_2205_; uint8_t v_isShared_2206_; uint8_t v_isSharedCheck_2210_; 
lean_dec(v_a_2127_);
lean_dec(v_a_2123_);
lean_del_object(v___x_2040_);
lean_dec(v_a_2038_);
lean_dec(v_a_2034_);
lean_dec(v_a_2030_);
lean_dec(v_a_2026_);
v_a_2203_ = lean_ctor_get(v___x_2130_, 0);
v_isSharedCheck_2210_ = !lean_is_exclusive(v___x_2130_);
if (v_isSharedCheck_2210_ == 0)
{
v___x_2205_ = v___x_2130_;
v_isShared_2206_ = v_isSharedCheck_2210_;
goto v_resetjp_2204_;
}
else
{
lean_inc(v_a_2203_);
lean_dec(v___x_2130_);
v___x_2205_ = lean_box(0);
v_isShared_2206_ = v_isSharedCheck_2210_;
goto v_resetjp_2204_;
}
v_resetjp_2204_:
{
lean_object* v___x_2208_; 
if (v_isShared_2206_ == 0)
{
v___x_2208_ = v___x_2205_;
goto v_reusejp_2207_;
}
else
{
lean_object* v_reuseFailAlloc_2209_; 
v_reuseFailAlloc_2209_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2209_, 0, v_a_2203_);
v___x_2208_ = v_reuseFailAlloc_2209_;
goto v_reusejp_2207_;
}
v_reusejp_2207_:
{
return v___x_2208_;
}
}
}
}
else
{
lean_object* v_a_2211_; lean_object* v___x_2213_; uint8_t v_isShared_2214_; uint8_t v_isSharedCheck_2218_; 
lean_dec(v_a_2123_);
lean_del_object(v___x_2040_);
lean_dec(v_a_2038_);
lean_dec(v_a_2034_);
lean_dec(v_a_2030_);
lean_dec(v_a_2026_);
lean_dec(v_j_2021_);
v_a_2211_ = lean_ctor_get(v___x_2126_, 0);
v_isSharedCheck_2218_ = !lean_is_exclusive(v___x_2126_);
if (v_isSharedCheck_2218_ == 0)
{
v___x_2213_ = v___x_2126_;
v_isShared_2214_ = v_isSharedCheck_2218_;
goto v_resetjp_2212_;
}
else
{
lean_inc(v_a_2211_);
lean_dec(v___x_2126_);
v___x_2213_ = lean_box(0);
v_isShared_2214_ = v_isSharedCheck_2218_;
goto v_resetjp_2212_;
}
v_resetjp_2212_:
{
lean_object* v___x_2216_; 
if (v_isShared_2214_ == 0)
{
v___x_2216_ = v___x_2213_;
goto v_reusejp_2215_;
}
else
{
lean_object* v_reuseFailAlloc_2217_; 
v_reuseFailAlloc_2217_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2217_, 0, v_a_2211_);
v___x_2216_ = v_reuseFailAlloc_2217_;
goto v_reusejp_2215_;
}
v_reusejp_2215_:
{
return v___x_2216_;
}
}
}
}
else
{
lean_object* v_a_2219_; lean_object* v___x_2221_; uint8_t v_isShared_2222_; uint8_t v_isSharedCheck_2226_; 
lean_del_object(v___x_2040_);
lean_dec(v_a_2038_);
lean_dec(v_a_2034_);
lean_dec(v_a_2030_);
lean_dec(v_a_2026_);
lean_dec(v_j_2021_);
v_a_2219_ = lean_ctor_get(v___x_2122_, 0);
v_isSharedCheck_2226_ = !lean_is_exclusive(v___x_2122_);
if (v_isSharedCheck_2226_ == 0)
{
v___x_2221_ = v___x_2122_;
v_isShared_2222_ = v_isSharedCheck_2226_;
goto v_resetjp_2220_;
}
else
{
lean_inc(v_a_2219_);
lean_dec(v___x_2122_);
v___x_2221_ = lean_box(0);
v_isShared_2222_ = v_isSharedCheck_2226_;
goto v_resetjp_2220_;
}
v_resetjp_2220_:
{
lean_object* v___x_2224_; 
if (v_isShared_2222_ == 0)
{
v___x_2224_ = v___x_2221_;
goto v_reusejp_2223_;
}
else
{
lean_object* v_reuseFailAlloc_2225_; 
v_reuseFailAlloc_2225_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2225_, 0, v_a_2219_);
v___x_2224_ = v_reuseFailAlloc_2225_;
goto v_reusejp_2223_;
}
v_reusejp_2223_:
{
return v___x_2224_;
}
}
}
v___jp_2042_:
{
if (v___y_2050_ == 0)
{
lean_object* v___x_2051_; lean_object* v___x_2053_; 
lean_dec(v___y_2049_);
lean_dec(v___y_2048_);
lean_dec(v___y_2046_);
lean_dec_ref(v___y_2045_);
lean_dec(v___y_2044_);
lean_dec(v_a_2038_);
lean_dec(v_a_2030_);
lean_dec(v_a_2026_);
v___x_2051_ = ((lean_object*)(l_LearningWorker_bench___closed__5));
if (v_isShared_2041_ == 0)
{
lean_ctor_set_tag(v___x_2040_, 1);
lean_ctor_set(v___x_2040_, 0, v___x_2051_);
v___x_2053_ = v___x_2040_;
goto v_reusejp_2052_;
}
else
{
lean_object* v_reuseFailAlloc_2054_; 
v_reuseFailAlloc_2054_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2054_, 0, v___x_2051_);
v___x_2053_ = v_reuseFailAlloc_2054_;
goto v_reusejp_2052_;
}
v_reusejp_2052_:
{
return v___x_2053_;
}
}
else
{
lean_object* v___x_2055_; lean_object* v___x_2056_; 
lean_del_object(v___x_2040_);
lean_inc(v___y_2049_);
v___x_2055_ = lean_st_mk_ref(v___y_2049_);
v___x_2056_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__12___redArg(v___x_2055_, v___y_2044_, v___y_2049_, v___y_2048_, v___y_2046_, v___y_2043_);
lean_dec(v___y_2046_);
lean_dec(v___y_2044_);
lean_dec(v___x_2055_);
if (lean_obj_tag(v___x_2056_) == 0)
{
lean_object* v___x_2057_; lean_object* v___x_2058_; 
lean_dec_ref_known(v___x_2056_, 1);
v___x_2057_ = lean_box(0);
lean_inc(v___y_2047_);
lean_inc(v_a_2026_);
v___x_2058_ = l_List_mapM_loop___at___00LearningWorker_bench_spec__13(v_a_2026_, v_a_2030_, v_a_2038_, v___y_2047_, v___x_2057_);
lean_dec(v_a_2038_);
lean_dec(v_a_2030_);
if (lean_obj_tag(v___x_2058_) == 0)
{
lean_object* v_a_2059_; lean_object* v___x_2061_; uint8_t v_isShared_2062_; uint8_t v_isSharedCheck_2103_; 
v_a_2059_ = lean_ctor_get(v___x_2058_, 0);
v_isSharedCheck_2103_ = !lean_is_exclusive(v___x_2058_);
if (v_isSharedCheck_2103_ == 0)
{
v___x_2061_ = v___x_2058_;
v_isShared_2062_ = v_isSharedCheck_2103_;
goto v_resetjp_2060_;
}
else
{
lean_inc(v_a_2059_);
lean_dec(v___x_2058_);
v___x_2061_ = lean_box(0);
v_isShared_2062_ = v_isSharedCheck_2103_;
goto v_resetjp_2060_;
}
v_resetjp_2060_:
{
lean_object* v_time_2063_; lean_object* v___x_2065_; uint8_t v_isShared_2066_; uint8_t v_isSharedCheck_2101_; 
v_time_2063_ = lean_ctor_get(v___y_2045_, 1);
v_isSharedCheck_2101_ = !lean_is_exclusive(v___y_2045_);
if (v_isSharedCheck_2101_ == 0)
{
lean_object* v_unused_2102_; 
v_unused_2102_ = lean_ctor_get(v___y_2045_, 0);
lean_dec(v_unused_2102_);
v___x_2065_ = v___y_2045_;
v_isShared_2066_ = v_isSharedCheck_2101_;
goto v_resetjp_2064_;
}
else
{
lean_inc(v_time_2063_);
lean_dec(v___y_2045_);
v___x_2065_ = lean_box(0);
v_isShared_2066_ = v_isSharedCheck_2101_;
goto v_resetjp_2064_;
}
v_resetjp_2064_:
{
lean_object* v___x_2067_; lean_object* v___x_2068_; lean_object* v___x_2069_; lean_object* v___x_2070_; lean_object* v___x_2072_; 
v___x_2067_ = l_List_mapTR_loop___at___00LearningWorker_bench_spec__14(v___y_2049_, v___y_2048_, v___x_2057_);
v___x_2068_ = l_LeanSort_Direct_Engine_discover___at___00LeanSort_Direct_Engine_adaptive___at___00LeanSort_Direct_Engine_strategy___at___00LeanSort_Direct_run___at___00LeanSort_LearnedSelection_dispatch___at___00LeanSort_LearnedSelection_run_spec__0_spec__0_spec__1_spec__3_spec__7(v_a_2026_);
v___x_2069_ = ((lean_object*)(l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg___closed__0));
v___x_2070_ = l_Lean_List_toJson___at___00LearningWorker_bench_spec__15(v___y_2049_);
if (v_isShared_2066_ == 0)
{
lean_ctor_set(v___x_2065_, 1, v___x_2070_);
lean_ctor_set(v___x_2065_, 0, v___x_2069_);
v___x_2072_ = v___x_2065_;
goto v_reusejp_2071_;
}
else
{
lean_object* v_reuseFailAlloc_2100_; 
v_reuseFailAlloc_2100_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2100_, 0, v___x_2069_);
lean_ctor_set(v_reuseFailAlloc_2100_, 1, v___x_2070_);
v___x_2072_ = v_reuseFailAlloc_2100_;
goto v_reusejp_2071_;
}
v_reusejp_2071_:
{
lean_object* v___x_2073_; lean_object* v___x_2074_; lean_object* v___x_2075_; lean_object* v___x_2076_; lean_object* v___x_2077_; lean_object* v___x_2078_; lean_object* v___x_2079_; lean_object* v___x_2080_; lean_object* v___x_2081_; lean_object* v___x_2082_; lean_object* v___x_2083_; lean_object* v___x_2084_; lean_object* v___x_2085_; lean_object* v___x_2086_; lean_object* v___x_2087_; lean_object* v___x_2088_; lean_object* v___x_2089_; lean_object* v___x_2090_; lean_object* v___x_2091_; lean_object* v___x_2092_; lean_object* v___x_2093_; lean_object* v___x_2094_; lean_object* v___x_2095_; lean_object* v___x_2096_; lean_object* v___x_2098_; 
v___x_2073_ = ((lean_object*)(l_LearningWorker_bench___closed__6));
v___x_2074_ = l_Lean_JsonNumber_fromNat(v_time_2063_);
v___x_2075_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2075_, 0, v___x_2074_);
v___x_2076_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2076_, 0, v___x_2073_);
lean_ctor_set(v___x_2076_, 1, v___x_2075_);
v___x_2077_ = ((lean_object*)(l_LearningWorker_bench___closed__7));
v___x_2078_ = l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(v_a_2059_);
v___x_2079_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2079_, 0, v___x_2077_);
lean_ctor_set(v___x_2079_, 1, v___x_2078_);
v___x_2080_ = ((lean_object*)(l_LearningWorker_bench___closed__8));
v___x_2081_ = l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(v___x_2067_);
v___x_2082_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2082_, 0, v___x_2080_);
lean_ctor_set(v___x_2082_, 1, v___x_2081_);
v___x_2083_ = ((lean_object*)(l_LearningWorker_bench___closed__9));
v___x_2084_ = l_List_mapTR_loop___at___00LearningWorker_bench_spec__16(v___x_2068_, v___x_2057_);
v___x_2085_ = l_Lean_List_toJson___at___00LearningWorker_bench_spec__15(v___x_2084_);
v___x_2086_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2086_, 0, v___x_2083_);
lean_ctor_set(v___x_2086_, 1, v___x_2085_);
v___x_2087_ = ((lean_object*)(l_LearningWorker_bench___closed__10));
v___x_2088_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_2088_, 0, v___y_2050_);
v___x_2089_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2089_, 0, v___x_2087_);
lean_ctor_set(v___x_2089_, 1, v___x_2088_);
v___x_2090_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2090_, 0, v___x_2089_);
lean_ctor_set(v___x_2090_, 1, v___x_2057_);
v___x_2091_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2091_, 0, v___x_2086_);
lean_ctor_set(v___x_2091_, 1, v___x_2090_);
v___x_2092_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2092_, 0, v___x_2082_);
lean_ctor_set(v___x_2092_, 1, v___x_2091_);
v___x_2093_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2093_, 0, v___x_2079_);
lean_ctor_set(v___x_2093_, 1, v___x_2092_);
v___x_2094_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2094_, 0, v___x_2076_);
lean_ctor_set(v___x_2094_, 1, v___x_2093_);
v___x_2095_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2095_, 0, v___x_2072_);
lean_ctor_set(v___x_2095_, 1, v___x_2094_);
v___x_2096_ = l_Lean_Json_mkObj(v___x_2095_);
lean_dec_ref_known(v___x_2095_, 2);
if (v_isShared_2062_ == 0)
{
lean_ctor_set(v___x_2061_, 0, v___x_2096_);
v___x_2098_ = v___x_2061_;
goto v_reusejp_2097_;
}
else
{
lean_object* v_reuseFailAlloc_2099_; 
v_reuseFailAlloc_2099_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2099_, 0, v___x_2096_);
v___x_2098_ = v_reuseFailAlloc_2099_;
goto v_reusejp_2097_;
}
v_reusejp_2097_:
{
return v___x_2098_;
}
}
}
}
}
else
{
lean_object* v_a_2104_; lean_object* v___x_2106_; uint8_t v_isShared_2107_; uint8_t v_isSharedCheck_2111_; 
lean_dec(v___y_2049_);
lean_dec(v___y_2048_);
lean_dec_ref(v___y_2045_);
lean_dec(v_a_2026_);
v_a_2104_ = lean_ctor_get(v___x_2058_, 0);
v_isSharedCheck_2111_ = !lean_is_exclusive(v___x_2058_);
if (v_isSharedCheck_2111_ == 0)
{
v___x_2106_ = v___x_2058_;
v_isShared_2107_ = v_isSharedCheck_2111_;
goto v_resetjp_2105_;
}
else
{
lean_inc(v_a_2104_);
lean_dec(v___x_2058_);
v___x_2106_ = lean_box(0);
v_isShared_2107_ = v_isSharedCheck_2111_;
goto v_resetjp_2105_;
}
v_resetjp_2105_:
{
lean_object* v___x_2109_; 
if (v_isShared_2107_ == 0)
{
v___x_2109_ = v___x_2106_;
goto v_reusejp_2108_;
}
else
{
lean_object* v_reuseFailAlloc_2110_; 
v_reuseFailAlloc_2110_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2110_, 0, v_a_2104_);
v___x_2109_ = v_reuseFailAlloc_2110_;
goto v_reusejp_2108_;
}
v_reusejp_2108_:
{
return v___x_2109_;
}
}
}
}
else
{
lean_object* v_a_2112_; lean_object* v___x_2114_; uint8_t v_isShared_2115_; uint8_t v_isSharedCheck_2119_; 
lean_dec(v___y_2049_);
lean_dec(v___y_2048_);
lean_dec_ref(v___y_2045_);
lean_dec(v_a_2038_);
lean_dec(v_a_2030_);
lean_dec(v_a_2026_);
v_a_2112_ = lean_ctor_get(v___x_2056_, 0);
v_isSharedCheck_2119_ = !lean_is_exclusive(v___x_2056_);
if (v_isSharedCheck_2119_ == 0)
{
v___x_2114_ = v___x_2056_;
v_isShared_2115_ = v_isSharedCheck_2119_;
goto v_resetjp_2113_;
}
else
{
lean_inc(v_a_2112_);
lean_dec(v___x_2056_);
v___x_2114_ = lean_box(0);
v_isShared_2115_ = v_isSharedCheck_2119_;
goto v_resetjp_2113_;
}
v_resetjp_2113_:
{
lean_object* v___x_2117_; 
if (v_isShared_2115_ == 0)
{
v___x_2117_ = v___x_2114_;
goto v_reusejp_2116_;
}
else
{
lean_object* v_reuseFailAlloc_2118_; 
v_reuseFailAlloc_2118_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2118_, 0, v_a_2112_);
v___x_2117_ = v_reuseFailAlloc_2118_;
goto v_reusejp_2116_;
}
v_reusejp_2116_:
{
return v___x_2117_;
}
}
}
}
}
}
}
else
{
lean_object* v_a_2228_; lean_object* v___x_2230_; uint8_t v_isShared_2231_; uint8_t v_isSharedCheck_2235_; 
lean_dec(v_a_2034_);
lean_dec(v_a_2030_);
lean_dec(v_a_2026_);
lean_dec(v_j_2021_);
v_a_2228_ = lean_ctor_get(v___x_2037_, 0);
v_isSharedCheck_2235_ = !lean_is_exclusive(v___x_2037_);
if (v_isSharedCheck_2235_ == 0)
{
v___x_2230_ = v___x_2037_;
v_isShared_2231_ = v_isSharedCheck_2235_;
goto v_resetjp_2229_;
}
else
{
lean_inc(v_a_2228_);
lean_dec(v___x_2037_);
v___x_2230_ = lean_box(0);
v_isShared_2231_ = v_isSharedCheck_2235_;
goto v_resetjp_2229_;
}
v_resetjp_2229_:
{
lean_object* v___x_2233_; 
if (v_isShared_2231_ == 0)
{
v___x_2233_ = v___x_2230_;
goto v_reusejp_2232_;
}
else
{
lean_object* v_reuseFailAlloc_2234_; 
v_reuseFailAlloc_2234_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2234_, 0, v_a_2228_);
v___x_2233_ = v_reuseFailAlloc_2234_;
goto v_reusejp_2232_;
}
v_reusejp_2232_:
{
return v___x_2233_;
}
}
}
}
else
{
lean_object* v_a_2236_; lean_object* v___x_2238_; uint8_t v_isShared_2239_; uint8_t v_isSharedCheck_2243_; 
lean_dec(v_a_2030_);
lean_dec(v_a_2026_);
lean_dec(v_j_2021_);
v_a_2236_ = lean_ctor_get(v___x_2033_, 0);
v_isSharedCheck_2243_ = !lean_is_exclusive(v___x_2033_);
if (v_isSharedCheck_2243_ == 0)
{
v___x_2238_ = v___x_2033_;
v_isShared_2239_ = v_isSharedCheck_2243_;
goto v_resetjp_2237_;
}
else
{
lean_inc(v_a_2236_);
lean_dec(v___x_2033_);
v___x_2238_ = lean_box(0);
v_isShared_2239_ = v_isSharedCheck_2243_;
goto v_resetjp_2237_;
}
v_resetjp_2237_:
{
lean_object* v___x_2241_; 
if (v_isShared_2239_ == 0)
{
v___x_2241_ = v___x_2238_;
goto v_reusejp_2240_;
}
else
{
lean_object* v_reuseFailAlloc_2242_; 
v_reuseFailAlloc_2242_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2242_, 0, v_a_2236_);
v___x_2241_ = v_reuseFailAlloc_2242_;
goto v_reusejp_2240_;
}
v_reusejp_2240_:
{
return v___x_2241_;
}
}
}
}
else
{
lean_object* v_a_2244_; lean_object* v___x_2246_; uint8_t v_isShared_2247_; uint8_t v_isSharedCheck_2251_; 
lean_dec(v_a_2026_);
lean_dec(v_j_2021_);
v_a_2244_ = lean_ctor_get(v___x_2029_, 0);
v_isSharedCheck_2251_ = !lean_is_exclusive(v___x_2029_);
if (v_isSharedCheck_2251_ == 0)
{
v___x_2246_ = v___x_2029_;
v_isShared_2247_ = v_isSharedCheck_2251_;
goto v_resetjp_2245_;
}
else
{
lean_inc(v_a_2244_);
lean_dec(v___x_2029_);
v___x_2246_ = lean_box(0);
v_isShared_2247_ = v_isSharedCheck_2251_;
goto v_resetjp_2245_;
}
v_resetjp_2245_:
{
lean_object* v___x_2249_; 
if (v_isShared_2247_ == 0)
{
v___x_2249_ = v___x_2246_;
goto v_reusejp_2248_;
}
else
{
lean_object* v_reuseFailAlloc_2250_; 
v_reuseFailAlloc_2250_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2250_, 0, v_a_2244_);
v___x_2249_ = v_reuseFailAlloc_2250_;
goto v_reusejp_2248_;
}
v_reusejp_2248_:
{
return v___x_2249_;
}
}
}
}
else
{
lean_object* v_a_2252_; lean_object* v___x_2254_; uint8_t v_isShared_2255_; uint8_t v_isSharedCheck_2259_; 
lean_dec(v_j_2021_);
v_a_2252_ = lean_ctor_get(v___x_2025_, 0);
v_isSharedCheck_2259_ = !lean_is_exclusive(v___x_2025_);
if (v_isSharedCheck_2259_ == 0)
{
v___x_2254_ = v___x_2025_;
v_isShared_2255_ = v_isSharedCheck_2259_;
goto v_resetjp_2253_;
}
else
{
lean_inc(v_a_2252_);
lean_dec(v___x_2025_);
v___x_2254_ = lean_box(0);
v_isShared_2255_ = v_isSharedCheck_2259_;
goto v_resetjp_2253_;
}
v_resetjp_2253_:
{
lean_object* v___x_2257_; 
if (v_isShared_2255_ == 0)
{
v___x_2257_ = v___x_2254_;
goto v_reusejp_2256_;
}
else
{
lean_object* v_reuseFailAlloc_2258_; 
v_reuseFailAlloc_2258_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2258_, 0, v_a_2252_);
v___x_2257_ = v_reuseFailAlloc_2258_;
goto v_reusejp_2256_;
}
v_reusejp_2256_:
{
return v___x_2257_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_LearningWorker_bench___boxed(lean_object* v_registry_2260_, lean_object* v_j_2261_, lean_object* v_a_2262_){
_start:
{
lean_object* v_res_2263_; 
v_res_2263_ = l_LearningWorker_bench(v_registry_2260_, v_j_2261_);
lean_dec(v_registry_2260_);
return v_res_2263_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3(lean_object* v_val_2264_, lean_object* v_val_2265_, lean_object* v_val_2266_, lean_object* v_a_2267_, lean_object* v_as_2268_, lean_object* v_as_x27_2269_, lean_object* v_b_2270_, lean_object* v_a_2271_){
_start:
{
lean_object* v___x_2273_; 
v___x_2273_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___redArg(v_val_2264_, v_val_2265_, v_val_2266_, v_a_2267_, v_as_x27_2269_, v_b_2270_);
return v___x_2273_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3___boxed(lean_object* v_val_2274_, lean_object* v_val_2275_, lean_object* v_val_2276_, lean_object* v_a_2277_, lean_object* v_as_2278_, lean_object* v_as_x27_2279_, lean_object* v_b_2280_, lean_object* v_a_2281_, lean_object* v___y_2282_){
_start:
{
lean_object* v_res_2283_; 
v_res_2283_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__3(v_val_2274_, v_val_2275_, v_val_2276_, v_a_2277_, v_as_2278_, v_as_x27_2279_, v_b_2280_, v_a_2281_);
lean_dec(v_as_x27_2279_);
lean_dec(v_as_2278_);
lean_dec(v_a_2277_);
lean_dec(v_val_2276_);
lean_dec(v_val_2275_);
lean_dec(v_val_2274_);
return v_res_2283_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__4(lean_object* v_val_2284_, lean_object* v_val_2285_, lean_object* v_val_2286_, lean_object* v_a_2287_, lean_object* v_as_2288_, lean_object* v_as_x27_2289_, lean_object* v_b_2290_, lean_object* v_a_2291_){
_start:
{
lean_object* v___x_2293_; 
v___x_2293_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__4___redArg(v_val_2284_, v_val_2285_, v_val_2286_, v_a_2287_, v_as_x27_2289_, v_b_2290_);
return v___x_2293_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__4___boxed(lean_object* v_val_2294_, lean_object* v_val_2295_, lean_object* v_val_2296_, lean_object* v_a_2297_, lean_object* v_as_2298_, lean_object* v_as_x27_2299_, lean_object* v_b_2300_, lean_object* v_a_2301_, lean_object* v___y_2302_){
_start:
{
lean_object* v_res_2303_; 
v_res_2303_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__4(v_val_2294_, v_val_2295_, v_val_2296_, v_a_2297_, v_as_2298_, v_as_x27_2299_, v_b_2300_, v_a_2301_);
lean_dec(v_as_x27_2299_);
lean_dec(v_as_2298_);
lean_dec(v_a_2297_);
lean_dec(v_val_2296_);
lean_dec(v_val_2295_);
lean_dec(v_val_2294_);
return v_res_2303_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7(lean_object* v_a_2304_, lean_object* v_val_2305_, lean_object* v_val_2306_, lean_object* v_val_2307_, lean_object* v_a_2308_, lean_object* v_as_2309_, lean_object* v_as_x27_2310_, lean_object* v_b_2311_, lean_object* v_a_2312_){
_start:
{
lean_object* v___x_2314_; 
v___x_2314_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7___redArg(v_a_2304_, v_val_2305_, v_val_2306_, v_val_2307_, v_a_2308_, v_as_x27_2310_, v_b_2311_);
return v___x_2314_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7___boxed(lean_object* v_a_2315_, lean_object* v_val_2316_, lean_object* v_val_2317_, lean_object* v_val_2318_, lean_object* v_a_2319_, lean_object* v_as_2320_, lean_object* v_as_x27_2321_, lean_object* v_b_2322_, lean_object* v_a_2323_, lean_object* v___y_2324_){
_start:
{
lean_object* v_res_2325_; 
v_res_2325_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__7(v_a_2315_, v_val_2316_, v_val_2317_, v_val_2318_, v_a_2319_, v_as_2320_, v_as_x27_2321_, v_b_2322_, v_a_2323_);
lean_dec(v_as_x27_2321_);
lean_dec(v_as_2320_);
lean_dec(v_a_2319_);
lean_dec(v_val_2318_);
lean_dec(v_val_2317_);
lean_dec(v_val_2316_);
return v_res_2325_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8(lean_object* v_val_2326_, lean_object* v_val_2327_, lean_object* v_val_2328_, lean_object* v_a_2329_, lean_object* v_a_2330_, lean_object* v___x_2331_, lean_object* v_as_2332_, lean_object* v_as_x27_2333_, lean_object* v_b_2334_, lean_object* v_a_2335_){
_start:
{
lean_object* v___x_2337_; 
v___x_2337_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg(v_val_2326_, v_val_2327_, v_val_2328_, v_a_2329_, v_a_2330_, v___x_2331_, v_as_x27_2333_, v_b_2334_);
return v___x_2337_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___boxed(lean_object* v_val_2338_, lean_object* v_val_2339_, lean_object* v_val_2340_, lean_object* v_a_2341_, lean_object* v_a_2342_, lean_object* v___x_2343_, lean_object* v_as_2344_, lean_object* v_as_x27_2345_, lean_object* v_b_2346_, lean_object* v_a_2347_, lean_object* v___y_2348_){
_start:
{
lean_object* v_res_2349_; 
v_res_2349_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8(v_val_2338_, v_val_2339_, v_val_2340_, v_a_2341_, v_a_2342_, v___x_2343_, v_as_2344_, v_as_x27_2345_, v_b_2346_, v_a_2347_);
lean_dec(v_as_x27_2345_);
lean_dec(v_as_2344_);
lean_dec(v_a_2342_);
lean_dec(v_a_2341_);
lean_dec(v_val_2340_);
lean_dec(v_val_2339_);
lean_dec(v_val_2338_);
return v_res_2349_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11(lean_object* v_val_2350_, lean_object* v_val_2351_, lean_object* v_a_2352_, lean_object* v___x_2353_, lean_object* v_as_2354_, lean_object* v_as_x27_2355_, lean_object* v_b_2356_, lean_object* v_a_2357_){
_start:
{
lean_object* v___x_2359_; 
v___x_2359_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11___redArg(v_val_2350_, v_val_2351_, v_a_2352_, v___x_2353_, v_as_x27_2355_, v_b_2356_);
return v___x_2359_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11___boxed(lean_object* v_val_2360_, lean_object* v_val_2361_, lean_object* v_a_2362_, lean_object* v___x_2363_, lean_object* v_as_2364_, lean_object* v_as_x27_2365_, lean_object* v_b_2366_, lean_object* v_a_2367_, lean_object* v___y_2368_){
_start:
{
lean_object* v_res_2369_; 
v_res_2369_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__11(v_val_2360_, v_val_2361_, v_a_2362_, v___x_2363_, v_as_2364_, v_as_x27_2365_, v_b_2366_, v_a_2367_);
lean_dec(v_as_x27_2365_);
lean_dec(v_as_2364_);
lean_dec(v___x_2363_);
lean_dec(v_val_2361_);
lean_dec(v_val_2360_);
return v_res_2369_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__12(lean_object* v_val_2370_, lean_object* v_val_2371_, lean_object* v___x_2372_, lean_object* v_a_2373_, lean_object* v_as_2374_, lean_object* v_as_x27_2375_, lean_object* v_b_2376_, lean_object* v_a_2377_){
_start:
{
lean_object* v___x_2379_; 
v___x_2379_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__12___redArg(v_val_2370_, v_val_2371_, v___x_2372_, v_a_2373_, v_as_x27_2375_, v_b_2376_);
return v___x_2379_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__12___boxed(lean_object* v_val_2380_, lean_object* v_val_2381_, lean_object* v___x_2382_, lean_object* v_a_2383_, lean_object* v_as_2384_, lean_object* v_as_x27_2385_, lean_object* v_b_2386_, lean_object* v_a_2387_, lean_object* v___y_2388_){
_start:
{
lean_object* v_res_2389_; 
v_res_2389_ = l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__12(v_val_2380_, v_val_2381_, v___x_2382_, v_a_2383_, v_as_2384_, v_as_x27_2385_, v_b_2386_, v_a_2387_);
lean_dec(v_as_x27_2385_);
lean_dec(v_as_2384_);
lean_dec(v_a_2383_);
lean_dec(v___x_2382_);
lean_dec(v_val_2381_);
lean_dec(v_val_2380_);
return v_res_2389_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00LearningWorker_handle_spec__0(lean_object* v_a_2391_, lean_object* v___x_2392_, lean_object* v_a_2393_, lean_object* v_a_2394_){
_start:
{
if (lean_obj_tag(v_a_2393_) == 0)
{
lean_object* v___x_2395_; 
lean_dec(v_a_2391_);
v___x_2395_ = l_List_reverse___redArg(v_a_2394_);
return v___x_2395_;
}
else
{
lean_object* v_head_2396_; lean_object* v_tail_2397_; lean_object* v___x_2399_; uint8_t v_isShared_2400_; uint8_t v_isSharedCheck_2448_; 
v_head_2396_ = lean_ctor_get(v_a_2393_, 0);
v_tail_2397_ = lean_ctor_get(v_a_2393_, 1);
v_isSharedCheck_2448_ = !lean_is_exclusive(v_a_2393_);
if (v_isSharedCheck_2448_ == 0)
{
v___x_2399_ = v_a_2393_;
v_isShared_2400_ = v_isSharedCheck_2448_;
goto v_resetjp_2398_;
}
else
{
lean_inc(v_tail_2397_);
lean_inc(v_head_2396_);
lean_dec(v_a_2393_);
v___x_2399_ = lean_box(0);
v_isShared_2400_ = v_isSharedCheck_2448_;
goto v_resetjp_2398_;
}
v_resetjp_2398_:
{
lean_object* v_fst_2401_; lean_object* v_snd_2402_; lean_object* v___x_2404_; uint8_t v_isShared_2405_; uint8_t v_isSharedCheck_2447_; 
v_fst_2401_ = lean_ctor_get(v_head_2396_, 0);
v_snd_2402_ = lean_ctor_get(v_head_2396_, 1);
v_isSharedCheck_2447_ = !lean_is_exclusive(v_head_2396_);
if (v_isSharedCheck_2447_ == 0)
{
v___x_2404_ = v_head_2396_;
v_isShared_2405_ = v_isSharedCheck_2447_;
goto v_resetjp_2403_;
}
else
{
lean_inc(v_snd_2402_);
lean_inc(v_fst_2401_);
lean_dec(v_head_2396_);
v___x_2404_ = lean_box(0);
v_isShared_2405_ = v_isSharedCheck_2447_;
goto v_resetjp_2403_;
}
v_resetjp_2403_:
{
lean_object* v___x_2406_; lean_object* v___x_2407_; lean_object* v___x_2409_; 
v___x_2406_ = ((lean_object*)(l_LearningWorker_sampleEvent___closed__5));
v___x_2407_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v___x_2407_, 0, v_fst_2401_);
if (v_isShared_2405_ == 0)
{
lean_ctor_set(v___x_2404_, 1, v___x_2407_);
lean_ctor_set(v___x_2404_, 0, v___x_2406_);
v___x_2409_ = v___x_2404_;
goto v_reusejp_2408_;
}
else
{
lean_object* v_reuseFailAlloc_2446_; 
v_reuseFailAlloc_2446_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2446_, 0, v___x_2406_);
lean_ctor_set(v_reuseFailAlloc_2446_, 1, v___x_2407_);
v___x_2409_ = v_reuseFailAlloc_2446_;
goto v_reusejp_2408_;
}
v_reusejp_2408_:
{
lean_object* v___x_2410_; lean_object* v___x_2411_; lean_object* v___x_2412_; lean_object* v___x_2413_; lean_object* v___x_2414_; lean_object* v___x_2415_; lean_object* v___x_2416_; lean_object* v___x_2417_; lean_object* v___x_2418_; lean_object* v___x_2419_; lean_object* v___x_2420_; lean_object* v___x_2421_; lean_object* v___x_2422_; lean_object* v___x_2423_; lean_object* v___y_2425_; 
v___x_2410_ = ((lean_object*)(l_List_mapTR_loop___at___00LearningWorker_bench_spec__14___closed__0));
lean_inc_n(v_snd_2402_, 2);
v___x_2411_ = l_LeanSort_LearnedSelection_select(v_snd_2402_, v_a_2391_);
lean_inc(v___x_2411_);
v___x_2412_ = l_Lean_Option_toJson___at___00LearningWorker_bench_spec__9(v___x_2411_);
v___x_2413_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2413_, 0, v___x_2410_);
lean_ctor_set(v___x_2413_, 1, v___x_2412_);
v___x_2414_ = ((lean_object*)(l_LearningWorker_sampleEvent___closed__8));
v___x_2415_ = l_LeanSort_LearnedSelection_resolve(v___x_2411_);
lean_dec(v___x_2411_);
v___x_2416_ = l_Lean_JsonNumber_fromNat(v___x_2415_);
v___x_2417_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2417_, 0, v___x_2416_);
v___x_2418_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2418_, 0, v___x_2414_);
lean_ctor_set(v___x_2418_, 1, v___x_2417_);
v___x_2419_ = ((lean_object*)(l_List_mapTR_loop___at___00LearningWorker_handle_spec__0___closed__0));
lean_inc(v_a_2391_);
v___x_2420_ = l_LeanSort_LearnedSelection_run(v_snd_2402_, v_a_2391_);
v___x_2421_ = l_Lean_List_toJson___at___00LearningWorker_bench_spec__15(v___x_2420_);
v___x_2422_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2422_, 0, v___x_2419_);
lean_ctor_set(v___x_2422_, 1, v___x_2421_);
v___x_2423_ = ((lean_object*)(l_LearningWorker_decodeTree___closed__11));
if (lean_obj_tag(v_snd_2402_) == 3)
{
lean_object* v_model_2439_; 
v_model_2439_ = lean_ctor_get(v_snd_2402_, 0);
lean_inc(v_model_2439_);
lean_dec_ref_known(v_snd_2402_, 1);
switch(lean_obj_tag(v_model_2439_))
{
case 1:
{
lean_object* v_tree_2440_; lean_object* v___x_2441_; 
v_tree_2440_ = lean_ctor_get(v_model_2439_, 0);
lean_inc_ref(v_tree_2440_);
lean_dec_ref_known(v_model_2439_, 1);
v___x_2441_ = l_LeanSort_LearnedSelection_Tree_eval(v_tree_2440_, v___x_2392_);
v___y_2425_ = v___x_2441_;
goto v___jp_2424_;
}
case 2:
{
lean_object* v_tree_2442_; lean_object* v___x_2443_; 
v_tree_2442_ = lean_ctor_get(v_model_2439_, 0);
lean_inc_ref(v_tree_2442_);
lean_dec_ref_known(v_model_2439_, 1);
v___x_2443_ = l_LeanSort_LearnedSelection_Tree_eval(v_tree_2442_, v___x_2392_);
v___y_2425_ = v___x_2443_;
goto v___jp_2424_;
}
default: 
{
lean_object* v___x_2444_; 
lean_dec(v_model_2439_);
v___x_2444_ = lean_box(0);
v___y_2425_ = v___x_2444_;
goto v___jp_2424_;
}
}
}
else
{
lean_object* v___x_2445_; 
lean_dec(v_snd_2402_);
v___x_2445_ = lean_box(0);
v___y_2425_ = v___x_2445_;
goto v___jp_2424_;
}
v___jp_2424_:
{
lean_object* v___x_2426_; lean_object* v___x_2427_; lean_object* v___x_2428_; lean_object* v___x_2430_; 
v___x_2426_ = l_Lean_Option_toJson___at___00LearningWorker_bench_spec__10(v___y_2425_);
v___x_2427_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2427_, 0, v___x_2423_);
lean_ctor_set(v___x_2427_, 1, v___x_2426_);
v___x_2428_ = lean_box(0);
if (v_isShared_2400_ == 0)
{
lean_ctor_set(v___x_2399_, 1, v___x_2428_);
lean_ctor_set(v___x_2399_, 0, v___x_2427_);
v___x_2430_ = v___x_2399_;
goto v_reusejp_2429_;
}
else
{
lean_object* v_reuseFailAlloc_2438_; 
v_reuseFailAlloc_2438_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2438_, 0, v___x_2427_);
lean_ctor_set(v_reuseFailAlloc_2438_, 1, v___x_2428_);
v___x_2430_ = v_reuseFailAlloc_2438_;
goto v_reusejp_2429_;
}
v_reusejp_2429_:
{
lean_object* v___x_2431_; lean_object* v___x_2432_; lean_object* v___x_2433_; lean_object* v___x_2434_; lean_object* v___x_2435_; lean_object* v___x_2436_; 
v___x_2431_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2431_, 0, v___x_2422_);
lean_ctor_set(v___x_2431_, 1, v___x_2430_);
v___x_2432_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2432_, 0, v___x_2418_);
lean_ctor_set(v___x_2432_, 1, v___x_2431_);
v___x_2433_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2433_, 0, v___x_2413_);
lean_ctor_set(v___x_2433_, 1, v___x_2432_);
v___x_2434_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2434_, 0, v___x_2409_);
lean_ctor_set(v___x_2434_, 1, v___x_2433_);
v___x_2435_ = l_Lean_Json_mkObj(v___x_2434_);
lean_dec_ref_known(v___x_2434_, 2);
v___x_2436_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2436_, 0, v___x_2435_);
lean_ctor_set(v___x_2436_, 1, v_a_2394_);
v_a_2393_ = v_tail_2397_;
v_a_2394_ = v___x_2436_;
goto _start;
}
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00LearningWorker_handle_spec__0___boxed(lean_object* v_a_2449_, lean_object* v___x_2450_, lean_object* v_a_2451_, lean_object* v_a_2452_){
_start:
{
lean_object* v_res_2453_; 
v_res_2453_ = l_List_mapTR_loop___at___00LearningWorker_handle_spec__0(v_a_2449_, v___x_2450_, v_a_2451_, v_a_2452_);
lean_dec(v___x_2450_);
return v_res_2453_;
}
}
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00LearningWorker_handle_spec__2(lean_object* v_x_2454_, lean_object* v_x_2455_){
_start:
{
if (lean_obj_tag(v_x_2454_) == 0)
{
lean_object* v___x_2457_; lean_object* v___x_2458_; 
v___x_2457_ = l_List_reverse___redArg(v_x_2455_);
v___x_2458_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2458_, 0, v___x_2457_);
return v___x_2458_;
}
else
{
lean_object* v_head_2459_; lean_object* v_tail_2460_; lean_object* v___x_2462_; uint8_t v_isShared_2463_; uint8_t v_isSharedCheck_2494_; 
v_head_2459_ = lean_ctor_get(v_x_2454_, 0);
v_tail_2460_ = lean_ctor_get(v_x_2454_, 1);
v_isSharedCheck_2494_ = !lean_is_exclusive(v_x_2454_);
if (v_isSharedCheck_2494_ == 0)
{
v___x_2462_ = v_x_2454_;
v_isShared_2463_ = v_isSharedCheck_2494_;
goto v_resetjp_2461_;
}
else
{
lean_inc(v_tail_2460_);
lean_inc(v_head_2459_);
lean_dec(v_x_2454_);
v___x_2462_ = lean_box(0);
v_isShared_2463_ = v_isSharedCheck_2494_;
goto v_resetjp_2461_;
}
v_resetjp_2461_:
{
lean_object* v___x_2464_; lean_object* v___x_2465_; lean_object* v___x_2466_; 
v___x_2464_ = ((lean_object*)(l_LearningWorker_sampleEvent___closed__5));
lean_inc(v_head_2459_);
v___x_2465_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_head_2459_, v___x_2464_);
v___x_2466_ = l_LearningWorker_orError___redArg(v___x_2465_);
if (lean_obj_tag(v___x_2466_) == 0)
{
lean_object* v_a_2467_; lean_object* v___x_2468_; lean_object* v___x_2469_; lean_object* v___x_2470_; 
v_a_2467_ = lean_ctor_get(v___x_2466_, 0);
lean_inc(v_a_2467_);
lean_dec_ref_known(v___x_2466_, 1);
v___x_2468_ = ((lean_object*)(l_List_mapTR_loop___at___00LearningWorker_bench_spec__6___closed__0));
v___x_2469_ = l_Lean_Json_getObjVal_x3f(v_head_2459_, v___x_2468_);
v___x_2470_ = l_LearningWorker_orError___redArg(v___x_2469_);
if (lean_obj_tag(v___x_2470_) == 0)
{
lean_object* v_a_2471_; lean_object* v___x_2472_; lean_object* v___x_2473_; lean_object* v___x_2475_; 
v_a_2471_ = lean_ctor_get(v___x_2470_, 0);
lean_inc(v_a_2471_);
lean_dec_ref_known(v___x_2470_, 1);
v___x_2472_ = l_LearningWorker_decodePolicy(v_a_2471_);
v___x_2473_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2473_, 0, v_a_2467_);
lean_ctor_set(v___x_2473_, 1, v___x_2472_);
if (v_isShared_2463_ == 0)
{
lean_ctor_set(v___x_2462_, 1, v_x_2455_);
lean_ctor_set(v___x_2462_, 0, v___x_2473_);
v___x_2475_ = v___x_2462_;
goto v_reusejp_2474_;
}
else
{
lean_object* v_reuseFailAlloc_2477_; 
v_reuseFailAlloc_2477_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_2477_, 0, v___x_2473_);
lean_ctor_set(v_reuseFailAlloc_2477_, 1, v_x_2455_);
v___x_2475_ = v_reuseFailAlloc_2477_;
goto v_reusejp_2474_;
}
v_reusejp_2474_:
{
v_x_2454_ = v_tail_2460_;
v_x_2455_ = v___x_2475_;
goto _start;
}
}
else
{
lean_object* v_a_2478_; lean_object* v___x_2480_; uint8_t v_isShared_2481_; uint8_t v_isSharedCheck_2485_; 
lean_dec(v_a_2467_);
lean_del_object(v___x_2462_);
lean_dec(v_tail_2460_);
lean_dec(v_x_2455_);
v_a_2478_ = lean_ctor_get(v___x_2470_, 0);
v_isSharedCheck_2485_ = !lean_is_exclusive(v___x_2470_);
if (v_isSharedCheck_2485_ == 0)
{
v___x_2480_ = v___x_2470_;
v_isShared_2481_ = v_isSharedCheck_2485_;
goto v_resetjp_2479_;
}
else
{
lean_inc(v_a_2478_);
lean_dec(v___x_2470_);
v___x_2480_ = lean_box(0);
v_isShared_2481_ = v_isSharedCheck_2485_;
goto v_resetjp_2479_;
}
v_resetjp_2479_:
{
lean_object* v___x_2483_; 
if (v_isShared_2481_ == 0)
{
v___x_2483_ = v___x_2480_;
goto v_reusejp_2482_;
}
else
{
lean_object* v_reuseFailAlloc_2484_; 
v_reuseFailAlloc_2484_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2484_, 0, v_a_2478_);
v___x_2483_ = v_reuseFailAlloc_2484_;
goto v_reusejp_2482_;
}
v_reusejp_2482_:
{
return v___x_2483_;
}
}
}
}
else
{
lean_object* v_a_2486_; lean_object* v___x_2488_; uint8_t v_isShared_2489_; uint8_t v_isSharedCheck_2493_; 
lean_del_object(v___x_2462_);
lean_dec(v_tail_2460_);
lean_dec(v_head_2459_);
lean_dec(v_x_2455_);
v_a_2486_ = lean_ctor_get(v___x_2466_, 0);
v_isSharedCheck_2493_ = !lean_is_exclusive(v___x_2466_);
if (v_isSharedCheck_2493_ == 0)
{
v___x_2488_ = v___x_2466_;
v_isShared_2489_ = v_isSharedCheck_2493_;
goto v_resetjp_2487_;
}
else
{
lean_inc(v_a_2486_);
lean_dec(v___x_2466_);
v___x_2488_ = lean_box(0);
v_isShared_2489_ = v_isSharedCheck_2493_;
goto v_resetjp_2487_;
}
v_resetjp_2487_:
{
lean_object* v___x_2491_; 
if (v_isShared_2489_ == 0)
{
v___x_2491_ = v___x_2488_;
goto v_reusejp_2490_;
}
else
{
lean_object* v_reuseFailAlloc_2492_; 
v_reuseFailAlloc_2492_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2492_, 0, v_a_2486_);
v___x_2491_ = v_reuseFailAlloc_2492_;
goto v_reusejp_2490_;
}
v_reusejp_2490_:
{
return v___x_2491_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapM_loop___at___00LearningWorker_handle_spec__2___boxed(lean_object* v_x_2495_, lean_object* v_x_2496_, lean_object* v___y_2497_){
_start:
{
lean_object* v_res_2498_; 
v_res_2498_ = l_List_mapM_loop___at___00LearningWorker_handle_spec__2(v_x_2495_, v_x_2496_);
return v_res_2498_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00LearningWorker_handle_spec__1_spec__1(lean_object* v_j_2499_){
_start:
{
lean_object* v___x_2500_; 
v___x_2500_ = l_Lean_Array_fromJson_x3f___at___00Lean_Widget_instRpcEncodableStrictOrLazy_dec_00___x40_Lean_Widget_InteractiveDiagnostic_2157017296____hygCtx___hyg_1____at___00Lean_Widget_instRpcEncodableHighlightedMsgEmbed_dec_00___x40_Lean_Server_FileWorker_WidgetRequests_2377472685____hygCtx___hyg_1__spec__2_spec__3(v_j_2499_);
if (lean_obj_tag(v___x_2500_) == 0)
{
lean_object* v_a_2501_; lean_object* v___x_2503_; uint8_t v_isShared_2504_; uint8_t v_isSharedCheck_2508_; 
v_a_2501_ = lean_ctor_get(v___x_2500_, 0);
v_isSharedCheck_2508_ = !lean_is_exclusive(v___x_2500_);
if (v_isSharedCheck_2508_ == 0)
{
v___x_2503_ = v___x_2500_;
v_isShared_2504_ = v_isSharedCheck_2508_;
goto v_resetjp_2502_;
}
else
{
lean_inc(v_a_2501_);
lean_dec(v___x_2500_);
v___x_2503_ = lean_box(0);
v_isShared_2504_ = v_isSharedCheck_2508_;
goto v_resetjp_2502_;
}
v_resetjp_2502_:
{
lean_object* v___x_2506_; 
if (v_isShared_2504_ == 0)
{
v___x_2506_ = v___x_2503_;
goto v_reusejp_2505_;
}
else
{
lean_object* v_reuseFailAlloc_2507_; 
v_reuseFailAlloc_2507_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2507_, 0, v_a_2501_);
v___x_2506_ = v_reuseFailAlloc_2507_;
goto v_reusejp_2505_;
}
v_reusejp_2505_:
{
return v___x_2506_;
}
}
}
else
{
lean_object* v_a_2509_; lean_object* v___x_2511_; uint8_t v_isShared_2512_; uint8_t v_isSharedCheck_2517_; 
v_a_2509_ = lean_ctor_get(v___x_2500_, 0);
v_isSharedCheck_2517_ = !lean_is_exclusive(v___x_2500_);
if (v_isSharedCheck_2517_ == 0)
{
v___x_2511_ = v___x_2500_;
v_isShared_2512_ = v_isSharedCheck_2517_;
goto v_resetjp_2510_;
}
else
{
lean_inc(v_a_2509_);
lean_dec(v___x_2500_);
v___x_2511_ = lean_box(0);
v_isShared_2512_ = v_isSharedCheck_2517_;
goto v_resetjp_2510_;
}
v_resetjp_2510_:
{
lean_object* v___x_2513_; lean_object* v___x_2515_; 
v___x_2513_ = lean_array_to_list(v_a_2509_);
if (v_isShared_2512_ == 0)
{
lean_ctor_set(v___x_2511_, 0, v___x_2513_);
v___x_2515_ = v___x_2511_;
goto v_reusejp_2514_;
}
else
{
lean_object* v_reuseFailAlloc_2516_; 
v_reuseFailAlloc_2516_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2516_, 0, v___x_2513_);
v___x_2515_ = v_reuseFailAlloc_2516_;
goto v_reusejp_2514_;
}
v_reusejp_2514_:
{
return v___x_2515_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_handle_spec__1(lean_object* v_j_2518_, lean_object* v_k_2519_){
_start:
{
lean_object* v___x_2520_; lean_object* v___x_2521_; 
v___x_2520_ = l_Lean_Json_getObjValD(v_j_2518_, v_k_2519_);
v___x_2521_ = l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00LearningWorker_handle_spec__1_spec__1(v___x_2520_);
return v___x_2521_;
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_handle_spec__1___boxed(lean_object* v_j_2522_, lean_object* v_k_2523_){
_start:
{
lean_object* v_res_2524_; 
v_res_2524_ = l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_handle_spec__1(v_j_2522_, v_k_2523_);
lean_dec_ref(v_k_2523_);
return v_res_2524_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_handle(lean_object* v_state_2534_, lean_object* v_j_2535_){
_start:
{
lean_object* v___x_2537_; lean_object* v___x_2538_; lean_object* v___x_2539_; 
v___x_2537_ = ((lean_object*)(l_LearningWorker_handle___closed__0));
lean_inc(v_j_2535_);
v___x_2538_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Server_Test_Runner_Client_instFromJsonSubexprInfo_fromJson_spec__1(v_j_2535_, v___x_2537_);
v___x_2539_ = l_LearningWorker_orError___redArg(v___x_2538_);
if (lean_obj_tag(v___x_2539_) == 0)
{
lean_object* v_a_2540_; lean_object* v___x_2542_; uint8_t v_isShared_2543_; uint8_t v_isSharedCheck_2626_; 
v_a_2540_ = lean_ctor_get(v___x_2539_, 0);
v_isSharedCheck_2626_ = !lean_is_exclusive(v___x_2539_);
if (v_isSharedCheck_2626_ == 0)
{
v___x_2542_ = v___x_2539_;
v_isShared_2543_ = v_isSharedCheck_2626_;
goto v_resetjp_2541_;
}
else
{
lean_inc(v_a_2540_);
lean_dec(v___x_2539_);
v___x_2542_ = lean_box(0);
v_isShared_2543_ = v_isSharedCheck_2626_;
goto v_resetjp_2541_;
}
v_resetjp_2541_:
{
lean_object* v___x_2544_; uint8_t v___x_2545_; 
v___x_2544_ = ((lean_object*)(l_LearningWorker_handle___closed__1));
v___x_2545_ = lean_string_dec_eq(v_a_2540_, v___x_2544_);
if (v___x_2545_ == 0)
{
lean_object* v___x_2546_; uint8_t v___x_2547_; 
v___x_2546_ = ((lean_object*)(l_LearningWorker_handle___closed__2));
v___x_2547_ = lean_string_dec_eq(v_a_2540_, v___x_2546_);
if (v___x_2547_ == 0)
{
lean_object* v___x_2548_; uint8_t v___x_2549_; 
v___x_2548_ = ((lean_object*)(l_LearningWorker_handle___closed__3));
v___x_2549_ = lean_string_dec_eq(v_a_2540_, v___x_2548_);
lean_dec(v_a_2540_);
if (v___x_2549_ == 0)
{
lean_object* v___x_2550_; lean_object* v___x_2552_; 
lean_dec(v_j_2535_);
v___x_2550_ = ((lean_object*)(l_LearningWorker_handle___closed__5));
if (v_isShared_2543_ == 0)
{
lean_ctor_set_tag(v___x_2542_, 1);
lean_ctor_set(v___x_2542_, 0, v___x_2550_);
v___x_2552_ = v___x_2542_;
goto v_reusejp_2551_;
}
else
{
lean_object* v_reuseFailAlloc_2553_; 
v_reuseFailAlloc_2553_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2553_, 0, v___x_2550_);
v___x_2552_ = v_reuseFailAlloc_2553_;
goto v_reusejp_2551_;
}
v_reusejp_2551_:
{
return v___x_2552_;
}
}
else
{
lean_object* v___x_2554_; lean_object* v___x_2555_; lean_object* v___x_2556_; 
lean_del_object(v___x_2542_);
v___x_2554_ = ((lean_object*)(l_LearningWorker_bench___closed__0));
v___x_2555_ = l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_bench_spec__1(v_j_2535_, v___x_2554_);
v___x_2556_ = l_LearningWorker_orError___redArg(v___x_2555_);
if (lean_obj_tag(v___x_2556_) == 0)
{
lean_object* v_a_2557_; lean_object* v___x_2559_; uint8_t v_isShared_2560_; uint8_t v_isSharedCheck_2577_; 
v_a_2557_ = lean_ctor_get(v___x_2556_, 0);
v_isSharedCheck_2577_ = !lean_is_exclusive(v___x_2556_);
if (v_isSharedCheck_2577_ == 0)
{
v___x_2559_ = v___x_2556_;
v_isShared_2560_ = v_isSharedCheck_2577_;
goto v_resetjp_2558_;
}
else
{
lean_inc(v_a_2557_);
lean_dec(v___x_2556_);
v___x_2559_ = lean_box(0);
v_isShared_2560_ = v_isSharedCheck_2577_;
goto v_resetjp_2558_;
}
v_resetjp_2558_:
{
lean_object* v___x_2561_; lean_object* v___x_2562_; lean_object* v___x_2563_; lean_object* v___x_2564_; lean_object* v___x_2565_; lean_object* v___x_2566_; lean_object* v___x_2567_; lean_object* v___x_2568_; lean_object* v___x_2569_; lean_object* v___x_2570_; lean_object* v___x_2571_; lean_object* v___x_2572_; lean_object* v___x_2573_; lean_object* v___x_2575_; 
v___x_2561_ = lean_st_ref_get(v_state_2534_);
v___x_2562_ = l_LeanSort_LearnedSelection_features(v_a_2557_);
v___x_2563_ = lean_box(0);
v___x_2564_ = l_List_mapTR_loop___at___00LearningWorker_handle_spec__0(v_a_2557_, v___x_2562_, v___x_2561_, v___x_2563_);
v___x_2565_ = ((lean_object*)(l_List_forIn_x27_loop___at___00LearningWorker_bench_spec__8___redArg___closed__0));
v___x_2566_ = l_Lean_List_toJson___at___00LearningWorker_bench_spec__15(v___x_2562_);
v___x_2567_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2567_, 0, v___x_2565_);
lean_ctor_set(v___x_2567_, 1, v___x_2566_);
v___x_2568_ = ((lean_object*)(l_LearningWorker_handle___closed__6));
v___x_2569_ = l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(v___x_2564_);
v___x_2570_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2570_, 0, v___x_2568_);
lean_ctor_set(v___x_2570_, 1, v___x_2569_);
v___x_2571_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2571_, 0, v___x_2570_);
lean_ctor_set(v___x_2571_, 1, v___x_2563_);
v___x_2572_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2572_, 0, v___x_2567_);
lean_ctor_set(v___x_2572_, 1, v___x_2571_);
v___x_2573_ = l_Lean_Json_mkObj(v___x_2572_);
lean_dec_ref_known(v___x_2572_, 2);
if (v_isShared_2560_ == 0)
{
lean_ctor_set(v___x_2559_, 0, v___x_2573_);
v___x_2575_ = v___x_2559_;
goto v_reusejp_2574_;
}
else
{
lean_object* v_reuseFailAlloc_2576_; 
v_reuseFailAlloc_2576_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2576_, 0, v___x_2573_);
v___x_2575_ = v_reuseFailAlloc_2576_;
goto v_reusejp_2574_;
}
v_reusejp_2574_:
{
return v___x_2575_;
}
}
}
else
{
lean_object* v_a_2578_; lean_object* v___x_2580_; uint8_t v_isShared_2581_; uint8_t v_isSharedCheck_2585_; 
v_a_2578_ = lean_ctor_get(v___x_2556_, 0);
v_isSharedCheck_2585_ = !lean_is_exclusive(v___x_2556_);
if (v_isSharedCheck_2585_ == 0)
{
v___x_2580_ = v___x_2556_;
v_isShared_2581_ = v_isSharedCheck_2585_;
goto v_resetjp_2579_;
}
else
{
lean_inc(v_a_2578_);
lean_dec(v___x_2556_);
v___x_2580_ = lean_box(0);
v_isShared_2581_ = v_isSharedCheck_2585_;
goto v_resetjp_2579_;
}
v_resetjp_2579_:
{
lean_object* v___x_2583_; 
if (v_isShared_2581_ == 0)
{
v___x_2583_ = v___x_2580_;
goto v_reusejp_2582_;
}
else
{
lean_object* v_reuseFailAlloc_2584_; 
v_reuseFailAlloc_2584_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2584_, 0, v_a_2578_);
v___x_2583_ = v_reuseFailAlloc_2584_;
goto v_reusejp_2582_;
}
v_reusejp_2582_:
{
return v___x_2583_;
}
}
}
}
}
else
{
lean_object* v___x_2586_; lean_object* v___x_2587_; 
lean_del_object(v___x_2542_);
lean_dec(v_a_2540_);
v___x_2586_ = lean_st_ref_get(v_state_2534_);
v___x_2587_ = l_LearningWorker_bench(v___x_2586_, v_j_2535_);
lean_dec(v___x_2586_);
return v___x_2587_;
}
}
else
{
lean_object* v___x_2588_; lean_object* v___x_2589_; lean_object* v___x_2590_; 
lean_del_object(v___x_2542_);
lean_dec(v_a_2540_);
v___x_2588_ = ((lean_object*)(l_LearningWorker_bench___closed__11));
v___x_2589_ = l_Lean_Json_getObjValAs_x3f___at___00LearningWorker_handle_spec__1(v_j_2535_, v___x_2588_);
v___x_2590_ = l_LearningWorker_orError___redArg(v___x_2589_);
if (lean_obj_tag(v___x_2590_) == 0)
{
lean_object* v_a_2591_; lean_object* v___x_2592_; lean_object* v___x_2593_; 
v_a_2591_ = lean_ctor_get(v___x_2590_, 0);
lean_inc(v_a_2591_);
lean_dec_ref_known(v___x_2590_, 1);
v___x_2592_ = lean_box(0);
v___x_2593_ = l_List_mapM_loop___at___00LearningWorker_handle_spec__2(v_a_2591_, v___x_2592_);
if (lean_obj_tag(v___x_2593_) == 0)
{
lean_object* v_a_2594_; lean_object* v___x_2596_; uint8_t v_isShared_2597_; uint8_t v_isSharedCheck_2609_; 
v_a_2594_ = lean_ctor_get(v___x_2593_, 0);
v_isSharedCheck_2609_ = !lean_is_exclusive(v___x_2593_);
if (v_isSharedCheck_2609_ == 0)
{
v___x_2596_ = v___x_2593_;
v_isShared_2597_ = v_isSharedCheck_2609_;
goto v_resetjp_2595_;
}
else
{
lean_inc(v_a_2594_);
lean_dec(v___x_2593_);
v___x_2596_ = lean_box(0);
v_isShared_2597_ = v_isSharedCheck_2609_;
goto v_resetjp_2595_;
}
v_resetjp_2595_:
{
lean_object* v___x_2598_; lean_object* v___x_2599_; lean_object* v___x_2600_; lean_object* v___x_2601_; lean_object* v___x_2602_; lean_object* v___x_2603_; lean_object* v___x_2604_; lean_object* v___x_2605_; lean_object* v___x_2607_; 
lean_inc(v_a_2594_);
v___x_2598_ = lean_st_ref_set(v_state_2534_, v_a_2594_);
v___x_2599_ = ((lean_object*)(l_LearningWorker_handle___closed__7));
v___x_2600_ = l_List_lengthTR___redArg(v_a_2594_);
lean_dec(v_a_2594_);
v___x_2601_ = l_Lean_JsonNumber_fromNat(v___x_2600_);
v___x_2602_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_2602_, 0, v___x_2601_);
v___x_2603_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2603_, 0, v___x_2599_);
lean_ctor_set(v___x_2603_, 1, v___x_2602_);
v___x_2604_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2604_, 0, v___x_2603_);
lean_ctor_set(v___x_2604_, 1, v___x_2592_);
v___x_2605_ = l_Lean_Json_mkObj(v___x_2604_);
lean_dec_ref_known(v___x_2604_, 2);
if (v_isShared_2597_ == 0)
{
lean_ctor_set(v___x_2596_, 0, v___x_2605_);
v___x_2607_ = v___x_2596_;
goto v_reusejp_2606_;
}
else
{
lean_object* v_reuseFailAlloc_2608_; 
v_reuseFailAlloc_2608_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2608_, 0, v___x_2605_);
v___x_2607_ = v_reuseFailAlloc_2608_;
goto v_reusejp_2606_;
}
v_reusejp_2606_:
{
return v___x_2607_;
}
}
}
else
{
lean_object* v_a_2610_; lean_object* v___x_2612_; uint8_t v_isShared_2613_; uint8_t v_isSharedCheck_2617_; 
v_a_2610_ = lean_ctor_get(v___x_2593_, 0);
v_isSharedCheck_2617_ = !lean_is_exclusive(v___x_2593_);
if (v_isSharedCheck_2617_ == 0)
{
v___x_2612_ = v___x_2593_;
v_isShared_2613_ = v_isSharedCheck_2617_;
goto v_resetjp_2611_;
}
else
{
lean_inc(v_a_2610_);
lean_dec(v___x_2593_);
v___x_2612_ = lean_box(0);
v_isShared_2613_ = v_isSharedCheck_2617_;
goto v_resetjp_2611_;
}
v_resetjp_2611_:
{
lean_object* v___x_2615_; 
if (v_isShared_2613_ == 0)
{
v___x_2615_ = v___x_2612_;
goto v_reusejp_2614_;
}
else
{
lean_object* v_reuseFailAlloc_2616_; 
v_reuseFailAlloc_2616_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2616_, 0, v_a_2610_);
v___x_2615_ = v_reuseFailAlloc_2616_;
goto v_reusejp_2614_;
}
v_reusejp_2614_:
{
return v___x_2615_;
}
}
}
}
else
{
lean_object* v_a_2618_; lean_object* v___x_2620_; uint8_t v_isShared_2621_; uint8_t v_isSharedCheck_2625_; 
v_a_2618_ = lean_ctor_get(v___x_2590_, 0);
v_isSharedCheck_2625_ = !lean_is_exclusive(v___x_2590_);
if (v_isSharedCheck_2625_ == 0)
{
v___x_2620_ = v___x_2590_;
v_isShared_2621_ = v_isSharedCheck_2625_;
goto v_resetjp_2619_;
}
else
{
lean_inc(v_a_2618_);
lean_dec(v___x_2590_);
v___x_2620_ = lean_box(0);
v_isShared_2621_ = v_isSharedCheck_2625_;
goto v_resetjp_2619_;
}
v_resetjp_2619_:
{
lean_object* v___x_2623_; 
if (v_isShared_2621_ == 0)
{
v___x_2623_ = v___x_2620_;
goto v_reusejp_2622_;
}
else
{
lean_object* v_reuseFailAlloc_2624_; 
v_reuseFailAlloc_2624_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2624_, 0, v_a_2618_);
v___x_2623_ = v_reuseFailAlloc_2624_;
goto v_reusejp_2622_;
}
v_reusejp_2622_:
{
return v___x_2623_;
}
}
}
}
}
}
else
{
lean_object* v_a_2627_; lean_object* v___x_2629_; uint8_t v_isShared_2630_; uint8_t v_isSharedCheck_2634_; 
lean_dec(v_j_2535_);
v_a_2627_ = lean_ctor_get(v___x_2539_, 0);
v_isSharedCheck_2634_ = !lean_is_exclusive(v___x_2539_);
if (v_isSharedCheck_2634_ == 0)
{
v___x_2629_ = v___x_2539_;
v_isShared_2630_ = v_isSharedCheck_2634_;
goto v_resetjp_2628_;
}
else
{
lean_inc(v_a_2627_);
lean_dec(v___x_2539_);
v___x_2629_ = lean_box(0);
v_isShared_2630_ = v_isSharedCheck_2634_;
goto v_resetjp_2628_;
}
v_resetjp_2628_:
{
lean_object* v___x_2632_; 
if (v_isShared_2630_ == 0)
{
v___x_2632_ = v___x_2629_;
goto v_reusejp_2631_;
}
else
{
lean_object* v_reuseFailAlloc_2633_; 
v_reuseFailAlloc_2633_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2633_, 0, v_a_2627_);
v___x_2632_ = v_reuseFailAlloc_2633_;
goto v_reusejp_2631_;
}
v_reusejp_2631_:
{
return v___x_2632_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_LearningWorker_handle___boxed(lean_object* v_state_2635_, lean_object* v_j_2636_, lean_object* v_a_2637_){
_start:
{
lean_object* v_res_2638_; 
v_res_2638_ = l_LearningWorker_handle(v_state_2635_, v_j_2636_);
lean_dec(v_state_2635_);
return v_res_2638_;
}
}
LEAN_EXPORT lean_object* l_LearningWorker_loop(lean_object* v_state_2647_){
_start:
{
lean_object* v_a_2650_; lean_object* v___y_2661_; lean_object* v___x_2677_; lean_object* v_getLine_2678_; lean_object* v___x_2679_; 
v___x_2677_ = lean_get_stdin();
v_getLine_2678_ = lean_ctor_get(v___x_2677_, 3);
lean_inc_ref(v_getLine_2678_);
lean_dec_ref(v___x_2677_);
v___x_2679_ = lean_apply_1(v_getLine_2678_, lean_box(0));
if (lean_obj_tag(v___x_2679_) == 0)
{
lean_object* v_a_2680_; lean_object* v___x_2682_; uint8_t v_isShared_2683_; uint8_t v_isSharedCheck_2695_; 
v_a_2680_ = lean_ctor_get(v___x_2679_, 0);
v_isSharedCheck_2695_ = !lean_is_exclusive(v___x_2679_);
if (v_isSharedCheck_2695_ == 0)
{
v___x_2682_ = v___x_2679_;
v_isShared_2683_ = v_isSharedCheck_2695_;
goto v_resetjp_2681_;
}
else
{
lean_inc(v_a_2680_);
lean_dec(v___x_2679_);
v___x_2682_ = lean_box(0);
v_isShared_2683_ = v_isSharedCheck_2695_;
goto v_resetjp_2681_;
}
v_resetjp_2681_:
{
lean_object* v___x_2684_; lean_object* v___x_2685_; uint8_t v___x_2686_; 
v___x_2684_ = lean_string_utf8_byte_size(v_a_2680_);
v___x_2685_ = lean_unsigned_to_nat(0u);
v___x_2686_ = lean_nat_dec_eq(v___x_2684_, v___x_2685_);
if (v___x_2686_ == 0)
{
lean_object* v___x_2687_; lean_object* v___x_2688_; 
lean_del_object(v___x_2682_);
v___x_2687_ = l_Lean_Json_parse(v_a_2680_);
v___x_2688_ = l_LearningWorker_orError___redArg(v___x_2687_);
if (lean_obj_tag(v___x_2688_) == 0)
{
lean_object* v_a_2689_; lean_object* v___x_2690_; 
v_a_2689_ = lean_ctor_get(v___x_2688_, 0);
lean_inc(v_a_2689_);
lean_dec_ref_known(v___x_2688_, 1);
v___x_2690_ = l_LearningWorker_handle(v_state_2647_, v_a_2689_);
v___y_2661_ = v___x_2690_;
goto v___jp_2660_;
}
else
{
v___y_2661_ = v___x_2688_;
goto v___jp_2660_;
}
}
else
{
lean_object* v___x_2691_; lean_object* v___x_2693_; 
lean_dec(v_a_2680_);
v___x_2691_ = lean_box(0);
if (v_isShared_2683_ == 0)
{
lean_ctor_set(v___x_2682_, 0, v___x_2691_);
v___x_2693_ = v___x_2682_;
goto v_reusejp_2692_;
}
else
{
lean_object* v_reuseFailAlloc_2694_; 
v_reuseFailAlloc_2694_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2694_, 0, v___x_2691_);
v___x_2693_ = v_reuseFailAlloc_2694_;
goto v_reusejp_2692_;
}
v_reusejp_2692_:
{
return v___x_2693_;
}
}
}
}
else
{
lean_object* v_a_2696_; lean_object* v___x_2698_; uint8_t v_isShared_2699_; uint8_t v_isSharedCheck_2703_; 
v_a_2696_ = lean_ctor_get(v___x_2679_, 0);
v_isSharedCheck_2703_ = !lean_is_exclusive(v___x_2679_);
if (v_isSharedCheck_2703_ == 0)
{
v___x_2698_ = v___x_2679_;
v_isShared_2699_ = v_isSharedCheck_2703_;
goto v_resetjp_2697_;
}
else
{
lean_inc(v_a_2696_);
lean_dec(v___x_2679_);
v___x_2698_ = lean_box(0);
v_isShared_2699_ = v_isSharedCheck_2703_;
goto v_resetjp_2697_;
}
v_resetjp_2697_:
{
lean_object* v___x_2701_; 
if (v_isShared_2699_ == 0)
{
v___x_2701_ = v___x_2698_;
goto v_reusejp_2700_;
}
else
{
lean_object* v_reuseFailAlloc_2702_; 
v_reuseFailAlloc_2702_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2702_, 0, v_a_2696_);
v___x_2701_ = v_reuseFailAlloc_2702_;
goto v_reusejp_2700_;
}
v_reusejp_2700_:
{
return v___x_2701_;
}
}
}
v___jp_2649_:
{
lean_object* v___x_2651_; lean_object* v___x_2652_; lean_object* v___x_2653_; lean_object* v___x_2654_; lean_object* v___x_2655_; lean_object* v___x_2656_; lean_object* v___x_2657_; lean_object* v___x_2658_; 
v___x_2651_ = ((lean_object*)(l_LearningWorker_loop___closed__2));
v___x_2652_ = ((lean_object*)(l_LearningWorker_loop___closed__3));
v___x_2653_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2653_, 0, v___x_2652_);
lean_ctor_set(v___x_2653_, 1, v_a_2650_);
v___x_2654_ = lean_box(0);
v___x_2655_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2655_, 0, v___x_2653_);
lean_ctor_set(v___x_2655_, 1, v___x_2654_);
v___x_2656_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2656_, 0, v___x_2651_);
lean_ctor_set(v___x_2656_, 1, v___x_2655_);
v___x_2657_ = l_Lean_Json_mkObj(v___x_2656_);
lean_dec_ref_known(v___x_2656_, 2);
v___x_2658_ = l_LearningWorker_emit(v___x_2657_);
if (lean_obj_tag(v___x_2658_) == 0)
{
lean_dec_ref_known(v___x_2658_, 1);
goto _start;
}
else
{
return v___x_2658_;
}
}
v___jp_2660_:
{
if (lean_obj_tag(v___y_2661_) == 0)
{
lean_object* v_a_2662_; 
v_a_2662_ = lean_ctor_get(v___y_2661_, 0);
lean_inc(v_a_2662_);
lean_dec_ref_known(v___y_2661_, 1);
v_a_2650_ = v_a_2662_;
goto v___jp_2649_;
}
else
{
lean_object* v_a_2663_; lean_object* v___x_2665_; uint8_t v_isShared_2666_; uint8_t v_isSharedCheck_2676_; 
v_a_2663_ = lean_ctor_get(v___y_2661_, 0);
v_isSharedCheck_2676_ = !lean_is_exclusive(v___y_2661_);
if (v_isSharedCheck_2676_ == 0)
{
v___x_2665_ = v___y_2661_;
v_isShared_2666_ = v_isSharedCheck_2676_;
goto v_resetjp_2664_;
}
else
{
lean_inc(v_a_2663_);
lean_dec(v___y_2661_);
v___x_2665_ = lean_box(0);
v_isShared_2666_ = v_isSharedCheck_2676_;
goto v_resetjp_2664_;
}
v_resetjp_2664_:
{
lean_object* v___x_2667_; lean_object* v___x_2668_; lean_object* v___x_2670_; 
v___x_2667_ = ((lean_object*)(l_LearningWorker_loop___closed__4));
v___x_2668_ = lean_io_error_to_string(v_a_2663_);
if (v_isShared_2666_ == 0)
{
lean_ctor_set_tag(v___x_2665_, 3);
lean_ctor_set(v___x_2665_, 0, v___x_2668_);
v___x_2670_ = v___x_2665_;
goto v_reusejp_2669_;
}
else
{
lean_object* v_reuseFailAlloc_2675_; 
v_reuseFailAlloc_2675_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_2675_, 0, v___x_2668_);
v___x_2670_ = v_reuseFailAlloc_2675_;
goto v_reusejp_2669_;
}
v_reusejp_2669_:
{
lean_object* v___x_2671_; lean_object* v___x_2672_; lean_object* v___x_2673_; lean_object* v___x_2674_; 
v___x_2671_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_2671_, 0, v___x_2667_);
lean_ctor_set(v___x_2671_, 1, v___x_2670_);
v___x_2672_ = lean_box(0);
v___x_2673_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_2673_, 0, v___x_2671_);
lean_ctor_set(v___x_2673_, 1, v___x_2672_);
v___x_2674_ = l_Lean_Json_mkObj(v___x_2673_);
lean_dec_ref_known(v___x_2673_, 2);
v_a_2650_ = v___x_2674_;
goto v___jp_2649_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_LearningWorker_loop___boxed(lean_object* v_state_2704_, lean_object* v_a_2705_){
_start:
{
lean_object* v_res_2706_; 
v_res_2706_ = l_LearningWorker_loop(v_state_2704_);
lean_dec(v_state_2704_);
return v_res_2706_;
}
}
static lean_object* _init_l_main___closed__4(void){
_start:
{
lean_object* v___x_2716_; lean_object* v___x_2717_; 
v___x_2716_ = ((lean_object*)(l_main___closed__3));
v___x_2717_ = l_Lean_Json_mkObj(v___x_2716_);
return v___x_2717_;
}
}
LEAN_EXPORT lean_object* _lean_main(){
_start:
{
lean_object* v___x_2719_; lean_object* v___x_2720_; lean_object* v___x_2721_; 
v___x_2719_ = lean_box(0);
v___x_2720_ = lean_obj_once(&l_main___closed__4, &l_main___closed__4_once, _init_l_main___closed__4);
v___x_2721_ = l_LearningWorker_emit(v___x_2720_);
if (lean_obj_tag(v___x_2721_) == 0)
{
lean_object* v___x_2722_; lean_object* v___x_2723_; 
lean_dec_ref_known(v___x_2721_, 1);
v___x_2722_ = lean_st_mk_ref(v___x_2719_);
v___x_2723_ = l_LearningWorker_loop(v___x_2722_);
lean_dec(v___x_2722_);
return v___x_2723_;
}
else
{
return v___x_2721_;
}
}
}
LEAN_EXPORT lean_object* l_main___boxed(lean_object* v_a_2724_){
_start:
{
lean_object* v_res_2725_; 
v_res_2725_ = _lean_main();
return v_res_2725_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_LeanSort_Algorithm_LearnedSelection_Model(uint8_t builtin);
lean_object* initialize_Lean(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_experiments_direct_x2dcost_x2dlearning_Worker(uint8_t builtin) {
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
res = initialize_LeanSort_Algorithm_LearnedSelection_Model(builtin);
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
  res = initialize_experiments_direct_x2dcost_x2dlearning_Worker(1 /* builtin */);
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
