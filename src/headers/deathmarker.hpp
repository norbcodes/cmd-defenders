#pragma once

#define MARKER_LIFETIME 60  // for now

#include "entity.hpp"

/*
A big X anywhere where an enemy dies.
*/

struct DeathMarker
{
    char x;
    char y;
    int lifetime;
    char color;  // 0 - Orange; 1 - Blue; 2 - Red; 3 - Gray

    DeathMarker() : lifetime(0)
    {}

    DeathMarker(char x, char y, int lifetime, char color) : x(x), y(y), lifetime(lifetime), color(color)
    {}
};