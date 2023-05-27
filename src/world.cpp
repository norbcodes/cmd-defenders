#include <string>
#include <iostream>
#include <fstream>
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
        int x = MapData["nodes"][std::to_string(i)]["x"];
        int y = MapData["nodes"][std::to_string(i)]["y"];
        Node t_Node;
        t_Node.x = x; t_Node.y = y;
        t_World.Ai_Nodes.emplace_back(t_Node);  // insert node
    }

    // Deco loader

    for (int i = 0; i != MapData["deco"]["deco_count"]; i++)
    {
        int x = MapData["deco"][std::to_string(i)]["x"];
        int y = MapData["deco"][std::to_string(i)]["y"];
        std::string skin = MapData["deco"][std::to_string(i)]["skin"];
        Deco t_Deco;
        t_Deco.x = x; t_Deco.y = y; t_Deco.skin = skin;
        t_World.Decorations.emplace_back(t_Deco);
    }

    return t_World;
}