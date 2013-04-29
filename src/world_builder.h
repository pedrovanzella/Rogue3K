#ifndef _WORLD_BUILDER_H_
#define _WORLD_BUILDER_H_
#include <vector>
#include "tile.h"
#include "world.h"

class WorldBuilder
{
    private:
        std::vector<std::vector<Tile*>> tiles;
        int width;
        int height;

        WorldBuilder* randomizeTiles();
        WorldBuilder* smooth(int);
    public:
        WorldBuilder(int, int);
        World* build();
        WorldBuilder* makeCaves();
};

#endif /* _WORLD_BUILDER_H_ */
