/*
 * PWM.c
 *  Author: Fayoumi
 */ 


#include "headers/headers.h"
#include "headers/PWM.h"



void PWM_OC1A_init(void)
{
	// OC1A output
	SETBIT(DDRD,5); 
	// (non-inverting mode)		COM1A1 = 1    COM1A0 = 0			
	// (Fast PWM, 10-bit)		WGM10 = 1	  WGM11 = 1		 WGM12 = 1		 WGM13 = 0		
	// (no pre-scaler)			CS10 = 1	  CS11 = 0		 CS12 = 0
	TCCR1A |= (1 << COM1A1) | (1 << WGM10) | (1 << WGM11)  ;
	TCCR1B |= (1 << WGM12) | (1<<CS10);
	
	/*
		Phase correct PWM (remove WGM12)
		TCCR1B |= (1<<CS10);
	*/
	
	/*
		Phase correct PWM ICR1 (WGM13 = 1 , WGM11 = 1)
		TCCR1A |= (1 << COM1A1) | (1 << WGM11)  ;
		TCCR1B |= (1 << WGM13) | (1<<CS10);
		ICR1 = 1023 * 2;
	*/
}


/*
duty = OCR1A / 1023 * 100
OCR1A = duty * 10.23
*/
void PWM_OC1A_set_duty(uint8_t duty)
{
	// set output on pin OCR1A (PD5)
	OCR1A = duty * 10.23;
}
