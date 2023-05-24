#include "headers/tower.hpp"
#include "headers/entity.hpp"
#include "headers/rng.hpp"
#include "headers/projectile.hpp"

extern RNG Global_RNG;

// entity hurt function
void HurtEntity(Tower* attacker, Enemy* target)
{
    if (attacker->type == target->immunity)
    {
        return;
    }

    int total_dmg = attacker->dmg;
    
    if (Global_RNG.Get(255) < attacker->crit_att_change)
    {
        total_dmg += Global_RNG.Get(5);
    }

    if (attacker->type == target->weakness)
    {
        total_dmg += 10;
    }

    target->health -= total_dmg;
}

// projectile hurt function
void ProjectileHurt(Projectile* attacker, Enemy* target)
{
    if (attacker->type == target->immunity)
    {
        return;
    }

    int total_dmg = attacker->dmg;

    if (attacker->type == target->weakness)
    {
        total_dmg += 10;
    }

    target->health -= total_dmg;
}