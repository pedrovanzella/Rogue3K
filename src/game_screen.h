#ifndef _GAME_SCREEN_H_
#define _GAME_SCREEN_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

class GameScreen
{
    private:
        SDL_Surface* screen;
        TTF_Font* font;
        void InitFont();

    public:
        void respondToUserInput(SDL_Event&);
        virtual SDL_Surface* currentScreen();
        TTF_Font* gameFont();
        void setScreen(SDL_Surface*);

        void apply_surface(int, int, SDL_Surface*, SDL_Surface*);
        void Init();

        GameScreen();
        ~GameScreen();
};

#endif /* _GAME_SCREEN_H_ */
