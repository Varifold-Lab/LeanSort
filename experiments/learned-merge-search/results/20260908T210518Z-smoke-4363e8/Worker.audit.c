// Lean compiler output
// Module: experiments.«learned-merge-search».Worker
// Imports: public import Init public meta import Init public import LeanSort.Verification.MergeSearch.Checks public import Lean
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
lean_object* l_List_reverse___redArg(lean_object*);
lean_object* l_List_lengthTR___redArg(lean_object*);
uint8_t l_LeanSort_MergeSearch_checkFits(lean_object*, lean_object*, lean_object*);
lean_object* l_LeanSort_MergeSearch_weights___boxed(lean_object*, lean_object*);
lean_object* l_LeanSort_MergeSearch_Shape_budget(lean_object*, lean_object*);
lean_object* l_LeanSort_MergeSearch_lookup(lean_object*, lean_object*, lean_object*);
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
size_t lean_array_size(lean_object*);
uint8_t lean_usize_dec_lt(size_t, size_t);
lean_object* lean_array_uget_borrowed(lean_object*, size_t);
lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonStackTable_fromJson_spec__0_spec__0(lean_object*);
lean_object* lean_array_to_list(lean_object*);
lean_object* lean_array_uset(lean_object*, size_t, lean_object*);
size_t lean_usize_add(size_t, size_t);
lean_object* l_Lean_Json_pretty(lean_object*, lean_object*);
lean_object* lean_string_append(lean_object*, lean_object*);
lean_object* lean_io_mono_nanos_now();
lean_object* lean_st_ref_get(lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lean_st_ref_set(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
lean_object* lean_array_mk(lean_object*);
lean_object* lean_array_uget(lean_object*, size_t);
lean_object* l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__0(lean_object*);
lean_object* lean_get_stdout();
lean_object* l_Lean_Json_compress(lean_object*);
lean_object* l_IO_FS_Stream_putStrLn(lean_object*, lean_object*);
lean_object* lean_io_error_to_string(lean_object*);
lean_object* l_Lean_Json_mkObj(lean_object*);
lean_object* lean_get_stdin();
lean_object* lean_string_utf8_byte_size(lean_object*);
lean_object* l_Lean_Json_parse(lean_object*);
lean_object* l_Lean_Json_getObjValD(lean_object*, lean_object*);
lean_object* l_List_replicateTR___redArg(lean_object*, lean_object*);
lean_object* l_Lean_JsonNumber_fromNat(lean_object*);
lean_object* l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__1(lean_object*);
lean_object* l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(lean_object*);
lean_object* lp_leansort_LeanSort_RunAdaptive_countPlan___redArg(lean_object*);
lean_object* lp_leansort_LeanSort_RunAdaptive_lengthPlan___redArg(lean_object*);
lean_object* l_Nat_decLe___boxed(lean_object*, lean_object*);
lean_object* l_List_foldl___at___00Array_appendList_spec__0___redArg(lean_object*, lean_object*);
lean_object* l_List_MergeSort_Internal_mergeSortTR_u2082___redArg(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_RunAdaptive_MergeTree_budget___redArg(lean_object*);
lean_object* lean_st_mk_ref(lean_object*);
lean_object* l_List_range(lean_object*);
uint8_t l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_RunAdaptive_MergeTree_leaves___redArg(lean_object*);
lean_object* l_LeanSort_MergeSearch_safePlan___redArg(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_RunAdaptive_MergeTree_program___redArg(lean_object*);
uint8_t l_List_instDecidablePairwise___redArg(lean_object*, lean_object*);
lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_Widget_instRpcEncodableStrictOrLazy_dec_00___x40_Lean_Widget_InteractiveDiagnostic_2157017296____hygCtx___hyg_1____at___00Lean_Widget_instRpcEncodableHighlightedMsgEmbed_dec_00___x40_Lean_Server_FileWorker_WidgetRequests_2377472685____hygCtx___hyg_1__spec__2_spec__3(lean_object*);
lean_object* l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonThread_fromJson_spec__0(lean_object*, lean_object*);
uint8_t l_LeanSort_MergeSearch_checkLower(lean_object*, lean_object*);
uint8_t l___private_Lean_Data_Json_Basic_0__Lean_Json_beq_x27(lean_object*, lean_object*);
lean_object* l_Lean_Json_getNat_x3f(lean_object*);
lean_object* l_Lean_Json_getArr_x3f(lean_object*);
lean_object* lean_array_get_size(lean_object*);
lean_object* lean_array_get_borrowed(lean_object*, lean_object*, lean_object*);
lean_object* lean_array_get(lean_object*, lean_object*, lean_object*);
lean_object* l_List_filterTR_loop___at___00__private_Lean_Meta_MkIffOfInductiveProp_0__Lean_Meta_toInductive_spec__3(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* lean_array_push(lean_object*, lean_object*);
lean_object* lp_plausible_List_foldr___at___00List_sum___at___00__private_Plausible_Gen_0__Plausible_Gen_sumFst_spec__1_spec__1(lean_object*, lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_MergeSearchWorker_orError___redArg(lean_object*);
LEAN_EXPORT lean_object* l_MergeSearchWorker_orError___redArg___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_MergeSearchWorker_orError(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_MergeSearchWorker_orError___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object l_MergeSearchWorker_decode___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 34, .m_capacity = 34, .m_length = 33, .m_data = "binary node requires two children"};
static const lean_object* l_MergeSearchWorker_decode___closed__0 = (const lean_object*)&l_MergeSearchWorker_decode___closed__0_value;
static const lean_ctor_object l_MergeSearchWorker_decode___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_MergeSearchWorker_decode___closed__0_value)}};
static const lean_object* l_MergeSearchWorker_decode___closed__1 = (const lean_object*)&l_MergeSearchWorker_decode___closed__1_value;
static const lean_string_object l_MergeSearchWorker_decode___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 34, .m_capacity = 34, .m_length = 33, .m_data = "tree depth exceeds resource limit"};
static const lean_object* l_MergeSearchWorker_decode___closed__2 = (const lean_object*)&l_MergeSearchWorker_decode___closed__2_value;
static const lean_ctor_object l_MergeSearchWorker_decode___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 0}, .m_objs = {((lean_object*)&l_MergeSearchWorker_decode___closed__2_value)}};
static const lean_object* l_MergeSearchWorker_decode___closed__3 = (const lean_object*)&l_MergeSearchWorker_decode___closed__3_value;
static const lean_ctor_object l_MergeSearchWorker_decode___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 1}, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* l_MergeSearchWorker_decode___closed__4 = (const lean_object*)&l_MergeSearchWorker_decode___closed__4_value;
LEAN_EXPORT lean_object* l_MergeSearchWorker_decode(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_MergeSearchWorker_decode___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_MergeSearchWorker_encode(lean_object*);
LEAN_EXPORT lean_object* l_MergeSearchWorker_signature(lean_object*);
LEAN_EXPORT lean_object* l_List_foldl___at___00MergeSearchWorker_checksum_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_foldl___at___00MergeSearchWorker_checksum_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_MergeSearchWorker_checksum(lean_object*);
LEAN_EXPORT lean_object* l_MergeSearchWorker_checksum___boxed(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0_spec__0_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0_spec__0(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0_spec__0___boxed(lean_object*);
LEAN_EXPORT lean_object* l_MergeSearchWorker_timedTree(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_MergeSearchWorker_timedTree___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0___boxed(lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__0_spec__0(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__0___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_sum___at___00MergeSearchWorker_handle_spec__9(lean_object*);
LEAN_EXPORT lean_object* l_List_sum___at___00MergeSearchWorker_handle_spec__9___boxed(lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__11_spec__15_spec__18(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__11_spec__15_spec__18___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__11_spec__15(lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00MergeSearchWorker_handle_spec__11(lean_object*);
LEAN_EXPORT lean_object* l_List_filterMapTR_go___at___00MergeSearchWorker_handle_spec__8(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2_spec__3(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2_spec__3___boxed(lean_object*, lean_object*, lean_object*);
static const lean_string_object l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 27, .m_capacity = 27, .m_length = 26, .m_data = "expected JSON array, got '"};
static const lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2___closed__0 = (const lean_object*)&l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2___closed__0_value;
static const lean_string_object l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 2, .m_capacity = 2, .m_length = 1, .m_data = "'"};
static const lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2___closed__1 = (const lean_object*)&l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2___closed__1_value;
LEAN_EXPORT lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__2_spec__4(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__2___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__6(lean_object*, lean_object*, lean_object*);
static const lean_closure_object l_List_all___at___00MergeSearchWorker_handle_spec__21___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Nat_decLe___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_List_all___at___00MergeSearchWorker_handle_spec__21___closed__0 = (const lean_object*)&l_List_all___at___00MergeSearchWorker_handle_spec__21___closed__0_value;
LEAN_EXPORT uint8_t l_List_all___at___00MergeSearchWorker_handle_spec__21(lean_object*);
LEAN_EXPORT lean_object* l_List_all___at___00MergeSearchWorker_handle_spec__21___boxed(lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__7(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__7___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00MergeSearchWorker_handle_spec__12(lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__20(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__4(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3_spec__6_spec__8_spec__28(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3_spec__6_spec__8_spec__28___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3_spec__6_spec__8(lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3_spec__6(lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00MergeSearchWorker_handle_spec__17(lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__18_spec__24_spec__31(size_t, size_t, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__18_spec__24_spec__31___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__18_spec__24(lean_object*);
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00MergeSearchWorker_handle_spec__18(lean_object*);
static const lean_string_object l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 22, .m_capacity = 22, .m_length = 21, .m_data = "timed output mismatch"};
static const lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___redArg___closed__0_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___redArg___closed__0_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___redArg___closed__1 = (const lean_object*)&l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___redArg___closed__1_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__25___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__23___redArg(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__24___lam__0(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__24___lam__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__24(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__24___lam__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19___lam__0(lean_object*, lean_object*);
static lean_once_cell_t l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19___closed__0;
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19___lam__1(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00MergeSearchWorker_handle_spec__15___redArg(lean_object*);
static const lean_string_object l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 37, .m_capacity = 37, .m_length = 36, .m_data = "execution/refinement/budget mismatch"};
static const lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__0 = (const lean_object*)&l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__0_value;
static const lean_ctor_object l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__0_value)}};
static const lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__1 = (const lean_object*)&l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__1_value;
static lean_once_cell_t l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__2;
static const lean_string_object l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "output"};
static const lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__3 = (const lean_object*)&l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__3_value;
static const lean_string_object l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 12, .m_capacity = 12, .m_length = 11, .m_data = "comparisons"};
static const lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__4 = (const lean_object*)&l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__4_value;
static const lean_string_object l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "budget"};
static const lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__5 = (const lean_object*)&l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__5_value;
static const lean_string_object l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 9, .m_capacity = 9, .m_length = 8, .m_data = "times_ns"};
static const lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__6 = (const lean_object*)&l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__6_value;
static const lean_string_object l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 7, .m_capacity = 7, .m_length = 6, .m_data = "leaves"};
static const lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__7 = (const lean_object*)&l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__7_value;
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__10(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00MergeSearchWorker_handle_spec__13(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__5(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__5___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_List_all___at___00MergeSearchWorker_handle_spec__22(lean_object*);
LEAN_EXPORT lean_object* l_List_all___at___00MergeSearchWorker_handle_spec__22___boxed(lean_object*);
static const lean_string_object l_MergeSearchWorker_handle___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "lengths"};
static const lean_object* l_MergeSearchWorker_handle___closed__0 = (const lean_object*)&l_MergeSearchWorker_handle___closed__0_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 14, .m_capacity = 14, .m_length = 13, .m_data = "lower_checked"};
static const lean_object* l_MergeSearchWorker_handle___closed__1 = (const lean_object*)&l_MergeSearchWorker_handle___closed__1_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "lower"};
static const lean_object* l_MergeSearchWorker_handle___closed__2 = (const lean_object*)&l_MergeSearchWorker_handle___closed__2_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "fits"};
static const lean_object* l_MergeSearchWorker_handle___closed__3 = (const lean_object*)&l_MergeSearchWorker_handle___closed__3_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "budgets"};
static const lean_object* l_MergeSearchWorker_handle___closed__4 = (const lean_object*)&l_MergeSearchWorker_handle___closed__4_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "optimal"};
static const lean_object* l_MergeSearchWorker_handle___closed__5 = (const lean_object*)&l_MergeSearchWorker_handle___closed__5_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 15, .m_capacity = 15, .m_length = 14, .m_data = "certificate_ns"};
static const lean_object* l_MergeSearchWorker_handle___closed__6 = (const lean_object*)&l_MergeSearchWorker_handle___closed__6_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 11, .m_capacity = 11, .m_length = 10, .m_data = "executions"};
static const lean_object* l_MergeSearchWorker_handle___closed__7 = (const lean_object*)&l_MergeSearchWorker_handle___closed__7_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 16, .m_capacity = 16, .m_length = 15, .m_data = "count_signature"};
static const lean_object* l_MergeSearchWorker_handle___closed__8 = (const lean_object*)&l_MergeSearchWorker_handle___closed__8_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 17, .m_capacity = 17, .m_length = 16, .m_data = "length_signature"};
static const lean_object* l_MergeSearchWorker_handle___closed__9 = (const lean_object*)&l_MergeSearchWorker_handle___closed__9_value;
static const lean_closure_object l_MergeSearchWorker_handle___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Nat_decLe___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_MergeSearchWorker_handle___closed__10 = (const lean_object*)&l_MergeSearchWorker_handle___closed__10_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 32, .m_capacity = 32, .m_length = 31, .m_data = "invalid sorted run precondition"};
static const lean_object* l_MergeSearchWorker_handle___closed__11 = (const lean_object*)&l_MergeSearchWorker_handle___closed__11_value;
static const lean_ctor_object l_MergeSearchWorker_handle___closed__12_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_MergeSearchWorker_handle___closed__11_value)}};
static const lean_object* l_MergeSearchWorker_handle___closed__12 = (const lean_object*)&l_MergeSearchWorker_handle___closed__12_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__13_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 28, .m_capacity = 28, .m_length = 27, .m_data = "certificate vector mismatch"};
static const lean_object* l_MergeSearchWorker_handle___closed__13 = (const lean_object*)&l_MergeSearchWorker_handle___closed__13_value;
static const lean_ctor_object l_MergeSearchWorker_handle___closed__14_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_MergeSearchWorker_handle___closed__13_value)}};
static const lean_object* l_MergeSearchWorker_handle___closed__14 = (const lean_object*)&l_MergeSearchWorker_handle___closed__14_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__15_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 43, .m_capacity = 43, .m_length = 42, .m_data = "positive lengths, at most 64 runs required"};
static const lean_object* l_MergeSearchWorker_handle___closed__15 = (const lean_object*)&l_MergeSearchWorker_handle___closed__15_value;
static const lean_ctor_object l_MergeSearchWorker_handle___closed__16_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_MergeSearchWorker_handle___closed__15_value)}};
static const lean_object* l_MergeSearchWorker_handle___closed__16 = (const lean_object*)&l_MergeSearchWorker_handle___closed__16_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__17_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "table"};
static const lean_object* l_MergeSearchWorker_handle___closed__17 = (const lean_object*)&l_MergeSearchWorker_handle___closed__17_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__18_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "trees"};
static const lean_object* l_MergeSearchWorker_handle___closed__18 = (const lean_object*)&l_MergeSearchWorker_handle___closed__18_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__19_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 5, .m_capacity = 5, .m_length = 4, .m_data = "runs"};
static const lean_object* l_MergeSearchWorker_handle___closed__19 = (const lean_object*)&l_MergeSearchWorker_handle___closed__19_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__20_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 8, .m_capacity = 8, .m_length = 7, .m_data = "execute"};
static const lean_object* l_MergeSearchWorker_handle___closed__20 = (const lean_object*)&l_MergeSearchWorker_handle___closed__20_value;
static const lean_string_object l_MergeSearchWorker_handle___closed__21_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 26, .m_capacity = 26, .m_length = 25, .m_data = "invalid lower certificate"};
static const lean_object* l_MergeSearchWorker_handle___closed__21 = (const lean_object*)&l_MergeSearchWorker_handle___closed__21_value;
static const lean_ctor_object l_MergeSearchWorker_handle___closed__22_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*1 + 0, .m_other = 1, .m_tag = 18}, .m_objs = {((lean_object*)&l_MergeSearchWorker_handle___closed__21_value)}};
static const lean_object* l_MergeSearchWorker_handle___closed__22 = (const lean_object*)&l_MergeSearchWorker_handle___closed__22_value;
static const lean_array_object l_MergeSearchWorker_handle___closed__23_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_MergeSearchWorker_handle___closed__23 = (const lean_object*)&l_MergeSearchWorker_handle___closed__23_value;
LEAN_EXPORT lean_object* l_MergeSearchWorker_handle(lean_object*);
LEAN_EXPORT lean_object* l_MergeSearchWorker_handle___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00MergeSearchWorker_handle_spec__15(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__23(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__25(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_string_object l_MergeSearchWorker_loop___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = 0, .m_other = 0, .m_tag = 249}, .m_size = 6, .m_capacity = 6, .m_length = 5, .m_data = "error"};
static const lean_object* l_MergeSearchWorker_loop___closed__0 = (const lean_object*)&l_MergeSearchWorker_loop___closed__0_value;
LEAN_EXPORT lean_object* l_MergeSearchWorker_loop();
LEAN_EXPORT lean_object* l_MergeSearchWorker_loop___boxed(lean_object*);
LEAN_EXPORT lean_object* _lean_main();
LEAN_EXPORT lean_object* l_main___boxed(lean_object*);
LEAN_EXPORT lean_object* l_MergeSearchWorker_orError___redArg(lean_object* v_x_1_){
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
LEAN_EXPORT lean_object* l_MergeSearchWorker_orError___redArg___boxed(lean_object* v_x_20_, lean_object* v_a_21_){
_start:
{
lean_object* v_res_22_; 
v_res_22_ = l_MergeSearchWorker_orError___redArg(v_x_20_);
return v_res_22_;
}
}
LEAN_EXPORT lean_object* l_MergeSearchWorker_orError(lean_object* v_00_u03b1_23_, lean_object* v_x_24_){
_start:
{
lean_object* v___x_26_; 
v___x_26_ = l_MergeSearchWorker_orError___redArg(v_x_24_);
return v___x_26_;
}
}
LEAN_EXPORT lean_object* l_MergeSearchWorker_orError___boxed(lean_object* v_00_u03b1_27_, lean_object* v_x_28_, lean_object* v_a_29_){
_start:
{
lean_object* v_res_30_; 
v_res_30_ = l_MergeSearchWorker_orError(v_00_u03b1_27_, v_x_28_);
return v_res_30_;
}
}
LEAN_EXPORT lean_object* l_MergeSearchWorker_decode(lean_object* v_x_39_, lean_object* v_x_40_){
_start:
{
lean_object* v_zero_43_; uint8_t v_isZero_44_; 
v_zero_43_ = lean_unsigned_to_nat(0u);
v_isZero_44_ = lean_nat_dec_eq(v_x_39_, v_zero_43_);
if (v_isZero_44_ == 1)
{
lean_object* v___x_45_; 
lean_dec(v_x_40_);
v___x_45_ = ((lean_object*)(l_MergeSearchWorker_decode___closed__3));
return v___x_45_;
}
else
{
lean_object* v___x_46_; uint8_t v___x_47_; 
v___x_46_ = lean_box(0);
v___x_47_ = l___private_Lean_Data_Json_Basic_0__Lean_Json_beq_x27(v_x_40_, v___x_46_);
if (v___x_47_ == 0)
{
lean_object* v___x_48_; 
lean_inc(v_x_40_);
v___x_48_ = l_Lean_Json_getNat_x3f(v_x_40_);
if (lean_obj_tag(v___x_48_) == 0)
{
lean_object* v___x_49_; 
lean_dec_ref_known(v___x_48_, 1);
v___x_49_ = l_Lean_Json_getArr_x3f(v_x_40_);
if (lean_obj_tag(v___x_49_) == 0)
{
lean_object* v_a_50_; lean_object* v___x_52_; uint8_t v_isShared_53_; uint8_t v_isSharedCheck_57_; 
v_a_50_ = lean_ctor_get(v___x_49_, 0);
v_isSharedCheck_57_ = !lean_is_exclusive(v___x_49_);
if (v_isSharedCheck_57_ == 0)
{
v___x_52_ = v___x_49_;
v_isShared_53_ = v_isSharedCheck_57_;
goto v_resetjp_51_;
}
else
{
lean_inc(v_a_50_);
lean_dec(v___x_49_);
v___x_52_ = lean_box(0);
v_isShared_53_ = v_isSharedCheck_57_;
goto v_resetjp_51_;
}
v_resetjp_51_:
{
lean_object* v___x_55_; 
if (v_isShared_53_ == 0)
{
v___x_55_ = v___x_52_;
goto v_reusejp_54_;
}
else
{
lean_object* v_reuseFailAlloc_56_; 
v_reuseFailAlloc_56_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_56_, 0, v_a_50_);
v___x_55_ = v_reuseFailAlloc_56_;
goto v_reusejp_54_;
}
v_reusejp_54_:
{
return v___x_55_;
}
}
}
else
{
lean_object* v_a_58_; lean_object* v___x_59_; lean_object* v___x_60_; uint8_t v___x_61_; 
v_a_58_ = lean_ctor_get(v___x_49_, 0);
lean_inc(v_a_58_);
lean_dec_ref_known(v___x_49_, 1);
v___x_59_ = lean_array_get_size(v_a_58_);
v___x_60_ = lean_unsigned_to_nat(2u);
v___x_61_ = lean_nat_dec_eq(v___x_59_, v___x_60_);
if (v___x_61_ == 0)
{
lean_dec(v_a_58_);
goto v___jp_41_;
}
else
{
if (v___x_47_ == 0)
{
lean_object* v_one_62_; lean_object* v_n_63_; lean_object* v___x_64_; lean_object* v___x_65_; 
v_one_62_ = lean_unsigned_to_nat(1u);
v_n_63_ = lean_nat_sub(v_x_39_, v_one_62_);
v___x_64_ = lean_array_get_borrowed(v___x_46_, v_a_58_, v_zero_43_);
lean_inc(v___x_64_);
v___x_65_ = l_MergeSearchWorker_decode(v_n_63_, v___x_64_);
if (lean_obj_tag(v___x_65_) == 0)
{
lean_dec(v_n_63_);
lean_dec(v_a_58_);
return v___x_65_;
}
else
{
lean_object* v_a_66_; lean_object* v___x_67_; lean_object* v___x_68_; 
v_a_66_ = lean_ctor_get(v___x_65_, 0);
lean_inc(v_a_66_);
lean_dec_ref_known(v___x_65_, 1);
v___x_67_ = lean_array_get(v___x_46_, v_a_58_, v_one_62_);
lean_dec(v_a_58_);
v___x_68_ = l_MergeSearchWorker_decode(v_n_63_, v___x_67_);
lean_dec(v_n_63_);
if (lean_obj_tag(v___x_68_) == 0)
{
lean_dec(v_a_66_);
return v___x_68_;
}
else
{
lean_object* v_a_69_; lean_object* v___x_71_; uint8_t v_isShared_72_; uint8_t v_isSharedCheck_77_; 
v_a_69_ = lean_ctor_get(v___x_68_, 0);
v_isSharedCheck_77_ = !lean_is_exclusive(v___x_68_);
if (v_isSharedCheck_77_ == 0)
{
v___x_71_ = v___x_68_;
v_isShared_72_ = v_isSharedCheck_77_;
goto v_resetjp_70_;
}
else
{
lean_inc(v_a_69_);
lean_dec(v___x_68_);
v___x_71_ = lean_box(0);
v_isShared_72_ = v_isSharedCheck_77_;
goto v_resetjp_70_;
}
v_resetjp_70_:
{
lean_object* v___x_73_; lean_object* v___x_75_; 
v___x_73_ = lean_alloc_ctor(2, 2, 0);
lean_ctor_set(v___x_73_, 0, v_a_66_);
lean_ctor_set(v___x_73_, 1, v_a_69_);
if (v_isShared_72_ == 0)
{
lean_ctor_set(v___x_71_, 0, v___x_73_);
v___x_75_ = v___x_71_;
goto v_reusejp_74_;
}
else
{
lean_object* v_reuseFailAlloc_76_; 
v_reuseFailAlloc_76_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_76_, 0, v___x_73_);
v___x_75_ = v_reuseFailAlloc_76_;
goto v_reusejp_74_;
}
v_reusejp_74_:
{
return v___x_75_;
}
}
}
}
}
else
{
lean_dec(v_a_58_);
goto v___jp_41_;
}
}
}
}
else
{
lean_object* v_a_78_; lean_object* v___x_80_; uint8_t v_isShared_81_; uint8_t v_isSharedCheck_86_; 
lean_dec(v_x_40_);
v_a_78_ = lean_ctor_get(v___x_48_, 0);
v_isSharedCheck_86_ = !lean_is_exclusive(v___x_48_);
if (v_isSharedCheck_86_ == 0)
{
v___x_80_ = v___x_48_;
v_isShared_81_ = v_isSharedCheck_86_;
goto v_resetjp_79_;
}
else
{
lean_inc(v_a_78_);
lean_dec(v___x_48_);
v___x_80_ = lean_box(0);
v_isShared_81_ = v_isSharedCheck_86_;
goto v_resetjp_79_;
}
v_resetjp_79_:
{
lean_object* v___x_82_; lean_object* v___x_84_; 
v___x_82_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_82_, 0, v_a_78_);
if (v_isShared_81_ == 0)
{
lean_ctor_set(v___x_80_, 0, v___x_82_);
v___x_84_ = v___x_80_;
goto v_reusejp_83_;
}
else
{
lean_object* v_reuseFailAlloc_85_; 
v_reuseFailAlloc_85_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_85_, 0, v___x_82_);
v___x_84_ = v_reuseFailAlloc_85_;
goto v_reusejp_83_;
}
v_reusejp_83_:
{
return v___x_84_;
}
}
}
}
else
{
lean_object* v___x_87_; 
lean_dec(v_x_40_);
v___x_87_ = ((lean_object*)(l_MergeSearchWorker_decode___closed__4));
return v___x_87_;
}
}
v___jp_41_:
{
lean_object* v___x_42_; 
v___x_42_ = ((lean_object*)(l_MergeSearchWorker_decode___closed__1));
return v___x_42_;
}
}
}
LEAN_EXPORT lean_object* l_MergeSearchWorker_decode___boxed(lean_object* v_x_88_, lean_object* v_x_89_){
_start:
{
lean_object* v_res_90_; 
v_res_90_ = l_MergeSearchWorker_decode(v_x_88_, v_x_89_);
lean_dec(v_x_88_);
return v_res_90_;
}
}
LEAN_EXPORT lean_object* l_MergeSearchWorker_encode(lean_object* v_x_91_){
_start:
{
switch(lean_obj_tag(v_x_91_))
{
case 0:
{
lean_object* v___x_92_; 
v___x_92_ = lean_box(0);
return v___x_92_;
}
case 1:
{
lean_object* v_index_93_; lean_object* v___x_95_; uint8_t v_isShared_96_; uint8_t v_isSharedCheck_101_; 
v_index_93_ = lean_ctor_get(v_x_91_, 0);
v_isSharedCheck_101_ = !lean_is_exclusive(v_x_91_);
if (v_isSharedCheck_101_ == 0)
{
v___x_95_ = v_x_91_;
v_isShared_96_ = v_isSharedCheck_101_;
goto v_resetjp_94_;
}
else
{
lean_inc(v_index_93_);
lean_dec(v_x_91_);
v___x_95_ = lean_box(0);
v_isShared_96_ = v_isSharedCheck_101_;
goto v_resetjp_94_;
}
v_resetjp_94_:
{
lean_object* v___x_97_; lean_object* v___x_99_; 
v___x_97_ = l_Lean_JsonNumber_fromNat(v_index_93_);
if (v_isShared_96_ == 0)
{
lean_ctor_set_tag(v___x_95_, 2);
lean_ctor_set(v___x_95_, 0, v___x_97_);
v___x_99_ = v___x_95_;
goto v_reusejp_98_;
}
else
{
lean_object* v_reuseFailAlloc_100_; 
v_reuseFailAlloc_100_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_100_, 0, v___x_97_);
v___x_99_ = v_reuseFailAlloc_100_;
goto v_reusejp_98_;
}
v_reusejp_98_:
{
return v___x_99_;
}
}
}
default: 
{
lean_object* v_left_102_; lean_object* v_right_103_; lean_object* v___x_105_; uint8_t v_isShared_106_; uint8_t v_isSharedCheck_115_; 
v_left_102_ = lean_ctor_get(v_x_91_, 0);
v_right_103_ = lean_ctor_get(v_x_91_, 1);
v_isSharedCheck_115_ = !lean_is_exclusive(v_x_91_);
if (v_isSharedCheck_115_ == 0)
{
v___x_105_ = v_x_91_;
v_isShared_106_ = v_isSharedCheck_115_;
goto v_resetjp_104_;
}
else
{
lean_inc(v_right_103_);
lean_inc(v_left_102_);
lean_dec(v_x_91_);
v___x_105_ = lean_box(0);
v_isShared_106_ = v_isSharedCheck_115_;
goto v_resetjp_104_;
}
v_resetjp_104_:
{
lean_object* v___x_107_; lean_object* v___x_108_; lean_object* v___x_109_; lean_object* v___x_111_; 
v___x_107_ = l_MergeSearchWorker_encode(v_left_102_);
v___x_108_ = l_MergeSearchWorker_encode(v_right_103_);
v___x_109_ = lean_box(0);
if (v_isShared_106_ == 0)
{
lean_ctor_set_tag(v___x_105_, 1);
lean_ctor_set(v___x_105_, 1, v___x_109_);
lean_ctor_set(v___x_105_, 0, v___x_108_);
v___x_111_ = v___x_105_;
goto v_reusejp_110_;
}
else
{
lean_object* v_reuseFailAlloc_114_; 
v_reuseFailAlloc_114_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_114_, 0, v___x_108_);
lean_ctor_set(v_reuseFailAlloc_114_, 1, v___x_109_);
v___x_111_ = v_reuseFailAlloc_114_;
goto v_reusejp_110_;
}
v_reusejp_110_:
{
lean_object* v___x_112_; lean_object* v___x_113_; 
v___x_112_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_112_, 0, v___x_107_);
lean_ctor_set(v___x_112_, 1, v___x_111_);
v___x_113_ = l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(v___x_112_);
return v___x_113_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_MergeSearchWorker_signature(lean_object* v_t_116_){
_start:
{
switch(lean_obj_tag(v_t_116_))
{
case 0:
{
lean_object* v___x_117_; 
v___x_117_ = lean_box(0);
return v___x_117_;
}
case 1:
{
lean_object* v_run_118_; lean_object* v___x_120_; uint8_t v_isShared_121_; uint8_t v_isSharedCheck_127_; 
v_run_118_ = lean_ctor_get(v_t_116_, 0);
v_isSharedCheck_127_ = !lean_is_exclusive(v_t_116_);
if (v_isSharedCheck_127_ == 0)
{
v___x_120_ = v_t_116_;
v_isShared_121_ = v_isSharedCheck_127_;
goto v_resetjp_119_;
}
else
{
lean_inc(v_run_118_);
lean_dec(v_t_116_);
v___x_120_ = lean_box(0);
v_isShared_121_ = v_isSharedCheck_127_;
goto v_resetjp_119_;
}
v_resetjp_119_:
{
lean_object* v___x_122_; lean_object* v___x_123_; lean_object* v___x_125_; 
v___x_122_ = l_List_lengthTR___redArg(v_run_118_);
lean_dec(v_run_118_);
v___x_123_ = l_Lean_JsonNumber_fromNat(v___x_122_);
if (v_isShared_121_ == 0)
{
lean_ctor_set_tag(v___x_120_, 2);
lean_ctor_set(v___x_120_, 0, v___x_123_);
v___x_125_ = v___x_120_;
goto v_reusejp_124_;
}
else
{
lean_object* v_reuseFailAlloc_126_; 
v_reuseFailAlloc_126_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v_reuseFailAlloc_126_, 0, v___x_123_);
v___x_125_ = v_reuseFailAlloc_126_;
goto v_reusejp_124_;
}
v_reusejp_124_:
{
return v___x_125_;
}
}
}
default: 
{
lean_object* v_left_128_; lean_object* v_right_129_; lean_object* v___x_131_; uint8_t v_isShared_132_; uint8_t v_isSharedCheck_141_; 
v_left_128_ = lean_ctor_get(v_t_116_, 0);
v_right_129_ = lean_ctor_get(v_t_116_, 1);
v_isSharedCheck_141_ = !lean_is_exclusive(v_t_116_);
if (v_isSharedCheck_141_ == 0)
{
v___x_131_ = v_t_116_;
v_isShared_132_ = v_isSharedCheck_141_;
goto v_resetjp_130_;
}
else
{
lean_inc(v_right_129_);
lean_inc(v_left_128_);
lean_dec(v_t_116_);
v___x_131_ = lean_box(0);
v_isShared_132_ = v_isSharedCheck_141_;
goto v_resetjp_130_;
}
v_resetjp_130_:
{
lean_object* v___x_133_; lean_object* v___x_134_; lean_object* v___x_135_; lean_object* v___x_137_; 
v___x_133_ = l_MergeSearchWorker_signature(v_left_128_);
v___x_134_ = l_MergeSearchWorker_signature(v_right_129_);
v___x_135_ = lean_box(0);
if (v_isShared_132_ == 0)
{
lean_ctor_set_tag(v___x_131_, 1);
lean_ctor_set(v___x_131_, 1, v___x_135_);
lean_ctor_set(v___x_131_, 0, v___x_134_);
v___x_137_ = v___x_131_;
goto v_reusejp_136_;
}
else
{
lean_object* v_reuseFailAlloc_140_; 
v_reuseFailAlloc_140_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_140_, 0, v___x_134_);
lean_ctor_set(v_reuseFailAlloc_140_, 1, v___x_135_);
v___x_137_ = v_reuseFailAlloc_140_;
goto v_reusejp_136_;
}
v_reusejp_136_:
{
lean_object* v___x_138_; lean_object* v___x_139_; 
v___x_138_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_138_, 0, v___x_133_);
lean_ctor_set(v___x_138_, 1, v___x_137_);
v___x_139_ = l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(v___x_138_);
return v___x_139_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_foldl___at___00MergeSearchWorker_checksum_spec__0(lean_object* v_x_142_, lean_object* v_x_143_){
_start:
{
if (lean_obj_tag(v_x_143_) == 0)
{
return v_x_142_;
}
else
{
lean_object* v_head_144_; lean_object* v_tail_145_; lean_object* v___x_146_; lean_object* v___x_147_; lean_object* v___x_148_; lean_object* v___x_149_; lean_object* v___x_150_; 
v_head_144_ = lean_ctor_get(v_x_143_, 0);
v_tail_145_ = lean_ctor_get(v_x_143_, 1);
v___x_146_ = lean_unsigned_to_nat(33u);
v___x_147_ = lean_nat_mul(v_x_142_, v___x_146_);
lean_dec(v_x_142_);
v___x_148_ = lean_nat_add(v___x_147_, v_head_144_);
lean_dec(v___x_147_);
v___x_149_ = lean_unsigned_to_nat(1000000007u);
v___x_150_ = lean_nat_mod(v___x_148_, v___x_149_);
lean_dec(v___x_148_);
v_x_142_ = v___x_150_;
v_x_143_ = v_tail_145_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_List_foldl___at___00MergeSearchWorker_checksum_spec__0___boxed(lean_object* v_x_152_, lean_object* v_x_153_){
_start:
{
lean_object* v_res_154_; 
v_res_154_ = l_List_foldl___at___00MergeSearchWorker_checksum_spec__0(v_x_152_, v_x_153_);
lean_dec(v_x_153_);
return v_res_154_;
}
}
LEAN_EXPORT lean_object* l_MergeSearchWorker_checksum(lean_object* v_xs_155_){
_start:
{
lean_object* v___x_156_; lean_object* v___x_157_; 
v___x_156_ = lean_unsigned_to_nat(0u);
v___x_157_ = l_List_foldl___at___00MergeSearchWorker_checksum_spec__0(v___x_156_, v_xs_155_);
return v___x_157_;
}
}
LEAN_EXPORT lean_object* l_MergeSearchWorker_checksum___boxed(lean_object* v_xs_158_){
_start:
{
lean_object* v_res_159_; 
v_res_159_ = l_MergeSearchWorker_checksum(v_xs_158_);
lean_dec(v_xs_158_);
return v_res_159_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0_spec__0_spec__1(lean_object* v_x_160_, lean_object* v_x_161_){
_start:
{
if (lean_obj_tag(v_x_160_) == 0)
{
return v_x_161_;
}
else
{
if (lean_obj_tag(v_x_161_) == 0)
{
return v_x_160_;
}
else
{
lean_object* v_head_162_; lean_object* v_tail_163_; lean_object* v_head_164_; lean_object* v_tail_165_; uint8_t v___x_166_; 
v_head_162_ = lean_ctor_get(v_x_160_, 0);
v_tail_163_ = lean_ctor_get(v_x_160_, 1);
v_head_164_ = lean_ctor_get(v_x_161_, 0);
v_tail_165_ = lean_ctor_get(v_x_161_, 1);
v___x_166_ = lean_nat_dec_le(v_head_162_, v_head_164_);
if (v___x_166_ == 0)
{
lean_object* v___x_168_; uint8_t v_isShared_169_; uint8_t v_isSharedCheck_174_; 
lean_inc(v_tail_165_);
lean_inc(v_head_164_);
v_isSharedCheck_174_ = !lean_is_exclusive(v_x_161_);
if (v_isSharedCheck_174_ == 0)
{
lean_object* v_unused_175_; lean_object* v_unused_176_; 
v_unused_175_ = lean_ctor_get(v_x_161_, 1);
lean_dec(v_unused_175_);
v_unused_176_ = lean_ctor_get(v_x_161_, 0);
lean_dec(v_unused_176_);
v___x_168_ = v_x_161_;
v_isShared_169_ = v_isSharedCheck_174_;
goto v_resetjp_167_;
}
else
{
lean_dec(v_x_161_);
v___x_168_ = lean_box(0);
v_isShared_169_ = v_isSharedCheck_174_;
goto v_resetjp_167_;
}
v_resetjp_167_:
{
lean_object* v___x_170_; lean_object* v___x_172_; 
v___x_170_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0_spec__0_spec__1(v_x_160_, v_tail_165_);
if (v_isShared_169_ == 0)
{
lean_ctor_set(v___x_168_, 1, v___x_170_);
v___x_172_ = v___x_168_;
goto v_reusejp_171_;
}
else
{
lean_object* v_reuseFailAlloc_173_; 
v_reuseFailAlloc_173_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_173_, 0, v_head_164_);
lean_ctor_set(v_reuseFailAlloc_173_, 1, v___x_170_);
v___x_172_ = v_reuseFailAlloc_173_;
goto v_reusejp_171_;
}
v_reusejp_171_:
{
return v___x_172_;
}
}
}
else
{
lean_object* v___x_178_; uint8_t v_isShared_179_; uint8_t v_isSharedCheck_184_; 
lean_inc(v_tail_163_);
lean_inc(v_head_162_);
v_isSharedCheck_184_ = !lean_is_exclusive(v_x_160_);
if (v_isSharedCheck_184_ == 0)
{
lean_object* v_unused_185_; lean_object* v_unused_186_; 
v_unused_185_ = lean_ctor_get(v_x_160_, 1);
lean_dec(v_unused_185_);
v_unused_186_ = lean_ctor_get(v_x_160_, 0);
lean_dec(v_unused_186_);
v___x_178_ = v_x_160_;
v_isShared_179_ = v_isSharedCheck_184_;
goto v_resetjp_177_;
}
else
{
lean_dec(v_x_160_);
v___x_178_ = lean_box(0);
v_isShared_179_ = v_isSharedCheck_184_;
goto v_resetjp_177_;
}
v_resetjp_177_:
{
lean_object* v___x_180_; lean_object* v___x_182_; 
v___x_180_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0_spec__0_spec__1(v_tail_163_, v_x_161_);
if (v_isShared_179_ == 0)
{
lean_ctor_set(v___x_178_, 1, v___x_180_);
v___x_182_ = v___x_178_;
goto v_reusejp_181_;
}
else
{
lean_object* v_reuseFailAlloc_183_; 
v_reuseFailAlloc_183_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_183_, 0, v_head_162_);
lean_ctor_set(v_reuseFailAlloc_183_, 1, v___x_180_);
v___x_182_ = v_reuseFailAlloc_183_;
goto v_reusejp_181_;
}
v_reusejp_181_:
{
return v___x_182_;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0_spec__0(lean_object* v_x_187_){
_start:
{
switch(lean_obj_tag(v_x_187_))
{
case 0:
{
lean_object* v___x_188_; 
v___x_188_ = lean_box(0);
return v___x_188_;
}
case 1:
{
lean_object* v_run_189_; 
v_run_189_ = lean_ctor_get(v_x_187_, 0);
lean_inc(v_run_189_);
return v_run_189_;
}
default: 
{
lean_object* v_left_190_; lean_object* v_right_191_; lean_object* v___x_192_; lean_object* v___x_193_; lean_object* v___x_194_; 
v_left_190_ = lean_ctor_get(v_x_187_, 0);
v_right_191_ = lean_ctor_get(v_x_187_, 1);
v___x_192_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0_spec__0(v_left_190_);
v___x_193_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0_spec__0(v_right_191_);
v___x_194_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0_spec__0_spec__1(v___x_192_, v___x_193_);
return v___x_194_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0_spec__0___boxed(lean_object* v_x_195_){
_start:
{
lean_object* v_res_196_; 
v_res_196_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0_spec__0(v_x_195_);
lean_dec(v_x_195_);
return v_res_196_;
}
}
LEAN_EXPORT lean_object* l_MergeSearchWorker_timedTree(lean_object* v_source_197_, lean_object* v_sink_198_){
_start:
{
lean_object* v___x_200_; lean_object* v___x_201_; lean_object* v___x_202_; lean_object* v___x_203_; lean_object* v___x_204_; lean_object* v___x_205_; lean_object* v___x_206_; lean_object* v___x_207_; lean_object* v___x_208_; 
v___x_200_ = lean_io_mono_nanos_now();
v___x_201_ = lean_st_ref_get(v_source_197_);
v___x_202_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0_spec__0(v___x_201_);
lean_dec(v___x_201_);
v___x_203_ = l_MergeSearchWorker_checksum(v___x_202_);
v___x_204_ = lean_st_ref_set(v_sink_198_, v___x_203_);
v___x_205_ = lean_io_mono_nanos_now();
v___x_206_ = lean_nat_sub(v___x_205_, v___x_200_);
lean_dec(v___x_200_);
lean_dec(v___x_205_);
v___x_207_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_207_, 0, v___x_206_);
lean_ctor_set(v___x_207_, 1, v___x_202_);
v___x_208_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_208_, 0, v___x_207_);
return v___x_208_;
}
}
LEAN_EXPORT lean_object* l_MergeSearchWorker_timedTree___boxed(lean_object* v_source_209_, lean_object* v_sink_210_, lean_object* v_a_211_){
_start:
{
lean_object* v_res_212_; 
v_res_212_ = l_MergeSearchWorker_timedTree(v_source_209_, v_sink_210_);
lean_dec(v_sink_210_);
lean_dec(v_source_209_);
return v_res_212_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0(lean_object* v_t_213_){
_start:
{
lean_object* v___x_214_; 
v___x_214_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0_spec__0(v_t_213_);
return v___x_214_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0___boxed(lean_object* v_t_215_){
_start:
{
lean_object* v_res_216_; 
v_res_216_ = l_LeanSort_Direct_tree___at___00MergeSearchWorker_timedTree_spec__0(v_t_215_);
lean_dec(v_t_215_);
return v_res_216_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__0_spec__0(lean_object* v_j_217_){
_start:
{
lean_object* v___x_218_; 
v___x_218_ = l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonStackTable_fromJson_spec__0_spec__0(v_j_217_);
if (lean_obj_tag(v___x_218_) == 0)
{
lean_object* v_a_219_; lean_object* v___x_221_; uint8_t v_isShared_222_; uint8_t v_isSharedCheck_226_; 
v_a_219_ = lean_ctor_get(v___x_218_, 0);
v_isSharedCheck_226_ = !lean_is_exclusive(v___x_218_);
if (v_isSharedCheck_226_ == 0)
{
v___x_221_ = v___x_218_;
v_isShared_222_ = v_isSharedCheck_226_;
goto v_resetjp_220_;
}
else
{
lean_inc(v_a_219_);
lean_dec(v___x_218_);
v___x_221_ = lean_box(0);
v_isShared_222_ = v_isSharedCheck_226_;
goto v_resetjp_220_;
}
v_resetjp_220_:
{
lean_object* v___x_224_; 
if (v_isShared_222_ == 0)
{
v___x_224_ = v___x_221_;
goto v_reusejp_223_;
}
else
{
lean_object* v_reuseFailAlloc_225_; 
v_reuseFailAlloc_225_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_225_, 0, v_a_219_);
v___x_224_ = v_reuseFailAlloc_225_;
goto v_reusejp_223_;
}
v_reusejp_223_:
{
return v___x_224_;
}
}
}
else
{
lean_object* v_a_227_; lean_object* v___x_229_; uint8_t v_isShared_230_; uint8_t v_isSharedCheck_235_; 
v_a_227_ = lean_ctor_get(v___x_218_, 0);
v_isSharedCheck_235_ = !lean_is_exclusive(v___x_218_);
if (v_isSharedCheck_235_ == 0)
{
v___x_229_ = v___x_218_;
v_isShared_230_ = v_isSharedCheck_235_;
goto v_resetjp_228_;
}
else
{
lean_inc(v_a_227_);
lean_dec(v___x_218_);
v___x_229_ = lean_box(0);
v_isShared_230_ = v_isSharedCheck_235_;
goto v_resetjp_228_;
}
v_resetjp_228_:
{
lean_object* v___x_231_; lean_object* v___x_233_; 
v___x_231_ = lean_array_to_list(v_a_227_);
if (v_isShared_230_ == 0)
{
lean_ctor_set(v___x_229_, 0, v___x_231_);
v___x_233_ = v___x_229_;
goto v_reusejp_232_;
}
else
{
lean_object* v_reuseFailAlloc_234_; 
v_reuseFailAlloc_234_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_234_, 0, v___x_231_);
v___x_233_ = v_reuseFailAlloc_234_;
goto v_reusejp_232_;
}
v_reusejp_232_:
{
return v___x_233_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__0(lean_object* v_j_236_, lean_object* v_k_237_){
_start:
{
lean_object* v___x_238_; lean_object* v___x_239_; 
v___x_238_ = l_Lean_Json_getObjValD(v_j_236_, v_k_237_);
v___x_239_ = l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__0_spec__0(v___x_238_);
return v___x_239_;
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__0___boxed(lean_object* v_j_240_, lean_object* v_k_241_){
_start:
{
lean_object* v_res_242_; 
v_res_242_ = l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__0(v_j_240_, v_k_241_);
lean_dec_ref(v_k_241_);
return v_res_242_;
}
}
LEAN_EXPORT lean_object* l_List_sum___at___00MergeSearchWorker_handle_spec__9(lean_object* v_l_243_){
_start:
{
lean_object* v___x_244_; lean_object* v___x_245_; 
v___x_244_ = lean_unsigned_to_nat(0u);
v___x_245_ = lp_plausible_List_foldr___at___00List_sum___at___00__private_Plausible_Gen_0__Plausible_Gen_sumFst_spec__1_spec__1(v___x_244_, v_l_243_);
return v___x_245_;
}
}
LEAN_EXPORT lean_object* l_List_sum___at___00MergeSearchWorker_handle_spec__9___boxed(lean_object* v_l_246_){
_start:
{
lean_object* v_res_247_; 
v_res_247_ = l_List_sum___at___00MergeSearchWorker_handle_spec__9(v_l_246_);
lean_dec(v_l_246_);
return v_res_247_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__11_spec__15_spec__18(size_t v_sz_248_, size_t v_i_249_, lean_object* v_bs_250_){
_start:
{
uint8_t v___x_251_; 
v___x_251_ = lean_usize_dec_lt(v_i_249_, v_sz_248_);
if (v___x_251_ == 0)
{
return v_bs_250_;
}
else
{
lean_object* v_v_252_; lean_object* v___x_253_; lean_object* v_bs_x27_254_; lean_object* v___x_255_; uint8_t v___x_256_; size_t v___x_257_; size_t v___x_258_; lean_object* v___x_259_; 
v_v_252_ = lean_array_uget(v_bs_250_, v_i_249_);
v___x_253_ = lean_unsigned_to_nat(0u);
v_bs_x27_254_ = lean_array_uset(v_bs_250_, v_i_249_, v___x_253_);
v___x_255_ = lean_alloc_ctor(1, 0, 1);
v___x_256_ = lean_unbox(v_v_252_);
lean_dec(v_v_252_);
lean_ctor_set_uint8(v___x_255_, 0, v___x_256_);
v___x_257_ = ((size_t)1ULL);
v___x_258_ = lean_usize_add(v_i_249_, v___x_257_);
v___x_259_ = lean_array_uset(v_bs_x27_254_, v_i_249_, v___x_255_);
v_i_249_ = v___x_258_;
v_bs_250_ = v___x_259_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__11_spec__15_spec__18___boxed(lean_object* v_sz_261_, lean_object* v_i_262_, lean_object* v_bs_263_){
_start:
{
size_t v_sz_boxed_264_; size_t v_i_boxed_265_; lean_object* v_res_266_; 
v_sz_boxed_264_ = lean_unbox_usize(v_sz_261_);
lean_dec(v_sz_261_);
v_i_boxed_265_ = lean_unbox_usize(v_i_262_);
lean_dec(v_i_262_);
v_res_266_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__11_spec__15_spec__18(v_sz_boxed_264_, v_i_boxed_265_, v_bs_263_);
return v_res_266_;
}
}
LEAN_EXPORT lean_object* l_Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__11_spec__15(lean_object* v_a_267_){
_start:
{
size_t v_sz_268_; size_t v___x_269_; lean_object* v___x_270_; lean_object* v___x_271_; 
v_sz_268_ = lean_array_size(v_a_267_);
v___x_269_ = ((size_t)0ULL);
v___x_270_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__11_spec__15_spec__18(v_sz_268_, v___x_269_, v_a_267_);
v___x_271_ = lean_alloc_ctor(4, 1, 0);
lean_ctor_set(v___x_271_, 0, v___x_270_);
return v___x_271_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00MergeSearchWorker_handle_spec__11(lean_object* v_a_272_){
_start:
{
lean_object* v___x_273_; lean_object* v___x_274_; 
v___x_273_ = lean_array_mk(v_a_272_);
v___x_274_ = l_Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__11_spec__15(v___x_273_);
return v___x_274_;
}
}
LEAN_EXPORT lean_object* l_List_filterMapTR_go___at___00MergeSearchWorker_handle_spec__8(lean_object* v_a_275_, lean_object* v_a_276_){
_start:
{
if (lean_obj_tag(v_a_275_) == 0)
{
lean_object* v___x_277_; 
v___x_277_ = lean_array_to_list(v_a_276_);
return v___x_277_;
}
else
{
lean_object* v_head_278_; 
v_head_278_ = lean_ctor_get(v_a_275_, 0);
if (lean_obj_tag(v_head_278_) == 0)
{
lean_object* v_tail_279_; 
v_tail_279_ = lean_ctor_get(v_a_275_, 1);
lean_inc(v_tail_279_);
lean_dec_ref_known(v_a_275_, 2);
v_a_275_ = v_tail_279_;
goto _start;
}
else
{
lean_object* v_tail_281_; lean_object* v_val_282_; lean_object* v___x_283_; 
lean_inc_ref(v_head_278_);
v_tail_281_ = lean_ctor_get(v_a_275_, 1);
lean_inc(v_tail_281_);
lean_dec_ref_known(v_a_275_, 2);
v_val_282_ = lean_ctor_get(v_head_278_, 0);
lean_inc(v_val_282_);
lean_dec_ref_known(v_head_278_, 1);
v___x_283_ = lean_array_push(v_a_276_, v_val_282_);
v_a_275_ = v_tail_281_;
v_a_276_ = v___x_283_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2_spec__3(size_t v_sz_285_, size_t v_i_286_, lean_object* v_bs_287_){
_start:
{
uint8_t v___x_288_; 
v___x_288_ = lean_usize_dec_lt(v_i_286_, v_sz_285_);
if (v___x_288_ == 0)
{
lean_object* v___x_289_; 
v___x_289_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_289_, 0, v_bs_287_);
return v___x_289_;
}
else
{
lean_object* v_v_290_; lean_object* v___x_291_; 
v_v_290_ = lean_array_uget_borrowed(v_bs_287_, v_i_286_);
lean_inc(v_v_290_);
v___x_291_ = l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonStackTable_fromJson_spec__0_spec__0(v_v_290_);
if (lean_obj_tag(v___x_291_) == 0)
{
lean_object* v_a_292_; lean_object* v___x_294_; uint8_t v_isShared_295_; uint8_t v_isSharedCheck_299_; 
lean_dec_ref(v_bs_287_);
v_a_292_ = lean_ctor_get(v___x_291_, 0);
v_isSharedCheck_299_ = !lean_is_exclusive(v___x_291_);
if (v_isSharedCheck_299_ == 0)
{
v___x_294_ = v___x_291_;
v_isShared_295_ = v_isSharedCheck_299_;
goto v_resetjp_293_;
}
else
{
lean_inc(v_a_292_);
lean_dec(v___x_291_);
v___x_294_ = lean_box(0);
v_isShared_295_ = v_isSharedCheck_299_;
goto v_resetjp_293_;
}
v_resetjp_293_:
{
lean_object* v___x_297_; 
if (v_isShared_295_ == 0)
{
v___x_297_ = v___x_294_;
goto v_reusejp_296_;
}
else
{
lean_object* v_reuseFailAlloc_298_; 
v_reuseFailAlloc_298_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_298_, 0, v_a_292_);
v___x_297_ = v_reuseFailAlloc_298_;
goto v_reusejp_296_;
}
v_reusejp_296_:
{
return v___x_297_;
}
}
}
else
{
lean_object* v_a_300_; lean_object* v___x_301_; lean_object* v_bs_x27_302_; size_t v___x_303_; size_t v___x_304_; lean_object* v___x_305_; 
v_a_300_ = lean_ctor_get(v___x_291_, 0);
lean_inc(v_a_300_);
lean_dec_ref_known(v___x_291_, 1);
v___x_301_ = lean_unsigned_to_nat(0u);
v_bs_x27_302_ = lean_array_uset(v_bs_287_, v_i_286_, v___x_301_);
v___x_303_ = ((size_t)1ULL);
v___x_304_ = lean_usize_add(v_i_286_, v___x_303_);
v___x_305_ = lean_array_uset(v_bs_x27_302_, v_i_286_, v_a_300_);
v_i_286_ = v___x_304_;
v_bs_287_ = v___x_305_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2_spec__3___boxed(lean_object* v_sz_307_, lean_object* v_i_308_, lean_object* v_bs_309_){
_start:
{
size_t v_sz_boxed_310_; size_t v_i_boxed_311_; lean_object* v_res_312_; 
v_sz_boxed_310_ = lean_unbox_usize(v_sz_307_);
lean_dec(v_sz_307_);
v_i_boxed_311_ = lean_unbox_usize(v_i_308_);
lean_dec(v_i_308_);
v_res_312_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2_spec__3(v_sz_boxed_310_, v_i_boxed_311_, v_bs_309_);
return v_res_312_;
}
}
LEAN_EXPORT lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2(lean_object* v_x_315_){
_start:
{
if (lean_obj_tag(v_x_315_) == 4)
{
lean_object* v_elems_316_; size_t v_sz_317_; size_t v___x_318_; lean_object* v___x_319_; 
v_elems_316_ = lean_ctor_get(v_x_315_, 0);
lean_inc_ref(v_elems_316_);
lean_dec_ref_known(v_x_315_, 1);
v_sz_317_ = lean_array_size(v_elems_316_);
v___x_318_ = ((size_t)0ULL);
v___x_319_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2_spec__3(v_sz_317_, v___x_318_, v_elems_316_);
return v___x_319_;
}
else
{
lean_object* v___x_320_; lean_object* v___x_321_; lean_object* v___x_322_; lean_object* v___x_323_; lean_object* v___x_324_; lean_object* v___x_325_; lean_object* v___x_326_; 
v___x_320_ = ((lean_object*)(l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2___closed__0));
v___x_321_ = lean_unsigned_to_nat(80u);
v___x_322_ = l_Lean_Json_pretty(v_x_315_, v___x_321_);
v___x_323_ = lean_string_append(v___x_320_, v___x_322_);
lean_dec_ref(v___x_322_);
v___x_324_ = ((lean_object*)(l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2___closed__1));
v___x_325_ = lean_string_append(v___x_323_, v___x_324_);
v___x_326_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_326_, 0, v___x_325_);
return v___x_326_;
}
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1(lean_object* v_j_327_, lean_object* v_k_328_){
_start:
{
lean_object* v___x_329_; lean_object* v___x_330_; 
v___x_329_ = l_Lean_Json_getObjValD(v_j_327_, v_k_328_);
v___x_330_ = l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2(v___x_329_);
return v___x_330_;
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1___boxed(lean_object* v_j_331_, lean_object* v_k_332_){
_start:
{
lean_object* v_res_333_; 
v_res_333_ = l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1(v_j_331_, v_k_332_);
lean_dec_ref(v_k_332_);
return v_res_333_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__2_spec__4(lean_object* v_j_334_){
_start:
{
lean_object* v___x_335_; 
v___x_335_ = l_Lean_Array_fromJson_x3f___at___00Lean_Widget_instRpcEncodableStrictOrLazy_dec_00___x40_Lean_Widget_InteractiveDiagnostic_2157017296____hygCtx___hyg_1____at___00Lean_Widget_instRpcEncodableHighlightedMsgEmbed_dec_00___x40_Lean_Server_FileWorker_WidgetRequests_2377472685____hygCtx___hyg_1__spec__2_spec__3(v_j_334_);
if (lean_obj_tag(v___x_335_) == 0)
{
lean_object* v_a_336_; lean_object* v___x_338_; uint8_t v_isShared_339_; uint8_t v_isSharedCheck_343_; 
v_a_336_ = lean_ctor_get(v___x_335_, 0);
v_isSharedCheck_343_ = !lean_is_exclusive(v___x_335_);
if (v_isSharedCheck_343_ == 0)
{
v___x_338_ = v___x_335_;
v_isShared_339_ = v_isSharedCheck_343_;
goto v_resetjp_337_;
}
else
{
lean_inc(v_a_336_);
lean_dec(v___x_335_);
v___x_338_ = lean_box(0);
v_isShared_339_ = v_isSharedCheck_343_;
goto v_resetjp_337_;
}
v_resetjp_337_:
{
lean_object* v___x_341_; 
if (v_isShared_339_ == 0)
{
v___x_341_ = v___x_338_;
goto v_reusejp_340_;
}
else
{
lean_object* v_reuseFailAlloc_342_; 
v_reuseFailAlloc_342_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_342_, 0, v_a_336_);
v___x_341_ = v_reuseFailAlloc_342_;
goto v_reusejp_340_;
}
v_reusejp_340_:
{
return v___x_341_;
}
}
}
else
{
lean_object* v_a_344_; lean_object* v___x_346_; uint8_t v_isShared_347_; uint8_t v_isSharedCheck_352_; 
v_a_344_ = lean_ctor_get(v___x_335_, 0);
v_isSharedCheck_352_ = !lean_is_exclusive(v___x_335_);
if (v_isSharedCheck_352_ == 0)
{
v___x_346_ = v___x_335_;
v_isShared_347_ = v_isSharedCheck_352_;
goto v_resetjp_345_;
}
else
{
lean_inc(v_a_344_);
lean_dec(v___x_335_);
v___x_346_ = lean_box(0);
v_isShared_347_ = v_isSharedCheck_352_;
goto v_resetjp_345_;
}
v_resetjp_345_:
{
lean_object* v___x_348_; lean_object* v___x_350_; 
v___x_348_ = lean_array_to_list(v_a_344_);
if (v_isShared_347_ == 0)
{
lean_ctor_set(v___x_346_, 0, v___x_348_);
v___x_350_ = v___x_346_;
goto v_reusejp_349_;
}
else
{
lean_object* v_reuseFailAlloc_351_; 
v_reuseFailAlloc_351_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_351_, 0, v___x_348_);
v___x_350_ = v_reuseFailAlloc_351_;
goto v_reusejp_349_;
}
v_reusejp_349_:
{
return v___x_350_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__2(lean_object* v_j_353_, lean_object* v_k_354_){
_start:
{
lean_object* v___x_355_; lean_object* v___x_356_; 
v___x_355_ = l_Lean_Json_getObjValD(v_j_353_, v_k_354_);
v___x_356_ = l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__2_spec__4(v___x_355_);
return v___x_356_;
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__2___boxed(lean_object* v_j_357_, lean_object* v_k_358_){
_start:
{
lean_object* v_res_359_; 
v_res_359_ = l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__2(v_j_357_, v_k_358_);
lean_dec_ref(v_k_358_);
return v_res_359_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__6(lean_object* v_a_360_, lean_object* v_a_361_, lean_object* v_a_362_){
_start:
{
if (lean_obj_tag(v_a_361_) == 0)
{
lean_object* v___x_363_; 
lean_dec(v_a_360_);
v___x_363_ = l_List_reverse___redArg(v_a_362_);
return v___x_363_;
}
else
{
lean_object* v_head_364_; lean_object* v_tail_365_; lean_object* v___x_367_; uint8_t v_isShared_368_; uint8_t v_isSharedCheck_386_; 
v_head_364_ = lean_ctor_get(v_a_361_, 0);
v_tail_365_ = lean_ctor_get(v_a_361_, 1);
v_isSharedCheck_386_ = !lean_is_exclusive(v_a_361_);
if (v_isSharedCheck_386_ == 0)
{
v___x_367_ = v_a_361_;
v_isShared_368_ = v_isSharedCheck_386_;
goto v_resetjp_366_;
}
else
{
lean_inc(v_tail_365_);
lean_inc(v_head_364_);
lean_dec(v_a_361_);
v___x_367_ = lean_box(0);
v_isShared_368_ = v_isSharedCheck_386_;
goto v_resetjp_366_;
}
v_resetjp_366_:
{
lean_object* v___y_370_; 
if (lean_obj_tag(v_head_364_) == 0)
{
lean_object* v___x_375_; 
v___x_375_ = lean_box(0);
v___y_370_ = v___x_375_;
goto v___jp_369_;
}
else
{
lean_object* v_val_376_; lean_object* v___x_378_; uint8_t v_isShared_379_; uint8_t v_isSharedCheck_385_; 
v_val_376_ = lean_ctor_get(v_head_364_, 0);
v_isSharedCheck_385_ = !lean_is_exclusive(v_head_364_);
if (v_isSharedCheck_385_ == 0)
{
v___x_378_ = v_head_364_;
v_isShared_379_ = v_isSharedCheck_385_;
goto v_resetjp_377_;
}
else
{
lean_inc(v_val_376_);
lean_dec(v_head_364_);
v___x_378_ = lean_box(0);
v_isShared_379_ = v_isSharedCheck_385_;
goto v_resetjp_377_;
}
v_resetjp_377_:
{
lean_object* v___x_380_; lean_object* v___x_381_; lean_object* v___x_383_; 
lean_inc(v_a_360_);
v___x_380_ = lean_alloc_closure((void*)(l_LeanSort_MergeSearch_weights___boxed), 2, 1);
lean_closure_set(v___x_380_, 0, v_a_360_);
v___x_381_ = l_LeanSort_MergeSearch_Shape_budget(v___x_380_, v_val_376_);
if (v_isShared_379_ == 0)
{
lean_ctor_set(v___x_378_, 0, v___x_381_);
v___x_383_ = v___x_378_;
goto v_reusejp_382_;
}
else
{
lean_object* v_reuseFailAlloc_384_; 
v_reuseFailAlloc_384_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_384_, 0, v___x_381_);
v___x_383_ = v_reuseFailAlloc_384_;
goto v_reusejp_382_;
}
v_reusejp_382_:
{
v___y_370_ = v___x_383_;
goto v___jp_369_;
}
}
}
v___jp_369_:
{
lean_object* v___x_372_; 
if (v_isShared_368_ == 0)
{
lean_ctor_set(v___x_367_, 1, v_a_362_);
lean_ctor_set(v___x_367_, 0, v___y_370_);
v___x_372_ = v___x_367_;
goto v_reusejp_371_;
}
else
{
lean_object* v_reuseFailAlloc_374_; 
v_reuseFailAlloc_374_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_374_, 0, v___y_370_);
lean_ctor_set(v_reuseFailAlloc_374_, 1, v_a_362_);
v___x_372_ = v_reuseFailAlloc_374_;
goto v_reusejp_371_;
}
v_reusejp_371_:
{
v_a_361_ = v_tail_365_;
v_a_362_ = v___x_372_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT uint8_t l_List_all___at___00MergeSearchWorker_handle_spec__21(lean_object* v_x_388_){
_start:
{
if (lean_obj_tag(v_x_388_) == 0)
{
uint8_t v___x_389_; 
v___x_389_ = 1;
return v___x_389_;
}
else
{
lean_object* v_head_390_; lean_object* v_tail_391_; lean_object* v___x_392_; uint8_t v___x_393_; 
v_head_390_ = lean_ctor_get(v_x_388_, 0);
lean_inc(v_head_390_);
v_tail_391_ = lean_ctor_get(v_x_388_, 1);
lean_inc(v_tail_391_);
lean_dec_ref_known(v_x_388_, 2);
v___x_392_ = ((lean_object*)(l_List_all___at___00MergeSearchWorker_handle_spec__21___closed__0));
v___x_393_ = l_List_instDecidablePairwise___redArg(v___x_392_, v_head_390_);
if (v___x_393_ == 0)
{
lean_dec(v_tail_391_);
return v___x_393_;
}
else
{
v_x_388_ = v_tail_391_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* l_List_all___at___00MergeSearchWorker_handle_spec__21___boxed(lean_object* v_x_395_){
_start:
{
uint8_t v_res_396_; lean_object* v_r_397_; 
v_res_396_ = l_List_all___at___00MergeSearchWorker_handle_spec__21(v_x_395_);
v_r_397_ = lean_box(v_res_396_);
return v_r_397_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__7(lean_object* v_a_398_, lean_object* v_a_399_, lean_object* v_a_400_, lean_object* v_a_401_){
_start:
{
if (lean_obj_tag(v_a_400_) == 0)
{
lean_object* v___x_402_; 
lean_dec(v_a_398_);
v___x_402_ = l_List_reverse___redArg(v_a_401_);
return v___x_402_;
}
else
{
lean_object* v_head_403_; lean_object* v_tail_404_; lean_object* v___x_406_; uint8_t v_isShared_407_; uint8_t v_isSharedCheck_424_; 
v_head_403_ = lean_ctor_get(v_a_400_, 0);
v_tail_404_ = lean_ctor_get(v_a_400_, 1);
v_isSharedCheck_424_ = !lean_is_exclusive(v_a_400_);
if (v_isSharedCheck_424_ == 0)
{
v___x_406_ = v_a_400_;
v_isShared_407_ = v_isSharedCheck_424_;
goto v_resetjp_405_;
}
else
{
lean_inc(v_tail_404_);
lean_inc(v_head_403_);
lean_dec(v_a_400_);
v___x_406_ = lean_box(0);
v_isShared_407_ = v_isSharedCheck_424_;
goto v_resetjp_405_;
}
v_resetjp_405_:
{
uint8_t v___y_409_; 
if (lean_obj_tag(v_head_403_) == 0)
{
uint8_t v___x_415_; 
v___x_415_ = 0;
v___y_409_ = v___x_415_;
goto v___jp_408_;
}
else
{
lean_object* v_val_416_; lean_object* v___x_417_; lean_object* v___x_418_; uint8_t v___x_419_; 
v_val_416_ = lean_ctor_get(v_head_403_, 0);
lean_inc(v_val_416_);
lean_dec_ref_known(v_head_403_, 1);
v___x_417_ = lean_unsigned_to_nat(0u);
v___x_418_ = l_List_lengthTR___redArg(v_a_398_);
v___x_419_ = l_LeanSort_MergeSearch_checkFits(v_val_416_, v___x_417_, v___x_418_);
if (v___x_419_ == 0)
{
lean_dec(v___x_418_);
lean_dec(v_val_416_);
v___y_409_ = v___x_419_;
goto v___jp_408_;
}
else
{
lean_object* v___x_420_; lean_object* v___x_421_; lean_object* v___x_422_; uint8_t v___x_423_; 
lean_inc(v_a_398_);
v___x_420_ = lean_alloc_closure((void*)(l_LeanSort_MergeSearch_weights___boxed), 2, 1);
lean_closure_set(v___x_420_, 0, v_a_398_);
v___x_421_ = l_LeanSort_MergeSearch_Shape_budget(v___x_420_, v_val_416_);
v___x_422_ = l_LeanSort_MergeSearch_lookup(v_a_399_, v___x_417_, v___x_418_);
lean_dec(v___x_418_);
v___x_423_ = lean_nat_dec_eq(v___x_421_, v___x_422_);
lean_dec(v___x_422_);
lean_dec(v___x_421_);
v___y_409_ = v___x_423_;
goto v___jp_408_;
}
}
v___jp_408_:
{
lean_object* v___x_410_; lean_object* v___x_412_; 
v___x_410_ = lean_box(v___y_409_);
if (v_isShared_407_ == 0)
{
lean_ctor_set(v___x_406_, 1, v_a_401_);
lean_ctor_set(v___x_406_, 0, v___x_410_);
v___x_412_ = v___x_406_;
goto v_reusejp_411_;
}
else
{
lean_object* v_reuseFailAlloc_414_; 
v_reuseFailAlloc_414_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_414_, 0, v___x_410_);
lean_ctor_set(v_reuseFailAlloc_414_, 1, v_a_401_);
v___x_412_ = v_reuseFailAlloc_414_;
goto v_reusejp_411_;
}
v_reusejp_411_:
{
v_a_400_ = v_tail_404_;
v_a_401_ = v___x_412_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__7___boxed(lean_object* v_a_425_, lean_object* v_a_426_, lean_object* v_a_427_, lean_object* v_a_428_){
_start:
{
lean_object* v_res_429_; 
v_res_429_ = l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__7(v_a_425_, v_a_426_, v_a_427_, v_a_428_);
lean_dec_ref(v_a_426_);
return v_res_429_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00MergeSearchWorker_handle_spec__12(lean_object* v_a_430_){
_start:
{
lean_object* v___x_431_; lean_object* v___x_432_; 
v___x_431_ = lean_array_mk(v_a_430_);
v___x_432_ = l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__1(v___x_431_);
return v___x_432_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__20(lean_object* v_a_433_, lean_object* v_a_434_){
_start:
{
if (lean_obj_tag(v_a_433_) == 0)
{
lean_object* v___x_435_; 
v___x_435_ = l_List_reverse___redArg(v_a_434_);
return v___x_435_;
}
else
{
lean_object* v_head_436_; lean_object* v_tail_437_; lean_object* v___x_439_; uint8_t v_isShared_440_; uint8_t v_isSharedCheck_446_; 
v_head_436_ = lean_ctor_get(v_a_433_, 0);
v_tail_437_ = lean_ctor_get(v_a_433_, 1);
v_isSharedCheck_446_ = !lean_is_exclusive(v_a_433_);
if (v_isSharedCheck_446_ == 0)
{
v___x_439_ = v_a_433_;
v_isShared_440_ = v_isSharedCheck_446_;
goto v_resetjp_438_;
}
else
{
lean_inc(v_tail_437_);
lean_inc(v_head_436_);
lean_dec(v_a_433_);
v___x_439_ = lean_box(0);
v_isShared_440_ = v_isSharedCheck_446_;
goto v_resetjp_438_;
}
v_resetjp_438_:
{
lean_object* v___x_441_; lean_object* v___x_443_; 
v___x_441_ = l_List_lengthTR___redArg(v_head_436_);
lean_dec(v_head_436_);
if (v_isShared_440_ == 0)
{
lean_ctor_set(v___x_439_, 1, v_a_434_);
lean_ctor_set(v___x_439_, 0, v___x_441_);
v___x_443_ = v___x_439_;
goto v_reusejp_442_;
}
else
{
lean_object* v_reuseFailAlloc_445_; 
v_reuseFailAlloc_445_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_445_, 0, v___x_441_);
lean_ctor_set(v_reuseFailAlloc_445_, 1, v_a_434_);
v___x_443_ = v_reuseFailAlloc_445_;
goto v_reusejp_442_;
}
v_reusejp_442_:
{
v_a_433_ = v_tail_437_;
v_a_434_ = v___x_443_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__4(lean_object* v_a_447_, lean_object* v_a_448_){
_start:
{
if (lean_obj_tag(v_a_447_) == 0)
{
lean_object* v___x_449_; 
v___x_449_ = l_List_reverse___redArg(v_a_448_);
return v___x_449_;
}
else
{
lean_object* v_head_450_; lean_object* v_tail_451_; lean_object* v___x_453_; uint8_t v_isShared_454_; uint8_t v_isSharedCheck_472_; 
v_head_450_ = lean_ctor_get(v_a_447_, 0);
v_tail_451_ = lean_ctor_get(v_a_447_, 1);
v_isSharedCheck_472_ = !lean_is_exclusive(v_a_447_);
if (v_isSharedCheck_472_ == 0)
{
v___x_453_ = v_a_447_;
v_isShared_454_ = v_isSharedCheck_472_;
goto v_resetjp_452_;
}
else
{
lean_inc(v_tail_451_);
lean_inc(v_head_450_);
lean_dec(v_a_447_);
v___x_453_ = lean_box(0);
v_isShared_454_ = v_isSharedCheck_472_;
goto v_resetjp_452_;
}
v_resetjp_452_:
{
lean_object* v___y_456_; lean_object* v___x_461_; lean_object* v___x_462_; 
v___x_461_ = lean_unsigned_to_nat(130u);
v___x_462_ = l_MergeSearchWorker_decode(v___x_461_, v_head_450_);
if (lean_obj_tag(v___x_462_) == 0)
{
lean_object* v___x_463_; 
lean_dec_ref_known(v___x_462_, 1);
v___x_463_ = lean_box(0);
v___y_456_ = v___x_463_;
goto v___jp_455_;
}
else
{
lean_object* v_a_464_; lean_object* v___x_466_; uint8_t v_isShared_467_; uint8_t v_isSharedCheck_471_; 
v_a_464_ = lean_ctor_get(v___x_462_, 0);
v_isSharedCheck_471_ = !lean_is_exclusive(v___x_462_);
if (v_isSharedCheck_471_ == 0)
{
v___x_466_ = v___x_462_;
v_isShared_467_ = v_isSharedCheck_471_;
goto v_resetjp_465_;
}
else
{
lean_inc(v_a_464_);
lean_dec(v___x_462_);
v___x_466_ = lean_box(0);
v_isShared_467_ = v_isSharedCheck_471_;
goto v_resetjp_465_;
}
v_resetjp_465_:
{
lean_object* v___x_469_; 
if (v_isShared_467_ == 0)
{
v___x_469_ = v___x_466_;
goto v_reusejp_468_;
}
else
{
lean_object* v_reuseFailAlloc_470_; 
v_reuseFailAlloc_470_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_470_, 0, v_a_464_);
v___x_469_ = v_reuseFailAlloc_470_;
goto v_reusejp_468_;
}
v_reusejp_468_:
{
v___y_456_ = v___x_469_;
goto v___jp_455_;
}
}
}
v___jp_455_:
{
lean_object* v___x_458_; 
if (v_isShared_454_ == 0)
{
lean_ctor_set(v___x_453_, 1, v_a_448_);
lean_ctor_set(v___x_453_, 0, v___y_456_);
v___x_458_ = v___x_453_;
goto v_reusejp_457_;
}
else
{
lean_object* v_reuseFailAlloc_460_; 
v_reuseFailAlloc_460_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_460_, 0, v___y_456_);
lean_ctor_set(v_reuseFailAlloc_460_, 1, v_a_448_);
v___x_458_ = v_reuseFailAlloc_460_;
goto v_reusejp_457_;
}
v_reusejp_457_:
{
v_a_447_ = v_tail_451_;
v_a_448_ = v___x_458_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3_spec__6_spec__8_spec__28(size_t v_sz_473_, size_t v_i_474_, lean_object* v_bs_475_){
_start:
{
uint8_t v___x_476_; 
v___x_476_ = lean_usize_dec_lt(v_i_474_, v_sz_473_);
if (v___x_476_ == 0)
{
lean_object* v___x_477_; 
v___x_477_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_477_, 0, v_bs_475_);
return v___x_477_;
}
else
{
lean_object* v_v_478_; lean_object* v___x_479_; 
v_v_478_ = lean_array_uget_borrowed(v_bs_475_, v_i_474_);
lean_inc(v_v_478_);
v___x_479_ = l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__0_spec__0(v_v_478_);
if (lean_obj_tag(v___x_479_) == 0)
{
lean_object* v_a_480_; lean_object* v___x_482_; uint8_t v_isShared_483_; uint8_t v_isSharedCheck_487_; 
lean_dec_ref(v_bs_475_);
v_a_480_ = lean_ctor_get(v___x_479_, 0);
v_isSharedCheck_487_ = !lean_is_exclusive(v___x_479_);
if (v_isSharedCheck_487_ == 0)
{
v___x_482_ = v___x_479_;
v_isShared_483_ = v_isSharedCheck_487_;
goto v_resetjp_481_;
}
else
{
lean_inc(v_a_480_);
lean_dec(v___x_479_);
v___x_482_ = lean_box(0);
v_isShared_483_ = v_isSharedCheck_487_;
goto v_resetjp_481_;
}
v_resetjp_481_:
{
lean_object* v___x_485_; 
if (v_isShared_483_ == 0)
{
v___x_485_ = v___x_482_;
goto v_reusejp_484_;
}
else
{
lean_object* v_reuseFailAlloc_486_; 
v_reuseFailAlloc_486_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_486_, 0, v_a_480_);
v___x_485_ = v_reuseFailAlloc_486_;
goto v_reusejp_484_;
}
v_reusejp_484_:
{
return v___x_485_;
}
}
}
else
{
lean_object* v_a_488_; lean_object* v___x_489_; lean_object* v_bs_x27_490_; size_t v___x_491_; size_t v___x_492_; lean_object* v___x_493_; 
v_a_488_ = lean_ctor_get(v___x_479_, 0);
lean_inc(v_a_488_);
lean_dec_ref_known(v___x_479_, 1);
v___x_489_ = lean_unsigned_to_nat(0u);
v_bs_x27_490_ = lean_array_uset(v_bs_475_, v_i_474_, v___x_489_);
v___x_491_ = ((size_t)1ULL);
v___x_492_ = lean_usize_add(v_i_474_, v___x_491_);
v___x_493_ = lean_array_uset(v_bs_x27_490_, v_i_474_, v_a_488_);
v_i_474_ = v___x_492_;
v_bs_475_ = v___x_493_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3_spec__6_spec__8_spec__28___boxed(lean_object* v_sz_495_, lean_object* v_i_496_, lean_object* v_bs_497_){
_start:
{
size_t v_sz_boxed_498_; size_t v_i_boxed_499_; lean_object* v_res_500_; 
v_sz_boxed_498_ = lean_unbox_usize(v_sz_495_);
lean_dec(v_sz_495_);
v_i_boxed_499_ = lean_unbox_usize(v_i_496_);
lean_dec(v_i_496_);
v_res_500_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3_spec__6_spec__8_spec__28(v_sz_boxed_498_, v_i_boxed_499_, v_bs_497_);
return v_res_500_;
}
}
LEAN_EXPORT lean_object* l_Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3_spec__6_spec__8(lean_object* v_x_501_){
_start:
{
if (lean_obj_tag(v_x_501_) == 4)
{
lean_object* v_elems_502_; size_t v_sz_503_; size_t v___x_504_; lean_object* v___x_505_; 
v_elems_502_ = lean_ctor_get(v_x_501_, 0);
lean_inc_ref(v_elems_502_);
lean_dec_ref_known(v_x_501_, 1);
v_sz_503_ = lean_array_size(v_elems_502_);
v___x_504_ = ((size_t)0ULL);
v___x_505_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3_spec__6_spec__8_spec__28(v_sz_503_, v___x_504_, v_elems_502_);
return v___x_505_;
}
else
{
lean_object* v___x_506_; lean_object* v___x_507_; lean_object* v___x_508_; lean_object* v___x_509_; lean_object* v___x_510_; lean_object* v___x_511_; lean_object* v___x_512_; 
v___x_506_ = ((lean_object*)(l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2___closed__0));
v___x_507_ = lean_unsigned_to_nat(80u);
v___x_508_ = l_Lean_Json_pretty(v_x_501_, v___x_507_);
v___x_509_ = lean_string_append(v___x_506_, v___x_508_);
lean_dec_ref(v___x_508_);
v___x_510_ = ((lean_object*)(l_Lean_Array_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1_spec__2___closed__1));
v___x_511_ = lean_string_append(v___x_509_, v___x_510_);
v___x_512_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_512_, 0, v___x_511_);
return v___x_512_;
}
}
}
LEAN_EXPORT lean_object* l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3_spec__6(lean_object* v_j_513_){
_start:
{
lean_object* v___x_514_; 
v___x_514_ = l_Lean_Array_fromJson_x3f___at___00Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3_spec__6_spec__8(v_j_513_);
if (lean_obj_tag(v___x_514_) == 0)
{
lean_object* v_a_515_; lean_object* v___x_517_; uint8_t v_isShared_518_; uint8_t v_isSharedCheck_522_; 
v_a_515_ = lean_ctor_get(v___x_514_, 0);
v_isSharedCheck_522_ = !lean_is_exclusive(v___x_514_);
if (v_isSharedCheck_522_ == 0)
{
v___x_517_ = v___x_514_;
v_isShared_518_ = v_isSharedCheck_522_;
goto v_resetjp_516_;
}
else
{
lean_inc(v_a_515_);
lean_dec(v___x_514_);
v___x_517_ = lean_box(0);
v_isShared_518_ = v_isSharedCheck_522_;
goto v_resetjp_516_;
}
v_resetjp_516_:
{
lean_object* v___x_520_; 
if (v_isShared_518_ == 0)
{
v___x_520_ = v___x_517_;
goto v_reusejp_519_;
}
else
{
lean_object* v_reuseFailAlloc_521_; 
v_reuseFailAlloc_521_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_521_, 0, v_a_515_);
v___x_520_ = v_reuseFailAlloc_521_;
goto v_reusejp_519_;
}
v_reusejp_519_:
{
return v___x_520_;
}
}
}
else
{
lean_object* v_a_523_; lean_object* v___x_525_; uint8_t v_isShared_526_; uint8_t v_isSharedCheck_531_; 
v_a_523_ = lean_ctor_get(v___x_514_, 0);
v_isSharedCheck_531_ = !lean_is_exclusive(v___x_514_);
if (v_isSharedCheck_531_ == 0)
{
v___x_525_ = v___x_514_;
v_isShared_526_ = v_isSharedCheck_531_;
goto v_resetjp_524_;
}
else
{
lean_inc(v_a_523_);
lean_dec(v___x_514_);
v___x_525_ = lean_box(0);
v_isShared_526_ = v_isSharedCheck_531_;
goto v_resetjp_524_;
}
v_resetjp_524_:
{
lean_object* v___x_527_; lean_object* v___x_529_; 
v___x_527_ = lean_array_to_list(v_a_523_);
if (v_isShared_526_ == 0)
{
lean_ctor_set(v___x_525_, 0, v___x_527_);
v___x_529_ = v___x_525_;
goto v_reusejp_528_;
}
else
{
lean_object* v_reuseFailAlloc_530_; 
v_reuseFailAlloc_530_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_530_, 0, v___x_527_);
v___x_529_ = v_reuseFailAlloc_530_;
goto v_reusejp_528_;
}
v_reusejp_528_:
{
return v___x_529_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3(lean_object* v_j_532_, lean_object* v_k_533_){
_start:
{
lean_object* v___x_534_; lean_object* v___x_535_; 
v___x_534_ = l_Lean_Json_getObjValD(v_j_532_, v_k_533_);
v___x_535_ = l_Lean_List_fromJson_x3f___at___00Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3_spec__6(v___x_534_);
return v___x_535_;
}
}
LEAN_EXPORT lean_object* l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3___boxed(lean_object* v_j_536_, lean_object* v_k_537_){
_start:
{
lean_object* v_res_538_; 
v_res_538_ = l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3(v_j_536_, v_k_537_);
lean_dec_ref(v_k_537_);
return v_res_538_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00MergeSearchWorker_handle_spec__17(lean_object* v_a_539_){
_start:
{
lean_object* v___x_540_; lean_object* v___x_541_; 
v___x_540_ = lean_array_mk(v_a_539_);
v___x_541_ = l_Lean_Array_toJson___at___00Lean_Firefox_instToJsonStackTable_toJson_spec__0(v___x_540_);
return v___x_541_;
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__18_spec__24_spec__31(size_t v_sz_542_, size_t v_i_543_, lean_object* v_bs_544_){
_start:
{
uint8_t v___x_545_; 
v___x_545_ = lean_usize_dec_lt(v_i_543_, v_sz_542_);
if (v___x_545_ == 0)
{
return v_bs_544_;
}
else
{
lean_object* v_v_546_; lean_object* v___x_547_; lean_object* v_bs_x27_548_; lean_object* v___x_549_; size_t v___x_550_; size_t v___x_551_; lean_object* v___x_552_; 
v_v_546_ = lean_array_uget(v_bs_544_, v_i_543_);
v___x_547_ = lean_unsigned_to_nat(0u);
v_bs_x27_548_ = lean_array_uset(v_bs_544_, v_i_543_, v___x_547_);
v___x_549_ = l_Lean_List_toJson___at___00MergeSearchWorker_handle_spec__17(v_v_546_);
v___x_550_ = ((size_t)1ULL);
v___x_551_ = lean_usize_add(v_i_543_, v___x_550_);
v___x_552_ = lean_array_uset(v_bs_x27_548_, v_i_543_, v___x_549_);
v_i_543_ = v___x_551_;
v_bs_544_ = v___x_552_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__18_spec__24_spec__31___boxed(lean_object* v_sz_554_, lean_object* v_i_555_, lean_object* v_bs_556_){
_start:
{
size_t v_sz_boxed_557_; size_t v_i_boxed_558_; lean_object* v_res_559_; 
v_sz_boxed_557_ = lean_unbox_usize(v_sz_554_);
lean_dec(v_sz_554_);
v_i_boxed_558_ = lean_unbox_usize(v_i_555_);
lean_dec(v_i_555_);
v_res_559_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__18_spec__24_spec__31(v_sz_boxed_557_, v_i_boxed_558_, v_bs_556_);
return v_res_559_;
}
}
LEAN_EXPORT lean_object* l_Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__18_spec__24(lean_object* v_a_560_){
_start:
{
size_t v_sz_561_; size_t v___x_562_; lean_object* v___x_563_; lean_object* v___x_564_; 
v_sz_561_ = lean_array_size(v_a_560_);
v___x_562_ = ((size_t)0ULL);
v___x_563_ = l___private_Init_Data_Array_Basic_0__Array_mapMUnsafe_map___at___00Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__18_spec__24_spec__31(v_sz_561_, v___x_562_, v_a_560_);
v___x_564_ = lean_alloc_ctor(4, 1, 0);
lean_ctor_set(v___x_564_, 0, v___x_563_);
return v___x_564_;
}
}
LEAN_EXPORT lean_object* l_Lean_List_toJson___at___00MergeSearchWorker_handle_spec__18(lean_object* v_a_565_){
_start:
{
lean_object* v___x_566_; lean_object* v___x_567_; 
v___x_566_ = lean_array_mk(v_a_565_);
v___x_567_ = l_Lean_Array_toJson___at___00Lean_List_toJson___at___00MergeSearchWorker_handle_spec__18_spec__24(v___x_566_);
return v___x_567_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___redArg(lean_object* v_val_571_, lean_object* v_val_572_, lean_object* v___x_573_, lean_object* v_as_x27_574_, lean_object* v_b_575_){
_start:
{
if (lean_obj_tag(v_as_x27_574_) == 0)
{
lean_object* v___x_577_; 
v___x_577_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_577_, 0, v_b_575_);
return v___x_577_;
}
else
{
lean_object* v_tail_578_; lean_object* v___x_579_; lean_object* v_a_580_; lean_object* v___x_582_; uint8_t v_isShared_583_; uint8_t v_isSharedCheck_601_; 
v_tail_578_ = lean_ctor_get(v_as_x27_574_, 1);
v___x_579_ = l_MergeSearchWorker_timedTree(v_val_571_, v_val_572_);
v_a_580_ = lean_ctor_get(v___x_579_, 0);
v_isSharedCheck_601_ = !lean_is_exclusive(v___x_579_);
if (v_isSharedCheck_601_ == 0)
{
v___x_582_ = v___x_579_;
v_isShared_583_ = v_isSharedCheck_601_;
goto v_resetjp_581_;
}
else
{
lean_inc(v_a_580_);
lean_dec(v___x_579_);
v___x_582_ = lean_box(0);
v_isShared_583_ = v_isSharedCheck_601_;
goto v_resetjp_581_;
}
v_resetjp_581_:
{
lean_object* v_fst_584_; lean_object* v_snd_585_; lean_object* v___x_587_; uint8_t v_isShared_588_; uint8_t v_isSharedCheck_600_; 
v_fst_584_ = lean_ctor_get(v_a_580_, 0);
v_snd_585_ = lean_ctor_get(v_a_580_, 1);
v_isSharedCheck_600_ = !lean_is_exclusive(v_a_580_);
if (v_isSharedCheck_600_ == 0)
{
v___x_587_ = v_a_580_;
v_isShared_588_ = v_isSharedCheck_600_;
goto v_resetjp_586_;
}
else
{
lean_inc(v_snd_585_);
lean_inc(v_fst_584_);
lean_dec(v_a_580_);
v___x_587_ = lean_box(0);
v_isShared_588_ = v_isSharedCheck_600_;
goto v_resetjp_586_;
}
v_resetjp_586_:
{
uint8_t v___x_589_; 
v___x_589_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v_snd_585_, v___x_573_);
lean_dec(v_snd_585_);
if (v___x_589_ == 0)
{
lean_object* v___x_590_; lean_object* v___x_592_; 
lean_del_object(v___x_587_);
lean_dec(v_fst_584_);
lean_dec(v_b_575_);
v___x_590_ = ((lean_object*)(l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___redArg___closed__1));
if (v_isShared_583_ == 0)
{
lean_ctor_set_tag(v___x_582_, 1);
lean_ctor_set(v___x_582_, 0, v___x_590_);
v___x_592_ = v___x_582_;
goto v_reusejp_591_;
}
else
{
lean_object* v_reuseFailAlloc_593_; 
v_reuseFailAlloc_593_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_593_, 0, v___x_590_);
v___x_592_ = v_reuseFailAlloc_593_;
goto v_reusejp_591_;
}
v_reusejp_591_:
{
return v___x_592_;
}
}
else
{
lean_object* v___x_594_; lean_object* v___x_596_; 
lean_del_object(v___x_582_);
v___x_594_ = lean_box(0);
if (v_isShared_588_ == 0)
{
lean_ctor_set_tag(v___x_587_, 1);
lean_ctor_set(v___x_587_, 1, v___x_594_);
v___x_596_ = v___x_587_;
goto v_reusejp_595_;
}
else
{
lean_object* v_reuseFailAlloc_599_; 
v_reuseFailAlloc_599_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_599_, 0, v_fst_584_);
lean_ctor_set(v_reuseFailAlloc_599_, 1, v___x_594_);
v___x_596_ = v_reuseFailAlloc_599_;
goto v_reusejp_595_;
}
v_reusejp_595_:
{
lean_object* v___x_597_; 
v___x_597_ = l_List_appendTR___redArg(v_b_575_, v___x_596_);
v_as_x27_574_ = v_tail_578_;
v_b_575_ = v___x_597_;
goto _start;
}
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___redArg___boxed(lean_object* v_val_602_, lean_object* v_val_603_, lean_object* v___x_604_, lean_object* v_as_x27_605_, lean_object* v_b_606_, lean_object* v___y_607_){
_start:
{
lean_object* v_res_608_; 
v_res_608_ = l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___redArg(v_val_602_, v_val_603_, v___x_604_, v_as_x27_605_, v_b_606_);
lean_dec(v_as_x27_605_);
lean_dec(v___x_604_);
lean_dec(v_val_603_);
lean_dec(v_val_602_);
return v_res_608_;
}
}
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__25___redArg(lean_object* v_m_609_, lean_object* v_f_610_){
_start:
{
lean_object* v_ret_611_; lean_object* v_time_612_; lean_object* v_r_613_; lean_object* v_ret_614_; lean_object* v_time_615_; lean_object* v___x_617_; uint8_t v_isShared_618_; uint8_t v_isSharedCheck_623_; 
v_ret_611_ = lean_ctor_get(v_m_609_, 0);
lean_inc(v_ret_611_);
v_time_612_ = lean_ctor_get(v_m_609_, 1);
lean_inc(v_time_612_);
lean_dec_ref(v_m_609_);
v_r_613_ = lean_apply_1(v_f_610_, v_ret_611_);
v_ret_614_ = lean_ctor_get(v_r_613_, 0);
v_time_615_ = lean_ctor_get(v_r_613_, 1);
v_isSharedCheck_623_ = !lean_is_exclusive(v_r_613_);
if (v_isSharedCheck_623_ == 0)
{
v___x_617_ = v_r_613_;
v_isShared_618_ = v_isSharedCheck_623_;
goto v_resetjp_616_;
}
else
{
lean_inc(v_time_615_);
lean_inc(v_ret_614_);
lean_dec(v_r_613_);
v___x_617_ = lean_box(0);
v_isShared_618_ = v_isSharedCheck_623_;
goto v_resetjp_616_;
}
v_resetjp_616_:
{
lean_object* v___x_619_; lean_object* v___x_621_; 
v___x_619_ = lean_nat_add(v_time_612_, v_time_615_);
lean_dec(v_time_615_);
lean_dec(v_time_612_);
if (v_isShared_618_ == 0)
{
lean_ctor_set(v___x_617_, 1, v___x_619_);
v___x_621_ = v___x_617_;
goto v_reusejp_620_;
}
else
{
lean_object* v_reuseFailAlloc_622_; 
v_reuseFailAlloc_622_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_622_, 0, v_ret_614_);
lean_ctor_set(v_reuseFailAlloc_622_, 1, v___x_619_);
v___x_621_ = v_reuseFailAlloc_622_;
goto v_reusejp_620_;
}
v_reusejp_620_:
{
return v___x_621_;
}
}
}
}
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__23___redArg(lean_object* v_a_624_){
_start:
{
lean_object* v___x_625_; lean_object* v___x_626_; 
v___x_625_ = lean_unsigned_to_nat(0u);
v___x_626_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_626_, 0, v_a_624_);
lean_ctor_set(v___x_626_, 1, v___x_625_);
return v___x_626_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__24___lam__0(lean_object* v_head_627_, lean_object* v_rest_628_){
_start:
{
lean_object* v___x_629_; lean_object* v___x_630_; 
v___x_629_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_629_, 0, v_head_627_);
lean_ctor_set(v___x_629_, 1, v_rest_628_);
v___x_630_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__23___redArg(v___x_629_);
return v___x_630_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__24___lam__2___boxed(lean_object* v_x_631_, lean_object* v_tail_632_, lean_object* v___f_633_, lean_object* v_tail_634_, lean_object* v_x_635_, lean_object* v___f_636_, lean_object* v_smaller_637_){
_start:
{
uint8_t v_smaller_boxed_638_; lean_object* v_res_639_; 
v_smaller_boxed_638_ = lean_unbox(v_smaller_637_);
v_res_639_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__24___lam__2(v_x_631_, v_tail_632_, v___f_633_, v_tail_634_, v_x_635_, v___f_636_, v_smaller_boxed_638_);
return v_res_639_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__24(lean_object* v_x_640_, lean_object* v_x_641_){
_start:
{
if (lean_obj_tag(v_x_640_) == 0)
{
lean_object* v___x_642_; 
v___x_642_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__23___redArg(v_x_641_);
return v___x_642_;
}
else
{
if (lean_obj_tag(v_x_641_) == 0)
{
lean_object* v___x_643_; 
v___x_643_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__23___redArg(v_x_640_);
return v___x_643_;
}
else
{
lean_object* v_head_644_; lean_object* v_tail_645_; lean_object* v_head_646_; lean_object* v_tail_647_; lean_object* v___f_648_; lean_object* v___f_649_; lean_object* v___f_650_; uint8_t v___x_651_; lean_object* v___x_652_; lean_object* v___x_653_; lean_object* v___x_654_; lean_object* v___x_655_; 
v_head_644_ = lean_ctor_get(v_x_640_, 0);
lean_inc_n(v_head_644_, 2);
v_tail_645_ = lean_ctor_get(v_x_640_, 1);
lean_inc(v_tail_645_);
v_head_646_ = lean_ctor_get(v_x_641_, 0);
lean_inc_n(v_head_646_, 2);
v_tail_647_ = lean_ctor_get(v_x_641_, 1);
lean_inc(v_tail_647_);
v___f_648_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__24___lam__0), 2, 1);
lean_closure_set(v___f_648_, 0, v_head_644_);
v___f_649_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__24___lam__0), 2, 1);
lean_closure_set(v___f_649_, 0, v_head_646_);
v___f_650_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__24___lam__2___boxed), 7, 6);
lean_closure_set(v___f_650_, 0, v_x_640_);
lean_closure_set(v___f_650_, 1, v_tail_647_);
lean_closure_set(v___f_650_, 2, v___f_649_);
lean_closure_set(v___f_650_, 3, v_tail_645_);
lean_closure_set(v___f_650_, 4, v_x_641_);
lean_closure_set(v___f_650_, 5, v___f_648_);
v___x_651_ = lean_nat_dec_le(v_head_644_, v_head_646_);
lean_dec(v_head_646_);
lean_dec(v_head_644_);
v___x_652_ = lean_unsigned_to_nat(1u);
v___x_653_ = lean_box(v___x_651_);
v___x_654_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_654_, 0, v___x_653_);
lean_ctor_set(v___x_654_, 1, v___x_652_);
v___x_655_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__25___redArg(v___x_654_, v___f_650_);
return v___x_655_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__24___lam__2(lean_object* v_x_656_, lean_object* v_tail_657_, lean_object* v___f_658_, lean_object* v_tail_659_, lean_object* v_x_660_, lean_object* v___f_661_, uint8_t v_smaller_662_){
_start:
{
if (v_smaller_662_ == 0)
{
lean_object* v___x_663_; lean_object* v___x_664_; 
lean_dec_ref(v___f_661_);
lean_dec(v_x_660_);
lean_dec(v_tail_659_);
v___x_663_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__24(v_x_656_, v_tail_657_);
v___x_664_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__25___redArg(v___x_663_, v___f_658_);
return v___x_664_;
}
else
{
lean_object* v___x_665_; lean_object* v___x_666_; 
lean_dec_ref(v___f_658_);
lean_dec(v_tail_657_);
lean_dec(v_x_656_);
v___x_665_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__24(v_tail_659_, v_x_660_);
v___x_666_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__25___redArg(v___x_665_, v___f_661_);
return v___x_666_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19___lam__0(lean_object* v_ls_667_, lean_object* v_rs_668_){
_start:
{
lean_object* v___x_669_; 
v___x_669_ = l_LeanSort_Direct_Engine_merge___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__24(v_ls_667_, v_rs_668_);
return v___x_669_;
}
}
static lean_object* _init_l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19___closed__0(void){
_start:
{
lean_object* v___x_670_; lean_object* v___x_671_; 
v___x_670_ = lean_box(0);
v___x_671_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__23___redArg(v___x_670_);
return v___x_671_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19(lean_object* v_x_672_){
_start:
{
switch(lean_obj_tag(v_x_672_))
{
case 0:
{
lean_object* v___x_673_; 
v___x_673_ = lean_obj_once(&l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19___closed__0, &l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19___closed__0_once, _init_l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19___closed__0);
return v___x_673_;
}
case 1:
{
lean_object* v_run_674_; lean_object* v___x_675_; 
v_run_674_ = lean_ctor_get(v_x_672_, 0);
lean_inc(v_run_674_);
lean_dec_ref_known(v_x_672_, 1);
v___x_675_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__23___redArg(v_run_674_);
return v___x_675_;
}
default: 
{
lean_object* v_left_676_; lean_object* v_right_677_; lean_object* v___f_678_; lean_object* v___x_679_; lean_object* v___x_680_; 
v_left_676_ = lean_ctor_get(v_x_672_, 0);
lean_inc(v_left_676_);
v_right_677_ = lean_ctor_get(v_x_672_, 1);
lean_inc(v_right_677_);
lean_dec_ref_known(v_x_672_, 2);
v___f_678_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19___lam__1), 2, 1);
lean_closure_set(v___f_678_, 0, v_right_677_);
v___x_679_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19(v_left_676_);
v___x_680_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__25___redArg(v___x_679_, v___f_678_);
return v___x_680_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19___lam__1(lean_object* v_right_681_, lean_object* v_ls_682_){
_start:
{
lean_object* v___f_683_; lean_object* v___x_684_; lean_object* v___x_685_; 
v___f_683_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19___lam__0), 2, 1);
lean_closure_set(v___f_683_, 0, v_ls_682_);
v___x_684_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19(v_right_681_);
v___x_685_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__25___redArg(v___x_684_, v___f_683_);
return v___x_685_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00MergeSearchWorker_handle_spec__15___redArg(lean_object* v_x_686_){
_start:
{
if (lean_obj_tag(v_x_686_) == 0)
{
lean_object* v_value_687_; lean_object* v___x_688_; lean_object* v___x_689_; 
v_value_687_ = lean_ctor_get(v_x_686_, 0);
lean_inc(v_value_687_);
lean_dec_ref_known(v_x_686_, 1);
v___x_688_ = lean_unsigned_to_nat(0u);
v___x_689_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_689_, 0, v_value_687_);
lean_ctor_set(v___x_689_, 1, v___x_688_);
return v___x_689_;
}
else
{
lean_object* v_left_690_; lean_object* v_right_691_; lean_object* v_next_692_; uint8_t v___x_693_; lean_object* v___x_694_; lean_object* v___x_695_; lean_object* v_rest_696_; lean_object* v_ret_697_; lean_object* v_time_698_; lean_object* v___x_700_; uint8_t v_isShared_701_; uint8_t v_isSharedCheck_707_; 
v_left_690_ = lean_ctor_get(v_x_686_, 0);
lean_inc(v_left_690_);
v_right_691_ = lean_ctor_get(v_x_686_, 1);
lean_inc(v_right_691_);
v_next_692_ = lean_ctor_get(v_x_686_, 2);
lean_inc_ref(v_next_692_);
lean_dec_ref_known(v_x_686_, 3);
v___x_693_ = lean_nat_dec_le(v_left_690_, v_right_691_);
lean_dec(v_right_691_);
lean_dec(v_left_690_);
v___x_694_ = lean_box(v___x_693_);
v___x_695_ = lean_apply_1(v_next_692_, v___x_694_);
v_rest_696_ = l_LeanSort_Comparison_Program_eval___at___00MergeSearchWorker_handle_spec__15___redArg(v___x_695_);
v_ret_697_ = lean_ctor_get(v_rest_696_, 0);
v_time_698_ = lean_ctor_get(v_rest_696_, 1);
v_isSharedCheck_707_ = !lean_is_exclusive(v_rest_696_);
if (v_isSharedCheck_707_ == 0)
{
v___x_700_ = v_rest_696_;
v_isShared_701_ = v_isSharedCheck_707_;
goto v_resetjp_699_;
}
else
{
lean_inc(v_time_698_);
lean_inc(v_ret_697_);
lean_dec(v_rest_696_);
v___x_700_ = lean_box(0);
v_isShared_701_ = v_isSharedCheck_707_;
goto v_resetjp_699_;
}
v_resetjp_699_:
{
lean_object* v___x_702_; lean_object* v___x_703_; lean_object* v___x_705_; 
v___x_702_ = lean_unsigned_to_nat(1u);
v___x_703_ = lean_nat_add(v_time_698_, v___x_702_);
lean_dec(v_time_698_);
if (v_isShared_701_ == 0)
{
lean_ctor_set(v___x_700_, 1, v___x_703_);
v___x_705_ = v___x_700_;
goto v_reusejp_704_;
}
else
{
lean_object* v_reuseFailAlloc_706_; 
v_reuseFailAlloc_706_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_706_, 0, v_ret_697_);
lean_ctor_set(v_reuseFailAlloc_706_, 1, v___x_703_);
v___x_705_ = v_reuseFailAlloc_706_;
goto v_reusejp_704_;
}
v_reusejp_704_:
{
return v___x_705_;
}
}
}
}
}
static lean_object* _init_l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__2(void){
_start:
{
lean_object* v___x_711_; lean_object* v___x_712_; 
v___x_711_ = lean_unsigned_to_nat(3u);
v___x_712_ = l_List_range(v___x_711_);
return v___x_712_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg(lean_object* v_a_718_, lean_object* v___x_719_, lean_object* v_as_x27_720_, lean_object* v_b_721_){
_start:
{
if (lean_obj_tag(v_as_x27_720_) == 0)
{
lean_object* v___x_726_; 
lean_dec(v_a_718_);
v___x_726_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_726_, 0, v_b_721_);
return v___x_726_;
}
else
{
lean_object* v_head_727_; lean_object* v_tail_728_; lean_object* v___x_729_; lean_object* v___x_730_; lean_object* v___y_732_; lean_object* v___y_733_; lean_object* v___y_734_; uint8_t v___y_735_; lean_object* v___y_796_; 
v_head_727_ = lean_ctor_get(v_as_x27_720_, 0);
v_tail_728_ = lean_ctor_get(v_as_x27_720_, 1);
v___x_729_ = lean_unsigned_to_nat(0u);
v___x_730_ = lean_box(0);
if (lean_obj_tag(v_head_727_) == 0)
{
lean_object* v___x_805_; 
v___x_805_ = lean_box(0);
v___y_796_ = v___x_805_;
goto v___jp_795_;
}
else
{
lean_object* v_val_806_; 
v_val_806_ = lean_ctor_get(v_head_727_, 0);
v___y_796_ = v_val_806_;
goto v___jp_795_;
}
v___jp_731_:
{
if (v___y_735_ == 0)
{
lean_dec(v___y_734_);
lean_dec_ref(v___y_733_);
lean_dec_ref(v___y_732_);
lean_dec(v_b_721_);
lean_dec(v_a_718_);
goto v___jp_723_;
}
else
{
lean_object* v_ret_736_; lean_object* v_time_737_; lean_object* v___x_739_; uint8_t v_isShared_740_; uint8_t v_isSharedCheck_794_; 
v_ret_736_ = lean_ctor_get(v___y_733_, 0);
v_time_737_ = lean_ctor_get(v___y_733_, 1);
v_isSharedCheck_794_ = !lean_is_exclusive(v___y_733_);
if (v_isSharedCheck_794_ == 0)
{
v___x_739_ = v___y_733_;
v_isShared_740_ = v_isSharedCheck_794_;
goto v_resetjp_738_;
}
else
{
lean_inc(v_time_737_);
lean_inc(v_ret_736_);
lean_dec(v___y_733_);
v___x_739_ = lean_box(0);
v_isShared_740_ = v_isSharedCheck_794_;
goto v_resetjp_738_;
}
v_resetjp_738_:
{
lean_object* v_time_741_; lean_object* v___x_743_; uint8_t v_isShared_744_; uint8_t v_isSharedCheck_792_; 
v_time_741_ = lean_ctor_get(v___y_732_, 1);
v_isSharedCheck_792_ = !lean_is_exclusive(v___y_732_);
if (v_isSharedCheck_792_ == 0)
{
lean_object* v_unused_793_; 
v_unused_793_ = lean_ctor_get(v___y_732_, 0);
lean_dec(v_unused_793_);
v___x_743_ = v___y_732_;
v_isShared_744_ = v_isSharedCheck_792_;
goto v_resetjp_742_;
}
else
{
lean_inc(v_time_741_);
lean_dec(v___y_732_);
v___x_743_ = lean_box(0);
v_isShared_744_ = v_isSharedCheck_792_;
goto v_resetjp_742_;
}
v_resetjp_742_:
{
uint8_t v___x_745_; 
v___x_745_ = lean_nat_dec_eq(v_time_737_, v_time_741_);
lean_dec(v_time_741_);
if (v___x_745_ == 0)
{
lean_del_object(v___x_743_);
lean_del_object(v___x_739_);
lean_dec(v_time_737_);
lean_dec(v_ret_736_);
lean_dec(v___y_734_);
lean_dec(v_b_721_);
lean_dec(v_a_718_);
goto v___jp_723_;
}
else
{
lean_object* v___x_746_; uint8_t v___x_747_; 
v___x_746_ = lp_leansort_LeanSort_RunAdaptive_MergeTree_budget___redArg(v___y_734_);
v___x_747_ = lean_nat_dec_le(v_time_737_, v___x_746_);
if (v___x_747_ == 0)
{
lean_dec(v___x_746_);
lean_del_object(v___x_743_);
lean_del_object(v___x_739_);
lean_dec(v_time_737_);
lean_dec(v_ret_736_);
lean_dec(v___y_734_);
lean_dec(v_b_721_);
lean_dec(v_a_718_);
goto v___jp_723_;
}
else
{
lean_object* v___x_748_; lean_object* v___x_749_; lean_object* v___x_750_; lean_object* v___x_751_; 
lean_inc(v___y_734_);
v___x_748_ = lean_st_mk_ref(v___y_734_);
v___x_749_ = lean_st_mk_ref(v___x_729_);
v___x_750_ = lean_obj_once(&l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__2, &l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__2_once, _init_l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__2);
v___x_751_ = l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___redArg(v___x_748_, v___x_749_, v___x_719_, v___x_750_, v___x_730_);
lean_dec(v___x_749_);
lean_dec(v___x_748_);
if (lean_obj_tag(v___x_751_) == 0)
{
lean_object* v_a_752_; lean_object* v___x_753_; lean_object* v___x_754_; lean_object* v___x_756_; 
v_a_752_ = lean_ctor_get(v___x_751_, 0);
lean_inc(v_a_752_);
lean_dec_ref_known(v___x_751_, 1);
v___x_753_ = ((lean_object*)(l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__3));
v___x_754_ = l_Lean_List_toJson___at___00MergeSearchWorker_handle_spec__17(v_ret_736_);
if (v_isShared_744_ == 0)
{
lean_ctor_set(v___x_743_, 1, v___x_754_);
lean_ctor_set(v___x_743_, 0, v___x_753_);
v___x_756_ = v___x_743_;
goto v_reusejp_755_;
}
else
{
lean_object* v_reuseFailAlloc_783_; 
v_reuseFailAlloc_783_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_783_, 0, v___x_753_);
lean_ctor_set(v_reuseFailAlloc_783_, 1, v___x_754_);
v___x_756_ = v_reuseFailAlloc_783_;
goto v_reusejp_755_;
}
v_reusejp_755_:
{
lean_object* v___x_757_; lean_object* v___x_758_; lean_object* v___x_759_; lean_object* v___x_761_; 
v___x_757_ = ((lean_object*)(l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__4));
v___x_758_ = l_Lean_JsonNumber_fromNat(v_time_737_);
v___x_759_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_759_, 0, v___x_758_);
if (v_isShared_740_ == 0)
{
lean_ctor_set(v___x_739_, 1, v___x_759_);
lean_ctor_set(v___x_739_, 0, v___x_757_);
v___x_761_ = v___x_739_;
goto v_reusejp_760_;
}
else
{
lean_object* v_reuseFailAlloc_782_; 
v_reuseFailAlloc_782_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_782_, 0, v___x_757_);
lean_ctor_set(v_reuseFailAlloc_782_, 1, v___x_759_);
v___x_761_ = v_reuseFailAlloc_782_;
goto v_reusejp_760_;
}
v_reusejp_760_:
{
lean_object* v___x_762_; lean_object* v___x_763_; lean_object* v___x_764_; lean_object* v___x_765_; lean_object* v___x_766_; lean_object* v___x_767_; lean_object* v___x_768_; lean_object* v___x_769_; lean_object* v___x_770_; lean_object* v___x_771_; lean_object* v___x_772_; lean_object* v___x_773_; lean_object* v___x_774_; lean_object* v___x_775_; lean_object* v___x_776_; lean_object* v___x_777_; lean_object* v___x_778_; lean_object* v___x_779_; lean_object* v___x_780_; 
v___x_762_ = ((lean_object*)(l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__5));
v___x_763_ = l_Lean_JsonNumber_fromNat(v___x_746_);
v___x_764_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_764_, 0, v___x_763_);
v___x_765_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_765_, 0, v___x_762_);
lean_ctor_set(v___x_765_, 1, v___x_764_);
v___x_766_ = ((lean_object*)(l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__6));
v___x_767_ = l_Lean_List_toJson___at___00MergeSearchWorker_handle_spec__17(v_a_752_);
v___x_768_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_768_, 0, v___x_766_);
lean_ctor_set(v___x_768_, 1, v___x_767_);
v___x_769_ = ((lean_object*)(l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__7));
v___x_770_ = lp_leansort_LeanSort_RunAdaptive_MergeTree_leaves___redArg(v___y_734_);
lean_dec(v___y_734_);
v___x_771_ = l_Lean_List_toJson___at___00MergeSearchWorker_handle_spec__18(v___x_770_);
v___x_772_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_772_, 0, v___x_769_);
lean_ctor_set(v___x_772_, 1, v___x_771_);
v___x_773_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_773_, 0, v___x_772_);
lean_ctor_set(v___x_773_, 1, v___x_730_);
v___x_774_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_774_, 0, v___x_768_);
lean_ctor_set(v___x_774_, 1, v___x_773_);
v___x_775_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_775_, 0, v___x_765_);
lean_ctor_set(v___x_775_, 1, v___x_774_);
v___x_776_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_776_, 0, v___x_761_);
lean_ctor_set(v___x_776_, 1, v___x_775_);
v___x_777_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_777_, 0, v___x_756_);
lean_ctor_set(v___x_777_, 1, v___x_776_);
v___x_778_ = l_Lean_Json_mkObj(v___x_777_);
lean_dec_ref_known(v___x_777_, 2);
v___x_779_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_779_, 0, v___x_778_);
lean_ctor_set(v___x_779_, 1, v___x_730_);
v___x_780_ = l_List_appendTR___redArg(v_b_721_, v___x_779_);
v_as_x27_720_ = v_tail_728_;
v_b_721_ = v___x_780_;
goto _start;
}
}
}
else
{
lean_object* v_a_784_; lean_object* v___x_786_; uint8_t v_isShared_787_; uint8_t v_isSharedCheck_791_; 
lean_dec(v___x_746_);
lean_del_object(v___x_743_);
lean_del_object(v___x_739_);
lean_dec(v_time_737_);
lean_dec(v_ret_736_);
lean_dec(v___y_734_);
lean_dec(v_b_721_);
lean_dec(v_a_718_);
v_a_784_ = lean_ctor_get(v___x_751_, 0);
v_isSharedCheck_791_ = !lean_is_exclusive(v___x_751_);
if (v_isSharedCheck_791_ == 0)
{
v___x_786_ = v___x_751_;
v_isShared_787_ = v_isSharedCheck_791_;
goto v_resetjp_785_;
}
else
{
lean_inc(v_a_784_);
lean_dec(v___x_751_);
v___x_786_ = lean_box(0);
v_isShared_787_ = v_isSharedCheck_791_;
goto v_resetjp_785_;
}
v_resetjp_785_:
{
lean_object* v___x_789_; 
if (v_isShared_787_ == 0)
{
v___x_789_ = v___x_786_;
goto v_reusejp_788_;
}
else
{
lean_object* v_reuseFailAlloc_790_; 
v_reuseFailAlloc_790_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_790_, 0, v_a_784_);
v___x_789_ = v_reuseFailAlloc_790_;
goto v_reusejp_788_;
}
v_reusejp_788_:
{
return v___x_789_;
}
}
}
}
}
}
}
}
}
v___jp_795_:
{
lean_object* v___x_797_; lean_object* v___x_798_; lean_object* v_ret_799_; lean_object* v___x_800_; lean_object* v___x_801_; uint8_t v___x_802_; 
lean_inc(v___y_796_);
lean_inc(v_a_718_);
v___x_797_ = l_LeanSort_MergeSearch_safePlan___redArg(v_a_718_, v___y_796_);
lean_inc_n(v___x_797_, 2);
v___x_798_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19(v___x_797_);
v_ret_799_ = lean_ctor_get(v___x_798_, 0);
lean_inc(v_ret_799_);
v___x_800_ = lp_leansort_LeanSort_RunAdaptive_MergeTree_program___redArg(v___x_797_);
v___x_801_ = l_LeanSort_Comparison_Program_eval___at___00MergeSearchWorker_handle_spec__15___redArg(v___x_800_);
v___x_802_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v_ret_799_, v___x_719_);
if (v___x_802_ == 0)
{
lean_dec(v_ret_799_);
v___y_732_ = v___x_801_;
v___y_733_ = v___x_798_;
v___y_734_ = v___x_797_;
v___y_735_ = v___x_802_;
goto v___jp_731_;
}
else
{
lean_object* v_ret_803_; uint8_t v___x_804_; 
v_ret_803_ = lean_ctor_get(v___x_801_, 0);
lean_inc(v_ret_803_);
v___x_804_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v_ret_799_, v_ret_803_);
lean_dec(v_ret_803_);
lean_dec(v_ret_799_);
v___y_732_ = v___x_801_;
v___y_733_ = v___x_798_;
v___y_734_ = v___x_797_;
v___y_735_ = v___x_804_;
goto v___jp_731_;
}
}
}
v___jp_723_:
{
lean_object* v___x_724_; lean_object* v___x_725_; 
v___x_724_ = ((lean_object*)(l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___closed__1));
v___x_725_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_725_, 0, v___x_724_);
return v___x_725_;
}
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg___boxed(lean_object* v_a_807_, lean_object* v___x_808_, lean_object* v_as_x27_809_, lean_object* v_b_810_, lean_object* v___y_811_){
_start:
{
lean_object* v_res_812_; 
v_res_812_ = l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg(v_a_807_, v___x_808_, v_as_x27_809_, v_b_810_);
lean_dec(v_as_x27_809_);
lean_dec(v___x_808_);
return v_res_812_;
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__10(lean_object* v_a_813_, lean_object* v_a_814_){
_start:
{
if (lean_obj_tag(v_a_813_) == 0)
{
lean_object* v___x_815_; 
v___x_815_ = l_List_reverse___redArg(v_a_814_);
return v___x_815_;
}
else
{
lean_object* v_head_816_; lean_object* v_tail_817_; lean_object* v___x_819_; uint8_t v_isShared_820_; uint8_t v_isSharedCheck_827_; 
v_head_816_ = lean_ctor_get(v_a_813_, 0);
v_tail_817_ = lean_ctor_get(v_a_813_, 1);
v_isSharedCheck_827_ = !lean_is_exclusive(v_a_813_);
if (v_isSharedCheck_827_ == 0)
{
v___x_819_ = v_a_813_;
v_isShared_820_ = v_isSharedCheck_827_;
goto v_resetjp_818_;
}
else
{
lean_inc(v_tail_817_);
lean_inc(v_head_816_);
lean_dec(v_a_813_);
v___x_819_ = lean_box(0);
v_isShared_820_ = v_isSharedCheck_827_;
goto v_resetjp_818_;
}
v_resetjp_818_:
{
lean_object* v___x_821_; lean_object* v___x_822_; lean_object* v___x_824_; 
v___x_821_ = lean_unsigned_to_nat(0u);
v___x_822_ = l_List_replicateTR___redArg(v_head_816_, v___x_821_);
if (v_isShared_820_ == 0)
{
lean_ctor_set(v___x_819_, 1, v_a_814_);
lean_ctor_set(v___x_819_, 0, v___x_822_);
v___x_824_ = v___x_819_;
goto v_reusejp_823_;
}
else
{
lean_object* v_reuseFailAlloc_826_; 
v_reuseFailAlloc_826_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_826_, 0, v___x_822_);
lean_ctor_set(v_reuseFailAlloc_826_, 1, v_a_814_);
v___x_824_ = v_reuseFailAlloc_826_;
goto v_reusejp_823_;
}
v_reusejp_823_:
{
v_a_813_ = v_tail_817_;
v_a_814_ = v___x_824_;
goto _start;
}
}
}
}
}
LEAN_EXPORT lean_object* l___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00MergeSearchWorker_handle_spec__13(lean_object* v_a_828_, lean_object* v_a_829_){
_start:
{
if (lean_obj_tag(v_a_828_) == 0)
{
lean_object* v___x_830_; 
v___x_830_ = lean_array_to_list(v_a_829_);
return v___x_830_;
}
else
{
lean_object* v_head_831_; lean_object* v_tail_832_; lean_object* v___x_833_; 
v_head_831_ = lean_ctor_get(v_a_828_, 0);
lean_inc(v_head_831_);
v_tail_832_ = lean_ctor_get(v_a_828_, 1);
lean_inc(v_tail_832_);
lean_dec_ref_known(v_a_828_, 2);
v___x_833_ = l_List_foldl___at___00Array_appendList_spec__0___redArg(v_a_829_, v_head_831_);
v_a_828_ = v_tail_832_;
v_a_829_ = v___x_833_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__5(lean_object* v_a_835_, lean_object* v_a_836_, lean_object* v_a_837_){
_start:
{
if (lean_obj_tag(v_a_836_) == 0)
{
lean_object* v___x_838_; 
v___x_838_ = l_List_reverse___redArg(v_a_837_);
return v___x_838_;
}
else
{
lean_object* v_head_839_; lean_object* v_tail_840_; lean_object* v___x_842_; uint8_t v_isShared_843_; uint8_t v_isSharedCheck_856_; 
v_head_839_ = lean_ctor_get(v_a_836_, 0);
v_tail_840_ = lean_ctor_get(v_a_836_, 1);
v_isSharedCheck_856_ = !lean_is_exclusive(v_a_836_);
if (v_isSharedCheck_856_ == 0)
{
v___x_842_ = v_a_836_;
v_isShared_843_ = v_isSharedCheck_856_;
goto v_resetjp_841_;
}
else
{
lean_inc(v_tail_840_);
lean_inc(v_head_839_);
lean_dec(v_a_836_);
v___x_842_ = lean_box(0);
v_isShared_843_ = v_isSharedCheck_856_;
goto v_resetjp_841_;
}
v_resetjp_841_:
{
uint8_t v___y_845_; 
if (lean_obj_tag(v_head_839_) == 0)
{
uint8_t v___x_851_; 
v___x_851_ = 0;
v___y_845_ = v___x_851_;
goto v___jp_844_;
}
else
{
lean_object* v_val_852_; lean_object* v___x_853_; lean_object* v___x_854_; uint8_t v___x_855_; 
v_val_852_ = lean_ctor_get(v_head_839_, 0);
lean_inc(v_val_852_);
lean_dec_ref_known(v_head_839_, 1);
v___x_853_ = lean_unsigned_to_nat(0u);
v___x_854_ = l_List_lengthTR___redArg(v_a_835_);
v___x_855_ = l_LeanSort_MergeSearch_checkFits(v_val_852_, v___x_853_, v___x_854_);
lean_dec(v___x_854_);
lean_dec(v_val_852_);
v___y_845_ = v___x_855_;
goto v___jp_844_;
}
v___jp_844_:
{
lean_object* v___x_846_; lean_object* v___x_848_; 
v___x_846_ = lean_box(v___y_845_);
if (v_isShared_843_ == 0)
{
lean_ctor_set(v___x_842_, 1, v_a_837_);
lean_ctor_set(v___x_842_, 0, v___x_846_);
v___x_848_ = v___x_842_;
goto v_reusejp_847_;
}
else
{
lean_object* v_reuseFailAlloc_850_; 
v_reuseFailAlloc_850_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_850_, 0, v___x_846_);
lean_ctor_set(v_reuseFailAlloc_850_, 1, v_a_837_);
v___x_848_ = v_reuseFailAlloc_850_;
goto v_reusejp_847_;
}
v_reusejp_847_:
{
v_a_836_ = v_tail_840_;
v_a_837_ = v___x_848_;
goto _start;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__5___boxed(lean_object* v_a_857_, lean_object* v_a_858_, lean_object* v_a_859_){
_start:
{
lean_object* v_res_860_; 
v_res_860_ = l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__5(v_a_857_, v_a_858_, v_a_859_);
lean_dec(v_a_857_);
return v_res_860_;
}
}
LEAN_EXPORT uint8_t l_List_all___at___00MergeSearchWorker_handle_spec__22(lean_object* v_x_861_){
_start:
{
if (lean_obj_tag(v_x_861_) == 0)
{
uint8_t v___x_862_; 
v___x_862_ = 1;
return v___x_862_;
}
else
{
lean_object* v_head_863_; lean_object* v_tail_864_; lean_object* v___x_865_; uint8_t v___x_866_; 
v_head_863_ = lean_ctor_get(v_x_861_, 0);
v_tail_864_ = lean_ctor_get(v_x_861_, 1);
v___x_865_ = lean_unsigned_to_nat(0u);
v___x_866_ = lean_nat_dec_lt(v___x_865_, v_head_863_);
if (v___x_866_ == 0)
{
return v___x_866_;
}
else
{
v_x_861_ = v_tail_864_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* l_List_all___at___00MergeSearchWorker_handle_spec__22___boxed(lean_object* v_x_868_){
_start:
{
uint8_t v_res_869_; lean_object* v_r_870_; 
v_res_869_ = l_List_all___at___00MergeSearchWorker_handle_spec__22(v_x_868_);
lean_dec(v_x_868_);
v_r_870_ = lean_box(v_res_869_);
return v_r_870_;
}
}
LEAN_EXPORT lean_object* l_MergeSearchWorker_handle(lean_object* v_j_900_){
_start:
{
lean_object* v___x_902_; lean_object* v___x_903_; lean_object* v___x_904_; 
v___x_902_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__0));
lean_inc(v_j_900_);
v___x_903_ = l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__0(v_j_900_, v___x_902_);
v___x_904_ = l_MergeSearchWorker_orError___redArg(v___x_903_);
if (lean_obj_tag(v___x_904_) == 0)
{
lean_object* v_a_905_; lean_object* v___x_907_; uint8_t v_isShared_908_; uint8_t v_isSharedCheck_1108_; 
v_a_905_ = lean_ctor_get(v___x_904_, 0);
v_isSharedCheck_1108_ = !lean_is_exclusive(v___x_904_);
if (v_isSharedCheck_1108_ == 0)
{
v___x_907_ = v___x_904_;
v_isShared_908_ = v_isSharedCheck_1108_;
goto v_resetjp_906_;
}
else
{
lean_inc(v_a_905_);
lean_dec(v___x_904_);
v___x_907_ = lean_box(0);
v_isShared_908_ = v_isSharedCheck_1108_;
goto v_resetjp_906_;
}
v_resetjp_906_:
{
lean_object* v___y_910_; uint8_t v___y_911_; lean_object* v___y_912_; lean_object* v___y_913_; lean_object* v___y_914_; lean_object* v___y_915_; lean_object* v___y_916_; lean_object* v___y_917_; lean_object* v_outputs_918_; lean_object* v___f_968_; lean_object* v___y_970_; uint8_t v___y_971_; lean_object* v___y_972_; lean_object* v___y_973_; lean_object* v___y_974_; lean_object* v___y_975_; lean_object* v___y_976_; lean_object* v___y_977_; lean_object* v___y_978_; lean_object* v___y_979_; lean_object* v___y_980_; lean_object* v___y_981_; uint8_t v___y_982_; lean_object* v___y_998_; uint8_t v___y_999_; uint8_t v___y_1000_; lean_object* v___y_1001_; lean_object* v___y_1002_; lean_object* v___y_1003_; lean_object* v___y_1004_; lean_object* v___y_1005_; lean_object* v___y_1006_; lean_object* v___y_1007_; lean_object* v___y_1008_; lean_object* v___y_1009_; uint8_t v___y_1010_; uint8_t v___y_1018_; uint8_t v___x_1104_; 
v___f_968_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__10));
v___x_1104_ = l_List_all___at___00MergeSearchWorker_handle_spec__22(v_a_905_);
if (v___x_1104_ == 0)
{
v___y_1018_ = v___x_1104_;
goto v___jp_1017_;
}
else
{
lean_object* v___x_1105_; lean_object* v___x_1106_; uint8_t v___x_1107_; 
v___x_1105_ = l_List_lengthTR___redArg(v_a_905_);
v___x_1106_ = lean_unsigned_to_nat(64u);
v___x_1107_ = lean_nat_dec_le(v___x_1105_, v___x_1106_);
lean_dec(v___x_1105_);
v___y_1018_ = v___x_1107_;
goto v___jp_1017_;
}
v___jp_909_:
{
lean_object* v___x_919_; lean_object* v___x_920_; lean_object* v___x_921_; lean_object* v___x_922_; lean_object* v___x_923_; lean_object* v___x_924_; lean_object* v___x_925_; lean_object* v___x_926_; lean_object* v___x_927_; lean_object* v___x_928_; lean_object* v___x_929_; lean_object* v___x_930_; lean_object* v___x_931_; lean_object* v___x_932_; lean_object* v___x_933_; lean_object* v___x_934_; lean_object* v___x_935_; lean_object* v___x_936_; lean_object* v___x_937_; lean_object* v___x_938_; lean_object* v___x_939_; lean_object* v___x_940_; lean_object* v___x_941_; lean_object* v___x_942_; lean_object* v___x_943_; lean_object* v___x_944_; lean_object* v___x_945_; lean_object* v___x_946_; lean_object* v___x_947_; lean_object* v___x_948_; lean_object* v___x_949_; lean_object* v___x_950_; lean_object* v___x_951_; lean_object* v___x_952_; lean_object* v___x_953_; lean_object* v___x_954_; lean_object* v___x_955_; lean_object* v___x_956_; lean_object* v___x_957_; lean_object* v___x_958_; lean_object* v___x_959_; lean_object* v___x_960_; lean_object* v___x_961_; lean_object* v___x_962_; lean_object* v___x_963_; lean_object* v___x_964_; lean_object* v___x_966_; 
v___x_919_ = lean_box(0);
lean_inc(v_a_905_);
v___x_920_ = l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__10(v_a_905_, v___x_919_);
v___x_921_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__1));
v___x_922_ = lean_alloc_ctor(1, 0, 1);
lean_ctor_set_uint8(v___x_922_, 0, v___y_911_);
v___x_923_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_923_, 0, v___x_921_);
lean_ctor_set(v___x_923_, 1, v___x_922_);
v___x_924_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__2));
v___x_925_ = l_List_lengthTR___redArg(v_a_905_);
lean_dec(v_a_905_);
v___x_926_ = l_LeanSort_MergeSearch_lookup(v___y_910_, v___y_917_, v___x_925_);
lean_dec(v___x_925_);
lean_dec(v___y_917_);
lean_dec_ref(v___y_910_);
v___x_927_ = l_Lean_JsonNumber_fromNat(v___x_926_);
v___x_928_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_928_, 0, v___x_927_);
v___x_929_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_929_, 0, v___x_924_);
lean_ctor_set(v___x_929_, 1, v___x_928_);
v___x_930_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__3));
v___x_931_ = l_Lean_List_toJson___at___00MergeSearchWorker_handle_spec__11(v___y_913_);
v___x_932_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_932_, 0, v___x_930_);
lean_ctor_set(v___x_932_, 1, v___x_931_);
v___x_933_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__4));
v___x_934_ = l_Lean_List_toJson___at___00MergeSearchWorker_handle_spec__12(v___y_916_);
v___x_935_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_935_, 0, v___x_933_);
lean_ctor_set(v___x_935_, 1, v___x_934_);
v___x_936_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__5));
v___x_937_ = l_Lean_List_toJson___at___00MergeSearchWorker_handle_spec__11(v___y_912_);
v___x_938_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_938_, 0, v___x_936_);
lean_ctor_set(v___x_938_, 1, v___x_937_);
v___x_939_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__6));
v___x_940_ = lean_nat_sub(v___y_914_, v___y_915_);
lean_dec(v___y_915_);
lean_dec(v___y_914_);
v___x_941_ = l_Lean_JsonNumber_fromNat(v___x_940_);
v___x_942_ = lean_alloc_ctor(2, 1, 0);
lean_ctor_set(v___x_942_, 0, v___x_941_);
v___x_943_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_943_, 0, v___x_939_);
lean_ctor_set(v___x_943_, 1, v___x_942_);
v___x_944_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__7));
v___x_945_ = l_Lean_List_toJson___at___00Lean_Option_toJson___at___00Lean_Server_instToJsonIlean_toJson_spec__1_spec__1(v_outputs_918_);
v___x_946_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_946_, 0, v___x_944_);
lean_ctor_set(v___x_946_, 1, v___x_945_);
v___x_947_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__8));
lean_inc(v___x_920_);
v___x_948_ = lp_leansort_LeanSort_RunAdaptive_countPlan___redArg(v___x_920_);
v___x_949_ = l_MergeSearchWorker_signature(v___x_948_);
v___x_950_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_950_, 0, v___x_947_);
lean_ctor_set(v___x_950_, 1, v___x_949_);
v___x_951_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__9));
v___x_952_ = lp_leansort_LeanSort_RunAdaptive_lengthPlan___redArg(v___x_920_);
v___x_953_ = l_MergeSearchWorker_signature(v___x_952_);
v___x_954_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_954_, 0, v___x_951_);
lean_ctor_set(v___x_954_, 1, v___x_953_);
v___x_955_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_955_, 0, v___x_954_);
lean_ctor_set(v___x_955_, 1, v___x_919_);
v___x_956_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_956_, 0, v___x_950_);
lean_ctor_set(v___x_956_, 1, v___x_955_);
v___x_957_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_957_, 0, v___x_946_);
lean_ctor_set(v___x_957_, 1, v___x_956_);
v___x_958_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_958_, 0, v___x_943_);
lean_ctor_set(v___x_958_, 1, v___x_957_);
v___x_959_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_959_, 0, v___x_938_);
lean_ctor_set(v___x_959_, 1, v___x_958_);
v___x_960_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_960_, 0, v___x_935_);
lean_ctor_set(v___x_960_, 1, v___x_959_);
v___x_961_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_961_, 0, v___x_932_);
lean_ctor_set(v___x_961_, 1, v___x_960_);
v___x_962_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_962_, 0, v___x_929_);
lean_ctor_set(v___x_962_, 1, v___x_961_);
v___x_963_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_963_, 0, v___x_923_);
lean_ctor_set(v___x_963_, 1, v___x_962_);
v___x_964_ = l_Lean_Json_mkObj(v___x_963_);
lean_dec_ref_known(v___x_963_, 2);
if (v_isShared_908_ == 0)
{
lean_ctor_set(v___x_907_, 0, v___x_964_);
v___x_966_ = v___x_907_;
goto v_reusejp_965_;
}
else
{
lean_object* v_reuseFailAlloc_967_; 
v_reuseFailAlloc_967_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_967_, 0, v___x_964_);
v___x_966_ = v_reuseFailAlloc_967_;
goto v_reusejp_965_;
}
v_reusejp_965_:
{
return v___x_966_;
}
}
v___jp_969_:
{
if (v___y_982_ == 0)
{
lean_object* v___x_983_; lean_object* v___x_984_; 
lean_dec(v___y_981_);
lean_dec(v___y_980_);
lean_dec(v___y_979_);
lean_dec_ref(v___y_978_);
lean_dec(v___y_977_);
lean_dec(v___y_976_);
lean_dec(v___y_975_);
lean_dec(v___y_974_);
lean_dec(v___y_973_);
lean_dec(v___y_972_);
lean_dec_ref(v___y_970_);
lean_del_object(v___x_907_);
lean_dec(v_a_905_);
v___x_983_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__12));
v___x_984_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_984_, 0, v___x_983_);
return v___x_984_;
}
else
{
lean_object* v___x_985_; lean_object* v___x_986_; lean_object* v___x_987_; 
lean_inc(v___y_980_);
v___x_985_ = l___private_Init_Data_List_Impl_0__List_flatMapTR_go___at___00MergeSearchWorker_handle_spec__13(v___y_980_, v___y_978_);
v___x_986_ = l_List_MergeSort_Internal_mergeSortTR_u2082___redArg(v___x_985_, v___f_968_);
v___x_987_ = l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg(v___y_980_, v___x_986_, v___y_972_, v___y_979_);
lean_dec(v___y_972_);
lean_dec(v___x_986_);
if (lean_obj_tag(v___x_987_) == 0)
{
lean_object* v_a_988_; 
v_a_988_ = lean_ctor_get(v___x_987_, 0);
lean_inc(v_a_988_);
lean_dec_ref_known(v___x_987_, 1);
v___y_910_ = v___y_970_;
v___y_911_ = v___y_971_;
v___y_912_ = v___y_973_;
v___y_913_ = v___y_977_;
v___y_914_ = v___y_974_;
v___y_915_ = v___y_981_;
v___y_916_ = v___y_975_;
v___y_917_ = v___y_976_;
v_outputs_918_ = v_a_988_;
goto v___jp_909_;
}
else
{
lean_object* v_a_989_; lean_object* v___x_991_; uint8_t v_isShared_992_; uint8_t v_isSharedCheck_996_; 
lean_dec(v___y_981_);
lean_dec(v___y_977_);
lean_dec(v___y_976_);
lean_dec(v___y_975_);
lean_dec(v___y_974_);
lean_dec(v___y_973_);
lean_dec_ref(v___y_970_);
lean_del_object(v___x_907_);
lean_dec(v_a_905_);
v_a_989_ = lean_ctor_get(v___x_987_, 0);
v_isSharedCheck_996_ = !lean_is_exclusive(v___x_987_);
if (v_isSharedCheck_996_ == 0)
{
v___x_991_ = v___x_987_;
v_isShared_992_ = v_isSharedCheck_996_;
goto v_resetjp_990_;
}
else
{
lean_inc(v_a_989_);
lean_dec(v___x_987_);
v___x_991_ = lean_box(0);
v_isShared_992_ = v_isSharedCheck_996_;
goto v_resetjp_990_;
}
v_resetjp_990_:
{
lean_object* v___x_994_; 
if (v_isShared_992_ == 0)
{
v___x_994_ = v___x_991_;
goto v_reusejp_993_;
}
else
{
lean_object* v_reuseFailAlloc_995_; 
v_reuseFailAlloc_995_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_995_, 0, v_a_989_);
v___x_994_ = v_reuseFailAlloc_995_;
goto v_reusejp_993_;
}
v_reusejp_993_:
{
return v___x_994_;
}
}
}
}
}
v___jp_997_:
{
if (v___y_1010_ == 0)
{
lean_object* v___x_1011_; lean_object* v___x_1012_; 
lean_dec(v___y_1009_);
lean_dec(v___y_1008_);
lean_dec_ref(v___y_1007_);
lean_dec(v___y_1006_);
lean_dec(v___y_1005_);
lean_dec(v___y_1004_);
lean_dec(v___y_1003_);
lean_dec(v___y_1002_);
lean_dec(v___y_1001_);
lean_dec_ref(v___y_998_);
lean_del_object(v___x_907_);
lean_dec(v_a_905_);
v___x_1011_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__14));
v___x_1012_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1012_, 0, v___x_1011_);
return v___x_1012_;
}
else
{
lean_object* v___x_1013_; 
v___x_1013_ = lean_box(0);
if (v___y_999_ == 0)
{
lean_dec(v___y_1008_);
lean_dec_ref(v___y_1007_);
lean_dec(v___y_1001_);
v___y_910_ = v___y_998_;
v___y_911_ = v___y_1000_;
v___y_912_ = v___y_1002_;
v___y_913_ = v___y_1006_;
v___y_914_ = v___y_1003_;
v___y_915_ = v___y_1009_;
v___y_916_ = v___y_1004_;
v___y_917_ = v___y_1005_;
v_outputs_918_ = v___x_1013_;
goto v___jp_909_;
}
else
{
lean_object* v___x_1014_; uint8_t v___x_1015_; 
lean_inc(v___y_1008_);
v___x_1014_ = l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__20(v___y_1008_, v___x_1013_);
v___x_1015_ = l_List_beq___at___00Lean_MacroScopesView_equalScope_spec__0(v___x_1014_, v_a_905_);
lean_dec(v___x_1014_);
if (v___x_1015_ == 0)
{
v___y_970_ = v___y_998_;
v___y_971_ = v___y_1000_;
v___y_972_ = v___y_1001_;
v___y_973_ = v___y_1002_;
v___y_974_ = v___y_1003_;
v___y_975_ = v___y_1004_;
v___y_976_ = v___y_1005_;
v___y_977_ = v___y_1006_;
v___y_978_ = v___y_1007_;
v___y_979_ = v___x_1013_;
v___y_980_ = v___y_1008_;
v___y_981_ = v___y_1009_;
v___y_982_ = v___x_1015_;
goto v___jp_969_;
}
else
{
uint8_t v___x_1016_; 
lean_inc(v___y_1008_);
v___x_1016_ = l_List_all___at___00MergeSearchWorker_handle_spec__21(v___y_1008_);
v___y_970_ = v___y_998_;
v___y_971_ = v___y_1000_;
v___y_972_ = v___y_1001_;
v___y_973_ = v___y_1002_;
v___y_974_ = v___y_1003_;
v___y_975_ = v___y_1004_;
v___y_976_ = v___y_1005_;
v___y_977_ = v___y_1006_;
v___y_978_ = v___y_1007_;
v___y_979_ = v___x_1013_;
v___y_980_ = v___y_1008_;
v___y_981_ = v___y_1009_;
v___y_982_ = v___x_1016_;
goto v___jp_969_;
}
}
}
}
v___jp_1017_:
{
if (v___y_1018_ == 0)
{
lean_object* v___x_1019_; lean_object* v___x_1020_; 
lean_del_object(v___x_907_);
lean_dec(v_a_905_);
lean_dec(v_j_900_);
v___x_1019_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__16));
v___x_1020_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v___x_1020_, 0, v___x_1019_);
return v___x_1020_;
}
else
{
lean_object* v___x_1021_; lean_object* v___x_1022_; lean_object* v___x_1023_; 
v___x_1021_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__17));
lean_inc(v_j_900_);
v___x_1022_ = l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__1(v_j_900_, v___x_1021_);
v___x_1023_ = l_MergeSearchWorker_orError___redArg(v___x_1022_);
if (lean_obj_tag(v___x_1023_) == 0)
{
lean_object* v_a_1024_; lean_object* v___x_1025_; lean_object* v___x_1026_; lean_object* v___x_1027_; 
v_a_1024_ = lean_ctor_get(v___x_1023_, 0);
lean_inc(v_a_1024_);
lean_dec_ref_known(v___x_1023_, 1);
v___x_1025_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__18));
lean_inc(v_j_900_);
v___x_1026_ = l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__2(v_j_900_, v___x_1025_);
v___x_1027_ = l_MergeSearchWorker_orError___redArg(v___x_1026_);
if (lean_obj_tag(v___x_1027_) == 0)
{
lean_object* v_a_1028_; lean_object* v___x_1029_; lean_object* v___x_1030_; lean_object* v___x_1031_; 
v_a_1028_ = lean_ctor_get(v___x_1027_, 0);
lean_inc(v_a_1028_);
lean_dec_ref_known(v___x_1027_, 1);
v___x_1029_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__19));
lean_inc(v_j_900_);
v___x_1030_ = l_Lean_Json_getObjValAs_x3f___at___00MergeSearchWorker_handle_spec__3(v_j_900_, v___x_1029_);
v___x_1031_ = l_MergeSearchWorker_orError___redArg(v___x_1030_);
if (lean_obj_tag(v___x_1031_) == 0)
{
lean_object* v_a_1032_; lean_object* v___x_1033_; lean_object* v___x_1034_; lean_object* v___x_1035_; 
v_a_1032_ = lean_ctor_get(v___x_1031_, 0);
lean_inc(v_a_1032_);
lean_dec_ref_known(v___x_1031_, 1);
v___x_1033_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__20));
v___x_1034_ = l_Lean_Json_getObjValAs_x3f___at___00Lean_Firefox_instFromJsonThread_fromJson_spec__0(v_j_900_, v___x_1033_);
v___x_1035_ = l_MergeSearchWorker_orError___redArg(v___x_1034_);
if (lean_obj_tag(v___x_1035_) == 0)
{
lean_object* v_a_1036_; lean_object* v___x_1038_; uint8_t v_isShared_1039_; uint8_t v_isSharedCheck_1071_; 
v_a_1036_ = lean_ctor_get(v___x_1035_, 0);
v_isSharedCheck_1071_ = !lean_is_exclusive(v___x_1035_);
if (v_isSharedCheck_1071_ == 0)
{
v___x_1038_ = v___x_1035_;
v_isShared_1039_ = v_isSharedCheck_1071_;
goto v_resetjp_1037_;
}
else
{
lean_inc(v_a_1036_);
lean_dec(v___x_1035_);
v___x_1038_ = lean_box(0);
v_isShared_1039_ = v_isSharedCheck_1071_;
goto v_resetjp_1037_;
}
v_resetjp_1037_:
{
lean_object* v___x_1040_; uint8_t v___x_1041_; 
v___x_1040_ = lean_io_mono_nanos_now();
lean_inc(v_a_1024_);
lean_inc(v_a_905_);
v___x_1041_ = l_LeanSort_MergeSearch_checkLower(v_a_905_, v_a_1024_);
if (v___x_1041_ == 0)
{
lean_object* v___x_1042_; lean_object* v___x_1044_; 
lean_dec(v___x_1040_);
lean_dec(v_a_1036_);
lean_dec(v_a_1032_);
lean_dec(v_a_1028_);
lean_dec(v_a_1024_);
lean_del_object(v___x_907_);
lean_dec(v_a_905_);
v___x_1042_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__22));
if (v_isShared_1039_ == 0)
{
lean_ctor_set_tag(v___x_1038_, 1);
lean_ctor_set(v___x_1038_, 0, v___x_1042_);
v___x_1044_ = v___x_1038_;
goto v_reusejp_1043_;
}
else
{
lean_object* v_reuseFailAlloc_1045_; 
v_reuseFailAlloc_1045_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1045_, 0, v___x_1042_);
v___x_1044_ = v_reuseFailAlloc_1045_;
goto v_reusejp_1043_;
}
v_reusejp_1043_:
{
return v___x_1044_;
}
}
else
{
lean_object* v___x_1046_; lean_object* v___x_1047_; lean_object* v___x_1048_; lean_object* v___x_1049_; lean_object* v___x_1050_; lean_object* v___x_1051_; lean_object* v___x_1052_; lean_object* v___x_1053_; lean_object* v___x_1054_; lean_object* v___x_1055_; lean_object* v___x_1056_; lean_object* v___x_1057_; lean_object* v___x_1058_; lean_object* v___x_1059_; lean_object* v___x_1060_; lean_object* v___x_1061_; lean_object* v___x_1062_; lean_object* v___x_1063_; lean_object* v___x_1064_; lean_object* v___x_1065_; uint8_t v___x_1066_; 
lean_del_object(v___x_1038_);
v___x_1046_ = lean_unsigned_to_nat(0u);
v___x_1047_ = lean_st_mk_ref(v___x_1046_);
v___x_1048_ = lean_box(0);
v___x_1049_ = l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__4(v_a_1028_, v___x_1048_);
lean_inc_n(v___x_1049_, 3);
v___x_1050_ = l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__5(v_a_905_, v___x_1049_, v___x_1048_);
lean_inc(v___x_1050_);
v___x_1051_ = l_List_filterTR_loop___at___00__private_Lean_Meta_MkIffOfInductiveProp_0__Lean_Meta_toInductive_spec__3(v___x_1050_, v___x_1048_);
v___x_1052_ = l_List_lengthTR___redArg(v___x_1051_);
lean_dec(v___x_1051_);
v___x_1053_ = lean_st_ref_set(v___x_1047_, v___x_1052_);
lean_inc_n(v_a_905_, 2);
v___x_1054_ = l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__6(v_a_905_, v___x_1049_, v___x_1048_);
v___x_1055_ = l_List_mapTR_loop___at___00MergeSearchWorker_handle_spec__7(v_a_905_, v_a_1024_, v___x_1049_, v___x_1048_);
v___x_1056_ = ((lean_object*)(l_MergeSearchWorker_handle___closed__23));
lean_inc(v___x_1054_);
v___x_1057_ = l_List_filterMapTR_go___at___00MergeSearchWorker_handle_spec__8(v___x_1054_, v___x_1056_);
v___x_1058_ = l_List_sum___at___00MergeSearchWorker_handle_spec__9(v___x_1057_);
lean_dec(v___x_1057_);
lean_inc(v___x_1055_);
v___x_1059_ = l_List_filterTR_loop___at___00__private_Lean_Meta_MkIffOfInductiveProp_0__Lean_Meta_toInductive_spec__3(v___x_1055_, v___x_1048_);
v___x_1060_ = l_List_lengthTR___redArg(v___x_1059_);
lean_dec(v___x_1059_);
v___x_1061_ = lean_nat_add(v___x_1058_, v___x_1060_);
lean_dec(v___x_1060_);
lean_dec(v___x_1058_);
v___x_1062_ = lean_st_ref_set(v___x_1047_, v___x_1061_);
lean_dec(v___x_1047_);
v___x_1063_ = lean_io_mono_nanos_now();
v___x_1064_ = l_List_lengthTR___redArg(v___x_1050_);
v___x_1065_ = l_List_lengthTR___redArg(v___x_1054_);
v___x_1066_ = lean_nat_dec_eq(v___x_1064_, v___x_1065_);
lean_dec(v___x_1064_);
if (v___x_1066_ == 0)
{
uint8_t v___x_1067_; 
lean_dec(v___x_1065_);
v___x_1067_ = lean_unbox(v_a_1036_);
lean_dec(v_a_1036_);
v___y_998_ = v_a_1024_;
v___y_999_ = v___x_1067_;
v___y_1000_ = v___x_1041_;
v___y_1001_ = v___x_1049_;
v___y_1002_ = v___x_1055_;
v___y_1003_ = v___x_1063_;
v___y_1004_ = v___x_1054_;
v___y_1005_ = v___x_1046_;
v___y_1006_ = v___x_1050_;
v___y_1007_ = v___x_1056_;
v___y_1008_ = v_a_1032_;
v___y_1009_ = v___x_1040_;
v___y_1010_ = v___x_1066_;
goto v___jp_997_;
}
else
{
lean_object* v___x_1068_; uint8_t v___x_1069_; uint8_t v___x_1070_; 
v___x_1068_ = l_List_lengthTR___redArg(v___x_1055_);
v___x_1069_ = lean_nat_dec_eq(v___x_1068_, v___x_1065_);
lean_dec(v___x_1065_);
lean_dec(v___x_1068_);
v___x_1070_ = lean_unbox(v_a_1036_);
lean_dec(v_a_1036_);
v___y_998_ = v_a_1024_;
v___y_999_ = v___x_1070_;
v___y_1000_ = v___x_1041_;
v___y_1001_ = v___x_1049_;
v___y_1002_ = v___x_1055_;
v___y_1003_ = v___x_1063_;
v___y_1004_ = v___x_1054_;
v___y_1005_ = v___x_1046_;
v___y_1006_ = v___x_1050_;
v___y_1007_ = v___x_1056_;
v___y_1008_ = v_a_1032_;
v___y_1009_ = v___x_1040_;
v___y_1010_ = v___x_1069_;
goto v___jp_997_;
}
}
}
}
else
{
lean_object* v_a_1072_; lean_object* v___x_1074_; uint8_t v_isShared_1075_; uint8_t v_isSharedCheck_1079_; 
lean_dec(v_a_1032_);
lean_dec(v_a_1028_);
lean_dec(v_a_1024_);
lean_del_object(v___x_907_);
lean_dec(v_a_905_);
v_a_1072_ = lean_ctor_get(v___x_1035_, 0);
v_isSharedCheck_1079_ = !lean_is_exclusive(v___x_1035_);
if (v_isSharedCheck_1079_ == 0)
{
v___x_1074_ = v___x_1035_;
v_isShared_1075_ = v_isSharedCheck_1079_;
goto v_resetjp_1073_;
}
else
{
lean_inc(v_a_1072_);
lean_dec(v___x_1035_);
v___x_1074_ = lean_box(0);
v_isShared_1075_ = v_isSharedCheck_1079_;
goto v_resetjp_1073_;
}
v_resetjp_1073_:
{
lean_object* v___x_1077_; 
if (v_isShared_1075_ == 0)
{
v___x_1077_ = v___x_1074_;
goto v_reusejp_1076_;
}
else
{
lean_object* v_reuseFailAlloc_1078_; 
v_reuseFailAlloc_1078_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1078_, 0, v_a_1072_);
v___x_1077_ = v_reuseFailAlloc_1078_;
goto v_reusejp_1076_;
}
v_reusejp_1076_:
{
return v___x_1077_;
}
}
}
}
else
{
lean_object* v_a_1080_; lean_object* v___x_1082_; uint8_t v_isShared_1083_; uint8_t v_isSharedCheck_1087_; 
lean_dec(v_a_1028_);
lean_dec(v_a_1024_);
lean_del_object(v___x_907_);
lean_dec(v_a_905_);
lean_dec(v_j_900_);
v_a_1080_ = lean_ctor_get(v___x_1031_, 0);
v_isSharedCheck_1087_ = !lean_is_exclusive(v___x_1031_);
if (v_isSharedCheck_1087_ == 0)
{
v___x_1082_ = v___x_1031_;
v_isShared_1083_ = v_isSharedCheck_1087_;
goto v_resetjp_1081_;
}
else
{
lean_inc(v_a_1080_);
lean_dec(v___x_1031_);
v___x_1082_ = lean_box(0);
v_isShared_1083_ = v_isSharedCheck_1087_;
goto v_resetjp_1081_;
}
v_resetjp_1081_:
{
lean_object* v___x_1085_; 
if (v_isShared_1083_ == 0)
{
v___x_1085_ = v___x_1082_;
goto v_reusejp_1084_;
}
else
{
lean_object* v_reuseFailAlloc_1086_; 
v_reuseFailAlloc_1086_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1086_, 0, v_a_1080_);
v___x_1085_ = v_reuseFailAlloc_1086_;
goto v_reusejp_1084_;
}
v_reusejp_1084_:
{
return v___x_1085_;
}
}
}
}
else
{
lean_object* v_a_1088_; lean_object* v___x_1090_; uint8_t v_isShared_1091_; uint8_t v_isSharedCheck_1095_; 
lean_dec(v_a_1024_);
lean_del_object(v___x_907_);
lean_dec(v_a_905_);
lean_dec(v_j_900_);
v_a_1088_ = lean_ctor_get(v___x_1027_, 0);
v_isSharedCheck_1095_ = !lean_is_exclusive(v___x_1027_);
if (v_isSharedCheck_1095_ == 0)
{
v___x_1090_ = v___x_1027_;
v_isShared_1091_ = v_isSharedCheck_1095_;
goto v_resetjp_1089_;
}
else
{
lean_inc(v_a_1088_);
lean_dec(v___x_1027_);
v___x_1090_ = lean_box(0);
v_isShared_1091_ = v_isSharedCheck_1095_;
goto v_resetjp_1089_;
}
v_resetjp_1089_:
{
lean_object* v___x_1093_; 
if (v_isShared_1091_ == 0)
{
v___x_1093_ = v___x_1090_;
goto v_reusejp_1092_;
}
else
{
lean_object* v_reuseFailAlloc_1094_; 
v_reuseFailAlloc_1094_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1094_, 0, v_a_1088_);
v___x_1093_ = v_reuseFailAlloc_1094_;
goto v_reusejp_1092_;
}
v_reusejp_1092_:
{
return v___x_1093_;
}
}
}
}
else
{
lean_object* v_a_1096_; lean_object* v___x_1098_; uint8_t v_isShared_1099_; uint8_t v_isSharedCheck_1103_; 
lean_del_object(v___x_907_);
lean_dec(v_a_905_);
lean_dec(v_j_900_);
v_a_1096_ = lean_ctor_get(v___x_1023_, 0);
v_isSharedCheck_1103_ = !lean_is_exclusive(v___x_1023_);
if (v_isSharedCheck_1103_ == 0)
{
v___x_1098_ = v___x_1023_;
v_isShared_1099_ = v_isSharedCheck_1103_;
goto v_resetjp_1097_;
}
else
{
lean_inc(v_a_1096_);
lean_dec(v___x_1023_);
v___x_1098_ = lean_box(0);
v_isShared_1099_ = v_isSharedCheck_1103_;
goto v_resetjp_1097_;
}
v_resetjp_1097_:
{
lean_object* v___x_1101_; 
if (v_isShared_1099_ == 0)
{
v___x_1101_ = v___x_1098_;
goto v_reusejp_1100_;
}
else
{
lean_object* v_reuseFailAlloc_1102_; 
v_reuseFailAlloc_1102_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1102_, 0, v_a_1096_);
v___x_1101_ = v_reuseFailAlloc_1102_;
goto v_reusejp_1100_;
}
v_reusejp_1100_:
{
return v___x_1101_;
}
}
}
}
}
}
}
else
{
lean_object* v_a_1109_; lean_object* v___x_1111_; uint8_t v_isShared_1112_; uint8_t v_isSharedCheck_1116_; 
lean_dec(v_j_900_);
v_a_1109_ = lean_ctor_get(v___x_904_, 0);
v_isSharedCheck_1116_ = !lean_is_exclusive(v___x_904_);
if (v_isSharedCheck_1116_ == 0)
{
v___x_1111_ = v___x_904_;
v_isShared_1112_ = v_isSharedCheck_1116_;
goto v_resetjp_1110_;
}
else
{
lean_inc(v_a_1109_);
lean_dec(v___x_904_);
v___x_1111_ = lean_box(0);
v_isShared_1112_ = v_isSharedCheck_1116_;
goto v_resetjp_1110_;
}
v_resetjp_1110_:
{
lean_object* v___x_1114_; 
if (v_isShared_1112_ == 0)
{
v___x_1114_ = v___x_1111_;
goto v_reusejp_1113_;
}
else
{
lean_object* v_reuseFailAlloc_1115_; 
v_reuseFailAlloc_1115_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1115_, 0, v_a_1109_);
v___x_1114_ = v_reuseFailAlloc_1115_;
goto v_reusejp_1113_;
}
v_reusejp_1113_:
{
return v___x_1114_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_MergeSearchWorker_handle___boxed(lean_object* v_j_1117_, lean_object* v_a_1118_){
_start:
{
lean_object* v_res_1119_; 
v_res_1119_ = l_MergeSearchWorker_handle(v_j_1117_);
return v_res_1119_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14(lean_object* v_t_1120_){
_start:
{
lean_object* v___x_1121_; 
v___x_1121_ = l_LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19(v_t_1120_);
return v___x_1121_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Comparison_Program_eval___at___00MergeSearchWorker_handle_spec__15(lean_object* v_00_u03b2_1122_, lean_object* v_x_1123_){
_start:
{
lean_object* v___x_1124_; 
v___x_1124_ = l_LeanSort_Comparison_Program_eval___at___00MergeSearchWorker_handle_spec__15___redArg(v_x_1123_);
return v___x_1124_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16(lean_object* v_val_1125_, lean_object* v_val_1126_, lean_object* v___x_1127_, lean_object* v_as_1128_, lean_object* v_as_x27_1129_, lean_object* v_b_1130_, lean_object* v_a_1131_){
_start:
{
lean_object* v___x_1133_; 
v___x_1133_ = l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___redArg(v_val_1125_, v_val_1126_, v___x_1127_, v_as_x27_1129_, v_b_1130_);
return v___x_1133_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16___boxed(lean_object* v_val_1134_, lean_object* v_val_1135_, lean_object* v___x_1136_, lean_object* v_as_1137_, lean_object* v_as_x27_1138_, lean_object* v_b_1139_, lean_object* v_a_1140_, lean_object* v___y_1141_){
_start:
{
lean_object* v_res_1142_; 
v_res_1142_ = l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__16(v_val_1134_, v_val_1135_, v___x_1136_, v_as_1137_, v_as_x27_1138_, v_b_1139_, v_a_1140_);
lean_dec(v_as_x27_1138_);
lean_dec(v_as_1137_);
lean_dec(v___x_1136_);
lean_dec(v_val_1135_);
lean_dec(v_val_1134_);
return v_res_1142_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19(lean_object* v_a_1143_, lean_object* v___x_1144_, lean_object* v_as_1145_, lean_object* v_as_x27_1146_, lean_object* v_b_1147_, lean_object* v_a_1148_){
_start:
{
lean_object* v___x_1150_; 
v___x_1150_ = l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___redArg(v_a_1143_, v___x_1144_, v_as_x27_1146_, v_b_1147_);
return v___x_1150_;
}
}
LEAN_EXPORT lean_object* l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19___boxed(lean_object* v_a_1151_, lean_object* v___x_1152_, lean_object* v_as_1153_, lean_object* v_as_x27_1154_, lean_object* v_b_1155_, lean_object* v_a_1156_, lean_object* v___y_1157_){
_start:
{
lean_object* v_res_1158_; 
v_res_1158_ = l_List_forIn_x27_loop___at___00MergeSearchWorker_handle_spec__19(v_a_1151_, v___x_1152_, v_as_1153_, v_as_x27_1154_, v_b_1155_, v_a_1156_);
lean_dec(v_as_x27_1154_);
lean_dec(v_as_1153_);
lean_dec(v___x_1152_);
return v_res_1158_;
}
}
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__23(lean_object* v_00_u03b1_1159_, lean_object* v_a_1160_){
_start:
{
lean_object* v___x_1161_; 
v___x_1161_ = l_Cslib_Algorithms_Lean_TimeM_pure___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__23___redArg(v_a_1160_);
return v___x_1161_;
}
}
LEAN_EXPORT lean_object* l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__25(lean_object* v_00_u03b1_1162_, lean_object* v_00_u03b2_1163_, lean_object* v_m_1164_, lean_object* v_f_1165_){
_start:
{
lean_object* v___x_1166_; 
v___x_1166_ = l_Cslib_Algorithms_Lean_TimeM_bind___at___00LeanSort_Direct_Engine_tree___at___00LeanSort_Direct_treeCounted___at___00MergeSearchWorker_handle_spec__14_spec__19_spec__25___redArg(v_m_1164_, v_f_1165_);
return v___x_1166_;
}
}
LEAN_EXPORT lean_object* l_MergeSearchWorker_loop(){
_start:
{
lean_object* v_a_1170_; lean_object* v___y_1178_; lean_object* v___x_1194_; lean_object* v_getLine_1195_; lean_object* v___x_1196_; 
v___x_1194_ = lean_get_stdin();
v_getLine_1195_ = lean_ctor_get(v___x_1194_, 3);
lean_inc_ref(v_getLine_1195_);
lean_dec_ref(v___x_1194_);
v___x_1196_ = lean_apply_1(v_getLine_1195_, lean_box(0));
if (lean_obj_tag(v___x_1196_) == 0)
{
lean_object* v_a_1197_; lean_object* v___x_1199_; uint8_t v_isShared_1200_; uint8_t v_isSharedCheck_1212_; 
v_a_1197_ = lean_ctor_get(v___x_1196_, 0);
v_isSharedCheck_1212_ = !lean_is_exclusive(v___x_1196_);
if (v_isSharedCheck_1212_ == 0)
{
v___x_1199_ = v___x_1196_;
v_isShared_1200_ = v_isSharedCheck_1212_;
goto v_resetjp_1198_;
}
else
{
lean_inc(v_a_1197_);
lean_dec(v___x_1196_);
v___x_1199_ = lean_box(0);
v_isShared_1200_ = v_isSharedCheck_1212_;
goto v_resetjp_1198_;
}
v_resetjp_1198_:
{
lean_object* v___x_1201_; lean_object* v___x_1202_; uint8_t v___x_1203_; 
v___x_1201_ = lean_string_utf8_byte_size(v_a_1197_);
v___x_1202_ = lean_unsigned_to_nat(0u);
v___x_1203_ = lean_nat_dec_eq(v___x_1201_, v___x_1202_);
if (v___x_1203_ == 0)
{
lean_object* v___x_1204_; lean_object* v___x_1205_; 
lean_del_object(v___x_1199_);
v___x_1204_ = l_Lean_Json_parse(v_a_1197_);
v___x_1205_ = l_MergeSearchWorker_orError___redArg(v___x_1204_);
if (lean_obj_tag(v___x_1205_) == 0)
{
lean_object* v_a_1206_; lean_object* v___x_1207_; 
v_a_1206_ = lean_ctor_get(v___x_1205_, 0);
lean_inc(v_a_1206_);
lean_dec_ref_known(v___x_1205_, 1);
v___x_1207_ = l_MergeSearchWorker_handle(v_a_1206_);
v___y_1178_ = v___x_1207_;
goto v___jp_1177_;
}
else
{
v___y_1178_ = v___x_1205_;
goto v___jp_1177_;
}
}
else
{
lean_object* v___x_1208_; lean_object* v___x_1210_; 
lean_dec(v_a_1197_);
v___x_1208_ = lean_box(0);
if (v_isShared_1200_ == 0)
{
lean_ctor_set(v___x_1199_, 0, v___x_1208_);
v___x_1210_ = v___x_1199_;
goto v_reusejp_1209_;
}
else
{
lean_object* v_reuseFailAlloc_1211_; 
v_reuseFailAlloc_1211_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1211_, 0, v___x_1208_);
v___x_1210_ = v_reuseFailAlloc_1211_;
goto v_reusejp_1209_;
}
v_reusejp_1209_:
{
return v___x_1210_;
}
}
}
}
else
{
lean_object* v_a_1213_; lean_object* v___x_1215_; uint8_t v_isShared_1216_; uint8_t v_isSharedCheck_1220_; 
v_a_1213_ = lean_ctor_get(v___x_1196_, 0);
v_isSharedCheck_1220_ = !lean_is_exclusive(v___x_1196_);
if (v_isSharedCheck_1220_ == 0)
{
v___x_1215_ = v___x_1196_;
v_isShared_1216_ = v_isSharedCheck_1220_;
goto v_resetjp_1214_;
}
else
{
lean_inc(v_a_1213_);
lean_dec(v___x_1196_);
v___x_1215_ = lean_box(0);
v_isShared_1216_ = v_isSharedCheck_1220_;
goto v_resetjp_1214_;
}
v_resetjp_1214_:
{
lean_object* v___x_1218_; 
if (v_isShared_1216_ == 0)
{
v___x_1218_ = v___x_1215_;
goto v_reusejp_1217_;
}
else
{
lean_object* v_reuseFailAlloc_1219_; 
v_reuseFailAlloc_1219_ = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1219_, 0, v_a_1213_);
v___x_1218_ = v_reuseFailAlloc_1219_;
goto v_reusejp_1217_;
}
v_reusejp_1217_:
{
return v___x_1218_;
}
}
}
v___jp_1169_:
{
lean_object* v___x_1171_; lean_object* v___x_1172_; lean_object* v___x_1173_; 
v___x_1171_ = lean_get_stdout();
v___x_1172_ = l_Lean_Json_compress(v_a_1170_);
lean_inc_ref(v___x_1171_);
v___x_1173_ = l_IO_FS_Stream_putStrLn(v___x_1171_, v___x_1172_);
if (lean_obj_tag(v___x_1173_) == 0)
{
lean_object* v_flush_1174_; lean_object* v___x_1175_; 
lean_dec_ref_known(v___x_1173_, 1);
v_flush_1174_ = lean_ctor_get(v___x_1171_, 0);
lean_inc_ref(v_flush_1174_);
lean_dec_ref(v___x_1171_);
v___x_1175_ = lean_apply_1(v_flush_1174_, lean_box(0));
if (lean_obj_tag(v___x_1175_) == 0)
{
lean_dec_ref_known(v___x_1175_, 1);
goto _start;
}
else
{
return v___x_1175_;
}
}
else
{
lean_dec_ref(v___x_1171_);
return v___x_1173_;
}
}
v___jp_1177_:
{
if (lean_obj_tag(v___y_1178_) == 0)
{
lean_object* v_a_1179_; 
v_a_1179_ = lean_ctor_get(v___y_1178_, 0);
lean_inc(v_a_1179_);
lean_dec_ref_known(v___y_1178_, 1);
v_a_1170_ = v_a_1179_;
goto v___jp_1169_;
}
else
{
lean_object* v_a_1180_; lean_object* v___x_1182_; uint8_t v_isShared_1183_; uint8_t v_isSharedCheck_1193_; 
v_a_1180_ = lean_ctor_get(v___y_1178_, 0);
v_isSharedCheck_1193_ = !lean_is_exclusive(v___y_1178_);
if (v_isSharedCheck_1193_ == 0)
{
v___x_1182_ = v___y_1178_;
v_isShared_1183_ = v_isSharedCheck_1193_;
goto v_resetjp_1181_;
}
else
{
lean_inc(v_a_1180_);
lean_dec(v___y_1178_);
v___x_1182_ = lean_box(0);
v_isShared_1183_ = v_isSharedCheck_1193_;
goto v_resetjp_1181_;
}
v_resetjp_1181_:
{
lean_object* v___x_1184_; lean_object* v___x_1185_; lean_object* v___x_1187_; 
v___x_1184_ = ((lean_object*)(l_MergeSearchWorker_loop___closed__0));
v___x_1185_ = lean_io_error_to_string(v_a_1180_);
if (v_isShared_1183_ == 0)
{
lean_ctor_set_tag(v___x_1182_, 3);
lean_ctor_set(v___x_1182_, 0, v___x_1185_);
v___x_1187_ = v___x_1182_;
goto v_reusejp_1186_;
}
else
{
lean_object* v_reuseFailAlloc_1192_; 
v_reuseFailAlloc_1192_ = lean_alloc_ctor(3, 1, 0);
lean_ctor_set(v_reuseFailAlloc_1192_, 0, v___x_1185_);
v___x_1187_ = v_reuseFailAlloc_1192_;
goto v_reusejp_1186_;
}
v_reusejp_1186_:
{
lean_object* v___x_1188_; lean_object* v___x_1189_; lean_object* v___x_1190_; lean_object* v___x_1191_; 
v___x_1188_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_1188_, 0, v___x_1184_);
lean_ctor_set(v___x_1188_, 1, v___x_1187_);
v___x_1189_ = lean_box(0);
v___x_1190_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_1190_, 0, v___x_1188_);
lean_ctor_set(v___x_1190_, 1, v___x_1189_);
v___x_1191_ = l_Lean_Json_mkObj(v___x_1190_);
lean_dec_ref_known(v___x_1190_, 2);
v_a_1170_ = v___x_1191_;
goto v___jp_1169_;
}
}
}
}
}
}
LEAN_EXPORT lean_object* l_MergeSearchWorker_loop___boxed(lean_object* v_a_1221_){
_start:
{
lean_object* v_res_1222_; 
v_res_1222_ = l_MergeSearchWorker_loop();
return v_res_1222_;
}
}
LEAN_EXPORT lean_object* _lean_main(){
_start:
{
lean_object* v___x_1224_; 
v___x_1224_ = l_MergeSearchWorker_loop();
return v___x_1224_;
}
}
LEAN_EXPORT lean_object* l_main___boxed(lean_object* v_a_1225_){
_start:
{
lean_object* v_res_1226_; 
v_res_1226_ = _lean_main();
return v_res_1226_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_LeanSort_Verification_MergeSearch_Checks(uint8_t builtin);
lean_object* initialize_Lean(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_experiments_learned_x2dmerge_x2dsearch_Worker(uint8_t builtin) {
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
res = initialize_LeanSort_Verification_MergeSearch_Checks(builtin);
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
  res = initialize_experiments_learned_x2dmerge_x2dsearch_Worker(1 /* builtin */);
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
