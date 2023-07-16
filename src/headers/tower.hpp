#pragma once
#include <math.h>
#include "entity.hpp"

/*
This file contains the Tower class and functions from tower.cpp.
*/

struct Tower
{
    unsigned char x;
    unsigned char y;
    float angle;
    unsigned int cost;
    // stats
    unsigned short radius;
    unsigned int dmg;
    unsigned char crit_att_change;  
    /*
    Each time the tower attack, a random number is pulled, 
    if it's lower than this value, we deal additional damage.
    */
    unsigned int firerate;  // Amount of tics between shots
    unsigned char type;  // 0 = Fire, 1 = Electricity, 2 = Laser, 3 = Hitscan
                // yup, this is where the enemy weakness and immune var come in play
                // Unlike enemies, a tower may only have one type.

    // Default constructor
    Tower() {}

    Tower(char type)
    {
        /*
        Still gotta type out the Tower types..
        */
    }

    void PointAt(const Enemy& target)
    {
        // listen i do not know much about trigonometry
        // when playtesting comes i will fix this (if it even doesn't work in the first place)
        this->angle = atan2(target.y, target.x);
    }
};

void HurtEntity(const Tower& attacker, Enemy& target);