/*
 * SPI.c
 *  Author: Fayoumi
 */ 


#include "headers/SPI.h"

#define SS   PB4
#define MOSI PB5
#define MISO PB6
#define SCK  PB7

void SPI_master_init(void)
{
	// Master mode (MOSI , SS , SCK = output)
	DDRB |= 1<<SS |1<<MOSI | 1<<SCK;
	
	// MSTR: Master/Slave Select
	SETBIT(SPCR,MSTR);
	
	// SPE: SPI Enable
	SETBIT(SPCR,SPE);
}

void SPI_slave_init(void)
{
	// Slave mode (MISO = output)
	DDRB |= 1<<MISO;	

	// SPE: SPI Enable
	SETBIT(SPCR,SPE);
}



void SPI_send_char(uint8_t data)
{
	// write data on SPI Data Register – SPDR
	SPDR = data;
	// from SPI Status Register – SPSR while SPIF: SPI Interrupt Flag
	while(READBIT(SPSR,SPIF) == 0);
}




uint8_t SPI_receive_char(){
	
	// from SPI Status Register – SPSR while SPIF: SPI Interrupt Flag
	while(READBIT(SPSR,SPIF) == 0);
	
	// return data from SPI Data Register
	return SPDR;
	
}