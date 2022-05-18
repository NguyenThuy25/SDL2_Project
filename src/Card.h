#pragma once
#ifndef CARD_H
#define CARD_H
#include "GameObject.h"
#include <string>
#include <iostream>

class Card : public GameObject {

public:
	int value;
	std::string path;
	// std::string texturesheet;
	bool isUp = false, goStraight = false, choosen = false;
	Card(){}
	Card(string path) : GameObject(path, 0, 0) {
	}
	Card(string texturesheet, int x, int y, int value);
	// void setPath(std::string* _path);
	void up(){
		if(!isUp) {
			destRect.y -= 15;
			isUp = true;
		}
		else {
			destRect.y += 15;
			isUp = false;
		}
	}

	bool isSelected() {
		return isUp;
	}
	
	void moveUp() {
		while(destRect.y > 300) {
			destRect.y -= 5;
		}
		// SDL_Delay(10);
	}
	
	void moveDown() {
		while(destRect.y < 300) {
			destRect.y += 1;
		}
	}

	void moveRight() {
		while(destRect.x < 300) {
			destRect.x += 1;
		}
	}

	void moveLeft() {
		while(destRect.x > 500) {
			destRect.x -= 1;
		}
	}
	
	~Card();
	// GameObject* card;

};

#endif // CARD_H