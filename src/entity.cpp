#include "headers/tower.hpp"
#include "headers/entity.hpp"

void HurtEntity(Tower* attacker, Enemy* target)
{
    int total_dmg = attacker->dmg;
    target->health = target->health - total_dmg;
}