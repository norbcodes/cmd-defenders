#include "headers/tower.h"
#include "headers/entity.h"

void HurtEntity(Tower* attacker, Enemy* target)
{
    int total_dmg = attacker->dmg;
    target->health = target->health - total_dmg;
}