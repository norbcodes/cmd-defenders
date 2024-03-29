#include <iostream>
#include <string>
#include <math.h>
#include <memory>
#include <csignal>

#include "headers/debug.hpp"

#include "headers/rng.hpp"
#include "headers/world.hpp"
#include "headers/strings.hpp"
#include "headers/utils.hpp"
#include "headers/ui.hpp"
#include "headers/maps.hpp"
#include "headers/nlohmann_json/json.hpp"
#include "headers/save.hpp"
#include "headers/game.hpp"
#include "headers/handbook.hpp"


// Global variables, oh no!
// Fight me, I dare you.
std::unique_ptr<GlobalData>     GLOBALDATA;
std::unique_ptr<UserData>       USERDATA; 

static void WelcomeMessage()
{
    // A smol welcome screen :>
    RestoreCursor();
    std::cout << ItalicText() + DefendersStrings::G_NORB + "\n\n";
    std::cout << BoldText() + BlueText(true) + (DefendersStrings::G_TITLE_WORD1 + '\n' + DefendersStrings::G_TITLE_WORD2 + '\n') + ResetColor();
    std::cout << ItalicText() + DefendersStrings::G_NORB2 + '\n';
    std::cout << BoldText() + DefendersStrings::U_ENTER + ResetColor();
    std::cin.get();
}

static void ConfirmExit()
{
    DefendersUtils::ClearConsole();
    RestoreCursor();
    std::cout << WhiteText(false) << LineSep() << ResetColor();
    std::cout << ItalicText() + RedText(true) + DefendersStrings::MM_CEX + "\n" + ResetColor();
    std::cout << BoldText() + "1. " + DefendersStrings::U_YES + "\n" + "2. " + DefendersStrings::U_NO + "\n" + ResetColor();
    std::cout << LineSep();

    DefendersUtils::KeyGuard();
    while (true)
    {
        if (DefendersUtils::GetNumKey(1))
        {
            DefendersUtils::ClearConsole();

            GLOBALDATA.reset();
            USERDATA.reset();

            DefendersUtils::KeyGuard();
            DefendersUtils::ClearConsole();
            std::cout << BoldText() << BlueText(false) << DefendersStrings::G_ENDSCREEN << ResetColor() << '\n';

            std::cout << "\033[8m";

            // Why bother clearing stdin
            // when you can sneakily hide it from the user ;)
            std::string useless;
            std::cin >> useless;
            std::cout << useless << ResetColor();

            exit(EXIT_SUCCESS);
        }
        if (DefendersUtils::GetNumKey(2))
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

    DefendersUtils::ClearConsole();

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
        std::cout << (gamemodeSelection ? DefendersStrings::MM_MESG2 : DefendersStrings::MM_MESG);
        std::cout << ResetColor() << "\n\n";

        std::cout << WhiteText(false) + DefendersStrings::MM_MAP + ResetColor() << "\n\n";

        std::cout << BoldText();
        if (!gamemodeSelection)
        {
            std::cout << "Page: " << page+1 << "/" << maxPages+1 << "\n" << SEP << "\n";
            for (int i = 0; (i != mapCountQuarter); i++)
            {
                std::cout << (i + 1) << ". " << MainMaps[i + (page * 5)]["name"] << "                 \n";
            }
            std::cout << SEP << "\n";
            std::cout << ResetColor() << "\n" << WhiteText(false) << DefendersStrings::MM_ARROWS << "\n\n";
        }
        else
        {
            std::cout << ResetColor() << BoldText();
            std::cout << "Gamemodes:" << "\n" << SEP << "\n";
            std::cout << ResetColor() << ItalicText();
            std::cout << WhiteText(true) << "1. " << DefendersStrings::MM_GM1 << "\n";
            std::cout << OrangeText(false) << "2. " << DefendersStrings::MM_GM2 << "\n";
            std::cout << RedText(true) << "3. " << DefendersStrings::MM_GM3 << "\n";
            std::cout << GreenText(true) << "4. " << DefendersStrings::MM_GM4 << "\n";
            std::cout << MagentaText(false) << "5. " << DefendersStrings::MM_GM5 << "\n";
            std::cout << BoldText() << BlueText(false) << "6. " << DefendersStrings::MM_GM6 << ResetColor();
            std::cout << BoldText() << SEP << "\n\n" << ResetColor();
        }

        std::cout << BoldText() << RedText(true) << "0. " << DefendersStrings::MM_BACK << "\n";
        if (gamemodeSelection)
        {
            std::cout << RedText(true) << "9. " << DefendersStrings::MM_RETURN << "\n";
        }
        std::cout << ResetColor() << WhiteText(false) << LineSep() << ResetColor();

        DefendersUtils::KeyGuard();
        while (true)
        {
            if (DefendersUtils::GetNumKey(0))
            {
                selection = 0;
                break;
            }
            if (DefendersUtils::GetNumKey(1))
            {
                selection = 1;
                break;
            }
            if (DefendersUtils::GetNumKey(2))
            {
                selection = 2;
                break;
            }
            if (DefendersUtils::GetNumKey(3))
            {
                selection = 3;
                break;
            }
            if (DefendersUtils::GetNumKey(4))
            {
                selection = 4;
                break;
            }
            if (DefendersUtils::GetNumKey(5))
            {
                selection = 5;
                break;
            }
            if (DefendersUtils::GetNumKey(6))
            {
                selection = 6;
                break;
            }
            if (DefendersUtils::GetNumKey(9))
            {
                selection = 9;
                break;
            }
            if (DefendersUtils::GetArrowKey(2))
            {
                selection = 15;
                break;
            }
            if (DefendersUtils::GetArrowKey(3))
            {
                selection = 16;
                break;
            }
        }

        if (!gamemodeSelection)  // Not selecting a gamemode
        {
            if (!(selection >= 1 && selection <= 5))  // The selection value is not within 1 and 5
            {
                switch (selection)
                {
                    case 0:  // Exit to main menu
                        inLoop = false;
                        break;

                    case 15:  // Next page
                        page += 1;
                        if (page > maxPages)
                        {
                            page = 0;
                        }
                        break;

                    case 16:  // Previous page
                        page -= 1;
                        if (page < 0)
                        {
                            page = maxPages;
                        }
                        break;
                }
            }
            else  // The selection value is within 1 and 5, meaning the use has picked a map.
            {
                DefendersUtils::ClearConsole();
                gamemodeSelection = true;  // Go to gamemode selection
                selectedMap = selection + (page * 5);  // Remember the selected map
                // this calculation doesn't account for the fact that indexes start at 0
                // Very devilish bug :(
                // it *used to, Norb. Word your shit better next time.
            }
        }
        else  // In gamemode selection
        {
            if (!(selection >= 1 && selection <= 6))  // Selection value not within 1 and 6
            {
                switch (selection)
                {
                    case 0:  // Exit to main menu
                        inLoop = false;
                        break;

                    case 9:  // Go back to map selection
                        DefendersUtils::ClearConsole();
                        gamemodeSelection = false;
                        selectedMap = -1;
                        selectedGamemode = -1;
                        break;
                }
            }
            else  // Selection value within 1 and 6, user picked a gamemode
            {
                selectedGamemode = selection;  // Remember the gamemode
                inLoop = false;
                break;
            }
        }
    }

    // check if the map and gamemode have been set
    if ( selectedMap != -1 && selectedGamemode != -1 )
    {
        param1 = selectedMap - 1;
        param2 = selectedGamemode - 1;
        /*
        StartGame(selectedMap, selectedGamemode)
        */
        return;  // of course
    }

    param1 = -1;
    param2 = -1;
    // Means failure
}

static void MainMenu(int& param1)
{
    DefendersUtils::ClearConsole();
    DefendersUtils::SetWindowSize();
    RestoreCursor();
    std::cout << WhiteText(false) << LineSep() << ResetColor();

    std::string Color;

    switch (DefendersRNG::RandInt(0, 3))
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

    std::cout << Color + BoldText() + (DefendersStrings::G_TITLE_SMALL) + ResetColor();
    std::cout << BoldText() << ItalicText() << "\t\t\t\t\t" << DefendersStrings::G_NORB_ALT << "\n" << ResetColor();
    std::cout << BoldText() + GreenText(true) + "1. " + DefendersStrings::MM_PLAY << "\n";
    std::cout << OrangeText(false) <<"2. " + DefendersStrings::MM_OPT << "\n";
    std::cout << MagentaText(true) <<"3. " + DefendersStrings::MM_CT << "\n";
    std::cout << CyanText(false) << "4. " + DefendersStrings::MM_HAND << "\n";
    std::cout << RedText(true) <<"5. " + DefendersStrings::MM_EX << "\n" + ResetColor();
    std::cout << WhiteText(false) << LineSep() << ResetColor();

    int selection;

    DefendersUtils::KeyGuard();
    while (true)
    {
        if (DefendersUtils::GetNumKey(1))
        {
            selection = 1;
            break;
        }
        if (DefendersUtils::GetNumKey(2))
        {
            selection = 2;
            break;
        }
        if (DefendersUtils::GetNumKey(3))
        {
            selection = 3;
            break;
        }
        if (DefendersUtils::GetNumKey(4))
        {
            selection = 4;
            break;
        }

        if (DefendersUtils::GetNumKey(5))
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
    DefendersUtils::ClearConsole();
    // Might as well clear the console.

    GLOBALDATA.reset();
    USERDATA.reset();
    std::string useless;
    std::cin >> useless;
    std::cout << useless << ResetColor();
    exit(EXIT_SUCCESS);
}

int main()
{
    DefendersUtils::ClearConsole();
    DefendersUtils::SetGameTitle();

    #ifndef _NORB_NO_SAVES_

    // users/
    // Unless it already exists, then do not do anything.
    CreateSaveDir();

    #endif // _NORB_NO_SAVES_

    GLOBALDATA      = std::make_unique<GlobalData>();
    USERDATA        = std::make_unique<UserData>();

    // Ah yes, signal handling!
    signal(SIGINT, KILL);
    signal(SIGBREAK, KILL);

    #ifndef _NORB_NO_SAVES_

    if (GLOBALDATA->GetUser() == "")
    {
        std::string USERNAME;
        UsernameScreen(USERNAME);
        GLOBALDATA->SetUser(USERNAME);
    }

    // Load user data.
    if (!SaveFileExists(GLOBALDATA->GetUser()))
    {
        USERDATA->SetPath(GLOBALDATA->GetUser());
        USERDATA->SetUsername(GLOBALDATA->GetUser());
    }
    else
    {
        USERDATA->LoadSave(GLOBALDATA->GetUser());
    }

    #endif  // _NORB_NO_SAVES_

    // i love mf366!!

    // Why would anyone not like the welcome screen? :(
    if (GLOBALDATA->Get_WS_option())
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
            case 1:  // Play game option
                int selectedMap;
                int selectedGamemode;
                MapSelection(selectedMap, selectedGamemode);

                if (selectedMap != -1 && selectedGamemode != -1)
                {
                    // Enter game!
                    // WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
                    StartGame(std::to_string(selectedMap), selectedGamemode);
                }
                break;

            case 4:  // Enter handbook
                EnterHandbook();
                break;

            case 5:  // Exit :(
                ConfirmExit();
                break;
        }
    }
    return EXIT_SUCCESS;
}