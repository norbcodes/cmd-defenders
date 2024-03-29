#pragma once
#include <string>

/*
A small class for decorations.
*/

struct Deco
{
    unsigned int x;
    unsigned int y;
    // char color; ... errrrr probably not
    // default color is gray btw
    std::string skin;  // an actual ASCII character

    // Default constructor
    Deco() : x(-1), y(-1), skin("") {}
    
    Deco(unsigned int x, unsigned int y, const std::string& skin) : x(x), y(y), skin(skin) {}

    Deco(const std::string& skin, char X, char Y)
    {
        this->x = X;
        this->y = Y;
        this->skin = skin;
    }
};