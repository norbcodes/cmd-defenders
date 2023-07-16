#include "headers/tower.hpp"
#include "headers/entity.hpp"
#include "headers/rng.hpp"
#include "headers/projectile.hpp"

// entity hurt function
void HurtEntity(const Tower& attacker, Enemy& target)
{
    if (attacker.type == target.GetImmunities().getAttr( attacker.type ))
    {
        return;
    }

    int total_dmg = attacker.dmg;
    
    if (n_randint(0, 255) < attacker.crit_att_change)
    {
        total_dmg += n_randint(0, 5);
    }

    if (attacker.type == target.GetWeaknesses().getAttr( attacker.type ))
    {
        total_dmg += 10;
    }

    target.health -= total_dmg;
}

// projectile hurt function
void ProjectileHurt(const Projectile& attacker, Enemy& target)
{
    if (attacker.type == target.GetImmunities().getAttr( attacker.type ))
    {
        return;
    }

    int total_dmg = attacker.dmg;

    if (attacker.type == target.GetWeaknesses().getAttr( attacker.type ))
    {
        total_dmg += 10;
    }

    target.health -= total_dmg;
}