/*
 * LED.c
 *
 * Created: 4/12/2021 8:36:18 PM
 *  Author: Ahmed
 */ 

#include "LED.h"

void LED_BLUE_INIT(void) // LED Blue
{
	DIO_SetPinDir(DIO_PORTC , DIO_PIN0 , DIO_PIN_OUTPUT);
}
void LED_BLUE_ON(void)
{
	DIO_SetPinVal(DIO_PORTC , DIO_PIN0 , DIO_PIN_HIGH);
}
void LED_BLUE_OFF(void)
{
	DIO_SetPinVal(DIO_PORTC , DIO_PIN0 , DIO_PIN_LOW);
}
void LED_BLUE_TOGGLE(void)
{
	DIO_TogglePIN(DIO_PORTC , DIO_PIN0);
}
//**********************************************************************
void LED_RED_INIT(void) //LED RED
{
	DIO_SetPinDir(DIO_PORTC , DIO_PIN1 , DIO_PIN_OUTPUT);
}
void LED_RED_ON(void)
{
	DIO_SetPinVal(DIO_PORTC , DIO_PIN1 , DIO_PIN_HIGH);
}
void LED_RED_OFF(void)
{
	DIO_SetPinVal(DIO_PORTC , DIO_PIN1 , DIO_PIN_LOW);
}
void LED_RED_TOGGLE(void)
{
	DIO_TogglePIN(DIO_PORTC , DIO_PIN1);
}
