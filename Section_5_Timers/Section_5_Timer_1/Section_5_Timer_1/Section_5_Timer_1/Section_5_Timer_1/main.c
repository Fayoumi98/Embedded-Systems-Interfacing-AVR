/*
 * Section_5_Timer_1.c
 * Author : Fayoumi
 */ 

#include <avr/io.h>
#include "headers/headers.h"
#include "headers/timer0.h"
#include "headers/timer1.h"


int main(void)
{
	
	// initialize LCD
	LCD_init();
	// maximum frequency at OC) = 31.25 Khz
	timer0_FG_init(200);
	uint16_t period = timer1_ICU_capture();
	LCD_write_string("Preiod = ");
	LCD_write_num(period);
	LCD_write_string(" usec");
	
    while (1) 
    {


    }
}

