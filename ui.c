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
        (Vector2){(float)x, (float)y},
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

void DrawProductionCell(
    int column,
    int row,
    float cellWidth,
    float cellHeight,
    float margin,
    float top,
    const char *name,
    int amount,
    int workers
    )
    {
    float x = margin + (column * cellWidth);
    float y = top + (row * cellHeight);


    // Cell border
    DrawRectangleLines(
        (int)x,
        (int)y,
        (int)cellWidth,
        (int)cellHeight,
        BLACK
    );

    // Production name
    float nameWidth = MeasureTextEx(
        medievalFont,
        name,
        26,
        1
    ).x;

    DrawMedievalText(
        name,
        x + (cellWidth - nameWidth) / 2,
        y + 15,
        26,
        BLACK
    );

    // Number of establishments
    DrawMedievalText(
        TextFormat("Buildings: %d", amount),
        x + 20,
        y + cellHeight * 0.50f,
        20,
        BLACK
    );

    // Number of workers
    DrawMedievalText(
        TextFormat("Workers: %d", workers),
        x + 20,
        y + cellHeight * 0.70f,
        20,
        BLACK
    );

}

void resourcesHUD(GameState *game)
{
    float margin = 30;
    float startY = 80;

    float columnWidth = GetScreenWidth() / 4.0f;;
    float rowHeight = 35;

// Population
    DrawMedievalText(
        TextFormat("Population: %d", game->population),
        margin,
        startY,
        24,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Idle Population: %d", game->idlePopulation),
        margin + columnWidth,
        startY,
        24,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Workers: %d", game->workers),
        margin + (columnWidth * 2),
        startY,
        24,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Gold: %d", game->gold),
        margin + (columnWidth * 3),
        startY,
        24,
        BLACK
    );


    // Resources
    DrawMedievalText(
        TextFormat("Grains: %.2f", game->grains),
        margin,
        startY + rowHeight,
        22,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Water: %.2f", game->water),
        margin + columnWidth,
        startY + rowHeight,
        22,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Bread: %.2f", game->bread),
        margin + (columnWidth * 2),
        startY + rowHeight,
        22,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Wine: %.2f", game->wine),
        margin + (columnWidth * 3),
        startY + rowHeight,
        22,
        BLACK
    );

    DrawMedievalText(
        TextFormat("Beer: %.2f", game->beer),
        margin,
        startY + (rowHeight * 2),
        22,
        BLACK
    );

}


void productionHUD(GameState *game)
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    // Grid dimensions
    int columns = 4;
    int rows = 4;

    float margin = 30;
    float top = 190;
    float bottom = 120;

    float gridWidth = screenWidth - (margin * 2);
    float gridHeight = screenHeight - top - bottom;

    float cellWidth = gridWidth / columns;
    float cellHeight = gridHeight / rows;

    // Row 1
    DrawProductionCell(
        0, 0,
        cellWidth, cellHeight,
        margin, top,
        "Farm",
        game->Farm.amount,
        game->Farm.workers
    );

    DrawProductionCell(
        1, 0,
        cellWidth, cellHeight,
        margin, top,
        "Well",
        game->Well.amount,
        game->Well.workers
    );

    DrawProductionCell(
        2, 0,
        cellWidth, cellHeight,
        margin, top,
        "Mill",
        game->Mill.amount,
        game->Mill.workers
    );

    DrawProductionCell(
        3, 0,
        cellWidth, cellHeight,
        margin, top,
        "Bakery",
        game->Bakery.amount,
        game->Bakery.workers
    );

    // Row 2
    DrawProductionCell(
        0, 1,
        cellWidth, cellHeight,
        margin, top,
        "Winery",
        game->Winery.amount,
        game->Winery.workers
    );

    DrawProductionCell(
        1, 1,
        cellWidth, cellHeight,
        margin, top,
        "Brewery",
        game->Brewery.amount,
        game->Brewery.workers
    );

// Empty cells reserved for future productions

}



void buildingButtons(void)
{
Rectangle farmButton;
Rectangle wellButton;
Rectangle wineryButton;
Rectangle breweryButton;


GetBuildingButtons(
    &farmButton,
    &wellButton,
    &wineryButton,
    &breweryButton
);

Vector2 mouse = GetMousePosition();

Color farmColor = LIGHTGRAY;
Color wellColor = LIGHTGRAY;
Color wineryColor = LIGHTGRAY;
Color breweryColor = LIGHTGRAY;

// Hover / click
if (CheckCollisionPointRec(mouse, farmButton)) {
    farmColor = IsMouseButtonDown(MOUSE_BUTTON_LEFT)
                ? DARKGRAY
                : GRAY;
}

if (CheckCollisionPointRec(mouse, wellButton)) {
    wellColor = IsMouseButtonDown(MOUSE_BUTTON_LEFT)
                ? DARKGRAY
                : GRAY;
}

if (CheckCollisionPointRec(mouse, wineryButton)) {
    wineryColor = IsMouseButtonDown(MOUSE_BUTTON_LEFT)
                  ? DARKGRAY
                  : GRAY;
}

if (CheckCollisionPointRec(mouse, breweryButton)) {
    breweryColor = IsMouseButtonDown(MOUSE_BUTTON_LEFT)
                   ? DARKGRAY
                   : GRAY;
}

// Farm button
DrawRectangleRec(farmButton, farmColor);

DrawMedievalText(
    "Farm",
    farmButton.x + 50,
    farmButton.y + 8,
    24,
    BLACK
);

DrawMedievalText(
    "5 gold",
    farmButton.x + 55,
    farmButton.y + 35,
    16,
    BLACK
);


// Well button
DrawRectangleRec(wellButton, wellColor);

DrawMedievalText(
    "Well",
    wellButton.x + 60,
    wellButton.y + 8,
    24,
    BLACK
);

DrawMedievalText(
    "5 gold",
    wellButton.x + 55,
    wellButton.y + 35,
    16,
    BLACK
);


// Winery button
DrawRectangleRec(wineryButton, wineryColor);

DrawMedievalText(
    "Winery",
    wineryButton.x + 60,
    wineryButton.y + 8,
    24,
    BLACK
);

DrawMedievalText(
    "10 gold",
    wineryButton.x + 55,
    wineryButton.y + 35,
    16,
    BLACK
);


// Brewery button
DrawRectangleRec(breweryButton, breweryColor);

DrawMedievalText(
    "Brewery",
    breweryButton.x + 50,
    breweryButton.y + 8,
    24,
    BLACK
);

DrawMedievalText(
    "10 gold",
    breweryButton.x + 45,
    breweryButton.y + 35,
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
            GetScreenWidth() - textWidth - 30,
            GetScreenHeight() - 60,
            30,
            RED
        );
    }


//     if (game->food == 0) {

//         const char *warning = "Out of food!";

//         float textWidth = MeasureTextEx(
//             medievalFont,
//             warning,
//             30,
//             1
//         ).x;

//         DrawMedievalText(
//             warning,
//             1280 - textWidth - 30,
//             690,
//             30,
//             RED
//         );
//     }
}


void warningSystem(GameState *game)
{
    // WATER

    if (game->water < 0) {
        game->water = 0;
    }


    // GRAINS

    if (game->grains < 0) {
        game->grains = 0;
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
