/*
 * Section_6_ADC.c
 * Author : Fayoumi
 */ 

#include <avr/io.h>
#include "headers/headers.h"
#include "headers/ADC.h"
#include "headers//LCD.h"


int main(void)
{	
	// initialize ADC
    ADC_init();
	
	// initialize LCD
	LCD_init();
	
	while (1) 
    {
		LCD_write_command(0x1);
		LCD_write_num(ADC_read(0));
		_delay_ms(1000);
    }
}

