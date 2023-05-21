#pragma once
#include "node.hpp"
#include "entity.hpp"
#include "tower.hpp"

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

    WorldClass()
    {
        /*
        Coming soon :P
        */
    }
};