#include <string>
#include <vector>
#include <iostream>
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

void GenerateCache(WorldClass* world)
{
    // Generate the RendererCache.

    std::vector<NodeInfo> NodeInfos;
    std::vector<int> NodeCoords;
    NodeInfos.reserve(255); NodeCoords.reserve(255);
    // Do stuff
    for (std::vector<Node>::iterator i = world->Ai_Nodes.begin(); i != world->Ai_Nodes.end(); ++i)
    {
    }
}