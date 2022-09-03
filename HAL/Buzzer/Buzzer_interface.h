/*
 * Buzzer_interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_BUZZER_BUZZER_INTERFACE_H_
#define HAL_BUZZER_BUZZER_INTERFACE_H_

#include "Buzzer_configuration.h"
#include "Dio_interface.h"
#include <util/delay.h>

void H_Buzzer_void_BuzzerInit(void);
void H_Buzzer_void_BuzzerOn(void);
void H_Buzzer_void_BuzzerOff(void);
void H_Buzzer_void_BuzzerTog(void);
void H_Buzzer_void_BuzzerShortSound(void);
void H_Buzzer_void_BuzzerDoubleSound(void);

#endif /* HAL_BUZZER_BUZZER_INTERFACE_H_ */
