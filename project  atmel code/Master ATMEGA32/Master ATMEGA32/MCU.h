/*
 * MCU.h
 *
 * Created: 4/12/2021 1:05:40 AM
 *  Author: Ahmed
 */ 


#ifndef MCU_H_
#define MCU_H_
#include "STD.h"
#define DDRA  (*(volatile uint8*)(0x3A))
#define PORTA (*(volatile uint8*)(0x3B))
#define PINA  (*(volatile uint8*)(0x39))

#define DDRB  (*(volatile uint8*)(0x37))
#define PORTB (*(volatile uint8*)(0x38))
#define PINB  (*(volatile uint8*)(0x36))

#define DDRC  (*(volatile uint8*)(0x34))
#define PORTC (*(volatile uint8*)(0x35))
#define PINC  (*(volatile uint8*)(0x33))

#define DDRD  (*(volatile uint8*)(0x31))
#define PORTD (*(volatile uint8*)(0x32))
#define PIND  (*(volatile uint8*)(0x30))

//***************************  EXT INT *****************************/

#define SREG   (*(volatile uint8*)(0x5F))
#define GICR   (*(volatile uint8*)(0x5B))
#define GIFR   (*(volatile uint8*)(0x5A))
#define MCUCR  (*(volatile uint8*)(0x55))
#define MCUCSR (*(volatile uint8*)(0x54))

//**************************** ADC *********************************/
#define ADMUX           (*(volatile uint8 *)(0x27))
#define ADCSRA          (*(volatile uint8 *)(0x26))
#define ADCH            (*(volatile uint8 *)(0x25))
#define ADCL            (*(volatile uint8 *)(0x24))
#define ADC_ADJUST      (*(volatile uint16 *)(0x24))
#define SFIOR           (*(volatile uint8 *)(0x50))

//**************************** Timer0 *********************************/

#define TCNT0  (*(volatile uint8*)(0x52))
#define TCCR0  (*(volatile uint8*)(0x53))
#define OCR0   (*(volatile uint8*)(0x5C))
#define TIMSK  (*(volatile uint8*)(0x59))

//*************************** Timer 1 *********************************/

#define TCCR1A (*(volatile uint8*)(0x4F))
#define TCCR1B (*(volatile uint8*)(0x4E))
#define OCR1A  (*(volatile uint16*)(0x4A))

//**************************** UART ***********************************/
#define UBRRH   (*((volatile uint8*)0x40))
#define UBRRL   (*((volatile uint8*)0x29))
#define UCSRA   (*((volatile uint8*)0x2B))
#define UCSRB   (*((volatile uint8*)0x2A))
#define UCSRC   (*((volatile uint8*)0x40))
#define UDR     (*((volatile uint8*)0x2C))
//*************************** SPI *************************************/
#define SPCR  (*(volatile uint16*)(0x2D))
#define SPSR  (*(volatile uint16*)(0x2E))
#define SPDR  (*(volatile uint16*)(0x2F))



#endif /* MCU_H_ */