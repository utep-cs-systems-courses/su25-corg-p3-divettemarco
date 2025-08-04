#include <msp430.h>
#include <stddef.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"

void initialize(){
  led_init();
  switch_init();
  buzzer_init();
  lcd_init();
}

/* assembly */
extern void reset_vars();

int sleeping = 0, buzzing = 0, ledBlink = 0, tvColor = 0, greenLight = 1, goCar = 0;
int setZero = 0, setOne = 1; 

int tvColorP[8] = {COLOR_WHITE, COLOR_YELLOW, COLOR_SKY_BLUE, COLOR_GREEN, COLOR_HOT_PINK, COLOR_RED, COLOR_BLUE, COLOR_BLACK};
int bNWColorP[8] = {COLOR_GRAY, COLOR_BLACK, COLOR_WHITE, COLOR_GRAY, COLOR_BLACK, COLOR_WHITE, COLOR_GRAY, COLOR_BLACK};

int *colorPattern = &tvColorP[0];
int *blackNWhitePattern = &bNWColorP[0];

int tvWidth = 150;
int tvHeight = 25;

/*
void reset_vars(){
  sleeping = 0;
  buzzing = 0;
  ledBlink = 0;
  tvColor = 0;
}
*/

/* sleep system if not already down */
void system_zzz(){
  if (!sleeping){
    green_off();
    red_off();
    buzzer_off();
    clearScreen(COLOR_NAVY);
    drawString5x7(5, 30, "2: tv colors and b&w", COLOR_SKY_BLUE, COLOR_NAVY);
    drawString5x7(5, 50, "3: car go and stop", COLOR_SKY_BLUE, COLOR_NAVY);
    drawString5x7(5, 70, "4: SOS SOS SOS", COLOR_SKY_BLUE, COLOR_NAVY);
    sleeping = 1;
  }
}

/* toggle between tv color pattern or black and white pattern */
void system_tv_color(){
  if (!tvColor){
    green_off();
    red_off();
    buzzer_off();
    set_tv(colorPattern);
    tvColor = 1;
  }else{
    red_on();
    green_off();
    buzzer_off();
    set_tv(blackNWhitePattern);
    //set_tv(colorPattern);
    tvColor = 0;
  }
  set_tv(colorPattern);
}

void set_tv(int *colorScheme){
  int *currColor = colorScheme;
  int colStart = 0;
  int rowStart = 0;
  clearScreen(*currColor);
  while(rowStart < 160){
    fillRectangle(colStart, rowStart, tvWidth, tvHeight, *currColor);
    rowStart += 20;
    currColor++;
  }
}

void go_update(){
  buzzer_off();
  static int currCol = 0;
  static int rowStart = 90;
  if(greenLight){
    green_on();
    red_off();
    clearScreen(COLOR_HOT_PINK);
    drawVeh(currCol, rowStart, COLOR_BLUE, COLOR_BLACK);
    if(currCol >= 120){
      currCol = 0;
    }else{
      currCol += 10;
    }
  }else{
    red_on();
    green_off();
    clearScreen(COLOR_HOT_PINK);
    drawVeh(currCol, rowStart, COLOR_BLUE, COLOR_BLACK);
  }
}

void go_toggle(){
  goCar++;
  if(goCar == 2){
    greenLight = 0;
    goCar = 0;
  }else{
    greenLight = 1;
  }
}


/* toggle buzzer */
void buzz_toggle_update(){
  if (!buzzing) {
    buzzer_set_period(1500);
    buzzing = 1;
  }else{
    buzzer_set_period(2500);
    buzzing = 0;
  }
}

/* toggle "sos" display on lcd */
void sos_toggle_update(){
  int col = 0;
  int row = 0;
  int print_sos = 1;
  clearScreen(COLOR_RED);
  while (print_sos){
    drawString5x7(col, row, "SOS", COLOR_DARK_GREEN, COLOR_RED);
    col += 5;
    row += 10;
    if (col >= 120){
      print_sos = 0;
      col = 120;
      row = 0;
    }
  }
  print_sos = 1;
  while (print_sos) {
    drawString5x7(col, row, "SOS", COLOR_DARK_GREEN, COLOR_RED);
    col -= 5;
    row += 10;
    if (col <= 0){
      print_sos = 0;
    }
  }
}

/* toggle red and green leds */
void led_toggle_update(){
  if (!ledBlink){
    red_on();
    green_off();
    ledBlink = 1;
  }else{
    red_off();
    green_on();
    ledBlink = 0;
  }
}

