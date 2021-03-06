#include "Character.h"
#include"Game.h"
#include<iostream>

Character::Character() {

}
Character::Character(int _indexOfPlayer, DeckOfCards& _deck) {
    indexOfPlayer = _indexOfPlayer;
    if(indexOfPlayer != 3) {
        for(int i=0; i<10; i++) {
        Card tmp1 = _deck.getCard();
        Card tmp2(cardGraphics[52]);
        tmp2.setPos(xpos[indexOfPlayer][i], ypos[indexOfPlayer][i]);
        // tmp.path = cardGraphics[tmp.value];
        tmp2.value = tmp1.value;
        hand.push_back(tmp2);
    }
    } else {
        for(int i=0; i<10; i++) {
        Card tmp = _deck.getCard();
        tmp.setPos(xpos[indexOfPlayer][i], ypos[indexOfPlayer][i]);
        tmp.path = cardGraphics[tmp.value];
        hand.push_back(tmp);
    }
    
}
}

void Character::printCard() {
    // if(indexOfPlayer != 3) {

    // }
    for(Card c : hand) {
        c.Render();
    }
    
}

// void Character::printCardback() {

// }
void Character::checkEvent(SDL_Event e) {
        for(int i=0; i<hand.size(); i++) {
            if(hand[i].isClicked(e, 1)) hand[i].up();
        }
    }
void Character::sort() {
    for(int i=0; i<hand.size()-1; i++) {
        for(int j=i+1; j<hand.size(); j++) {
            if(hand[i].value > hand[j].value) {
                Card tmp = hand[i];
                hand[i] = hand[j];
                hand[j] = tmp;
                hand[i].setPos(xpos[indexOfPlayer][i], ypos[indexOfPlayer][i]);
                hand[j].setPos(xpos[indexOfPlayer][j], ypos[indexOfPlayer][j]);
            }
        }
    }
    for(int i=0; i<hand.size(); i++) {
        std::cout << hand[i].value << " ";
    }
}
void Character::putPair()
    {
        pair.clear();
        for (int i = 0; i < hand.size(); i++)
        {
            hand[i].choosen = false;
        }
        for (int i = 0; i < hand.size() - 1; i++)
        {
            if ((hand[i].value / 4 == hand[i + 1].value / 4) && (hand[i].choosen == false || hand[i + 1].choosen == false))
            {
                hand[i].choosen = true;
                hand[i + 1].choosen = true;
                Pair tmp(hand[i], hand[i + 1]);
                pair.push_back(tmp);
                // cout << "pair: " << hand[i].value << "+" << hand[i + 1].value << endl;
            }
        }
    }

void Character::putThree()
    {
        three.clear();
        for (int i = 0; i < hand.size(); i++)
        {
            hand[i].choosen = false;
        }

        for (int i = 0; i < hand.size() - 3; i++)
        {
            if ((hand[i].value / 4 == hand[i + 1].value / 4) && (hand[i + 1].value / 4 == hand[i + 2].value / 4) && (hand[i].choosen == false || hand[i + 1].choosen == false || (hand[i+2].choosen == false)))
            {
                hand[i].choosen = true;
                hand[i + 1].choosen = true;
                hand[i + 2].choosen = true;
                Three tmp(hand[i], hand[i + 1], hand[i + 2]);
                three.push_back(tmp);
            }
        }
    }
void Character::putStraightThree()
    {
        straightThree.clear();
        for (int i = 0; i < hand.size(); i++)
        {
            hand[i].choosen = false;
        }
        for (int i = 0; i < (hand.size() - 2); i++)
        {
            if (hand.size() < 3)
                break;
            int v1 = i;
            int v2 = nextFace(v1);
            int v3 = nextFace(v2);
            if (v1 >= 0 && v2 > 0 && v3 > 0)
            {
                if ((hand[v1].value / 4 == hand[v2].value / 4 - 1) && (hand[v2].value / 4 == hand[v3].value / 4 - 1) && (hand[v1].choosen == false || hand[v2].choosen == false || hand[v3].choosen == false) && (hand[v3].value / 4!= 12))
                {
                    hand[v1].choosen = true;
                    hand[v2].choosen = true;
                    hand[v3].choosen = true;
                    StraightThree tmp(hand[v1], hand[v2], hand[v3]);
                    straightThree.push_back(tmp);
                    cout << "straightThree: " << hand[v1].value << "+" << hand[v2].value << "+" << hand[v3].value << endl;
                }
            }
        }

    }
int Character::nextFace(int a)
    {
        for (int i = a + 1; i < hand.size(); i++)
        {
            if (hand[i].value / 4 != hand[a].value / 4)
            {
                return i;
            }
        }
        return -1;
    }
void Character::popOut()
    {
        for (int i = 0; i < hand.size(); i++)
        {
            if (hand[i].value == -2)
            {
                // hand[i].isUp = false;
                hand.erase(hand.begin() + i);
                i--;
            }
        }
        // cout << "size of hand" << hand.size() << endl;
        if (hand.size() >= 2)
        {
            putPair();
        }
        if (hand.size() >= 3)
        {
            putStraightThree();
            putThree();
        }
    }

int Character::isPlayedCard(Play &pre, SDL_Event &event, bool playButtonIsClicked, bool passButtonIsClicked)
    {
        cout << "isPlayedCard ";
        if (pre.maxCard < 0) {
            pre.kindcode = 1;
            
            if (hand.size() > 2) {
                for (int i = 0; i < (hand.size() - 2); i++) {
                    if (hand.size() < 3)
                        break;
                    int v1 = i;
                    int v2 = nextFace(v1);
                    int v3 = nextFace(v2);
                    if (v1 >= 0 && v2 > 0 && v3 > 0) {
                        if (hand[v1].isSelected() && hand[v2].isSelected() && hand[v3].isSelected()) {

                            if ((hand[v1].value / 4 == hand[v2].value / 4 - 1) && (hand[v2].value / 4 == hand[v3].value / 4 - 1)) {
                                pre.kindcode = 5;
                                break;
                            }
                        }
                    }
                    if (hand[i].isSelected() && hand[i + 1].isSelected() && hand[i + 2].isSelected())
                    {
                        if ((hand[i].value / 4 == hand[i + 1].value / 4) && (hand[i + 1].value / 4 == hand[i + 2].value / 4)) {
                            pre.kindcode = 3;
                            break;
                        }
                    }
                    if(hand[i].isSelected() && hand[i+1].isSelected() && !hand[i+2].isSelected()) {
                    pre.kindcode = 2;
                    break;
                }
                }
                
            } else if (hand.size() == 2) {
                for(int i=0; i<hand.size(); i++) {
                if(hand[i].isSelected() && hand[i+1].isSelected()) {
                    pre.kindcode = 2;
                }
                }
            }
        }
        // cout << "pre.kindcode =====" << pre.kindcode << endl;
        bool isCardIsClicked = false;
        bool valid = false;

        switch (pre.kindcode)
        {
        case 1:
            for (int i = 0; i < hand.size(); i++)
            {
                if (hand[i].isSelected())
                {
                    isCardIsClicked = true;
                    if (hand[i].value / 4 > pre.maxCard / 4)
                        valid = true;
                    break;
                }
            }
            break;
        case 2:
            for (int i = 0; i < pair.size(); i++)
            {
                if (pair[i].p1->isSelected() && pair[i].p2->isSelected())
                {
                    isCardIsClicked = true;
                    if ((pair[i].p2->value / 4) > (pre.maxCard / 4))
                    {
                        valid = true;
                    }
                    break;
                }
            }
            break;
        case 3:
            for (int i = 0; i < three.size(); i++)
            {
                cout << " three shoud be played";
                if (three[i].t[0]->isSelected() && three[i].t[1]->isSelected() && three[i].t[2]->isSelected())
                {
                    isCardIsClicked = true;

                    if ((three[i].maxCard->value / 4) > (pre.maxCard / 4))
                    {
                        cout << "valid = true" << endl;
                        valid = true;
                    }
                    break;
                }
            }
            break;
        case 5:
            for (int i = 0; i < straightThree.size(); i++)
            {
                
                if (straightThree[i].s[0]->isSelected() && straightThree[i].s[1]->isSelected() && straightThree[i].s[2]->isSelected())
                {
                    isCardIsClicked = true;
                    cout << "isCardIsClicked = true" << endl;
                    if ((straightThree[i].maxCard->value / 4) > (pre.maxCard / 4))
                    {
                        valid = true;
                    }
                    break;
                }
            }
        }

        if (isCardIsClicked)
        {
            if (playButtonIsClicked)
            {
                if (valid)
                {
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
            if (passButtonIsClicked)
                return 3;
            return 0;
        }
        if (passButtonIsClicked)
            return 3;
        return -1;
    }

Play Character::playerPlayCard(Play play, SDL_Event event, int &passNum)
    {
        
        switch (play.kindcode)
        {
        case 1:
            for (int i = 0; i < hand.size(); i++)
            {
                if (hand[i].isSelected())
                {
                    passNum = 0;
                    // Card playedCard3(hand[i].path);
                    Card playedCard3(cardGraphics[hand[i].value]);
                    playedCard3.RenderButton(550, 500, 150, 200, 0, true);
                    play.maxCard = hand[i].value;
                    cout << "player play single card " << hand[i].value << endl;
                    hand[i].value = -2; // every card that have value -2 will be pop out
                    // don't need this but still add to try
                    play.kindcode = 1;
                    break;
                }
            }
            break;
        case 2:
            for (int i = 0; i < pair.size(); i++)
            {
                if (pair[i].p1->isSelected() && pair[i].p2->isSelected())
                {
                    passNum = 0;

                    // Card playedPair1(pair[i].p1->path);
                    // Card playedPair2(pair[i].p2->path);
                    Card playedPair1(cardGraphics[pair[i].p1->value]);
                    Card playedPair2(cardGraphics[pair[i].p2->value]);
                    playedPair1.RenderButton(550, 500, 150, 200, 0, true);
                    playedPair2.RenderButton(600, 500, 150, 200, 0, true);
                    play.maxCard = pair[i].p2->value;

                    // don't need this but still add to try
                    play.kindcode = 2;

                    cout << "player play pair " << pair[i].p1->value << " + " << pair[i].p2->value << endl;
                    pair[i].p1->value = -2;
                    pair[i].p2->value = -2;
                    pair.erase(pair.begin() + i);

                    break;
                }
            }
            break;
        case 3:
            for (int i = 0; i < three.size(); i++)
            {
                if (three[i].t[0]->isSelected() && three[i].t[1]->isSelected() && three[i].t[2]->isSelected())
                {
                    passNum = 0;
                    // Card playedThree1(three[i].t[0]->path);
                    // Card playedThree2(three[i].t[1]->path);
                    // Card playedThree3(three[i].t[2]->path);
                    Card playedThree1(cardGraphics[three[i].t[0]->value]);
                    Card playedThree2(cardGraphics[three[i].t[1]->value]);
                    Card playedThree3(cardGraphics[three[i].t[2]->value]);
                    playedThree1.RenderButton(550, 500, 150, 200, 0, true);
                    playedThree2.RenderButton(600, 500, 150, 200, 0, true);
                    playedThree3.RenderButton(650, 500, 150, 200, 0, true);
                    play.maxCard = three[i].maxCard->value;

                    // don't need this but still add to try
                    play.kindcode = 3;
                    cout << "player plays three " << three[i].t[0]->value << " + " << three[i].t[1]->value << " + " << three[i].t[2]->value << endl;
                    three[i].t[0]->value = -2;
                    three[i].t[1]->value = -2;
                    three[i].t[2]->value = -2;
                    three.erase(three.begin() + i);
                }
            }
        case 5:
            for (int i = 0; i < straightThree.size(); i++)
            {
                if (straightThree[i].s[0]->isSelected() && straightThree[i].s[1]->isSelected() && straightThree[i].s[2]->isSelected())
                {
                    passNum = 0;
                    // Card playedStraightThree1(straightThree[i].s[0]->path);
                    // Card playedStraightThree2(straightThree[i].s[1]->path);
                    // Card playedStraightThree3(straightThree[i].s[2]->path);
                    Card playedStraightThree1(cardGraphics[straightThree[i].s[0]->value]);
                    Card playedStraightThree2(cardGraphics[straightThree[i].s[1]->value]);
                    Card playedStraightThree3(cardGraphics[straightThree[i].s[2]->value]);
                    playedStraightThree1.RenderButton(550, 500, 150, 200, 0, true);
                    playedStraightThree2.RenderButton(600, 500, 150, 200, 0, true);
                    playedStraightThree3.RenderButton(650, 500, 150, 200, 0, true);
                    play.maxCard = straightThree[i].maxCard->value;
                    // don't need this but still add to try
                    play.kindcode = 5;
                    cout << "player plays straight three " << straightThree[i].s[0]->value << " + " << straightThree[i].s[1]->value << " + " << straightThree[i].s[2]->value << endl;
                    straightThree[i].s[0]->value = -2;
                    straightThree[i].s[1]->value = -2;
                    straightThree[i].s[2]->value = -2;
                    straightThree.erase(straightThree.begin() + i);
                }
            }
        }
        cout << "play.maxCard = " << play.maxCard << endl;
        return play;
    }

Play Character::playCardAI(Play pre, int &whoTurn, int &passNum)
    {
        bool justPlayed = false;
        switch (pre.kindcode)
        {
        case 1: // single card
            for (int i = 0; i < hand.size(); i++)
            {
                if (((hand[i].value / 4) > (pre.maxCard / 4)) && hand[i].choosen == 0)
                {
                    // Card botPlayedCard(hand[i].path);
                    Card botPlayedCard(cardGraphics[hand[i].value]);
                    // switch (indexOfPlayer)
                    switch (whoTurn)
                    {
                    case 0:
                        botPlayedCard.RenderButton(230, 330, 150, 200, 0, true);
                        break;
                    case 1:
                        botPlayedCard.RenderButton(500, 200, 150, 200, 0, true);
                        break;
                    case 2:
                        botPlayedCard.RenderButton(850, 300, 150, 200, 0, true);
                        // botPlayedCard.RenderButton(800, 300, 150, 200, 0, true);
                    default:
                        break;
                    }

                    // SDL_Delay(200);
                    justPlayed = true;
                    passNum = 0;
                    pre.maxCard = hand[i].value;
                    // don't need this but still add to try
                    pre.kindcode = 1;
                    cout << "bot " << whoTurn << " plays single card " << hand[i].value << endl;
                    hand[i].value = -2;
                }
                if (justPlayed)
                    break;
            }
            break;
        case 2: // pair
            for (int i = 0; i < pair.size(); i++)
            {
                if ((pair[i].p2->value / 4) > (pre.maxCard / 4) /* && pair[i].choosen = false */)
                {
                    // Card botPlayPair1(pair[i].p1->path);
                    // Card botPlayPair2(pair[i].p2->path);
                    Card botPlayPair1(cardGraphics[pair[i].p1->value]);
                    Card botPlayPair2(cardGraphics[pair[i].p2->value]);
                    switch (whoTurn)
                    {
                    case 0:
                        botPlayPair1.RenderButton(230, 330, 150, 200, 0, true);
                        botPlayPair2.RenderButton(280, 330, 150, 200, 0, true);
                        break;
                    case 1:
                        botPlayPair1.RenderButton(500, 200, 150, 200, 0, true);
                        botPlayPair2.RenderButton(550, 200, 150, 200, 0, true);
                        break;
                    case 2:
                        botPlayPair1.RenderButton(850, 300, 150, 200, 0, true);
                        botPlayPair2.RenderButton(950, 300, 150, 200, 0, true);
                    default:
                        break;
                    }

                    // SDL_Delay(200);
                    justPlayed = true;
                    passNum = 0;
                    pre.maxCard = pair[i].p2->value;
                    // don't need this but still add to try
                    pre.kindcode = 2;
                    cout << "bot " << whoTurn << " plays pair " << pair[i].p1->value << " + " << pair[i].p2->value << endl;
                    // int value1 = pair[i].p1->value;
                    // int value2 = pair[i].p2->value;

                    // pair[i].p1->value = -2;
                    // pair[i].p2->value = -2;
                    pair[i].p1->value = -2;
                    pair[i].p2->value = -2;
                    pair.erase(pair.begin() + i);
                    // eraseByValue(value1);
                    // eraseByValue(value2);
                    // cout << "erase " << pair[i].p1->value << " + " << pair[i].p2->value << endl;
                }
                if (justPlayed)
                    break;
            }
            break;
        case 3: // three
            for (int i = 0; i < three.size(); i++)
            {
                if ((three[i].maxCard->value / 4) > (pre.maxCard / 4) /* && pair[i].choosen = false */)
                {
                    // Card botPlayThree1(three[i].t[0]->path);
                    // Card botPlayThree2(three[i].t[1]->path);
                    // Card botPlayThree3(three[i].t[2]->path);
                    Card botPlayThree1(cardGraphics[three[i].t[0]->value]);
                    Card botPlayThree2(cardGraphics[three[i].t[1]->value]);
                    Card botPlayThree3(cardGraphics[three[i].t[2]->value]);
                    switch (whoTurn)
                    {
                    case 0:
                        botPlayThree1.RenderButton(230, 330, 150, 200, 0, true);
                        botPlayThree2.RenderButton(280, 330, 150, 200, 0, true);
                        botPlayThree3.RenderButton(330, 330, 150, 200, 0, true);
                        break;
                    case 1:
                        botPlayThree1.RenderButton(500, 200, 150, 200, 0, true);
                        botPlayThree2.RenderButton(550, 200, 150, 200, 0, true);
                        botPlayThree3.RenderButton(600, 200, 150, 200, 0, true);
                        break;
                    case 2:
                        botPlayThree1.RenderButton(850, 300, 150, 200, 0, true);
                        botPlayThree2.RenderButton(900, 300, 150, 200, 0, true);
                        botPlayThree3.RenderButton(950, 300, 150, 200, 0, true);
                        break;

                    default:
                        break;
                    }

                    // SDL_Delay(200);
                    justPlayed = true;
                    passNum = 0;
                    pre.maxCard = three[i].maxCard->value;
                    // don't need this but still add to try
                    pre.kindcode = 3;
                    cout << "bot plays three " << three[i].t[0]->value << " + " << three[i].t[1]->value << " + " << three[i].t[2]->value << endl;

                    three[i].t[0]->value = -2;
                    three[i].t[1]->value = -2;
                    three[i].t[2]->value = -2;
                    three.erase(three.begin() + i);
                }
                if (justPlayed)
                    break;
            }
            break;
        case 5: 
            for (int i = 0; i < straightThree.size(); i++)
            {
                if ((straightThree[i].maxCard->value / 4) > (pre.maxCard / 4) /* && pair[i].choosen = false */)
                {
                    // Card botPlaystraightThree1(straightThree[i].s[0]->path);
                    // Card botPlaystraightThree2(straightThree[i].s[1]->path);
                    // Card botPlaystraightThree3(straightThree[i].s[2]->path);
                    Card botPlaystraightThree1(cardGraphics[straightThree[i].s[0]->value]);
                    Card botPlaystraightThree2(cardGraphics[straightThree[i].s[1]->value]);
                    Card botPlaystraightThree3(cardGraphics[straightThree[i].s[2]->value]);
                    
                    switch (whoTurn)
                    {
                    case 0:
                        botPlaystraightThree1.RenderButton(230, 330, 150, 200, 0, true);
                        botPlaystraightThree2.RenderButton(280, 330, 150, 200, 0, true);
                        botPlaystraightThree3.RenderButton(330, 330, 150, 200, 0, true);
                        break;
                    case 1:
                        botPlaystraightThree1.RenderButton(500, 200, 150, 200, 0, true);
                        botPlaystraightThree2.RenderButton(550, 200, 150, 200, 0, true);
                        botPlaystraightThree3.RenderButton(600, 200, 150, 200, 0, true);
                        break;
                    case 2:
                        botPlaystraightThree1.RenderButton(850, 300, 150, 200, 0, true);
                        botPlaystraightThree2.RenderButton(900, 300, 150, 200, 0, true);
                        botPlaystraightThree3.RenderButton(950, 300, 150, 200, 0, true);
                        break;
                    default:
                        break;
                    }

                    // SDL_Delay(200);
                    justPlayed = true;
                    passNum = 0;
                    pre.maxCard = straightThree[i].maxCard->value;
                    // don't need this but still add to try
                    pre.kindcode = 5;
                    cout << "bot plays straightThree " << straightThree[i].s[0]->value << " + " << straightThree[i].s[1]->value << " + " << straightThree[i].s[2]->value << endl;

                    straightThree[i].s[0]->value = -2;
                    straightThree[i].s[1]->value = -2;
                    straightThree[i].s[2]->value = -2;
                    straightThree.erase(straightThree.begin() + i);
                }
                if (justPlayed) {
                    break;
                }
                    
            }
            break;
        }
        if (justPlayed == false)
        {
            passNum++;
            cout << "Pass " << passNum << endl;
            if (passNum == 3)
            {
                pre.maxCard = -5;
            }
            if (passNum > 3)
                passNum = 1;
        }
        return pre;
    }

bool Character::runOutOfCard()
    {
        if (hand.size() == 0)
            return true;
        else
            return false;
    }

Character::~Character() {
    
}

