#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

/*
Functions for setting the console title and some more stuff.
*/

void SetGameTitle()
{
    TCHAR GameTitle[14];
    StringCchPrintf(GameTitle, MAX_PATH, TEXT("%s"), "CMD Defenders");
    SetConsoleTitle(GameTitle);
}