/*
 * File: ConvertPWMtoAngle.h
 *
 * Code generated for Simulink model 'ConvertPWMtoAngle'.
 *
 * Model version                  : 7.27
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jul  4 23:01:13 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ConvertPWMtoAngle_h_
#define RTW_HEADER_ConvertPWMtoAngle_h_
#ifndef ConvertPWMtoAngle_COMMON_INCLUDES_
#define ConvertPWMtoAngle_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ConvertPWMtoAngle_COMMON_INCLUDES_ */

#include "ConvertPWMtoAngle_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Includes for objects with custom storage classes */
#include "PWMtoAngle_const.h"
#include "ConstParams.h"

/* Block states (default storage) for model 'ConvertPWMtoAngle' */
#ifndef ConvertPWMtoAngle_MDLREF_HIDE_CHILD_

typedef struct {
  int32_T UnitDelay_DSTATE;            /* '<Root>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_l;          /* '<S6>/Unit Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S4>/Delay Input1' */
} DW_ConvertPWMtoAngle_f_T;

#endif                                 /*ConvertPWMtoAngle_MDLREF_HIDE_CHILD_*/

#ifndef ConvertPWMtoAngle_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_ConvertPWMtoAngle_T {
  const char_T **errorStatus;
};

#endif                                 /*ConvertPWMtoAngle_MDLREF_HIDE_CHILD_*/

#ifndef ConvertPWMtoAngle_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_ConvertPWMtoAngle_T rtm;
} MdlrefDW_ConvertPWMtoAngle_T;

#endif                                 /*ConvertPWMtoAngle_MDLREF_HIDE_CHILD_*/

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T afterMergeAngle_tst;   /* '<Root>/Merge' */
extern real32_T initialAngle;          /* '<S5>/Data Type Conversion' */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern int32_T EncoderCounterOld;      /* '<S1>/Unit Delay' */
extern boolean_T Sig_invert_angleElec; /* '<Root>/Data Store Memory' */
extern void ConvertPWMtoAngle(const boolean_T *rtu_UsersInputIsNull, const
  real32_T *rtu_AngleMecIn, real32_T *rty_AngleElec, real32_T *rty_AnlgleMec);

/* Model reference registration function */
extern void ConvertPWMtoAngle_initialize(const char_T **rt_errorStatus);

#ifndef ConvertPWMtoAngle_MDLREF_HIDE_CHILD_

extern MdlrefDW_ConvertPWMtoAngle_T ConvertPWMtoAngle_MdlrefDW;

#endif                                 /*ConvertPWMtoAngle_MDLREF_HIDE_CHILD_*/

#ifndef ConvertPWMtoAngle_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_ConvertPWMtoAngle_f_T ConvertPWMtoAngle_DW;

#endif                                 /*ConvertPWMtoAngle_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
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
 * '<Root>' : 'ConvertPWMtoAngle'
 * '<S1>'   : 'ConvertPWMtoAngle/Calculate angle from encoder sensor'
 * '<S2>'   : 'ConvertPWMtoAngle/Compare To Constant'
 * '<S3>'   : 'ConvertPWMtoAngle/Compare To Zero'
 * '<S4>'   : 'ConvertPWMtoAngle/Detect Decrease'
 * '<S5>'   : 'ConvertPWMtoAngle/Initialize angle from PWM sensor'
 * '<S6>'   : 'ConvertPWMtoAngle/isTheFirstExec'
 * '<S7>'   : 'ConvertPWMtoAngle/Calculate angle from encoder sensor/Subsystem'
 * '<S8>'   : 'ConvertPWMtoAngle/Calculate angle from encoder sensor/Subsystem1'
 * '<S9>'   : 'ConvertPWMtoAngle/isTheFirstExec/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_ConvertPWMtoAngle_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
