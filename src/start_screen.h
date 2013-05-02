#ifndef _START_SCREEN_H_
#define _START_SCREEN_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "game_screen.h"
#include "renderer.h"

class StartScreen: public GameScreen
{
    public:
        GameScreen* respondToUserInput(SDL_Event&);

        StartScreen();
        ~StartScreen();
};

#endif /* _START_SCREEN_H_ */
