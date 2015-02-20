#ifndef SHO_H
#define SHO_H

#include "Personaje.h"

class Sho : public Personaje
{
    public:
        vector<SDL_Texture*>sho_standing;
        vector<SDL_Texture*>sho_forward;
        vector<SDL_Texture*>sho_backward;
        SDL_Texture* pau_img;
        SDL_Rect rect;
        SDL_Rect rectp;
        int op;
        int frame;
        int animacion_sho;
        int suelo;
        int lim;
        bool pause;
        Sho(SDL_Renderer* renderer);
        void draw(SDL_Renderer* renderer);
        void drawP();
        void act();
        virtual ~Sho();
    protected:
    private:
};

#endif // SHO_H
