#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "raylib.h"
#include "time.h"
#include "ui.h"
#include "save.h"
#include "game.h"
#include "inputs.h"
#include "economy.h"


int main() {

    GameState game = {0};

    loadGame(&game);
    printf(
    "DEBUG: Gold=%d Population=%d Food=%.2f Water=%.2f\n",
    game.gold,
    game.population,
    game.food,
    game.water
);


InitWindow(1280, 720, "Medieval Simulator");
medievalFont = LoadFont("fonts/MedievalSharp-Regular.ttf");
SetTargetFPS(60);

while (!WindowShouldClose()) {

    timeCounter(&game);
    inputMap(&game);
    updateEconomy(&game);
    warningSystem(&game);

    BeginDrawing();
    ClearBackground(RAYWHITE);

    timerHUD(&game);
    productionHUD(&game);
	buildingButtons();
    warningHUD(&game);

    EndDrawing();
}
UnloadFont(medievalFont);
saveGame(&game);
CloseWindow();
    return 0;
}
