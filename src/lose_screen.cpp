#include <SDL/SDL.h>
#include <iostream>
#include "world_screen.h"
#include "lose_screen.h"
#include "renderer.h"

LoseScreen::LoseScreen()
{
    std::cout << "Initializing LoseScreen" << std::endl;
    Renderer::clear_area(0, 0, 800, 600);
    Renderer::write_message_to_screen(255, 0, 0, "You Lose! Press [Enter] to play again.", 50, 150);
}

LoseScreen::~LoseScreen()
{
    std::cout << "Cleaning up LoseScreen" << std::endl;
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
