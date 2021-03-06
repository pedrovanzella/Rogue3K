#ifndef _WORLD_SCREEN_H_
#define _WORLD_SCREEN_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "game_screen.h"
#include "world.h"
#include "world_builder.h"
#include "renderer.h"

class WorldScreen: public GameScreen
{
    private:
        static World* world;

        void createWorld();
    public:
        GameScreen* respondToUserInput(SDL_Event&);
        int Update();

        WorldScreen();
        ~WorldScreen();
};

#endif /* _WORLD_SCREEN_H_ */
