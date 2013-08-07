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

    while(!makeRoom(x, y, w, h)) {
        x = x_distribution(generator);
        w = width_distribution(generator);
        y = y_distribution(generator);
        h = height_distribution(generator);
        std::cout << "Failed to build first room. Retrying." << std::endl;
    }

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
            x = nx;
            y = ny;
            w = nw;
            h = nh;
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
    int room_a_x = distribution_for_xa(generator);

    std::uniform_int_distribution<int> distribution_for_ya(ya, ya + ha - 1);
    int room_a_y = distribution_for_ya(generator);

    std::uniform_int_distribution<int> distribution_for_xb(xb, xb + wb - 1);
    int room_b_x = distribution_for_xb(generator);

    std::uniform_int_distribution<int> distribution_for_yb(yb, yb + hb - 1);
    int room_b_y = distribution_for_yb(generator);

    std::cout << std::endl << "[=] Connecting:\t\tA(" << room_a_x << ", " << room_a_y << ");\tB(" << room_b_x << ", " << room_b_y << ")" << std::endl;

    /* Draw a corridor */
    std::bernoulli_distribution chance(0.5);
    //if (chance(generator)) {
    if (true) {
        std::cout << "Vertical -> Horizontal" << std::endl;
        /* Half the time, draw vertical then horizontal */

        /* Case 1 */
        if (xa <= xb && ya <= yb) {
            for (int i = room_a_x; i <= room_b_x; i++) {
                tiles[i][room_a_y] = Tile::Floor();
            }
            for (int j = room_a_y; j <= room_b_y; j++) {
                tiles[room_b_x][j] = Tile::Floor();
            }
        }

        /* Case 2 */
        if (xa <= xb && ya >= yb) {
            for (int i = room_a_x; i <= room_b_x; i++) {
                tiles[i][room_a_y] = Tile::Floor();
            }
            for (int j = room_b_y; j <= room_a_y; j++) {
                tiles[room_b_x][j] = Tile::Floor();
            }
        }

        /* Case 3 */
        if (xa >= xb && ya <= yb) {
            for (int i = room_b_x; i <= room_a_x; i++) {
                tiles[i][room_a_y] = Tile::Floor();
            }
            for (int j = room_a_y; j <= room_b_y; j++) {
                tiles[room_b_x][j] = Tile::Floor();
            }
        }

        /* Case 4 */
        if (xa >= xb && ya >= yb) {
            for (int i = room_b_x; i <= room_a_x; i++) {
                tiles[i][room_a_y] = Tile::Floor();
            }
            for (int j = room_b_y; j <= room_a_y; j++) {
                tiles[room_b_x][j] = Tile::Floor();
            }
        }
    } else {
        std::cout << "Horizontal -> Vertical" << std::endl;
        /* Half the time, draw horizontal then vertical */
    }

    return this;
}
