/*
 * File: TemperatureComp_data.c
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

/* Constant parameters (default storage) */
const ConstP_TemperatureComp_T TemperatureComp_ConstP = {
  /* Computed Parameter: adctomv1_tableData
   * Referenced by: '<Root>/adc to mv1'
   */
  { 150, -50 },

  /* Pooled Parameter (Expression: [0 3300])
   * Referenced by:
   *   '<Root>/adc to mv'
   *   '<Root>/adc to mv1'
   */
  { 0U, 3300U },
  { 538U, 3277U },

  /* Computed Parameter: adctomv_bp01Data
   * Referenced by: '<Root>/adc to mv'
   */
  { 0U, 4096U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
