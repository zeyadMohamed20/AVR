/*
 * ADC_interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "StandardTypes.h"
#include "BitMath.h"
#include "ADC_configuration.h"
#include <avr/interrupt.h>

void M_ADC_void_Init(void);
u16  M_ADC_void_Read(void);
void M_ADC_void_SetCallBack(void (*)(void));

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
