#include <string>
#include <fstream>
#include <iostream>
#include "headers/world.hpp"
#include "headers/nlohmann_json/json.hpp"
#include "headers/maps.hpp"

WorldClass InitializeWorld(const std::string& mapname)
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
            MapData = MainMaps[std::stoi(mapname)];
        }
    }
    catch (const std::invalid_argument&)
    {
        // mapname is not a number -> custom map detected
        std::ifstream CustomMap("./Custom_Content" + mapname);
        MapData = nlohmann::json::parse(CustomMap);
    }

    WorldClass t_World;  // t_ prefix for "temporary"
    t_World.ReserveVectors();

    t_World.name = MapData["name"];

    // Node loader
    // NOTE: Run the LinkNodes() function to link the nodes together!

    for (int i = 0; i != MapData["nodes"]["node_count"]; i++)
    {
        unsigned int x = MapData["nodes"][std::to_string(i)]["x"];
        unsigned int y = MapData["nodes"][std::to_string(i)]["y"];
        t_World.Ai_Nodes.emplace_back(x, y);  // emplace node
        // When you have a massive brain fart and forget that
        // .emplace_back takes in the constructor arguments...
        // What the fuck Norb?
    }
    //std::cout << t_World.Ai_Nodes[0].x << " " << t_World.Ai_Nodes[0].y;

    // Deco loader

    for (int i = 0; i != MapData["deco"]["deco_count"]; i++)
    {
        unsigned int x = MapData["deco"][std::to_string(i)]["x"];
        unsigned int y = MapData["deco"][std::to_string(i)]["y"];
        std::string skin = MapData["deco"][std::to_string(i)]["skin"];
        t_World.Decorations.emplace_back(x, y, skin);
    }

    return t_World;
}