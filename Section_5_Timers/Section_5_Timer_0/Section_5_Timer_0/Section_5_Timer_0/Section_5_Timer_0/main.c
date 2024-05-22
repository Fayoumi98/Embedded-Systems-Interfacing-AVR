/*
 * Section_5_Timer_0.c
 * Author : Fayoumi
 */ 

#include <avr/io.h>
#include "headers//headers.h"

int main(void)
{

	SETBIT(DDRD,2);
	
	// Normal mode example
	//timer0_NM_init();

	// CTC mode example
	//timer0_CTC_init(249);
	
	// Frequency generator mode example:  frequency Generated  = 16000000 / ((255+1) * 2) = 3125 hz = 3.125 khz
	timer0_FG_init(255);
	
    while (1) 
    {
		
    }
}



/*
	Clock cycle (Msec) = 1/16 Msec x count = 1 sec = 1000000 Msec
	count   10000/16 = 62,500
	count   0 => 625000
*/
// timer 0 normal mode ISR
// note : TIMER0_OVF_vect source from interrupt vector table
ISR(TIMER0_OVF_vect)
{
	static uint16_t count = 0;
	count++;
	if(count == 62500)
	{
		count = 0;
		TOGBIT(PORTD,2);
	}
}


/*
	OCR0 * Prescaler * Clock cycle = 250 * 1024 * 1/16Msec = 16 msec
	16 msec * count = 1000 msec = 1sec
	count = 62.5 = 62
*/
// timer 0 CTC mode ISR
// note : TIMER0_COMP_vect source from interrupt vector table
ISR(TIMER0_COMP_vect)
{
	static uint16_t count = 0;
	count++;
	if(count == 62)
	{
		count = 0;
		TOGBIT(PORTD,2);
	}
}