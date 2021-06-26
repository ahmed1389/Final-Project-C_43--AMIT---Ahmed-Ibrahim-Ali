/*
 * ADC.c
 *
 * Created: 16/10/2020 01:47:24 م
 *  Author: Ali
 */ 

#include "ADC.h"


void ADC_Init(void)
{
	#if   ADC_VOLTAGE_REFRENCE   ==      ADC_VREF_AVCC
	
	SET_BIT(ADMUX , 6);
	CLR_BIT(ADMUX , 7);
	
	#elif  ADC_VOLTAGE_REFRENCE  ==     ADC_VREF_INTERNAL
	
	#endif
	
	#if    ADC_ADjUST            ==     ADC_RIGHT_ADJUST
	
	CLR_BIT(ADMUX , 5);
	
	#endif
	
	#if   ADC_CHANNEL           ==     ADC_CHANNEL_1
	
	SET_BIT(ADMUX , 0);
	
	#endif
	
	#if  ADC_CONVERSION_TRIGGER  ==    ADC_AUTO_TRIGGER
	
	SET_BIT(ADCSRA , 5);
	
	#endif
	
	#if  ADC_PRESCALER          ==      PRESCALER_128
	
	SET_BIT(ADCSRA , 0);
	SET_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);
	
	#endif
	
	#if  ADC_INTERRUPT_STATUS   ==     INTERRUPT_DISABLED
	
	CLR_BIT(ADCSRA , 3);
	
	#endif
	
	
	//Enable  ADC
	SET_BIT(ADCSRA , 7);
	
	
}

uint16 ADC_Read(void)
{
	uint16 value = 0;
	
	SET_BIT(ADCSRA , 6);
	
	while(GET_BIT(ADCSRA,4) == 0);
	
	value = ADC_ADJUST ;
	
	return value;
	
}