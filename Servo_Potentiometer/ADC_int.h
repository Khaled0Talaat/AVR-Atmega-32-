/*
 * ADC_int.h
 *
 *  Created on: 6 Sep 2019
 *      Author: user
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

void Adc_vidInit(void);
u16 Adc_u16ConvertChannel(u8 channel);

#define Channel0 0
#define Channel1 1
#define Channel2 2
#define Channel3 3
#define Channel4 4
#define Channel5 5
#define Channel6 6
#define Channel7 7
#endif /* ADC_INT_H_ */
