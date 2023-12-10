
TARGET = inputTester

CC = $(CROSS_COMPILE)gcc
CFLAGS   = -I/opt/rg35xx/arm-buildroot-linux-gnueabihf/sysroot/usr/include/SDL/ -D_GNU_SOURCE=1 -D_REENTRANT -Os -marm -mtune=cortex-a9 -mfpu=neon-fp16 -mfloat-abi=hard -march=armv7-a
LDFLAGS	 = -ldl -lSDL -lm -lSDL_image -lSDL_ttf -lpthread -lfreetype

all:
	@mkdir -p build
	$(CC) ./src/main.c -o ./build/$(TARGET) $(CFLAGS) $(LDFLAGS)
	@mkdir -p ./build/res
	@cp ./res/* ./build/res

linux:
	$(MAKE) CC=gcc CROSS_COMPILE="" CFLAGS="" --no-print-directory	
	
.PHONY: clean

clean:
	rm -fr ./build
