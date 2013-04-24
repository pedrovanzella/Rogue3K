#include <iostream>
#include "application_main.h"

ApplicationMain::ApplicationMain()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = NULL;
    message = NULL;
    font = NULL;
}

ApplicationMain::~ApplicationMain()
{
    SDL_FreeSurface(message);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}

int ApplicationMain::Init()
{
    screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
    SDL_WM_SetCaption("Rogue3k", NULL);

    textColor = {0, 255, 0};
    if ((font = TTF_OpenFont("assets/VeraMono.ttf", 10)) == NULL) {
        std::cerr << "Can't open font!" << std::endl;
        return -1;
    }
    message = TTF_RenderText_Solid(font, "Rogue3k", textColor);

    apply_surface(0, 150, message, screen);
    update();

    SDL_Delay(2000);
    
    if (screen == NULL || message == NULL) {
        return -1;
    }
    return 1;
}

int ApplicationMain::update()
{
    if (SDL_Flip(screen) == -1) {
        return -1;
    }
    return 1;
}

void ApplicationMain::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
    
    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}
