#include <iostream>
#include <string>
#include <math.h>
#include <memory>
#include <csignal>

#include "headers/rng.hpp"
#include "headers/world.hpp"
#include "headers/renderer.hpp"
#include "headers/strings.hpp"
#include "headers/utils.hpp"
#include "headers/ui.hpp"
#include "headers/maps.hpp"
#include "headers/nlohmann_json/json.hpp"
#include "headers/save.hpp"
#include "headers/game.hpp"

// DO NOT USE FOR ANYTHING.
// LOAD THESE SO WE CAN HANDLE SIGINT AND SIGBREAK SIGNALS.
static std::unique_ptr<GlobalData>*     GLOBAL_REF;
static std::unique_ptr<UserData>*       USER_REF; 

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

static void ConfirmExit(std::unique_ptr<GlobalData>& global, std::unique_ptr<UserData>& user)
{
    ClearConsole();
    RestoreCursor();
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

            global.reset();
            user.reset();

            KeyGuard();
            ClearConsole();
            std::cout << BoldText() << BlueText(false) << G_ENDSCREEN << ResetColor() << '\n';

            std::cout << "\033[8m";

            // Why bother clearing stdin
            // when you can sneakily hide it from the user ;)
            std::string useless;
            std::cin >> useless;
            std::cout << useless << ResetColor();

            exit(EXIT_SUCCESS);
        }
        if (GetNumKey(2))
        {
            break;
        }
    }
}

static void MapSelection(int& param1, int& param2)
{
    /*
    
    Select a map, gamemode and play!

    */

    ClearConsole();

    const double mapCount = floor(MAPCOUNT);
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
            std::cout << ResetColor() << BoldText();
            std::cout << "Gamemodes:" << "\n" << SEP << "\n";
            std::cout << ResetColor() << ItalicText();
            std::cout << WhiteText(true) << "1. " << MM_GM1 << "\n";
            std::cout << OrangeText(false) << "2. " << MM_GM2 << "\n";
            std::cout << RedText(true) << "3. " << MM_GM3 << "\n";
            std::cout << GreenText(true) << "4. " << MM_GM4 << "\n";
            std::cout << MagentaText(false) << "5. " << MM_GM5 << "\n";
            std::cout << BoldText() << BlueText(false) << "6. " << MM_GM6 << ResetColor();
            std::cout << BoldText() << SEP << "\n\n" << ResetColor();
        }

        std::cout << BoldText() << RedText(true) << "0. " << MM_BACK << "\n";
        if (gamemodeSelection)
        {
            std::cout << RedText(true) << "9. " << MM_RETURN << "\n";
        }
        std::cout << ResetColor() << WhiteText(false) << LineSep() << ResetColor();

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
        param1 = selectedMap;
        param2 = selectedGamemode;
        /*
        StartGame(selectedMap, selectedGamemode)
        */
    }

    param1 = -1;
    param2 = -1;
    // Means failure
}

static void MainMenu(int& param1)
{
    ClearConsole();
    RestoreCursor();
    std::cout << WhiteText(false) << LineSep() << ResetColor();

    std::string Color;

    std::cout << n_RandInt(0, 3) << "\n\n";

    switch (n_RandInt(0, 3))
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
    std::cout << BoldText() + GreenText(true) + "1. " + MM_PLAY << "\n";
    std::cout << OrangeText(false) <<"2. " + MM_OPT << "\n";
    std::cout << MagentaText(true) <<"3. " + MM_CT << "\n";
    std::cout << CyanText(false) << "4. " + MM_HAND << "\n";
    std::cout << RedText(true) <<"5. " + MM_EX << "\n" + ResetColor();
    std::cout << WhiteText(false) << LineSep() << ResetColor();

    int selection;

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

    param1 = selection;

    /*
    switch (selection)
    {
        case 1:
            MapSelection();
            break;
        case 5:
            ConfirmExit();
            break;
    }
    Nonononono
    */
}

// Goldfoot's machine,
// creates another fiend,
// so beautiful..
// They'll make you kill!
static void KILL(int signum)
{
    ClearConsole();
    // Might as well clear the console.

    (*GLOBAL_REF).reset();
    (*USER_REF).reset();
    std::string useless;
    std::cin >> useless;
    std::cout << useless << ResetColor();
    exit(EXIT_SUCCESS);
}

int main()
{
    ClearConsole();
    SetGameTitle();

    // users/
    // Unless it already exists, then do not do anything.
    CreateSaveDir();

    std::unique_ptr<GlobalData> GLOBAL      = std::make_unique<GlobalData>();
    std::unique_ptr<UserData>   USERDATA    = std::make_unique<UserData>();

    // magic
    GLOBAL_REF = &GLOBAL;
    USER_REF = &USERDATA;

    // Ah yes, signal handling!
    signal(SIGINT, KILL);
    signal(SIGBREAK, KILL);

    {
        std::string USERNAME;
        UsernameScreen(USERNAME);
        GLOBAL->SetUser(USERNAME);
    }

    // Load user data.
    if (!SaveFileExists(GLOBAL->GetUser()))
    {
        USERDATA->SetPath(GLOBAL->GetUser());
        USERDATA->SetUsername(GLOBAL->GetUser());
    }
    else
    {
        USERDATA->LoadSave(GLOBAL->GetUser());
    }

    // i love mf366!!

    // Why would anyone not like the welcome screen? :(
    if ( GLOBAL->Get_WS_option() )
    {
        WelcomeMessage();
    }

    // Calling functions from functions may inflate the call stack
    // soooo let's not do that
    while (true)
    {
        int MainMenuOption;
        MainMenu(MainMenuOption);

        switch (MainMenuOption)
        {
            case 1:
                int selectedMap;
                int selectedGamemode;
                MapSelection(selectedMap, selectedGamemode);

                if (selectedMap != -1 && selectedGamemode != -1)
                {
                    // Enter game!
                    // WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
                    StartGame(std::to_string(selectedMap), selectedGamemode, USERDATA, GLOBAL);
                }
                break;

            case 5:
                ConfirmExit(GLOBAL, USERDATA);
                break;
        }
    }
    return 0;
}