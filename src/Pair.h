#ifndef PAIR_H
#define PAIR_H

#include "Card.h"
using namespace std;

class Pair
{
	public:
	Card *p1=NULL;
	Card *p2=NULL;
	Card *maxCard=NULL;
	Card *minCard=NULL;
    Pair();//constructor with no parameter
	Pair(Card& p1,Card& p2);//contructor's function: let p1,p2 point to the parameter's reference, find the
                        //max card, assign to maxCard.
	
	int comparePair(Pair ,Pair);//compare 2 pair.maxCard.value, if former is bigger, return 1 , if latter
                                //is bigger, return 0. And if the same, return (error message) -1
    static const int kindcode=2;
};
#endif