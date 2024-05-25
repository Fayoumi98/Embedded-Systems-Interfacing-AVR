/*
 * Section_6_PWM.c
 * Author : Fayoumi
 */ 

#include <avr/io.h>
#include "headers/PWM.h"

int main(void)
{	
	// initialize OC1A timer 1 Fast PWM
	PWM_OC1A_init();
	// Set duty cycle to 50%
	PWM_OC1A_set_duty(25);
	
	/*
		Fast PWM mode
		Period = 1024 * 1/16 = 64 Msec
		Phase correct PWM mode
		Period = 1024* 2 * 1/16 = 128 Msec
		Phase correct PWM mode  ICR1 = 1023*2 = 2046
		Period = 2046* 2 * 1/16 = 256 Msec
	*/
	
    while (1) 
    {
		
    }
}

