#include "Game.h"
// #include "Character.h"
Game::Game() {
    isRunning = true;
}
Game::~Game() {}

void Game::init(const char *title, int x, int y, int w, int h, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialised..." << std::endl;

        window = SDL_CreateWindow(title, x, y, w, h, flags);
        if (window)
        {
            std::cout << "Window created!" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        if(TTF_Init() == -1) {
            std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl ;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    
}

void Game::setUp() {}

void Game::handleEvents(SDL_Event event)
{
    while (SDL_PollEvent(&event) != 0) {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::update()
{
    
}
void Game::render(vector<Character> &character)
{
    

    for(int i=0; i<3; i++) {
        for(int j=0; j<character[i].hand.size(); j++) {
            character[i].hand[j].path = cardGraphics[52];
        }
    }
    character[0].printCard();
    character[1].printCard();
    character[2].printCard();
    character[3].printCard();  
        
    

    // for(int i=0; i<3; i++) {
    //     character[i].printCard();
    // }
    
    
}


void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}