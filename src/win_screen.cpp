#include <SDL/SDL.h>
#include <iostream>
#include "win_screen.h"
#include "world_screen.h"
#include "renderer.h"

WinScreen::WinScreen()
{
    std::cout << "Initializing WinScreen" << std::endl;
    Renderer::write_message_to_screen(0, 0, 255, "Great job. Press [Enter] to play again.", 50, 150);
}

WinScreen::~WinScreen()
{
    std::cout << "Cleaning up WinScreen" << std::endl;
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
