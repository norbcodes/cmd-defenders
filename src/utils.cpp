#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <winuser.h>
//#include <tchar.h>
#include <strsafe.h>
#include <chrono>
#include <thread>
#include <iostream>

/*
Functions for setting the console title and some more stuff.
*/

bool n_GetArrowKey(int arrow)
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

bool n_GetEnterKey()
{
    return GetAsyncKeyState(VK_RETURN);
}

bool n_GetNumKey(int which)
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

void n_SetWindowSize(int width, int height)
{
    HWND Window = GetConsoleWindow();
    if (Window != NULL)
    { 
        SetWindowPos(Window, 0, 0, 0, width, height, SWP_SHOWWINDOW|SWP_NOMOVE); 
    }
}

void n_SetGameTitle()
{
    TCHAR GameTitle[14];
    StringCchPrintf(GameTitle, MAX_PATH, TEXT("%s"), "CMD Defenders");
    SetConsoleTitle(GameTitle);
}

void n_ClearConsole()
{
    system("cls");
}

void n_Sleep(int ms)
{
    // ms = milliseconds btw
    std::chrono::milliseconds duration(ms);
    std::this_thread::sleep_for(duration);
}

void n_TickFPS(int fps)
{
    n_Sleep((int)((1 / fps) * 1000));  
    // Divide 1 by FPS, multiply by 1000 to get the milliseconds and then convert to int
}

bool n_GetSpacebar()
{
    // Next wave button
    return GetAsyncKeyState(VK_SPACE);
}

bool n_GetPKey()
{
    // Pausing during the game
    return GetAsyncKeyState(0x50);
}

void n_KeyGuard()
{
    // If anything is pressed down: do not let things happen.
    while (n_GetEnterKey() || n_GetArrowKey(1) || n_GetArrowKey(2) || n_GetArrowKey(3) || n_GetArrowKey(4) || n_GetNumKey(1) || n_GetNumKey(2) || n_GetNumKey(3) || n_GetNumKey(4)|| n_GetNumKey(5)|| n_GetNumKey(6)|| n_GetNumKey(7)|| n_GetNumKey(8)|| n_GetNumKey(9) || n_GetPKey() || n_GetSpacebar())
    {
        continue;
    }
}