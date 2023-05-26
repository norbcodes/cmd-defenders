#include <iostream>
#include "headers/rng.hpp"
#include "headers/strings.hpp"

RNG Global_RNG = RNG();

void MainMenu()
{
    std::cout << (G_TITLE_WORD1 + '\n' + G_TITLE_WORD2);
}

int main()
{
    // i love mf366!!
    MainMenu();
    return 0;
}