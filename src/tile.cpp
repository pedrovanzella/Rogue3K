#include <iostream>
#include <SDL/SDL.h>
#include "tile.h"

Tile::Tile(char g, SDL_Color c)
{
    std::cout << "making" << std::endl;
    glph = g;
    clr = c;
}

Tile* Tile::Floor()
{
    std::cout << "Making a Floor tile" << std::endl;
    SDL_Color c = FLOOR_COLOR;
    return new Tile('.', c);
}

Tile* Tile::Wall()
{
    std::cout << "Making a Wall tile" << std::endl;
    SDL_Color c = WALL_COLOR;
    return new Tile('#', c);
}

Tile* Tile::Bounds()
{
    std::cout << "Making a Bounds tile" << std::endl;
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
