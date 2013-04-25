#include <SDL/SDL.h>
#include <iostream>
#include "start_screen.h"

StartScreen::StartScreen(SDL_Surface* scr)
{
    std::cout << "Initializing game screen" << std::endl;
    if (screen == NULL) {
        std::cerr << "WTF null screen?" << std::endl;
    }
    setScreen(scr);

    Init();

    textColor = {0, 255, 0};
    if ((message = TTF_RenderText_Solid(gameFont(), "Welcome to Rogue3k", textColor)) == NULL) {
        std::cerr << "Can't open message buffer!" << std::endl;
    }

    apply_surface(50, 150, message, screen);
    std::cout << "Surface applied" << std::endl;
}

StartScreen::~StartScreen()
{
    std::cout << "Cleaning up StartScreen" << std::endl;
    SDL_FreeSurface(message);
}

void StartScreen::respondToUserInput(SDL_Event&)
{
}

SDL_Surface* StartScreen::currentScreen()
{
    std::cout << "Returning screen" << std::endl;
    return screen;
}
