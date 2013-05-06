#include "world_builder.h"
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include "tile.h"
#include "world.h"

using std::vector;

WorldBuilder::WorldBuilder(int x, int y)
{
    width = x;
    height = y;
}

World* WorldBuilder::build()
{
    return new World(tiles);
}

WorldBuilder* WorldBuilder::randomizeTiles()
{
    std::cout << "Randomizing Tiles" << std::endl;
    for (int x = 0; x <= width; x++) {
        vector<Tile *> ys;
        for (int y = 0; y <= height; y++) {
            std::uniform_int_distribution<int> distribution(0,1);
            std::random_device rd;
            std::default_random_engine generator(rd());
            int g = distribution(generator);
            switch (g) {
                case 0:
                    ys.push_back(Tile::Floor());
                    break;
                case 1:
                    ys.push_back(Tile::Wall());
                    break;
            }
        }
        tiles.push_back(ys);
    }
    return this;
}

WorldBuilder* WorldBuilder::smooth(int times)
{
    std::cout << "Smoothing world" << std::endl;
    std::vector<std::vector<Tile*>> tiles2;
    vector<Tile*> ys;
    for (int i = 0; i < times; i++) {
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                int floors = 0;
                int rocks = 0;

                for (int ox = -1; ox < 2; ox++) {
                    for (int oy = -1; oy < 2; oy++) {
                        if (x + ox < 0 || x + ox >= width || y + oy < 0 || y + oy >= height) {
                            continue;
                        }
                        if (tiles[x + ox][y + oy]->type() == TILE_TYPE_FLOOR) {
                            floors++;
                        } else {
                            rocks++;
                        }
                    }
                }
                if (floors >= rocks) {
                    ys.push_back(Tile::Floor());
                } else {
                    ys.push_back(Tile::Wall());
                }
            }
            tiles2.push_back(ys);
        }
        tiles = tiles2;
    }
    return this;
}

WorldBuilder* WorldBuilder::makeCaves()
{
    std::random_device rd;
    std::default_random_engine generator(rd());

    std::uniform_int_distribution<int> width_distribution(6, 11);
    std::uniform_int_distribution<int> height_distribution(6, 11);
    std::uniform_int_distribution<int> x_distribution(0, width);
    std::uniform_int_distribution<int> y_distribution(0, height);

    std::uniform_int_distribution<int> room_num_distribution(5, 17);

    // Start with walls all around
    fillWithEarth();

    // Draw a first room
    int x = x_distribution(generator);
    int w = width_distribution(generator);
    int y = y_distribution(generator);
    int h = height_distribution(generator);

    makeRoom(x, y, w, h);

    for (int i = 0; i <= room_num_distribution(generator); i++) {
        int nx = x_distribution(generator);
        int nw = width_distribution(generator);
        int ny = y_distribution(generator);
        int nh = height_distribution(generator);

        if (!makeRoom(nx, ny, nw, nh)) {
            // If we went off borders
            std::cout << "Invalid room. Retrying." << std::endl;
            continue;
        }

        joinRooms(x, y, w, h, nx, ny, nw, nh);

        std::bernoulli_distribution chance(0.5);

        if (chance(generator)) {
            std::cout << "Continuing from newly created room" << std::endl;
            x = nx;
            y = ny;
            w = nw;
            h = nh;
            std::cout << "\t (" << x << ", " << y << ") -> (" << x + w << ", " << y + h << ")" << std::endl;
        } else {
            std::cout << "Continuing from old room" << std::endl;
            std::cout << "\t (" << x << ", " << y << ") -> (" << x + w << ", " << y + h << ")" << std::endl;
        }
    }

    return this;
}

WorldBuilder* WorldBuilder::fillWithEarth()
{
    for (int x = 0; x < width; x++) {
        vector<Tile*> ys;
        for (int y = 0; y < height; y++) {
            ys.push_back(Tile::Wall());
        }
        tiles.push_back(ys);
    }
    return this;
}

WorldBuilder* WorldBuilder::makeRoom(int x, int y, int w, int h)
{
    /* Make sure we don't go off borders */
    if (isThereARoomHere(x, y, w, h)) {
        return NULL;
    }
    std::cout << "Making a room in (" << x << ", " << y << ") -> (" << x + w << ", " << y + h << ")" << std::endl;
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + h; j++) {
            tiles[i][j] = Tile::Floor();
        }
    }
    return this;
}

bool WorldBuilder::isThereARoomHere(int x, int y, int w, int h)
{
    if (x + w >= width || y + h >= height) {
        // Technically not true, I know.
        return true;
    }
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + h; j++) {
            if (tiles[i][j]->type() == TILE_TYPE_FLOOR) {
                return true;
            }
        }
    }
    return false;
}

WorldBuilder* WorldBuilder::joinRooms(int xa, int ya, int wa, int ha, int xb, int yb, int wb, int hb)
{
    std::random_device rd;
    std::default_random_engine generator(rd());

    /* Randomly select points inside both rooms */
    std::uniform_int_distribution<int> distribution_for_xa(xa, xa + wa - 1);
    int rcax = distribution_for_xa(generator);

    std::uniform_int_distribution<int> distribution_for_ya(ya, ya + ha - 1);
    int rcay = distribution_for_ya(generator);

    std::uniform_int_distribution<int> distribution_for_xb(xb, xb + wb - 1);
    int rcbx = distribution_for_xb(generator);

    std::uniform_int_distribution<int> distribution_for_yb(yb, yb + hb - 1);
    int rcby = distribution_for_yb(generator);

    /* Draw a corridor */
    int max_x = std::max(rcax, rcbx);
    int max_y = std::max(rcay, rcby);
    int min_x = std::min(rcax, rcbx);
    int min_y = std::min(rcay, rcby);

    int new_axis_min;
    int new_axis_max;
    if (rcax < rcbx && rcay < rcby) {
        new_axis_min = max_y;
        new_axis_max = min_y;
    } else {
        new_axis_min = min_y;
        new_axis_max = max_y;
    }

    std::cout << "Connecting: [" << min_x << ", " << min_y << "] -> [" << max_x << ", " << max_y << "]" << std::endl;

    std::bernoulli_distribution chance(0.5);
    if (chance(generator)) {
        std::cout << "Vertical -> Horizontal" << std::endl;
        /* Half the time, draw vertical then horizontal */
        for (int i = min_y; i <= max_y; i++) {
            tiles[min_x][i] = Tile::Floor();
        }
        for (int j = min_x; j <= max_x; j++) {
            tiles[j][new_axis_min] = Tile::Floor();
        }
    } else {
        std::cout << "Horizontal -> Vertical" << std::endl;
        /* Half the time, draw horizontal then vertical */
        for (int j = min_x; j <= max_x; j++) {
            tiles[j][new_axis_max] = Tile::Floor();
        }
        for (int i = min_y; i <= max_y; i++) {
            tiles[max_x][i] = Tile::Floor();
        }
    }

    return this;
}
