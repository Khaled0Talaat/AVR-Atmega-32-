/*
 * Lcd_int.h
 *
 *  Created on: 23 Aug 2019
 *      Author: user
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

void Lcd_vidInit(void);
void Lcd_vidWriteChar(u8 Character);
void Lcd_vidSendCommand(u8 Cmd);
void Lcd_vidGoTo(u8 x , u8 y);
void Lcd_vidWriteString(u8* String);

#endif /* LCD_INT_H_ */
