#include <msp430.h>
#include "switches.h"
#include "game.h"
#include "stateMachines.h"
#include <unistd.h>

/* interrupt for port 2 (switches) */

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  // state 1 tv colors
  if (P2IFG & SW1){
    currState = STATE_OFF;
    reset_vars();
  }
  // state 2 tv B&W
  else if (P2IFG & SW2){
    currState = STATE_TV;
    reset_vars();
  }
  // state 3: toggle leds at different speeds and change buzzer every second
  else if (P2IFG & SW3){
    currState = STATE_GO;
    reset_vars();
  }
  // state 4: change buzzer every second
  else if (P2IFG & SW4){
    currState = STATE_SOS;
    //turn_off_update();
    reset_vars();
  }
  
  P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */
}
