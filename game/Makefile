
# makefile configuration
COMMON_OBJECTS  =  #wdinterrupthandler.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

# switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: game.elf

# additional rules for files
game.elf: ${COMMON_OBJECTS} game.o p2InterruptHandler.o wdInterruptHandler.o buzzer.o led.o switches.o stateMachines.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: game.elf
	msp430loader.sh game.elf
#msp430loader.sh $toyMain.elf

clean:
	rm -f *.o *.elf *~
