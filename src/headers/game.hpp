#pragma once

#include <memory>
#include <string>

#include "save.hpp"

// some constants
#define FPS 15  // probably won't be adding delta timing, or will I?

void StartGame(const std::string& map, int gamemode);