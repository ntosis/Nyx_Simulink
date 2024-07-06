/*
 * File: ConstParams.h
 *
 * Code generated for Simulink model 'MotorControlLib'.
 *
 * Model version                  : 3.56
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 28 17:30:35 2022
 */

#ifndef RTW_HEADER_ConstParams_h_
#define RTW_HEADER_ConstParams_h_
#include "rtwtypes.h"

/* Const memory section */
/* Exported data declaration */
/* Declaration for custom storage class: Const */
extern const int16_T ADC_V_OUT[4097];

/* fixdt(1,16,2^-10,0) */
extern const real32_T BrkPoints[3];
extern const int8_T DRV_GAIN;

/* fixdt(1,8,2^-1,0) */
extern const int16_T DRV_SHUNTR_OHM;

/* fixdt(1,16,2^-15,0) */
extern const uint8_T DRV_V_REF_Div2;

/* fixdt(1,8,2^-5,0) */
extern const real32_T EMFobsLdGain;

/* (1/L) = 100.000

   fixdt(1,16,2^2,0) */
extern const real32_T EMFobsRS;

/* fixdt(1,16,2^-8,0) */
extern const int16_T TqToIqConst;
extern const uint32_T MaxValCnt;
/* fixdt(1,16,2^-8,0)
   Val=2/(3*p*psim)=2/3*Kt
   old=97.75 */
extern const int8_T dSoll;

/* int8 */
extern const real32_T degresProCounter;
extern const uint8_T polepairs;
extern const uint16_T pwmTableData[3];

#endif                                 /* RTW_HEADER_ConstParams_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
