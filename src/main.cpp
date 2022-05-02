#include "DeckOfCards.h"
#include "Game.h"
#include "Character.h"

Game* game = nullptr;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event event;

int main(int argc, char* argv[]) {

    game = new Game();
    game->init("BIG TWO GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 840, false);
    
    DeckOfCards deckOfCard;
    deckOfCard.shuffle();
    vector<Character> character;
    Character player1(0, deckOfCard); //  tay
    player1.sort();
    Character player2(1, deckOfCard); //  bac
    player2.sort();
    Character player3(2, deckOfCard); // dong
    player3.sort();
    Character player4(3, deckOfCard); // nam
    player4.sort();
    character.push_back(player1);
    character.push_back(player2);
    character.push_back(player3);
    character.push_back(player4);

    int whoTurn = game->whoPlayFirst();
    character[0].playFirstCard();
    // SDL_Delay(100);
    while (game->running()) {
        
        // game->handleEvents(event) ;
        GameObject playButton("res/go.png", 150, 150);
        playButton.RenderButton(500, 500, 200, 70);
        
        while (SDL_PollEvent(&event) != 0) {
        switch (event.type)
        {
        case SDL_QUIT:
            game->stop();
            break;
        default:
            break;
        }
        player4.checkEvent(event);
    }
        player1.printCard();
        player2.printCard();
        player3.printCard();
        player4.printCard();
        
        

        SDL_RenderPresent(Game::renderer);
        SDL_RenderClear(Game::renderer);
        // game->update();
        // game->render(d);

        // while(!player1.runOutOfCard() && !player1.runOutOfCard() && !player1.runOutOfCard() && !player1.runOutOfCard()) {

        // }

    }
    
    game->clean();

    return 0;
}

