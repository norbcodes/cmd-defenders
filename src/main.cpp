#include <iostream>
#include "headers/rng.hpp"
#include "headers/strings.hpp"
#include "headers/utils.hpp"
#include "headers/ui.hpp"

RNG Global_RNG = RNG();

void WelcomeMessage()
{
    // A smol welcome screen :>
    RestoreCursor();
    std::cout << "NorbCodes presents...\n";
    std::cout << LineSep();
    std::cout << (G_TITLE_WORD1 + '\n' + G_TITLE_WORD2);
    std::cout << LineSep();
    std::cout << "Press enter to continue...";
    std::cin.get();
}

void MainMenu()
{
    int selection = 0;
    while (!GetEnterKey())
    {
        RestoreCursor();
        std::cout << LineSep();
        std::cout << (G_TITLE_WORD1 + '\n' + G_TITLE_WORD2);
        std::cout << LineSep();
        std::cout << ((selection == 0) ? "-> " + MM_PLAY : "   " + MM_PLAY ) << "\n";
        std::cout << ((selection == 1) ? "-> " + MM_OPT : "   " + MM_OPT ) << "\n";
        std::cout << ((selection == 2) ? "-> " + MM_CT : "   " + MM_CT ) << "\n";
        std::cout << ((selection == 3) ? "-> " + MM_EX : "   " + MM_EX ) << "\n";
        std::cout << LineSep();
        if (GetArrowKey(0))
        {
            selection -= 1;
            if (selection < 0)
            {
                selection = 3;
            }
            selection %= 4;
        }
        if (GetArrowKey(1))
        {
            selection += 1;
            selection %= 4;
        }
        Sleep(90);
    }
}

int main()
{
    ClearConsole();
    // i love mf366!!
    MainMenu();
    return 0;
}