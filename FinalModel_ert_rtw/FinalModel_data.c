/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: FinalModel_data.c
 *
 * Code generated for Simulink model 'FinalModel'.
 *
 * Model version                  : 1.55
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Dec  7 18:59:48 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FinalModel.h"

/* Block parameters (default storage) */
P_FinalModel_T FinalModel_P = {
  /* Mask Parameter: SRFlipFlop_initial_condition
   * Referenced by: '<S11>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop1_initial_condition
   * Referenced by: '<S12>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop2_initial_condition
   * Referenced by: '<S13>/Memory'
   */
  false,

  /* Mask Parameter: SRFlipFlop3_initial_condition
   * Referenced by: '<S14>/Memory'
   */
  false,

  /* Expression: 1
   * Referenced by: '<S1>/Constant6'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant5'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S4>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch'
   */
  0.0,

  /* Expression: 178
   * Referenced by: '<S4>/Tool Up Speed'
   */
  178.0,

  /* Expression: 178
   * Referenced by: '<S4>/Tool Down Speed'
   */
  178.0,

  /* Expression: -1
   * Referenced by: '<S4>/Gain2'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch2'
   */
  0.0,

  /* Expression: 200
   * Referenced by: '<S4>/Switch11'
   */
  200.0,

  /* Expression: 60
   * Referenced by: '<S4>/Gripper Up Speed'
   */
  60.0,

  /* Expression: 30
   * Referenced by: '<S4>/Gripper Down Speed'
   */
  30.0,

  /* Expression: -1
   * Referenced by: '<S4>/Gain3'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch4'
   */
  0.0,

  /* Expression: 187
   * Referenced by: '<S4>/Switch12'
   */
  187.0,

  /* Expression: -1
   * Referenced by: '<S4>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S4>/Gain6'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain'
   */
  -1.0,

  /* Expression: 1/13.5
   * Referenced by: '<Root>/Large Motor 1'
   */
  0.07407407407407407,

  /* Expression: 1/13.5
   * Referenced by: '<Root>/Large Motor 2'
   */
  0.07407407407407407,

  /* Expression: 0
   * Referenced by: '<S4>/Constant2'
   */
  0.0,

  /* Expression: -160
   * Referenced by: '<S4>/Gripper C. Ammnt'
   */
  -160.0,

  /* Expression: 160
   * Referenced by: '<S4>/Gripper O. Ammnt'
   */
  160.0,

  /* Expression: 2
   * Referenced by: '<S6>/Constant1'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S6>/Constant3'
   */
  3.0,

  /* Expression: 4
   * Referenced by: '<S6>/Constant2'
   */
  4.0,

  /* Expression: 1
   * Referenced by: '<S6>/Constant5'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S6>/Constant'
   */
  1.0,

  /* Expression: 1/13.5
   * Referenced by: '<Root>/Small Motor 1'
   */
  0.07407407407407407,

  /* Expression: 1/13.5
   * Referenced by: '<Root>/Small Motor 2'
   */
  0.07407407407407407,

  /* Expression: 1
   * Referenced by: '<Root>/Direction 2'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Direction 1'
   */
  -1.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Slow Speed'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<Root>/Fast Speed'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Switch4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Idle'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant11'
   */
  0.0,

  /* Expression: -1000
   * Referenced by: '<S4>/Constant3'
   */
  -1000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant12'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant13'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant14'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant8'
   */
  0.0,

  /* Expression: -1000
   * Referenced by: '<S4>/Constant5'
   */
  -1000.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch7'
   */
  0.0,

  /* Expression: 180
   * Referenced by: '<S4>/Switch14'
   */
  180.0,

  /* Expression: 0.0
   * Referenced by: '<S4>/Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch13'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant4'
   */
  1.0,

  /* Expression: 40
   * Referenced by: '<S1>/Constant'
   */
  40.0,

  /* Expression: 45
   * Referenced by: '<S1>/Constant1'
   */
  45.0,

  /* Expression: 3
   * Referenced by: '<Root>/Constant15'
   */
  3.0,

  /* Expression: 3
   * Referenced by: '<S1>/Switch1'
   */
  3.0,

  /* Expression: 3
   * Referenced by: '<S1>/Switch2'
   */
  3.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch'
   */
  0.0,

  /* Expression: 0.6136723700887217
   * Referenced by: '<Root>/Constant6'
   */
  0.61367237008872166,

  /* Expression: 0
   * Referenced by: '<Root>/Constant5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch1'
   */
  0.0,

  /* Expression: 2.264784165698813
   * Referenced by: '<Root>/Constant7'
   */
  2.264784165698813,

  /* Expression: -1
   * Referenced by: '<Root>/Gain1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain'
   */
  -1.0,

  /* Expression: 115.9864498644986
   * Referenced by: '<Root>/Constant10'
   */
  115.9864498644986,

  /* Computed Parameter: Logic_table
   * Referenced by: '<S11>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_a
   * Referenced by: '<S12>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_b
   * Referenced by: '<S13>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Logic_table_j
   * Referenced by: '<S14>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Expression: true
   * Referenced by: '<S1>/Constant7'
   */
  true,

  /* Expression: false
   * Referenced by: '<S1>/Constant8'
   */
  false,

  /* Start of '<S8>/Chart' */
  {
    /* Expression: output0
     * Referenced by: '<S8>/Chart'
     */
    0.0
  }
  ,

  /* End of '<S8>/Chart' */

  /* Start of '<S3>/Chart' */
  {
    /* Expression: output0
     * Referenced by: '<S3>/Chart'
     */
    0.0
  }
  /* End of '<S3>/Chart' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
