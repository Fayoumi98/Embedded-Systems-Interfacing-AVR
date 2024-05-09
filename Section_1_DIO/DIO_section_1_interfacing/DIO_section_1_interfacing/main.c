/*
 * DIO_section_1_interfacing.c
 *
 * Author : Omar ElFayoumi
 */ 

#include <avr/io.h>


int main(void)
{
	// PB0 output pin and 5v will be output
	DDRB |= 1<<0;
	// PB1 Input pin  // pull up
	PORTB |= 1<<1;
	
    while (1) 
    {
		if (PINB & 0b10)
		{
			PORTB &= ~(1<<0);
		}
		else
		{
			PORTB |= 1<<0;
		}
    }
}

