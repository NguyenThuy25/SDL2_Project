#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include "GameObject.h"
#include "Card.h"
#include <vector>
#include "DeckOfCards.h"
#include "Pair.h"
#include "Play.h"
using namespace std;

class Character : public GameObject
{
private:
    int xpos[4][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {150, 200, 250, 300, 350, 400, 450, 500, 550, 600},
        {1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200},
        {200, 270, 340, 410, 480, 550, 620, 690, 760, 830}};

    int ypos[4][10] = {
        {50, 90, 130, 170, 210, 250, 290, 330, 370, 410},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {100, 140, 180, 220, 260, 300, 340, 380, 420, 460},
        {700, 700, 700, 700, 700, 700, 700, 700, 700, 700}};

public:
    // std::vector<Card*> hand;
    // int pass;
    vector<Card> hand;
    vector<Pair> pair;
    int indexOfPlayer; // 0->bot1 1->bot2 2->bot3 3->player
    Character();
    Character(int _indexOfPlayer, DeckOfCards &_deck);
    void printCard();
    void checkEvent(SDL_Event e);
    void sort();
    void putPair() {
        pair.clear();
        for(int i=0; i<hand.size()-1; i++) {
            if(hand[i].value/4 == hand[i+1].value/4) {
                hand[i].choosen = true;
                hand[i+1].choosen = true;
                Pair tmp(hand[i], hand[i+1]);
                pair.push_back(tmp);
            }
        }
    }

    int isPlayedCard(int preValue, SDL_Event event, bool playButtonIsClicked, bool passButtonIsClicked)
    {
        bool isCardIsClicked = false;
        bool valid = false;
        for (int i = 0; i < hand.size(); i++)
        {
            if (hand[i].isSelected())
            {
                isCardIsClicked = true;
                if (hand[i].value / 4 > preValue / 4)
                    valid = true;
                break;
            }
        }
        if (isCardIsClicked)
        {
            if (playButtonIsClicked)
            {
                if (valid)
                {
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
            if (passButtonIsClicked)
                return 3;
            return 0;
        }
        if (passButtonIsClicked)
            return 3;
        return -1;
    }

    int playerPlayCard(int preValue, SDL_Event event, int &passNum)
    {
        // cout<< "playerPlayCard is running";
        int value = preValue;
        // cout << hand.size();
        for (int i = 0; i < hand.size(); i++)
        {
            if (hand[i].isSelected())
            {
                Card playedCard3(hand[i].path);
                // SDL_Delay(100);
                playedCard3.RenderButton(400, 500, 150, 200);
                value = hand[i].value;
                hand.erase(hand.begin() + i);
                cout << "player play card " << value << endl;

                break;
            }
        }

        return value;
    }
    void eraseByValue(int value) {
        for(int i=0; i<hand.size(); i++) {
            if(hand[i].value == value) {
                hand.erase(hand.begin()+i);
            }
        }
    }
    int botPlaySingleCard(int preValue, int &whoTurn, int &passNum)
    {
        int value = preValue;
        bool justPlayed = false;
        cout << "preValue" << preValue << endl;
        cout << "Bot " << whoTurn << " play card ";
        for (int i = 0; i < hand.size(); i++)
        {
            if ((hand[i].value / 4) > (preValue / 4))
            {
                Card botPlayedCard(hand[i].path);
                cout << hand[i].value << endl;
                // switch (indexOfPlayer)
                switch (whoTurn)
                {
                case 0:
                    botPlayedCard.RenderButton(200, 300, 150, 200);
                    break;
                case 1: 
                    botPlayedCard.RenderButton(500, 200, 150, 200);
                    break;
                case 2:
                    botPlayedCard.RenderButton(800, 300, 150, 200);
                default:
                    break;
                }
                
                SDL_Delay(200);
                justPlayed = true;
                passNum = 0;
                value = hand[i].value;
                hand.erase(hand.begin() + i);
            }
            if(justPlayed) break;
        }

            // if (value == preValue)
            if (justPlayed == false)
            {
                passNum++;
                cout << "Pass " << passNum << endl;
                if (passNum == 3)
                {
                    // whoTurn = (whoTurn + 1)%4;
                    value = -5;
                }
                if (passNum > 3)
                    passNum = 1;
                // else
                // passNum++;
            }
            return value;
        }

    
    Pair botPlayPair(Pair prev, int& whoTurn, int& passNum) {
        Pair value = prev;
        // int value = prev.maxCard->value;
        bool justPlayed = false;
        // cout << "preValue" << preValue << endl;
        cout << "Bot " << whoTurn << " play pair " << endl;
        for (int i = 0; i < pair.size(); i++)
        {
            if ((pair[i].p1->value) - (prev.p2->value) > 1)
            {
                Card botPlayedPair1(pair[i].p1->path);
                Card botPlayedPair2(pair[i].p2->path);
                cout << pair[i].p1->value << " + " << pair[i].p2->value << endl;
                // switch (indexOfPlayer)
                switch (whoTurn)
                {
                case 0:
                    botPlayedPair1.RenderButton(200, 300, 150, 200);
                    botPlayedPair2.RenderButton(250, 300, 150, 200);
                    break;
                case 1: 
                    botPlayedPair1.RenderButton(500, 200, 150, 200);
                    botPlayedPair2.RenderButton(550, 200, 150, 200);
                    break;
                case 2:
                    botPlayedPair1.RenderButton(800, 300, 150, 200);
                    botPlayedPair2.RenderButton(850, 300, 150, 200);
                default:
                    break;
                }
                
                SDL_Delay(300);
                justPlayed = true;
                passNum = 0;
                Pair tmp(*(pair[i].p1), *(pair[i].p2));
                value = tmp;
                // cout << "Pair tmp " << tmp.p1->value << " " << tmp.p2->value << endl;
                // value = hand[i].value;
                pair.erase(pair.begin() + i);
                
                eraseByValue(pair[i].p1->value);
                eraseByValue(pair[i].p2->value);
            }
            if(justPlayed) break;
        }

            // if (value == preValue)
            if (justPlayed == false)
            {
                passNum++;
                cout << "Pass " << passNum << endl;
                if (passNum == 3)
                {
                    // whoTurn = (whoTurn + 1)%4;
                    value.p1->value = -5;
                    value.p2->value = -5;
                }
                if (passNum > 3)
                    passNum = 1;
                // else
                // passNum++;
            }
            return value;
    }

// add function
    void classify() {
        putPair();
    }
    // Play playCardAI(Play in) {
    //     classify();
    //     switch(in.kindcode) {
    //         case 1: // If the card last player play Single 
    //         {
                
    //         }
    //     }
    // }



        bool runOutOfCard()
        {
            if (hand.size() == 0)
                return true;
            else
                return false;
        }
        ~Character();
    };
#endif // CHARACTER_H