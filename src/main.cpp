#include <iostream>
#include <SDL/SDL.h>

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    // Init SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    // Set up screen
    SDL_Surface* screen;
    screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);

    // Don't quit just yet
    SDL_Delay(2000);

    // Quit SDL
    SDL_Quit();

    return 0;
}
