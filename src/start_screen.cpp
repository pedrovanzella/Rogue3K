#include <SDL/SDL.h>
#include <iostream>
#include "start_screen.h"
#include "world_screen.h"
#include "renderer.h"

StartScreen::StartScreen()
{
    std::cout << "Initializing StartScreen" << std::endl;
    Renderer::clear_area(0, 0, 800, 600);
    Renderer::write_message_to_screen(0, 255, 0, "Welcome to Rogue3k.", 50, 150);
    Renderer::write_message_to_screen(0, 255, 0, "Press [Enter] to Play.", 50, 250);
}

StartScreen::~StartScreen()
{
    std::cout << "Cleaning up StartScreen" << std::endl;
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
