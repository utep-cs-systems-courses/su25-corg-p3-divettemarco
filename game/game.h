#ifndef game_H
#define game_H

typedef enum{
  STATE_OFF,
  STATE_TV,
  STATE_GO,
  STATE_SOS
} State;

extern volatile State currState;

#endif // included
