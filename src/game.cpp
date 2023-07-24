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
    KEYS[0] = n_GetEnterKey();
    KEYS[1] = n_GetArrowKey(0);
    KEYS[2] = n_GetArrowKey(1);
    KEYS[3] = n_GetArrowKey(2);
    KEYS[4] = n_GetArrowKey(3);
    KEYS[5] = n_GetSpacebar();
    KEYS[6] = n_GetPKey();
}

void StartGame(const std::string& map, int gamemode, std::unique_ptr<UserData>& USERDATA, std::unique_ptr<GlobalData>& GLOBAL)
{
    n_ClearConsole();

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
        n_TickFPS(FPS);
        DetectKeys();
    }
}