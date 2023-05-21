#pragma once
#include "node.h"
#include "tower.h"

/*
This file contains the Enemy class and functions for entity handling from entity.cpp.
*/

struct Enemy
{
    char x;
    char y;
    float speed;
    int health;
    char weakness;  // 0 = Fire, 1 = Electricity, 2 = Laser

    Enemy(char type, Node* start_node)
    {
        /*
        Still gotta write out all the enemy types...
        */
    }
};

void HurtEntity(Tower* attacker, Enemy* target);