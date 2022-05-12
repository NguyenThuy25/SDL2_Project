#include "Card.h"
#include "Game.h"

Card::Card(std::string texturesheet, int x, int y, int value) : GameObject(texturesheet, x, y) {
    this->value = value;
}


Card::~Card() {

}