/*
 * ADC_prg.c
 *
 *  Created on: 6 Sep 2019
 *      Author: user
 */
#include<avr/io.h>
#include"std_types.h"
#include"Bit_math.h"
void Adc_vidInit(void)
{
	CLEAR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
#if ADC_u8ADJUST==ADC_u8Right_ADJUST
	CLEAR_BIT(ADMUX,5);
#elif ADC_u8ADJUST==ADC_u8Left_ADJUST
	SET_BIT(ADMUX,5);
#endif
	SET_BIT(ADCSRA,7);
	SET_BIT(ADCSRA,5);
	CLEAR_BIT(ADCSRA,3);
	CLEAR_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);

	CLEAR_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);
}

u16 Adc_u16ConvertChannel(u8 channel)
{
	u8 Reg_value;
	u16 Adc_Result=0;
	Reg_value=(ADMUX&0xE0)|channel;
	ADMUX=Reg_value;
	//SET_BIT(ADCSRA,6); Commented because of auto trigger
	while(GET_BIT(ADCSRA,4)==0);
	SET_BIT(ADCSRA,4);
#if ADC_u8ADJUST==ADC_u8Right_ADJUST
	Adc_Result=ADCL;
	Adc_Result|=(ADCH<<8);
#elif ADC_u8ADJUST==ADC_u8Left_ADJUST
	Adc_Result=ADCH;
#endif
	return Adc_Result;

}
