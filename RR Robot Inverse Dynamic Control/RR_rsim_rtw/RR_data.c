/*
 * RR_data.c
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

#include "RR.h"
#include "RR_private.h"

/* Block parameters (default storage) */
P rtP = {
  /* Expression: pi/4
   * Referenced by: '<Root>/pi//4.cost'
   */
  0.78539816339744828,

  /* Expression: 0
   * Referenced by: '<Root>/pi//4.cost'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/pi//4.cost'
   */
  1.0,

  /* Expression: pi/2
   * Referenced by: '<Root>/pi//4.cost'
   */
  1.5707963267948966,

  /* Expression: pi/6
   * Referenced by: '<Root>/pi//6.cos(2t+pi//4)'
   */
  0.52359877559829882,

  /* Expression: 0
   * Referenced by: '<Root>/pi//6.cos(2t+pi//4)'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<Root>/pi//6.cos(2t+pi//4)'
   */
  2.0,

  /* Expression: pi/4
   * Referenced by: '<Root>/pi//6.cos(2t+pi//4)'
   */
  0.78539816339744828,

  /* Expression: [0;0]
   * Referenced by: '<Root>/Integrator1'
   */
  { 0.0, 0.0 },

  /* Expression: [0;0]
   * Referenced by: '<Root>/Integrator'
   */
  { 0.0, 0.0 },

  /* Expression: [0.99 0;0 0.99]
   * Referenced by: '<Root>/KD'
   */
  { 0.99, 0.0, 0.0, 0.99 },

  /* Expression: [1.155 0;0 1.155]
   * Referenced by: '<Root>/KP'
   */
  { 1.155, 0.0, 0.0, 1.155 }
};
