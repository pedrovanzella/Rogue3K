#ifndef _WORLD_BUILDER_H_
#define _WORLD_BUILDER_H_
#include <vector>
#include <random>
#include "tile.h"
#include "world.h"

class WorldBuilder
{
    private:
        std::vector<std::vector<Tile*>> tiles;
        int width;
        int height;

        // For cellular automata
        WorldBuilder* randomizeTiles();
        WorldBuilder* smooth(int);

        // For rooms
        WorldBuilder* fillWithEarth();
        WorldBuilder* makeRoom(int, int, int, int);
        WorldBuilder* joinRooms(int, int, int, int, int, int, int, int);
        bool isThereARoomHere(int, int, int, int);

    public:
        WorldBuilder(int, int);
        World* build();
        WorldBuilder* makeCaves();
};

#endif /* _WORLD_BUILDER_H_ */
