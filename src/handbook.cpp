#include <iostream>

#include "headers/debug.hpp"

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
    std::cout << BoldText() << Color << DefendersHandbook::HB_GREET << ResetColor() << "\n\n";
    std::cout << WhiteText(true) << "1. " << BoldText() << DefendersHandbook::HB_CAT1 << ResetColor() << '\n';
    std::cout << WhiteText(true) << "2. " << BoldText() << DefendersHandbook::HB_CAT2 << ResetColor() << '\n';
    std::cout << WhiteText(true) << "3. " << BoldText() << DefendersHandbook::HB_CAT3 << ResetColor() << '\n';
    std::cout << WhiteText(true) << "4. " << BoldText() << DefendersHandbook::HB_ADD_CAT << ResetColor() << '\n';
    std::cout << WhiteText(true) << "5. " << BoldText() << DefendersHandbook::HB_CAT4 << ResetColor() << "\n\n";
    std::cout << BoldText() << RedText(true) << "0. " << DefendersStrings::MM_BACK << "\n";

    DefendersUtils::KeyGuard();
    while (true) 
    {
        if (DefendersUtils::GetNumKey(0)) { return; }
    }
}