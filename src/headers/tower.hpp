#pragma once
#include <math.h>
#include "entity.hpp"

/*
This file contains the Tower class and functions from tower.cpp.
*/

struct Tower
{
    char x;
    char y;
    float angle;
    // stats
    short radius;
    int dmg;
    char crit_att_change;  
    /*
    Each time the tower attack, a random number is pulled, 
    if it's lower than this value, we deal additional damage.
    */
    int firerate;  // Amount of tics between shots
    char type;  // 0 = Fire, 1 = Electricity, 2 = Laser, 3 = Hitscan
                // yup, this is where the enemy weakness and immune var come in play

    // Default constructor
    Tower() {}

    Tower(char type)
    {
        /*
        Still gotta type out the Tower types..
        */
    }

    void PointAt(Enemy* target)
    {
        // listen i do not know much about trigonometry
        // when playtesting comes i will fix this (if it even doesn't work in the first place)
        this->angle = atan2(target->y, target->x);
    }
};

void HurtEntity(Tower* attacker, Enemy* target);