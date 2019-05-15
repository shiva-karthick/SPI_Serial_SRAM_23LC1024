/*
* Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.c

* Created: 5/7/2019 5:44:17 PM
* Author : Shankar

* ---------------Instructions---------------
* Connect the SPI SRAM according to pinDefines.h file

* ---------------Explanation---------------
* The Address which are required to access the SRAM is a bit crazy. However, they are explained here !

* 0b   0000000		 0 0000 0000 0000 0000				0000 0000
* (don't care bits)  (the actual address in the SRAM)	(these bits are used to fill up the uint32_t variable)
* Therefore the above binary number is 0.

* 0b   0000000		 0 0000 0000 0000 0001				0000 0000
* (don't care bits)  (the actual address in the SRAM)	(these bits are used to fill up the uint32_t variable)
* Therefore the above binary number is 256.

* 0b   0000000		 0 0000 0000 0000 0010				0000 0000
* (don't care bits)  (the actual address in the SRAM)	(these bits are used to fill up the uint32_t variable)
* Therefore the above binary number is 512.

* 0b   0000000		 0 0000 0000 0000 0011				0000 0000
* (don't care bits)  (the actual address in the SRAM)	(these bits are used to fill up the uint32_t variable)
* Therefore the above binary number is 768.

* This continues until 0x1F3FF.

* The Address of the SRAM is in multiples of 256. For example,
* First Address - 0 (decimal)
* Second Address - 256 (decimal)
* Third Address - 512 (same as above...)
* Fourth Address - 768
* ... so on and so forth
*/

#include <avr/io.h>
#include "USART.h"
#include "macros.h"
#include "23LC1024.h"
#include "pinDefines.h"
#include <stdio.h>


#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
(byte & 0x80 ? '1' : '0'), \
(byte & 0x40 ? '1' : '0'), \
(byte & 0x20 ? '1' : '0'), \
(byte & 0x10 ? '1' : '0'), \
(byte & 0x08 ? '1' : '0'), \
(byte & 0x04 ? '1' : '0'), \
(byte & 0x02 ? '1' : '0'), \
(byte & 0x01 ? '1' : '0')

// ********************************************************************************
// Global Variables
// ********************************************************************************
static FILE mystdout = FDEV_SETUP_STREAM(usart_putchar_printf, NULL, _FDEV_SETUP_WRITE);

int main(void) {
	uint8_t i;
	// uint32_t memory_slot;

	// -------- Initializations --------- //
	initSPI();

	initUSART();
	// setup our stdio stream
	stdout = &mystdout;

	// ------ Event loop ------ //
	while (1) {
		printString("\r\n====  EEPROM Memory Playground ====\r\n");
		printString("Address  Value\r\n");

		for (i = 0; i < 10; i++) {  /* print out first ten bytes of memory */
			printString("  ");
			printByte(i);
			printString("     ");
			printByte(EEPROM_readByte(i));
			printString("\r\n");
		}
		printString(" [e] to erase all memory\r\n");
		printString(" [r] to read memory\r\n");
		printString(" [w] to write byte to memory\r\n");
		printString(" [m] to check the mode\r\n\r\n");

		switch (receiveByte()) {                             /* take input */
			case 'e':
			printString("Clearing EEPROM, this could take a few seconds, please be patient.\r\n");
			EEPROM_clearAll();
			break;
			case 'w':
			// printString("Which memory slot would you like to write to?\r\n");
			// memory_slot = getNumber();

			// printString("\r\nWhat number would you like to store there?\r\n");
			// i = getNumber();

			//EEPROM_writeByte(memory_slot, i);
			
			/* Only for Debugging */
			printString("Writing ...");
			uint8_t random_number_to_be_stored = 0;

			for (uint32_t SRAM_memory_address = 4261413119; SRAM_memory_address <= 4294967295; SRAM_memory_address+=256)
			{
				EEPROM_writeByte(SRAM_memory_address, random_number_to_be_stored);
				random_number_to_be_stored+=5;
				if (random_number_to_be_stored == 250)
				{
					random_number_to_be_stored = 0;
				}
			}
			
			//EEPROM_writeByte(4261413119, 50);
			//EEPROM_writeByte(4261413375, 150);
			
			
			//EEPROM_writeByte(0x00000000/*0*/, 50);
			//EEPROM_writeByte(0x00000100/*256*/, 100);
			//EEPROM_writeByte(0x00000200/*512*/, 150);
			//EEPROM_writeByte(0x00000300/*768*/, 200);
			//EEPROM_writeByte(0x00000400/*1024*/, 250);
			//EEPROM_writeByte(0x0000A000/**/, 252);

			// EEPROM_writeByte(0b00000000000000000000000000000000/*0*/, 50);
			// EEPROM_writeByte(0b00000000000000000000000100000000/*256*/, 100);
			// EEPROM_writeByte(0b00000000000000000000001000000000/*512*/, 150);
			// EEPROM_writeByte(0b00000000000000000000001100000000/*768*/, 200);

			printString("\r\n");
			break;
			case 'r':
			 // printString("Which memory slot would you like to read to?\r\n");
			 //memory_slot = getNumber();

			 //printString("Reading ... \r\n");
			 //printf("The value is %u \r\n", EEPROM_readByte(memory_slot));

			/* Only for debugging */
			printString("Reading ... \r\n");

			for (uint32_t x = 4261413119; x <= 4294967295; x+=256)
			{
				printf("\r\n The value is %u \r\n", EEPROM_readByte(x));
			}

			//printf("The value is %u \r\n", EEPROM_readByte(4261413119));
			//printf("The value is %u \r\n", EEPROM_readByte(4261413375));
			
			
			//printf("The value is %u \r\n", EEPROM_readByte(0x00000000/*0*/));
			//printf("The value is %u \r\n", EEPROM_readByte(0x00000100/*256*/));
			//printf("The value is %u \r\n", EEPROM_readByte(0x00000200/*512*/));
			//printf("The value is %u \r\n", EEPROM_readByte(0x00000300/*768*/));
			//printf("The value is %u \r\n", EEPROM_readByte(0x00000400/*1024*/));
			//printf("The value is %u \r\n", EEPROM_readByte(0x0000A000/**/));

			// printf("The value is %u \r\n", EEPROM_readByte(0b00000000000000000000000000000000/*0*/));
			// printf("The value is %u \r\n", EEPROM_readByte(0b00000000000000000000000100000000/*256*/));
			// printf("The value is %u \r\n", EEPROM_readByte(0b00000000000000000000001000000000/*512*/));
			// printf("The value is %u \r\n", EEPROM_readByte(0b00000000000000000000001100000000/*768*/));
			
			printString("\r\n");
			break;
			case 'm':
			printString("Finding out the mode bits which indicate the Mode of the operation \r\n");
			// printf("The mode is %x \r\n", EEPROM_readStatus());
			printf("The mode is "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(EEPROM_readStatus()));
			printString("\r\n");
			break;
			default:
			printString("What?? \r\n");
		}
		}                                                  /* End event loop */
		return 0;                            /* This line is never reached */
	}


