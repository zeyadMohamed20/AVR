/*
 * SPI_configuration.h
 *
 *  Created on: Aug 28, 2022
 *      Author: zeyad
 */

#ifndef SPI_SPI_CONFIGURATION_H_
#define SPI_SPI_CONFIGURATION_H_

/*
 * Choose :
 * SPI_CLK_POL_IDLE_HIGH
 * SPI_CLK_POL_IDLE_LOW
 */
#define SPI_CLK_POL 	   SPI_CLK_POL_IDLE_LOW

/*
 * Choose :
 * SPI_CLK_PHASE_SAMPLE_FIRST
 * SPI_CLK_PHASE_SAMPLE_LAST
 */
#define SPI_CLK_PHASE 		SPI_CLK_PHASE_SAMPLE_FIRST

/*
 * Choose :
 * Normal Speed:
 * SPI_CLK_PRESCALER_NORMAL_4
 * SPI_CLK_PRESCALER_NORMAL_16
 * SPI_CLK_PRESCALER_NORMAL_64
 * SPI_CLK_PRESCALER_NORMAL_128
 *
 * Double Speed:
 * SPI_CLK_PRESCALER_DOUBLE_2
 * SPI_CLK_PRESCALER_DOUBLE_8
 * SPI_CLK_PRESCALER_DOUBLE_32
 * SPI_CLK_PRESCALER_DOUBLE_64
 */
#define SPI_CLK_SPEED 		SPI_CLK_PRESCALER_NORMAL_4

/*
 * Choose :
 * SPI_DATA_ORDER_MSB_FIRST
 * SPI_DATA_ORDER_LSB_FIRST
 */
#define SPI_DATA_ORDER 		SPI_DATA_ORDER_LSB_FIRST

/*
 * Choose :
 * SPI_SPEED_MODE_NORMAL_SPEED
 * SPI_SPEED_MODE_DOUBLE_SPEED
 */
#define SPI_SPEED_MODE		SPI_SPEED_MODE_NORMAL_SPEED

#endif /* SPI_SPI_CONFIGURATION_H_ */
