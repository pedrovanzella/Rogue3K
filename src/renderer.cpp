#include "renderer.h"
#include <iostream>

SDL_Surface* Renderer::screen = NULL;
TTF_Font* Renderer::font = NULL;

void Renderer::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
    
    //Blit the surface
    SDL_BlitSurface(source, NULL, destination, &offset);
}

void Renderer::Init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    std::cout << "Creating SDL buffer" << std::endl;
    if ((screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE)) == NULL) {
        std::cerr << "Can't create screen!" << std::endl;
    }
    std::cout << "Initializing font" << std::endl;
    TTF_Init();
    if ((font = TTF_OpenFont("assets/VeraMono.ttf", 10)) == NULL) {
        std::cerr << "Can't open font!" << std::endl;
    }
}

int Renderer::Update()
{
    if (SDL_Flip(screen) == -1) {
        return -1;
    }
    return 1;
}

void Renderer::CloseRenderer()
{
    SDL_FreeSurface(screen);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}

void Renderer::write_message_to_screen(int r, int g, int b, std::string msg, int x, int y)
{
    SDL_Color textColor = {static_cast<Uint8>(r), static_cast<Uint8>(g), static_cast<Uint8>(b)};
    SDL_Surface* message = TTF_RenderText_Solid(font, msg.c_str(), textColor);
    apply_surface(x, y, message, screen);
    SDL_FreeSurface(message);
}

void Renderer::set_window_title(std::string title)
{
    SDL_WM_SetCaption(title.c_str(), NULL);
}

void Renderer::clear_area(int x, int y, int w, int h)
{
    SDL_Rect area;
    area.x = x;
    area.y = y;
    area.w = w;
    area.h = h;

    SDL_FillRect(screen, &area, 0x000000);
}
