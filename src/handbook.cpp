#include <iostream>

#include "headers/utils.hpp"
#include "headers/strings.hpp"
#include "headers/ui.hpp"
#include "headers/rng.hpp"

/*
Actual handbook code and stuff.
*/

void EnterHandbook()
{
    DefendersUtils::ClearConsole();

    std::string Color;
    switch (DefendersRNG::RandInt(0, 2))
    {
        case 0:
            Color = BlueText(true);
            break;
        case 1:
            Color = GreenText(true);
            break;
        case 2:
            Color = MagentaText(true);
            break;
    }

    std::cout << WhiteText(false) << LineSep() << ResetColor();
    std::cout << BoldText() << Color << DefendersStrings::HB_GREET << ResetColor() << "\n\n";
}