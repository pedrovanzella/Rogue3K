#ifndef _GAME_SCREEN_H_
#define _GAME_SCREEN_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "renderer.h"

class GameScreen
{
    public:
        virtual GameScreen* respondToUserInput(SDL_Event&);

        virtual int Update();

        GameScreen();
        virtual ~GameScreen();
};

#endif /* _GAME_SCREEN_H_ */
