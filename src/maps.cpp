#ifdef _NORB_LOCAL_
#include <fstream>
#endif // _NORB_LOCAL_

#include "headers/nlohmann_json/json.hpp"
#include "headers/maps.hpp"
#include "headers/debug.hpp"

// yeah basically NORB_LOCAL allows me to make changes to a json file
// but when we build the game in "Release" mode then it is hardcoded in here

#ifdef _NORB_LOCAL_
#define MAP01 nlohmann::json::parse( std::ifstream(".\\maps\\map01.json") )
#else
#define MAP01 nlohmann::json::parse( "{}" )
#endif // _NORB_LOCAL_

/*
Main game maps are hardcoded here.
*/

// MAP01 - ASCII Meadow
nlohmann::json Map01 = MAP01;

#ifdef _NORB_DEBUG_
nlohmann::json test = nlohmann::json::parse("{\"deco\":{\"0\":{\"skin\":\"#\",\"x\":17,\"y\":2},\"1\":{\"skin\":\"@\",\"x\":44,\"y\":2},\"10\":{\"skin\":\"@\",\"x\":13,\"y\":22},\"11\":{\"skin\":\"@\",\"x\":59,\"y\":25},\"12\":{\"skin\":\"#\",\"x\":4,\"y\":26},\"13\":{\"skin\":\"#\",\"x\":31,\"y\":26},\"14\":{\"skin\":\"#\",\"x\":50,\"y\":27},\"2\":{\"skin\":\"@\",\"x\":18,\"y\":5},\"3\":{\"skin\":\"#\",\"x\":33,\"y\":5},\"4\":{\"skin\":\"#\",\"x\":59,\"y\":6},\"5\":{\"skin\":\"#\",\"x\":5,\"y\":7},\"6\":{\"skin\":\"@\",\"x\":58,\"y\":14},\"7\":{\"skin\":\"#\",\"x\":33,\"y\":15},\"8\":{\"skin\":\"#\",\"x\":5,\"y\":17},\"9\":{\"skin\":\"#\",\"x\":20,\"y\":19},\"deco_count\":15},\"name\":\"TESTIN\",\"nodes\":{\"0\":{\"link\":1,\"x\":0,\"y\":13},\"1\":{\"link\":2,\"x\":20,\"y\":13},\"2\":{\"link\":3,\"x\":20,\"y\":8},\"3\":{\"link\":4,\"x\":46,\"y\":8},\"4\":{\"link\":5,\"x\":46,\"y\":20},\"5\":{\"link\":1,\"x\":64,\"y\":20},\"node_count\":6}}");
#endif // _NORB_DEBUG_

// MAP02 - Integer Overflow
// ...

#ifdef _NORB_DEBUG_
nlohmann::json MainMaps[MAPCOUNT] = {Map01, test};
#else
nlohmann::json MainMaps[MAPCOUNT] = {Map01};
#endif // _NORB_DEBUG_

// Add all maps into a handy list :)