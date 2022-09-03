/*
 * Buzzer_program.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "Buzzer_interface.h"

void H_Buzzer_void_BuzzerInit(void)
{
	M_Dio_void_PinMode(BUZZER_PIN,OUTPUT);
}
void H_Buzzer_void_BuzzerOn(void)
{
	M_Dio_void_PinWrite(BUZZER_PIN,HIGH);
}
void H_Buzzer_void_BuzzerOff(void)
{
	M_Dio_void_PinWrite(BUZZER_PIN,LOW);
}
void H_Buzzer_void_BuzzerTog(void)
{

}
void H_Buzzer_void_BuzzerShortSound(void)
{
	M_Dio_void_PinWrite(BUZZER_PIN,HIGH);
	_delay_ms(BUZZER_TIME_ON);
	M_Dio_void_PinWrite(BUZZER_PIN,LOW);

}
void H_Buzzer_void_BuzzerDoubleSound(void)
{
	M_Dio_void_PinWrite(BUZZER_PIN,HIGH);
	_delay_ms(BUZZER_TIME_ON);
	M_Dio_void_PinWrite(BUZZER_PIN,LOW);
	_delay_ms(60);
	M_Dio_void_PinWrite(BUZZER_PIN,HIGH);
	_delay_ms(BUZZER_TIME_ON);
	M_Dio_void_PinWrite(BUZZER_PIN,LOW);
}
