/*
 * SPI.c
 *
 * Created: 6/20/2021 2:13:13 PM
 *  Author: Ahmed
 */ 

#include "SPI.h"


void  SPI_Master_Init(void)
{
	/* SS Pin o/p , if it master you can make it any other dio pin but if it is slave must be the ss pin*/
	DIO_SetPinDir(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT);
	/*MOSI PIN*/
	DIO_SetPinDir(DIO_PORTB,DIO_PIN5,DIO_PIN_OUTPUT);
	/*MISO PIN*/
	DIO_SetPinDir(DIO_PORTB,DIO_PIN6,DIO_PIN_INPUT);
	/*CLK PIN*/
	DIO_SetPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT);
	
	SPCR = 0x53;
	
}

void  SPI_Slave_Init(void)
{
	/* SS Pin I/P*/
	DIO_SetPinDir(DIO_PORTB,DIO_PIN4,DIO_PIN_INPUT);
	/*MOSI PIN I/P*/
	DIO_SetPinDir(DIO_PORTB,DIO_PIN5,DIO_PIN_INPUT);
	/*MISO PIN O/P*/
	DIO_SetPinDir(DIO_PORTB,DIO_PIN6,DIO_PIN_OUTPUT);
	/*CLK PIN I/P*/
	DIO_SetPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_INPUT);
	
	SPCR = 0x40;
}

void  SPI_Master_InitTrans(void)
{
	DIO_SetPinVal(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
	
}

void  SPI_Master_EndTrans(void)
{
	DIO_SetPinVal(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
}

uint8 SPI_TranSiver(uint8 data)
{
	SPDR = data ; 
	
	while(GET_BIT( SPSR , 7 ) == 0);
	
	return SPDR ; 
	
}

void SPI_Slave_Init_INT(void)  // for interrupt 
{
	DIO_SetPinDir(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT);
	DIO_SetPinDir(DIO_PORTB, DIO_PIN5, DIO_PIN_INPUT);
	DIO_SetPinDir(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTB, DIO_PIN7, DIO_PIN_INPUT);
	
	SET_BIT(SPCR, 6);
	SET_BIT(SREG, 7);
	SET_BIT(SPCR, 7);
}
uint8 SPI_RC()
{
	return SPDR;
}