#include <msp430.h>
#include "switches.h"
#include "games.h"
#include "stateMachines.h"


/* interrupt for port 2 (switches) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  // state 1: toggle between tv color test and tv b&w test
  if (P2IFG & SW1){
    if (currState == STATE_TV){
      currState == STATE_TV_BW;
    }else{
      currState = STATE_TV;
    }
    turn_off_update();
  }
  // state 2: car in motion when led is green
  else if (P2IFG & SW2){
    if (currState == STATE_CAR){
      currState = STATE_PARK;
    }else{
      currState = STATE_CAR;
    }
    turn_off_update();
  }
  // state 3: boom animation every x seconds, play beeping before boom
  else if (P2IFG & SW3){
    currState = STATE_BOOM;
    turn_off_update();
  }
  // state 4: SOS, lights blaring, siren
  else if (P2IFG & SW4){
    currState = STATE_SOS;
    turn_off_update();
  }
  P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */
}
