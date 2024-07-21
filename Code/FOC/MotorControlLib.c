/*
 * File: MotorControlLib.c
 *
 * Code generated for Simulink model 'MotorControlLib'.
 *
 * Model version                  : 5.8
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jul 16 15:23:47 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorControlLib.h"
#include "rtwtypes.h"
#include "MotorControlLib_private.h"
#include <math.h>
#include "InterfaceBswApp.h"
#include "look1_iflftu16Df_binlc.h"
#include "ConstParams.h"
#include "ADCRawToIab.h"
#include "SafetyChecks.h"
#define ConvertPWMtoAngle_MDLREF_HIDE_CHILD_
#include "ConvertPWMtoAngle.h"
#define SAMPLE_RATE 5000 // Sampling rate in Hz (100 samples per second)
#define CUTOFF_FREQ 100 // Cutoff frequency in Hz

/* Exported block signals */
#define ALPHA (float)(2.0f * 3.14159265f * CUTOFF_FREQ / SAMPLE_RATE) / (2.0f * 3.14159265f * CUTOFF_FREQ / SAMPLE_RATE + 1.0f)
float lowPassFilter(float currentValue, float previousFilteredValue); // todo added manual low pass filter//
/* Exported block signals */
boolean_T resetPIIntegratorDQ;         /* '<Root>/Inport6' */
boolean_T enableFluxObs;               /* '<Root>/Inport2' */
uint8_T set_AngleInput;                /* '<Root>/Inport1' */
boolean_T enablePositionObs;           /* '<Root>/Inport3' */
int16_T dth_dt;                        /* '<Root>/Inport4' */
boolean_T resetPIIntegrator;           /* '<Root>/Inport5' */
boolean_T Sig_change_SVMalgorithm;     /* '<Root>/In1' */
boolean_T activateRPMCntlr;            /* '<Root>/Inport8'
                                        * Set to 1 to activate the RPM Controller
                                        */
real32_T Sig_MechanicalAngle;          /* '<Root>/AngleCalculation' */
real32_T Sig_theta_el_m;               /* '<Root>/Multiport Switch' */
real32_T Sig_Ia_m;                     /* '<Root>/ADCRAwToCurrent(Iabc)' */
real32_T Sig_Ib_m;                     /* '<Root>/ADCRAwToCurrent(Iabc)' */
real32_T Sig_Iq_Soll;                  /* '<S5>/Switch' */
real32_T Sig_cos_m;                    /* '<S15>/Sum6' */
real32_T Sig_Ibeta_m;                  /* '<S196>/one_by_sqrt3' */
real32_T Sig_sin_m;                    /* '<S15>/Sum4' */
real32_T Sig_Id_axis_meas;             /* '<S11>/Gain2' */
real32_T Sig_Iq_axis_meas;             /* '<S11>/Gain3' */
real32_T Sig_Vqsatu_m;                 /* '<S7>/DQ_Limiter' */
real32_T Sig_Vdsatu_m;                 /* '<S7>/DQ_Limiter' */
real32_T Sig_Va_m;                     /* '<Root>/Gain' */
real32_T Sig_Vb_m;                     /* '<Root>/Gain1' */
real32_T Sig_Valpha_m;                 /* '<S8>/Switch' */
real32_T Sig_Vbeta_m;                  /* '<S8>/Switch1' */
real32_T Sig_Vgamma_m;                 /* '<S8>/Switch2' */
real32_T Sig_Speed_rads;               /* '<S3>/Diff'
                                        * Speed in Radians/s
                                        */
real32_T Sig_Rpm_measurment;           /* '<S9>/Switch' */
real32_T Sig_dAxis_errorSum_m;         /* '<S75>/Add' */
real32_T Sig_qAxis_errorSum_m;         /* '<S75>/Add1' */
real32_T Sig_IQ;                       /* '<S75>/Data Type Conversion1' */
real32_T Sig_PQ;                       /* '<S75>/Data Type Conversion2' */
real32_T Sig_PD;                       /* '<S75>/Data Type Conversion3' */
real32_T Sig_ID;                       /* '<S75>/Data Type Conversion4' */
real32_T Sig_qAxis_PI_out;             /* '<S75>/PI Qaxis' */
real32_T Sig_dAxis_PI_out;             /* '<S75>/PI DAxis' */
real32_T Sig_PRPM;                     /* '<S6>/Data Type Conversion3' */
real32_T Sig_IRPM;                     /* '<S6>/Data Type Conversion4' */
int16_T constantAngle;                 /* '<S188>/Discrete-Time Integrator' */
boolean_T Sig_requestMotorBreak;       /* '<S1>/OR' */

/* Exported block parameters */
real32_T Minus_1 = -1.0F;              /* Variable: Minus_1
                                        * Referenced by: '<S75>/Gain'
                                        * Multiply PI Q with -1 for more stability.
                                        */
int16_T d_q_Voltage_Limiter_max = 92;  /* Variable: d_q_Voltage_Limiter_max
                                        * Referenced by: '<S7>/DQ_Limiter'
                                        * =Vnom/sqrt(3)
                                        */
int16_T d_q_Voltage_Limiter_sat_neg = -160;/* Variable: d_q_Voltage_Limiter_sat_neg
                                            * Referenced by:
                                            *   '<S64>/Saturation'
                                            *   '<S120>/Saturation'
                                            *   '<S171>/Saturation'
                                            *   '<S50>/DeadZone'
                                            *   '<S106>/DeadZone'
                                            *   '<S157>/DeadZone'
                                            * fixdt(1,16,2^-4,0)
                                            */
int16_T d_q_Voltage_Limiter_sat_pos = 160;/* Variable: d_q_Voltage_Limiter_sat_pos
                                           * Referenced by:
                                           *   '<S64>/Saturation'
                                           *   '<S120>/Saturation'
                                           *   '<S171>/Saturation'
                                           *   '<S50>/DeadZone'
                                           *   '<S106>/DeadZone'
                                           *   '<S157>/DeadZone'
                                           * fixdt(1,16,2^-4,0)
                                           */
uint16_T Ki_Rpm = 20480U;              /* Variable: Ki_Rpm
                                        * Referenced by: '<S6>/Constant7'
                                        * fixdt(0,16,2^-11,0)
                                        */
uint16_T Kp_Rpm = 299U;                /* Variable: Kp_Rpm
                                        * Referenced by: '<S6>/Constant6'
                                        * fixdt(0,16,2^-11,0)
                                        */
uint16_T Ki_dAxis = 0U;            /* Variable: Ki_dAxis
                                        * Referenced by: '<S75>/Constant7'
                                        * fixdt(0,16,2^-8,0)
                                        */
uint16_T Ki_qAxis = 0U;            /* Variable: Ki_qAxis
                                        * Referenced by: '<S75>/Constant5'
                                        * fixdt(0,16,2^-8,0)
                                        */
uint16_T Kp_dAxis = 10U;               /* Variable: Kp_dAxis
                                        * Referenced by: '<S75>/Constant6'
                                        * fixdt(0,16,2^-8,0)
                                        */
uint16_T Kp_qAxis = 200U;               /* Variable: Kp_qAxis
                                        * Referenced by: '<S75>/Constant4'
                                        * fixdt(0,16,2^-8,0)
                                        */
uint16_T MaximumCurrentBeforeReaction = 4864U;/* Variable: MaximumCurrentBeforeReaction
                                               * Referenced by: '<Root>/SafetyChecks'
                                               * Maximum current limit before software shutdowns the mosfets.
                                               */

/* Exported block states */
real32_T AngleMec_1z;                  /* '<Root>/Unit Delay' */
uint16_T rpmSoll;                      /* '<Root>/Data Store Memory1' */
int16_T qSoll;                         /* '<Root>/Data Store Memory'
                                        * fixdt(1,16,2^-8,0)
                                        */

/* Block signals (default storage) */
B_MotorControlLib_T MotorControlLib_B;

/* Block states (default storage) */
DW_MotorControlLib_T MotorControlLib_DW;

/* Real-time model */
static RT_MODEL_MotorControlLib_T MotorControlLib_M_;
RT_MODEL_MotorControlLib_T *const MotorControlLib_M = &MotorControlLib_M_;

/* System initialize for atomic system: '<S6>/PI DAxis' */
void MotorControlLi_PIDAxis_Init(DW_PIDAxis_MotorControlLib_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S57>/Integrator' */
  localDW->Integrator_IC_LOADING = 1U;
}

/* Output and update for atomic system: '<S6>/PI DAxis' */
void MotorControlLib_PIDAxis(real32_T rtu_error, real32_T rtu_P, real32_T rtu_I,
  boolean_T rtu_Reset, real32_T rtu_init, real32_T *rty_PIDOut,
  DW_PIDAxis_MotorControlLib_T *localDW)
{
  real32_T rtb_IProdOut;
  real32_T rtb_Sum_g;
  real32_T u1;
  real32_T u2;
  int8_T rtb_Switch1;
  int8_T tmp;
  boolean_T rtb_RelationalOperator_k;

  /* DiscreteIntegrator: '<S57>/Integrator' */
  if (localDW->Integrator_IC_LOADING != 0) {
    localDW->Integrator_DSTATE = rtu_init;
  }

  if (rtu_Reset || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = rtu_init;
  }

  /* Sum: '<S66>/Sum' incorporates:
   *  DiscreteIntegrator: '<S57>/Integrator'
   *  Product: '<S62>/PProd Out'
   */
  rtb_Sum_g = rtu_error * rtu_P + localDW->Integrator_DSTATE;

  /* DeadZone: '<S50>/DeadZone' incorporates:
   *  Saturate: '<S64>/Saturation'
   */
  u2 = (real32_T)d_q_Voltage_Limiter_sat_pos * 0.0625F;
  if (rtb_Sum_g > u2) {
    rtb_IProdOut = rtb_Sum_g - u2;
  } else {
    rtb_IProdOut = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
    if (rtb_Sum_g >= rtb_IProdOut) {
      rtb_IProdOut = 0.0F;
    } else {
      rtb_IProdOut = rtb_Sum_g - rtb_IProdOut;
    }
  }

  /* End of DeadZone: '<S50>/DeadZone' */

  /* RelationalOperator: '<S48>/Relational Operator' incorporates:
   *  Constant: '<S48>/Clamping_zero'
   */
  rtb_RelationalOperator_k = (rtb_IProdOut != 0.0F);

  /* Switch: '<S48>/Switch1' incorporates:
   *  Constant: '<S48>/Clamping_zero'
   *  Constant: '<S48>/Constant'
   *  Constant: '<S48>/Constant2'
   *  RelationalOperator: '<S48>/fix for DT propagation issue'
   */
  if (rtb_IProdOut > 0.0F) {
    rtb_Switch1 = 1;
  } else {
    rtb_Switch1 = -1;
  }

  /* End of Switch: '<S48>/Switch1' */

  /* Product: '<S54>/IProd Out' */
  rtb_IProdOut = rtu_error * rtu_I;

  /* Saturate: '<S64>/Saturation' */
  u1 = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
  if (rtb_Sum_g > u2) {
    *rty_PIDOut = u2;
  } else if (rtb_Sum_g < u1) {
    *rty_PIDOut = u1;
  } else {
    *rty_PIDOut = rtb_Sum_g;
  }

  /* Update for DiscreteIntegrator: '<S57>/Integrator' */
  localDW->Integrator_IC_LOADING = 0U;

  /* Switch: '<S48>/Switch2' incorporates:
   *  Constant: '<S48>/Clamping_zero'
   *  Constant: '<S48>/Constant3'
   *  Constant: '<S48>/Constant4'
   *  RelationalOperator: '<S48>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S48>/Switch' incorporates:
   *  Constant: '<S48>/Constant1'
   *  Logic: '<S48>/AND3'
   *  RelationalOperator: '<S48>/Equal1'
   *  Switch: '<S48>/Switch2'
   */
  if (rtb_RelationalOperator_k && (rtb_Switch1 == tmp)) {
    rtb_IProdOut = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S57>/Integrator' incorporates:
   *  Switch: '<S48>/Switch'
   */
  localDW->Integrator_DSTATE += 0.01F * rtb_IProdOut;
  localDW->Integrator_PrevResetState = (int8_T)rtu_Reset;
}

/* Output and update for atomic system: '<S7>/DQ_Limiter' */
void MotorControlLib_DQ_Limiter(real32_T rtu_Vd_ref, real32_T rtu_Vq_ref,
  real32_T rty_Vd_sat[2], real32_T *rty_Vmax_unsat, int16_T rtp_Vmax)
{
  real32_T rtb_Gain_n;

  /* Sum: '<S74>/Sum2' incorporates:
   *  Product: '<S74>/Product'
   *  Product: '<S74>/Product1'
   */
  *rty_Vmax_unsat = rtu_Vd_ref * rtu_Vd_ref + rtu_Vq_ref * rtu_Vq_ref;

  /* Sqrt: '<S74>/Sqrt' */
  *rty_Vmax_unsat = sqrtf(*rty_Vmax_unsat);

  /* Switch: '<S74>/Switch' incorporates:
   *  Gain: '<S74>/Gain'
   *  Math: '<S74>/Math Function2'
   *  Product: '<S74>/Product2'
   *
   * About '<S74>/Math Function2':
   *  Operator: reciprocal
   */
  rtb_Gain_n = (real32_T)rtp_Vmax * 0.0625F;
  if (*rty_Vmax_unsat >= rtb_Gain_n) {
    rtb_Gain_n *= 1.0F / *rty_Vmax_unsat;
    rty_Vd_sat[0] = rtb_Gain_n * rtu_Vd_ref;
    rty_Vd_sat[1] = rtb_Gain_n * rtu_Vq_ref;
  } else {
    rty_Vd_sat[0] = rtu_Vd_ref;
    rty_Vd_sat[1] = rtu_Vq_ref;
  }

  /* End of Switch: '<S74>/Switch' */
}

/*
 * System initialize for atomic system:
 *    '<S75>/PI DAxis'
 *    '<S75>/PI Qaxis'
 */
void MotorControl_PIDAxis_c_Init(DW_PIDAxis_MotorControlLib_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S113>/Integrator' */
  localDW->Integrator_IC_LOADING = 1U;
}

/*
 * Output and update for atomic system:
 *    '<S75>/PI DAxis'
 *    '<S75>/PI Qaxis'
 */
real32_T MotorControlLib_PIDAxis_m(real32_T rtu_error, real32_T rtu_P, real32_T
  rtu_I, boolean_T rtu_Reset, real32_T rtu_init, DW_PIDAxis_MotorControlLib_c_T *
  localDW)
{
  real32_T rty_PIDOut_0;
  real32_T rtb_IProdOut;
  real32_T u1;
  real32_T u2;
  int8_T rtb_Switch1;
  int8_T tmp;
  boolean_T rtb_RelationalOperator_e;

  /* DiscreteIntegrator: '<S113>/Integrator' */
  if (localDW->Integrator_IC_LOADING != 0) {
    localDW->Integrator_DSTATE = rtu_init;
  }

  if (rtu_Reset || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = rtu_init;
  }

  /* Sum: '<S122>/Sum' incorporates:
   *  DiscreteIntegrator: '<S113>/Integrator'
   *  Product: '<S118>/PProd Out'
   */
  rty_PIDOut_0 = rtu_error * rtu_P + localDW->Integrator_DSTATE;

  /* DeadZone: '<S106>/DeadZone' incorporates:
   *  Saturate: '<S120>/Saturation'
   */
  u2 = (real32_T)d_q_Voltage_Limiter_sat_pos * 0.0625F;
  if (rty_PIDOut_0 > u2) {
    rtb_IProdOut = rty_PIDOut_0 - u2;
  } else {
    rtb_IProdOut = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
    if (rty_PIDOut_0 >= rtb_IProdOut) {
      rtb_IProdOut = 0.0F;
    } else {
      rtb_IProdOut = rty_PIDOut_0 - rtb_IProdOut;
    }
  }

  /* End of DeadZone: '<S106>/DeadZone' */

  /* RelationalOperator: '<S104>/Relational Operator' incorporates:
   *  Constant: '<S104>/Clamping_zero'
   */
  rtb_RelationalOperator_e = (rtb_IProdOut != 0.0F);

  /* Switch: '<S104>/Switch1' incorporates:
   *  Constant: '<S104>/Clamping_zero'
   *  Constant: '<S104>/Constant'
   *  Constant: '<S104>/Constant2'
   *  RelationalOperator: '<S104>/fix for DT propagation issue'
   */
  if (rtb_IProdOut > 0.0F) {
    rtb_Switch1 = 1;
  } else {
    rtb_Switch1 = -1;
  }

  /* End of Switch: '<S104>/Switch1' */

  /* Product: '<S110>/IProd Out' */
  rtb_IProdOut = rtu_error * rtu_I;

  /* Saturate: '<S120>/Saturation' */
  u1 = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
  if (rty_PIDOut_0 > u2) {
    rty_PIDOut_0 = u2;
  } else if (rty_PIDOut_0 < u1) {
    rty_PIDOut_0 = u1;
  }

  /* Update for DiscreteIntegrator: '<S113>/Integrator' */
  localDW->Integrator_IC_LOADING = 0U;

  /* Switch: '<S104>/Switch2' incorporates:
   *  Constant: '<S104>/Clamping_zero'
   *  Constant: '<S104>/Constant3'
   *  Constant: '<S104>/Constant4'
   *  RelationalOperator: '<S104>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S104>/Switch' incorporates:
   *  Constant: '<S104>/Constant1'
   *  Logic: '<S104>/AND3'
   *  RelationalOperator: '<S104>/Equal1'
   *  Switch: '<S104>/Switch2'
   */
  if (rtb_RelationalOperator_e && (rtb_Switch1 == tmp)) {
    rtb_IProdOut = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S113>/Integrator' incorporates:
   *  Switch: '<S104>/Switch'
   */
  localDW->Integrator_DSTATE += 0.0002F * rtb_IProdOut;
  localDW->Integrator_PrevResetState = (int8_T)rtu_Reset;
  return rty_PIDOut_0;
}

/* Output and update for Simulink Function: '<S9>/Task_Calculate_fast_speed' */
void M_Task_Calculate_fast_speed(boolean_T rtu_u)
{
  int32_T tmp;
  uint8_T rtb_Switch;
  UNUSED_PARAMETER(rtu_u);

  /* Gain: '<S185>/to useconds' */
  tmp = ((uint16_T)CounterFactor_us) + -500;
  if (((uint16_T)CounterFactor_us) + -500 < 0) {
    tmp = 0;
  }

  /* Switch: '<S185>/Switch' incorporates:
   *  Constant: '<S185>/Constant'
   *  Constant: '<S186>/Constant'
   *  DataStoreRead: '<S185>/Sig_speed_timer_counter'
   *  DataStoreRead: '<S185>/Sig_speed_timer_counter_1z'
   *  Gain: '<S185>/to useconds'
   *  RelationalOperator: '<S186>/Compare'
   *  Sum: '<S185>/Add'
   */
  if (((uint32_T)tmp + 500U) * (uint16_T)(Sig_speed_timer_counter -
       Sig_speed_timer_counter_1z) == 0U) {
    rtb_Switch = 60U;
  } else {
    rtb_Switch = 0U;
  }

  /* End of Switch: '<S185>/Switch' */

  /* Product: '<S185>/Divide' incorporates:
   *  Constant: '<S185>/Constant'
   */
  if (rtb_Switch == 0U) {
    rtb_Switch = MAX_uint8_T;

    /* Divide by zero handler */
  } else {
    rtb_Switch = (uint8_T)(60U / rtb_Switch);
  }

  /* DataTypeConversion: '<S185>/Data Type Conversion' incorporates:
   *  Product: '<S185>/Divide'
   */
  MotorControlLib_B.DataTypeConversion = rtb_Switch;
}

/* Model step function for TID0 */
void MotorControlLib_step0(void)       /* Sample time: [5.0E-5s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void MotorControlLib_step1(void)       /* Sample time: [0.0002s, 0.0s] */
{
  /* local block i/o variables */
  real32_T rtb_AngleElec;
  real32_T rtb_Switch[2];
  real32_T rtb_AngleMec_1z;
  real32_T rtb_a;
  real32_T rtb_add_b;
  real32_T rtb_add_c;
  real32_T rtb_b;
  real32_T rtb_c;
  int16_T tmp;
  uint16_T rtb_uDLookupTable_tmp_tmp;
  boolean_T rtb_Logic_c_idx_0;
  boolean_T rtb_Logic_idx_0;
  boolean_T rtb_UnitDelay1_b;
  boolean_T rtb_UnitDelay_n;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.0002s, 0.0s] to Sample time: [0.01s, 0.0s]  */
  MotorControlLib_M->Timing.RateInteraction.b_TID1_2 =
    (MotorControlLib_M->Timing.RateInteraction.TID1_2 == 0);
  (MotorControlLib_M->Timing.RateInteraction.TID1_2)++;
  if ((MotorControlLib_M->Timing.RateInteraction.TID1_2) > 49) {
    MotorControlLib_M->Timing.RateInteraction.TID1_2 = 0;
  }

  /* RateTransition generated from: '<S1>/AND' */
  if (MotorControlLib_M->Timing.RateInteraction.TID1_2 == 1) {
    /* RateTransition generated from: '<S1>/AND' */
    MotorControlLib_B.TmpRTBAtANDInport1 =
      MotorControlLib_DW.TmpRTBAtANDInport1_Buffer0;
  }

  /* End of RateTransition generated from: '<S1>/AND' */

  /* Logic: '<S1>/OR' incorporates:
   *  Constant: '<S12>/Constant'
   *  DataStoreRead: '<S1>/Data Store Read1'
   *  DataStoreRead: '<S1>/Data Store Read2'
   *  Logic: '<S1>/AND'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S13>/Compare'
   */
  Sig_requestMotorBreak = ((MotorControlLib_B.TmpRTBAtANDInport1 && (rpmSoll ==
    0)) || (qSoll == 0));

  /* UnitDelay: '<Root>/Unit Delay' */
  rtb_AngleMec_1z = AngleMec_1z;

  /* ModelReference: '<Root>/AngleCalculation' incorporates:
   *  Inport: '<Root>/Duty cycle input'
   *  Inport: '<Root>/Encoder input'
   */
  ConvertPWMtoAngle(&Sig_requestMotorBreak, &rtb_AngleMec_1z, &rtb_AngleElec,
                    &Sig_MechanicalAngle);

  /* Outputs for Atomic SubSystem: '<Root>/Start up' */
  /* UnitDelay: '<S188>/Unit Delay' */
  rtb_UnitDelay_n = MotorControlLib_DW.UnitDelay_DSTATE_p;

  /* DiscreteIntegrator: '<S188>/Discrete-Time Integrator' incorporates:
   *  UnitDelay: '<S188>/Unit Delay'
   */
  if (MotorControlLib_DW.UnitDelay_DSTATE_p &&
      (MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE = 0;
  }

  /* DiscreteIntegrator: '<S188>/Discrete-Time Integrator' */
  constantAngle = MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE;

  /* UnitDelay: '<S187>/Unit Delay1' */
  rtb_UnitDelay1_b = MotorControlLib_DW.UnitDelay1_DSTATE_m;

  /* CombinatorialLogic: '<S193>/Logic' incorporates:
   *  Memory: '<S193>/Memory'
   *  UnitDelay: '<S187>/Unit Delay'
   */
  rtb_Logic_idx_0 = rtCP_Logic_table[((MotorControlLib_DW.UnitDelay_DSTATE_e +
    2U) << 1) + MotorControlLib_DW.Memory_PreviousInput];

  /* Outputs for Enabled SubSystem: '<S187>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S191>/Enable'
   */
  if (rtb_Logic_idx_0) {
    /* RelationalOperator: '<S195>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S195>/Delay Input1'
     *
     * Block description for '<S195>/Delay Input1':
     *
     *  Store in Global RAM
     */
    MotorControlLib_B.FixPtRelationalOperator =
      (MotorControlLib_DW.DelayInput1_DSTATE != 0.0);

    /* Update for UnitDelay: '<S195>/Delay Input1'
     *
     * Block description for '<S195>/Delay Input1':
     *
     *  Store in Global RAM
     */
    MotorControlLib_DW.DelayInput1_DSTATE = 0.0;
  }

  /* End of Outputs for SubSystem: '<S187>/Enabled Subsystem' */

  /* CombinatorialLogic: '<S194>/Logic' incorporates:
   *  Memory: '<S194>/Memory'
   *  RelationalOperator: '<S190>/FixPt Relational Operator'
   *  UnitDelay: '<S190>/Delay Input1'
   *
   * Block description for '<S190>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Logic_c_idx_0 = rtCP_Logic_table_m[((((uint32_T)
    MotorControlLib_B.FixPtRelationalOperator << 1) + (uint32_T)((int32_T)
    rtb_UnitDelay1_b < (int32_T)MotorControlLib_DW.DelayInput1_DSTATE_f)) << 1)
    + MotorControlLib_DW.Memory_PreviousInput_b];

  /* Outputs for Enabled SubSystem: '<S187>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S192>/Enable'
   */
  if (rtb_Logic_c_idx_0) {
    /* RelationalOperator: '<S192>/Relational Operator' incorporates:
     *  Constant: '<S192>/Constant1'
     *  UnitDelay: '<S192>/Unit Delay1'
     */
    MotorControlLib_B.RelationalOperator = (MotorControlLib_DW.UnitDelay1_DSTATE
      <= 10000);

    /* Update for UnitDelay: '<S192>/Unit Delay1' incorporates:
     *  Constant: '<S192>/Constant'
     *  Sum: '<S192>/Add'
     */
    MotorControlLib_DW.UnitDelay1_DSTATE++;
  }

  /* End of Outputs for SubSystem: '<S187>/Enabled Subsystem1' */

  /* Abs: '<S188>/Abs' incorporates:
   *  DiscreteIntegrator: '<S188>/Discrete-Time Integrator'
   */
  if (constantAngle < 0) {
    tmp = (int16_T)-constantAngle;
  } else {
    tmp = constantAngle;
  }

  /* Update for UnitDelay: '<S188>/Unit Delay' incorporates:
   *  Abs: '<S188>/Abs'
   *  RelationalOperator: '<S188>/Relational Operator'
   */
  MotorControlLib_DW.UnitDelay_DSTATE_p = (tmp >= 1608);

  /* Update for DiscreteIntegrator: '<S188>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/Inport4'
   */
  MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE = (int16_T)(((6711 * dth_dt) >>
    17) + MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE);
  MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_UnitDelay_n;

  /* Update for UnitDelay: '<S190>/Delay Input1'
   *
   * Block description for '<S190>/Delay Input1':
   *
   *  Store in Global RAM
   */
  MotorControlLib_DW.DelayInput1_DSTATE_f = rtb_UnitDelay1_b;

  /* Update for UnitDelay: '<S187>/Unit Delay1' */
  MotorControlLib_DW.UnitDelay1_DSTATE_m = MotorControlLib_B.RelationalOperator;

  /* Update for UnitDelay: '<S187>/Unit Delay' */
  MotorControlLib_DW.UnitDelay_DSTATE_e = rtb_Logic_c_idx_0;

  /* Update for Memory: '<S193>/Memory' */
  MotorControlLib_DW.Memory_PreviousInput = rtb_Logic_idx_0;

  /* Update for Memory: '<S194>/Memory' */
  MotorControlLib_DW.Memory_PreviousInput_b = rtb_Logic_c_idx_0;

  /* End of Outputs for SubSystem: '<Root>/Start up' */

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Inport: '<Root>/Inport1'
   */
  switch (set_AngleInput) {
   case 0:
    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  DiscreteIntegrator: '<S188>/Discrete-Time Integrator'
     */
    Sig_theta_el_m = (real32_T)constantAngle * 0.00390625F;
    break;

   case 1:
    /* MultiPortSwitch: '<Root>/Multiport Switch' */
    Sig_theta_el_m = 0.0F;
    break;

   case 2:
    /* MultiPortSwitch: '<Root>/Multiport Switch' */
    Sig_theta_el_m = 0.0F;
    break;

   default:
    /* MultiPortSwitch: '<Root>/Multiport Switch' */
    Sig_theta_el_m = rtb_AngleElec;
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* ModelReference: '<Root>/ADCRAwToCurrent(Iabc)' */
  ADCRawToIab(&Sig_Ia_m, &Sig_Ib_m);

  /* SignalConversion generated from: '<Root>/Vector Concatenate' */
  rtb_Switch[0] = Sig_Ia_m;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' */
  rtb_Switch[1] = Sig_Ib_m;

  /* ModelReference: '<Root>/SafetyChecks' */
  SafetyChecks(&rtb_Switch[0],
               &(MotorControlLib_DW.SafetyChecks_InstanceData.rtdw));

  /* RateTransition: '<Root>/Rate Transition5' */
  rtb_AngleMec_1z = MotorControlLib_DW.RateTransition5_Buffer0;

  /* RateTransition: '<Root>/Rate Transition6' */
  rtb_UnitDelay_n = MotorControlLib_DW.RateTransition6_Buffer0;

  /* Switch: '<S5>/Switch' */
  if (rtb_UnitDelay_n) {
    /* Switch: '<S5>/Switch' */
    Sig_Iq_Soll = rtb_AngleMec_1z;
  } else {
    /* Switch: '<S5>/Switch' incorporates:
     *  DataStoreRead: '<S5>/Data Store Read'
     *  Gain: '<S21>/Tq--> iqRef'
     */
    Sig_Iq_Soll = (real32_T)TqToIqConst * 0.00390625F * ((real32_T)qSoll *
      0.00390625F);
  }

  /* End of Switch: '<S5>/Switch' */

  /* Gain: '<S16>/convert_pu' */
  rtb_AngleMec_1z = 0.159154937F * Sig_theta_el_m;

  /* If: '<S16>/If' incorporates:
   *  Constant: '<S17>/Constant'
   *  DataTypeConversion: '<S18>/Convert_back'
   *  DataTypeConversion: '<S18>/Convert_uint16'
   *  DataTypeConversion: '<S19>/Convert_back'
   *  DataTypeConversion: '<S19>/Convert_uint16'
   *  Gain: '<S14>/indexing'
   *  RelationalOperator: '<S17>/Compare'
   *  Sum: '<S18>/Sum'
   *  Sum: '<S19>/Sum'
   */
  if (rtb_AngleMec_1z < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    rtb_b = rtb_AngleMec_1z - (real32_T)(int16_T)floorf(rtb_AngleMec_1z);

    /* End of Outputs for SubSystem: '<S16>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    rtb_b = rtb_AngleMec_1z - (real32_T)(int16_T)rtb_AngleMec_1z;

    /* End of Outputs for SubSystem: '<S16>/If Action Subsystem1' */
  }

  rtb_b *= 400.0F;

  /* End of If: '<S16>/If' */

  /* DataTypeConversion: '<S14>/Get_Integer' */
  rtb_uDLookupTable_tmp_tmp = (uint16_T)rtb_b;

  /* Sum: '<S14>/Sum2' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion1'
   *  DataTypeConversion: '<S14>/Get_Integer'
   */
  rtb_b -= (real32_T)(uint16_T)rtb_b;

  /* Selector: '<S14>/Lookup' incorporates:
   *  Constant: '<S14>/offset'
   *  Constant: '<S14>/sine_table_values'
   *  DataTypeConversion: '<S14>/Get_Integer'
   *  Sum: '<S14>/Sum'
   *  Sum: '<S15>/Sum5'
   */
  rtb_AngleMec_1z = rtCP_sine_table_values_Value[(int32_T)
    (rtb_uDLookupTable_tmp_tmp + 100U)];

  /* Sum: '<S15>/Sum6' incorporates:
   *  Constant: '<S14>/offset'
   *  Constant: '<S14>/sine_table_values'
   *  DataTypeConversion: '<S14>/Get_Integer'
   *  Product: '<S15>/Product1'
   *  Selector: '<S14>/Lookup'
   *  Sum: '<S14>/Sum'
   *  Sum: '<S15>/Sum5'
   */
  Sig_cos_m = (rtCP_sine_table_values_Value[(int32_T)(rtb_uDLookupTable_tmp_tmp
    + 101U)] - rtb_AngleMec_1z) * rtb_b + rtb_AngleMec_1z;

  /* Gain: '<S196>/one_by_sqrt3' incorporates:
   *  Sum: '<S196>/a_plus_2b'
   */
  Sig_Ibeta_m = ((Sig_Ia_m + Sig_Ib_m) + Sig_Ib_m) * 0.577350259F;

  /* Selector: '<S14>/Lookup' incorporates:
   *  Constant: '<S14>/sine_table_values'
   *  DataTypeConversion: '<S14>/Get_Integer'
   */
  rtb_AngleMec_1z = rtCP_sine_table_values_Value[rtb_uDLookupTable_tmp_tmp];

  /* Sum: '<S15>/Sum4' incorporates:
   *  Constant: '<S14>/offset'
   *  Constant: '<S14>/sine_table_values'
   *  DataTypeConversion: '<S14>/Get_Integer'
   *  Product: '<S15>/Product'
   *  Selector: '<S14>/Lookup'
   *  Sum: '<S14>/Sum'
   *  Sum: '<S15>/Sum3'
   */
  Sig_sin_m = (rtCP_sine_table_values_Value[(int32_T)(rtb_uDLookupTable_tmp_tmp
    + 1U)] - rtb_AngleMec_1z) * rtb_b + rtb_AngleMec_1z;

  /* Switch: '<S198>/Switch' incorporates:
   *  Product: '<S197>/acos'
   *  Product: '<S197>/asin'
   *  Product: '<S197>/bcos'
   *  Product: '<S197>/bsin'
   *  Sum: '<S197>/sum_Ds'
   *  Sum: '<S197>/sum_Qs'
   */
  rtb_Switch[0] = Sig_Ia_m * Sig_cos_m + Sig_Ibeta_m * Sig_sin_m;
  rtb_Switch[1] = Sig_Ibeta_m * Sig_cos_m - Sig_Ia_m * Sig_sin_m;

  /* Gain: '<S11>/Gain2' */
  Sig_Id_axis_meas = rtb_Switch[0];

  /* Gain: '<S11>/Gain3' */
  Sig_Iq_axis_meas = rtb_Switch[1];

  /* Outputs for Atomic SubSystem: '<S7>/PI_Controller' */
  /* Sum: '<S75>/Add' incorporates:
   *  Constant: '<S7>/d Soll'
   */
  Sig_dAxis_errorSum_m = (real32_T)dSoll - Sig_Id_axis_meas;

  /* Sum: '<S75>/Add1' */
  Sig_qAxis_errorSum_m = Sig_Iq_Soll - Sig_Iq_axis_meas;

  /* DataTypeConversion: '<S75>/Data Type Conversion1' incorporates:
   *  Constant: '<S75>/Constant5'
   */
  Sig_IQ = (real32_T)Ki_qAxis * 0.00390625F;

  /* DataTypeConversion: '<S75>/Data Type Conversion2' incorporates:
   *  Constant: '<S75>/Constant4'
   */
  Sig_PQ = (real32_T)Kp_qAxis * 0.00390625F;

  /* DataTypeConversion: '<S75>/Data Type Conversion3' incorporates:
   *  Constant: '<S75>/Constant6'
   */
  Sig_PD = (real32_T)Kp_dAxis * 0.00390625F;

  /* DataTypeConversion: '<S75>/Data Type Conversion4' incorporates:
   *  Constant: '<S75>/Constant7'
   */
  Sig_ID = (real32_T)Ki_dAxis * 0.00390625F;

  /* Outputs for Enabled SubSystem: '<S78>/Subsystem' incorporates:
   *  EnablePort: '<S182>/Enable'
   */
  /* UnitDelay: '<S78>/Unit Delay' */
  if (MotorControlLib_DW.UnitDelay_DSTATE_o) {
    /* Sum: '<S182>/Add2' incorporates:
     *  Constant: '<S78>/Constant8'
     *  UnitDelay: '<S182>/Unit Delay'
     */
    MotorControlLib_B.Add2 = (uint16_T)(MotorControlLib_DW.UnitDelay_DSTATE + 1U);

    /* Update for UnitDelay: '<S182>/Unit Delay' */
    MotorControlLib_DW.UnitDelay_DSTATE = MotorControlLib_B.Add2;
  }

  /* End of UnitDelay: '<S78>/Unit Delay' */
  /* End of Outputs for SubSystem: '<S78>/Subsystem' */

  /* RelationalOperator: '<S181>/Compare' incorporates:
   *  Constant: '<S181>/Constant'
   */
  rtb_UnitDelay_n = (MotorControlLib_B.Add2 < 1500);

  /* Logic: '<S75>/OR' incorporates:
   *  Inport: '<Root>/Inport6'
   */
  rtb_UnitDelay1_b = (rtb_UnitDelay_n || resetPIIntegratorDQ);

  if (!Sig_requestMotorBreak) {
  /* Outputs for Atomic SubSystem: '<S75>/PI Qaxis' */
  /* SignalConversion generated from: '<S75>/PI Qaxis' */
  Sig_qAxis_PI_out = MotorControlLib_PIDAxis_m(Sig_qAxis_errorSum_m, Sig_PQ,
    Sig_IQ, rtb_UnitDelay1_b, 0.0F, &MotorControlLib_DW.PIQaxis);

  /* End of Outputs for SubSystem: '<S75>/PI Qaxis' */

  /* Outputs for Atomic SubSystem: '<S75>/PI DAxis' */
  /* SignalConversion generated from: '<S75>/PI DAxis' */
  Sig_dAxis_PI_out = MotorControlLib_PIDAxis_m(Sig_dAxis_errorSum_m, Sig_PD,
    Sig_ID, rtb_UnitDelay1_b, 0.0F, &MotorControlLib_DW.PIDAxis_m);

  }
  else {
	  Sig_qAxis_PI_out=0.0f;
	  Sig_dAxis_PI_out=0.0f;
  }
  /* End of Outputs for SubSystem: '<S75>/PI DAxis' */

  /* Update for UnitDelay: '<S78>/Unit Delay' */
  MotorControlLib_DW.UnitDelay_DSTATE_o = rtb_UnitDelay_n;

  /* Outputs for Atomic SubSystem: '<S7>/DQ_Limiter' */
  /* Gain: '<S75>/Gain' */
  MotorControlLib_DQ_Limiter(Sig_dAxis_PI_out, Minus_1 * Sig_qAxis_PI_out,
    rtb_Switch, &rtb_AngleMec_1z, d_q_Voltage_Limiter_max);

  /* End of Outputs for SubSystem: '<S7>/DQ_Limiter' */
  /* End of Outputs for SubSystem: '<S7>/PI_Controller' */

  /* SignalConversion generated from: '<S7>/DQ_Limiter' */
  Sig_Vqsatu_m = rtb_Switch[1];

  /* SignalConversion generated from: '<S7>/DQ_Limiter' */
  Sig_Vdsatu_m = rtb_Switch[0];

  /* Gain: '<Root>/Gain' incorporates:
   *  Product: '<S4>/dcos'
   *  Product: '<S4>/qsin'
   *  Sum: '<S4>/sum_alpha'
   */
  Sig_Va_m = Sig_Vdsatu_m * Sig_cos_m - Sig_Vqsatu_m * Sig_sin_m;

  /* Gain: '<Root>/Gain1' incorporates:
   *  Product: '<S4>/dsin'
   *  Product: '<S4>/qcos'
   *  Sum: '<S4>/sum_beta'
   */
  Sig_Vb_m = Sig_Vqsatu_m * Sig_cos_m + Sig_Vdsatu_m * Sig_sin_m;

  /* Outputs for Atomic SubSystem: '<S8>/Inverse Clarke Transform' */
  /* Gain: '<S183>/one_by_two' incorporates:
   *  SignalConversion generated from: '<S183>/In1'
   */
  rtb_AngleMec_1z = 0.5F * Sig_Va_m;

  /* Gain: '<S183>/sqrt3_by_two' */
  rtb_b = 0.866025388F * Sig_Vb_m;

  /* Sum: '<S183>/add_b' */
  rtb_add_b = rtb_b - rtb_AngleMec_1z;

  /* Sum: '<S183>/add_c' */
  rtb_add_c = (0.0F - rtb_AngleMec_1z) - rtb_b;

  /* End of Outputs for SubSystem: '<S8>/Inverse Clarke Transform' */

  /* Outputs for Atomic SubSystem: '<S8>/Space Vector Generator' */
  /* Gain: '<S184>/one_by_sqrt3' */
  rtb_c = 0.577350259F * Sig_Va_m;

  /* Sum: '<S184>/a' */
  rtb_a = rtb_c + rtb_c;

  /* Sum: '<S184>/b' */
  rtb_b = Sig_Vb_m - rtb_c;

  /* Sum: '<S184>/c' */
  rtb_c = (0.0F - rtb_c) - Sig_Vb_m;

  /* Gain: '<S184>/one_by_two' incorporates:
   *  MinMax: '<S184>/Max'
   *  MinMax: '<S184>/Min'
   *  Sum: '<S184>/Add'
   */
  rtb_AngleMec_1z = (fmaxf(fmaxf(rtb_a, rtb_b), rtb_c) + fminf(fminf(rtb_a,
    rtb_b), rtb_c)) * 0.5F;

  /* End of Outputs for SubSystem: '<S8>/Space Vector Generator' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Inport: '<Root>/In1'
   *  Switch: '<S8>/Switch1'
   *  Switch: '<S8>/Switch2'
   */
  if (Sig_change_SVMalgorithm) {
    /* Outputs for Atomic SubSystem: '<S8>/Inverse Clarke Transform' */
    /* Switch: '<S8>/Switch' incorporates:
     *  SignalConversion generated from: '<S183>/In1'
     */
    Sig_Valpha_m = Sig_Va_m;

    /* End of Outputs for SubSystem: '<S8>/Inverse Clarke Transform' */

    /* Switch: '<S8>/Switch1' */
    Sig_Vbeta_m = rtb_add_b;

    /* Switch: '<S8>/Switch2' */
    Sig_Vgamma_m = rtb_add_c;
  } else {
    /* Outputs for Atomic SubSystem: '<S8>/Space Vector Generator' */
    /* Switch: '<S8>/Switch' incorporates:
     *  Sum: '<S184>/Da'
     */
    Sig_Valpha_m = rtb_a - rtb_AngleMec_1z;

    /* Switch: '<S8>/Switch1' incorporates:
     *  Sum: '<S184>/Db'
     */
    Sig_Vbeta_m = rtb_b - rtb_AngleMec_1z;

    /* Switch: '<S8>/Switch2' incorporates:
     *  Sum: '<S184>/Dc'
     */
    Sig_Vgamma_m = rtb_c - rtb_AngleMec_1z;

    /* End of Outputs for SubSystem: '<S8>/Space Vector Generator' */
  }

  /* End of Switch: '<S8>/Switch' */

  /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
   *  Lookup_n-D: '<S8>/1-D Lookup Table'
   *  Switch: '<S8>/Switch'
   */
  set_PWM_A_DT(look1_iflftu16Df_binlc(Sig_Valpha_m, &BrkPoints[0],
    &pwmTableData[0], 2U));

  /* DataTypeConversion: '<S8>/Data Type Conversion1' incorporates:
   *  Lookup_n-D: '<S8>/1-D Lookup Table1'
   *  Switch: '<S8>/Switch1'
   */
  set_PWM_B_DT(look1_iflftu16Df_binlc(Sig_Vbeta_m, &BrkPoints[0], &pwmTableData
    [0], 2U));

  /* DataTypeConversion: '<S8>/Data Type Conversion2' incorporates:
   *  Lookup_n-D: '<S8>/1-D Lookup Table2'
   *  Switch: '<S8>/Switch2'
   */
  set_PWM_C_DT(look1_iflftu16Df_binlc(Sig_Vgamma_m, &BrkPoints[0],
    &pwmTableData[0], 2U));

  /* SampleTimeMath: '<S3>/TSamp'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_AngleMec_1z = Sig_MechanicalAngle * 5000.0F;

  /* Sum: '<S3>/Diff' incorporates:
   *  UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  Sig_Speed_rads = rtb_AngleMec_1z - MotorControlLib_DW.UD_DSTATE;

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  AngleMec_1z = Sig_MechanicalAngle;

  /* Update for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  MotorControlLib_DW.UD_DSTATE = rtb_AngleMec_1z;
}

/* Model step function for TID2 */
void MotorControlLib_step2(void)       /* Sample time: [0.01s, 0.0s] */
{
  real32_T rtb_RateTransition1;
  boolean_T rtb_RateTransition4;

  /* RateTransition: '<Root>/Rate Transition1' */
  rtb_RateTransition1 = Sig_Speed_rads;

  /* Outputs for Atomic SubSystem: '<Root>/Speed Calculator' */
  /* Switch: '<S9>/Switch' incorporates:
   *  DataStoreRead: '<S9>/Data Store Read1'
   */
  /* Unit Conversion - from: rad/s to: rpm
     Expression: output = (9.5493*input) + (0) */
  if (Sig_speed_timer_has_overflowed) {
    /* Switch: '<S9>/Switch' incorporates:
     *  UnitConversion: '<S9>/Unit Conversion'
     */
    Sig_Rpm_measurment = 9.54929638F * rtb_RateTransition1;
    if(Sig_Rpm_measurment>200) {
    	Sig_speed_timer_has_overflowed = 0;
    }
  } else {
    /* Switch: '<S9>/Switch' */
    Sig_Rpm_measurment = MotorControlLib_B.DataTypeConversion;
  }

  /* End of Switch: '<S9>/Switch' */
  /* End of Outputs for SubSystem: '<Root>/Speed Calculator' */

  /* RateTransition: '<Root>/Rate Transition4' incorporates:
   *  Inport: '<Root>/Inport6'
   */
  rtb_RateTransition4 = resetPIIntegratorDQ;

  /* Outputs for Enabled SubSystem: '<Root>/PI controller RPM' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  /* Inport: '<Root>/Inport8' */
  if (activateRPMCntlr) {
    /* DataTypeConversion: '<S6>/Data Type Conversion3' incorporates:
     *  Constant: '<S6>/Constant6'
     */
    Sig_PRPM = (real32_T)Kp_Rpm * 0.00048828125F;

    /* DataTypeConversion: '<S6>/Data Type Conversion4' incorporates:
     *  Constant: '<S6>/Constant7'
     */
    Sig_IRPM = (real32_T)Ki_Rpm * 0.00048828125F;

    /* Outputs for Atomic SubSystem: '<S6>/PI DAxis' */
    /* Sum: '<S6>/Add' incorporates:
     *  DataStoreRead: '<S6>/Data Store Read1'
     */
    MotorControlLib_PIDAxis((real32_T)rpmSoll - Sig_Rpm_measurment, Sig_PRPM,
      Sig_IRPM, rtb_RateTransition4, 0.0F, &MotorControlLib_B.Saturation,
      &MotorControlLib_DW.PIDAxis);

    /* End of Outputs for SubSystem: '<S6>/PI DAxis' */
  }

  /* End of Inport: '<Root>/Inport8' */
  /* End of Outputs for SubSystem: '<Root>/PI controller RPM' */

  /* RateTransition: '<Root>/Rate Transition5' */
  MotorControlLib_DW.RateTransition5_Buffer0 = MotorControlLib_B.Saturation;

  /* Update for RateTransition generated from: '<S1>/AND' incorporates:
   *  Inport: '<Root>/Inport8'
   */
  MotorControlLib_DW.TmpRTBAtANDInport1_Buffer0 = activateRPMCntlr;

  /* Update for RateTransition: '<Root>/Rate Transition6' incorporates:
   *  Inport: '<Root>/Inport8'
   */
  MotorControlLib_DW.RateTransition6_Buffer0 = activateRPMCntlr;
}

/* Model initialize function */
void MotorControlLib_initialize(void)
{
  /* Registration code */

  /* external inputs */
  set_AngleInput = 3U;
  dth_dt = 210;
  Sig_change_SVMalgorithm = true;

  /* Model Initialize function for ModelReference Block: '<Root>/ADCRAwToCurrent(Iabc)' */
  ADCRawToIab_initialize(rtmGetErrorStatusPointer(MotorControlLib_M),
    &(MotorControlLib_DW.ADCRAwToCurrentIabc_InstanceDat.rtm));

  /* Model Initialize function for ModelReference Block: '<Root>/AngleCalculation' */
  ConvertPWMtoAngle_initialize(rtmGetErrorStatusPointer(MotorControlLib_M));

  /* Model Initialize function for ModelReference Block: '<Root>/SafetyChecks' */
  SafetyChecks_initialize(rtmGetErrorStatusPointer(MotorControlLib_M),
    &(MotorControlLib_DW.SafetyChecks_InstanceData.rtm));

  /* SystemInitialize for ModelReference: '<Root>/AngleCalculation' incorporates:
   *  Inport: '<Root>/Duty cycle input'
   *  Inport: '<Root>/Encoder input'
   */
  ConvertPWMtoAngle_Init();

  /* SystemInitialize for Enabled SubSystem: '<Root>/PI controller RPM' */
  /* SystemInitialize for Atomic SubSystem: '<S6>/PI DAxis' */
  MotorControlLi_PIDAxis_Init(&MotorControlLib_DW.PIDAxis);

  /* End of SystemInitialize for SubSystem: '<S6>/PI DAxis' */
  /* End of SystemInitialize for SubSystem: '<Root>/PI controller RPM' */

  /* SystemInitialize for Atomic SubSystem: '<S7>/PI_Controller' */
  /* SystemInitialize for Atomic SubSystem: '<S75>/PI DAxis' */
  MotorControl_PIDAxis_c_Init(&MotorControlLib_DW.PIDAxis_m);

  /* End of SystemInitialize for SubSystem: '<S75>/PI DAxis' */

  /* SystemInitialize for Atomic SubSystem: '<S75>/PI Qaxis' */
  MotorControl_PIDAxis_c_Init(&MotorControlLib_DW.PIQaxis);

  /* End of SystemInitialize for SubSystem: '<S75>/PI Qaxis' */
  /* End of SystemInitialize for SubSystem: '<S7>/PI_Controller' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Start up' */
  /* InitializeConditions for DiscreteIntegrator: '<S188>/Discrete-Time Integrator' */
  MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* End of SystemInitialize for SubSystem: '<Root>/Start up' */
}

/* Model terminate function */
void MotorControlLib_terminate(void)
{
  /* (no terminate code required) */
}

float lowPassFilter(float currentValue, float previousFilteredValue) {
    return ALPHA * currentValue + (1 - ALPHA) * previousFilteredValue;
}
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
