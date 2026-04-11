#ifndef GAME_H
#define GAME_H
#include "time.h"

typedef struct GameState {
    GameTime time;

    // Resources

    int gold;
    int population;
    int food;
    int water;
    int farms;
    int wells;


    // Control

    int lastDay;
    int lastWeek;
    int lastMonth;


} GameState;


#endif
