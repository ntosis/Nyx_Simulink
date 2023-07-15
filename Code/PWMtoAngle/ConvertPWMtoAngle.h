/*
 * File: ConvertPWMtoAngle.h
 *
 * Code generated for Simulink model 'ConvertPWMtoAngle'.
 *
 * Model version                  : 7.4
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 28 17:27:38 2022
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

/* Block signals for model 'ConvertPWMtoAngle' */
#ifndef ConvertPWMtoAngle_MDLREF_HIDE_CHILD_

typedef struct {
  real_T UnitDelay;                    /* '<S9>/Unit Delay' */
  uint32_T Add4;                       /* '<S10>/Add4' */
  uint32_T EncoderCounterIn;           /* '<S5>/EncoderCounterIn' */
} B_ConvertPWMtoAngle_c_T;

#endif                                 /*ConvertPWMtoAngle_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'ConvertPWMtoAngle' */
#ifndef ConvertPWMtoAngle_MDLREF_HIDE_CHILD_

typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S9>/Unit Delay' */
  uint32_T UnitDelay_DSTATE_m;         /* '<Root>/Unit Delay' */
  uint32_T UnitDelay_DSTATE_i;         /* '<S1>/Unit Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S4>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE;         /* '<S1>/Unit Delay1' */
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
extern real32_T continuesAngle;        /* '<S1>/Merge' */
extern real32_T initialAngle;          /* '<S5>/Data Type Conversion' */
extern real32_T  Sig_MechanicalAngle;
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
 * Block '<S5>/Constant1' : Unused code path elimination
 * Block '<S5>/Mod' : Unused code path elimination
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
 * '<S3>'   : 'ConvertPWMtoAngle/Compare To Constant1'
 * '<S4>'   : 'ConvertPWMtoAngle/Detect Decrease'
 * '<S5>'   : 'ConvertPWMtoAngle/Initialize angle from PWM sensor'
 * '<S6>'   : 'ConvertPWMtoAngle/Calculate angle from encoder sensor/Compare To Constant'
 * '<S7>'   : 'ConvertPWMtoAngle/Calculate angle from encoder sensor/CounterHasOverflowed'
 * '<S8>'   : 'ConvertPWMtoAngle/Calculate angle from encoder sensor/CounterIsInNoramlOperation'
 * '<S9>'   : 'ConvertPWMtoAngle/Calculate angle from encoder sensor/EnableOnFirstExec'
 * '<S10>'  : 'ConvertPWMtoAngle/Calculate angle from encoder sensor/CounterHasOverflowed/underflow case'
 */
#endif                                 /* RTW_HEADER_ConvertPWMtoAngle_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
