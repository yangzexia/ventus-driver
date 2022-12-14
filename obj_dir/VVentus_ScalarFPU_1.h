// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VVentus.h for the primary calling header

#ifndef VERILATED_VVENTUS_SCALARFPU_1_H_
#define VERILATED_VVENTUS_SCALARFPU_1_H_  // guard

#include "verilated.h"

class VVentus__Syms;
class VVentus_FCMA_ADD_s1;


class VVentus_ScalarFPU_1 final : public VerilatedModule {
  public:
    // CELLS
    VVentus_FCMA_ADD_s1* __PVT__FMA__DOT__addPipe__DOT__s1;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(__PVT__clock,0,0);
        VL_IN8(__PVT__reset,0,0);
        VL_IN8(__PVT__io_in_valid,0,0);
        VL_IN8(__PVT__io_in_bits_op,5,0);
        VL_IN8(__PVT__io_in_bits_rm,2,0);
        VL_IN8(__PVT__io_out_ready,0,0);
        CData/*0:0*/ __PVT__FMA_io_in_valid;
        CData/*0:0*/ __PVT__FCMP_io_in_valid;
        CData/*0:0*/ __PVT__FCMP_io_out_ready;
        CData/*0:0*/ __PVT__FPMV_io_in_valid;
        CData/*2:0*/ __PVT__FPMV_io_in_bits_op;
        CData/*0:0*/ __PVT__FPMV_io_out_ready;
        CData/*0:0*/ __PVT__FPToInt_io_in_valid;
        CData/*0:0*/ __PVT__FPToInt_io_out_ready;
        CData/*0:0*/ __PVT__IntToFP_io_in_valid;
        CData/*0:0*/ __PVT__IntToFP_io_out_ready;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe_io_in_valid;
        CData/*2:0*/ __PVT__FMA__DOT__mulPipe_io_in_bits_op;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe_io_out_ready;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe_io_in_valid;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe_io_out_ready;
        CData/*0:0*/ __PVT__FMA__DOT__toAddArbiter_io_in_0_valid;
        CData/*0:0*/ __PVT__FMA__DOT__mulFIFO_io_enq_ready;
        CData/*0:0*/ __PVT__FMA__DOT__mulFIFO_io_deq_ready;
        CData/*0:0*/ __PVT__FMA__DOT__toOutArbiter_io_out_valid;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__multiplier_io_regEnables_0;
        CData/*2:0*/ __PVT__FMA__DOT__mulPipe__DOT__s1_io_rm;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__REG;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__REG_1;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s2_io_in_r_special_case_valid;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s2_io_in_r_special_case_bits_nan;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s2_io_in_r_special_case_bits_inf;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s2_io_in_r_special_case_bits_hasZero;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s2_io_in_r_early_overflow;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s2_io_in_r_prod_sign;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s2_io_in_r_may_be_subnormal;
        CData/*2:0*/ __PVT__FMA__DOT__mulPipe__DOT__s2_io_in_r_rm;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT___s3_io_in_T_3;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3_io_in_r_special_case_valid;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3_io_in_r_special_case_bits_nan;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3_io_in_r_special_case_bits_inf;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3_io_in_r_special_case_bits_hasZero;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3_io_in_r_early_overflow;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3_io_in_r_prod_sign;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3_io_in_r_may_be_subnormal;
        CData/*2:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3_io_in_r_rm;
        CData/*2:0*/ __PVT__FMA__DOT__mulPipe__DOT__toAdd_op_r;
        CData/*2:0*/ __PVT__FMA__DOT__mulPipe__DOT__toAdd_op_r_1;
        CData/*7:0*/ __PVT__FMA__DOT__mulPipe__DOT__s1__DOT__fp_a_exp;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s1__DOT__exceed_lim;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s1__DOT__hasZero;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s1__DOT__hasNaN;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s1__DOT__hasInf;
        CData/*5:0*/ __PVT__FMA__DOT__mulPipe__DOT__s1__DOT__lzc_clz__DOT___io_out_T_72;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3__DOT__rounder_io_stickyIn;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3__DOT__rounder_io_cout;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3__DOT__exp_is_subnormal;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3__DOT__no_extra_shift;
        CData/*7:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3__DOT__raw_in_exp;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3__DOT__common_of;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3__DOT__rmin;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3__DOT__tininess_rounder__DOT__rounder__DOT__inexact;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3__DOT__rounder__DOT__inexact;
        CData/*0:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3__DOT__rounder__DOT__r_up;
    };
    struct {
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__REG;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__REG_1;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT___T_2;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__isFMA;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT___s1_io_a_T_4;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s1_io_b_inter_valid_r;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s1_io_b_inter_flags_r_isNaN;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s1_io_b_inter_flags_r_isInf;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s1_io_b_inter_flags_r_overflow;
        CData/*2:0*/ __PVT__FMA__DOT__addPipe__DOT__s1_io_rm_r;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT___s2_io_in_T_3;
        CData/*2:0*/ __PVT__FMA__DOT__addPipe__DOT__s2_io_in_r_rm;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2_io_in_r_far_path_out_sign;
        CData/*7:0*/ __PVT__FMA__DOT__addPipe__DOT__s2_io_in_r_far_path_out_exp;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2_io_in_r_near_path_out_sign;
        CData/*7:0*/ __PVT__FMA__DOT__addPipe__DOT__s2_io_in_r_near_path_out_exp;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2_io_in_r_special_case_valid;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2_io_in_r_special_case_bits_nan;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2_io_in_r_special_case_bits_inf_sign;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2_io_in_r_far_path_mul_of;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2_io_in_r_near_path_sig_is_zero;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2_io_in_r_sel_far_path;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2__DOT__far_path_rounder_io_cout;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2__DOT__near_path_is_zero;
        CData/*7:0*/ __PVT__FMA__DOT__addPipe__DOT__s2__DOT__near_path_exp_rounded;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2__DOT__rmin;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2__DOT__far_path_tininess_rounder__DOT__rounder__DOT__inexact;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2__DOT__far_path_rounder__DOT__inexact;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2__DOT__far_path_rounder__DOT__r_up;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2__DOT__near_path_tininess_rounder__DOT__rounder__DOT__inexact;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2__DOT__near_path_rounder__DOT__inexact;
        CData/*0:0*/ __PVT__FMA__DOT__addPipe__DOT__s2__DOT__near_path_rounder__DOT__r_up;
        CData/*0:0*/ __PVT__FMA__DOT__mulFIFO__DOT__ram_result_MPORT_en;
        CData/*0:0*/ __PVT__FMA__DOT__mulFIFO__DOT__maybe_full;
        CData/*0:0*/ __PVT__FMA__DOT__mulFIFO__DOT__do_deq;
        CData/*0:0*/ __PVT__FMA__DOT__addFIFO__DOT__ram_result_MPORT_en;
        CData/*0:0*/ __PVT__FMA__DOT__addFIFO__DOT__maybe_full;
        CData/*0:0*/ __PVT__FMA__DOT__addFIFO__DOT__do_deq;
        CData/*0:0*/ __PVT__FCMP__DOT__REG;
        CData/*0:0*/ __PVT__FCMP__DOT__REG_1;
        CData/*0:0*/ __PVT__FCMP__DOT___eq_T_4;
        CData/*0:0*/ __PVT__FCMP__DOT__eq;
        CData/*0:0*/ __PVT__FCMP__DOT__le;
        CData/*0:0*/ __PVT__FCMP__DOT__lt;
        CData/*4:0*/ __PVT__FCMP__DOT__fflags;
        CData/*2:0*/ __PVT__FCMP__DOT__op;
        CData/*0:0*/ __PVT__FCMP__DOT__FCMPCore__DOT__fp_a_sign;
        CData/*7:0*/ __PVT__FCMP__DOT__FCMPCore__DOT__fp_a_exp;
        CData/*7:0*/ __PVT__FCMP__DOT__FCMPCore__DOT__fp_b_exp;
        CData/*0:0*/ __PVT__FCMP__DOT__FCMPCore__DOT__decode_a___05FisNaN;
        CData/*0:0*/ __PVT__FCMP__DOT__FCMPCore__DOT__decode_b___05FisNaN;
        CData/*0:0*/ __PVT__FCMP__DOT__FCMPCore__DOT__hasNaN;
        CData/*0:0*/ __PVT__FCMP__DOT__FCMPCore__DOT__bothZero;
        CData/*0:0*/ __PVT__FCMP__DOT__FCMPCore__DOT__same_sign;
        CData/*0:0*/ __PVT__FCMP__DOT__FCMPCore__DOT__uint_less;
        CData/*0:0*/ __PVT__FPMV__DOT__REG;
        CData/*0:0*/ __PVT__FPMV__DOT__REG_1;
        CData/*0:0*/ __PVT__FPMV__DOT___a_T_8;
        CData/*2:0*/ __PVT__FPMV__DOT__s1_op;
        CData/*0:0*/ __PVT__FPMV__DOT__classifyOut_decode___05FisSubnormal;
        CData/*0:0*/ __PVT__FPMV__DOT__classifyOut_decode___05FisInf;
        CData/*0:0*/ __PVT__FPMV__DOT__classifyOut_decode___05FisZero;
        CData/*0:0*/ __PVT__FPMV__DOT__classifyOut_decode___05FisNaN;
        CData/*0:0*/ __PVT__FPMV__DOT__classifyOut_isNormal;
    };
    struct {
        CData/*0:0*/ FPMV__DOT____VdfgTmp_h8faae4b3__0;
        CData/*0:0*/ __PVT__FPToInt__DOT__REG;
        CData/*0:0*/ __PVT__FPToInt__DOT__REG_1;
        CData/*0:0*/ __PVT__FPToInt__DOT___isSingle_T_7;
        CData/*0:0*/ __PVT__FPToInt__DOT__isSingle;
        CData/*1:0*/ __PVT__FPToInt__DOT__coreOp;
        CData/*2:0*/ __PVT__FPToInt__DOT__rm;
        CData/*0:0*/ __PVT__FPToInt__DOT___io_out_bits_fflags_T_3;
        CData/*0:0*/ __PVT__FPToInt__DOT__io_out_bits_result_r;
        CData/*0:0*/ __PVT__FPToInt__DOT__F2ICore__DOT__rpath_rounder_io_roundIn;
        CData/*0:0*/ __PVT__FPToInt__DOT__F2ICore__DOT__rpath_rounder_io_signIn;
        CData/*7:0*/ __PVT__FPToInt__DOT__F2ICore__DOT__fp_a_exp;
        CData/*7:0*/ __PVT__FPToInt__DOT__F2ICore__DOT__raw_a_exp;
        CData/*0:0*/ __PVT__FPToInt__DOT__F2ICore__DOT__lpath_iv;
        CData/*0:0*/ __PVT__FPToInt__DOT__F2ICore__DOT__lpath_may_of;
        CData/*0:0*/ __PVT__FPToInt__DOT__F2ICore__DOT__rpath_rounder__DOT__inexact;
        CData/*0:0*/ __PVT__FPToInt__DOT__F2ICore__DOT__rpath_rounder__DOT__r_up;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm_io_in_sign;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm_io_in_long;
        CData/*0:0*/ __PVT__IntToFP__DOT__REG;
        CData/*0:0*/ __PVT__IntToFP__DOT__REG_1;
        CData/*0:0*/ __PVT__IntToFP__DOT___s2_isSingle_T_4;
        CData/*0:0*/ __PVT__IntToFP__DOT__s2_isSingle_r;
        CData/*0:0*/ __PVT__IntToFP__DOT___s2_isSingle_T_8;
        CData/*0:0*/ __PVT__IntToFP__DOT__s2_isSingle;
        CData/*5:0*/ __PVT__IntToFP__DOT__r_lzc;
        CData/*0:0*/ __PVT__IntToFP__DOT__r_is_zero;
        CData/*0:0*/ __PVT__IntToFP__DOT__r_sign;
        CData/*2:0*/ __PVT__IntToFP__DOT__r_1;
        CData/*0:0*/ IntToFP__DOT____VdfgTmp_h0d28c158__0;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__in_sign;
        CData/*5:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lzc;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lzc_error;
        CData/*0:0*/ IntToFP__DOT__IntToFP_prenorm__DOT____VdfgTmp_h664229ef__0;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_1;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_2;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_3;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_4;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_5;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_6;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_7;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_8;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_9;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_10;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_11;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_12;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_13;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_14;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_15;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_16;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_17;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_18;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_19;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_20;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_21;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_22;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_23;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_24;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_25;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_26;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_27;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_28;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_29;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_30;
    };
    struct {
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_31;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_32;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_33;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_34;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_35;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_36;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_37;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_38;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_39;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_40;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_41;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_42;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_43;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_44;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_45;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_46;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_47;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_48;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_49;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_50;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_51;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_52;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_53;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_54;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_55;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_56;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_57;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_58;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_59;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_60;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_61;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_62;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__f_63;
        CData/*7:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__io_f_lo_hi_lo;
        CData/*7:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__io_f_hi_hi_lo;
        CData/*5:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__pos_lzc_clz__DOT___io_out_T_91;
        CData/*5:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__neg_lzc_clz__DOT___io_out_T_97;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_postnorm__DOT__rounder__DOT__inexact;
        CData/*0:0*/ __PVT__IntToFP__DOT__IntToFP_postnorm__DOT__rounder__DOT__r_up;
        CData/*0:0*/ outArbiter__DOT____VdfgTmp_h245e14da__0;
        CData/*0:0*/ outArbiter__DOT____VdfgTmp_h5724d08f__0;
        SData/*8:0*/ __PVT__FMA__DOT__mulPipe__DOT__s2_io_in_r_shift_amt;
        SData/*8:0*/ __PVT__FMA__DOT__mulPipe__DOT__s2_io_in_r_exp_shifted;
        SData/*8:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3_io_in_r_shift_amt;
        SData/*8:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3_io_in_r_exp_shifted;
        SData/*8:0*/ __PVT__FMA__DOT__mulPipe__DOT__s1__DOT__exp_sum;
        SData/*8:0*/ __PVT__FMA__DOT__mulPipe__DOT__s1__DOT__shift_amt;
        SData/*8:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3__DOT__exp_pre_round;
        VL_IN(__PVT__io_in_bits_a,31,0);
        VL_IN(__PVT__io_in_bits_b,31,0);
        VL_IN(__PVT__io_in_bits_c,31,0);
        IData/*31:0*/ __PVT__FPMV_io_in_bits_a;
        IData/*31:0*/ __PVT___T_58;
        IData/*31:0*/ __PVT__FMA__DOT__mulPipe_io_in_bits_b;
        IData/*31:0*/ __PVT__FMA__DOT__mulPipe__DOT__s1_io_b;
        IData/*31:0*/ __PVT__FMA__DOT__mulPipe__DOT__toAdd_addAnother_r;
        IData/*31:0*/ __PVT__FMA__DOT__mulPipe__DOT__toAdd_addAnother_r_1;
        IData/*24:0*/ __PVT__FMA__DOT__mulPipe__DOT__multiplier__DOT__io_result_r;
        IData/*24:0*/ __PVT__FMA__DOT__mulPipe__DOT__multiplier__DOT__io_result_r_1;
        IData/*22:0*/ __PVT__FMA__DOT__mulPipe__DOT__s1__DOT__fp_a_sig;
        IData/*23:0*/ __PVT__FMA__DOT__mulPipe__DOT__s1__DOT__raw_a_sig;
        IData/*23:0*/ __PVT__FMA__DOT__mulPipe__DOT__s1__DOT__raw_b_sig;
        IData/*23:0*/ __PVT__FMA__DOT__mulPipe__DOT__s1__DOT__subnormal_sig;
        VlWide<3>/*73:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3__DOT__sig_shifted_raw;
    };
    struct {
        VlWide<3>/*73:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3__DOT__sig_shifted;
        IData/*31:0*/ __PVT__FMA__DOT__addPipe__DOT__srcB;
        IData/*26:0*/ __PVT__FMA__DOT__addPipe__DOT__s2_io_in_r_far_path_out_sig;
        IData/*26:0*/ __PVT__FMA__DOT__addPipe__DOT__s2_io_in_r_near_path_out_sig;
        IData/*31:0*/ __PVT__FCMP__DOT__FCMPCore_io_a;
        IData/*31:0*/ __PVT__FCMP__DOT__FCMPCore_io_b;
        IData/*31:0*/ __PVT__FCMP__DOT__a;
        IData/*31:0*/ __PVT__FCMP__DOT__b;
        IData/*31:0*/ __PVT__FCMP__DOT__io_out_bits_result_r;
        IData/*22:0*/ __PVT__FCMP__DOT__FCMPCore__DOT__fp_a_sig;
        IData/*22:0*/ __PVT__FCMP__DOT__FCMPCore__DOT__fp_b_sig;
        IData/*23:0*/ __PVT__FPToInt__DOT__F2ICore__DOT__rpath_rounder_io_in;
        IData/*22:0*/ __PVT__FPToInt__DOT__F2ICore__DOT__fp_a_sig;
        IData/*23:0*/ __PVT__FPToInt__DOT__F2ICore__DOT__raw_a_sig;
        IData/*24:0*/ __PVT__FPToInt__DOT__F2ICore__DOT__shiftRightJam__DOT___io_out_T;
        IData/*24:0*/ __PVT__FPToInt__DOT__F2ICore__DOT__shiftRightJam__DOT___io_sticky_T;
        IData/*31:0*/ __PVT__IntToFP__DOT__io_out_bits_result_r;
        IData/*31:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__lza__DOT__io_f_hi;
        IData/*24:0*/ __VdfgTmp_h22dfd192__0;
        VL_OUT64(__PVT__io_out_bits_result,63,0);
        QData/*47:0*/ __PVT__FMA__DOT__mulPipe__DOT__s3_io_in_r_prod;
        QData/*55:0*/ __PVT__FMA__DOT__addPipe__DOT__s1_io_a_r;
        QData/*55:0*/ __PVT__FMA__DOT__addPipe__DOT__s1_io_b_r;
        QData/*32:0*/ __PVT__FCMP__DOT__FCMPCore__DOT__a_minus_b;
        QData/*62:0*/ __PVT__FPMV__DOT__a;
        QData/*62:0*/ __PVT__FPMV__DOT__io_out_bits_result_r;
        QData/*63:0*/ __PVT__FPToInt__DOT__src;
        QData/*63:0*/ __PVT__FPToInt__DOT__io_out_bits_result_r_1;
        QData/*63:0*/ __PVT__FPToInt__DOT__F2ICore__DOT__int_abs;
        QData/*62:0*/ __PVT__IntToFP__DOT__r_norm_int;
        QData/*63:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__pos_lzc_clz_io_in;
        QData/*63:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__in_raw;
        QData/*63:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__in_abs;
        QData/*63:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__one_mask;
        QData/*62:0*/ __PVT__IntToFP__DOT__IntToFP_prenorm__DOT__in_shift_s1;
        VlUnpacked<IData/*31:0*/, 1> __PVT__FMA__DOT__mulFIFO__DOT__ram_result;
        VlUnpacked<IData/*31:0*/, 1> __PVT__FMA__DOT__addFIFO__DOT__ram_result;
    };

    // INTERNAL VARIABLES
    VVentus__Syms* const vlSymsp;

    // CONSTRUCTORS
    VVentus_ScalarFPU_1(VVentus__Syms* symsp, const char* name);
    ~VVentus_ScalarFPU_1();
    VL_UNCOPYABLE(VVentus_ScalarFPU_1);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
