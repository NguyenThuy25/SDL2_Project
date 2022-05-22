#include "Game.h"
Game::Game() {
    isRunning = true;
}

void Game::init(const char *title, int x, int y, int w, int h, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialised..." << std::endl;

        window = SDL_CreateWindow(title, x, y, w, h, flags);
        if (window) {
            std::cout << "Window created!" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        if (TTF_Init() == -1) {
            std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
        }
        isRunning = true;
    }
    else {
        isRunning = false;
    }
}

int Game::whoPlayFirst() {
    cout << rand() % 4 << " play first" << endl;
    return rand()%4;
}

bool Game::running() { 
    return isRunning;
}

void Game::handCard(DeckOfCards &deck, vector<Character> &character) {
    deck.shuffle();
    character.push_back(Character(0, deck));
    character.push_back(Character(1, deck));
    character.push_back(Character(2, deck));
    character.push_back(Character(3, deck));
    for (int i = 0; i < 4; i++) {
        character[i].sort();
        character[i].putStraightThree();
        character[i].putThree();
        character[i].putPair();
    }
}

void Game::renderMenu(SDL_Event &event) {
    GameObject menuBackground("res/bghuhu.png", 0, 0);
    GameObject startButton("res/startButton1.png", 200, 200);
    while (isRunning) {
        bool out = false;
        SDL_SetRenderDrawColor(Game::renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(Game::renderer);
        menuBackground.RenderButton(0, 0, 1280, 840, 0, false);
        startButton.RenderButton(900, 600, 128, 136, 0, false);
        SDL_RenderPresent(Game::renderer);
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
                break;
            }
            if (startButton.isClicked(event, 2)) {
                out = true;
            }
        }
        if (out)
            break;
    }
}

void Game::renderInGame(GameObject &playButton, GameObject &passButton) {
    GameObject inGameBg("res/inGamebg.png", 0, 0);
    GameObject table("res/table.png", 400, 400);

    inGameBg.RenderButton(0, 0, 1280, 840, 0, true);
    table.RenderButton(150, 180, 1000, 500, 0, true);
    playButton.RenderButton(1000, 670, 200, 70, 0, false);
    passButton.RenderButton(1000, 750, 200, 70, 0, false);
}

void Game::render(vector<Character> &character) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < character[i].hand.size(); j++) {
            character[i].hand[j].path = cardGraphics[52];
        }
    }
    character[0].printCard();
    character[1].printCard();
    character[2].printCard();
    character[3].printCard();
    SDL_RenderPresent(Game::renderer);
    SDL_RenderClear(Game::renderer);
}

void Game::isOver(vector<Character> &character, Texture &whoWinText) {
    for (int i = 0; i < 4; i++) {
        if (character[i].runOutOfCard() != 0) {
            cout << "player " << i << " win!" << endl;
            SDL_Color textColor = {255, 255, 255};
            whoWinText.setBlendMode(SDL_BLENDMODE_BLEND);
            string str;
            if (i == 3) {
                str = "You Win!";
            }
            else if (i == 0)
                str = "Player 1 win!";
            else if (i == 1)
                str = "Player 2 win!";
            else if (i == 2)
                str = "Player 3 win!";
            whoWinText.loadFromRenderedText(str, textColor);
            whoWinText.render(650, 550);
            isRunning = false;
        }
    }
}

void Game::stop() {
    isRunning = false;
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

Game::~Game() {}
