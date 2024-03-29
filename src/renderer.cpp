#include <iostream>
#include <string>
#include <math.h>
#include <unordered_map>

#include "headers/world.hpp"
#include "headers/node.hpp"
#include "headers/ui.hpp"

#include "headers/utils.hpp"

#include "headers/debug.hpp"

#define SCREEN_W 97
#define SCREEN_H 30  // 28 + 2
#define UiSep       "+-----------------------------------------------------------------+------------------------------+"
#define UiEmpty     "|                                                                 |                              |"
#define UiLineSep   "|                                                                 | ---------------------------- |"

static std::string RendererCache;
static std::string ScreenCache;
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

static void Blit(std::string& buffer, unsigned int x, unsigned int y, unsigned int height, unsigned int width, const std::string& txt, const std::string& styles)
{
    // A handy function that blits text to the screen buffer
    // or anything really
    buffer.insert(GetIndexFromPos(x, y, width), styles);
    unsigned int current_x = 0; unsigned int current_y = 0;
    unsigned int indx = 0;
    while (indx != (height * width))
    {
        buffer[GetIndexFromPos(current_y + y, current_x + x, width)] = txt[indx];
        current_x += 1;
        if (current_x == width) { current_x = 0; current_y += 1; }
        indx += 1;
    }
}

static void GenerateScreenCache()
{
    ScreenCache += UiSep + '\n';
    ScreenCache += UiEmpty + '\n';
    ScreenCache += UiEmpty + '\n';
    ScreenCache += UiLineSep + '\n';
    for (int i = 0; i != 17; i++) { ScreenCache += UiEmpty + '\n'; }
    ScreenCache += UiLineSep + '\n';
    for (int i = 0; i != 3; i++) { ScreenCache += UiEmpty + '\n'; }
    ScreenCache += UiLineSep + '\n';
    for (int i = 0; i != 3; i++) { ScreenCache += UiEmpty + '\n'; }
    ScreenCache += UiSep;
}

void GenerateCache(const WorldClass& world)
{
    // Initialize the CharacterMap.
    InitializeMap();

    // Generate the RendererCache.

    for (int i = 0; i != MAP_H * MAP_W; i++)
    {
        RendererCache += ' ';
    }

    const char TrackMarker = '@';  // doesn't have to be that, can be anything really

    DEBUG_PRINT_WAIT("Write track markers");

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

    DEBUG_PRINT_WAIT("Write track edges");

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

    DEBUG_PRINT_WAIT("Done");
    #ifdef _NORB_DEBUG_
    DefendersUtils::ClearConsole();
    #endif // _NORB_DEBUG_

    // All done, cache generated, now delete all track markers
    for (int i = 0; i != (MAP_H * MAP_W); i++)
    {
        if (RendererCache[i] == TrackMarker)
        {
            RendererCache[i] = ' ';
        }
    }
    // Cache generated. Can be used by the rendering function now.
    GenerateScreenCache();
}

void Render(const WorldClass& world)
{
    RestoreCursor();
    std::string OutputBuff;
    for (int i = 0; i != SCREEN_W * SCREEN_H; i++) { OutputBuff += ' '; }
    Blit(OutputBuff, 0, 0, SCREEN_H, SCREEN_W, ScreenCache, BoldText());
    std::cout << OutputBuff;
}