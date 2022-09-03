/*
 * TImer2_Pivate.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Samy
 */

#ifndef TIMER2_TIMER2_PIVATE_H_
#define TIMER2_TIMER2_PIVATE_H_
#define TCCR2_REG		*(volatile u8*)0x45
#define TIMSK_REG		*(volatile u8*)0x59
#define TCNT2_REG		*(volatile u8*)0x44
#define OCR2_REG		*(volatile u8*)0x43

// TCCR2_REG BITS
#define WGM20_BIT		6
#define WGM21_BIT		3
#define CS22_BIT		2
#define	CS21_BIT		1
#define	CS20_BIT		0

// TIMSK_REG BITS
#define TOIE2_BIT		6
#define OCIE2_BIT		7

//TIMER2_MODES
#define TIMER2_NORMAL_MODE				0
#define TIMER2_PHASECORRECT_MODE		1
#define TIMER2_CTC_MODE					2
#define TIMER2_FASTPWM_MODE				3

//TIMER2 CLK
#define TIMER2_PRESCALAR_1						1
#define TIMER2_PRESCALAR_8						2
#define TIMER2_PRESCALAR_32						3
#define TIMER2_PRESCALAR_64						4
#define TIMER2_PRESCALAR_128					5
#define TIMER2_PRESCALAR_256					6
#define TIMER2_PRESCALAR_1024					7

//TIMER2 OC2 MODES (Non PWM):
#define TIMER2_OC2_DISCONNECTED				0
#define TIMER2_OC2_TOG						1
#define TIMER2_OC2_CLR						2
#define TIMER2_OC2_SET						3

//TIMER2 OC2 MODES (PWM):
#define TIMER2_OC2_PWM_NON_INVERTING		0b00100000 //value is inside mask
#define TIMER2_OC2_PWM_INVERTING			0b00110000 //value is inside mask

#define TIMER2_PRESCALAR_MASK		0b11111000

#define TIMER2_OC2_MASK				0b11001111

#define TIMER2_OC2_SHIFT			4


#endif /* TIMER2_TIMER2_PIVATE_H_ */
