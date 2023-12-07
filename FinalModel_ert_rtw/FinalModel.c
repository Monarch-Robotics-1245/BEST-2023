/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: FinalModel.c
 *
 * Code generated for Simulink model 'FinalModel'.
 *
 * Model version                  : 1.49
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Dec  7 13:42:45 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FinalModel.h"
#include "rtwtypes.h"
#include "FinalModel_private.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Named constants for Chart: '<S3>/Chart' */
#define FinalModel_IN_init             ((uint8_T)1U)
#define FinalModel_IN_wait             ((uint8_T)2U)

/* Block signals (default storage) */
B_FinalModel_T FinalModel_B;

/* Block states (default storage) */
DW_FinalModel_T FinalModel_DW;

/* Real-time model */
static RT_MODEL_FinalModel_T FinalModel_M_;
RT_MODEL_FinalModel_T *const FinalModel_M = &FinalModel_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (FinalModel_M->Timing.TaskCounters.TID[1])++;
  if ((FinalModel_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.2s, 0.0s] */
    FinalModel_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    '<S3>/Chart'
 *    '<S8>/Chart'
 */
void FinalModel_Chart_Init(real_T *rty_output)
{
  *rty_output = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S3>/Chart'
 *    '<S8>/Chart'
 */
void FinalModel_Chart(real_T rtu_trigger, real_T *rty_output,
                      DW_Chart_FinalModel_T *localDW, P_Chart_FinalModel_T
                      *localP)
{
  /* Chart: '<S3>/Chart' */
  if (localDW->is_active_c7_vexcommonlib == 0U) {
    localDW->is_active_c7_vexcommonlib = 1U;
    *rty_output = localP->Chart_output0;
    localDW->is_c7_vexcommonlib = FinalModel_IN_init;
  } else if (localDW->is_c7_vexcommonlib == FinalModel_IN_init) {
    if (rtu_trigger != 0.0) {
      *rty_output = !(*rty_output != 0.0);
      localDW->is_c7_vexcommonlib = FinalModel_IN_wait;
    }

    /* case IN_wait: */
  } else if (rtu_trigger == 0.0) {
    localDW->is_c7_vexcommonlib = FinalModel_IN_init;
  }

  /* End of Chart: '<S3>/Chart' */
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void FinalModel_step(void)
{
  real_T rtb_Direction;
  real_T rtb_MultiportSwitch6;
  real_T rtb_Switch3;
  real_T rtb_left_motor;
  real_T tmp;
  real_T y;
  int32_T tmp_0;
  uint8_T b_varargout_1;
  uint8_T b_varargout_2;
  boolean_T tmp_1;
  boolean_T tmp_2;
  boolean_T tmp_3;

  /* MATLABSystem: '<Root>/Gamepad Button5' */
  FinalModel_B.MinMax = joystickGetDigital(1, 7, 4);

  /* MATLABSystem: '<Root>/Gamepad Button7' */
  rtb_MultiportSwitch6 = joystickGetDigital(1, 7, 8);

  /* MATLABSystem: '<Root>/Gamepad Button6' */
  rtb_left_motor = joystickGetDigital(1, 7, 2);

  /* MATLABSystem: '<Root>/Gamepad Button4' */
  rtb_Switch3 = joystickGetDigital(1, 7, 1);

  /* MinMax: '<S7>/MinMax2' incorporates:
   *  MATLABSystem: '<Root>/Gamepad Button4'
   *  MATLABSystem: '<Root>/Gamepad Button6'
   *  MATLABSystem: '<Root>/Gamepad Button7'
   *  MinMax: '<S7>/MinMax1'
   *  MinMax: '<S7>/MinMax3'
   *  MinMax: '<S7>/MinMax4'
   */
  tmp_1 = rtIsNaN(rtb_left_motor);
  if ((rtb_MultiportSwitch6 >= rtb_left_motor) || tmp_1) {
    y = rtb_MultiportSwitch6;
  } else {
    y = rtb_left_motor;
  }

  tmp_3 = !rtIsNaN(rtb_Switch3);
  if ((!(y >= rtb_Switch3)) && tmp_3) {
    y = rtb_Switch3;
  }

  /* Switch: '<S6>/Switch' incorporates:
   *  CombinatorialLogic: '<S11>/Logic'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   *  MATLABSystem: '<Root>/Gamepad Button5'
   *  Memory: '<S11>/Memory'
   *  MinMax: '<S7>/MinMax2'
   */
  FinalModel_DW.Memory_PreviousInput = FinalModel_P.Logic_table[((((uint32_T)
    (FinalModel_B.MinMax != 0.0) << 1) + (uint32_T)(y != 0.0)) << 1) +
    FinalModel_DW.Memory_PreviousInput];

  /* MinMax: '<S7>/MinMax1' incorporates:
   *  MATLABSystem: '<Root>/Gamepad Button4'
   *  MATLABSystem: '<Root>/Gamepad Button5'
   *  MATLABSystem: '<Root>/Gamepad Button6'
   */
  if ((FinalModel_B.MinMax >= rtb_left_motor) || tmp_1) {
    y = FinalModel_B.MinMax;
  } else {
    y = rtb_left_motor;
  }

  if ((!(y >= rtb_Switch3)) && tmp_3) {
    y = rtb_Switch3;
  }

  /* Switch: '<S6>/Switch1' incorporates:
   *  CombinatorialLogic: '<S12>/Logic'
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   *  DataTypeConversion: '<S7>/Data Type Conversion3'
   *  MATLABSystem: '<Root>/Gamepad Button7'
   *  Memory: '<S12>/Memory'
   *  MinMax: '<S7>/MinMax1'
   */
  FinalModel_DW.Memory_PreviousInput_a = FinalModel_P.Logic_table_a[((((uint32_T)
    (rtb_MultiportSwitch6 != 0.0) << 1) + (uint32_T)(y != 0.0)) << 1) +
    FinalModel_DW.Memory_PreviousInput_a];

  /* MinMax: '<S7>/MinMax3' incorporates:
   *  MATLABSystem: '<Root>/Gamepad Button4'
   *  MATLABSystem: '<Root>/Gamepad Button5'
   *  MATLABSystem: '<Root>/Gamepad Button7'
   *  MinMax: '<S7>/MinMax4'
   */
  tmp_2 = ((FinalModel_B.MinMax >= rtb_MultiportSwitch6) || rtIsNaN
           (rtb_MultiportSwitch6));
  if (tmp_2) {
    y = FinalModel_B.MinMax;
  } else {
    y = rtb_MultiportSwitch6;
  }

  if ((!(y >= rtb_Switch3)) && tmp_3) {
    y = rtb_Switch3;
  }

  /* Switch: '<S6>/Switch2' incorporates:
   *  CombinatorialLogic: '<S13>/Logic'
   *  DataTypeConversion: '<S7>/Data Type Conversion4'
   *  DataTypeConversion: '<S7>/Data Type Conversion5'
   *  MATLABSystem: '<Root>/Gamepad Button6'
   *  Memory: '<S13>/Memory'
   *  MinMax: '<S7>/MinMax3'
   */
  FinalModel_DW.Memory_PreviousInput_i = FinalModel_P.Logic_table_b[((((uint32_T)
    (rtb_left_motor != 0.0) << 1) + (uint32_T)(y != 0.0)) << 1) +
    FinalModel_DW.Memory_PreviousInput_i];

  /* MinMax: '<S7>/MinMax4' incorporates:
   *  MATLABSystem: '<Root>/Gamepad Button5'
   *  MATLABSystem: '<Root>/Gamepad Button6'
   */
  if (tmp_2) {
    rtb_MultiportSwitch6 = FinalModel_B.MinMax;
  }

  if ((rtb_MultiportSwitch6 >= rtb_left_motor) || tmp_1) {
    rtb_left_motor = rtb_MultiportSwitch6;
  }

  /* Switch: '<S6>/Switch3' incorporates:
   *  CombinatorialLogic: '<S14>/Logic'
   *  DataTypeConversion: '<S7>/Data Type Conversion6'
   *  DataTypeConversion: '<S7>/Data Type Conversion7'
   *  MATLABSystem: '<Root>/Gamepad Button4'
   *  Memory: '<S14>/Memory'
   *  MinMax: '<S7>/MinMax4'
   */
  FinalModel_DW.Memory_PreviousInput_n = FinalModel_P.Logic_table_j[((((uint32_T)
    (rtb_Switch3 != 0.0) << 1) + (uint32_T)(rtb_left_motor != 0.0)) << 1) +
    FinalModel_DW.Memory_PreviousInput_n];

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant4'
   */
  if (FinalModel_DW.Memory_PreviousInput) {
    rtb_left_motor = FinalModel_P.Constant_Value;
  } else {
    rtb_left_motor = FinalModel_P.Constant4_Value;
  }

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant4'
   */
  if (FinalModel_DW.Memory_PreviousInput_a) {
    rtb_MultiportSwitch6 = FinalModel_P.Constant1_Value;
  } else {
    rtb_MultiportSwitch6 = FinalModel_P.Constant4_Value;
  }

  /* Switch: '<S6>/Switch2' incorporates:
   *  Constant: '<S6>/Constant3'
   *  Constant: '<S6>/Constant4'
   */
  if (FinalModel_DW.Memory_PreviousInput_i) {
    rtb_Switch3 = FinalModel_P.Constant3_Value;
  } else {
    rtb_Switch3 = FinalModel_P.Constant4_Value;
  }

  /* Switch: '<S6>/Switch3' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S6>/Constant4'
   */
  if (FinalModel_DW.Memory_PreviousInput_n) {
    FinalModel_B.MinMax = FinalModel_P.Constant2_Value_e;
  } else {
    FinalModel_B.MinMax = FinalModel_P.Constant4_Value;
  }

  /* MinMax: '<S6>/MinMax' incorporates:
   *  Switch: '<S6>/Switch'
   *  Switch: '<S6>/Switch1'
   *  Switch: '<S6>/Switch2'
   *  Switch: '<S6>/Switch3'
   */
  if ((rtb_left_motor >= rtb_MultiportSwitch6) || rtIsNaN(rtb_MultiportSwitch6))
  {
    rtb_MultiportSwitch6 = rtb_left_motor;
  }

  if ((rtb_MultiportSwitch6 >= rtb_Switch3) || rtIsNaN(rtb_Switch3)) {
    rtb_Switch3 = rtb_MultiportSwitch6;
  }

  if ((rtb_Switch3 >= FinalModel_B.MinMax) || rtIsNaN(FinalModel_B.MinMax)) {
    FinalModel_B.MinMax = rtb_Switch3;
  }

  /* End of MinMax: '<S6>/MinMax' */

  /* Switch: '<S6>/Switch4' incorporates:
   *  Constant: '<S6>/Constant5'
   */
  if (!(FinalModel_B.MinMax > FinalModel_P.Switch4_Threshold_j)) {
    FinalModel_B.MinMax = FinalModel_P.Constant5_Value_n;
  }

  /* End of Switch: '<S6>/Switch4' */

  /* MultiPortSwitch: '<S2>/Multiport Switch6' incorporates:
   *  Constant: '<S2>/Idle'
   */
  switch ((int32_T)FinalModel_B.MinMax) {
   case 1:
    rtb_MultiportSwitch6 = 0.0;
    break;

   case 2:
    rtb_MultiportSwitch6 = 0.0;
    break;

   case 3:
    rtb_MultiportSwitch6 = 0.0;
    break;

   default:
    rtb_MultiportSwitch6 = FinalModel_P.Idle_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch6' */

  /* MATLABSystem: '<Root>/Servo Motor 3' */
  if (rtb_MultiportSwitch6 > 127.0) {
    rtb_MultiportSwitch6 = 127.0;
  } else if (rtb_MultiportSwitch6 < -128.0) {
    rtb_MultiportSwitch6 = -128.0;
  }

  tmp = rt_roundd_snf(rtb_MultiportSwitch6);
  if (tmp < 2.147483648E+9) {
    tmp_0 = (int32_T)tmp;
  } else {
    tmp_0 = MAX_int32_T;
  }

  motorSet(8, tmp_0);

  /* End of MATLABSystem: '<Root>/Servo Motor 3' */

  /* MultiPortSwitch: '<S2>/Multiport Switch7' incorporates:
   *  Constant: '<S2>/Idle'
   */
  switch ((int32_T)FinalModel_B.MinMax) {
   case 1:
    rtb_MultiportSwitch6 = 0.0;
    break;

   case 2:
    rtb_MultiportSwitch6 = 0.0;
    break;

   case 3:
    rtb_MultiportSwitch6 = 0.0;
    break;

   default:
    rtb_MultiportSwitch6 = FinalModel_P.Idle_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch7' */

  /* MATLABSystem: '<Root>/Servo Motor 4' */
  if (rtb_MultiportSwitch6 > 127.0) {
    rtb_MultiportSwitch6 = 127.0;
  } else if (rtb_MultiportSwitch6 < -128.0) {
    rtb_MultiportSwitch6 = -128.0;
  }

  tmp = rt_roundd_snf(rtb_MultiportSwitch6);
  if (tmp < 2.147483648E+9) {
    tmp_0 = (int32_T)tmp;
  } else {
    tmp_0 = MAX_int32_T;
  }

  motorSet(9, tmp_0);

  /* End of MATLABSystem: '<Root>/Servo Motor 4' */

  /* MATLABSystem: '<Root>/Gamepad Button' */
  rtb_MultiportSwitch6 = joystickGetDigital(1, 5, 4);

  /* MATLABSystem: '<Root>/Gamepad Button1' */
  rtb_left_motor = joystickGetDigital(1, 5, 1);

  /* MultiPortSwitch: '<S2>/Multiport Switch2' incorporates:
   *  Constant: '<S2>/Idle'
   */
  switch ((int32_T)FinalModel_B.MinMax) {
   case 1:
    /* Switch: '<S4>/Switch3' incorporates:
     *  Constant: '<S4>/Constant3'
     *  Constant: '<S4>/Tool Down Speed'
     *  Gain: '<S4>/Gain2'
     *  MATLABSystem: '<Root>/Gamepad Button1'
     */
    if (rtb_left_motor > FinalModel_P.Switch3_Threshold) {
      rtb_Switch3 = FinalModel_P.Gain2_Gain * FinalModel_P.ToolDownSpeed_Value;
    } else {
      rtb_Switch3 = FinalModel_P.Constant3_Value_b;
    }

    /* End of Switch: '<S4>/Switch3' */

    /* Switch: '<S4>/Switch2' incorporates:
     *  Constant: '<S4>/Constant3'
     *  Constant: '<S4>/Tool Up Speed'
     *  MATLABSystem: '<Root>/Gamepad Button'
     */
    if (rtb_MultiportSwitch6 > FinalModel_P.Switch2_Threshold) {
      rtb_left_motor = FinalModel_P.ToolUpSpeed_Value;
    } else {
      rtb_left_motor = FinalModel_P.Constant3_Value_b;
    }

    /* MinMax: '<S4>/Max2' incorporates:
     *  Switch: '<S4>/Switch2'
     */
    if ((rtb_left_motor >= rtb_Switch3) || rtIsNaN(rtb_Switch3)) {
      rtb_Switch3 = rtb_left_motor;
    }

    /* End of MinMax: '<S4>/Max2' */

    /* Switch: '<S4>/Switch11' incorporates:
     *  Abs: '<S4>/Abs1'
     *  Constant: '<S4>/Constant4'
     */
    if (fabs(rtb_Switch3) > FinalModel_P.Switch11_Threshold) {
      rtb_Switch3 = FinalModel_P.Constant4_Value_i;
    }

    /* End of Switch: '<S4>/Switch11' */
    break;

   case 2:
    rtb_Switch3 = 0.0;
    break;

   case 3:
    rtb_Switch3 = 0.0;
    break;

   default:
    rtb_Switch3 = FinalModel_P.Idle_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch2' */

  /* MATLABSystem: '<Root>/Small Motor 1' */
  if (FinalModel_DW.obj_h.scaleFactor != FinalModel_P.SmallMotor1_scaleFactor) {
    if (FinalModel_DW.obj_h.isInitialized == 1) {
      FinalModel_DW.obj_h.TunablePropsChanged = true;
    }

    FinalModel_DW.obj_h.scaleFactor = FinalModel_P.SmallMotor1_scaleFactor;
  }

  if (FinalModel_DW.obj_h.TunablePropsChanged) {
    FinalModel_DW.obj_h.TunablePropsChanged = false;
  }

  if (rtb_Switch3 > 127.0) {
    rtb_Switch3 = 127.0;
  } else if (rtb_Switch3 < -128.0) {
    rtb_Switch3 = -128.0;
  }

  tmp = rt_roundd_snf(rtb_Switch3);
  if (tmp < 2.147483648E+9) {
    tmp_0 = (int32_T)tmp;
  } else {
    tmp_0 = MAX_int32_T;
  }

  motorSet(4, tmp_0);

  /* End of MATLABSystem: '<Root>/Small Motor 1' */

  /* MATLABSystem: '<Root>/Gamepad Button2' */
  rtb_MultiportSwitch6 = joystickGetDigital(1, 6, 4);

  /* MATLABSystem: '<Root>/Gamepad Button3' */
  rtb_left_motor = joystickGetDigital(1, 6, 1);

  /* MultiPortSwitch: '<S2>/Multiport Switch3' incorporates:
   *  Constant: '<S2>/Idle'
   */
  switch ((int32_T)FinalModel_B.MinMax) {
   case 1:
    /* Switch: '<S4>/Switch5' incorporates:
     *  Constant: '<S4>/Constant3'
     *  Constant: '<S4>/Gripper Down Speed'
     *  Gain: '<S4>/Gain3'
     *  MATLABSystem: '<Root>/Gamepad Button3'
     */
    if (rtb_left_motor > FinalModel_P.Switch5_Threshold) {
      rtb_Switch3 = FinalModel_P.Gain3_Gain *
        FinalModel_P.GripperDownSpeed_Value;
    } else {
      rtb_Switch3 = FinalModel_P.Constant3_Value_b;
    }

    /* End of Switch: '<S4>/Switch5' */

    /* Switch: '<S4>/Switch4' incorporates:
     *  Constant: '<S4>/Constant3'
     *  Constant: '<S4>/Gripper Up Speed'
     *  MATLABSystem: '<Root>/Gamepad Button2'
     */
    if (rtb_MultiportSwitch6 > FinalModel_P.Switch4_Threshold) {
      rtb_left_motor = FinalModel_P.GripperUpSpeed_Value;
    } else {
      rtb_left_motor = FinalModel_P.Constant3_Value_b;
    }

    /* MinMax: '<S4>/Max1' incorporates:
     *  Switch: '<S4>/Switch4'
     */
    if ((rtb_left_motor >= rtb_Switch3) || rtIsNaN(rtb_Switch3)) {
      rtb_Switch3 = rtb_left_motor;
    }

    /* End of MinMax: '<S4>/Max1' */

    /* Switch: '<S4>/Switch12' incorporates:
     *  Abs: '<S4>/Abs2'
     *  Constant: '<S4>/Constant4'
     */
    if (fabs(rtb_Switch3) > FinalModel_P.Switch12_Threshold) {
      rtb_Switch3 = FinalModel_P.Constant4_Value_i;
    }

    /* End of Switch: '<S4>/Switch12' */
    break;

   case 2:
    rtb_Switch3 = 0.0;
    break;

   case 3:
    rtb_Switch3 = 0.0;
    break;

   default:
    rtb_Switch3 = FinalModel_P.Idle_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch3' */

  /* MATLABSystem: '<Root>/Small Motor 2' */
  if (FinalModel_DW.obj.scaleFactor != FinalModel_P.SmallMotor2_scaleFactor) {
    if (FinalModel_DW.obj.isInitialized == 1) {
      FinalModel_DW.obj.TunablePropsChanged = true;
    }

    FinalModel_DW.obj.scaleFactor = FinalModel_P.SmallMotor2_scaleFactor;
  }

  if (FinalModel_DW.obj.TunablePropsChanged) {
    FinalModel_DW.obj.TunablePropsChanged = false;
  }

  if (rtb_Switch3 > 127.0) {
    rtb_Switch3 = 127.0;
  } else if (rtb_Switch3 < -128.0) {
    rtb_Switch3 = -128.0;
  }

  tmp = rt_roundd_snf(rtb_Switch3);
  if (tmp < 2.147483648E+9) {
    tmp_0 = (int32_T)tmp;
  } else {
    tmp_0 = MAX_int32_T;
  }

  motorSet(5, tmp_0);

  /* End of MATLABSystem: '<Root>/Small Motor 2' */

  /* MATLABSystem: '<Root>/Gamepad Button8' */
  rtb_left_motor = joystickGetDigital(1, 8, 1);

  /* MATLABSystem: '<Root>/Gamepad Button9' */
  rtb_MultiportSwitch6 = joystickGetDigital(1, 8, 4);

  /* Switch: '<S4>/Switch6' incorporates:
   *  Constant: '<S4>/Constant5'
   *  Constant: '<S4>/Gripper C. Ammnt'
   *  MATLABSystem: '<Root>/Gamepad Button8'
   */
  if (rtb_left_motor > FinalModel_P.Switch6_Threshold) {
    rtb_left_motor = FinalModel_P.GripperCAmmnt_Value;
  } else {
    rtb_left_motor = FinalModel_P.Constant5_Value_p;
  }

  /* Switch: '<S4>/Switch7' incorporates:
   *  Constant: '<S4>/Constant5'
   *  Constant: '<S4>/Gripper O. Ammnt'
   *  MATLABSystem: '<Root>/Gamepad Button9'
   */
  if (rtb_MultiportSwitch6 > FinalModel_P.Switch7_Threshold) {
    rtb_MultiportSwitch6 = FinalModel_P.GripperOAmmnt_Value;
  } else {
    rtb_MultiportSwitch6 = FinalModel_P.Constant5_Value_p;
  }

  /* MinMax: '<S4>/Max' incorporates:
   *  Switch: '<S4>/Switch6'
   *  Switch: '<S4>/Switch7'
   */
  if ((rtb_left_motor >= rtb_MultiportSwitch6) || rtIsNaN(rtb_MultiportSwitch6))
  {
    rtb_MultiportSwitch6 = rtb_left_motor;
  }

  /* End of MinMax: '<S4>/Max' */

  /* Switch: '<S4>/Switch14' incorporates:
   *  Abs: '<S4>/Abs4'
   *  Constant: '<S4>/Constant2'
   */
  if (fabs(rtb_MultiportSwitch6) > FinalModel_P.Switch14_Threshold) {
    rtb_MultiportSwitch6 = FinalModel_P.Constant2_Value;
  }

  /* End of Switch: '<S4>/Switch14' */

  /* Switch: '<S4>/Switch13' incorporates:
   *  Abs: '<S4>/Abs3'
   *  Delay: '<S4>/Delay1'
   */
  if (fabs(rtb_MultiportSwitch6) > FinalModel_P.Switch13_Threshold) {
    FinalModel_DW.Delay1_DSTATE = rtb_MultiportSwitch6;
  }

  /* End of Switch: '<S4>/Switch13' */

  /* MultiPortSwitch: '<S2>/Multiport Switch4' incorporates:
   *  Constant: '<S2>/Idle'
   *  Delay: '<S4>/Delay1'
   */
  switch ((int32_T)FinalModel_B.MinMax) {
   case 1:
    rtb_MultiportSwitch6 = FinalModel_DW.Delay1_DSTATE;
    break;

   case 2:
    rtb_MultiportSwitch6 = 0.0;
    break;

   case 3:
    rtb_MultiportSwitch6 = 0.0;
    break;

   default:
    rtb_MultiportSwitch6 = FinalModel_P.Idle_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch4' */

  /* MATLABSystem: '<Root>/Servo Motor 1' */
  if (rtb_MultiportSwitch6 > 127.0) {
    rtb_MultiportSwitch6 = 127.0;
  } else if (rtb_MultiportSwitch6 < -128.0) {
    rtb_MultiportSwitch6 = -128.0;
  }

  tmp = rt_roundd_snf(rtb_MultiportSwitch6);
  if (tmp < 2.147483648E+9) {
    tmp_0 = (int32_T)tmp;
  } else {
    tmp_0 = MAX_int32_T;
  }

  motorSet(6, tmp_0);

  /* End of MATLABSystem: '<Root>/Servo Motor 1' */

  /* MultiPortSwitch: '<S2>/Multiport Switch5' incorporates:
   *  Constant: '<S2>/Idle'
   */
  switch ((int32_T)FinalModel_B.MinMax) {
   case 1:
    rtb_MultiportSwitch6 = 0.0;
    break;

   case 2:
    rtb_MultiportSwitch6 = 0.0;
    break;

   case 3:
    rtb_MultiportSwitch6 = 0.0;
    break;

   default:
    rtb_MultiportSwitch6 = FinalModel_P.Idle_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch5' */

  /* MATLABSystem: '<Root>/Servo Motor 2' */
  if (rtb_MultiportSwitch6 > 127.0) {
    rtb_MultiportSwitch6 = 127.0;
  } else if (rtb_MultiportSwitch6 < -128.0) {
    rtb_MultiportSwitch6 = -128.0;
  }

  tmp = rt_roundd_snf(rtb_MultiportSwitch6);
  if (tmp < 2.147483648E+9) {
    tmp_0 = (int32_T)tmp;
  } else {
    tmp_0 = MAX_int32_T;
  }

  motorSet(7, tmp_0);

  /* End of MATLABSystem: '<Root>/Servo Motor 2' */
  if (FinalModel_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<S1>/Digital Input' */
    FinalModel_B.DigitalInput = digitalRead(1);

    /* MATLABSystem: '<S1>/Digital Input1' */
    FinalModel_B.DigitalInput1 = digitalRead(2);

    /* MATLABSystem: '<S1>/Digital Input2' */
    FinalModel_B.DigitalInput2 = digitalRead(3);

    /* Sum: '<S1>/Sum' */
    rtb_MultiportSwitch6 = (FinalModel_B.DigitalInput +
      FinalModel_B.DigitalInput1) + FinalModel_B.DigitalInput2;

    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant7'
     *  Constant: '<S1>/Constant8'
     */
    if (rtb_MultiportSwitch6 > FinalModel_P.Switch1_Threshold_n) {
      tmp_1 = FinalModel_P.Constant7_Value_j;
    } else {
      tmp_1 = FinalModel_P.Constant8_Value_l;
    }

    /* Switch: '<S1>/Switch2' incorporates:
     *  Constant: '<S1>/Constant7'
     *  Constant: '<S1>/Constant8'
     */
    if (rtb_MultiportSwitch6 >= FinalModel_P.Switch2_Threshold_k) {
      tmp_3 = FinalModel_P.Constant7_Value_j;
    } else {
      tmp_3 = FinalModel_P.Constant8_Value_l;
    }

    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant5'
     *  Constant: '<S1>/Constant6'
     *  Delay: '<S1>/Delay'
     *  Logic: '<S1>/AND'
     *  Logic: '<S1>/NOT'
     *  Sum: '<S1>/Add'
     *  Switch: '<S1>/Switch1'
     *  Switch: '<S1>/Switch2'
     */
    if ((!tmp_1) && tmp_3) {
      FinalModel_DW.Delay_DSTATE += FinalModel_P.Constant6_Value;
    } else {
      FinalModel_DW.Delay_DSTATE = FinalModel_P.Constant5_Value;
    }

    /* End of Switch: '<S1>/Switch' */
  }

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Constant15'
   *  Constant: '<S1>/Constant'
   *  Sum: '<Root>/Subtract'
   */
  rtb_MultiportSwitch6 = 0.0;
  rtb_left_motor = 0.0;
  if (FinalModel_B.MinMax - FinalModel_P.Constant15_Value == 0.0) {
    if ((FinalModel_B.DigitalInput2 == 1.0) && (FinalModel_B.DigitalInput1 ==
         0.0) && (FinalModel_B.DigitalInput == 1.0)) {
      rtb_MultiportSwitch6 = FinalModel_P.Constant_Value_f;
      rtb_left_motor = FinalModel_P.Constant_Value_f;
    } else if ((FinalModel_B.DigitalInput2 == 1.0) &&
               (FinalModel_B.DigitalInput1 == 0.0) && (FinalModel_B.DigitalInput
                == 0.0)) {
      rtb_MultiportSwitch6 = FinalModel_P.Constant_Value_f / 2.5;
      rtb_left_motor = FinalModel_P.Constant_Value_f / 1.5;
    } else if ((FinalModel_B.DigitalInput2 == 1.0) &&
               (FinalModel_B.DigitalInput1 == 1.0) && (FinalModel_B.DigitalInput
                == 0.0)) {
      rtb_left_motor = FinalModel_P.Constant_Value_f / 1.5;
    } else if ((FinalModel_B.DigitalInput2 == 0.0) &&
               (FinalModel_B.DigitalInput1 == 0.0) && (FinalModel_B.DigitalInput
                == 1.0)) {
      rtb_MultiportSwitch6 = FinalModel_P.Constant_Value_f / 1.5;
      rtb_left_motor = FinalModel_P.Constant_Value_f / 2.5;
    } else if ((FinalModel_B.DigitalInput2 == 0.0) &&
               (FinalModel_B.DigitalInput1 == 1.0) && (FinalModel_B.DigitalInput
                == 1.0)) {
      rtb_MultiportSwitch6 = FinalModel_P.Constant_Value_f / 1.5;
    }
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function1' */

  /* MATLABSystem: '<Root>/Gamepad Button10' */
  tmp = joystickGetDigital(1, 8, 2);

  /* Chart: '<S8>/Chart' incorporates:
   *  MATLABSystem: '<Root>/Gamepad Button10'
   */
  FinalModel_Chart(tmp, &FinalModel_B.output, &FinalModel_DW.sf_Chart_j,
                   &FinalModel_P.sf_Chart_j);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Fast Speed'
   *  Constant: '<Root>/Slow Speed'
   */
  if (FinalModel_B.output > FinalModel_P.Switch_Threshold_l) {
    rtb_Switch3 = FinalModel_P.SlowSpeed_Value;
  } else {
    rtb_Switch3 = FinalModel_P.FastSpeed_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLABSystem: '<Root>/Gamepad Joystick2' */
  y = joystickGetAnalog(1, 2);

  /* MATLABSystem: '<Root>/Gamepad Button11' */
  tmp = joystickGetDigital(1, 8, 8);

  /* Chart: '<S3>/Chart' incorporates:
   *  MATLABSystem: '<Root>/Gamepad Button11'
   */
  FinalModel_Chart(tmp, &FinalModel_B.output_e, &FinalModel_DW.sf_Chart,
                   &FinalModel_P.sf_Chart);

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Direction 1'
   *  Constant: '<Root>/Direction 2'
   */
  if (FinalModel_B.output_e > FinalModel_P.Switch1_Threshold_d) {
    rtb_Direction = FinalModel_P.Direction2_Value;
  } else {
    rtb_Direction = FinalModel_P.Direction1_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* MATLABSystem: '<Root>/Gamepad Joystick1' */
  FinalModel_B.rtb_GamepadJoystick1_m = joystickGetAnalog(1, 3);

  /* MultiPortSwitch: '<S2>/Multiport Switch1' incorporates:
   *  Constant: '<S2>/Idle'
   *  Product: '<S4>/Product1'
   *  Switch: '<S4>/Switch'
   */
  switch ((int32_T)FinalModel_B.MinMax) {
   case 1:
    /* Switch: '<S4>/Switch' incorporates:
     *  Gain: '<S4>/Gain'
     *  MATLABSystem: '<Root>/Gamepad Joystick1'
     *  MATLABSystem: '<Root>/Gamepad Joystick2'
     */
    if (rtb_Direction > FinalModel_P.Switch_Threshold) {
      tmp = FinalModel_P.Gain_Gain * FinalModel_B.rtb_GamepadJoystick1_m;
    } else {
      tmp = y;
    }

    rtb_MultiportSwitch6 = tmp * rtb_Switch3;
    break;

   case 2:
    rtb_MultiportSwitch6 = 0.0;
    break;

   case 3:
    break;

   default:
    rtb_MultiportSwitch6 = FinalModel_P.Idle_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch1' */

  /* Gain: '<Root>/Gain1' */
  rtb_MultiportSwitch6 *= FinalModel_P.Gain1_Gain_h;

  /* MATLABSystem: '<Root>/Large Motor 2' */
  if (FinalModel_DW.obj_g.scaleFactor != FinalModel_P.LargeMotor2_scaleFactor) {
    if (FinalModel_DW.obj_g.isInitialized == 1) {
      FinalModel_DW.obj_g.TunablePropsChanged = true;
    }

    FinalModel_DW.obj_g.scaleFactor = FinalModel_P.LargeMotor2_scaleFactor;
  }

  if (FinalModel_DW.obj_g.TunablePropsChanged) {
    FinalModel_DW.obj_g.TunablePropsChanged = false;
  }

  if (rtb_MultiportSwitch6 > 127.0) {
    rtb_MultiportSwitch6 = 127.0;
  } else if (rtb_MultiportSwitch6 < -128.0) {
    rtb_MultiportSwitch6 = -128.0;
  }

  tmp = rt_roundd_snf(rtb_MultiportSwitch6);
  if (tmp < 2.147483648E+9) {
    tmp_0 = (int32_T)tmp;
  } else {
    tmp_0 = MAX_int32_T;
  }

  motorSet(3, tmp_0);

  /* End of MATLABSystem: '<Root>/Large Motor 2' */

  /* MultiPortSwitch: '<S2>/Multiport Switch' incorporates:
   *  Constant: '<S2>/Idle'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S4>/Gain6'
   *  Product: '<S4>/Product'
   *  Switch: '<S4>/Switch1'
   */
  switch ((int32_T)FinalModel_B.MinMax) {
   case 1:
    /* Switch: '<S4>/Switch1' incorporates:
     *  Gain: '<S4>/Gain1'
     *  MATLABSystem: '<Root>/Gamepad Joystick2'
     */
    if (rtb_Direction > FinalModel_P.Switch1_Threshold) {
      FinalModel_B.rtb_GamepadJoystick1_m = FinalModel_P.Gain1_Gain * y;
    }

    rtb_MultiportSwitch6 = FinalModel_B.rtb_GamepadJoystick1_m * rtb_Switch3 *
      FinalModel_P.Gain6_Gain;
    break;

   case 2:
    rtb_MultiportSwitch6 = 0.0;
    break;

   case 3:
    rtb_MultiportSwitch6 = FinalModel_P.Gain_Gain_n * rtb_left_motor;
    break;

   default:
    rtb_MultiportSwitch6 = FinalModel_P.Idle_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch' */

  /* Gain: '<Root>/Gain' */
  FinalModel_B.MinMax = FinalModel_P.Gain_Gain_nz * rtb_MultiportSwitch6;

  /* MATLABSystem: '<Root>/Large Motor 1' */
  if (FinalModel_DW.obj_p.scaleFactor != FinalModel_P.LargeMotor1_scaleFactor) {
    if (FinalModel_DW.obj_p.isInitialized == 1) {
      FinalModel_DW.obj_p.TunablePropsChanged = true;
    }

    FinalModel_DW.obj_p.scaleFactor = FinalModel_P.LargeMotor1_scaleFactor;
  }

  if (FinalModel_DW.obj_p.TunablePropsChanged) {
    FinalModel_DW.obj_p.TunablePropsChanged = false;
  }

  if (FinalModel_B.MinMax > 127.0) {
    FinalModel_B.MinMax = 127.0;
  } else if (FinalModel_B.MinMax < -128.0) {
    FinalModel_B.MinMax = -128.0;
  }

  tmp = rt_roundd_snf(FinalModel_B.MinMax);
  if (tmp < 2.147483648E+9) {
    tmp_0 = (int32_T)tmp;
  } else {
    tmp_0 = MAX_int32_T;
  }

  motorSet(2, tmp_0);

  /* End of MATLABSystem: '<Root>/Large Motor 1' */

  /* MATLABSystem: '<Root>/Competition Switch' */
  CompetitionSwitch(&b_varargout_1, &b_varargout_2);

  /* MATLABSystem: '<Root>/Gamepad Joystick3' */
  joystickGetAnalog(1, 1);

  /* MATLABSystem: '<Root>/Gamepad Joystick' */
  joystickGetAnalog(1, 4);
  rate_scheduler();
}

/* Model initialize function */
void FinalModel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for Switch: '<S6>/Switch' incorporates:
   *  Memory: '<S11>/Memory'
   */
  FinalModel_DW.Memory_PreviousInput = FinalModel_P.SRFlipFlop_initial_condition;

  /* InitializeConditions for Switch: '<S6>/Switch1' incorporates:
   *  Memory: '<S12>/Memory'
   */
  FinalModel_DW.Memory_PreviousInput_a =
    FinalModel_P.SRFlipFlop1_initial_condition;

  /* InitializeConditions for Switch: '<S6>/Switch2' incorporates:
   *  Memory: '<S13>/Memory'
   */
  FinalModel_DW.Memory_PreviousInput_i =
    FinalModel_P.SRFlipFlop2_initial_condition;

  /* InitializeConditions for Switch: '<S6>/Switch3' incorporates:
   *  Memory: '<S14>/Memory'
   */
  FinalModel_DW.Memory_PreviousInput_n =
    FinalModel_P.SRFlipFlop3_initial_condition;

  /* InitializeConditions for Delay: '<S4>/Delay1' */
  FinalModel_DW.Delay1_DSTATE = FinalModel_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  FinalModel_DW.Delay_DSTATE = FinalModel_P.Delay_InitialCondition;

  /* SystemInitialize for Chart: '<S8>/Chart' */
  FinalModel_Chart_Init(&FinalModel_B.output);

  /* SystemInitialize for Chart: '<S3>/Chart' */
  FinalModel_Chart_Init(&FinalModel_B.output_e);

  /* Start for MATLABSystem: '<Root>/Small Motor 1' */
  FinalModel_DW.obj_h.scaleFactor = FinalModel_P.SmallMotor1_scaleFactor;
  FinalModel_DW.obj_h.isInitialized = 1;
  FinalModel_DW.obj_h.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<Root>/Small Motor 2' */
  FinalModel_DW.obj.scaleFactor = FinalModel_P.SmallMotor2_scaleFactor;
  FinalModel_DW.obj.isInitialized = 1;
  FinalModel_DW.obj.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<S1>/Digital Input' */
  MW_pinModeDigIn(1);

  /* Start for MATLABSystem: '<S1>/Digital Input1' */
  MW_pinModeDigIn(2);

  /* Start for MATLABSystem: '<S1>/Digital Input2' */
  MW_pinModeDigIn(3);

  /* Start for MATLABSystem: '<Root>/Large Motor 2' */
  FinalModel_DW.obj_g.scaleFactor = FinalModel_P.LargeMotor2_scaleFactor;
  FinalModel_DW.obj_g.isInitialized = 1;
  FinalModel_DW.obj_g.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<Root>/Large Motor 1' */
  FinalModel_DW.obj_p.scaleFactor = FinalModel_P.LargeMotor1_scaleFactor;
  FinalModel_DW.obj_p.isInitialized = 1;
  FinalModel_DW.obj_p.TunablePropsChanged = false;
}

/* Model terminate function */
void FinalModel_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
