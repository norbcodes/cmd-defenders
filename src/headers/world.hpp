#pragma once

#include <string>
#include <vector>

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
    short current_wave;  // Base game waves are not handwritten, a custom algorithm is used.
    short lives;
    int money;

    std::vector<Node> Ai_Nodes;
    std::vector<Deco> Decorations;  // for the sake of making the maps a bit better to look at :)
    std::vector<Enemy> Enemies;
    std::vector<Tower> Towers;
    std::vector<Projectile> Projectiles;  // good lord

    WorldClass() {}

    void ReserveVectors()
    {
        this->Ai_Nodes.reserve(255);
        this->Decorations.reserve(255);
        this->Enemies.reserve(255);
        this->Towers.reserve(255);
        this->Projectiles.reserve(255);
    }

    void LinkNodes()
    {
        // Link nodes
        for (int i = 0; i != 255; i++)
        {
            if (i == 0)
            {
                continue;
            }

            Ai_Nodes[i-1].link = &(Ai_Nodes[i]);
        }
    }
};

WorldClass InitializeWorld(std::string mapname);