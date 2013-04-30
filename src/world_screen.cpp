#include <SDL/SDL.h>
#include <iostream>
#include "world_screen.h"
#include "win_screen.h"
#include "lose_screen.h"
#include "world_builder.h"
#include "world.h"

World* WorldScreen::world = NULL;

WorldScreen::WorldScreen()
{
    std::cout << "Initializing WorldScreen" << std::endl;

    textColor = {255, 255, 0};
    if ((message = TTF_RenderText_Solid(font, "This is the world of Rogue3k.", textColor)) == NULL) {
        std::cerr << "Can't open message buffer!" << std::endl;
    }

    apply_surface(50, 550, message, screen);

    SDL_FreeSurface(message);

    if ((message = TTF_RenderText_Solid(font, "Press [Escape] do Die.", textColor)) == NULL) {
        std::cerr << "Can't open message buffer!" << std::endl;
    }

    apply_surface(50, 565, message, screen);

    SDL_FreeSurface(message);

    if ((message = TTF_RenderText_Solid(font, "Press [Enter] to Win.", textColor)) == NULL) {
        std::cerr << "Can't open message buffer!" << std::endl;
    }

    apply_surface(50, 580, message, screen);

    SDL_FreeSurface(message);

    if (!WorldScreen::world) {
        std::cout << "Creating a world" << std::endl;
        createWorld();
    } else {
        std::cout << "World already exists." << std::endl;
    }
}

WorldScreen::~WorldScreen()
{
    std::cout << "Cleaning up WorldScreen" << std::endl;
}

int WorldScreen::Update()
{
    return GameScreen::Update();
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

void WorldScreen::createWorld()
{
    WorldBuilder* worldbuilder = new WorldBuilder(90, 31);
    worldbuilder = worldbuilder->makeCaves();
    WorldScreen::world = worldbuilder->build();
    delete worldbuilder;
}
