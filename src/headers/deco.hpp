#pragma once
#include <string>

/*
A small class for decorations.
*/

struct Deco
{
    char x;
    char y;
    //char color; ... errrrr probably not
    std::string skin;  // an actual ASCII character

    // Default constructor
    Deco() {}

    Deco(std::string skin, char X, char Y)
    {
        this->x = X;
        this->y = Y;
        this->skin = skin;
    }
};