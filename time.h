// Declare time system

#ifndef TIME_H
#define TIME_H

typedef struct GameTime {int years; int months; int weeks; int days; int hours; int minutes;} GameTime;


struct GameState;

void timeCounter(struct GameState *game);


#endif
