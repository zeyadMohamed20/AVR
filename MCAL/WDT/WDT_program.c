/*
 * WDT_program.c
 *
 *  Created on: Aug 31, 2022
 *      Author: zeyad
 */

#include "WDT_interface.h"
#include "WDT_private.h"

void M_WDT_void_Enable(void)
{
	SET_BIT(WDTCR_REG,WDE_BIT);
}

void M_WDT_void_Disable(void)
{
	WDTCR_REG |= (1<<WDTOE_BIT) | (1<<WDE_BIT);
	WDTCR_REG = 0x00;
}

void M_WDT_void_Sleep(u8 Copy_u8_Time)
{
	//step 1: Apply Mask
	WDTCR_REG &= WDT_PRESCALER_MASK;
	//step 2: Insert Prescaler
	WDTCR_REG |= Copy_u8_Time;
}

void M_WDT_void_Refresh(void)
{
	asm("WDR");
}

