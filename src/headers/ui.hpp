#pragma once
#include <string>

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
void SwitchCursorVisibility(bool b);