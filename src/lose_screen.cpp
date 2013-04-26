#include <SDL/SDL.h>
#include <iostream>
#include "world_screen.h"
#include "lose_screen.h"

LoseScreen::LoseScreen()
{
    std::cout << "Initializing LoseScreen" << std::endl;

    textColor = {255, 0, 0};
    if ((message = TTF_RenderText_Solid(font, "You Lose! Press [Enter] to play again.", textColor)) == NULL) {
        std::cerr << "Can't open message buffer!" << std::endl;
    }

    apply_surface(50, 150, message, screen);
}

LoseScreen::~LoseScreen()
{
    std::cout << "Cleaning up LoseScreen" << std::endl;
    SDL_FreeSurface(message);
}

GameScreen* LoseScreen::respondToUserInput(SDL_Event& event)
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
