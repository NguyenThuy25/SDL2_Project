#include "GameObject.h"
#include "Game.h"
GameObject::GameObject() {
    x = 0;
    y = 0;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 150;
    srcRect.h = 200;

    destRect.x = x;
    destRect.y = y;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}

SDL_Texture* GameObject::LoadTexture(const char* texture) {
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}
GameObject::GameObject(std::string texturesheet, int _x, int _y) : GameObject(){
    objTexture = LoadTexture(texturesheet.c_str());
    x = _x;
    y = _y;
}

void GameObject::Update() {
    
}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
    // SDL_RenderCopyEx(Game::renderer, objTexture, &srcRect, &destRect, 0, NULL, SDL_FLIP_NONE);
}
// void GameObject::RenderFull() {
//     SDL_RenderCopy(Game::renderer, objTexture, NULL, NULL);
// }
void GameObject::RenderButton(int xButton, int yButton, int widthButton, int heightButton) {
    x = 0;
    y = 0;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = widthButton;
    srcRect.h = heightButton;

    destRect.x = xButton;
    destRect.y = yButton;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
    SDL_Delay(200);
}
bool GameObject::isClicked(SDL_Event event, int cardOrButton)
{
    // int cardOrButton: 1->card ; 2->button
    if (event.type == SDL_MOUSEMOTION) {
        int x_m = event.motion.x;
        int y_m = event.motion.y;
        // cout << "mouse: " << x_m << " " << y_m << endl; 
        if(cardOrButton == 1) {
            if (x_m > getRect().x && x_m < getRect().x + getRect().w/2
            && y_m > getRect().y && y_m < getRect().y + getRect().h)
        {
            inSide = true;
        }
        else
        {
            inSide = false;
            return false;
        }
        } else {
            if (x_m > getRect().x && x_m < getRect().x + getRect().w
            && y_m > getRect().y && y_m < getRect().y + getRect().h)
        {
            inSide = true;
        }
        else
        {
            inSide = false;
            return false;
        }
        }
        
    }
    if (event.type == SDL_MOUSEBUTTONDOWN && inSide) {
        // cout << "clicked" << endl;
        return true;
    }
    return false;
}

GameObject::~GameObject() {

}


