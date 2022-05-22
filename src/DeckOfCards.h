#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Card.h"
#include<vector>

using namespace std;
const string cardGraphics[53] = 
    {
        "res/cardSpades3.png", "res/cardClubs3.png", "res/cardDiamonds3.png", "res/cardHearts3.png",
        "res/cardSpades4.png", "res/cardClubs4.png", "res/cardDiamonds4.png", "res/cardHearts4.png",
        "res/cardSpades5.png", "res/cardClubs5.png", "res/cardDiamonds5.png", "res/cardHearts5.png",
        "res/cardSpades6.png", "res/cardClubs6.png", "res/cardDiamonds6.png", "res/cardHearts6.png",
        "res/cardSpades7.png", "res/cardClubs7.png", "res/cardDiamonds7.png", "res/cardHearts7.png",
        "res/cardSpades8.png", "res/cardClubs8.png", "res/cardDiamonds8.png", "res/cardHearts8.png",
        "res/cardSpades9.png", "res/cardClubs9.png", "res/cardDiamonds9.png", "res/cardHearts9.png",
        "res/cardSpades10.png", "res/cardClubs10.png", "res/cardDiamonds10.png", "res/cardHearts10.png",
        "res/cardSpadesJ.png", "res/cardClubsJ.png", "res/cardDiamondsJ.png", "res/cardHeartsJ.png",
        "res/cardSpadesQ.png", "res/cardClubsQ.png", "res/cardDiamondsQ.png", "res/cardHeartsQ.png",
        "res/cardSpadesK.png", "res/cardClubsK.png", "res/cardDiamondsK.png", "res/cardHeartsK.png",
        "res/cardSpadesA.png", "res/cardClubsA.png", "res/cardDiamondsA.png", "res/cardHeartsA.png",
        "res/cardSpades2.png", "res/cardClubs2.png", "res/cardDiamonds2.png", "res/cardHearts2.png",
        "res/cardBack_blue3.png"
    }; // 52 first path -> card, the last one -> cardback
class DeckOfCards {
public:
    std::vector<Card> deck;

    DeckOfCards();
    void shuffle();
    Card getCard();
    ~DeckOfCards();
};
#endif // DECKOFCARD_H