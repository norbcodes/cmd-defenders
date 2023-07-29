#include "headers/tower.hpp"
#include "headers/entity.hpp"
#include "headers/rng.hpp"
#include "headers/projectile.hpp"

// Tower on Entity attack
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
    if (DefendersRNG::RandInt(0, 255) < attacker.crit_att_chance)
    {
        // If good RNG, deal damage
        total_dmg += DefendersRNG::RandInt(0, 5);
    }

    // Check weakness.
    if (attacker.type == target.GetWeaknesses().getAttr( attacker.type ))
    {
        total_dmg += 10;
    }

    target.Hurt(total_dmg);  // Ouch.
}

// Projectile on Entity attack
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

    target.Hurt(total_dmg);  // Deal damage.
}

// Spiky Rock on Entity attack
void SpikyHurt(SpikyRock& rock, Enemy& target)
{
    rock.health -= 1;
    target.Hurt(rock.dmg);
}