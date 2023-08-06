#include <memory>
#include <string>
#include <iostream>

#include "headers/game.hpp"
#include "headers/save.hpp"
#include "headers/world.hpp"
#include "headers/renderer.hpp"
#include "headers/utils.hpp"
#include "headers/ui.hpp"

#include "headers/debug.hpp"

extern std::unique_ptr<GlobalData>     GLOBAL;
extern std::unique_ptr<UserData>       USERDATA; 

// Game loop and stuff!

//          KEYS
static bool KEYS[7] = {
    false,  // Enter
    false,  // Up
    false,  // Down
    false,  // Right
    false,  // Left
    false,  // Spacebar - Next wave
    false   // P - pause the game
};
// Global to only this source file.
// OBVIOUSLY NORB

static void DetectKeys()
{
    // exactly
    KEYS[0] = DefendersUtils::GetEnterKey();
    KEYS[1] = DefendersUtils::GetArrowKey(0);
    KEYS[2] = DefendersUtils::GetArrowKey(1);
    KEYS[3] = DefendersUtils::GetArrowKey(2);
    KEYS[4] = DefendersUtils::GetArrowKey(3);
    KEYS[5] = DefendersUtils::GetSpacebar();
    KEYS[6] = DefendersUtils::GetPKey();
}

void StartGame(const std::string& map, int gamemode)
{
    DefendersUtils::ClearConsole();

    DEBUG_PRINT_WAIT("in game");

    // USERDATA and GLOBAL is passed in so we can modify global and user data
    // obviously

    // Create unique_ptr of WORLD
    std::unique_ptr<WorldClass> WORLD       = std::make_unique<WorldClass>();
    std::unique_ptr<UiManager>  UI_MANAGER  = std::make_unique<UiManager>();

    // Do stuff
    InitializeWorld(WORLD, map);  // pretty sure this might get me impaled on a pitchfork
    WORLD->LinkNodes();

    // Generate renderer cache.

    DEBUG_PRINT_WAIT("about to gen caches");

    GenerateCache(*WORLD);

    bool GameLoop = true;
    bool TowerPlacingMode = false;

    /*
    TODO: Insert music playback code here
    No! Not yet atleast...
    */

    //////////////////////////////////////A
    // HELL YEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    //////////////////////////////////////A
    while (GameLoop)
    {
        RestoreCursor();
        DefendersUtils::TickFPS(FPS);
        DetectKeys();
    }
}