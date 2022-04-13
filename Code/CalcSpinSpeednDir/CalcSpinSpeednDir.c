/*
 * File: CalcSpinSpeednDir.c
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

#include "CalcSpinSpeednDir.h"
#include "CalcSpinSpeednDir_private.h"

/* Output and update for referenced model: 'CalcSpinSpeednDir' */
void CalcSpinSpeednDir(const real32_T *rtu_Thetael, DW_CalcSpinSpeednDir_f_T
  *localDW, ZCE_CalcSpinSpeednDir_T *localZCE)
{
  boolean_T rtb_OR;

  /* Sum: '<Root>/Add1' incorporates:
   *  UnitDelay: '<Root>/Unit Delay3'
   */
  localDW->UnitDelay3_DSTATE -= *rtu_Thetael;

  /* Logic: '<Root>/OR' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   *  RelationalOperator: '<S2>/Compare'
   *  UnitDelay: '<Root>/Unit Delay3'
   */
  rtb_OR = ((localDW->UnitDelay3_DSTATE >= 5.0F) || (localDW->UnitDelay3_DSTATE <=
             -5.0F));

  /* Delay: '<Root>/Delay' */
  if ((!rtb_OR) && (localZCE->Delay_Reset_ZCE != ZERO_ZCSIG)) {
    localDW->Delay_DSTATE = 0U;
  }

  localZCE->Delay_Reset_ZCE = rtb_OR;

  /* Sum: '<Root>/Add5' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Delay: '<Root>/Delay'
   */
  localDW->Delay_DSTATE++;

  /* Switch: '<Root>/Switch2' incorporates:
   *  Delay: '<Root>/Delay'
   *  Delay: '<Root>/Delay1'
   *  RelationalOperator: '<S3>/FixPt Relational Operator'
   *  UnitDelay: '<S3>/Delay Input1'
   *
   * Block description for '<S3>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((int32_T)rtb_OR > (int32_T)localDW->DelayInput1_DSTATE) {
    localDW->Delay1_DSTATE = localDW->Delay_DSTATE;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* Product: '<Root>/Product' incorporates:
   *  Constant: '<Root>/Constant'
   *  Delay: '<Root>/Delay1'
   *  UnitDelay: '<Root>/Unit Delay3'
   */
  localDW->UnitDelay3_DSTATE = (real32_T)localDW->Delay1_DSTATE * 0.0002F;

  /* Product: '<Root>/Divide' incorporates:
   *  UnitDelay: '<Root>/Unit Delay3'
   */
  localDW->UnitDelay3_DSTATE = 1.0F / localDW->UnitDelay3_DSTATE;

  /* Product: '<Root>/Product1' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Gain: '<Root>/Hz to Rpm'
   *  UnitDelay: '<Root>/Unit Delay3'
   */
  Sig_rpm = 60.0F * localDW->UnitDelay3_DSTATE * (1.0F / (real32_T)p);

  /* UnitConversion: '<Root>/Unit Conversion1' */
  /* Unit Conversion - from: rpm to: rad/sec
     Expression: output = (0.10472*input) + (0) */
  Sig_Angular_Velocity_radpsec_m = 0.104719758F * Sig_rpm;

  /* Update for UnitDelay: '<Root>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE = *rtu_Thetael;

  /* Update for UnitDelay: '<S3>/Delay Input1'
   *
   * Block description for '<S3>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtb_OR;
}

/* Model initialize function */
void CalcSpinSpeednDir_initialize(const char_T **rt_errorStatus,
  RT_MODEL_CalcSpinSpeednDir_T *const CalcSpinSpeednDir_M,
  ZCE_CalcSpinSpeednDir_T *localZCE)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(CalcSpinSpeednDir_M, rt_errorStatus);
  localZCE->Delay_Reset_ZCE = ZERO_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
