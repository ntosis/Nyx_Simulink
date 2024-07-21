/*
 * File: look1_iflftu16Df_binlc.c
 *
 * Code generated for Simulink model 'MotorControlLib'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jul 16 15:23:47 2024
 */

#include "look1_iflftu16Df_binlc.h"
#include "rtwtypes.h"

uint16_T look1_iflftu16Df_binlc(real32_T u0, const real32_T bp0[], const
  uint16_T table[], uint32_T maxIndex)
{
  real32_T frac;
  uint32_T iLeft;
  uint16_T yL_0d0;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0F;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[iLeft];
  return (uint16_T)((uint32_T)(uint16_T)(((real32_T)table[iLeft + 1U] -
    (real32_T)yL_0d0) * frac) + yL_0d0);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
