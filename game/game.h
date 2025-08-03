#ifndef game_H
#define game_H

typedef enum{
  STATE_OFF,
  STATE_TV,
  STATE_TV_BW,
  STATE_GO,
  STATE_STOP,
  STATE_SOS
} State;

extern volatile State currState;

#endif // included
