/*
 * UART_private.h
 *
 *  Created on: Aug 24, 2022
 *      Author: zeyad
 */

#ifndef UART_UART_PRIVATE_H_
#define UART_UART_PRIVATE_H_

#define UDR_REG 	*((volatile u8*)0x2C)
#define UCSRA_REG 	*((volatile u8*)0x2B)
#define UCSRB_REG  	*((volatile u8*)0x2A)
#define UCSRC_REG  	*((volatile u8*)0x40)
#define UBRRH_REG 	*((volatile u8*)0x40)
#define UBRRL_REG 	*((volatile u8*)0x29)

//UCSRC
#define URSEL_BIT   			7 //selects between USCRC and UBRRH
#define UMSEL_BIT   			6 //synchronous ot asynchronus
#define UPM1_BIT	   			5 //parity bit 1
#define UPM0_BIT	   			4 // parity bit 0
#define USPS_BIT	   			3 //stop bit
#define UCSZ1_BIT	  			2 // data length 1
#define UCSZ0_BIT   			1 //data length 0
#define UCPOL_BIT			    0

//UCSRB
#define RXCIE_BIT				7 //RX complete interrupt Enable
#define TZCIE_BIT				6 //TX complete interrupt Enable
#define UDRIE_BIT				5 //data register Empty interrupt Enable
#define RXEN_BIT				4 // RX Enable
#define TXEN_BIT				3 // TX Enable
#define UXSZ2_BIT				2 //Select when 1 (9bitmode)
#define RXB8_BIT				1 //9th bit inRX
#define TXB8_BIT				0 //9th bit in TX

//UCSRA
#define RXC_BIT 				7 //RX Complete Flag
#define TXC_BIT 				6 //TX Complete Flag
#define UDRE_BIT 				5 // Data Register Empty Flag
#define FE_BIT					4 //Frame Error Flag
#define DOR_BIT	 				3 //Data Overrun Error Flag
#define PE_BIT 					2 //Parity Error Flag
#define U2X_BIT 				1 //Double Speed
#define MPCM_BIT 				0

#define UART_DATA_SIZE_MASK		0b11111001
#define UART_PARITY_MASK		0b11001111
#define UART_STOP_BIT_MASK      0b11110111

#define UART_DATA_SIZE_5_BITS	0 // 0 0
#define UART_DATA_SIZE_6_BITS	1 // 0 1
#define UART_DATA_SIZE_7_BITS	2 // 1 0
#define UART_DATA_SIZE_8_BITS	3 // 1 1

#define UART_PARITY_ODD			3
#define UART_PARITY_EVEM		2
#define UART_PARITY_NO_PARITY	0

#define UART_STOP_BITS_1		0
#define UART_STOP_BITS_2		1

#define UART_BR_16MHZ_2400			416
#define UART_BR_16MHZ_9600			103
#define UART_BR_16MHZ_115200		8

#define UART_BR_8MHZ_2400			207
#define UART_BR_8MHZ_9600			51
#define UART_BR_8MHZ_115200		3

#endif /* UART_UART_PRIVATE_H_ */
