/*
 * File: MotorControlLib.h
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

#ifndef RTW_HEADER_MotorControlLib_h_
#define RTW_HEADER_MotorControlLib_h_
#ifndef MotorControlLib_COMMON_INCLUDES_
#define MotorControlLib_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* MotorControlLib_COMMON_INCLUDES_ */

#include "MotorControlLib_types.h"
#include "ADCRawToIab.h"
#include "SafetyChecks.h"

/* Includes for objects with custom storage classes */
#include "ConstParams.h"
#include "PWMtoAngle_const.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
#endif

/* Block states (default storage) for system '<S5>/PI DAxis' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S55>/Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S55>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S55>/Integrator' */
} DW_PIDAxis_MotorControlLib_T;

/* Block states (default storage) for system '<S73>/PI DAxis' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S111>/Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S111>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S111>/Integrator' */
} DW_PIDAxis_MotorControlLib_c_T;

/* Block signals (default storage) */
typedef struct {
  real32_T Saturation;                 /* '<S62>/Saturation' */
  uint16_T Add2;                       /* '<S180>/Add2' */
  boolean_T TmpRTBAtANDInport1;
  boolean_T RelationalOperator;        /* '<S188>/Relational Operator' */
  boolean_T FixPtRelationalOperator;   /* '<S191>/FixPt Relational Operator' */
} B_MotorControlLib_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S191>/Delay Input1' */
  real32_T IntegratorofAngle_DSTATE;   /* '<Root>/Integrator of Angle' */
  volatile real32_T RateTransition5_Buffer0;/* '<Root>/Rate Transition5' */
  uint16_T UnitDelay1_DSTATE;          /* '<S188>/Unit Delay1' */
  uint16_T UnitDelay_DSTATE;           /* '<S180>/Unit Delay' */
  int16_T DiscreteTimeIntegrator_DSTATE;/* '<S184>/Discrete-Time Integrator' */
  boolean_T UnitDelay_DSTATE_p;        /* '<S184>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S186>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE_m;       /* '<S183>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S183>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_o;        /* '<S76>/Unit Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S184>/Discrete-Time Integrator' */
  boolean_T TmpRTBAtANDInport1_Buffer0;/* synthesized block */
  volatile boolean_T RateTransition6_Buffer0;/* '<Root>/Rate Transition6' */
  boolean_T Memory_PreviousInput;      /* '<S189>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S190>/Memory' */
  MdlrefDW_ADCRawToIab_T ADCRAwToCurrentIabc_InstanceDat;/* '<Root>/ADCRAwToCurrent(Iabc)' */
  MdlrefDW_SafetyChecks_T SafetyChecks_InstanceData;/* '<Root>/SafetyChecks' */
  DW_PIDAxis_MotorControlLib_c_T PIQaxis;/* '<S73>/PI Qaxis' */
  DW_PIDAxis_MotorControlLib_c_T PIDAxis_m;/* '<S73>/PI DAxis' */
  DW_PIDAxis_MotorControlLib_T PIDAxis;/* '<S5>/PI DAxis' */
} DW_MotorControlLib_T;

/* Real-time Model Data Structure */
struct tag_RTM_MotorControlLib_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID1_2;
      boolean_T b_TID1_2;
    } RateInteraction;
  } Timing;
};

/* Block signals (default storage) */
extern B_MotorControlLib_T MotorControlLib_B;

/* Block states (default storage) */
extern DW_MotorControlLib_T MotorControlLib_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern boolean_T resetPIIntegratorDQ;  /* '<Root>/Inport6' */
extern boolean_T enableFluxObs;        /* '<Root>/Inport2' */
extern uint8_T set_AngleInput;         /* '<Root>/Inport1' */
extern boolean_T enablePositionObs;    /* '<Root>/Inport3' */
extern int16_T dth_dt;                 /* '<Root>/Inport4' */
extern boolean_T resetPIIntegrator;    /* '<Root>/Inport5' */
extern boolean_T Sig_change_SVMalgorithm;/* '<Root>/In1' */
extern boolean_T activateRPMCntlr;     /* '<Root>/Inport8'
                                        * Set to 1 to activate the RPM Controller
                                        */
extern real32_T Sig_MechanicalAngle;   /* '<Root>/AngleCalculation' */
extern real32_T Sig_theta_el_m;        /* '<Root>/Multiport Switch' */
extern real32_T Sig_Ia_m;              /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern real32_T Sig_Ib_m;              /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern real32_T Sig_Iq_Soll;           /* '<S4>/Switch' */
extern real32_T Sig_cos_m;             /* '<S13>/Sum6' */
extern real32_T Sig_Ibeta_m;           /* '<S192>/one_by_sqrt3' */
extern real32_T Sig_sin_m;             /* '<S13>/Sum4' */
extern real32_T Sig_Id_axis_meas;      /* '<S9>/Gain2' */
extern real32_T Sig_Iq_axis_meas;      /* '<S9>/Gain3' */
extern real32_T Sig_Vqsatu_m;          /* '<S6>/DQ_Limiter' */
extern real32_T Sig_Vdsatu_m;          /* '<S6>/DQ_Limiter' */
extern real32_T Sig_Va_m;              /* '<Root>/Gain' */
extern real32_T Sig_Vb_m;              /* '<Root>/Gain1' */
extern real32_T Sig_Valpha_m;          /* '<S7>/Switch' */
extern real32_T Sig_Vbeta_m;           /* '<S7>/Switch1' */
extern real32_T Sig_Vgamma_m;          /* '<S7>/Switch2' */
extern real32_T Sig_angle_speed;       /* '<Root>/Integrator of Angle' */
extern real32_T Sig_dAxis_errorSum_m;  /* '<S73>/Add' */
extern real32_T Sig_qAxis_errorSum_m;  /* '<S73>/Add1' */
extern real32_T Sig_IQ;                /* '<S73>/Data Type Conversion1' */
extern real32_T Sig_PQ;                /* '<S73>/Data Type Conversion2' */
extern real32_T Sig_PD;                /* '<S73>/Data Type Conversion3' */
extern real32_T Sig_ID;                /* '<S73>/Data Type Conversion4' */
extern real32_T Sig_Rpm_measurment;    /* '<S5>/Unit Conversion' */
extern real32_T Sig_PRPM;              /* '<S5>/Data Type Conversion3' */
extern real32_T Sig_IRPM;              /* '<S5>/Data Type Conversion4' */
extern int16_T constantAngle;          /* '<S184>/Discrete-Time Integrator' */
extern boolean_T Sig_requestMotorBreak;/* '<S1>/OR' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern int16_T d_q_Voltage_Limiter_max;/* Variable: d_q_Voltage_Limiter_max
                                        * Referenced by: '<S6>/DQ_Limiter'
                                        * =Vnom/sqrt(3)
                                        */
extern int16_T d_q_Voltage_Limiter_sat_neg;/* Variable: d_q_Voltage_Limiter_sat_neg
                                            * Referenced by:
                                            *   '<S62>/Saturation'
                                            *   '<S118>/Saturation'
                                            *   '<S169>/Saturation'
                                            *   '<S48>/DeadZone'
                                            *   '<S104>/DeadZone'
                                            *   '<S155>/DeadZone'
                                            * fixdt(1,16,2^-4,0)
                                            */
extern int16_T d_q_Voltage_Limiter_sat_pos;/* Variable: d_q_Voltage_Limiter_sat_pos
                                            * Referenced by:
                                            *   '<S62>/Saturation'
                                            *   '<S118>/Saturation'
                                            *   '<S169>/Saturation'
                                            *   '<S48>/DeadZone'
                                            *   '<S104>/DeadZone'
                                            *   '<S155>/DeadZone'
                                            * fixdt(1,16,2^-4,0)
                                            */
extern uint16_T Ki_Rpm;                /* Variable: Ki_Rpm
                                        * Referenced by: '<S5>/Constant7'
                                        * fixdt(0,16,2^-11,0)
                                        */
extern uint16_T Kp_Rpm;                /* Variable: Kp_Rpm
                                        * Referenced by: '<S5>/Constant6'
                                        * fixdt(0,16,2^-11,0)
                                        */
extern uint16_T Ki_dAxis;              /* Variable: Ki_dAxis
                                        * Referenced by: '<S73>/Constant7'
                                        * fixdt(0,16,2^-8,0)
                                        */
extern uint16_T Ki_qAxis;              /* Variable: Ki_qAxis
                                        * Referenced by: '<S73>/Constant5'
                                        * fixdt(0,16,2^-8,0)
                                        */
extern uint16_T Kp_dAxis;              /* Variable: Kp_dAxis
                                        * Referenced by: '<S73>/Constant6'
                                        * fixdt(0,16,2^-8,0)
                                        */
extern uint16_T Kp_qAxis;              /* Variable: Kp_qAxis
                                        * Referenced by: '<S73>/Constant4'
                                        * fixdt(0,16,2^-8,0)
                                        */
extern uint16_T MaximumCurrentBeforeReaction;/* Variable: MaximumCurrentBeforeReaction
                                              * Referenced by: '<Root>/SafetyChecks'
                                              * Maximum current limit before software shutdowns the mosfets.
                                              */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern real32_T AngleMec_1z;           /* '<Root>/Unit Delay' */
extern uint16_T rpmSoll;               /* '<Root>/Data Store Memory1' */
extern int16_T qSoll;                  /* '<Root>/Data Store Memory'
                                        * fixdt(1,16,2^-8,0)
                                        */

/* Model entry point functions */
extern void MotorControlLib_initialize(void);
extern void MotorControlLib_step0(void);
extern void MotorControlLib_step1(void);
extern void MotorControlLib_step2(void);
extern void MotorControlLib_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MotorControlLib_T *const MotorControlLib_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Propagation' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S181>/Data Type Duplicate' : Unused code path elimination
 * Block '<S182>/Data Type Duplicate' : Unused code path elimination
 * Block '<S192>/Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S12>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<Root>/Gain4' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain5' : Eliminated nontunable gain of 1
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S72>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S74>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S74>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S75>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S75>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S18>/Offset' : Unused code path elimination
 * Block '<S18>/Unary_Minus' : Unused code path elimination
 * Block '<S194>/Offset' : Unused code path elimination
 * Block '<S194>/Unary_Minus' : Unused code path elimination
 */

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
 * '<Root>' : 'MotorControlLib'
 * '<S1>'   : 'MotorControlLib/Calculate if user set input to null'
 * '<S2>'   : 'MotorControlLib/CosSin'
 * '<S3>'   : 'MotorControlLib/Inverse Park Transform'
 * '<S4>'   : 'MotorControlLib/Merge Qsoll and RPM'
 * '<S5>'   : 'MotorControlLib/PI controller RPM'
 * '<S6>'   : 'MotorControlLib/PI stage'
 * '<S7>'   : 'MotorControlLib/PWM Output'
 * '<S8>'   : 'MotorControlLib/Start up'
 * '<S9>'   : 'MotorControlLib/Subsystem'
 * '<S10>'  : 'MotorControlLib/Calculate if user set input to null/Compare To Zero'
 * '<S11>'  : 'MotorControlLib/Calculate if user set input to null/Compare To Zero1'
 * '<S12>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup'
 * '<S13>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/Interpolation'
 * '<S14>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp'
 * '<S15>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S16>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S17>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S18>'  : 'MotorControlLib/Inverse Park Transform/Switch_Axis'
 * '<S19>'  : 'MotorControlLib/Merge Qsoll and RPM/torqueToIq'
 * '<S20>'  : 'MotorControlLib/PI controller RPM/PI DAxis'
 * '<S21>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID'
 * '<S22>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Anti-windup'
 * '<S23>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/D Gain'
 * '<S24>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Filter'
 * '<S25>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Filter ICs'
 * '<S26>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/I Gain'
 * '<S27>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Ideal P Gain'
 * '<S28>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Ideal P Gain Fdbk'
 * '<S29>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Integrator'
 * '<S30>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Integrator ICs'
 * '<S31>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/N Copy'
 * '<S32>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/N Gain'
 * '<S33>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/P Copy'
 * '<S34>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Parallel P Gain'
 * '<S35>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Reset Signal'
 * '<S36>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Saturation'
 * '<S37>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Saturation Fdbk'
 * '<S38>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Sum'
 * '<S39>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Sum Fdbk'
 * '<S40>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tracking Mode'
 * '<S41>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tracking Mode Sum'
 * '<S42>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tsamp - Integral'
 * '<S43>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tsamp - Ngain'
 * '<S44>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/postSat Signal'
 * '<S45>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/preSat Signal'
 * '<S46>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel'
 * '<S47>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S48>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S49>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/D Gain/Disabled'
 * '<S50>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Filter/Disabled'
 * '<S51>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Filter ICs/Disabled'
 * '<S52>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/I Gain/External Parameters'
 * '<S53>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Ideal P Gain/Passthrough'
 * '<S54>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Ideal P Gain Fdbk/Disabled'
 * '<S55>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Integrator/Discrete'
 * '<S56>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Integrator ICs/External IC'
 * '<S57>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/N Copy/Disabled wSignal Specification'
 * '<S58>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/N Gain/Disabled'
 * '<S59>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/P Copy/Disabled'
 * '<S60>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Parallel P Gain/External Parameters'
 * '<S61>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Reset Signal/External Reset'
 * '<S62>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Saturation/Enabled'
 * '<S63>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Saturation Fdbk/Disabled'
 * '<S64>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Sum/Sum_PI'
 * '<S65>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Sum Fdbk/Disabled'
 * '<S66>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tracking Mode/Disabled'
 * '<S67>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tracking Mode Sum/Passthrough'
 * '<S68>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tsamp - Integral/Passthrough'
 * '<S69>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tsamp - Ngain/Passthrough'
 * '<S70>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/postSat Signal/Forward_Path'
 * '<S71>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/preSat Signal/Forward_Path'
 * '<S72>'  : 'MotorControlLib/PI stage/DQ_Limiter'
 * '<S73>'  : 'MotorControlLib/PI stage/PI_Controller'
 * '<S74>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis'
 * '<S75>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis'
 * '<S76>'  : 'MotorControlLib/PI stage/PI_Controller/disable integrator on start up'
 * '<S77>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID'
 * '<S78>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup'
 * '<S79>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/D Gain'
 * '<S80>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter'
 * '<S81>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter ICs'
 * '<S82>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/I Gain'
 * '<S83>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain'
 * '<S84>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain Fdbk'
 * '<S85>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator'
 * '<S86>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator ICs'
 * '<S87>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Copy'
 * '<S88>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Gain'
 * '<S89>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/P Copy'
 * '<S90>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Parallel P Gain'
 * '<S91>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Reset Signal'
 * '<S92>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation'
 * '<S93>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation Fdbk'
 * '<S94>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum'
 * '<S95>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum Fdbk'
 * '<S96>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode'
 * '<S97>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode Sum'
 * '<S98>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Integral'
 * '<S99>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Ngain'
 * '<S100>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/postSat Signal'
 * '<S101>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/preSat Signal'
 * '<S102>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel'
 * '<S103>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S104>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S105>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/D Gain/Disabled'
 * '<S106>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter/Disabled'
 * '<S107>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter ICs/Disabled'
 * '<S108>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/I Gain/External Parameters'
 * '<S109>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain/Passthrough'
 * '<S110>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain Fdbk/Disabled'
 * '<S111>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator/Discrete'
 * '<S112>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator ICs/External IC'
 * '<S113>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Copy/Disabled wSignal Specification'
 * '<S114>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Gain/Disabled'
 * '<S115>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/P Copy/Disabled'
 * '<S116>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Parallel P Gain/External Parameters'
 * '<S117>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Reset Signal/External Reset'
 * '<S118>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation/Enabled'
 * '<S119>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation Fdbk/Disabled'
 * '<S120>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum/Sum_PI'
 * '<S121>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum Fdbk/Disabled'
 * '<S122>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode/Disabled'
 * '<S123>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode Sum/Passthrough'
 * '<S124>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Integral/Passthrough'
 * '<S125>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Ngain/Passthrough'
 * '<S126>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/postSat Signal/Forward_Path'
 * '<S127>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/preSat Signal/Forward_Path'
 * '<S128>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID'
 * '<S129>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup'
 * '<S130>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/D Gain'
 * '<S131>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter'
 * '<S132>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter ICs'
 * '<S133>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/I Gain'
 * '<S134>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain'
 * '<S135>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain Fdbk'
 * '<S136>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator'
 * '<S137>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator ICs'
 * '<S138>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Copy'
 * '<S139>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Gain'
 * '<S140>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/P Copy'
 * '<S141>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Parallel P Gain'
 * '<S142>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Reset Signal'
 * '<S143>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation'
 * '<S144>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation Fdbk'
 * '<S145>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum'
 * '<S146>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum Fdbk'
 * '<S147>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode'
 * '<S148>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode Sum'
 * '<S149>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Integral'
 * '<S150>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Ngain'
 * '<S151>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/postSat Signal'
 * '<S152>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/preSat Signal'
 * '<S153>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup/Disc. Clamping Parallel'
 * '<S154>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S155>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S156>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/D Gain/Disabled'
 * '<S157>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter/Disabled'
 * '<S158>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter ICs/Disabled'
 * '<S159>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/I Gain/External Parameters'
 * '<S160>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain/Passthrough'
 * '<S161>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain Fdbk/Disabled'
 * '<S162>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator/Discrete'
 * '<S163>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator ICs/External IC'
 * '<S164>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Copy/Disabled wSignal Specification'
 * '<S165>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Gain/Disabled'
 * '<S166>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/P Copy/Disabled'
 * '<S167>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Parallel P Gain/External Parameters'
 * '<S168>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Reset Signal/External Reset'
 * '<S169>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation/Enabled'
 * '<S170>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation Fdbk/Disabled'
 * '<S171>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum/Sum_PI'
 * '<S172>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum Fdbk/Disabled'
 * '<S173>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode/Disabled'
 * '<S174>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode Sum/Passthrough'
 * '<S175>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Integral/Passthrough'
 * '<S176>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Ngain/Passthrough'
 * '<S177>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/postSat Signal/Forward_Path'
 * '<S178>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/preSat Signal/Forward_Path'
 * '<S179>' : 'MotorControlLib/PI stage/PI_Controller/disable integrator on start up/Compare To Constant'
 * '<S180>' : 'MotorControlLib/PI stage/PI_Controller/disable integrator on start up/Subsystem'
 * '<S181>' : 'MotorControlLib/PWM Output/Inverse Clarke Transform'
 * '<S182>' : 'MotorControlLib/PWM Output/Space Vector Generator'
 * '<S183>' : 'MotorControlLib/Start up/Logic after motor is stoped'
 * '<S184>' : 'MotorControlLib/Start up/Simulate start up Theta'
 * '<S185>' : 'MotorControlLib/Start up/Logic after motor is stoped/Compare To Zero'
 * '<S186>' : 'MotorControlLib/Start up/Logic after motor is stoped/Detect Decrease'
 * '<S187>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem'
 * '<S188>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem1'
 * '<S189>' : 'MotorControlLib/Start up/Logic after motor is stoped/S-R Flip-Flop'
 * '<S190>' : 'MotorControlLib/Start up/Logic after motor is stoped/S-R Flip-Flop1'
 * '<S191>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem/Detect Change'
 * '<S192>' : 'MotorControlLib/Subsystem/Clarke Transform'
 * '<S193>' : 'MotorControlLib/Subsystem/Park Transform'
 * '<S194>' : 'MotorControlLib/Subsystem/Park Transform/Switch_Axis'
 */
#endif                                 /* RTW_HEADER_MotorControlLib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
