/*
 * Section_7_UART_receiver.c
 * Author : Fayoumi
 */ 

#include <avr/io.h>
#include "headers/headers.h"
#include "headers/UART.h"
#include "headers/LCD.h"

int main(void)
{
	Uart_init();
	LCD_init();

    while (1) 
    {
		LCD_write_command(0x80);
		LCD_write_num(Uart_Receive());
		
    }
}

