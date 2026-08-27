#include "raylib.h"
#include "game.h"
#include "inputs.h"
#include "buttons.h"

void inputMap(GameState *game) {

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {

        Vector2 mouse = GetMousePosition();

        if (CheckCollisionPointRec(mouse, FARM_BUTTON)) {

            if (game->gold >= 5) {
                game->farms += 1;
                game->gold -= 5;
            }
        }

        else if (CheckCollisionPointRec(mouse, WELL_BUTTON)) {

            if (game->gold >= 5) {
                game->wells += 1;
                game->gold -= 5;
            }
        }

        else if (CheckCollisionPointRec(mouse, WINERY_BUTTON)) {

            if (game->gold >= 10) {
                game->wineries += 1;
                game->gold -= 10;
            }
        }

        else if (CheckCollisionPointRec(mouse, BREWERY_BUTTON)) {

            if (game->gold >= 10) {
                game->breweries += 1;
                game->gold -= 10;
            }
        }
    }
}
