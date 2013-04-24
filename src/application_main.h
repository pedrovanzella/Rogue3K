#include <SDL/SDL.h>

class ApplicationMain
{
    private:
        SDL_Surface* screen;

    public:
        ApplicationMain();

        int Init();

        ~ApplicationMain();
};
