#include <iostream>
#include "application_main.h"
#include "game_screen.h"
#include "start_screen.h"

ApplicationMain::ApplicationMain()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = NULL;
    quit = false;
}

ApplicationMain::~ApplicationMain()
{
    std::cout << "Cleaning up..." << std::endl;
    SDL_Quit();
}

int ApplicationMain::Init()
{
    if ((screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE)) == NULL) {
        std::cerr << "Can't create screen!" << std::endl;
        return -1;
    }
    SDL_WM_SetCaption("Rogue3k", NULL);

    gameScreen = StartScreen(screen);
 
    return 1;
}

int ApplicationMain::Update()
{
    screen = gameScreen.currentScreen();
    if (SDL_Flip(screen) == -1) {
        return -1;
    }
    return 1;
}

void ApplicationMain::mainLoop()
{
    while (!quit) {
        // Update our screen
        Update();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }
}
