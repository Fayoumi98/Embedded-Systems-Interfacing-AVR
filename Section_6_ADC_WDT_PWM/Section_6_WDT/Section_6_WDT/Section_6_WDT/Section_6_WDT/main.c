/*
 * Section_6_WDT.c
 * Author : Fayoumi
 */ 

#include <avr/io.h>

#include "headers/headers.h"
#include "headers/LCD.h"
#include "headers/WDT.h"


int main(void)
{
	
	// initialize LCD
	LCD_init();
	uint8_t i = 0;
	
	WDT_on();
	
	
	while (1)
	{
		LCD_write_command(0x1);
		LCD_write_num(i++);
		_delay_ms(1100);
		
		WDT_off();
	}
}

