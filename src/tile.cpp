#include "tile.h"

Tile::Tile(char g, SDL_Color c)
{
    glyph = g;
    color = c;
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
