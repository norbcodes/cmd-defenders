#include <iostream>
#include "headers/rng.hpp"
#include "headers/strings.hpp"
#include "headers/utils.hpp"
#include "headers/ui.hpp"

RNG Global_RNG = RNG();

//          KEYS
static bool KEYS[5] = {
    false,  // Enter
    false,  // Up
    false,  // Down
    false,  // Right
    false   // Left
};
// Global to only this source file.
// OBVIOUSLY NORB

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
    while (GetEnterKey() % 0x8000)
    {
        continue;
    }
}

void MainMenu()
{
    ClearConsole();
    int selection = 0;
    while(!KEYS[0])
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

        // Find the most significant bit and the least significant bit...
        // Who the hell though this was a good idea
        // got me suffering over here

        KEYS[1] = (GetArrowKey(0) & 0x8000) == 0x8000;
        KEYS[2] = (GetArrowKey(1) & 0x8000) == 0x8000;

        if (KEYS[1])
        {
            selection -= 1;
            if (selection < 0)
            {
                selection = 0;
            }
        }
        if (KEYS[2])
        {
            selection += 1;
        }
        selection %= 4;
        KEYS[1] = false; KEYS[2] = false;
        
        Sleep(75);

        // AAAAAA
        // Degrading sanity
        KEYS[0] = ((GetEnterKey() & 0x8000) == 0x8000) && ((GetEnterKey() & 0x0001) == 0);
    }
}

int main()
{
    ClearConsole();
    // i love mf366!!
    WelcomeMessage();
    MainMenu();
    return 0;
}