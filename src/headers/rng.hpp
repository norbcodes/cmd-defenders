#pragma once
#include <random>

/*
Random number generator
*/

struct RNG
{
    private:
        std::random_device rd;

    public:
        int Get(int limit)
        {
            std::mt19937 generator(this->rd());
            return generator() % limit;
        }
};