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
	CLEAR_BIT(ADMUX,5);

	SET_BIT(ADCSRA,7);
	CLEAR_BIT(ADCSRA,5);

	CLEAR_BIT(ADCSRA,3);
	CLEAR_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);
}

u16 Adc_u16ConvertChannel(u8 channel)
{
	u8 Reg_value;
	u16 Adc_Result=0;
	Reg_value=(ADMUX&0xE0)|channel;
	ADMUX=Reg_value;
	SET_BIT(ADCSRA,6);
	while(GET_BIT(ADCSRA,4)==0);
	SET_BIT(ADCSRA,4);
	Adc_Result=ADCL;
	Adc_Result|=(ADCH<<8);

	return Adc_Result;
}
