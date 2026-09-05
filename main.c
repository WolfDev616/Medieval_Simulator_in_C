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


    // WINDOW SIZE
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1280, 720, "Medieval Simulator");
    SetWindowMinSize(1000, 700);


    // MUSIC
    InitAudioDevice();

    Music music = LoadMusicStream("/home/andreas/Programação/C Projects/Medieval_Simulator/sounds/MidnightWalk.mp3");
    PlayMusicStream(music);

    medievalFont = LoadFont("fonts/MedievalSharp-Regular.ttf");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        UpdateMusicStream(music);

        timeCounter(&game);
        resourcesHUD(&game);
        inputMap(&game);
        updateEconomy(&game);
        updateIdlePopulation(&game);
        updateRevealAlpha(&game);
        warningSystem(&game);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        timerHUD(&game);
        productionHUD(&game);
        buildingButtons(&game);
        warningHUD(&game);

        EndDrawing();
    }
UnloadFont(medievalFont);
saveGame(&game);
UnloadMusicStream(music);   // Unload music stream buffers from RAM
CloseAudioDevice(); 
CloseWindow();
    return 0;
}
