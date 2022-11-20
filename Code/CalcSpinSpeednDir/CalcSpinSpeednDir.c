/*
 * File: CalcSpinSpeednDir.c
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

#include "CalcSpinSpeednDir.h"
#include "CalcSpinSpeednDir_private.h"

/* Exported block signals */
real32_T Sig_rpm;                      /* '<Root>/Switch' */
real32_T Sig_Angular_Velocity_radpsec_m;/* '<Root>/Unit Conversion1' */

/* Block states (default storage) */
DW_CalcSpinSpeednDir_T CalcSpinSpeednDir_DW;

/* External inputs (root inport signals with default storage) */
ExtU_CalcSpinSpeednDir_T CalcSpinSpeednDir_U;

/* Real-time model */
RT_MODEL_CalcSpinSpeednDir_T CalcSpinSpeednDir_M_;
RT_MODEL_CalcSpinSpeednDir_T *const CalcSpinSpeednDir_M = &CalcSpinSpeednDir_M_;

/* Model step function */
void CalcSpinSpeednDir_step(void)
{
  real32_T rtb_Add;

  /* Sum: '<Root>/Add' incorporates:
   *  Inport: '<Root>/Theta el'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  rtb_Add = Sig_Theta_el_cont_m - CalcSpinSpeednDir_DW.UnitDelay_DSTATE;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Logic: '<Root>/NOT'
   *  Product: '<Root>/Divide'
   *  RelationalOperator: '<S1>/Compare'
   */
  if (!(rtb_Add < 0.0F)) {
    /* Product: '<Root>/Divide' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<Root>/Constant2'
     */
    rtb_Add = floorf(rtb_Add / 6.28F);
    if (rtIsNaNF(rtb_Add) || rtIsInfF(rtb_Add)) {
      rtb_Add = 0.0F;
    } else {
      rtb_Add = fmodf(rtb_Add, 4.2949673E+9F);
    }

    rtb_Add = floorf((real32_T)(rtb_Add < 0.0F ? -(int32_T)(uint32_T)-rtb_Add :
      (int32_T)(uint32_T)rtb_Add) / (real32_T)polepairs);
    if (rtIsNaNF(rtb_Add) || rtIsInfF(rtb_Add)) {
      rtb_Add = 0.0F;
    } else {
      rtb_Add = fmodf(rtb_Add, 4.2949673E+9F);
    }

    Sig_rpm = (real32_T)(rtb_Add < 0.0F ? -(int32_T)(uint32_T)-rtb_Add :
                         (int32_T)(uint32_T)rtb_Add);
  }

  /* End of Switch: '<Root>/Switch' */

  /* UnitConversion: '<Root>/Unit Conversion1' */
  /* Unit Conversion - from: rpm to: rad/sec
     Expression: output = (0.10472*input) + (0) */
  Sig_Angular_Velocity_radpsec_m = 0.104719758F * Sig_rpm;

  /* Update for UnitDelay: '<Root>/Unit Delay' incorporates:
   *  Inport: '<Root>/Theta el'
   */
  CalcSpinSpeednDir_DW.UnitDelay_DSTATE = Sig_Theta_el_cont_m;
}

/* Model initialize function */
void CalcSpinSpeednDir_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void CalcSpinSpeednDir_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
