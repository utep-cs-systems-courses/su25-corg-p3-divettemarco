#include <msp430.h>
#include "games.h"          // currState
#include "switches.h"       // switch input
#include "stateMachines.h"  // turn_off_update()

/* interrupt for port 2 (switches) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  // state 1: tv color test
  if (P2IFG & SW1){
    currState = STATE_TV;
    turn_off_update();
  }
  // state 2: tv color test B&W
  else if (P2IFG & SW2){
    currState = STATE_TV_BW;
    turn_off_update();
  }
  // state 3: car in motion until button is pressed to park it when red led is on
  else if (P2IFG & SW3){
    if (currState == STATE_CAR){
      currState = STATE_PARK;
    }else{
      currState = STATE_CAR;
    }
    turn_off_update();
  }
  // state 4: SOS, lights blaring, siren
  else if (P2IFG & SW4){
    currState = STATE_SOS;
    turn_off_update();
  }
  P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */
}
