#include "Button.h"
#include "DeckOfCards.h"
Button::Button()
{
    mPosition.x = 0;
    mPosition.y = 0;
    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
    clickCount=0;
}

void Button::setPosition( int x, int y )
{
    mPosition.x = x;
    mPosition.y = y;
}

void Button::handleEvent( SDL_Event* e , int type)
{
    //If mouse event happened
    if( e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );

        //Check if mouse is in button
        bool inside = true;
        int WIDTH=0;
        int HEIGHT=0;

        if(type==1)
        {
            WIDTH=BUTTON_WIDTH;
            HEIGHT=BUTTON_HEIGHT;
        }
        else if(type==2)
        {
            WIDTH=BUTTON_WIDTH2;
            HEIGHT=BUTTON_HEIGHT2;
        }
        else if(type==3)
        {
            WIDTH=BUTTON_WIDTH3;
            HEIGHT=BUTTON_HEIGHT3;
        }
        else if(type==4)
        {
            WIDTH=BUTTON_WIDTH4;
            HEIGHT=BUTTON_HEIGHT4;
        }

        //Mouse is left of the button
        if( x < mPosition.x )
        {
            inside = false;
        }
        //Mouse is right of the button
        else if( x > mPosition.x + WIDTH )
        {
            inside = false;
        }
        //Mouse above the button
        else if( y < mPosition.y )
        {
            inside = false;
        }
        //Mouse below the button
        else if( y > mPosition.y + HEIGHT )
        {
            inside = false;
        }

        //Mouse is outside button
        if( !inside )
        {
            mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        }
        //Mouse is inside button
        else
        {
            //Set mouse over sprite
            switch( e->type )
            {
                case SDL_MOUSEBUTTONDOWN:
                    mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                    clickCount++;
                    break;

                case SDL_MOUSEBUTTONUP:
                    mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                    break;
            }
        }
    }
}

// void Button::render(int i)
// {
//     //Show current button sprite
//     cardGraphics[i].render( mPosition.x, mPosition.y, &cardGraphics[ i ] );
//     cardGraphics[i].render( mPosition.x, mPosition.y, &CardButtons[ i ] );
// }

int Button::getEnum()
{
    return mCurrentSprite;
}