#ifndef _TILE_H_
#define _TILE_H_
#include <SDL/SDL.h>
#include "renderer.h"

#define FLOOR_COLOR {0, 140, 120}
#define WALL_COLOR {255, 255, 0}
#define BOUNDS_COLOR {250, 50, 0}

class Tile
{
    private:
        char glph;
        SDL_Color clr;

    public:
        static const int TILE_SIZE;

        Tile(char, SDL_Color);
        
        static Tile* Floor();
        static Tile* Wall();
        static Tile* Bounds();

        void Draw(int, int);
};

#endif /* _TILE_H_ */
