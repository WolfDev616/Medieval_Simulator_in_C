#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "time.h"
#include "ui.h"
#include "game.h"

void timerHUD(GameState *game) {

        printf("\033[H");
        printf("\nYear: %d | Month: %d | Week: %d | Day %d\n", game->time.years, game->time.months, game->time.weeks, game->time.days);

        printf("\n----------------------------------------\n");
}


void productionHUD(GameState *game) {

        // Population
        printf("\n");
        printf("Population: %d\n", game->population);
        // Gold
        printf("Gold: %d\n", game->gold);
        printf("\n");
        // Provisions
        printf("Food: %.2f\n", game->food);
        printf("Farms: %d\n", game->farms);
        printf("\n");
        // Water
        printf("Water: %.2f\n", game->water);
        printf("Wells: %d\n", game->wells);
        printf("\n");
        // Beverages
        if (game->wineries > 1) {
        printf("Wine: %.2f barrels.\n", game->wine);
        printf("Wineries: %d\n", game->wineries);
        printf("\n");
        }
        if (game->breweries > 1) {
        printf("Beer: %.2f\n", game->beer);
        printf("Breweries: %d\n", game->breweries);
        printf("\n");
        }
        // Livestock

}

void warningSystem(GameState *game) {
        // RUNNING OUT OF SUPPLIES

        // WATER
        if (game->water < 0) {
            game->water = 0;
            }
        if (game->water == 0) {
            printf("Out of water!\n");
            }

        // FOOD
        if (game->food < 0) {
            game->food = 0;
            }
        if (game->food == 0) {
            printf("Out of food!\n");
            }

}

