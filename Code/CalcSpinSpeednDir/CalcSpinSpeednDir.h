/*
 * File: CalcSpinSpeednDir.h
 *
 * Code generated for Simulink model 'CalcSpinSpeednDir'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Fri Apr  8 13:08:23 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CalcSpinSpeednDir_h_
#define RTW_HEADER_CalcSpinSpeednDir_h_
#ifndef CalcSpinSpeednDir_COMMON_INCLUDES_
# define CalcSpinSpeednDir_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* CalcSpinSpeednDir_COMMON_INCLUDES_ */

#include "CalcSpinSpeednDir_types.h"

/* Includes for objects with custom storage classes. */
#include "ConstParams.h"

/* Block states (default storage) for model 'CalcSpinSpeednDir' */
typedef struct {
  real32_T UnitDelay3_DSTATE;          /* '<Root>/Unit Delay3' */
  uint16_T Delay_DSTATE;               /* '<Root>/Delay' */
  uint16_T Delay1_DSTATE;              /* '<Root>/Delay1' */
  boolean_T DelayInput1_DSTATE;        /* '<S3>/Delay Input1' */
} DW_CalcSpinSpeednDir_f_T;

/* Zero-crossing (trigger) state for model 'CalcSpinSpeednDir' */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<Root>/Delay' */
} ZCE_CalcSpinSpeednDir_T;

/* Real-time Model Data Structure */
struct tag_RTM_CalcSpinSpeednDir_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_CalcSpinSpeednDir_f_T rtdw;
  RT_MODEL_CalcSpinSpeednDir_T rtm;
  ZCE_CalcSpinSpeednDir_T rtzce;
} MdlrefDW_CalcSpinSpeednDir_T;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T Sig_rpm;               /* '<Root>/Product1' */
extern real32_T Sig_Angular_Velocity_radpsec_m;/* '<Root>/Unit Conversion1' */

/* Model reference registration function */
extern void CalcSpinSpeednDir_initialize(const char_T **rt_errorStatus,
  RT_MODEL_CalcSpinSpeednDir_T *const CalcSpinSpeednDir_M,
  ZCE_CalcSpinSpeednDir_T *localZCE);
extern void CalcSpinSpeednDir(const real32_T *rtu_Thetael,
  DW_CalcSpinSpeednDir_f_T *localDW, ZCE_CalcSpinSpeednDir_T *localZCE);

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
 * '<Root>' : 'CalcSpinSpeednDir'
 * '<S1>'   : 'CalcSpinSpeednDir/Compare To Constant'
 * '<S2>'   : 'CalcSpinSpeednDir/Compare To Constant1'
 * '<S3>'   : 'CalcSpinSpeednDir/Update the signal in rising edge'
 */
#endif                                 /* RTW_HEADER_CalcSpinSpeednDir_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
