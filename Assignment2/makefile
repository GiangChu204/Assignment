# Makefile
include sources.mk

# Tên file thực thi đầu ra
TARGET = stats

# Nền tảng mặc định (Nếu không truyền tham số sẽ là HOST)
PLATFORM ?= HOST

# Các cờ (flags) biên dịch chung
GENERAL_FLAGS = -Wall -Werror -g -O0 -std=c99

# --- Cấu hình Toolchain và Flags theo Nền tảng ---
ifeq ($(PLATFORM), MSP432)
    # Compiler cho ARM MSP432
    CC = arm-none-eabi-gcc
    LD = arm-none-eabi-ld
    SIZE = arm-none-eabi-size
    OBJDUMP = arm-none-eabi-objdump
    
    # Linker Script (đường dẫn file cấu hình bộ nhớ chip)
    LINKER_FILE = ../msp432p401r.lds
    
    # Flags đặc chủng cho chip ARM Cortex-M4
    CPU = cortex-m4
    ARCH = armv7e-m
    SPECS = nosys.specs
    FPU = fpv4-sp-d16
    ABI = hard
    
    CPPFLAGS = -DMSP432 $(INCLUDES)
    CFLAGS = $(GENERAL_FLAGS) $(CPPFLAGS) \
             -mcpu=$(CPU) -mthumb -march=$(ARCH) \
             -mfloat-abi=$(ABI) -mfpu=$(FPU) --specs=$(SPECS)
    LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
else
    # Compiler cho HOST (Ubuntu/Linux)
    CC = gcc
    SIZE = size
    OBJDUMP = objdump
    
    CPPFLAGS = -DHOST $(INCLUDES)
    CFLAGS = $(GENERAL_FLAGS) $(CPPFLAGS)
    LDFLAGS = -Wl,-Map=$(TARGET).map
endif

# Tạo danh sách file Object (.o) từ danh sách file nguồn (.c)
OBJS = $(SOURCES:.c=.o)

# --- CÁC TARGET CHÍNH ---

# 1. Target Build (Tạo file thực thi, file map, mã asm và in size)
.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@
	$(OBJDUMP) -D $@ > $(TARGET).asm

# 2. Target tạo file Preprocessed (.i) cho từng file .c
%.i : %.c
	$(CC) -E $(CPPFLAGS) $< -o $@

# 3. Target tạo file Assembly (.asm) cho từng file .c
%.asm : %.c
	$(CC) -S $(CFLAGS) $< -o $@

# 4. Target tạo file Object (.o) và file Dependency (.d)
%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@
	$(CC) -E -M $(CPPFLAGS) $< -o $(@:.o=.d)

# 5. Target Compile All (Chỉ tạo file .o, không link)
.PHONY: compile-all
compile-all: $(OBJS)

# 6. Target Clean (Dọn dẹp mọi file sinh ra)
.PHONY: clean
clean:
	rm -f *.o *.i *.asm *.d *.map *.out
