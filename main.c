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

    game.population = 100;
    game.gold = 40;
    game.food = 100;
    game.farms = 0;
    game.water = 50;
    game.wells = 0;
    game.wine = 0;
    game.wineries = 0;
    game.beer = 0;
    game.breweries = 0;
    game.lastDay = 0;


    loadGame(&game);


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

    EndDrawing();
}

CloseWindow();
    return 0;
}
