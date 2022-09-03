/*
 * DC_MOTOR_Interface.h
 *
 *  Created on: Aug 28, 2022
 *      Author: Eng.Hazem
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_
#define HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_
/********************************************INCLUDES************************************************************************************************************/
#include "Dio_Interface.h"
#include "Timer_0_interface.h"
#include "StandardTypes.h"
#include "DC_MOTOR_Configration.h"
#include "DC_MOTOR_Private.h"
#include "BitMath.h"
/************************************************PROTOTYPES*****************************************************************************************************/
void H_DC_Motor_void_Init(void);
void H_DC_Motor_void_TurnOn_AntiClockWise(void);
void H_DC_Motor_void_TurnOn_ClockWise(void);
void H_DC_Motor_void_TurnOff(void);
void H_DC_Motor_void_FullSpeed_Enable(void);
void H_DC_Motor_void_NormalSpeed_Enable(void);
#endif /* HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_ */
