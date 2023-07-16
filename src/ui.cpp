#include <iostream>
#include <string>

#define LINESEP "-----------------------------------------------------------------------------------------\n"

// A bunch of ANSI escape codes:
// Reset all text attributes
#define C_END       "\033[0m"

// Colors!
// Bright color palette
// Prefix CB_
#define CB_BLACK    "\033[90m"
#define CB_RED      "\033[91m"
#define CB_GREEN    "\033[92m"
#define CB_YELLOW   "\033[93m"
#define CB_BLUE     "\033[94m"
#define CB_MAGENTA  "\033[95m"
#define CB_CYAN     "\033[96m"
#define CB_WHITE    "\033[97m"

// Basic palette
// Prefix C_
#define C_BLACK     "\033[30m"
#define C_RED       "\033[31m"
#define C_GREEN     "\033[32m"
#define C_YELLOW    "\033[33m"
#define C_BLUE      "\033[34m"
#define C_MAGENTA   "\033[35m"
#define C_CYAN      "\033[36m"
#define C_WHITE     "\033[37m"

// Background change
// Prefix B_
#define B_BLACK     "\033[40m"
#define B_RED       "\033[41m"
#define B_GREEN     "\033[42m"
#define B_YELLOW    "\033[43m"
#define B_BLUE      "\033[44m"
#define B_MAGENTA   "\033[45m"
#define B_CYAN      "\033[46m"
#define B_WHITE     "\033[47m"

// Styles! Prefix S_ for "styles"
#define S_BOLD     "\033[1m"
#define S_ITALIC   "\033[3m"
#define S_UNDER    "\033[4m"

// Cursor stuff
#define RESTOREC    "\033[H"
#define SHOWC       "\033[?25h"
#define HIDEC       "\033[?25l"

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