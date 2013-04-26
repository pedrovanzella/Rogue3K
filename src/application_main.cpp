#include <iostream>
#include "application_main.h"
#include "game_screen.h"
#include "start_screen.h"

ApplicationMain::ApplicationMain()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    quit = false;
}

ApplicationMain::~ApplicationMain()
{
    std::cout << "Cleaning up..." << std::endl;
    delete gameScreen;
    SDL_Quit();
}

int ApplicationMain::Init()
{
    SDL_WM_SetCaption("Rogue3k", NULL);

    gameScreen = new StartScreen();
 
    return 1;
}

int ApplicationMain::Update()
{
    return gameScreen->Update();
}

void ApplicationMain::mainLoop()
{
    while (!quit) {
        // Update our screen
        Update();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
                break;
            }
            GameScreen* oldgameScreen = gameScreen;
            gameScreen = gameScreen->respondToUserInput(event);
            if (oldgameScreen != gameScreen) {
                delete oldgameScreen;
            }
        }
    }
}
