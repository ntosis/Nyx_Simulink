/*
 * File: MotorControlLib.c
 *
 * Code generated for Simulink model 'MotorControlLib'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Fri Oct 28 10:27:56 2022
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
boolean_T resetPIIntegratorDQ;         /* '<Root>/Inport6' */
boolean_T enableFluxObs;               /* '<Root>/Inport2' */
uint8_T set_AngleInput;                /* '<Root>/Inport1' */
boolean_T enablePositionObs;           /* '<Root>/Inport3' */
int16_T dth_dt;                        /* '<Root>/Inport4' */
boolean_T resetPIIntegrator;           /* '<Root>/Inport5' */
boolean_T Sig_change_SVMalgorithm;     /* '<Root>/In1' */
real32_T Sig_Ia_m;                     /* '<Root>/ADCRAwToCurrent(Iabc)' */
real32_T Sig_Ib_m;                     /* '<Root>/ADCRAwToCurrent(Iabc)' */
real32_T Sig_cos_m;                    /* '<S15>/Sum6' */
real32_T Sig_Ibeta_m;                  /* '<S1>/one_by_sqrt3' */
real32_T Sig_sin_m;                    /* '<S15>/Sum4' */
real32_T Sig_Iq_Soll;                  /* '<S13>/Tq--> iqRef' */
real32_T Sig_dAxis_m;                  /* '<Root>/Gain2' */
real32_T Sig_qAxis_m;                  /* '<Root>/Gain3' */
real32_T Sig_Vqsatu_m;                 /* '<Root>/DQ_Limiter' */
real32_T Sig_Vdsatu_m;                 /* '<Root>/DQ_Limiter' */
real32_T Sig_Va_m;                     /* '<Root>/Gain' */
real32_T Sig_Vb_m;                     /* '<Root>/Gain1' */
real32_T Sig_Valpha_m;                 /* '<S7>/Switch' */
real32_T Sig_Vbeta_m;                  /* '<S7>/Switch1' */
real32_T Sig_Vgamma_m;                 /* '<S7>/Switch2' */
real32_T Sig_Theta_el_cont_m;          /* '<S10>/Switch' */
real32_T Sig_dAxis_errorSum_m;         /* '<S6>/Add' */
real32_T Sig_qAxis_errorSum_m;         /* '<S6>/Add1' */
int16_T constantAngle;                 /* '<S144>/Discrete-Time Integrator' */
int16_T PositionObsAnlge;              /* '<S129>/Data Type Conversion5' */
int16_T FluxObsAngle;                  /* '<S20>/PositionGain' */
real32_T Sig_Emfobs_errorSum_m;        /* '<S130>/Add6' */
real32_T Sig_Emfobs_PI_out;            /* '<S137>/Saturation' */
real32_T di_dt_E9;                     /* '<S136>/Inductance' */
real32_T di_dt_times_Ts_En8;           /* '<S136>/Gain' */
real32_T i_integrated_en4;             /* '<S136>/Sum' */
real32_T i_integrated_times_Rs_en8;    /* '<S136>/Resistance' */
real32_T Va_all_16En4;                 /* '<S136>/Add5' */
int16_T Sig_First_LPF_out;             /* '<S132>/Product1'
                                        * 16En6
                                        */
int16_T Sig_Second_LPF_out;            /* '<S133>/Product1'
                                        * 16En6
                                        */
real32_T Sig_theta_el_m;

/* Exported block parameters */
real32_T TsIntern = 5.0E-5F;           /* Variable: TsIntern
                                        * Referenced by:
                                        *   '<S136>/Gain'
                                        *   '<S139>/Gain'
                                        * fixdt(0,32,2^-24,0)
                                        */
int16_T MaxBckEMFVol_sat_neg = -48;    /* Variable: MaxBckEMFVol_sat_neg
                                        * Referenced by:
                                        *   '<S137>/Saturation'
                                        *   '<S140>/Saturation'
                                        * fixdt(1,16,2^-2,0)
                                        */
int16_T MaxBckEMFVol_sat_pos = 48;     /* Variable: MaxBckEMFVol_sat_pos
                                        * Referenced by:
                                        *   '<S137>/Saturation'
                                        *   '<S140>/Saturation'
                                        * fixdt(1,32,2^-8,0)
                                        */
int16_T Ki_Iab_EMFobs = 0;             /* Variable: Ki_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S138>/Ki'
                                        *   '<S141>/Ki'
                                        * fixdt(1,16,2^-3,0)
                                        */
int16_T d_q_Voltage_Limiter_max = 92;  /* Variable: d_q_Voltage_Limiter_max
                                        * Referenced by: '<Root>/DQ_Limiter'
                                        * =12/sqrt(3)
                                        */
uint16_T Ki_dAxis = 5760;                /* Variable: Ki_dAxis
                                        * Referenced by: '<S6>/Constant7'
                                        * fixdt(1,16,2^-5,0)
                                        */
uint16_T Ki_qAxis = 5600;                  /* Variable: Ki_qAxis
                                        * Referenced by: '<S6>/Constant5'
                                        * fixdt(1,16,2^-5,0)
                                        */
uint16_T Kp_dAxis = 150;                 /* Variable: Kp_dAxis
                                        * Referenced by: '<S6>/Constant6'
                                        * fixdt(1,16,2^-5,0)
                                        */
uint16_T Kp_qAxis = 150;                 /* Variable: Kp_qAxis
                                        * Referenced by: '<S6>/Constant4'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Kp_Iab_EMFobs = 256;           /* Variable: Kp_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S137>/Kp'
                                        *   '<S140>/Kp'
                                        * fixdt(1,16,2^-8,0)
                                        */
int16_T qSoll = 0;                     /* Variable: qSoll
                                        * Referenced by: '<Root>/q Soll'
                                        * fixdt(1,16,2^-8,0)
                                        */
uint16_T MaximumCurrentBeforeReaction = 4864U;/* Variable: MaximumCurrentBeforeReaction
                                               * Referenced by: '<Root>/SafetyChecks'
                                               * Maximum current limit before softare shutdowns the mosfets.
                                               */
uint16_T CuttOffFreq_c = 4000U;        /* Variable: CuttOffFreq_c
                                        * Referenced by:
                                        *   '<S132>/Constant'
                                        *   '<S133>/Constant'
                                        *   '<S134>/Constant'
                                        *   '<S135>/Constant'
                                        */
int16_T d_q_Voltage_Limiter_sat_neg = -160;
int16_T d_q_Voltage_Limiter_sat_pos = 160;

float Sig_dAxis_PI_out;      /* '<S111>/Saturation' */
float Sig_qAxis_PI_out;      /* '<S67>/Saturation' */
/* Exported block states */
real32_T UnitDelayIntegratorPosObs;    /* '<S136>/Delay' */

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

  /* Sum: '<S3>/Sum2' incorporates:
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product1'
   */
  *rty_Vmax_unsat = rtu_Vd_ref * rtu_Vd_ref + rtu_Vq_ref * rtu_Vq_ref;

  /* Sqrt: '<S3>/Sqrt' */
  *rty_Vmax_unsat = sqrtf(*rty_Vmax_unsat);

  /* Switch: '<S3>/Switch' incorporates:
   *  Gain: '<S3>/Gain'
   *  Math: '<S3>/Math Function2'
   *  Product: '<S3>/Product2'
   *
   * About '<S3>/Math Function2':
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

  /* End of Switch: '<S3>/Switch' */
}

/* Output and update for enable system: '<Root>/Flux_observer' */
void MotorControlLib_Flux_observer(boolean_T rtu_Enable, real32_T rtu_In1,
  real32_T rtu_In2, real32_T rtu_In3, real32_T rtu_In4, int16_T
  *rty_FluxObsAngle, B_Flux_observer_MotorControlL_T *localB, const
  ConstB_Flux_observer_MotorCon_T *localC, DW_Flux_observer_MotorControl_T
  *localDW, ZCE_Flux_observer_MotorContro_T *localZCE)
{
  real32_T rtb_Atan2;

  /* Outputs for Enabled SubSystem: '<Root>/Flux_observer' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (rtu_Enable) {
    /* Outputs for Atomic SubSystem: '<S4>/Flux Observer' */
    /* Delay: '<S23>/Delay' */
    if ((localZCE->Delay_Reset_ZCE == POS_ZCSIG) && (localZCE->Delay_Reset_ZCE
         != UNINITIALIZED_ZCSIG)) {
      localDW->Delay_DSTATE = 0.0F;
    }

    localZCE->Delay_Reset_ZCE = 0U;

    /* Sum: '<S23>/Sum' incorporates:
     *  Delay: '<S23>/Delay'
     *  Gain: '<S23>/Gain'
     *  Gain: '<S29>/ScalingR'
     *  Sum: '<S23>/Sum3'
     */
    localDW->Delay_DSTATE += (rtu_In2 - EMFobsRS * rtu_In4) * 9.99998301E-5F;

    /* Delay: '<S22>/Delay' */
    if ((localZCE->Delay_Reset_ZCE_o == POS_ZCSIG) &&
        (localZCE->Delay_Reset_ZCE_o != UNINITIALIZED_ZCSIG)) {
      localDW->Delay_DSTATE_e = 0.0F;
    }

    localZCE->Delay_Reset_ZCE_o = 0U;

    /* Sum: '<S22>/Sum' incorporates:
     *  Delay: '<S22>/Delay'
     *  Gain: '<S22>/Gain'
     *  Gain: '<S28>/ScalingR'
     *  Sum: '<S22>/Sum3'
     */
    localDW->Delay_DSTATE_e += (rtu_In1 - EMFobsRS * rtu_In3) * 9.99998301E-5F;

    /* Outputs for Atomic SubSystem: '<S20>/atan2' */
    /* Trigonometry: '<S21>/Atan2' incorporates:
     *  Delay: '<S22>/Delay'
     *  Delay: '<S23>/Delay'
     *  Gain: '<S28>/ScalingL'
     *  Gain: '<S29>/ScalingL'
     *  Sum: '<S22>/Sum1'
     *  Sum: '<S23>/Sum1'
     *  Switch: '<S22>/Switch'
     *  Switch: '<S23>/Switch'
     */
    rtb_Atan2 = rt_atan2f_snf(localDW->Delay_DSTATE - EMFobsLdGain * rtu_In4,
      localDW->Delay_DSTATE_e - EMFobsLdGain * rtu_In3);

    /* Outputs for Enabled SubSystem: '<S21>/If Action Subsystem' incorporates:
     *  EnablePort: '<S26>/Enable'
     */
    if (localC->Compare) {
      /* Inport: '<S26>/In1' */
      localB->Merge = rtb_Atan2;
    }

    /* End of Outputs for SubSystem: '<S21>/If Action Subsystem' */

    /* Outputs for Enabled SubSystem: '<S21>/per Uint' incorporates:
     *  EnablePort: '<S27>/Enable'
     */
    if (localC->Compare_l) {
      /* Gain: '<S27>/Gain' */
      localB->Merge = 0.159154937F * rtb_Atan2;

      /* Switch: '<S27>/Switch' incorporates:
       *  Bias: '<S27>/Bias'
       */
      if (!(localB->Merge >= 0.0F)) {
        localB->Merge++;
      }

      /* End of Switch: '<S27>/Switch' */
    }

    /* End of Outputs for SubSystem: '<S21>/per Uint' */

    /* Gain: '<S20>/PositionGain' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S21>/a16'
     */
    rtb_Atan2 = truncf(6.28318548F * localB->Merge * 256.0F);

    /* End of Outputs for SubSystem: '<S20>/atan2' */
    if (rtIsNaNF(rtb_Atan2) || rtIsInfF(rtb_Atan2)) {
      rtb_Atan2 = 0.0F;
    } else {
      rtb_Atan2 = fmodf(rtb_Atan2, 65536.0F);
    }

    *rty_FluxObsAngle = (int16_T)(rtb_Atan2 < 0.0F ? (int32_T)(int16_T)-(int16_T)
      (uint16_T)-rtb_Atan2 : (int32_T)(int16_T)(uint16_T)rtb_Atan2);

    /* End of Gain: '<S20>/PositionGain' */
    /* End of Outputs for SubSystem: '<S4>/Flux Observer' */
  }

  /* End of Outputs for SubSystem: '<Root>/Flux_observer' */
}

/* Output and update for atomic system: '<S6>/PI DAxis' */
real32_T MotorControlLib_PIDAxis(real32_T rtu_error, int16_T rtu_P, int16_T
  rtu_I, boolean_T rtu_Reset, DW_PIDAxis_MotorControlLib_T *localDW)
{
  real32_T rty_PIDOut_0;
  real32_T rtb_IProdOut;
  real32_T rtb_ZeroGain;
  real32_T rtb_DeadZone;
  real32_T u1;
  real32_T u2;

  /* Product: '<S61>/IProd Out' incorporates:
   *  DataTypeConversion: '<S31>/Data Type Conversion'
   */
  rtb_IProdOut = (real32_T)rtu_I * 0.03125F * rtu_error;

  /* DiscreteIntegrator: '<S64>/Integrator' */
  if (rtu_Reset || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = 0.0F;
  }
  PI_d_Integrator =localDW->Integrator_DSTATE;
  /* Sum: '<S73>/Sum' incorporates:
   *  DataTypeConversion: '<S31>/Data Type Conversion3'
   *  DiscreteIntegrator: '<S64>/Integrator'
   *  Product: '<S69>/PProd Out'
   */
  rty_PIDOut_0 = (real32_T)rtu_P * 9.765625e-4F * rtu_error +
    localDW->Integrator_DSTATE;

  /* DeadZone: '<S57>/DeadZone' incorporates:
   *  Saturate: '<S71>/Saturation'
   */
  u2 = (real32_T)d_q_Voltage_Limiter_sat_pos * 0.0625F;
  if (rty_PIDOut_0 > u2) {
    rtb_DeadZone = rty_PIDOut_0 - u2;
  } else {
    u1 = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
    if (rty_PIDOut_0 >= u1) {
      rtb_DeadZone = 0.0F;
    } else {
      rtb_DeadZone = rty_PIDOut_0 - u1;
    }
  }

  /* End of DeadZone: '<S57>/DeadZone' */

  /* Gain: '<S57>/ZeroGain' */
  rtb_ZeroGain = 0.0F * rty_PIDOut_0;

  /* Saturate: '<S71>/Saturation' */
  u1 = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
  if (rty_PIDOut_0 > u2) {
    rty_PIDOut_0 = u2;
  } else {
    if (rty_PIDOut_0 < u1) {
      rty_PIDOut_0 = u1;
    }
  }

  /* End of Saturate: '<S71>/Saturation' */

  /* Signum: '<S57>/SignPreSat' */
  if (rtb_DeadZone < 0.0F) {
    /* DataTypeConversion: '<S57>/DataTypeConv1' */
    u1 = -1.0F;
  } else if (rtb_DeadZone > 0.0F) {
    /* DataTypeConversion: '<S57>/DataTypeConv1' */
    u1 = 1.0F;
  } else if (rtb_DeadZone == 0.0F) {
    /* DataTypeConversion: '<S57>/DataTypeConv1' */
    u1 = 0.0F;
  } else {
    /* DataTypeConversion: '<S57>/DataTypeConv1' */
    u1 = (rtNaNF);
  }

  /* End of Signum: '<S57>/SignPreSat' */

  /* DataTypeConversion: '<S57>/DataTypeConv1' */
  if (rtIsNaNF(u1)) {
    u1 = 0.0F;
  } else {
    u1 = fmodf(u1, 256.0F);
  }

  /* Signum: '<S57>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0F) {
    /* DataTypeConversion: '<S57>/DataTypeConv2' */
    u2 = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    /* DataTypeConversion: '<S57>/DataTypeConv2' */
    u2 = 1.0F;
  } else if (rtb_IProdOut == 0.0F) {
    /* DataTypeConversion: '<S57>/DataTypeConv2' */
    u2 = 0.0F;
  } else {
    /* DataTypeConversion: '<S57>/DataTypeConv2' */
    u2 = (rtNaNF);
  }

  /* End of Signum: '<S57>/SignPreIntegrator' */

  /* DataTypeConversion: '<S57>/DataTypeConv2' */
  if (rtIsNaNF(u2)) {
    u2 = 0.0F;
  } else {
    u2 = fmodf(u2, 256.0F);
  }

  /* Switch: '<S57>/Switch' incorporates:
   *  Constant: '<S57>/Constant1'
   *  DataTypeConversion: '<S57>/DataTypeConv1'
   *  DataTypeConversion: '<S57>/DataTypeConv2'
   *  Logic: '<S57>/AND3'
   *  RelationalOperator: '<S57>/Equal1'
   *  RelationalOperator: '<S57>/NotEqual'
   */
  if ((rtb_ZeroGain != rtb_DeadZone) && ((u1 < 0.0F ? (int32_T)(int8_T)-(int8_T)
        (uint8_T)-u1 : (int32_T)(int8_T)(uint8_T)u1) == (u2 < 0.0F ? (int32_T)
        (int8_T)-(int8_T)(uint8_T)-u2 : (int32_T)(int8_T)(uint8_T)u2))) {
    rtb_IProdOut = 0.0F;
  }

  /* End of Switch: '<S57>/Switch' */

  /* Update for DiscreteIntegrator: '<S64>/Integrator' */
  localDW->Integrator_DSTATE += 0.0002F * rtb_IProdOut;
  localDW->Integrator_PrevResetState = (int8_T)rtu_Reset;
  Sig_dAxis_PI_out = rty_PIDOut_0;
  return rty_PIDOut_0;
}

/* Output and update for atomic system: '<S6>/PI Qaxis' */
real32_T MotorControlLib_PIQaxis(real32_T rtu_error, real32_T rtu_P, real32_T
  rtu_I, boolean_T rtu_Reset, DW_PIQaxis_MotorControlLib_T *localDW)
{
  real32_T rty_PIDOut_0;
  real32_T rtb_IProdOut;
  boolean_T rtb_NotEqual_c;
  real32_T u1;
  real32_T u2;
  real32_T tmp;

  /* DiscreteIntegrator: '<S109>/Integrator' */
  if (rtu_Reset || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = 0.0F;
  }
  PI_q_Integrator = localDW->Integrator_DSTATE;
  /* Sum: '<S118>/Sum' incorporates:
   *  DiscreteIntegrator: '<S109>/Integrator'
   *  Product: '<S114>/PProd Out'
   */
  rty_PIDOut_0 = rtu_error * rtu_P + localDW->Integrator_DSTATE;

  /* DeadZone: '<S102>/DeadZone' incorporates:
   *  Saturate: '<S116>/Saturation'
   */
  u2 = (real32_T)d_q_Voltage_Limiter_sat_pos * 0.0625F;
  if (rty_PIDOut_0 > u2) {
    rtb_IProdOut = rty_PIDOut_0 - u2;
  } else {
    tmp = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
    if (rty_PIDOut_0 >= tmp) {
      rtb_IProdOut = 0.0F;
    } else {
      rtb_IProdOut = rty_PIDOut_0 - tmp;
    }
  }

  /* End of DeadZone: '<S102>/DeadZone' */

  /* RelationalOperator: '<S102>/NotEqual' incorporates:
   *  Gain: '<S102>/ZeroGain'
   */
  rtb_NotEqual_c = (0.0F * rty_PIDOut_0 != rtb_IProdOut);

  /* Signum: '<S102>/SignPreSat' */
  if (rtb_IProdOut < 0.0F) {
    rtb_IProdOut = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    rtb_IProdOut = 1.0F;
  } else if (rtb_IProdOut == 0.0F) {
    rtb_IProdOut = 0.0F;
  } else {
    rtb_IProdOut = (rtNaNF);
  }

  /* End of Signum: '<S102>/SignPreSat' */

  /* DataTypeConversion: '<S102>/DataTypeConv1' */
  if (rtIsNaNF(rtb_IProdOut)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(rtb_IProdOut, 256.0F);
  }

  /* Product: '<S106>/IProd Out' */
  rtb_IProdOut = rtu_error * rtu_I;

  /* Saturate: '<S116>/Saturation' */
  u1 = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
  if (rty_PIDOut_0 > u2) {
    rty_PIDOut_0 = u2;
  } else {
    if (rty_PIDOut_0 < u1) {
      rty_PIDOut_0 = u1;
    }
  }

  /* End of Saturate: '<S116>/Saturation' */

  /* Signum: '<S102>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0F) {
    /* DataTypeConversion: '<S102>/DataTypeConv2' */
    u2 = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    /* DataTypeConversion: '<S102>/DataTypeConv2' */
    u2 = 1.0F;
  } else if (rtb_IProdOut == 0.0F) {
    /* DataTypeConversion: '<S102>/DataTypeConv2' */
    u2 = 0.0F;
  } else {
    /* DataTypeConversion: '<S102>/DataTypeConv2' */
    u2 = (rtNaNF);
  }

  /* End of Signum: '<S102>/SignPreIntegrator' */

  /* DataTypeConversion: '<S102>/DataTypeConv2' */
  if (rtIsNaNF(u2)) {
    u2 = 0.0F;
  } else {
    u2 = fmodf(u2, 256.0F);
  }

  /* Switch: '<S102>/Switch' incorporates:
   *  Constant: '<S102>/Constant1'
   *  DataTypeConversion: '<S102>/DataTypeConv1'
   *  DataTypeConversion: '<S102>/DataTypeConv2'
   *  Logic: '<S102>/AND3'
   *  RelationalOperator: '<S102>/Equal1'
   */
  if (rtb_NotEqual_c && ((int8_T)(tmp < 0.0F ? (int32_T)(int8_T)-(int8_T)
        (uint8_T)-tmp : (int32_T)(int8_T)(uint8_T)tmp) == (u2 < 0.0F ? (int32_T)
        (int8_T)-(int8_T)(uint8_T)-u2 : (int32_T)(int8_T)(uint8_T)u2))) {
    rtb_IProdOut = 0.0F;
  }

  /* End of Switch: '<S102>/Switch' */

  /* Update for DiscreteIntegrator: '<S109>/Integrator' */
  localDW->Integrator_DSTATE += 0.0002F * rtb_IProdOut;
  localDW->Integrator_PrevResetState = (int8_T)rtu_Reset;
  Sig_qAxis_PI_out = rty_PIDOut_0;
  return rty_PIDOut_0;
}

/* System reset for enable system: '<Root>/Position observer' */
void MotorCon_Positionobserver_Reset(DW_Positionobserver_MotorCont_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S130>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  localDW->UnitDelay_DSTATE_cm = 0;

  /* InitializeConditions for UnitDelay: '<S132>/Unit Delay' */
  localDW->UnitDelay_DSTATE_k = 0;

  /* InitializeConditions for Delay: '<S132>/Delay' */
  localDW->Delay_DSTATE_l = 0;

  /* InitializeConditions for UnitDelay: '<S133>/Unit Delay' */
  localDW->UnitDelay_DSTATE_o = 0;

  /* InitializeConditions for Delay: '<S133>/Delay' */
  localDW->Delay_DSTATE_k = 0;

  /* InitializeConditions for Saturate: '<S140>/Saturation' incorporates:
   *  UnitDelay: '<S131>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE_g = 0;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = 0;

  /* InitializeConditions for UnitDelay: '<S135>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p = 0;

  /* InitializeConditions for Delay: '<S135>/Delay' */
  localDW->Delay_DSTATE_b = 0;

  /* InitializeConditions for UnitDelay: '<S134>/Unit Delay' */
  localDW->UnitDelay_DSTATE_mq = 0;

  /* InitializeConditions for Delay: '<S134>/Delay' */
  localDW->Delay_DSTATE_e = 0;

  /* SystemReset for Atomic SubSystem: '<S130>/DC Motor Model' */
  /* InitializeConditions for UnitDelay: '<S136>/Unit Delay' */
  localDW->UnitDelay_DSTATE_c = 0.0F;

  /* InitializeConditions for Delay: '<S136>/Delay' */
  UnitDelayIntegratorPosObs = 0.0F;

  /* End of SystemReset for SubSystem: '<S130>/DC Motor Model' */

  /* SystemReset for Atomic SubSystem: '<S131>/DC Motor Model' */
  /* InitializeConditions for UnitDelay: '<S139>/Unit Delay' */
  localDW->UnitDelay_DSTATE_m = 0;

  /* InitializeConditions for Delay: '<S139>/Delay' */
  localDW->Delay_DSTATE = 0;

  /* End of SystemReset for SubSystem: '<S131>/DC Motor Model' */
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
   *  EnablePort: '<S9>/Enable'
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
      /* UnitDelay: '<S130>/Unit Delay' */
      localB->UnitDelay = localDW->UnitDelay_DSTATE;

      /* UnitDelay: '<S9>/Unit Delay' */
      localB->UnitDelay_n = localDW->UnitDelay_DSTATE_cm;
    }

    /* Outputs for Atomic SubSystem: '<S130>/DC Motor Model' */
    /* Gain: '<S136>/Inductance' incorporates:
     *  UnitDelay: '<S136>/Unit Delay'
     */
    di_dt_E9 = EMFobsLdGain * localDW->UnitDelay_DSTATE_c;

    /* Gain: '<S136>/Gain' */
    di_dt_times_Ts_En8 = TsIntern * di_dt_E9;

    /* Sum: '<S136>/Sum' incorporates:
     *  Delay: '<S136>/Delay'
     */
    i_integrated_en4 = di_dt_times_Ts_En8 + UnitDelayIntegratorPosObs;

    /* Gain: '<S136>/Resistance' */
    i_integrated_times_Rs_en8 = EMFobsRS * i_integrated_en4;

    /* Sum: '<S136>/Add5' */
    Va_all_16En4 = ((rtu_Va - i_integrated_times_Rs_en8) - localB->UnitDelay) -
      (real32_T)localB->UnitDelay_n * 0.015625F;

    /* Update for UnitDelay: '<S136>/Unit Delay' */
    localDW->UnitDelay_DSTATE_c = Va_all_16En4;

    /* Update for Delay: '<S136>/Delay' */
    UnitDelayIntegratorPosObs = i_integrated_en4;

    /* End of Outputs for SubSystem: '<S130>/DC Motor Model' */
    if (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0) {
      /* Sum: '<S130>/Add6' */
      Sig_Emfobs_errorSum_m = i_integrated_en4 - rtu_Ia;

      /* Outputs for Enabled SubSystem: '<S137>/Anti-windup' incorporates:
       *  EnablePort: '<S138>/Enable'
       */
      /* RelationalOperator: '<S137>/Relational Operator' incorporates:
       *  Abs: '<S137>/Abs'
       *  Constant: '<S137>/Ki activation treashold'
       */
      if (fabsf(Sig_Emfobs_errorSum_m) <= 0.23F) {
        /* Delay: '<S138>/Delay1' */
        if ((((localZCE->Delay1_Reset_ZCE_j == POS_ZCSIG) != (int32_T)rtu_In5) &&
             (localZCE->Delay1_Reset_ZCE_j != UNINITIALIZED_ZCSIG)) || rtu_In5)
        {
          localDW->Delay1_DSTATE_m = 0;
        }

        localZCE->Delay1_Reset_ZCE_j = rtu_In5;

        /* Sum: '<S138>/Sum1' incorporates:
         *  Delay: '<S138>/Delay1'
         *  Gain: '<S138>/Gain1'
         *  Gain: '<S138>/Ki'
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

        /* End of Sum: '<S138>/Sum1' */

        /* Update for Delay: '<S138>/Delay1' */
        localDW->Delay1_DSTATE_m = localB->Sum1_p;
      }

      /* End of RelationalOperator: '<S137>/Relational Operator' */
      /* End of Outputs for SubSystem: '<S137>/Anti-windup' */

      /* Sum: '<S137>/Add1' incorporates:
       *  Gain: '<S137>/Kp'
       */
      Sig_Emfobs_PI_out = (real32_T)Kp_Iab_EMFobs * 0.00390625F *
        Sig_Emfobs_errorSum_m + (real32_T)localB->Sum1_p * 0.00390625F;

      /* Saturate: '<S137>/Saturation' */
      u1 = (real32_T)MaxBckEMFVol_sat_neg * 0.25F;
      rtb_Atan2 = (real32_T)MaxBckEMFVol_sat_pos * 0.25F;
      if (Sig_Emfobs_PI_out > rtb_Atan2) {
        /* Sum: '<S137>/Add1' */
        Sig_Emfobs_PI_out = rtb_Atan2;
      } else {
        if (Sig_Emfobs_PI_out < u1) {
          /* Sum: '<S137>/Add1' */
          Sig_Emfobs_PI_out = u1;
        }
      }

      /* End of Saturate: '<S137>/Saturation' */

      /* Gain: '<S132>/Gain' incorporates:
       *  Sum: '<S132>/Add2'
       *  UnitDelay: '<S132>/Unit Delay'
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

      /* End of Gain: '<S132>/Gain' */

      /* Sum: '<S132>/Sum' incorporates:
       *  Delay: '<S132>/Delay'
       */
      localDW->Delay_DSTATE_l += rtb_Add6;

      /* Product: '<S132>/Product1' incorporates:
       *  Constant: '<S132>/Constant'
       *  Delay: '<S132>/Delay'
       */
      Sig_First_LPF_out = (int16_T)((localDW->Delay_DSTATE_l * CuttOffFreq_c) >>
        8);

      /* Sum: '<S133>/Sum' incorporates:
       *  Delay: '<S133>/Delay'
       *  Gain: '<S133>/Gain'
       *  Sum: '<S133>/Add2'
       *  UnitDelay: '<S133>/Unit Delay'
       */
      localDW->Delay_DSTATE_k = (int16_T)(((int16_T)(Sig_First_LPF_out -
        localDW->UnitDelay_DSTATE_o) >> 4) + localDW->Delay_DSTATE_k);

      /* Product: '<S133>/Product1' incorporates:
       *  Constant: '<S133>/Constant'
       *  Delay: '<S133>/Delay'
       */
      Sig_Second_LPF_out = (int16_T)((localDW->Delay_DSTATE_k * CuttOffFreq_c) >>
        8);

      /* DataTypeConversion: '<S129>/Data Type Conversion6' */
      rtb_Atan2 = (real32_T)Sig_Second_LPF_out * 0.015625F;

      /* DataTypeConversion: '<S131>/Data Type Conversion' */
      u1 = floorf(rtu_Ib * 16.0F);
      if (rtIsNaNF(u1) || rtIsInfF(u1)) {
        u1 = 0.0F;
      } else {
        u1 = fmodf(u1, 65536.0F);
      }

      rtb_Add2 = (int16_T)(u1 < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-u1
                           : (int32_T)(int16_T)(uint16_T)u1);

      /* End of DataTypeConversion: '<S131>/Data Type Conversion' */

      /* UnitDelay: '<S131>/Unit Delay' */
      localB->UnitDelay_j = localDW->UnitDelay_DSTATE_g;

      /* UnitDelay: '<S9>/Unit Delay1' */
      localB->UnitDelay1 = localDW->UnitDelay1_DSTATE;
    }

    /* Outputs for Atomic SubSystem: '<S131>/DC Motor Model' */
    /* Gain: '<S139>/Inductance' */
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

    /* Gain: '<S139>/Gain' incorporates:
     *  Gain: '<S139>/Inductance'
     *  UnitDelay: '<S139>/Unit Delay'
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

    /* End of Gain: '<S139>/Gain' */

    /* Sum: '<S139>/Sum' incorporates:
     *  Delay: '<S139>/Delay'
     *  UnitDelay: '<S139>/Unit Delay'
     */
    localDW->Delay_DSTATE += localDW->UnitDelay_DSTATE_m;

    /* Sum: '<S139>/Add5' */
    u1 = floorf(rtu_Vb * 16.0F);
    if (rtIsNaNF(u1) || rtIsInfF(u1)) {
      u1 = 0.0F;
    } else {
      u1 = fmodf(u1, 65536.0F);
    }

    /* Gain: '<S139>/Resistance' */
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

    /* Sum: '<S139>/Add5' incorporates:
     *  Delay: '<S139>/Delay'
     *  Gain: '<S139>/Resistance'
     *  UnitDelay: '<S139>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE_m = (int16_T)((int16_T)((int16_T)((u1 < 0.0F ?
      (int32_T)(int16_T)-(int16_T)(uint16_T)-u1 : (int32_T)(int16_T)(uint16_T)u1)
      - ((rtb_Add6 * localDW->Delay_DSTATE) >> 16)) - localB->UnitDelay_j) -
      (localB->UnitDelay1 >> 2));

    /* End of Outputs for SubSystem: '<S131>/DC Motor Model' */
    if (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0) {
      /* Sum: '<S131>/Add6' incorporates:
       *  Delay: '<S139>/Delay'
       */
      rtb_Add6 = (int16_T)(localDW->Delay_DSTATE - rtb_Add2);

      /* Outputs for Atomic SubSystem: '<S131>/PI Controller' */
      /* Abs: '<S140>/Abs' */
      if (rtb_Add6 < 0) {
        rtb_Add2 = (int16_T)-rtb_Add6;
      } else {
        rtb_Add2 = rtb_Add6;
      }

      /* End of Abs: '<S140>/Abs' */

      /* Outputs for Enabled SubSystem: '<S140>/Anti-windup' incorporates:
       *  EnablePort: '<S141>/Enable'
       */
      /* RelationalOperator: '<S140>/Relational Operator' incorporates:
       *  Constant: '<S140>/Constant1'
       */
      if ((rtb_Add2 << 4) <= 59) {
        /* Delay: '<S141>/Delay1' */
        if ((((localZCE->Delay1_Reset_ZCE == POS_ZCSIG) != (int32_T)rtu_In5) &&
             (localZCE->Delay1_Reset_ZCE != UNINITIALIZED_ZCSIG)) || rtu_In5) {
          localDW->Delay1_DSTATE = 0;
        }

        localZCE->Delay1_Reset_ZCE = rtu_In5;

        /* Sum: '<S141>/Sum1' incorporates:
         *  Delay: '<S141>/Delay1'
         *  Gain: '<S141>/Gain1'
         *  Gain: '<S141>/Ki'
         */
        localB->Sum1 = (int16_T)((((int16_T)((Ki_Iab_EMFobs * rtb_Add6) >> 3) >>
          4) + (localDW->Delay1_DSTATE << 4)) >> 4);

        /* Update for Delay: '<S141>/Delay1' */
        localDW->Delay1_DSTATE = localB->Sum1;
      }

      /* End of RelationalOperator: '<S140>/Relational Operator' */
      /* End of Outputs for SubSystem: '<S140>/Anti-windup' */

      /* Sum: '<S140>/Add1' incorporates:
       *  Gain: '<S140>/Kp'
       */
      rtb_Add2 = (int16_T)((((int16_T)((Kp_Iab_EMFobs * rtb_Add6) >> 8) << 4) +
                            localB->Sum1) >> 4);

      /* Saturate: '<S140>/Saturation' incorporates:
       *  UnitDelay: '<S131>/Unit Delay'
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

      /* End of Saturate: '<S140>/Saturation' */
      /* End of Outputs for SubSystem: '<S131>/PI Controller' */

      /* Sum: '<S135>/Sum' incorporates:
       *  Delay: '<S135>/Delay'
       *  Gain: '<S135>/Gain'
       *  Sum: '<S135>/Add2'
       *  UnitDelay: '<S131>/Unit Delay'
       *  UnitDelay: '<S135>/Unit Delay'
       */
      localDW->Delay_DSTATE_b = (int16_T)(((int16_T)
        (((localDW->UnitDelay_DSTATE_g << 2) - localDW->UnitDelay_DSTATE_p) >> 2)
        >> 2) + localDW->Delay_DSTATE_b);

      /* Product: '<S135>/Product1' incorporates:
       *  Constant: '<S135>/Constant'
       *  Delay: '<S135>/Delay'
       *  UnitDelay: '<S135>/Unit Delay'
       */
      localDW->UnitDelay_DSTATE_p = (int16_T)((localDW->Delay_DSTATE_b *
        CuttOffFreq_c) >> 8);

      /* Sum: '<S134>/Sum' incorporates:
       *  Delay: '<S134>/Delay'
       *  Gain: '<S134>/Gain'
       *  Sum: '<S134>/Add2'
       *  UnitDelay: '<S134>/Unit Delay'
       *  UnitDelay: '<S135>/Unit Delay'
       */
      localDW->Delay_DSTATE_e = (int16_T)(((int16_T)(localDW->UnitDelay_DSTATE_p
        - localDW->UnitDelay_DSTATE_mq) >> 4) + localDW->Delay_DSTATE_e);

      /* Product: '<S134>/Product1' incorporates:
       *  Constant: '<S134>/Constant'
       *  Delay: '<S134>/Delay'
       *  UnitDelay: '<S134>/Unit Delay'
       */
      localDW->UnitDelay_DSTATE_mq = (int16_T)((localDW->Delay_DSTATE_e *
        CuttOffFreq_c) >> 8);

      /* Trigonometry: '<S129>/Atan2' incorporates:
       *  DataTypeConversion: '<S129>/Data Type Conversion7'
       *  UnitDelay: '<S134>/Unit Delay'
       */
      rtb_Atan2 = rt_atan2f_snf_cordic6(rtb_Atan2, (real32_T)
        localDW->UnitDelay_DSTATE_mq * 0.015625F);

      /* DataTypeConversion: '<S129>/Data Type Conversion5' */
      u1 = floorf(rtb_Atan2 * 256.0F);
      if (rtIsNaNF(u1) || rtIsInfF(u1)) {
        u1 = 0.0F;
      } else {
        u1 = fmodf(u1, 65536.0F);
      }

      *rty_theta = (int16_T)(u1 < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
        -u1 : (int32_T)(int16_T)(uint16_T)u1);

      /* End of DataTypeConversion: '<S129>/Data Type Conversion5' */

      /* Update for UnitDelay: '<S130>/Unit Delay' */
      localDW->UnitDelay_DSTATE = Sig_Emfobs_PI_out;

      /* Update for UnitDelay: '<S9>/Unit Delay' */
      localDW->UnitDelay_DSTATE_cm = Sig_First_LPF_out;

      /* Update for UnitDelay: '<S132>/Unit Delay' */
      localDW->UnitDelay_DSTATE_k = Sig_First_LPF_out;

      /* Update for UnitDelay: '<S133>/Unit Delay' */
      localDW->UnitDelay_DSTATE_o = Sig_Second_LPF_out;

      /* Update for UnitDelay: '<S9>/Unit Delay1' incorporates:
       *  UnitDelay: '<S135>/Unit Delay'
       */
      localDW->UnitDelay1_DSTATE = localDW->UnitDelay_DSTATE_p;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Position observer' */
}

/* Model step function */
void MotorControlLib_step(void)
{
  /* local block i/o variables */
  real32_T rtb_AngleCalculation_o1;
  int32_T rowIdx;
  int32_T rowIdx_0;
  real32_T rtb_a;
  real32_T rtb_c;
  real32_T rtb_Add_m;
  real32_T rtb_convert_pu;
  real32_T rtb_Switch_m[2];
  real32_T rtb_UnitDelay1;
  real32_T rtb_UnitDelay2;
  boolean_T rtb_FixPtRelationalOperator;
  uint8_T rtb_UnitDelay_n;
  real32_T rtb_one_by_two;
  uint16_T rtb_UnitDelay1_n;
  int16_T rtb_RateTransition1;
  real32_T rtb_Saturation_j;
  real32_T rtb_Saturation;
  real32_T rtb_VectorConcatenate[2];
  int16_T tmp;

  /* RateTransition: '<Root>/Rate Transition3' incorporates:
   *  RateTransition: '<Root>/Rate Transition2'
   */
  if ((MotorControlLib_M->Timing.TaskCounters.TID[1] == 0) &&
      (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0)) {
    MotorControlLib_B.RateTransition3 =
      MotorControlLib_DW.RateTransition3_Buffer0;
    MotorControlLib_B.RateTransition2 =
      MotorControlLib_DW.RateTransition2_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition3' */
  if (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0) {
    /* UnitDelay: '<Root>/Unit Delay1' */
    rtb_UnitDelay1 = MotorControlLib_DW.UnitDelay1_DSTATE;

    /* UnitDelay: '<Root>/Unit Delay2' */
    rtb_UnitDelay2 = MotorControlLib_DW.UnitDelay2_DSTATE;

    /* ModelReference: '<Root>/ADCRAwToCurrent(Iabc)' incorporates:
     *  Inport: '<Root>/Inport'
     *  Inport: '<Root>/Inport7'
     */
    ADCRawToIab(&Sig_Ia_m, &Sig_Ib_m);

    /* UnitDelay: '<Root>/Unit Delay3' */
    MotorControlLib_B.UnitDelay3 = Sig_Ibeta_m;
  }

  /* RateTransition: '<Root>/Rate Transition4' incorporates:
   *  SignalConversion generated from: '<S4>/Enable'
   */
  if (MotorControlLib_M->Timing.TaskCounters.TID[1] == 0) {
    if (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0) {
      MotorControlLib_B.RateTransition4 =
        MotorControlLib_DW.RateTransition4_Buffer0;
    }

    /* Outputs for Enabled SubSystem: '<Root>/Flux_observer' */
    MotorControlLib_Flux_observer(MotorControlLib_B.RateTransition4,
      MotorControlLib_B.RateTransition3, MotorControlLib_B.RateTransition2,
      Sig_Ia_m, MotorControlLib_B.UnitDelay3, &FluxObsAngle,
      &MotorControlLib_B.Flux_observer, &MotorControlLib_ConstB.Flux_observer,
      &MotorControlLib_DW.Flux_observer, &MotorControlLib_PrevZCX.Flux_observer);

    /* End of Outputs for SubSystem: '<Root>/Flux_observer' */

    /* RateTransition: '<Root>/Rate Transition1' incorporates:
     *  SignalConversion generated from: '<S4>/Enable'
     */
    if (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0) {
      MotorControlLib_DW.RateTransition1_Buffer = FluxObsAngle;
    }
  }

  /* End of RateTransition: '<Root>/Rate Transition4' */

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
    Sig_Ia_m, MotorControlLib_B.UnitDelay3, resetPIIntegrator, &PositionObsAnlge,
    &MotorControlLib_B.Positionobserver, &MotorControlLib_DW.Positionobserver,
    &MotorControlLib_PrevZCX.Positionobserver);

  /* End of Outputs for SubSystem: '<Root>/Position observer' */
  if (MotorControlLib_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outputs for Atomic SubSystem: '<Root>/Start up' */
    /* CombinatorialLogic: '<S149>/Logic' incorporates:
     *  Constant: '<Root>/q Soll'
     *  Memory: '<S149>/Memory'
     *  RelationalOperator: '<S145>/Compare'
     *  UnitDelay: '<S143>/Unit Delay'
     */
    rowIdx = (int32_T)(((((uint32_T)(qSoll == 0) << 1) +
                         MotorControlLib_DW.UnitDelay_DSTATE_eb) << 1) +
                       MotorControlLib_DW.Memory_PreviousInput);

    /* UnitDelay: '<S146>/Delay Input1'
     *
     * Block description for '<S146>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator = MotorControlLib_DW.DelayInput1_DSTATE_f;

    /* UnitDelay: '<S143>/Unit Delay1' incorporates:
     *  UnitDelay: '<S146>/Delay Input1'
     *
     * Block description for '<S146>/Delay Input1':
     *
     *  Store in Global RAM
     */
    MotorControlLib_DW.DelayInput1_DSTATE_f =
      MotorControlLib_DW.UnitDelay1_DSTATE_m;

    /* RelationalOperator: '<S146>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S146>/Delay Input1'
     *
     * Block description for '<S146>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator = ((int32_T)
      MotorControlLib_DW.DelayInput1_DSTATE_f < (int32_T)
      rtb_FixPtRelationalOperator);

    /* Outputs for Enabled SubSystem: '<S143>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S147>/Enable'
     */
    /* CombinatorialLogic: '<S149>/Logic' */
    if (rtCP_Logic_table[(uint32_T)rowIdx]) {
      /* RelationalOperator: '<S151>/FixPt Relational Operator' incorporates:
       *  Constant: '<Root>/q Soll'
       *  UnitDelay: '<S151>/Delay Input1'
       *
       * Block description for '<S151>/Delay Input1':
       *
       *  Store in Global RAM
       */
      MotorControlLib_B.FixPtRelationalOperator = (qSoll !=
        MotorControlLib_DW.DelayInput1_DSTATE);

      /* Update for UnitDelay: '<S151>/Delay Input1' incorporates:
       *  Constant: '<Root>/q Soll'
       *
       * Block description for '<S151>/Delay Input1':
       *
       *  Store in Global RAM
       */
      MotorControlLib_DW.DelayInput1_DSTATE = qSoll;
    }

    /* End of Outputs for SubSystem: '<S143>/Enabled Subsystem' */

    /* Memory: '<S150>/Memory' incorporates:
     *  UnitDelay: '<S143>/Unit Delay'
     */
    MotorControlLib_DW.UnitDelay_DSTATE_eb =
      MotorControlLib_DW.Memory_PreviousInput_b;

    /* CombinatorialLogic: '<S150>/Logic' incorporates:
     *  UnitDelay: '<S143>/Unit Delay'
     */
    rowIdx_0 = (int32_T)(((((uint32_T)MotorControlLib_B.FixPtRelationalOperator <<
      1) + rtb_FixPtRelationalOperator) << 1) +
                         MotorControlLib_DW.UnitDelay_DSTATE_eb);

    /* Outputs for Enabled SubSystem: '<S143>/Enabled Subsystem1' incorporates:
     *  EnablePort: '<S148>/Enable'
     */
    if (rtCP_Logic_table_m[(uint32_T)rowIdx_0]) {
      /* UnitDelay: '<S148>/Unit Delay1' */
      rtb_UnitDelay1_n = MotorControlLib_DW.UnitDelay1_DSTATE_o;

      /* Sum: '<S148>/Add' incorporates:
       *  Constant: '<S148>/Constant'
       *  UnitDelay: '<S148>/Unit Delay1'
       */
      MotorControlLib_DW.UnitDelay1_DSTATE_o++;

      /* RelationalOperator: '<S148>/Relational Operator' incorporates:
       *  Constant: '<S148>/Constant1'
       *  UnitDelay: '<S143>/Unit Delay1'
       */
      MotorControlLib_DW.UnitDelay1_DSTATE_m = (rtb_UnitDelay1_n <= 10000);
    }

    /* End of Outputs for SubSystem: '<S143>/Enabled Subsystem1' */

    /* UnitDelay: '<S144>/Unit Delay' */
    rtb_FixPtRelationalOperator = MotorControlLib_DW.UnitDelay_DSTATE_pf;

    /* DiscreteIntegrator: '<S144>/Discrete-Time Integrator' incorporates:
     *  UnitDelay: '<S144>/Unit Delay'
     */
    if (MotorControlLib_DW.UnitDelay_DSTATE_pf &&
        (MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE = 0;
    }

    constantAngle = MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */

    /* Abs: '<S144>/Abs' */
    if (constantAngle < 0) {
      tmp = (int16_T)-constantAngle;
    } else {
      tmp = constantAngle;
    }

    /* End of Abs: '<S144>/Abs' */

    /* RelationalOperator: '<S144>/Relational Operator' incorporates:
     *  UnitDelay: '<S144>/Unit Delay'
     */
    MotorControlLib_DW.UnitDelay_DSTATE_pf = (tmp >= 1608);

    /* Update for UnitDelay: '<S143>/Unit Delay' incorporates:
     *  CombinatorialLogic: '<S150>/Logic'
     */
    MotorControlLib_DW.UnitDelay_DSTATE_eb = rtCP_Logic_table_m[(uint32_T)
      rowIdx_0];

    /* Update for Memory: '<S149>/Memory' incorporates:
     *  CombinatorialLogic: '<S149>/Logic'
     */
    MotorControlLib_DW.Memory_PreviousInput = rtCP_Logic_table[(uint32_T)rowIdx];

    /* Update for Memory: '<S150>/Memory' incorporates:
     *  CombinatorialLogic: '<S150>/Logic'
     */
    MotorControlLib_DW.Memory_PreviousInput_b = rtCP_Logic_table_m[(uint32_T)
      rowIdx_0];

    /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/Inport4'
     */
    MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE = (int16_T)(((6711 * dth_dt)
      >> 17) + MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE);
    MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      rtb_FixPtRelationalOperator;

    /* End of Outputs for SubSystem: '<Root>/Start up' */

    /* Outputs for Atomic SubSystem: '<Root>/detectStartUp' */
    /* UnitDelay: '<S12>/Unit Delay' */
    rtb_UnitDelay_n = MotorControlLib_DW.UnitDelay_DSTATE_c;

    /* Sum: '<S12>/Add' incorporates:
     *  Constant: '<S12>/Constant'
     *  UnitDelay: '<S12>/Unit Delay'
     */
    rowIdx = (int32_T)(MotorControlLib_DW.UnitDelay_DSTATE_c + 1U);
    if ((uint32_T)rowIdx > 255U) {
      rowIdx = 255;
    }

    MotorControlLib_DW.UnitDelay_DSTATE_c = (uint8_T)rowIdx;

    /* End of Sum: '<S12>/Add' */

    /* RelationalOperator: '<S152>/Compare' incorporates:
     *  Constant: '<S152>/Constant'
     */
    rtb_FixPtRelationalOperator = (rtb_UnitDelay_n == 0);

    /* End of Outputs for SubSystem: '<Root>/detectStartUp' */

    /* ModelReference: '<Root>/AngleCalculation' incorporates:
     *  Constant: '<Root>/q Soll'
     *  Inport: '<Root>/Input'
     *  Inport: '<Root>/Input1'
     *  UnitDelay: '<Root>/Unit Delay'
     */
    ConvertPWMtoAngle(&qSoll, &rtb_FixPtRelationalOperator,
                      &MotorControlLib_DW.UnitDelay_DSTATE,
                      &rtb_AngleCalculation_o1,
                      &MotorControlLib_B.AngleCalculation_o2);

    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Inport: '<Root>/Inport1'
     */
    switch (set_AngleInput) {
     case 0:
      rtb_Add_m = (real32_T)constantAngle * 0.00390625F;
      break;

     case 1:
      rtb_Add_m = (real32_T)rtb_RateTransition1 * 0.00390625F;
      break;

     case 2:
      rtb_Add_m = (real32_T)PositionObsAnlge * 0.00390625F;
      break;

     default:
      rtb_Add_m = rtb_AngleCalculation_o1;
      break;
    }
    Sig_theta_el_m = rtb_Add_m;

    /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

    /* Gain: '<S16>/convert_pu' */
    rtb_convert_pu = 0.159154937F * rtb_Add_m;

    /* If: '<S16>/If' incorporates:
     *  Constant: '<S17>/Constant'
     *  RelationalOperator: '<S17>/Compare'
     */
    if (rtb_convert_pu < 0.0F) {
      /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      /* DataTypeConversion: '<S18>/Convert_uint16' */
      rtb_one_by_two = floorf(rtb_convert_pu);
      if (rtIsInfF(rtb_one_by_two)) {
        rtb_one_by_two = 0.0F;
      } else {
        rtb_one_by_two = fmodf(rtb_one_by_two, 65536.0F);
      }

      /* Sum: '<S18>/Sum' incorporates:
       *  DataTypeConversion: '<S18>/Convert_back'
       *  DataTypeConversion: '<S18>/Convert_uint16'
       */
      rtb_convert_pu -= (real32_T)(rtb_one_by_two < 0.0F ? (int32_T)(int16_T)
        -(int16_T)(uint16_T)-rtb_one_by_two : (int32_T)(int16_T)(uint16_T)
        rtb_one_by_two);

      /* End of Outputs for SubSystem: '<S16>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      /* DataTypeConversion: '<S19>/Convert_uint16' */
      rtb_one_by_two = truncf(rtb_convert_pu);
      if (rtIsNaNF(rtb_one_by_two) || rtIsInfF(rtb_one_by_two)) {
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

      /* End of Outputs for SubSystem: '<S16>/If Action Subsystem1' */
    }

    /* End of If: '<S16>/If' */

    /* Gain: '<S14>/indexing' */
    rtb_convert_pu *= 400.0F;

    /* DataTypeConversion: '<S14>/Get_Integer' */
    rtb_one_by_two = truncf(rtb_convert_pu);
    if (rtIsNaNF(rtb_one_by_two) || rtIsInfF(rtb_one_by_two)) {
      rtb_one_by_two = 0.0F;
    } else {
      rtb_one_by_two = fmodf(rtb_one_by_two, 65536.0F);
    }

    rtb_UnitDelay1_n = (uint16_T)(rtb_one_by_two < 0.0F ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-rtb_one_by_two : (int32_T)(uint16_T)rtb_one_by_two);

    /* End of DataTypeConversion: '<S14>/Get_Integer' */

    /* Sum: '<S14>/Sum2' incorporates:
     *  DataTypeConversion: '<S14>/Data Type Conversion1'
     */
    rtb_convert_pu -= (real32_T)rtb_UnitDelay1_n;

    /* Selector: '<S14>/Lookup' incorporates:
     *  Sum: '<S14>/Sum'
     *  Sum: '<S15>/Sum5'
     *  Sum: '<S15>/Sum6'
     */
    rowIdx = (int32_T)(rtb_UnitDelay1_n + 100U);

    /* Sum: '<S15>/Sum6' incorporates:
     *  Constant: '<S14>/sine_table_values'
     *  Product: '<S15>/Product1'
     *  Selector: '<S14>/Lookup'
     *  Sum: '<S14>/Sum'
     *  Sum: '<S15>/Sum5'
     */
    Sig_cos_m = (rtCP_sine_table_values_Value[(int32_T)(rtb_UnitDelay1_n + 101U)]
                 - rtCP_sine_table_values_Value[rowIdx]) * rtb_convert_pu +
      rtCP_sine_table_values_Value[rowIdx];

    /* Gain: '<S1>/one_by_sqrt3' incorporates:
     *  Sum: '<S1>/a_plus_2b'
     */
    Sig_Ibeta_m = ((Sig_Ia_m + Sig_Ib_m) + Sig_Ib_m) * 0.577350259F;

    /* Sum: '<S15>/Sum4' incorporates:
     *  Constant: '<S14>/sine_table_values'
     *  Product: '<S15>/Product'
     *  Selector: '<S14>/Lookup'
     *  Sum: '<S14>/Sum'
     *  Sum: '<S15>/Sum3'
     */
    Sig_sin_m = (rtCP_sine_table_values_Value[(int32_T)(rtb_UnitDelay1_n + 1U)]
                 - rtCP_sine_table_values_Value[rtb_UnitDelay1_n]) *
      rtb_convert_pu + rtCP_sine_table_values_Value[rtb_UnitDelay1_n];

    /* Switch: '<S128>/Switch' incorporates:
     *  Product: '<S8>/acos'
     *  Product: '<S8>/asin'
     *  Product: '<S8>/bcos'
     *  Product: '<S8>/bsin'
     *  Sum: '<S8>/sum_Ds'
     *  Sum: '<S8>/sum_Qs'
     */
    rtb_Switch_m[0] = Sig_Ia_m * Sig_cos_m + Sig_Ibeta_m * Sig_sin_m;
    rtb_Switch_m[1] = Sig_Ibeta_m * Sig_cos_m - Sig_Ia_m * Sig_sin_m;

    /* Gain: '<S13>/Tq--> iqRef' incorporates:
     *  Constant: '<Root>/q Soll'
     */
    Sig_Iq_Soll = (real32_T)TqToIqConst * 0.00390625F * ((real32_T)qSoll *
      0.00390625F);

    /* Gain: '<Root>/Gain2' */
    Sig_dAxis_m = rtb_Switch_m[0];

    /* Gain: '<Root>/Gain3' */
    Sig_qAxis_m = -rtb_Switch_m[1];

    /* Outputs for Atomic SubSystem: '<Root>/PI_Controller' */
    /* Sum: '<S6>/Add' incorporates:
     *  Constant: '<Root>/d Soll'
     */
    Sig_dAxis_errorSum_m = (real32_T)dSoll - Sig_dAxis_m;

    /* Outputs for Enabled SubSystem: '<S33>/Subsystem' incorporates:
     *  EnablePort: '<S125>/Enable'
     */
    /* UnitDelay: '<S33>/Unit Delay' */
    if (MotorControlLib_DW.UnitDelay_DSTATE_o) {
      /* Sum: '<S125>/Add2' incorporates:
       *  Constant: '<S33>/Constant8'
       *  UnitDelay: '<S125>/Unit Delay'
       */
      MotorControlLib_DW.UnitDelay_DSTATE_p++;
    }

    /* End of Outputs for SubSystem: '<S33>/Subsystem' */

    /* RelationalOperator: '<S124>/Compare' incorporates:
     *  Constant: '<S124>/Constant'
     *  UnitDelay: '<S125>/Unit Delay'
     *  UnitDelay: '<S33>/Unit Delay'
     */
    MotorControlLib_DW.UnitDelay_DSTATE_o =
      (MotorControlLib_DW.UnitDelay_DSTATE_p < 1500);

    /* Logic: '<S6>/OR' incorporates:
     *  Inport: '<Root>/Inport6'
     *  UnitDelay: '<S33>/Unit Delay'
     */
    rtb_FixPtRelationalOperator = (MotorControlLib_DW.UnitDelay_DSTATE_o ||
      resetPIIntegratorDQ);

    /* Outputs for Atomic SubSystem: '<S6>/PI DAxis' */
    /* Constant: '<S6>/Constant6' incorporates:
     *  Constant: '<S6>/Constant7'
     */
    if (qSoll !=0 ) {
    rtb_Saturation_j = MotorControlLib_PIDAxis(Sig_dAxis_errorSum_m, Kp_dAxis,
      Ki_dAxis, rtb_FixPtRelationalOperator, &MotorControlLib_DW.PIDAxis);
    }
    else {

    	rtb_Saturation_j =0;
    }

    /* End of Outputs for SubSystem: '<S6>/PI DAxis' */

    /* Sum: '<S6>/Add1' */
    Sig_qAxis_errorSum_m = Sig_Iq_Soll - Sig_qAxis_m;

    /* Outputs for Atomic SubSystem: '<S6>/PI Qaxis' */
    /* DataTypeConversion: '<S6>/Data Type Conversion2' incorporates:
     *  Constant: '<S6>/Constant4'
     *  Constant: '<S6>/Constant5'
     *  DataTypeConversion: '<S6>/Data Type Conversion1'
     */
    if (qSoll !=0 ) {
    rtb_Saturation = MotorControlLib_PIQaxis(Sig_qAxis_errorSum_m, (real32_T)
      Kp_qAxis * 9.765625e-4F, (real32_T)Ki_qAxis * 0.03125F,
      rtb_FixPtRelationalOperator, &MotorControlLib_DW.PIQaxis);
    }
    else {

      	rtb_Saturation_j =0;

    }

    /* End of Outputs for SubSystem: '<S6>/PI Qaxis' */
    /* End of Outputs for SubSystem: '<Root>/PI_Controller' */

    /* Outputs for Atomic SubSystem: '<Root>/DQ_Limiter' */
    MotorControlLib_DQ_Limiter(rtb_Saturation_j, rtb_Saturation, rtb_Switch_m,
      &rtb_convert_pu, d_q_Voltage_Limiter_max);

    /* End of Outputs for SubSystem: '<Root>/DQ_Limiter' */

    /* SignalConversion generated from: '<Root>/DQ_Limiter' */
    Sig_Vqsatu_m = rtb_Switch_m[1];

    /* SignalConversion generated from: '<Root>/DQ_Limiter' */
    Sig_Vdsatu_m = rtb_Switch_m[0];

    /* Switch: '<S30>/Switch' incorporates:
     *  Product: '<S5>/dcos'
     *  Product: '<S5>/dsin'
     *  Product: '<S5>/qcos'
     *  Product: '<S5>/qsin'
     *  Sum: '<S5>/sum_alpha'
     *  Sum: '<S5>/sum_beta'
     */
    rtb_Switch_m[0] = Sig_Vdsatu_m * Sig_cos_m - Sig_Vqsatu_m * Sig_sin_m;
    rtb_Switch_m[1] = Sig_Vqsatu_m * Sig_cos_m + Sig_Vdsatu_m * Sig_sin_m;

    /* Gain: '<Root>/Gain' */
    Sig_Va_m = -rtb_Switch_m[0];

    /* Gain: '<Root>/Gain1' */
    Sig_Vb_m = rtb_Switch_m[1];

    /* Outputs for Atomic SubSystem: '<S7>/Inverse Clarke Transform' */
    /* Gain: '<S126>/one_by_two' incorporates:
     *  Inport: '<S126>/In1'
     */
    rtb_one_by_two = 0.5F * Sig_Va_m;

    /* Gain: '<S126>/sqrt3_by_two' */
    rtb_convert_pu = 0.866025388F * Sig_Vb_m;

    /* Sum: '<S126>/add_b' */
    Sig_Vbeta_m = rtb_convert_pu - rtb_one_by_two;

    /* Sum: '<S126>/add_c' */
    Sig_Vgamma_m = (0.0F - rtb_one_by_two) - rtb_convert_pu;

    /* End of Outputs for SubSystem: '<S7>/Inverse Clarke Transform' */

    /* Outputs for Atomic SubSystem: '<S7>/Space Vector Generator' */
    /* Gain: '<S127>/one_by_sqrt3' */
    rtb_c = 0.577350259F * Sig_Va_m;

    /* Sum: '<S127>/a' */
    rtb_a = rtb_c + rtb_c;

    /* Sum: '<S127>/b' */
    rtb_convert_pu = Sig_Vb_m - rtb_c;

    /* Sum: '<S127>/c' */
    rtb_c = (0.0F - rtb_c) - Sig_Vb_m;

    /* Gain: '<S127>/one_by_two' incorporates:
     *  MinMax: '<S127>/Max'
     *  MinMax: '<S127>/Min'
     *  Sum: '<S127>/Add'
     */
    rtb_one_by_two = (fmaxf(fmaxf(rtb_a, rtb_convert_pu), rtb_c) + fminf(fminf
      (rtb_a, rtb_convert_pu), rtb_c)) * 0.5F;

    /* End of Outputs for SubSystem: '<S7>/Space Vector Generator' */

    /* Switch: '<S7>/Switch' incorporates:
     *  Inport: '<Root>/In1'
     *  Inport: '<S126>/In1'
     *  Sum: '<S127>/Da'
     *  Sum: '<S127>/Db'
     *  Switch: '<S7>/Switch1'
     */
    if (Sig_change_SVMalgorithm) {
      /* Outputs for Atomic SubSystem: '<S7>/Inverse Clarke Transform' */
      Sig_Valpha_m = Sig_Va_m;

      /* End of Outputs for SubSystem: '<S7>/Inverse Clarke Transform' */
    } else {
      /* Outputs for Atomic SubSystem: '<S7>/Space Vector Generator' */
      Sig_Valpha_m = rtb_a - rtb_one_by_two;
      Sig_Vbeta_m = rtb_convert_pu - rtb_one_by_two;

      /* End of Outputs for SubSystem: '<S7>/Space Vector Generator' */
    }

    /* End of Switch: '<S7>/Switch' */

    /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
     *  Lookup_n-D: '<S7>/1-D Lookup Table'
     */
    set_PWM_A_DT(look1_iflftu16Df_binlcpw(Sig_Valpha_m, (&(BrkPoints[0])),
      (&(pwmTableData[0])), 2U));

    /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
     *  Lookup_n-D: '<S7>/1-D Lookup Table1'
     */
    set_PWM_B_DT(look1_iflftu16Df_binlcpw(Sig_Vbeta_m, (&(BrkPoints[0])),
      (&(pwmTableData[0])), 2U));

    /* Switch: '<S7>/Switch2' incorporates:
     *  Inport: '<Root>/In1'
     *  Sum: '<S127>/Dc'
     */
    if (!Sig_change_SVMalgorithm) {
      /* Outputs for Atomic SubSystem: '<S7>/Space Vector Generator' */
      Sig_Vgamma_m = rtb_c - rtb_one_by_two;

      /* End of Outputs for SubSystem: '<S7>/Space Vector Generator' */
    }

    /* End of Switch: '<S7>/Switch2' */

    /* DataTypeConversion: '<S7>/Data Type Conversion2' incorporates:
     *  Lookup_n-D: '<S7>/1-D Lookup Table2'
     */
    set_PWM_C_DT(look1_iflftu16Df_binlcpw(Sig_Vgamma_m, (&(BrkPoints[0])),
      (&(pwmTableData[0])), 2U));

    /* Outport: '<Root>/Position' */
    MotorControlLib_Y.Position = rtb_Add_m;

    /* Sum: '<S10>/Add' */
    rtb_Add_m += Sig_Theta_el_cont_m;

    /* Switch: '<S10>/Switch' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S142>/Constant'
     *  RelationalOperator: '<S142>/Compare'
     */
    if (rtb_Add_m > 400000.0F) {
      Sig_Theta_el_cont_m = 0.0F;
    } else {
      Sig_Theta_el_cont_m = rtb_Add_m;
    }

    /* End of Switch: '<S10>/Switch' */

    /* SignalConversion generated from: '<Root>/Vector Concatenate' */
    rtb_VectorConcatenate[0] = Sig_Ia_m;

    /* SignalConversion generated from: '<Root>/Vector Concatenate' */
    rtb_VectorConcatenate[1] = Sig_Ib_m;

    /* ModelReference: '<Root>/SafetyChecks' */
    SafetyChecks(&rtb_VectorConcatenate[0],
                 &(MotorControlLib_DW.SafetyChecks_InstanceData.rtdw));

    /* Update for UnitDelay: '<Root>/Unit Delay1' */
    MotorControlLib_DW.UnitDelay1_DSTATE = rtb_Switch_m[0];

    /* Update for UnitDelay: '<Root>/Unit Delay2' */
    MotorControlLib_DW.UnitDelay2_DSTATE = rtb_Switch_m[1];

    /* Update for RateTransition: '<Root>/Rate Transition3' */
    MotorControlLib_DW.RateTransition3_Buffer0 = rtb_UnitDelay1;

    /* Update for RateTransition: '<Root>/Rate Transition2' */
    MotorControlLib_DW.RateTransition2_Buffer0 = rtb_UnitDelay2;

    /* Update for RateTransition: '<Root>/Rate Transition4' incorporates:
     *  Inport: '<Root>/Inport2'
     */
    MotorControlLib_DW.RateTransition4_Buffer0 = enableFluxObs;

    /* Update for UnitDelay: '<Root>/Unit Delay' */
    MotorControlLib_DW.UnitDelay_DSTATE = MotorControlLib_B.AngleCalculation_o2;
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

  /* Model Initialize function for ModelReference Block: '<Root>/AngleCalculation' */
  ConvertPWMtoAngle_initialize(rtmGetErrorStatusPointer(MotorControlLib_M));

  /* Model Initialize function for ModelReference Block: '<Root>/SafetyChecks' */
  SafetyChecks_initialize(rtmGetErrorStatusPointer(MotorControlLib_M),
    &(MotorControlLib_DW.SafetyChecks_InstanceData.rtm));
  MotorControlLib_PrevZCX.Positionobserver.Delay1_Reset_ZCE_j =
    UNINITIALIZED_ZCSIG;
  MotorControlLib_PrevZCX.Positionobserver.Delay1_Reset_ZCE =
    UNINITIALIZED_ZCSIG;
  MotorControlLib_PrevZCX.Flux_observer.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
  MotorControlLib_PrevZCX.Flux_observer.Delay_Reset_ZCE_o = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Start up' */
  /* InitializeConditions for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
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
