/*
 * File: ConvertPWMtoAngle.c
 *
 * Code generated for Simulink model 'ConvertPWMtoAngle'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Mar 20 18:17:27 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ConvertPWMtoAngle.h"
#include "ConvertPWMtoAngle_private.h"
#include "rt_modf_snf.h"

/* Output and update for referenced model: 'ConvertPWMtoAngle' */
void ConvertPWMtoAngle(const boolean_T *rtu_setAngleFormat)
{
  int16_T rtb_Switch;
  uint16_T tmp;
  int16_T tmp_0;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Inport: '<Root>/Input'
   *  LookupNDDirect: '<Root>/Direct Lookup Table (n-D)'
   *  Sum: '<Root>/Add'
   *
   * About '<Root>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   */
  if (*rtu_setAngleFormat) {
    /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)' incorporates:
     *  Inport: '<Root>/Input'
     *
     * About '<Root>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     */
    if (Duty < 4095) {
      tmp = Duty;
    } else {
      tmp = 4095U;
    }

    rtb_Switch = (int16_T)(1608 - (Angle_T[tmp] >> 2));
  } else {
    if (Duty < 4095) {
      /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)' incorporates:
       *  Inport: '<Root>/Input'
       *
       * About '<Root>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       */
      tmp = Duty;
    } else {
      /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)'
       *
       * About '<Root>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       */
      tmp = 4095U;
    }

    rtb_Switch = (int16_T)(Angle_T[tmp] >> 2);
  }

  /* End of Switch: '<Root>/Switch' */

  /* Gain: '<Root>/Gain' */
  if (p > 7) {
    tmp_0 = MAX_int16_T;
  } else {
    tmp_0 = (int16_T)(p << 12);
  }

  /* Math: '<Root>/Mod' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<Root>/Gain'
   */
  Angle_sensor_in = rt_modf_snf(6.28318548F, (real32_T)tmp_0 * 0.000244140625F *
    ((real32_T)rtb_Switch * 0.00390625F));
}

/* Model initialize function */
void ConvertPWMtoAngle_initialize(const char_T **rt_errorStatus,
  RT_MODEL_ConvertPWMtoAngle_T *const ConvertPWMtoAngle_M)
{
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
