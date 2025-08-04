#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "game.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static int secCount = 0;
  static int halfSecCount = 0;
  static int quarterSecCount = 0;
  
  /* check case and switch if necessary */
  switch (currState)
  {
  /* turn off leds, buzzer, and clear screen with zzz */
  case STATE_OFF:
    system_zzz();
    break;

  case STATE_TV:
    system_tv_color();
    break;

  /* toggle red and green on and off every sec; if green is on, red is off and vice versa  */
  case STATE_TV_BW:
    if (secCount >= 250){
      system_zzz();
    }
    break;

  /* make car move and stop */
  case STATE_GO:
    /* update location of car and print new display */
    /* if 5 sec mark, stop car, turn on red led */
    break;

  /* sos written on lcd, siren on, lights flashing */
  case STATE_SOS:
    if (halfSecCount >= 125) {
      led_toggle_update();
      buzz_toggle_update();
      //sos_toggle_update();
    }
    if (quarterSecCount >= 62){
      sos_toggle_update();
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
  if (quarterSecCount >= 62){
    quarterSecCount = 0;
  }
  secCount++;
  halfSecCount++;
  quarterSecCount++;
}
