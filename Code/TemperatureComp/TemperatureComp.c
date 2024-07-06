/*
 * File: TemperatureComp.c
 *
 * Code generated for Simulink model 'TemperatureComp'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jul  4 15:54:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TemperatureComp.h"
#include "rtwtypes.h"
#include "TemperatureComp_private.h"
#include "InterfaceBswApp.h"

/* Exported block signals */
int16_T Sig_board_temperature;         /* '<Root>/adc to mv1' */

/* Block states (default storage) */
DW_TemperatureComp_T TemperatureComp_DW;

/* Real-time model */
static RT_MODEL_TemperatureComp_T TemperatureComp_M_;
RT_MODEL_TemperatureComp_T *const TemperatureComp_M = &TemperatureComp_M_;
uint16_T look1_iu16lu32n16_pbinlcse(uint16_T u0, const uint16_T bp0[], const
  uint16_T table[], uint32_T prevIndex[], uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T frac;
  uint16_T bpLeftVar;
  uint16_T y;
  uint16_T yL_0d0;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T found;
    uint32_T iRght;

    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0U];
    frac = 0U;
    iRght = maxIndex;
    found = 0U;
    while (found == 0U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx - 1U;
        bpIdx = ((bpIdx + frac) - 1U) >> 1U;
      } else if (u0 < bp0[bpIdx + 1U]) {
        found = 1U;
      } else {
        frac = bpIdx + 1U;
        bpIdx = ((bpIdx + iRght) + 1U) >> 1U;
      }
    }

    bpLeftVar = bp0[bpIdx];
    frac = ((uint32_T)(uint16_T)((uint32_T)u0 - bpLeftVar) << 16) / (uint16_T)
      ((uint32_T)bp0[bpIdx + 1U] - bpLeftVar);
  } else {
    bpIdx = maxIndex - 1U;
    frac = 65536U;
  }

  prevIndex[0U] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  bpLeftVar = table[bpIdx + 1U];
  yL_0d0 = table[bpIdx];
  if (bpLeftVar >= yL_0d0) {
    y = (uint16_T)((uint32_T)(uint16_T)(((uint16_T)((uint32_T)bpLeftVar - yL_0d0)
      * frac) >> 16) + yL_0d0);
  } else {
    y = (uint16_T)((uint32_T)yL_0d0 - (uint16_T)(((uint16_T)((uint32_T)yL_0d0 -
      bpLeftVar) * frac) >> 16));
  }

  return y;
}

int16_T look1_iu16lu32n16ts16D_8WDIoWoi(uint16_T u0, const uint16_T bp0[], const
  int16_T table[], uint32_T prevIndex[], uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T frac;
  int16_T yL_0d0;

  /* Column-major Lookup 1-D
     Canonical function name: look1_iu16lu32n16ts16Ds32_pbinlcs
     Search method: 'binary'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T found;
    uint32_T iRght;

    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0U];
    frac = 0U;
    iRght = maxIndex;
    found = 0U;
    while (found == 0U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx - 1U;
        bpIdx = ((bpIdx + frac) - 1U) >> 1U;
      } else if (u0 < bp0[bpIdx + 1U]) {
        found = 1U;
      } else {
        frac = bpIdx + 1U;
        bpIdx = ((bpIdx + iRght) + 1U) >> 1U;
      }
    }

    uint16_T bpLeftVar;
    bpLeftVar = bp0[bpIdx];
    frac = ((uint32_T)(uint16_T)((uint32_T)u0 - bpLeftVar) << 16) / (uint16_T)
      ((uint32_T)bp0[bpIdx + 1U] - bpLeftVar);
  } else {
    bpIdx = maxIndex - 1U;
    frac = 65536U;
  }

  prevIndex[0U] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[bpIdx];
  return (int16_T)((int16_T)(((table[bpIdx + 1U] - yL_0d0) * (int32_T)frac) >>
    16) + yL_0d0);
}

/* Model step function */
void TemperatureComp_step(void)
{
  uint16_T rtb_adctomv;

  /* Lookup_n-D: '<Root>/adc to mv' incorporates:
   *  Inport: '<Root>/Inport'
   */
  rtb_adctomv = look1_iu16lu32n16_pbinlcse(Sig_ADCin_temptr_sens,
    TemperatureComp_ConstP.adctomv_bp01Data, TemperatureComp_ConstP.pooled1,
    &TemperatureComp_DW.m_bpIndex, 1U);

  /* Lookup_n-D: '<Root>/adc to mv1' incorporates:
   *  Lookup_n-D: '<Root>/adc to mv'
   */
  Sig_board_temperature = look1_iu16lu32n16ts16D_8WDIoWoi(rtb_adctomv,
    TemperatureComp_ConstP.pooled1, TemperatureComp_ConstP.adctomv1_tableData,
    &TemperatureComp_DW.m_bpIndex_k, 1U);
}

/* Model initialize function */
void TemperatureComp_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void TemperatureComp_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
