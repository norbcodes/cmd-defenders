#pragma once

#include <memory>
#include <string>

#include "save.hpp"

void StartGame(const std::string& map, int gamemode, std::unique_ptr<UserData>& USERDATA, std::unique_ptr<GlobalData>& GLOBAL);