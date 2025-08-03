COMMON_OBJECTS  = main.o led.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS         = -L/opt/ti/msp430_gcc/include -L../lib
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

all: main.elf

main.elf: ${COMMON_OBJECTS} ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf *~
#	rm -f libLcd.a *o
