#include <vector>
#include "Card.h"
#include "StraightThree.h"
using namespace std;

StraightThree::StraightThree(Card& a, Card& b, Card& c){
    // don't need to check cuz putStraightThree already does that
    if((a.value / 4 == b.value / 4 - 1) && (b.value / 4 == c.value / 4 - 1))
    {
        s[0] = &a;
        s[1] = &b;
        s[2] = &c;
	}
	else
    {
        cout<<"Invalid three";
    }
    int n = -1;
	for(int i=0;i<3;i++){
        if(s[i]->value > n){
        n=s[i]->value;
        maxCard=s[i];
        }
    }
}
StraightThree::StraightThree(){
}

bool StraightThree::CompareStraightThree(StraightThree a, StraightThree b) {
    if((a.maxCard->value / 4) > (b.maxCard->value / 4)) {
        return 1;
    } else return 0;
}