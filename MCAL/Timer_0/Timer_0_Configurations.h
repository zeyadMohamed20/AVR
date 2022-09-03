/*
 * Timer_0_Configurations.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Mazin
 */

#ifndef MCAL_TIMER_0_TIMER_0_CONFIGURATIONS_H_
#define MCAL_TIMER_0_TIMER_0_CONFIGURATIONS_H_


 /*
 * choose from:
 *   TIMER0_PRESCALER_1
 *   TIMER0_PRESCALER_8
 *   TIMER0_PRESCALER_64
 *   TIMER0_PRESCALER_256
 *   TIMER0_PRESCALER_1024
 *   TIMER0_PRESCALER_EXTCLK_FALLEDGE
 *   TIMER0_PRESCALER_EXTCLK_RAISEDGE
 */

#define TIMER_0_PRESCALER	TIMER_0_PRESCALER_1024

/*
 * select F_OSC			in Mega HZ
 */
#define F_OSC				16
/*
 *   choose from :
 *   TIMER_0_NORMAL_MODE
 *   TIMER_0_CTC_MODE
 *   TIMER_0_PHASE_CORRECT_PWM_MODE
 *   TIMER_0_FASTPWM_MODE
 *
 */

#define  TIMER_0_MODE			TIMER_0_FASTPWM_MODE


/*
 * choose from :
 *  Non PWM:
 *   TIMER0_OC0_DISCONNECTED
 *   TIMER0_OC0_TOG
 *   TIMER0_OC0_CLEAR
 *   TIMER0_OC0_SET
 *
 *   PWM:
 *   TIMER0_OC0_PWM_NON_INVERTING
 *   TIMER0_OC0_PWM_INVERTING
 */
#define  TIMER_0_OC0_MODE		TIMER0_OC0_PWM_NON_INVERTING



#endif /* MCAL_TIMER_0_TIMER_0_CONFIGURATIONS_H_ */
