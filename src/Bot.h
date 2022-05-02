#ifndef BOT_H
#define BOT_H
#include "Character.h"

class Bot : public Character {
private:
public:
    Bot();
    
    Card play(Card& pre) {
        int played;
        for(int i=0; i<hand.size(); i++) {
            if(hand[i].value - pre.value >=4) {
                
                hand.erase(hand.begin()+i);
                played = i;
                break;

            }
        }
        return hand[played];
    }
    // Bot(std::vector<Card*> handx);
    ~Bot();

};

#endif // BOT_H