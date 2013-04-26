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
    std::cout << "LoseScreen responding" << std::endl;
    if (event.type == SDL_KEYDOWN) {
        std::cout << "Key pressed" << std::endl;
        switch (event.key.keysym.sym) {
            case SDLK_RETURN:
                std::cout << "RETURN pressed" << std::endl;
                return new WorldScreen();
            default:
                return this;
        }
    }
    return this;

}
