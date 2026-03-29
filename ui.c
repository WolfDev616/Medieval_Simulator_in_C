#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "time.h"
#include "ui.h"
#include "game.h"

void timerHUD(GameState *game) {

        system("clear");
        printf("Year: %d | Month: %d | Week: %d | Day %d\n", game->time.years, game->time.months, game->time.weeks, game->time.days);
        printf("%02d o'clock\n", game->time.hours);


        printf("\n");
        printf("Population: %d\n", game->population);
        printf("Gold: %d\n", game->gold);
        printf("Food: %d\n", game->food);
        printf("Farms: %d\n", game->farms);

        printf("\n\n\n");
}

