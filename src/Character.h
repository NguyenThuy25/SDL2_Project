#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include "GameObject.h"
#include "Card.h"
#include<vector>
#include "DeckOfCards.h"
using namespace std;

class Character : public GameObject{
private:
int xpos[4][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {150, 200, 250, 300, 350, 400, 450, 500, 550, 600},
    {1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200},
    {200, 270, 340, 410, 480, 550, 620, 690, 760, 830}
};

int ypos[4][10] = {
    {50, 90, 130, 170, 210, 250, 290, 330, 370, 410},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {100, 140, 180, 220, 260, 300, 340, 380, 420, 460},
    {700, 700, 700, 700, 700, 700, 700, 700, 700, 700}
};
public:
    // std::vector<Card*> hand;
    vector<Card> hand;
    int indexOfPlayer; // 0->bot1 1->bot2 2->bot3 3->player
    // 
    // Moi character co 1 set card
    Character();
    Character(int _indexOfPlayer, DeckOfCards& _deck);
    void printCard();
    void checkEvent(SDL_Event e);
    void sort();
    int playCard(int preValue) {
        for(int i=0; i<hand.size(); i++) {
            if(hand[i].value - preValue >= 4) {
                return i;
                break;
            }
        }
        return -1;
    }
    void botPlayFirstCard() {
        
        Card playedCard0(hand[0].path);
        Card playedCard1(hand[0].path);
        Card playedCard2(hand[0].path);

        // GameObject playedCard1(hand[0].path, 300, 300);
        switch (indexOfPlayer)
        {
        // case 3:
        //     playedCard3.RenderButton(300, 300, 150, 200);
        //     cout << "player3's turn" << endl;
        //     if(hand.size() != 0) hand.erase(hand.begin());
        //     break;
        case 0:
            playedCard0.RenderButton(400, 300, 150, 200);
            cout << "player0's turn"<< endl;
            // if(hand.size() != 9) hand.erase(hand.begin());
            break;
        case 1: 
            playedCard1.RenderButton(300, 300, 150, 200);
            cout << "player1's turn"<< endl;
            if(hand.size() != 0) hand.erase(hand.begin());
            break;
        case 2:
            playedCard2.RenderButton(300, 300, 150, 200);
            cout << "player2's turn"<< endl;
            if(hand.size() != 0) hand.erase(hand.begin());
        default:
            break;
        }        
    }
    bool runOutOfCard() {
        if(hand.size() == 0) return true;
        else return false;
    }
    ~Character();

};
#endif // CHARACTER_H