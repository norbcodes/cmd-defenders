#include <iostream>
#include <string>

#include "headers/rng.hpp"
#include "headers/world.hpp"
#include "headers/renderer.hpp"
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

// Declare stuff here
void WelcomeMessage();
void ConfirmExit();
void MainMenu();
// basically exists so that the assembler doesn't beat my ass

void KeyGuard()
{
    // If anything is pressed down: do not let things happen.
    while (GetEnterKey() || GetArrowKey(1) || GetArrowKey(2) || GetArrowKey(3) || GetArrowKey(4) || GetNumKey(1) || GetNumKey(2) || GetNumKey(3) || GetNumKey(4))
    {
        continue;
    }
}

void WelcomeMessage()
{
    // A smol welcome screen :>
    RestoreCursor();
    std::cout << ItalicText() + G_NORB + "\n\n";
    std::cout << BoldText() + BlueText(true) + (G_TITLE_WORD1 + '\n' + G_TITLE_WORD2 + '\n') + ResetColor();
    std::cout << ItalicText() + G_NORB2 + '\n';
    std::cout << BoldText() + U_ENTER + ResetColor();
    std::cin.get();
}

void ConfirmExit()
{
    ClearConsole();
    RestoreCursor();
    int selection;
    std::cout << LineSep();
    std::cout << ItalicText() + RedText(true) + MM_CEX + "\n" + ResetColor();
    std::cout << BoldText() + "1. " + U_YES + "\n" + "2. " + U_NO + "\n" + ResetColor();
    std::cout << LineSep();

    KeyGuard();
    while (true)
    {
        if (GetNumKey(1))
        {
            ClearConsole();
            /* 
            Code to run when exiting... Nothing here yet... 
            */
            std::cout << BlueText(false) << G_ENDSCREEN << ResetColor() << "\n";
            break;
        }
        if (GetNumKey(2))
        {
            MainMenu();
            break;
        }
    }
}

void MainMenu()
{
    ClearConsole();
    RestoreCursor();
    std::cout << LineSep();
    std::cout << BlueText(true) + BoldText() + (G_TITLE_SMALL) + ResetColor();
    std::cout << LineSep();
    std::cout << BoldText() + "1. " + MM_PLAY << "\n";
    std::cout << "2. " + MM_OPT << "\n";
    std::cout << "3. " + MM_CT << "\n";
    std::cout << "4. " + MM_HAND << "\n";
    std::cout << "5. " + MM_EX << "\n" + ResetColor();
    std::cout << LineSep();

    char selection;

    KeyGuard();
    while (true)
    {
        if (GetNumKey(1))
        {
            selection = 1;
            break;
        }
        if (GetNumKey(2))
        {
            selection = 2;
            break;
        }
        if (GetNumKey(3))
        {
            selection = 3;
            break;
        }
        if (GetNumKey(4))
        {
            selection = 4;
            break;
        }

        if (GetNumKey(5))
        {
            selection = 5;
            break;
        }
    }

    switch (selection)
    {
        case 5:
            ConfirmExit();
            break;
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