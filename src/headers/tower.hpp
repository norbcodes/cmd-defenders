#pragma once
#include <math.h>
#include "entity.hpp"
#include "collision.hpp"

/*
This file contains the Tower class and functions from tower.cpp.
*/

#define TOWER_SPEED_BOOST   3
#define TOWER_DMG_BOOST     2

struct Tower
{
    unsigned int boosting_time = 0;
    unsigned char x;
    unsigned char y;
    float angle;
    unsigned int cost;
    // stats
    unsigned short radius;
    unsigned int dmg;
    unsigned char crit_att_chance;  
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

#define SPIKYROCK_HP    50
#define SPIKYROCK_DMG   30

// A special tower type.
struct SpikyRock
{
    unsigned int x;
    unsigned int y;
    unsigned int health;
    unsigned int dmg;
    BoundingBox Box;

    SpikyRock() : health(SPIKYROCK_HP), dmg(SPIKYROCK_DMG), Box(BoundingBox( S_HITBOX_W, S_HITBOX_H )), x(-1), y(-1) {}

    SpikyRock(unsigned int x, unsigned int y)
    : health(SPIKYROCK_HP), dmg(SPIKYROCK_DMG), Box(BoundingBox( S_HITBOX_W, S_HITBOX_H )), x(x), y(y)  {}
};

void HurtEntity(const Tower& attacker, Enemy& target);
void SpikyHurt(SpikyRock& rock, Enemy& target);