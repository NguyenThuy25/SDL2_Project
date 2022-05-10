#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include "GameObject.h"
#include "Card.h"
#include <vector>
#include "DeckOfCards.h"
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
    int indexOfPlayer; // 0->bot1 1->bot2 2->bot3 3->player
    Character();
    Character(int _indexOfPlayer, DeckOfCards &_deck);
    void printCard();
    void checkEvent(SDL_Event e);
    void sort();
    // void waitUntilMouseClicked()
    // {
    //     SDL_Event e;
    //     while (true)
    //     {
    //         if (SDL_WaitEvent(&e) != 0 && (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_QUIT))
    //             return;
    //         SDL_Delay(100);
    //     }
    // }

    int isPlayedCard(int preValue, SDL_Event event, bool playButtonIsClicked, bool passButtonIsClicked) {
        bool isCardIsClicked = false;
        bool valid = false;
        // if(playButtonIsClicked) cout << "play Button is Clicked !!!!" << endl;
        for (int i = 0; i < hand.size(); i++)
        {
            if (hand[i].isSelected())
            {
                // cout << "Card is clicked \n";
                isCardIsClicked = true;
                if(hand[i].value/4 > preValue/4) valid = true;
                break;
            }
        }
        if(isCardIsClicked) {
            if(playButtonIsClicked) {
                if(valid) {
                    return 1;
                } else {
                    return 2;
                }
            } 
            if(passButtonIsClicked) return 3;
            return 0;
        } 
        if(passButtonIsClicked) return 3;
        return -1;
    }

    int playerPlayCard(int preValue, SDL_Event event)
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
                playedCard3.RenderButton(400,500, 150, 200);
                value = hand[i].value;
                hand.erase(hand.begin() + i);
                cout << "player play card " << value << endl;
                break;
            }
        }

        return value;
    }
    int botPlayCard(int preValue, int& whoTurn, int& passNum)
    {
        int value = preValue;
        bool justPlayed = false;
        cout << "preValue" << preValue << endl;
        for (int i = 0; i < hand.size(); i++)
        {
            if (hand[i].value/4 > preValue/4)
            {
                Card botPlayedCard(hand[i].path);
                switch (indexOfPlayer)
                {
                case 0:
                    cout << "bot0 play card " << hand[i].value << endl; 
                    botPlayedCard.RenderButton(200, 300, 150, 200);
                    // if (hand.size() != 0)
                    // {
                        justPlayed = true;
                        passNum = 0;
                        value = hand[i].value;
                        hand.erase(hand.begin() + i);
                    // }
                    break;
                case 1:
                    cout << "bot1 play card " << hand[i].value << endl; 
                    botPlayedCard.RenderButton(500, 200, 150, 200);
                    // if (hand.size() != 0)
                    // {
                        justPlayed = true;
                        passNum = 0;
                        value = hand[i].value;
                        hand.erase(hand.begin() + i);
                    // }
                    break;
                case 2:
                    cout << "bot2 play card " << hand[i].value << endl; 
                    botPlayedCard.RenderButton(800, 300, 150, 200);
                    // if (hand.size() != 0)
                    // {
                        justPlayed = true;
                        passNum = 0;
                        value = hand[i].value;
                        hand.erase(hand.begin() + i);
                    // }
                    break;
                default:
                    break;
                }
                // cout << "Bot play card " << value << endl;
            }
            if(justPlayed) break;
        }
        
        if (value == preValue)
        {
            passNum++;
            cout << "Pass "  << passNum << endl;
            if (passNum == 3) {
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