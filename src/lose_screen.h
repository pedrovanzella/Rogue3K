#ifndef _LOSE_SCREEN_H_
#define _LOSE_SCREEN_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "game_screen.h"
#include "renderer.h"

class LoseScreen: public GameScreen
{
    public:
        GameScreen* respondToUserInput(SDL_Event&);

        LoseScreen();
        ~LoseScreen();
};

#endif /* _LOSE_SCREEN_H_ */
