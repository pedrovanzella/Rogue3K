#include "world_builder.h"
#include <vector>
#include <random>
#include <iostream>
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
    return fillWithEarth();
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
