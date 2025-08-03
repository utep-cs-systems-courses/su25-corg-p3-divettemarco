#include <msp430.h>
#include "switches.h"
#include "game.h"
#include "stateMachines.h"

/* interrupt for port 2 (switches) */

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  // state 1: toggle leds every sec
  if (P2IFG & SW1){
    currState = STATE_TV;
    turn_off_update();
  }
  // state 2: change leds from dim to bright
  else if (P2IFG & SW2){
    currState = STATE_TV_BW;
    turn_off_update();
  }
  // state 3: toggle leds at different speeds and change buzzer every second
  else if (P2IFG & SW3){
    if (currState == STATE_GO) {
      currState = STATE_STOP;
    }
    currState = STATE_GO;
    turn_off_update();
  }
  // state 4: change buzzer every second
  else if (P2IFG & SW4){
    currState = STATE_SOS;
    turn_off_update();
  }
  
  P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */

}
