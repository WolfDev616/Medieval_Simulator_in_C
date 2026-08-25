#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "raylib.h"
#include "time.h"
#include "ui.h"
#include "game.h"

void timerHUD(GameState *game) {

    char timeText[100];

    sprintf(
        timeText,
        "Year: %d | Month: %d | Week: %d | Day: %d",
        game->time.years,
        game->time.months,
        game->time.weeks,
        game->time.days
    );

    DrawText(timeText, 30, 30, 24, BLACK);
}

void productionHUD(GameState *game) {

    DrawText(TextFormat("Population: %d", game->population),
             30, 100, 24, BLACK);

    DrawText(TextFormat("Gold: %d", game->gold),
             30, 130, 24, BLACK);

    DrawText(TextFormat("Food: %.2f", game->food),
             30, 180, 24, BLACK);

    DrawText(TextFormat("Farms: %d", game->farms),
             30, 210, 24, BLACK);

    DrawText(TextFormat("Water: %.2f", game->water),
             30, 260, 24, BLACK);

    DrawText(TextFormat("Wells: %d", game->wells),
             30, 290, 24, BLACK);

    if (game->wineries > 0) {

        DrawText(TextFormat("Wine: %.2f barrels", game->wine),
                 30, 340, 24, BLACK);

        DrawText(TextFormat("Wineries: %d", game->wineries),
                 30, 370, 24, BLACK);
    }

    if (game->breweries > 0) {

        DrawText(TextFormat("Beer: %.2f", game->beer),
                 30, 420, 24, BLACK);

        DrawText(TextFormat("Breweries: %d", game->breweries),
                 30, 450, 24, BLACK);
    }
}

void warningHUD(GameState *game) {

    if (game->water == 0) {
        const char *warning = "Out of water!";
        DrawText(
            warning,
            1280 - MeasureText(warning, 24) - 30,
            660,
            24,
            RED
        );
    }

    if (game->food == 0) {
        const char *warning = "Out of food!";
        DrawText(
            warning,
            1280 - MeasureText(warning, 24) - 30,
            690,
            24,
            RED
        );
    }
}

void warningSystem(GameState *game) {

    // WATER
    if (game->water < 0) {
        game->water = 0;
    }

    // FOOD
    if (game->food < 0) {
        game->food = 0;
    }
}
