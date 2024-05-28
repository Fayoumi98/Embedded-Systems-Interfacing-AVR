/*
 * I2C.c
 *  Author: Fayoumi
 */ 


#include "headers/headers.h"
#include "headers/I2C.h"



void I2C_master_init(void)
{	
	//TWI Bit Rate Register – TWBR
	// form formula set clock frequency
	TWBR = 12;
}



void I2C_master_start(void)
{
	/*
		In TWI Control Register – TWCR:
			- Set TWEN : TWI Enable Bit
			- Set TWINT : TWI Interrupt Flag (to reset it to 0)
			- Set TWSTA : TWI START Condition Bit to be sent
	*/
	TWCR = (1 << TWSTA) | (1 << TWINT) | (1 << TWEN) ;
	
	// Wait until Start condition is sent
	while(READBIT(TWCR,TWINT) == 0);
}



void I2C_master_addr(uint8_t ID, uint8_t R_W)
{
	/*
		TWI Data Register – TWDR
			- write id (address) on bit 1-7
			- if read write R_W =  1 on TWDR bit 0 else if read R_W =  0 on TWDR bit 0
			
	*/
	TWDR = (ID << 1);
	R_W == 1 ? SETBIT(TWDR,0):CLRBIT(TWDR,0);
	
	// Wait until Address is sent
	TWCR = (1 << TWINT) | (1 << TWEN) ;
	while(READBIT(TWCR,TWINT) == 0);
}



void I2C_master_write(uint8_t data)
{
	/*
		TWI Data Register – TWDR
			- write data on bit 0-7
			*/
	TWDR = data;
	
	// Wait until data is sent
	TWCR = (1 << TWINT) | (1 << TWEN) ;
	while(READBIT(TWCR,TWINT) == 0);
}



void I2C_master_stop(void)
{	
	/*
		In TWI Control Register – TWCR:
			- Set TWEN : TWI Enable Bit
			- Set TWINT : TWI Interrupt Flag (to reset it to 0)
			- Set TWSTO : TWI Stop Condition Bit to be sent
	*/
	TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN) ;
}



void I2C_slave_Init(uint8_t My_Add)
{
	// TWI (Slave) Address	Register – TWAR
	TWAR = My_Add << 1;
	// Set Address	Register bit 0 = 1 (to enable this slave so the master to the same data at the same time [general call] )
	SETBIT(TWAR,TWGCE);
}



uint8_t I2C_slave_available()
{
	/*
	In TWI Control Register – TWCR:
		- Set TWEN : TWI Enable Bit
		- Set TWINT : TWI Interrupt Flag (to reset it to 0)
		- Set TWEA: TWI Enable Acknowledge Bit
	*/
	TWCR = (1 << TWEA) | (1 << TWINT) | (1 << TWEN) ;
	
	// Wait until slave address and Write are received from master
	while(READBIT(TWCR,TWINT) == 0);
	
	// Own SLA+W has been received + ACK has been returned (Table 76)
	if(TWSR == 0x60)
	{
		// data ready to transfer
		return 1 ;
	}
	else
	{
		// data not ready to transfer
		return 0 ;
	}
}



uint8_t I2C_slave_read(void)
{
	/*
	In TWI Control Register – TWCR:
		- Set TWEN : TWI Enable Bit
		- Set TWINT : TWI Interrupt Flag (to reset it to 0)
		- Set TWEA: TWI Enable Acknowledge Bit
	*/
	TWCR = (1 << TWEA) | (1 << TWINT) | (1 << TWEN) ;
	
	// Wait until slave address and Write are received from master
	while(READBIT(TWCR,TWINT) == 0);
	
	// when data ready return it
	return TWDR;
}