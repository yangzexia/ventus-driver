// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VVentus.h for the primary calling header

#include "verilated.h"

#include "VVentus_FCMA_ADD_s1.h"

VL_ATTR_COLD void VVentus_FCMA_ADD_s1___ctor_var_reset(VVentus_FCMA_ADD_s1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VVentus__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                      VVentus_FCMA_ADD_s1___ctor_var_reset\n"); );
    // Body
    vlSelf->__PVT__io_a = VL_RAND_RESET_Q(56);
    vlSelf->__PVT__io_b = VL_RAND_RESET_Q(56);
    vlSelf->__PVT__io_b_inter_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__io_b_inter_flags_isNaN = VL_RAND_RESET_I(1);
    vlSelf->__PVT__io_b_inter_flags_isInf = VL_RAND_RESET_I(1);
    vlSelf->__PVT__io_b_inter_flags_overflow = VL_RAND_RESET_I(1);
    vlSelf->__PVT__io_rm = VL_RAND_RESET_I(3);
    vlSelf->__PVT__io_out_rm = VL_RAND_RESET_I(3);
    vlSelf->__PVT__io_out_far_path_out_sign = VL_RAND_RESET_I(1);
    vlSelf->__PVT__io_out_far_path_out_exp = VL_RAND_RESET_I(8);
    vlSelf->__PVT__io_out_far_path_out_sig = VL_RAND_RESET_I(27);
    vlSelf->__PVT__io_out_near_path_out_sign = VL_RAND_RESET_I(1);
    vlSelf->__PVT__io_out_near_path_out_exp = VL_RAND_RESET_I(8);
    vlSelf->__PVT__io_out_near_path_out_sig = VL_RAND_RESET_I(27);
    vlSelf->__PVT__io_out_special_case_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__io_out_special_case_bits_nan = VL_RAND_RESET_I(1);
    vlSelf->__PVT__io_out_special_case_bits_inf_sign = VL_RAND_RESET_I(1);
    vlSelf->__PVT__io_out_far_path_mul_of = VL_RAND_RESET_I(1);
    vlSelf->__PVT__io_out_near_path_sig_is_zero = VL_RAND_RESET_I(1);
    vlSelf->__PVT__io_out_sel_far_path = VL_RAND_RESET_I(1);
    vlSelf->__PVT__far_path_mods_0_io_in_a_exp = VL_RAND_RESET_I(8);
    vlSelf->__PVT__far_path_mods_0_io_in_b_sig = VL_RAND_RESET_Q(48);
    vlSelf->__PVT__far_path_mods_0_io_in_effSub = VL_RAND_RESET_I(1);
    vlSelf->__PVT__far_path_mods_0_io_in_smallAdd = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0_io_in_a_exp = VL_RAND_RESET_I(8);
    vlSelf->__PVT__near_path_mods_0_io_in_a_sig = VL_RAND_RESET_Q(48);
    vlSelf->__PVT__near_path_mods_0_io_in_b_sig = VL_RAND_RESET_Q(48);
    vlSelf->__PVT__near_path_mods_0_io_in_need_shift_b = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1_io_in_a_exp = VL_RAND_RESET_I(8);
    vlSelf->__PVT__decode_a___05FisInf = VL_RAND_RESET_I(1);
    vlSelf->__PVT__b_isInf = VL_RAND_RESET_I(1);
    vlSelf->__PVT__special_path_hasNaN = VL_RAND_RESET_I(1);
    vlSelf->__PVT__exp_diff_a_b = VL_RAND_RESET_I(9);
    vlSelf->__PVT__exp_diff_b_a = VL_RAND_RESET_I(9);
    vlSelf->__PVT__need_swap = VL_RAND_RESET_I(1);
    vlSelf->__PVT___T_5 = VL_RAND_RESET_I(9);
    vlSelf->__PVT___near_path_out_T_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__far_path_mods_0__DOT__adder_in_sig_b = VL_RAND_RESET_Q(52);
    vlSelf->__PVT__far_path_mods_0__DOT__adder_result = VL_RAND_RESET_Q(52);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab_io_f = VL_RAND_RESET_Q(49);
    vlSelf->__PVT__near_path_mods_0__DOT__lzc_clz_io_in = VL_RAND_RESET_Q(49);
    vlSelf->__PVT__near_path_mods_0__DOT__lzc_clz_io_out = VL_RAND_RESET_I(6);
    vlSelf->__PVT__near_path_mods_0__DOT__b_sig = VL_RAND_RESET_Q(49);
    vlSelf->__PVT__near_path_mods_0__DOT___a_minus_b_T_3 = VL_RAND_RESET_Q(50);
    vlSelf->__PVT__near_path_mods_0__DOT__int_bit_mask = VL_RAND_RESET_Q(49);
    vlSelf->__PVT__near_path_mods_0__DOT___int_bit_predicted_T_1 = VL_RAND_RESET_Q(49);
    vlSelf->__PVT__near_path_mods_0__DOT__exceed_lim = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_error = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__sig_s1 = VL_RAND_RESET_Q(49);
    vlSelf->__PVT__near_path_mods_0__DOT__near_path_sig = VL_RAND_RESET_Q(49);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_3 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_4 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_5 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_6 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_7 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_8 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_9 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_10 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_11 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_13 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_14 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_15 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_16 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_17 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_18 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_19 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_20 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_21 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_22 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_23 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_25 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_26 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_27 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_28 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_29 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_30 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_31 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_32 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_33 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_34 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_35 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_37 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_38 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_39 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_40 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_41 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_42 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_43 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_44 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_45 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_46 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_47 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__f_48 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__io_f_lo_hi_lo = VL_RAND_RESET_I(6);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__io_f_hi_hi_lo = VL_RAND_RESET_I(6);
    vlSelf->__PVT__near_path_mods_0__DOT__lza_ab__DOT__io_f_hi = VL_RAND_RESET_I(25);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab_io_f = VL_RAND_RESET_Q(49);
    vlSelf->__PVT__near_path_mods_1__DOT__lzc_clz_io_in = VL_RAND_RESET_Q(49);
    vlSelf->__PVT__near_path_mods_1__DOT__lzc_clz_io_out = VL_RAND_RESET_I(6);
    vlSelf->__PVT__near_path_mods_1__DOT__b_sig = VL_RAND_RESET_Q(49);
    vlSelf->__PVT__near_path_mods_1__DOT___a_minus_b_T_3 = VL_RAND_RESET_Q(50);
    vlSelf->__PVT__near_path_mods_1__DOT__int_bit_mask = VL_RAND_RESET_Q(49);
    vlSelf->__PVT__near_path_mods_1__DOT___int_bit_predicted_T_1 = VL_RAND_RESET_Q(49);
    vlSelf->__PVT__near_path_mods_1__DOT__exceed_lim = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_error = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__sig_s1 = VL_RAND_RESET_Q(49);
    vlSelf->__PVT__near_path_mods_1__DOT__near_path_sig = VL_RAND_RESET_Q(49);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_1 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_2 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_3 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_4 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_5 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_6 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_7 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_8 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_9 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_10 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_11 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_13 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_14 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_15 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_16 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_17 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_18 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_19 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_20 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_21 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_22 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_23 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_25 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_26 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_27 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_28 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_29 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_30 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_31 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_32 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_33 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_34 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_35 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_37 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_38 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_39 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_40 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_41 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_42 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_43 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_44 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_45 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_46 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_47 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__f_48 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__io_f_lo_hi_lo = VL_RAND_RESET_I(6);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__io_f_hi_hi_lo = VL_RAND_RESET_I(6);
    vlSelf->__PVT__near_path_mods_1__DOT__lza_ab__DOT__io_f_hi = VL_RAND_RESET_I(25);
}
