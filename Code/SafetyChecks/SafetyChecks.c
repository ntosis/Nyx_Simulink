/*
 * File: SafetyChecks.c
 *
 * Code generated for Simulink model 'SafetyChecks'.
 *
 * Model version                  : 5.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 28 17:26:33 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SafetyChecks.h"
#include "rtwtypes.h"
#include <math.h>
#include "InterfaceBswApp.h"
#include "SafetyChecks_private.h"

/* Disable for referenced model: 'SafetyChecks' */
void SafetyChecks_Disable(DW_SafetyChecks_f_T *localDW)
{
  /* Disable for Enabled SubSystem: '<Root>/delay error reaction' */
  if (localDW->delayerrorreaction_MODE) {
    /* Disable for RelationalOperator: '<S4>/Relational Operator' incorporates:
     *  Outport: '<S4>/error reaction'
     */
    emergency_disable_hardware(false);
    localDW->delayerrorreaction_MODE = false;
  }

  /* End of Disable for SubSystem: '<Root>/delay error reaction' */
}

/* Output and update for referenced model: 'SafetyChecks' */
void SafetyChecks(const real32_T rtu_Iab[2], DW_SafetyChecks_f_T *localDW)
{
  real32_T tmp;

  /* Constant: '<S1>/Constant' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S3>/Constant'
   */
  tmp = (real32_T)MaximumCurrentBeforeReaction * 0.00390625F;

  /* Outputs for Enabled SubSystem: '<Root>/delay error reaction' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Logic: '<Root>/OR' incorporates:
   *  Abs: '<Root>/Abs'
   *  Abs: '<Root>/Abs1'
   *  Abs: '<Root>/Abs2'
   *  Constant: '<S1>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   *  RelationalOperator: '<S2>/Compare'
   *  RelationalOperator: '<S3>/Compare'
   *  Sum: '<Root>/Add'
   */
  if ((fabsf((0.0F - rtu_Iab[0]) - rtu_Iab[1]) > tmp) || (fabsf(rtu_Iab[0]) >
       tmp) || (fabsf(rtu_Iab[1]) > tmp)) {
    uint16_T rtb_UnitDelay1;
    if (!localDW->delayerrorreaction_MODE) {
      /* InitializeConditions for UnitDelay: '<S4>/Unit Delay1' */
      localDW->UnitDelay1_DSTATE = 0U;
      localDW->delayerrorreaction_MODE = true;
    }

    /* UnitDelay: '<S4>/Unit Delay1' */
    rtb_UnitDelay1 = localDW->UnitDelay1_DSTATE;

    /* Sum: '<S4>/Add' incorporates:
     *  Constant: '<S4>/Constant'
     *  UnitDelay: '<S4>/Unit Delay1'
     */
    localDW->UnitDelay1_DSTATE++;

    /* RelationalOperator: '<S4>/Relational Operator' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    emergency_disable_hardware(rtb_UnitDelay1 >= 125);
  } else if (localDW->delayerrorreaction_MODE) {
    /* Disable for RelationalOperator: '<S4>/Relational Operator' incorporates:
     *  Outport: '<S4>/error reaction'
     */
    emergency_disable_hardware(false);
    localDW->delayerrorreaction_MODE = false;
  }

  /* End of Logic: '<Root>/OR' */
  /* End of Outputs for SubSystem: '<Root>/delay error reaction' */
}

/* Model initialize function */
void SafetyChecks_initialize(const char_T **rt_errorStatus,
  RT_MODEL_SafetyChecks_T *const SafetyChecks_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(SafetyChecks_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
