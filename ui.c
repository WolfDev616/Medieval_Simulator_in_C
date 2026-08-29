#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "raylib.h"
#include "time.h"
#include "ui.h"
#include "game.h"
#include "buttons.h"


Font medievalFont;


void DrawMedievalText(const char *text, int x, int y, float size, Color color)
{
    DrawTextEx(
        medievalFont,
        text,
        (Vector2){x, y},
        size,
        1,
        color
    );
}


void timerHUD(GameState *game)
{
    char timeText[100];

    sprintf(
        timeText,
        "Year: %d | Month: %d | Week: %d | Day: %d",
        game->time.years,
        game->time.months,
        game->time.weeks,
        game->time.days
    );

    DrawMedievalText(
        timeText,
        30,
        30,
        30,
        BLACK
    );
}


void productionHUD(GameState *game)
{
    // Population / Workers

    DrawMedievalText(
        TextFormat("Population: %d", game->population),
        30,
        100,
        30,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Workers: %d", game->workers),
        280,
        100,
        30,
        BLACK
    );


    // Gold

    DrawMedievalText(
        TextFormat("Gold: %d pieces", game->gold),
        30,
        140,
        30,
        BLACK
    );


    // Food / Farms

    DrawMedievalText(
        TextFormat("Food: %.2f sacks", game->food),
        30,
        190,
        30,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Farms: %d", game->Farm.amount),
        30,
        220,
        30,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Farm workers: %d", game->Farm.workers),
        30,
        250,
        24,
        BLACK
    );


    // Water / Wells

    DrawMedievalText(
        TextFormat("Water: %.2f litres", game->water),
        30,
        290,
        30,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Wells: %d", game->Well.amount),
        30,
        320,
        30,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Well workers: %d", game->Well.workers),
        30,
        350,
        24,
        BLACK
    );


    // Wine / Wineries

    if (game->Winery.amount > 0) {

        DrawMedievalText(
            TextFormat("Wine: %.2f barrels", game->wine),
            30,
            390,
            30,
            BLACK
        );

        DrawMedievalText(
            TextFormat("Wineries: %d", game->Winery.amount),
            30,
            420,
            30,
            BLACK
        );

        DrawMedievalText(
            TextFormat("Winery workers: %d", game->Winery.workers),
            30,
            450,
            24,
            BLACK
        );
    }


    // Beer / Breweries

    if (game->Brewery.amount > 0) {

        DrawMedievalText(
            TextFormat("Beer: %.2f barrels", game->beer),
            30,
            490,
            30,
            BLACK
        );

        DrawMedievalText(
            TextFormat("Breweries: %d", game->Brewery.amount),
            30,
            520,
            30,
            BLACK
        );

        DrawMedievalText(
            TextFormat("Brewery workers: %d", game->Brewery.workers),
            30,
            550,
            24,
            BLACK
        );
    }
}


void buildingButtons(void)
{
    Vector2 mouse = GetMousePosition();

    Color farmColor = LIGHTGRAY;
    Color wellColor = LIGHTGRAY;
    Color wineryColor = LIGHTGRAY;
    Color breweryColor = LIGHTGRAY;


    // Hover / click

    if (CheckCollisionPointRec(mouse, FARM_BUTTON)) {

        farmColor = IsMouseButtonDown(MOUSE_BUTTON_LEFT)
                    ? DARKGRAY
                    : GRAY;
    }

    if (CheckCollisionPointRec(mouse, WELL_BUTTON)) {

        wellColor = IsMouseButtonDown(MOUSE_BUTTON_LEFT)
                    ? DARKGRAY
                    : GRAY;
    }

    if (CheckCollisionPointRec(mouse, WINERY_BUTTON)) {

        wineryColor = IsMouseButtonDown(MOUSE_BUTTON_LEFT)
                      ? DARKGRAY
                      : GRAY;
    }

    if (CheckCollisionPointRec(mouse, BREWERY_BUTTON)) {

        breweryColor = IsMouseButtonDown(MOUSE_BUTTON_LEFT)
                       ? DARKGRAY
                       : GRAY;
    }


    // Farm button

    DrawRectangleRec(FARM_BUTTON, farmColor);

    DrawMedievalText(
        "Farm",
        80,
        628,
        24,
        BLACK
    );

    DrawMedievalText(
        "5 gold",
        85,
        655,
        16,
        BLACK
    );


    // Well button

    DrawRectangleRec(WELL_BUTTON, wellColor);

    DrawMedievalText(
        "Well",
        290,
        628,
        24,
        BLACK
    );

    DrawMedievalText(
        "5 gold",
        285,
        655,
        16,
        BLACK
    );


    // Winery button

    DrawRectangleRec(WINERY_BUTTON, wineryColor);

    DrawMedievalText(
        "Winery",
        490,
        628,
        24,
        BLACK
    );

    DrawMedievalText(
        "10 gold",
        485,
        655,
        16,
        BLACK
    );


    // Brewery button

    DrawRectangleRec(BREWERY_BUTTON, breweryColor);

    DrawMedievalText(
        "Brewery",
        680,
        628,
        24,
        BLACK
    );

    DrawMedievalText(
        "10 gold",
        675,
        655,
        16,
        BLACK
    );
}


void warningHUD(GameState *game)
{
    if (game->water == 0) {

        const char *warning = "Out of water!";

        float textWidth = MeasureTextEx(
            medievalFont,
            warning,
            30,
            1
        ).x;

        DrawMedievalText(
            warning,
            1280 - textWidth - 30,
            660,
            30,
            RED
        );
    }


    if (game->food == 0) {

        const char *warning = "Out of food!";

        float textWidth = MeasureTextEx(
            medievalFont,
            warning,
            30,
            1
        ).x;

        DrawMedievalText(
            warning,
            1280 - textWidth - 30,
            690,
            30,
            RED
        );
    }
}


void warningSystem(GameState *game)
{
    // WATER

    if (game->water < 0) {
        game->water = 0;
    }


    // FOOD

    if (game->food < 0) {
        game->food = 0;
    }


    // WINE

    if (game->wine < 0) {
        game->wine = 0;
    }


    // BEER

    if (game->beer < 0) {
        game->beer = 0;
    }
}
