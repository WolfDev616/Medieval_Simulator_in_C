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

        game->gold = 100;
        game->population = 100;
        game->food = 100;
        game->water = 50;

        game->farms = 0;
        game->wells = 0;
        game->wine = 0;
        game->wineries = 0;
        game->beer = 0;
        game->breweries = 0;

        game->lastDay = 0;
        game->lastWeek = 0;
        game->lastMonth = 0;

        return;

    }

    if (fread(game, sizeof(GameState), 1, file) != 1) {
        *game = (GameState){0};

        game->gold = 100;
        game->population = 100;
        game->food = 100;
        game->water = 50;

        game->farms = 0;
        game->wells = 0;
        game->wine = 0;
        game->wineries = 0;
        game->beer = 0;
        game->breweries = 0;

        game->lastDay = 0;
        game->lastWeek = 0;
        game->lastMonth = 0;
    }

    fclose(file);
}
