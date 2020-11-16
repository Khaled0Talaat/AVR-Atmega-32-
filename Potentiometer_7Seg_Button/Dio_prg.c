/*
 * Dio_prg.c
 *
 *  Created on: 17 Aug 2019
 *      Author: user
 */
#include"std_types.h"
#include"Bit_math.h"
#include<avr/io.h>
void Dio_vidSetPinDir(u8 Pin,u8 Dir)
{
	u8 Loc_u8Port;
	u8 Loc_u8Pin;

	Loc_u8Port=Pin/8;
	Loc_u8Pin=Pin%8;

	switch(Loc_u8Port)
	{
	case 0:
	if(Dir==0)
		CLEAR_BIT(DDRA,Loc_u8Pin);
	else
		SET_BIT(DDRA,Loc_u8Pin);
	break;

	case 1:
		if(Dir==0)
			CLEAR_BIT(DDRB,Loc_u8Pin);
		else
			SET_BIT(DDRB,Loc_u8Pin);
		break;
	case 2:
		if(Dir==0)
			CLEAR_BIT(DDRC,Loc_u8Pin);
		else
			SET_BIT(DDRC,Loc_u8Pin);
		break;
	case 3:
		if(Dir==0)
			CLEAR_BIT(DDRD,Loc_u8Pin);
		else
			SET_BIT(DDRD,Loc_u8Pin);
		break;
	}
}
void Dio_vidSetPinVal(u8 Pin,u8 Val)
{
	u8 Loc_u8Port;
	u8 Loc_u8Pin;

		Loc_u8Port=Pin/8;
		Loc_u8Pin=Pin%8;

		switch(Loc_u8Port)
		{
		case 0:
		if(Val==0)
			CLEAR_BIT(PORTA,Loc_u8Pin);
		else
			SET_BIT(PORTA,Loc_u8Pin);
		break;

		case 1:
			if(Val==0)
				CLEAR_BIT(PORTB,Loc_u8Pin);
			else
				SET_BIT(PORTB,Loc_u8Pin);
			break;
		case 2:
			if(Val==0)
				CLEAR_BIT(PORTC,Loc_u8Pin);
			else
				SET_BIT(PORTC,Loc_u8Pin);
			break;
		case 3:
			if(Val==0)
				CLEAR_BIT(PORTD,Loc_u8Pin);
			else
				SET_BIT(PORTD,Loc_u8Pin);
			break;
		}
	}
u8 Dio_u8GetPinVal(u8 Pin)
{
	u8 Loc_u8Port;
	u8 Loc_u8Pin;

	Loc_u8Port=Pin/8;
	Loc_u8Pin=Pin%8;

	switch(Loc_u8Port)
	{

	case 0:
		return GET_BIT(PINA,Loc_u8Pin);
		break;
	case 1:
		return GET_BIT(PINB,Loc_u8Pin);
		break;
	case 2:
		return GET_BIT(PINC,Loc_u8Pin);
		break;
	case 3:
		return GET_BIT(PIND,Loc_u8Pin);
	break;


	}




}






