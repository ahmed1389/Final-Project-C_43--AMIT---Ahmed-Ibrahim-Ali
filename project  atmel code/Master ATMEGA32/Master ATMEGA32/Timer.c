/*
 * Timer.c
 *
 * Created: 5/24/2021 10:18:06 PM
 *  Author: Ahmed
 */ 

#include "Timer.h"
#include <avr/interrupt.h>
#include <stddef.h> //for NULL  or   use  #define Null (void*)(0);

uint32 NUM_OVF = 0;
uint32 INIT_VALUE = 0;

void Timer0_Init(void)
{
	// select normal mode
	CLR_BIT(TCCR0, 3);
	CLR_BIT(TCCR0, 6);
	
	// enable global interrupts
	SET_BIT(SREG, 7);
	
	// enable peripheral interrupt
	SET_BIT(TIMSK, 0);
}

void Timer0_Start(void)
{
	// prescaler 1024
	SET_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 2);
	CLR_BIT(TCCR0, 1);
}

void Timer0_Stop(void)
{
	// no clock source
	CLR_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 2);
	CLR_BIT(TCCR0, 1);
}

void Timer0_SetDelay(uint32 delay_ms)
{
	uint8 TICK_TIME = 1024 / 16;
	uint32 NUM_TICKS = (delay_ms * 1000) / TICK_TIME;
	NUM_OVF = (NUM_TICKS / 256);
	INIT_VALUE = 256 - (NUM_TICKS % 256);
	TCNT0 = INIT_VALUE;
	NUM_OVF++;
}

void(*ptr0)(void) = NULL;

void Timer0_SetCallback(void(*p)(void))
{
	ptr0 = p;
}

ISR(TIMER0_OVF_vect)
{
	static uint32 cnt_0 = 0;
	
	cnt_0++;
	
	if (cnt_0 == NUM_OVF)
	{
		(*ptr0)();
		cnt_0 = 0;
		TCNT0 = INIT_VALUE;
	}
}

void(*ptr1)(void) = NULL;

void Timer1_Init(void)
{
	// enable CTC mode
	SET_BIT(TCCR1B, 3);
	
	// enable global interrupts
	SET_BIT(SREG, 7);
	
	// enable peripheral interrupt
	SET_BIT(TIMSK, 4);
}

void Timer1_Start(void)
{
	// prescaler 1024
	SET_BIT(TCCR1B, 0);
	CLR_BIT(TCCR1B, 1);
	SET_BIT(TCCR1B, 2);
}

void Timer1_Stop(void)
{
	// no clock source
	CLR_BIT(TCCR1B, 0);
	CLR_BIT(TCCR1B, 1);
	CLR_BIT(TCCR1B, 2);
}

void Timer1_SetDelay(uint32 delay_ms)
{
	if (delay_ms <= 4000)
	{
		uint8 tick_time = 1024 / 16;
		uint32 num_ticks = (delay_ms * 1000) / tick_time;
		OCR1A = num_ticks - 1;
	}
}

void Timer1_SetCallback(void(*p)(void))
{
	ptr1 = p;
}

ISR(TIMER1_COMPA_vect)
{
	static uint32 cnt_1 = 0;
	cnt_1++;
	if (cnt_1 == 1)
	{
		cnt_1 = 0;
		(*ptr1)();
	}
}

void PWM0_Init(void)
{
	// set pin PB3 as output
	SET_BIT(DDRB, 3);
	// set as fast PWM
	SET_BIT(TCCR0, 3);
	SET_BIT(TCCR0, 6);
	// set as non-inverted PWM
	SET_BIT(TCCR0, 5);
}

void PWM0_Generate(uint16 duty_cycle)
{
	OCR0 = ((duty_cycle  * 256) /100) - 1;
}

void PWM0_Start(void)
{
	// start with no prescaler
	SET_BIT(TCCR0, 0);
}

