#pragma once

/*
A small class for decorations.
*/

struct Deco
{
    short x;
    short y;
    //char color;
    char skin;  // an actuall ASCII char

    Deco(char skin, short X, short Y)
    {
        this->x = X;
        this->y = Y;
        this->skin = skin;
    }
};