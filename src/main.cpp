#include <iostream>
#include <string>
#include <math.h>

#include "headers/rng.hpp"
#include "headers/world.hpp"
#include "headers/renderer.hpp"
#include "headers/strings.hpp"
#include "headers/utils.hpp"
#include "headers/ui.hpp"
#include "headers/maps.hpp"
#include "headers/nlohmann_json/json.hpp"

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
static void WelcomeMessage();
static void ConfirmExit();
static void MainMenu();
// basically exists so that the assembler doesn't beat my ass
// or the linker? I don't even know...

static void KeyGuard()
{
    // If anything is pressed down: do not let things happen.
    while (GetEnterKey() || GetArrowKey(1) || GetArrowKey(2) || GetArrowKey(3) || GetArrowKey(4) || GetNumKey(1) || GetNumKey(2) || GetNumKey(3) || GetNumKey(4)|| GetNumKey(5)|| GetNumKey(6)|| GetNumKey(7)|| GetNumKey(8)|| GetNumKey(9))
    {
        continue;
    }
}

static void WelcomeMessage()
{
    // A smol welcome screen :>
    RestoreCursor();
    std::cout << ItalicText() + G_NORB + "\n\n";
    std::cout << BoldText() + BlueText(true) + (G_TITLE_WORD1 + '\n' + G_TITLE_WORD2 + '\n') + ResetColor();
    std::cout << ItalicText() + G_NORB2 + '\n';
    std::cout << BoldText() + U_ENTER + ResetColor();
    std::cin.get();
}

static void ConfirmExit()
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
            KeyGuard();
            std::cout << BlueText(false) << G_ENDSCREEN << ResetColor() << "\n\n";
            while (!GetEnterKey())
            {
                continue;
            }
            break;
        }
        if (GetNumKey(2))
        {
            MainMenu();
            break;
        }
    }
}

static void MapSelection()
{
    /*
    
    Select a map, gamemode and play!

    */

    ClearConsole();

    const double mapCount = floor(sizeof(MainMaps) / sizeof(nlohmann::json));
    const double mapCountQuarter = floor(mapCount / 4);
    int page = 0;
    const int maxPages = 3;
    const std::string SEP = "+---------------------+";
    int selection;
    bool inLoop = true;
    bool gamemodeSelection = false;
    int selectedMap = -1;
    int selectedGamemode = -1;

    while (inLoop)
    {
        std::cout << ResetColor();
        selection = -1;
        RestoreCursor();
        std::cout << WhiteText(false) << LineSep() << ResetColor();

        std::cout << BlueText(true) << BoldText() << ItalicText();
        std::cout << (gamemodeSelection ? MM_MESG2 : MM_MESG);
        std::cout << ResetColor() << "\n\n";

        std::cout << WhiteText(false) + MM_MAP + ResetColor() << "\n\n";

        std::cout << BoldText();
        if (!gamemodeSelection)
        {
            std::cout << "Page: " << page+1 << "/" << maxPages+1 << "\n" << SEP << "\n";
            for (int i = 0; (i != mapCountQuarter); i++)
            {
                std::cout << (i + 1) << ". " << MainMaps[i + (page * 5)]["name"] << "                 \n";
            }
            std::cout << SEP << "\n";
            std::cout << ResetColor() << "\n" << WhiteText(false) << MM_ARROWS << "\n\n";
        }
        else
        {
            std::cout << "Gamemodes:" << "\n" << SEP << "\n";
            std::cout << "1. " << MM_GM1 << "\n";
            std::cout << "2. " << MM_GM2 << "\n";
            std::cout << "3. " << MM_GM3 << "\n";
            std::cout << "4. " << MM_GM4 << "\n";
            std::cout << "5. " << MM_GM5 << "\n";
            std::cout << "6. " << MM_GM6 << "";
            std::cout << SEP << "\n\n";
        }

        std::cout << BoldText() << WhiteText(true) << "0. " << MM_BACK << "\n";
        if (gamemodeSelection)
        {
            std::cout << "9. " << MM_RETURN;
        }
        std::cout << WhiteText(false) << LineSep() << ResetColor();

        KeyGuard();
        while (true)
        {
            if (GetNumKey(0))
            {
                selection = 0;
                break;
            }
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
            if (GetNumKey(6))
            {
                selection = 6;
                break;
            }
            if (GetNumKey(9))
            {
                selection = 9;
                break;
            }
            if (GetArrowKey(2))
            {
                selection = 15;
                break;
            }
            if (GetArrowKey(3))
            {
                selection = 16;
                break;
            }
        }

        if (!gamemodeSelection)
        {
            if (!(selection >= 1 && selection <= 5))
            {
                switch (selection)
                {
                    case 0:
                        inLoop = false;
                        MainMenu();
                        break;

                    case 15:
                        page += 1;
                        if (page > maxPages)
                        {
                            page = 0;
                        }
                        break;

                    case 16:
                        page -= 1;
                        if (page < 0)
                        {
                            page = maxPages;
                        }
                        break;
                }
            }
            else
            {
                ClearConsole();
                gamemodeSelection = true;
                selectedMap = selection + (page * 5);
            }
        }
        else
        {
            if (!(selection >= 1 && selection <= 6))
            {
                switch (selection)
                {
                    case 0:
                        inLoop = false;
                        MainMenu();
                        break;

                    case 9:
                        ClearConsole();
                        gamemodeSelection = false;
                        selectedMap = -1;
                        selectedGamemode = -1;
                        break;
                }
            }
            else
            {
                selectedGamemode = selection;
                inLoop = false;
                break;
            }
        }
    }

    if ( selectedMap != -1 && selectedGamemode != -1 )
    {
        /*

        StartGame(selectedMap, selectedGamemode)

        */
    }
}

static void MainMenu()
{
    ClearConsole();
    RestoreCursor();
    std::cout << WhiteText(false) << LineSep() << ResetColor();

    std::string Color;

    switch (Global_RNG.Get(3))
    {
        case 0:
            Color = BlueText(true);
            break;
        case 1:
            Color = GreenText(true);
            break;
        case 2:
            Color = OrangeText(true);
            break;
        case 3:
            Color = MagentaText(true);
            break;
    }

    std::cout << Color + BoldText() + (G_TITLE_SMALL) + ResetColor();
    std::cout << BoldText() << ItalicText() << "\t\t\t\t\t" << G_NORB_ALT << "\n" << ResetColor();
    std::cout << BoldText() + "1. " + MM_PLAY << "\n";
    std::cout << "2. " + MM_OPT << "\n";
    std::cout << "3. " + MM_CT << "\n";
    std::cout << "4. " + MM_HAND << "\n";
    std::cout << "5. " + MM_EX << "\n" + ResetColor();
    std::cout << WhiteText(false) << LineSep() << ResetColor();

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
        case 1:
            MapSelection();
            break;
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