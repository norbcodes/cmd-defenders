#include <iostream>
#include <string>

#include "headers/ui.hpp"

// Functions start here

std::string BlackText(bool bright)
{
    switch (bright)
    {
        // 0 = false, 1 = true obviously
        case 0:
            return C_BLACK;
        case 1:
            return CB_BLACK;
    }
}

std::string RedText(bool bright)
{
    switch (bright)
    {
        case 0:
            return C_RED;
        case 1:
            return CB_RED;
    }
}

std::string GreenText(bool bright)
{
    switch (bright)
    {
        case 0:
            return C_GREEN;
        case 1:
            return CB_GREEN;
    }
}

std::string OrangeText(bool bright)
{
    switch (bright)
    {
        case 0:
            return C_YELLOW;
        case 1:
            return CB_YELLOW;
    }
}

std::string BlueText(bool bright)
{
    switch (bright)
    {
        case 0:
            return C_BLUE;
        case 1:
            return CB_CYAN;
    }
}

std::string MagentaText(bool bright)
{
    switch (bright)
    {
        case 0:
            return C_MAGENTA;
        case 1:
            return CB_MAGENTA;
    }
}

std::string CyanText(bool bright)
{
    switch (bright)
    {
        case 0:
            return C_CYAN;
        case 1:
            return CB_CYAN;
    }
}

std::string WhiteText(bool bright)
{
    switch (bright)
    {
        case 0:
            return C_WHITE;
        case 1:
            return CB_WHITE;
    }
}

std::string ResetColor()
{
    return C_END;
}

void RestoreCursor()
{
    std::cout << RESTOREC;
}

std::string BoldText()
{
    return S_BOLD;
}

std::string ItalicText()
{
    return S_ITALIC;
}

std::string Underline()
{
    return S_UNDER;
}

void SwitchCursorVisibility(bool b)
{
    std::cout << ((b) ? SHOWC : HIDEC);
}

std::string LineSep()
{
    return LINESEP;
}