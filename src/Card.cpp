#include "Card.h"
#include "Game.h"

Card::Card(std::string texturesheet, int x, int y, int value) : GameObject(texturesheet, x, y) {
    this->value = value;
}


Card::~Card() {

}







/*
#include "Card.h"
#include <iostream>
#include <string.h>
using namespace std;

Card::Card(int a, int b) {
    face = a;
    suit = b;
    value = 4*(face-1)+suit;
    chosen = 0;
}

void Card::setFace(int a) {
    face = a;
}

void Card::setSuit(int b) {
    suit = b;
}

int Card::getFace() {
    return face;
}

int Card::getSuit() {
    return suit;
}

string Card::faceString[]={"none", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2"};
string Card::suitString[]={"none", "Clubs", "Diamonds", "Hearts", "Spades"};

string Card::toString() {
    string tmp = faceString[face] + " of " + suitString[suit];
    return tmp;
}
*/