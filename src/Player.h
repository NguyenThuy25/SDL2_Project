#include "Play.h"
#include "Character.h"

void botPlayCard(int& whoTurn, Play& play, vector<Character>& charater, int& passNum, bool& isPlayed, GameObject& arrow);
void userPlayCard(int& whoTurn, vector<Character>& character, SDL_Event& event, Play& play, GameObject& playButton, GameObject& passButton, int& passNum, bool& isPlayed, int& type, GameObject& arrow);
