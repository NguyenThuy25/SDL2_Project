#ifndef GAMEOBJIECT_H
#define GAMEOBJIECT_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>
using namespace std;

class GameObject {
public:
    int x;
    int y;
    
    GameObject();
    GameObject(std::string texturesheet, int _x, int _y);
    SDL_Texture* LoadTexture(const char* texture);
    void Render();
    void RenderArrow(int angle);
    void RenderButton(int xButton, int yButton, int widthButton, int heightButton, int angle, bool isDelay);
    void setPos(int _x, int _y);
    SDL_Rect getRect();
    bool isClicked(SDL_Event& event, int cardOrButton);
    ~GameObject();

public:
    bool inSide = false;
    SDL_Texture* objTexture;
    SDL_Rect rect;
    SDL_Rect srcRect, destRect;
};

#endif //GAMEOBJIECT_H
