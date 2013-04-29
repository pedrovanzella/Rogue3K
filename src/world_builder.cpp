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
        for (int y = 0; y <= height; y++) {
            std::default_random_engine generator;
            std::uniform_int_distribution<int> distribution(0,1);
            std::cout << "Tile [" << x << "][" << y << "] is ";
            switch (distribution(generator)) {
                case 0:
                    tiles[x][y] = Tile::Floor();
                    std::cout << "Floor" << std::endl;
                case 1:
                    tiles[x][y] = Tile::Wall();
                    std::cout << "Wall" << std::endl;
            }
        }
    }
    return this;
}

WorldBuilder* WorldBuilder::smooth(int times)
{
    return this;
}

WorldBuilder* WorldBuilder::makeCaves()
{
    return randomizeTiles()->smooth(8);
}
