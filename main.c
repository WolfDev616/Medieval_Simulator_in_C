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
    game.lastDay = 0;

    loadGame(&game);


    while(1) {
        timeCounter(&game);
        inputMap(&game);
        timerHUD(&game);
        productionHUD(&game);
        updateEconomy(&game);
        saveGame(&game);
        sleep(1);

}
    return 0;
};
