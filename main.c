#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "time.h"
#include "ui.h"
#include "save.h"
#include "game.h"

int main() {

    GameState game = {0};

    game.population = 100;
    game.gold = 40;
    game.food = 50;
    game.farms = 0;
    game.lastHour = 0;

    loadGame(&game);


    while(1) {
        timeCounter(&game);
        if (game.time.hours != game.lastHour) {
        game.gold += game.population * (0.025);
        game.population += 1;
        game.food -= game.population * (0.01);
        game.food += game.farms * (0.02);





        game.lastHour = game.time.hours;
}
        timerHUD(&game);
        saveGame(&game);
        sleep(1);

} system("pwd");
    return 0;
};
