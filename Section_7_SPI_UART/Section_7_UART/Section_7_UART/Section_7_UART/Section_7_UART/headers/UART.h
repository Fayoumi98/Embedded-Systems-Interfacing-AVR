/*
 * UART.h
 *  Author: Fayoumi
 */ 


#ifndef UART_H_
#define UART_H_

#include "headers.h"


/*****************************************************************************
* Function Name: Uart_init
* Purpose      : init uart with one zero bit, no parity, baud rate 9600 and 8 bit data
* Parameters   : void
* Return value : void
*****************************************************************************/
void Uart_init(void);

/*****************************************************************************
* Function Name: Uart_Transmit
* Purpose      : Send 8-bit data and make sure the data is out (sync function)
* Parameters   : uint8_t  data to send
* Return value : void
*****************************************************************************/
void Uart_Transmit(uint8_t);

/*****************************************************************************
* Function Name: Uart_Read
* Purpose      : wait until receiving 1 byte (sync function)
* Parameters   : void
* Return value : data received
*****************************************************************************/
uint8_t Uart_Receive(void);

/*****************************************************************************
* Function Name: Uart_Transmit_string
* Purpose      : Send array of char  and make sure the string is out
* Parameters   : uint8_t*  pointer to string which needed to send
* Return value : void
*****************************************************************************/
void Uart_Transmit_string(uint8_t *data);


#endif /* UART_H_ */