#pragma once

#include <memory>
#include <string>

#include "save.hpp"

// some constants
#define FPS 15  // probably won't be adding delta timing

void StartGame(const std::string& map, int gamemode);