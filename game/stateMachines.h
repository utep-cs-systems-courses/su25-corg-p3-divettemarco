#ifndef stateMachine_included
#define stateMachine_included

void initialize();

/* variables to assist in the methods */
void reset_vars();
int sleeping, buzzing, ledBlink, tvColor, tvWidth, tvHeight, greenLight;
int *colorPattern;
int *blackNWhitePattern;

/* methods for states to use */
void system_zzz();
void system_tv_color();
void set_tv(int *colorScheme);
void go_update();
void go_toggle();
void buzz_toggle_update();
void sos_toggle_update();
void led_toggle_update();

#endif // included
