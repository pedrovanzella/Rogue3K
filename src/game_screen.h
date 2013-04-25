#ifndef _GAME_SCREEN_H_
#define _GAME_SCREEN_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

class GameScreen
{
    protected:
        SDL_Surface* screen;
        TTF_Font* font;
        void InitFont();

        void apply_surface(int, int, SDL_Surface*, SDL_Surface*);

    public:
        void respondToUserInput(SDL_Event&);

        void Init();
        int Update();

        GameScreen();
        ~GameScreen();
};

#endif /* _GAME_SCREEN_H_ */
