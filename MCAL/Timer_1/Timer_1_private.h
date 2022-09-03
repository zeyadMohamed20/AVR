/*
 * Timer_1_private.h
 *
 *  Created on: Aug 23, 2022
 *      Author: zeyad
 */

#ifndef TIMER_1_TIMER_1_PRIVATE_H_
#define TIMER_1_TIMER_1_PRIVATE_H_

#define TCCR1A_REG     (*((volatile u8*)0x4F))
#define TCCR1B_REG     (*((volatile u8*)0x4E))
#define ICR1_REG       (*((volatile u16*)0x46))
#define TIMSK_REG      (*((volatile u8*)0x59))

/*ICU interrupt Enable/Disable*/
#define TICIE1_BIT		  5

/*Mode Select*/
#define WGM10_BIT          0 //TCCR1A
#define WGM11_BIT          1 //TCCR1A
#define WGM12_BIT          3 //TCCR1B
#define WGM13_BIT          4 //TCCR1B

/*ICU Trigger Select*/
#define ICES1_BIT		   6 //TCCR1B (0 is falling, 1 is rising)

#define CS10_BIT           0
#define CS11_BIT           1
#define CS12_BIT           2


#endif /* TIMER_1_TIMER_1_PRIVATE_H_ */
