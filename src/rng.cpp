#include <random>

/*
Random number generator

I decided not to use one single global class for RNG calls.
*/

namespace DefendersRNG
{
    int RandInt(int min, int max)
    {
        std::random_device RD;
        std::mt19937 GEN( RD() );
        std::uniform_int_distribution<int> DIST(min, max);
        return DIST(GEN);
    }
}