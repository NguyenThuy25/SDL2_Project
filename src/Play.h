#ifndef PLAY_H
#define PLAY_H

// #include <iostream>
// #include <string>
// #include "Character.h"
#include "Pair.h"
// #include "Single.h"
// #include "Three.h"
// #include "Four.h"
// #include "Straight.h"
#include <vector>
using namespace std;

class Play {
	public:
        int maxCard;
        int kindcode;
        Play();
        // Play(Single);
        Play(Pair);
        // Play(Three,Pair);
        // Play(Four,Single);
        Play(int,int);
        // Play(Straight);
        // Play(Straight,int);
};
#endif // PLAY_H