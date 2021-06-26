/*
 * UART.h
 *
 * Created: 5/24/2021 10:18:26 PM
 *  Author: Ahmed
 */ 


#ifndef UART_H_
#define UART_H_

#include "MCU.h"
#include "STD.h"
#include "BIT_Math.h"

void UART_Init(void);

void UART_Tx(uint8 chr);

void UART_TxString(uint8* str);

void UART_Rx (void);



#endif /* UART_H_ */