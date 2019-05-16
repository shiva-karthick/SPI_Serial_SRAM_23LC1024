# SPI Serial SRAM 23LC1024

23LC1024 are 1 Mbit Serial SRAM devices. It is accessed via a simple SPI compatible serial bus.
This tutorial code is written for AtMega328p on Atmel Studio 7. However, the code is portable to other microcontrollers. 

It is tested on Atmel Studio 7 <img src="images/atmel studio 7.png" alt="atmel studio 7" width="25" height = "25"/> and Windows 10.

![23LC1024 SPI SRAM Circuit diagram](https://github.com/shankar-shiv/SPI_Serial_SRAM_23LC1024/blob/master/images/23LC1024%20SRAM%20SPI_schem.png)

---

## How Addresses are accessed in the SPI Serial SRAM 23LC1024
+ Add 256 for every subsequent address. For example, 4261413119 + 256 = 4261413375

```
0b 1111111 0 0000 0000 0000 0000 1111 1111 (binary) <-> 4261413119 (decimal) 0th Address
   <-----> <-------------------> <------->
    7 don't  17 Actual Address    8 don't care bits
    care	 bits
    bits

0b 1111111 0 0000 0000 0000 0001 1111 1111 (binary) <-> 4261413375 (decimal) 1st Address
   <-----> <-------------------> <------->
    7 don't   17 Actual Address   8 don't care bits
    care	  bits
    bits

0b 1111111 0 0000 0000 0000 0010 1111 1111 (binary) <-> 4261413631 (decimal) 2nd Address
   <-----> <-------------------> <------->
    7 don't   17 Actual Address   8 don't care bits
    care       bits
    bits
	   
0b 1111111 0 0000 0000 0000 0011 1111 1111 (binary) <-> 4261413887 (decimal) 3rd Address
   <-----> <-------------------> <------->
    7 don't  17 Actual Address    8 don't care bits
     care     bits
     bits
	   
0b 1111111 0 0000 0000 0000 0100 1111 1111 (binary) <-> 4261414143 (decimal) 4th Address
   <-----> <-------------------> <------->
    7 don't  17 Actual Address    8 don't care bits
    care      bits
    bits
	
0b 1111111 0 0000 0000 0000 0101 1111 1111 (binary) <-> 4261414399 (decimal) 5th Address
   <-----> <-------------------> <------->
    7 don't  17 Actual Address    8 don't care bits
    care      bits
    bits
	
	... until 0x1FFFF (actual address) or 0b1111111 1 1111 1111 1111 1111 1111 1111 / ‭4294967295‬(decimal) is reached.
```
---

## Atmel Studio Source Files

+ 23LC1024.c , 23LC1024.h
	+ It contains all the necessary initialisation and SPI functions.

+ pinDefines.h
	+ It contains easy to read names instead of register names.
	
+ setbaud.h , USART.c , USART.h 
	+ These files above contain the necessary functions to communicate to the PC via USART interface. 

+ macros.h
	+ This file provides some convenience functions.

---

## Modes of Operation

There are 3 modes of operation selected by setting bits 7 and 6 in the MODE register.
+ Byte
	+ is selected when bits 7 and 6 in the mode register are set to 00.
	
+ Page
	+ is selected when bits 7 and 6 in the mode register are set to 10.
	
+ Sequential aka Burst (This is the Default Mode and is discussed here)
	+ is selected when bits 7 and 6 in the mode register are set to 01.
	+ Below picture shows the order of bits (for example : Instruction bits first, 24-bit address second and a data byte lastly) that need to be sent for a sequential write operation
	![Sequential Write Sequence (SPI Mode)](https://github.com/shankar-shiv/SPI_Serial_SRAM_23LC1024/blob/master/images/sequential%20write%20operation.PNG)
	+ Below picture shows the order of bits (for example : Instruction bits first, 24-bit address second and a data bytes are read in lastly) for a sequential read operation
	![Sequential Read Sequence (SPI Mode)](https://github.com/shankar-shiv/SPI_Serial_SRAM_23LC1024/blob/master/images/sequential%20read%20operation.PNG)
---

## Technical information from the 23LC1024 datasheet

+ There is 0 write time
+ 128K x 8-bit organisation
	+ 32 byte page
+ 4096 pages of 32 bytes
+ All instructions and data are transferred MSB first, LSB last
+ Highest address is 0x1FFFF

---

## Easy to use APIs

All functions are well commented and easy to understand for maximum portability

```c
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

```