/*
 * Timer.h
 *
* Created: 5/24/2021 10:18:06 PM
*  Author: Ahmed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "STD.h"
#include "MCU.h"
#include "BIT_Math.h"

void Timer0_Init(void);

void Timer0_Start(void);

void Timer0_Stop(void);

void Timer0_SetDelay(uint32 delay_ms);

void Timer0_SetCallback(void(*p)(void));

void Timer1_Init(void);

void Timer1_Start(void);

void Timer1_Stop(void);

void Timer1_SetDelay(uint32 delay_ms);

void Timer1_SetCallback(void(*p)(void));

void PWM0_Init(void);

void PWM0_Generate(uint16 duty_cycle);

void PWM0_Start(void);

#endif /* TIMER_H_ */