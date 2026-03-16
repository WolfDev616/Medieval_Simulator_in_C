// Declare time system

#ifndef TIME_H
#define TIME_H

typedef struct {int years; int months; int weeks; int days; int hours; int minutes; int seconds;} GameTime;


void timeCounter(GameTime* gameTime);


#endif
