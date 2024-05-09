#include <avr/io.h>
#include <avr/interrupt.h>



int main(void)
{
    // PB0 output pin and 5v will be output
    DDRB |= 1<<0;
	// PD2 Input pin  // pull up
	PORTD = 1<<2;
	
	// MCUCR Interrupt control register
	// ISC Interrupt Sense Control has 3 modes :
	//1/ Rising Edge
	//2/ Falling Edge
	//3/ Any logic change
	//4/ Low level
	// ISC00 & ISC01    ====> interrupt 0	PD2
	// ISC10 & ISC11    ====> interrupt 1	PD3
	MCUCR |= (1<<ISC00) | (1<<ISC01);
	
	// GICR general interrupt control register
	// enables masked interrupts INT0 INT1 INT2
	// BIT6 External interrupt request 0 enable
	GICR |= 1<<INT0;

	// SREG : Status Register (Non Memory Mapped Register)
	// Note : SREG has a virtual address
	// Global interrupt flag enabled
	SREG |= 1<<7;
	
    while (1) 
    {
		
    }
}



// Create Interrupt Service Routine
ISR(INT0_vect)
{
	PORTB ^= 1<<0;
}
