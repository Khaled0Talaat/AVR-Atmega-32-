/*
 * Keypad_prg.c
 *
 *  Created on: 24 Aug 2019
 *      Author: user
 */
#include"std_types.h"
#include"Bit_math.h"
#include"Dio_int.h"
#include"Keypad_cfg.h"
#include"Keypad_int.h"

void Keypad_vidInit(void)
{
	Dio_vidSetPinDir(KEYPAD_u8R1,DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8R2,DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8R3,DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8R4,DIO_u8OUTPUT);

	Dio_vidSetPinDir(KEYPAD_u8C1,DIO_u8INPUT);
	Dio_vidSetPinDir(KEYPAD_u8C2,DIO_u8INPUT);
	Dio_vidSetPinDir(KEYPAD_u8C3,DIO_u8INPUT);
	Dio_vidSetPinDir(KEYPAD_u8C4,DIO_u8INPUT);

	Dio_vidSetPinVal(KEYPAD_u8C1,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8C2,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8C3,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8C3,DIO_u8HIGH);

}
u8 Keypad_u8GetKey(void)
{
	Dio_vidSetPinVal(KEYPAD_u8R1,DIO_u8LOW);
	Dio_vidSetPinVal(KEYPAD_u8R2,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R3,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R4,DIO_u8HIGH);

	if(     Dio_u8GetPinVal(KEYPAD_u8C1)==0  &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1    )

	{
		return 1;
	}
	if(     Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==0&&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1&&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1   )

	{
		return 2;
	}
	if(     Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1&&
			Dio_u8GetPinVal(KEYPAD_u8C3)==0&&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1   )

	{
		return 3;
	}
	if(     Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1&&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1&&
			Dio_u8GetPinVal(KEYPAD_u8C4)==0   )
	{
		return 10;
	}

	Dio_vidSetPinVal(KEYPAD_u8R1,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R2,DIO_u8LOW);
	Dio_vidSetPinVal(KEYPAD_u8R3,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R4,DIO_u8HIGH);

	if(     Dio_u8GetPinVal(KEYPAD_u8C1)==0  &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1    )

	{
		return 4;
	}
	if(     Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==0&&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1&&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1   )

	{
		return 5;
	}
	if(     Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1&&
			Dio_u8GetPinVal(KEYPAD_u8C3)==0&&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1   )

	{
		return 6;
	}
	if(     Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1&&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1&&
			Dio_u8GetPinVal(KEYPAD_u8C4)==0   )
	{
		return 11;
	}
	Dio_vidSetPinVal(KEYPAD_u8R1,DIO_u8HIGH);
		Dio_vidSetPinVal(KEYPAD_u8R2,DIO_u8HIGH);
		Dio_vidSetPinVal(KEYPAD_u8R3,DIO_u8LOW);
		Dio_vidSetPinVal(KEYPAD_u8R4,DIO_u8HIGH);

		if(     Dio_u8GetPinVal(KEYPAD_u8C1)==0  &&
				Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
				Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
				Dio_u8GetPinVal(KEYPAD_u8C4)==1    )

		{
			return 7;
		}
		if(     Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
				Dio_u8GetPinVal(KEYPAD_u8C2)==0&&
				Dio_u8GetPinVal(KEYPAD_u8C3)==1&&
				Dio_u8GetPinVal(KEYPAD_u8C4)==1   )

		{
			return 8;
		}
		if(     Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
				Dio_u8GetPinVal(KEYPAD_u8C2)==1&&
				Dio_u8GetPinVal(KEYPAD_u8C3)==0&&
				Dio_u8GetPinVal(KEYPAD_u8C4)==1   )

		{
			return 9;
		}
		if(     Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
				Dio_u8GetPinVal(KEYPAD_u8C2)==1&&
				Dio_u8GetPinVal(KEYPAD_u8C3)==1&&
				Dio_u8GetPinVal(KEYPAD_u8C4)==0   )
		{
			return 12;
		}

		Dio_vidSetPinVal(KEYPAD_u8R1,DIO_u8HIGH);
			Dio_vidSetPinVal(KEYPAD_u8R2,DIO_u8HIGH);
			Dio_vidSetPinVal(KEYPAD_u8R3,DIO_u8HIGH);
			Dio_vidSetPinVal(KEYPAD_u8R4,DIO_u8LOW);

			if(     Dio_u8GetPinVal(KEYPAD_u8C1)==0  &&
					Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
					Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
					Dio_u8GetPinVal(KEYPAD_u8C4)==1    )

			{
				return 15;
			}
			if(     Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
					Dio_u8GetPinVal(KEYPAD_u8C2)==0&&
					Dio_u8GetPinVal(KEYPAD_u8C3)==1&&
					Dio_u8GetPinVal(KEYPAD_u8C4)==1   )

			{
				return 0;
			}
			if(     Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
					Dio_u8GetPinVal(KEYPAD_u8C2)==1&&
					Dio_u8GetPinVal(KEYPAD_u8C3)==0&&
					Dio_u8GetPinVal(KEYPAD_u8C4)==1 )

			{
				return 14 ;
			}
			if(     Dio_u8GetPinVal(KEYPAD_u8C1)==1&&
					Dio_u8GetPinVal(KEYPAD_u8C2)==1&&
					Dio_u8GetPinVal(KEYPAD_u8C3)==1&&
					Dio_u8GetPinVal(KEYPAD_u8C4)==0  )
			{
				return 13;
			}
return KEYPAD_u8NO_KEY;

}
