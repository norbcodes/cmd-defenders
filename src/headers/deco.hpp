#pragma once

/*
A small class for decorations.
*/

struct Deco
{
    char x;
    char y;
    //char color; ... errrrr probably not
    char skin;  // an actual ASCII character

    Deco(char skin, char X, char Y)
    {
        this->x = X;
        this->y = Y;
        this->skin = skin;
    }
};