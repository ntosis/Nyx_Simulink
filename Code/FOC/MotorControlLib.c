/*
 * File: MotorControlLib.c
 *
 * Code generated for Simulink model 'MotorControlLib'.
 *
 * Model version                  : 3.56
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 28 17:30:35 2022
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
#include "rt_nonfinite.h"
#include "InterfaceBswApp.h"
#include "look1_iflftu16Df_binlcmpw.h"
#include "ConstParams.h"
#include "ADCRawToIab.h"
#include "SafetyChecks.h"
#define ConvertPWMtoAngle_MDLREF_HIDE_CHILD_
#include "ConvertPWMtoAngle.h"

/* Exported block signals */
boolean_T resetPIIntegratorDQ;         /* '<Root>/Inport6' */
boolean_T enableFluxObs;               /* '<Root>/Inport2' */
uint8_T set_AngleInput;                /* '<Root>/Inport1' */
boolean_T enablePositionObs;           /* '<Root>/Inport3' */
int16_T dth_dt;                        /* '<Root>/Inport4' */
boolean_T resetPIIntegrator;           /* '<Root>/Inport5' */
boolean_T Sig_change_SVMalgorithm;     /* '<Root>/In1' */
real32_T Sig_MechanicalAngle;          /* '<Root>/AngleCalculation' */
real32_T Sig_theta_el_m;               /* '<Root>/Multiport Switch' */
real32_T Sig_Ia_m;                     /* '<Root>/ADCRAwToCurrent(Iabc)' */
real32_T Sig_Ib_m;                     /* '<Root>/ADCRAwToCurrent(Iabc)' */
real32_T Sig_Theta_el_cont_m;          /* '<S5>/Switch' */
real32_T Sig_Iq_Soll;                  /* '<S18>/Tq--> iqRef' */
real32_T Sig_cos_m;                    /* '<S10>/Sum6' */
real32_T Sig_Ibeta_m;                  /* '<S138>/one_by_sqrt3' */
real32_T Sig_sin_m;                    /* '<S10>/Sum4' */
real32_T Sig_Id_axis_meas;             /* '<S7>/Gain2' */
real32_T Sig_Iq_axis_meas;             /* '<S7>/Gain3' */
real32_T Sig_Vqsatu_m;                 /* '<S3>/DQ_Limiter' */
real32_T Sig_Vdsatu_m;                 /* '<S3>/DQ_Limiter' */
real32_T Sig_Va_m;                     /* '<Root>/Gain' */
real32_T Sig_Vb_m;                     /* '<Root>/Gain1' */
real32_T Sig_Valpha_m;                 /* '<S4>/Switch' */
real32_T Sig_Vbeta_m;                  /* '<S4>/Switch1' */
real32_T Sig_Vgamma_m;                 /* '<S4>/Switch2' */
real32_T Sig_dAxis_errorSum_m;         /* '<S17>/Add' */
real32_T Sig_qAxis_errorSum_m;         /* '<S17>/Add1' */
real32_T Sig_dAxis_PI_out;             /* '<S17>/PI DAxis' */
real32_T Sig_qAxis_PI_out;             /* '<S17>/PI Qaxis' */
int16_T constantAngle;                 /* '<S130>/Discrete-Time Integrator' */
real32_T FeedPIQ[10] = {0,0,0.5f,0.5f,1.0f,1.0f,1.5f,1.5f,2.0f,2.0f};
int16_T count=0;
int16_T idx=0;
/* Exported block parameters */
int16_T d_q_Voltage_Limiter_max = 92;  /* Variable: d_q_Voltage_Limiter_max
                                        * Referenced by: '<S3>/DQ_Limiter'
                                        * =Vnom/sqrt(3)
                                        */
int16_T d_q_Voltage_Limiter_sat_neg = -160;/* Variable: d_q_Voltage_Limiter_sat_neg
                                            * Referenced by:
                                            *   '<S63>/Saturation'
                                            *   '<S114>/Saturation'
                                            *   '<S49>/DeadZone'
                                            *   '<S100>/DeadZone'
                                            * fixdt(1,16,2^-4,0)
                                            */
int16_T d_q_Voltage_Limiter_sat_pos = 160;/* Variable: d_q_Voltage_Limiter_sat_pos
                                           * Referenced by:
                                           *   '<S63>/Saturation'
                                           *   '<S114>/Saturation'
                                           *   '<S49>/DeadZone'
                                           *   '<S100>/DeadZone'
                                           * fixdt(1,16,2^-4,0)
                                           */
uint16_T Kp_dAxis = 0U;              /* Variable: Kp_dAxis
                                        * Referenced by: '<S17>/Constant6'
                                        * fixdt(0,16,2^-10,0)
                                        */
uint32_T Kp_qAxis = 0U;              /* Variable: Kp_qAxis
                                        * Referenced by: '<S17>/Constant4'
                                        * fixdt(0,16,2^-10,0)
                                        */
uint16_T Ki_dAxis = 0U;             /* Variable: Ki_dAxis
                                        * Referenced by: '<S17>/Constant7'
                                        * fixdt(0,16,2^-8,0)
                                        */
uint32_T Ki_qAxis = 0U;             /* Variable: Ki_qAxis
                                        * Referenced by: '<S17>/Constant5'
                                        * fixdt(0,16,2^-8,0)
                                        */
uint16_T MaximumCurrentBeforeReaction = 4864U;/* Variable: MaximumCurrentBeforeReaction
                                               * Referenced by: '<Root>/SafetyChecks'
                                               * Maximum current limit before software shutdowns the mosfets.
                                               */

/* Exported block states */
int16_T qSoll;                         /* '<Root>/Data Store Memory'
                                        * fixdt(1,16,2^-8,0)
                                        */
/* Exported block states */
int16_T rpmSoll;
real32_T Sig_omega;

/*extern volatile float Q_P=0;
extern volatile float Q_I=0;*/
void writeInFile(void);

/* Block signals (default storage) */
B_MotorControlLib_T MotorControlLib_B;

/* Block states (default storage) */
DW_MotorControlLib_T MotorControlLib_DW;
real32_T PI_q_Integrator;
real32_T PI_d_Integrator;

/* Real-time model */
static RT_MODEL_MotorControlLib_T MotorControlLib_M_;
RT_MODEL_MotorControlLib_T *const MotorControlLib_M = &MotorControlLib_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (MotorControlLib_M->Timing.TaskCounters.TID[1])++;
  if ((MotorControlLib_M->Timing.TaskCounters.TID[1]) > 12) {/* Sample time: [0.0002s, 0.0s] */
    MotorControlLib_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Output and update for atomic system: '<S3>/DQ_Limiter' */
void MotorControlLib_DQ_Limiter(real32_T rtu_Vd_ref, real32_T rtu_Vq_ref,
  real32_T rty_Vd_sat[2], real32_T *rty_Vmax_unsat, int16_T rtp_Vmax)
{
  real32_T rtb_Gain;

  /* Sum: '<S16>/Sum2' incorporates:
   *  Product: '<S16>/Product'
   *  Product: '<S16>/Product1'
   */
  *rty_Vmax_unsat = rtu_Vd_ref * rtu_Vd_ref + rtu_Vq_ref * rtu_Vq_ref;

  /* Sqrt: '<S16>/Sqrt' */
  *rty_Vmax_unsat = sqrtf(*rty_Vmax_unsat);

  /* Switch: '<S16>/Switch' incorporates:
   *  Gain: '<S16>/Gain'
   *  Math: '<S16>/Math Function2'
   *  Product: '<S16>/Product2'
   *
   * About '<S16>/Math Function2':
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

  /* End of Switch: '<S16>/Switch' */
}

/*
 * System initialize for atomic system:
 *    '<S17>/PI DAxis'
 *    '<S17>/PI Qaxis'
 */
void MotorControlLib_PIDAxis_Init(DW_PIDAxis_MotorControlLib_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S56>/Integrator' */
  localDW->Integrator_IC_LOADING = 1U;
}

/*
 * Output and update for atomic system:
 *    '<S17>/PI DAxis'
 *    '<S17>/PI Qaxis'
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

  /* DiscreteIntegrator: '<S56>/Integrator' */
  if (localDW->Integrator_IC_LOADING != 0) {
    localDW->Integrator_DSTATE = rtu_init;
  }

  if (rtu_Reset || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = rtu_init;
  }

  /* Sum: '<S65>/Sum' incorporates:
   *  DiscreteIntegrator: '<S56>/Integrator'
   *  Product: '<S61>/PProd Out'
   */
  rty_PIDOut_0 = rtu_error * rtu_P + localDW->Integrator_DSTATE;

  /* DeadZone: '<S49>/DeadZone' incorporates:
   *  Saturate: '<S63>/Saturation'
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

  /* End of DeadZone: '<S49>/DeadZone' */

  /* RelationalOperator: '<S47>/Relational Operator' incorporates:
   *  Constant: '<S47>/Clamping_zero'
   */
  rtb_RelationalOperator_o = (rtb_IProdOut != 0.0F);

  /* Switch: '<S47>/Switch1' incorporates:
   *  Constant: '<S47>/Clamping_zero'
   *  Constant: '<S47>/Constant'
   *  Constant: '<S47>/Constant2'
   *  RelationalOperator: '<S47>/fix for DT propagation issue'
   */
  if (rtb_IProdOut > 0.0F) {
    rtb_Switch1 = 1;
  } else {
    rtb_Switch1 = -1;
  }

  /* End of Switch: '<S47>/Switch1' */

  /* Product: '<S53>/IProd Out' */
  rtb_IProdOut = rtu_error * rtu_I;

  /* Saturate: '<S63>/Saturation' */
  u1 = (real32_T)d_q_Voltage_Limiter_sat_neg * 0.0625F;
  if (rty_PIDOut_0 > u2) {
    rty_PIDOut_0 = u2;
  } else if (rty_PIDOut_0 < u1) {
    rty_PIDOut_0 = u1;
  }

  /* Update for DiscreteIntegrator: '<S56>/Integrator' */
  localDW->Integrator_IC_LOADING = 0U;

  /* Switch: '<S47>/Switch2' incorporates:
   *  Constant: '<S47>/Clamping_zero'
   *  Constant: '<S47>/Constant3'
   *  Constant: '<S47>/Constant4'
   *  RelationalOperator: '<S47>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S47>/Switch' incorporates:
   *  Constant: '<S47>/Constant1'
   *  Logic: '<S47>/AND3'
   *  RelationalOperator: '<S47>/Equal1'
   *  Switch: '<S47>/Switch2'
   */
  if (rtb_RelationalOperator_o && (rtb_Switch1 == tmp)) {
    rtb_IProdOut = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S56>/Integrator' incorporates:
   *  Switch: '<S47>/Switch'
   */
  localDW->Integrator_DSTATE += 0.0008F * rtb_IProdOut;
  localDW->Integrator_PrevResetState = (int8_T)rtu_Reset;
  return rty_PIDOut_0;
}

/* Model step function */
void MotorControlLib_step(void)
{
  /* local block i/o variables */
  real32_T rtb_AngleCalculation_o1;
  real32_T rtb_Switch_i[2];
  real32_T UnitDelay_DSTATE;
  boolean_T rtb_UnitDelay_n;
  if (MotorControlLib_M->Timing.TaskCounters.TID[1] == 0) {
    int32_T tmp;
    real32_T rtb_a;
    real32_T rtb_c;
    real32_T rtb_one_by_two;
    int16_T tmp_0;
    uint16_T rtb_UnitDelay1;
    uint8_T rtb_UnitDelay_c;
    boolean_T rtb_FixPtRelationalOperator;

    /* Outputs for Atomic SubSystem: '<Root>/Start up' */
    /* UnitDelay: '<S130>/Unit Delay' */
    rtb_UnitDelay_n = MotorControlLib_DW.UnitDelay_DSTATE_pf;

    /* DiscreteIntegrator: '<S130>/Discrete-Time Integrator' incorporates:
     *  UnitDelay: '<S130>/Unit Delay'
     */
    if (MotorControlLib_DW.UnitDelay_DSTATE_pf &&
        (MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE = 0;
    }

    /* DiscreteIntegrator: '<S130>/Discrete-Time Integrator' */
    constantAngle = MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE;

    /* Abs: '<S130>/Abs' incorporates:
     *  DiscreteIntegrator: '<S130>/Discrete-Time Integrator'
     */
    if (constantAngle < 0) {
      tmp_0 = (int16_T)-constantAngle;
    } else {
      tmp_0 = constantAngle;
    }

    /* RelationalOperator: '<S130>/Relational Operator' incorporates:
     *  Abs: '<S130>/Abs'
     *  UnitDelay: '<S130>/Unit Delay'
     */
    MotorControlLib_DW.UnitDelay_DSTATE_pf = (tmp_0 >= 1608);

    /* UnitDelay: '<S132>/Delay Input1'
     *
     * Block description for '<S132>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator = MotorControlLib_DW.DelayInput1_DSTATE_f;

    /* UnitDelay: '<S129>/Unit Delay1' incorporates:
     *  UnitDelay: '<S132>/Delay Input1'
     *
     * Block description for '<S132>/Delay Input1':
     *
     *  Store in Global RAM
     */
    MotorControlLib_DW.DelayInput1_DSTATE_f =
      MotorControlLib_DW.UnitDelay1_DSTATE_m;

    /* RelationalOperator: '<S132>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S132>/Delay Input1'
     *
     * Block description for '<S132>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator = ((int32_T)
      MotorControlLib_DW.DelayInput1_DSTATE_f < (int32_T)
      rtb_FixPtRelationalOperator);

    /* Outputs for Enabled SubSystem: '<S129>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S133>/Enable'
     */
    /* CombinatorialLogic: '<S135>/Logic' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read'
     *  Memory: '<S135>/Memory'
     *  RelationalOperator: '<S131>/Compare'
     *  UnitDelay: '<S129>/Unit Delay'
     */
    MotorControlLib_DW.Memory_PreviousInput = rtCP_Logic_table[((int32_T)
      (((((uint32_T)(qSoll == 0) << 1) + MotorControlLib_DW.UnitDelay_DSTATE_eb)
        << 1) + MotorControlLib_DW.Memory_PreviousInput) % 8) << 1];
    if (MotorControlLib_DW.Memory_PreviousInput) {
      /* RelationalOperator: '<S137>/FixPt Relational Operator' incorporates:
       *  DataStoreRead: '<Root>/Data Store Read'
       *  UnitDelay: '<S137>/Delay Input1'
       *
       * Block description for '<S137>/Delay Input1':
       *
       *  Store in Global RAM
       */
      MotorControlLib_B.FixPtRelationalOperator = (qSoll !=
        MotorControlLib_DW.DelayInput1_DSTATE);

      /* Update for UnitDelay: '<S137>/Delay Input1' incorporates:
       *  DataStoreRead: '<Root>/Data Store Read'
       * *
       * Block description for '<S137>/Delay Input1':
       *
       *  Store in Global RAM
       */
      MotorControlLib_DW.DelayInput1_DSTATE = qSoll;
    }

    /* End of Outputs for SubSystem: '<S129>/Enabled Subsystem' */

    /* Outputs for Enabled SubSystem: '<S129>/Enabled Subsystem1' incorporates:
     *  EnablePort: '<S134>/Enable'
     */
    /* CombinatorialLogic: '<S136>/Logic' incorporates:
     *  Memory: '<S136>/Memory'
     */
    MotorControlLib_DW.UnitDelay_DSTATE_eb = rtCP_Logic_table_m[((int32_T)
      (((((uint32_T)MotorControlLib_B.FixPtRelationalOperator << 1) +
         rtb_FixPtRelationalOperator) << 1) +
       MotorControlLib_DW.Memory_PreviousInput_b) % 8) << 1];
    if (MotorControlLib_DW.UnitDelay_DSTATE_eb) {
      /* UnitDelay: '<S134>/Unit Delay1' */
      rtb_UnitDelay1 = MotorControlLib_DW.UnitDelay1_DSTATE;

      /* Sum: '<S134>/Add' incorporates:
       *  Constant: '<S134>/Constant'
       *  UnitDelay: '<S134>/Unit Delay1'
       */
      MotorControlLib_DW.UnitDelay1_DSTATE++;

      /* RelationalOperator: '<S134>/Relational Operator' incorporates:
       *  Constant: '<S134>/Constant1'
       *  UnitDelay: '<S129>/Unit Delay1'
       */
      MotorControlLib_DW.UnitDelay1_DSTATE_m = (rtb_UnitDelay1 <= 10000);
    }

    /* End of Outputs for SubSystem: '<S129>/Enabled Subsystem1' */

    /* Update for DiscreteIntegrator: '<S130>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/Inport4'
     */
    MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE = (int16_T)(((6711 * dth_dt)
      >> 17) + MotorControlLib_DW.DiscreteTimeIntegrator_DSTATE);
    MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_UnitDelay_n;

    /* Update for Memory: '<S136>/Memory' */
    MotorControlLib_DW.Memory_PreviousInput_b =
      MotorControlLib_DW.UnitDelay_DSTATE_eb;

    /* End of Outputs for SubSystem: '<Root>/Start up' */

    /* Outputs for Atomic SubSystem: '<Root>/detectStartUp' */
    /* UnitDelay: '<S8>/Unit Delay' */
    rtb_UnitDelay_c = MotorControlLib_DW.UnitDelay_DSTATE_c;

    /* Sum: '<S8>/Add' incorporates:
     *  Constant: '<S8>/Constant'
     *  UnitDelay: '<S8>/Unit Delay'
     */
    tmp = (int32_T)(MotorControlLib_DW.UnitDelay_DSTATE_c + 1U);
    if (MotorControlLib_DW.UnitDelay_DSTATE_c + 1U > 255U) {
      tmp = 255;
    }

    MotorControlLib_DW.UnitDelay_DSTATE_c = (uint8_T)tmp;

    /* End of Sum: '<S8>/Add' */

    /* RelationalOperator: '<S141>/Compare' incorporates:
     *  Constant: '<S141>/Constant'
     */
    rtb_UnitDelay_n = (rtb_UnitDelay_c == 0);

    /* End of Outputs for SubSystem: '<Root>/detectStartUp' */

    /* ModelReference: '<Root>/AngleCalculation' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read'
     *  Inport: '<Root>/Input'
     *  Inport: '<Root>/Input1'
     *  UnitDelay: '<Root>/Unit Delay'
     */
    ConvertPWMtoAngle(&qSoll, &rtb_UnitDelay_n, &UnitDelay_DSTATE,
                      &rtb_AngleCalculation_o1, &Sig_MechanicalAngle);

    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Inport: '<Root>/Inport1'
     */
    switch (set_AngleInput) {
     case 0:
      /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
       *  DiscreteIntegrator: '<S130>/Discrete-Time Integrator'
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
      Sig_theta_el_m = (float)(2*3.14f) - rtb_AngleCalculation_o1;
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

    /* Sum: '<S5>/Add' */
    UnitDelay_DSTATE = Sig_theta_el_m + Sig_Theta_el_cont_m;

    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S128>/Constant'
     *  RelationalOperator: '<S128>/Compare'
     */
    if (UnitDelay_DSTATE >= 628318.5307F) {
      /* Switch: '<S5>/Switch' incorporates:
       *  Constant: '<S5>/Constant'
       */
      Sig_Theta_el_cont_m = 0.0F;
    } else {
      /* Switch: '<S5>/Switch' */
      Sig_Theta_el_cont_m = UnitDelay_DSTATE;
    }

    /* End of Switch: '<S5>/Switch' */
    /*Todo manual implement of PI for Speed*/


    if(rpmSoll>0)
    {
    Sig_omega=calculateOmega(&Sig_MechanicalAngle);
    Sig_Iq_Soll =  MotorControlLib_PIDAxis((((float)rpmSoll)-Sig_omega), RPM_P,RPM_I , rtb_UnitDelay_n,
          0.0F, &MotorControlLib_DW.PISpeed);
    qSoll=10; //dumy todo to be removed
    }
    else if(rpmSoll==0) {
    	qSoll=0;
    	Sig_Iq_Soll=0;
    }

    /* Gain: '<S18>/Tq--> iqRef' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read'
     */
   // todo manual implement of PI for Speed Sig_Iq_Soll = (real32_T)TqToIqConst * 0.00390625F * ((real32_T)qSoll *
    //  0.00390625F);

    /* Gain: '<S11>/convert_pu' */
    UnitDelay_DSTATE = 0.159154937F * Sig_theta_el_m;

    /* If: '<S11>/If' incorporates:
     *  Constant: '<S12>/Constant'
     *  RelationalOperator: '<S12>/Compare'
     */
    if (UnitDelay_DSTATE < 0.0F) {
      /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      /* DataTypeConversion: '<S13>/Convert_uint16' */
      rtb_one_by_two = floorf(UnitDelay_DSTATE);
      if (rtIsInfF(rtb_one_by_two)) {
        rtb_one_by_two = 0.0F;
      } else {
        rtb_one_by_two = fmodf(rtb_one_by_two, 65536.0F);
      }

      /* Sum: '<S13>/Sum' incorporates:
       *  DataTypeConversion: '<S13>/Convert_back'
       *  DataTypeConversion: '<S13>/Convert_uint16'
       */
      UnitDelay_DSTATE -= (real32_T)(rtb_one_by_two < 0.0F ? (int32_T)(int16_T)
        -(int16_T)(uint16_T)-rtb_one_by_two : (int32_T)(int16_T)(uint16_T)
        rtb_one_by_two);

      /* End of Outputs for SubSystem: '<S11>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      /* DataTypeConversion: '<S14>/Convert_uint16' */
      rtb_one_by_two = truncf(UnitDelay_DSTATE);
      if (rtIsNaNF(rtb_one_by_two) || rtIsInfF(rtb_one_by_two)) {
        rtb_one_by_two = 0.0F;
      } else {
        rtb_one_by_two = fmodf(rtb_one_by_two, 65536.0F);
      }

      /* Sum: '<S14>/Sum' incorporates:
       *  DataTypeConversion: '<S14>/Convert_back'
       *  DataTypeConversion: '<S14>/Convert_uint16'
       */
      UnitDelay_DSTATE -= (real32_T)(int16_T)(uint16_T)rtb_one_by_two;

      /* End of Outputs for SubSystem: '<S11>/If Action Subsystem1' */
    }

    /* End of If: '<S11>/If' */

    /* Gain: '<S9>/indexing' */
    UnitDelay_DSTATE *= 400.0F;

    /* DataTypeConversion: '<S9>/Get_Integer' */
    rtb_one_by_two = truncf(UnitDelay_DSTATE);
    if (rtIsNaNF(rtb_one_by_two) || rtIsInfF(rtb_one_by_two)) {
      rtb_one_by_two = 0.0F;
    } else {
      rtb_one_by_two = fmodf(rtb_one_by_two, 65536.0F);
    }

    rtb_UnitDelay1 = (uint16_T)(rtb_one_by_two < 0.0F ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-rtb_one_by_two : (int32_T)(uint16_T)rtb_one_by_two);

    /* End of DataTypeConversion: '<S9>/Get_Integer' */

    /* Sum: '<S9>/Sum2' incorporates:
     *  DataTypeConversion: '<S9>/Data Type Conversion1'
     */
    UnitDelay_DSTATE -= (real32_T)rtb_UnitDelay1;

    /* Selector: '<S9>/Lookup' incorporates:
     *  Constant: '<S9>/offset'
     *  Constant: '<S9>/sine_table_values'
     *  Sum: '<S10>/Sum5'
     *  Sum: '<S9>/Sum'
     */
    rtb_one_by_two = rtCP_sine_table_values_Value[(int32_T)(rtb_UnitDelay1 +
      100U)];

    /* Sum: '<S10>/Sum6' incorporates:
     *  Constant: '<S9>/offset'
     *  Constant: '<S9>/sine_table_values'
     *  Product: '<S10>/Product1'
     *  Selector: '<S9>/Lookup'
     *  Sum: '<S10>/Sum5'
     *  Sum: '<S9>/Sum'
     */
    Sig_cos_m = (rtCP_sine_table_values_Value[(int32_T)(rtb_UnitDelay1 + 101U)]
                 - rtb_one_by_two) * UnitDelay_DSTATE + rtb_one_by_two;

    /* Gain: '<S138>/one_by_sqrt3' incorporates:
     *  Sum: '<S138>/a_plus_2b'
     */
    Sig_Ibeta_m = ((Sig_Ia_m + Sig_Ib_m) + Sig_Ib_m) * 0.577350259F;

    /* Selector: '<S9>/Lookup' incorporates:
     *  Constant: '<S9>/sine_table_values'
     *  Sum: '<S9>/Sum'
     */
    rtb_one_by_two = rtCP_sine_table_values_Value[rtb_UnitDelay1];

    /* Sum: '<S10>/Sum4' incorporates:
     *  Constant: '<S9>/offset'
     *  Constant: '<S9>/sine_table_values'
     *  Product: '<S10>/Product'
     *  Selector: '<S9>/Lookup'
     *  Sum: '<S10>/Sum3'
     *  Sum: '<S9>/Sum'
     */
    Sig_sin_m = (rtCP_sine_table_values_Value[(int32_T)(rtb_UnitDelay1 + 1U)] -
                 rtb_one_by_two) * UnitDelay_DSTATE + rtb_one_by_two;

    /* Switch: '<S140>/Switch' incorporates:
     *  Product: '<S139>/acos'
     *  Product: '<S139>/asin'
     *  Product: '<S139>/bcos'
     *  Product: '<S139>/bsin'
     *  Sum: '<S139>/sum_Ds'
     *  Sum: '<S139>/sum_Qs'
     *  Switch: '<S15>/Switch'
     */
    Sig_Id_axis_meas = Sig_Ia_m * Sig_cos_m + Sig_Ibeta_m * Sig_sin_m;
    Sig_Iq_axis_meas = Sig_Ibeta_m * Sig_cos_m - Sig_Ia_m * Sig_sin_m;

    if(qSoll!=0) {
    /* Outputs for Atomic SubSystem: '<S3>/PI_Controller' */
    /* Sum: '<S17>/Add' incorporates:
     *  Constant: '<S3>/d Soll'
     */
    Sig_dAxis_errorSum_m = (real32_T)dSoll - Sig_Id_axis_meas;

    /* Sum: '<S17>/Add1' */
    Sig_qAxis_errorSum_m = Sig_Iq_Soll - Sig_Iq_axis_meas;
    }
    /* Outputs for Enabled SubSystem: '<S21>/Subsystem' incorporates:
     *  EnablePort: '<S125>/Enable'
     */
    /* UnitDelay: '<S21>/Unit Delay' */
    if (MotorControlLib_DW.UnitDelay_DSTATE_o) {
      /* Sum: '<S125>/Add2' incorporates:
       *  Constant: '<S21>/Constant8'
       *  UnitDelay: '<S125>/Unit Delay'
       */
      MotorControlLib_DW.UnitDelay_DSTATE_p++;
    }

    /* End of Outputs for SubSystem: '<S21>/Subsystem' */

    /* RelationalOperator: '<S124>/Compare' incorporates:
     *  Constant: '<S124>/Constant'
     *  UnitDelay: '<S125>/Unit Delay'
     *  UnitDelay: '<S21>/Unit Delay'
     */
    MotorControlLib_DW.UnitDelay_DSTATE_o =
      (MotorControlLib_DW.UnitDelay_DSTATE_p < 1500);

    /* Logic: '<S17>/OR' incorporates:
     *  Inport: '<Root>/Inport6'
     *  UnitDelay: '<S21>/Unit Delay'
     */
    rtb_UnitDelay_n = (MotorControlLib_DW.UnitDelay_DSTATE_o ||
                       resetPIIntegratorDQ);

    /* Outputs for Atomic SubSystem: '<S17>/PI DAxis' */
    /* SignalConversion generated from: '<S17>/PI DAxis' incorporates:
     *  Constant: '<S17>/Constant6'
     *  Constant: '<S17>/Constant7'
     *  DataTypeConversion: '<S17>/Data Type Conversion3'
     *  DataTypeConversion: '<S17>/Data Type Conversion4'
     */
    /*Q_P = (real32_T) Kp_qAxis * 0.015625F;
    Q_I = (real32_T) Ki_qAxis * 0.015625F;//2^-6*/

    if(qSoll!=0) {

    Sig_dAxis_PI_out =  MotorControlLib_PIDAxis(Sig_dAxis_errorSum_m, D_P,D_I , rtb_UnitDelay_n,
      0.0F, &MotorControlLib_DW.PIDAxis);


    /* End of Outputs for SubSystem: '<S17>/PI DAxis' */

    /* Outputs for Atomic SubSystem: '<S17>/PI Qaxis' */
    /* SignalConversion generated from: '<S17>/PI Qaxis' incorporates:
     *  Constant: '<S17>/Constant4'
     *  Constant: '<S17>/Constant5'
     *  DataTypeConversion: '<S17>/Data Type Conversion1'
     *  DataTypeConversion: '<S17>/Data Type Conversion2'
     */

    /*Sig_qAxis_PI_out = (-1.0f)* MotorControlLib_PIDAxis(Sig_qAxis_errorSum_m, (real32_T)
      Kp_qAxis * 0.0009765625F, (real32_T)Ki_qAxis * 0.03125F, rtb_UnitDelay_n,
      0.0F, &MotorControlLib_DW.PIQaxis); */



    Sig_qAxis_PI_out = (1.0f)* MotorControlLib_PIDAxis(Sig_qAxis_errorSum_m, Q_P, Q_I, rtb_UnitDelay_n,
         0.0F, &MotorControlLib_DW.PIQaxis);

    /*count++;
    if (count>50) {
    	idx++;
    	count =0;
    	if(idx>9) {writeInFile();}
    }*/



    PI_d_Integrator=MotorControlLib_DW.PIDAxis.Integrator_DSTATE;
    PI_q_Integrator=MotorControlLib_DW.PIQaxis.Integrator_DSTATE;

    /* End of Outputs for SubSystem: '<S17>/PI Qaxis' */
    /* End of Outputs for SubSystem: '<S3>/PI_Controller' */

    /* Outputs for Atomic SubSystem: '<S3>/DQ_Limiter' */
    MotorControlLib_DQ_Limiter(Sig_dAxis_PI_out, Sig_qAxis_PI_out, rtb_Switch_i,
      &UnitDelay_DSTATE, d_q_Voltage_Limiter_max);

    /* End of Outputs for SubSystem: '<S3>/DQ_Limiter' */

    /* SignalConversion generated from: '<S3>/DQ_Limiter' */
    Sig_Vqsatu_m = rtb_Switch_i[1];

    /* SignalConversion generated from: '<S3>/DQ_Limiter' */
    Sig_Vdsatu_m = rtb_Switch_i[0];

    /* Gain: '<Root>/Gain' incorporates:
     *  Product: '<S2>/dcos'
     *  Product: '<S2>/qsin'
     *  Sum: '<S2>/sum_alpha'
     */
    Sig_Va_m = Sig_Vdsatu_m * Sig_cos_m - Sig_Vqsatu_m * Sig_sin_m;

    /* Gain: '<Root>/Gain1' incorporates:
     *  Product: '<S2>/dsin'
     *  Product: '<S2>/qcos'
     *  Sum: '<S2>/sum_beta'
     */
    Sig_Vb_m = Sig_Vqsatu_m * Sig_cos_m + Sig_Vdsatu_m * Sig_sin_m;

    /* Outputs for Atomic SubSystem: '<S4>/Inverse Clarke Transform' */
    /* Gain: '<S126>/one_by_two' incorporates:
     *  SignalConversion generated from: '<S126>/In1'
     */
    rtb_one_by_two = 0.5F * Sig_Va_m;

    /* Gain: '<S126>/sqrt3_by_two' */
    UnitDelay_DSTATE = 0.866025388F * Sig_Vb_m;

    /* Sum: '<S126>/add_b' */
    Sig_Vbeta_m = UnitDelay_DSTATE - rtb_one_by_two;

    /* Sum: '<S126>/add_c' */
    Sig_Vgamma_m = (0.0F - rtb_one_by_two) - UnitDelay_DSTATE;

    /* End of Outputs for SubSystem: '<S4>/Inverse Clarke Transform' */

    /* Outputs for Atomic SubSystem: '<S4>/Space Vector Generator' */
    /* Gain: '<S127>/one_by_sqrt3' */
    rtb_c = 0.577350259F * Sig_Va_m;

    /* Sum: '<S127>/a' */
    rtb_a = rtb_c + rtb_c;

    /* Sum: '<S127>/b' */
    UnitDelay_DSTATE = Sig_Vb_m - rtb_c;

    /* Sum: '<S127>/c' */
    rtb_c = (0.0F - rtb_c) - Sig_Vb_m;

    /* Gain: '<S127>/one_by_two' incorporates:
     *  MinMax: '<S127>/Max'
     *  MinMax: '<S127>/Min'
     *  Sum: '<S127>/Add'
     */
    rtb_one_by_two = (fmaxf(fmaxf(rtb_a, UnitDelay_DSTATE), rtb_c) + fminf(fminf
      (rtb_a, UnitDelay_DSTATE), rtb_c)) * 0.5F;

    /* End of Outputs for SubSystem: '<S4>/Space Vector Generator' */

    /* Switch: '<S4>/Switch' incorporates:
     *  Inport: '<Root>/In1'
     *  Switch: '<S4>/Switch1'
     *  Switch: '<S4>/Switch2'
     */
    if (Sig_change_SVMalgorithm) {
      /* Outputs for Atomic SubSystem: '<S4>/Inverse Clarke Transform' */
      /* Switch: '<S4>/Switch' incorporates:
       *  SignalConversion generated from: '<S126>/In1'
       */
      Sig_Valpha_m = Sig_Va_m;

      /* End of Outputs for SubSystem: '<S4>/Inverse Clarke Transform' */
    } else {
      /* Outputs for Atomic SubSystem: '<S4>/Space Vector Generator' */
      /* Switch: '<S4>/Switch' incorporates:
       *  Sum: '<S127>/Da'
       */
      Sig_Valpha_m = rtb_a - rtb_one_by_two;

      /* Sum: '<S126>/add_b' incorporates:
       *  Sum: '<S127>/Db'
       *  Switch: '<S4>/Switch1'
       */
      Sig_Vbeta_m = UnitDelay_DSTATE - rtb_one_by_two;

      /* Sum: '<S126>/add_c' incorporates:
       *  Sum: '<S127>/Dc'
       *  Switch: '<S4>/Switch2'
       */
      Sig_Vgamma_m = rtb_c - rtb_one_by_two;

      /* End of Outputs for SubSystem: '<S4>/Space Vector Generator' */
    }
    }
    /* End of Switch: '<S4>/Switch' */

    /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
     *  Lookup_n-D: '<S4>/1-D Lookup Table'
     *  Switch: '<S4>/Switch'
     */
    set_PWM_A_DT(look1_iflftu16Df_binlcmpw(Sig_Valpha_m, &BrkPoints[0],
      &pwmTableData[0], 2U));

    /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
     *  Lookup_n-D: '<S4>/1-D Lookup Table1'
     *  Switch: '<S4>/Switch1'
     */
    set_PWM_B_DT(look1_iflftu16Df_binlcmpw(Sig_Vbeta_m, &BrkPoints[0],
      &pwmTableData[0], 2U));

    /* DataTypeConversion: '<S4>/Data Type Conversion2' incorporates:
     *  Lookup_n-D: '<S4>/1-D Lookup Table2'
     *  Switch: '<S4>/Switch2'
     */
    set_PWM_C_DT(look1_iflftu16Df_binlcmpw(Sig_Vgamma_m, &BrkPoints[0],
      &pwmTableData[0], 2U));
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

  /* SystemInitialize for Atomic SubSystem: '<Root>/Start up' */
  /* InitializeConditions for DiscreteIntegrator: '<S130>/Discrete-Time Integrator' */
  MotorControlLib_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* End of SystemInitialize for SubSystem: '<Root>/Start up' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/PI_Controller' */
  /* SystemInitialize for Atomic SubSystem: '<S17>/PI DAxis' */
  MotorControlLib_PIDAxis_Init(&MotorControlLib_DW.PIDAxis);

  /* End of SystemInitialize for SubSystem: '<S17>/PI DAxis' */

  /* SystemInitialize for Atomic SubSystem: '<S17>/PI Qaxis' */
  MotorControlLib_PIDAxis_Init(&MotorControlLib_DW.PIQaxis);

  /* End of SystemInitialize for SubSystem: '<S17>/PI Qaxis' */
  /* End of SystemInitialize for SubSystem: '<S3>/PI_Controller' */
}

/* Model terminate function */
void MotorControlLib_terminate(void)
{
  /* (no terminate code required) */
}
float calculateOmega(const float *mecAngle) {
	static float oldmecAngle = 0;
	float angularVelocity;
	float deltaTh;
	float rpm;

	deltaTh = fabsf(*mecAngle - oldmecAngle);
	oldmecAngle = *mecAngle;

	angularVelocity = deltaTh / (2 * 3.14159f * 0.0008f);  // Convert delta angle to angular velocity
	rpm = angularVelocity * 60;  // Convert angular velocity to RPM
	return rpm;

}
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
