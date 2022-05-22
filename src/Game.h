#pragma once
#ifndef GAME_H
#define GAME_H

#include "Character.h"
#include "Texture.h"

class Game {
private:
    SDL_Window *window;
    
public:
    static SDL_Renderer *renderer;
    bool isRunning;

    Game();
    void init(const char* title, int x, int y, int w, int h, bool fullscreen);
    int whoPlayFirst();
    bool running();
    void handCard(DeckOfCards& deck, vector<Character>& character);
    void renderMenu(SDL_Event &event);
    void renderInGame(GameObject& playButton, GameObject& passButton);
    void render(vector<Character> &character);
    void isOver(vector<Character>& character,  Texture& whoWinText);
    void stop();
    void clean();
    ~Game();
};

#endif // GAME_H