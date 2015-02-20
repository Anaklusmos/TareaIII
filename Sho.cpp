#include "Sho.h"

Sho::Sho(SDL_Renderer* renderer)
{
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/1.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/2.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/3.png"));
    sho_standing.push_back(IMG_LoadTexture(renderer,"Sho/standing/4.png"));

    sho_forward.push_back(IMG_LoadTexture(renderer,"Sho/walkforward/1.png"));
    sho_forward.push_back(IMG_LoadTexture(renderer,"Sho/walkforward/2.png"));
    sho_forward.push_back(IMG_LoadTexture(renderer,"Sho/walkforward/3.png"));
    sho_forward.push_back(IMG_LoadTexture(renderer,"Sho/walkforward/4.png"));
    sho_forward.push_back(IMG_LoadTexture(renderer,"Sho/walkforward/5.png"));

    sho_backward.push_back(IMG_LoadTexture(renderer,"Sho/walkback/1.png"));
    sho_backward.push_back(IMG_LoadTexture(renderer,"Sho/walkback/2.png"));
    sho_backward.push_back(IMG_LoadTexture(renderer,"Sho/walkback/3.png"));
    sho_backward.push_back(IMG_LoadTexture(renderer,"Sho/walkback/4.png"));
    sho_backward.push_back(IMG_LoadTexture(renderer,"Sho/walkback/5.png"));

    pau_img = IMG_LoadTexture(renderer,"pau.png");

    SDL_QueryTexture(pau_img, NULL, NULL, &rectp.w, &rectp.h);
    rectp.x=250;
    rectp.y=150;

    SDL_QueryTexture(sho_standing[0], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(sho_backward[0], NULL, NULL, &rect.w, &rect.h);
    SDL_QueryTexture(sho_forward[0], NULL, NULL, &rect.w, &rect.h);
    rect.x = 100;
    rect.y = 200;

    frame = 0;
    animacion_sho = 0;
    pause = false;
    op=0;
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

     if (pause)
        SDL_RenderCopy(renderer, pau_img, NULL, &rectp);
}

void Sho::act()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_P])
    {
        if (pause){
        pause=false;
        }
        else
        pause=true;
    }
    if (pause==false){

    if(currentKeyStates[SDL_SCANCODE_UP] && rect.y >=-20)
    {
        rect.y--;
        if (currentKeyStates[SDL_SCANCODE_F])
            rect.y-=2;
    }

    if(currentKeyStates[SDL_SCANCODE_LEFT] && rect.x >=-20)
    {
        rect.x--;
        if (currentKeyStates[SDL_SCANCODE_F])
            rect.x-=2;
    }

    if(currentKeyStates[SDL_SCANCODE_DOWN] && rect.y <= 300)
    {
        rect.y++;
        if (currentKeyStates[SDL_SCANCODE_F])
            rect.y+=2;
    }

    if(currentKeyStates[SDL_SCANCODE_RIGHT] && rect.x <= 820)
    {
        rect.x++;
        if (currentKeyStates[SDL_SCANCODE_F])
            rect.x+=2;
    }


    }
}

Sho::~Sho()
{
    //dtor
}
