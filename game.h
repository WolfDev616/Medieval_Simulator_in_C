#ifndef GAME_H
#define GAME_H
#include "time.h"

typedef struct {
    int amount;
    int workers;
} Workplace;        

typedef struct GameState {
    GameTime time;
	float timeAccumulator;

    char warningMessage[100];
    float warningTimer;

    // Resources

    int gold;
    int population;
    int workers;
    int idlePopulation;
    float food;
    float water;
    float wine;
    float beer;
    Workplace Farm;
    Workplace Well;
    Workplace Winery;
    Workplace Brewery;

    
    // Control

    int lastDay;
    int lastWeek;
    int lastMonth;


} GameState;

void updateIdlePopulation(GameState *game);


#endif
