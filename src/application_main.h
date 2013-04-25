#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

class ApplicationMain
{
    private:
        SDL_Surface* screen;
        SDL_Surface* message;
        TTF_Font* font;
        SDL_Color textColor;
        SDL_Event event;
        bool quit;

        void apply_surface(int, int, SDL_Surface*, SDL_Surface*);

    public:
        ApplicationMain();

        int Init();
        int Update();
        void mainLoop();

        ~ApplicationMain();
};
