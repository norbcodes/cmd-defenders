#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <winuser.h>
#include <tchar.h>
#include <strsafe.h>
#include <chrono>
#include <thread>
#include <iostream>

/*
Functions for setting the console title and some more stuff.
*/

COORD DefaultFontSize;
COORD GameplayFontSize;

// Gameplay font has to have all characters be exactly the same width and height.
// DefaultFont is the console's font when it first loads.

bool GetArrowKey(int arrow)
{
    short key;
    switch (arrow)
    {
        case 0:
            key = GetAsyncKeyState(VK_UP);
        case 1:
            key = GetAsyncKeyState(VK_DOWN);
        case 2:
            key = GetAsyncKeyState(VK_RIGHT);
        case 3:
            key = GetAsyncKeyState(VK_LEFT);
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