#include <memory>
#include <string>
#include <iostream>

#include "headers/save.hpp"
#include "headers/world.hpp"
#include "headers/renderer.hpp"
#include "headers/utils.hpp"

// Game loop and stuff!

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

void StartGame(const std::string& map, int gamemode, std::unique_ptr<UserData>& USERDATA, std::unique_ptr<GlobalData>& GLOBAL)
{
    n_ClearConsole();

    // USERDATA and GLOBAL is passed in so we can modify global and user data
    // obviously

    // Create unique_ptr of WORLD
    std::unique_ptr<WorldClass> WORLD = std::make_unique<WorldClass>();

    // Do stuff
    *WORLD = InitializeWorld(map);  // pretty sure this might get me impaled on a pitchfork
    WORLD->LinkNodes();

    // Generate renderer cache.
    GenerateCache(*WORLD);

    /*
    TODO: Insert music playback code here
    */
}