#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "games.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static int secCount = 0;
  //static int twoSecCycle = 0;

  /* check case and switch if necessary */
  switch (currState)
    {
      /* start with everything off */
    case STATE_TV:
      //turn_off_update();
      break;

    /* toggle red and green on and off every sec; if green is on, red is off and vice versa  */
    case STATE_CAR:
      //if (secCount >= 250){
      //led_toggle_update();
      //}
      break;

      /* make leds go from bright to dim */
    case STATE_COLORS:
      break;

      /* update buzzer each second, leds on and off at different speeds */
    case STATE_SOS:
      break;
  
  /* update counts for secs */
      if (secCount >= 250) {
	secCount = 0;
      }
      secCount++;
    }
}
