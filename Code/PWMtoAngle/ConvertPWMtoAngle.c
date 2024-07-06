/*
 * File: ConvertPWMtoAngle.c
 *
 * Code generated for Simulink model 'ConvertPWMtoAngle'.
 *
 * Model version                  : 7.30
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jul  6 10:12:57 2024
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
real32_T initialAngle;                 /* '<S5>/Data Type Conversion' */

/* Exported block states */
int32_T EncoderCounterOld;             /* '<S1>/Unit Delay' */
boolean_T Sig_invert_angleElec;        /* '<Root>/Data Store Memory' */
MdlrefDW_ConvertPWMtoAngle_T ConvertPWMtoAngle_MdlrefDW;

/* Block states (default storage) */
DW_ConvertPWMtoAngle_f_T ConvertPWMtoAngle_DW;

/* System initialize for referenced model: 'ConvertPWMtoAngle' */
void ConvertPWMtoAngle_Init(void)
{
  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  Sig_invert_angleElec = true;
}

/* Output and update for referenced model: 'ConvertPWMtoAngle' */
void ConvertPWMtoAngle(const boolean_T *rtu_UsersInputIsNull, const real32_T
  *rtu_AngleMecIn, real32_T *rty_AngleElec, real32_T *rty_AnlgleMec)
{
  boolean_T rtb_Compare;

  /* RelationalOperator: '<S2>/Compare' */
  rtb_Compare = !*rtu_UsersInputIsNull;

  /* If: '<Root>/If' incorporates:
   *  Constant: '<S9>/Constant'
   *  Logic: '<Root>/OR'
   *  RelationalOperator: '<S4>/FixPt Relational Operator'
   *  RelationalOperator: '<S9>/Compare'
   *  UnitDelay: '<S4>/Delay Input1'
   *  UnitDelay: '<S6>/Unit Delay'
   *
   * Block description for '<S4>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((int32_T)rtb_Compare < (int32_T)ConvertPWMtoAngle_DW.DelayInput1_DSTATE) ||
      (ConvertPWMtoAngle_DW.UnitDelay_DSTATE_l == 0)) {
    uint16_T tmp_0;

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
      tmp_0 = Duty;
    } else {
      tmp_0 = 4095U;
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
     *  LookupNDDirect: '<S5>/Direct Lookup Table (n-D)'
     *
     * About '<S5>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    initialAngle = (real32_T)Angle_T[tmp_0] * 0.0009765625F;

    /* Merge: '<Root>/Merge' incorporates:
     *  SignalConversion: '<S5>/Signal Copy1'
     */
    afterMergeAngle_tst = initialAngle;

    /* SignalConversion generated from: '<S5>/EncoderCounterIn' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  Inport generated from: '<Root>/EncoderCounterIn'
     *  UnitDelay: '<Root>/Unit Delay'
     */
    ConvertPWMtoAngle_DW.UnitDelay_DSTATE = (int32_T)EncoderCounter;

    /* End of Outputs for SubSystem: '<Root>/Initialize angle from PWM sensor' */
  } else {
    int32_T tmp_1;
    real32_T rtb_Switch1_p;
    boolean_T rtb_EncoderCounterHasOverflowed;

    /* Outputs for IfAction SubSystem: '<Root>/Calculate angle from encoder sensor' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* DataStoreRead: '<S1>/Data Store Read' */
    rtb_EncoderCounterHasOverflowed = EncoderCounterHasOverflowed;

    /* If: '<S1>/If' incorporates:
     *  DataStoreRead: '<S1>/Data Store Read'
     */
    if (EncoderCounterHasOverflowed) {
      /* Outputs for IfAction SubSystem: '<S1>/Subsystem' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      /* Logic: '<S7>/Logical Operator' incorporates:
       *  DataStoreWrite: '<S7>/Data Store Write'
       */
      EncoderCounterHasOverflowed = false;

      /* Switch: '<S7>/Switch' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion'
       *  Inport generated from: '<Root>/EncoderCounterIn'
       *  RelationalOperator: '<S7>/Relational Operator'
       *  UnitDelay: '<S1>/Unit Delay'
       */
      if ((int32_T)EncoderCounter > EncoderCounterOld) {
        uint32_T tmp;

        /* Sum: '<S7>/Add' incorporates:
         *  Constant: '<S7>/Constant'
         */
        tmp = MaxValCnt + 1U;
        if (MaxValCnt + 1U > 2147483647U) {
          tmp = 2147483647U;
        }

        if ((EncoderCounterOld < 0) && ((int32_T)tmp < MIN_int32_T
             - EncoderCounterOld)) {
          /* Merge: '<S1>/Merge1' */
          EncoderCounterOld = MIN_int32_T;
        } else if ((EncoderCounterOld > 0) && ((int32_T)tmp > MAX_int32_T
                    - EncoderCounterOld)) {
          /* Merge: '<S1>/Merge1' */
          EncoderCounterOld = MAX_int32_T;
        } else {
          /* Merge: '<S1>/Merge1' */
          EncoderCounterOld += (int32_T)tmp;
        }

        /* End of Sum: '<S7>/Add' */
      } else {
        uint32_T tmp;

        /* Sum: '<S7>/Add1' incorporates:
         *  Constant: '<S7>/Constant'
         */
        tmp = MaxValCnt + 1U;
        if (MaxValCnt + 1U > 2147483647U) {
          tmp = 2147483647U;
        }

        if ((EncoderCounterOld >= 0) && ((int32_T)tmp < EncoderCounterOld -
             MAX_int32_T)) {
          /* Merge: '<S1>/Merge1' */
          EncoderCounterOld = MAX_int32_T;
        } else if ((EncoderCounterOld < 0) && ((int32_T)tmp > EncoderCounterOld
                    - MIN_int32_T)) {
          /* Merge: '<S1>/Merge1' */
          EncoderCounterOld = MIN_int32_T;
        } else {
          /* Merge: '<S1>/Merge1' */
          EncoderCounterOld -= (int32_T)tmp;
        }

        /* End of Sum: '<S7>/Add1' */
      }

      /* End of Switch: '<S7>/Switch' */
      /* End of Outputs for SubSystem: '<S1>/Subsystem' */
    }

    /* End of If: '<S1>/If' */

    /* Switch: '<S1>/Switch1' incorporates:
     *  UnitDelay: '<Root>/Unit Delay1'
     */
    if (rtb_EncoderCounterHasOverflowed) {
      rtb_Switch1_p = initialAngle;
    } else {
      rtb_Switch1_p = *rtu_AngleMecIn;
    }

    /* End of Switch: '<S1>/Switch1' */

    /* Sum: '<S1>/Add2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  Inport generated from: '<Root>/EncoderCounterIn'
     */
    if (((int32_T)EncoderCounter >= 0) && (EncoderCounterOld < (int32_T)
         EncoderCounter - MAX_int32_T)) {
      tmp_1 = MAX_int32_T;
    } else if (((int32_T)EncoderCounter < 0) && (EncoderCounterOld > (int32_T)
                EncoderCounter - MIN_int32_T)) {
      tmp_1 = MIN_int32_T;
    } else {
      tmp_1 = (int32_T)EncoderCounter - EncoderCounterOld;
    }

    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Product: '<S1>/Product1'
     *  Sum: '<S1>/Add2'
     *  Sum: '<S1>/Add3'
     */
    afterMergeAngle_tst = degresProCounter * (real32_T)tmp_1 + rtb_Switch1_p;

    /* Update for Merge: '<S1>/Merge1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  Inport generated from: '<Root>/EncoderCounterIn'
     *  UnitDelay: '<S1>/Unit Delay'
     */
    EncoderCounterOld = (int32_T)EncoderCounter;

    /* End of Outputs for SubSystem: '<Root>/Calculate angle from encoder sensor' */
  }

  /* End of If: '<Root>/If' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  DataStoreRead: '<Root>/Data Store Read'
   *  Math: '<Root>/Mod'
   *  Product: '<Root>/Product'
   *  Sum: '<Root>/invert angle'
   */
  if (Sig_invert_angleElec) {
    *rty_AngleElec = rt_modf_snf((real32_T)polepairs * afterMergeAngle_tst,
      6.28318548F);
  } else {
    *rty_AngleElec = 6.28318548F - rt_modf_snf((real32_T)polepairs *
      afterMergeAngle_tst, 6.28318548F);
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  RelationalOperator: '<S3>/Compare'
   *  Sum: '<Root>/Add1'
   *  Switch: '<Root>/Switch'
   */
  if (afterMergeAngle_tst < 0.0F) {
    *rty_AnlgleMec = afterMergeAngle_tst + 6.28318548F;
  } else if (afterMergeAngle_tst >= 6.28318548F) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Sum: '<Root>/Add'
     */
    *rty_AnlgleMec = afterMergeAngle_tst - 6.28318548F;
  } else {
    /* Switch: '<Root>/Switch' */
    *rty_AnlgleMec = afterMergeAngle_tst;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* Update for UnitDelay: '<S4>/Delay Input1'
   *
   * Block description for '<S4>/Delay Input1':
   *
   *  Store in Global RAM
   */
  ConvertPWMtoAngle_DW.DelayInput1_DSTATE = rtb_Compare;

  /* Update for UnitDelay: '<S6>/Unit Delay' incorporates:
   *  Constant: '<S6>/Constant'
   */
  ConvertPWMtoAngle_DW.UnitDelay_DSTATE_l = 1U;
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
