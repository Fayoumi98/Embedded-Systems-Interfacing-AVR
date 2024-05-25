/*
 * SPI.h
 *  Author: Fayoumi
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "headers.h"


/*****************************************************************************
* Function Name: SPI_master_init
* Purpose      : init spi to be master LSB first, freq/4 = 4Mhz
* Parameters   : void
* Return value : void
*****************************************************************************/
void SPI_master_init(void);

/*****************************************************************************
* Function Name: SPI_slave_init
* Purpose      : init spi to be slave
* Parameters   : void
* Return value : void
*****************************************************************************/
void SPI_slave_init(void);

/*****************************************************************************
* Function Name: SPI_send_char
* Purpose      : Send 8-bit data and make sure the data is out
* Parameters   : uint8_t data to send
* Return value : void
*****************************************************************************/
void SPI_send_char(uint8_t data);

/*****************************************************************************
* Function Name: SPI_receive_char
* Purpose      : wait until receiving 1 byte (sync function)
* Parameters   : void
* Return value : data received
*****************************************************************************/
uint8_t SPI_receive_char();



#endif /* SPI_H_ */