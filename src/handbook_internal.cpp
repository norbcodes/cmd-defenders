#include <vector>
#include <string>

#include "headers/strings.hpp"
#include "headers/handbook_internal.hpp"

/*
Retrieves actual handbook entries and text hardcoded in the game engine,
which are of course located in strings.cpp
This does NOT support handbook entries from mods.

The premise of the handbook is to obviously give the user data on gameplay stuff and etc.
It's divided into 3 parts:
Categories -> Entries -> Text
A "category" can contain one or more "entry" and selecting it brings up its "text".
*/

void GetEntries(std::vector<std::string>& write_to, std::string& optional_write, bool& is_text_only, int category)
{
    // This is internal handbook entries lookup
    // so the category param can be an int.

    // write_to is where we push back the entry names
    // optional_write is used when there are no entries -> skip to text instead
    // if the above is used, is_text_only will be set to true.
    switch (category)
    {
        case CAT1:
            is_text_only = true;
            optional_write = DefendersHandbook::CAT_CT_TEXT;
            break;
    }
}