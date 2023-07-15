/*
 * File: ADCRawToIab.c
 *
 * Code generated for Simulink model 'ADCRawToIab'.
 *
 * Model version                  : 7.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 28 17:26:23 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADCRawToIab.h"
#include "rtwtypes.h"
#include "ADCRawToIab_private.h"
#include "InterfaceBswApp.h"
#include "ConstParams.h"

/* Output and update for referenced model: 'ADCRawToIab' */
void ADCRawToIab(real32_T *rty_Ia, real32_T *rty_Ib)
{
  int32_T tmp;
  int32_T tmp_1;
  uint16_T tmp_0;

  /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)' incorporates:
   *  Inport generated from: '<Root>/adcBuffer'
   *  Inport generated from: '<Root>/autoCalADCVal'
   *  Sum: '<Root>/Add2'
   *
   * About '<Root>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  tmp = adcBuffer[0] + autoCalADCVal[0];
  if (tmp < 0) {
    tmp = 0;
  } else if (tmp > 65535) {
    tmp = 65535;
  }

  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   */
  tmp_1 = (DRV_GAIN * DRV_SHUNTR_OHM) >> 6;
  if (tmp_1 > 32767) {
    tmp_1 = 32767;
  } else if (tmp_1 < -32768) {
    tmp_1 = -32768;
  }

  /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)' incorporates:
   *  Sum: '<Root>/Add2'
   *
   * About '<Root>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if ((uint16_T)tmp <= 4096) {
    tmp_0 = (uint16_T)tmp;
  } else {
    tmp_0 = 4096U;
  }

  /* Product: '<Root>/Divide1' incorporates:
   *  Constant: '<Root>/Constant'
   *  LookupNDDirect: '<Root>/Direct Lookup Table (n-D)'
   *  Product: '<Root>/Divide2'
   *  Sum: '<Root>/Add'
   *
   * About '<Root>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  *rty_Ia = (real32_T)(int16_T)((DRV_V_REF_Div2 << 5) - ADC_V_OUT[tmp_0]) *
    0.0009765625F / ((real32_T)tmp_1 * 0.0009765625F);

  /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)1' incorporates:
   *  Inport generated from: '<Root>/adcBuffer'
   *  Inport generated from: '<Root>/autoCalADCVal'
   *  Sum: '<Root>/Add3'
   *
   * About '<Root>/Direct Lookup Table (n-D)1':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  tmp = adcBuffer[1] + autoCalADCVal[1];
  if (tmp < 0) {
    tmp = 0;
  } else if (tmp > 65535) {
    tmp = 65535;
  }

  /* Product: '<Root>/Divide4' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   */
  tmp_1 = (DRV_GAIN * DRV_SHUNTR_OHM) >> 6;
  if (tmp_1 > 32767) {
    tmp_1 = 32767;
  } else if (tmp_1 < -32768) {
    tmp_1 = -32768;
  }

  /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)1' incorporates:
   *  Sum: '<Root>/Add3'
   *
   * About '<Root>/Direct Lookup Table (n-D)1':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if ((uint16_T)tmp <= 4096) {
    tmp_0 = (uint16_T)tmp;
  } else {
    tmp_0 = 4096U;
  }

  /* Product: '<Root>/Divide3' incorporates:
   *  Constant: '<Root>/Constant3'
   *  LookupNDDirect: '<Root>/Direct Lookup Table (n-D)1'
   *  Product: '<Root>/Divide4'
   *  Sum: '<Root>/Add1'
   *
   * About '<Root>/Direct Lookup Table (n-D)1':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  *rty_Ib = (real32_T)(int16_T)((int16_T)((DRV_V_REF_Div2 << 5) -
    ADC_V_OUT[tmp_0]) << 4) * 6.10351562E-5F / ((real32_T)tmp_1 * 0.0009765625F);
}

/* Model initialize function */
void ADCRawToIab_initialize(const char_T **rt_errorStatus,
  RT_MODEL_ADCRawToIab_T *const ADCRawToIab_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(ADCRawToIab_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
