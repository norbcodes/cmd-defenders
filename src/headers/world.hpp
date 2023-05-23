#pragma once

#define MAP_W 64
#define MAP_H 29
// temporary for now, need to get a font that has characters with width and height the same.

#include <string>
#include "node.hpp"
#include "entity.hpp"
#include "tower.hpp"
#include "deco.hpp"
#include "projectile.hpp"

// World as in when you are in-game, as this class controls all of it

struct WorldClass
{
    short current_wave;  // Base game waves are not handwritten, a custom algorithm is used.
    short lives;
    Node* ai_nodes[255];
    Enemy* enemies[65535];
    Tower* towers[255];
    Deco* decorations[255];  // for the sake of making the maps a bit better to look at :)
    Projectile* projectiles[65535];  // good lord

    WorldClass()
    {
        this->current_wave = 0;
        this->lives = 100;
    }
};

WorldClass* Initialize(std::string mapname);