#include <iostream>
#include "application_main.h"

ApplicationMain::ApplicationMain()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = NULL;
    message = NULL;
    font = NULL;
    quit = false;
}

ApplicationMain::~ApplicationMain()
{
    std::cout << "Cleaning up..." << std::endl;
    SDL_FreeSurface(message);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}

int ApplicationMain::Init()
{
    if ((screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE)) == NULL) {
        std::cerr << "Can't create screen!" << std::endl;
        return -1;
    }
    SDL_WM_SetCaption("Rogue3k", NULL);

    TTF_Init();
    textColor = {0, 255, 0};
    if ((font = TTF_OpenFont("assets/VeraMono.ttf", 10)) == NULL) {
        std::cerr << "Can't open font!" << std::endl;
        return -1;
    }

    if ((message = TTF_RenderText_Solid(font, "Rogue3k", textColor)) == NULL) {
        std::cerr << "Can't open message buffer!" << std::endl;
        return -1;
    }

    apply_surface(50, 150, message, screen);

    return 1;
}

int ApplicationMain::Update()
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

void ApplicationMain::mainLoop()
{
    while (!quit) {
        // Update our screen
        Update();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }
}
