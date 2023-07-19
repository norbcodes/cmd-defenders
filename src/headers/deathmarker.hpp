#pragma once

#define MARKER_LIFETIME 60  // for now

#include "entity.hpp"

/*
A big X anywhere where an enemy dies.
*/

struct DeathMarker
{
    unsigned char x;
    unsigned char y;
    unsigned int lifetime;
    unsigned char color;  // 0 - Orange; 1 - Blue; 2 - Red; 3 - Gray

    DeathMarker() : x(-1), y(-1), lifetime(0)
    {}

    DeathMarker(unsigned char x, unsigned char y, unsigned int lifetime, unsigned char color) : x(x), y(y), lifetime(lifetime), color(color)
    {}
};