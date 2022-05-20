#pragma once
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
    SDL_Texture* LoadTexture(const char* texture);
    GameObject();
    GameObject(std::string texturesheet, int _x, int _y);
    void Update();
    void Render();
    // void RenderFull();
    void RenderArrow(int angle);
    void RenderButton(int xButton, int yButton, int widthButton, int heightButton, int angle);
    void setPos(int _x, int _y){
        x = _x;
        y = _y;
        destRect.x = x;
        destRect.y = y;
    }
    SDL_Rect getRect() { 
        return destRect; 
    }
    bool isClicked(SDL_Event& event, int cardOrButton);
    // int showMenu(SDL_Surface* des, TTF_Font* font) {
    //     objTexture = LoadTexture("res/gameMenu.jpg");
    //     if(objTexture == NULL) {
    //         return 1;
    //     }

    //     const int item = 2;
    //     SDL_Rect pos_arr[item];
    //     pos_arr[0].x = 200;
    //     pos_arr[0].y = 200;
    //     pos_arr[1].x = 300;
    //     pos_arr[2].y = 300;


    // }
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
