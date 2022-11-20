/*
 * File: ConvertPWMtoAngle.h
 *
 * Code generated for Simulink model 'ConvertPWMtoAngle'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Nov  2 09:21:15 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ConvertPWMtoAngle_h_
#define RTW_HEADER_ConvertPWMtoAngle_h_
#ifndef ConvertPWMtoAngle_COMMON_INCLUDES_
# define ConvertPWMtoAngle_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ConvertPWMtoAngle_COMMON_INCLUDES_ */

#include "ConvertPWMtoAngle_types.h"

/* Includes for objects with custom storage classes. */
#include "PWMtoAngle_const.h"
#include "ConstParams.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Block signals for model 'ConvertPWMtoAngle' */
#ifndef ConvertPWMtoAngle_MDLREF_HIDE_CHILD_

typedef struct {
  real_T UnitDelay;                    /* '<S8>/Unit Delay' */
  uint32_T Add4;                       /* '<S9>/Add4' */
} B_ConvertPWMtoAngle_c_T;

#endif                                 /*ConvertPWMtoAngle_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'ConvertPWMtoAngle' */
#ifndef ConvertPWMtoAngle_MDLREF_HIDE_CHILD_

typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S8>/Unit Delay' */
  uint32_T UnitDelay_DSTATE_m;         /* '<Root>/Unit Delay' */
  uint32_T UnitDelay_DSTATE_i;         /* '<S3>/Unit Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S2>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE;         /* '<S3>/Unit Delay1' */
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

extern void ConvertPWMtoAngle(const int16_T *rtu_qSollin, const boolean_T
  *rtu_detectStartUpin, const real32_T *rtu_AngleMecIn, real32_T *rty_AngleElec,
  real32_T *rty_AnlgleMec);

/* Model reference registration function */
extern void ConvertPWMtoAngle_initialize(const char_T **rt_errorStatus);

#ifndef ConvertPWMtoAngle_MDLREF_HIDE_CHILD_

extern MdlrefDW_ConvertPWMtoAngle_T ConvertPWMtoAngle_MdlrefDW;

#endif                                 /*ConvertPWMtoAngle_MDLREF_HIDE_CHILD_*/

#ifndef ConvertPWMtoAngle_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_ConvertPWMtoAngle_c_T ConvertPWMtoAngle_B;

/* Block states (default storage) */
extern DW_ConvertPWMtoAngle_f_T ConvertPWMtoAngle_DW;

#endif                                 /*ConvertPWMtoAngle_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Constant1' : Unused code path elimination
 * Block '<S7>/Mod' : Unused code path elimination
 * Block '<S4>/Constant1' : Unused code path elimination
 * Block '<S4>/Mod' : Unused code path elimination
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
 * '<S1>'   : 'ConvertPWMtoAngle/Compare To Constant'
 * '<S2>'   : 'ConvertPWMtoAngle/Detect Decrease'
 * '<S3>'   : 'ConvertPWMtoAngle/If Action Subsystem1'
 * '<S4>'   : 'ConvertPWMtoAngle/Subsystem'
 * '<S5>'   : 'ConvertPWMtoAngle/If Action Subsystem1/Compare To Constant'
 * '<S6>'   : 'ConvertPWMtoAngle/If Action Subsystem1/CounterHasOverflowed'
 * '<S7>'   : 'ConvertPWMtoAngle/If Action Subsystem1/CounterIsInNoramlOperation'
 * '<S8>'   : 'ConvertPWMtoAngle/If Action Subsystem1/EnableOnFirstExec'
 * '<S9>'   : 'ConvertPWMtoAngle/If Action Subsystem1/CounterHasOverflowed/underflow case'
 */
#endif                                 /* RTW_HEADER_ConvertPWMtoAngle_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
