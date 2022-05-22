#include "Player.h"


void botPlayCard(int& whoTurn, Play& play, vector<Character>& character, int& passNum, bool& isPlayed, GameObject& arrow) {
    if (whoTurn != 3){
        if (whoTurn == 0) {
            arrow.RenderArrow(90);
        }
        else if (whoTurn == 1) {
            arrow.RenderArrow(180);
        }
        else {
            arrow.RenderArrow(270);
        }

        if (play.maxCard < 0) {
            if (character[whoTurn].straightThree.size() != 0) {
                play.kindcode = 5;
            }
            else if (character[whoTurn].three.size() != 0) {
                    play.kindcode = 3;
            }
            else if (character[whoTurn].pair.size() != 0) {
                    play.kindcode = 2;
            }
            else {
                play.kindcode = 1;
            }
        }
        cout << "play.kindcode =" << play.kindcode << endl;
        play = character[whoTurn].playCardAI(play, whoTurn, passNum);
        character[whoTurn].popOut();
        isPlayed = true;
    }
}

void userPlayCard(int& whoTurn, vector<Character>& character, SDL_Event& event, Play& play, GameObject& playButton, GameObject& passButton, int& passNum, bool& isPlayed, int& type, GameObject& arrow) {
    if (whoTurn == 3) {
        character[3].checkEvent(event);
        arrow.RenderArrow(0);
        cout << "type of player " << type << endl;
        if (type == 1) {
            play = character[3].playerPlayCard(play, event, passNum);
            character[3].popOut();
            isPlayed = true; // isPassed
        }
        if (type == 3) {
            isPlayed = true; // isPassed
            passNum++;
            cout << "Pass " << passNum << endl;
            if (passNum == 3) {
                play.maxCard = -5;
            }
            if (passNum > 3) {
                passNum = 1;
            }     
        }
    }
}