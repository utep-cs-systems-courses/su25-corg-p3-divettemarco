/** \file games.c
 *  \brief initializes everything and sets the machine to the default state
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

#include "games.h"
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  /* intitialize everything */
  lcd_init();
  led_init();
  switch_init();
  buzzer_init();
  configureClocks(); /* setup master oscillator, CPU, & peripheral clocks */
  enableWDTInterrupts(); /* enable periodic interrupt */
  
  //u_char width = screenWidth, height = screenHeight;
  //clearScreen(COLOR_BLUE);
  //drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);
  //fillRectangle(30,30, 60, 60, COLOR_ORANGE);

  or_sr(0x18); /* CPU off, GIE on */
}
