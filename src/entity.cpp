#include "headers/tower.hpp"
#include "headers/entity.hpp"
#include "headers/rng.hpp"
#include "headers/projectile.hpp"

// entity hurt function
void HurtEntity(const Tower& attacker, Enemy& target)
{
    // Check immunity.
    if (attacker.type == target.GetImmunities().getAttr( attacker.type ))
    {
        // If immune, do not continue further
        return;
    }

    unsigned int total_dmg = attacker.dmg;
    
    // Check crit attack chance
    if (n_RandInt(0, 255) < attacker.crit_att_chance)
    {
        // If good RNG, deal damage
        total_dmg += n_RandInt(0, 5);
    }

    // Check weakness.
    if (attacker.type == target.GetWeaknesses().getAttr( attacker.type ))
    {
        total_dmg += 10;
    }

    target.health -= total_dmg;  // Ouch.
}

// projectile hurt function
void ProjectileHurt(const Projectile& attacker, Enemy& target)
{
    // Check immunity.
    if (attacker.type == target.GetImmunities().getAttr( attacker.type ))
    {
        return;
    }

    unsigned int total_dmg = attacker.dmg;

    // Check weakness.
    if (attacker.type == target.GetWeaknesses().getAttr( attacker.type ))
    {
        total_dmg += 10;
    }

    target.health -= total_dmg;  // Deal damage.
}