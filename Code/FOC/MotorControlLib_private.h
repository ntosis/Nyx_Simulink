/*
 * File: MotorControlLib_private.h
 *
 * Code generated for Simulink model 'MotorControlLib'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Fri Oct 28 10:27:56 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MotorControlLib_private_h_
#define RTW_HEADER_MotorControlLib_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "MotorControlLib.h"

/* Includes for objects with custom storage classes. */
#include "InterfaceBswApp.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern const real32_T rtCP_pooled_ixJ5snPtuZfQ[502];
extern const boolean_T rtCP_pooled_h9SS684EhrQx[16];

#define rtCP_sine_table_values_Value   rtCP_pooled_ixJ5snPtuZfQ  /* Computed Parameter: rtCP_sine_table_values_Value
                                                                  * Referenced by: '<S14>/sine_table_values'
                                                                  */
#define rtCP_Logic_table               rtCP_pooled_h9SS684EhrQx  /* Computed Parameter: rtCP_Logic_table
                                                                  * Referenced by: '<S149>/Logic'
                                                                  */
#define rtCP_Logic_table_m             rtCP_pooled_h9SS684EhrQx  /* Computed Parameter: rtCP_Logic_table_m
                                                                  * Referenced by: '<S150>/Logic'
                                                                  */

/* Imported (extern) block signals */
extern uint32_T EncoderCounter;        /* '<Root>/Input1' */
extern uint16_T Duty;                  /* '<Root>/Input' */
extern void MotorControlLib_DQ_Limiter(real32_T rtu_Vd_ref, real32_T rtu_Vq_ref,
  real32_T rty_Vd_sat[2], real32_T *rty_Vmax_unsat, int16_T rtp_Vmax);
extern void MotorControlLib_Flux_observer(boolean_T rtu_Enable, real32_T rtu_In1,
  real32_T rtu_In2, real32_T rtu_In3, real32_T rtu_In4, int16_T
  *rty_FluxObsAngle, B_Flux_observer_MotorControlL_T *localB, const
  ConstB_Flux_observer_MotorCon_T *localC, DW_Flux_observer_MotorControl_T
  *localDW, ZCE_Flux_observer_MotorContro_T *localZCE);
extern real32_T MotorControlLib_PIDAxis(real32_T rtu_error, int16_T rtu_P,
  int16_T rtu_I, boolean_T rtu_Reset, DW_PIDAxis_MotorControlLib_T *localDW);
extern real32_T MotorControlLib_PIQaxis(real32_T rtu_error, real32_T rtu_P,
  real32_T rtu_I, boolean_T rtu_Reset, DW_PIQaxis_MotorControlLib_T *localDW);
extern void MotorCon_Positionobserver_Reset(DW_Positionobserver_MotorCont_T
  *localDW);
extern void MotorC_Positionobserver_Disable(DW_Positionobserver_MotorCont_T
  *localDW);
extern void MotorControlLi_Positionobserver(RT_MODEL_MotorControlLib_T * const
  MotorControlLib_M, boolean_T rtu_Enable, real32_T rtu_Va, real32_T rtu_Vb,
  real32_T rtu_Ia, real32_T rtu_Ib, boolean_T rtu_In5, int16_T *rty_theta,
  B_Positionobserver_MotorContr_T *localB, DW_Positionobserver_MotorCont_T
  *localDW, ZCE_Positionobserver_MotorCon_T *localZCE);

#endif                               /* RTW_HEADER_MotorControlLib_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
