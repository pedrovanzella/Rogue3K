#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>
#include <SDL/SDL.h>
#include "tile.h"

class World
{
    private:
        std::vector<std::vector<Tile*>> tiles;
        int width;
        int height;
    public:
        World(std::vector<std::vector<Tile*>>);
        Tile* tile(int, int);

        // Top left coordinates
        void Draw(int, int);
};

#endif /* _WORLD_H_ */
