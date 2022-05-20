#include "Character.h"
#include"Game.h"
#include<iostream>

Character::Character() {

}
Character::Character(int _indexOfPlayer, DeckOfCards& _deck) {
    indexOfPlayer = _indexOfPlayer;
    if(indexOfPlayer != 3) {
        for(int i=0; i<10; i++) {
        Card tmp1 = _deck.getCard();
        Card tmp2(cardGraphics[52]);
        tmp2.setPos(xpos[indexOfPlayer][i], ypos[indexOfPlayer][i]);
        // tmp.path = cardGraphics[tmp.value];
        tmp2.value = tmp1.value;
        hand.push_back(tmp2);
    }
    } else {
        for(int i=0; i<10; i++) {
        Card tmp = _deck.getCard();
        tmp.setPos(xpos[indexOfPlayer][i], ypos[indexOfPlayer][i]);
        tmp.path = cardGraphics[tmp.value];
        hand.push_back(tmp);
    }
    
}
}

void Character::printCard() {
    // if(indexOfPlayer != 3) {

    // }
    for(Card c : hand) {
        c.Render();
    }
    
}

// void Character::printCardback() {

// }
void Character::checkEvent(SDL_Event e) {
        for(int i=0; i<hand.size(); i++) {
            if(hand[i].isClicked(e, 1)) hand[i].up();
        }
    }
void Character::sort() {
    for(int i=0; i<hand.size()-1; i++) {
        for(int j=i+1; j<hand.size(); j++) {
            if(hand[i].value > hand[j].value) {
                Card tmp = hand[i];
                hand[i] = hand[j];
                hand[j] = tmp;
                hand[i].setPos(xpos[indexOfPlayer][i], ypos[indexOfPlayer][i]);
                hand[j].setPos(xpos[indexOfPlayer][j], ypos[indexOfPlayer][j]);
            }
        }
    }
    for(int i=0; i<hand.size(); i++) {
        std::cout << hand[i].value << " ";
    }
}

Character::~Character() {
    
}

