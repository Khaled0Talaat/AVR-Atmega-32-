/*
 * main.c
 *
 *  Created on: 4 Sep 2019
 *      Author: user
 */
#include"std_types.h"
#include"Bit_math.h"
#include<avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>
#include"Lcd_int.h"
#include"Keypad_int.h"


int main(void)
{
	 Keypad_vidInit();
	  Lcd_vidInit();
	f32 x=10,y=10;
	f32 result;
	u8 res;
	u8 op=100;
	f32 z;
	u8 arr[]="Unknown Operation";
	while(1)
	{
	while(x==10)
		{
		x=Keypad_u8GetKey();

		   if(x<10)
		     {
			   Lcd_vidWriteChar(x+0x30);
			break;
		     }
		}




	while(op==100)
		{
		    op=Keypad_u8GetKey();

			if(op<100)
				 {

			     break;
				  }
		}
	switch(op)
	{
	   case(10):
	    {
		   Lcd_vidWriteChar('+');
		break;
	    }
	   case(11):
	    {
	   	   Lcd_vidWriteChar('-');
	   	break;
	    }
	   case(12):
	    {
	   	   Lcd_vidWriteChar('*');

	   	break;
	    }
	   case(13):
	    {
	   	   Lcd_vidWriteChar('/');
	   	break;
	    }
	   default: Lcd_vidWriteChar('?');

	}



	while(y==10)
	{
	    y=Keypad_u8GetKey();

			if(y<10)
			 {
		     break;
			  }
	}


	Lcd_vidWriteChar(y+0x30);
	_delay_ms(150);

switch(op)
{
	case(10):
	{
		result=x+y;
		break;
	}
	case(11):
	{
		result=x-y;
	    break;
	}
	case(12):
	{
		result=x*y;
	    break;
	}
	case(13):
	{
		result=x/y;
	    break;
	}
	default:Lcd_vidWriteString(arr);
}
res=result;
z=(result-res)*10;
Lcd_vidWriteChar('=');
	_delay_ms(2);
Lcd_vidWriteChar(res+0x30);
	_delay_ms(2);
Lcd_vidWriteChar('.');
		_delay_ms(2);
Lcd_vidWriteChar(z+0x30);
			_delay_ms(2);
_delay_ms(2000);
 Lcd_vidSendCommand(0x01);
 _delay_ms(1000);

}
	return 0;
	}

