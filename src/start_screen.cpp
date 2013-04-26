#include <SDL/SDL.h>
#include <iostream>
#include "start_screen.h"
#include "world_screen.h"

StartScreen::StartScreen()
{
    std::cout << "Initializing StartScreen" << std::endl;

    textColor = {0, 255, 0};
    if ((message = TTF_RenderText_Solid(font, "Welcome to Rogue3k.", textColor)) == NULL) {
        std::cerr << "Can't open message buffer!" << std::endl;
    }

    apply_surface(50, 150, message, screen);

    if ((message = TTF_RenderText_Solid(font, "Press [Enter] to Play.", textColor)) == NULL) {
        std::cerr << "Can't open message buffer!" << std::endl;
    }

    apply_surface(50, 250, message, screen);
}

StartScreen::~StartScreen()
{
    std::cout << "Cleaning up StartScreen" << std::endl;
    SDL_FreeSurface(message);
}

GameScreen* StartScreen::respondToUserInput(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_RETURN:
                return new WorldScreen();
            default:
                return this;
        }
    }
    return this;
}
