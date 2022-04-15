/*
 * File: MotorControlLib.c
 *
 * Code generated for Simulink model 'MotorControlLib'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Apr 14 09:54:01 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorControlLib.h"
#include "MotorControlLib_private.h"
#include "InterfaceBswApp.h"
#include "look1_iflftu16Df_binlcpw.h"
#include "rt_atan2f_snf.h"
#include "rt_atan2f_snf_cordic6.h"

/* Exported block signals */
boolean_T enableFluxObs;               /* '<Root>/Inport2' */
uint8_T set_AngleInput;                /* '<Root>/Inport1' */
boolean_T enablePositionObs;           /* '<Root>/Inport3' */
int16_T dth_dt;                        /* '<Root>/Inport4' */
boolean_T resetPIIntegrator;           /* '<Root>/Inport5' */
boolean_T Sig_change_SVMalgorithm;     /* '<Root>/In1' */
boolean_T resetPIIntegratorDQ;         /* '<Root>/Inport6' */
boolean_T setAngleFormat;              /* '<Root>/Input1' */
real32_T Sig_theta_el_m;               /* '<Root>/Delay' */
real32_T Sig_Ia_m;                     /* '<Root>/ADCRAwToCurrent(Iabc)' */
real32_T Sig_Ib_m;                     /* '<Root>/ADCRAwToCurrent(Iabc)' */
real32_T Sig_cos_m;                    /* '<S16>/Sum6' */
real32_T Sig_Ibeta_m;                  /* '<S1>/one_by_sqrt3' */
real32_T Sig_sin_m;                    /* '<S16>/Sum4' */
real32_T Sig_Iq_Soll;                  /* '<S14>/Tq--> iqRef' */
real32_T Sig_dAxis_m;                  /* '<Root>/Gain2' */
real32_T Sig_qAxis_m;                  /* '<Root>/Gain3' */
real32_T Sig_Vqsatu_m;                 /* '<Root>/DQ_Limiter' */
real32_T Sig_Vdsatu_m;                 /* '<Root>/DQ_Limiter' */
real32_T Sig_Va_m;                     /* '<Root>/Gain' */
real32_T Sig_Vb_m;                     /* '<Root>/Gain1' */
real32_T Sig_Valpha_m;                 /* '<S9>/Switch' */
real32_T Sig_Vbeta_m;                  /* '<S9>/Switch1' */
real32_T Sig_Vgamma_m;                 /* '<S9>/Switch2' */
real32_T Angle_sensor_in;              /* '<Root>/PWM angle decoder' */
real32_T Sig_Theta_el_cont_m;          /* '<S12>/Switch' */
real32_T Sig_dAxis_PI_out;             /* '<S115>/Saturation' */
real32_T Sig_qAxis_PI_out;             /* '<S71>/Saturation' */
int16_T constantAngle;                 /* '<S143>/Discrete-Time Integrator' */
int16_T PositionObsAnlge;              /* '<S128>/Data Type Conversion5' */
int16_T FluxObsAngle;                  /* '<S21>/PositionGain' */
boolean_T Sig_qSollIsNegative;         /* '<S3>/Compare' */
real32_T Sig_Emfobs_errorSum_m;        /* '<S129>/Add6' */
real32_T Sig_Emfobs_PI_out;            /* '<S136>/Saturation' */
real32_T di_dt_E9;                     /* '<S135>/Inductance' */
real32_T di_dt_times_Ts_En8;           /* '<S135>/Gain' */
real32_T i_integrated_en4;             /* '<S135>/Sum' */
real32_T i_integrated_times_Rs_en8;    /* '<S135>/Resistance' */
real32_T Va_all_16En4;                 /* '<S135>/Add5' */
int16_T Sig_First_LPF_out;             /* '<S131>/Product1'
                                        * 16En6
                                        */
int16_T Sig_Second_LPF_out;            /* '<S132>/Product1'
                                        * 16En6
                                        */
real32_T Sig_dAxis_errorSum_m;         /* '<S8>/Add' */
real32_T Sig_qAxis_errorSum_m;         /* '<S8>/Add1' */

/* Exported block parameters */
real32_T TsIntern = 5.0E-5F;           /* Variable: TsIntern
                                        * Referenced by:
                                        *   '<S135>/Gain'
                                        *   '<S138>/Gain'
                                        * fixdt(0,32,2^-24,0)
                                        */
int16_T MaxBckEMFVol_sat_neg = -48;    /* Variable: MaxBckEMFVol_sat_neg
                                        * Referenced by:
                                        *   '<S136>/Saturation'
                                        *   '<S139>/Saturation'
                                        * fixdt(1,16,2^-2,0)
                                        */
int16_T MaxBckEMFVol_sat_pos = 48;     /* Variable: MaxBckEMFVol_sat_pos
                                        * Referenced by:
                                        *   '<S136>/Saturation'
                                        *   '<S139>/Saturation'
                                        * fixdt(1,32,2^-8,0)
                                        */
int16_T Ki_Iab_EMFobs = 0;             /* Variable: Ki_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S137>/Ki'
                                        *   '<S140>/Ki'
                                        * fixdt(1,16,2^-3,0)
                                        */
int16_T d_q_Voltage_Limiter_max = 111; /* Variable: d_q_Voltage_Limiter_max
                                        * Referenced by: '<Root>/DQ_Limiter'
                                        * =12/sqrt(3)
                                        */
int16_T d_q_Voltage_Limiter_sat_neg = -96;/* Variable: d_q_Voltage_Limiter_sat_neg
                                           * Referenced by:
                                           *   '<S57>/DeadZone'
                                           *   '<S71>/Saturation'
                                           *   '<S101>/DeadZone'
                                           *   '<S115>/Saturation'
                                           * fixdt(1,16,2^-4,0)
                                           */
int16_T d_q_Voltage_Limiter_sat_pos = 96;/* Variable: d_q_Voltage_Limiter_sat_pos
                                          * Referenced by:
                                          *   '<S57>/DeadZone'
                                          *   '<S71>/Saturation'
                                          *   '<S101>/DeadZone'
                                          *   '<S115>/Saturation'
                                          * fixdt(1,16,2^-4,0)
                                          */
int16_T Ki_dAxis = 100;                  /* Variable: Ki_dAxis
                                        * Referenced by: '<S6>/Constant7'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Ki_qAxis = 100;                  /* Variable: Ki_qAxis
                                        * Referenced by: '<S6>/Constant5'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Kp_dAxis = 4;                 /* Variable: Kp_dAxis
                                        * Referenced by: '<S6>/Constant6'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Kp_qAxis = 25;                 /* Variable: Kp_qAxis
                                        * Referenced by: '<S6>/Constant4'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Kp_Iab_EMFobs = 256;           /* Variable: Kp_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S136>/Kp'
                                        *   '<S139>/Kp'
                                        * fixdt(1,16,2^-8,0)
                                        */
int16_T qSoll = 0;                     /* Variable: qSoll
                                        * Referenced by: '<Root>/q Soll'
                                        * fixdt(1,16,2^-8,0)
                                        */
uint16_T MaximumCurrentBeforeReaction = 10240U;/* Variable: MaximumCurrentBeforeReaction
                                                * Referenced by: '<Root>/SafetyChecks'
                                                * Maximum current limit before softare shutdowns the mosfets.
                                                */
uint16_T CuttOffFreq_c = 4000U;        /* Variable: CuttOffFreq_c
                                        * Referenced by:
                                        *   '<S131>/Constant'
                                        *   '<S132>/Constant'
                                        *   '<S133>/Constant'
                                        *   '<S134>/Constant'
                                        */

/* Exported block states */
real32_T UnitDelayIntegratorPosObs;    /* '<S135>/Delay' */

/* Block signals (default storage) */
B_MotorControlLib_T MotorControlLib_B;

/* Block states (default storage) */
DW_MotorControlLib_T MotorControlLib_DW;

real32_T PI_q_Integrator;
real32_T PI_d_Integrator;

/* Previous zero-crossings (trigger) states */
PrevZCX_MotorControlLib_T MotorControlLib_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
ExtY_MotorControlLib_T MotorControlLib_Y;

/* Real-time model */
RT_MODEL_MotorControlLib_T MotorControlLib_M_;
RT_MODEL_MotorControlLib_T *const MotorControlLib_M = &MotorControlLib_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (MotorControlLib_M->Timing.TaskCounters.TID[1])++;
  if ((MotorControlLib_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.0001s, 0.0s] */
    MotorControlLib_M->Timing.TaskCounters.TID[1] = 0;
  }

  (MotorControlLib_M->Timing.TaskCounters.TID[2])++;
  if ((MotorControlLib_M->Timing.TaskCounters.TID[2]) > 3) {/* Sample time: [0.0002s, 0.0s] */
    MotorControlLib_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Output and update for atomic system: '<Root>/DQ_Limiter' */
void MotorControlLib_DQ_Limiter(real32_T rtu_Vd_ref, real32_T rtu_Vq_ref,
  real32_T rty_Vd_sat[2], real32_T *rty_Vmax_unsat, int16_T rtp_Vmax)
{
  real32_T rtb_Gain;

  /* Sum: '<S5>/Sum2' incorporates:
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   */
  *rty_Vmax_unsat = rtu_Vd_ref * rtu_Vd_ref + rtu_Vq_ref * rtu_Vq_ref;

  /* Sqrt: '<S5>/Sqrt' */
  *rty_Vmax_unsat = sqrtf(*rty_Vmax_unsat);

  /* Switch: '<S5>/Switch' incorporates:
   *  Gain: '<S5>/Gain'
   *  Math: '<S5>/Math Function2'
   *  Product: '<S5>/Product2'
   *
   * About '<S5>/Math Function2':
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

  /* End of Switch: '<S5>/Switch' */
}

/* Output and update for enable system: '<Root>/FluxObserver' */
void MotorControlLib_FluxObserver(boolean_T rtu_Enable, real32_T rtu_In1,
  real32_T rtu_In2, real32_T rtu_In3, real32_T rtu_In4, int16_T
  *rty_FluxObsAngle, B_FluxObserver_MotorControlLi_T *localB, const
  ConstB_FluxObserver_MotorCont_T *localC, DW_FluxObserver_MotorControlL_T
  *localDW, ZCE_FluxObserver_MotorControl_T *localZCE)
{
  real32_T rtb_Atan2;

  /* Outputs for Enabled SubSystem: '<Root>/FluxObserver' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (rtu_Enable) {
    /* Outputs for Atomic SubSystem: '<S6>/FluxObserver' */
    /* Delay: '<S24>/Delay' */
    if ((localZCE->Delay_Reset_ZCE == POS_ZCSIG) && (localZCE->Delay_Reset_ZCE
         != UNINITIALIZED_ZCSIG)) {
      localDW->Delay_DSTATE = 0.0F;
    }

    localZCE->Delay_Reset_ZCE = 0U;

    /* Sum: '<S24>/Sum' incorporates:
     *  Delay: '<S24>/Delay'
     *  Gain: '<S24>/Gain'
     *  Gain: '<S30>/ScalingR'
     *  Sum: '<S24>/Sum3'
     */
    localDW->Delay_DSTATE += (rtu_In2 - EMFobsRS * rtu_In4) * 9.99998301E-5F;

    /* Delay: '<S23>/Delay' */
    if ((localZCE->Delay_Reset_ZCE_o == POS_ZCSIG) &&
        (localZCE->Delay_Reset_ZCE_o != UNINITIALIZED_ZCSIG)) {
      localDW->Delay_DSTATE_e = 0.0F;
    }

    localZCE->Delay_Reset_ZCE_o = 0U;

    /* Sum: '<S23>/Sum' incorporates:
     *  Delay: '<S23>/Delay'
     *  Gain: '<S23>/Gain'
     *  Gain: '<S29>/ScalingR'
     *  Sum: '<S23>/Sum3'
     */
    localDW->Delay_DSTATE_e += (rtu_In1 - EMFobsRS * rtu_In3) * 9.99998301E-5F;

    /* Outputs for Atomic SubSystem: '<S21>/atan2' */
    /* Trigonometry: '<S22>/Atan2' incorporates:
     *  Delay: '<S23>/Delay'
     *  Delay: '<S24>/Delay'
     *  Gain: '<S29>/ScalingL'
     *  Gain: '<S30>/ScalingL'
     *  Sum: '<S23>/Sum1'
     *  Sum: '<S24>/Sum1'
     *  Switch: '<S23>/Switch'
     *  Switch: '<S24>/Switch'
     */
    rtb_Atan2 = rt_atan2f_snf(localDW->Delay_DSTATE - EMFobsLdGain * rtu_In4,
      localDW->Delay_DSTATE_e - EMFobsLdGain * rtu_In3);

    /* Outputs for Enabled SubSystem: '<S22>/If Action Subsystem' incorporates:
     *  EnablePort: '<S27>/Enable'
     */
    if (localC->Compare) {
      /* Inport: '<S27>/In1' */
      localB->Merge = rtb_Atan2;
    }

    /* End of Outputs for SubSystem: '<S22>/If Action Subsystem' */

    /* Outputs for Enabled SubSystem: '<S22>/per Uint' incorporates:
     *  EnablePort: '<S28>/Enable'
     */
    if (localC->Compare_l) {
      /* Gain: '<S28>/Gain' */
      localB->Merge = 0.159154937F * rtb_Atan2;

      /* Switch: '<S28>/Switch' incorporates:
       *  Bias: '<S28>/Bias'
       */
      if (!(localB->Merge >= 0.0F)) {
        localB->Merge++;
      }

      /* End of Switch: '<S28>/Switch' */
    }

    /* End of Outputs for SubSystem: '<S22>/per Uint' */

    /* Gain: '<S21>/PositionGain' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S22>/a16'
     */
    rtb_Atan2 = truncf(6.28318548F * localB->Merge * 256.0F);

    /* End of Outputs for SubSystem: '<S21>/atan2' */
    if (rtIsNaNF(rtb_Atan2) || rtIsInfF(rtb_Atan2)) {
      rtb_Atan2 = 0.0F;
    } else {
      rtb_Atan2 = fmodf(rtb_Atan2, 65536.0F);
    }

    *rty_FluxObsAngle = (int16_T)(rtb_Atan2 < 0.0F ? (int32_T)(int16_T)-(int16_T)
      (uint16_T)-rtb_Atan2 : (int32_T)(int16_T)(uint16_T)rtb_Atan2);

    /* End of Gain: '<S21>/PositionGain' */
    /* End of Outputs for SubSystem: '<S6>/FluxObserver' */
  }

  /* End of Outputs for SubSystem: '<Root>/FluxObserver' */
}

/* Output and update for atomic system: '<Root>/PI_Controller' */
void MotorControlLib_PI_Controller(int8_T rtu_dRef, real32_T rtu_In5, real32_T
  rtu_qRef, real32_T rtu_In6, boolean_T rtu_Inport6, real32_T *rty_d, real32_T
  *rty_q, DW_PI_Controller_MotorControl_T *localDW)
{
  real32_T rtb_Sum_j;
  real32_T rtb_IProdOut;
  boolean_T rtb_OR_o;
  boolean_T rtb_NotEqual;
  real32_T rtb_Switch_e;
  real32_T u2;
  real32_T u1_tmp;
  real32_T u1;

  /* Sum: '<S8>/Add' */
  Sig_dAxis_errorSum_m = (real32_T)rtu_dRef - rtu_In5;

  /* Outputs for Enabled SubSystem: '<S34>/Subsystem' incorporates:
   *  EnablePort: '<S124>/Enable'
   */
  /* UnitDelay: '<S34>/Unit Delay' */
  if (localDW->UnitDelay_DSTATE_o) {
    /* Sum: '<S124>/Add2' incorporates:
     *  Constant: '<S34>/Constant8'
     *  UnitDelay: '<S124>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE++;
  }

  /* End of Outputs for SubSystem: '<S34>/Subsystem' */

  /* RelationalOperator: '<S123>/Compare' incorporates:
   *  Constant: '<S123>/Constant'
   *  UnitDelay: '<S124>/Unit Delay'
   *  UnitDelay: '<S34>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE_o = (localDW->UnitDelay_DSTATE < 50);

  /* Logic: '<S8>/OR' incorporates:
   *  UnitDelay: '<S34>/Unit Delay'
   */
  rtb_OR_o = (localDW->UnitDelay_DSTATE_o || rtu_Inport6);

  /* DiscreteIntegrator: '<S108>/Integrator' */
  if (rtb_OR_o || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = 0.0F;
  }

  /* Sum: '<S117>/Sum' incorporates:
   *  Constant: '<S8>/Constant6'
   *  DataTypeConversion: '<S8>/Data Type Conversion3'
   *  DiscreteIntegrator: '<S108>/Integrator'
   *  Product: '<S113>/PProd Out'
   */
  rtb_IProdOut = (real32_T)Kp_dAxis * 0.03125F * Sig_dAxis_errorSum_m +
    localDW->Integrator_DSTATE;

  /* DeadZone: '<S101>/DeadZone' incorporates:
   *  Saturate: '<S115>/Saturation'
   */
  u2 = (real32_T)d_q_Voltage_Limiter_sat_pos * 0.0625F;
  if (rtb_IProdOut > u2) {
    rtb_Sum_j = rtb_IProdOut - u2;
  } else {
    u1_tmp = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
    if (rtb_IProdOut >= u1_tmp) {
      rtb_Sum_j = 0.0F;
    } else {
      rtb_Sum_j = rtb_IProdOut - u1_tmp;
    }
  }

  /* End of DeadZone: '<S101>/DeadZone' */

  /* RelationalOperator: '<S101>/NotEqual' incorporates:
   *  Gain: '<S101>/ZeroGain'
   */
  rtb_NotEqual = (0.0F * rtb_IProdOut != rtb_Sum_j);

  /* Signum: '<S101>/SignPreSat' */
  if (rtb_Sum_j < 0.0F) {
    rtb_Sum_j = -1.0F;
  } else if (rtb_Sum_j > 0.0F) {
    rtb_Sum_j = 1.0F;
  } else if (rtb_Sum_j == 0.0F) {
    rtb_Sum_j = 0.0F;
  } else {
    rtb_Sum_j = (rtNaNF);
  }

  /* End of Signum: '<S101>/SignPreSat' */

  /* DataTypeConversion: '<S101>/DataTypeConv1' */
  if (rtIsNaNF(rtb_Sum_j)) {
    u1_tmp = 0.0F;
  } else {
    u1_tmp = fmodf(rtb_Sum_j, 256.0F);
  }

  /* Product: '<S105>/IProd Out' incorporates:
   *  Constant: '<S8>/Constant7'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   */
  rtb_Sum_j = (real32_T)Ki_dAxis * 0.03125F * Sig_dAxis_errorSum_m;

  /* Signum: '<S101>/SignPreIntegrator' */
  if (rtb_Sum_j < 0.0F) {
    /* DataTypeConversion: '<S101>/DataTypeConv2' */
    rtb_Switch_e = -1.0F;
  } else if (rtb_Sum_j > 0.0F) {
    /* DataTypeConversion: '<S101>/DataTypeConv2' */
    rtb_Switch_e = 1.0F;
  } else if (rtb_Sum_j == 0.0F) {
    /* DataTypeConversion: '<S101>/DataTypeConv2' */
    rtb_Switch_e = 0.0F;
  } else {
    /* DataTypeConversion: '<S101>/DataTypeConv2' */
    rtb_Switch_e = (rtNaNF);
  }

  /* End of Signum: '<S101>/SignPreIntegrator' */

  /* DataTypeConversion: '<S101>/DataTypeConv2' */
  if (rtIsNaNF(rtb_Switch_e)) {
    rtb_Switch_e = 0.0F;
  } else {
    rtb_Switch_e = fmodf(rtb_Switch_e, 256.0F);
  }

  /* Switch: '<S101>/Switch' incorporates:
   *  Constant: '<S101>/Constant1'
   *  DataTypeConversion: '<S101>/DataTypeConv1'
   *  DataTypeConversion: '<S101>/DataTypeConv2'
   *  Logic: '<S101>/AND3'
   *  RelationalOperator: '<S101>/Equal1'
   */
  if (rtb_NotEqual && ((int8_T)(u1_tmp < 0.0F ? (int32_T)(int8_T)-(int8_T)
        (uint8_T)-u1_tmp : (int32_T)(int8_T)(uint8_T)u1_tmp) == (rtb_Switch_e <
        0.0F ? (int32_T)(int8_T)-(int8_T)(uint8_T)-rtb_Switch_e : (int32_T)
        (int8_T)(uint8_T)rtb_Switch_e))) {
    rtb_Switch_e = 0.0F;
  } else {
    rtb_Switch_e = rtb_Sum_j;
  }

  /* End of Switch: '<S101>/Switch' */

  /* Saturate: '<S115>/Saturation' */
  u1_tmp = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
  if (rtb_IProdOut > u2) {
    *rty_d = u2;
  } else if (rtb_IProdOut < u1_tmp) {
    *rty_d = u1_tmp;
  } else {
    *rty_d = rtb_IProdOut;
  }

  /* DiscreteIntegrator: '<S64>/Integrator' */
  if (rtb_OR_o || (localDW->Integrator_PrevResetState_l != 0)) {
    localDW->Integrator_DSTATE_m = 0.0F;
  }

  /* Sum: '<S8>/Add1' */
  Sig_qAxis_errorSum_m = rtu_qRef - rtu_In6;

  /* Sum: '<S73>/Sum' incorporates:
   *  Constant: '<S8>/Constant4'
   *  DataTypeConversion: '<S8>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S64>/Integrator'
   *  Product: '<S69>/PProd Out'
   */
  rtb_Sum_j = (real32_T)Kp_qAxis * 0.03125F * Sig_qAxis_errorSum_m +
    localDW->Integrator_DSTATE_m;

  /* DeadZone: '<S57>/DeadZone' */
  if (rtb_Sum_j > (real32_T)d_q_Voltage_Limiter_sat_pos * 0.0625F) {
    rtb_IProdOut = rtb_Sum_j - (real32_T)d_q_Voltage_Limiter_sat_pos * 0.0625F;
  } else if (rtb_Sum_j >= (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F) {
    rtb_IProdOut = 0.0F;
  } else {
    rtb_IProdOut = rtb_Sum_j - (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
  }

  /* End of DeadZone: '<S57>/DeadZone' */

  /* RelationalOperator: '<S57>/NotEqual' incorporates:
   *  Gain: '<S57>/ZeroGain'
   */
  rtb_NotEqual = (0.0F * rtb_Sum_j != rtb_IProdOut);

  /* Signum: '<S57>/SignPreSat' */
  if (rtb_IProdOut < 0.0F) {
    rtb_IProdOut = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    rtb_IProdOut = 1.0F;
  } else if (rtb_IProdOut == 0.0F) {
    rtb_IProdOut = 0.0F;
  } else {
    rtb_IProdOut = (rtNaNF);
  }

  /* End of Signum: '<S57>/SignPreSat' */

  /* DataTypeConversion: '<S57>/DataTypeConv1' */
  if (rtIsNaNF(rtb_IProdOut)) {
    u1_tmp = 0.0F;
  } else {
    u1_tmp = fmodf(rtb_IProdOut, 256.0F);
  }

  /* Product: '<S61>/IProd Out' incorporates:
   *  Constant: '<S8>/Constant5'
   *  DataTypeConversion: '<S8>/Data Type Conversion1'
   */
  rtb_IProdOut = (real32_T)Ki_qAxis * 0.03125F * Sig_qAxis_errorSum_m;

  /* Saturate: '<S71>/Saturation' */
  u1 = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
  u2 = (real32_T)d_q_Voltage_Limiter_sat_pos * 0.0625F;
  if (rtb_Sum_j > u2) {
    *rty_q = u2;
  } else if (rtb_Sum_j < u1) {
    *rty_q = u1;
  } else {
    *rty_q = rtb_Sum_j;
  }

  /* End of Saturate: '<S71>/Saturation' */

  /* Update for DiscreteIntegrator: '<S108>/Integrator' */
  localDW->Integrator_DSTATE += 0.0002F * rtb_Switch_e;
  localDW->Integrator_PrevResetState = (int8_T)rtb_OR_o;

  /* Signum: '<S57>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0F) {
    /* DataTypeConversion: '<S57>/DataTypeConv2' */
    rtb_Switch_e = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    /* DataTypeConversion: '<S57>/DataTypeConv2' */
    rtb_Switch_e = 1.0F;
  } else if (rtb_IProdOut == 0.0F) {
    /* DataTypeConversion: '<S57>/DataTypeConv2' */
    rtb_Switch_e = 0.0F;
  } else {
    /* DataTypeConversion: '<S57>/DataTypeConv2' */
    rtb_Switch_e = (rtNaNF);
  }

  /* End of Signum: '<S57>/SignPreIntegrator' */

  /* DataTypeConversion: '<S57>/DataTypeConv2' */
  if (rtIsNaNF(rtb_Switch_e)) {
    rtb_Switch_e = 0.0F;
  } else {
    rtb_Switch_e = fmodf(rtb_Switch_e, 256.0F);
  }

  /* Switch: '<S57>/Switch' incorporates:
   *  Constant: '<S57>/Constant1'
   *  DataTypeConversion: '<S57>/DataTypeConv1'
   *  DataTypeConversion: '<S57>/DataTypeConv2'
   *  Logic: '<S57>/AND3'
   *  RelationalOperator: '<S57>/Equal1'
   */
  if (rtb_NotEqual && ((int8_T)(u1_tmp < 0.0F ? (int32_T)(int8_T)-(int8_T)
        (uint8_T)-u1_tmp : (int32_T)(int8_T)(uint8_T)u1_tmp) == (rtb_Switch_e <
        0.0F ? (int32_T)(int8_T)-(int8_T)(uint8_T)-rtb_Switch_e : (int32_T)
        (int8_T)(uint8_T)rtb_Switch_e))) {
    rtb_IProdOut = 0.0F;
  }

  /* End of Switch: '<S57>/Switch' */

  /* Update for DiscreteIntegrator: '<S60>/Integrator' */
  PI_q_Integrator=localDW->Integrator_DSTATE_m;
  localDW->Integrator_DSTATE_m += 0.0002F * rtb_IProdOut;
  localDW->Integrator_PrevResetState_l = (int8_T)rtb_OR_o;
}

/* System reset for enable system: '<Root>/Position observer' */
void MotorCon_Positionobserver_Reset(DW_Positionobserver_MotorCont_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S129>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
  localDW->UnitDelay_DSTATE_cm = 0;

  /* InitializeConditions for UnitDelay: '<S131>/Unit Delay' */
  localDW->UnitDelay_DSTATE_k = 0;

  /* InitializeConditions for Delay: '<S131>/Delay' */
  localDW->Delay_DSTATE_l = 0;

  /* InitializeConditions for UnitDelay: '<S132>/Unit Delay' */
  localDW->UnitDelay_DSTATE_o = 0;

  /* InitializeConditions for Delay: '<S132>/Delay' */
  localDW->Delay_DSTATE_k = 0;

  /* InitializeConditions for Saturate: '<S139>/Saturation' incorporates:
   *  UnitDelay: '<S130>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE_g = 0;

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = 0;

  /* InitializeConditions for UnitDelay: '<S134>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p = 0;

  /* InitializeConditions for Delay: '<S134>/Delay' */
  localDW->Delay_DSTATE_b = 0;

  /* InitializeConditions for UnitDelay: '<S133>/Unit Delay' */
  localDW->UnitDelay_DSTATE_mq = 0;

  /* InitializeConditions for Delay: '<S133>/Delay' */
  localDW->Delay_DSTATE_e = 0;

  /* SystemReset for Atomic SubSystem: '<S129>/DC Motor Model' */
  /* InitializeConditions for UnitDelay: '<S135>/Unit Delay' */
  localDW->UnitDelay_DSTATE_c = 0.0F;

  /* InitializeConditions for Delay: '<S135>/Delay' */
  UnitDelayIntegratorPosObs = 0.0F;

  /* End of SystemReset for SubSystem: '<S129>/DC Motor Model' */

  /* SystemReset for Atomic SubSystem: '<S130>/DC Motor Model' */
  /* InitializeConditions for UnitDelay: '<S138>/Unit Delay' */
  localDW->UnitDelay_DSTATE_m = 0;

  /* InitializeConditions for Delay: '<S138>/Delay' */
  localDW->Delay_DSTATE = 0;

  /* End of SystemReset for SubSystem: '<S130>/DC Motor Model' */
}

/* Disable for enable system: '<Root>/Position observer' */
void MotorC_Positionobserver_Disable(DW_Positionobserver_MotorCont_T *localDW)
{
  localDW->Positionobserver_MODE = false;
}

/* Output and update for enable system: '<Root>/Position observer' */
void MotorControlLi_Positionobserver(RT_MODEL_MotorControlLib_T * const
  MotorControlLib_M, boolean_T rtu_Enable, real32_T rtu_Va, real32_T rtu_Vb,
  real32_T rtu_Ia, real32_T rtu_Ib, boolean_T rtu_In5, int16_T *rty_theta,
  B_Positionobserver_MotorContr_T *localB, DW_Positionobserver_MotorCont_T
  *localDW, ZCE_Positionobserver_MotorCon_T *localZCE)
{
  real32_T rtb_Atan2;
  int16_T rtb_Add6;
  int16_T rtb_Add2;
  real32_T u;
  real32_T v;
  real32_T u1;

  /* Outputs for Enabled SubSystem: '<Root>/Position observer' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  if (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0) {
    if (rtu_Enable) {
      if (!localDW->Positionobserver_MODE) {
        MotorCon_Positionobserver_Reset(localDW);
        localDW->Positionobserver_MODE = true;
      }
    } else {
      if (localDW->Positionobserver_MODE) {
        MotorC_Positionobserver_Disable(localDW);
      }
    }
  }

  if (localDW->Positionobserver_MODE) {
    if (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0) {
      /* UnitDelay: '<S129>/Unit Delay' */
      localB->UnitDelay = localDW->UnitDelay_DSTATE;

      /* UnitDelay: '<S11>/Unit Delay' */
      localB->UnitDelay_n = localDW->UnitDelay_DSTATE_cm;
    }

    /* Outputs for Atomic SubSystem: '<S129>/DC Motor Model' */
    /* Gain: '<S135>/Inductance' incorporates:
     *  UnitDelay: '<S135>/Unit Delay'
     */
    di_dt_E9 = EMFobsLdGain * localDW->UnitDelay_DSTATE_c;

    /* Gain: '<S135>/Gain' */
    di_dt_times_Ts_En8 = TsIntern * di_dt_E9;

    /* Sum: '<S135>/Sum' incorporates:
     *  Delay: '<S135>/Delay'
     */
    i_integrated_en4 = di_dt_times_Ts_En8 + UnitDelayIntegratorPosObs;

    /* Gain: '<S135>/Resistance' */
    i_integrated_times_Rs_en8 = EMFobsRS * i_integrated_en4;

    /* Sum: '<S135>/Add5' */
    Va_all_16En4 = ((rtu_Va - i_integrated_times_Rs_en8) - localB->UnitDelay) -
      (real32_T)localB->UnitDelay_n * 0.015625F;

    /* Update for UnitDelay: '<S135>/Unit Delay' */
    localDW->UnitDelay_DSTATE_c = Va_all_16En4;

    /* Update for Delay: '<S135>/Delay' */
    UnitDelayIntegratorPosObs = i_integrated_en4;

    /* End of Outputs for SubSystem: '<S129>/DC Motor Model' */
    if (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0) {
      /* Sum: '<S129>/Add6' */
      Sig_Emfobs_errorSum_m = i_integrated_en4 - rtu_Ia;

      /* Outputs for Enabled SubSystem: '<S136>/Anti-windup' incorporates:
       *  EnablePort: '<S137>/Enable'
       */
      /* RelationalOperator: '<S136>/Relational Operator' incorporates:
       *  Abs: '<S136>/Abs'
       *  Constant: '<S136>/Ki activation treashold'
       */
      if (fabsf(Sig_Emfobs_errorSum_m) <= 0.23F) {
        /* Delay: '<S137>/Delay1' */
        if ((((localZCE->Delay1_Reset_ZCE_j == POS_ZCSIG) != (int32_T)rtu_In5) &&
             (localZCE->Delay1_Reset_ZCE_j != UNINITIALIZED_ZCSIG)) || rtu_In5)
        {
          localDW->Delay1_DSTATE_m = 0;
        }

        localZCE->Delay1_Reset_ZCE_j = rtu_In5;

        /* Sum: '<S137>/Sum1' incorporates:
         *  Delay: '<S137>/Delay1'
         *  Gain: '<S137>/Gain1'
         *  Gain: '<S137>/Ki'
         */
        u1 = floorf(((real32_T)Ki_Iab_EMFobs * 0.125F * Sig_Emfobs_errorSum_m *
                     0.000244140625F + (real32_T)localDW->Delay1_DSTATE_m *
                     0.00390625F) * 256.0F);
        if (rtIsNaNF(u1) || rtIsInfF(u1)) {
          u1 = 0.0F;
        } else {
          u1 = fmodf(u1, 65536.0F);
        }

        localB->Sum1_p = (int16_T)(u1 < 0.0F ? (int32_T)(int16_T)-(int16_T)
          (uint16_T)-u1 : (int32_T)(int16_T)(uint16_T)u1);

        /* End of Sum: '<S137>/Sum1' */

        /* Update for Delay: '<S137>/Delay1' */
        localDW->Delay1_DSTATE_m = localB->Sum1_p;
      }

      /* End of RelationalOperator: '<S136>/Relational Operator' */
      /* End of Outputs for SubSystem: '<S136>/Anti-windup' */

      /* Sum: '<S136>/Add1' incorporates:
       *  Gain: '<S136>/Kp'
       */
      Sig_Emfobs_PI_out = (real32_T)Kp_Iab_EMFobs * 0.00390625F *
        Sig_Emfobs_errorSum_m + (real32_T)localB->Sum1_p * 0.00390625F;

      /* Saturate: '<S136>/Saturation' */
      u1 = (real32_T)MaxBckEMFVol_sat_neg * 0.25F;
      rtb_Atan2 = (real32_T)MaxBckEMFVol_sat_pos * 0.25F;
      if (Sig_Emfobs_PI_out > rtb_Atan2) {
        /* Sum: '<S136>/Add1' */
        Sig_Emfobs_PI_out = rtb_Atan2;
      } else {
        if (Sig_Emfobs_PI_out < u1) {
          /* Sum: '<S136>/Add1' */
          Sig_Emfobs_PI_out = u1;
        }
      }

      /* End of Saturate: '<S136>/Saturation' */

      /* Gain: '<S131>/Gain' incorporates:
       *  Sum: '<S131>/Add2'
       *  UnitDelay: '<S131>/Unit Delay'
       */
      u1 = floorf((Sig_Emfobs_PI_out - (real32_T)localDW->UnitDelay_DSTATE_k *
                   0.015625F) * 0.000244140625F * 16384.0F);
      if (u1 < 32768.0F) {
        if (u1 >= -32768.0F) {
          rtb_Add6 = (int16_T)u1;
        } else {
          rtb_Add6 = MIN_int16_T;
        }
      } else {
        rtb_Add6 = MAX_int16_T;
      }

      /* End of Gain: '<S131>/Gain' */

      /* Sum: '<S131>/Sum' incorporates:
       *  Delay: '<S131>/Delay'
       */
      localDW->Delay_DSTATE_l += rtb_Add6;

      /* Product: '<S131>/Product1' incorporates:
       *  Constant: '<S131>/Constant'
       *  Delay: '<S131>/Delay'
       */
      Sig_First_LPF_out = (int16_T)((localDW->Delay_DSTATE_l * CuttOffFreq_c) >>
        8);

      /* Sum: '<S132>/Sum' incorporates:
       *  Delay: '<S132>/Delay'
       *  Gain: '<S132>/Gain'
       *  Sum: '<S132>/Add2'
       *  UnitDelay: '<S132>/Unit Delay'
       */
      localDW->Delay_DSTATE_k = (int16_T)(((int16_T)(Sig_First_LPF_out -
        localDW->UnitDelay_DSTATE_o) >> 4) + localDW->Delay_DSTATE_k);

      /* Product: '<S132>/Product1' incorporates:
       *  Constant: '<S132>/Constant'
       *  Delay: '<S132>/Delay'
       */
      Sig_Second_LPF_out = (int16_T)((localDW->Delay_DSTATE_k * CuttOffFreq_c) >>
        8);

      /* DataTypeConversion: '<S128>/Data Type Conversion6' */
      rtb_Atan2 = (real32_T)Sig_Second_LPF_out * 0.015625F;

      /* DataTypeConversion: '<S130>/Data Type Conversion' */
      u1 = floorf(rtu_Ib * 16.0F);
      if (rtIsNaNF(u1) || rtIsInfF(u1)) {
        u1 = 0.0F;
      } else {
        u1 = fmodf(u1, 65536.0F);
      }

      rtb_Add2 = (int16_T)(u1 < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-u1
                           : (int32_T)(int16_T)(uint16_T)u1);

      /* End of DataTypeConversion: '<S130>/Data Type Conversion' */

      /* UnitDelay: '<S130>/Unit Delay' */
      localB->UnitDelay_j = localDW->UnitDelay_DSTATE_g;

      /* UnitDelay: '<S11>/Unit Delay1' */
      localB->UnitDelay1 = localDW->UnitDelay1_DSTATE;
    }

    /* Outputs for Atomic SubSystem: '<S130>/DC Motor Model' */
    /* Gain: '<S138>/Inductance' */
    u = EMFobsLdGain * 0.5F;
    v = fabsf(u);
    if (v < 8.388608E+6F) {
      if (v >= 0.5F) {
        u = floorf(u + 0.5F);
      } else {
        u *= 0.0F;
      }
    }

    if (u < 32768.0F) {
      if (u >= -32768.0F) {
        rtb_Add6 = (int16_T)u;
      } else {
        rtb_Add6 = MIN_int16_T;
      }
    } else {
      rtb_Add6 = MAX_int16_T;
    }

    /* Gain: '<S138>/Gain' incorporates:
     *  Gain: '<S138>/Inductance'
     *  UnitDelay: '<S138>/Unit Delay'
     */
    u1 = floorf((real32_T)(int16_T)((rtb_Add6 * localDW->UnitDelay_DSTATE_m) >>
      12) * 512.0F * TsIntern * 16.0F);
    if (u1 < 32768.0F) {
      if (u1 >= -32768.0F) {
        localDW->UnitDelay_DSTATE_m = (int16_T)u1;
      } else {
        localDW->UnitDelay_DSTATE_m = MIN_int16_T;
      }
    } else {
      localDW->UnitDelay_DSTATE_m = MAX_int16_T;
    }

    /* End of Gain: '<S138>/Gain' */

    /* Sum: '<S138>/Sum' incorporates:
     *  Delay: '<S138>/Delay'
     *  UnitDelay: '<S138>/Unit Delay'
     */
    localDW->Delay_DSTATE += localDW->UnitDelay_DSTATE_m;

    /* Sum: '<S138>/Add5' */
    u1 = floorf(rtu_Vb * 16.0F);
    if (rtIsNaNF(u1) || rtIsInfF(u1)) {
      u1 = 0.0F;
    } else {
      u1 = fmodf(u1, 65536.0F);
    }

    /* Gain: '<S138>/Resistance' */
    u = EMFobsRS * 65536.0F;
    v = fabsf(u);
    if (v < 8.388608E+6F) {
      if (v >= 0.5F) {
        u = floorf(u + 0.5F);
      } else {
        u *= 0.0F;
      }
    }

    if (u < 32768.0F) {
      if (u >= -32768.0F) {
        rtb_Add6 = (int16_T)u;
      } else {
        rtb_Add6 = MIN_int16_T;
      }
    } else {
      rtb_Add6 = MAX_int16_T;
    }

    /* Sum: '<S138>/Add5' incorporates:
     *  Delay: '<S138>/Delay'
     *  Gain: '<S138>/Resistance'
     *  UnitDelay: '<S138>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE_m = (int16_T)((int16_T)((int16_T)((u1 < 0.0F ?
      (int32_T)(int16_T)-(int16_T)(uint16_T)-u1 : (int32_T)(int16_T)(uint16_T)u1)
      - ((rtb_Add6 * localDW->Delay_DSTATE) >> 16)) - localB->UnitDelay_j) -
      (localB->UnitDelay1 >> 2));

    /* End of Outputs for SubSystem: '<S130>/DC Motor Model' */
    if (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0) {
      /* Sum: '<S130>/Add6' incorporates:
       *  Delay: '<S138>/Delay'
       */
      rtb_Add6 = (int16_T)(localDW->Delay_DSTATE - rtb_Add2);

      /* Outputs for Atomic SubSystem: '<S130>/PI Controller' */
      /* Abs: '<S139>/Abs' */
      if (rtb_Add6 < 0) {
        rtb_Add2 = (int16_T)-rtb_Add6;
      } else {
        rtb_Add2 = rtb_Add6;
      }

      /* End of Abs: '<S139>/Abs' */

      /* Outputs for Enabled SubSystem: '<S139>/Anti-windup' incorporates:
       *  EnablePort: '<S140>/Enable'
       */
      /* RelationalOperator: '<S139>/Relational Operator' incorporates:
       *  Constant: '<S139>/Constant1'
       */
      if ((rtb_Add2 << 4) <= 59) {
        /* Delay: '<S140>/Delay1' */
        if ((((localZCE->Delay1_Reset_ZCE == POS_ZCSIG) != (int32_T)rtu_In5) &&
             (localZCE->Delay1_Reset_ZCE != UNINITIALIZED_ZCSIG)) || rtu_In5) {
          localDW->Delay1_DSTATE = 0;
        }

        localZCE->Delay1_Reset_ZCE = rtu_In5;

        /* Sum: '<S140>/Sum1' incorporates:
         *  Delay: '<S140>/Delay1'
         *  Gain: '<S140>/Gain1'
         *  Gain: '<S140>/Ki'
         */
        localB->Sum1 = (int16_T)((((int16_T)((Ki_Iab_EMFobs * rtb_Add6) >> 3) >>
          4) + (localDW->Delay1_DSTATE << 4)) >> 4);

        /* Update for Delay: '<S140>/Delay1' */
        localDW->Delay1_DSTATE = localB->Sum1;
      }

      /* End of RelationalOperator: '<S139>/Relational Operator' */
      /* End of Outputs for SubSystem: '<S139>/Anti-windup' */

      /* Sum: '<S139>/Add1' incorporates:
       *  Gain: '<S139>/Kp'
       */
      rtb_Add2 = (int16_T)((((int16_T)((Kp_Iab_EMFobs * rtb_Add6) >> 8) << 4) +
                            localB->Sum1) >> 4);

      /* Saturate: '<S139>/Saturation' incorporates:
       *  UnitDelay: '<S130>/Unit Delay'
       */
      if (MaxBckEMFVol_sat_neg > 8191) {
        localDW->UnitDelay_DSTATE_g = MAX_int16_T;
      } else if (MaxBckEMFVol_sat_neg <= -8192) {
        localDW->UnitDelay_DSTATE_g = MIN_int16_T;
      } else {
        localDW->UnitDelay_DSTATE_g = (int16_T)(MaxBckEMFVol_sat_neg << 2);
      }

      if (MaxBckEMFVol_sat_pos > 8191) {
        rtb_Add6 = MAX_int16_T;
      } else if (MaxBckEMFVol_sat_pos <= -8192) {
        rtb_Add6 = MIN_int16_T;
      } else {
        rtb_Add6 = (int16_T)(MaxBckEMFVol_sat_pos << 2);
      }

      if (rtb_Add2 > rtb_Add6) {
        localDW->UnitDelay_DSTATE_g = rtb_Add6;
      } else {
        if (rtb_Add2 >= localDW->UnitDelay_DSTATE_g) {
          localDW->UnitDelay_DSTATE_g = rtb_Add2;
        }
      }

      /* End of Saturate: '<S139>/Saturation' */
      /* End of Outputs for SubSystem: '<S130>/PI Controller' */

      /* Sum: '<S134>/Sum' incorporates:
       *  Delay: '<S134>/Delay'
       *  Gain: '<S134>/Gain'
       *  Sum: '<S134>/Add2'
       *  UnitDelay: '<S130>/Unit Delay'
       *  UnitDelay: '<S134>/Unit Delay'
       */
      localDW->Delay_DSTATE_b = (int16_T)(((int16_T)
        (((localDW->UnitDelay_DSTATE_g << 2) - localDW->UnitDelay_DSTATE_p) >> 2)
        >> 2) + localDW->Delay_DSTATE_b);

      /* Product: '<S134>/Product1' incorporates:
       *  Constant: '<S134>/Constant'
       *  Delay: '<S134>/Delay'
       *  UnitDelay: '<S134>/Unit Delay'
       */
      localDW->UnitDelay_DSTATE_p = (int16_T)((localDW->Delay_DSTATE_b *
        CuttOffFreq_c) >> 8);

      /* Sum: '<S133>/Sum' incorporates:
       *  Delay: '<S133>/Delay'
       *  Gain: '<S133>/Gain'
       *  Sum: '<S133>/Add2'
       *  UnitDelay: '<S133>/Unit Delay'
       *  UnitDelay: '<S134>/Unit Delay'
       */
      localDW->Delay_DSTATE_e = (int16_T)(((int16_T)(localDW->UnitDelay_DSTATE_p
        - localDW->UnitDelay_DSTATE_mq) >> 4) + localDW->Delay_DSTATE_e);

      /* Product: '<S133>/Product1' incorporates:
       *  Constant: '<S133>/Constant'
       *  Delay: '<S133>/Delay'
       *  UnitDelay: '<S133>/Unit Delay'
       */
      localDW->UnitDelay_DSTATE_mq = (int16_T)((localDW->Delay_DSTATE_e *
        CuttOffFreq_c) >> 8);

      /* Trigonometry: '<S128>/Atan2' incorporates:
       *  DataTypeConversion: '<S128>/Data Type Conversion7'
       *  UnitDelay: '<S133>/Unit Delay'
       */
      rtb_Atan2 = rt_atan2f_snf_cordic6(rtb_Atan2, (real32_T)
        localDW->UnitDelay_DSTATE_mq * 0.015625F);

      /* DataTypeConversion: '<S128>/Data Type Conversion5' */
      u1 = floorf(rtb_Atan2 * 256.0F);
      if (rtIsNaNF(u1) || rtIsInfF(u1)) {
        u1 = 0.0F;
      } else {
        u1 = fmodf(u1, 65536.0F);
      }

      *rty_theta = (int16_T)(u1 < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
        -u1 : (int32_T)(int16_T)(uint16_T)u1);

      /* End of DataTypeConversion: '<S128>/Data Type Conversion5' */

      /* Update for UnitDelay: '<S129>/Unit Delay' */
      localDW->UnitDelay_DSTATE = Sig_Emfobs_PI_out;

      /* Update for UnitDelay: '<S11>/Unit Delay' */
      localDW->UnitDelay_DSTATE_cm = Sig_First_LPF_out;

      /* Update for UnitDelay: '<S131>/Unit Delay' */
      localDW->UnitDelay_DSTATE_k = Sig_First_LPF_out;

      /* Update for UnitDelay: '<S132>/Unit Delay' */
      localDW->UnitDelay_DSTATE_o = Sig_Second_LPF_out;

      /* Update for UnitDelay: '<S11>/Unit Delay1' incorporates:
       *  UnitDelay: '<S134>/Unit Delay'
       */
      localDW->UnitDelay1_DSTATE = localDW->UnitDelay_DSTATE_p;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Position observer' */
}

/* Model step function */
void MotorControlLib_step(void)
{
  int32_T rowIdx;
  real32_T rtb_a;
  real32_T rtb_Add_m;
  real32_T rtb_convert_pu;
  uint16_T rtb_uDLookupTable2;
  real32_T rtb_Switch_p[2];
  real32_T rtb_one_by_two;
  boolean_T rtb_FixPtRelationalOperator;
  int16_T rtb_RateTransition1;
  real32_T rtb_VectorConcatenate[2];
  int16_T tmp;
  int32_T Sig_cos_m_tmp;
  if (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0) {
    /* Delay: '<Root>/Delay' */
    Sig_theta_el_m = MotorControlLib_Y.Position;

    /* Gain: '<S17>/convert_pu' */
    rtb_convert_pu = 0.159154937F * Sig_theta_el_m;

    /* If: '<S17>/If' incorporates:
     *  Constant: '<S18>/Constant'
     *  RelationalOperator: '<S18>/Compare'
     */
    if (rtb_convert_pu < 0.0F) {
      /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      /* DataTypeConversion: '<S19>/Convert_uint16' */
      rtb_one_by_two = floorf(rtb_convert_pu);
      if (rtIsInfF(rtb_one_by_two)) {
        rtb_one_by_two = 0.0F;
      } else {
        rtb_one_by_two = fmodf(rtb_one_by_two, 65536.0F);
      }

      /* Sum: '<S19>/Sum' incorporates:
       *  DataTypeConversion: '<S19>/Convert_back'
       *  DataTypeConversion: '<S19>/Convert_uint16'
       */
      rtb_convert_pu -= (real32_T)(rtb_one_by_two < 0.0F ? (int32_T)(int16_T)
        -(int16_T)(uint16_T)-rtb_one_by_two : (int32_T)(int16_T)(uint16_T)
        rtb_one_by_two);

      /* End of Outputs for SubSystem: '<S17>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* DataTypeConversion: '<S20>/Convert_uint16' */
      rtb_one_by_two = truncf(rtb_convert_pu);
      if (rtIsNaNF(rtb_one_by_two) || rtIsInfF(rtb_one_by_two)) {
        rtb_one_by_two = 0.0F;
      } else {
        rtb_one_by_two = fmodf(rtb_one_by_two, 65536.0F);
      }

      /* Sum: '<S20>/Sum' incorporates:
       *  DataTypeConversion: '<S20>/Convert_back'
       *  DataTypeConversion: '<S20>/Convert_uint16'
       */
      rtb_convert_pu -= (real32_T)(rtb_one_by_two < 0.0F ? (int32_T)(int16_T)
        -(int16_T)(uint16_T)-rtb_one_by_two : (int32_T)(int16_T)(uint16_T)
        rtb_one_by_two);

      /* End of Outputs for SubSystem: '<S17>/If Action Subsystem1' */
    }

    /* End of If: '<S17>/If' */

    /* Gain: '<S15>/indexing' */
    rtb_convert_pu *= 400.0F;

    /* DataTypeConversion: '<S15>/Get_Integer' */
    rtb_one_by_two = truncf(rtb_convert_pu);
    if (rtIsNaNF(rtb_one_by_two) || rtIsInfF(rtb_one_by_two)) {
      rtb_one_by_two = 0.0F;
    } else {
      rtb_one_by_two = fmodf(rtb_one_by_two, 65536.0F);
    }

    rtb_uDLookupTable2 = (uint16_T)(rtb_one_by_two < 0.0F ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-rtb_one_by_two : (int32_T)(uint16_T)rtb_one_by_two);

    /* End of DataTypeConversion: '<S15>/Get_Integer' */

    /* ModelReference: '<Root>/ADCRAwToCurrent(Iabc)' incorporates:
     *  Inport: '<Root>/Inport'
     *  Inport: '<Root>/Inport7'
     */
    ADCRawToIab(&Sig_Ia_m, &Sig_Ib_m);

    /* Sum: '<S15>/Sum2' incorporates:
     *  DataTypeConversion: '<S15>/Data Type Conversion1'
     */
    rtb_convert_pu -= (real32_T)rtb_uDLookupTable2;

    /* Selector: '<S15>/Lookup' incorporates:
     *  Sum: '<S15>/Sum'
     *  Sum: '<S16>/Sum5'
     *  Sum: '<S16>/Sum6'
     */
    Sig_cos_m_tmp = (int32_T)(rtb_uDLookupTable2 + 100U);

    /* Sum: '<S16>/Sum6' incorporates:
     *  Constant: '<S15>/sine_table_values'
     *  Product: '<S16>/Product1'
     *  Selector: '<S15>/Lookup'
     *  Sum: '<S15>/Sum'
     *  Sum: '<S16>/Sum5'
     */
    Sig_cos_m = (rtCP_sine_table_values_Value[(int32_T)(rtb_uDLookupTable2 +
      101U)] - rtCP_sine_table_values_Value[Sig_cos_m_tmp]) * rtb_convert_pu +
      rtCP_sine_table_values_Value[Sig_cos_m_tmp];

    /* Gain: '<S1>/one_by_sqrt3' incorporates:
     *  Sum: '<S1>/a_plus_2b'
     */
    Sig_Ibeta_m = ((Sig_Ia_m + Sig_Ib_m) + Sig_Ib_m) * 0.577350259F;

    /* Sum: '<S16>/Sum4' incorporates:
     *  Constant: '<S15>/sine_table_values'
     *  Product: '<S16>/Product'
     *  Selector: '<S15>/Lookup'
     *  Sum: '<S15>/Sum'
     *  Sum: '<S16>/Sum3'
     */
    Sig_sin_m = (rtCP_sine_table_values_Value[(int32_T)(rtb_uDLookupTable2 + 1U)]
                 - rtCP_sine_table_values_Value[rtb_uDLookupTable2]) *
      rtb_convert_pu + rtCP_sine_table_values_Value[rtb_uDLookupTable2];

    /* Switch: '<S127>/Switch' incorporates:
     *  Product: '<S10>/acos'
     *  Product: '<S10>/asin'
     *  Product: '<S10>/bcos'
     *  Product: '<S10>/bsin'
     *  Sum: '<S10>/sum_Ds'
     *  Sum: '<S10>/sum_Qs'
     */
    rtb_Switch_p[0] = Sig_Ia_m * Sig_cos_m + Sig_Ibeta_m * Sig_sin_m;
    rtb_Switch_p[1] = Sig_Ibeta_m * Sig_cos_m - Sig_Ia_m * Sig_sin_m;

    /* Gain: '<Root>/Gain2' */
    Sig_dAxis_m = rtb_Switch_p[0];

    /* Abs: '<S14>/Abs' incorporates:
     *  Constant: '<Root>/q Soll'
     *  SignalConversion: '<Root>/Signal Copy'
     */
    if (qSoll < 0) {
      tmp = (int16_T)-qSoll;
    } else {
      tmp = qSoll;
    }

    /* End of Abs: '<S14>/Abs' */

    /* Gain: '<S14>/Tq--> iqRef' */
    Sig_Iq_Soll = (real32_T)TqToIqConst * 0.00390625F * ((real32_T)tmp *
      0.00390625F);

    /* Gain: '<Root>/Gain3' */
    Sig_qAxis_m = rtb_Switch_p[1];

    /* Outputs for Atomic SubSystem: '<Root>/PI_Controller' */
    /* Constant: '<Root>/d Soll' incorporates:
     *  Constant: '<Root>/q Soll'
     *  Inport: '<Root>/Inport6'
     *  Logic: '<Root>/OR'
     *  RelationalOperator: '<S2>/Compare'
     *  SignalConversion: '<Root>/Signal Copy'
     */
    MotorControlLib_PI_Controller(dSoll, Sig_dAxis_m, Sig_Iq_Soll, Sig_qAxis_m,
      (qSoll == 0) || resetPIIntegratorDQ, &Sig_dAxis_PI_out, &Sig_qAxis_PI_out,
      &MotorControlLib_DW.PI_Controller);

    /* End of Outputs for SubSystem: '<Root>/PI_Controller' */

    /* Outputs for Atomic SubSystem: '<Root>/DQ_Limiter' */
    MotorControlLib_DQ_Limiter(Sig_dAxis_PI_out, Sig_qAxis_PI_out, rtb_Switch_p,
      &rtb_convert_pu, d_q_Voltage_Limiter_max);

    /* End of Outputs for SubSystem: '<Root>/DQ_Limiter' */

    /* SignalConversion generated from: '<Root>/DQ_Limiter' */
    Sig_Vqsatu_m = rtb_Switch_p[1];

    /* SignalConversion generated from: '<Root>/DQ_Limiter' */
    Sig_Vdsatu_m = rtb_Switch_p[0];

    /* Switch: '<S31>/Switch' incorporates:
     *  Product: '<S7>/dcos'
     *  Product: '<S7>/dsin'
     *  Product: '<S7>/qcos'
     *  Product: '<S7>/qsin'
     *  Sum: '<S7>/sum_alpha'
     *  Sum: '<S7>/sum_beta'
     */
    rtb_Switch_p[0] = Sig_Vdsatu_m * Sig_cos_m - Sig_Vqsatu_m * Sig_sin_m;
    rtb_Switch_p[1] = Sig_Vqsatu_m * Sig_cos_m + Sig_Vdsatu_m * Sig_sin_m;

    /* Gain: '<Root>/Gain' */
    Sig_Va_m = rtb_Switch_p[0];

    /* Gain: '<Root>/Gain1' */
    Sig_Vb_m = rtb_Switch_p[1];

    /* Outputs for Atomic SubSystem: '<S9>/Inverse Clarke Transform' */
    /* Gain: '<S125>/one_by_two' incorporates:
     *  Inport: '<S125>/In1'
     */
    rtb_one_by_two = 0.5F * Sig_Va_m;

    /* Gain: '<S125>/sqrt3_by_two' */
    rtb_convert_pu = 0.866025388F * Sig_Vb_m;

    /* Sum: '<S125>/add_b' */
    Sig_Vbeta_m = rtb_convert_pu - rtb_one_by_two;

    /* Sum: '<S125>/add_c' */
    Sig_Vgamma_m = (0.0F - rtb_one_by_two) - rtb_convert_pu;

    /* End of Outputs for SubSystem: '<S9>/Inverse Clarke Transform' */

    /* Outputs for Atomic SubSystem: '<S9>/Space Vector Generator' */
    /* Gain: '<S126>/one_by_sqrt3' */
    rtb_Add_m = 0.577350259F * Sig_Va_m;

    /* Sum: '<S126>/a' */
    rtb_a = rtb_Add_m + rtb_Add_m;

    /* Sum: '<S126>/b' */
    rtb_convert_pu = Sig_Vb_m - rtb_Add_m;

    /* Sum: '<S126>/c' */
    rtb_Add_m = (0.0F - rtb_Add_m) - Sig_Vb_m;

    /* Gain: '<S126>/one_by_two' incorporates:
     *  MinMax: '<S126>/Max'
     *  MinMax: '<S126>/Min'
     *  Sum: '<S126>/Add'
     */
    rtb_one_by_two = (fmaxf(fmaxf(rtb_a, rtb_convert_pu), rtb_Add_m) + fminf
                      (fminf(rtb_a, rtb_convert_pu), rtb_Add_m)) * 0.5F;

    /* End of Outputs for SubSystem: '<S9>/Space Vector Generator' */

    /* Switch: '<S9>/Switch' incorporates:
     *  Inport: '<Root>/In1'
     *  Inport: '<S125>/In1'
     *  Sum: '<S126>/Da'
     *  Sum: '<S126>/Db'
     *  Switch: '<S9>/Switch1'
     */
    if (Sig_change_SVMalgorithm) {
      /* Outputs for Atomic SubSystem: '<S9>/Inverse Clarke Transform' */
      Sig_Valpha_m = Sig_Va_m;

      /* End of Outputs for SubSystem: '<S9>/Inverse Clarke Transform' */
    } else {
      /* Outputs for Atomic SubSystem: '<S9>/Space Vector Generator' */
      Sig_Valpha_m = rtb_a - rtb_one_by_two;
      Sig_Vbeta_m = rtb_convert_pu - rtb_one_by_two;

      /* End of Outputs for SubSystem: '<S9>/Space Vector Generator' */
    }

    /* End of Switch: '<S9>/Switch' */

    /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
     *  Lookup_n-D: '<S9>/1-D Lookup Table'
     */
    set_PWM_A_DT(look1_iflftu16Df_binlcpw(Sig_Valpha_m, (&(BrkPoints[0])),
      (&(pwmTableData[0])), 2U));

    /* DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
     *  Lookup_n-D: '<S9>/1-D Lookup Table1'
     */
    set_PWM_B_DT(look1_iflftu16Df_binlcpw(Sig_Vbeta_m, (&(BrkPoints[0])),
      (&(pwmTableData[0])), 2U));

    /* Switch: '<S9>/Switch2' incorporates:
     *  Inport: '<Root>/In1'
     *  Sum: '<S126>/Dc'
     */
    if (!Sig_change_SVMalgorithm) {
      /* Outputs for Atomic SubSystem: '<S9>/Space Vector Generator' */
      Sig_Vgamma_m = rtb_Add_m - rtb_one_by_two;

      /* End of Outputs for SubSystem: '<S9>/Space Vector Generator' */
    }

    /* End of Switch: '<S9>/Switch2' */

    /* DataTypeConversion: '<S9>/Data Type Conversion2' incorporates:
     *  Lookup_n-D: '<S9>/1-D Lookup Table2'
     */
    set_PWM_C_DT(look1_iflftu16Df_binlcpw(Sig_Vgamma_m, (&(BrkPoints[0])),
      (&(pwmTableData[0])), 2U));

    /* Outputs for Atomic SubSystem: '<Root>/Start up' */
    /* CombinatorialLogic: '<S148>/Logic' incorporates:
     *  Constant: '<Root>/q Soll'
     *  Memory: '<S148>/Memory'
     *  RelationalOperator: '<S144>/Compare'
     *  SignalConversion: '<Root>/Signal Copy'
     *  UnitDelay: '<S142>/Unit Delay'
     */
    Sig_cos_m_tmp = (int32_T)(((((uint32_T)(qSoll == 0) << 1) +
      MotorControlLib_DW.UnitDelay_DSTATE_e) << 1) +
      MotorControlLib_DW.Memory_PreviousInput);

    /* UnitDelay: '<S145>/Delay Input1'
     *
     * Block description for '<S145>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator = MotorControlLib_DW.DelayInput1_DSTATE_f;

    /* UnitDelay: '<S142>/Unit Delay1' incorporates:
     *  UnitDelay: '<S145>/Delay Input1'
     *
     * Block description for '<S145>/Delay Input1':
     *
     *  Store in Global RAM
     */
    MotorControlLib_DW.DelayInput1_DSTATE_f =
      MotorControlLib_DW.UnitDelay1_DSTATE_m;

    /* RelationalOperator: '<S145>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S145>/Delay Input1'
     *
     * Block description for '<S145>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator = ((int32_T)
      MotorControlLib_DW.DelayInput1_DSTATE_f < (int32_T)
      rtb_FixPtRelationalOperator);

    /* Outputs for Enabled SubSystem: '<S142>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S146>/Enable'
     */
    /* CombinatorialLogic: '<S148>/Logic' */
    if (rtCP_Logic_table[(uint32_T)Sig_cos_m_tmp]) {
      /* RelationalOperator: '<S150>/FixPt Relational Operator' incorporates:
       *  Constant: '<Root>/q Soll'
       *  SignalConversion: '<Root>/Signal Copy'
       *  UnitDelay: '<S150>/Delay Input1'
       *
       * Block description for '<S150>/Delay Input1':
       *
       *  Store in Global RAM
       */
      MotorControlLib_B.FixPtRelationalOperator = (qSoll !=
        MotorControlLib_DW.DelayInput1_DSTATE);

      /* Update for UnitDelay: '<S150>/Delay Input1' incorporates:
       *  Constant: '<Root>/q Soll'
       *  SignalConversion: '<Root>/Signal Copy'
       *
       * Block description for '<S150>/Delay Input1':
       *
       *  Store in Global RAM
       */
      MotorControlLib_DW.DelayInput1_DSTATE = qSoll;
    }

    /* End of Outputs for SubSystem: '<S142>/Enabled Subsystem' */

    /* Memory: '<S149>/Memory' incorporates:
     *  UnitDelay: '<S142>/Unit Delay'
     */
    MotorControlLib_DW.UnitDelay_DSTATE_e =
      MotorControlLib_DW.Memory_PreviousInput_b;

    /* CombinatorialLogic: '<S149>/Logic' incorporates:
     *  UnitDelay: '<S142>/Unit Delay'
     */
    rowIdx = (int32_T)(((((uint32_T)MotorControlLib_B.FixPtRelationalOperator <<
                          1) + rtb_FixPtRelationalOperator) << 1) +
                       MotorControlLib_DW.UnitDelay_DSTATE_e);

    /* Outputs for Enabled SubSystem: '<S142>/Enabled Subsystem1' incorporates:
     *  EnablePort: '<S147>/Enable'
     */
    if (rtCP_Logic_table_m[(uint32_T)rowIdx]) {
      /* UnitDelay: '<S147>/Unit Delay1' */
      rtb_uDLookupTable2 = MotorControlLib_DW.UnitDelay1_DSTATE_o;

      /* Sum: '<S147>/Add' incorporates:
       *  Constant: '<S147>/Constant'
       *  UnitDelay: '<S147>/Unit Delay1'
       */
      MotorControlLib_DW.UnitDelay1_DSTATE_o++;

      /* RelationalOperator: '<S147>/Relational Operator' incorporates:
       *  Constant: '<S147>/Constant1'
       *  UnitDelay: '<S142>/Unit Delay1'
       */
      MotorControlLib_DW.UnitDelay1_DSTATE_m = (rtb_uDLookupTable2 <= 10000);
    }

    /* End of Outputs for SubSystem: '<S142>/Enabled Subsystem1' */

    /* UnitDelay: '<S143>/Unit Delay' */
    rtb_FixPtRelationalOperator = MotorControlLib_DW.UnitDelay_DSTATE_p;

    /* DiscreteIntegrator: '<S143>/Discrete-Time Integrator' incorporates:
     *  UnitDelay: '<S143>/Unit Delay'
     */
    if (MotorControlLib_DW.UnitDelay_DSTATE_p &&
        (MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE = 0;
    }

    constantAngle = MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S143>/Discrete-Time Integrator' */

    /* Abs: '<S143>/Abs' */
    if (constantAngle < 0) {
      tmp = (int16_T)-constantAngle;
    } else {
      tmp = constantAngle;
    }

    /* End of Abs: '<S143>/Abs' */

    /* RelationalOperator: '<S143>/Relational Operator' incorporates:
     *  UnitDelay: '<S143>/Unit Delay'
     */
    MotorControlLib_DW.UnitDelay_DSTATE_p = (tmp >= 1608);

    /* Update for UnitDelay: '<S142>/Unit Delay' incorporates:
     *  CombinatorialLogic: '<S149>/Logic'
     */
    MotorControlLib_DW.UnitDelay_DSTATE_e = rtCP_Logic_table_m[(uint32_T)rowIdx];

    /* Update for Memory: '<S148>/Memory' incorporates:
     *  CombinatorialLogic: '<S148>/Logic'
     */
    MotorControlLib_DW.Memory_PreviousInput = rtCP_Logic_table[(uint32_T)
      Sig_cos_m_tmp];

    /* Update for Memory: '<S149>/Memory' incorporates:
     *  CombinatorialLogic: '<S149>/Logic'
     */
    MotorControlLib_DW.Memory_PreviousInput_b = rtCP_Logic_table_m[(uint32_T)
      rowIdx];

    /* Update for DiscreteIntegrator: '<S143>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/Inport4'
     */
    MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE = (int16_T)(((6711 * dth_dt)
      >> 17) + MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE);
    MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      rtb_FixPtRelationalOperator;

    /* End of Outputs for SubSystem: '<Root>/Start up' */
  }

  /* RateTransition: '<Root>/Rate Transition3' incorporates:
   *  SignalConversion generated from: '<S6>/Enable'
   */
  if (MotorControlLib_M->Timing.TaskCounters.TID[1] == 0) {
    /* RateTransition: '<Root>/Rate Transition2' incorporates:
     *  RateTransition: '<Root>/Rate Transition4'
     */
    if (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0) {
      MotorControlLib_B.RateTransition3 =
        MotorControlLib_DW.RateTransition3_Buffer0;
      MotorControlLib_B.RateTransition2 =
        MotorControlLib_DW.RateTransition2_Buffer0;
      MotorControlLib_B.RateTransition4 =
        MotorControlLib_DW.RateTransition4_Buffer0;
    }

    /* End of RateTransition: '<Root>/Rate Transition2' */

    /* Outputs for Enabled SubSystem: '<Root>/FluxObserver' */
    MotorControlLib_FluxObserver(MotorControlLib_B.RateTransition4,
      MotorControlLib_B.RateTransition3, MotorControlLib_B.RateTransition2,
      Sig_Ia_m, Sig_Ibeta_m, &FluxObsAngle, &MotorControlLib_B.FluxObserver,
      &MotorControlLib_ConstB.FluxObserver, &MotorControlLib_DW.FluxObserver,
      &MotorControlLib_PrevZCX.FluxObserver);

    /* End of Outputs for SubSystem: '<Root>/FluxObserver' */

    /* RateTransition: '<Root>/Rate Transition1' incorporates:
     *  SignalConversion generated from: '<S6>/Enable'
     */
    if (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0) {
      MotorControlLib_DW.RateTransition1_Buffer = FluxObsAngle;
    }
  }

  /* End of RateTransition: '<Root>/Rate Transition3' */

  /* RateTransition: '<Root>/Rate Transition1' */
  if (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0) {
    rtb_RateTransition1 = MotorControlLib_DW.RateTransition1_Buffer;
  }

  /* Outputs for Enabled SubSystem: '<Root>/Position observer' */
  /* Inport: '<Root>/Inport3' incorporates:
   *  Inport: '<Root>/Inport5'
   */
  MotorControlLi_Positionobserver(MotorControlLib_M, enablePositionObs,
    MotorControlLib_B.RateTransition3, MotorControlLib_B.RateTransition2,
    Sig_Ia_m, Sig_Ibeta_m, resetPIIntegrator, &PositionObsAnlge,
    &MotorControlLib_B.Positionobserver, &MotorControlLib_DW.Positionobserver,
    &MotorControlLib_PrevZCX.Positionobserver);

  /* End of Outputs for SubSystem: '<Root>/Position observer' */
  if (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0) {
    /* ModelReference: '<Root>/PWM angle decoder' incorporates:
     *  Inport: '<Root>/Input'
     *  Inport: '<Root>/Input1'
     */
    ConvertPWMtoAngle();

    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Delay: '<Root>/Delay'
     *  Inport: '<Root>/Inport1'
     */
    switch (set_AngleInput) {
     case 0:
      MotorControlLib_Y.Position = (real32_T)constantAngle * 0.00390625F;
      break;

     case 1:
      MotorControlLib_Y.Position = (real32_T)rtb_RateTransition1 * 0.00390625F;
      break;

     case 2:
      MotorControlLib_Y.Position = (real32_T)PositionObsAnlge * 0.00390625F;
      break;

     default:
      MotorControlLib_Y.Position = Angle_sensor_in;
      break;
    }

    /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

    /* Sum: '<S12>/Add' incorporates:
     *  Abs: '<S12>/Abs'
     *  Delay: '<Root>/Delay'
     *  Sum: '<S12>/Add1'
     *  UnitDelay: '<S12>/Unit Delay1'
     */
    rtb_Add_m = fabsf(MotorControlLib_Y.Position -
                      MotorControlLib_DW.UnitDelay1_DSTATE) +
      Sig_Theta_el_cont_m;

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S141>/Constant'
     *  RelationalOperator: '<S141>/Compare'
     */
    if (rtb_Add_m > 400000.0F) {
      Sig_Theta_el_cont_m = 0.0F;
    } else {
      Sig_Theta_el_cont_m = rtb_Add_m;
    }

    /* End of Switch: '<S12>/Switch' */

    /* SignalConversion generated from: '<Root>/Vector Concatenate' */
    rtb_VectorConcatenate[0] = Sig_Ia_m;

    /* SignalConversion generated from: '<Root>/Vector Concatenate' */
    rtb_VectorConcatenate[1] = Sig_Ib_m;

    /* ModelReference: '<Root>/SafetyChecks' */
    SafetyChecks(&rtb_VectorConcatenate[0],
                 &(MotorControlLib_DW.SafetyChecks_InstanceData.rtdw));

    /* RelationalOperator: '<S3>/Compare' */
    Sig_qSollIsNegative = (qSoll < 0);

    /* Update for RateTransition: '<Root>/Rate Transition3' */
    MotorControlLib_DW.RateTransition3_Buffer0 = rtb_Switch_p[0];

    /* Update for RateTransition: '<Root>/Rate Transition2' */
    MotorControlLib_DW.RateTransition2_Buffer0 = rtb_Switch_p[1];

    /* Update for RateTransition: '<Root>/Rate Transition4' incorporates:
     *  Inport: '<Root>/Inport2'
     */
    MotorControlLib_DW.RateTransition4_Buffer0 = enableFluxObs;

    /* Update for UnitDelay: '<S12>/Unit Delay1' incorporates:
     *  Delay: '<Root>/Delay'
     */
    MotorControlLib_DW.UnitDelay1_DSTATE = MotorControlLib_Y.Position;
  }

  rate_scheduler();
}

/* Model initialize function */
void MotorControlLib_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* external inputs */
  set_AngleInput = 3U;
  dth_dt = 210;
  Sig_change_SVMalgorithm = true;

  /* Model Initialize function for ModelReference Block: '<Root>/ADCRAwToCurrent(Iabc)' */
  ADCRawToIab_initialize(rtmGetErrorStatusPointer(MotorControlLib_M),
    &(MotorControlLib_DW.ADCRAwToCurrentIabc_InstanceDat.rtm));

  /* Model Initialize function for ModelReference Block: '<Root>/PWM angle decoder' */
  ConvertPWMtoAngle_initialize(rtmGetErrorStatusPointer(MotorControlLib_M),
    &(MotorControlLib_DW.PWMangledecoder_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<Root>/SafetyChecks' */
  SafetyChecks_initialize(rtmGetErrorStatusPointer(MotorControlLib_M),
    &(MotorControlLib_DW.SafetyChecks_InstanceData.rtm));
  MotorControlLib_PrevZCX.Positionobserver.Delay1_Reset_ZCE_j =
    UNINITIALIZED_ZCSIG;
  MotorControlLib_PrevZCX.Positionobserver.Delay1_Reset_ZCE =
    UNINITIALIZED_ZCSIG;
  MotorControlLib_PrevZCX.FluxObserver.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
  MotorControlLib_PrevZCX.FluxObserver.Delay_Reset_ZCE_o = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Start up' */
  /* InitializeConditions for DiscreteIntegrator: '<S143>/Discrete-Time Integrator' */
  MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* End of SystemInitialize for SubSystem: '<Root>/Start up' */
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
