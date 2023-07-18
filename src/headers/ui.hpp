#pragma once
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

/////////////////////////////////////////////////

#include "world.hpp"

struct UiManager
{
    private:
        bool TowerPlacing;  // If on - we are in tower placement mode
        unsigned char TowerMarkerX;
        unsigned char TowerMarkerY;  // Markers that can be moved around, and indicate where a tower will be placed.
        unsigned int TowerSelection;  // Highlighted selection in the side menu
        std::string OnScreenMsg;  // Display a message on screen
        unsigned char HeartColor;  // 0 - Green, 1 - Yellow, 2 - Red, 3 - Blue (over 100 HP)

    public:
        UiManager() : TowerPlacing(false), TowerMarkerX(0), TowerMarkerY(0), TowerSelection(-1) {}

        void ChangeTowerPlacingMode(bool a)
        {
            this->TowerPlacing = a;
        }

        // ARE WE IN TOWER PLACING MODE OR NAH???
        bool IsTowerPlacingMode() const
        {
            return this->TowerPlacing; // YESSS WE ARE
        }

        void MoveTowerUI(unsigned char new_x, unsigned char new_y)
        {
            this->TowerMarkerX = new_x;
            this->TowerMarkerY = new_y;
        }

        unsigned char TowerUI_X() const
        {
            return this->TowerMarkerX;
        }

        unsigned char TowerUI_Y() const
        {
            return this->TowerMarkerY;
        }

        // Wanted to make this a templated function for some reason
        // Thank god I didn't lol
        void DisplayMessage(const std::string& msg, const std::string& styles)
        {
            this->OnScreenMsg = styles + msg + C_END;
        }

        std::string GetMessage() const
        {
            return this->OnScreenMsg;
        }

        void UpdateHeartColor(unsigned int hearts)
        {
            if (hearts > DEFAULT_HEARTS)
            {
                this->HeartColor = 3;
                return;
            }

            const float div = DEFAULT_HEARTS / 3;
            
            if (hearts >= (div * 2))
            {
                this->HeartColor = 0;
                return;
            }
            else if (hearts >= div)
            {
                this->HeartColor = 1;
                return;
            }
            else
            {
                this->HeartColor = 2;
                return;
            }
        }
};

/////////////////////////////////////////////////

std::string BlackText(bool bright);
std::string RedText(bool bright);
std::string GreenText(bool bright);
std::string OrangeText(bool bright);
std::string BlueText(bool bright);
std::string MagentaText(bool bright);
std::string CyanText(bool bright);
std::string WhiteText(bool bright);
std::string ResetColor();

void RestoreCursor();
std::string BoldText();
std::string ItalicText();
std::string Underline();
void SwitchCursorVisibility(bool b);
std::string LineSep();