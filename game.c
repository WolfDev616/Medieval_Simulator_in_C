#include "game.h"

void updateIdlePopulation(GameState *game)
{
    game->idlePopulation =
        game->population - game->workers;
}