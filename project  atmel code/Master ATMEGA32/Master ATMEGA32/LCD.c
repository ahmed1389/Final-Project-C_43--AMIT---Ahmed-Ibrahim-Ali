/*
 * LCD.c
 *
 * Created: 4/19/2021 11:44:21 PM
 *  Author: Ahmed
 */ 

#include "LCD.h"
#define  F_CPU 16000000
#include <util/delay.h>

void LCD_INIT(void)
{
	DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT , RS_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT , RW_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_CMD_PORT , E_PIN  , DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , D4_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , D5_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , D6_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_MODE_DATA_PORT , D7_PIN , DIO_PIN_OUTPUT);
	
	_delay_ms(100);
	
	LCD_Write_Command(0x33);   // commands must be written to use 4-bitMode
	LCD_Write_Command(0x32);   // commands must be written to use 4-bitMode
	LCD_Write_Command(0x28);   // commands must be written to use 4-bitMode
	LCD_Write_Command(0x0c);  // turn off cruiser 
	LCD_Write_Command(0x01);  // clear screen if thing is written
	LCD_Write_Command(0x06);  // write from left to right
	LCD_Write_Command(0x02);  // begin from column 0 & row 0 , to write from the beginning of LCD
	
}

void LCD_Write_Command(uint8 cmd)
{
	DIO_SetPinVal(LCD_4BIT_MODE_CMD_PORT , RS_PIN , DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_MODE_CMD_PORT , RW_PIN , DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_MODE_CMD_PORT , E_PIN  , DIO_PIN_LOW);
	
	PORTA = (cmd & 0xf0) | (PORTA & 0x0f);
	
	DIO_SetPinVal(LCD_4BIT_MODE_CMD_PORT , E_PIN  , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_MODE_CMD_PORT , E_PIN  , DIO_PIN_LOW);
	
	PORTA = (cmd << 4) | (PORTA & 0x0f);
	
	DIO_SetPinVal(LCD_4BIT_MODE_CMD_PORT , E_PIN  , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_MODE_CMD_PORT , E_PIN  , DIO_PIN_LOW);
	
	_delay_ms(5);
}

void LCD_Write_Char(uint8 chr)
{
	DIO_SetPinVal(LCD_4BIT_MODE_CMD_PORT , RS_PIN , DIO_PIN_HIGH);
	DIO_SetPinVal(LCD_4BIT_MODE_CMD_PORT , RW_PIN , DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_MODE_CMD_PORT , E_PIN  , DIO_PIN_LOW);
	
	PORTA = (chr & 0xf0) | (PORTA & 0x0f);
	
	DIO_SetPinVal(LCD_4BIT_MODE_CMD_PORT , E_PIN  , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_MODE_CMD_PORT , E_PIN  , DIO_PIN_LOW);
	
	PORTA = (chr << 4) | (PORTA & 0x0f);
	
	DIO_SetPinVal(LCD_4BIT_MODE_CMD_PORT , E_PIN  , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_MODE_CMD_PORT , E_PIN  , DIO_PIN_LOW);
	
	_delay_ms(5);
}

void LCD_Write_String(uint8* str)
{
	uint8 i = 0;
	while(str[i] !='\0')
	{
		LCD_Write_Char(str[i]);
		i++;
	}
}

void LCD_GoTo(uint8 col, uint8 row)
{
	uint8 arr[2] = {0x80 , 0xc0};
		
	LCD_Write_Command(arr[row]+col);
}

void LCD_Clear(void)
{
	LCD_Write_Command(0x01); // clear screen if thing is written
}
void LCD_WriteInteger(sint32 intgr)
{

	sint32 y = 1;

	if(intgr < 0)
	{
		LCD_Write_Char('-');
		intgr *= -1;
	}

	while(intgr > 0)
	{
		y = ((y*10) + (intgr%10));
		intgr /= 10;
	}

	while(y > 1 )
	{
		LCD_Write_Char(((y%10)+48));
		y /= 10;
	}
}