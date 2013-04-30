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
        char glyph(int, int);
        SDL_Color color(int, int);

        void Draw(SDL_Surface*, int, int);
};

#endif /* _WORLD_H_ */
