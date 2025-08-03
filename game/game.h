#ifndef game_H
#define game_H

typedef enum{
  STATE_OFF,
  STATE_TOGGLE,
  STATE_DIM_TO_BRIGHT,
  STATE_WILD,
  STATE_BUZZ
} State;

extern volatile State currState;

#endif // included
