/*
 * UART.c
 *
 * Created: 5/24/2021 10:18:06 PM
 *  Author: Ahmed
 */ 

#include "UART.h"

uint8 UARTRC = 0 ;

void UART_Init(void)
{
	uint32 UBRR_Val=0 ;
	/* TX pin as output */
	SET_BIT(DDRD , 1);
	
	/* RX pin as output */
	CLR_BIT(DDRD , 0);
	
	/* Enable TX */
	SET_BIT(UCSRB , 3);
	/*Enable RX*/
	SET_BIT(UCSRB , 4);
	
	/* one stop , no parity , 8 bit data*/
	UCSRC = 0x86 ;
	
	UBRR_Val = ((160000) / (16 * 96)) -1 ;
	
	UBRRL = UBRR_Val ; 
}
void UART_Tx(uint8 chr)
{
	UDR = chr ;
	
	while (GET_BIT(UCSRA,5) == 0);
	
}
void UART_TxString(uint8* str)
{
	uint8 i = 0 ;
	
	while(str[i] !='\0')
	{
		UART_Tx(str[i]);
		i++;
	}
}



void UART_Rx (void)
{
	//if data received //
	if(GET_BIT(UCSRA,7) == 1)
	{
		UARTRC = UDR;
	}
	
	else
	{
		
	} 
}