#include "world.h"
#include <vector>

using std::vector;

World::World(vector<vector<Tile*>> ts)
{
    tiles = ts;
    width = ts.size();
    height = ts[0].size();
}

Tile* World::tile(int x, int y)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
        return Tile::Bounds();
    else
        return tiles[x][y];
}

char World::glyph(int x, int y)
{
    return tile(x, y)->glyph();
}

SDL_Color World::color(int x, int y)
{
    return tile(x, y)->color();
}

void World::Draw(int x, int y)
{
    for (int i = 0; i < tiles.size(); i++) {
        for (int j = 0; j < tiles[0].size(); j++) {
            tiles[i][j]->Draw(x + i * Tile::TILE_SIZE, y + j * Tile::TILE_SIZE);
        }
    }
}
