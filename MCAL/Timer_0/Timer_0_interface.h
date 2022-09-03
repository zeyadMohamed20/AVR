/*
 * Timer_0_interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_TIMER_0_TIMER_0_INTERFACE_H_
#define MCAL_TIMER_0_TIMER_0_INTERFACE_H_
#include "Timer_0_configuration.h"
#include "StandardTypes.h"
#include "BitMath.h"
#include <avr/interrupt.h>
#include <stdlib.h>

#define TIMER0_OVF_INT_ID          0
#define TIMER0_COMP_MATCH_INT_ID   1

void M_Timer_0_void_Init(void);
void M_Timer_0_void_SetTime(u32);
void M_Timer_0_void_Start(void);
void M_Timer_0_void_Stop(void);
void M_Timer_0_void_EnableInt(u8);
void M_Timer_0_void_DisableInt(u8);
void M_Timer_0_SetCallBack(void (*)(void),u8);
void M_Timer_0_SetFastPWM(u8);
void M_Timer_0_SetPhaseCorrect(u8);

#endif /* MCAL_TIMER_0_TIMER_0_INTERFACE_H_ */
