#include <iostream>
#include "game_screen.h"

void GameScreen::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
    std::cout << "Applying surface" << std::endl;
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
    
    //Blit the surface
    if (source == NULL) {
        std::cerr << "NULL Source" << std::endl;
    }
    if (destination == NULL) {
        std::cerr << "NULL destination" << std::endl;
    }
    SDL_BlitSurface(source, NULL, destination, &offset);
}

SDL_Surface* GameScreen::currentScreen()
{
    return screen;
}

void GameScreen::setScreen(SDL_Surface* scr)
{
    screen = scr;
}

void GameScreen::respondToUserInput(SDL_Event&)
{
}

GameScreen::GameScreen()
{
}

GameScreen::~GameScreen()
{
    std::cout << "Cleaning up GameScreen" << std::endl;
    TTF_CloseFont(font);
    TTF_Quit();
}

void GameScreen::Init()
{
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

TTF_Font* GameScreen::gameFont()
{
    return font;
}
