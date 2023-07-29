#pragma once

/*
Random number generator

I decided not to use one single global class for RNG calls.
*/

// So we don't collide with any randint function that can be in the STD.
namespace DefendersRNG
{
    int RandInt(int min, int max);
}