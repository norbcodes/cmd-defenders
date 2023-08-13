#pragma once

#include <vector>
#include <string>

#define CAT1        0xff00  // Category 1 - Controls
#define CAT2        0xff01  // Category 2 - How to play
#define CAT3        0xff02  // Category 3 - All about modding
#define CAT4        0xff03  // Category 4 - Credits
#define CAT_ADDON   0xff04  // Category for modded handbook entries

void GetEntries(std::vector<std::string>& write_to, std::string& optional_write, bool& is_text_only, int category);