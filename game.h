#ifndef GAME_H
#define GAME_H
#include "time.h"

typedef struct GameState {
    GameTime time;
	float timeAccumulator;

    char warningMessage[100];
    float warningTimer;

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

    // Control

    int lastDay;
    int lastWeek;
    int lastMonth;


} GameState;


#endif
