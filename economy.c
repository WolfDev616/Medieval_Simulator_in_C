#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "time.h"
#include "ui.h"
#include "save.h"
#include "game.h"

void updateEconomy(GameState *game) {


    if (game->time.days != game->lastDay) {

        // DAILY CONSUMPTION
        if (game->water > 0) {
            game->water -= (game->population * 0.02);
        }
        if (game->food > 0) {
            game->food -= (game->population * 0.01);
        }
        if (game->wine > 0) {
            game->wine -= (game->population * 0.01);
        }
        if (game->beer > 0) {
            game->beer -= (game->population * 0.01);
        }
        if (game->farms > 0) {
        for (int i = 1; i <= game->farms; i++) {
            game->water -= 1;
        }


        // DAILY PRODUCTION
        if (game->wells > 0) {
            for (int j = 1; j <= game->wells; j++) {
                game->water += 1;
            }
        }
    }

}


    if (game->time.weeks != game->lastWeek) {

        // WEEKLY PRODUCTION
        game->gold += game->population * (0.025);
        game->food += game->farms * (0.02);

        game->lastWeek = game->time.weeks;
    }

    if (game->time.months != game->lastMonth) {

        // MONTHLY PRODUCTION
        game->population += 1;

        if (game->farms > 0) {
        for (int i = 1; i <= game->farms; i++) {
            game->food += 10;
        }
        if (game->breweries > 0) {
        for (int i = 1; i <= game->breweries; i++) {
            game->beer += 20;
        }

        // MONTHLY CONSUMPTION
        if (game->breweries > 0) {
        for (int i = 1; i <= game->breweries; i++) {
            game->water -= 25;
        }
        if (game->wineries > 0) {
        for (int i = 1; i <= game->wineries; i++) {
            game->water -= 25;
        }


    }
        game->lastMonth = game->time.months;

}



}
}
}
}

