#include <string>
#include <fstream>
#include <vector>
#include "headers/world.hpp"
#include "headers/nlohmann_json/json.hpp"
#include "headers/maps.hpp"

#include "headers/debug.hpp"

#ifdef _NORB_DEBUG_
#include <iostream>
#endif

void InitializeWorld(std::unique_ptr<WorldClass>& world, const std::string& mapname)
{
    /*
    If mapname is a number between 1 - 20, then we load main game maps.
    These are, of course hardcoded in headers/maps.
    */

    nlohmann::json MapData;

    // create pointers
    world->Ai_Nodes = std::make_unique<std::vector<Node>>();
    world->Decorations = std::make_unique<std::vector<Deco>>();
    world->Enemies = std::make_unique<std::vector<Enemy>>();
    world->Towers = std::make_unique<std::vector<Tower>>();
    world->Projectiles = std::make_unique<std::vector<Projectile>>();
    world->Markers = std::make_unique<std::vector<DeathMarker>>();

    // reserve vectors
    world->Ai_Nodes->reserve(MAP_SIZE);
    world->Decorations->reserve(MAX_DECO);
    world->Enemies->reserve(MAX_ENEMIES);
    world->Towers->reserve(MAP_SIZE);
    world->Projectiles->reserve(MAX_PROJECTILES);
    world->Markers->reserve(MAX_ENEMIES);

    try
    {
        if (std::stoi(mapname) >= 0 && std::stoi(mapname) <= 19)
        {
            MapData = MainMaps[std::stoi(mapname)];
        }
    }
    catch (const std::invalid_argument&)
    {
        // mapname is not a number -> custom map detected
        std::ifstream CustomMap("./Custom_Content" + mapname);
        MapData = nlohmann::json::parse(CustomMap);
    }

    world->name = MapData["name"];

    // Node loader
    // NOTE: Run the LinkNodes() function to link the nodes together!

    for (int i = 0; i != MapData["nodes"]["node_count"]; i++)
    {
        unsigned int x = MapData["nodes"][std::to_string(i)]["x"];
        unsigned int y = MapData["nodes"][std::to_string(i)]["y"];
        world->Ai_Nodes->emplace_back(x, y); // emplace node
        // When you have a massive brain fart and forget that
        // .emplace_back takes in the constructor arguments...
        // What the fuck Norb?
    }

    #ifdef _NORB_DEBUG_
    std::cout << (*(world->Ai_Nodes))[0].x << " " << (*(world->Ai_Nodes))[0].y << std::endl;
    std::cin.get();
    #endif

    // Deco loader

    for (int i = 0; i != MapData["deco"]["deco_count"]; i++)
    {
        unsigned int x = MapData["deco"][std::to_string(i)]["x"];
        unsigned int y = MapData["deco"][std::to_string(i)]["y"];
        std::string skin = MapData["deco"][std::to_string(i)]["skin"];
        world->Decorations->emplace_back(x, y, skin);
    }
}