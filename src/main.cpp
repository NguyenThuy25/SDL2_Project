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
    Character player1(0, deckOfCard); //  tay
    player1.sort();
    player1.putPair();
    player1.putThree();
    cout << endl;
    Character player2(1, deckOfCard); //  bac
    player2.sort();
    player2.putPair();
    player2.putThree();
    cout << endl;
    Character player3(2, deckOfCard); // dong
    player3.sort();
    player3.putPair();
    player3.putThree();
    cout << endl;
    Character player4(3, deckOfCard); // nam
    player4.sort();
    player4.putPair();
    player4.putThree();
    cout << endl;

    character.push_back(player1);
    character.push_back(player2);
    character.push_back(player3);
    character.push_back(player4);

    int whoTurn = game->whoPlayFirst();
    cout << whoTurn << " play first" << endl;
    play.maxCard = -5;
    while (game->running())
    {
        // frameStart = SDL_GetTicks();
        // check if any player is win (run out of card)
        for (int i = 0; i < 4; i++)
        {
            if (player1.runOutOfCard() != 0 || player2.runOutOfCard() != 0 || player3.runOutOfCard() != 0 || player4.runOutOfCard() != 0)
            {
                game->stop();
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
            switch (whoTurn)
            {
            case 0:
                if (play.maxCard < 0) {
                    if(player1.three.size() != 0) {
                        play.kindcode = 3;
                    }
                    else if (player1.pair.size() != 0) {
                        play.kindcode = 2;
                    }
                    else {
                        play.kindcode = 1;
                    }
                }
                play = player1.playCardAI(play, whoTurn, passNum);
                player1.popOut();
                isPlayed = true;
                break;
            case 1:
                if (play.maxCard < 0) {
                    if(player2.three.size() != 0) {
                        play.kindcode = 3;
                    }
                    else if (player2.pair.size() != 0) {
                        play.kindcode = 2;
                    }
                    else {
                        play.kindcode = 1;
                    }
                }

                play = player2.playCardAI(play, whoTurn, passNum);
                player2.popOut();
                isPlayed = true;
                break;
            case 2:
                if (play.maxCard < 0) {
                    if(player3.three.size() != 0) {
                        play.kindcode = 3;
                    }
                    else if (player3.pair.size() != 0) {
                        play.kindcode = 2;
                    }
                    else {
                        play.kindcode = 1;
                    }
                }
        
                play = player3.playCardAI(play, whoTurn, passNum);
                player3.popOut();
                isPlayed = true;
                break;
            }
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
            cout << "whoTurn of the last " << whoTurn << endl;
            if (whoTurn == 3)
            {
                player4.checkEvent(event);
                int type = player4.isPlayedCard(play, event, playButton.isClicked(event, 2), passButton.isClicked(event, 2));
                cout << "type of player " << type << endl;
                if (type == 1)
                {
                    play = player4.playerPlayCard(play, event, passNum);
                    player4.popOut();
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
        if (isPlayed)
        {
            whoTurn = (whoTurn + 1) % 4;
        }
        // cout << whoTurn << "'s turn " << endl;

        player1.printCard();
        player2.printCard();
        player3.printCard();
        player4.printCard();

        SDL_RenderPresent(Game::renderer);
        SDL_RenderClear(Game::renderer);
        // game->update();
        // game->render(d);
        // frameTime = SDL_GetTicks() - frameStart;
        // if (frameDelay > frameTime)
        // {
        //     SDL_Delay(frameDelay - frameTime);
        // }
    }

    game->clean();

    return 0;
}

