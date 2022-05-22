#ifndef CARD_H
#define CARD_H
#include "GameObject.h"

class Card : public GameObject {

public:
	int value;
	std::string path;
	bool isUp = false, choosen = false;

	Card();
	Card(string path);
	void setPath(std::string _path);
	Card(string texturesheet, int x, int y, int value);
	void up();
	bool isSelected();
	~Card();
};

#endif // CARD_H