/*
 * ADC_program.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "ADC_interface.h"
#include "ADC_private.h"
#include "Led_interface.h"

void (*ADC_Int_CallBack) (void);

void M_ADC_void_Init(void)
{
#if   ADC_V_REF   ==   AVCC
	SET_BIT(ADMUX_REG,REFS0_BIT);
	CLR_BIT(ADMUX_REG,REFS1_BIT);
#elif ADC_V_REF   ==   AREF_PIN
	CLR_BIT(ADMUX_REG,REFS0_BIT);
	CLR_BIT(ADMUX_REG,REFS1_BIT);
#elif ADC_V_REF   ==   _2V56
	SET_BIT(ADMUX_REG,REFS0_BIT);
	SET_BIT(ADMUX_REG,REFS1_BIT);
#endif
	// to select right adjust
	CLR_BIT(ADMUX_REG,ADLAR_BIT);
	// to select ADC0 channel
	CLR_BIT(ADMUX_REG,MUX4_BIT);
	CLR_BIT(ADMUX_REG,MUX3_BIT);
	CLR_BIT(ADMUX_REG,MUX2_BIT);
	CLR_BIT(ADMUX_REG,MUX1_BIT);
	CLR_BIT(ADMUX_REG,MUX0_BIT);

	SET_BIT(ADCSRA_REG,ADPS0_BIT);
	SET_BIT(ADCSRA_REG,ADPS1_BIT);
	SET_BIT(ADCSRA_REG,ADPS2_BIT);

	//To Enable free running mode
    SET_BIT(ADCSRA_REG,ADATE_BIT);
	CLR_BIT(SFIOR_REG,ADTS2_BIT);
	CLR_BIT(SFIOR_REG,ADTS1_BIT);
	CLR_BIT(SFIOR_REG,ADTS0_BIT);

	// to enable ADC circuit
	SET_BIT(ADCSRA_REG,ADEN_BIT);

	//To enable ADC interrupt
	//SET_BIT(ADCSRA_REG,ADIE_BIT);


}
u16  M_ADC_void_Read(void)
{
	// to start conversion
	SET_BIT(ADCSRA_REG,ADSC_BIT);
	while(GET_BIT(ADCSRA_REG,ADIF_BIT) == 0);
	return ADC_VALUE_REG;
}

void M_ADC_void_SetCallBack(void (*Copy_Ptr) (void))
{
	ADC_Int_CallBack = Copy_Ptr;
}

ISR(ADC_vect)
{
	if(ADC_Int_CallBack!=NULL)
		ADC_Int_CallBack();
}
