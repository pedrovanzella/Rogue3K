#include "tile.h"

Tile::Tile(char g, SDL_Color c)
{
    glph = g;
    clr = c;
}

Tile* Tile::Floor()
{
    return new Tile('.', FLOOR_COLOR);
}

Tile* Tile::Wall()
{
    return new Tile('#', WALL_COLOR);
}

Tile* Tile::Bounds()
{
    return new Tile('x', BOUNDS_COLOR);
}

char Tile::glyph()
{
    return glph;
}

SDL_Color Tile::color()
{
    return clr;
}
