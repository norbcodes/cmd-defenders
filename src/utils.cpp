#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <winuser.h>
#include <tchar.h>
#include <strsafe.h>
#include <chrono>
#include <thread>

/*
Functions for setting the console title and some more stuff.
*/

short GetArrowKey(int arrow)
{
    switch (arrow)
    {
        case 0:
            return GetAsyncKeyState(VK_UP) & 0x8000;
        case 1:
            return GetAsyncKeyState(VK_DOWN) & 0x8000;
        case 2:
            return GetAsyncKeyState(VK_RIGHT) & 0x8000;
        case 3:
            return GetAsyncKeyState(VK_LEFT) & 0x8000;
    }
    return -1;
}

short GetEnterKey()
{
    return GetAsyncKeyState(VK_RETURN) & 0x8000;
}

void SetWindowSize(int x, int y)
{
    HWND Window = GetConsoleWindow();
    if (Window != NULL)
    { 
        SetWindowPos(Window, 0, 0, 0, x, y, SWP_SHOWWINDOW|SWP_NOMOVE); 
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