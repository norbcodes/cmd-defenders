#pragma once

#include "entity.hpp"
#include "world.hpp"

/*
A big X anywhere where an enemy dies.
*/

struct DeathMarker
{
    char x;
    char y;
    int lifetime;
    char color;  // 1 - Orange; 2 - Blue; 3 - Red; 4 - Gray

    DeathMarker() : lifetime(0)
    {}

    DeathMarker(char x, char y, int lifetime, char color) : x(x), y(y), lifetime(lifetime), color(color)
    {}
};

void SpawnMarker(const Enemy& enemy, const WorldClass& world);