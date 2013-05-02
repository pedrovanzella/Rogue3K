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
    Tile* t = new Tile('*', c);
    t->tp = TILE_TYPE_FLOOR;
    return t;
}

Tile* Tile::Wall()
{
    SDL_Color c = WALL_COLOR;
    Tile* t = new Tile('#', c);
    t->tp = TILE_TYPE_WALL;
    return t;
}

Tile* Tile::Bounds()
{
    SDL_Color c = BOUNDS_COLOR;
    Tile* t = new Tile('x', c);
    t->tp = TILE_TYPE_BOUNDS;
    return t;
}

void Tile::Draw(int x, int y)
{
    std::string s;
    s[0] = glph;
    Renderer::write_message_to_screen(clr.r, clr.g, clr.b, s.c_str(), x, y);
}

int Tile::type()
{
    return tp;
}
