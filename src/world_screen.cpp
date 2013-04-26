#include <SDL/SDL.h>
#include <iostream>
#include "world_screen.h"
#include "win_screen.h"
#include "lose_screen.h"

WorldScreen::WorldScreen()
{
    std::cout << "Initializing WorldScreen" << std::endl;

    textColor = {255, 255, 0};
    if ((message = TTF_RenderText_Solid(font, "This is the world of Rogue3k.", textColor)) == NULL) {
        std::cerr << "Can't open message buffer!" << std::endl;
    }

    apply_surface(50, 150, message, screen);

    SDL_FreeSurface(message);

    if ((message = TTF_RenderText_Solid(font, "Press [Escape] do Die.", textColor)) == NULL) {
        std::cerr << "Can't open message buffer!" << std::endl;
    }

    apply_surface(50, 200, message, screen);

    SDL_FreeSurface(message);

    if ((message = TTF_RenderText_Solid(font, "Press [Enter] to Win.", textColor)) == NULL) {
        std::cerr << "Can't open message buffer!" << std::endl;
    }

    apply_surface(50, 250, message, screen);

    SDL_FreeSurface(message);
}

WorldScreen::~WorldScreen()
{
    std::cout << "Cleaning up WorldScreen" << std::endl;
}

GameScreen* WorldScreen::respondToUserInput(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_RETURN:
                return new WinScreen();
            case SDLK_ESCAPE:
                return new LoseScreen();
            default:
                return this;
        }
    }
    return this;

}
