#include <iostream>
#include "game_screen.h"

void GameScreen::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
    
    //Blit the surface
    SDL_BlitSurface(source, NULL, destination, &offset);
}

GameScreen* GameScreen::respondToUserInput(SDL_Event&)
{
    return this;
}

GameScreen::GameScreen()
{
    std::cout << "Initializing GameScreen" << std::endl;
    Init();
}

GameScreen::~GameScreen()
{
    std::cout << "Cleaning up GameScreen" << std::endl;
    SDL_FreeSurface(screen);
    TTF_CloseFont(font);
    TTF_Quit();
}

void GameScreen::Init()
{
    std::cout << "Creating SDL buffer" << std::endl;
    if ((screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE)) == NULL) {
        std::cerr << "Can't create screen!" << std::endl;
    }
    InitFont();
}

void GameScreen::InitFont()
{
    std::cout << "Initializing font" << std::endl;
    TTF_Init();
    if ((font = TTF_OpenFont("assets/VeraMono.ttf", 10)) == NULL) {
        std::cerr << "Can't open font!" << std::endl;
    }
}

int GameScreen::Update()
{
    if (SDL_Flip(screen) == -1) {
        return -1;
    }
    return 1;
}
