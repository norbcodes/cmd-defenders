#include <windows.h>
#include <shellapi.h>
#include <string>

#include "headers/nrecycle.hpp"

static const char* DNull(std::string str)  // Noooo where is "const std::string&" ??/???? TRASH CODE!!!
{
    str += '\0';
    return str.c_str();
}

namespace DefendersRecycle
{
    void Recycle(const std::string& path)
    {
        SHFILEOPSTRUCTA Operation;
        Operation.hwnd = NULL;
        Operation.wFunc = FO_DELETE;
        Operation.pFrom = DNull(path);
        Operation.pTo = NULL;
        Operation.fFlags = FOF_ALLOWUNDO | FOF_NOCONFIRMATION | FOF_SILENT | FOF_NOERRORUI;
        SHFileOperationA(&Operation);
    }
}

// Compiled into libnrecycle.a, found in the lib/ folder