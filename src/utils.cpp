#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <winuser.h>
#include <strsafe.h>
#include <chrono>
#include <thread>
#include <iostream>

/*
Functions for setting the console title and some more stuff.
*/

namespace DefendersUtils
{
    bool GetArrowKey(int arrow)
    {
        short key;
        switch (arrow)
        {
            case 0:
                key = GetAsyncKeyState(VK_UP);
                break;
            case 1:
                key = GetAsyncKeyState(VK_DOWN);
                break;
            case 2:
                key = GetAsyncKeyState(VK_RIGHT);
                break;
            case 3:
                key = GetAsyncKeyState(VK_LEFT);
                break;
            // imagine forgetting to add break in a switch statement...
        }
        return key;
    }

    bool GetEnterKey()
    {
        return GetAsyncKeyState(VK_RETURN);
    }

    bool GetNumKey(int which)
    {
        // I know my own code BUT JUST IN CASE
        if (which >= 0 && which <= 9)
        {
            return GetAsyncKeyState(0x30 + which) || GetAsyncKeyState(0x60 + which);;
            // According to Microsofts Virtual Key Codes...
            // 0x30 <-> 0x39 are F1 <-> F9 keys
            // 0x60 <-> 0x69 are numpad keys
        }
    }

    void SetWindowSize(int width, int height)
    {
        HWND Window = GetConsoleWindow();
        if (Window != NULL)
        { 
            SetWindowPos(Window, 0, 0, 0, width, height, SWP_SHOWWINDOW|SWP_NOMOVE); 
        }
    }

    void SetGameTitle()
    {
        TCHAR GameTitle[14];
        StringCchPrintf(GameTitle, MAX_PATH, TEXT("%s"), "CMD Defenders");
        SetConsoleTitle(GameTitle);
    }

    void ClearConsole()
    {
        system("cls");
    }

    void Sleep(int ms)
    {
        // ms = milliseconds btw
        std::chrono::milliseconds duration(ms);
        std::this_thread::sleep_for(duration);
    }

    void TickFPS(int fps)
    {
        Sleep((int)((1 / fps) * 1000));  
        // Divide 1 by FPS, multiply by 1000 to get the milliseconds and then convert to int
    }

    bool GetSpacebar()
    {
        // Next wave button
        return GetAsyncKeyState(VK_SPACE);
    }

    bool GetPKey()
    {
        // Pausing during the game
        return GetAsyncKeyState(0x50);
    }

    void KeyGuard()
    {
        // If anything is pressed down: do not let things happen.
        while (GetEnterKey() || GetArrowKey(1) || GetArrowKey(2) || GetArrowKey(3) || GetArrowKey(4) || GetNumKey(1) || GetNumKey(2) || GetNumKey(3) || GetNumKey(4)|| GetNumKey(5)|| GetNumKey(6)|| GetNumKey(7)|| GetNumKey(8)|| GetNumKey(9) || GetPKey() || GetSpacebar())
        {
            continue;
        }
    }
}