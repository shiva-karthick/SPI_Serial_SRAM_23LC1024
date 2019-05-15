

#include "23LC1024.h"


void initSPI(void){
	SPI_SS_DDR/*DDRB*/ |= (1 << SPI_SS/*PB2*/);    /* set SS output */
	SPI_SS_PORT/*PORTB*/ |= (1 << SPI_SS/*PB2*/);		/* start off not selected (high) */

	SPI_MOSI_DDR/*DDRB*/ |= (1 << SPI_MOSI/*PB3*/);		/* output on MOSI */
	
	SPI_MISO_PORT/*PORTB*/ |= (1 << SPI_MISO/*PB4*/);   /* pull-up on MISO which is a input by default*/
	SPI_SCK_DDR/*DDRB*/ |= (1 << SPI_SCK/*PB5*/);       /* output on SCK */


	/* Don't have to set phase, polarity b/c default works with 25LCxxx chips */
	SPCR |= (1 << SPR0);    /* div 16, safer for breadboards */
	SPCR |= (1 << MSTR);    /* clock master */
	SPCR |= (1 << SPE);     /* enable : When the SPE bit is written to one, the SPI is enabled. This bit must be set to enable any SPI operations.*/
}

void SPI_tradeByte(uint8_t byte) {
	SPDR = byte;                       /* SPI starts sending immediately */
	loop_until_bit_is_set(SPSR, SPIF);                /* wait until done */
	/* SPDR now contains the received byte */
}

/*
*	Microchip 23LC1024 needs 24 bit address, so I have divided into 3 x 8s.
*	The first 7 bits will be don't care bits. The address is only 17 bits.
*	The last 8 bits will be ignored. Nevertheless, we have to ALL send 32 bits. 
*/

void EEPROM_send24BitAddress(uint32_t address) {
	uint8_t dont_care_7_bits;
	dont_care_7_bits = (uint8_t)(address >> 7);    /* shift 7 don't care bits */
	SPI_tradeByte((uint8_t) (address >> 8));    /* most significant byte */
	SPI_tradeByte((uint8_t) (address >> 8));    /* most significant byte */
	SPI_tradeByte((uint8_t) (address >> 8));    /* most significant byte */
	// The last 8 bits are ignored ! 
}

/*
*		
*/
void EEPROM_send8BitAddress(uint8_t address) {
	SPI_tradeByte((uint8_t) address);          /* least significant byte */
} 


uint8_t EEPROM_readStatus(void) {
	SLAVE_SELECT;
	SPI_tradeByte(EEPROM_READ_MODE_REGISTER);
	SPI_tradeByte(0);                            /* clock out eight bits */
	SLAVE_DESELECT;
	return (SPDR);                                  /* return the result */
}

uint8_t EEPROM_readByte(uint32_t address) {
	SLAVE_SELECT;
	SPI_tradeByte(EEPROM_READ);
	EEPROM_send24BitAddress(address);
	SPI_tradeByte(0);
	SLAVE_DESELECT;
	return (SPDR);
}

uint16_t EEPROM_readWord(uint32_t address) {
	uint16_t eepromWord;
	SLAVE_SELECT;
	SPI_tradeByte(EEPROM_READ);
	EEPROM_send24BitAddress(address);
	SPI_tradeByte(0);
	eepromWord = SPDR;
	eepromWord = (eepromWord << 8);                      /* most-significant bit */
	SPI_tradeByte(0);
	eepromWord += SPDR;                                 /* least-significant bit */
	SLAVE_DESELECT;
	return (eepromWord);
}

void EEPROM_writeByte(uint32_t address, uint8_t byte) {
	SLAVE_SELECT;
	SPI_tradeByte(EEPROM_WRITE);
	EEPROM_send24BitAddress(address);
	SPI_tradeByte(byte);
	SLAVE_DESELECT;
}


void EEPROM_writeWord(uint32_t address, uint16_t word) {
	SLAVE_SELECT;
	SPI_tradeByte(EEPROM_WRITE);
	EEPROM_send24BitAddress(address);
	SPI_tradeByte((uint8_t) (word >> 8));
	SPI_tradeByte((uint8_t) word);
	SLAVE_DESELECT;
}

void EEPROM_clearAll(void) {
	uint8_t i;
	uint32_t pageAddress = 0;
	while (pageAddress < EEPROM_BYTES_MAX) {
		SLAVE_SELECT;
		SPI_tradeByte(EEPROM_WRITE);
		EEPROM_send24BitAddress(pageAddress);
		for (i = 0; i < EEPROM_BYTES_PER_PAGE; i++) {
			SPI_tradeByte(0);
		}
		SLAVE_DESELECT;
		pageAddress += EEPROM_BYTES_PER_PAGE;
	}
}


