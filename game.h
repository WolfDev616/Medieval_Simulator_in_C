#ifndef GAME_H
#define GAME_H
#include "time.h"

typedef struct GameState {
    GameTime time;

    // Resources

    int gold;
    int population;
    float food;
    float water;
    float wine;
    float beer;
    int farms;
    int wells;
    int wineries;
    int breweries;

    // Mechanics
    int buildMode;

    // Control

    int lastDay;
    int lastWeek;
    int lastMonth;


} GameState;


#endif
