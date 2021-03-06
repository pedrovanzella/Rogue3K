#ifndef _WIN_SCREEN_H_
#define _WIN_SCREEN_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "game_screen.h"
#include "world.h"
#include "renderer.h"

class WinScreen: public GameScreen
{
    public:
        GameScreen* respondToUserInput(SDL_Event&);

        WinScreen();
        ~WinScreen();
};

#endif /* _WIN_SCREEN_H_ */
