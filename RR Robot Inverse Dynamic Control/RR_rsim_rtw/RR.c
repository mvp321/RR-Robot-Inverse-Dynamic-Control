/*
 * RR.c
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

#include <math.h>
#include "RR.h"
#include "RR_private.h"
#include "RR_dt.h"

/* user code (top of parameter file) */
const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 0;
const int_T gblNumFrWksBlocks = 0;
const char *gblSlvrJacPatternFileName = "RR_rsim_rtw\\RR_Jpattern.mat";

/* Root inports information  */
const int_T gblNumRootInportBlks = 0;
const int_T gblNumModelInputs = 0;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
const int_T gblInportDataTypeIdx[] = { -1 };

const int_T gblInportDims[] = { -1 } ;

const int_T gblInportComplex[] = { -1 };

const int_T gblInportInterpoFlag[] = { -1 };

const int_T gblInportContinuous[] = { -1 };

#include "simstruc.h"
#include "fixedpoint.h"

/* Block signals (default storage) */
B rtB;

/* Continuous states */
X rtX;

/* Block states (default storage) */
DW rtDW;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

/* System initialize for root system: '<Root>' */
void MdlInitialize(void)
{
  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  rtDW.TimeStampA = (rtInf);
  rtDW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  rtDW.TimeStampA_j = (rtInf);
  rtDW.TimeStampB_i = (rtInf);

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  rtX.Integrator1_CSTATE[0] = rtP.Integrator1_IC[0];

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  rtX.Integrator_CSTATE[0] = rtP.Integrator_IC[0];

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  rtX.Integrator1_CSTATE[1] = rtP.Integrator1_IC[1];

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  rtX.Integrator_CSTATE[1] = rtP.Integrator_IC[1];
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{
  MdlInitialize();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_u[2];
  real_T (*lastU)[2];
  real_T y[4];
  real_T B_0[2];
  real_T r;
  real_T t;
  int32_T r1;
  int32_T r2;
  real_T H_idx_0;
  real_T rtb_u_tmp;
  real_T rtb_u_tmp_0;
  real_T rtb_u_tmp_1;

  /* Sin: '<Root>/pi//4.cost' incorporates:
   *  Sin: '<Root>/pi//6.cos(2t+pi//4)'
   */
  r = ssGetT(rtS);

  /* MATLAB Function: '<Root>/qd' incorporates:
   *  Sin: '<Root>/pi//4.cost'
   *  Sin: '<Root>/pi//6.cos(2t+pi//4)'
   */
  rtB.qd[0] = sin(rtP.pi4cost_Freq * r + rtP.pi4cost_Phase) * rtP.pi4cost_Amp +
    rtP.pi4cost_Bias;
  rtB.qd[1] = sin(rtP.pi6cos2tpi4_Freq * r + rtP.pi6cos2tpi4_Phase) *
    rtP.pi6cos2tpi4_Amp + rtP.pi6cos2tpi4_Bias;

  /* Integrator: '<Root>/Integrator1' */
  rtB.q[0] = rtX.Integrator1_CSTATE[0];
  rtB.q[1] = rtX.Integrator1_CSTATE[1];

  /* Derivative: '<Root>/Derivative' incorporates:
   *  Derivative: '<Root>/Derivative1'
   */
  r = ssGetT(rtS);
  if ((rtDW.TimeStampA >= r) && (rtDW.TimeStampB >= r)) {
    rtB.qd_dot[0] = 0.0;
    rtB.qd_dot[1] = 0.0;
  } else {
    t = rtDW.TimeStampA;
    lastU = &rtDW.LastUAtTimeA;
    if (rtDW.TimeStampA < rtDW.TimeStampB) {
      if (rtDW.TimeStampB < r) {
        t = rtDW.TimeStampB;
        lastU = &rtDW.LastUAtTimeB;
      }
    } else {
      if (rtDW.TimeStampA >= r) {
        t = rtDW.TimeStampB;
        lastU = &rtDW.LastUAtTimeB;
      }
    }

    t = r - t;
    rtB.qd_dot[0] = (rtB.qd[0] - (*lastU)[0]) / t;
    rtB.qd_dot[1] = (rtB.qd[1] - (*lastU)[1]) / t;
  }

  /* End of Derivative: '<Root>/Derivative' */

  /* Derivative: '<Root>/Derivative1' */
  if ((rtDW.TimeStampA_j >= r) && (rtDW.TimeStampB_i >= r)) {
    rtB.qd_dot_dot[0] = 0.0;
    rtB.qd_dot_dot[1] = 0.0;
  } else {
    t = rtDW.TimeStampA_j;
    lastU = &rtDW.LastUAtTimeA_d;
    if (rtDW.TimeStampA_j < rtDW.TimeStampB_i) {
      if (rtDW.TimeStampB_i < r) {
        t = rtDW.TimeStampB_i;
        lastU = &rtDW.LastUAtTimeB_e;
      }
    } else {
      if (rtDW.TimeStampA_j >= r) {
        t = rtDW.TimeStampB_i;
        lastU = &rtDW.LastUAtTimeB_e;
      }
    }

    t = r - t;
    rtB.qd_dot_dot[0] = (rtB.qd_dot[0] - (*lastU)[0]) / t;
    rtB.qd_dot_dot[1] = (rtB.qd_dot[1] - (*lastU)[1]) / t;
  }

  /* Integrator: '<Root>/Integrator' */
  rtB.q_dot[0] = rtX.Integrator_CSTATE[0];

  /* Sum: '<Root>/Sum1' */
  rtB.e_dot[0] = rtB.q_dot[0] - rtB.qd_dot[0];

  /* Integrator: '<Root>/Integrator' */
  rtB.q_dot[1] = rtX.Integrator_CSTATE[1];

  /* Sum: '<Root>/Sum1' */
  rtB.e_dot[1] = rtB.q_dot[1] - rtB.qd_dot[1];

  /* Gain: '<Root>/KD' */
  rtB.KD[0] = 0.0;
  rtB.KD[0] += rtP.KD_Gain[0] * rtB.e_dot[0];
  rtB.KD[0] += rtP.KD_Gain[2] * rtB.e_dot[1];

  /* Sum: '<Root>/Sum' */
  rtB.e[0] = rtB.q[0] - rtB.qd[0];

  /* Gain: '<Root>/KD' */
  rtB.KD[1] = 0.0;
  rtB.KD[1] += rtP.KD_Gain[1] * rtB.e_dot[0];
  rtB.KD[1] += rtP.KD_Gain[3] * rtB.e_dot[1];

  /* Sum: '<Root>/Sum' */
  rtB.e[1] = rtB.q[1] - rtB.qd[1];

  /* Gain: '<Root>/KP' */
  rtB.KP[0] = 0.0;
  rtB.KP[0] += rtP.KP_Gain[0] * rtB.e[0];
  rtB.KP[0] += rtP.KP_Gain[2] * rtB.e[1];

  /* Sum: '<Root>/Sum2' */
  rtB.a0[0] = (rtB.qd_dot_dot[0] + rtB.KD[0]) + rtB.KP[0];

  /* Gain: '<Root>/KP' */
  rtB.KP[1] = 0.0;
  rtB.KP[1] += rtP.KP_Gain[1] * rtB.e[0];
  rtB.KP[1] += rtP.KP_Gain[3] * rtB.e[1];

  /* Sum: '<Root>/Sum2' */
  rtB.a0[1] = (rtB.qd_dot_dot[1] + rtB.KD[1]) + rtB.KP[1];

  /* MATLAB Function: '<Root>/Control' incorporates:
   *  MATLAB Function: '<Root>/Manipulator'
   */
  r = cos(rtB.q[1]);
  t = sin(rtB.q[1]);
  rtb_u_tmp = cos(rtB.q[0] + rtB.q[1]) * 0.12262500000000001;
  rtb_u_tmp_1 = rtb_u_tmp + 0.36787500000000006 * cos(rtB.q[0]);
  rtb_u[0] = ((((((r + 1.25) * 0.025 + 0.00625) + 0.0001) + 0.0001) * rtB.a0[0]
               + ((0.5 * r + 0.25) * 0.025 + 0.0001) * rtB.a0[1]) + rtb_u_tmp_1)
    + (-0.0125 * t * rtB.q_dot[1] * rtB.q_dot[0] + -0.0125 * sin(rtB.q[1]) *
       (rtB.q_dot[0] + rtB.q_dot[1]) * rtB.q_dot[1]);
  rtb_u_tmp_0 = (0.5 * cos(rtB.q[1]) + 0.25) * 0.025 + 0.0001;
  rtb_u[1] = ((rtb_u_tmp_0 * rtB.a0[0] + 0.0063500000000000006 * rtB.a0[1]) +
              rtb_u_tmp) + (0.0125 * t * rtB.q_dot[0] * rtB.q_dot[0] + 0.0 *
    rtB.q_dot[1]);

  /* MATLAB Function: '<Root>/Manipulator' */
  H_idx_0 = (((cos(rtB.q[1]) + 1.25) * 0.025 + 0.00625) + 0.0001) + 0.0001;
  if (fabs(rtb_u_tmp_0) > H_idx_0) {
    r = H_idx_0 / rtb_u_tmp_0;
    t = 1.0 / (r * 0.0063500000000000006 - rtb_u_tmp_0);
    y[0] = 0.0063500000000000006 / rtb_u_tmp_0 * t;
    y[1] = -t;
    y[2] = -rtb_u_tmp_0 / rtb_u_tmp_0 * t;
    y[3] = r * t;
  } else {
    r = rtb_u_tmp_0 / H_idx_0;
    t = 1.0 / (0.0063500000000000006 - r * rtb_u_tmp_0);
    y[0] = 0.0063500000000000006 / H_idx_0 * t;
    y[1] = -r * t;
    y[2] = -rtb_u_tmp_0 / H_idx_0 * t;
    y[3] = t;
  }

  B_0[0] = rtb_u[0] - ((-0.0125 * sin(rtB.q[1]) * rtB.q_dot[1] * rtB.q_dot[0] +
                        -0.0125 * sin(rtB.q[1]) * (rtB.q_dot[0] + rtB.q_dot[1]) *
                        rtB.q_dot[1]) + rtb_u_tmp_1);
  B_0[1] = rtb_u[1] - ((0.0125 * sin(rtB.q[1]) * rtB.q_dot[0] * rtB.q_dot[0] +
                        0.0 * rtB.q_dot[1]) + rtb_u_tmp);
  if (fabs(y[1]) > fabs(y[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }

  r = y[r2] / y[r1];
  t = y[r1 + 2];
  rtB.q_dot_dot[1] = (B_0[r2] - B_0[r1] * r) / (y[r2 + 2] - t * r);
  rtB.q_dot_dot[0] = (B_0[r1] - t * rtB.q_dot_dot[1]) / y[r1];
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
  real_T (*lastU)[2];

  /* Update for Derivative: '<Root>/Derivative' */
  if (rtDW.TimeStampA == (rtInf)) {
    rtDW.TimeStampA = ssGetT(rtS);
    lastU = &rtDW.LastUAtTimeA;
  } else if (rtDW.TimeStampB == (rtInf)) {
    rtDW.TimeStampB = ssGetT(rtS);
    lastU = &rtDW.LastUAtTimeB;
  } else if (rtDW.TimeStampA < rtDW.TimeStampB) {
    rtDW.TimeStampA = ssGetT(rtS);
    lastU = &rtDW.LastUAtTimeA;
  } else {
    rtDW.TimeStampB = ssGetT(rtS);
    lastU = &rtDW.LastUAtTimeB;
  }

  (*lastU)[0] = rtB.qd[0];
  (*lastU)[1] = rtB.qd[1];

  /* End of Update for Derivative: '<Root>/Derivative' */

  /* Update for Derivative: '<Root>/Derivative1' */
  if (rtDW.TimeStampA_j == (rtInf)) {
    rtDW.TimeStampA_j = ssGetT(rtS);
    lastU = &rtDW.LastUAtTimeA_d;
  } else if (rtDW.TimeStampB_i == (rtInf)) {
    rtDW.TimeStampB_i = ssGetT(rtS);
    lastU = &rtDW.LastUAtTimeB_e;
  } else if (rtDW.TimeStampA_j < rtDW.TimeStampB_i) {
    rtDW.TimeStampA_j = ssGetT(rtS);
    lastU = &rtDW.LastUAtTimeA_d;
  } else {
    rtDW.TimeStampB_i = ssGetT(rtS);
    lastU = &rtDW.LastUAtTimeB_e;
  }

  (*lastU)[0] = rtB.qd_dot[0];
  (*lastU)[1] = rtB.qd_dot[1];

  /* End of Update for Derivative: '<Root>/Derivative1' */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void MdlDerivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) ssGetdX(rtS));

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = rtB.q_dot[0];

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = rtB.q_dot_dot[0];

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[1] = rtB.q_dot[1];

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = rtB.q_dot_dot[1];
}

/* Projection for root system: '<Root>' */
void MdlProjection(void)
{
}

/* Termination for root system: '<Root>' */
void MdlTerminate(void)
{
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 4);          /* Number of continuous states */
  ssSetNumPeriodicContStates(rtS, 0); /* Number of periodic continuous states */
  ssSetNumY(rtS, 0);                   /* Number of model outputs */
  ssSetNumU(rtS, 0);                   /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 0);      /* The model is not direct feedthrough */
  ssSetNumSampleTimes(rtS, 1);         /* Number of sample times */
  ssSetNumBlocks(rtS, 22);             /* Number of blocks */
  ssSetNumBlockIO(rtS, 11);            /* Number of block outputs */
  ssSetNumBlockParams(rtS, 20);        /* Sum of parameter "widths" */
}

/* Function to initialize sample times. */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
}

/* Function to register the model */
/* Turns off all optimizations on Windows because of issues with VC 2015 compiler.
   This function is not performance-critical, hence this is not a problem.
 */
#if defined(_MSC_VER)

#pragma optimize( "", off )

#endif

SimStruct * RR(void)
{
  static struct _ssMdlInfo mdlInfo;
  (void) memset((char *)rtS, 0,
                sizeof(SimStruct));
  (void) memset((char *)&mdlInfo, 0,
                sizeof(struct _ssMdlInfo));
  ssSetMdlInfoPtr(rtS, &mdlInfo);

  /* timing info */
  {
    static time_T mdlPeriod[NSAMPLE_TIMES];
    static time_T mdlOffset[NSAMPLE_TIMES];
    static time_T mdlTaskTimes[NSAMPLE_TIMES];
    static int_T mdlTsMap[NSAMPLE_TIMES];
    static int_T mdlSampleHits[NSAMPLE_TIMES];
    static boolean_T mdlTNextWasAdjustedPtr[NSAMPLE_TIMES];
    static int_T mdlPerTaskSampleHits[NSAMPLE_TIMES * NSAMPLE_TIMES];
    static time_T mdlTimeOfNextSampleHit[NSAMPLE_TIMES];

    {
      int_T i;
      for (i = 0; i < NSAMPLE_TIMES; i++) {
        mdlPeriod[i] = 0.0;
        mdlOffset[i] = 0.0;
        mdlTaskTimes[i] = 0.0;
        mdlTsMap[i] = i;
        mdlSampleHits[i] = 1;
      }
    }

    ssSetSampleTimePtr(rtS, &mdlPeriod[0]);
    ssSetOffsetTimePtr(rtS, &mdlOffset[0]);
    ssSetSampleTimeTaskIDPtr(rtS, &mdlTsMap[0]);
    ssSetTPtr(rtS, &mdlTaskTimes[0]);
    ssSetSampleHitPtr(rtS, &mdlSampleHits[0]);
    ssSetTNextWasAdjustedPtr(rtS, &mdlTNextWasAdjustedPtr[0]);
    ssSetPerTaskSampleHitsPtr(rtS, &mdlPerTaskSampleHits[0]);
    ssSetTimeOfNextSampleHitPtr(rtS, &mdlTimeOfNextSampleHit[0]);
  }

  ssSetSolverMode(rtS, SOLVER_MODE_SINGLETASKING);

  /*
   * initialize model vectors and cache them in SimStruct
   */

  /* block I/O */
  {
    ssSetBlockIO(rtS, ((void *) &rtB));
    (void) memset(((void *) &rtB), 0,
                  sizeof(B));
  }

  /* states (continuous)*/
  {
    real_T *x = (real_T *) &rtX;
    ssSetContStates(rtS, x);
    (void) memset((void *)x, 0,
                  sizeof(X));
  }

  /* states (dwork) */
  {
    void *dwork = (void *) &rtDW;
    ssSetRootDWork(rtS, dwork);
    (void) memset(dwork, 0,
                  sizeof(DW));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ssSetModelMappingInfo(rtS, &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Model specific registration */
  ssSetRootSS(rtS, rtS);
  ssSetVersion(rtS, SIMSTRUCT_VERSION_LEVEL2);
  ssSetModelName(rtS, "RR");
  ssSetPath(rtS, "RR");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 20.0);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ssSetRTWLogInfo(rtS, &rt_DataLoggingInfo);
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogXSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogT(ssGetRTWLogInfo(rtS), "tout");
    rtliSetLogX(ssGetRTWLogInfo(rtS), "");
    rtliSetLogXFinal(ssGetRTWLogInfo(rtS), "");
    rtliSetLogVarNameModifier(ssGetRTWLogInfo(rtS), "rt_");
    rtliSetLogFormat(ssGetRTWLogInfo(rtS), 4);
    rtliSetLogMaxRows(ssGetRTWLogInfo(rtS), 0);
    rtliSetLogDecimation(ssGetRTWLogInfo(rtS), 1);
    rtliSetLogY(ssGetRTWLogInfo(rtS), "");
    rtliSetLogYSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogYSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
  }

  {
    static struct _ssStatesInfo2 statesInfo2;
    ssSetStatesInfo2(rtS, &statesInfo2);
  }

  {
    static ssPeriodicStatesInfo periodicStatesInfo;
    ssSetPeriodicStatesInfo(rtS, &periodicStatesInfo);
  }

  {
    static ssJacobianPerturbationBounds jacobianPerturbationBounds;
    ssSetJacobianPerturbationBounds(rtS, &jacobianPerturbationBounds);
  }

  {
    static ssSolverInfo slvrInfo;
    static boolean_T contStatesDisabled[4];
    static real_T absTol[4] = { 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6 };

    static uint8_T absTolControl[4] = { 0U, 0U, 0U, 0U };

    static real_T contStateJacPerturbBoundMinVec[4];
    static real_T contStateJacPerturbBoundMaxVec[4];

    /* Initialize cont state perturbation bound */
    {
      int i;
      for (i = 0; i < 4; ++i) {
        contStateJacPerturbBoundMinVec[i] = 0;
        contStateJacPerturbBoundMaxVec[i] = rtGetInf();
      }
    }

    ssSetSolverRelTol(rtS, 0.001);
    ssSetStepSize(rtS, 0.0);
    ssSetMinStepSize(rtS, 0.0);
    ssSetMaxNumMinSteps(rtS, -1);
    ssSetMinStepViolatedError(rtS, 0);
    ssSetMaxStepSize(rtS, 0.4);
    ssSetSolverMaxOrder(rtS, -1);
    ssSetSolverRefineFactor(rtS, 1);
    ssSetOutputTimes(rtS, (NULL));
    ssSetNumOutputTimes(rtS, 0);
    ssSetOutputTimesOnly(rtS, 0);
    ssSetOutputTimesIndex(rtS, 0);
    ssSetZCCacheNeedsReset(rtS, 0);
    ssSetDerivCacheNeedsReset(rtS, 0);
    ssSetNumNonContDerivSigInfos(rtS, 0);
    ssSetNonContDerivSigInfos(rtS, (NULL));
    ssSetSolverInfo(rtS, &slvrInfo);
    ssSetSolverName(rtS, "VariableStepAuto");
    ssSetVariableStepSolver(rtS, 1);
    ssSetSolverConsistencyChecking(rtS, 0);
    ssSetSolverAdaptiveZcDetection(rtS, 0);
    ssSetSolverRobustResetMethod(rtS, 0);
    ssSetAbsTolVector(rtS, absTol);
    ssSetAbsTolControlVector(rtS, absTolControl);
    ssSetSolverAbsTol_Obsolete(rtS, absTol);
    ssSetSolverAbsTolControl_Obsolete(rtS, absTolControl);
    ssSetJacobianPerturbationBoundsMinVec(rtS, contStateJacPerturbBoundMinVec);
    ssSetJacobianPerturbationBoundsMaxVec(rtS, contStateJacPerturbBoundMaxVec);
    ssSetSolverStateProjection(rtS, 0);
    ssSetSolverMassMatrixType(rtS, (ssMatrixType)0);
    ssSetSolverMassMatrixNzMax(rtS, 0);
    ssSetModelOutputs(rtS, MdlOutputs);
    ssSetModelLogData(rtS, rt_UpdateTXYLogVars);
    ssSetModelLogDataIfInInterval(rtS, rt_UpdateTXXFYLogVars);
    ssSetModelUpdate(rtS, MdlUpdate);
    ssSetModelDerivatives(rtS, MdlDerivatives);
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
    ssSetSolverShapePreserveControl(rtS, 2);
    ssSetTNextTid(rtS, INT_MIN);
    ssSetTNext(rtS, rtMinusInf);
    ssSetSolverNeedsReset(rtS);
    ssSetNumNonsampledZCs(rtS, 0);
    ssSetContStateDisabled(rtS, contStatesDisabled);
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
  }

  ssSetChecksumVal(rtS, 0, 2874293658U);
  ssSetChecksumVal(rtS, 1, 2612012124U);
  ssSetChecksumVal(rtS, 2, 246350964U);
  ssSetChecksumVal(rtS, 3, 3673759645U);
  return rtS;
}

/* When you use the on parameter, it resets the optimizations to those that you
   specified with the /O compiler option. */
#if defined(_MSC_VER)

#pragma optimize( "", on )

#endif
