/*
 * DIO.h
 *
 * Created: 4/12/2021 10:23:52 PM
 *  Author: Ahmed
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "STD.h"
#include "BIT_Math.h"
#include "MCU.h"

#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

#define DIO_PIN0    0
#define DIO_PIN1    1
#define DIO_PIN2    2
#define DIO_PIN3    3
#define DIO_PIN4    4
#define DIO_PIN5    5
#define DIO_PIN6    6
#define DIO_PIN7    7

#define DIO_PIN_INPUT    0
#define DIO_PIN_OUTPUT   1

#define DIO_PORT_INPUT   0
#define DIO_PORT_OUTPUT  1

#define DIO_PIN_LOW      0
#define DIO_PIN_HIGH     1

#define DIO_PORT_LOW     0x00
#define DIO_PORT_HIGH    0xff

void DIO_SetPortDir(uint8 Port, uint8 dir);
void DIO_SetPinDir(uint8 Port,uint8 pin , uint8 dir);

void DIO_SetPortVal(uint8 Port, uint8 val);
void DIO_SetPinVal(uint8 Port, uint8 pin, uint8 val);

uint8 DIO_GetPortVal(uint8 Port);
uint8 DIO_GetPinVal(uint8 Port, uint8 pin);

void DIO_TogglePort(uint8 Port);
void DIO_TogglePIN(uint8 Port, uint8 pin);

void DIO_SETPULLUP(uint8 port, uint8 pin);

#endif /* DIO_H_ */