#include <iostream>
#include <string>
#include <math.h>
#include <bits/stdc++.h>
#include "headers/world.hpp"
#include "headers/node.hpp"

static char RendererCache[MAP_W * MAP_H];
// This is the first image that gets rendered, and it's only the path.
// Then we draw decorations, towers, enemies over it.

void GenerateCache(const WorldClass& world)
{
    // Generate the RendererCache.

    memset(RendererCache, ' ', sizeof(unsigned char) * (MAP_W * MAP_H));

    for (int i = 0; i != world.Ai_Nodes.size(); i++)
    {
        const Node& current_node = world.Ai_Nodes[i];
        if (current_node.GetNext() == nullptr)
        {
            break;
            // Final node, nothing to draw.
        }
        const Node& next_node = *(current_node.GetNext());

        // Find the direction
        if (current_node.y == next_node.y)
        {
            // Horizontal
            for (int i = fmin(current_node.x, next_node.x); i != fmax(current_node.x, next_node.x); i++)
            {
                RendererCache[i + (current_node.y * MAP_W)] = '@';
            }
        }

        if (current_node.x == next_node.x)
        {
            // Vertical
            for (int i = fmin(current_node.y, next_node.y); i != fmax(current_node.y, next_node.y) + 1; i++)
            {
                RendererCache[current_node.x + (i * MAP_W)] = '@';
            }
        }
    }
}