#pragma once
#include "nlohmann_json/json.hpp"

#ifdef _NORB_DEBUG_
#define MAPCOUNT 21  // Because of the test map
#else
#define MAPCOUNT 20
#endif // _NORB_DEBUG_

// Defined in maps.cpp
#ifdef _NORB_DEBUG_
extern nlohmann::json test;
#endif // _NORB_DEBUG_

extern nlohmann::json Map01;

extern nlohmann::json MainMaps[MAPCOUNT];