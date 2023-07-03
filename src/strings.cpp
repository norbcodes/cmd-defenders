#include <string>

/*
Strings like game title, gamemodes, map names and all that are defined here.
*/

// This kind of a system, having strings defined in one file, could allow translating the game into
// more languages. Not planned, but it's a possibility!


// prefix G - Game
std::string G_TITLE_WORD1 = \
" \
      ::::::::    :::   :::   :::::::::\n \
    :+:    :+:  :+:+: :+:+:  :+:    :+:\n \
   +:+        +:+ +:+:+ +:+ +:+    +:+ \n \
  +#+        +#+  +:+  +#+ +#+    +:+  \n \
 +#+        +#+       +#+ +#+    +#+   \n \
#+#    #+# #+#       #+# #+#    #+#    \n \
########  ###       ### #########         \
";

std::string G_TITLE_WORD2 = \
" \
      :::::::::  :::::::::: :::::::::: :::::::::: ::::    ::: :::::::::  :::::::::: :::::::::   ::::::::\n \
     :+:    :+: :+:        :+:        :+:        :+:+:   :+: :+:    :+: :+:        :+:    :+: :+:    :+:\n \
    +:+    +:+ +:+        +:+        +:+        :+:+:+  +:+ +:+    +:+ +:+        +:+    +:+ +:+        \n \
   +#+    +:+ +#++:++#   :#::+::#   +#++:++#   +#+ +:+ +#+ +#+    +:+ +#++:++#   +#++:++#:  +#++:++#++  \n \
  +#+    +#+ +#+        +#+        +#+        +#+  +#+#+# +#+    +#+ +#+        +#+    +#+        +#+   \n \
 #+#    #+# #+#        #+#        #+#        #+#   #+#+# #+#    #+# #+#        #+#    #+# #+#    #+#    \n \
#########  ########## ###        ########## ###    #### #########  ########## ###    ###  ########      \n \
";

std::string G_TITLE_SMALL = \
" \
 _____               _      ______      __               _               \n \
/  __ \\             | |     |  _  \\    / _|             | |              \n \
| /  \\/_ __ ___   __| |     | | | |___| |_ ___ _ __   __| | ___ _ __ ___ \n \
| |   | '_ ` _ \\ / _` |     | | | / _ \\  _/ _ \\ '_ \\ / _` |/ _ \\ '__/ __|\n \
| \\__/\\ | | | | | (_| |     | |/ /  __/ ||  __/ | | | (_| |  __/ |  \\__ \\\n \
 \\____/_| |_| |_|\\__,_|     |___/ \\___|_| \\___|_| |_|\\__,_|\\___|_|  |___/\n\
";

std::string G_NORB      = "NorbCodes presents...";
std::string G_NORB2     = "A tower defense game, entirely in the CMD. Coded by Norb (NorbCodes) using C++.";

std::string G_ENDSCREEN = \
" \
+----------------------------------------------+\n \
             Thanks for playing! :D             \n \
      This game was made with lots of love.     \n \
   Hopefully you had fun playing as much as I   \n \
           had programming this game!           \n \
                                                \n \
                    Credits:                    \n \
                 Coding - Norb                  \n \
                Game idea - Norb                \n \
                 Powered by C++                 \n \
           Json Parser lib - Nlohmann           \n \
+----------------------------------------------+\n \
";  // More will be added here!

// prefix U - universal
std::string U_YES       = "Yes";
std::string U_NO        = "No";
std::string U_ENTER     = "Press enter to continue...";

// prefix MM - Main Menu      but tbh it's also used in other places
std::string MM_PLAY     = "Play game";
std::string MM_OPT      = "Options";
std::string MM_CT       = "Custom Content";
std::string MM_EX       = "Exit game";
std::string MM_CEX      = "Are you sure you wanna exit?";
std::string MM_HAND     = "Read handbook";
std::string MM_MESG     = "Select a map to play...";
std::string MM_MAP      = "Maps are in no particular order, difficulty may wary per map!\nYou get a different colored * for each gamemode you played on that map.";
std::string MM_ARROWS   = "Use right and left arrow keys to change page.";
std::string MM_BACK     = "Go back";
std::string MM_MESG2    = "Select a gamemode...   ";
std::string MM_GM1      = "Standard\n";
std::string MM_GM2      = "Hard\n   Enemies have 1.5x more health and move 2x faster.\n";
std::string MM_GM3      = "CMD Pro\n   Enemies have 2x more health, speed and take 2 extra lives when they reach the end of the track.\n";
std::string MM_GM4      = "Half Cash\n   Recieve half of the cash from enemy kills and wave bonuses.\n";
std::string MM_GM5      = "Reverse!\n   Enemies approach from the other end of the track.\n";
std::string MM_GM6      = "Sandbox\n   Unlimited money and lives. You can also spawn enemies at will.\n";
std::string MM_RETURN   = "Go back to map selection";