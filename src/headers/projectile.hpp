#pragma once
#include <math.h>
#include "entity.hpp"
#include "tower.hpp"

/*
Projectile class and code.
*/

struct Projectile
{
    float x;
    float y;
    float angle;
    float speed;
    int dmg;  // projectile dmg + tower dmg = total dmg
    char type; // 0 = Fire, 1 = Electricity, 2 = Laser

    // Default constructor
    Projectile() {}

    Projectile(float x, float y, float angle, float speed, int dmg, Tower* spawner)
    {
        this->x = x;
        this->y = y;
        this->angle = angle;
        this->speed = speed;
        this->dmg = dmg + spawner->dmg;
        this->type = spawner->type;  // projectile inherits its spawner type.
    }

    void Advance()
    {
        /*
        Despite the X,Y coords being float, they are rounded down and the
        rounded versions are used to draw them on screen.
        */

        // FUTURE NORB: CHECK THIS BECAUSE IT MIGHT NOT FUCKING WORK.
        // Also, does not account for collision checking, YET.
        this->x += cosf(this->angle) * this->speed;
        this->y += sinf(this->angle) * this->speed;
    }
};

void ProjectileHurt(Projectile* attacker, Enemy* target);