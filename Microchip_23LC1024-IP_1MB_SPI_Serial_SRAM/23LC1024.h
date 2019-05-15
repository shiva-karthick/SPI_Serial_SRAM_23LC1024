
/*
*	Includes
*/
#include <avr/io.h>
#include "pinDefines.h"
#include <avr/delay.h>

/* These registers defined here are for maximum code portability */





/* Which pin selects EEPROM as slave? */
#define SLAVE_SELECT    SPI_SS_PORT &= ~(1 << SPI_SS) /* PORTB &= ~(1 << PB2) */
#define SLAVE_DESELECT  SPI_SS_PORT |= (1 << SPI_SS)  /* PORTB |= (1 << PB2) */

// Instruction Set -- from data sheet
#define EEPROM_READ      0b00000011                     /* read memory */
#define EEPROM_WRITE     0b00000010                 /* write to memory */

#define EEPROM_READ_MODE_REGISTER 0b10100000		/* Read Mode Register */
#define EEPROM_WRITE_MODE_REGISTER 0b00000001		/* Write Mode Register */

/* EEPROM Mode Register Bits -- from data sheet
* Use these to indicate the operating more of the SRAM. The possible modes of operation are :
*	00 - Byte Mode
*	10 - Page Mode
*	01 - Sequential Mode (default operation)
*	11 - reserved
* Note : Bits 0 through 5 are reserved and should always be set to 0.
*/

#define EEPROM_BYTE_MODE		0b00000000
#define EEPROM_PAGE_MODE		0b00000001
#define EEPROM_SEQUENTIAL_MODE	0b00000010

#define EEPROM_BYTES_PER_PAGE	32
#define EEPROM_BYTES_MAX		0x1F3FF


// Functions

					/* Initialize SPI to run EEPROM with phase, polarity = 0,0 */
void initSPI(void);

								/* Generic.  Just loads up HW SPI register and waits */
void SPI_tradeByte(uint8_t byte);

											/* splits 24-bit address into 3 bytes, sends all 3 bytes */
void EEPROM_send24BitAddress(uint32_t address);

											/* sends 1 byte */
void EEPROM_send8BitAddress(uint8_t address);

								/* reads the EEPROM status register */
uint8_t EEPROM_readStatus(void);
											/* gets a byte from a given memory location */
uint8_t EEPROM_readByte(uint32_t address);
											/* gets 2 bytes from a given memory location */
uint16_t EEPROM_readWord(uint32_t address);
													/* writes 1 byte from a given memory location */		
void EEPROM_writeByte(uint32_t address, uint8_t byte);
														
													/* writes 2 bytes from a given memory location */
void EEPROM_writeWord(uint32_t address, uint16_t word);

							/* sets every byte in memory to zero */
void EEPROM_clearAll(void);