#pragma once
#ifndef GAMEOBJIECT_H
#define GAMEOBJIECT_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>


using namespace std;

class GameObject {
public:
    SDL_Texture* LoadTexture(const char* texture);
    GameObject();
    GameObject(std::string texturesheet, int _x, int _y);
    // void Init(std::string texturesheet, int x, int y);
    // void SetPos(int x, int y);
    // void SetObjTexture();
    void Update();
    void Render();
    void RenderButton(int xButton, int yButton, int widthButton, int heightButton);
    void setPos(int _x, int _y){
        x = _x;
        y = _y;
        destRect.x = x;
        destRect.y = y;
    }
    SDL_Rect getRect() { 
        // cout << destRect.x << " " << destRect.y << " " << destRect.w  << " "  << destRect.h << endl;
        return destRect; 
    }
    bool isClicked(SDL_Event event);
    // bool buttonIsClicked(SDL_Event event);
    int x;
    int y;
    ~GameObject();

    
protected:
    bool inSide = false;
    SDL_Texture* objTexture;
    SDL_Rect rect;
    SDL_Rect srcRect, destRect;
    
};

#endif //GAMEOBJIECT_H
