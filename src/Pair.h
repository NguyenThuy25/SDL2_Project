#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include "Card.h"
// #include <vector>
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
    // void swap(Pair&,Pair&);
    static const int kindcode=2;
};
#endif