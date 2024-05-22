/*
 * timer1.c
 * Author : Fayoumi
 */ 


#include "headers/timer1.h"


uint16_t timer1_ICU_capture(void)
{
	uint16_t t1,t2;
	// Control Register A: enable CTC mode		WGM11 = 0		WGM10 = 0      
	TCCR1A = 0;
	
	// Control Register B:		No prescaler 
	// Control Register B:		Input Capture Edge Select (0 falling edge - 1 rising edge)
	TCCR1B |= 1<<CS00 | 1<<ICES1;
	
	// Interrupt Flag Register (TIFR) : set Input Capture Flag (ICF1) to clear interrupt flag
	// Note : ICF1 is automatically cleared when the Input Capture Interrupt Vector is executed. 
	//		  Alternatively, ICF1 can be cleared by writing a logic one to its bit location.
	TIFR |= 1<<ICF1;
	
	while(READBIT(TIFR,ICF1) == 0); // wait until first rising edge detect
	t1 = ICR1;                      // store value of first rising edge from Input Capture Register (ICR = 16bit)
	TIFR |= 1<<ICF1;                // clear IC flag

	while(READBIT(TIFR,ICF1) == 0); // wait until first rising edge detect
	t2 = ICR1;                      // store value of second rising edge from Input Capture Register (ICR = 16bit)
	TIFR |= 1<<ICF1;                // clear IC flag
	
	return (t2-t1)/16.0;
}