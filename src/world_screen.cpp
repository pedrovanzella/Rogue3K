#include <SDL/SDL.h>
#include <iostream>
#include "world_screen.h"
#include "win_screen.h"
#include "lose_screen.h"

WorldScreen::WorldScreen()
{
    std::cout << "Initializing WorldScreen" << std::endl;

    textColor = {255, 255, 0};
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
    std::cout << "WorldScreen responding" << std::endl;
    if (event.type == SDL_KEYDOWN) {
        std::cout << "Key pressed" << std::endl;
        switch (event.key.keysym.sym) {
            case SDLK_RETURN:
                std::cout << "RETURN pressed" << std::endl;
                return new WinScreen();
            case SDLK_ESCAPE:
                std::cout << "ESCAPE pressed" << std::endl;
                return new LoseScreen();
            default:
                return this;
        }
    }
    return this;

}
