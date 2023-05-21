#pragma once
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

    Tower(char type)
    {
        /*
        Still gotta type out the Tower types..
        */
    }

    void PointAt(Enemy* target)
    {
        /*Not yet implemented*/
    }
};

void HurtEntity(Tower* attacker, Enemy* target);