#include <iostream>
#include <SDL/SDL.h>
#include "tile.h"

Tile::Tile(char g, SDL_Color c)
{
    glph = g;
    clr = c;
}

Tile* Tile::Floor()
{
    SDL_Color c = FLOOR_COLOR;
    return new Tile('.', c);
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

char Tile::glyph()
{
    return glph;
}

SDL_Color Tile::color()
{
    return clr;
}

void Tile::Draw(SDL_Surface* screen, int x, int y)
{
}
