#ifndef stateMachine_included
#define stateMachine_included

void initialize();

/* variables to assist in the methods */
void resetVars();
int sleeping, buzzing, ledBlink;

/* methods for states to use */
void system_zzz();
void buzz_toggle_update();
void sos_toggle_update();
void led_toggle_update();

#endif // included
