all: libLcd.a game.elf

# makefile configuration
COMMON_OBJECTS  =  #wdinterrupthandler.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include -L../lib

# switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

libLcd.a: font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o
	$(AR) crs $@ $^

lcddraw.o: lcddraw.c lcddraw.h lcdutils.h
lcdutils.o: lcdutils.c lcdutils.h

install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

# additional rules for files
game.elf: ${COMMON_OBJECTS} game.o p2InterruptHandler.o wdInterruptHandler.o buzzer.o led.o switches.o stateMachines.o libLcd.a ../lib/libTimer.a
#	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer

load: game.elf
#	msp430loader.sh game.elf
	msp430loader.sh $^

clean:
	rm -f libLcd.a *.o *.elf *~
