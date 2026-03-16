#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "time.h"

int main() {

    GameTime gameTime = {0};

    while(1) {
        timeCounter(&gameTime); // passa ponteiro para a função
        timerHUD(&gameTime); // depois chama o HUD
        sleep(1);
}
    return 0;
};
