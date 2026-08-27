#ifndef UI_H
#define UI_H

#include "game.h"
#include "raylib.h"

extern Font medievalFont;

void timerHUD(GameState *game);
void productionHUD(GameState *game);
void buildingButtons(void);
void warningHUD(GameState *game);
void warningSystem(GameState *game);

#endif
