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
        
        if (game->bread > 0) {
            game->bread -= game->population * 0.01;
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


        // DAILY PRODUCTION

        if (game->Well.amount > 0) {

            for (int j = 1; j <= game->Well.amount; j++) {
                game->water += 3;
            }
        }

        if (game->Bakery.amount > 0) {
            
            for (int i = 1; i <= game->Bakery.amount; i++) {

                if (game->flour > 5 && game->water > 5){

                    game->flour -= 5;
                    game->flour -= 5;
                    game->bread += 5;
                } 
            }
        }


        // Mark day as processed

        game->lastDay = game->time.days;
    }


    // WEEKLY ECONOMY

    if (game->time.weeks != game->lastWeek) {

        // WEEKLY PRODUCTION

        game->gold += game->population * 0.08;

        if (game->Mill.amount > 0) {

            for (int i = 1; i <= game->Mill.amount; i++) {
                if (game->grains > 5) {
                    game->grains -= 5;
                    game->flour += 25;
                }
            }
        }


        // BREWERY PRODUCTION AND CONSUMPTION

        if (game->Brewery.amount > 0) {

            for (int i = 1; i <= game->Brewery.amount; i++) {
                if (game->grains > 5 && game->water > 5) {
                    game->water -= 5;
                    game->grains -= 5;
                    game->beer += 15;
                }
            }
        }


        // Mark week as processed

        game->lastWeek = game->time.weeks;
    }


    // MONTHLY ECONOMY

    if (game->time.months != game->lastMonth) {

        // MONTHLY POPULATION GROWTH

        game->population += (rand() % 3) + 1;

        // FARM PRODUCTION

        if (game->Farm.amount > 0) {

            for (int i = 1; i <= game->Farm.amount; i++) {
                game->grains += 10;
            }
        }


        // WINERY PRODUCTION

        if (game->Winery.amount > 0) {

            for (int i = 1; i <= game->Winery.amount; i++) {
                if (game->grains > 15 && game->water > 15) {

                    game->grains -= 15;
                    game->water -= 15;
                    game->wine += 15;
                }
            }
        }


        // WINERY WATER AND GRAINS CONSUMPTION

        if (game->Winery.amount > 0) {

            for (int i = 1; i <= game->Winery.amount; i++) {
            }
        }


        // Mark month as processed

        game->lastMonth = game->time.months;
    }
}
