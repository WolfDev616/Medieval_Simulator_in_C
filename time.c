#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "time.h"

void timeCounter(GameTime *gameTime) {

    gameTime->seconds += 1;

    if (gameTime->seconds >= 20) {
        gameTime->minutes++;
        gameTime->seconds = 0;
        };
    if (gameTime->minutes >= 60) {
        gameTime->hours++;
        gameTime->minutes = 0;
        };
    if (gameTime->hours >= 24) {
        gameTime->days++;
        gameTime->hours = 0;
        };
    if (gameTime->days >= 7) {
        gameTime->weeks++;
        gameTime->days = 0;
        };
    if (gameTime->weeks >= 4) {
        gameTime->months++;
        gameTime->weeks = 0;
        };
    if (gameTime->months >= 12) {
        gameTime->years++;
        gameTime->months = 0;
        };
}
