################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../23LC1024.c \
../main.c \
../USART.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
23LC1024.o \
main.o \
USART.o

OBJS_AS_ARGS +=  \
23LC1024.o \
main.o \
USART.o

C_DEPS +=  \
23LC1024.d \
main.d \
USART.d

C_DEPS_AS_ARGS +=  \
23LC1024.d \
main.d \
USART.d

OUTPUT_FILE_PATH +=Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.elf

OUTPUT_FILE_PATH_AS_ARGS +=Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./23LC1024.o: .././23LC1024.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\Program Files (x86)\AtmelStudio\7.0\Packs\Atmel\ATmega_DFP\1.3.300\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "C:\Program Files (x86)\AtmelStudio\7.0\Packs\Atmel\ATmega_DFP\1.3.300\gcc\dev\atmega328p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\Program Files (x86)\AtmelStudio\7.0\Packs\Atmel\ATmega_DFP\1.3.300\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "C:\Program Files (x86)\AtmelStudio\7.0\Packs\Atmel\ATmega_DFP\1.3.300\gcc\dev\atmega328p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./USART.o: .././USART.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\Program Files (x86)\AtmelStudio\7.0\Packs\Atmel\ATmega_DFP\1.3.300\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "C:\Program Files (x86)\AtmelStudio\7.0\Packs\Atmel\ATmega_DFP\1.3.300\gcc\dev\atmega328p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)C:\Program Files (x86)\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.map" -Wl,--start-group -Wl,-lm -Wl,-lprintf_flt  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega328p -B "C:\Program Files (x86)\AtmelStudio\7.0\Packs\Atmel\ATmega_DFP\1.3.300\gcc\dev\atmega328p" -Wl,-u,vfprintf  
	@echo Finished building target: $@
	"C:\Program Files (x86)\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.elf" "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.hex"
	"C:\Program Files (x86)\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.elf" "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.eep" || exit 0
	"C:\Program Files (x86)\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.elf" > "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.lss"
	"C:\Program Files (x86)\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.elf" "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.srec"
	"C:\Program Files (x86)\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.elf" "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.a" "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.hex" "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.lss" "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.eep" "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.map" "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.srec" "Microchip_23LC1024-IP_1MB_SPI_Serial_SRAM.usersignatures"
	