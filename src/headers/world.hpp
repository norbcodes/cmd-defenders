#pragma once

#include <string>
#include <vector>
#include <memory>

#define MAP_W       64
#define MAP_H       29
// temporary for now, need to get a font that has characters with width and height the same.
#define DEFAULT_HEARTS  100

#include "node.hpp"
#include "entity.hpp"
#include "tower.hpp"
#include "deco.hpp"
#include "projectile.hpp"
#include "deathmarker.hpp"

// World as in when you are in-game, as this class controls all of it

#define MAP_SIZE            MAP_W * MAP_H
#define MAX_DECO            UINT8_MAX
#define MAX_ENEMIES         500
#define MAX_PROJECTILES     500

struct WorldClass
{
    std::string name;
    unsigned short current_wave;  // Base game waves are not handwritten, a custom algorithm is used.
    unsigned short lives;
    unsigned int money;

    std::unique_ptr<std::vector<Node>>           Ai_Nodes;
    std::unique_ptr<std::vector<Deco>>           Decorations;  // for the sake of making the maps a bit better to look at :)
    std::unique_ptr<std::vector<Enemy>>          Enemies;
    std::unique_ptr<std::vector<Tower>>          Towers;
    std::unique_ptr<std::vector<Projectile>>     Projectiles;  // good lord
    std::unique_ptr<std::vector<DeathMarker>>    Markers;

    WorldClass() {}

    void LinkNodes()
    {
        // Link nodes
        for (int i = 0; i != 255; i++)
        {
            if (i == 0)
            {
                continue;
            }

            if (((unsigned int)i) == (this->Ai_Nodes)->size())
            {
                break;
            }

            (*this->Ai_Nodes)[i-1].SetNext((*this->Ai_Nodes)[i]);
            (*this->Ai_Nodes)[i+1].SetPrev((*this->Ai_Nodes)[i]);
        }
        (*this->Ai_Nodes)[0].SetPrevNull();
        (*this->Ai_Nodes)[Ai_Nodes->size()-1].SetNextNull();
        // TODO: Debug this sometime
    }
};

// Including world.hpp in deathmarker.hpp will cause an error
// It HAS to be here.
void SpawnMarker(const Enemy& enemy, WorldClass& world);

void InitializeWorld(std::unique_ptr<WorldClass>& world, const std::string& mapname);