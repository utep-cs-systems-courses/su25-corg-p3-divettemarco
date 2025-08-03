#ifndef games_H
#define games_H

typedef enum{
  STATE_TV,
  STATE_CAR,
  STATE_COLORS,
  STATE_SOS
} State;

extern volatile State currState;

#endif // included
