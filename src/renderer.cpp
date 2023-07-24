#include <iostream>
#include <string>
#include <math.h>
#include <bits/stdc++.h>
#include <unordered_map>

#include "headers/world.hpp"
#include "headers/node.hpp"
#include "headers/ui.hpp"

#include "headers/debug.hpp"

#define SCREEN_W 97
#define SCREEN_H 30  // 28 + 2

static char RendererCache[MAP_W * MAP_H];
static char ScreenLayout[SCREEN_W * SCREEN_H];
// This is the first image that gets rendered, and it's only the path.
// Then we draw decorations, towers, enemies over it.

static std::unordered_map<unsigned char, char> CharacterMap;

/*
Each cell and their value:

    8
2   x   4
    1 

We check each adjacent tile and add their value to the final score.
Then we use to score in a lookup table to get the character to render.
We also check corners, and if any is detected then the score is automatically 128.
*/

static void InitializeMap()
{
    CharacterMap.reserve(17);
    CharacterMap[0b00000000] = ' ';
    CharacterMap[0b00000001] = '-';
    CharacterMap[0b00000010] = '|';
    CharacterMap[0b00000011] = '+';
    CharacterMap[0b00000100] = '|';
    CharacterMap[0b00000101] = '+';
    CharacterMap[0b00000110] = '|';
    CharacterMap[0b00000111] = '+';
    CharacterMap[0b00001000] = '-';
    CharacterMap[0b00001001] = '-';
    CharacterMap[0b00001010] = '+';
    CharacterMap[0b00001011] = '+';
    CharacterMap[0b00001100] = '+';
    CharacterMap[0b00001101] = '+';
    CharacterMap[0b00001110] = '+';
    CharacterMap[0b00001111] = '+';
    CharacterMap[0b10000000] = '+';
}

static void GenerateScreenLayoutCache()
{
    char LineSep[SCREEN_W];
    char Edges[SCREEN_W];

    ////////////////////////////////////////
    // GENERATE INDIVIDUAL COMPONENTS     //
    ////////////////////////////////////////

    DEBUG_PRINT("Linesep gen");

    // Generate the Line Sep
    LineSep[0] = '+';
    for (int i = 1; i != MAP_W; i++)
    {
        LineSep[i] = '-';
    }
    LineSep[MAP_W] = '+';  // 64th index, right after the last -
    for (int i = 65; i != SCREEN_W; i++)
    {
        LineSep[i] = '-';  // Because of the UI
    }
    LineSep[SCREEN_W] = '+';  // The very last index. And we're done!

    DEBUG_PRINT("Edge gen");

    // Generate the Edges
    Edges[0] = '|';
    for (int i = 1; i != MAP_W; i++)
    {
        Edges[i] = ' ';
    }
    Edges[MAP_W] = '|';
    for (int i = 65; i != SCREEN_W; i++)
    {
        Edges[i] = ' ';
    }
    Edges[SCREEN_W] = '|';  // And we're done with both of these!

    ////////////////////////////////////////
    // NOW START GENERATING               //
    ////////////////////////////////////////

    DEBUG_PRINT("Layout gen");

    // Top linesep
    for (int i = 0; i != SCREEN_W; i++)
    {
        ScreenLayout[i] = LineSep[i];
    }

    DEBUG_PRINT("Juicy part begin");

    // Now for the juicy part
    for (int y = 0; y != SCREEN_H; y++)
    {
        for (int x = 0 + (SCREEN_H * y); x != (SCREEN_H * (y + 1)); x++)
        {
            ScreenLayout[x] = Edges[ x - (SCREEN_H * (y + 1)) ];
        }
    }
    // Also there are no \n characters in there, no
    // That's done during rendering

    DEBUG_PRINT("Juicy part over");

    for (int i = (SCREEN_W * SCREEN_H) - SCREEN_H; i != SCREEN_W * SCREEN_H; i++)
    {
        ScreenLayout[i] = LineSep[i - (SCREEN_W * SCREEN_H) - SCREEN_H];
    }

    DEBUG_PRINT("Gen finished successfully");
}

static void Blit(std::string& buffer, unsigned int x, unsigned int y, const std::string& txt, const std::string& styles)
{
    // A handy function that blits text to the screen buffer

}

void GenerateCache(const WorldClass& world)
{
    // Initialize the CharacterMap.
    InitializeMap();

    // Generate the RendererCache.

    const char TrackMarker = '@';  // doesn't have to be that, can be anything really

    memset(RendererCache, ' ', sizeof(unsigned char) * (MAP_W * MAP_H));

    // Draw Track markers in the RendererCache
    for (unsigned int i = 0; i != (*(world.Ai_Nodes)).size(); i++)
    {
        const Node& current_node = (*(world.Ai_Nodes))[i];
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
        // Are we on the track?
        // If yes, do not advance further.
        if (RendererCache[i] == TrackMarker)
        {
            continue;
        }

        unsigned char score = 0b00000000;  // A value from 0 - 255.

        // Check tile right below us.
        if (RendererCache[i + MAP_W] == TrackMarker)
        {
            score = score | 0b00000001;
        }

        // Check tile right above us.
        if (RendererCache[i - MAP_W] == TrackMarker)
        {
            score = score | 0b00001000;
        }

        // Check tiles on the right to us.
        if (RendererCache[i - 1] == TrackMarker)
        {
            score = score | 0b00000010;
        }

        // Check tiles on the left to us.
        if (RendererCache[i + 1] == TrackMarker)
        {
            score = score | 0b00000100;
        }

        // Check corner tiles, all of them
        if ((RendererCache[i + MAP_W + 1] == TrackMarker ||
             RendererCache[i + MAP_W - 1] == TrackMarker ||
             RendererCache[i - MAP_W + 1] == TrackMarker ||
             RendererCache[i - MAP_W - 1] == TrackMarker) &&
            score == 0)
        {
            score = score | 0b10000000;
        }

        RendererCache[i] = CharacterMap[score];
    }

    // All done, cache generated, now delete all track markers
    for (int i = 0; i != (MAP_H * MAP_W); i++)
    {
        if (RendererCache[i] == TrackMarker)
        {
            RendererCache[i] = ' ';
        }
    }

    // Cache generated. Can be used by the rendering function now.
    // Also generate screen layout pls
    GenerateScreenLayoutCache();
}

void Render(const WorldClass& world)
{
    RestoreCursor();

    std::string OUTPUT[SCREEN_H * SCREEN_W];

}