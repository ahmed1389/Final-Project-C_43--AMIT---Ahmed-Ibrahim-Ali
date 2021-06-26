/*
 * Temp.h
 *
 * Created: 16/10/2020 02:52:02 م
 *  Author: Ali
 */ 


#ifndef TEMP_H_
#define TEMP_H_

#include "ADC.h"


void TempSensor_Init(void);

uint16 TempSensor_Read(void);



#endif /* TEMP_H_ */