#ifndef _MW_CUSTOM_RTOS_HEADER_H_
#define _MW_CUSTOM_RTOS_HEADER_H_
#define MW_BASERATE_PRIORITY           40
#define MW_BASERATE_PERIOD             0.02
#define MW_NUMBER_SUBRATES             0
#define MW_NUMBER_APERIODIC_TASKS      0
#define MW_IS_CONCURRENT               0
#define MW_NUMBER_TIMER_DRIVEN_TASKS   0

extern void exitFcn(int sig);
extern void *terminateTask(void *arg);
extern void *baseRateTask(void *arg);
extern void *subrateTask(void *arg);
extern TaskHandle schedulerThread;
extern TaskHandle baseRateThread;
extern TaskHandle subRateThread[];
extern Semaphore stopSem;
extern Semaphore baserateTaskSem;
extern Semaphore subrateTaskSem[];
extern int taskId[];
extern int subratePriority[];

#endif

#define MW_MAX_TASKNAME                16
