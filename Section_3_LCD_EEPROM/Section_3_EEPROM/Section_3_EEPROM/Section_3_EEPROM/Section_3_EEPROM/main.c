/*
 * Section_3_EEPROM.c
 *  Author: Fayoumi
 */

#include "headers/headers.h"
#include "LCD.h"
#include "EEPROM.h"

int main(void)
{
	uint8_t counter = EEPROM_read(5);
	LCD_init();
	
	
    while (1) 
    {

		_delay_ms(100);
		LCD_write_command(0x01);
		LCD_write_num(counter++);
		EEPROM_write(5,counter);
    }
}

