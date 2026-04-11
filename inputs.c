#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include "game.h"
#include "inputs.h"

void inputMap(GameState *game) {

    fd_set set;
    struct timeval timeout;

    FD_ZERO(&set);
    FD_SET(STDIN_FILENO, &set);

    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    int result = select(STDIN_FILENO + 1, &set, NULL, NULL, &timeout);

    if (result > 0) {
        char input = getchar();

        if (input == 'c') {
            if (game->gold >= 5) {
                game->farms += 1;
                game->gold -= 5;
            } else {
                printf("There is not enough gold!\n");
            }
        }

        if (input == 'w') {
            if (game->gold >= 5) {
                game->wells += 1;
                game->gold -= 5;
            } else {
                printf("There is not enough gold!\n");
            }
        }
    }
}
