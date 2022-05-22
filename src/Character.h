#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include "GameObject.h"
#include "DeckOfCards.h"
#include "Pair.h"
#include "Three.h"
#include "Play.h"
#include "StraightThree.h"
using namespace std;

class Character : public GameObject
{
private:
    // position of the card
    int xpos[4][10] = {
        {-80, -80, -80, -80, -80, -80, -80, -80, -80, -80},
        {200, 270, 340, 410, 480, 550, 620, 690, 760, 830},
        {1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200},
        {200, 270, 340, 410, 480, 550, 620, 690, 760, 830}};

    int ypos[4][10] = {
        {100, 140, 180, 220, 260, 300, 340, 380, 420, 460},
        {-40, -40, -40, -40, -40, -40, -40, -40, -40, -40},
        {100, 140, 180, 220, 260, 300, 340, 380, 420, 460},
        {700, 700, 700, 700, 700, 700, 700, 700, 700, 700}};

public:
    vector<Card> hand;
    vector<Pair> pair;
    vector<Three> three;
    vector<StraightThree> straightThree;
    int indexOfPlayer; // 0->bot1 1->bot2 2->bot3 3->player
    Character();
    Character(int _indexOfPlayer, DeckOfCards &_deck);
    void printCard();
    void checkEvent(SDL_Event e);
    void sort();
    void putPair();
    void putThree();
    void putStraightThree();
    int nextFace(int a);
    void popOut();
    int isPlayedCard(Play &pre, SDL_Event &event, bool playButtonIsClicked, bool passButtonIsClicked);
    Play playerPlayCard(Play play, SDL_Event event, int &passNum);
    Play playCardAI(Play pre, int &whoTurn, int &passNum);
    bool runOutOfCard();
    ~Character();
};
#endif // CHARACTER_H