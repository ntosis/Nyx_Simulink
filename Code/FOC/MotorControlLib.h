/*
 * File: MotorControlLib.h
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

#ifndef RTW_HEADER_MotorControlLib_h_
#define RTW_HEADER_MotorControlLib_h_
#ifndef MotorControlLib_COMMON_INCLUDES_
#define MotorControlLib_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* MotorControlLib_COMMON_INCLUDES_ */

#include "MotorControlLib_types.h"
#include "ADCRawToIab.h"
#include "SafetyChecks.h"
#include "rt_defines.h"

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

/* Block states (default storage) for system '<S6>/PI DAxis' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S57>/Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S57>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S57>/Integrator' */
} DW_PIDAxis_MotorControlLib_T;

/* Block states (default storage) for system '<S75>/PI DAxis' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S113>/Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S113>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S113>/Integrator' */
} DW_PIDAxis_MotorControlLib_c_T;

/* Block signals (default storage) */
typedef struct {
  real32_T DataTypeConversion;         /* '<S185>/Data Type Conversion' */
  real32_T Saturation;                 /* '<S64>/Saturation' */
  uint16_T Add2;                       /* '<S182>/Add2' */
  boolean_T TmpRTBAtANDInport1;
  boolean_T RelationalOperator;        /* '<S192>/Relational Operator' */
  boolean_T FixPtRelationalOperator;   /* '<S195>/FixPt Relational Operator' */
} B_MotorControlLib_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S195>/Delay Input1' */
  real32_T UD_DSTATE;                  /* '<S3>/UD' */
  volatile real32_T RateTransition5_Buffer0;/* '<Root>/Rate Transition5' */
  uint16_T UnitDelay1_DSTATE;          /* '<S192>/Unit Delay1' */
  uint16_T UnitDelay_DSTATE;           /* '<S182>/Unit Delay' */
  int16_T DiscreteTimeIntegrator_DSTATE;/* '<S188>/Discrete-Time Integrator' */
  boolean_T UnitDelay_DSTATE_p;        /* '<S188>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S190>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE_m;       /* '<S187>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S187>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_o;        /* '<S78>/Unit Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S188>/Discrete-Time Integrator' */
  boolean_T TmpRTBAtANDInport1_Buffer0;/* synthesized block */
  volatile boolean_T RateTransition6_Buffer0;/* '<Root>/Rate Transition6' */
  boolean_T Memory_PreviousInput;      /* '<S193>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S194>/Memory' */
  MdlrefDW_ADCRawToIab_T ADCRAwToCurrentIabc_InstanceDat;/* '<Root>/ADCRAwToCurrent(Iabc)' */
  MdlrefDW_SafetyChecks_T SafetyChecks_InstanceData;/* '<Root>/SafetyChecks' */
  DW_PIDAxis_MotorControlLib_c_T PIQaxis;/* '<S75>/PI Qaxis' */
  DW_PIDAxis_MotorControlLib_c_T PIDAxis_m;/* '<S75>/PI DAxis' */
  DW_PIDAxis_MotorControlLib_T PIDAxis;/* '<S6>/PI DAxis' */
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
extern real32_T Sig_Iq_Soll;           /* '<S5>/Switch' */
extern real32_T Sig_cos_m;             /* '<S15>/Sum6' */
extern real32_T Sig_Ibeta_m;           /* '<S196>/one_by_sqrt3' */
extern real32_T Sig_sin_m;             /* '<S15>/Sum4' */
extern real32_T Sig_Id_axis_meas;      /* '<S11>/Gain2' */
extern real32_T Sig_Iq_axis_meas;      /* '<S11>/Gain3' */
extern real32_T Sig_Vqsatu_m;          /* '<S7>/DQ_Limiter' */
extern real32_T Sig_Vdsatu_m;          /* '<S7>/DQ_Limiter' */
extern real32_T Sig_Va_m;              /* '<Root>/Gain' */
extern real32_T Sig_Vb_m;              /* '<Root>/Gain1' */
extern real32_T Sig_Valpha_m;          /* '<S8>/Switch' */
extern real32_T Sig_Vbeta_m;           /* '<S8>/Switch1' */
extern real32_T Sig_Vgamma_m;          /* '<S8>/Switch2' */
extern real32_T Sig_Speed_rads;        /* '<S3>/Diff'
                                        * Speed in Radians/s
                                        */
extern real32_T Sig_Rpm_measurment;    /* '<S9>/Switch' */
extern real32_T Sig_dAxis_errorSum_m;  /* '<S75>/Add' */
extern real32_T Sig_qAxis_errorSum_m;  /* '<S75>/Add1' */
extern real32_T Sig_IQ;                /* '<S75>/Data Type Conversion1' */
extern real32_T Sig_PQ;                /* '<S75>/Data Type Conversion2' */
extern real32_T Sig_PD;                /* '<S75>/Data Type Conversion3' */
extern real32_T Sig_ID;                /* '<S75>/Data Type Conversion4' */
extern real32_T Sig_qAxis_PI_out;      /* '<S75>/PI Qaxis' */
extern real32_T Sig_dAxis_PI_out;      /* '<S75>/PI DAxis' */
extern real32_T Sig_PRPM;              /* '<S6>/Data Type Conversion3' */
extern real32_T Sig_IRPM;              /* '<S6>/Data Type Conversion4' */
extern int16_T constantAngle;          /* '<S188>/Discrete-Time Integrator' */
extern boolean_T Sig_requestMotorBreak;/* '<S1>/OR' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T Minus_1;               /* Variable: Minus_1
                                        * Referenced by: '<S75>/Gain'
                                        * Multiply PI Q with -1 for more stability.
                                        */
extern int16_T d_q_Voltage_Limiter_max;/* Variable: d_q_Voltage_Limiter_max
                                        * Referenced by: '<S7>/DQ_Limiter'
                                        * =Vnom/sqrt(3)
                                        */
extern int16_T d_q_Voltage_Limiter_sat_neg;/* Variable: d_q_Voltage_Limiter_sat_neg
                                            * Referenced by:
                                            *   '<S64>/Saturation'
                                            *   '<S120>/Saturation'
                                            *   '<S171>/Saturation'
                                            *   '<S50>/DeadZone'
                                            *   '<S106>/DeadZone'
                                            *   '<S157>/DeadZone'
                                            * fixdt(1,16,2^-4,0)
                                            */
extern int16_T d_q_Voltage_Limiter_sat_pos;/* Variable: d_q_Voltage_Limiter_sat_pos
                                            * Referenced by:
                                            *   '<S64>/Saturation'
                                            *   '<S120>/Saturation'
                                            *   '<S171>/Saturation'
                                            *   '<S50>/DeadZone'
                                            *   '<S106>/DeadZone'
                                            *   '<S157>/DeadZone'
                                            * fixdt(1,16,2^-4,0)
                                            */
extern uint16_T Ki_Rpm;                /* Variable: Ki_Rpm
                                        * Referenced by: '<S6>/Constant7'
                                        * fixdt(0,16,2^-11,0)
                                        */
extern uint16_T Kp_Rpm;                /* Variable: Kp_Rpm
                                        * Referenced by: '<S6>/Constant6'
                                        * fixdt(0,16,2^-11,0)
                                        */
extern uint16_T Ki_dAxis;              /* Variable: Ki_dAxis
                                        * Referenced by: '<S75>/Constant7'
                                        * fixdt(0,16,2^-8,0)
                                        */
extern uint16_T Ki_qAxis;              /* Variable: Ki_qAxis
                                        * Referenced by: '<S75>/Constant5'
                                        * fixdt(0,16,2^-8,0)
                                        */
extern uint16_T Kp_dAxis;              /* Variable: Kp_dAxis
                                        * Referenced by: '<S75>/Constant6'
                                        * fixdt(0,16,2^-8,0)
                                        */
extern uint16_T Kp_qAxis;              /* Variable: Kp_qAxis
                                        * Referenced by: '<S75>/Constant4'
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
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Propagation' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate' : Unused code path elimination
 * Block '<S196>/Data Type Duplicate' : Unused code path elimination
 * Block '<S197>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S14>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<Root>/Gain4' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain5' : Eliminated nontunable gain of 1
 * Block '<S22>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S22>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S74>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S76>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S76>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S77>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S77>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S20>/Offset' : Unused code path elimination
 * Block '<S20>/Unary_Minus' : Unused code path elimination
 * Block '<S198>/Offset' : Unused code path elimination
 * Block '<S198>/Unary_Minus' : Unused code path elimination
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
 * '<S3>'   : 'MotorControlLib/Discrete Derivative'
 * '<S4>'   : 'MotorControlLib/Inverse Park Transform'
 * '<S5>'   : 'MotorControlLib/Merge Qsoll and RPM'
 * '<S6>'   : 'MotorControlLib/PI controller RPM'
 * '<S7>'   : 'MotorControlLib/PI stage'
 * '<S8>'   : 'MotorControlLib/PWM Output'
 * '<S9>'   : 'MotorControlLib/Speed Calculator'
 * '<S10>'  : 'MotorControlLib/Start up'
 * '<S11>'  : 'MotorControlLib/Subsystem'
 * '<S12>'  : 'MotorControlLib/Calculate if user set input to null/Compare To Zero'
 * '<S13>'  : 'MotorControlLib/Calculate if user set input to null/Compare To Zero1'
 * '<S14>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup'
 * '<S15>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/Interpolation'
 * '<S16>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp'
 * '<S17>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S18>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S19>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S20>'  : 'MotorControlLib/Inverse Park Transform/Switch_Axis'
 * '<S21>'  : 'MotorControlLib/Merge Qsoll and RPM/torqueToIq'
 * '<S22>'  : 'MotorControlLib/PI controller RPM/PI DAxis'
 * '<S23>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID'
 * '<S24>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Anti-windup'
 * '<S25>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/D Gain'
 * '<S26>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Filter'
 * '<S27>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Filter ICs'
 * '<S28>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/I Gain'
 * '<S29>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Ideal P Gain'
 * '<S30>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Ideal P Gain Fdbk'
 * '<S31>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Integrator'
 * '<S32>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Integrator ICs'
 * '<S33>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/N Copy'
 * '<S34>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/N Gain'
 * '<S35>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/P Copy'
 * '<S36>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Parallel P Gain'
 * '<S37>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Reset Signal'
 * '<S38>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Saturation'
 * '<S39>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Saturation Fdbk'
 * '<S40>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Sum'
 * '<S41>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Sum Fdbk'
 * '<S42>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tracking Mode'
 * '<S43>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tracking Mode Sum'
 * '<S44>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tsamp - Integral'
 * '<S45>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tsamp - Ngain'
 * '<S46>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/postSat Signal'
 * '<S47>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/preSat Signal'
 * '<S48>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel'
 * '<S49>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S50>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S51>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/D Gain/Disabled'
 * '<S52>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Filter/Disabled'
 * '<S53>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Filter ICs/Disabled'
 * '<S54>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/I Gain/External Parameters'
 * '<S55>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Ideal P Gain/Passthrough'
 * '<S56>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Ideal P Gain Fdbk/Disabled'
 * '<S57>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Integrator/Discrete'
 * '<S58>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Integrator ICs/External IC'
 * '<S59>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/N Copy/Disabled wSignal Specification'
 * '<S60>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/N Gain/Disabled'
 * '<S61>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/P Copy/Disabled'
 * '<S62>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Parallel P Gain/External Parameters'
 * '<S63>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Reset Signal/External Reset'
 * '<S64>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Saturation/Enabled'
 * '<S65>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Saturation Fdbk/Disabled'
 * '<S66>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Sum/Sum_PI'
 * '<S67>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Sum Fdbk/Disabled'
 * '<S68>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tracking Mode/Disabled'
 * '<S69>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tracking Mode Sum/Passthrough'
 * '<S70>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tsamp - Integral/Passthrough'
 * '<S71>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/Tsamp - Ngain/Passthrough'
 * '<S72>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/postSat Signal/Forward_Path'
 * '<S73>'  : 'MotorControlLib/PI controller RPM/PI DAxis/PID/preSat Signal/Forward_Path'
 * '<S74>'  : 'MotorControlLib/PI stage/DQ_Limiter'
 * '<S75>'  : 'MotorControlLib/PI stage/PI_Controller'
 * '<S76>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis'
 * '<S77>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis'
 * '<S78>'  : 'MotorControlLib/PI stage/PI_Controller/disable integrator on start up'
 * '<S79>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID'
 * '<S80>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup'
 * '<S81>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/D Gain'
 * '<S82>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter'
 * '<S83>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter ICs'
 * '<S84>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/I Gain'
 * '<S85>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain'
 * '<S86>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain Fdbk'
 * '<S87>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator'
 * '<S88>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator ICs'
 * '<S89>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Copy'
 * '<S90>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Gain'
 * '<S91>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/P Copy'
 * '<S92>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Parallel P Gain'
 * '<S93>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Reset Signal'
 * '<S94>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation'
 * '<S95>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation Fdbk'
 * '<S96>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum'
 * '<S97>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum Fdbk'
 * '<S98>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode'
 * '<S99>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode Sum'
 * '<S100>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Integral'
 * '<S101>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Ngain'
 * '<S102>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/postSat Signal'
 * '<S103>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/preSat Signal'
 * '<S104>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel'
 * '<S105>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S106>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S107>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/D Gain/Disabled'
 * '<S108>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter/Disabled'
 * '<S109>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter ICs/Disabled'
 * '<S110>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/I Gain/External Parameters'
 * '<S111>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain/Passthrough'
 * '<S112>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain Fdbk/Disabled'
 * '<S113>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator/Discrete'
 * '<S114>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator ICs/External IC'
 * '<S115>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Copy/Disabled wSignal Specification'
 * '<S116>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Gain/Disabled'
 * '<S117>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/P Copy/Disabled'
 * '<S118>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Parallel P Gain/External Parameters'
 * '<S119>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Reset Signal/External Reset'
 * '<S120>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation/Enabled'
 * '<S121>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation Fdbk/Disabled'
 * '<S122>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum/Sum_PI'
 * '<S123>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum Fdbk/Disabled'
 * '<S124>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode/Disabled'
 * '<S125>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode Sum/Passthrough'
 * '<S126>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Integral/Passthrough'
 * '<S127>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Ngain/Passthrough'
 * '<S128>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/postSat Signal/Forward_Path'
 * '<S129>' : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/preSat Signal/Forward_Path'
 * '<S130>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID'
 * '<S131>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup'
 * '<S132>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/D Gain'
 * '<S133>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter'
 * '<S134>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter ICs'
 * '<S135>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/I Gain'
 * '<S136>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain'
 * '<S137>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain Fdbk'
 * '<S138>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator'
 * '<S139>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator ICs'
 * '<S140>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Copy'
 * '<S141>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Gain'
 * '<S142>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/P Copy'
 * '<S143>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Parallel P Gain'
 * '<S144>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Reset Signal'
 * '<S145>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation'
 * '<S146>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation Fdbk'
 * '<S147>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum'
 * '<S148>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum Fdbk'
 * '<S149>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode'
 * '<S150>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode Sum'
 * '<S151>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Integral'
 * '<S152>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Ngain'
 * '<S153>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/postSat Signal'
 * '<S154>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/preSat Signal'
 * '<S155>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup/Disc. Clamping Parallel'
 * '<S156>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S157>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S158>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/D Gain/Disabled'
 * '<S159>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter/Disabled'
 * '<S160>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter ICs/Disabled'
 * '<S161>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/I Gain/External Parameters'
 * '<S162>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain/Passthrough'
 * '<S163>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain Fdbk/Disabled'
 * '<S164>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator/Discrete'
 * '<S165>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator ICs/External IC'
 * '<S166>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Copy/Disabled wSignal Specification'
 * '<S167>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Gain/Disabled'
 * '<S168>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/P Copy/Disabled'
 * '<S169>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Parallel P Gain/External Parameters'
 * '<S170>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Reset Signal/External Reset'
 * '<S171>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation/Enabled'
 * '<S172>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation Fdbk/Disabled'
 * '<S173>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum/Sum_PI'
 * '<S174>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum Fdbk/Disabled'
 * '<S175>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode/Disabled'
 * '<S176>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode Sum/Passthrough'
 * '<S177>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Integral/Passthrough'
 * '<S178>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Ngain/Passthrough'
 * '<S179>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/postSat Signal/Forward_Path'
 * '<S180>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/preSat Signal/Forward_Path'
 * '<S181>' : 'MotorControlLib/PI stage/PI_Controller/disable integrator on start up/Compare To Constant'
 * '<S182>' : 'MotorControlLib/PI stage/PI_Controller/disable integrator on start up/Subsystem'
 * '<S183>' : 'MotorControlLib/PWM Output/Inverse Clarke Transform'
 * '<S184>' : 'MotorControlLib/PWM Output/Space Vector Generator'
 * '<S185>' : 'MotorControlLib/Speed Calculator/Task_Calculate_fast_speed'
 * '<S186>' : 'MotorControlLib/Speed Calculator/Task_Calculate_fast_speed/avoid division with zero'
 * '<S187>' : 'MotorControlLib/Start up/Logic after motor is stoped'
 * '<S188>' : 'MotorControlLib/Start up/Simulate start up Theta'
 * '<S189>' : 'MotorControlLib/Start up/Logic after motor is stoped/Compare To Zero'
 * '<S190>' : 'MotorControlLib/Start up/Logic after motor is stoped/Detect Decrease'
 * '<S191>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem'
 * '<S192>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem1'
 * '<S193>' : 'MotorControlLib/Start up/Logic after motor is stoped/S-R Flip-Flop'
 * '<S194>' : 'MotorControlLib/Start up/Logic after motor is stoped/S-R Flip-Flop1'
 * '<S195>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem/Detect Change'
 * '<S196>' : 'MotorControlLib/Subsystem/Clarke Transform'
 * '<S197>' : 'MotorControlLib/Subsystem/Park Transform'
 * '<S198>' : 'MotorControlLib/Subsystem/Park Transform/Switch_Axis'
 */
#endif                                 /* RTW_HEADER_MotorControlLib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
