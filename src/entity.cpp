#include "headers/tower.hpp"
#include "headers/entity.hpp"
#include "headers/rng.hpp"
#include "headers/projectile.hpp"

extern RNG Global_RNG;

void HurtEntity(Tower* attacker, Enemy* target)
{
    int total_dmg = attacker->dmg;
    
    if (Global_RNG.Get(255) < attacker->crit_att_change)
    {
        total_dmg += Global_RNG.Get(5);
    }

    target->health -= total_dmg;
}

void ProjectileHurt(Projectile* attacker, Enemy* target)
{
    target->health -= attacker->dmg;
}