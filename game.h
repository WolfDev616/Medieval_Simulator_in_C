#ifndef GAME_H
#define GAME_H
#include "time.h"

typedef struct GameState {
    GameTime time;

    // Resources

    int gold;
    int population;
    int food;
    int farms;


    // Control

    int lastDay;
    int lastMonth;


} GameState;


#endif
