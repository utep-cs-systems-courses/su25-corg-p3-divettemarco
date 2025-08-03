#include <msp430.h>
#include "switches.h"
#include "games.h"
#include "stateMachines.h"


/* interrupt for port 2 (switches) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  // state 1: tv color test
  if (P2IFG & SW1){
    currState = STATE_TV;
    turn_off_update();
  }
  // state 2: car in motion
  else if (P2IFG & SW2){
    currState = STATE_CAR;
    turn_off_update();
  }
  // state 3: different colors
  else if (P2IFG & SW3){
    currState = STATE_COLORS;
    turn_off_update();
  }
  // state 4: SOS SOS SOS
  else if (P2IFG & SW4){
    currState = STATE_SOS;
    turn_off_update();
  }
  P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */
}
