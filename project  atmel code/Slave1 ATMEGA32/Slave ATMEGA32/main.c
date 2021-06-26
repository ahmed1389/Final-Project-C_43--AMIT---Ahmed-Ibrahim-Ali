/*
 * Slave ATMEGA32.c
 *
 * Created: 6/20/2021 6:45:34 PM
 * Author : Ahmed
 */ 

#include "SPI.h"
#include "LED.h"
#include "LCD.h"


int main(void)
{
	LED_BLUE_INIT(); // Blue LED Initializing as output
	LED_RED_INIT();  // Red  LED Initializing as output
	LCD_INIT();
	
	
	SPI_Slave_Init(); // Initializing the micro controller as a slave SPI 
	
	uint8 Slave_data = 0 ; // Tx Data from Slave Micro
	
	uint8 Receive_data = 0 ; // Rx Data from Master Micro
	
	uint8 *s =  "a,b to TogleLED" ; // Instructions display for the user to know what to type to control the system LED
	uint8 *t =  "Put'p'CLR & OFF" ;
	
	
	LCD_Clear();
	LCD_GoTo(0,0);
	LCD_Write_String(s);
	LCD_GoTo(0,1);
	LCD_Write_String(t);
    
    while (1) 
    {
		Receive_data = SPI_TranSiver(Slave_data);  // Initializing received data from the Master Micro
		
		if (Receive_data == 'a') 
		{
			LED_BLUE_TOGGLE(); // Toggle Blue LED if received Char a  
		}
	
		if (Receive_data == 'b')
		{
			LED_RED_TOGGLE();  // Toggle Red LED if received Char b 
		}
		
		if (Receive_data == 'p') // Switching off "BLUE & RED" LED  for clearing data in the Master Micro in LCD "code written in the Master main.c data clearing in LCD" and also to know witch operation we are from LCD
		{
			LED_BLUE_OFF(); 
			LED_RED_OFF();
		}
		
	}
		
  }
	


