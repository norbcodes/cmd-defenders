#include <iostream>
#include <string>

#include "headers/ui.hpp"

// Functions start here

std::string BlackText(bool bright)
{
    return (bright ? C_BLACK : CB_BLACK);
}

std::string RedText(bool bright)
{
    return (bright ? C_RED : CB_RED);
}

std::string GreenText(bool bright)
{
    return (bright ? C_GREEN : CB_GREEN);
}

std::string OrangeText(bool bright)
{
    return (bright ? C_YELLOW : CB_YELLOW);
}

std::string BlueText(bool bright)
{
    return (bright ? C_BLUE : CB_CYAN);
}

std::string MagentaText(bool bright)
{
    return (bright ? C_MAGENTA : CB_MAGENTA);
}

std::string CyanText(bool bright)
{
    return (bright ? C_CYAN : CB_CYAN);
}

std::string WhiteText(bool bright)
{
    return (bright ? C_WHITE : CB_WHITE);
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