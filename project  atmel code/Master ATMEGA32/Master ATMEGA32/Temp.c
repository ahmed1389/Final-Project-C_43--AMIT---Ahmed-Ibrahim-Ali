/*
 * Temp.c
 *
 * Created: 16/10/2020 02:52:18 م
 *  Author: Ali
 */ 


#include "Temp.h"


void TempSensor_Init(void)
{
	ADC_Init();
}

uint16 TempSensor_Read(void)
{
	uint32  Digital_OutPut = 0;
	uint32  Temp = 0;
	
	Digital_OutPut = ADC_Read();
	
	Temp = (Digital_OutPut * 500) / 1024 ;
	
	return Temp;
	
}