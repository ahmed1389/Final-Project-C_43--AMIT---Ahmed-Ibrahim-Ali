/*
 * Master ATMEGA32.c
 *
 * Created: 6/20/2021 6:37:53 PM
 * Author : Ahmed
 */ 

#include "UART.h"
#include "LCD.h"
#include "SPI.h"
#include "Temp.h"
#include "Timer.h"

#define F_CPU 16000000
#include <util/delay.h>


extern uint8 UARTRC; // Master Data that will be received from the UART then sending this data to the Slave 1 Micro ex terning that data in a Global variable from UART.c File 

int main(void)
{
	UART_Init(); // Initializing UART communication protocol BLUETOOTH 
	
	Timer1_SetCallback(UART_Rx); // Taking Flag by a Timer for the UART data Receive 
	Timer1_Init();
	Timer1_SetDelay(100);
	Timer1_Start();
	
	LCD_INIT(); // Initializing LCD
	
	TempSensor_Init(); // Initializing the temperature sensor as an I/P
	 
	
	SPI_Master_Init(); // Initializing the Micro Controller as a Master and ss o/p for slave 1
	
	SPI_Master_Init2(); // Initializing the Micro Controller as a Master and ss o/p for slave 2	
		 
	 
	uint16 Temp = 0;
	    
    while (1) 
    {
		if (UARTRC)
		{
			if (UARTRC == 'p')       // Clearing Data in LCD if char 'p' is sent also to switch "BLUE & RED " LED OFF while clearing LCD "switching off LED code written in the Slave main.c"
			{ 
				_delay_ms(10);       // these delays for the Proteus simulation 
				LCD_Clear();
				_delay_ms(10);
			}
			LCD_Write_Char(UARTRC);  // writing and showing the operations taken from the UART BLUETOOTH on the LCD 
			
		SPI_Master_InitTrans();     // Choosing slave 1 for begging the transmission 
		_delay_ms(10);
		SPI_TranSiver(UARTRC);     // sending data from Master Micro and receiving data from Slave Micro to complete the SPI cycle 
		_delay_ms(10);
		SPI_Master_EndTrans();    // ending the transmission to slave 1 to complete the app
		
		UARTRC = 0;              // to end the condition after receiving the data from the user 
		}
		
		/************************* Air Conditoner **************/
	
		Temp = TempSensor_Read();  // Taking the Sensor Digital Reads on a variable 
		SPI_Master_InitTrans2();   // Choosing slave 2 for begging the transmission 
		_delay_ms(10);
		SPI_TranSiver(Temp);       //  sending the sensor reads to the chosen slave
		_delay_ms(10);             //  these delays for the Proteus simulation 
		SPI_Master_EndTrans2();    //  ending transmission to slave 2 to begin the cycle all over 
    }
	
	
}


