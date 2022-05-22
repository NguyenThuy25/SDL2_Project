#ifndef PLAY_H
#define PLAY_H

#include "Pair.h"
using namespace std;

class Play {
	public:
        int maxCard;
        int kindcode; // 1->single, 2->pair, 3->three, 5->straightThree
        Play();
        Play(Pair);
};
#endif // PLAY_H
