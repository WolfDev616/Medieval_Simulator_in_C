#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "time.h"
#include "ui.h"
#include "save.h"
#include "game.h"
#include "raylib.h"


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
            game->wine -= game->population * 0.01;
        }

        if (game->beer > 0) {
            game->beer -= game->population * 0.02;
        }


        // FARM WATER CONSUMPTION

        if (game->Farm.amount > 0) {

            for (int i = 1; i <= game->Farm.amount; i++) {
                game->water -= 1;
            }
        }


        // WELL WATER PRODUCTION

        if (game->Well.amount > 0) {

            for (int j = 1; j <= game->Well.amount; j++) {
                game->water += 3;
            }
        }


        // Mark day as processed

        game->lastDay = game->time.days;
    }


    // WEEKLY ECONOMY

    if (game->time.weeks != game->lastWeek) {

        // WEEKLY PRODUCTION

        game->gold += game->population * 0.025;
        game->food += game->Farm.amount * 0.02;


        // BREWERY PRODUCTION

        if (game->Brewery.amount > 0) {

            for (int i = 1; i <= game->Brewery.amount; i++) {
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

        if (game->Farm.amount > 0) {

            for (int i = 1; i <= game->Farm.amount; i++) {
                game->food += 10;
            }
        }


        // WINERY PRODUCTION

        if (game->Winery.amount > 0) {

            for (int i = 1; i <= game->Winery.amount; i++) {
                game->wine += 15;
            }
        }


        // BREWERY WATER CONSUMPTION

        if (game->Brewery.amount > 0) {

            for (int i = 1; i <= game->Brewery.amount; i++) {
                game->water -= 10;
            }
        }


        // WINERY WATER CONSUMPTION

        if (game->Winery.amount > 0) {

            for (int i = 1; i <= game->Winery.amount; i++) {
                game->water -= 15;
            }
        }


        // Mark month as processed

        game->lastMonth = game->time.months;
    }
}
