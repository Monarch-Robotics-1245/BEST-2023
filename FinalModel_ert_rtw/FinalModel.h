/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: FinalModel.h
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

#ifndef RTW_HEADER_FinalModel_h_
#define RTW_HEADER_FinalModel_h_
#ifndef FinalModel_COMMON_INCLUDES_
#define FinalModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_DigitalIn_Wrapper.h"
#include "vex_competition_switch.h"
#include "MW_GamepadButton_Wrapper.h"
#include "MW_GamepadAccel_Wrapper.h"
#include "MW_DCMotor_Wrapper.h"
#endif                                 /* FinalModel_COMMON_INCLUDES_ */

#include "FinalModel_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S3>/Chart' */
typedef struct {
  uint8_T is_active_c7_vexcommonlib;   /* '<S3>/Chart' */
  uint8_T is_c7_vexcommonlib;          /* '<S3>/Chart' */
} DW_Chart_FinalModel_T;

/* Block signals (default storage) */
typedef struct {
  real_T output;                       /* '<S8>/Chart' */
  real_T output_e;                     /* '<S3>/Chart' */
  real_T DigitalInput2;                /* '<S1>/Digital Input2' */
  real_T DigitalInput1;                /* '<S1>/Digital Input1' */
  real_T DigitalInput;                 /* '<S1>/Digital Input' */
  real_T rtb_GamepadJoystick1_m;
  real_T MinMax;                       /* '<S6>/MinMax' */
} B_FinalModel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  vex_DCMotor_FinalModel_T obj;        /* '<Root>/Small Motor 2' */
  vex_DCMotor_FinalModel_T obj_h;      /* '<Root>/Small Motor 1' */
  vex_DCMotor_FinalModel_T obj_g;      /* '<Root>/Large Motor 2' */
  vex_DCMotor_FinalModel_T obj_p;      /* '<Root>/Large Motor 1' */
  real_T Delay1_DSTATE;                /* '<S4>/Delay1' */
  real_T Delay_DSTATE;                 /* '<S1>/Delay' */
  boolean_T Memory_PreviousInput;      /* '<S11>/Memory' */
  boolean_T Memory_PreviousInput_a;    /* '<S12>/Memory' */
  boolean_T Memory_PreviousInput_i;    /* '<S13>/Memory' */
  boolean_T Memory_PreviousInput_n;    /* '<S14>/Memory' */
  DW_Chart_FinalModel_T sf_Chart_j;    /* '<S8>/Chart' */
  DW_Chart_FinalModel_T sf_Chart;      /* '<S3>/Chart' */
} DW_FinalModel_T;

/* Parameters for system: '<S3>/Chart' */
struct P_Chart_FinalModel_T_ {
  real_T Chart_output0;                /* Expression: output0
                                        * Referenced by: '<S3>/Chart'
                                        */
};

/* Parameters (default storage) */
struct P_FinalModel_T_ {
  boolean_T SRFlipFlop_initial_condition;
                                 /* Mask Parameter: SRFlipFlop_initial_condition
                                  * Referenced by: '<S11>/Memory'
                                  */
  boolean_T SRFlipFlop1_initial_condition;
                                /* Mask Parameter: SRFlipFlop1_initial_condition
                                 * Referenced by: '<S12>/Memory'
                                 */
  boolean_T SRFlipFlop2_initial_condition;
                                /* Mask Parameter: SRFlipFlop2_initial_condition
                                 * Referenced by: '<S13>/Memory'
                                 */
  boolean_T SRFlipFlop3_initial_condition;
                                /* Mask Parameter: SRFlipFlop3_initial_condition
                                 * Referenced by: '<S14>/Memory'
                                 */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant6'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T ToolUpSpeed_Value;            /* Expression: 178
                                        * Referenced by: '<S4>/Tool Up Speed'
                                        */
  real_T ToolDownSpeed_Value;          /* Expression: 178
                                        * Referenced by: '<S4>/Tool Down Speed'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<S4>/Switch3'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S4>/Switch2'
                                        */
  real_T Switch11_Threshold;           /* Expression: 200
                                        * Referenced by: '<S4>/Switch11'
                                        */
  real_T GripperUpSpeed_Value;         /* Expression: 60
                                        * Referenced by: '<S4>/Gripper Up Speed'
                                        */
  real_T GripperDownSpeed_Value;       /* Expression: 30
                                        * Referenced by: '<S4>/Gripper Down Speed'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<S4>/Gain3'
                                        */
  real_T Switch5_Threshold;            /* Expression: 0
                                        * Referenced by: '<S4>/Switch5'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0
                                        * Referenced by: '<S4>/Switch4'
                                        */
  real_T Switch12_Threshold;           /* Expression: 187
                                        * Referenced by: '<S4>/Switch12'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S4>/Switch1'
                                        */
  real_T Gain6_Gain;                   /* Expression: -1
                                        * Referenced by: '<S4>/Gain6'
                                        */
  real_T Gain_Gain_n;                  /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T LargeMotor1_scaleFactor;      /* Expression: 1/13.5
                                        * Referenced by: '<Root>/Large Motor 1'
                                        */
  real_T LargeMotor2_scaleFactor;      /* Expression: 1/13.5
                                        * Referenced by: '<Root>/Large Motor 2'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T GripperCAmmnt_Value;          /* Expression: -160
                                        * Referenced by: '<S4>/Gripper C. Ammnt'
                                        */
  real_T GripperOAmmnt_Value;          /* Expression: 160
                                        * Referenced by: '<S4>/Gripper O. Ammnt'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant3_Value;              /* Expression: 3
                                        * Referenced by: '<S6>/Constant3'
                                        */
  real_T Constant2_Value_e;            /* Expression: 4
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Constant5_Value_n;            /* Expression: 1
                                        * Referenced by: '<S6>/Constant5'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T SmallMotor1_scaleFactor;      /* Expression: 1/13.5
                                        * Referenced by: '<Root>/Small Motor 1'
                                        */
  real_T SmallMotor2_scaleFactor;      /* Expression: 1/13.5
                                        * Referenced by: '<Root>/Small Motor 2'
                                        */
  real_T Direction2_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Direction 2'
                                        */
  real_T Direction1_Value;             /* Expression: -1
                                        * Referenced by: '<Root>/Direction 1'
                                        */
  real_T SlowSpeed_Value;              /* Expression: 0.5
                                        * Referenced by: '<Root>/Slow Speed'
                                        */
  real_T FastSpeed_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Fast Speed'
                                        */
  real_T Constant_Value_h;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value_m;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value_o;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant4'
                                        */
  real_T Switch4_Threshold_j;          /* Expression: 0
                                        * Referenced by: '<S6>/Switch4'
                                        */
  real_T Idle_Value;                   /* Expression: 0
                                        * Referenced by: '<S2>/Idle'
                                        */
  real_T Constant4_Value_i;            /* Expression: 0
                                        * Referenced by: '<S4>/Constant4'
                                        */
  real_T Constant11_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T Constant3_Value_b;            /* Expression: -1000
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Constant12_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant12'
                                        */
  real_T Constant13_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant13'
                                        */
  real_T Constant14_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant14'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant5_Value_p;            /* Expression: -1000
                                        * Referenced by: '<S4>/Constant5'
                                        */
  real_T Switch6_Threshold;            /* Expression: 0
                                        * Referenced by: '<S4>/Switch6'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Switch7_Threshold;            /* Expression: 0
                                        * Referenced by: '<S4>/Switch7'
                                        */
  real_T Switch14_Threshold;           /* Expression: 180
                                        * Referenced by: '<S4>/Switch14'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S4>/Delay1'
                                        */
  real_T Switch13_Threshold;           /* Expression: 0
                                        * Referenced by: '<S4>/Switch13'
                                        */
  real_T Constant2_Value_o;            /* Expression: 1
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant3_Value_m;            /* Expression: 1
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant4_Value_p;            /* Expression: 1
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Constant_Value_f;             /* Expression: 40
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value_j;            /* Expression: 45
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant15_Value;             /* Expression: 3
                                        * Referenced by: '<Root>/Constant15'
                                        */
  real_T Switch1_Threshold_n;          /* Expression: 3
                                        * Referenced by: '<S1>/Switch1'
                                        */
  real_T Switch2_Threshold_k;          /* Expression: 3
                                        * Referenced by: '<S1>/Switch2'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T Constant4_Value_i0;           /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Switch_Threshold_l;           /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Constant6_Value_e;            /* Expression: 0.6136723700887217
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant5_Value_n2;           /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Switch1_Threshold_d;          /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T Constant7_Value;              /* Expression: 2.264784165698813
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: -1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain_Gain_nz;                 /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant10_Value;             /* Expression: 115.9864498644986
                                        * Referenced by: '<Root>/Constant10'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S11>/Logic'
                                        */
  boolean_T Logic_table_a[16];         /* Computed Parameter: Logic_table_a
                                        * Referenced by: '<S12>/Logic'
                                        */
  boolean_T Logic_table_b[16];         /* Computed Parameter: Logic_table_b
                                        * Referenced by: '<S13>/Logic'
                                        */
  boolean_T Logic_table_j[16];         /* Computed Parameter: Logic_table_j
                                        * Referenced by: '<S14>/Logic'
                                        */
  boolean_T Constant7_Value_j;         /* Expression: true
                                        * Referenced by: '<S1>/Constant7'
                                        */
  boolean_T Constant8_Value_l;         /* Expression: false
                                        * Referenced by: '<S1>/Constant8'
                                        */
  P_Chart_FinalModel_T sf_Chart_j;     /* '<S8>/Chart' */
  P_Chart_FinalModel_T sf_Chart;       /* '<S3>/Chart' */
};

/* Real-time Model Data Structure */
struct tag_RTM_FinalModel_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_FinalModel_T FinalModel_P;

/* Block signals (default storage) */
extern B_FinalModel_T FinalModel_B;

/* Block states (default storage) */
extern DW_FinalModel_T FinalModel_DW;

/* Model entry point functions */
extern void FinalModel_initialize(void);
extern void FinalModel_step(void);
extern void FinalModel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FinalModel_T *const FinalModel_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<Root>/Constant16' : Unused code path elimination
 * Block '<Root>/Drive' : Unused code path elimination
 * Block '<S5>/Gain' : Unused code path elimination
 * Block '<S5>/Gain1' : Unused code path elimination
 * Block '<S5>/Gain6' : Unused code path elimination
 * Block '<S5>/Product' : Unused code path elimination
 * Block '<S5>/Product1' : Unused code path elimination
 * Block '<S5>/Switch' : Unused code path elimination
 * Block '<S5>/Switch1' : Unused code path elimination
 * Block '<Root>/Tools' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FinalModel'
 * '<S1>'   : 'FinalModel/Automomys'
 * '<S2>'   : 'FinalModel/Computational Cortex'
 * '<S3>'   : 'FinalModel/Direction'
 * '<S4>'   : 'FinalModel/Manual Control'
 * '<S5>'   : 'FinalModel/Manual Control1'
 * '<S6>'   : 'FinalModel/Mode Indexing'
 * '<S7>'   : 'FinalModel/Mode Selection System'
 * '<S8>'   : 'FinalModel/Speed'
 * '<S9>'   : 'FinalModel/Automomys/MATLAB Function1'
 * '<S10>'  : 'FinalModel/Direction/Chart'
 * '<S11>'  : 'FinalModel/Mode Selection System/S-R Flip-Flop'
 * '<S12>'  : 'FinalModel/Mode Selection System/S-R Flip-Flop1'
 * '<S13>'  : 'FinalModel/Mode Selection System/S-R Flip-Flop2'
 * '<S14>'  : 'FinalModel/Mode Selection System/S-R Flip-Flop3'
 * '<S15>'  : 'FinalModel/Speed/Chart'
 */
#endif                                 /* RTW_HEADER_FinalModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
