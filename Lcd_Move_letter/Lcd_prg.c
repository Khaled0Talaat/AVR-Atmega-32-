/*
 * Lcd_prg.c
 *
 *  Created on: 23 Aug 2019
 *      Author: user
 */
#include"std_types.h"
#include"Bit_math.h"
#include"Dio_int.h"
#define F_CPU 8000000
#include<util/delay.h>
#include"Lcd_cfg.h"
#include"Lcd_int.h"


void Lcd_vidInit(void)
{
	Dio_vidSetPinDir(LCD_u8D0,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D1,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D2,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D3,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D3,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D4,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D5,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D6,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D7,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8RS,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8RW,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8EN,DIO_u8OUTPUT);

	Lcd_vidSendCommand(0x38);
	_delay_ms(2);
	Lcd_vidSendCommand(0x0c);
	_delay_ms(2);
	Lcd_vidSendCommand(0x01);
	_delay_ms(2);

}
void Lcd_vidWriteChar(u8 Character)
{
	Dio_vidSetPinVal(LCD_u8RS,DIO_u8HIGH);
	Dio_vidSetPinVal(LCD_u8RW,DIO_u8LOW);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);

	Dio_vidSetPinVal(LCD_u8D0,GET_BIT(Character,0));
	Dio_vidSetPinVal(LCD_u8D1,GET_BIT(Character,1));
	Dio_vidSetPinVal(LCD_u8D2,GET_BIT(Character,2));
	Dio_vidSetPinVal(LCD_u8D3,GET_BIT(Character,3));
	Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Character,4));
	Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Character,5));
	Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Character,6));
	Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Character,7));
	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);

}
void Lcd_vidSendCommand(u8 Cmd)
{
	    Dio_vidSetPinVal(LCD_u8RS,DIO_u8LOW);
		Dio_vidSetPinVal(LCD_u8RW,DIO_u8LOW);
		Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);

		Dio_vidSetPinVal(LCD_u8D0,GET_BIT(Cmd,0));
		Dio_vidSetPinVal(LCD_u8D1,GET_BIT(Cmd,1));
		Dio_vidSetPinVal(LCD_u8D2,GET_BIT(Cmd,2));
		Dio_vidSetPinVal(LCD_u8D3,GET_BIT(Cmd,3));
		Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Cmd,4));
		Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Cmd,5));
		Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Cmd,6));
		Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Cmd,7));
		_delay_ms(2);
		Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);
}
void Lcd_vidWriteString(u8* String)
{
	u8 i=0;
	while(String[i]!='\0')
	{
		Lcd_vidWriteChar(String[i]);
		_delay_ms(2);
		i++;
	}
}

void Lcd_vidGoTo(u8 x , u8 y)
{
	if(x>0 && x<=16)    // x is a col
	{
		switch(y)      // y is a row
		{
		case 1:
			// col num + (0x80-1) in decimal (0x80 Force cursor to beginning to 1st line)
			Lcd_vidSendCommand(x+127);
			break;
		case 2:
			// col num + (0xc0-1) in decimal (0xc0 Force cursor to beginning to 2nd line)
			Lcd_vidSendCommand(x+191);
			break;
		default:
			break;
		}
	}
}

