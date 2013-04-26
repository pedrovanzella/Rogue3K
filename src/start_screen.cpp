#include <SDL/SDL.h>
#include <iostream>
#include "start_screen.h"
#include "world_screen.h"

StartScreen::StartScreen()
{
    std::cout << "Initializing StartScreen" << std::endl;

    textColor = {0, 255, 0};
    if ((message = TTF_RenderText_Solid(font, "Welcome to Rogue3k.\nPress Enter to Play.", textColor)) == NULL) {
        std::cerr << "Can't open message buffer!" << std::endl;
    }

    apply_surface(50, 150, message, screen);
}

StartScreen::~StartScreen()
{
    std::cout << "Cleaning up StartScreen" << std::endl;
    SDL_FreeSurface(message);
}

GameScreen* StartScreen::respondToUserInput(SDL_Event& event)
{
    std::cout << "StartScreen responding" << std::endl;
    if (event.type == SDL_KEYDOWN) {
        std::cout << "Key pressed" << std::endl;
        if (event.key.keysym.sym == SDLK_RETURN) {
            std::cout << "RETURN pressed" << std::endl;
            return new WorldScreen();
        }
    }
    return this;
}
