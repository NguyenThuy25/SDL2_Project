#include <iostream>
#include "Game.h"
#include "Player.h"
using namespace std;

Game *game = nullptr;
SDL_Renderer *Game::renderer = nullptr;
SDL_Event event;
int passNum = 0;
Play play;

int main(int argc, char *argv[])
{
    game = new Game();
    game->init("CARD GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 840, false);
    // init deck of cards, character, shuffle, handcard and put in type
    DeckOfCards deckOfCards;
    vector<Character> character;
    game->handCard(deckOfCards, character);

    int whoTurn = game->whoPlayFirst();

    play.maxCard = -5; // the first player can play any card
    GameObject playButton("res/go.png", 150, 150);
    GameObject passButton("res/pass.png", 200, 200);
    GameObject arrow("res/arrow.png", 600, 400);

    game->renderMenu(event); // render menu and check if user press x or start

    while (game->running())
    {
        Texture whoWinText(Game::renderer);
        game->isOver(character, whoWinText);        // check if anyone is win and render winning text
        game->renderInGame(playButton, passButton); // render background, playButton, passButton
        bool isPlayed = false;
        botPlayCard(whoTurn, play, character, passNum, isPlayed, arrow); // render arrow and deal with kindCode (5->3->2->1)
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
            int type = character[3].isPlayedCard(play, event, playButton.isClicked(event, 2), passButton.isClicked(event, 2)); // handle user's input and check valid
            if (whoTurn == 3)
            {
                character[3].checkEvent(event);
                arrow.RenderArrow(0);
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
                    {
                        passNum = 1;
                    }
                }
            }
            // userPlayCard(whoTurn, character, event, play, playButton, passButton, passNum, isPlayed, type, arrow);
        }
        if (isPlayed)
        {
            whoTurn = (whoTurn + 1) % 4; // next turn
        }
        game->render(character);
    }
    game->clean();
    return 0;
}
