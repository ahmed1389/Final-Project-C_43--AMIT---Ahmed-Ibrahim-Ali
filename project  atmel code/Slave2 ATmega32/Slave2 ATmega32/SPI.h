/*
 * SPI.h
 *
 * Created: 6/20/2021 2:13:36 PM
 *  Author: Ahmed
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"

void  SPI_Master_Init(void);

void  SPI_Slave_Init(void); 

void  SPI_Master_InitTrans(void);

void  SPI_Master_EndTrans(void);

uint8 SPI_TranSiver(uint8 data);

void SPI_Slave_Init_INT(void);

uint8 SPI_RC();

#endif /* SPI_H_ */