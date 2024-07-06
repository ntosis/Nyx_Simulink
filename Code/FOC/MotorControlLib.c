/*
 * File: MotorControlLib.c
 *
 * Code generated for Simulink model 'MotorControlLib'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Jul 31 15:23:33 2023
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
#include "look1_iflftu16Df_binlcm.h"
#include "ConstParams.h"
#include "ADCRawToIab.h"
#include "SafetyChecks.h"
#define ConvertPWMtoAngle_MDLREF_HIDE_CHILD_
#include "ConvertPWMtoAngle.h"
#define SAMPLE_RATE 5000 // Sampling rate in Hz (100 samples per second)
#define CUTOFF_FREQ 100 // Cutoff frequency in Hz

// Calculate the filter coefficient based on the cutoff frequency and sampling rate
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
real32_T Sig_Iq_Soll;                  /* '<S4>/Switch' */
real32_T Sig_cos_m;                    /* '<S13>/Sum6' */
real32_T Sig_Ibeta_m;                  /* '<S192>/one_by_sqrt3' */
real32_T Sig_sin_m;                    /* '<S13>/Sum4' */
real32_T Sig_Id_axis_meas;             /* '<S9>/Gain2' */
real32_T Sig_Iq_axis_meas;             /* '<S9>/Gain3' */
real32_T Sig_Vqsatu_m;                 /* '<S6>/DQ_Limiter' */
real32_T Sig_Vdsatu_m;                 /* '<S6>/DQ_Limiter' */
real32_T Sig_Va_m;                     /* '<Root>/Gain' */
real32_T Sig_Vb_m;                     /* '<Root>/Gain1' */
real32_T Sig_Valpha_m;                 /* '<S7>/Switch' */
real32_T Sig_Vbeta_m;                  /* '<S7>/Switch1' */
real32_T Sig_Vgamma_m;                 /* '<S7>/Switch2' */
real32_T Sig_angle_speed;              /* '<Root>/Integrator of Angle' */
real32_T Sig_dAxis_errorSum_m;         /* '<S73>/Add' */
real32_T Sig_qAxis_errorSum_m;         /* '<S73>/Add1' */
real32_T Sig_IQ;                       /* '<S73>/Data Type Conversion1' */
real32_T Sig_PQ;                       /* '<S73>/Data Type Conversion2' */
real32_T Sig_PD;                       /* '<S73>/Data Type Conversion3' */
real32_T Sig_ID;                       /* '<S73>/Data Type Conversion4' */
real32_T Sig_Rpm_measurment;           /* '<S5>/Unit Conversion' */
real32_T Sig_PRPM;                     /* '<S5>/Data Type Conversion3' */
real32_T Sig_IRPM;                     /* '<S5>/Data Type Conversion4' */
int16_T constantAngle;                 /* '<S184>/Discrete-Time Integrator' */
boolean_T Sig_requestMotorBreak;       /* '<S1>/OR' */

/* Exported block parameters */
int16_T d_q_Voltage_Limiter_max = 92;  /* Variable: d_q_Voltage_Limiter_max
                                        * Referenced by: '<S6>/DQ_Limiter'
                                        * =Vnom/sqrt(3)
                                        */
int16_T d_q_Voltage_Limiter_sat_neg = -160;/* Variable: d_q_Voltage_Limiter_sat_neg
                                            * Referenced by:
                                            *   '<S62>/Saturation'
                                            *   '<S118>/Saturation'
                                            *   '<S169>/Saturation'
                                            *   '<S48>/DeadZone'
                                            *   '<S104>/DeadZone'
                                            *   '<S155>/DeadZone'
                                            * fixdt(1,16,2^-4,0)
                                            */
int16_T d_q_Voltage_Limiter_sat_pos = 160;/* Variable: d_q_Voltage_Limiter_sat_pos
                                           * Referenced by:
                                           *   '<S62>/Saturation'
                                           *   '<S118>/Saturation'
                                           *   '<S169>/Saturation'
                                           *   '<S48>/DeadZone'
                                           *   '<S104>/DeadZone'
                                           *   '<S155>/DeadZone'
                                           * fixdt(1,16,2^-4,0)
                                           */
uint16_T Ki_Rpm = 0U;              /* Variable: Ki_Rpm
                                        * Referenced by: '<S5>/Constant7'
                                        * fixdt(0,16,2^-11,0)
                                        */
uint16_T Kp_Rpm = 0U;                /* Variable: Kp_Rpm
                                        * Referenced by: '<S5>/Constant6'
                                        * fixdt(0,16,2^-11,0)
                                        */
uint16_T Ki_dAxis = 0U;            /* Variable: Ki_dAxis
                                        * Referenced by: '<S73>/Constant7'
                                        * fixdt(0,16,2^-8,0)
                                        */
uint16_T Ki_qAxis = 0U;            /* Variable: Ki_qAxis
                                        * Referenced by: '<S73>/Constant5'
                                        * fixdt(0,16,2^-8,0)
                                        */
uint16_T Kp_dAxis = 200U;               /* Variable: Kp_dAxis
                                        * Referenced by: '<S73>/Constant6'
                                        * fixdt(0,16,2^-8,0)
                                        */
uint16_T Kp_qAxis = 800U;               /* Variable: Kp_qAxis
                                        * Referenced by: '<S73>/Constant4'
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

/* System initialize for atomic system: '<S5>/PI DAxis' */
void MotorControlLi_PIDAxis_Init(DW_PIDAxis_MotorControlLib_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S55>/Integrator' */
  localDW->Integrator_IC_LOADING = 1U;
}

/* Output and update for atomic system: '<S5>/PI DAxis' */
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

  /* DiscreteIntegrator: '<S55>/Integrator' */
  if (localDW->Integrator_IC_LOADING != 0) {
    localDW->Integrator_DSTATE = rtu_init;
  }

  if (rtu_Reset || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = rtu_init;
  }

  /* Sum: '<S64>/Sum' incorporates:
   *  DiscreteIntegrator: '<S55>/Integrator'
   *  Product: '<S60>/PProd Out'
   */
  rtb_Sum_g = rtu_error * rtu_P + localDW->Integrator_DSTATE;

  /* DeadZone: '<S48>/DeadZone' incorporates:
   *  Saturate: '<S62>/Saturation'
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

  /* End of DeadZone: '<S48>/DeadZone' */

  /* RelationalOperator: '<S46>/Relational Operator' incorporates:
   *  Constant: '<S46>/Clamping_zero'
   */
  rtb_RelationalOperator_k = (rtb_IProdOut != 0.0F);

  /* Switch: '<S46>/Switch1' incorporates:
   *  Constant: '<S46>/Clamping_zero'
   *  Constant: '<S46>/Constant'
   *  Constant: '<S46>/Constant2'
   *  RelationalOperator: '<S46>/fix for DT propagation issue'
   */
  if (rtb_IProdOut > 0.0F) {
    rtb_Switch1 = 1;
  } else {
    rtb_Switch1 = -1;
  }

  /* End of Switch: '<S46>/Switch1' */

  /* Product: '<S52>/IProd Out' */
  rtb_IProdOut = rtu_error * rtu_I;

  /* Saturate: '<S62>/Saturation' */
  u1 = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
  if (rtb_Sum_g > u2) {
    *rty_PIDOut = u2;
  } else if (rtb_Sum_g < u1) {
    *rty_PIDOut = u1;
  } else {
    *rty_PIDOut = rtb_Sum_g;
  }

  /* Update for DiscreteIntegrator: '<S55>/Integrator' */
  localDW->Integrator_IC_LOADING = 0U;

  /* Switch: '<S46>/Switch2' incorporates:
   *  Constant: '<S46>/Clamping_zero'
   *  Constant: '<S46>/Constant3'
   *  Constant: '<S46>/Constant4'
   *  RelationalOperator: '<S46>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S46>/Switch' incorporates:
   *  Constant: '<S46>/Constant1'
   *  Logic: '<S46>/AND3'
   *  RelationalOperator: '<S46>/Equal1'
   *  Switch: '<S46>/Switch2'
   */
  if (rtb_RelationalOperator_k && (rtb_Switch1 == tmp)) {
    rtb_IProdOut = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S55>/Integrator' incorporates:
   *  Switch: '<S46>/Switch'
   */
  localDW->Integrator_DSTATE += 0.01F * rtb_IProdOut;
  localDW->Integrator_PrevResetState = (int8_T)rtu_Reset;
}

/* Output and update for atomic system: '<S6>/DQ_Limiter' */
void MotorControlLib_DQ_Limiter(real32_T rtu_Vd_ref, real32_T rtu_Vq_ref,
  real32_T rty_Vd_sat[2], real32_T *rty_Vmax_unsat, int16_T rtp_Vmax)
{
  real32_T rtb_Gain;

  /* Sum: '<S72>/Sum2' incorporates:
   *  Product: '<S72>/Product'
   *  Product: '<S72>/Product1'
   */
  *rty_Vmax_unsat = rtu_Vd_ref * rtu_Vd_ref + rtu_Vq_ref * rtu_Vq_ref;

  /* Sqrt: '<S72>/Sqrt' */
  *rty_Vmax_unsat = sqrtf(*rty_Vmax_unsat);

  /* Switch: '<S72>/Switch' incorporates:
   *  Gain: '<S72>/Gain'
   *  Math: '<S72>/Math Function2'
   *  Product: '<S72>/Product2'
   *
   * About '<S72>/Math Function2':
   *  Operator: reciprocal
   */
  rtb_Gain = (real32_T)rtp_Vmax * 0.0625F;
  if (*rty_Vmax_unsat >= rtb_Gain) {
    rtb_Gain *= 1.0F / *rty_Vmax_unsat;
    rty_Vd_sat[0] = rtb_Gain * rtu_Vd_ref;
    rty_Vd_sat[1] = rtb_Gain * rtu_Vq_ref;
  } else {
    rty_Vd_sat[0] = rtu_Vd_ref;
    rty_Vd_sat[1] = rtu_Vq_ref;
  }

  /* End of Switch: '<S72>/Switch' */
}

/*
 * System initialize for atomic system:
 *    '<S73>/PI DAxis'
 *    '<S73>/PI Qaxis'
 */
void MotorControl_PIDAxis_c_Init(DW_PIDAxis_MotorControlLib_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S111>/Integrator' */
  localDW->Integrator_IC_LOADING = 1U;
}

/*
 * Output and update for atomic system:
 *    '<S73>/PI DAxis'
 *    '<S73>/PI Qaxis'
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

  /* DiscreteIntegrator: '<S111>/Integrator' */
  if (localDW->Integrator_IC_LOADING != 0) {
    localDW->Integrator_DSTATE = rtu_init;
  }

  if (rtu_Reset || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = rtu_init;
  }

  /* Sum: '<S120>/Sum' incorporates:
   *  DiscreteIntegrator: '<S111>/Integrator'
   *  Product: '<S116>/PProd Out'
   */
  rty_PIDOut_0 = rtu_error * rtu_P + localDW->Integrator_DSTATE;

  /* DeadZone: '<S104>/DeadZone' incorporates:
   *  Saturate: '<S118>/Saturation'
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

  /* End of DeadZone: '<S104>/DeadZone' */

  /* RelationalOperator: '<S102>/Relational Operator' incorporates:
   *  Constant: '<S102>/Clamping_zero'
   */
  rtb_RelationalOperator_e = (rtb_IProdOut != 0.0F);

  /* Switch: '<S102>/Switch1' incorporates:
   *  Constant: '<S102>/Clamping_zero'
   *  Constant: '<S102>/Constant'
   *  Constant: '<S102>/Constant2'
   *  RelationalOperator: '<S102>/fix for DT propagation issue'
   */
  if (rtb_IProdOut > 0.0F) {
    rtb_Switch1 = 1;
  } else {
    rtb_Switch1 = -1;
  }

  /* End of Switch: '<S102>/Switch1' */

  /* Product: '<S108>/IProd Out' */
  rtb_IProdOut = rtu_error * rtu_I;

  /* Saturate: '<S118>/Saturation' */
  u1 = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
  if (rty_PIDOut_0 > u2) {
    rty_PIDOut_0 = u2;
  } else if (rty_PIDOut_0 < u1) {
    rty_PIDOut_0 = u1;
  }

  /* Update for DiscreteIntegrator: '<S111>/Integrator' */
  localDW->Integrator_IC_LOADING = 0U;

  /* Switch: '<S102>/Switch2' incorporates:
   *  Constant: '<S102>/Clamping_zero'
   *  Constant: '<S102>/Constant3'
   *  Constant: '<S102>/Constant4'
   *  RelationalOperator: '<S102>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S102>/Switch' incorporates:
   *  Constant: '<S102>/Constant1'
   *  Logic: '<S102>/AND3'
   *  RelationalOperator: '<S102>/Equal1'
   *  Switch: '<S102>/Switch2'
   */
  if (rtb_RelationalOperator_e && (rtb_Switch1 == tmp)) {
    rtb_IProdOut = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S111>/Integrator' incorporates:
   *  Switch: '<S102>/Switch'
   */
  localDW->Integrator_DSTATE += 0.0002F * rtb_IProdOut;
  localDW->Integrator_PrevResetState = (int8_T)rtu_Reset;
  return rty_PIDOut_0;
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
  real32_T rtb_Switch_i[2];
  real32_T rtb_RateTransition5;
  real32_T rtb_Saturation;
  real32_T rtb_a;
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

  /* Outputs for Atomic SubSystem: '<Root>/Start up' */
  /* UnitDelay: '<S184>/Unit Delay' */
  rtb_UnitDelay_n = MotorControlLib_DW.UnitDelay_DSTATE_p;

  /* DiscreteIntegrator: '<S184>/Discrete-Time Integrator' incorporates:
   *  UnitDelay: '<S184>/Unit Delay'
   */
  if (MotorControlLib_DW.UnitDelay_DSTATE_p &&
      (MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE = 0;
  }

  /* DiscreteIntegrator: '<S184>/Discrete-Time Integrator' */
  constantAngle = MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE;

  /* UnitDelay: '<S183>/Unit Delay1' */
  rtb_UnitDelay1_b = MotorControlLib_DW.UnitDelay1_DSTATE_m;

  /* CombinatorialLogic: '<S189>/Logic' incorporates:
   *  Memory: '<S189>/Memory'
   *  UnitDelay: '<S183>/Unit Delay'
   */
  rtb_Logic_idx_0 = rtCP_Logic_table[((int32_T)
    (((MotorControlLib_DW.UnitDelay_DSTATE_e + 2U) << 1) +
     MotorControlLib_DW.Memory_PreviousInput) % 8) << 1];

  /* Outputs for Enabled SubSystem: '<S183>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S187>/Enable'
   */
  if (rtb_Logic_idx_0) {
    /* RelationalOperator: '<S191>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S191>/Delay Input1'
     *
     * Block description for '<S191>/Delay Input1':
     *
     *  Store in Global RAM
     */
    MotorControlLib_B.FixPtRelationalOperator =
      (MotorControlLib_DW.DelayInput1_DSTATE != 0.0);

    /* Update for UnitDelay: '<S191>/Delay Input1'
     *
     * Block description for '<S191>/Delay Input1':
     *
     *  Store in Global RAM
     */
    MotorControlLib_DW.DelayInput1_DSTATE = 0.0;
  }

  /* End of Outputs for SubSystem: '<S183>/Enabled Subsystem' */

  /* CombinatorialLogic: '<S190>/Logic' incorporates:
   *  Memory: '<S190>/Memory'
   *  RelationalOperator: '<S186>/FixPt Relational Operator'
   *  UnitDelay: '<S186>/Delay Input1'
   *
   * Block description for '<S186>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Logic_c_idx_0 = rtCP_Logic_table_m[((int32_T)(((((uint32_T)
    MotorControlLib_B.FixPtRelationalOperator << 1) + (uint32_T)((int32_T)
    rtb_UnitDelay1_b < (int32_T)MotorControlLib_DW.DelayInput1_DSTATE_f)) << 1)
    + MotorControlLib_DW.Memory_PreviousInput_b) % 8) << 1];

  /* Outputs for Enabled SubSystem: '<S183>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S188>/Enable'
   */
  if (rtb_Logic_c_idx_0) {
    /* RelationalOperator: '<S188>/Relational Operator' incorporates:
     *  Constant: '<S188>/Constant1'
     *  UnitDelay: '<S188>/Unit Delay1'
     */
    MotorControlLib_B.RelationalOperator = (MotorControlLib_DW.UnitDelay1_DSTATE
      <= 10000);

    /* Update for UnitDelay: '<S188>/Unit Delay1' incorporates:
     *  Constant: '<S188>/Constant'
     *  Sum: '<S188>/Add'
     */
    MotorControlLib_DW.UnitDelay1_DSTATE++;
  }

  /* End of Outputs for SubSystem: '<S183>/Enabled Subsystem1' */

  /* Abs: '<S184>/Abs' incorporates:
   *  DiscreteIntegrator: '<S184>/Discrete-Time Integrator'
   */
  if (constantAngle < 0) {
    tmp = (int16_T)-constantAngle;
  } else {
    tmp = constantAngle;
  }

  /* Update for UnitDelay: '<S184>/Unit Delay' incorporates:
   *  Abs: '<S184>/Abs'
   *  RelationalOperator: '<S184>/Relational Operator'
   */
  MotorControlLib_DW.UnitDelay_DSTATE_p = (tmp >= 1608);

  /* Update for DiscreteIntegrator: '<S184>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/Inport4'
   */
  MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE = (int16_T)(((6711 * dth_dt) >>
    17) + MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE);
  MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_UnitDelay_n;

  /* Update for UnitDelay: '<S186>/Delay Input1'
   *
   * Block description for '<S186>/Delay Input1':
   *
   *  Store in Global RAM
   */
  MotorControlLib_DW.DelayInput1_DSTATE_f = rtb_UnitDelay1_b;

  /* Update for UnitDelay: '<S183>/Unit Delay1' */
  MotorControlLib_DW.UnitDelay1_DSTATE_m = MotorControlLib_B.RelationalOperator;

  /* Update for UnitDelay: '<S183>/Unit Delay' */
  MotorControlLib_DW.UnitDelay_DSTATE_e = rtb_Logic_c_idx_0;

  /* Update for Memory: '<S189>/Memory' */
  MotorControlLib_DW.Memory_PreviousInput = rtb_Logic_idx_0;

  /* Update for Memory: '<S190>/Memory' */
  MotorControlLib_DW.Memory_PreviousInput_b = rtb_Logic_c_idx_0;

  /* End of Outputs for SubSystem: '<Root>/Start up' */

  /* RateTransition generated from: '<S1>/AND' */
  if (MotorControlLib_M->Timing.RateInteraction.TID1_2 == 1) {
    /* RateTransition generated from: '<S1>/AND' */
    MotorControlLib_B.TmpRTBAtANDInport1 =
      MotorControlLib_DW.TmpRTBAtANDInport1_Buffer0;
  }

  /* End of RateTransition generated from: '<S1>/AND' */

  /* Logic: '<S1>/OR' incorporates:
   *  Constant: '<S10>/Constant'
   *  DataStoreRead: '<S1>/Data Store Read1'
   *  DataStoreRead: '<S1>/Data Store Read2'
   *  Logic: '<S1>/AND'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   */
  Sig_requestMotorBreak = ((MotorControlLib_B.TmpRTBAtANDInport1 && (rpmSoll ==
    0)) || (!MotorControlLib_B.TmpRTBAtANDInport1 && (qSoll == 0)));

  /* ModelReference: '<Root>/AngleCalculation' incorporates:
   *  Inport: '<Root>/Duty cycle input'
   *  Inport: '<Root>/Encoder input'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  ConvertPWMtoAngle(&Sig_requestMotorBreak, &AngleMec_1z, &rtb_AngleElec,
                    &Sig_MechanicalAngle);

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Inport: '<Root>/Inport1'
   */
  switch (set_AngleInput) {
   case 0:
    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  DiscreteIntegrator: '<S184>/Discrete-Time Integrator'
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
  rtb_Switch_i[0] = Sig_Ia_m;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' */
  rtb_Switch_i[1] = Sig_Ib_m;

  /* ModelReference: '<Root>/SafetyChecks' */
  SafetyChecks(&rtb_Switch_i[0],
               &(MotorControlLib_DW.SafetyChecks_InstanceData.rtdw));

  /* RateTransition: '<Root>/Rate Transition5' */
  rtb_RateTransition5 = MotorControlLib_DW.RateTransition5_Buffer0;

  /* RateTransition: '<Root>/Rate Transition6' */
  rtb_UnitDelay_n = MotorControlLib_DW.RateTransition6_Buffer0;

  /* Switch: '<S4>/Switch' */
  if (rtb_UnitDelay_n) {
    /* Switch: '<S4>/Switch' */
    Sig_Iq_Soll = rtb_RateTransition5;
  } else {
    /* Switch: '<S4>/Switch' incorporates:
     *  DataStoreRead: '<S4>/Data Store Read'
     *  Gain: '<S19>/Tq--> iqRef'
     */
    Sig_Iq_Soll = (real32_T)TqToIqConst * 0.00390625F * ((real32_T)qSoll *
      0.00390625F);
  }

  /* End of Switch: '<S4>/Switch' */

  /* Gain: '<S14>/convert_pu' */
  rtb_RateTransition5 = 0.159154937F * Sig_theta_el_m;

  /* If: '<S14>/If' incorporates:
   *  Constant: '<S15>/Constant'
   *  RelationalOperator: '<S15>/Compare'
   */
  if (rtb_RateTransition5 < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* Sum: '<S16>/Sum' incorporates:
     *  DataTypeConversion: '<S16>/Convert_back'
     *  DataTypeConversion: '<S16>/Convert_uint16'
     */
    rtb_b = rtb_RateTransition5 - (real32_T)(int16_T)floorf(rtb_RateTransition5);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* Sum: '<S17>/Sum' incorporates:
     *  DataTypeConversion: '<S17>/Convert_back'
     *  DataTypeConversion: '<S17>/Convert_uint16'
     */
    rtb_b = rtb_RateTransition5 - (real32_T)(int16_T)rtb_RateTransition5;

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem1' */
  }

  /* End of If: '<S14>/If' */

  /* Gain: '<S12>/indexing' */
  rtb_b *= 400.0F;

  /* DataTypeConversion: '<S12>/Get_Integer' */
  rtb_uDLookupTable_tmp_tmp = (uint16_T)rtb_b;

  /* Sum: '<S12>/Sum2' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion1'
   *  DataTypeConversion: '<S12>/Get_Integer'
   */
  rtb_b -= (real32_T)(uint16_T)rtb_b;

  /* Selector: '<S12>/Lookup' incorporates:
   *  Constant: '<S12>/offset'
   *  Constant: '<S12>/sine_table_values'
   *  DataTypeConversion: '<S12>/Get_Integer'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S13>/Sum5'
   */
  rtb_add_c = rtCP_sine_table_values_Value[(int32_T)(rtb_uDLookupTable_tmp_tmp +
    100U)];

  /* Sum: '<S13>/Sum6' incorporates:
   *  Constant: '<S12>/offset'
   *  Constant: '<S12>/sine_table_values'
   *  DataTypeConversion: '<S12>/Get_Integer'
   *  Product: '<S13>/Product1'
   *  Selector: '<S12>/Lookup'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S13>/Sum5'
   */
  Sig_cos_m = (rtCP_sine_table_values_Value[(int32_T)(rtb_uDLookupTable_tmp_tmp
    + 101U)] - rtb_add_c) * rtb_b + rtb_add_c;

  /* Gain: '<S192>/one_by_sqrt3' incorporates:
   *  Sum: '<S192>/a_plus_2b'
   */
  Sig_Ibeta_m = ((Sig_Ia_m + Sig_Ib_m) + Sig_Ib_m) * 0.577350259F;

  /* Selector: '<S12>/Lookup' incorporates:
   *  Constant: '<S12>/sine_table_values'
   *  DataTypeConversion: '<S12>/Get_Integer'
   */
  rtb_add_c = rtCP_sine_table_values_Value[rtb_uDLookupTable_tmp_tmp];

  /* Sum: '<S13>/Sum4' incorporates:
   *  Constant: '<S12>/offset'
   *  Constant: '<S12>/sine_table_values'
   *  DataTypeConversion: '<S12>/Get_Integer'
   *  Product: '<S13>/Product'
   *  Selector: '<S12>/Lookup'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S13>/Sum3'
   */
  Sig_sin_m = (rtCP_sine_table_values_Value[(int32_T)(rtb_uDLookupTable_tmp_tmp
    + 1U)] - rtb_add_c) * rtb_b + rtb_add_c;

  /* Switch: '<S194>/Switch' incorporates:
   *  Product: '<S193>/acos'
   *  Product: '<S193>/asin'
   *  Product: '<S193>/bcos'
   *  Product: '<S193>/bsin'
   *  Sum: '<S193>/sum_Ds'
   *  Sum: '<S193>/sum_Qs'
   *  Switch: '<S18>/Switch'
   */
  rtb_Switch_i[0] = Sig_Ia_m * Sig_cos_m + Sig_Ibeta_m * Sig_sin_m;
  rtb_Switch_i[1] = Sig_Ibeta_m * Sig_cos_m - Sig_Ia_m * Sig_sin_m;

  /* Gain: '<S9>/Gain2' */
  Sig_Id_axis_meas = rtb_Switch_i[0];

  /* Gain: '<S9>/Gain3' */
  Sig_Iq_axis_meas = rtb_Switch_i[1];

  /* Outputs for Atomic SubSystem: '<S6>/PI_Controller' */
  /* Sum: '<S73>/Add' incorporates:
   *  Constant: '<S6>/d Soll'
   */
  Sig_dAxis_errorSum_m = (real32_T)dSoll - Sig_Id_axis_meas;

  /* Sum: '<S73>/Add1' */
  Sig_qAxis_errorSum_m = Sig_Iq_Soll - Sig_Iq_axis_meas;

  /* DataTypeConversion: '<S73>/Data Type Conversion1' incorporates:
   *  Constant: '<S73>/Constant5'
   */
  Sig_IQ = (real32_T)Ki_qAxis * 0.00390625F;

  /* DataTypeConversion: '<S73>/Data Type Conversion2' incorporates:
   *  Constant: '<S73>/Constant4'
   */
  Sig_PQ = (real32_T)Kp_qAxis * 0.0009765625F; //todo 2^-10

  /* DataTypeConversion: '<S73>/Data Type Conversion3' incorporates:
   *  Constant: '<S73>/Constant6'
   */
  Sig_PD = (real32_T)Kp_dAxis * 0.0009765625F; //todo 2^-10

  /* DataTypeConversion: '<S73>/Data Type Conversion4' incorporates:
   *  Constant: '<S73>/Constant7'
   */
  Sig_ID = (real32_T)Ki_dAxis * 0.00390625F;

  /* Outputs for Enabled SubSystem: '<S76>/Subsystem' incorporates:
   *  EnablePort: '<S180>/Enable'
   */
  /* UnitDelay: '<S76>/Unit Delay' */
  if (MotorControlLib_DW.UnitDelay_DSTATE_o) {
    /* Sum: '<S180>/Add2' incorporates:
     *  Constant: '<S76>/Constant8'
     *  UnitDelay: '<S180>/Unit Delay'
     */
    MotorControlLib_B.Add2 = (uint16_T)(MotorControlLib_DW.UnitDelay_DSTATE + 1U);

    /* Update for UnitDelay: '<S180>/Unit Delay' */
    MotorControlLib_DW.UnitDelay_DSTATE = MotorControlLib_B.Add2;
  }

  /* End of UnitDelay: '<S76>/Unit Delay' */
  /* End of Outputs for SubSystem: '<S76>/Subsystem' */

  /* RelationalOperator: '<S179>/Compare' incorporates:
   *  Constant: '<S179>/Constant'
   */
  rtb_UnitDelay_n = (MotorControlLib_B.Add2 < 1500);

  /* Logic: '<S73>/OR' incorporates:
   *  Inport: '<Root>/Inport6'
   */
  rtb_UnitDelay1_b = (rtb_UnitDelay_n || resetPIIntegratorDQ);

  if (!Sig_requestMotorBreak) {
  /* Outputs for Atomic SubSystem: '<S73>/PI DAxis' */
  rtb_RateTransition5 =  (MotorControlLib_PIDAxis_m(Sig_dAxis_errorSum_m, Sig_PD,
    Sig_ID, rtb_UnitDelay1_b, 0.0F, &MotorControlLib_DW.PIDAxis_m));

  /* End of Outputs for SubSystem: '<S73>/PI DAxis' */

  /* Outputs for Atomic SubSystem: '<S73>/PI Qaxis' */
  rtb_Saturation = (-1.0F)*(MotorControlLib_PIDAxis_m(Sig_qAxis_errorSum_m, Sig_PQ,
    Sig_IQ, rtb_UnitDelay1_b, 0.0F, &MotorControlLib_DW.PIQaxis));

  }
  else {
	  rtb_Saturation=0.0f;
	  rtb_RateTransition5=0.0f;
  }
  /* End of Outputs for SubSystem: '<S73>/PI Qaxis' */

  /* Update for UnitDelay: '<S76>/Unit Delay' */
  MotorControlLib_DW.UnitDelay_DSTATE_o = rtb_UnitDelay_n;

  /* End of Outputs for SubSystem: '<S6>/PI_Controller' */

  /* Outputs for Atomic SubSystem: '<S6>/DQ_Limiter' */
  MotorControlLib_DQ_Limiter(rtb_RateTransition5, rtb_Saturation, rtb_Switch_i,
    &rtb_b, d_q_Voltage_Limiter_max);

  /* End of Outputs for SubSystem: '<S6>/DQ_Limiter' */

  /* SignalConversion generated from: '<S6>/DQ_Limiter' */
  Sig_Vqsatu_m = rtb_Switch_i[1];

  /* SignalConversion generated from: '<S6>/DQ_Limiter' */
  Sig_Vdsatu_m = rtb_Switch_i[0];

  /* Gain: '<Root>/Gain' incorporates:
   *  Product: '<S3>/dcos'
   *  Product: '<S3>/qsin'
   *  Sum: '<S3>/sum_alpha'
   */
  Sig_Va_m = Sig_Vdsatu_m * Sig_cos_m - Sig_Vqsatu_m * Sig_sin_m;

  /* Gain: '<Root>/Gain1' incorporates:
   *  Product: '<S3>/dsin'
   *  Product: '<S3>/qcos'
   *  Sum: '<S3>/sum_beta'
   */
  Sig_Vb_m = Sig_Vqsatu_m * Sig_cos_m + Sig_Vdsatu_m * Sig_sin_m;

  /* Outputs for Atomic SubSystem: '<S7>/Inverse Clarke Transform' */
  /* Gain: '<S181>/one_by_two' incorporates:
   *  SignalConversion generated from: '<S181>/In1'
   */
  rtb_RateTransition5 = 0.5F * Sig_Va_m;

  /* Gain: '<S181>/sqrt3_by_two' */
  rtb_b = 0.866025388F * Sig_Vb_m;

  /* Sum: '<S181>/add_b' */
  rtb_Saturation = rtb_b - rtb_RateTransition5;

  /* Sum: '<S181>/add_c' */
  rtb_add_c = (0.0F - rtb_RateTransition5) - rtb_b;

  /* End of Outputs for SubSystem: '<S7>/Inverse Clarke Transform' */

  /* Outputs for Atomic SubSystem: '<S7>/Space Vector Generator' */
  /* Gain: '<S182>/one_by_sqrt3' */
  rtb_c = 0.577350259F * Sig_Va_m;

  /* Sum: '<S182>/a' */
  rtb_a = rtb_c + rtb_c;

  /* Sum: '<S182>/b' */
  rtb_b = Sig_Vb_m - rtb_c;

  /* Sum: '<S182>/c' */
  rtb_c = (0.0F - rtb_c) - Sig_Vb_m;

  /* Gain: '<S182>/one_by_two' incorporates:
   *  MinMax: '<S182>/Max'
   *  MinMax: '<S182>/Min'
   *  Sum: '<S182>/Add'
   */
  rtb_RateTransition5 = (fmaxf(fmaxf(rtb_a, rtb_b), rtb_c) + fminf(fminf(rtb_a,
    rtb_b), rtb_c)) * 0.5F;

  /* End of Outputs for SubSystem: '<S7>/Space Vector Generator' */

  /* Switch: '<S7>/Switch' incorporates:
   *  Inport: '<Root>/In1'
   *  Switch: '<S7>/Switch1'
   *  Switch: '<S7>/Switch2'
   */
  if (Sig_change_SVMalgorithm) {
    /* Outputs for Atomic SubSystem: '<S7>/Inverse Clarke Transform' */
    /* Switch: '<S7>/Switch' incorporates:
     *  SignalConversion generated from: '<S181>/In1'
     */
    Sig_Valpha_m = Sig_Va_m;

    /* End of Outputs for SubSystem: '<S7>/Inverse Clarke Transform' */

    /* Switch: '<S7>/Switch1' */
    Sig_Vbeta_m = rtb_Saturation;

    /* Switch: '<S7>/Switch2' */
    Sig_Vgamma_m = rtb_add_c;
  } else {
    /* Outputs for Atomic SubSystem: '<S7>/Space Vector Generator' */
    /* Switch: '<S7>/Switch' incorporates:
     *  Sum: '<S182>/Da'
     */
    Sig_Valpha_m = rtb_a - rtb_RateTransition5;

    /* Switch: '<S7>/Switch1' incorporates:
     *  Sum: '<S182>/Db'
     */
    Sig_Vbeta_m = rtb_b - rtb_RateTransition5;

    /* Switch: '<S7>/Switch2' incorporates:
     *  Sum: '<S182>/Dc'
     */
    Sig_Vgamma_m = rtb_c - rtb_RateTransition5;

    /* End of Outputs for SubSystem: '<S7>/Space Vector Generator' */
  }

  /* End of Switch: '<S7>/Switch' */

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Lookup_n-D: '<S7>/1-D Lookup Table'
   *  Switch: '<S7>/Switch'
   */
  set_PWM_A_DT(look1_iflftu16Df_binlcm(Sig_Valpha_m, &BrkPoints[0],
    &pwmTableData[0], 2U));

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Lookup_n-D: '<S7>/1-D Lookup Table1'
   *  Switch: '<S7>/Switch1'
   */
  set_PWM_B_DT(look1_iflftu16Df_binlcm(Sig_Vbeta_m, &BrkPoints[0],
    &pwmTableData[0], 2U));

  /* DataTypeConversion: '<S7>/Data Type Conversion2' incorporates:
   *  Lookup_n-D: '<S7>/1-D Lookup Table2'
   *  Switch: '<S7>/Switch2'
   */
  set_PWM_C_DT(look1_iflftu16Df_binlcm(Sig_Vgamma_m, &BrkPoints[0],
    &pwmTableData[0], 2U));

  /* DiscreteIntegrator: '<Root>/Integrator of Angle' */
  Sig_angle_speed = lowPassFilter((float)(Sig_MechanicalAngle - AngleMec_1z)/(0.0002F),Sig_angle_speed);

//MotorControlLib_DW.IntegratorofAngle_DSTATE;
  Sig_Rpm_measurment = 9.54929638F * Sig_angle_speed;
  /* Update for UnitDelay: '<Root>/Unit Delay' */
  AngleMec_1z = Sig_MechanicalAngle;

  /* Update for DiscreteIntegrator: '<Root>/Integrator of Angle' */
  MotorControlLib_DW.IntegratorofAngle_DSTATE +=  0.0002F * Sig_MechanicalAngle;
}

/* Model step function for TID2 */
void MotorControlLib_step2(void)       /* Sample time: [0.01s, 0.0s] */
{
  real32_T rtb_RateTransition1;
  boolean_T rtb_RateTransition4;

  /* RateTransition: '<Root>/Rate Transition1' */
  rtb_RateTransition1 = Sig_angle_speed;

  /* RateTransition: '<Root>/Rate Transition4' incorporates:
   *  Inport: '<Root>/Inport6'
   */
  rtb_RateTransition4 = resetPIIntegratorDQ;

  /* Outputs for Enabled SubSystem: '<Root>/PI controller RPM' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  /* Inport: '<Root>/Inport8' */
  if (activateRPMCntlr) {
    /* UnitConversion: '<S5>/Unit Conversion' */
    /* Unit Conversion - from: rad/sec to: rpm
       Expression: output = (9.5493*input) + (0) */
    Sig_Rpm_measurment = 9.54929638F * rtb_RateTransition1;

    /* DataTypeConversion: '<S5>/Data Type Conversion3' incorporates:
     *  Constant: '<S5>/Constant6'
     */
    Sig_PRPM = (real32_T)Kp_Rpm * 0.00048828125F;

    /* DataTypeConversion: '<S5>/Data Type Conversion4' incorporates:
     *  Constant: '<S5>/Constant7'
     */
    Sig_IRPM = (real32_T)Ki_Rpm * 0.00048828125F;

    /* Outputs for Atomic SubSystem: '<S5>/PI DAxis' */
    /* Sum: '<S5>/Add' incorporates:
     *  DataStoreRead: '<S5>/Data Store Read1'
     */
    MotorControlLib_PIDAxis((real32_T)rpmSoll - Sig_Rpm_measurment, Sig_PRPM,
      Sig_IRPM, rtb_RateTransition4, 0.0F, &MotorControlLib_B.Saturation,
      &MotorControlLib_DW.PIDAxis);

    /* End of Outputs for SubSystem: '<S5>/PI DAxis' */
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

  /* SystemInitialize for Enabled SubSystem: '<Root>/PI controller RPM' */
  /* SystemInitialize for Atomic SubSystem: '<S5>/PI DAxis' */
  MotorControlLi_PIDAxis_Init(&MotorControlLib_DW.PIDAxis);

  /* End of SystemInitialize for SubSystem: '<S5>/PI DAxis' */
  /* End of SystemInitialize for SubSystem: '<Root>/PI controller RPM' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/PI_Controller' */
  /* SystemInitialize for Atomic SubSystem: '<S73>/PI DAxis' */
  MotorControl_PIDAxis_c_Init(&MotorControlLib_DW.PIDAxis_m);

  /* End of SystemInitialize for SubSystem: '<S73>/PI DAxis' */

  /* SystemInitialize for Atomic SubSystem: '<S73>/PI Qaxis' */
  MotorControl_PIDAxis_c_Init(&MotorControlLib_DW.PIQaxis);

  /* End of SystemInitialize for SubSystem: '<S73>/PI Qaxis' */
  /* End of SystemInitialize for SubSystem: '<S6>/PI_Controller' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Start up' */
  /* InitializeConditions for DiscreteIntegrator: '<S184>/Discrete-Time Integrator' */
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
