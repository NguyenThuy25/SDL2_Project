#include "Pair.h"
using namespace std;

Pair::Pair(){
	// Card a;
	// Card b;
	// p1=&a;
	// p2=&b;
}

Pair::Pair(Card& a,Card& b)
{
	if(a.value - b.value < 4)
    {
        p1=&a;
        p2=&b;
	}
	else
    {
        cout<<"Invalid pair";
    }
	if(p1->value > p2->value) {
        maxCard = p1;
        minCard = p2;
    } else {
        maxCard = p2;
        minCard = p1;
    }
}
//contructor of the class: Pair
//Find the max card and assign it to maxCard
//The constructor when no inputs received

int Pair::comparePair(Pair A,Pair B){

	if((A.maxCard->value)>(B.maxCard->value))
	return 1;
	else if((A.maxCard->value)<(B.maxCard->value))
	return 0;
	else
	return -1;
}
//compare two "pair.maxCard.value"
//If the former is bigger , return 1 , if latter is bigger , then return 0.
//And if the values are the same , return (error message) -1.

// void Pair::swap(Pair& a,Pair& b)
// {
//     Pair tmp;
//     tmp=a;
//     a=b;
//     b=tmp;
// }
