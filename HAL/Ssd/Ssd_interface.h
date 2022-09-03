/*
 * Ssd_interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

#include "Ssd_configuration.h"
#include "Dio_interface.h"
#include <util/delay.h>

void H_Ssd_void_SsdInit(void);
void H_Ssd_void_SsdDisplay(u8);
void H_Ssd_void_SsdCountUp(u8);
void H_Ssd_void_SsdCountDown(u8);

#endif /* HAL_SSD_SSD_INTERFACE_H_ */
