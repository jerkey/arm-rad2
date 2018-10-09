CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy
ARCHFLAGS=-mcpu=arm7tdmi
CFLAGS=$(ARCHFLAGS) -nostdlib -nostartfiles -ffreestanding
LDFLAGS=-Taduc7060.ld -L/usr/lib/gcc/arm-none-eabi/5.4.1 -L/usr/lib/arm-none-eabi/lib
LIBS=-lgcc
OBJS=startup.o arm-rad2.o irq_arm.o aduc7060.o

all: firmware.hex

startup.o: startup.S
	$(CC) $(CFLAGS) -c startup.S

arm-rad2.o: arm-rad2.c

firmware.elf: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o firmware.elf $(LIBS)

firmware.hex: firmware.elf
	$(OBJCOPY) -I elf32-littlearm -O ihex firmware.elf firmware.hex

clean:
	rm -f $(OBJS) firmware.elf
