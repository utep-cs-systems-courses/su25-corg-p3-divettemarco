#include <msp430.h>
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

int sleeping = 0;
int buzzing = 0;
int ledBlink = 0;
int tvColor = 0;
int tvCol = 150;
int tvRow = 20;

void reset_vars(){
  sleeping = 0;
  buzzing = 0;
  ledBlink = 0;
  tvColor = 0;
}

/* sleep system if not already down */
void system_zzz(){
  if (!sleeping){
    green_off();
    red_off();
    buzzer_off();
    clearScreen(COLOR_NAVY);
    drawString5x7(20, 30, "ZZZ", COLOR_GREEN, COLOR_RED);
    sleeping = 1;
  }
}

/* display tv color pattern if not already displayed */
void system_tv_color(){
  if (!tvColor){
    green_off();
    red_off();
    buzzer_off();
    int colStart = 0;
    int rowStart = 0;
    fillRectangle(colStart, rowStart, tvCol, tvRow, COLOR_WHITE);
    rowStart += 20;
    fillRectangle(colStart, rowStart, tvCol, tvRow, COLOR_YELLOW);
    rowStart += 20;
    fillRectangle(colStart, rowStart, tvCol, tvRow, COLOR_SKY_BLUE);
    rowStart += 20;
    fillRectangle(colStart, rowStart, tvCol, tvRow, COLOR_GREEN);
    rowStart += 20;
    fillRectangle(colStart, rowStart, tvCol, tvRow, COLOR_HOT_PINK);
    rowStart += 20;
    fillRectangle(colStart, rowStart, tvCol, tvRow, COLOR_RED);
    rowStart += 20;
    fillRectangle(colStart, rowStart, tvCol, tvRow, COLOR_BLUE);
    rowStart += 20;
    fillRectangle(colStart, rowStart, tvCol, tvRow+5, COLOR_BLACK);
    tvColor = 1;
  }
}

/* toggle buzzer */
void buzz_toggle_update(){
  if (!buzzing) {
    buzzer_set_period(1500);
    buzzing = 1;
  }else{
    buzzer_off();
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

