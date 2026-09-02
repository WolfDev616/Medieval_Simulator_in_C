#include "raylib.h"
#include "buttons.h"

void GetBuildingButtons(
Rectangle *farm,
Rectangle *well,
Rectangle *mill,
Rectangle *bakery,
Rectangle *winery,
Rectangle *brewery
)
{
int screenWidth = GetScreenWidth();
int screenHeight = GetScreenHeight();


const int columns = 3;

float margin = 30;
float spacing = 15;

float buttonHeight = 60;

float availableWidth =
    screenWidth
    - (margin * 2)
    - (spacing * (columns - 1));

float buttonWidth =
    availableWidth / columns;

float bottomMargin = 30;

float startY =
    screenHeight
    - (buttonHeight * 2)
    - spacing
    - bottomMargin;

// First row

*farm = (Rectangle){
    margin,
    startY,
    buttonWidth,
    buttonHeight
};

*well = (Rectangle){
    margin + buttonWidth + spacing,
    startY,
    buttonWidth,
    buttonHeight
};

*mill = (Rectangle){
    margin + (buttonWidth + spacing) * 2,
    startY,
    buttonWidth,
    buttonHeight
};


// Second row

*bakery = (Rectangle){
    margin,
    startY + buttonHeight + spacing,
    buttonWidth,
    buttonHeight
};

*winery = (Rectangle){
    margin + buttonWidth + spacing,
    startY + buttonHeight + spacing,
    buttonWidth,
    buttonHeight
};

*brewery = (Rectangle){
    margin + (buttonWidth + spacing) * 2,
    startY + buttonHeight + spacing,
    buttonWidth,
    buttonHeight
};

}
