#ifndef GAME_H
#define GAME_H
#include "time.h"
#include <stdbool.h>


typedef struct {
    int amount;
    int workers;
} Workplace;       

typedef struct {
    float alpha;     // current visual alpha
    bool  revealed;  // true once it has fully faded in at least once (ever)
} Reveal;

typedef struct GameState {
    GameTime time;
	float timeAccumulator;
    int revealed;

    char warningMessage[100];
    float warningTimer;

    // Resources

    int gold;
    int population;
    int workers;
    int idlePopulation;
    float grains;
    float water;
    float flour;
    float bread;
    float wine;
    float beer;
    Workplace Farm;
    Workplace Well;
    Workplace Mill;
    Workplace Bakery;
    Workplace Winery;
    Workplace Brewery;


    Reveal farmReveal;
    Reveal wellReveal;
    Reveal millReveal;
    Reveal bakeryReveal;
    Reveal wineReveal;
    Reveal wineryReveal;
    Reveal beerReveal;
    Reveal breweryReveal;

    
    // Control

    int lastDay;
    int lastWeek;
    int lastMonth;


} GameState;

void updateIdlePopulation(GameState *game);


#endif
