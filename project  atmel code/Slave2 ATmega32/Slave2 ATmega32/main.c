/*
 * Slave2 ATmega32.c
 *
 * Created: 6/23/2021 3:44:54 PM
 * Author : Ahmed
 */ 

#include "SPI.h"
#include "LCD.h"
#include "Air_Conditoner.h"

 
#include "avr/interrupt.h"



uint8 Receive_data = 0 ; // Rx Data from Master Micro As a global variable for the main & ISR Functions

int main(void)
{
	
	LCD_INIT(); 
	
	AC_INIT(); //Air Conditioner Initializing 
	
	SPI_Slave_Init_INT(); // Initializing the micro controller as a slave SPI with Interrupt

	
	
	
	
	uint8 *x =  "Temp =" ; // The Constant Displays to declare about the current Temprature and The A/C Mode
	uint8 *y = "A/C is";
	LCD_GoTo(0,0);
	LCD_Write_String(x);
	LCD_GoTo(0,1);
	LCD_Write_String(y);
	
	
	while (1)
	{
		Receive_data = SPI_RC();  // Initializing received data from the Master Micro
		
		
		/************************* Air Conditioner **************/
		
		LCD_GoTo(7,0);
		LCD_WriteInteger(Receive_data); // The ADC Read Came from the Master Micro to be displayed on the LCD 
		
		if (Receive_data  >= 25) //  Air Conditioner is ON if temp >= 25c
		{
			AC_ON();
			uint8 *c = "ON ";
			LCD_GoTo(7,1);
			LCD_Write_String(c);
		}
		
		
		
		if (Receive_data  < 24 )//  Air Conditioner is off if temp < 24c
		{
			AC_OFF();
			uint8 *f = "OFF";
			LCD_GoTo(7,1);
			LCD_Write_String(f); 
		}
	
	}
	
}
ISR(SPI_STC_vect)
{
	Receive_data = SPI_RC(); // using the received data if true for an Interrupt 
}