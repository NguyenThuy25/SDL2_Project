#include "DeckOfCards.h"
#include <time.h>

using namespace std;

#define DECK_SIZE 53

DeckOfCards::DeckOfCards() {
    for(int i = 0; i < DECK_SIZE-1; i++) {
        Card t(cardGraphics[i]);
        t.value = i;
        t.choosen=false;
        deck.push_back(t);
    }
    
}


void DeckOfCards::shuffle() {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE-1; i++) {
        int random = rand() % (DECK_SIZE - i - 1) + i;
        Card tmp = deck[i];
        deck[i] = deck[random];
        deck[random] = tmp;
    }
}


Card DeckOfCards::getCard(){
    // cout << deck.size() << endl;
    Card tmp = deck.back();
    deck.pop_back();
    return tmp;
}



DeckOfCards::~DeckOfCards() {

}





