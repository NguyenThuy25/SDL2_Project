#include <vector>
// #include "Card.h"
#include "Three.h"
using namespace std;

Three::Three(Card &a, Card &b, Card &c){
    if((a.value / 4 == b.value / 4) && (b.value / 4 == c.value / 4))
    {
        t[0] = &a;
        t[1] = &b;
        t[2] = &c;
	}
	else
    {
        cout<<"Invalid three";
    }
    int n = -1;
	for(int i=0;i<3;i++){
        if(t[i]->value>n){
        n=t[i]->value;
        maxCard=t[i];
        }
    }
}
Three::Three(){}

int Three::CompareThree(Three A,Three B){
	if((A.maxCard->value)>(B.maxCard->value))
		return 1;
	else if((A.maxCard->value)<(B.maxCard->value))
		return 0;
	else
		return -1;
}
