/*
 * main.c
 *
 *  Created on: 23 Aug 2019
 *      Author: user
 */
#include"std_types.h"
#include"Bit_math.h"
#include<avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>
#include"Lcd_int.h"

int main(void)
{
u8 i;
u8 arr[]="Omar";
	Lcd_vidInit();

    _delay_ms(2);

while(1)
{
	 Lcd_vidSendCommand(0x80);
		 	 _delay_ms(2);

		 	Lcd_vidWriteString(arr);
	 _delay_ms(2);

	 for(i=0;i<15;i++)
	 {
	     Lcd_vidSendCommand(0x1c);
	     _delay_ms(100);
	 }

	 Lcd_vidSendCommand(0x01);
	 	_delay_ms(2);

	 Lcd_vidSendCommand(0xc0);
	 _delay_ms(2);

	 Lcd_vidWriteString(arr);
	 	 _delay_ms(2);

	 for(i=0;i<15;i++)
	 {
	 Lcd_vidSendCommand(0x1c);
	 _delay_ms(100);
	 }

	 Lcd_vidSendCommand(0x01);
	 	 	_delay_ms(2);

}



return 0;
}
