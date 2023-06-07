#include <iostream>
#include <string>
#include "headers/world.hpp"

static std::string RendererCache[MAP_W * MAP_H];
// This is the first image that gets rendered, and it's only the path.
// Then we draw decorations, towers, enemies over it.

struct NodeInfo
{
    char x;
    char y;
    // Up | Down | Right | Left
    bool LinkDirs[4] = {0, 0, 0, 0};
};

void GenerateCache(const WorldClass& world)
{
    // Generate the RendererCache.

    // To be reworked...
}