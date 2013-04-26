#include <SDL/SDL.h>
#include <iostream>
#include "win_screen.h"
#include "world_screen.h"

WinScreen::WinScreen()
{
    std::cout << "Initializing WinScreen" << std::endl;

    textColor = {0, 0, 255};
    if ((message = TTF_RenderText_Solid(font, "Great job. Press [Enter] to play again.", textColor)) == NULL) {
        std::cerr << "Can't open message buffer!" << std::endl;
    }

    apply_surface(50, 150, message, screen);
}

WinScreen::~WinScreen()
{
    std::cout << "Cleaning up WinScreen" << std::endl;
    SDL_FreeSurface(message);
}

GameScreen* WinScreen::respondToUserInput(SDL_Event& event)
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
