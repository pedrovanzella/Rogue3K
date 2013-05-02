#include <iostream>
#include "game_screen.h"
#include "renderer.h"

GameScreen* GameScreen::respondToUserInput(SDL_Event&)
{
    return this;
}

GameScreen::GameScreen()
{
    std::cout << "Initializing GameScreen" << std::endl;
}

GameScreen::~GameScreen()
{
    std::cout << "Cleaning up GameScreen" << std::endl;
    Renderer::CloseRenderer();
}

int GameScreen::Update()
{
    return Renderer::Update();
}
