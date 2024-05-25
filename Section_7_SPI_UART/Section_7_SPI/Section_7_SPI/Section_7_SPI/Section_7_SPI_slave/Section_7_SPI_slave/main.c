/*
 * Section_7_SPI_slave.c
 * Author : Fayoumi
 */ 

#include <avr/io.h>
#include "headers/headers.h"
#include "headers/LCD.h"
#include "headers/SPI.h"

int main(void)
{
	SPI_slave_init();
	LCD_init();
	
    while (1) 
    {
		LCD_write_command(0x80);
		LCD_write_num(SPI_receive_char());
    }
}

