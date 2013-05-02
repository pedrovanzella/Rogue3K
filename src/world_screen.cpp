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

    Renderer::clear_area(0, 0, 800, 600);
    Renderer::write_message_to_screen(255, 255, 0, "This is the world of Rogue3k.", 50, 550);
    Renderer::write_message_to_screen(255, 255, 0, "Press [Escape] to Die.", 50, 565);
    Renderer::write_message_to_screen(255, 255, 0, "Press [Enter] to Win.", 50, 580);

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
    world->Draw(25, 25);
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
    WorldBuilder* worldbuilder = new WorldBuilder(80, 51);
    worldbuilder = worldbuilder->makeCaves();
    WorldScreen::world = worldbuilder->build();
    delete worldbuilder;
}
