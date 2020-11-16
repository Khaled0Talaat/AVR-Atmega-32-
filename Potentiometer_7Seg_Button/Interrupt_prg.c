/*
 * Interrupt_prg.c
 *
 *  Created on: 4 Sep 2019
 *      Author: user
 */
#include"std_types.h"
#include"Bit_math.h"
#include"Dio_int.h"
#include<avr/interrupt.h>
#define F_CPU 8000000
#include<util/delay.h>

void Interrupt_vidINT0_Init(void)
{

SET_BIT(SREG,7);/*global interrupt */

	SET_BIT(GICR,6);/*peripheral interrupt 0*/
	SET_BIT(MCUCR,0);//generate interrupt at rising edge
	SET_BIT(MCUCR,1);

	Dio_vidSetPinDir(Dio_u8Pin_26,DIO_u8INPUT);
	Dio_vidSetPinVal(Dio_u8Pin_26,DIO_u8HIGH);
}
void Interrupt_vidINT1_Init(void)
{
	SET_BIT(SREG,7);/*global interrupt */

		SET_BIT(GICR,7);/*peripheral interrupt 1*/
		CLEAR_BIT(MCUCR,2);
		CLEAR_BIT(MCUCR,3);
		Dio_vidSetPinDir(Dio_u8Pin_27,DIO_u8INPUT);
		Dio_vidSetPinVal(Dio_u8Pin_27,DIO_u8HIGH);


}
