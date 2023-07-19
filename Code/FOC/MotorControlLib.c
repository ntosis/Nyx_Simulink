/*
 * File: MotorControlLib.c
 *
 * Code generated for Simulink model 'MotorControlLib'.
 *
 * Model version                  : 3.80
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jul 11 16:23:53 2023
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

const int16_T MotorControlLib_sfix16_En8_GND = 0;/* int16_T ground */

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
real32_T Sig_Iq_Soll;                  /* '<S9>/Switch' */
real32_T Sig_cos_m;                    /* '<S13>/Sum6' */
real32_T Sig_Ibeta_m;                  /* '<S139>/one_by_sqrt3' */
real32_T Sig_sin_m;                    /* '<S13>/Sum4' */
real32_T Sig_Id_axis_meas;             /* '<S7>/Gain2' */
real32_T Sig_Iq_axis_meas;             /* '<S7>/Gain3' */
real32_T Sig_Vqsatu_m;                 /* '<S4>/DQ_Limiter' */
real32_T Sig_Vdsatu_m;                 /* '<S4>/DQ_Limiter' */
real32_T Sig_Va_m;                     /* '<Root>/Gain' */
real32_T Sig_Vb_m;                     /* '<Root>/Gain1' */
real32_T Sig_Valpha_m;                 /* '<S5>/Switch' */
real32_T Sig_Vbeta_m;                  /* '<S5>/Switch1' */
real32_T Sig_Vgamma_m;                 /* '<S5>/Switch2' */
real32_T Sig_angle_speed;              /* '<Root>/Integrator of Angle' */
real32_T Sig_Rpm_measurment;           /* '<S8>/Unit Conversion' */
real32_T Sig_PRPM;                     /* '<S8>/Data Type Conversion3' */
real32_T Sig_IRPM;                     /* '<S8>/Data Type Conversion4' */
real32_T Sig_dAxis_errorSum_m;         /* '<S20>/Add' */
real32_T Sig_qAxis_errorSum_m;         /* '<S20>/Add1' */
real32_T Sig_IQ;                       /* '<S20>/Data Type Conversion1' */
real32_T Sig_PQ;                       /* '<S20>/Data Type Conversion2' */
real32_T Sig_PD;                       /* '<S20>/Data Type Conversion3' */
real32_T Sig_ID;                       /* '<S20>/Data Type Conversion4' */
real32_T Sig_dAxis_PI_out;             /* '<S20>/PI DAxis' */
real32_T Sig_qAxis_PI_out;             /* '<S20>/PI Qaxis' */
int16_T constantAngle;                 /* '<S131>/Discrete-Time Integrator' */
boolean_T Sig_requestMotorBreak;       /* '<S1>/OR' */

/* Exported block parameters */
int16_T d_q_Voltage_Limiter_max = 92;  /* Variable: d_q_Voltage_Limiter_max
                                        * Referenced by: '<S4>/DQ_Limiter'
                                        * =Vnom/sqrt(3)
                                        */
int16_T d_q_Voltage_Limiter_sat_neg = -160;/* Variable: d_q_Voltage_Limiter_sat_neg
                                            * Referenced by:
                                            *   '<S184>/Saturation'
                                            *   '<S65>/Saturation'
                                            *   '<S116>/Saturation'
                                            *   '<S170>/DeadZone'
                                            *   '<S51>/DeadZone'
                                            *   '<S102>/DeadZone'
                                            * fixdt(1,16,2^-4,0)
                                            */
int16_T d_q_Voltage_Limiter_sat_pos = 160;/* Variable: d_q_Voltage_Limiter_sat_pos
                                           * Referenced by:
                                           *   '<S184>/Saturation'
                                           *   '<S65>/Saturation'
                                           *   '<S116>/Saturation'
                                           *   '<S170>/DeadZone'
                                           *   '<S51>/DeadZone'
                                           *   '<S102>/DeadZone'
                                           * fixdt(1,16,2^-4,0)
                                           */
uint16_T Ki_Rpm = 20480U;              /* Variable: Ki_Rpm
                                        * Referenced by: '<S8>/Constant7'
                                        * fixdt(0,16,2^-11,0)
                                        */
uint16_T Kp_Rpm = 299U;                /* Variable: Kp_Rpm
                                        * Referenced by: '<S8>/Constant6'
                                        * fixdt(0,16,2^-11,0)
                                        */
uint16_T Ki_dAxis = 46080U;            /* Variable: Ki_dAxis
                                        * Referenced by: '<S20>/Constant7'
                                        * fixdt(0,16,2^-8,0)
                                        */
uint16_T Ki_qAxis = 44800U;            /* Variable: Ki_qAxis
                                        * Referenced by: '<S20>/Constant5'
                                        * fixdt(0,16,2^-8,0)
                                        */
uint16_T Kp_dAxis = 37U;               /* Variable: Kp_dAxis
                                        * Referenced by: '<S20>/Constant6'
                                        * fixdt(0,16,2^-8,0)
                                        */
uint16_T Kp_qAxis = 37U;               /* Variable: Kp_qAxis
                                        * Referenced by: '<S20>/Constant4'
                                        * fixdt(0,16,2^-8,0)
                                        */
uint16_T MaximumCurrentBeforeReaction = 4864U;/* Variable: MaximumCurrentBeforeReaction
                                               * Referenced by: '<Root>/SafetyChecks'
                                               * Maximum current limit before software shutdowns the mosfets.
                                               */

/* Exported block states */
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

/* Output and update for atomic system: '<S4>/DQ_Limiter' */
void MotorControlLib_DQ_Limiter(real32_T rtu_Vd_ref, real32_T rtu_Vq_ref,
  real32_T rty_Vd_sat[2], real32_T *rty_Vmax_unsat, int16_T rtp_Vmax)
{
  real32_T rtb_Gain;

  /* Sum: '<S19>/Sum2' incorporates:
   *  Product: '<S19>/Product'
   *  Product: '<S19>/Product1'
   */
  *rty_Vmax_unsat = rtu_Vd_ref * rtu_Vd_ref + rtu_Vq_ref * rtu_Vq_ref;

  /* Sqrt: '<S19>/Sqrt' */
  *rty_Vmax_unsat = sqrtf(*rty_Vmax_unsat);

  /* Switch: '<S19>/Switch' incorporates:
   *  Gain: '<S19>/Gain'
   *  Math: '<S19>/Math Function2'
   *  Product: '<S19>/Product2'
   *
   * About '<S19>/Math Function2':
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

  /* End of Switch: '<S19>/Switch' */
}

/*
 * System initialize for atomic system:
 *    '<S20>/PI DAxis'
 *    '<S20>/PI Qaxis'
 */
void MotorControlLi_PIDAxis_Init(DW_PIDAxis_MotorControlLib_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S58>/Integrator' */
  localDW->Integrator_IC_LOADING = 1U;
}

/*
 * Output and update for atomic system:
 *    '<S20>/PI DAxis'
 *    '<S20>/PI Qaxis'
 */
real32_T MotorControlLib_PIDAxis(real32_T rtu_error, real32_T rtu_P, real32_T
  rtu_I, boolean_T rtu_Reset, real32_T rtu_init, DW_PIDAxis_MotorControlLib_T
  *localDW)
{
  real32_T rty_PIDOut_0;
  real32_T rtb_IProdOut;
  real32_T u1;
  real32_T u2;
  int8_T rtb_Switch1;
  int8_T tmp;
  boolean_T rtb_RelationalOperator_o;

  /* DiscreteIntegrator: '<S58>/Integrator' */
  if (localDW->Integrator_IC_LOADING != 0) {
    localDW->Integrator_DSTATE = rtu_init;
  }

  if (rtu_Reset || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = rtu_init;
  }

  /* Sum: '<S67>/Sum' incorporates:
   *  DiscreteIntegrator: '<S58>/Integrator'
   *  Product: '<S63>/PProd Out'
   */
  rty_PIDOut_0 = rtu_error * rtu_P + localDW->Integrator_DSTATE;

  /* DeadZone: '<S51>/DeadZone' incorporates:
   *  Saturate: '<S65>/Saturation'
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

  /* End of DeadZone: '<S51>/DeadZone' */

  /* RelationalOperator: '<S49>/Relational Operator' incorporates:
   *  Constant: '<S49>/Clamping_zero'
   */
  rtb_RelationalOperator_o = (rtb_IProdOut != 0.0F);

  /* Switch: '<S49>/Switch1' incorporates:
   *  Constant: '<S49>/Clamping_zero'
   *  Constant: '<S49>/Constant'
   *  Constant: '<S49>/Constant2'
   *  RelationalOperator: '<S49>/fix for DT propagation issue'
   */
  if (rtb_IProdOut > 0.0F) {
    rtb_Switch1 = 1;
  } else {
    rtb_Switch1 = -1;
  }

  /* End of Switch: '<S49>/Switch1' */

  /* Product: '<S55>/IProd Out' */
  rtb_IProdOut = rtu_error * rtu_I;

  /* Saturate: '<S65>/Saturation' */
  u1 = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
  if (rty_PIDOut_0 > u2) {
    rty_PIDOut_0 = u2;
  } else if (rty_PIDOut_0 < u1) {
    rty_PIDOut_0 = u1;
  }

  /* Update for DiscreteIntegrator: '<S58>/Integrator' */
  localDW->Integrator_IC_LOADING = 0U;

  /* Switch: '<S49>/Switch2' incorporates:
   *  Constant: '<S49>/Clamping_zero'
   *  Constant: '<S49>/Constant3'
   *  Constant: '<S49>/Constant4'
   *  RelationalOperator: '<S49>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S49>/Switch' incorporates:
   *  Constant: '<S49>/Constant1'
   *  Logic: '<S49>/AND3'
   *  RelationalOperator: '<S49>/Equal1'
   *  Switch: '<S49>/Switch2'
   */
  if (rtb_RelationalOperator_o && (rtb_Switch1 == tmp)) {
    rtb_IProdOut = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S58>/Integrator' incorporates:
   *  Switch: '<S49>/Switch'
   */
  localDW->Integrator_DSTATE += 0.0002F * rtb_IProdOut;
  localDW->Integrator_PrevResetState = (int8_T)rtu_Reset;
  return rty_PIDOut_0;
}

/* System initialize for atomic system: '<S8>/PI DAxis' */
void MotorControl_PIDAxis_l_Init(DW_PIDAxis_MotorControlLib_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S177>/Integrator' */
  localDW->Integrator_IC_LOADING = 1U;
}

/* Output and update for atomic system: '<S8>/PI DAxis' */
void MotorControlLib_PIDAxis_h(real32_T rtu_error, real32_T rtu_P, real32_T
  rtu_I, boolean_T rtu_Reset, real32_T rtu_init, real32_T *rty_PIDOut,
  DW_PIDAxis_MotorControlLib_l_T *localDW)
{
  real32_T rtb_IProdOut;
  real32_T rtb_Sum_g;
  real32_T u1;
  real32_T u2;
  int8_T rtb_Switch1;
  int8_T tmp;
  boolean_T rtb_RelationalOperator_d;

  /* DiscreteIntegrator: '<S177>/Integrator' */
  if (localDW->Integrator_IC_LOADING != 0) {
    localDW->Integrator_DSTATE = rtu_init;
  }

  if (rtu_Reset || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = rtu_init;
  }

  /* Sum: '<S186>/Sum' incorporates:
   *  DiscreteIntegrator: '<S177>/Integrator'
   *  Product: '<S182>/PProd Out'
   */
  rtb_Sum_g = rtu_error * rtu_P + localDW->Integrator_DSTATE;

  /* DeadZone: '<S170>/DeadZone' incorporates:
   *  Saturate: '<S184>/Saturation'
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

  /* End of DeadZone: '<S170>/DeadZone' */

  /* RelationalOperator: '<S168>/Relational Operator' incorporates:
   *  Constant: '<S168>/Clamping_zero'
   */
  rtb_RelationalOperator_d = (rtb_IProdOut != 0.0F);

  /* Switch: '<S168>/Switch1' incorporates:
   *  Constant: '<S168>/Clamping_zero'
   *  Constant: '<S168>/Constant'
   *  Constant: '<S168>/Constant2'
   *  RelationalOperator: '<S168>/fix for DT propagation issue'
   */
  if (rtb_IProdOut > 0.0F) {
    rtb_Switch1 = 1;
  } else {
    rtb_Switch1 = -1;
  }

  /* End of Switch: '<S168>/Switch1' */

  /* Product: '<S174>/IProd Out' */
  rtb_IProdOut = rtu_error * rtu_I;

  /* Saturate: '<S184>/Saturation' */
  u1 = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
  if (rtb_Sum_g > u2) {
    *rty_PIDOut = u2;
  } else if (rtb_Sum_g < u1) {
    *rty_PIDOut = u1;
  } else {
    *rty_PIDOut = rtb_Sum_g;
  }

  /* Update for DiscreteIntegrator: '<S177>/Integrator' */
  localDW->Integrator_IC_LOADING = 0U;

  /* Switch: '<S168>/Switch2' incorporates:
   *  Constant: '<S168>/Clamping_zero'
   *  Constant: '<S168>/Constant3'
   *  Constant: '<S168>/Constant4'
   *  RelationalOperator: '<S168>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S168>/Switch' incorporates:
   *  Constant: '<S168>/Constant1'
   *  Logic: '<S168>/AND3'
   *  RelationalOperator: '<S168>/Equal1'
   *  Switch: '<S168>/Switch2'
   */
  if (rtb_RelationalOperator_d && (rtb_Switch1 == tmp)) {
    rtb_IProdOut = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S177>/Integrator' incorporates:
   *  Switch: '<S168>/Switch'
   */
  localDW->Integrator_DSTATE += 0.01F * rtb_IProdOut;
  localDW->Integrator_PrevResetState = (int8_T)rtu_Reset;
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
  real32_T rtb_AngleCalculation_o1;
  real32_T rtb_Switch_i[2];
  real32_T UnitDelay_DSTATE;
  real32_T rtb_RateTransition5;
  real32_T rtb_a;
  real32_T rtb_add_b;
  real32_T rtb_add_c;
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
  /* UnitDelay: '<S131>/Unit Delay' */
  rtb_UnitDelay_n = MotorControlLib_DW.UnitDelay_DSTATE_pf;

  /* DiscreteIntegrator: '<S131>/Discrete-Time Integrator' incorporates:
   *  UnitDelay: '<S131>/Unit Delay'
   */
  if (MotorControlLib_DW.UnitDelay_DSTATE_pf &&
      (MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE = 0;
  }

  /* DiscreteIntegrator: '<S131>/Discrete-Time Integrator' */
  constantAngle = MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE;

  /* UnitDelay: '<S130>/Unit Delay1' */
  rtb_UnitDelay1_b = MotorControlLib_DW.UnitDelay1_DSTATE_m;

  /* CombinatorialLogic: '<S136>/Logic' incorporates:
   *  Memory: '<S136>/Memory'
   *  UnitDelay: '<S130>/Unit Delay'
   */
  rtb_Logic_idx_0 = rtCP_Logic_table[((int32_T)
    (((MotorControlLib_DW.UnitDelay_DSTATE_e + 2U) << 1) +
     MotorControlLib_DW.Memory_PreviousInput) % 8) << 1];

  /* Outputs for Enabled SubSystem: '<S130>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S134>/Enable'
   */
  if (rtb_Logic_idx_0) {
    /* RelationalOperator: '<S138>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S138>/Delay Input1'
     *
     * Block description for '<S138>/Delay Input1':
     *
     *  Store in Global RAM
     */
    MotorControlLib_B.FixPtRelationalOperator =
      (MotorControlLib_DW.DelayInput1_DSTATE != 0);

    /* Update for UnitDelay: '<S138>/Delay Input1'
     *
     * Block description for '<S138>/Delay Input1':
     *
     *  Store in Global RAM
     */
    MotorControlLib_DW.DelayInput1_DSTATE = 0;
  }

  /* End of Outputs for SubSystem: '<S130>/Enabled Subsystem' */

  /* CombinatorialLogic: '<S137>/Logic' incorporates:
   *  Memory: '<S137>/Memory'
   *  RelationalOperator: '<S133>/FixPt Relational Operator'
   *  UnitDelay: '<S133>/Delay Input1'
   *
   * Block description for '<S133>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Logic_c_idx_0 = rtCP_Logic_table_m[((int32_T)(((((uint32_T)
    MotorControlLib_B.FixPtRelationalOperator << 1) + (uint32_T)((int32_T)
    rtb_UnitDelay1_b < (int32_T)MotorControlLib_DW.DelayInput1_DSTATE_f)) << 1)
    + MotorControlLib_DW.Memory_PreviousInput_b) % 8) << 1];

  /* Outputs for Enabled SubSystem: '<S130>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S135>/Enable'
   */
  if (rtb_Logic_c_idx_0) {
    /* RelationalOperator: '<S135>/Relational Operator' incorporates:
     *  Constant: '<S135>/Constant1'
     *  UnitDelay: '<S135>/Unit Delay1'
     */
    MotorControlLib_B.RelationalOperator = (MotorControlLib_DW.UnitDelay1_DSTATE
      <= 10000);

    /* Update for UnitDelay: '<S135>/Unit Delay1' incorporates:
     *  Constant: '<S135>/Constant'
     *  Sum: '<S135>/Add'
     */
    MotorControlLib_DW.UnitDelay1_DSTATE++;
  }

  /* End of Outputs for SubSystem: '<S130>/Enabled Subsystem1' */

  /* Abs: '<S131>/Abs' incorporates:
   *  DiscreteIntegrator: '<S131>/Discrete-Time Integrator'
   */
  if (constantAngle < 0) {
    tmp = (int16_T)-constantAngle;
  } else {
    tmp = constantAngle;
  }

  /* Update for UnitDelay: '<S131>/Unit Delay' incorporates:
   *  Abs: '<S131>/Abs'
   *  RelationalOperator: '<S131>/Relational Operator'
   */
  MotorControlLib_DW.UnitDelay_DSTATE_pf = (tmp >= 1608);

  /* Update for DiscreteIntegrator: '<S131>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/Inport4'
   */
  MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE = (int16_T)(((6711 * dth_dt) >>
    17) + MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE);
  MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_UnitDelay_n;

  /* Update for UnitDelay: '<S133>/Delay Input1'
   *
   * Block description for '<S133>/Delay Input1':
   *
   *  Store in Global RAM
   */
  MotorControlLib_DW.DelayInput1_DSTATE_f = rtb_UnitDelay1_b;

  /* Update for UnitDelay: '<S130>/Unit Delay1' */
  MotorControlLib_DW.UnitDelay1_DSTATE_m = MotorControlLib_B.RelationalOperator;

  /* Update for UnitDelay: '<S130>/Unit Delay' */
  MotorControlLib_DW.UnitDelay_DSTATE_e = rtb_Logic_c_idx_0;

  /* Update for Memory: '<S136>/Memory' */
  MotorControlLib_DW.Memory_PreviousInput = rtb_Logic_idx_0;

  /* Update for Memory: '<S137>/Memory' */
  MotorControlLib_DW.Memory_PreviousInput_b = rtb_Logic_c_idx_0;

  /* End of Outputs for SubSystem: '<Root>/Start up' */

  /* ModelReference: '<Root>/AngleCalculation' incorporates:
   *  Inport: '<Root>/Input'
   *  Inport: '<Root>/Input1'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  ConvertPWMtoAngle(((const int16_T*) &MotorControlLib_sfix16_En8_GND),
                    &UnitDelay_DSTATE, &rtb_AngleCalculation_o1,
                    &Sig_MechanicalAngle);

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Inport: '<Root>/Inport1'
   */
  switch (set_AngleInput) {
   case 0:
    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  DiscreteIntegrator: '<S131>/Discrete-Time Integrator'
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
    Sig_theta_el_m = rtb_AngleCalculation_o1;
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

  /* RateTransition generated from: '<S9>/Switch' */
  if (MotorControlLib_M->Timing.RateInteraction.TID1_2 == 1) {
    /* RateTransition generated from: '<S9>/Switch' */
    MotorControlLib_B.TmpRTBAtSwitchInport2 =
      MotorControlLib_DW.TmpRTBAtSwitchInport2_Buffer0;
  }

  /* End of RateTransition generated from: '<S9>/Switch' */

  /* Switch: '<S9>/Switch' */
  if (MotorControlLib_B.TmpRTBAtSwitchInport2) {
    /* Switch: '<S9>/Switch' */
    Sig_Iq_Soll = rtb_RateTransition5;
  } else {
    /* Switch: '<S9>/Switch' incorporates:
     *  DataStoreRead: '<S9>/Data Store Read'
     *  Gain: '<S194>/Tq--> iqRef'
     */
    Sig_Iq_Soll = (real32_T)TqToIqConst * 0.00390625F * ((real32_T)qSoll *
      0.00390625F);
  }

  /* End of Switch: '<S9>/Switch' */

  /* Gain: '<S14>/convert_pu' */
  rtb_RateTransition5 = 0.159154937F * Sig_theta_el_m;

  /* If: '<S14>/If' incorporates:
   *  Constant: '<S15>/Constant'
   *  DataTypeConversion: '<S16>/Convert_back'
   *  DataTypeConversion: '<S16>/Convert_uint16'
   *  DataTypeConversion: '<S17>/Convert_back'
   *  DataTypeConversion: '<S17>/Convert_uint16'
   *  Gain: '<S12>/indexing'
   *  RelationalOperator: '<S15>/Compare'
   *  Sum: '<S16>/Sum'
   *  Sum: '<S17>/Sum'
   */
  if (rtb_RateTransition5 < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    UnitDelay_DSTATE = rtb_RateTransition5 - (real32_T)(int16_T)floorf
      (rtb_RateTransition5);

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S14>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    UnitDelay_DSTATE = rtb_RateTransition5 - (real32_T)(int16_T)
      rtb_RateTransition5;

    /* End of Outputs for SubSystem: '<S14>/If Action Subsystem1' */
  }

  UnitDelay_DSTATE *= 400.0F;

  /* End of If: '<S14>/If' */

  /* DataTypeConversion: '<S12>/Get_Integer' */
  rtb_uDLookupTable_tmp_tmp = (uint16_T)UnitDelay_DSTATE;

  /* Sum: '<S12>/Sum2' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion1'
   *  DataTypeConversion: '<S12>/Get_Integer'
   */
  UnitDelay_DSTATE -= (real32_T)(uint16_T)UnitDelay_DSTATE;

  /* Selector: '<S12>/Lookup' incorporates:
   *  Constant: '<S12>/offset'
   *  Constant: '<S12>/sine_table_values'
   *  DataTypeConversion: '<S12>/Get_Integer'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S13>/Sum5'
   */
  rtb_RateTransition5 = rtCP_sine_table_values_Value[(int32_T)
    (rtb_uDLookupTable_tmp_tmp + 100U)];

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
    + 101U)] - rtb_RateTransition5) * UnitDelay_DSTATE + rtb_RateTransition5;

  /* Gain: '<S139>/one_by_sqrt3' incorporates:
   *  Sum: '<S139>/a_plus_2b'
   */
  Sig_Ibeta_m = ((Sig_Ia_m + Sig_Ib_m) + Sig_Ib_m) * 0.577350259F;

  /* Selector: '<S12>/Lookup' incorporates:
   *  Constant: '<S12>/sine_table_values'
   *  DataTypeConversion: '<S12>/Get_Integer'
   */
  rtb_RateTransition5 = rtCP_sine_table_values_Value[rtb_uDLookupTable_tmp_tmp];

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
    + 1U)] - rtb_RateTransition5) * UnitDelay_DSTATE + rtb_RateTransition5;

  /* Switch: '<S141>/Switch' incorporates:
   *  Product: '<S140>/acos'
   *  Product: '<S140>/asin'
   *  Product: '<S140>/bcos'
   *  Product: '<S140>/bsin'
   *  Sum: '<S140>/sum_Ds'
   *  Sum: '<S140>/sum_Qs'
   *  Switch: '<S18>/Switch'
   */
  rtb_Switch_i[0] = Sig_Ia_m * Sig_cos_m + Sig_Ibeta_m * Sig_sin_m;
  rtb_Switch_i[1] = Sig_Ibeta_m * Sig_cos_m - Sig_Ia_m * Sig_sin_m;

  /* Gain: '<S7>/Gain2' */
  Sig_Id_axis_meas = rtb_Switch_i[0];

  /* Gain: '<S7>/Gain3' */
  Sig_Iq_axis_meas = rtb_Switch_i[1];

  /* Outputs for Atomic SubSystem: '<S4>/PI_Controller' */
  /* Sum: '<S20>/Add' incorporates:
   *  Constant: '<S4>/d Soll'
   */
  Sig_dAxis_errorSum_m = (real32_T)dSoll - Sig_Id_axis_meas;

  /* Sum: '<S20>/Add1' */
  Sig_qAxis_errorSum_m = Sig_Iq_Soll - Sig_Iq_axis_meas;

  /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
   *  Constant: '<S20>/Constant5'
   */
  Sig_IQ = (real32_T)Ki_qAxis * 0.00390625F;

  /* DataTypeConversion: '<S20>/Data Type Conversion2' incorporates:
   *  Constant: '<S20>/Constant4'
   */
  Sig_PQ = (real32_T)Kp_qAxis * 0.00390625F;

  /* DataTypeConversion: '<S20>/Data Type Conversion3' incorporates:
   *  Constant: '<S20>/Constant6'
   */
  Sig_PD = (real32_T)Kp_dAxis * 0.00390625F;

  /* DataTypeConversion: '<S20>/Data Type Conversion4' incorporates:
   *  Constant: '<S20>/Constant7'
   */
  Sig_ID = (real32_T)Ki_dAxis * 0.00390625F;

  /* Outputs for Enabled SubSystem: '<S23>/Subsystem' incorporates:
   *  EnablePort: '<S127>/Enable'
   */
  /* UnitDelay: '<S23>/Unit Delay' */
  if (MotorControlLib_DW.UnitDelay_DSTATE_o) {
    /* Sum: '<S127>/Add2' incorporates:
     *  Constant: '<S23>/Constant8'
     *  UnitDelay: '<S127>/Unit Delay'
     */
    MotorControlLib_B.Add2 = (uint16_T)(MotorControlLib_DW.UnitDelay_DSTATE_p +
      1U);

    /* Update for UnitDelay: '<S127>/Unit Delay' */
    MotorControlLib_DW.UnitDelay_DSTATE_p = MotorControlLib_B.Add2;
  }

  /* End of UnitDelay: '<S23>/Unit Delay' */
  /* End of Outputs for SubSystem: '<S23>/Subsystem' */

  /* RelationalOperator: '<S126>/Compare' incorporates:
   *  Constant: '<S126>/Constant'
   */
  rtb_UnitDelay_n = (MotorControlLib_B.Add2 < 1500);

  /* Logic: '<S20>/OR' incorporates:
   *  Inport: '<Root>/Inport6'
   */
  rtb_UnitDelay1_b = (rtb_UnitDelay_n || resetPIIntegratorDQ);

  /* Outputs for Atomic SubSystem: '<S20>/PI DAxis' */
  /* SignalConversion generated from: '<S20>/PI DAxis' */
  Sig_dAxis_PI_out = MotorControlLib_PIDAxis(Sig_dAxis_errorSum_m, Sig_PD,
    Sig_ID, rtb_UnitDelay1_b, 0.0F, &MotorControlLib_DW.PIDAxis);

  /* End of Outputs for SubSystem: '<S20>/PI DAxis' */

  /* Outputs for Atomic SubSystem: '<S20>/PI Qaxis' */
  /* SignalConversion generated from: '<S20>/PI Qaxis' */
  Sig_qAxis_PI_out = MotorControlLib_PIDAxis(Sig_qAxis_errorSum_m, Sig_PQ,
    Sig_IQ, rtb_UnitDelay1_b, 0.0F, &MotorControlLib_DW.PIQaxis);

  /* End of Outputs for SubSystem: '<S20>/PI Qaxis' */

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  MotorControlLib_DW.UnitDelay_DSTATE_o = rtb_UnitDelay_n;

  /* End of Outputs for SubSystem: '<S4>/PI_Controller' */

  /* Outputs for Atomic SubSystem: '<S4>/DQ_Limiter' */
  MotorControlLib_DQ_Limiter(Sig_dAxis_PI_out, Sig_qAxis_PI_out, rtb_Switch_i,
    &rtb_RateTransition5, d_q_Voltage_Limiter_max);

  /* End of Outputs for SubSystem: '<S4>/DQ_Limiter' */

  /* SignalConversion generated from: '<S4>/DQ_Limiter' */
  Sig_Vqsatu_m = rtb_Switch_i[1];

  /* SignalConversion generated from: '<S4>/DQ_Limiter' */
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

  /* Outputs for Atomic SubSystem: '<S5>/Inverse Clarke Transform' */
  /* Gain: '<S128>/one_by_two' incorporates:
   *  SignalConversion generated from: '<S128>/In1'
   */
  rtb_RateTransition5 = 0.5F * Sig_Va_m;

  /* Gain: '<S128>/sqrt3_by_two' */
  UnitDelay_DSTATE = 0.866025388F * Sig_Vb_m;

  /* Sum: '<S128>/add_b' */
  rtb_add_b = UnitDelay_DSTATE - rtb_RateTransition5;

  /* Sum: '<S128>/add_c' */
  rtb_add_c = (0.0F - rtb_RateTransition5) - UnitDelay_DSTATE;

  /* End of Outputs for SubSystem: '<S5>/Inverse Clarke Transform' */

  /* Outputs for Atomic SubSystem: '<S5>/Space Vector Generator' */
  /* Gain: '<S129>/one_by_sqrt3' */
  rtb_c = 0.577350259F * Sig_Va_m;

  /* Sum: '<S129>/a' */
  rtb_a = rtb_c + rtb_c;

  /* Sum: '<S129>/b' */
  UnitDelay_DSTATE = Sig_Vb_m - rtb_c;

  /* Sum: '<S129>/c' */
  rtb_c = (0.0F - rtb_c) - Sig_Vb_m;

  /* Gain: '<S129>/one_by_two' incorporates:
   *  MinMax: '<S129>/Max'
   *  MinMax: '<S129>/Min'
   *  Sum: '<S129>/Add'
   */
  rtb_RateTransition5 = (fmaxf(fmaxf(rtb_a, UnitDelay_DSTATE), rtb_c) + fminf
    (fminf(rtb_a, UnitDelay_DSTATE), rtb_c)) * 0.5F;

  /* End of Outputs for SubSystem: '<S5>/Space Vector Generator' */

  /* Switch: '<S5>/Switch' incorporates:
   *  Inport: '<Root>/In1'
   *  Switch: '<S5>/Switch1'
   *  Switch: '<S5>/Switch2'
   */
  if (Sig_change_SVMalgorithm) {
    /* Outputs for Atomic SubSystem: '<S5>/Inverse Clarke Transform' */
    /* Switch: '<S5>/Switch' incorporates:
     *  SignalConversion generated from: '<S128>/In1'
     */
    Sig_Valpha_m = Sig_Va_m;

    /* End of Outputs for SubSystem: '<S5>/Inverse Clarke Transform' */

    /* Switch: '<S5>/Switch1' */
    Sig_Vbeta_m = rtb_add_b;

    /* Switch: '<S5>/Switch2' */
    Sig_Vgamma_m = rtb_add_c;
  } else {
    /* Outputs for Atomic SubSystem: '<S5>/Space Vector Generator' */
    /* Switch: '<S5>/Switch' incorporates:
     *  Sum: '<S129>/Da'
     */
    Sig_Valpha_m = rtb_a - rtb_RateTransition5;

    /* Switch: '<S5>/Switch1' incorporates:
     *  Sum: '<S129>/Db'
     */
    Sig_Vbeta_m = UnitDelay_DSTATE - rtb_RateTransition5;

    /* Switch: '<S5>/Switch2' incorporates:
     *  Sum: '<S129>/Dc'
     */
    Sig_Vgamma_m = rtb_c - rtb_RateTransition5;

    /* End of Outputs for SubSystem: '<S5>/Space Vector Generator' */
  }

  /* End of Switch: '<S5>/Switch' */

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Lookup_n-D: '<S5>/1-D Lookup Table'
   *  Switch: '<S5>/Switch'
   */
  set_PWM_A_DT(look1_iflftu16Df_binlcm(Sig_Valpha_m, &BrkPoints[0],
    &pwmTableData[0], 2U));

  /* DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
   *  Lookup_n-D: '<S5>/1-D Lookup Table1'
   *  Switch: '<S5>/Switch1'
   */
  set_PWM_B_DT(look1_iflftu16Df_binlcm(Sig_Vbeta_m, &BrkPoints[0],
    &pwmTableData[0], 2U));

  /* DataTypeConversion: '<S5>/Data Type Conversion2' incorporates:
   *  Lookup_n-D: '<S5>/1-D Lookup Table2'
   *  Switch: '<S5>/Switch2'
   */
  set_PWM_C_DT(look1_iflftu16Df_binlcm(Sig_Vgamma_m, &BrkPoints[0],
    &pwmTableData[0], 2U));

  /* DiscreteIntegrator: '<Root>/Integrator of Angle' */
  Sig_angle_speed = MotorControlLib_DW.IntegratorofAngle_DSTATE;

  /* Update for DiscreteIntegrator: '<Root>/Integrator of Angle' */
  MotorControlLib_DW.IntegratorofAngle_DSTATE += 0.0002F * Sig_MechanicalAngle;
}

/* Model step function for TID2 */
void MotorControlLib_step2(void)       /* Sample time: [0.01s, 0.0s] */
{
  real32_T rtb_RateTransition1;
  boolean_T rtb_RateTransition4;

  /* Logic: '<S1>/OR' incorporates:
   *  Constant: '<S10>/Constant'
   *  DataStoreRead: '<S1>/Data Store Read1'
   *  DataStoreRead: '<S1>/Data Store Read2'
   *  Inport: '<Root>/Inport8'
   *  Logic: '<S1>/AND'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   */
  Sig_requestMotorBreak = ((activateRPMCntlr && (rpmSoll == 0)) || (qSoll == 0));

  /* RateTransition: '<Root>/Rate Transition1' */
  rtb_RateTransition1 = Sig_angle_speed;

  /* RateTransition: '<Root>/Rate Transition4' incorporates:
   *  Inport: '<Root>/Inport6'
   */
  rtb_RateTransition4 = resetPIIntegratorDQ;

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  /* Inport: '<Root>/Inport8' */
  if (activateRPMCntlr) {
    /* UnitConversion: '<S8>/Unit Conversion' */
    /* Unit Conversion - from: rad/sec to: rpm
       Expression: output = (9.5493*input) + (0) */
    Sig_Rpm_measurment = 9.54929638F * rtb_RateTransition1;

    /* DataTypeConversion: '<S8>/Data Type Conversion3' incorporates:
     *  Constant: '<S8>/Constant6'
     */
    Sig_PRPM = (real32_T)Kp_Rpm * 0.00048828125F;

    /* DataTypeConversion: '<S8>/Data Type Conversion4' incorporates:
     *  Constant: '<S8>/Constant7'
     */
    Sig_IRPM = (real32_T)Ki_Rpm * 0.00048828125F;

    /* Outputs for Atomic SubSystem: '<S8>/PI DAxis' */
    /* Sum: '<S8>/Add' incorporates:
     *  DataStoreRead: '<S8>/Data Store Read1'
     */
    MotorControlLib_PIDAxis_h((real32_T)rpmSoll - Sig_Rpm_measurment, Sig_PRPM,
      Sig_IRPM, rtb_RateTransition4, 0.0F, &MotorControlLib_B.Saturation,
      &MotorControlLib_DW.PIDAxis_h);

    /* End of Outputs for SubSystem: '<S8>/PI DAxis' */
  }

  /* End of Outputs for SubSystem: '<Root>/Subsystem1' */

  /* RateTransition: '<Root>/Rate Transition5' */
  MotorControlLib_DW.RateTransition5_Buffer0 = MotorControlLib_B.Saturation;

  /* Update for RateTransition generated from: '<S9>/Switch' incorporates:
   *  Inport: '<Root>/Inport8'
   */
  MotorControlLib_DW.TmpRTBAtSwitchInport2_Buffer0 = activateRPMCntlr;
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
   *  Inport: '<Root>/Input'
   *  Inport: '<Root>/Input1'
   */
  ConvertPWMtoAngle_Init();

  /* SystemInitialize for Atomic SubSystem: '<S4>/PI_Controller' */
  /* SystemInitialize for Atomic SubSystem: '<S20>/PI DAxis' */
  MotorControlLi_PIDAxis_Init(&MotorControlLib_DW.PIDAxis);

  /* End of SystemInitialize for SubSystem: '<S20>/PI DAxis' */

  /* SystemInitialize for Atomic SubSystem: '<S20>/PI Qaxis' */
  MotorControlLi_PIDAxis_Init(&MotorControlLib_DW.PIQaxis);

  /* End of SystemInitialize for SubSystem: '<S20>/PI Qaxis' */
  /* End of SystemInitialize for SubSystem: '<S4>/PI_Controller' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Start up' */
  /* InitializeConditions for DiscreteIntegrator: '<S131>/Discrete-Time Integrator' */
  MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* End of SystemInitialize for SubSystem: '<Root>/Start up' */

  /* SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1' */
  /* SystemInitialize for Atomic SubSystem: '<S8>/PI DAxis' */
  MotorControl_PIDAxis_l_Init(&MotorControlLib_DW.PIDAxis_h);

  /* End of SystemInitialize for SubSystem: '<S8>/PI DAxis' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subsystem1' */
}

/* Model terminate function */
void MotorControlLib_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
