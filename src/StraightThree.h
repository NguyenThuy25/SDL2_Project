#ifndef STRAIGHTTHREE_H
#define STRAIGHTTHREE_H

// #include <iostream>
// #include <string>
#include "Card.h"
// #include <vector>
using namespace std;

class StraightThree{
	public:
	Card* s[3]={NULL,NULL,NULL};
	Card* maxCard=NULL;
	// Card *minCard=NULL;
	StraightThree(Card& a,Card& b,Card& c);
	StraightThree();
	bool CompareStraightThree(StraightThree a, StraightThree b); // check if a > b
    static const int kindcode=5;
};
#endif // STRAIGHTTHREE_H
