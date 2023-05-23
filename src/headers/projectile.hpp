#pragma once
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

    Projectile(float x, float y, float angle, float speed, int dmg, Tower* spawner)
    {
        this->x = x;
        this->y = y;
        this->angle = angle;
        this->speed = speed;
        this->dmg = dmg + spawner->dmg;
    }
};

void ProjectileHurt(Projectile* attacker, Enemy* target);