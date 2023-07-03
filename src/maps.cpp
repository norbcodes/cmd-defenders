#include "headers/nlohmann_json/json.hpp"

/*
Main game maps are hardcoded here.
*/

// MAP01 - ASCII Meadow
nlohmann::json Map01 = nlohmann::json::parse("{\"deco\":{\"0\":{\"skin\":\"#\",\"x\":17,\"y\":2},\"1\":{\"skin\":\"@\",\"x\":44,\"y\":2},\"10\":{\"skin\":\"@\",\"x\":13,\"y\":22},\"11\":{\"skin\":\"@\",\"x\":59,\"y\":25},\"12\":{\"skin\":\"#\",\"x\":4,\"y\":26},\"13\":{\"skin\":\"#\",\"x\":31,\"y\":26},\"14\":{\"skin\":\"#\",\"x\":50,\"y\":27},\"2\":{\"skin\":\"@\",\"x\":18,\"y\":5},\"3\":{\"skin\":\"#\",\"x\":33,\"y\":5},\"4\":{\"skin\":\"#\",\"x\":59,\"y\":6},\"5\":{\"skin\":\"#\",\"x\":5,\"y\":7},\"6\":{\"skin\":\"@\",\"x\":58,\"y\":14},\"7\":{\"skin\":\"#\",\"x\":33,\"y\":15},\"8\":{\"skin\":\"#\",\"x\":5,\"y\":17},\"9\":{\"skin\":\"#\",\"x\":20,\"y\":19},\"deco_count\":15},\"name\":\"ASCII Meadow\",\"nodes\":{\"0\":{\"link\":1,\"x\":0,\"y\":13},\"1\":{\"link\":2,\"x\":20,\"y\":13},\"2\":{\"link\":3,\"x\":20,\"y\":8},\"3\":{\"link\":4,\"x\":46,\"y\":8},\"4\":{\"link\":5,\"x\":46,\"y\":20},\"5\":{\"link\":1,\"x\":64,\"y\":20},\"node_count\":6}}");

nlohmann::json test = nlohmann::json::parse("{\"name\": \"TEST\",\"nodes\":{\"node_count\": 5,\"0\":{\"x\": 0,\"y\": 0,\"link\": 1},\"1\":{\"x\": 10,\"y\": 0,\"link\": 2},\"2\":{\"x\": 10,\"y\": 8,\"link\": 3},\"3\":{\"x\": 20,\"y\": 8,\"link\": 4},\"4\":{\"x\": 20,\"y\": 0,\"link\": 5},\"5\":{\"x\": 10,\"y\": 0,\"link\": 1}},\"deco\":{\"deco_count\": 15,\"0\":{\"x\": 17,\"y\": 2,\"skin\": \"#\"},\"1\":{\"x\": 44,\"y\": 2,\"skin\": \"@\"},\"2\":{\"x\": 18,\"y\": 5,\"skin\": \"@\"},\"3\":{\"x\": 33,\"y\": 5,\"skin\": \"#\"},\"4\":{\"x\": 59,\"y\": 6,\"skin\": \"#\"},\"5\":{\"x\": 5,\"y\": 7,\"skin\": \"#\"},\"6\":{\"x\": 58,\"y\": 14,\"skin\": \"@\"},\"7\":{\"x\": 33,\"y\": 15,\"skin\": \"#\"},\"8\":{\"x\": 5,\"y\": 17,\"skin\": \"#\"},\"9\":{\"x\": 20,\"y\": 19,\"skin\": \"#\"},\"10\":{\"x\": 13,\"y\": 22,\"skin\": \"@\"},\"11\":{\"x\": 59,\"y\": 25,\"skin\": \"@\"},\"12\":{\"x\": 4,\"y\": 26,\"skin\": \"#\"},\"13\":{\"x\": 31,\"y\": 26,\"skin\": \"#\"},\"14\":{\"x\": 50,\"y\": 27,\"skin\": \"#\"}}}");

// MAP02 - Integer Overflow
// ...

nlohmann::json MainMaps[20] = {Map01, test};
// Add all maps into a handy list :)