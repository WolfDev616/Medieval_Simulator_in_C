#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "time.h"
#include "ui.h"
#include "game.h"

void timeCounter(GameState *game) {

    game->time.minutes += 1;

    if (game->time.minutes >= 60) {
        game->time.hours++;
        game->time.minutes = 0;
        };
    if (game->time.hours >= 12) {
        game->time.days++;
        game->time.hours = 0;
        };
    if (game->time.days >= 7) {
        game->time.weeks++;
        game->time.days = 0;
        };
    if (game->time.weeks >= 4) {
        game->time.months++;
        game->time.weeks = 0;
        };
    if (game->time.months >= 12) {
        game->time.years++;
        game->time.months = 0;
        };
}
