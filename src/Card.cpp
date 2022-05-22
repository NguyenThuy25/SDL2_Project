#include "Card.h"
// #include "Game.h"

Card::Card(){}
Card::Card(string path) : GameObject(path, 0, 0) {}

void Card::setPath(std::string _path) {
		path = _path;
}

Card::Card(std::string texturesheet, int x, int y, int value) : GameObject(texturesheet, x, y) {
    this->value = value;
}

void Card::up(){
		if(!isUp) {
			destRect.y -= 15;
			isUp = true;
		}
		else {
			destRect.y += 15;
			isUp = false;
		}
	}

bool Card::isSelected() {
		return isUp;
	}
    
Card::~Card() {}