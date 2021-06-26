/*
 * LCD.h
 *
 * Created: 4/19/2021 11:44:51 PM
 *  Author: Ahmed
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include "LCD_CFG.h"

void LCD_INIT(void);

void LCD_Write_Command(uint8 cmd);

void LCD_Write_Char(uint8 chr);

void LCD_Write_String(uint8* str);

void LCD_GoTo(uint8 col, uint8 row);

void LCD_Clear(void);

void LCD_WriteInteger(sint32 intgr);

#endif /* LCD_H_ */