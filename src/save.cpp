#include <sys/stat.h>
#include <filesystem>

#include "headers/save.hpp"

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