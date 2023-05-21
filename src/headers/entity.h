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
    Node* move_to;  // The current node the entity is walking to.
    float speed;
    int health;
    char weakness;  // 0 = Fire, 1 = Electricity, 2 = Laser

    Enemy(char type, Node* start_node)
    {
        /*
        Still gotta write out all the enemy types...
        */
    }

    void UpdateNode()
    {
        // ONLY RUN THIS when we are standing directly on top of the move_to node!!
        this->move_to = this->move_to->GetNext();
    }
};

void HurtEntity(Tower* attacker, Enemy* target);