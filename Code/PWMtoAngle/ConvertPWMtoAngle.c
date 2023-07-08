/*
 * File: ConvertPWMtoAngle.c
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

#include "ConvertPWMtoAngle.h"
#include "rtwtypes.h"
#include "rt_modf_snf.h"
#include "ConvertPWMtoAngle_private.h"
#include "PWMtoAngle_const.h"
#include "ConstParams.h"
#include "rt_nonfinite.h"

/* Exported block signals */
real32_T continuesAngle;               /* '<S1>/Merge' */
real32_T initialAngle;
volatile real32_T PWMAngle; /* '<S5>/Data Type Conversion' */
MdlrefDW_ConvertPWMtoAngle_T ConvertPWMtoAngle_MdlrefDW;

#define pi (3.141592653589793f)
/* Block signals (default storage) */
B_ConvertPWMtoAngle_c_T ConvertPWMtoAngle_B;

/* Block states (default storage) */
DW_ConvertPWMtoAngle_f_T ConvertPWMtoAngle_DW;

/* Output and update for referenced model: 'ConvertPWMtoAngle' */
void ConvertPWMtoAngle(const int16_T *rtu_qSollin, const boolean_T
  *rtu_detectStartUpin, const real32_T *rtu_AngleMecIn, real32_T *rty_AngleElec,
  real32_T *rty_AnlgleMec)
{
  real32_T rtb_Merge;
  boolean_T rtb_Compare;

  /* RelationalOperator: '<S2>/Compare' */
  rtb_Compare = (*rtu_qSollin == 0);

  /* If: '<Root>/If' incorporates:
   *  Logic: '<Root>/OR'
   *  RelationalOperator: '<S4>/FixPt Relational Operator'
   *  UnitDelay: '<S1>/Unit Delay1'
   *  UnitDelay: '<S4>/Delay Input1'
   *
   * Block description for '<S4>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((int32_T)rtb_Compare < (int32_T)ConvertPWMtoAngle_DW.DelayInput1_DSTATE) ||
      (*rtu_detectStartUpin)) {
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
    initialAngle = ((real32_T)Angle_T[(4095U-tmp)] * 0.0009765625F );//+(pi/2);

    /* SignalConversion: '<S5>/Signal Copy1' */
    rtb_Merge = initialAngle;

    /* SignalConversion generated from: '<S5>/EncoderCounterIn' incorporates:
     *  Inport generated from: '<Root>/EncoderCounterIn'
     */
    ConvertPWMtoAngle_B.EncoderCounterIn = EncoderCounter;

    /* End of Outputs for SubSystem: '<Root>/Initialize angle from PWM sensor' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/Calculate angle from encoder sensor' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Outputs for Enabled SubSystem: '<S1>/EnableOnFirstExec' incorporates:
     *  EnablePort: '<S9>/Enable'
     */
    if (ConvertPWMtoAngle_DW.UnitDelay1_DSTATE)  {
      /* UnitDelay: '<S9>/Unit Delay' */
      ConvertPWMtoAngle_B.UnitDelay = ConvertPWMtoAngle_DW.UnitDelay_DSTATE;

      /* Sum: '<S9>/Add' incorporates:
       *  Constant: '<S9>/Constant'
       *  UnitDelay: '<S9>/Unit Delay'
       */
      ConvertPWMtoAngle_DW.UnitDelay_DSTATE = ConvertPWMtoAngle_B.UnitDelay +
        1.0;
    }

    /* End of Outputs for SubSystem: '<S1>/EnableOnFirstExec' */

    /* Switch: '<S1>/Switch' */
    if (ConvertPWMtoAngle_B.UnitDelay > 0.0) {
      /* Switch: '<S1>/Switch' incorporates:
       *  UnitDelay: '<S1>/Unit Delay'
       */
      ConvertPWMtoAngle_DW.UnitDelay_DSTATE_m =
        ConvertPWMtoAngle_DW.UnitDelay_DSTATE_i;
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
      if (EncoderCounter > ConvertPWMtoAngle_DW.UnitDelay_DSTATE_m) {
        /* Sum: '<S10>/Add4' incorporates:
         *  Constant: '<S10>/MaxVal'
         *  Sum: '<S10>/Add3'
         */
        ConvertPWMtoAngle_B.Add4 = (uint16_T)((uint16_T)((uint32_T)(uint16_T)
          ConvertPWMtoAngle_DW.UnitDelay_DSTATE_m - (uint16_T)EncoderCounter) +
          65535U);

        /* Switch: '<S7>/Switch' */
        rtb_Switch_d = ConvertPWMtoAngle_B.Add4;
      } else {
        /* Switch: '<S7>/Switch' incorporates:
         *  Constant: '<S7>/MaxVal-1ToavoidOverflow'
         *  Sum: '<S7>/Add'
         *  Sum: '<S7>/Add1'
         */
        rtb_Switch_d = (uint32_T)(int16_T)((EncoderCounter -
          ConvertPWMtoAngle_DW.UnitDelay_DSTATE_m) + MAX_uint32_T);
      }

      /* End of Outputs for SubSystem: '<S7>/underflow case' */

      /* Sum: '<S7>/Add2' incorporates:
       *  Constant: '<S7>/Constant'
       *  Inport generated from: '<Root>/EncoderCounterIn'
       *  Product: '<S7>/Product'
       *  RelationalOperator: '<S7>/Relational Operator'
       */
      continuesAngle = (degresProCounter * (real32_T)rtb_Switch_d) +
        (Sig_MechanicalAngle); //Sig_MechanicalAngle
      initialAngle = ((real32_T)Angle_T[(4095U-Duty)] * 0.0009765625F );//+(pi/2);
      /* End of Outputs for SubSystem: '<S1>/CounterHasOverflowed' */
    } else {
      /* Outputs for IfAction SubSystem: '<S1>/CounterIsInNoramlOperation' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      /* Sum: '<S8>/Add1' incorporates:
       *  Constant: '<S8>/Constant'
       *  Inport generated from: '<Root>/EncoderCounterIn'
       *  Product: '<S8>/Product'
       *  Sum: '<S8>/Add'
       */
      continuesAngle = (real32_T)((int16_T)((int16_T)EncoderCounter - (int16_T)
        ConvertPWMtoAngle_DW.UnitDelay_DSTATE_m) * degresProCounter) +
        (Sig_MechanicalAngle);

      /* End of Outputs for SubSystem: '<S1>/CounterIsInNoramlOperation' */
    }

    /* End of If: '<S1>/If' */

    /* Logic: '<S1>/NOT' incorporates:
     *  Constant: '<S6>/Constant'
     *  RelationalOperator: '<S6>/Compare'
     *  UnitDelay: '<S1>/Unit Delay1'
     */
    ConvertPWMtoAngle_DW.UnitDelay1_DSTATE = !(ConvertPWMtoAngle_B.UnitDelay >
      0.0);

    /* SignalConversion: '<S1>/Signal Copy' */
    rtb_Merge = continuesAngle;
    /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
     *  Inport generated from: '<Root>/EncoderCounterIn'
     */
    ConvertPWMtoAngle_DW.UnitDelay_DSTATE_i = EncoderCounter;

    /* End of Outputs for SubSystem: '<Root>/Calculate angle from encoder sensor' */
  }

  /* End of If: '<Root>/If' */

  /* Math: '<Root>/Mod' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Product: '<Root>/Product'
   */
  *rty_AngleElec = rt_modf_snf((real32_T)polepairs * rtb_Merge, 6.28318548F);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   *  Sum: '<Root>/Add'
   */
  if (rtb_Merge < 0.0F) {
    *rty_AnlgleMec = rtb_Merge + 6.28318548F;
  } else {
    *rty_AnlgleMec = rtb_Merge;
  }


  /* End of Switch: '<Root>/Switch' */

  /* Update for UnitDelay: '<S4>/Delay Input1'
   *
   * Block description for '<S4>/Delay Input1':
   *
   *  Store in Global RAM
   */
  ConvertPWMtoAngle_DW.DelayInput1_DSTATE = rtb_Compare;

  /* Update for Switch: '<S1>/Switch' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  ConvertPWMtoAngle_DW.UnitDelay_DSTATE_m = ConvertPWMtoAngle_B.EncoderCounterIn;
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
