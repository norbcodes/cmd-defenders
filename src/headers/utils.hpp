#pragma once

#define GetIndexFromPos(x, y, w) (y * w) + x

namespace DefendersUtils
{
    bool GetArrowKey(int arrow);
    bool GetEnterKey();
    bool GetNumKey(int which);
    void SetWindowSize();
    void SetGameTitle();
    void ClearConsole();
    void Sleep(int ms);
    void TickFPS(int fps);
    bool GetSpacebar();
    bool GetPKey();
    void KeyGuard();
}