#include <memory>
#include <string>

#include "headers/save.hpp"
#include "headers/world.hpp"
#include "headers/renderer.hpp"

// Game loop and stuff!

void StartGame(const std::string& map, int gamemode, std::unique_ptr<UserData>& USERDATA, std::unique_ptr<GlobalData>& GLOBAL)
{
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