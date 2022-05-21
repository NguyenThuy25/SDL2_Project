#pragma once
#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
// #include"DeckOfCards.h"
#include "Character.h"

class Game {
public:
    Game();
    ~Game();
    
    void init(const char* title, int x, int y, int w, int h, bool fullscreen);
    void setUp();
    void handleEvents(SDL_Event event);
    void update();
    void render(vector<Character> &character);
    void clean();
    bool running() {return isRunning; };
    void stop() {
        isRunning = false;
    }

    static SDL_Renderer *renderer;
    // int numOfPlayerLeft = 4;

    int whoPlayFirst() {
        return rand()%4;
    }

private:
    bool isRunning;
    SDL_Window *window;
    // add class Character
    // Deck -> bo bai
    // std::vector<Character*> characters; -> THuy ba linh
    // characters.push_back(new Bot())
    // characters.push_back(new Bot())
    // characters.push_back(new Player())

    // std::vector<Card*> bot1;
    // std::vector<Card*> bot2;
    // std::vector<Card*> bot3;
    // std::vector<Card*> player;
};

#endif // GAME_H