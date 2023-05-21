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
            this->y += (this->y - this->move_to->y < 0) ? this->speed : -this->speed;
        }
        if (this->y - this->move_to->y == 0)
        {
            // Enemy and Node Y is same: horizontal movement
            this->x += (this->x - this->move_to->x < 0) ? this->speed : -this->speed;
        }
    }
};