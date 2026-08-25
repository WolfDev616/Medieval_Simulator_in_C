#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "time.h"
#include "ui.h"
#include "save.h"
#include "game.h"


void updateEconomy(GameState *game) {

    // DAILY ECONOMY
    if (game->time.days != game->lastDay) {

        // DAILY CONSUMPTION

        if (game->water > 0) {
            game->water -= game->population * 0.02;
        }

        if (game->food > 0) {
            game->food -= game->population * 0.02;
        }

        if (game->wine > 0) {
            game->wine -= game->population * 0.02;
        }

        if (game->beer > 0) {
            game->beer -= game->population * 0.02;
        }


        // FARM WATER CONSUMPTION

        if (game->farms > 0) {

            for (int i = 1; i <= game->farms; i++) {
                game->water -= 1;
            }
        }


        // WELL WATER PRODUCTION

        if (game->wells > 0) {

            for (int j = 1; j <= game->wells; j++) {
                game->water += 1;
            }
        }


        // Mark day as processed

        game->lastDay = game->time.days;
    }


    // WEEKLY ECONOMY

    if (game->time.weeks != game->lastWeek) {

        // WEEKLY PRODUCTION

        game->gold += game->population * 0.025;
        game->food += game->farms * 0.02;


        // BREWERY PRODUCTION

        if (game->breweries > 0) {

            for (int i = 1; i <= game->breweries; i++) {
                game->beer += 8;
            }
        }


        // Mark week as processed

        game->lastWeek = game->time.weeks;
    }


    // MONTHLY ECONOMY

    if (game->time.months != game->lastMonth) {

        // MONTHLY POPULATION GROWTH

        game->population += 1;


        // FARM PRODUCTION

        if (game->farms > 0) {

            for (int i = 1; i <= game->farms; i++) {
                game->food += 10;
            }
        }


        // WINERY PRODUCTION

        if (game->wineries > 0) {

            for (int i = 1; i <= game->wineries; i++) {
                game->wine += 8;
            }
        }


        // BREWERY WATER CONSUMPTION

        if (game->breweries > 0) {

            for (int i = 1; i <= game->breweries; i++) {
                game->water -= 18;
            }
        }


        // WINERY WATER CONSUMPTION

        if (game->wineries > 0) {

            for (int i = 1; i <= game->wineries; i++) {
                game->water -= 18;
            }
        }


        // Mark month as processed

        game->lastMonth = game->time.months;
    }
}
