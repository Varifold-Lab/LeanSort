// Lean compiler output
// Module: LeanSort.Algorithm.Direct.Engine
// Imports: public import Init public meta import Init public import LeanSort.Algorithm.RunStrategy
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
lean_object* l_List_lengthTR___redArg(lean_object*);
uint8_t lean_nat_dec_lt(lean_object*, lean_object*);
lean_object* lean_nat_shiftr(lean_object*, lean_object*);
lean_object* l_List_drop___redArg(lean_object*, lean_object*);
lean_object* lean_mk_empty_array_with_capacity(lean_object*);
lean_object* l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_CostedPlan_Cut_position(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_RunAdaptive_countPlan(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_RunAdaptive_lengthPlan(lean_object*, lean_object*);
lean_object* l_Function_comp(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_Comparison_Program_bind___redArg(lean_object*, lean_object*);
lean_object* lp_leansort_LeanSort_Comparison_Program_bind(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Function_const___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__0(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__3(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__4(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__5(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__6(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__7(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__7___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__8(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__9(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__10(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__10___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__11(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_closure_object l_LeanSort_Direct_programMonad___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_LeanSort_Direct_programMonad___lam__0, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_programMonad___closed__0 = (const lean_object*)&l_LeanSort_Direct_programMonad___closed__0_value;
static const lean_closure_object l_LeanSort_Direct_programMonad___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_LeanSort_Direct_programMonad___lam__1, .m_arity = 5, .m_num_fixed = 1, .m_objs = {((lean_object*)&l_LeanSort_Direct_programMonad___closed__0_value)} };
static const lean_object* l_LeanSort_Direct_programMonad___closed__1 = (const lean_object*)&l_LeanSort_Direct_programMonad___closed__1_value;
static const lean_closure_object l_LeanSort_Direct_programMonad___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_LeanSort_Direct_programMonad___lam__3, .m_arity = 5, .m_num_fixed = 1, .m_objs = {((lean_object*)&l_LeanSort_Direct_programMonad___closed__0_value)} };
static const lean_object* l_LeanSort_Direct_programMonad___closed__2 = (const lean_object*)&l_LeanSort_Direct_programMonad___closed__2_value;
static const lean_closure_object l_LeanSort_Direct_programMonad___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_LeanSort_Direct_programMonad___lam__2, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_programMonad___closed__3 = (const lean_object*)&l_LeanSort_Direct_programMonad___closed__3_value;
static const lean_closure_object l_LeanSort_Direct_programMonad___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_LeanSort_Direct_programMonad___lam__4, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_programMonad___closed__4 = (const lean_object*)&l_LeanSort_Direct_programMonad___closed__4_value;
static const lean_closure_object l_LeanSort_Direct_programMonad___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_LeanSort_Direct_programMonad___lam__6, .m_arity = 5, .m_num_fixed = 1, .m_objs = {((lean_object*)&l_LeanSort_Direct_programMonad___closed__4_value)} };
static const lean_object* l_LeanSort_Direct_programMonad___closed__5 = (const lean_object*)&l_LeanSort_Direct_programMonad___closed__5_value;
static const lean_closure_object l_LeanSort_Direct_programMonad___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_LeanSort_Direct_programMonad___lam__9, .m_arity = 4, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_programMonad___closed__6 = (const lean_object*)&l_LeanSort_Direct_programMonad___closed__6_value;
static const lean_closure_object l_LeanSort_Direct_programMonad___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_LeanSort_Direct_programMonad___lam__11, .m_arity = 4, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_programMonad___closed__7 = (const lean_object*)&l_LeanSort_Direct_programMonad___closed__7_value;
static const lean_ctor_object l_LeanSort_Direct_programMonad___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_LeanSort_Direct_programMonad___closed__1_value),((lean_object*)&l_LeanSort_Direct_programMonad___closed__2_value)}};
static const lean_object* l_LeanSort_Direct_programMonad___closed__8 = (const lean_object*)&l_LeanSort_Direct_programMonad___closed__8_value;
static const lean_ctor_object l_LeanSort_Direct_programMonad___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*5 + 0, .m_other = 5, .m_tag = 0}, .m_objs = {((lean_object*)&l_LeanSort_Direct_programMonad___closed__8_value),((lean_object*)&l_LeanSort_Direct_programMonad___closed__3_value),((lean_object*)&l_LeanSort_Direct_programMonad___closed__5_value),((lean_object*)&l_LeanSort_Direct_programMonad___closed__6_value),((lean_object*)&l_LeanSort_Direct_programMonad___closed__7_value)}};
static const lean_object* l_LeanSort_Direct_programMonad___closed__9 = (const lean_object*)&l_LeanSort_Direct_programMonad___closed__9_value;
static const lean_closure_object l_LeanSort_Direct_programMonad___closed__10_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_leansort_LeanSort_Comparison_Program_bind, .m_arity = 5, .m_num_fixed = 1, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))} };
static const lean_object* l_LeanSort_Direct_programMonad___closed__10 = (const lean_object*)&l_LeanSort_Direct_programMonad___closed__10_value;
static const lean_ctor_object l_LeanSort_Direct_programMonad___closed__11_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_LeanSort_Direct_programMonad___closed__9_value),((lean_object*)&l_LeanSort_Direct_programMonad___closed__10_value)}};
static const lean_object* l_LeanSort_Direct_programMonad___closed__11 = (const lean_object*)&l_LeanSort_Direct_programMonad___closed__11_value;
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad(lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_symbolicCompare___redArg___lam__0(uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_symbolicCompare___redArg___lam__0___boxed(lean_object*);
static const lean_closure_object l_LeanSort_Direct_symbolicCompare___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_LeanSort_Direct_symbolicCompare___redArg___lam__0___boxed, .m_arity = 1, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_symbolicCompare___redArg___closed__0 = (const lean_object*)&l_LeanSort_Direct_symbolicCompare___redArg___closed__0_value;
LEAN_EXPORT lean_object* l_LeanSort_Direct_symbolicCompare___redArg(uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_symbolicCompare___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_symbolicCompare(lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_symbolicCompare___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_countedCompare___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_countedCompare(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_countedCompare___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_LeanSort_Direct_plainCompare___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_plainCompare___redArg___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t l_LeanSort_Direct_plainCompare(lean_object*, lean_object*, uint8_t, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_plainCompare___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___redArg___lam__0(uint8_t, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___redArg___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___redArg___lam__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___redArg___lam__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___redArg___lam__0(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___redArg___lam__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___redArg___lam__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_LeanSort_Algorithm_Direct_Engine_0__LeanSort_Direct_Engine_merge_match__1_splitter___redArg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l___private_LeanSort_Algorithm_Direct_Engine_0__LeanSort_Direct_Engine_merge_match__1_splitter(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___redArg___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___redArg___lam__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___redArg___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_array_object l_LeanSort_Direct_Engine_mergeSort___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_array_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 246}, .m_size = 0, .m_capacity = 0, .m_data = {}};
static const lean_object* l_LeanSort_Direct_Engine_mergeSort___redArg___closed__0 = (const lean_object*)&l_LeanSort_Direct_Engine_mergeSort___redArg___closed__0_value;
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___redArg___lam__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___redArg___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___redArg___lam__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___redArg___lam__0___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___redArg___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___redArg___lam__2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, uint8_t);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___redArg___lam__2___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___redArg___lam__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___redArg___lam__1(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___redArg___lam__0(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_closure_object l_LeanSort_Direct_Engine_strategy___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_leansort_LeanSort_RunAdaptive_countPlan, .m_arity = 2, .m_num_fixed = 1, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))} };
static const lean_object* l_LeanSort_Direct_Engine_strategy___redArg___closed__0 = (const lean_object*)&l_LeanSort_Direct_Engine_strategy___redArg___closed__0_value;
static const lean_closure_object l_LeanSort_Direct_Engine_strategy___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*1, .m_other = 0, .m_tag = 245}, .m_fun = (void*)lp_leansort_LeanSort_RunAdaptive_lengthPlan, .m_arity = 2, .m_num_fixed = 1, .m_objs = {((lean_object*)(((size_t)(0) << 1) | 1))} };
static const lean_object* l_LeanSort_Direct_Engine_strategy___redArg___closed__1 = (const lean_object*)&l_LeanSort_Direct_Engine_strategy___redArg___closed__1_value;
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__0(lean_object* v_value_1_){
_start:
{
lean_object* v___x_2_; 
v___x_2_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_2_, 0, v_value_1_);
return v___x_2_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__1(lean_object* v___f_3_, lean_object* v_00_u03b1_4_, lean_object* v_00_u03b2_5_, lean_object* v_f_6_, lean_object* v_x_7_){
_start:
{
lean_object* v___x_8_; lean_object* v___x_9_; 
v___x_8_ = lean_alloc_closure((void*)(l_Function_comp), 6, 5);
lean_closure_set(v___x_8_, 0, lean_box(0));
lean_closure_set(v___x_8_, 1, lean_box(0));
lean_closure_set(v___x_8_, 2, lean_box(0));
lean_closure_set(v___x_8_, 3, v___f_3_);
lean_closure_set(v___x_8_, 4, v_f_6_);
v___x_9_ = lp_leansort_LeanSort_Comparison_Program_bind___redArg(v_x_7_, v___x_8_);
return v___x_9_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__3(lean_object* v___f_10_, lean_object* v_00_u03b1_11_, lean_object* v_00_u03b2_12_, lean_object* v___y_13_, lean_object* v___y_14_){
_start:
{
lean_object* v___x_15_; lean_object* v___x_16_; lean_object* v___x_17_; 
v___x_15_ = lean_alloc_closure((void*)(l_Function_const___boxed), 4, 3);
lean_closure_set(v___x_15_, 0, lean_box(0));
lean_closure_set(v___x_15_, 1, lean_box(0));
lean_closure_set(v___x_15_, 2, v___y_13_);
v___x_16_ = lean_alloc_closure((void*)(l_Function_comp), 6, 5);
lean_closure_set(v___x_16_, 0, lean_box(0));
lean_closure_set(v___x_16_, 1, lean_box(0));
lean_closure_set(v___x_16_, 2, lean_box(0));
lean_closure_set(v___x_16_, 3, v___f_10_);
lean_closure_set(v___x_16_, 4, v___x_15_);
v___x_17_ = lp_leansort_LeanSort_Comparison_Program_bind___redArg(v___y_14_, v___x_16_);
return v___x_17_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__2(lean_object* v_00_u03b1_18_, lean_object* v___y_19_){
_start:
{
lean_object* v___x_20_; 
v___x_20_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_20_, 0, v___y_19_);
return v___x_20_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__4(lean_object* v___y_21_){
_start:
{
lean_object* v___x_22_; 
v___x_22_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_22_, 0, v___y_21_);
return v___x_22_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__5(lean_object* v_x_23_, lean_object* v___f_24_, lean_object* v_y_25_){
_start:
{
lean_object* v___x_26_; lean_object* v___x_27_; lean_object* v___x_28_; lean_object* v___x_29_; 
v___x_26_ = lean_box(0);
v___x_27_ = lean_apply_1(v_x_23_, v___x_26_);
v___x_28_ = lean_alloc_closure((void*)(l_Function_comp), 6, 5);
lean_closure_set(v___x_28_, 0, lean_box(0));
lean_closure_set(v___x_28_, 1, lean_box(0));
lean_closure_set(v___x_28_, 2, lean_box(0));
lean_closure_set(v___x_28_, 3, v___f_24_);
lean_closure_set(v___x_28_, 4, v_y_25_);
v___x_29_ = lp_leansort_LeanSort_Comparison_Program_bind___redArg(v___x_27_, v___x_28_);
return v___x_29_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__6(lean_object* v___f_30_, lean_object* v_00_u03b1_31_, lean_object* v_00_u03b2_32_, lean_object* v_f_33_, lean_object* v_x_34_){
_start:
{
lean_object* v___f_35_; lean_object* v___x_36_; 
v___f_35_ = lean_alloc_closure((void*)(l_LeanSort_Direct_programMonad___lam__5), 3, 2);
lean_closure_set(v___f_35_, 0, v_x_34_);
lean_closure_set(v___f_35_, 1, v___f_30_);
v___x_36_ = lp_leansort_LeanSort_Comparison_Program_bind___redArg(v_f_33_, v___f_35_);
return v___x_36_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__7(lean_object* v_a_37_, lean_object* v_x_38_){
_start:
{
lean_object* v___x_39_; 
v___x_39_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_39_, 0, v_a_37_);
return v___x_39_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__7___boxed(lean_object* v_a_40_, lean_object* v_x_41_){
_start:
{
lean_object* v_res_42_; 
v_res_42_ = l_LeanSort_Direct_programMonad___lam__7(v_a_40_, v_x_41_);
lean_dec(v_x_41_);
return v_res_42_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__8(lean_object* v_y_43_, lean_object* v_a_44_){
_start:
{
lean_object* v___f_45_; lean_object* v___x_46_; lean_object* v___x_47_; lean_object* v___x_48_; 
v___f_45_ = lean_alloc_closure((void*)(l_LeanSort_Direct_programMonad___lam__7___boxed), 2, 1);
lean_closure_set(v___f_45_, 0, v_a_44_);
v___x_46_ = lean_box(0);
v___x_47_ = lean_apply_1(v_y_43_, v___x_46_);
v___x_48_ = lp_leansort_LeanSort_Comparison_Program_bind___redArg(v___x_47_, v___f_45_);
return v___x_48_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__9(lean_object* v_00_u03b1_49_, lean_object* v_00_u03b2_50_, lean_object* v_x_51_, lean_object* v_y_52_){
_start:
{
lean_object* v___f_53_; lean_object* v___x_54_; 
v___f_53_ = lean_alloc_closure((void*)(l_LeanSort_Direct_programMonad___lam__8), 2, 1);
lean_closure_set(v___f_53_, 0, v_y_52_);
v___x_54_ = lp_leansort_LeanSort_Comparison_Program_bind___redArg(v_x_51_, v___f_53_);
return v___x_54_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__10(lean_object* v_y_55_, lean_object* v_x_56_){
_start:
{
lean_object* v___x_57_; lean_object* v___x_58_; 
v___x_57_ = lean_box(0);
v___x_58_ = lean_apply_1(v_y_55_, v___x_57_);
return v___x_58_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__10___boxed(lean_object* v_y_59_, lean_object* v_x_60_){
_start:
{
lean_object* v_res_61_; 
v_res_61_ = l_LeanSort_Direct_programMonad___lam__10(v_y_59_, v_x_60_);
lean_dec(v_x_60_);
return v_res_61_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad___lam__11(lean_object* v_00_u03b1_62_, lean_object* v_00_u03b2_63_, lean_object* v_x_64_, lean_object* v_y_65_){
_start:
{
lean_object* v___f_66_; lean_object* v___x_67_; 
v___f_66_ = lean_alloc_closure((void*)(l_LeanSort_Direct_programMonad___lam__10___boxed), 2, 1);
lean_closure_set(v___f_66_, 0, v_y_65_);
v___x_67_ = lp_leansort_LeanSort_Comparison_Program_bind___redArg(v_x_64_, v___f_66_);
return v___x_67_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_programMonad(lean_object* v_00_u03b1_92_){
_start:
{
lean_object* v___x_93_; 
v___x_93_ = ((lean_object*)(l_LeanSort_Direct_programMonad___closed__11));
return v___x_93_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_symbolicCompare___redArg___lam__0(uint8_t v_value_94_){
_start:
{
lean_object* v___x_95_; lean_object* v___x_96_; 
v___x_95_ = lean_box(v_value_94_);
v___x_96_ = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(v___x_96_, 0, v___x_95_);
return v___x_96_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_symbolicCompare___redArg___lam__0___boxed(lean_object* v_value_97_){
_start:
{
uint8_t v_value_boxed_98_; lean_object* v_res_99_; 
v_value_boxed_98_ = lean_unbox(v_value_97_);
v_res_99_ = l_LeanSort_Direct_symbolicCompare___redArg___lam__0(v_value_boxed_98_);
return v_res_99_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_symbolicCompare___redArg(uint8_t v_phase_101_, lean_object* v_x_102_, lean_object* v_y_103_){
_start:
{
lean_object* v___f_104_; lean_object* v___x_105_; 
v___f_104_ = ((lean_object*)(l_LeanSort_Direct_symbolicCompare___redArg___closed__0));
v___x_105_ = lean_alloc_ctor(1, 3, 1);
lean_ctor_set(v___x_105_, 0, v_x_102_);
lean_ctor_set(v___x_105_, 1, v_y_103_);
lean_ctor_set(v___x_105_, 2, v___f_104_);
lean_ctor_set_uint8(v___x_105_, sizeof(void*)*3, v_phase_101_);
return v___x_105_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_symbolicCompare___redArg___boxed(lean_object* v_phase_106_, lean_object* v_x_107_, lean_object* v_y_108_){
_start:
{
uint8_t v_phase_boxed_109_; lean_object* v_res_110_; 
v_phase_boxed_109_ = lean_unbox(v_phase_106_);
v_res_110_ = l_LeanSort_Direct_symbolicCompare___redArg(v_phase_boxed_109_, v_x_107_, v_y_108_);
return v_res_110_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_symbolicCompare(lean_object* v_00_u03b1_111_, uint8_t v_phase_112_, lean_object* v_x_113_, lean_object* v_y_114_){
_start:
{
lean_object* v___f_115_; lean_object* v___x_116_; 
v___f_115_ = ((lean_object*)(l_LeanSort_Direct_symbolicCompare___redArg___closed__0));
v___x_116_ = lean_alloc_ctor(1, 3, 1);
lean_ctor_set(v___x_116_, 0, v_x_113_);
lean_ctor_set(v___x_116_, 1, v_y_114_);
lean_ctor_set(v___x_116_, 2, v___f_115_);
lean_ctor_set_uint8(v___x_116_, sizeof(void*)*3, v_phase_112_);
return v___x_116_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_symbolicCompare___boxed(lean_object* v_00_u03b1_117_, lean_object* v_phase_118_, lean_object* v_x_119_, lean_object* v_y_120_){
_start:
{
uint8_t v_phase_boxed_121_; lean_object* v_res_122_; 
v_phase_boxed_121_ = lean_unbox(v_phase_118_);
v_res_122_ = l_LeanSort_Direct_symbolicCompare(v_00_u03b1_117_, v_phase_boxed_121_, v_x_119_, v_y_120_);
return v_res_122_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_countedCompare___redArg(lean_object* v_inst_123_, lean_object* v_x_124_, lean_object* v_y_125_){
_start:
{
lean_object* v_toDecidableLE_126_; lean_object* v___x_127_; lean_object* v___x_128_; lean_object* v___x_129_; 
v_toDecidableLE_126_ = lean_ctor_get(v_inst_123_, 4);
lean_inc_ref(v_toDecidableLE_126_);
lean_dec_ref(v_inst_123_);
v___x_127_ = lean_apply_2(v_toDecidableLE_126_, v_x_124_, v_y_125_);
v___x_128_ = lean_unsigned_to_nat(1u);
v___x_129_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_129_, 0, v___x_127_);
lean_ctor_set(v___x_129_, 1, v___x_128_);
return v___x_129_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_countedCompare(lean_object* v_00_u03b1_130_, lean_object* v_inst_131_, uint8_t v_x_132_, lean_object* v_x_133_, lean_object* v_y_134_){
_start:
{
lean_object* v_toDecidableLE_135_; lean_object* v___x_136_; lean_object* v___x_137_; lean_object* v___x_138_; 
v_toDecidableLE_135_ = lean_ctor_get(v_inst_131_, 4);
lean_inc_ref(v_toDecidableLE_135_);
lean_dec_ref(v_inst_131_);
v___x_136_ = lean_apply_2(v_toDecidableLE_135_, v_x_133_, v_y_134_);
v___x_137_ = lean_unsigned_to_nat(1u);
v___x_138_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_138_, 0, v___x_136_);
lean_ctor_set(v___x_138_, 1, v___x_137_);
return v___x_138_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_countedCompare___boxed(lean_object* v_00_u03b1_139_, lean_object* v_inst_140_, lean_object* v_x_141_, lean_object* v_x_142_, lean_object* v_y_143_){
_start:
{
uint8_t v_x_27__boxed_144_; lean_object* v_res_145_; 
v_x_27__boxed_144_ = lean_unbox(v_x_141_);
v_res_145_ = l_LeanSort_Direct_countedCompare(v_00_u03b1_139_, v_inst_140_, v_x_27__boxed_144_, v_x_142_, v_y_143_);
return v_res_145_;
}
}
LEAN_EXPORT uint8_t l_LeanSort_Direct_plainCompare___redArg(lean_object* v_inst_146_, lean_object* v_x_147_, lean_object* v_y_148_){
_start:
{
lean_object* v_toDecidableLE_149_; lean_object* v___x_150_; uint8_t v___x_151_; 
v_toDecidableLE_149_ = lean_ctor_get(v_inst_146_, 4);
lean_inc_ref(v_toDecidableLE_149_);
lean_dec_ref(v_inst_146_);
v___x_150_ = lean_apply_2(v_toDecidableLE_149_, v_x_147_, v_y_148_);
v___x_151_ = lean_unbox(v___x_150_);
return v___x_151_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_plainCompare___redArg___boxed(lean_object* v_inst_152_, lean_object* v_x_153_, lean_object* v_y_154_){
_start:
{
uint8_t v_res_155_; lean_object* v_r_156_; 
v_res_155_ = l_LeanSort_Direct_plainCompare___redArg(v_inst_152_, v_x_153_, v_y_154_);
v_r_156_ = lean_box(v_res_155_);
return v_r_156_;
}
}
LEAN_EXPORT uint8_t l_LeanSort_Direct_plainCompare(lean_object* v_00_u03b1_157_, lean_object* v_inst_158_, uint8_t v_x_159_, lean_object* v_x_160_, lean_object* v_y_161_){
_start:
{
lean_object* v_toDecidableLE_162_; lean_object* v___x_163_; uint8_t v___x_164_; 
v_toDecidableLE_162_ = lean_ctor_get(v_inst_158_, 4);
lean_inc_ref(v_toDecidableLE_162_);
lean_dec_ref(v_inst_158_);
v___x_163_ = lean_apply_2(v_toDecidableLE_162_, v_x_160_, v_y_161_);
v___x_164_ = lean_unbox(v___x_163_);
return v___x_164_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_plainCompare___boxed(lean_object* v_00_u03b1_165_, lean_object* v_inst_166_, lean_object* v_x_167_, lean_object* v_x_168_, lean_object* v_y_169_){
_start:
{
uint8_t v_x_19__boxed_170_; uint8_t v_res_171_; lean_object* v_r_172_; 
v_x_19__boxed_170_ = lean_unbox(v_x_167_);
v_res_171_ = l_LeanSort_Direct_plainCompare(v_00_u03b1_165_, v_inst_166_, v_x_19__boxed_170_, v_x_168_, v_y_169_);
v_r_172_ = lean_box(v_res_171_);
return v_r_172_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___redArg___lam__0(uint8_t v_ascending_173_, lean_object* v_head_174_, lean_object* v_toPure_175_, lean_object* v_____x_176_){
_start:
{
if (v_ascending_173_ == 0)
{
lean_object* v_fst_177_; lean_object* v_snd_178_; lean_object* v___x_180_; uint8_t v_isShared_181_; uint8_t v_isSharedCheck_189_; 
v_fst_177_ = lean_ctor_get(v_____x_176_, 0);
v_snd_178_ = lean_ctor_get(v_____x_176_, 1);
v_isSharedCheck_189_ = !lean_is_exclusive(v_____x_176_);
if (v_isSharedCheck_189_ == 0)
{
v___x_180_ = v_____x_176_;
v_isShared_181_ = v_isSharedCheck_189_;
goto v_resetjp_179_;
}
else
{
lean_inc(v_snd_178_);
lean_inc(v_fst_177_);
lean_dec(v_____x_176_);
v___x_180_ = lean_box(0);
v_isShared_181_ = v_isSharedCheck_189_;
goto v_resetjp_179_;
}
v_resetjp_179_:
{
lean_object* v___x_182_; lean_object* v___x_183_; lean_object* v___x_184_; lean_object* v___x_186_; 
v___x_182_ = lean_box(0);
v___x_183_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_183_, 0, v_head_174_);
lean_ctor_set(v___x_183_, 1, v_fst_177_);
v___x_184_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_184_, 0, v___x_183_);
lean_ctor_set(v___x_184_, 1, v_snd_178_);
if (v_isShared_181_ == 0)
{
lean_ctor_set(v___x_180_, 1, v___x_184_);
lean_ctor_set(v___x_180_, 0, v___x_182_);
v___x_186_ = v___x_180_;
goto v_reusejp_185_;
}
else
{
lean_object* v_reuseFailAlloc_188_; 
v_reuseFailAlloc_188_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_188_, 0, v___x_182_);
lean_ctor_set(v_reuseFailAlloc_188_, 1, v___x_184_);
v___x_186_ = v_reuseFailAlloc_188_;
goto v_reusejp_185_;
}
v_reusejp_185_:
{
lean_object* v___x_187_; 
v___x_187_ = lean_apply_2(v_toPure_175_, lean_box(0), v___x_186_);
return v___x_187_;
}
}
}
else
{
lean_object* v_fst_190_; lean_object* v_snd_191_; lean_object* v___x_193_; uint8_t v_isShared_194_; uint8_t v_isSharedCheck_200_; 
v_fst_190_ = lean_ctor_get(v_____x_176_, 0);
v_snd_191_ = lean_ctor_get(v_____x_176_, 1);
v_isSharedCheck_200_ = !lean_is_exclusive(v_____x_176_);
if (v_isSharedCheck_200_ == 0)
{
v___x_193_ = v_____x_176_;
v_isShared_194_ = v_isSharedCheck_200_;
goto v_resetjp_192_;
}
else
{
lean_inc(v_snd_191_);
lean_inc(v_fst_190_);
lean_dec(v_____x_176_);
v___x_193_ = lean_box(0);
v_isShared_194_ = v_isSharedCheck_200_;
goto v_resetjp_192_;
}
v_resetjp_192_:
{
lean_object* v___x_195_; lean_object* v___x_197_; 
v___x_195_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_195_, 0, v_head_174_);
lean_ctor_set(v___x_195_, 1, v_fst_190_);
if (v_isShared_194_ == 0)
{
lean_ctor_set(v___x_193_, 0, v___x_195_);
v___x_197_ = v___x_193_;
goto v_reusejp_196_;
}
else
{
lean_object* v_reuseFailAlloc_199_; 
v_reuseFailAlloc_199_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_199_, 0, v___x_195_);
lean_ctor_set(v_reuseFailAlloc_199_, 1, v_snd_191_);
v___x_197_ = v_reuseFailAlloc_199_;
goto v_reusejp_196_;
}
v_reusejp_196_:
{
lean_object* v___x_198_; 
v___x_198_ = lean_apply_2(v_toPure_175_, lean_box(0), v___x_197_);
return v___x_198_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___redArg___lam__0___boxed(lean_object* v_ascending_201_, lean_object* v_head_202_, lean_object* v_toPure_203_, lean_object* v_____x_204_){
_start:
{
uint8_t v_ascending_boxed_205_; lean_object* v_res_206_; 
v_ascending_boxed_205_ = lean_unbox(v_ascending_201_);
v_res_206_ = l_LeanSort_Direct_Engine_scanTail___redArg___lam__0(v_ascending_boxed_205_, v_head_202_, v_toPure_203_, v_____x_204_);
return v_res_206_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___redArg___lam__1___boxed(lean_object* v_head_207_, lean_object* v_toPure_208_, lean_object* v_inst_209_, lean_object* v_cmp_210_, lean_object* v_tail_211_, lean_object* v_toBind_212_, lean_object* v_ascending_213_){
_start:
{
uint8_t v_ascending_boxed_214_; lean_object* v_res_215_; 
v_ascending_boxed_214_ = lean_unbox(v_ascending_213_);
v_res_215_ = l_LeanSort_Direct_Engine_scanTail___redArg___lam__1(v_head_207_, v_toPure_208_, v_inst_209_, v_cmp_210_, v_tail_211_, v_toBind_212_, v_ascending_boxed_214_);
return v_res_215_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___redArg(lean_object* v_inst_216_, lean_object* v_cmp_217_, lean_object* v_x_218_, lean_object* v_x_219_){
_start:
{
if (lean_obj_tag(v_x_219_) == 0)
{
lean_object* v_toApplicative_220_; lean_object* v___x_222_; uint8_t v_isShared_223_; uint8_t v_isSharedCheck_230_; 
v_toApplicative_220_ = lean_ctor_get(v_inst_216_, 0);
lean_inc_ref(v_toApplicative_220_);
lean_dec(v_x_218_);
lean_dec(v_cmp_217_);
v_isSharedCheck_230_ = !lean_is_exclusive(v_inst_216_);
if (v_isSharedCheck_230_ == 0)
{
lean_object* v_unused_231_; lean_object* v_unused_232_; 
v_unused_231_ = lean_ctor_get(v_inst_216_, 1);
lean_dec(v_unused_231_);
v_unused_232_ = lean_ctor_get(v_inst_216_, 0);
lean_dec(v_unused_232_);
v___x_222_ = v_inst_216_;
v_isShared_223_ = v_isSharedCheck_230_;
goto v_resetjp_221_;
}
else
{
lean_dec(v_inst_216_);
v___x_222_ = lean_box(0);
v_isShared_223_ = v_isSharedCheck_230_;
goto v_resetjp_221_;
}
v_resetjp_221_:
{
lean_object* v_toPure_224_; lean_object* v___x_225_; lean_object* v___x_227_; 
v_toPure_224_ = lean_ctor_get(v_toApplicative_220_, 1);
lean_inc(v_toPure_224_);
lean_dec_ref(v_toApplicative_220_);
v___x_225_ = lean_box(0);
if (v_isShared_223_ == 0)
{
lean_ctor_set(v___x_222_, 1, v___x_225_);
lean_ctor_set(v___x_222_, 0, v_x_219_);
v___x_227_ = v___x_222_;
goto v_reusejp_226_;
}
else
{
lean_object* v_reuseFailAlloc_229_; 
v_reuseFailAlloc_229_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v_reuseFailAlloc_229_, 0, v_x_219_);
lean_ctor_set(v_reuseFailAlloc_229_, 1, v___x_225_);
v___x_227_ = v_reuseFailAlloc_229_;
goto v_reusejp_226_;
}
v_reusejp_226_:
{
lean_object* v___x_228_; 
v___x_228_ = lean_apply_2(v_toPure_224_, lean_box(0), v___x_227_);
return v___x_228_;
}
}
}
else
{
lean_object* v_toApplicative_233_; lean_object* v_toBind_234_; lean_object* v_toPure_235_; lean_object* v_head_236_; lean_object* v_tail_237_; lean_object* v___f_238_; uint8_t v___x_239_; lean_object* v___x_240_; lean_object* v___x_241_; lean_object* v___x_242_; 
v_toApplicative_233_ = lean_ctor_get(v_inst_216_, 0);
v_toBind_234_ = lean_ctor_get(v_inst_216_, 1);
lean_inc_n(v_toBind_234_, 2);
v_toPure_235_ = lean_ctor_get(v_toApplicative_233_, 1);
lean_inc(v_toPure_235_);
v_head_236_ = lean_ctor_get(v_x_219_, 0);
lean_inc_n(v_head_236_, 2);
v_tail_237_ = lean_ctor_get(v_x_219_, 1);
lean_inc(v_tail_237_);
lean_dec_ref_known(v_x_219_, 2);
lean_inc(v_cmp_217_);
v___f_238_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_scanTail___redArg___lam__1___boxed), 7, 6);
lean_closure_set(v___f_238_, 0, v_head_236_);
lean_closure_set(v___f_238_, 1, v_toPure_235_);
lean_closure_set(v___f_238_, 2, v_inst_216_);
lean_closure_set(v___f_238_, 3, v_cmp_217_);
lean_closure_set(v___f_238_, 4, v_tail_237_);
lean_closure_set(v___f_238_, 5, v_toBind_234_);
v___x_239_ = 0;
v___x_240_ = lean_box(v___x_239_);
v___x_241_ = lean_apply_3(v_cmp_217_, v___x_240_, v_x_218_, v_head_236_);
v___x_242_ = lean_apply_4(v_toBind_234_, lean_box(0), lean_box(0), v___x_241_, v___f_238_);
return v___x_242_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail___redArg___lam__1(lean_object* v_head_243_, lean_object* v_toPure_244_, lean_object* v_inst_245_, lean_object* v_cmp_246_, lean_object* v_tail_247_, lean_object* v_toBind_248_, uint8_t v_ascending_249_){
_start:
{
lean_object* v___x_250_; lean_object* v___f_251_; lean_object* v___x_252_; lean_object* v___x_253_; 
v___x_250_ = lean_box(v_ascending_249_);
lean_inc(v_head_243_);
v___f_251_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_scanTail___redArg___lam__0___boxed), 4, 3);
lean_closure_set(v___f_251_, 0, v___x_250_);
lean_closure_set(v___f_251_, 1, v_head_243_);
lean_closure_set(v___f_251_, 2, v_toPure_244_);
v___x_252_ = l_LeanSort_Direct_Engine_scanTail___redArg(v_inst_245_, v_cmp_246_, v_head_243_, v_tail_247_);
v___x_253_ = lean_apply_4(v_toBind_248_, lean_box(0), lean_box(0), v___x_252_, v___f_251_);
return v___x_253_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_scanTail(lean_object* v_m_254_, lean_object* v_inst_255_, lean_object* v_00_u03b1_256_, lean_object* v_cmp_257_, lean_object* v_x_258_, lean_object* v_x_259_){
_start:
{
lean_object* v___x_260_; 
v___x_260_ = l_LeanSort_Direct_Engine_scanTail___redArg(v_inst_255_, v_cmp_257_, v_x_258_, v_x_259_);
return v___x_260_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___redArg___lam__0(lean_object* v_head_261_, lean_object* v_toPure_262_, lean_object* v_____x_263_){
_start:
{
lean_object* v_fst_264_; lean_object* v_snd_265_; lean_object* v___x_267_; uint8_t v_isShared_268_; uint8_t v_isSharedCheck_274_; 
v_fst_264_ = lean_ctor_get(v_____x_263_, 0);
v_snd_265_ = lean_ctor_get(v_____x_263_, 1);
v_isSharedCheck_274_ = !lean_is_exclusive(v_____x_263_);
if (v_isSharedCheck_274_ == 0)
{
v___x_267_ = v_____x_263_;
v_isShared_268_ = v_isSharedCheck_274_;
goto v_resetjp_266_;
}
else
{
lean_inc(v_snd_265_);
lean_inc(v_fst_264_);
lean_dec(v_____x_263_);
v___x_267_ = lean_box(0);
v_isShared_268_ = v_isSharedCheck_274_;
goto v_resetjp_266_;
}
v_resetjp_266_:
{
lean_object* v___x_270_; 
if (v_isShared_268_ == 0)
{
lean_ctor_set_tag(v___x_267_, 1);
lean_ctor_set(v___x_267_, 1, v_fst_264_);
lean_ctor_set(v___x_267_, 0, v_head_261_);
v___x_270_ = v___x_267_;
goto v_reusejp_269_;
}
else
{
lean_object* v_reuseFailAlloc_273_; 
v_reuseFailAlloc_273_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_273_, 0, v_head_261_);
lean_ctor_set(v_reuseFailAlloc_273_, 1, v_fst_264_);
v___x_270_ = v_reuseFailAlloc_273_;
goto v_reusejp_269_;
}
v_reusejp_269_:
{
lean_object* v___x_271_; lean_object* v___x_272_; 
v___x_271_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_271_, 0, v___x_270_);
lean_ctor_set(v___x_271_, 1, v_snd_265_);
v___x_272_ = lean_apply_2(v_toPure_262_, lean_box(0), v___x_271_);
return v___x_272_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover___redArg(lean_object* v_inst_275_, lean_object* v_cmp_276_, lean_object* v_x_277_){
_start:
{
if (lean_obj_tag(v_x_277_) == 0)
{
lean_object* v_toApplicative_278_; lean_object* v_toPure_279_; lean_object* v___x_280_; lean_object* v___x_281_; 
v_toApplicative_278_ = lean_ctor_get(v_inst_275_, 0);
lean_inc_ref(v_toApplicative_278_);
lean_dec(v_cmp_276_);
lean_dec_ref(v_inst_275_);
v_toPure_279_ = lean_ctor_get(v_toApplicative_278_, 1);
lean_inc(v_toPure_279_);
lean_dec_ref(v_toApplicative_278_);
v___x_280_ = lean_box(0);
v___x_281_ = lean_apply_2(v_toPure_279_, lean_box(0), v___x_280_);
return v___x_281_;
}
else
{
lean_object* v_toApplicative_282_; lean_object* v_toBind_283_; lean_object* v_toPure_284_; lean_object* v_head_285_; lean_object* v_tail_286_; lean_object* v___f_287_; lean_object* v___x_288_; lean_object* v___x_289_; 
v_toApplicative_282_ = lean_ctor_get(v_inst_275_, 0);
v_toBind_283_ = lean_ctor_get(v_inst_275_, 1);
lean_inc(v_toBind_283_);
v_toPure_284_ = lean_ctor_get(v_toApplicative_282_, 1);
v_head_285_ = lean_ctor_get(v_x_277_, 0);
lean_inc_n(v_head_285_, 2);
v_tail_286_ = lean_ctor_get(v_x_277_, 1);
lean_inc(v_tail_286_);
lean_dec_ref_known(v_x_277_, 2);
lean_inc(v_toPure_284_);
v___f_287_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_discover___redArg___lam__0), 3, 2);
lean_closure_set(v___f_287_, 0, v_head_285_);
lean_closure_set(v___f_287_, 1, v_toPure_284_);
v___x_288_ = l_LeanSort_Direct_Engine_scanTail___redArg(v_inst_275_, v_cmp_276_, v_head_285_, v_tail_286_);
v___x_289_ = lean_apply_4(v_toBind_283_, lean_box(0), lean_box(0), v___x_288_, v___f_287_);
return v___x_289_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_discover(lean_object* v_m_290_, lean_object* v_inst_291_, lean_object* v_00_u03b1_292_, lean_object* v_cmp_293_, lean_object* v_x_294_){
_start:
{
lean_object* v___x_295_; 
v___x_295_ = l_LeanSort_Direct_Engine_discover___redArg(v_inst_291_, v_cmp_293_, v_x_294_);
return v___x_295_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___redArg___lam__0(lean_object* v_head_296_, lean_object* v_toPure_297_, lean_object* v_rest_298_){
_start:
{
lean_object* v___x_299_; lean_object* v___x_300_; 
v___x_299_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_299_, 0, v_head_296_);
lean_ctor_set(v___x_299_, 1, v_rest_298_);
v___x_300_ = lean_apply_2(v_toPure_297_, lean_box(0), v___x_299_);
return v___x_300_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___redArg___lam__2___boxed(lean_object* v_inst_301_, lean_object* v_cmp_302_, lean_object* v_x_303_, lean_object* v_tail_304_, lean_object* v_toBind_305_, lean_object* v___f_306_, lean_object* v_tail_307_, lean_object* v_x_308_, lean_object* v___f_309_, lean_object* v_smaller_310_){
_start:
{
uint8_t v_smaller_boxed_311_; lean_object* v_res_312_; 
v_smaller_boxed_311_ = lean_unbox(v_smaller_310_);
v_res_312_ = l_LeanSort_Direct_Engine_merge___redArg___lam__2(v_inst_301_, v_cmp_302_, v_x_303_, v_tail_304_, v_toBind_305_, v___f_306_, v_tail_307_, v_x_308_, v___f_309_, v_smaller_boxed_311_);
return v_res_312_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___redArg(lean_object* v_inst_313_, lean_object* v_cmp_314_, lean_object* v_x_315_, lean_object* v_x_316_){
_start:
{
if (lean_obj_tag(v_x_315_) == 0)
{
lean_object* v_toApplicative_317_; lean_object* v_toPure_318_; lean_object* v___x_319_; 
v_toApplicative_317_ = lean_ctor_get(v_inst_313_, 0);
lean_inc_ref(v_toApplicative_317_);
lean_dec(v_cmp_314_);
lean_dec_ref(v_inst_313_);
v_toPure_318_ = lean_ctor_get(v_toApplicative_317_, 1);
lean_inc(v_toPure_318_);
lean_dec_ref(v_toApplicative_317_);
v___x_319_ = lean_apply_2(v_toPure_318_, lean_box(0), v_x_316_);
return v___x_319_;
}
else
{
if (lean_obj_tag(v_x_316_) == 0)
{
lean_object* v_toApplicative_320_; lean_object* v_toPure_321_; lean_object* v___x_322_; 
v_toApplicative_320_ = lean_ctor_get(v_inst_313_, 0);
lean_inc_ref(v_toApplicative_320_);
lean_dec(v_cmp_314_);
lean_dec_ref(v_inst_313_);
v_toPure_321_ = lean_ctor_get(v_toApplicative_320_, 1);
lean_inc(v_toPure_321_);
lean_dec_ref(v_toApplicative_320_);
v___x_322_ = lean_apply_2(v_toPure_321_, lean_box(0), v_x_315_);
return v___x_322_;
}
else
{
lean_object* v_toApplicative_323_; lean_object* v_toBind_324_; lean_object* v_toPure_325_; lean_object* v_head_326_; lean_object* v_tail_327_; lean_object* v_head_328_; lean_object* v_tail_329_; lean_object* v___f_330_; lean_object* v___f_331_; lean_object* v___f_332_; uint8_t v___x_333_; lean_object* v___x_334_; lean_object* v___x_335_; lean_object* v___x_336_; 
v_toApplicative_323_ = lean_ctor_get(v_inst_313_, 0);
v_toBind_324_ = lean_ctor_get(v_inst_313_, 1);
lean_inc_n(v_toBind_324_, 2);
v_toPure_325_ = lean_ctor_get(v_toApplicative_323_, 1);
v_head_326_ = lean_ctor_get(v_x_315_, 0);
lean_inc_n(v_head_326_, 2);
v_tail_327_ = lean_ctor_get(v_x_315_, 1);
lean_inc(v_tail_327_);
v_head_328_ = lean_ctor_get(v_x_316_, 0);
lean_inc_n(v_head_328_, 2);
v_tail_329_ = lean_ctor_get(v_x_316_, 1);
lean_inc(v_tail_329_);
lean_inc_n(v_toPure_325_, 2);
v___f_330_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___redArg___lam__0), 3, 2);
lean_closure_set(v___f_330_, 0, v_head_326_);
lean_closure_set(v___f_330_, 1, v_toPure_325_);
v___f_331_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___redArg___lam__0), 3, 2);
lean_closure_set(v___f_331_, 0, v_head_328_);
lean_closure_set(v___f_331_, 1, v_toPure_325_);
lean_inc(v_cmp_314_);
v___f_332_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___redArg___lam__2___boxed), 10, 9);
lean_closure_set(v___f_332_, 0, v_inst_313_);
lean_closure_set(v___f_332_, 1, v_cmp_314_);
lean_closure_set(v___f_332_, 2, v_x_315_);
lean_closure_set(v___f_332_, 3, v_tail_329_);
lean_closure_set(v___f_332_, 4, v_toBind_324_);
lean_closure_set(v___f_332_, 5, v___f_331_);
lean_closure_set(v___f_332_, 6, v_tail_327_);
lean_closure_set(v___f_332_, 7, v_x_316_);
lean_closure_set(v___f_332_, 8, v___f_330_);
v___x_333_ = 1;
v___x_334_ = lean_box(v___x_333_);
v___x_335_ = lean_apply_3(v_cmp_314_, v___x_334_, v_head_326_, v_head_328_);
v___x_336_ = lean_apply_4(v_toBind_324_, lean_box(0), lean_box(0), v___x_335_, v___f_332_);
return v___x_336_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge___redArg___lam__2(lean_object* v_inst_337_, lean_object* v_cmp_338_, lean_object* v_x_339_, lean_object* v_tail_340_, lean_object* v_toBind_341_, lean_object* v___f_342_, lean_object* v_tail_343_, lean_object* v_x_344_, lean_object* v___f_345_, uint8_t v_smaller_346_){
_start:
{
if (v_smaller_346_ == 0)
{
lean_object* v___x_347_; lean_object* v___x_348_; 
lean_dec(v___f_345_);
lean_dec(v_x_344_);
lean_dec(v_tail_343_);
v___x_347_ = l_LeanSort_Direct_Engine_merge___redArg(v_inst_337_, v_cmp_338_, v_x_339_, v_tail_340_);
v___x_348_ = lean_apply_4(v_toBind_341_, lean_box(0), lean_box(0), v___x_347_, v___f_342_);
return v___x_348_;
}
else
{
lean_object* v___x_349_; lean_object* v___x_350_; 
lean_dec(v___f_342_);
lean_dec(v_tail_340_);
lean_dec(v_x_339_);
v___x_349_ = l_LeanSort_Direct_Engine_merge___redArg(v_inst_337_, v_cmp_338_, v_tail_343_, v_x_344_);
v___x_350_ = lean_apply_4(v_toBind_341_, lean_box(0), lean_box(0), v___x_349_, v___f_345_);
return v___x_350_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_merge(lean_object* v_m_351_, lean_object* v_inst_352_, lean_object* v_00_u03b1_353_, lean_object* v_cmp_354_, lean_object* v_x_355_, lean_object* v_x_356_){
_start:
{
lean_object* v___x_357_; 
v___x_357_ = l_LeanSort_Direct_Engine_merge___redArg(v_inst_352_, v_cmp_354_, v_x_355_, v_x_356_);
return v___x_357_;
}
}
LEAN_EXPORT lean_object* l___private_LeanSort_Algorithm_Direct_Engine_0__LeanSort_Direct_Engine_merge_match__1_splitter___redArg(lean_object* v_x_358_, lean_object* v_x_359_, lean_object* v_h__1_360_, lean_object* v_h__2_361_, lean_object* v_h__3_362_){
_start:
{
if (lean_obj_tag(v_x_358_) == 0)
{
lean_object* v___x_363_; 
lean_dec(v_h__3_362_);
lean_dec(v_h__2_361_);
v___x_363_ = lean_apply_1(v_h__1_360_, v_x_359_);
return v___x_363_;
}
else
{
lean_dec(v_h__1_360_);
if (lean_obj_tag(v_x_359_) == 0)
{
lean_object* v___x_364_; 
lean_dec(v_h__3_362_);
v___x_364_ = lean_apply_2(v_h__2_361_, v_x_358_, lean_box(0));
return v___x_364_;
}
else
{
lean_object* v_head_365_; lean_object* v_tail_366_; lean_object* v_head_367_; lean_object* v_tail_368_; lean_object* v___x_369_; 
lean_dec(v_h__2_361_);
v_head_365_ = lean_ctor_get(v_x_358_, 0);
lean_inc(v_head_365_);
v_tail_366_ = lean_ctor_get(v_x_358_, 1);
lean_inc(v_tail_366_);
lean_dec_ref_known(v_x_358_, 2);
v_head_367_ = lean_ctor_get(v_x_359_, 0);
lean_inc(v_head_367_);
v_tail_368_ = lean_ctor_get(v_x_359_, 1);
lean_inc(v_tail_368_);
lean_dec_ref_known(v_x_359_, 2);
v___x_369_ = lean_apply_4(v_h__3_362_, v_head_365_, v_tail_366_, v_head_367_, v_tail_368_);
return v___x_369_;
}
}
}
}
LEAN_EXPORT lean_object* l___private_LeanSort_Algorithm_Direct_Engine_0__LeanSort_Direct_Engine_merge_match__1_splitter(lean_object* v_00_u03b1_370_, lean_object* v_motive_371_, lean_object* v_x_372_, lean_object* v_x_373_, lean_object* v_h__1_374_, lean_object* v_h__2_375_, lean_object* v_h__3_376_){
_start:
{
if (lean_obj_tag(v_x_372_) == 0)
{
lean_object* v___x_377_; 
lean_dec(v_h__3_376_);
lean_dec(v_h__2_375_);
v___x_377_ = lean_apply_1(v_h__1_374_, v_x_373_);
return v___x_377_;
}
else
{
lean_dec(v_h__1_374_);
if (lean_obj_tag(v_x_373_) == 0)
{
lean_object* v___x_378_; 
lean_dec(v_h__3_376_);
v___x_378_ = lean_apply_2(v_h__2_375_, v_x_372_, lean_box(0));
return v___x_378_;
}
else
{
lean_object* v_head_379_; lean_object* v_tail_380_; lean_object* v_head_381_; lean_object* v_tail_382_; lean_object* v___x_383_; 
lean_dec(v_h__2_375_);
v_head_379_ = lean_ctor_get(v_x_372_, 0);
lean_inc(v_head_379_);
v_tail_380_ = lean_ctor_get(v_x_372_, 1);
lean_inc(v_tail_380_);
lean_dec_ref_known(v_x_372_, 2);
v_head_381_ = lean_ctor_get(v_x_373_, 0);
lean_inc(v_head_381_);
v_tail_382_ = lean_ctor_get(v_x_373_, 1);
lean_inc(v_tail_382_);
lean_dec_ref_known(v_x_373_, 2);
v___x_383_ = lean_apply_4(v_h__3_376_, v_head_379_, v_tail_380_, v_head_381_, v_tail_382_);
return v___x_383_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___redArg___lam__1___boxed(lean_object* v_inst_384_, lean_object* v_cmp_385_, lean_object* v_x_386_, lean_object* v_tail_387_, lean_object* v_toBind_388_, lean_object* v___f_389_, lean_object* v_x_390_, lean_object* v_toPure_391_, lean_object* v_smaller_392_){
_start:
{
uint8_t v_smaller_boxed_393_; lean_object* v_res_394_; 
v_smaller_boxed_393_ = lean_unbox(v_smaller_392_);
v_res_394_ = l_LeanSort_Direct_Engine_insert___redArg___lam__1(v_inst_384_, v_cmp_385_, v_x_386_, v_tail_387_, v_toBind_388_, v___f_389_, v_x_390_, v_toPure_391_, v_smaller_boxed_393_);
return v_res_394_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___redArg(lean_object* v_inst_395_, lean_object* v_cmp_396_, lean_object* v_x_397_, lean_object* v_x_398_){
_start:
{
if (lean_obj_tag(v_x_398_) == 0)
{
lean_object* v_toApplicative_399_; lean_object* v___x_401_; uint8_t v_isShared_402_; uint8_t v_isSharedCheck_408_; 
v_toApplicative_399_ = lean_ctor_get(v_inst_395_, 0);
lean_inc_ref(v_toApplicative_399_);
lean_dec(v_cmp_396_);
v_isSharedCheck_408_ = !lean_is_exclusive(v_inst_395_);
if (v_isSharedCheck_408_ == 0)
{
lean_object* v_unused_409_; lean_object* v_unused_410_; 
v_unused_409_ = lean_ctor_get(v_inst_395_, 1);
lean_dec(v_unused_409_);
v_unused_410_ = lean_ctor_get(v_inst_395_, 0);
lean_dec(v_unused_410_);
v___x_401_ = v_inst_395_;
v_isShared_402_ = v_isSharedCheck_408_;
goto v_resetjp_400_;
}
else
{
lean_dec(v_inst_395_);
v___x_401_ = lean_box(0);
v_isShared_402_ = v_isSharedCheck_408_;
goto v_resetjp_400_;
}
v_resetjp_400_:
{
lean_object* v_toPure_403_; lean_object* v___x_405_; 
v_toPure_403_ = lean_ctor_get(v_toApplicative_399_, 1);
lean_inc(v_toPure_403_);
lean_dec_ref(v_toApplicative_399_);
if (v_isShared_402_ == 0)
{
lean_ctor_set_tag(v___x_401_, 1);
lean_ctor_set(v___x_401_, 1, v_x_398_);
lean_ctor_set(v___x_401_, 0, v_x_397_);
v___x_405_ = v___x_401_;
goto v_reusejp_404_;
}
else
{
lean_object* v_reuseFailAlloc_407_; 
v_reuseFailAlloc_407_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v_reuseFailAlloc_407_, 0, v_x_397_);
lean_ctor_set(v_reuseFailAlloc_407_, 1, v_x_398_);
v___x_405_ = v_reuseFailAlloc_407_;
goto v_reusejp_404_;
}
v_reusejp_404_:
{
lean_object* v___x_406_; 
v___x_406_ = lean_apply_2(v_toPure_403_, lean_box(0), v___x_405_);
return v___x_406_;
}
}
}
else
{
lean_object* v_toApplicative_411_; lean_object* v_toBind_412_; lean_object* v_toPure_413_; lean_object* v_head_414_; lean_object* v_tail_415_; lean_object* v___f_416_; lean_object* v___f_417_; uint8_t v___x_418_; lean_object* v___x_419_; lean_object* v___x_420_; lean_object* v___x_421_; 
v_toApplicative_411_ = lean_ctor_get(v_inst_395_, 0);
v_toBind_412_ = lean_ctor_get(v_inst_395_, 1);
lean_inc_n(v_toBind_412_, 2);
v_toPure_413_ = lean_ctor_get(v_toApplicative_411_, 1);
lean_inc_n(v_toPure_413_, 2);
v_head_414_ = lean_ctor_get(v_x_398_, 0);
lean_inc_n(v_head_414_, 2);
v_tail_415_ = lean_ctor_get(v_x_398_, 1);
lean_inc(v_tail_415_);
v___f_416_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_merge___redArg___lam__0), 3, 2);
lean_closure_set(v___f_416_, 0, v_head_414_);
lean_closure_set(v___f_416_, 1, v_toPure_413_);
lean_inc(v_x_397_);
lean_inc(v_cmp_396_);
v___f_417_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_insert___redArg___lam__1___boxed), 9, 8);
lean_closure_set(v___f_417_, 0, v_inst_395_);
lean_closure_set(v___f_417_, 1, v_cmp_396_);
lean_closure_set(v___f_417_, 2, v_x_397_);
lean_closure_set(v___f_417_, 3, v_tail_415_);
lean_closure_set(v___f_417_, 4, v_toBind_412_);
lean_closure_set(v___f_417_, 5, v___f_416_);
lean_closure_set(v___f_417_, 6, v_x_398_);
lean_closure_set(v___f_417_, 7, v_toPure_413_);
v___x_418_ = 1;
v___x_419_ = lean_box(v___x_418_);
v___x_420_ = lean_apply_3(v_cmp_396_, v___x_419_, v_x_397_, v_head_414_);
v___x_421_ = lean_apply_4(v_toBind_412_, lean_box(0), lean_box(0), v___x_420_, v___f_417_);
return v___x_421_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert___redArg___lam__1(lean_object* v_inst_422_, lean_object* v_cmp_423_, lean_object* v_x_424_, lean_object* v_tail_425_, lean_object* v_toBind_426_, lean_object* v___f_427_, lean_object* v_x_428_, lean_object* v_toPure_429_, uint8_t v_smaller_430_){
_start:
{
if (v_smaller_430_ == 0)
{
lean_object* v___x_431_; lean_object* v___x_432_; 
lean_dec(v_toPure_429_);
lean_dec(v_x_428_);
v___x_431_ = l_LeanSort_Direct_Engine_insert___redArg(v_inst_422_, v_cmp_423_, v_x_424_, v_tail_425_);
v___x_432_ = lean_apply_4(v_toBind_426_, lean_box(0), lean_box(0), v___x_431_, v___f_427_);
return v___x_432_;
}
else
{
lean_object* v___x_433_; lean_object* v___x_434_; 
lean_dec(v___f_427_);
lean_dec(v_toBind_426_);
lean_dec(v_tail_425_);
lean_dec(v_cmp_423_);
lean_dec_ref(v_inst_422_);
v___x_433_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_433_, 0, v_x_424_);
lean_ctor_set(v___x_433_, 1, v_x_428_);
v___x_434_ = lean_apply_2(v_toPure_429_, lean_box(0), v___x_433_);
return v___x_434_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insert(lean_object* v_m_435_, lean_object* v_inst_436_, lean_object* v_00_u03b1_437_, lean_object* v_cmp_438_, lean_object* v_x_439_, lean_object* v_x_440_){
_start:
{
lean_object* v___x_441_; 
v___x_441_ = l_LeanSort_Direct_Engine_insert___redArg(v_inst_436_, v_cmp_438_, v_x_439_, v_x_440_);
return v___x_441_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___redArg___lam__0(lean_object* v_inst_442_, lean_object* v_cmp_443_, lean_object* v_head_444_, lean_object* v_rest_445_){
_start:
{
lean_object* v___x_446_; 
v___x_446_ = l_LeanSort_Direct_Engine_insert___redArg(v_inst_442_, v_cmp_443_, v_head_444_, v_rest_445_);
return v___x_446_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion___redArg(lean_object* v_inst_447_, lean_object* v_cmp_448_, lean_object* v_x_449_){
_start:
{
if (lean_obj_tag(v_x_449_) == 0)
{
lean_object* v_toApplicative_450_; lean_object* v_toPure_451_; lean_object* v___x_452_; 
v_toApplicative_450_ = lean_ctor_get(v_inst_447_, 0);
lean_inc_ref(v_toApplicative_450_);
lean_dec(v_cmp_448_);
lean_dec_ref(v_inst_447_);
v_toPure_451_ = lean_ctor_get(v_toApplicative_450_, 1);
lean_inc(v_toPure_451_);
lean_dec_ref(v_toApplicative_450_);
v___x_452_ = lean_apply_2(v_toPure_451_, lean_box(0), v_x_449_);
return v___x_452_;
}
else
{
lean_object* v_toBind_453_; lean_object* v_head_454_; lean_object* v_tail_455_; lean_object* v___f_456_; lean_object* v___x_457_; lean_object* v___x_458_; 
v_toBind_453_ = lean_ctor_get(v_inst_447_, 1);
lean_inc(v_toBind_453_);
v_head_454_ = lean_ctor_get(v_x_449_, 0);
lean_inc(v_head_454_);
v_tail_455_ = lean_ctor_get(v_x_449_, 1);
lean_inc(v_tail_455_);
lean_dec_ref_known(v_x_449_, 2);
lean_inc(v_cmp_448_);
lean_inc_ref(v_inst_447_);
v___f_456_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_insertion___redArg___lam__0), 4, 3);
lean_closure_set(v___f_456_, 0, v_inst_447_);
lean_closure_set(v___f_456_, 1, v_cmp_448_);
lean_closure_set(v___f_456_, 2, v_head_454_);
v___x_457_ = l_LeanSort_Direct_Engine_insertion___redArg(v_inst_447_, v_cmp_448_, v_tail_455_);
v___x_458_ = lean_apply_4(v_toBind_453_, lean_box(0), lean_box(0), v___x_457_, v___f_456_);
return v___x_458_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_insertion(lean_object* v_m_459_, lean_object* v_inst_460_, lean_object* v_00_u03b1_461_, lean_object* v_cmp_462_, lean_object* v_x_463_){
_start:
{
lean_object* v___x_464_; 
v___x_464_ = l_LeanSort_Direct_Engine_insertion___redArg(v_inst_460_, v_cmp_462_, v_x_463_);
return v___x_464_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___redArg___lam__0(lean_object* v_inst_465_, lean_object* v_cmp_466_, lean_object* v_left_467_, lean_object* v_right_468_){
_start:
{
lean_object* v___x_469_; 
v___x_469_ = l_LeanSort_Direct_Engine_merge___redArg(v_inst_465_, v_cmp_466_, v_left_467_, v_right_468_);
return v___x_469_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___redArg___lam__1___boxed(lean_object* v_inst_470_, lean_object* v_cmp_471_, lean_object* v___x_472_, lean_object* v_xs_473_, lean_object* v_toBind_474_, lean_object* v_left_475_){
_start:
{
lean_object* v_res_476_; 
v_res_476_ = l_LeanSort_Direct_Engine_mergeSort___redArg___lam__1(v_inst_470_, v_cmp_471_, v___x_472_, v_xs_473_, v_toBind_474_, v_left_475_);
lean_dec(v_xs_473_);
return v_res_476_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___redArg(lean_object* v_inst_479_, lean_object* v_cmp_480_, lean_object* v_xs_481_){
_start:
{
lean_object* v___x_482_; lean_object* v___x_483_; uint8_t v___x_484_; 
v___x_482_ = l_List_lengthTR___redArg(v_xs_481_);
v___x_483_ = lean_unsigned_to_nat(2u);
v___x_484_ = lean_nat_dec_lt(v___x_482_, v___x_483_);
if (v___x_484_ == 0)
{
lean_object* v_toBind_485_; lean_object* v___x_486_; lean_object* v___x_487_; lean_object* v___f_488_; lean_object* v___x_489_; lean_object* v___x_490_; lean_object* v___x_491_; lean_object* v___x_492_; 
v_toBind_485_ = lean_ctor_get(v_inst_479_, 1);
lean_inc_n(v_toBind_485_, 2);
v___x_486_ = lean_unsigned_to_nat(1u);
v___x_487_ = lean_nat_shiftr(v___x_482_, v___x_486_);
lean_dec(v___x_482_);
lean_inc_n(v_xs_481_, 2);
lean_inc(v___x_487_);
lean_inc(v_cmp_480_);
lean_inc_ref(v_inst_479_);
v___f_488_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_mergeSort___redArg___lam__1___boxed), 6, 5);
lean_closure_set(v___f_488_, 0, v_inst_479_);
lean_closure_set(v___f_488_, 1, v_cmp_480_);
lean_closure_set(v___f_488_, 2, v___x_487_);
lean_closure_set(v___f_488_, 3, v_xs_481_);
lean_closure_set(v___f_488_, 4, v_toBind_485_);
v___x_489_ = ((lean_object*)(l_LeanSort_Direct_Engine_mergeSort___redArg___closed__0));
v___x_490_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_xs_481_, v_xs_481_, v___x_487_, v___x_489_);
lean_dec(v_xs_481_);
v___x_491_ = l_LeanSort_Direct_Engine_mergeSort___redArg(v_inst_479_, v_cmp_480_, v___x_490_);
v___x_492_ = lean_apply_4(v_toBind_485_, lean_box(0), lean_box(0), v___x_491_, v___f_488_);
return v___x_492_;
}
else
{
lean_object* v_toApplicative_493_; lean_object* v_toPure_494_; lean_object* v___x_495_; 
lean_dec(v___x_482_);
lean_dec(v_cmp_480_);
v_toApplicative_493_ = lean_ctor_get(v_inst_479_, 0);
lean_inc_ref(v_toApplicative_493_);
lean_dec_ref(v_inst_479_);
v_toPure_494_ = lean_ctor_get(v_toApplicative_493_, 1);
lean_inc(v_toPure_494_);
lean_dec_ref(v_toApplicative_493_);
v___x_495_ = lean_apply_2(v_toPure_494_, lean_box(0), v_xs_481_);
return v___x_495_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort___redArg___lam__1(lean_object* v_inst_496_, lean_object* v_cmp_497_, lean_object* v___x_498_, lean_object* v_xs_499_, lean_object* v_toBind_500_, lean_object* v_left_501_){
_start:
{
lean_object* v___f_502_; lean_object* v___x_503_; lean_object* v___x_504_; lean_object* v___x_505_; 
lean_inc(v_cmp_497_);
lean_inc_ref(v_inst_496_);
v___f_502_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_mergeSort___redArg___lam__0), 4, 3);
lean_closure_set(v___f_502_, 0, v_inst_496_);
lean_closure_set(v___f_502_, 1, v_cmp_497_);
lean_closure_set(v___f_502_, 2, v_left_501_);
v___x_503_ = l_List_drop___redArg(v___x_498_, v_xs_499_);
v___x_504_ = l_LeanSort_Direct_Engine_mergeSort___redArg(v_inst_496_, v_cmp_497_, v___x_503_);
v___x_505_ = lean_apply_4(v_toBind_500_, lean_box(0), lean_box(0), v___x_504_, v___f_502_);
return v___x_505_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_mergeSort(lean_object* v_m_506_, lean_object* v_inst_507_, lean_object* v_00_u03b1_508_, lean_object* v_cmp_509_, lean_object* v_xs_510_){
_start:
{
lean_object* v___x_511_; 
v___x_511_ = l_LeanSort_Direct_Engine_mergeSort___redArg(v_inst_507_, v_cmp_509_, v_xs_510_);
return v___x_511_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___redArg___lam__1___boxed(lean_object* v_inst_512_, lean_object* v_cmp_513_, lean_object* v___x_514_, lean_object* v_xs_515_, lean_object* v_threshold_516_, lean_object* v_toBind_517_, lean_object* v_left_518_){
_start:
{
lean_object* v_res_519_; 
v_res_519_ = l_LeanSort_Direct_Engine_hybrid___redArg___lam__1(v_inst_512_, v_cmp_513_, v___x_514_, v_xs_515_, v_threshold_516_, v_toBind_517_, v_left_518_);
lean_dec(v_xs_515_);
return v_res_519_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___redArg(lean_object* v_inst_520_, lean_object* v_cmp_521_, lean_object* v_threshold_522_, lean_object* v_xs_523_){
_start:
{
lean_object* v___x_524_; lean_object* v___y_526_; lean_object* v___x_537_; uint8_t v___x_538_; 
v___x_524_ = l_List_lengthTR___redArg(v_xs_523_);
v___x_537_ = lean_unsigned_to_nat(1u);
v___x_538_ = lean_nat_dec_le(v___x_537_, v_threshold_522_);
if (v___x_538_ == 0)
{
v___y_526_ = v___x_537_;
goto v___jp_525_;
}
else
{
lean_inc(v_threshold_522_);
v___y_526_ = v_threshold_522_;
goto v___jp_525_;
}
v___jp_525_:
{
uint8_t v___x_527_; 
v___x_527_ = lean_nat_dec_le(v___x_524_, v___y_526_);
lean_dec(v___y_526_);
if (v___x_527_ == 0)
{
lean_object* v_toBind_528_; lean_object* v___x_529_; lean_object* v___x_530_; lean_object* v___f_531_; lean_object* v___x_532_; lean_object* v___x_533_; lean_object* v___x_534_; lean_object* v___x_535_; 
v_toBind_528_ = lean_ctor_get(v_inst_520_, 1);
lean_inc_n(v_toBind_528_, 2);
v___x_529_ = lean_unsigned_to_nat(1u);
v___x_530_ = lean_nat_shiftr(v___x_524_, v___x_529_);
lean_dec(v___x_524_);
lean_inc(v_threshold_522_);
lean_inc_n(v_xs_523_, 2);
lean_inc(v___x_530_);
lean_inc(v_cmp_521_);
lean_inc_ref(v_inst_520_);
v___f_531_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_hybrid___redArg___lam__1___boxed), 7, 6);
lean_closure_set(v___f_531_, 0, v_inst_520_);
lean_closure_set(v___f_531_, 1, v_cmp_521_);
lean_closure_set(v___f_531_, 2, v___x_530_);
lean_closure_set(v___f_531_, 3, v_xs_523_);
lean_closure_set(v___f_531_, 4, v_threshold_522_);
lean_closure_set(v___f_531_, 5, v_toBind_528_);
v___x_532_ = ((lean_object*)(l_LeanSort_Direct_Engine_mergeSort___redArg___closed__0));
v___x_533_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_xs_523_, v_xs_523_, v___x_530_, v___x_532_);
lean_dec(v_xs_523_);
v___x_534_ = l_LeanSort_Direct_Engine_hybrid___redArg(v_inst_520_, v_cmp_521_, v_threshold_522_, v___x_533_);
v___x_535_ = lean_apply_4(v_toBind_528_, lean_box(0), lean_box(0), v___x_534_, v___f_531_);
return v___x_535_;
}
else
{
lean_object* v___x_536_; 
lean_dec(v___x_524_);
lean_dec(v_threshold_522_);
v___x_536_ = l_LeanSort_Direct_Engine_insertion___redArg(v_inst_520_, v_cmp_521_, v_xs_523_);
return v___x_536_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid___redArg___lam__1(lean_object* v_inst_539_, lean_object* v_cmp_540_, lean_object* v___x_541_, lean_object* v_xs_542_, lean_object* v_threshold_543_, lean_object* v_toBind_544_, lean_object* v_left_545_){
_start:
{
lean_object* v___f_546_; lean_object* v___x_547_; lean_object* v___x_548_; lean_object* v___x_549_; 
lean_inc(v_cmp_540_);
lean_inc_ref(v_inst_539_);
v___f_546_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_mergeSort___redArg___lam__0), 4, 3);
lean_closure_set(v___f_546_, 0, v_inst_539_);
lean_closure_set(v___f_546_, 1, v_cmp_540_);
lean_closure_set(v___f_546_, 2, v_left_545_);
v___x_547_ = l_List_drop___redArg(v___x_541_, v_xs_542_);
v___x_548_ = l_LeanSort_Direct_Engine_hybrid___redArg(v_inst_539_, v_cmp_540_, v_threshold_543_, v___x_547_);
v___x_549_ = lean_apply_4(v_toBind_544_, lean_box(0), lean_box(0), v___x_548_, v___f_546_);
return v___x_549_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_hybrid(lean_object* v_m_550_, lean_object* v_inst_551_, lean_object* v_00_u03b1_552_, lean_object* v_cmp_553_, lean_object* v_threshold_554_, lean_object* v_xs_555_){
_start:
{
lean_object* v___x_556_; 
v___x_556_ = l_LeanSort_Direct_Engine_hybrid___redArg(v_inst_551_, v_cmp_553_, v_threshold_554_, v_xs_555_);
return v___x_556_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___redArg___lam__0___boxed(lean_object* v_toPure_557_, lean_object* v_inst_558_, lean_object* v_cmp_559_, lean_object* v_tail_560_, lean_object* v_smaller_561_){
_start:
{
uint8_t v_smaller_boxed_562_; lean_object* v_res_563_; 
v_smaller_boxed_562_ = lean_unbox(v_smaller_561_);
v_res_563_ = l_LeanSort_Direct_Engine_checkSorted___redArg___lam__0(v_toPure_557_, v_inst_558_, v_cmp_559_, v_tail_560_, v_smaller_boxed_562_);
return v_res_563_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___redArg(lean_object* v_inst_564_, lean_object* v_cmp_565_, lean_object* v_x_566_){
_start:
{
if (lean_obj_tag(v_x_566_) == 0)
{
lean_object* v_toApplicative_567_; lean_object* v_toPure_568_; uint8_t v___x_569_; lean_object* v___x_570_; lean_object* v___x_571_; 
v_toApplicative_567_ = lean_ctor_get(v_inst_564_, 0);
lean_inc_ref(v_toApplicative_567_);
lean_dec(v_cmp_565_);
lean_dec_ref(v_inst_564_);
v_toPure_568_ = lean_ctor_get(v_toApplicative_567_, 1);
lean_inc(v_toPure_568_);
lean_dec_ref(v_toApplicative_567_);
v___x_569_ = 1;
v___x_570_ = lean_box(v___x_569_);
v___x_571_ = lean_apply_2(v_toPure_568_, lean_box(0), v___x_570_);
return v___x_571_;
}
else
{
lean_object* v_toApplicative_572_; lean_object* v_tail_573_; 
v_toApplicative_572_ = lean_ctor_get(v_inst_564_, 0);
v_tail_573_ = lean_ctor_get(v_x_566_, 1);
lean_inc(v_tail_573_);
if (lean_obj_tag(v_tail_573_) == 0)
{
lean_object* v_toPure_574_; uint8_t v___x_575_; lean_object* v___x_576_; lean_object* v___x_577_; 
lean_inc_ref(v_toApplicative_572_);
lean_dec_ref_known(v_x_566_, 2);
lean_dec(v_cmp_565_);
lean_dec_ref(v_inst_564_);
v_toPure_574_ = lean_ctor_get(v_toApplicative_572_, 1);
lean_inc(v_toPure_574_);
lean_dec_ref(v_toApplicative_572_);
v___x_575_ = 1;
v___x_576_ = lean_box(v___x_575_);
v___x_577_ = lean_apply_2(v_toPure_574_, lean_box(0), v___x_576_);
return v___x_577_;
}
else
{
lean_object* v_toBind_578_; lean_object* v_toPure_579_; lean_object* v_head_580_; lean_object* v_head_581_; lean_object* v___f_582_; uint8_t v___x_583_; lean_object* v___x_584_; lean_object* v___x_585_; lean_object* v___x_586_; 
v_toBind_578_ = lean_ctor_get(v_inst_564_, 1);
lean_inc(v_toBind_578_);
v_toPure_579_ = lean_ctor_get(v_toApplicative_572_, 1);
lean_inc(v_toPure_579_);
v_head_580_ = lean_ctor_get(v_x_566_, 0);
lean_inc(v_head_580_);
lean_dec_ref_known(v_x_566_, 2);
v_head_581_ = lean_ctor_get(v_tail_573_, 0);
lean_inc(v_head_581_);
lean_inc(v_cmp_565_);
v___f_582_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_checkSorted___redArg___lam__0___boxed), 5, 4);
lean_closure_set(v___f_582_, 0, v_toPure_579_);
lean_closure_set(v___f_582_, 1, v_inst_564_);
lean_closure_set(v___f_582_, 2, v_cmp_565_);
lean_closure_set(v___f_582_, 3, v_tail_573_);
v___x_583_ = 0;
v___x_584_ = lean_box(v___x_583_);
v___x_585_ = lean_apply_3(v_cmp_565_, v___x_584_, v_head_580_, v_head_581_);
v___x_586_ = lean_apply_4(v_toBind_578_, lean_box(0), lean_box(0), v___x_585_, v___f_582_);
return v___x_586_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted___redArg___lam__0(lean_object* v_toPure_587_, lean_object* v_inst_588_, lean_object* v_cmp_589_, lean_object* v_tail_590_, uint8_t v_smaller_591_){
_start:
{
if (v_smaller_591_ == 0)
{
lean_object* v___x_592_; lean_object* v___x_593_; 
lean_dec(v_tail_590_);
lean_dec(v_cmp_589_);
lean_dec_ref(v_inst_588_);
v___x_592_ = lean_box(v_smaller_591_);
v___x_593_ = lean_apply_2(v_toPure_587_, lean_box(0), v___x_592_);
return v___x_593_;
}
else
{
lean_object* v___x_594_; 
lean_dec(v_toPure_587_);
v___x_594_ = l_LeanSort_Direct_Engine_checkSorted___redArg(v_inst_588_, v_cmp_589_, v_tail_590_);
return v___x_594_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_checkSorted(lean_object* v_m_595_, lean_object* v_inst_596_, lean_object* v_00_u03b1_597_, lean_object* v_cmp_598_, lean_object* v_x_599_){
_start:
{
lean_object* v___x_600_; 
v___x_600_ = l_LeanSort_Direct_Engine_checkSorted___redArg(v_inst_596_, v_cmp_598_, v_x_599_);
return v___x_600_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component___redArg(lean_object* v_inst_601_, lean_object* v_cmp_602_, lean_object* v_x_603_, lean_object* v_x_604_){
_start:
{
switch(lean_obj_tag(v_x_603_))
{
case 0:
{
lean_object* v___x_605_; 
v___x_605_ = l_LeanSort_Direct_Engine_mergeSort___redArg(v_inst_601_, v_cmp_602_, v_x_604_);
return v___x_605_;
}
case 1:
{
lean_object* v___x_606_; 
v___x_606_ = l_LeanSort_Direct_Engine_insertion___redArg(v_inst_601_, v_cmp_602_, v_x_604_);
return v___x_606_;
}
default: 
{
lean_object* v_threshold_607_; lean_object* v___x_608_; 
v_threshold_607_ = lean_ctor_get(v_x_603_, 0);
lean_inc(v_threshold_607_);
lean_dec_ref_known(v_x_603_, 1);
v___x_608_ = l_LeanSort_Direct_Engine_hybrid___redArg(v_inst_601_, v_cmp_602_, v_threshold_607_, v_x_604_);
return v___x_608_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_component(lean_object* v_m_609_, lean_object* v_inst_610_, lean_object* v_00_u03b1_611_, lean_object* v_cmp_612_, lean_object* v_x_613_, lean_object* v_x_614_){
_start:
{
lean_object* v___x_615_; 
v___x_615_ = l_LeanSort_Direct_Engine_component___redArg(v_inst_610_, v_cmp_612_, v_x_613_, v_x_614_);
return v___x_615_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___redArg___lam__0(lean_object* v_inst_616_, lean_object* v_cmp_617_, lean_object* v_ls_618_, lean_object* v_rs_619_){
_start:
{
lean_object* v___x_620_; 
v___x_620_ = l_LeanSort_Direct_Engine_merge___redArg(v_inst_616_, v_cmp_617_, v_ls_618_, v_rs_619_);
return v___x_620_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___redArg___lam__1___boxed(lean_object* v_inst_621_, lean_object* v_cmp_622_, lean_object* v___x_623_, lean_object* v_x_624_, lean_object* v_right_625_, lean_object* v_toBind_626_, lean_object* v_ls_627_){
_start:
{
lean_object* v_res_628_; 
v_res_628_ = l_LeanSort_Direct_Engine_schema___redArg___lam__1(v_inst_621_, v_cmp_622_, v___x_623_, v_x_624_, v_right_625_, v_toBind_626_, v_ls_627_);
lean_dec(v_x_624_);
return v_res_628_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___redArg___lam__2(lean_object* v_inst_629_, lean_object* v_cmp_630_, lean_object* v_fallback_631_, lean_object* v_x_632_, lean_object* v_toApplicative_633_, uint8_t v_sorted_634_){
_start:
{
if (v_sorted_634_ == 0)
{
lean_object* v___x_635_; 
lean_dec_ref(v_toApplicative_633_);
v___x_635_ = l_LeanSort_Direct_Engine_schema___redArg(v_inst_629_, v_cmp_630_, v_fallback_631_, v_x_632_);
return v___x_635_;
}
else
{
lean_object* v_toPure_636_; lean_object* v___x_637_; 
lean_dec_ref(v_fallback_631_);
lean_dec(v_cmp_630_);
lean_dec_ref(v_inst_629_);
v_toPure_636_ = lean_ctor_get(v_toApplicative_633_, 1);
lean_inc(v_toPure_636_);
lean_dec_ref(v_toApplicative_633_);
v___x_637_ = lean_apply_2(v_toPure_636_, lean_box(0), v_x_632_);
return v___x_637_;
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___redArg___lam__2___boxed(lean_object* v_inst_638_, lean_object* v_cmp_639_, lean_object* v_fallback_640_, lean_object* v_x_641_, lean_object* v_toApplicative_642_, lean_object* v_sorted_643_){
_start:
{
uint8_t v_sorted_boxed_644_; lean_object* v_res_645_; 
v_sorted_boxed_644_ = lean_unbox(v_sorted_643_);
v_res_645_ = l_LeanSort_Direct_Engine_schema___redArg___lam__2(v_inst_638_, v_cmp_639_, v_fallback_640_, v_x_641_, v_toApplicative_642_, v_sorted_boxed_644_);
return v_res_645_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___redArg(lean_object* v_inst_646_, lean_object* v_cmp_647_, lean_object* v_x_648_, lean_object* v_x_649_){
_start:
{
switch(lean_obj_tag(v_x_648_))
{
case 0:
{
lean_object* v_component_650_; lean_object* v___x_651_; 
v_component_650_ = lean_ctor_get(v_x_648_, 0);
lean_inc(v_component_650_);
lean_dec_ref_known(v_x_648_, 1);
v___x_651_ = l_LeanSort_Direct_Engine_component___redArg(v_inst_646_, v_cmp_647_, v_component_650_, v_x_649_);
return v___x_651_;
}
case 1:
{
lean_object* v_toBind_652_; lean_object* v_cut_653_; lean_object* v_left_654_; lean_object* v_right_655_; lean_object* v___x_656_; lean_object* v___x_657_; lean_object* v___f_658_; lean_object* v___x_659_; lean_object* v___x_660_; lean_object* v___x_661_; lean_object* v___x_662_; 
v_toBind_652_ = lean_ctor_get(v_inst_646_, 1);
lean_inc_n(v_toBind_652_, 2);
v_cut_653_ = lean_ctor_get(v_x_648_, 0);
lean_inc_ref(v_cut_653_);
v_left_654_ = lean_ctor_get(v_x_648_, 1);
lean_inc_ref(v_left_654_);
v_right_655_ = lean_ctor_get(v_x_648_, 2);
lean_inc_ref(v_right_655_);
lean_dec_ref_known(v_x_648_, 3);
v___x_656_ = l_List_lengthTR___redArg(v_x_649_);
v___x_657_ = lp_leansort_LeanSort_CostedPlan_Cut_position(v_cut_653_, v___x_656_);
lean_dec(v___x_656_);
lean_dec_ref(v_cut_653_);
lean_inc_n(v_x_649_, 2);
lean_inc(v___x_657_);
lean_inc(v_cmp_647_);
lean_inc_ref(v_inst_646_);
v___f_658_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___redArg___lam__1___boxed), 7, 6);
lean_closure_set(v___f_658_, 0, v_inst_646_);
lean_closure_set(v___f_658_, 1, v_cmp_647_);
lean_closure_set(v___f_658_, 2, v___x_657_);
lean_closure_set(v___f_658_, 3, v_x_649_);
lean_closure_set(v___f_658_, 4, v_right_655_);
lean_closure_set(v___f_658_, 5, v_toBind_652_);
v___x_659_ = ((lean_object*)(l_LeanSort_Direct_Engine_mergeSort___redArg___closed__0));
v___x_660_ = l___private_Init_Data_List_Impl_0__List_takeTR_go___redArg(v_x_649_, v_x_649_, v___x_657_, v___x_659_);
lean_dec(v_x_649_);
v___x_661_ = l_LeanSort_Direct_Engine_schema___redArg(v_inst_646_, v_cmp_647_, v_left_654_, v___x_660_);
v___x_662_ = lean_apply_4(v_toBind_652_, lean_box(0), lean_box(0), v___x_661_, v___f_658_);
return v___x_662_;
}
default: 
{
lean_object* v_toApplicative_663_; lean_object* v_toBind_664_; lean_object* v_fallback_665_; lean_object* v___f_666_; lean_object* v___x_667_; lean_object* v___x_668_; 
v_toApplicative_663_ = lean_ctor_get(v_inst_646_, 0);
v_toBind_664_ = lean_ctor_get(v_inst_646_, 1);
lean_inc(v_toBind_664_);
v_fallback_665_ = lean_ctor_get(v_x_648_, 0);
lean_inc_ref(v_fallback_665_);
lean_dec_ref_known(v_x_648_, 1);
lean_inc_ref(v_toApplicative_663_);
lean_inc(v_x_649_);
lean_inc(v_cmp_647_);
lean_inc_ref(v_inst_646_);
v___f_666_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___redArg___lam__2___boxed), 6, 5);
lean_closure_set(v___f_666_, 0, v_inst_646_);
lean_closure_set(v___f_666_, 1, v_cmp_647_);
lean_closure_set(v___f_666_, 2, v_fallback_665_);
lean_closure_set(v___f_666_, 3, v_x_649_);
lean_closure_set(v___f_666_, 4, v_toApplicative_663_);
v___x_667_ = l_LeanSort_Direct_Engine_checkSorted___redArg(v_inst_646_, v_cmp_647_, v_x_649_);
v___x_668_ = lean_apply_4(v_toBind_664_, lean_box(0), lean_box(0), v___x_667_, v___f_666_);
return v___x_668_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema___redArg___lam__1(lean_object* v_inst_669_, lean_object* v_cmp_670_, lean_object* v___x_671_, lean_object* v_x_672_, lean_object* v_right_673_, lean_object* v_toBind_674_, lean_object* v_ls_675_){
_start:
{
lean_object* v___f_676_; lean_object* v___x_677_; lean_object* v___x_678_; lean_object* v___x_679_; 
lean_inc(v_cmp_670_);
lean_inc_ref(v_inst_669_);
v___f_676_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___redArg___lam__0), 4, 3);
lean_closure_set(v___f_676_, 0, v_inst_669_);
lean_closure_set(v___f_676_, 1, v_cmp_670_);
lean_closure_set(v___f_676_, 2, v_ls_675_);
v___x_677_ = l_List_drop___redArg(v___x_671_, v_x_672_);
v___x_678_ = l_LeanSort_Direct_Engine_schema___redArg(v_inst_669_, v_cmp_670_, v_right_673_, v___x_677_);
v___x_679_ = lean_apply_4(v_toBind_674_, lean_box(0), lean_box(0), v___x_678_, v___f_676_);
return v___x_679_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_schema(lean_object* v_m_680_, lean_object* v_inst_681_, lean_object* v_00_u03b1_682_, lean_object* v_cmp_683_, lean_object* v_x_684_, lean_object* v_x_685_){
_start:
{
lean_object* v___x_686_; 
v___x_686_ = l_LeanSort_Direct_Engine_schema___redArg(v_inst_681_, v_cmp_683_, v_x_684_, v_x_685_);
return v___x_686_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___redArg(lean_object* v_inst_687_, lean_object* v_cmp_688_, lean_object* v_x_689_){
_start:
{
switch(lean_obj_tag(v_x_689_))
{
case 0:
{
lean_object* v_toApplicative_690_; lean_object* v_toPure_691_; lean_object* v___x_692_; lean_object* v___x_693_; 
v_toApplicative_690_ = lean_ctor_get(v_inst_687_, 0);
lean_inc_ref(v_toApplicative_690_);
lean_dec(v_cmp_688_);
lean_dec_ref(v_inst_687_);
v_toPure_691_ = lean_ctor_get(v_toApplicative_690_, 1);
lean_inc(v_toPure_691_);
lean_dec_ref(v_toApplicative_690_);
v___x_692_ = lean_box(0);
v___x_693_ = lean_apply_2(v_toPure_691_, lean_box(0), v___x_692_);
return v___x_693_;
}
case 1:
{
lean_object* v_toApplicative_694_; lean_object* v_toPure_695_; lean_object* v_run_696_; lean_object* v___x_697_; 
v_toApplicative_694_ = lean_ctor_get(v_inst_687_, 0);
lean_inc_ref(v_toApplicative_694_);
lean_dec(v_cmp_688_);
lean_dec_ref(v_inst_687_);
v_toPure_695_ = lean_ctor_get(v_toApplicative_694_, 1);
lean_inc(v_toPure_695_);
lean_dec_ref(v_toApplicative_694_);
v_run_696_ = lean_ctor_get(v_x_689_, 0);
lean_inc(v_run_696_);
lean_dec_ref_known(v_x_689_, 1);
v___x_697_ = lean_apply_2(v_toPure_695_, lean_box(0), v_run_696_);
return v___x_697_;
}
default: 
{
lean_object* v_toBind_698_; lean_object* v_left_699_; lean_object* v_right_700_; lean_object* v___f_701_; lean_object* v___x_702_; lean_object* v___x_703_; 
v_toBind_698_ = lean_ctor_get(v_inst_687_, 1);
lean_inc_n(v_toBind_698_, 2);
v_left_699_ = lean_ctor_get(v_x_689_, 0);
lean_inc(v_left_699_);
v_right_700_ = lean_ctor_get(v_x_689_, 1);
lean_inc(v_right_700_);
lean_dec_ref_known(v_x_689_, 2);
lean_inc(v_cmp_688_);
lean_inc_ref(v_inst_687_);
v___f_701_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_tree___redArg___lam__1), 5, 4);
lean_closure_set(v___f_701_, 0, v_inst_687_);
lean_closure_set(v___f_701_, 1, v_cmp_688_);
lean_closure_set(v___f_701_, 2, v_right_700_);
lean_closure_set(v___f_701_, 3, v_toBind_698_);
v___x_702_ = l_LeanSort_Direct_Engine_tree___redArg(v_inst_687_, v_cmp_688_, v_left_699_);
v___x_703_ = lean_apply_4(v_toBind_698_, lean_box(0), lean_box(0), v___x_702_, v___f_701_);
return v___x_703_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree___redArg___lam__1(lean_object* v_inst_704_, lean_object* v_cmp_705_, lean_object* v_right_706_, lean_object* v_toBind_707_, lean_object* v_ls_708_){
_start:
{
lean_object* v___f_709_; lean_object* v___x_710_; lean_object* v___x_711_; 
lean_inc(v_cmp_705_);
lean_inc_ref(v_inst_704_);
v___f_709_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_schema___redArg___lam__0), 4, 3);
lean_closure_set(v___f_709_, 0, v_inst_704_);
lean_closure_set(v___f_709_, 1, v_cmp_705_);
lean_closure_set(v___f_709_, 2, v_ls_708_);
v___x_710_ = l_LeanSort_Direct_Engine_tree___redArg(v_inst_704_, v_cmp_705_, v_right_706_);
v___x_711_ = lean_apply_4(v_toBind_707_, lean_box(0), lean_box(0), v___x_710_, v___f_709_);
return v___x_711_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_tree(lean_object* v_m_712_, lean_object* v_inst_713_, lean_object* v_00_u03b1_714_, lean_object* v_cmp_715_, lean_object* v_x_716_){
_start:
{
lean_object* v___x_717_; 
v___x_717_ = l_LeanSort_Direct_Engine_tree___redArg(v_inst_713_, v_cmp_715_, v_x_716_);
return v___x_717_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___redArg___lam__0(lean_object* v_planner_718_, lean_object* v_inst_719_, lean_object* v_cmp_720_, lean_object* v_runs_721_){
_start:
{
lean_object* v___x_722_; lean_object* v___x_723_; 
v___x_722_ = lean_apply_1(v_planner_718_, v_runs_721_);
v___x_723_ = l_LeanSort_Direct_Engine_tree___redArg(v_inst_719_, v_cmp_720_, v___x_722_);
return v___x_723_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive___redArg(lean_object* v_inst_724_, lean_object* v_cmp_725_, lean_object* v_planner_726_, lean_object* v_xs_727_){
_start:
{
lean_object* v_toBind_728_; lean_object* v___f_729_; lean_object* v___x_730_; lean_object* v___x_731_; 
v_toBind_728_ = lean_ctor_get(v_inst_724_, 1);
lean_inc(v_toBind_728_);
lean_inc(v_cmp_725_);
lean_inc_ref(v_inst_724_);
v___f_729_ = lean_alloc_closure((void*)(l_LeanSort_Direct_Engine_adaptive___redArg___lam__0), 4, 3);
lean_closure_set(v___f_729_, 0, v_planner_726_);
lean_closure_set(v___f_729_, 1, v_inst_724_);
lean_closure_set(v___f_729_, 2, v_cmp_725_);
v___x_730_ = l_LeanSort_Direct_Engine_discover___redArg(v_inst_724_, v_cmp_725_, v_xs_727_);
v___x_731_ = lean_apply_4(v_toBind_728_, lean_box(0), lean_box(0), v___x_730_, v___f_729_);
return v___x_731_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_adaptive(lean_object* v_m_732_, lean_object* v_inst_733_, lean_object* v_00_u03b1_734_, lean_object* v_cmp_735_, lean_object* v_planner_736_, lean_object* v_xs_737_){
_start:
{
lean_object* v___x_738_; 
v___x_738_ = l_LeanSort_Direct_Engine_adaptive___redArg(v_inst_733_, v_cmp_735_, v_planner_736_, v_xs_737_);
return v___x_738_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy___redArg(lean_object* v_inst_741_, lean_object* v_cmp_742_, lean_object* v_x_743_, lean_object* v_x_744_){
_start:
{
switch(lean_obj_tag(v_x_743_))
{
case 0:
{
lean_object* v_schema_745_; lean_object* v___x_746_; 
v_schema_745_ = lean_ctor_get(v_x_743_, 0);
lean_inc_ref(v_schema_745_);
lean_dec_ref_known(v_x_743_, 1);
v___x_746_ = l_LeanSort_Direct_Engine_schema___redArg(v_inst_741_, v_cmp_742_, v_schema_745_, v_x_744_);
return v___x_746_;
}
case 1:
{
lean_object* v___x_747_; lean_object* v___x_748_; 
v___x_747_ = ((lean_object*)(l_LeanSort_Direct_Engine_strategy___redArg___closed__0));
v___x_748_ = l_LeanSort_Direct_Engine_adaptive___redArg(v_inst_741_, v_cmp_742_, v___x_747_, v_x_744_);
return v___x_748_;
}
default: 
{
lean_object* v___x_749_; lean_object* v___x_750_; 
v___x_749_ = ((lean_object*)(l_LeanSort_Direct_Engine_strategy___redArg___closed__1));
v___x_750_ = l_LeanSort_Direct_Engine_adaptive___redArg(v_inst_741_, v_cmp_742_, v___x_749_, v_x_744_);
return v___x_750_;
}
}
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_Engine_strategy(lean_object* v_m_751_, lean_object* v_inst_752_, lean_object* v_00_u03b1_753_, lean_object* v_cmp_754_, lean_object* v_x_755_, lean_object* v_x_756_){
_start:
{
lean_object* v___x_757_; 
v___x_757_ = l_LeanSort_Direct_Engine_strategy___redArg(v_inst_752_, v_cmp_754_, v_x_755_, v_x_756_);
return v___x_757_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_leansort_LeanSort_Algorithm_RunStrategy(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_LeanSort_Algorithm_Direct_Engine(uint8_t builtin) {
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
res = initialize_leansort_LeanSort_Algorithm_RunStrategy(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
