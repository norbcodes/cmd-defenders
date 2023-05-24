#include <string>
#include "headers/world.hpp"
#include "headers/nlohmann_json/json.hpp"
#include "headers/maps.hpp"

WorldClass InitializeWorld(std::string mapname)
{
    /*
    If mapname is a number between 1 - 20, then we load main game maps.
    These are, of course hardcoded in headers/maps.
    */

    nlohmann::json MapData;

    try
    {
        if (std::stoi(mapname) >= 0 && std::stoi(mapname) <= 19)
        {
            MapData = main_maps[std::stoi(mapname)];
        }
    }
    catch (std::invalid_argument){}  // do nothing.
}