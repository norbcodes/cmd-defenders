#include <iostream>
#include <string>
#include <math.h>
#include "headers/world.hpp"
#include "headers/node.hpp"

static std::string RendererCache[MAP_W * MAP_H];
// This is the first image that gets rendered, and it's only the path.
// Then we draw decorations, towers, enemies over it.

/*
struct NodeInfo
{
    char x;
    char y;
    // Up | Down | Right | Left
    bool LinkDirs[4] = {0, 0, 0, 0};
};
*/

void GenerateCache(const WorldClass& world)
{
    // Generate the RendererCache.

    for (int i = 0; i != world.Ai_Nodes.size(); ++i)
    {
        // CODE GOES HERE
        // Bug is squashed. Tomorrow comes big stuff.
    }
}