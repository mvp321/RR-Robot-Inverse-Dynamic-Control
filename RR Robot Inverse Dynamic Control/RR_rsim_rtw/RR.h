/*
 * RR.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RR".
 *
 * Model version              : 1.66
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Mon Oct 12 13:38:19 2020
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RR_h_
#define RTW_HEADER_RR_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef RR_COMMON_INCLUDES_
# define RR_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rsim.h"
#include "rt_logging.h"
#include "dt_info.h"
#endif                                 /* RR_COMMON_INCLUDES_ */

#include "RR_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#define MODEL_NAME                     RR
#define NSAMPLE_TIMES                  (1)                       /* Number of sample times */
#define NINPUTS                        (0)                       /* Number of model inputs */
#define NOUTPUTS                       (0)                       /* Number of model outputs */
#define NBLOCKIO                       (11)                      /* Number of data output port signals */
#define NUM_ZC_EVENTS                  (0)                       /* Number of zero-crossing events */
#ifndef NCSTATES
# define NCSTATES                      (4)                       /* Number of continuous states */
#elif NCSTATES != 4
# error Invalid specification of NCSTATES defined in compiler command
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        (NULL)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T q[2];                         /* '<Root>/Integrator1' */
  real_T qd_dot[2];                    /* '<Root>/Derivative' */
  real_T qd_dot_dot[2];                /* '<Root>/Derivative1' */
  real_T q_dot[2];                     /* '<Root>/Integrator' */
  real_T e_dot[2];                     /* '<Root>/Sum1' */
  real_T KD[2];                        /* '<Root>/KD' */
  real_T e[2];                         /* '<Root>/Sum' */
  real_T KP[2];                        /* '<Root>/KP' */
  real_T a0[2];                        /* '<Root>/Sum2' */
  real_T qd[2];                        /* '<Root>/qd' */
  real_T q_dot_dot[2];                 /* '<Root>/Manipulator' */
} B;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA[2];              /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB[2];              /* '<Root>/Derivative' */
  real_T TimeStampA_j;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeA_d[2];            /* '<Root>/Derivative1' */
  real_T TimeStampB_i;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeB_e[2];            /* '<Root>/Derivative1' */
  struct {
    void *LoggedData;
  } DesiredTrajectory_PWORK;           /* '<Root>/Desired Trajectory' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE[2];        /* '<Root>/Integrator1' */
  real_T Integrator_CSTATE[2];         /* '<Root>/Integrator' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE[2];        /* '<Root>/Integrator1' */
  real_T Integrator_CSTATE[2];         /* '<Root>/Integrator' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE[2];     /* '<Root>/Integrator1' */
  boolean_T Integrator_CSTATE[2];      /* '<Root>/Integrator' */
} XDis;

/* Continuous State Absolute Tolerance  */
typedef struct {
  real_T Integrator1_CSTATE[2];        /* '<Root>/Integrator1' */
  real_T Integrator_CSTATE[2];         /* '<Root>/Integrator' */
} CStateAbsTol;

/* Continuous State Perturb Min  */
typedef struct {
  real_T Integrator1_CSTATE[2];        /* '<Root>/Integrator1' */
  real_T Integrator_CSTATE[2];         /* '<Root>/Integrator' */
} CXPtMin;

/* Continuous State Perturb Max  */
typedef struct {
  real_T Integrator1_CSTATE[2];        /* '<Root>/Integrator1' */
  real_T Integrator_CSTATE[2];         /* '<Root>/Integrator' */
} CXPtMax;

/* Parameters (default storage) */
struct P_ {
  real_T pi4cost_Amp;                  /* Expression: pi/4
                                        * Referenced by: '<Root>/pi//4.cost'
                                        */
  real_T pi4cost_Bias;                 /* Expression: 0
                                        * Referenced by: '<Root>/pi//4.cost'
                                        */
  real_T pi4cost_Freq;                 /* Expression: 1
                                        * Referenced by: '<Root>/pi//4.cost'
                                        */
  real_T pi4cost_Phase;                /* Expression: pi/2
                                        * Referenced by: '<Root>/pi//4.cost'
                                        */
  real_T pi6cos2tpi4_Amp;              /* Expression: pi/6
                                        * Referenced by: '<Root>/pi//6.cos(2t+pi//4)'
                                        */
  real_T pi6cos2tpi4_Bias;             /* Expression: 0
                                        * Referenced by: '<Root>/pi//6.cos(2t+pi//4)'
                                        */
  real_T pi6cos2tpi4_Freq;             /* Expression: 2
                                        * Referenced by: '<Root>/pi//6.cos(2t+pi//4)'
                                        */
  real_T pi6cos2tpi4_Phase;            /* Expression: pi/4
                                        * Referenced by: '<Root>/pi//6.cos(2t+pi//4)'
                                        */
  real_T Integrator1_IC[2];            /* Expression: [0;0]
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Integrator_IC[2];             /* Expression: [0;0]
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T KD_Gain[4];                   /* Expression: [0.99 0;0 0.99]
                                        * Referenced by: '<Root>/KD'
                                        */
  real_T KP_Gain[4];                   /* Expression: [1.155 0;0 1.155]
                                        * Referenced by: '<Root>/KP'
                                        */
};

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern B rtB;                          /* block i/o */
extern X rtX;                          /* states (continuous) */
extern DW rtDW;                        /* states (dwork) */
extern P rtP;                          /* parameters */

/* Simulation Structure */
extern SimStruct *const rtS;

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
 * '<Root>' : 'RR'
 * '<S1>'   : 'RR/Control'
 * '<S2>'   : 'RR/Manipulator'
 * '<S3>'   : 'RR/qd'
 */

/* user code (bottom of header file) */
extern const int_T gblNumToFiles;
extern const int_T gblNumFrFiles;
extern const int_T gblNumFrWksBlocks;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
extern const int_T gblNumRootInportBlks;
extern const int_T gblNumModelInputs;
extern const int_T gblInportDataTypeIdx[];
extern const int_T gblInportDims[];
extern const int_T gblInportComplex[];
extern const int_T gblInportInterpoFlag[];
extern const int_T gblInportContinuous[];

#endif                                 /* RTW_HEADER_RR_h_ */
