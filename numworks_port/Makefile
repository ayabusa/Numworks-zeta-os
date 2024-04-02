TARGET = main

# Directories
SRC_DIR = src
BUILD_DIR = build

# Define the linker script location and chip architecture.
LD_SCRIPT = $(SRC_DIR)/linker.ld
MCU_SPEC  = cortex-m7

# Toolchain definitions (ARM bare metal defaults)
ifndef RUN_IN_GITHUB_ACTION
TOOLCHAIN = /usr/bin# if make is run normally
else
TOOLCHAIN = $(ARM_NONE_EABI_GCC_PATH) # if run inside of a github action
endif

CP = $(TOOLCHAIN)/arm-none-eabi-g++
CC = $(TOOLCHAIN)/arm-none-eabi-gcc
AS = $(TOOLCHAIN)/arm-none-eabi-as
LD = $(TOOLCHAIN)/arm-none-eabi-ld
OC = $(TOOLCHAIN)/arm-none-eabi-objcopy
OD = $(TOOLCHAIN)/arm-none-eabi-objdump
OS = $(TOOLCHAIN)/arm-none-eabi-size

# Assembly directives.
ASFLAGS += -c
ASFLAGS += -O0
ASFLAGS += -mcpu=$(MCU_SPEC)
ASFLAGS += -march=armv7e-m
ASFLAGS += -mfpu=fpv5-sp-d16
ASFLAGS += -mfloat-abi=softfp
ASFLAGS += -mthumb
ASFLAGS += -Wall
# (Set error messages to appear on a single line.)
ASFLAGS += -fmessage-length=0

# C compilation directives
CFLAGS += -mcpu=$(MCU_SPEC)
CFLAGS += -march=armv7e-m
CFLAGS += -mfpu=fpv5-sp-d16
CFLAGS += -mfloat-abi=softfp
CFLAGS += -mthumb
CFLAGS += -Wall
CFLAGS += -g
# (Set error messages to appear on a single line.)
CFLAGS += -fmessage-length=0
# (Set system to ignore semihosted junk)
CFLAGS += --specs=nosys.specs

# Linker directives.
LSCRIPT = $(LD_SCRIPT)
LFLAGS += -mcpu=$(MCU_SPEC)
LFLAGS += -mthumb
LFLAGS += -Wall
LFLAGS += --specs=nosys.specs
LFLAGS += -nostdlib
LFLAGS += -T$(LSCRIPT)

# AS_SRC   = $(SRC_DIR)/core.S
#C_SRC    = $(SRC_DIR)/main.c
CPP_SRC := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/Laplace/*.cpp)
C_SRC := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/Laplace/*.c)

INCLUDE  =  -I./
INCLUDE  += -I./device

#OBJS = $(BUILD_DIR)/$(notdir $(AS_SRC:.S=.o))
#OBJS += $(BUILD_DIR)/$(notdir $(C_SRC:.c=.o))
OBJS += $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_SRC))
OBJS += $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CPP_SRC))

.PHONY: all
all: $(BUILD_DIR)/$(TARGET).bin

#$(BUILD_DIR)/%.o: $(SRC_DIR)/%.S
#	$(CC) -x assembler-with-cpp $(ASFLAGS) $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CP) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OC) -S -O binary $< $@
	$(OS) $<

.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/Laplace/*.o
	rm -f $(BUILD_DIR)/$(TARGET).elf
	rm -f $(BUILD_DIR)/$(TARGET).bin

.PHONY: flash
flash:
	dfu-util -a 0 -i 0 -s 0x90400000 -D build/main.bin