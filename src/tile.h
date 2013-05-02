#ifndef _TILE_H_
#define _TILE_H_
#include <SDL/SDL.h>
#include "renderer.h"

#define FLOOR_COLOR {0, 140, 120}
#define WALL_COLOR {255, 255, 0}
#define BOUNDS_COLOR {250, 50, 0}

// Poor man's introspection
#define TILE_TYPE_FLOOR 0
#define TILE_TYPE_WALL 1
#define TILE_TYPE_BOUNDS 2

class Tile
{
    private:
        char glph;
        SDL_Color clr;
        int tp;

    public:
        static const int TILE_SIZE;

        Tile(char, SDL_Color);
        
        static Tile* Floor();
        static Tile* Wall();
        static Tile* Bounds();

        int type();

        void Draw(int, int);
};

#endif /* _TILE_H_ */
