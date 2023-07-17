#include <math.h>

#include "headers/deathmarker.hpp"
#include "headers/world.hpp"
#include "headers/entity.hpp"

void SpawnMarker(const Enemy& enemy, WorldClass& world)
{
    world.Markers.emplace_back(
        (unsigned char)floor(enemy.x),
        (unsigned char)floor(enemy.y),
        MARKER_LIFETIME,
        (unsigned char)enemy.GetWeaknesses().color
    );
}