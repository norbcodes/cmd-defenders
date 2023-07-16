#pragma once

#define SAVEDIR             "./users/"
#define GLOBALJSON          "./global.json"

#include <fstream>
#include <string>
#include <unordered_map>

#include "nlohmann_json/json.hpp"
#include "maps.hpp"

#define DEFAULT_USER        "default_username"
// key identifiers
#define GAMETIME            "gametime"
#define MAPCOMPL            "map_completions"
#define USER                "username"
#define EXP                 "exp"

#define CURRENTUSER         "current_user"
#define WELCOMESCRN         "enable_welcome"

/*

Saving user data.
Stuff like achievements, challenges, tower upgrades, map completion badges, loaded custom content...

Also saving and reading global.json
Where global stuff is stored.

*/

/*
    TODO: User data loading
    TODO: Global data loading
    TODO: Global data - custom color palette (if enabled)
    TODO: Global data - Achievement and challenge saving

*/

// I don't normally use private/public in code that is not gonna be used by anybody
// But here it comes in handy

// Also I know this can be easily cheated
// But who cares? You get free software, you can do whatever the fuck you want with it.

bool SaveFileExists(const std::string& filepath);

struct UserData
{
    private:
        nlohmann::json parsed_json;
        std::string path;

        // Actual data to then store in the json.
        std::string UserName;
        std::unordered_map<int, unsigned char> MapCompletions;
        unsigned long long gametime;
        unsigned long long exp;

        void _InitValues()
        {
            // Initialize internal variables
            this->MapCompletions.reserve(20);
            for (int i = 0; i != MAPCOUNT; i++)
            {
                this->MapCompletions.emplace(i, 0b00000000);
                // 0b00000000 is a number from 0 - 255
                // With the last 5 bits mapping to: standard, hard, cmd pro, half cash, reverse
                // from right to left, respectively.
            }

            this->gametime = 0;
            this->UserName = DEFAULT_USER;
            this->exp = 0;
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
            this->parsed_json = nlohmann::json::parse( std::ifstream(SAVEDIR + path + ".json") );
            this->path = path;
            this->_LoadValues();
        }

        void LoadSave(const std::string& path)
        {
            this->parsed_json = nlohmann::json::parse( std::ifstream(SAVEDIR + path + ".json") );
            this->path = path;
            this->_LoadValues();
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

            std::ofstream(SAVEDIR + this->path + ".json") << this->parsed_json.dump(4, ' ', true);
        }

        ~UserData()
        {
            this->Save();
            // fuck you
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

        void SetUsername(const std::string& username)
        {
            this->UserName = username;
        }

        std::string GetUsername() const
        {
            return this->UserName;
        }
};

bool GlobalExists();
void CreateGlobalJson();
void UsernameScreen(std::string& dest);

struct GlobalData
{
    private:
        nlohmann::json parsed_json;

        std::string currentUser;
        bool enableWelcomeScreen;

        void _InitValues()
        {
            // Initialize internal variables same thing as in UserData
            this->currentUser = "";  // empty for now
            this->enableWelcomeScreen = true;
        }

        void _LoadValues()
        {
            // Parse
            this->parsed_json = nlohmann::json::parse( std::ifstream(GLOBALJSON) );

            // Load into internal variables
            this->currentUser = this->parsed_json[CURRENTUSER];
            this->enableWelcomeScreen = this->parsed_json[WELCOMESCRN];
        }

    public:
        GlobalData()
        {
            if (!GlobalExists())
            {
                CreateGlobalJson();
                this->_InitValues();
            }
            else
            {
                this->_LoadValues();
            }
        }

        void Save()
        {
            this->parsed_json[CURRENTUSER] = this->currentUser;
            this->parsed_json[WELCOMESCRN] = this->enableWelcomeScreen;

            std::ofstream(GLOBALJSON) << this->parsed_json.dump(4, ' ', true);
        }

        ~GlobalData()
        {
            this->Save();  // B)
        }

        // Some getters and setters

        void SetUser(const std::string& user)
        {
            this->currentUser = user;
        }

        std::string GetUser() const
        {
            return this->currentUser;
        }

        void Set_WS_option(bool enabled)
        {
            this->enableWelcomeScreen = enabled;
        }

        bool Get_WS_option() const
        {
            return this->enableWelcomeScreen;
        }
};

bool SaveDirExists();
void CreateSaveDir();