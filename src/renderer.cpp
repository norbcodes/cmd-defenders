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

    for (int i = 0; i != world.Ai_Nodes.size(); i++)
    {
        const Node& node = world.Ai_Nodes[i];
        //if (node.GetNext() == nullptr)
        //{
        //    break;
            // There is literally no node to draw a line to
        //}
        const Node& node_next = *(node.GetNext());
        // Ok so basically we are getting the references to both the node we are currently on and the linked one

        // Figure out the direction to draw in
        if (node.x == node_next.x)
        {
            // Horizontal
            for (int i = fmin(node.x, node_next.x); i != fmax(node.x, node_next.x); i++)
            {
                RendererCache[i + (node.y * MAP_W)] = '@';
            }
        }

        if (node.y == node_next.y)
        {
            // vertical
            for (int i = fmin(node.y, node_next.y); i != fmax(node.y, node_next.y); i++)
            {
                RendererCache[node.x + (i * MAP_W)] = '@';
            }
        }
    }
}