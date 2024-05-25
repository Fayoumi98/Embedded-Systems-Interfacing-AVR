/*
 * Section_7_UART.c
 * Author : Fayoumi
 */ 

#include <avr/io.h>
#include "headers/headers.h"
#include "headers/UART.h"

int main(void)
{
	Uart_init();

	uint8_t i = 0;
	
    while (1) 
    {
		Uart_Transmit(i++);
		_delay_ms(100);
    }
}

