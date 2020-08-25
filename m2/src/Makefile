#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = MSP432

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
M_ARCH = armv7e-m
SPECS = nosys.specs
FPU = fpv4-sp-d16
FLOAT_ABI = hard

# General Flags 
GFLAGS = -std=$(STD) -Wall -Werror -g -O0
OBJDFLAGS = -S
CPPFLAGs = -E 
CCSIZEFLAGS = -Atd
STD = c99
TARGET = c1m2

# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)
	CC = gcc
	CCSIZE = size
	LD = ld
	OBJDUMP = objdump
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = $(GFLAGS)
	PLATFORM = HOST
	SOURCES = $(HOST_SOURCES)
	INCLUDES = $(HOST_INCLUDES)
else
	CC = arm-none-eabi-gcc
	CCSIZE = arm-none-eabi-size
	LD = arm-none-eabi-ld
	OBJDUMP = arm-none-eabi-objdump
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = $(GFLAGS) -mcpu=$(CPU) -m$(ARCH) -march=$(M_ARCH) --specs=$(SPECS) -mfpu=$(FPU) -mfloat-abi=$(FLOAT_ABI)
	PLATFORM = MSP432
	SOURCES = $(MSP432_SOURCES)
	INCLUDES = $(MSP432_INCLUDES)
endif

# Here every source file will traslate to  object files, preprocessed output files and assembly output
OBJECTS = $(SOURCES:.c=.o)
PREPRSD = $(SOURCES:.c=.i)
ASSMS = $(SOURCES:.c=.asm)

# specifying the object file you want to compile

%.o : %.c
	$(CC) -c $^ $(CFLAGS) -D$(PLATFORM) $(INCLUDES)  -o $@

# Generate the preprocessed output of all c-program implementation files

%.i : %.c
	$(CC) -E -D$(PLATFORM) $< $(CFLAGS) $(INCLUDES) -o $@
# Generate assembly output of c-program implementation files and the final output executable

%.asm : %.c
	$(CC) -S -D$(PLATFORM) $< $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ #output executable
	$(OBJDUMP) -S -D$(PLATFORM) $< $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ #assmebly output


.PHONY: compile-all
compile-all: $(OBJECTS)

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJECTS)
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -D$(PLATFORM) $(INCLUDES) -o $@ 

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(TARGET).out $(TARGET).map $(PREPRSD) $(ASSMS)


