/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'FinalModel'.
 *
 * Model version                  : 1.65
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Dec 14 19:41:36 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FinalModel.h"
#include "FinalModel_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "main.h"
#include "pros_wrapper.h"
#include "pros_rtos_init.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
Semaphore stopSem;
Semaphore baserateTaskSem;
TaskHandle schedulerThread;
TaskHandle baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(FinalModel_M) == (NULL));
  while (runModel) {
    mw_osSemaphoreWaitEver(&baserateTaskSem);
    FinalModel_step();

    /* Get model outputs here */
    stopRequested = !((rtmGetErrorStatus(FinalModel_M) == (NULL)));
    runModel = !stopRequested;
  }

  runModel = 0;
  terminateTask(arg);
  taskDelete((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(FinalModel_M, "stopping the model");
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  /* Terminate model */
  FinalModel_terminate();
  mw_osSemaphoreRelease(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  rtmSetErrorStatus(FinalModel_M, 0);

  /* Initialize model */
  FinalModel_initialize();

  /* Call RTOS Initialization function */
  prosRTOSInit(0.02, 0);

  /* Wait for stop semaphore */
  mw_osSemaphoreWaitEver(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(mw_osSemaphoreDelete(&timerTaskSem[i]), 0,
                   "mw_osSemaphoreDelete");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
