/*
 * File: CalcSpinSpeednDir.h
 *
 * Code generated for Simulink model 'CalcSpinSpeednDir'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Mon Apr 11 17:09:17 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CalcSpinSpeednDir_h_
#define RTW_HEADER_CalcSpinSpeednDir_h_
#include <math.h>
#ifndef CalcSpinSpeednDir_COMMON_INCLUDES_
# define CalcSpinSpeednDir_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* CalcSpinSpeednDir_COMMON_INCLUDES_ */

#include "CalcSpinSpeednDir_types.h"

/* Includes for objects with custom storage classes. */
#include "ConstParams.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<Root>/Unit Delay' */
} DW_CalcSpinSpeednDir_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Thetael;                    /* '<Root>/Theta el' */
} ExtU_CalcSpinSpeednDir_T;

/* Real-time Model Data Structure */
struct tag_RTM_CalcSpinSpeednDir_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_CalcSpinSpeednDir_T CalcSpinSpeednDir_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_CalcSpinSpeednDir_T CalcSpinSpeednDir_U;
extern real32_T Sig_Theta_el_cont_m;
/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T Sig_rpm;               /* '<Root>/Switch' */
extern real32_T Sig_Angular_Velocity_radpsec_m;/* '<Root>/Unit Conversion1' */

/* Model entry point functions */
extern void CalcSpinSpeednDir_initialize(void);
extern void CalcSpinSpeednDir_step(void);
extern void CalcSpinSpeednDir_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CalcSpinSpeednDir_T *const CalcSpinSpeednDir_M;

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
 * '<S1>'   : 'CalcSpinSpeednDir/Compare To Zero'
 */
#endif                                 /* RTW_HEADER_CalcSpinSpeednDir_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
