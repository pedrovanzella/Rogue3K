#ifndef _APPLICATION_MAIN_H_
#define _APPLICATION_MAIN_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "game_screen.h"
#include "renderer.h"

class ApplicationMain
{
    private:
        SDL_Event event;
        GameScreen* gameScreen;
        bool quit;


    public:
        ApplicationMain();

        int Init();
        int Update();
        void mainLoop();

        ~ApplicationMain();
};

#endif /* _APPLICATION_MAIN_H_ */
