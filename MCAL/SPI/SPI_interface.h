/*
 * SPI_interface.h
 *
 *  Created on: Aug 28, 2022
 *      Author: zeyad
 */

#ifndef SPI_SPI_INTERFACE_H_
#define SPI_SPI_INTERFACE_H_

#include "BitMath.h"
#include "StandardTypes.h"
#include "SPI_configuration.h"

void M_SPI_void_MasterInit(void);
void M_SPI_void_SlaveInit(void);
u8 M_SPI_u8_TransferByte(u8);

#endif /* SPI_SPI_INTERFACE_H_ */
