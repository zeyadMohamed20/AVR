/*
 * Timer_1_interface.h
 *
 *  Created on: Aug 23, 2022
 *      Author: zeyad
 */

#ifndef TIMER_1_TIMER_1_INTERFACE_H_
#define TIMER_1_TIMER_1_INTERFACE_H_

#include "StandardTypes.h"
#include "BitMath.h"
#include "Timer_1_configuration.h"
#include <avr/interrupt.h>

#define TIMER1_ICU_RISING_TRIGGER  1
#define TIMER1_ICU_FALLING_TRIGGER 0

void M_Timer1_void_Init(void);
void M_Timer1_void_ICU_Init(void);
u16 M_Timer1_u16_ICU_inputRead();
void M_Timer1_void_ICU_setCallBack(void(*)(void));
void M_Timer1_ICU_EnableInt(void);
void M_Timer1_ICU_DisableInt(void);
void M_Timer1_ICU_SetTrigger(u8);


#endif /* TIMER_1_TIMER_1_INTERFACE_H_ */
