#include <stdio.h>
#include "save.h"
#include "game.h"

void saveGame(GameState *game) {
    FILE *file = fopen("save.dat", "wb");
    if (file == NULL) return;

    fwrite(game, sizeof(GameState), 1, file);
    fclose(file);
}


void loadGame(GameState *game) {
    FILE *file = fopen("save.dat", "rb");

    if (file == NULL) {
        *game = (GameState){0};
        game->gold = 40;
        game->population = 40;
        game->food = 100;
        game->farms = 0;
        game->lastDay = 0;
        game->lastMonth = 0;
        return;
    }

    if (fread(game, sizeof(GameState), 1, file) != 1) {
        *game = (GameState){0};
        game->gold = 40;
        game->population = 40;
        game->food = 100;
        game->farms = 0;
        game->lastDay = 0;
        game->lastMonth = 0;
    }

    fclose(file);
}
