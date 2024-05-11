/*
 * Section_3_LCD.c
 *  Author: Fayoumi
 */

#include "headers/headers.h"
#include "LCD.h"

int main(void)
{
	uint32_t counter = 0;
	
	LCD_init();
	//LCD_write_char('A');
	//LCD_write_string("hello world");
	//LCD_write_num(1234);
    while (1) 
    {

		_delay_ms(50);
		LCD_write_command(0x01);
		LCD_write_num(counter++);
		
    }
}

