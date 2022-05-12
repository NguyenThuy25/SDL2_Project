#include "Character.h"
#include"Game.h"
#include<iostream>

Character::Character() {

}
Character::Character(int _indexOfPlayer, DeckOfCards& _deck) {
    indexOfPlayer = _indexOfPlayer;
    for(int i=0; i<10; i++) {
        Card tmp = _deck.getCard();
        tmp.setPos(xpos[indexOfPlayer][i], ypos[indexOfPlayer][i]);
        tmp.path = cardGraphics[tmp.value];
        hand.push_back(tmp);
        
    }
}

void Character::printCard() {
    for(Card c : hand) {
        c.Render();
    }
    
}
void Character::checkEvent(SDL_Event e) {
        for(int i=0; i<hand.size(); i++) {
            if(hand[i].isClicked(e)) hand[i].up();
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


/*
#include "Character.h"
#include<iostream>
Character::Character() {

}
Character::Character(int _index, DeckOfCards _deck) {
    index = _index;
    for(int i=0; i<10; i++) {
        Card tmp = _deck.getCard();
        // std::cout << tmp.value << " ";
        tmp.setPos(xpos[index][i], ypos[index][i]);
        hand.push_back(tmp);
    }
}

void Character::printCard() {
    // for(Card c : hand) {
    //     c.Render();
    //     std::cout << c.x << " ";
    // }
    for(int i=0; i<10; i++) {
        hand[i].Render();
        // std::cout << hand[i].x << " ";
    }
    
}

Character::~Character() {
    
}

*/