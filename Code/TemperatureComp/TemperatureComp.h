/*
 * File: TemperatureComp.h
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

#ifndef RTW_HEADER_TemperatureComp_h_
#define RTW_HEADER_TemperatureComp_h_
#ifndef TemperatureComp_COMMON_INCLUDES_
#define TemperatureComp_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TemperatureComp_COMMON_INCLUDES_ */

#include "TemperatureComp_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint32_T m_bpIndex;                  /* '<Root>/adc to mv' */
  uint32_T m_bpIndex_k;                /* '<Root>/adc to mv1' */
} DW_TemperatureComp_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: adctomv1_tableData
   * Referenced by: '<Root>/adc to mv1'
   */
  int16_T adctomv1_tableData[2];

  /* Pooled Parameter (Expression: [0 3300])
   * Referenced by:
   *   '<Root>/adc to mv'
   *   '<Root>/adc to mv1'
   */
  uint16_T pooled1[2];

  /* Computed Parameter: adctomv_bp01Data
   * Referenced by: '<Root>/adc to mv'
   */
  uint16_T adctomv_bp01Data[2];
} ConstP_TemperatureComp_T;

/* Real-time Model Data Structure */
struct tag_RTM_TemperatureComp_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_TemperatureComp_T TemperatureComp_DW;

/* Constant parameters (default storage) */
extern const ConstP_TemperatureComp_T TemperatureComp_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern int16_T Sig_board_temperature;  /* '<Root>/adc to mv1' */

/* Model entry point functions */
extern void TemperatureComp_initialize(void);
extern void TemperatureComp_step(void);
extern void TemperatureComp_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TemperatureComp_T *const TemperatureComp_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TemperatureComp'
 */
#endif                                 /* RTW_HEADER_TemperatureComp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
