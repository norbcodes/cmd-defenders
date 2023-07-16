#pragma once
#include "node.hpp"

/*
This file contains the Enemy class and functions for entity handling from entity.cpp.
*/

#define FIRE                    0
#define ELECTRICITY             1
#define LASER                   2
#define HITSCAN                 3

#define FIRE_WEAKNESS           0b00001000
#define FIRE_IMMUNITY           0b00001000  // For readability sake ;)
#define ELECTRICITY_WEAKNESS    0b00000100
#define ELECTRICITY_IMMUNITY    0b00000100
#define LASER_WEAKNESS          0b00000010
#define LASER_IMMUNITY          0b00000010
#define HITSCAN_WEAKNESS        0b00000001
#define HITSCAN_IMMUNITY        0b00000001

struct EnemyAttributes
{
    bool fire;
    bool electricity;
    bool laser;
    bool hitscan;
    int color;

    bool getAttr(int a)
    {
        switch (a)
        {
            case 0:
                return this->fire;
            case 1:
                return this->electricity;
            case 2:
                return this->electricity;
            case 3:
                return this->electricity;
        }
    }
};

struct Enemy
{
    float x;
    float y;
    Node* move_to;  // The current node the entity is walking to.
    float speed;  // Map units to move after each second.
    unsigned int health;
    // the amount of money you get from an entity
    // is based on this equation:
    // (HEALTH / 3) * (SPEED * 1.5)
    // So the more health it has and the faster it goes, the more you earn.
    unsigned int armor;
    unsigned char weakness;  // Fire / Electricity / Laser / Hitscan - or any combination of them
    unsigned char immunity;    // Fire / Electricity / Laser / Hitscan - or any combination of them

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

    EnemyAttributes GetWeaknesses() const
    {
        int color = 0;
        char _copyweakness = this->weakness;

        for (int i = 0; i != 4; i++)
        {
            if ((_copyweakness & 0b00001000) == 1)
            {
                // is the 4th bit (from right) ON?
                // then break.
                break;
            }
            else
            {
                // otherwise increment color
                color += 1;
                // and bitshift our lil variable to the left once
                _copyweakness = _copyweakness << 1;
            }
        }

        return {
            this->weakness & FIRE_WEAKNESS,
            this->weakness & ELECTRICITY_WEAKNESS,
            this->weakness & LASER_WEAKNESS,
            this->weakness & HITSCAN_WEAKNESS,
            color // yes color
        };
    }

    EnemyAttributes GetImmunities() const
    {
        return {
            this->immunity & FIRE_IMMUNITY,
            this->immunity & ELECTRICITY_IMMUNITY,
            this->immunity & LASER_IMMUNITY,
            this->immunity & HITSCAN_IMMUNITY,
            -1 // no color
        };
    }
};