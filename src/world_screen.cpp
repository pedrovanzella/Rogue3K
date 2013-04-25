#include <SDL/SDL.h>
#include <iostream>
#include "world_screen.h"

WorldScreen::WorldScreen()
{
    std::cout << "Initializing WorldScreen" << std::endl;

    textColor = {255, 0, 0};
    if ((message = TTF_RenderText_Solid(font, "This is the world of Rogue3k.\nPress Escape do Die.\nPress Enter to Win.", textColor)) == NULL) {
        std::cerr << "Can't open message buffer!" << std::endl;
    }

    apply_surface(50, 150, message, screen);
}

WorldScreen::~WorldScreen()
{
    std::cout << "Cleaning up WorldScreen" << std::endl;
    SDL_FreeSurface(message);
}

GameScreen* WorldScreen::respondToUserInput(SDL_Event& event)
{
}
