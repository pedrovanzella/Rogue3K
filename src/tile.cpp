#include <iostream>
#include <SDL/SDL.h>
#include <string>
#include "tile.h"
#include "renderer.h"

const int Tile::TILE_SIZE = 8;

Tile::Tile(char g, SDL_Color c)
{
    glph = g;
    clr = c;
}

Tile* Tile::Floor()
{
    SDL_Color c = FLOOR_COLOR;
    return new Tile('*', c);
}

Tile* Tile::Wall()
{
    SDL_Color c = WALL_COLOR;
    return new Tile('#', c);
}

Tile* Tile::Bounds()
{
    SDL_Color c = BOUNDS_COLOR;
    return new Tile('x', c);
}

void Tile::Draw(int x, int y)
{
    std::string s;
    s[0] = glph;
    Renderer::write_message_to_screen(clr.r, clr.g, clr.b, s.c_str(), x, y);
}
