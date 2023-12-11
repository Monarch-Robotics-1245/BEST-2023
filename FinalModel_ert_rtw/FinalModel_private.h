/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: FinalModel_private.h
 *
 * Code generated for Simulink model 'FinalModel'.
 *
 * Model version                  : 1.59
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Dec  8 13:26:38 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FinalModel_private_h_
#define RTW_HEADER_FinalModel_private_h_
#include "rtwtypes.h"
#include "FinalModel.h"
#include "FinalModel_types.h"

extern real_T rt_roundd_snf(real_T u);
extern void FinalModel_Chart_Init(real_T *rty_output);
extern void FinalModel_Chart(real_T rtu_trigger, real_T *rty_output,
  DW_Chart_FinalModel_T *localDW, P_Chart_FinalModel_T *localP);

#endif                                 /* RTW_HEADER_FinalModel_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
