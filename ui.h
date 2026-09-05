#ifndef UI_H
#define UI_H

#include <stdbool.h>
#include "raylib.h"
#include "game.h"

// ---------------------------------------------------------
// Font used for all in-game text
// ---------------------------------------------------------
extern Font medievalFont;

// ---------------------------------------------------------
// Reveal / fade-in system
// ---------------------------------------------------------
void UpdateReveal(Reveal *r, bool unlocked);
void updateRevealAlpha(GameState *game);

// ---------------------------------------------------------
// Drawing helpers
// ---------------------------------------------------------
void DrawMedievalText(const char *text, int x, int y, float size, Color color);

void DrawProductionCell(
    int column,
    int row,
    float cellWidth,
    float cellHeight,
    float margin,
    float top,
    const char *name,
    int amount,
    int workers,
    float alpha
);

// ---------------------------------------------------------
// HUD sections
// ---------------------------------------------------------
void timerHUD(GameState *game);
void resourcesHUD(GameState *game);
void productionHUD(GameState *game);
void buildingButtons(GameState *game);
void warningHUD(GameState *game);

// ---------------------------------------------------------
// Systems
// ---------------------------------------------------------
void warningSystem(GameState *game);

#endif // UI_H