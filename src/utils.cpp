#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

/*
Functions for setting the console title and some more stuff.
*/

void SetWindowSize(int x, int y)
{
    HWND Window = GetConsoleWindow();
    if(Window != NULL)
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