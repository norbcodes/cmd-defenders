#pragma once
#include "node.hpp"

/*
This file contains the Enemy class and functions for entity handling from entity.cpp.
*/

struct Enemy
{
    float x;
    float y;
    Node* move_to;  // The current node the entity is walking to.
    float speed;  // Map units to move after each second.
    int health;
    // the amount of money you get from an entity
    // is based on this equation:
    // (HEALTH / 3) * (SPEED * 1.5)
    // So the more health it has and the faster it goes, the more you earn.
    int armor;
    char weakness;  // Fire / Electricity / Laser / Hitscan - or any combination of them
    char immunity;    // Fire / Electricity / Laser / Hitscan - or any combination of them

    // Default constructor
    Enemy() {}

    Enemy(char type, const Node& start_node)
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

    void Move()
    {
        // check if not standing on move_to node
        if (this->x == this->move_to->x && this->y == this->move_to->y)
        {
            this->UpdateNode();
        }

        // moving vertically or horizontally?
        if (this->x - this->move_to->x == 0)
        {
            // Enemy and Node X is same: vertical movement
            this->y += (this->y - this->move_to->y < 0) ? this->speed : -(this->speed);
        }
        if (this->y - this->move_to->y == 0)
        {
            // Enemy and Node Y is same: horizontal movement
            this->x += (this->x - this->move_to->x < 0) ? this->speed : -(this->speed);
        }
    }
};