/*
 * Air_Conditoner.c
 *
 * Created: 6/22/2021 9:20:43 PM
 *  Author: Ahmed
 */ 
#include "Air_Conditoner.h"

void AC_INIT(void)

{
	DIO_SetPinDir(DIO_PORTC , DIO_PIN4 , DIO_PIN_OUTPUT);
}
void AC_ON(void)

{
	DIO_SetPinVal(DIO_PORTC , DIO_PIN4 , DIO_PIN_HIGH);
}
void AC_OFF(void)

{
	DIO_SetPinVal(DIO_PORTC , DIO_PIN4 , DIO_PIN_LOW);
}
void AC_TOGGLE(void)

{
	DIO_TogglePIN(DIO_PORTC , DIO_PIN4);
}