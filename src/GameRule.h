#ifndef GAMERULE_H
#define GAMERULE_H

#include "Character.h"

class GameRule : public Character {
public:
    int numOfPlayerLeft;

    int whoPlayFirst() {
        return rand()%4;
    }

    

};

#endif // GAMERULE_H