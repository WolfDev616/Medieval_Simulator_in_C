#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "time.h"
#include "ui.h"
#include "save.h"
#include "game.h"
#include "inputs.h"
#include "economy.h"

int main() {

    GameState game = {0};

    game.population = 100;
    game.gold = 40;
    game.food = 100;
    game.farms = 0;
    game.water = 50;
    game.wells = 0;
    game.wine = 0;
    game.wineries = 0;
    game.beer = 0;
    game.breweries = 0;
    game.lastDay = 0;


    loadGame(&game);


    while(1) {
        timeCounter(&game);
        inputMap(&game);
        timerHUD(&game);
        productionHUD(&game);
        updateEconomy(&game);
        saveGame(&game);
        warningSystem(&game);
        fflush(stdout);
        usleep(1000000);

}
    return 0;
}
