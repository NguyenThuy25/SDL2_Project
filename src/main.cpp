#include <iostream>
#include "DeckOfCards.h"
#include "Game.h"
#include "Character.h"
#include "Bot.h"

Game *game = nullptr;
SDL_Renderer *Game::renderer = nullptr;
SDL_Event event;
int passNum = 0;

int main(int argc, char *argv[])
{

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("BIG TWO GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 840, false);

    DeckOfCards deckOfCard;
    deckOfCard.shuffle();
    vector<Character> character;
    Character player1(0, deckOfCard); //  tay
    player1.sort();
    cout << endl;
    Character player2(1, deckOfCard); //  bac
    player2.sort();
    cout << endl;
    Character player3(2, deckOfCard); // dong
    player3.sort();
    cout << endl;
    Character player4(3, deckOfCard); // nam
    player4.sort();
    cout << endl;

    character.push_back(player1);
    character.push_back(player2);
    character.push_back(player3);
    character.push_back(player4);

    int whoTurn = game->whoPlayFirst();
    cout << whoTurn << " play first" << endl;
    int preValue = -5;
    while (game->running())
    {
        frameStart = SDL_GetTicks();

        // check if any player is win (run out of card)
        for (int i = 0; i < 4; i++)
        {
            if (character[i].runOutOfCard() != 0)
            {
                game->stop();
                cout << "player " << i << " win";
            }
        }
        // game->handleEvents(event) ;
        GameObject playButton("res/go.png", 150, 150);
        GameObject passButton("res/pass.png", 200, 200);
        playButton.RenderButton(500, 500, 200, 70);
        passButton.RenderButton(800, 500, 200, 70);

        bool isPlayed = false;

        if (whoTurn != 3)
        {
            // switch (whoTurn)
            // {
            // case 0:
            //     preValue = player1.botPlayCard(preValue, whoTurn, passNum);
            //     isPlayed = true;
            //     break;
            // case 1:
            //     preValue = player2.botPlayCard(preValue, whoTurn, passNum);
            //     isPlayed = true;
            //     break;
            // case 2:
            //     preValue = player2.botPlayCard(preValue, whoTurn, passNum);
            //     isPlayed = true;
            //     break;
            // default:
            //     break;
            // }
            preValue = character[whoTurn].botPlayCard(preValue, whoTurn, passNum);
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
                player4.checkEvent(event);
                // preValue = player4.playerPlayCard(preValue, whoTurn);
                int type = player4.isPlayedCard(preValue, event, playButton.isClicked(event), passButton.isClicked(event));
                // if(type!=-1) {
                //     cout << "PreValue: " << preValue << endl;
                //     cout << "Type is: " << type << endl;
                // }

                if (type == 1)
                {
                    preValue = player4.playerPlayCard(preValue, event, passNum);
                    isPlayed = true; // isPassed
                }
                if (type == 3)
                {
                    isPlayed = true; // isPassed
                    passNum++;
                    cout << "Pass " << passNum << endl;
                    if (passNum == 3)
                    {
                        // whoTurn = (whoTurn + 1) % 4;
                        preValue = -5;
                    }
                    if (passNum > 3)
                        passNum = 1;
                }
            }
        }

        if (isPlayed)
        {
            whoTurn = (whoTurn + 1) % 4;
        }
        // cout << whoTurn << ": " << endl;

        player1.printCard();
        player2.printCard();
        player3.printCard();
        player4.printCard();

        SDL_RenderPresent(Game::renderer);
        SDL_RenderClear(Game::renderer);
        // game->update();
        // game->render(d);
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}

// bot1 bot2 bot3 player
// value1 pass pass++ pass++ value1 pass play->pass : 0