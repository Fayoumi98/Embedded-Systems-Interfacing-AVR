/*
 * Section_7_SPI.c
 * Author : Fayoumi
 */ 

#include <avr/io.h>
#include "headers/headers.h"
#include "headers/SPI.h"

int main(void)
{
	uint8_t i = 0;
	SPI_master_init();
	_delay_ms(100);
    while (1) 
    {
		SPI_send_char(i++);
		_delay_ms(100);
    }
}

