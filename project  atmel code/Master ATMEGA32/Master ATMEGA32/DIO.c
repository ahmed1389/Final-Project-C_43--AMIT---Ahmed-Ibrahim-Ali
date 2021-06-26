/*
 * DIO.c
 *
 * Created: 4/12/2021 10:23:26 PM
 *  Author: Ahmed
 */ 
#include "DIO.h"

void DIO_SetPortDir(uint8 Port, uint8 dir)
{
	switch(Port)
	{
	case DIO_PORTA:
	DDRA= dir;
	break;
	
	
	case DIO_PORTB:
	DDRB= dir;
	break;
	
	
	case DIO_PORTC:
	DDRC= dir;
	break;
	

	case DIO_PORTD:
	DDRD= dir;
	break;
	
	default:
	
	break ;
	}
}
void DIO_SetPinDir(uint8 Port,uint8 pin , uint8 dir)
{
	switch(dir)
	{
		case DIO_PIN_OUTPUT :
		
		switch (Port)
		{
			case DIO_PORTA :
			SET_BIT(DDRA , pin);
			break;
			
			case DIO_PORTB :
			SET_BIT(DDRB , pin);
			break;
			
			case DIO_PORTC :
			SET_BIT(DDRC , pin);
			break;
			
			case DIO_PORTD :
			SET_BIT(DDRD , pin);
			break;
			
			default:
			
			break;
		}
		
		break;
		
		case DIO_PIN_INPUT :
		
		switch (Port)
		{
			case DIO_PORTA :
			CLR_BIT(DDRA , pin);
			break;
			
			case DIO_PORTB :
			CLR_BIT(DDRB , pin);
			break;
			
			case DIO_PORTC :
			CLR_BIT(DDRC , pin);
			break;
			
			case DIO_PORTD :
			CLR_BIT(DDRD , pin);
			break;
			
			default:
			
			break;
		}
		
		break;	
	}
}

void DIO_SetPortVal(uint8 Port, uint8 val)
{
	switch(Port)
	{
		case DIO_PORTA:
		PORTA= val;
		break;
		
		
		case DIO_PORTB:
		PORTB= val;
		break;
		

		case DIO_PORTC:
		PORTC= val;
		break;
		

		case DIO_PORTD:
		PORTD= val;
		break;
		
		default:
		
		break ;
	}
}
void DIO_SetPinVal(uint8 Port, uint8 pin, uint8 val)
{
	switch(val)
	{
		case DIO_PIN_HIGH :
		
		switch (Port)
		{
			case DIO_PORTA :
			SET_BIT(PORTA , pin);
			break;
			
			case DIO_PORTB :
			SET_BIT(PORTB , pin);
			break;
			
			case DIO_PORTC :
			SET_BIT(PORTC , pin);
			break;
			
			case DIO_PORTD :
			SET_BIT(PORTD , pin);
			break;
			
			default:
			
			break;
		}
		
		break;
		
		case DIO_PIN_LOW :
		
		switch (Port)
		{
			case DIO_PORTA :
			CLR_BIT(PORTA , pin);
			break;
			
			case DIO_PORTB :
			CLR_BIT(PORTB , pin);
			break;
			
			case DIO_PORTC :
			CLR_BIT(PORTC , pin);
			break;
			
			case DIO_PORTD :
			CLR_BIT(PORTD , pin);
			break;
			
			default:
			
			break;
		}
		
		break;
	}
}
uint8 DIO_GetPortVal(uint8 Port)
{ 
	uint8 val=0 ; 
	
	switch(Port)
	{
	case DIO_PORTA:
	val= PINA;
	break;
	
	
	case DIO_PORTB:
	val=PINC;
	break;
	
	
	case DIO_PORTC:
	val=PINC;
	break;
	
	
	case DIO_PORTD:
	val=PIND;
	break;
	
	default:
	
	break ;
	}
	return val ;
}
uint8 DIO_GetPinVal(uint8 Port, uint8 pin)
{
	uint8 val = 0;
	switch(Port)
	{
		case DIO_PORTA:
		val=GET_BIT(PINA,pin);
		break;
		
		case DIO_PORTB:
		val=GET_BIT(PINB,pin);
		break;
		
		case DIO_PORTC:
		val=GET_BIT(PINC,pin);
		break;
		
		case DIO_PORTD:
		val=GET_BIT(PIND,pin);
		break;
		
		default:
		break;
	}
	return val;
}

void DIO_TogglePort(uint8 Port)

{
	switch(Port)
	{
		case DIO_PORTA:
		PORTA ^=0xff;
		break;
		
		case DIO_PORTB:
		PORTB ^=0xff;
		break;
		
		case DIO_PORTC:
		PORTC ^=0xff;
		break;
	
		case DIO_PORTD:
		PORTD ^=0xff;
		break;
		
		default:
		
		break ;
	}
}
void DIO_TogglePIN(uint8 Port, uint8 pin)
{
	switch(Port)
	{
		case DIO_PORTA:
		Toggle_BIT(PORTA,pin);
		break;
		
		case DIO_PORTB:
		Toggle_BIT(PORTB,pin);
		break;
		
		case DIO_PORTC:
		Toggle_BIT(PORTC,pin);
		break;
		
		case DIO_PORTD:
		Toggle_BIT(PORTD,pin);
		break;
		
		default:
		break;
		
	}
}
void DIO_SETPULLUP(uint8 port, uint8 pin)
{
	switch(port)
	{
		case DIO_PORTA :
		SET_BIT(PORTA , pin);
		break;
		
		case DIO_PORTB :
		SET_BIT(PORTB , pin);
		break;
		
		case DIO_PORTC :
		SET_BIT(PORTC , pin);
		break;
		
		case DIO_PORTD :
		SET_BIT(PORTD , pin);
		break;
		
		default:
		break;
	}
}