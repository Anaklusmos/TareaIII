#include "Sho.h"

Sho::Sho(SDL_Renderer* renderer)
{
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/1.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/2.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/3.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/4.png"));

    sho_jump.push_back(IMG_LoadTexture(renderer,"Sho/jumpup/1.png"));
    sho_jump.push_back(IMG_LoadTexture(renderer,"Sho/jumpup/2.png"));
    sho_jump.push_back(IMG_LoadTexture(renderer,"Sho/jumpup/3.png"));
    sho_jump.push_back(IMG_LoadTexture(renderer,"Sho/jumpup/4.png"));
    sho_jump.push_back(IMG_LoadTexture(renderer,"Sho/jumpup/5.png"));
    sho_jump.push_back(IMG_LoadTexture(renderer,"Sho/jumpup/6.png"));
    sho_jump.push_back(IMG_LoadTexture(renderer,"Sho/jumpup/7.png"));


    SDL_QueryTexture(sho_standing[0], NULL, NULL, &rect.w, &rect.h);
    rect.x = 100;
    rect.y = 250;

    frame = 0;
    animacion_sho = 0;
}

void Sho::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, sho_standing[animacion_sho], NULL, &rect);
    if(frame%100==0)
    {
        animacion_sho++;
        if(animacion_sho>=sho_standing.size())
            animacion_sho=0;
    }
    frame++;
}

void Sho::act()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if(currentKeyStates[SDL_SCANCODE_UP] && rect.y>=-20)
    {
        rect.y--;
        if(currentKeyStates[SDL_SCANCODE_F] && rect.y>=-20)
            rect.y-=2;
    }

    if(currentKeyStates[SDL_SCANCODE_LEFT] && rect.x>=-20)
    {
        rect.x--;
        if(currentKeyStates[SDL_SCANCODE_F] && rect.x>=-20)
            rect.x-=2;
    }

    if(currentKeyStates[SDL_SCANCODE_DOWN] && rect.y<=280)
    {
        rect.y++;
        if(currentKeyStates[SDL_SCANCODE_F] && rect.y<=200)
            rect.y+=2;
    }

    if(currentKeyStates[SDL_SCANCODE_RIGHT] && rect.x<=820)
    {
        rect.x++;
        if(currentKeyStates[SDL_SCANCODE_F] && rect.x<=820)
            rect.x+=2;
    }

}

Sho::~Sho()
{
    //dtor
}
