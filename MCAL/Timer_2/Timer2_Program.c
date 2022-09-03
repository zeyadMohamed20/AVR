/*
 * Timer2_Program.c
 *
 *  Created on: Aug 31, 2022
 *      Author: Samy
 */

#include "Timer2_Interface.h"
#include "TImer2_Pivate.h"

u32 Timer2_u32_NumOfOVF;
u32 Timer2_u32_NumOfCompMatch;
u8 Timer2_u8_RemTicks;
void (*Timer2_CallBack[2])(void) = {NULL};


void M_Timer_2_void_Init(void)
{
#if(TIMER_2_MODE	==	 TIMER2_NORMAL_MODE)
	// to select normal mode
	CLR_BIT(TCCR2_REG,WGM21_BIT);
	CLR_BIT(TCCR2_REG,WGM20_BIT);
#if(TIMER_2_OC2_MODE >= 0 && TIMER_2_OC2_MODE <= 3)
	// apply mask
	TCCR2_REG &= TIMER2_OC2_MASK;
	// insert value
	TCCR2_REG |= (TIMER_2_OC2_MODE << TIMER2_OC2_SHIFT);

#else
#error ("Wrong OC2 mode")

#endif

#elif(TIMER_2_MODE	==	 TIMER2_CTC_MODE)

	SET_BIT(TCCR2_REG,WGM21_BIT);
	CLR_BIT(TCCR2_REG,WGM20_BIT);

#elif(TIMER_2_MODE	==	 TIMER2_PHASECORRECT_MODE)
	CLR_BIT(TCCR2_REG,WGM21_BIT);
	SET_BIT(TCCR2_REG,WGM20_BIT);
#if(TIMER_2_OC2_MODE	==	TIMER2_OC2_PWM_NON_INVERTING	||	TIMER_2_OC2_MODE	==	TIMER2_OC2_PWM_INVERTING)
	// apply mask
	TCCR2_REG &= TIMER2_OC2_MASK;
	// insert value
	TCCR2_REG |= TIMER_2_OC2_MODE;

#else
#error ("Wrong OC2 mode")

#endif

#elif(TIMER_2_MODE	==	 TIMER2_FASTPWM_MODE)
	SET_BIT(TCCR2_REG,WGM21_BIT);
	SET_BIT(TCCR2_REG,WGM20_BIT);
#if(TIMER_2_OC2_MODE	==	TIMER2_OC2_PWM_NON_INVERTING	||	TIMER_2_OC2_MODE	==	TIMER2_OC2_PWM_INVERTING)
	// apply mask
	TCCR2_REG &= TIMER2_OC2_MASK;
	// insert value
	TCCR2_REG |= TIMER_2_OC2_MODE;


#else
#error ("Wrong OC2 mode")

#endif

#else
#error ("Wrong timer mode")

#endif

}

void M_Timer_2_void_SetTime(u32 Copy_u32_DesiredTime)
{
	u32 Local_arr_Prescalar[5] = {1,8,64,256,1024};
	u32 Local_u32_TickTime   = Local_arr_Prescalar[TIMER_2_PRESCALER-1] / F_OSC;	// result in micro
	u32 Local_u32_TotalTicks = (Copy_u32_DesiredTime * 1000) / Local_u32_TickTime;
#if(TIMER_2_MODE	==	TIMER2_NORMAL_MODE)
	Timer2_u32_NumOfOVF 	 = Local_u32_TotalTicks / 256;
	Timer2_u8_RemTicks 		 = Local_u32_TotalTicks % 256;
	if(Timer2_u8_RemTicks != 0)
	{
		TCNT2_REG = 256 - Timer2_u8_RemTicks;
		Timer2_u32_NumOfOVF++;
	}
#elif(TIMER_2_MODE	==	TIMER2_CTC_MODE)
	u8 Local_u8_Counter = 255;
	while(Local_u32_TotalTicks % Local_u8_Counter)
		Local_u8_Counter--;
	Timer2_u32_NumOfCompMatch = Local_u32_TotalTicks / Local_u8_Counter;
	OCR2_REG = Local_u8_Counter;

#endif

}

void M_Timer_2_void_SetFastPWM(u8 Copy_u8_DutyCycle)
{
#if(TIMER_2_MODE	==	TIMER2_FASTPWM_MODE)
#if(TIMER_2_OC2_MODE	==	TIMER2_OC2_PWM_NON_INVERTING)
	OCR2_REG = abs(((Copy_u8_DutyCycle * 256)/100)-1);

#elif(TIMER_2_OC2_MODE	==	TIMER2_OC2_PWM_INVERTING)
	OCR2_REG = abs(255-((Copy_u8_DutyCycle * 256)/100));

#else
#error ("Wrong OC2 mode")

#endif

#endif
}

void M_Timer_2_void_SetPhaseCorrectPWM(u8 Copy_u8_DutyCycle)
{
#if(TIMER_2_MODE	==	TIMER2_PHASECORRECT_MODE)
#if(TIMER_2_OC2_MODE	==	TIMER2_OC2_PWM_NON_INVERTING)
	OCR2_REG = (Copy_u8_DutyCycle * 255) / 100;

#elif(TIMER_2_OC2_MODE	==	TIMER2_OC2_PWM_INVERTING)
	OCR2_REG = 255 - ((Copy_u8_DutyCycle * 255) / 100;);

#else
#error ("Wrong OC0 mode")

#endif

#endif
}

void M_Timer_2_void_Start(void)
{
#if(TIMER_2_PRESCALER >0 && TIMER_2_PRESCALER <= 7)
	// apply timer mask
	TCCR2_REG &= TIMER2_PRESCALAR_MASK;

	TCCR2_REG |= TIMER_2_PRESCALER;

#else
#error ("Wrong choice")

#endif

}

void M_Timer_2_void_Stop(void)
{
	CLR_BIT(TCCR2_REG,CS20_BIT);
	CLR_BIT(TCCR2_REG,CS21_BIT);
	CLR_BIT(TCCR2_REG,CS22_BIT);
}

void M_Timer_2_void_SetCallBack(void (*Copy_Ptr)(void) , u8 Copy_u8_IntId)
{
	Timer2_CallBack[Copy_u8_IntId] = Copy_Ptr;
}

void M_Timer_2_void_EnableInt(u8 Copy_u8_IntId)
{
	switch(Copy_u8_IntId)
	{
	case TIMER2_OVF_INT_ID:
		SET_BIT(TIMSK_REG,TOIE2_BIT);
		break;
	case TIMER2_COMP_MATCH_INT_ID:
		SET_BIT(TIMSK_REG,OCIE2_BIT);
		break;
	default:
		break;
	}
}

void M_Timer_2_void_DisableInt(u8 Copy_u8_IntId)
{
	switch(Copy_u8_IntId)
	{
	case TIMER2_OVF_INT_ID:
		CLR_BIT(TIMSK_REG,TOIE2_BIT);
		break;
	case TIMER2_COMP_MATCH_INT_ID:
		CLR_BIT(TIMSK_REG,OCIE2_BIT);
		break;
	}
}

ISR(TIMER2_OVF_vect)
{
	if(Timer2_CallBack != NULL)
	{
		static u32 Local_u32_Counter = 0;
		Local_u32_Counter++;
		if(Local_u32_Counter == Timer2_u32_NumOfOVF)
		{
			Timer2_CallBack[TIMER2_OVF_INT_ID]();
			Local_u32_Counter = 0;
			TCNT2_REG = 256 - Timer2_u8_RemTicks;
		}
	}
}

ISR(TIMER2_COMP_vect)
{
	if(Timer2_CallBack != NULL)
	{
		static u32 Local_u32_Counter = 0;
		Local_u32_Counter++;
		if(Local_u32_Counter == Timer2_u32_NumOfCompMatch)
		{
			Timer2_CallBack[TIMER2_COMP_MATCH_INT_ID]();
			Local_u32_Counter = 0;
		}
	}
}

