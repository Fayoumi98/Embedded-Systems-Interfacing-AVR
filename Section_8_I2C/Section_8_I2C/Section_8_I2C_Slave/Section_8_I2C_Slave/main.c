/*
 * Section_8_I2C_Slave.c
 * Author : Fayoumi
 */ 

#include <avr/io.h>
#include "headers/headers.h"
#include "headers/I2C.h"
#include "headers/LCD.h"

int main(void)
{
	LCD_init();
	I2C_slave_Init(15);
	
    uint8_t data = 0;
	
    while (1) 
    {
		if(I2C_slave_available()== 1)
		{
			data = I2C_slave_read();
			LCD_write_command(0x80);
			LCD_write_num(data);
		}
    }
}

