/*
 * UART_program.c
 *
 *  Created on: Aug 24, 2022
 *      Author: zeyad
 */

#include "UART_interface.h"
#include "UART_private.h"

void M_UART_void_Init(void)
{
	//step 1: config mode as Asynchronous
	//select register UCSRC
	SET_BIT(UCSRC_REG,URSEL_BIT);
	CLR_BIT(UCSRC_REG,UMSEL_BIT);
	//step 2: Enable Tx and Rx
	SET_BIT(UCSRB_REG,TXEN_BIT);
	SET_BIT(UCSRB_REG,RXEN_BIT);
	//step 3: config data length
	UCSRC_REG &= UART_DATA_SIZE_MASK;
	UCSRC_REG |= UART_DATA_SIZE << 1;
	CLR_BIT(UCSRB_REG,UXSZ2_BIT);
	//step 4: config stop bits
	UCSRC_REG &= UART_STOP_BIT_MASK;
	UCSRC_REG |= UART_STOP_BITS <<3;
	//step 5: config parity bits
	UCSRC_REG &= UART_PARITY_MASK;
	UCSRC_REG |= UART_PARITY << 4;
	//step 6: config Baude Rate
	CLR_BIT(UBRRH_REG,URSEL_BIT);
	UBRRH_REG = UART_BAUD_RATE>>8;
	UBRRL_REG = UART_BAUD_RATE;
}


void M_UART_void_sendByte(u8 Copy_u8_Byte)
{
	/*Can't be made !=0 and put data inside while loop because if the UDR is busy so it breaks while loop and end function
	  so the data is missed
	  while(GET_BIT(UCSRA_REG,UDRE_BIT)!=0)
	  {
	  	  UDR_REG = Copy_u8_Byte;
	  }
	  This is wrong
	*/
	while(GET_BIT(UCSRA_REG,UDRE_BIT)==0); //busy waiting
	UDR_REG = Copy_u8_Byte;
}

u8 M_UART_u8_recieveByte(void)
{
	while(GET_BIT(UCSRA_REG,RXC_BIT)==0); //busy waiting
	return UDR_REG;
}


void M_UART_void_sendString(u8* str)
{
	u32 i =0;
	while(str[i]='\0')
	{
		M_UART_void_sendByte(str[i]);
		i++;
	}
}

