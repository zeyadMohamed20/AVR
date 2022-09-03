/*
 * Timer2_Interface.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Samy
 */

#ifndef TIMER2_TIMER2_INTERFACE_H_
#define TIMER2_TIMER2_INTERFACE_H_

#include "StandardTypes.h"
#include "BitMath.h"
#include "avr/interrupt.h"
#include <stdlib.h>
#include "Timer2_config.h"

#define TIMER2_OVF_INT_ID			0
#define TIMER2_COMP_MATCH_INT_ID	1

void M_Timer_2_void_Init(void);
void M_Timer_2_void_SetTime(u32);
void M_Timer_2_void_Start(void);
void M_Timer_2_void_Stop(void);
void M_Timer_2_void_EnableInt(u8);
void M_Timer_2_void_DisableInt(u8);
void M_Timer_2_void_SetCallBack(void (*)(void) , u8);
void M_Timer_2_void_SetFastPWM(u8);
void M_Timer_2_void_SetPhaseCorrectPWM(u8);

#endif /* TIMER2_TIMER2_INTERFACE_H_ */
