#pragma once

namespace DefendersUtils
{
    bool GetArrowKey(int arrow);
    bool GetEnterKey();
    bool GetNumKey(int which);
    void SetWindowSize(int width, int height);
    void SetGameTitle();
    void ClearConsole();
    void Sleep(int ms);
    void TickFPS(int fps);
    bool GetSpacebar();
    bool GetPKey();
    void KeyGuard();
}