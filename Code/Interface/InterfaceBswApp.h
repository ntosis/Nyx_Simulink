/*
 * InterfaceBswApp.h
 *
 *  Created on: Jan 15, 2021
 *      Author: unix
 */

#ifndef INC_INTERFACE_INTERFACEBSWAPP_H_
#define INC_INTERFACE_INTERFACEBSWAPP_H_

#include <stdint.h>

void set_PWM_A_DT(uint16_t a);
void set_PWM_B_DT(uint16_t a);
void set_PWM_C_DT(uint16_t a);
void writeInFile(void);
void disablePWMInputTimer(void);
extern void TemperatureComp_step(void);


//#define SEMIHOSTING     //Enable Semihostig Functions
//#define EXTENDED_DEBUG  //Enable DAC Debugging and data logging
extern float Iabc[3];
extern char Flags[2];
uint32_t rCpuClocks(void);
void emergency_disable_hardware(uint8_t in);

extern int16_t qSoll;
extern uint16_t rpmSoll;
extern volatile uint32_t *DebugCntr;
extern volatile uint16_t adcBuffer[3];
extern volatile uint16_t DmaBuffer[3];
extern int16_t autoCalADCVal[2];
extern volatile uint16_t PWMdbg[3];
extern uint32_t pwm_set_a_m;
extern uint32_t pwm_set_b_m;
extern uint32_t pwm_set_c_m;
extern uint8_t Sig_requestMotorBreak;
extern uint8_t hasTimer8Overflowed;
extern uint8_t hasMathOverflowed_PWMin;
extern uint8_t NoSignal_PWMin;
extern char hasPWMSignalbeenread;
volatile uint16_t Sig_ADCin_temptr_sens;
extern volatile uint8_t NfaultState;
extern volatile uint8_t NfaultStateRunningCnt;
extern volatile uint16_t faultRegister1Value;
extern volatile uint16_t faultRegister2Value;
extern volatile uint16_t DRVConRegisterValue;
extern volatile uint16_t Duty;
extern uint32_t countWrongSignals;

volatile uint16_t ICValueFalling;
volatile uint16_t ICValueRising;

extern uint8_t Sig_qSollIsNegative;

extern uint8_t countInteruptsinOut;
extern uint8_t StepFunctionisStillRunning;
extern uint8_t EncoderCounterHasOverflowed;
extern uint8_t EncoderCounterHasOverflowedErrorFlag;
extern uint32_t EncoderCounter;

extern volatile uint32_t clocksNeededOfMAtlabFunc;
extern volatile uint32_t clocksNeededOfMAtlabFuncMAX;
extern volatile uint32_t clocksNeededOfMAtlabFuncMIN;
extern float Sig_theta_el_m;        /* '<Root>/Delay' */
extern float Sig_Ia_m;              /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern float Sig_Ib_m;              /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern float Sig_cos_m;             /* '<S12>/Sum6' */
extern float Sig_Ibeta_m;           /* '<S1>/one_by_sqrt3' */
extern float Sig_sin_m;             /* '<S12>/Sum4' */
extern float Sig_Iq_Soll;           /* '<Root>/Tq--> iqRef' */
extern float Sig_dAxis_m;           /* '<Root>/Gain2' */
extern float Sig_qAxis_m;           /* '<Root>/Gain3' */
extern float Sig_Vqsatu_m;          /* '<Root>/DQ_Limiter' */
extern float Sig_Vdsatu_m;          /* '<Root>/DQ_Limiter' */
extern float Sig_Va_m;              /* '<Root>/Gain' */
extern float Sig_Vb_m;              /* '<Root>/Gain1' */
extern float Sig_Valpha_m;          /* '<S7>/Switch' */
extern float Sig_Vbeta_m;           /* '<S7>/Switch1' */
extern float Sig_Vgamma_m;          /* '<S7>/Switch2' */
extern float Sig_dAxis_PI_out;      /* '<S111>/Saturation' */
extern float Sig_qAxis_PI_out;      /* '<S67>/Saturation' */
extern float Sig_dAxis_errorSum_m;  /* '<S6>/Add' */
extern float Sig_qAxis_errorSum_m;  /* '<S6>/Add1' */
extern float PI_q_Integrator;
extern float PI_d_Integrator;
extern int16_t d_q_Voltage_Limiter_sat_neg;
extern int16_t d_q_Voltage_Limiter_sat_pos;
extern char Flags[2];
extern uint16_t Kp_dAxis;
extern void MotorControlLib_initialize(void);
extern void ConvertPWMtoAngle_Init(void);
extern void MotorControlLib_step2(void);
extern void MotorControlLib_step1(void);
extern uint16_t Ki_dAxis;
struct CPU_clocks {
  uint32_t StepFunctionClocks;
  uint32_t FluxObserverClocks;
  uint32_t Step1;
  uint32_t Step2;
  uint32_t Step3;
  uint32_t Step4;
  uint32_t Step5;
  uint32_t Step6;
  uint32_t Step7;
  uint32_t Step8;
  uint32_t Step9;
};

extern uint8_t Sig_speed_timer_has_overflowed;
extern uint8_t EncoderCounterHasOverflowed_2;
extern uint16_t Sig_speed_timer_counter;
extern uint16_t Sig_speed_timer_counter_1z;
#define CounterFactor_us (uint16_t)500 //500 us period
extern void M_Task_Calculate_fast_speed(uint8_t rtu_u);

#ifdef EXTENDED_DEBUG

	#define MAX_DBG_BUFFERSIZE ((uint16_t)512U)

	struct Debug_signals {
		float dbgSig_theta_el_m[MAX_DBG_BUFFERSIZE];               /* '<Root>/Delay' */
		float dbgSig_Ia_m[MAX_DBG_BUFFERSIZE];                     /* '<Root>/ADCRAwToCurrent(Iabc)' */
		float dbgSig_Ib_m[MAX_DBG_BUFFERSIZE];                     /* '<Root>/ADCRAwToCurrent(Iabc)' */
		float dbgSig_dAxis_error[MAX_DBG_BUFFERSIZE];                  /* '<Root>/Gain2' */
		float dbgSig_qAxis_error[MAX_DBG_BUFFERSIZE];                  /* '<Root>/Gain3' */
		float dbgSig_Vqsatu_m[MAX_DBG_BUFFERSIZE];                 /* '<Root>/DQ_Limiter' */
		float dbgSig_Vdsatu_m[MAX_DBG_BUFFERSIZE];                 /* '<Root>/DQ_Limiter' */
		float dbgSig_Va_m[MAX_DBG_BUFFERSIZE];                     /* '<Root>/Gain' */
		float dbgSig_Vb_m[MAX_DBG_BUFFERSIZE];                     /* '<Root>/Gain1' */
		float dbgSig_Valpha_m[MAX_DBG_BUFFERSIZE];                 /* '<S7>/Switch' */
		float dbgSig_Vbeta_m[MAX_DBG_BUFFERSIZE];                  /* '<S7>/Switch1' */
		float dbgSig_Vgamma_m[MAX_DBG_BUFFERSIZE];                 /* '<S7>/Switch2' */
		float dbgSig_dAxis_PI_out[MAX_DBG_BUFFERSIZE];             /* '<S111>/Saturation' */
		float dbgSig_qAxis_PI_out[MAX_DBG_BUFFERSIZE];
		float dbgPI_d_Integrator[MAX_DBG_BUFFERSIZE];
		float dbgPI_q_Integrator[MAX_DBG_BUFFERSIZE];
		char dbgFlag_0[MAX_DBG_BUFFERSIZE];
		int16_t dbgqSoll[MAX_DBG_BUFFERSIZE];
		char dbgFlag_1[MAX_DBG_BUFFERSIZE];
		float dbg_Id_axis_meas[MAX_DBG_BUFFERSIZE];
		float dbg_Iq_axis_meas[MAX_DBG_BUFFERSIZE];
		uint16_t dbgDuty[MAX_DBG_BUFFERSIZE];
		uint16_t dbgadcBuffer_0[MAX_DBG_BUFFERSIZE];
		uint16_t dbgadcBuffer_1[MAX_DBG_BUFFERSIZE];
		uint16_t dbgKpq[MAX_DBG_BUFFERSIZE];
		uint16_t dbgKpd[MAX_DBG_BUFFERSIZE];
		uint16_t dbgPWM_A[MAX_DBG_BUFFERSIZE];
		uint16_t dbgPWM_B[MAX_DBG_BUFFERSIZE];
		uint16_t dbgPWM_C[MAX_DBG_BUFFERSIZE];
		uint32_t  dbgEncoder[MAX_DBG_BUFFERSIZE];
		int16_t  dbgKiq[MAX_DBG_BUFFERSIZE];
		int16_t  dbgKid[MAX_DBG_BUFFERSIZE];
		uint16_t k;
	};


#endif

extern volatile struct CPU_clocks CPU_clocks_ins;
#ifdef EXTENDED_DEBUG
extern volatile struct Debug_signals dbg_obj;
#endif

#endif /* INC_INTERFACE_INTERFACEBSWAPP_H_ */
