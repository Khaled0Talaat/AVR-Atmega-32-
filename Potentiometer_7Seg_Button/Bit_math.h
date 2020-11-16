/*
 * Bit_math.h
 *
 *  Created on: 17 Aug 2019
 *      Author: user
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Reg,Bit)   (Reg|=(1<<Bit))
#define CLEAR_BIT(Reg,Bit)  (Reg&=(~(1<<Bit)))
#define GET_BIT(Reg,Bit) ((Reg>>Bit)&0x01)
#endif /* BIT_MATH_H_ */
