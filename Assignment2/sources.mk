# sources.mk

# 1. Liệt kê các file .c bạn đang có
SOURCES = main.c \
          stats.c

# 2. Đường dẫn đến thư mục chứa file stats.h (giả sử nằm trong thư mục include cùng cấp)
INCLUDES = -I../include

# 3. msp
ifeq ($(PLATFORM), MSP432)

    INCLUDES += -I../include/CMSIS \
                -I../include/msp432
endif
