#pragma once

#include <fstream>
#include <string>
#include <unordered_map>

#include "nlohmann_json/json.hpp"
#include "maps.hpp"

#define DEFAULT_USER "default_username"
// key identifiers
#define GAMETIME "gametime"
#define MAPCOMPL "map_completions"
#define USER "username"

/*

Saving user data.

Stuff like achievements, challenges, tower upgrades, color palette, map completion badges, loaded custom content...

*/

/*

    TODO: Achievement and challenge saving

*/

// I don't normally use private/public in code that is not gonna be used by anybody
// But here it comes in handy
struct UserData
{
    private:
        nlohmann::json parsed_json;
        std::string path;

        // Actual data to then store in the json.
        std::string UserName;
        std::unordered_map<int, unsigned char> MapCompletions;
        long long gametime;

        void _InitValues()
        {
            // Initialize internal variables
            this->MapCompletions.reserve(20);
            for (int i = 0; i != MAPCOUNT; i++)
            {
                this->MapCompletions.emplace(i, 0b00000000);
            }

            this->gametime = 0;
            this->UserName = DEFAULT_USER;
        }

        void _LoadValues()
        {
            // Load from the parsed json (parsed_json)
        }

    public:
        UserData()  // Does NOT load anything when constructed
        {
            this->_InitValues();
        }

        UserData(const std::string& path)
        {
            this->parsed_json = nlohmann::json::parse( std::ifstream(path) );
            this->path = path;
            this->_LoadValues();
        }

        void LoadSave(const std::string& path)
        {
            this->parsed_json = nlohmann::json::parse( std::ifstream(path) );
        }

        void Save()
        {
            // Stuff everything inside the parsed_json
            this->parsed_json[GAMETIME] = this->gametime;

            nlohmann::json MapCompletionsObj = nlohmann::json::object();

            for (int i = 0; i != MAPCOUNT; i++)
            {
                MapCompletionsObj[std::to_string(i)] = this->MapCompletions[i];
            }
            this->parsed_json[MAPCOMPL] = MapCompletionsObj;
            this->parsed_json[USER] = this->UserName;

            std::ofstream(this->path) << this->parsed_json.dump(4, ' ', true);
        }

        // Some getters and setters to make my life easier
        
        void SetPath(const std::string& path)
        {
            this->path = path;
        }

        std::string GetPath() const
        {
            return this->path;
        }
};