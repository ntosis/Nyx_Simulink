/*
 * File: MotorControlLib_private.h
 *
 * Code generated for Simulink model 'MotorControlLib'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jul 16 15:23:47 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MotorControlLib_private_h_
#define RTW_HEADER_MotorControlLib_private_h_
#include "rtwtypes.h"
#include "MotorControlLib.h"
#include "MotorControlLib_types.h"

/* Includes for objects with custom storage classes */
#include "InterfaceBswApp.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef CounterFactor_us
#error The value of parameter "CounterFactor_us" is not defined
#endif

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

extern const real32_T rtCP_pooled_7NbV46a8FLEx[502];
extern const boolean_T rtCP_pooled_kUC6nmgO8rex[16];

#define rtCP_sine_table_values_Value   rtCP_pooled_7NbV46a8FLEx  /* Computed Parameter: rtCP_sine_table_values_Value
                                                                  * Referenced by: '<S14>/sine_table_values'
                                                                  */
#define rtCP_Logic_table               rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table
                                                                  * Referenced by: '<S193>/Logic'
                                                                  */
#define rtCP_Logic_table_m             rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table_m
                                                                  * Referenced by: '<S194>/Logic'
                                                                  */

/* Imported (extern) block signals */
extern uint32_T EncoderCounter;        /* '<Root>/Encoder input' */
extern volatile uint16_T Duty;                  /* '<Root>/Duty cycle input' */
extern void MotorControlLi_PIDAxis_Init(DW_PIDAxis_MotorControlLib_T *localDW);
extern void MotorControlLib_PIDAxis(real32_T rtu_error, real32_T rtu_P, real32_T
  rtu_I, boolean_T rtu_Reset, real32_T rtu_init, real32_T *rty_PIDOut,
  DW_PIDAxis_MotorControlLib_T *localDW);
extern void MotorControlLib_DQ_Limiter(real32_T rtu_Vd_ref, real32_T rtu_Vq_ref,
  real32_T rty_Vd_sat[2], real32_T *rty_Vmax_unsat, int16_T rtp_Vmax);
extern void MotorControl_PIDAxis_c_Init(DW_PIDAxis_MotorControlLib_c_T *localDW);
extern real32_T MotorControlLib_PIDAxis_m(real32_T rtu_error, real32_T rtu_P,
  real32_T rtu_I, boolean_T rtu_Reset, real32_T rtu_init,
  DW_PIDAxis_MotorControlLib_c_T *localDW);
extern void M_Task_Calculate_fast_speed(boolean_T rtu_u);

#endif                               /* RTW_HEADER_MotorControlLib_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
