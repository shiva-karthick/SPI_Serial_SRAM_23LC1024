# SPI Serial SRAM 23LC1024

23LC1024 are 1 Mbit Serial SRAM devices. The memory is accessed via a simple SPI compatible serial bus.
This tutorial code is written for AtMega328p. The SPI hardware is used. However, the code is portable to other microcontrollers. 

TODO : Insert a picture here

---

## How Addresses are accessed in the SPI Serial SRAM 23LC1024
```
0b 1111111 0 0000 0000 0000 0000 1111 1111 <-> 4261413119 (decimal) 0th Address
   <-----> <-------------------> <------->
    7 don't  17 Actual Address    8 don't care bits
    care	 bits
    bits

0b 1111111 0 0000 0000 0000 0001 1111 1111 <-> 4261413375 (decimal) 1st Address
   <-----> <-------------------> <------->
    7 don't   17 Actual Address   8 don't care bits
    care	  bits
    bits

0b 1111111 0 0000 0000 0000 0010 1111 1111 <-> 4261413631 (decimal) 2nd Address
   <-----> <-------------------> <------->
    7 don't   17 Actual Address   8 don't care bits
    care       bits
    bits
	   
0b 1111111 0 0000 0000 0000 0011 1111 1111 <-> 4261413887 (decimal) 3rd Address
   <-----> <-------------------> <------->
    7 don't  17 Actual Address    8 don't care bits
     care     bits
     bits
	   
0b 1111111 0 0000 0000 0000 0100 1111 1111 <-> 4261414143 (decimal) 4th Address
   <-----> <-------------------> <------->
    7 don't  17 Actual Address    8 don't care bits
    care      bits
    bits
```
---

## Technical information from the 23LC1024 datasheet

+ There is 0 write time
+ 128K x 8-bit organisation
	+ 32 byte page
+ 4096 pages of 32 bytes