/*
 * timer0.h
 *  Author: Fayoumi
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "headers/headers.h"
#include "headers/timer0.h"



void timer0_NM_init(void)
{
	// enable normal mode with no prescaler
	// CS00 = 1		CS01 = 0	CS02 = 0
	TCCR0 |= (1<<CS00);
	
	// Interrupt Mask Register (enable interrupt overflow)
	TIMSK |= (1<<TOIE0);
	
	// Enable global interrupt
	sei();
}



void timer0_CTC_init(uint8_t value)
{
	// enable CTC mode with 1024 prescaler
	// CTC : WGM00 = 0		WGM01 = 1 
	// 1024 prescaler : CS00 = 1		CS01 = 0	CS02 = 1
	TCCR0 |= (1<<CS00) | (1<<CS02) | (1<<WGM01);
	
	OCR0 = value;
		 
	// Interrupt Mask Register (enable interrupt overflow)
	// CTC mode interrupt
	TIMSK |= (1<<OCIE0);
		
	// Enable global interrupt
	sei();
}




void timer0_FG_init(uint8_t value)
{
	// configure OC0 pin output
	SETBIT(DDRB,3);
	
	// enable FG mode with 1024 prescaler
	// CTC : WGM00 = 0		WGM01 = 1
	// 1024 prescaler : CS00 = 1		CS01 = 0	CS02 = 1
	TCCR0 |= (1<<CS00) | (1<<CS02) | (1<<WGM01) | (1<<COM00);
		
	OCR0 = value;
}



#endif /* TIMER0_H_ */