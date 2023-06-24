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

    char TrackMarker = '@';  // doesn't have to be that, can be anything really

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
                RendererCache[i + (current_node.y * MAP_W)] = TrackMarker;
            }
        }

        if (current_node.x == next_node.x)
        {
            // Vertical
            for (int i = fmin(current_node.y, next_node.y); i != fmax(current_node.y, next_node.y) + 1; i++)
            {
                RendererCache[current_node.x + (i * MAP_W)] = TrackMarker;
            }
        }
    }

    for (int i = 0; i != MAP_W * MAP_H; i++)
    {
        /*
        Each cell and their value:
        
           8
        2  x   4
           1 

        We check each adjacent tile and add their value to the final score.
        Then we use to score in a lookup table to get the character to render.

        */
        unsigned char score = 0b00000000;  // A value from 0 - 255.

        // Check tiles right below us and above us.
        if (RendererCache[i + MAP_W] == TrackMarker)
        {
            score = score | 0b00000001;
        }

        if (RendererCache[i - MAP_W] == TrackMarker)
        {
            score = score | 0b00001000;
        }

        // Check tiles on the right and left to us.
        if (RendererCache[i - 1] == TrackMarker)
        {
            score = score | 0b00000010;
        }

        if (RendererCache[i + 1] == TrackMarker)
        {
            score = score | 0b00000100;
        }
    }
}