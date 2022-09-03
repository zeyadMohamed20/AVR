/*
 * DC_MOTOR_Program.c
 *
 *  Created on: Aug 28, 2022
 *      Author: Eng.Hazem
 */

#include "DC_MOTOR_Interface.h"
#include "DC_MOTOR_Private.h"
#include "Led_interface.h"

void H_DC_Motor_void_Init(void)
{
	/*Configure input pin for Motor driver*/
	M_Dio_void_PinMode(DC_MOTOR_INPUT_1,OUTPUT);
	M_Dio_void_PinMode(DC_MOTOR_INPUT_2,OUTPUT);
	/*Configure PWM Pin As Output to control speed of motor*/
	M_Dio_void_PinMode(PB3_PIN,OUTPUT);
}
void H_DC_Motor_void_TurnOn_AntiClockWise(void)
{
	//Rotate DC motor AntiClockwise
	M_Dio_void_PinWrite(DC_MOTOR_INPUT_1,HIGH);
	M_Dio_void_PinWrite(DC_MOTOR_INPUT_2,LOW);
}
void H_DC_Motor_void_TurnOn_ClockWise(void)
{
	//Rotate DC motor Clockwise
	M_Dio_void_PinWrite(DC_MOTOR_INPUT_1,LOW);
	M_Dio_void_PinWrite(DC_MOTOR_INPUT_2,HIGH);
}
void H_DC_Motor_void_TurnOff(void)
{
	//Stop Dc Motor
	M_Dio_void_PinWrite(DC_MOTOR_INPUT_1,LOW);
	M_Dio_void_PinWrite(DC_MOTOR_INPUT_2,LOW);
	M_Timer_0_SetFastPWM(LOW_SPEED_PERCENTAGE);
}

void H_DC_Motor_void_FullSpeed_Enable(void)
{
	M_Timer_0_SetFastPWM(FULL_SPEED_PERCENTAGE);
}

void H_DC_Motor_void_NormalSpeed_Enable(void)
{
	M_Timer_0_SetFastPWM(NORMAL_SPEED_PERCENTAGE);
}
