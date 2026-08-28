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

void productionHUD(GameState *game) {
    DrawMedievalText(
        TextFormat("Population: %d", game->population),
        30,
        100,
        30,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Gold: %d pieces", game->gold),
        30,
        130,
        30,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Food: %.2f sacks", game->food),
        30,
        180,
        30,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Farms: %d", game->farms),
        30,
        210,
        30,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Water: %.2f litres", game->water),
        30,
        260,
        30,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Wells: %d", game->wells),
        30,
        290,
        30,
        BLACK
    );

    if (game->wineries > 0) {

        DrawMedievalText(
            TextFormat("Wine: %.2f barrels", game->wine),
            30,
            340,
            30,
            BLACK
        );

        DrawMedievalText(
            TextFormat("Wineries: %d", game->wineries),
            30,
            370,
            30,
            BLACK
        );
    }

    if (game->breweries > 0) {

        DrawMedievalText(
            TextFormat("Beer: %.2f barrels", game->beer),
            30,
            420,
            30,
            BLACK
        );

        DrawMedievalText(
            TextFormat("Breweries: %d", game->breweries),
            30,
            450,
            30,
            BLACK
        );
    }
}

void buildingButtons(void) {

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


    // Buttons

    DrawRectangleRec(FARM_BUTTON, farmColor);
    DrawTextEx(
        medievalFont,
        "Farm",
        (Vector2){80, 558},
        24,
        1,
        BLACK
    );
    DrawText(
        "5 gold",
        85,
        585,
        16,
        BLACK
    );


    DrawRectangleRec(WELL_BUTTON, wellColor);
    DrawTextEx(
        medievalFont,
        "Well",
        (Vector2){290, 558},
        24,
        1,
        BLACK
    );
    DrawText(
        "5 gold",
        285,
        585,
        16,
        BLACK
    );


    DrawRectangleRec(WINERY_BUTTON, wineryColor);
    DrawTextEx(
        medievalFont,
        "Winery",
        (Vector2){490, 558},
        24,
        1,
        BLACK
    );
    DrawText(
        "10 gold",
        485,
        585,
        16,
        BLACK
    );


    DrawRectangleRec(BREWERY_BUTTON, breweryColor);
    DrawTextEx(
        medievalFont,
        "Brewery",
        (Vector2){680, 558},
        24,
        1,
        BLACK
    );
    DrawText(
        "10 gold",
        675,
        585,
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
