#include <iostream>
#include "Game.h"
#include "Character.h"

Game *game = nullptr;
SDL_Renderer *Game::renderer = nullptr;
SDL_Event event;
int passNum = 0;
Play play;

int main(int argc, char *argv[])
{
    // const int FPS = 60;
    // const int frameDelay = 1000 / FPS;
    // Uint32 frameStart;
    // int frameTime;
    game = new Game();
    game->init("BIG TWO GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 840, false);

    DeckOfCards deckOfCard;
    deckOfCard.shuffle();
    vector<Character> character;
    character.push_back(Character(0, deckOfCard));
    character.push_back(Character(1, deckOfCard));
    character.push_back(Character(2, deckOfCard));
    character.push_back(Character(3, deckOfCard));
    for(int i=0; i<4; i++) {
        character[i].sort();
        character[i].putStraightThree();
        character[i].putPair();
        character[i].putThree();
    }
    
    int whoTurn = game->whoPlayFirst();
    cout << whoTurn << " play first" << endl;
    play.maxCard = -5;
    while (game->running())
    {
        // frameStart = SDL_GetTicks();
        
        // game->handleEvents(event) ;
        GameObject playButton("res/go.png", 150, 150);
        GameObject passButton("res/pass.png", 200, 200);
        playButton.RenderButton(500, 500, 200, 70);
        passButton.RenderButton(800, 500, 200, 70);

        bool isPlayed = false;
        if (whoTurn != 3)
        {
            if (play.maxCard < 0) {
                    if(character[whoTurn].straightThree.size() != 0) {
                        play.kindcode = 5;

                    }
                    else if(character[whoTurn].three.size() != 0) {
                        play.kindcode = 3;
                    }
                    else if (character[whoTurn].pair.size() != 0) {
                        play.kindcode = 2;
                    }
                    else {
                        play.kindcode = 1;
                    }
                }
                cout <<"play.kindcode ="  << play.kindcode << endl;
                play = character[whoTurn].playCardAI(play, whoTurn, passNum);
                character[whoTurn].popOut();
                isPlayed = true;

            }
        

        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                game->stop();
                break;
            default:
                break;
            }
            if (whoTurn == 3)
            {
                character[3].checkEvent(event);
                int type = character[3].isPlayedCard(play, event, playButton.isClicked(event, 2), passButton.isClicked(event, 2));
                // cout << "type of player " << type << endl;
                if (type == 1)
                {
                    play = character[3].playerPlayCard(play, event, passNum);
                    character[3].popOut();
                    isPlayed = true; // isPassed
                }
                if (type == 3)
                {
                    isPlayed = true; // isPassed
                    passNum++;
                    cout << "Pass " << passNum << endl;
                    if (passNum == 3)
                    {
                        play.maxCard = -5;
                    }
                    if (passNum > 3)
                        passNum = 1;
                }
        
            }
        }
        // check if any player is win (run out of card)
        for(int i=0; i<4; i++) {
            if(character[i].runOutOfCard() != 0) {
                cout << "player " << i << " win!" << endl;
                game->stop();
            }
        }
        if (isPlayed)
        {
            whoTurn = (whoTurn + 1) % 4;
        }
        // cout << whoTurn << "'s turn " << endl;

        // game->update();
        game->render(character);
        // frameTime = SDL_GetTicks() - frameStart;
        // if (frameDelay > frameTime)
        // {
        //     SDL_Delay(frameDelay - frameTime);
        // }
    }
    game->clean();
    return 0;
}

