/*
 * ADC.h
 *
 * Created: 16/10/2020 01:47:37 م
 *  Author: Ali
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "MCU.h"
#include "BIT_MATH.h"
#include "ADC_Cfg.h"


#define    ADC_VREF_AVCC       0
#define    ADC_VREF_INTERNAL   1
#define    ADC_VREF_AREF       2

#define    ADC_CHANNEL_1       1

#define   ADC_AUTO_TRIGGER     0

#define   ADC_RIGHT_ADJUST     0
#define   ADC_LEFT_ADJUST      1

#define   INTERRUPT_ENABLE     0
#define   INTERRUPT_DISABLED   1


#define   PRESCALER_2          1
#define   PRESCALER_4          2
#define   PRESCALER_8          3
#define   PRESCALER_16         4
#define   PRESCALER_128        7



void ADC_Init(void);

uint16 ADC_Read(void);


#endif /* ADC_H_ */