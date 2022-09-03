/*
 * UART_interface.h
 *
 *  Created on: Aug 24, 2022
 *      Author: zeyad
 */

#ifndef UART_UART_INTERFACE_H_
#define UART_UART_INTERFACE_H_

#include "StandardTypes.h"
#include "BitMath.h"
#include "UART_configuration.h"

void M_UART_void_Init(void);
void M_UART_void_sendByte(u8);
u8 M_UART_u8_recieveByte(void);
void M_UART_void_sendString(u8*);



#endif /* UART_UART_INTERFACE_H_ */
