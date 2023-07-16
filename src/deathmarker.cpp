#include <math.h>

#include "headers/deathmarker.hpp"
#include "headers/world.hpp"
#include "headers/entity.hpp"

void SpawnMarker(const Enemy& enemy, WorldClass& world)
{
    world.Markers.emplace_back(
        (char)floor(enemy.x),
        (char)floor(enemy.y),
        MARKER_LIFETIME,
        (char)enemy.GetWeaknesses().color
    );
}