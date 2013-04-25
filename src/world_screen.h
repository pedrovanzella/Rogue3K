#ifndef _WORLD_SCREEN_H_
#define _WORLD_SCREEN_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "game_screen.h"

class WorldScreen: public GameScreen
{
    private:
        SDL_Surface* message;
        SDL_Color textColor;

    public:
        GameScreen* respondToUserInput(SDL_Event&);

        WorldScreen();
        ~WorldScreen();
};

#endif /* _WORLD_SCREEN_H_ */
