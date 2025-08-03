//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "game.h"
#include "libTimer.h"
#include "stateMachines.h"

volatile State currState = STATE_OFF;

int main(void) {
  configureClocks();/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();/* enable periodic interrupt */
  initialize();

  or_sr(0x18);/* CPU off, GIE on */
}
