#pragma once

#include <string>

#define MAP_W 64
#define MAP_H 29
// temporary for now, need to get a font that has characters with width and height the same.

#include "node.hpp"
#include "entity.hpp"
#include "tower.hpp"
#include "deco.hpp"
#include "projectile.hpp"

// World as in when you are in-game, as this class controls all of it

struct WorldClass
{
    std::string name;
    short current_wave = 0;  // Base game waves are not handwritten, a custom algorithm is used.
    short lives = 100;
    Node ai_nodes[255];
    Enemy enemies[255];
    Tower towers[255];
    Deco decorations[255];  // for the sake of making the maps a bit better to look at :)
    Projectile projectiles[255];  // good lord

    WorldClass() {}
};

WorldClass InitializeWorld(std::string mapname);