/*
 * Section_4_Keypad.c
 * Author : Fayoumi
 */ 

#include <avr/io.h>
#include "headers/headers.h"
#include "headers/LCD.h"
#include "headers/keypad.h"

int main(void)
{
	
	LCD_init();
	keypad_init();
	
    while (1) 
    {
		int8_t key = keypad_read();
		
		if(key != -1)
		{
			// Clear LCD display
			LCD_write_command(0x1);
			LCD_write_char(key);
		}
    }
}

