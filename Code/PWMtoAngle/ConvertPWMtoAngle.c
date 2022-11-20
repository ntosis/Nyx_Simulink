/*
 * File: ConvertPWMtoAngle.c
 *
 * Code generated for Simulink model 'ConvertPWMtoAngle'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Mon Oct 31 09:38:40 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ConvertPWMtoAngle.h"
#include "ConvertPWMtoAngle_private.h"
#include <math.h>


MdlrefDW_ConvertPWMtoAngle_T ConvertPWMtoAngle_MdlrefDW;

/* Block signals (default storage) */
B_ConvertPWMtoAngle_c_T ConvertPWMtoAngle_B;

/* Block states (default storage) */
DW_ConvertPWMtoAngle_f_T ConvertPWMtoAngle_DW;
volatile float mecAngle,mecAngleOld;
/* Output and update for referenced model: 'ConvertPWMtoAngle' */
void ConvertPWMtoAngle(const int16_T *rtu_qSollin, const boolean_T
  *rtu_detectStartUpin, const real32_T *rtu_AngleMecIn, real32_T *rty_AngleElec,
  real32_T *rty_AnlgleMec)
{
  boolean_T rtb_Compare;
  uint32_T rtb_Switch;
  uint16_T tmp;

  mecAngle = *rty_AnlgleMec;
  mecAngleOld = *rtu_AngleMecIn;

  /* RelationalOperator: '<S1>/Compare' */
  rtb_Compare = (*rtu_qSollin == 0);

  /* If: '<Root>/If' incorporates:
   *  Inport: '<Root>/EncoderCounterIn'
   *  Inport: '<S4>/EncoderCounterIn'
   *  Logic: '<Root>/OR'
   *  RelationalOperator: '<S2>/FixPt Relational Operator'
   *  UnitDelay: '<Root>/Unit Delay'
   *  UnitDelay: '<S2>/Delay Input1'
   *  UnitDelay: '<S3>/Unit Delay1'
   *
   * Block description for '<S2>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((int32_T)rtb_Compare < (int32_T)ConvertPWMtoAngle_DW.DelayInput1_DSTATE) ||
      (*rtu_detectStartUpin)) {
    /* Outputs for IfAction SubSystem: '<Root>/Subsystem' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* LookupNDDirect: '<S4>/Direct Lookup Table (n-D)' incorporates:
     *  Inport: '<Root>/DutyIn'
     *
     * About '<S4>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     */
    if (Duty < 4095) {
      tmp = Duty;
    } else {
      tmp = 4095U;
    }

    /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
     *  LookupNDDirect: '<S4>/Direct Lookup Table (n-D)'
     *
     * About '<S4>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     */
    *rty_AnlgleMec = (real32_T)Angle_T[tmp] * 0.0009765625F;
    ConvertPWMtoAngle_DW.UnitDelay_DSTATE_m = EncoderCounter;

    /* End of Outputs for SubSystem: '<Root>/Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Outputs for Enabled SubSystem: '<S3>/EnableOnFirstExec' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    if (ConvertPWMtoAngle_DW.UnitDelay1_DSTATE) {
      /* UnitDelay: '<S8>/Unit Delay' */
      ConvertPWMtoAngle_B.UnitDelay = ConvertPWMtoAngle_DW.UnitDelay_DSTATE;

      /* Sum: '<S8>/Add' incorporates:
       *  Constant: '<S8>/Constant'
       *  UnitDelay: '<S8>/Unit Delay'
       */
      ConvertPWMtoAngle_DW.UnitDelay_DSTATE = ConvertPWMtoAngle_B.UnitDelay +
        1.0;
    }

    /* End of Outputs for SubSystem: '<S3>/EnableOnFirstExec' */

    /* Switch: '<S3>/Switch' incorporates:
     *  UnitDelay: '<Root>/Unit Delay'
     */
    if (!(ConvertPWMtoAngle_B.UnitDelay > 0.0)) {
      ConvertPWMtoAngle_DW.UnitDelay_DSTATE_i =
        ConvertPWMtoAngle_DW.UnitDelay_DSTATE_m;
    }

    /* End of Switch: '<S3>/Switch' */

    /* If: '<S3>/If' incorporates:
     *  Inport: '<Root>/EncoderCounterIn'
     *  RelationalOperator: '<S6>/Relational Operator'
     */
    if (EncoderCounterHasOverflowed) {
    	EncoderCounterHasOverflowed = 0;
      /* Outputs for IfAction SubSystem: '<S3>/CounterHasOverflowed' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* Outputs for Enabled SubSystem: '<S6>/underflow case' incorporates:
       *  EnablePort: '<S9>/Enable'
       */
      if (EncoderCounter > ConvertPWMtoAngle_DW.UnitDelay_DSTATE_i) {
        /* Sum: '<S9>/Add4' incorporates:
         *  Constant: '<S9>/MaxVal'
         *  Sum: '<S9>/Add3'
         */
        ConvertPWMtoAngle_B.Add4 = (uint16_T)((65535U - (uint16_T)EncoderCounter)
          + (uint16_T)ConvertPWMtoAngle_DW.UnitDelay_DSTATE_i);

        /* Switch: '<S6>/Switch' */
        rtb_Switch = ConvertPWMtoAngle_B.Add4;
      } else {
        /* Switch: '<S6>/Switch' incorporates:
         *  Constant: '<S6>/MaxVal-1ToavoidOverflow'
         *  Sum: '<S6>/Add'
         *  Sum: '<S6>/Add1'
         */
        rtb_Switch = (uint32_T)(int16_T)((EncoderCounter -
          ConvertPWMtoAngle_DW.UnitDelay_DSTATE_i) + MAX_uint32_T);
      }

      /* End of Outputs for SubSystem: '<S6>/underflow case' */

      /* Sum: '<S6>/Add2' incorporates:
       *  Constant: '<S6>/Constant'
       *  Inport: '<Root>/EncoderCounterIn'
       *  Product: '<S6>/Product'
       *  RelationalOperator: '<S6>/Relational Operator'
       */
      *rty_AnlgleMec = degresProCounter * (real32_T)rtb_Switch + *rtu_AngleMecIn;

      if (*rty_AnlgleMec < 0) {

    	  *rty_AnlgleMec = *rty_AnlgleMec + 6.28318548F;
      }

      /* End of Outputs for SubSystem: '<S3>/CounterHasOverflowed' */
    } else {
      /* Outputs for IfAction SubSystem: '<S3>/CounterIsInNoramlOperation' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      /* Sum: '<S7>/Add1' incorporates:
       *  Constant: '<S7>/Constant'
       *  Inport: '<Root>/EncoderCounterIn'
       *  Product: '<S7>/Product'
       *  Sum: '<S7>/Add'
       */
      *rty_AnlgleMec = (real32_T)(int16_T)((int16_T)EncoderCounter - (int16_T)
        ConvertPWMtoAngle_DW.UnitDelay_DSTATE_i) * degresProCounter +
        *rtu_AngleMecIn;

      if (*rty_AnlgleMec < 0) {

          	  *rty_AnlgleMec = *rty_AnlgleMec + 6.28318548F;
            }

      /* End of Outputs for SubSystem: '<S3>/CounterIsInNoramlOperation' */
    }

    /* End of If: '<S3>/If' */

    /* Logic: '<S3>/NOT' incorporates:
     *  Constant: '<S5>/Constant'
     *  RelationalOperator: '<S5>/Compare'
     *  UnitDelay: '<S3>/Unit Delay1'
     */
    ConvertPWMtoAngle_DW.UnitDelay1_DSTATE = !(ConvertPWMtoAngle_B.UnitDelay >
      0.0);

    /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
     *  Inport: '<Root>/EncoderCounterIn'
     */
    ConvertPWMtoAngle_DW.UnitDelay_DSTATE_i = EncoderCounter;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */
  }

  /* End of If: '<Root>/If' */

  /* Math: '<Root>/Mod' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Product: '<Root>/Product'
   */
  *rty_AngleElec = fmodf((real32_T)polepairs * *rty_AnlgleMec, 6.28318548F);

  /* Update for UnitDelay: '<S2>/Delay Input1'
   *
   * Block description for '<S2>/Delay Input1':
   *
   *  Store in Global RAM
   */
  ConvertPWMtoAngle_DW.DelayInput1_DSTATE = rtb_Compare;
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
