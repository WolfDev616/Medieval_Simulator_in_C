#include "raylib.h"
#include "buttons.h"

void GetBuildingButtons(
    Rectangle *farm,
    Rectangle *well,
    Rectangle *winery,
    Rectangle *brewery
)
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    float margin = 30;
    float spacing = 20;

    float availableWidth =
        screenWidth - (margin * 2) - (spacing * 3);

    float buttonWidth = availableWidth / 4.0f;
    float buttonHeight = 50;

    float startX = margin;

    float y = screenHeight - buttonHeight - 30;


    *farm = (Rectangle){
        startX,
        y,
        buttonWidth,
        buttonHeight
    };

    *well = (Rectangle){
        startX + buttonWidth + spacing,
        y,
        buttonWidth,
        buttonHeight
    };

    *winery = (Rectangle){
        startX + (buttonWidth + spacing) * 2,
        y,
        buttonWidth,
        buttonHeight
    };

    *brewery = (Rectangle){
        startX + (buttonWidth + spacing) * 3,
        y,
        buttonWidth,
        buttonHeight
};

}
