#include <sys/stat.h>
#include <filesystem>
#include <iostream>

#include "headers/save.hpp"
#include "headers/ui.hpp"
#include "headers/strings.hpp"
#include "headers/utils.hpp"

bool SaveDirExists()
{
    // Return true if our save directory exists, otherwise return false
    const char* PATH = SAVEDIR;
    struct stat sb;
    return stat(PATH, &sb) == 0;
}

void CreateSaveDir()
{
    // Create our save directory if it does not exist
    if (!SaveDirExists())
    {
        std::filesystem::path PATH = SAVEDIR;
        std::filesystem::create_directory(PATH);
    }
}

bool GlobalExists()
{
    // Same stuff as perviously
    const char* PATH = GLOBALJSON;
    struct stat sb;
    return stat(PATH, &sb) == 0 && !(sb.st_mode & S_IFDIR);
}

void CreateGlobalJson()
{
    if (!GlobalExists())
    {
        std::ofstream(GLOBALJSON);
    }
}

void UsernameScreen(std::string& dest)
{
    std::cout << ResetColor() << WhiteText(false) << LineSep();

    std::cout << ResetColor();
    std::cout << BoldText() << WhiteText(true) << DefendersStrings::USER_LINE1 << '\n' << ResetColor();
    std::cout << BlueText(true) << DefendersStrings::USER_LINE2 << '\n';
    std::cout << ItalicText() << RedText(true) << DefendersStrings::USER_LINE3 << ResetColor();
    DefendersUtils::KeyGuard();
    std::getline( std::cin, dest );
    std::cout << '\n' << BoldText() << GreenText(false) << DefendersStrings::USER_WELC1 << dest << DefendersStrings::USER_WELC2 << '\n';
    std::cout << ResetColor() << BlackText(true) << DefendersStrings::U_ENTER << ResetColor() << '\n';

    std::cout << ResetColor() << WhiteText(false) << LineSep();

    DefendersUtils::KeyGuard();
    std::cin.get();

    DefendersUtils::ClearConsole();
}

bool SaveFileExists(const std::string& filepath)
{
    std::ifstream FILE(SAVEDIR + filepath + ".json");
    return FILE.good();
}