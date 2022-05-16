#ifndef THREE_H
#define THREE_H

// #include <iostream>
// #include <string>
// #include "Card.h"
// #include <vector>
using namespace std;

class Three{
	public:
	Card* t[3]={NULL,NULL,NULL};
	Card *maxCard=NULL;
	// Card *minCard=NULL;
	Three(Card& ,Card& ,Card& );
	Three();
	int CompareThree(Three ,Three ); // 1-> A>B, 2-> A<B, -1->A==B
    static const int kindcode=3;
};
#endif // THREE_H
