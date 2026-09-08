// Lean compiler output
// Module: LeanSort.Algorithm.Direct.Executor
// Imports: public import Init public meta import Init public import LeanSort.Algorithm.Direct.Engine
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
lean_object* l_Id_instMonad___lam__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Id_instMonad___lam__5___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Id_instMonad___lam__6(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Id_instMonad___lam__4___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Id_instMonad___lam__3(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Id_instMonad___lam__2___boxed(lean_object*, lean_object*);
lean_object* l_Id_instMonad___lam__0(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_LeanSort_Direct_plainCompare___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_LeanSort_Direct_Engine_tree___redArg(lean_object*, lean_object*, lean_object*);
lean_object* l_LeanSort_Direct_Engine_discover___redArg(lean_object*, lean_object*, lean_object*);
extern lean_object* lp_mathlib_Nat_instAddCancelCommMonoid;
lean_object* lp_mathlib_AddMonoid_toAddZeroClass___redArg(lean_object*);
lean_object* lp_mathlib_AddZeroClass_toAddZero___redArg(lean_object*);
lean_object* lp_cslib_Cslib_Algorithms_Lean_TimeM_instMonadOfAddZero___redArg(lean_object*);
lean_object* l_LeanSort_Direct_countedCompare___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_LeanSort_Direct_Engine_merge___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_LeanSort_Direct_Engine_strategy___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
static const lean_closure_object l_LeanSort_Direct_scan___redArg___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Id_instMonad___lam__0, .m_arity = 4, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_scan___redArg___closed__0 = (const lean_object*)&l_LeanSort_Direct_scan___redArg___closed__0_value;
static const lean_closure_object l_LeanSort_Direct_scan___redArg___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Id_instMonad___lam__1___boxed, .m_arity = 4, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_scan___redArg___closed__1 = (const lean_object*)&l_LeanSort_Direct_scan___redArg___closed__1_value;
static const lean_closure_object l_LeanSort_Direct_scan___redArg___closed__2_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Id_instMonad___lam__2___boxed, .m_arity = 2, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_scan___redArg___closed__2 = (const lean_object*)&l_LeanSort_Direct_scan___redArg___closed__2_value;
static const lean_closure_object l_LeanSort_Direct_scan___redArg___closed__3_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Id_instMonad___lam__3, .m_arity = 4, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_scan___redArg___closed__3 = (const lean_object*)&l_LeanSort_Direct_scan___redArg___closed__3_value;
static const lean_closure_object l_LeanSort_Direct_scan___redArg___closed__4_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Id_instMonad___lam__4___boxed, .m_arity = 4, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_scan___redArg___closed__4 = (const lean_object*)&l_LeanSort_Direct_scan___redArg___closed__4_value;
static const lean_closure_object l_LeanSort_Direct_scan___redArg___closed__5_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Id_instMonad___lam__5___boxed, .m_arity = 4, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_scan___redArg___closed__5 = (const lean_object*)&l_LeanSort_Direct_scan___redArg___closed__5_value;
static const lean_closure_object l_LeanSort_Direct_scan___redArg___closed__6_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_closure_object) + sizeof(void*)*0, .m_other = 0, .m_tag = 245}, .m_fun = (void*)l_Id_instMonad___lam__6, .m_arity = 4, .m_num_fixed = 0, .m_objs = {} };
static const lean_object* l_LeanSort_Direct_scan___redArg___closed__6 = (const lean_object*)&l_LeanSort_Direct_scan___redArg___closed__6_value;
static const lean_ctor_object l_LeanSort_Direct_scan___redArg___closed__7_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_LeanSort_Direct_scan___redArg___closed__0_value),((lean_object*)&l_LeanSort_Direct_scan___redArg___closed__1_value)}};
static const lean_object* l_LeanSort_Direct_scan___redArg___closed__7 = (const lean_object*)&l_LeanSort_Direct_scan___redArg___closed__7_value;
static const lean_ctor_object l_LeanSort_Direct_scan___redArg___closed__8_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*5 + 0, .m_other = 5, .m_tag = 0}, .m_objs = {((lean_object*)&l_LeanSort_Direct_scan___redArg___closed__7_value),((lean_object*)&l_LeanSort_Direct_scan___redArg___closed__2_value),((lean_object*)&l_LeanSort_Direct_scan___redArg___closed__3_value),((lean_object*)&l_LeanSort_Direct_scan___redArg___closed__4_value),((lean_object*)&l_LeanSort_Direct_scan___redArg___closed__5_value)}};
static const lean_object* l_LeanSort_Direct_scan___redArg___closed__8 = (const lean_object*)&l_LeanSort_Direct_scan___redArg___closed__8_value;
static const lean_ctor_object l_LeanSort_Direct_scan___redArg___closed__9_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)&l_LeanSort_Direct_scan___redArg___closed__8_value),((lean_object*)&l_LeanSort_Direct_scan___redArg___closed__6_value)}};
static const lean_object* l_LeanSort_Direct_scan___redArg___closed__9 = (const lean_object*)&l_LeanSort_Direct_scan___redArg___closed__9_value;
LEAN_EXPORT lean_object* l_LeanSort_Direct_scan___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_scan(lean_object*, lean_object*, lean_object*);
static lean_once_cell_t l_LeanSort_Direct_scanCounted___redArg___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LeanSort_Direct_scanCounted___redArg___closed__0;
static lean_once_cell_t l_LeanSort_Direct_scanCounted___redArg___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LeanSort_Direct_scanCounted___redArg___closed__1;
static lean_once_cell_t l_LeanSort_Direct_scanCounted___redArg___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* l_LeanSort_Direct_scanCounted___redArg___closed__2;
LEAN_EXPORT lean_object* l_LeanSort_Direct_scanCounted___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_scanCounted(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_merge___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_merge(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_mergeCounted___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_mergeCounted(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_tree___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_tree(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_treeCounted___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_treeCounted(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_run___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_run(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_runCounted___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_runCounted(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* l_LeanSort_Direct_scan___redArg(lean_object* v_inst_20_, lean_object* v_xs_21_){
_start:
{
lean_object* v___x_22_; lean_object* v___x_23_; lean_object* v___x_24_; 
v___x_22_ = ((lean_object*)(l_LeanSort_Direct_scan___redArg___closed__9));
v___x_23_ = lean_alloc_closure((void*)(l_LeanSort_Direct_plainCompare___boxed), 5, 2);
lean_closure_set(v___x_23_, 0, lean_box(0));
lean_closure_set(v___x_23_, 1, v_inst_20_);
v___x_24_ = l_LeanSort_Direct_Engine_discover___redArg(v___x_22_, v___x_23_, v_xs_21_);
return v___x_24_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_scan(lean_object* v_00_u03b1_25_, lean_object* v_inst_26_, lean_object* v_xs_27_){
_start:
{
lean_object* v___x_28_; 
v___x_28_ = l_LeanSort_Direct_scan___redArg(v_inst_26_, v_xs_27_);
return v___x_28_;
}
}
static lean_object* _init_l_LeanSort_Direct_scanCounted___redArg___closed__0(void){
_start:
{
lean_object* v___x_29_; lean_object* v___x_30_; 
v___x_29_ = lp_mathlib_Nat_instAddCancelCommMonoid;
v___x_30_ = lp_mathlib_AddMonoid_toAddZeroClass___redArg(v___x_29_);
return v___x_30_;
}
}
static lean_object* _init_l_LeanSort_Direct_scanCounted___redArg___closed__1(void){
_start:
{
lean_object* v___x_31_; lean_object* v___x_32_; 
v___x_31_ = lean_obj_once(&l_LeanSort_Direct_scanCounted___redArg___closed__0, &l_LeanSort_Direct_scanCounted___redArg___closed__0_once, _init_l_LeanSort_Direct_scanCounted___redArg___closed__0);
v___x_32_ = lp_mathlib_AddZeroClass_toAddZero___redArg(v___x_31_);
return v___x_32_;
}
}
static lean_object* _init_l_LeanSort_Direct_scanCounted___redArg___closed__2(void){
_start:
{
lean_object* v___x_33_; lean_object* v___x_34_; 
v___x_33_ = lean_obj_once(&l_LeanSort_Direct_scanCounted___redArg___closed__1, &l_LeanSort_Direct_scanCounted___redArg___closed__1_once, _init_l_LeanSort_Direct_scanCounted___redArg___closed__1);
v___x_34_ = lp_cslib_Cslib_Algorithms_Lean_TimeM_instMonadOfAddZero___redArg(v___x_33_);
return v___x_34_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_scanCounted___redArg(lean_object* v_inst_35_, lean_object* v_xs_36_){
_start:
{
lean_object* v___x_37_; lean_object* v___x_38_; lean_object* v___x_39_; 
v___x_37_ = lean_obj_once(&l_LeanSort_Direct_scanCounted___redArg___closed__2, &l_LeanSort_Direct_scanCounted___redArg___closed__2_once, _init_l_LeanSort_Direct_scanCounted___redArg___closed__2);
v___x_38_ = lean_alloc_closure((void*)(l_LeanSort_Direct_countedCompare___boxed), 5, 2);
lean_closure_set(v___x_38_, 0, lean_box(0));
lean_closure_set(v___x_38_, 1, v_inst_35_);
v___x_39_ = l_LeanSort_Direct_Engine_discover___redArg(v___x_37_, v___x_38_, v_xs_36_);
return v___x_39_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_scanCounted(lean_object* v_00_u03b1_40_, lean_object* v_inst_41_, lean_object* v_xs_42_){
_start:
{
lean_object* v___x_43_; 
v___x_43_ = l_LeanSort_Direct_scanCounted___redArg(v_inst_41_, v_xs_42_);
return v___x_43_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_merge___redArg(lean_object* v_inst_44_, lean_object* v_xs_45_, lean_object* v_ys_46_){
_start:
{
lean_object* v___x_47_; lean_object* v___x_48_; lean_object* v___x_49_; 
v___x_47_ = ((lean_object*)(l_LeanSort_Direct_scan___redArg___closed__9));
v___x_48_ = lean_alloc_closure((void*)(l_LeanSort_Direct_plainCompare___boxed), 5, 2);
lean_closure_set(v___x_48_, 0, lean_box(0));
lean_closure_set(v___x_48_, 1, v_inst_44_);
v___x_49_ = l_LeanSort_Direct_Engine_merge___redArg(v___x_47_, v___x_48_, v_xs_45_, v_ys_46_);
return v___x_49_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_merge(lean_object* v_00_u03b1_50_, lean_object* v_inst_51_, lean_object* v_xs_52_, lean_object* v_ys_53_){
_start:
{
lean_object* v___x_54_; 
v___x_54_ = l_LeanSort_Direct_merge___redArg(v_inst_51_, v_xs_52_, v_ys_53_);
return v___x_54_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_mergeCounted___redArg(lean_object* v_inst_55_, lean_object* v_xs_56_, lean_object* v_ys_57_){
_start:
{
lean_object* v___x_58_; lean_object* v___x_59_; lean_object* v___x_60_; 
v___x_58_ = lean_obj_once(&l_LeanSort_Direct_scanCounted___redArg___closed__2, &l_LeanSort_Direct_scanCounted___redArg___closed__2_once, _init_l_LeanSort_Direct_scanCounted___redArg___closed__2);
v___x_59_ = lean_alloc_closure((void*)(l_LeanSort_Direct_countedCompare___boxed), 5, 2);
lean_closure_set(v___x_59_, 0, lean_box(0));
lean_closure_set(v___x_59_, 1, v_inst_55_);
v___x_60_ = l_LeanSort_Direct_Engine_merge___redArg(v___x_58_, v___x_59_, v_xs_56_, v_ys_57_);
return v___x_60_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_mergeCounted(lean_object* v_00_u03b1_61_, lean_object* v_inst_62_, lean_object* v_xs_63_, lean_object* v_ys_64_){
_start:
{
lean_object* v___x_65_; 
v___x_65_ = l_LeanSort_Direct_mergeCounted___redArg(v_inst_62_, v_xs_63_, v_ys_64_);
return v___x_65_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_tree___redArg(lean_object* v_inst_66_, lean_object* v_t_67_){
_start:
{
lean_object* v___x_68_; lean_object* v___x_69_; lean_object* v___x_70_; 
v___x_68_ = ((lean_object*)(l_LeanSort_Direct_scan___redArg___closed__9));
v___x_69_ = lean_alloc_closure((void*)(l_LeanSort_Direct_plainCompare___boxed), 5, 2);
lean_closure_set(v___x_69_, 0, lean_box(0));
lean_closure_set(v___x_69_, 1, v_inst_66_);
v___x_70_ = l_LeanSort_Direct_Engine_tree___redArg(v___x_68_, v___x_69_, v_t_67_);
return v___x_70_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_tree(lean_object* v_00_u03b1_71_, lean_object* v_inst_72_, lean_object* v_t_73_){
_start:
{
lean_object* v___x_74_; 
v___x_74_ = l_LeanSort_Direct_tree___redArg(v_inst_72_, v_t_73_);
return v___x_74_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_treeCounted___redArg(lean_object* v_inst_75_, lean_object* v_t_76_){
_start:
{
lean_object* v___x_77_; lean_object* v___x_78_; lean_object* v___x_79_; 
v___x_77_ = lean_obj_once(&l_LeanSort_Direct_scanCounted___redArg___closed__2, &l_LeanSort_Direct_scanCounted___redArg___closed__2_once, _init_l_LeanSort_Direct_scanCounted___redArg___closed__2);
v___x_78_ = lean_alloc_closure((void*)(l_LeanSort_Direct_countedCompare___boxed), 5, 2);
lean_closure_set(v___x_78_, 0, lean_box(0));
lean_closure_set(v___x_78_, 1, v_inst_75_);
v___x_79_ = l_LeanSort_Direct_Engine_tree___redArg(v___x_77_, v___x_78_, v_t_76_);
return v___x_79_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_treeCounted(lean_object* v_00_u03b1_80_, lean_object* v_inst_81_, lean_object* v_t_82_){
_start:
{
lean_object* v___x_83_; 
v___x_83_ = l_LeanSort_Direct_treeCounted___redArg(v_inst_81_, v_t_82_);
return v___x_83_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_run___redArg(lean_object* v_inst_84_, lean_object* v_s_85_, lean_object* v_xs_86_){
_start:
{
lean_object* v___x_87_; lean_object* v___x_88_; lean_object* v___x_89_; 
v___x_87_ = ((lean_object*)(l_LeanSort_Direct_scan___redArg___closed__9));
v___x_88_ = lean_alloc_closure((void*)(l_LeanSort_Direct_plainCompare___boxed), 5, 2);
lean_closure_set(v___x_88_, 0, lean_box(0));
lean_closure_set(v___x_88_, 1, v_inst_84_);
v___x_89_ = l_LeanSort_Direct_Engine_strategy___redArg(v___x_87_, v___x_88_, v_s_85_, v_xs_86_);
return v___x_89_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_run(lean_object* v_00_u03b1_90_, lean_object* v_inst_91_, lean_object* v_s_92_, lean_object* v_xs_93_){
_start:
{
lean_object* v___x_94_; 
v___x_94_ = l_LeanSort_Direct_run___redArg(v_inst_91_, v_s_92_, v_xs_93_);
return v___x_94_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_runCounted___redArg(lean_object* v_inst_95_, lean_object* v_s_96_, lean_object* v_xs_97_){
_start:
{
lean_object* v___x_98_; lean_object* v___x_99_; lean_object* v___x_100_; 
v___x_98_ = lean_obj_once(&l_LeanSort_Direct_scanCounted___redArg___closed__2, &l_LeanSort_Direct_scanCounted___redArg___closed__2_once, _init_l_LeanSort_Direct_scanCounted___redArg___closed__2);
v___x_99_ = lean_alloc_closure((void*)(l_LeanSort_Direct_countedCompare___boxed), 5, 2);
lean_closure_set(v___x_99_, 0, lean_box(0));
lean_closure_set(v___x_99_, 1, v_inst_95_);
v___x_100_ = l_LeanSort_Direct_Engine_strategy___redArg(v___x_98_, v___x_99_, v_s_96_, v_xs_97_);
return v___x_100_;
}
}
LEAN_EXPORT lean_object* l_LeanSort_Direct_runCounted(lean_object* v_00_u03b1_101_, lean_object* v_inst_102_, lean_object* v_s_103_, lean_object* v_xs_104_){
_start:
{
lean_object* v___x_105_; 
v___x_105_ = l_LeanSort_Direct_runCounted___redArg(v_inst_102_, v_s_103_, v_xs_104_);
return v___x_105_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_LeanSort_Algorithm_Direct_Engine(uint8_t builtin);
void lean_initialize();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_LeanSort_Algorithm_Direct_Executor(uint8_t builtin) {
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
res = initialize_LeanSort_Algorithm_Direct_Engine(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
