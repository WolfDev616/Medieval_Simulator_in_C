#include "raylib.h"
#include "game.h"
#include "inputs.h"
#include "buttons.h"
#include <stdio.h>

void inputMap(GameState *game) {

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {

        Vector2 mouse = GetMousePosition();
        Rectangle farmButton;
        Rectangle wellButton;
        Rectangle millButton;
        Rectangle bakeryButton;
        Rectangle wineryButton;
        Rectangle breweryButton;

        GetBuildingButtons(
            &farmButton,
            &wellButton,
            &millButton,
            &bakeryButton,
            &wineryButton,
            &breweryButton
);
    

        if (CheckCollisionPointRec(mouse, farmButton)) {

            if (game->gold >= 5) {
                game->Farm.amount += 1;
                game->gold -= 5;
                game->workers += 1;
                game->Farm.workers += 1;
                
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

        else if (CheckCollisionPointRec(mouse, wellButton)) {

            if (game->gold >= 5) {
                game->Well.amount += 1;
                game->gold -= 5;
                game->workers += 1;
                game->Well.workers += 1;
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

        else if (CheckCollisionPointRec(mouse, millButton)) {

            if (game->gold >= 10) {
                game->Mill.amount += 1;
                game->gold -= 10;
                game->workers += 1;
                game->Mill.workers += 1;
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

        else if (CheckCollisionPointRec(mouse, bakeryButton)) {

            if (game->gold >= 12) {
                game->Bakery.amount += 1;
                game->gold -= 12;
                game->workers += 1;
                game->Bakery.workers += 1;
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

        else if (CheckCollisionPointRec(mouse, wineryButton)) {

            if (game->gold >= 10) {
                game->Winery.amount += 1;
                game->gold -= 10;
                game->workers += 1;
                game->Winery.workers += 1;
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

        else if (CheckCollisionPointRec(mouse, breweryButton)) {

            if (game->gold >= 10) {
                game->Brewery.amount += 1;
                game->gold -= 10;
                game->workers += 1;
                game->Brewery.workers += 1;
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
