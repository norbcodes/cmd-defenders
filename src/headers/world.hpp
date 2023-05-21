#pragma once
#include <string>
#include "node.hpp"
#include "entity.hpp"
#include "tower.hpp"
#include "deco.hpp"

// World as in when you are in-game, as this class controls all of it

struct WorldClass
{
    char width;
    char height;
    short current_wave;  // Base game waves are not handwritten, a custom algorithm is used.
    short lives;
    Node* ai_nodes[255];
    Enemy* enemies[65535];
    Tower* towers[255];
    Deco* decorations[255];  // for the sake of making the maps a bit better to look at :)

    WorldClass(char width, char height)
    {
        this->width = width;
        this->height = height;
        this->current_wave = 0;
        this->lives = 100;
    }
};

WorldClass* Initialize(std::string mapname);