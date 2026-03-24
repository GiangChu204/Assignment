include sources.mk

# Thiết lập mặc định nếu người dùng không nhập PLATFORM
PLATFORM = HOST

# Tên file đầu ra
TARGET = c1m2

# Các cờ biên dịch chung
GENERAL_FLAGS = -Wall -Werror -g -O0 -std=c99

ifeq ($(PLATFORM), MSP432)
	# Cấu hình cho MSP432
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map -T msp432p401r.lds
	CPPFLAGS = -DMSP432 $(INCLUDES)
	CFLAGS = $(GENERAL_FLAGS) -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs
else
	# Cấu hình cho HOST (Máy Linux)
	CC = gcc
	CPPFLAGS = -DHOST $(INCLUDES)
	CFLAGS = $(GENERAL_FLAGS)
	LDFLAGS = -Wl,-Map=$(TARGET).map
endif

OBJS = $(SOURCES:.c=.o)

.PHONY: build clean

# Mục tiêu build chính
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	size $@

# Quy tắc tạo file .o
%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

# Lệnh dọn dẹp (giống ảnh 3)
clean:
	rm -f *.o *.out *.map *.asm *.i *.d
