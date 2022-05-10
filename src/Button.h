#ifndef BUTTON_H
#define BUTTON_H
#include <SDL2/SDL.h>
enum ButtonSprite
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 13
};
const int BUTTON_WIDTH = 60;
const int BUTTON_HEIGHT = 170;
const int BUTTON_WIDTH2 = 150;
const int BUTTON_HEIGHT2 = 56;
const int BUTTON_WIDTH3 = 100;
const int BUTTON_HEIGHT3 = 60;
const int BUTTON_WIDTH4 = 240;
const int BUTTON_HEIGHT4 = 28;
const int TOTAL_BUTTONS = 13;
class Button
{
public:
    Button();
    // ~Button();
    void setPosition(int x, int y);

    void handleEvent(SDL_Event* e, int type);

    void render(int type);

    int getEnum();

    int clickCount;
private:
    SDL_Point mPosition;

    ButtonSprite mCurrentSprite;

};
#endif // BUTTON_H