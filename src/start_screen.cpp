#include <SDL/SDL.h>
#include <iostream>
#include "start_screen.h"

StartScreen::StartScreen()
{
    std::cout << "Initializing StartScreen" << std::endl;

    textColor = {0, 255, 0};
    if ((message = TTF_RenderText_Solid(font, "Welcome to Rogue3k", textColor)) == NULL) {
        std::cerr << "Can't open message buffer!" << std::endl;
    }

    apply_surface(50, 150, message, screen);
}

StartScreen::~StartScreen()
{
    std::cout << "Cleaning up StartScreen" << std::endl;
    SDL_FreeSurface(message);
}

void StartScreen::respondToUserInput(SDL_Event&)
{
}
