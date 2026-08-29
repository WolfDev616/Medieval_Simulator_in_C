#include "raylib.h"
#include "game.h"
#include "inputs.h"
#include "buttons.h"
#include <stdio.h>

void inputMap(GameState *game) {

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {

        Vector2 mouse = GetMousePosition();
    

        if (CheckCollisionPointRec(mouse, FARM_BUTTON)) {

            if (game->gold >= 5) {
                game->Farm.amount += 1;
                game->gold -= 5;
                
            }
            else {
                snprintf(
                    game->warningMessage,
                    sizeof(game->warningMessage),
                    "There is not enough gold!"
                );

                game->warningTimer = 3.0f;
            }
        }

        else if (CheckCollisionPointRec(mouse, WELL_BUTTON)) {

            if (game->gold >= 5) {
                game->Well.amount += 1;
                game->gold -= 5;
            }
            else {
                snprintf(
                    game->warningMessage,
                    sizeof(game->warningMessage),
                    "There is not enough gold!"
                );

                game->warningTimer = 3.0f;
            }
        }

        else if (CheckCollisionPointRec(mouse, WINERY_BUTTON)) {

            if (game->gold >= 10) {
                game->Winery.amount += 1;
                game->gold -= 10;
            }
            else {
                snprintf(
                    game->warningMessage,
                    sizeof(game->warningMessage),
                    "There is not enough gold!"
                );

                game->warningTimer = 3.0f;
            }
        }

        else if (CheckCollisionPointRec(mouse, BREWERY_BUTTON)) {

            if (game->gold >= 10) {
                game->Brewery.amount += 1;
                game->gold -= 10;
            }
            else {
                snprintf(
                    game->warningMessage,
                    sizeof(game->warningMessage),
                    "There is not enough gold!"
                );

                game->warningTimer = 3.0f;
            }
        }
    }
}
