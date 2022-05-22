#include "Pair.h"
using namespace std;

Pair::Pair(){}

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

int Pair::comparePair(Pair A,Pair B){

	if((A.maxCard->value)>(B.maxCard->value))
	return 1;
	else if((A.maxCard->value)<(B.maxCard->value))
	return 0;
	else
	return -1;
}

