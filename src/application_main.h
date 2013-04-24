#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

class ApplicationMain
{
    private:
        SDL_Surface* screen;
        SDL_Surface* message;
        TTF_Font* font;
        SDL_Color textColor;

    public:
        ApplicationMain();

        int Init();
        int update();
        void apply_surface(int, int, SDL_Surface*, SDL_Surface*);

        ~ApplicationMain();
};
