#pragma once
#include <math.h>
#include "entity.hpp"
#include "tower.hpp"
#include "collision.hpp"

/*
Projectile class and code.
*/

struct Projectile
{
    float x;
    float y;
    float angle;
    float speed;
    BoundingBox Box;
    unsigned int dmg;  // projectile dmg + tower dmg = total dmg
    unsigned char type; // 0 = Fire, 1 = Electricity, 2 = Laser

    // Default constructor
    Projectile() : Box(BoundingBox( P_HITBOX_W, P_HITBOX_H )), x(-1.0f), y(-1.0f), speed(0.0f) {}

    Projectile(float x, float y, float angle, float speed, unsigned int dmg, const Tower& spawner) 
    : x(x), y(y), angle(angle), speed(speed), Box(BoundingBox( P_HITBOX_W, P_HITBOX_H ))
    {
        this->dmg = dmg + spawner.dmg;
        this->type = spawner.type;  // projectile inherits its spawner type.
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

void ProjectileHurt(const Projectile& attacker, Enemy& target);