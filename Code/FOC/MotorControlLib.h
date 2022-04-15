/*
 * File: MotorControlLib.h
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

#ifndef RTW_HEADER_MotorControlLib_h_
#define RTW_HEADER_MotorControlLib_h_
#include <math.h>
#ifndef MotorControlLib_COMMON_INCLUDES_
# define MotorControlLib_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* MotorControlLib_COMMON_INCLUDES_ */

#include "MotorControlLib_types.h"

/* Child system includes */
#include "ADCRawToIab.h"
#include "ConvertPWMtoAngle.h"
#include "SafetyChecks.h"

/* Includes for objects with custom storage classes. */
#include "ConstParams.h"
#include "PWMtoAngle_const.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

/* Block signals for system '<Root>/FluxObserver' */
typedef struct {
  real32_T Merge;                      /* '<S22>/Merge' */
} B_FluxObserver_MotorControlLi_T;

/* Block states (default storage) for system '<Root>/FluxObserver' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S24>/Delay' */
  real32_T Delay_DSTATE_e;             /* '<S23>/Delay' */
} DW_FluxObserver_MotorControlL_T;

/* Zero-crossing (trigger) state for system '<Root>/FluxObserver' */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S24>/Delay' */
  ZCSigState Delay_Reset_ZCE_o;        /* '<S23>/Delay' */
} ZCE_FluxObserver_MotorControl_T;

/* Block states (default storage) for system '<Root>/PI_Controller' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S108>/Integrator' */
  real32_T Integrator_DSTATE_m;        /* '<S64>/Integrator' */
  uint16_T UnitDelay_DSTATE;           /* '<S124>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_o;        /* '<S34>/Unit Delay' */
  int8_T Integrator_PrevResetState;    /* '<S108>/Integrator' */
  int8_T Integrator_PrevResetState_l;  /* '<S64>/Integrator' */
} DW_PI_Controller_MotorControl_T;

/* Block signals for system '<Root>/Position observer' */
typedef struct {
  real32_T UnitDelay;                  /* '<S129>/Unit Delay' */
  int16_T Sum1;                        /* '<S140>/Sum1' */
  int16_T Sum1_p;                      /* '<S137>/Sum1' */
  int16_T UnitDelay_n;                 /* '<S11>/Unit Delay' */
  int16_T UnitDelay1;                  /* '<S11>/Unit Delay1' */
  int16_T UnitDelay_j;                 /* '<S130>/Unit Delay' */
} B_Positionobserver_MotorContr_T;

/* Block states (default storage) for system '<Root>/Position observer' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S129>/Unit Delay' */
  real32_T UnitDelay_DSTATE_c;         /* '<S135>/Unit Delay' */
  int16_T UnitDelay_DSTATE_g;          /* '<S130>/Unit Delay' */
  int16_T UnitDelay_DSTATE_m;          /* '<S138>/Unit Delay' */
  int16_T Delay_DSTATE;                /* '<S138>/Delay' */
  int16_T Delay1_DSTATE;               /* '<S140>/Delay1' */
  int16_T Delay1_DSTATE_m;             /* '<S137>/Delay1' */
  int16_T Delay_DSTATE_l;              /* '<S131>/Delay' */
  int16_T Delay_DSTATE_k;              /* '<S132>/Delay' */
  int16_T Delay_DSTATE_b;              /* '<S134>/Delay' */
  int16_T Delay_DSTATE_e;              /* '<S133>/Delay' */
  int16_T UnitDelay_DSTATE_cm;         /* '<S11>/Unit Delay' */
  int16_T UnitDelay_DSTATE_k;          /* '<S131>/Unit Delay' */
  int16_T UnitDelay_DSTATE_o;          /* '<S132>/Unit Delay' */
  int16_T UnitDelay1_DSTATE;           /* '<S11>/Unit Delay1' */
  int16_T UnitDelay_DSTATE_p;          /* '<S134>/Unit Delay' */
  int16_T UnitDelay_DSTATE_mq;         /* '<S133>/Unit Delay' */
  boolean_T Positionobserver_MODE;     /* '<Root>/Position observer' */
} DW_Positionobserver_MotorCont_T;

/* Zero-crossing (trigger) state for system '<Root>/Position observer' */
typedef struct {
  ZCSigState Delay1_Reset_ZCE;         /* '<S140>/Delay1' */
  ZCSigState Delay1_Reset_ZCE_j;       /* '<S137>/Delay1' */
} ZCE_Positionobserver_MotorCon_T;

/* Block signals (default storage) */
typedef struct {
  real32_T RateTransition3;            /* '<Root>/Rate Transition3' */
  real32_T RateTransition2;            /* '<Root>/Rate Transition2' */
  boolean_T RateTransition4;           /* '<Root>/Rate Transition4' */
  boolean_T FixPtRelationalOperator;   /* '<S150>/FixPt Relational Operator' */
  B_Positionobserver_MotorContr_T Positionobserver;/* '<Root>/Position observer' */
  B_FluxObserver_MotorControlLi_T FluxObserver;/* '<Root>/FluxObserver' */
} B_MotorControlLib_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay1_DSTATE;          /* '<S12>/Unit Delay1' */
  real32_T RateTransition3_Buffer0;    /* '<Root>/Rate Transition3' */
  real32_T RateTransition2_Buffer0;    /* '<Root>/Rate Transition2' */
  uint16_T UnitDelay1_DSTATE_o;        /* '<S147>/Unit Delay1' */
  int16_T DiscreteTimeIntegrator_DSTATE;/* '<S143>/Discrete-Time Integrator' */
  int16_T DelayInput1_DSTATE;          /* '<S150>/Delay Input1' */
  int16_T RateTransition1_Buffer;      /* '<Root>/Rate Transition1' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S142>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S145>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE_m;       /* '<S142>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_p;        /* '<S143>/Unit Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S143>/Discrete-Time Integrator' */
  boolean_T RateTransition4_Buffer0;   /* '<Root>/Rate Transition4' */
  boolean_T Memory_PreviousInput;      /* '<S148>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S149>/Memory' */
  MdlrefDW_ADCRawToIab_T ADCRAwToCurrentIabc_InstanceDat;/* '<Root>/ADCRAwToCurrent(Iabc)' */
  MdlrefDW_ConvertPWMtoAngle_T PWMangledecoder_InstanceData;/* '<Root>/PWM angle decoder' */
  MdlrefDW_SafetyChecks_T SafetyChecks_InstanceData;/* '<Root>/SafetyChecks' */
  DW_Positionobserver_MotorCont_T Positionobserver;/* '<Root>/Position observer' */
  DW_PI_Controller_MotorControl_T PI_Controller;/* '<Root>/PI_Controller' */
  DW_FluxObserver_MotorControlL_T FluxObserver;/* '<Root>/FluxObserver' */
} DW_MotorControlLib_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_Positionobserver_MotorCon_T Positionobserver;/* '<Root>/Position observer' */
  ZCE_FluxObserver_MotorControl_T FluxObserver;/* '<Root>/FluxObserver' */
} PrevZCX_MotorControlLib_T;

/* Invariant block signals for system '<Root>/FluxObserver' */
typedef struct {
  const boolean_T Compare;             /* '<S25>/Compare' */
  const boolean_T Compare_l;           /* '<S26>/Compare' */
} ConstB_FluxObserver_MotorCont_T;

/* Invariant block signals (default storage) */
typedef struct {
  ConstB_FluxObserver_MotorCont_T FluxObserver;/* '<Root>/FluxObserver' */
} ConstB_MotorControlLib_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Position;                   /* '<Root>/Position' */
} ExtY_MotorControlLib_T;

/* Real-time Model Data Structure */
struct tag_RTM_MotorControlLib_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_MotorControlLib_T MotorControlLib_B;

/* Block states (default storage) */
extern DW_MotorControlLib_T MotorControlLib_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_MotorControlLib_T MotorControlLib_Y;
extern const ConstB_MotorControlLib_T MotorControlLib_ConstB;/* constant block i/o */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern boolean_T enableFluxObs;        /* '<Root>/Inport2' */
extern uint8_T set_AngleInput;         /* '<Root>/Inport1' */
extern boolean_T enablePositionObs;    /* '<Root>/Inport3' */
extern int16_T dth_dt;                 /* '<Root>/Inport4' */
extern boolean_T resetPIIntegrator;    /* '<Root>/Inport5' */
extern boolean_T Sig_change_SVMalgorithm;/* '<Root>/In1' */
extern boolean_T resetPIIntegratorDQ;  /* '<Root>/Inport6' */
extern boolean_T setAngleFormat;       /* '<Root>/Input1' */
extern real32_T Sig_theta_el_m;        /* '<Root>/Delay' */
extern real32_T Sig_Ia_m;              /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern real32_T Sig_Ib_m;              /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern real32_T Sig_cos_m;             /* '<S16>/Sum6' */
extern real32_T Sig_Ibeta_m;           /* '<S1>/one_by_sqrt3' */
extern real32_T Sig_sin_m;             /* '<S16>/Sum4' */
extern real32_T Sig_Iq_Soll;           /* '<S14>/Tq--> iqRef' */
extern real32_T Sig_dAxis_m;           /* '<Root>/Gain2' */
extern real32_T Sig_qAxis_m;           /* '<Root>/Gain3' */
extern real32_T Sig_Vqsatu_m;          /* '<Root>/DQ_Limiter' */
extern real32_T Sig_Vdsatu_m;          /* '<Root>/DQ_Limiter' */
extern real32_T Sig_Va_m;              /* '<Root>/Gain' */
extern real32_T Sig_Vb_m;              /* '<Root>/Gain1' */
extern real32_T Sig_Valpha_m;          /* '<S9>/Switch' */
extern real32_T Sig_Vbeta_m;           /* '<S9>/Switch1' */
extern real32_T Sig_Vgamma_m;          /* '<S9>/Switch2' */
extern real32_T Angle_sensor_in;       /* '<Root>/PWM angle decoder' */
extern real32_T Sig_Theta_el_cont_m;   /* '<S12>/Switch' */
extern real32_T Sig_dAxis_PI_out;      /* '<S115>/Saturation' */
extern real32_T Sig_qAxis_PI_out;      /* '<S71>/Saturation' */
extern int16_T constantAngle;          /* '<S143>/Discrete-Time Integrator' */
extern int16_T PositionObsAnlge;       /* '<S128>/Data Type Conversion5' */
extern int16_T FluxObsAngle;           /* '<S21>/PositionGain' */
extern boolean_T Sig_qSollIsNegative;  /* '<S3>/Compare' */
extern real32_T Sig_Emfobs_errorSum_m; /* '<S129>/Add6' */
extern real32_T Sig_Emfobs_PI_out;     /* '<S136>/Saturation' */
extern real32_T di_dt_E9;              /* '<S135>/Inductance' */
extern real32_T di_dt_times_Ts_En8;    /* '<S135>/Gain' */
extern real32_T i_integrated_en4;      /* '<S135>/Sum' */
extern real32_T i_integrated_times_Rs_en8;/* '<S135>/Resistance' */
extern real32_T Va_all_16En4;          /* '<S135>/Add5' */
extern int16_T Sig_First_LPF_out;      /* '<S131>/Product1'
                                        * 16En6
                                        */
extern int16_T Sig_Second_LPF_out;     /* '<S132>/Product1'
                                        * 16En6
                                        */
extern real32_T Sig_dAxis_errorSum_m;  /* '<S8>/Add' */
extern real32_T Sig_qAxis_errorSum_m;  /* '<S8>/Add1' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T TsIntern;              /* Variable: TsIntern
                                        * Referenced by:
                                        *   '<S135>/Gain'
                                        *   '<S138>/Gain'
                                        * fixdt(0,32,2^-24,0)
                                        */
extern int16_T MaxBckEMFVol_sat_neg;   /* Variable: MaxBckEMFVol_sat_neg
                                        * Referenced by:
                                        *   '<S136>/Saturation'
                                        *   '<S139>/Saturation'
                                        * fixdt(1,16,2^-2,0)
                                        */
extern int16_T MaxBckEMFVol_sat_pos;   /* Variable: MaxBckEMFVol_sat_pos
                                        * Referenced by:
                                        *   '<S136>/Saturation'
                                        *   '<S139>/Saturation'
                                        * fixdt(1,32,2^-8,0)
                                        */
extern int16_T Ki_Iab_EMFobs;          /* Variable: Ki_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S137>/Ki'
                                        *   '<S140>/Ki'
                                        * fixdt(1,16,2^-3,0)
                                        */
extern int16_T d_q_Voltage_Limiter_max;/* Variable: d_q_Voltage_Limiter_max
                                        * Referenced by: '<Root>/DQ_Limiter'
                                        * =12/sqrt(3)
                                        */
extern int16_T d_q_Voltage_Limiter_sat_neg;/* Variable: d_q_Voltage_Limiter_sat_neg
                                            * Referenced by:
                                            *   '<S57>/DeadZone'
                                            *   '<S71>/Saturation'
                                            *   '<S101>/DeadZone'
                                            *   '<S115>/Saturation'
                                            * fixdt(1,16,2^-4,0)
                                            */
extern int16_T d_q_Voltage_Limiter_sat_pos;/* Variable: d_q_Voltage_Limiter_sat_pos
                                            * Referenced by:
                                            *   '<S57>/DeadZone'
                                            *   '<S71>/Saturation'
                                            *   '<S101>/DeadZone'
                                            *   '<S115>/Saturation'
                                            * fixdt(1,16,2^-4,0)
                                            */
extern int16_T Ki_dAxis;               /* Variable: Ki_dAxis
                                        * Referenced by: '<S8>/Constant7'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Ki_qAxis;               /* Variable: Ki_qAxis
                                        * Referenced by: '<S8>/Constant5'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Kp_dAxis;               /* Variable: Kp_dAxis
                                        * Referenced by: '<S8>/Constant6'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Kp_qAxis;               /* Variable: Kp_qAxis
                                        * Referenced by: '<S8>/Constant4'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Kp_Iab_EMFobs;          /* Variable: Kp_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S136>/Kp'
                                        *   '<S139>/Kp'
                                        * fixdt(1,16,2^-8,0)
                                        */
extern int16_T qSoll;                  /* Variable: qSoll
                                        * Referenced by: '<Root>/q Soll'
                                        * fixdt(1,16,2^-8,0)
                                        */
extern uint16_T MaximumCurrentBeforeReaction;/* Variable: MaximumCurrentBeforeReaction
                                              * Referenced by: '<Root>/SafetyChecks'
                                              * Maximum current limit before softare shutdowns the mosfets.
                                              */
extern uint16_T CuttOffFreq_c;         /* Variable: CuttOffFreq_c
                                        * Referenced by:
                                        *   '<S131>/Constant'
                                        *   '<S132>/Constant'
                                        *   '<S133>/Constant'
                                        *   '<S134>/Constant'
                                        */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern real32_T UnitDelayIntegratorPosObs;/* '<S135>/Delay' */

/* Model entry point functions */
extern void MotorControlLib_initialize(void);
extern void MotorControlLib_step(void);
extern void MotorControlLib_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MotorControlLib_T *const MotorControlLib_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Propagation' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Conversion' : Unused code path elimination
 * Block '<S21>/Data Type Conversion1' : Unused code path elimination
 * Block '<S21>/FluxGain' : Unused code path elimination
 * Block '<S21>/Product' : Unused code path elimination
 * Block '<S21>/Product1' : Unused code path elimination
 * Block '<S21>/Sqrt' : Unused code path elimination
 * Block '<S21>/Square' : Unused code path elimination
 * Block '<S21>/Square1' : Unused code path elimination
 * Block '<S21>/Sum' : Unused code path elimination
 * Block '<S21>/Sum1' : Unused code path elimination
 * Block '<S21>/TorqueGain' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Propagation' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Propagation' : Unused code path elimination
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S15>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S22>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S22>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S22>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<Root>/Gain4' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain5' : Eliminated nontunable gain of 1
 * Block '<S11>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S11>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S135>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S129>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S129>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S129>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S129>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S130>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S130>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S130>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S130>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S12>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S31>/Offset' : Unused code path elimination
 * Block '<S31>/Unary_Minus' : Unused code path elimination
 * Block '<S127>/Offset' : Unused code path elimination
 * Block '<S127>/Unary_Minus' : Unused code path elimination
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
 * '<S1>'   : 'MotorControlLib/Clarke Transform'
 * '<S2>'   : 'MotorControlLib/Compare To Zero'
 * '<S3>'   : 'MotorControlLib/Compare To Zero1'
 * '<S4>'   : 'MotorControlLib/CosSin'
 * '<S5>'   : 'MotorControlLib/DQ_Limiter'
 * '<S6>'   : 'MotorControlLib/FluxObserver'
 * '<S7>'   : 'MotorControlLib/Inverse Park Transform'
 * '<S8>'   : 'MotorControlLib/PI_Controller'
 * '<S9>'   : 'MotorControlLib/PWM Output'
 * '<S10>'  : 'MotorControlLib/Park Transform'
 * '<S11>'  : 'MotorControlLib/Position observer'
 * '<S12>'  : 'MotorControlLib/Prepare theta el. for RPM'
 * '<S13>'  : 'MotorControlLib/Start up'
 * '<S14>'  : 'MotorControlLib/torqueToIq'
 * '<S15>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup'
 * '<S16>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/Interpolation'
 * '<S17>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp'
 * '<S18>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S19>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S20>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S21>'  : 'MotorControlLib/FluxObserver/FluxObserver'
 * '<S22>'  : 'MotorControlLib/FluxObserver/FluxObserver/atan2'
 * '<S23>'  : 'MotorControlLib/FluxObserver/FluxObserver/psiAlpha'
 * '<S24>'  : 'MotorControlLib/FluxObserver/FluxObserver/psiBeta'
 * '<S25>'  : 'MotorControlLib/FluxObserver/FluxObserver/atan2/Compare To Constant'
 * '<S26>'  : 'MotorControlLib/FluxObserver/FluxObserver/atan2/Compare To Constant1'
 * '<S27>'  : 'MotorControlLib/FluxObserver/FluxObserver/atan2/If Action Subsystem'
 * '<S28>'  : 'MotorControlLib/FluxObserver/FluxObserver/atan2/per Uint'
 * '<S29>'  : 'MotorControlLib/FluxObserver/FluxObserver/psiAlpha/Scaling'
 * '<S30>'  : 'MotorControlLib/FluxObserver/FluxObserver/psiBeta/Scaling'
 * '<S31>'  : 'MotorControlLib/Inverse Park Transform/Switch_Axis'
 * '<S32>'  : 'MotorControlLib/PI_Controller/PID q-Axis'
 * '<S33>'  : 'MotorControlLib/PI_Controller/PID q-Axis1'
 * '<S34>'  : 'MotorControlLib/PI_Controller/disable integrator on start up'
 * '<S35>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Anti-windup'
 * '<S36>'  : 'MotorControlLib/PI_Controller/PID q-Axis/D Gain'
 * '<S37>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Filter'
 * '<S38>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Filter ICs'
 * '<S39>'  : 'MotorControlLib/PI_Controller/PID q-Axis/I Gain'
 * '<S40>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Ideal P Gain'
 * '<S41>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Ideal P Gain Fdbk'
 * '<S42>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Integrator'
 * '<S43>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Integrator ICs'
 * '<S44>'  : 'MotorControlLib/PI_Controller/PID q-Axis/N Copy'
 * '<S45>'  : 'MotorControlLib/PI_Controller/PID q-Axis/N Gain'
 * '<S46>'  : 'MotorControlLib/PI_Controller/PID q-Axis/P Copy'
 * '<S47>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Parallel P Gain'
 * '<S48>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Reset Signal'
 * '<S49>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Saturation'
 * '<S50>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Saturation Fdbk'
 * '<S51>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Sum'
 * '<S52>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Sum Fdbk'
 * '<S53>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Tracking Mode'
 * '<S54>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Tracking Mode Sum'
 * '<S55>'  : 'MotorControlLib/PI_Controller/PID q-Axis/postSat Signal'
 * '<S56>'  : 'MotorControlLib/PI_Controller/PID q-Axis/preSat Signal'
 * '<S57>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Anti-windup/Disc. Clamping Parallel'
 * '<S58>'  : 'MotorControlLib/PI_Controller/PID q-Axis/D Gain/Disabled'
 * '<S59>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Filter/Disabled'
 * '<S60>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Filter ICs/Disabled'
 * '<S61>'  : 'MotorControlLib/PI_Controller/PID q-Axis/I Gain/External Parameters'
 * '<S62>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Ideal P Gain/Passthrough'
 * '<S63>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Ideal P Gain Fdbk/Disabled'
 * '<S64>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Integrator/Discrete'
 * '<S65>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Integrator ICs/Internal IC'
 * '<S66>'  : 'MotorControlLib/PI_Controller/PID q-Axis/N Copy/Disabled wSignal Specification'
 * '<S67>'  : 'MotorControlLib/PI_Controller/PID q-Axis/N Gain/Disabled'
 * '<S68>'  : 'MotorControlLib/PI_Controller/PID q-Axis/P Copy/Disabled'
 * '<S69>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Parallel P Gain/External Parameters'
 * '<S70>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Reset Signal/External Reset'
 * '<S71>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Saturation/Enabled'
 * '<S72>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Saturation Fdbk/Disabled'
 * '<S73>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Sum/Sum_PI'
 * '<S74>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Sum Fdbk/Disabled'
 * '<S75>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Tracking Mode/Disabled'
 * '<S76>'  : 'MotorControlLib/PI_Controller/PID q-Axis/Tracking Mode Sum/Passthrough'
 * '<S77>'  : 'MotorControlLib/PI_Controller/PID q-Axis/postSat Signal/Forward_Path'
 * '<S78>'  : 'MotorControlLib/PI_Controller/PID q-Axis/preSat Signal/Forward_Path'
 * '<S79>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/Anti-windup'
 * '<S80>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/D Gain'
 * '<S81>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/Filter'
 * '<S82>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/Filter ICs'
 * '<S83>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/I Gain'
 * '<S84>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/Ideal P Gain'
 * '<S85>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/Ideal P Gain Fdbk'
 * '<S86>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/Integrator'
 * '<S87>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/Integrator ICs'
 * '<S88>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/N Copy'
 * '<S89>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/N Gain'
 * '<S90>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/P Copy'
 * '<S91>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/Parallel P Gain'
 * '<S92>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/Reset Signal'
 * '<S93>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/Saturation'
 * '<S94>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/Saturation Fdbk'
 * '<S95>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/Sum'
 * '<S96>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/Sum Fdbk'
 * '<S97>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/Tracking Mode'
 * '<S98>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/Tracking Mode Sum'
 * '<S99>'  : 'MotorControlLib/PI_Controller/PID q-Axis1/postSat Signal'
 * '<S100>' : 'MotorControlLib/PI_Controller/PID q-Axis1/preSat Signal'
 * '<S101>' : 'MotorControlLib/PI_Controller/PID q-Axis1/Anti-windup/Disc. Clamping Parallel'
 * '<S102>' : 'MotorControlLib/PI_Controller/PID q-Axis1/D Gain/Disabled'
 * '<S103>' : 'MotorControlLib/PI_Controller/PID q-Axis1/Filter/Disabled'
 * '<S104>' : 'MotorControlLib/PI_Controller/PID q-Axis1/Filter ICs/Disabled'
 * '<S105>' : 'MotorControlLib/PI_Controller/PID q-Axis1/I Gain/External Parameters'
 * '<S106>' : 'MotorControlLib/PI_Controller/PID q-Axis1/Ideal P Gain/Passthrough'
 * '<S107>' : 'MotorControlLib/PI_Controller/PID q-Axis1/Ideal P Gain Fdbk/Disabled'
 * '<S108>' : 'MotorControlLib/PI_Controller/PID q-Axis1/Integrator/Discrete'
 * '<S109>' : 'MotorControlLib/PI_Controller/PID q-Axis1/Integrator ICs/Internal IC'
 * '<S110>' : 'MotorControlLib/PI_Controller/PID q-Axis1/N Copy/Disabled wSignal Specification'
 * '<S111>' : 'MotorControlLib/PI_Controller/PID q-Axis1/N Gain/Disabled'
 * '<S112>' : 'MotorControlLib/PI_Controller/PID q-Axis1/P Copy/Disabled'
 * '<S113>' : 'MotorControlLib/PI_Controller/PID q-Axis1/Parallel P Gain/External Parameters'
 * '<S114>' : 'MotorControlLib/PI_Controller/PID q-Axis1/Reset Signal/External Reset'
 * '<S115>' : 'MotorControlLib/PI_Controller/PID q-Axis1/Saturation/Enabled'
 * '<S116>' : 'MotorControlLib/PI_Controller/PID q-Axis1/Saturation Fdbk/Disabled'
 * '<S117>' : 'MotorControlLib/PI_Controller/PID q-Axis1/Sum/Sum_PI'
 * '<S118>' : 'MotorControlLib/PI_Controller/PID q-Axis1/Sum Fdbk/Disabled'
 * '<S119>' : 'MotorControlLib/PI_Controller/PID q-Axis1/Tracking Mode/Disabled'
 * '<S120>' : 'MotorControlLib/PI_Controller/PID q-Axis1/Tracking Mode Sum/Passthrough'
 * '<S121>' : 'MotorControlLib/PI_Controller/PID q-Axis1/postSat Signal/Forward_Path'
 * '<S122>' : 'MotorControlLib/PI_Controller/PID q-Axis1/preSat Signal/Forward_Path'
 * '<S123>' : 'MotorControlLib/PI_Controller/disable integrator on start up/Compare To Constant'
 * '<S124>' : 'MotorControlLib/PI_Controller/disable integrator on start up/Subsystem'
 * '<S125>' : 'MotorControlLib/PWM Output/Inverse Clarke Transform'
 * '<S126>' : 'MotorControlLib/PWM Output/Space Vector Generator'
 * '<S127>' : 'MotorControlLib/Park Transform/Switch_Axis'
 * '<S128>' : 'MotorControlLib/Position observer/Atan2'
 * '<S129>' : 'MotorControlLib/Position observer/EMF Observer Ia'
 * '<S130>' : 'MotorControlLib/Position observer/EMF Observer Ia2'
 * '<S131>' : 'MotorControlLib/Position observer/Low pass filter'
 * '<S132>' : 'MotorControlLib/Position observer/Low pass filter1'
 * '<S133>' : 'MotorControlLib/Position observer/Low pass filter2'
 * '<S134>' : 'MotorControlLib/Position observer/Low pass filter3'
 * '<S135>' : 'MotorControlLib/Position observer/EMF Observer Ia/DC Motor Model'
 * '<S136>' : 'MotorControlLib/Position observer/EMF Observer Ia/PI Controller'
 * '<S137>' : 'MotorControlLib/Position observer/EMF Observer Ia/PI Controller/Anti-windup'
 * '<S138>' : 'MotorControlLib/Position observer/EMF Observer Ia2/DC Motor Model'
 * '<S139>' : 'MotorControlLib/Position observer/EMF Observer Ia2/PI Controller'
 * '<S140>' : 'MotorControlLib/Position observer/EMF Observer Ia2/PI Controller/Anti-windup'
 * '<S141>' : 'MotorControlLib/Prepare theta el. for RPM/Compare To Constant'
 * '<S142>' : 'MotorControlLib/Start up/Logic after motor is stoped'
 * '<S143>' : 'MotorControlLib/Start up/Simulate start up Theta'
 * '<S144>' : 'MotorControlLib/Start up/Logic after motor is stoped/Compare To Zero'
 * '<S145>' : 'MotorControlLib/Start up/Logic after motor is stoped/Detect Decrease'
 * '<S146>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem'
 * '<S147>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem1'
 * '<S148>' : 'MotorControlLib/Start up/Logic after motor is stoped/S-R Flip-Flop'
 * '<S149>' : 'MotorControlLib/Start up/Logic after motor is stoped/S-R Flip-Flop1'
 * '<S150>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem/Detect Change'
 */
#endif                                 /* RTW_HEADER_MotorControlLib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
