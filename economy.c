#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "time.h"
#include "ui.h"
#include "save.h"
#include "game.h"

void updateEconomy(GameState *game) {

    if (game->time.days != game->lastDay) {
        game->gold += game->population * (0.025);
        game->food -= game->population * (0.01);
        game->food += game->farms * (0.02);

        game->lastDay = game->time.days;
    }

    if (game->time.months != game->lastMonth) {
        game->population += 1;

        game->lastMonth = game->time.months;
    }

}
