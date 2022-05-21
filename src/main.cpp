#include <iostream>
#include "Game.h"
#include "Character.h"
#include "Texture.h"
using namespace std;

Game *game = nullptr;
SDL_Renderer *Game::renderer = nullptr;
SDL_Event event;
int passNum = 0;
int whoWin = -1;
Play play;


int main(int argc, char *argv[])
{

    game = new Game();
    game->init("CARD GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 840, false);

    DeckOfCards deckOfCard;
    deckOfCard.shuffle();
    vector<Character> character;
    character.push_back(Character(0, deckOfCard));
    character.push_back(Character(1, deckOfCard));
    character.push_back(Character(2, deckOfCard));
    character.push_back(Character(3, deckOfCard));

    for (int i = 0; i < 4; i++)
    {
        character[i].sort();
        character[i].putStraightThree();
        character[i].putThree();
        character[i].putPair();
    }

    int whoTurn = game->whoPlayFirst();
    cout << whoTurn << " play first" << endl;
    play.maxCard = -5;
    GameObject playButton("res/go.png", 150, 150);
    GameObject passButton("res/pass.png", 200, 200);
    GameObject arrow("res/arrow.png", 600, 400);
    GameObject menuBackground("res/bghuhu.png", 0, 0);
    GameObject startButton1("res/startButton1.png", 200, 200);
    GameObject startButton2("res/startButton2.png", 200, 200);
    GameObject inGameBg("res/inGamebg.png", 0, 0);
    GameObject table("res/table.png", 400, 400);
    // Texture wait;
    // wait.waitUntilKeyPressed();
    while (game->running())
    {
        bool out = false;
        SDL_SetRenderDrawColor(Game::renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(Game::renderer);
        menuBackground.RenderButton(0, 0, 1280, 840, 0, false);
        startButton1.RenderButton(900, 600, 128, 136, 0, false);
        SDL_RenderPresent(Game::renderer);
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                game->stop();
                break;
            }
            if (startButton1.isClicked(event, 2))
            {
                out = true;
            }
        }
        if (out)
            break;
    }

    while (game->running())
    {
        // check if any player is win (run out of card)
        for (int i = 0; i < 4; i++)
        {
            if (character[i].runOutOfCard() != 0)
            {
                cout << "player " << i << " win!" << endl;
                // whoWin = i;
                
                // whoWin.setAlpha(255);
                SDL_Color textColor = {255, 255, 255};
                Texture whoWinText;
                whoWinText.setBlendMode(SDL_BLENDMODE_BLEND);
                string str;
                if(i==3) {
                    str = "You Win!";
                } else if(i==0) str = "Player 1 win!";
                else if(i==1) str = "Player 2 win!";
                else if(i==2) str = "Player 3 win!";
                whoWinText.loadFromRenderedText(str, textColor);
                whoWinText.render(650, 550);
            game->stop();
            
            }
            
        }
        
        
        // game->handleEvents(event) ;
        // menuBackground.RenderButton(0, 0, 1280, 840, 0);

        // startButton.RenderButton(200, 200, 50, 50, 0);
        inGameBg.RenderButton(0, 0, 1280, 840, 0, true);
        table.RenderButton(150, 180, 1000, 500, 0, true);
        playButton.RenderButton(1000, 670, 200, 70, 0, false);
        passButton.RenderButton(1000, 750, 200, 70, 0, false);
        
        // playButton.LoadTexture("res/arrow.png");

        bool isPlayed = false;
        if (whoTurn != 3)
        {
            if (whoTurn == 0)
            {
                arrow.RenderArrow(90);
            }
            else if (whoTurn == 1)
            {
                arrow.RenderArrow(180);
            }
            else
            {
                arrow.RenderArrow(270);
            }
            if (play.maxCard < 0)
            {
                if (character[whoTurn].straightThree.size() != 0)
                {
                    play.kindcode = 5;
                }
                else if (character[whoTurn].three.size() != 0)
                {
                    play.kindcode = 3;
                }
                else if (character[whoTurn].pair.size() != 0)
                {
                    play.kindcode = 2;
                }
                else
                {
                    play.kindcode = 1;
                }
            }
            cout << "play.kindcode =" << play.kindcode << endl;
            play = character[whoTurn].playCardAI(play, whoTurn, passNum);
            // turnCount++;
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
                // while(whoTurn == 3) {
                arrow.RenderArrow(0);
                // }

                // arrow.RenderButton(400, 400, 100, 100, 0);
                int type = character[3].isPlayedCard(play, event, playButton.isClicked(event, 2), passButton.isClicked(event, 2));
                cout << "type of player " << type << endl;
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

        if (isPlayed)
        {
            whoTurn = (whoTurn + 1) % 4;
            // turnCount++;
        }
        // game->update();

        game->render(character);

        SDL_RenderPresent(Game::renderer);
        SDL_RenderClear(Game::renderer);
    }
    game->clean();
    return 0;
}
