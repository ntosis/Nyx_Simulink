/*
 * File: ConvertPWMtoAngle.c
 *
 * Code generated for Simulink model 'ConvertPWMtoAngle'.
 *
 * Model version                  : 7.11
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Jun 26 15:57:35 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ConvertPWMtoAngle.h"
#include "rtwtypes.h"
#include "rt_modf_snf.h"
#include "ConvertPWMtoAngle_private.h"
#include "PWMtoAngle_const.h"
#include "ConstParams.h"
#include "rt_nonfinite.h"

/* Exported block signals */
real32_T afterMergeAngle_tst;          /* '<Root>/Merge' */
real32_T continuesAngle;               /* '<S1>/Merge' */
real32_T initialAngle;                 /* '<S5>/Data Type Conversion' */
MdlrefDW_ConvertPWMtoAngle_T ConvertPWMtoAngle_MdlrefDW;

/* Block signals (default storage) */
B_ConvertPWMtoAngle_c_T ConvertPWMtoAngle_B;

/* Block states (default storage) */
DW_ConvertPWMtoAngle_f_T ConvertPWMtoAngle_DW;

/*
 * System initialize for atomic system:
 *    '<S1>/isTheFirstExec'
 *    '<Root>/isTheFirstExec'
 */
void ConvertPWMt_isTheFirstExec_Init(DW_isTheFirstExec_ConvertPWMt_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = true;
}

/*
 * Output and update for atomic system:
 *    '<S1>/isTheFirstExec'
 *    '<Root>/isTheFirstExec'
 */
boolean_T ConvertPWMtoAngl_isTheFirstExec(DW_isTheFirstExec_ConvertPWMt_T
  *localDW)
{
  boolean_T rty_startUp_0;

  /* UnitDelay: '<S9>/Unit Delay1' */
  rty_startUp_0 = localDW->UnitDelay1_DSTATE;

  /* Update for UnitDelay: '<S9>/Unit Delay1' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  localDW->UnitDelay1_DSTATE = false;
  return rty_startUp_0;
}

/* System initialize for referenced model: 'ConvertPWMtoAngle' */
void ConvertPWMtoAngle_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/isTheFirstExec' */
  ConvertPWMt_isTheFirstExec_Init(&ConvertPWMtoAngle_DW.isTheFirstExec);

  /* End of SystemInitialize for SubSystem: '<Root>/isTheFirstExec' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/Calculate angle from encoder sensor' */
  /* SystemInitialize for Atomic SubSystem: '<S1>/isTheFirstExec' */
  ConvertPWMt_isTheFirstExec_Init(&ConvertPWMtoAngle_DW.isTheFirstExec_k);

  /* End of SystemInitialize for SubSystem: '<S1>/isTheFirstExec' */
  /* End of SystemInitialize for SubSystem: '<Root>/Calculate angle from encoder sensor' */
}

/* Output and update for referenced model: 'ConvertPWMtoAngle' */
void ConvertPWMtoAngle(const int16_T *rtu_qSollin, const real32_T
  *rtu_AngleMecIn, real32_T *rty_AngleElec, real32_T *rty_AnlgleMec)
{
  boolean_T rtb_Compare;
  boolean_T rtb_isTheFirstStepAfterReset;
  boolean_T rtb_isTheFirstStepAfterReset_g;

  /* RelationalOperator: '<S2>/Compare' */
  rtb_Compare = (*rtu_qSollin == 0);

  /* Outputs for Atomic SubSystem: '<Root>/isTheFirstExec' */
  rtb_isTheFirstStepAfterReset = ConvertPWMtoAngl_isTheFirstExec
    (&ConvertPWMtoAngle_DW.isTheFirstExec);

  /* End of Outputs for SubSystem: '<Root>/isTheFirstExec' */

  /* If: '<Root>/If' incorporates:
   *  Logic: '<Root>/OR'
   *  RelationalOperator: '<S4>/FixPt Relational Operator'
   *  UnitDelay: '<S4>/Delay Input1'
   *
   * Block description for '<S4>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((int32_T)rtb_Compare < (int32_T)ConvertPWMtoAngle_DW.DelayInput1_DSTATE) ||
      rtb_isTheFirstStepAfterReset) {
    uint16_T tmp;

    /* Outputs for IfAction SubSystem: '<Root>/Initialize angle from PWM sensor' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* LookupNDDirect: '<S5>/Direct Lookup Table (n-D)' incorporates:
     *  Inport generated from: '<Root>/DutyIn'
     *
     * About '<S5>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    if (Duty <= 4095) {
      tmp = Duty;
    } else {
      tmp = 4095U;
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
     *  LookupNDDirect: '<S5>/Direct Lookup Table (n-D)'
     *
     * About '<S5>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    initialAngle = (real32_T)Angle_T[tmp] * 0.0009765625F;

    /* Merge: '<Root>/Merge' incorporates:
     *  SignalConversion: '<S5>/Signal Copy1'
     */
    afterMergeAngle_tst = initialAngle;

    /* SignalConversion generated from: '<S5>/EncoderCounterIn' incorporates:
     *  Inport generated from: '<Root>/EncoderCounterIn'
     */
    ConvertPWMtoAngle_B.EncoderCounterIn = EncoderCounter;

    /* End of Outputs for SubSystem: '<Root>/Initialize angle from PWM sensor' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/Calculate angle from encoder sensor' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S1>/isTheFirstExec' */
    rtb_isTheFirstStepAfterReset_g = ConvertPWMtoAngl_isTheFirstExec
      (&ConvertPWMtoAngle_DW.isTheFirstExec_k);

    /* End of Outputs for SubSystem: '<S1>/isTheFirstExec' */

    /* Switch: '<S1>/Switch' */
    if (rtb_isTheFirstStepAfterReset_g) {
      /* Switch: '<S1>/Switch' incorporates:
       *  UnitDelay: '<Root>/Unit Delay'
       */
      ConvertPWMtoAngle_DW.UnitDelay_DSTATE_i =
        ConvertPWMtoAngle_DW.UnitDelay_DSTATE;
    }

    /* End of Switch: '<S1>/Switch' */

    /* If: '<S1>/If' incorporates:
     *  DataStoreRead: '<S1>/Data Store Read'
     *  Inport generated from: '<Root>/EncoderCounterIn'
     *  RelationalOperator: '<S7>/Relational Operator'
     */
    if (EncoderCounterHasOverflowed) {
      uint32_T rtb_Switch_d;

      /* Outputs for IfAction SubSystem: '<S1>/CounterHasOverflowed' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      /* DataStoreWrite: '<S7>/Data Store Write' incorporates:
       *  Logic: '<S7>/NOT'
       */
      EncoderCounterHasOverflowed = false;

      /* Outputs for Enabled SubSystem: '<S7>/underflow case' incorporates:
       *  EnablePort: '<S10>/Enable'
       */
      if (EncoderCounter > ConvertPWMtoAngle_DW.UnitDelay_DSTATE_i) {
        /* Sum: '<S10>/Add4' incorporates:
         *  Constant: '<S10>/MaxVal'
         *  Sum: '<S10>/Add3'
         */
        ConvertPWMtoAngle_B.Add4 = (uint16_T)((uint16_T)((uint32_T)(uint16_T)
          ConvertPWMtoAngle_DW.UnitDelay_DSTATE_i - (uint16_T)EncoderCounter) +
          65535U);

        /* Switch: '<S7>/Switch' */
        rtb_Switch_d = ConvertPWMtoAngle_B.Add4;
      } else {
        /* Switch: '<S7>/Switch' incorporates:
         *  Sum: '<S7>/Add'
         *  Sum: '<S7>/Add1'
         */
        rtb_Switch_d = (uint32_T)(int16_T)(EncoderCounter -
          ConvertPWMtoAngle_DW.UnitDelay_DSTATE_i);
      }

      /* End of Outputs for SubSystem: '<S7>/underflow case' */

      /* Merge: '<S1>/Merge' incorporates:
       *  Constant: '<S7>/Constant'
       *  Inport generated from: '<Root>/EncoderCounterIn'
       *  Product: '<S7>/Product'
       *  RelationalOperator: '<S7>/Relational Operator'
       *  Sum: '<S7>/Add2'
       */
      continuesAngle = degresProCounter * (real32_T)rtb_Switch_d +
        *rtu_AngleMecIn;

      /* End of Outputs for SubSystem: '<S1>/CounterHasOverflowed' */
    } else {
      /* Outputs for IfAction SubSystem: '<S1>/CounterIsInNoramlOperation' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      /* Merge: '<S1>/Merge' incorporates:
       *  Constant: '<S8>/Constant'
       *  Inport generated from: '<Root>/EncoderCounterIn'
       *  Product: '<S8>/Product'
       *  Sum: '<S8>/Add'
       *  Sum: '<S8>/Add1'
       */
      continuesAngle = (real32_T)(int16_T)((int16_T)EncoderCounter - (int16_T)
        ConvertPWMtoAngle_DW.UnitDelay_DSTATE_i) * degresProCounter +
        *rtu_AngleMecIn;

      /* End of Outputs for SubSystem: '<S1>/CounterIsInNoramlOperation' */
    }

    /* End of If: '<S1>/If' */

    /* Merge: '<Root>/Merge' incorporates:
     *  SignalConversion: '<S1>/Signal Copy'
     */
    afterMergeAngle_tst = continuesAngle;

    /* Update for Switch: '<S1>/Switch' incorporates:
     *  Inport generated from: '<Root>/EncoderCounterIn'
     *  UnitDelay: '<S1>/Unit Delay'
     */
    ConvertPWMtoAngle_DW.UnitDelay_DSTATE_i = EncoderCounter;

    /* End of Outputs for SubSystem: '<Root>/Calculate angle from encoder sensor' */
  }

  /* End of If: '<Root>/If' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   *  Sum: '<Root>/Add'
   */
  if (afterMergeAngle_tst < 0.0F) {
    *rty_AnlgleMec = afterMergeAngle_tst + 6.28318548F;
  } else {
    *rty_AnlgleMec = afterMergeAngle_tst;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  DataStoreRead: '<Root>/Data Store Read'
   *  Math: '<Root>/Mod'
   *  Product: '<Root>/Product'
   *  Sum: '<Root>/invert angle'
   */
  if (ConvertPWMtoAngle_DW.Sig_invert_angleElec > 0.0) {
    *rty_AngleElec = rt_modf_snf((real32_T)polepairs * afterMergeAngle_tst,
      6.28318548F);
  } else {
    *rty_AngleElec = 6.28318548F - rt_modf_snf((real32_T)polepairs *
      afterMergeAngle_tst, 6.28318548F);
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Update for UnitDelay: '<S4>/Delay Input1'
   *
   * Block description for '<S4>/Delay Input1':
   *
   *  Store in Global RAM
   */
  ConvertPWMtoAngle_DW.DelayInput1_DSTATE = rtb_Compare;

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  ConvertPWMtoAngle_DW.UnitDelay_DSTATE = ConvertPWMtoAngle_B.EncoderCounterIn;
}

/* Model initialize function */
void ConvertPWMtoAngle_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_ConvertPWMtoAngle_T *const ConvertPWMtoAngle_M =
    &(ConvertPWMtoAngle_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(ConvertPWMtoAngle_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
