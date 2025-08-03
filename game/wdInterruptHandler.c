#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "game.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static int secCount = 0;
  static int halfSecCount = 0;
  
  /* check case and switch if necessary */
  switch (currState)
  {
  /* start with buzzer and leds off*/
  case STATE_OFF:
    turn_off_update();
    break;

  case STATE_TV:
    turn_off_update();
    break;

  /* toggle red and green on and off every sec; if green is on, red is off and vice versa  */
  case STATE_TV_BW:
    if (secCount >= 250){
      led_toggle_update();
    }
    break;

  /* make leds go from bright to dim */
  case STATE_GO:
    /* update leds and their counts */
    dim_to_bright_update();

    /* update led limit every second*/
    if (secCount >= 250) {
      dim_to_bright_limit_update();
    }
    break;

  /* update buzzer each second, leds on and off at different speeds */
  case STATE_STOP:
    /* update buzzer and green led every second */
    if (secCount >= 250) {
      wild_update();
    }
    break;

  /* sos written on lcd, siren on, lights flashing */
  case STATE_SOS:
    /*
    if (secCount >= 250) {
      
	}
    */
    if (halfSecCount >= 125) {
      led_toggle_update();
      buzz_toggle_update();
    }
    break;
  }
  /* update counts for secs */
  if (secCount >= 250) {
    secCount = 0;
  }
  if (halfSecCount >= 125) {
    halfSecCount = 0;
  }
  secCount++;
  halfSecCount++;
}
