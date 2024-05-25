/*
 * UART.c
 *  Author: Fayoumi
 */ 

#include "headers/UART.h"



void Uart_init(void)
{
	// baud rate register (calculated from formula table 60 or from table 71)
	UBRRL = 103;
	
	// 
	UCSRB |= (1 << RXEN) | (1 << TXEN);
	// enable 8 bit mode (from table 66)
	// Set   UCSZ2 = 0		UCSZ1 = 1		UCSZ0 = 1
	UCSRB |= (1 << UCSZ1) | (1 << UCSZ0) ;
}


void Uart_Transmit(uint8_t data)
{
	// write data on USART I/O Data	Register – UDR
	UDR = data;
	while(READBIT(UCSRA,TXC) == 0);
}




uint8_t Uart_Receive(void)
{
	// RXC: USART Receive Complete
	while(READBIT(UCSRA,RXC) == 0);
	// return data from USART I/O Data Register – UDR
	return UDR;
}



void Uart_Transmit_string(uint8_t *data)
{
	for(uint8_t i = 0; data[i] != '\0'; i++)
	Uart_Transmit(data[i]);
}