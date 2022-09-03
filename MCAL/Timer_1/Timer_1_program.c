/*
 * Timer_1_program.c
 *
 *  Created on: Aug 23, 2022
 *      Author: zeyad
 */

#include "Timer_1_interface.h"
#include "Timer_1_private.h"

static void (*Timer1_ICU_CallBack)(void) = NULL;

void M_Timer1_void_Init(void)
{
	//step1: config timer in normal mode
	CLR_BIT(TCCR1A_REG,WGM10_BIT);
	CLR_BIT(TCCR1A_REG,WGM11_BIT);
	CLR_BIT(TCCR1B_REG,WGM12_BIT);
	CLR_BIT(TCCR1B_REG,WGM13_BIT);

	//step2: config prescaler =>256
	CLR_BIT(TCCR1B_REG,CS10_BIT);
	CLR_BIT(TCCR1B_REG,CS11_BIT);
	SET_BIT(TCCR1B_REG,CS12_BIT);
}

void M_Timer1_void_ICU_Init(void)
{
	//set trigger as rising edge
	SET_BIT(TCCR1B_REG,ICES1_BIT);
}

u16 M_Timer1_u16_ICU_inputRead()
{
	return ICR1_REG;
}

void M_Timer1_void_ICU_setCallBack(void(*Copy_Ptr)(void))
{
	Timer1_ICU_CallBack = Copy_Ptr;
}

void M_Timer1_ICU_EnableInt(void)
{
	SET_BIT(TIMSK_REG,TICIE1_BIT);
}

void M_Timer1_ICU_DisableInt(void)
{
	CLR_BIT(TIMSK_REG,TICIE1_BIT);
}

void M_Timer1_ICU_SetTrigger(u8 Copy_u8_Trigger)
{
	//Method 1
	switch(Copy_u8_Trigger)
	{
	case TIMER1_ICU_RISING_TRIGGER:
		SET_BIT(TCCR1B_REG,ICES1_BIT);
		break;
	case TIMER1_ICU_FALLING_TRIGGER:
		CLR_BIT(TCCR1B_REG,ICES1_BIT);
		break;
	default:
		break;
	}
	//Method 2
	/*TCCR1B_REG&=0b1011111;
	TCCR1B_REG|=Copy_u8_Trigger<<6;*/
}

//it is vector 6 as out vector table doesn't begin with reset interrupt
ISR(TIMER1_CAPT_vect)
{
	Timer1_ICU_CallBack();
}
