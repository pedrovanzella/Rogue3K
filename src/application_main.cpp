#include "application_main.h"

ApplicationMain::ApplicationMain()
{
    SDL_Init(SDL_INIT_EVERYTHING);
}

ApplicationMain::~ApplicationMain()
{
    SDL_Quit();
}

int ApplicationMain::Init()
{
    screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
    SDL_Delay(2000);
    return 1;
}
