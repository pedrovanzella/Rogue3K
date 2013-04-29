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
            //std::cout << "Tile [" << x << "][" << y << "] is ";
            int g = distribution(generator);
            //std::cout << "[" << g << "] ";
            switch (g) {
                case 0:
                    ys.push_back(Tile::Floor());
                    //std::cout << "Floor" << std::endl;
                    break;
                case 1:
                    ys.push_back(Tile::Wall());
                    //std::cout << "Wall" << std::endl;
                    break;
            }
        }
        tiles.push_back(ys);
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
