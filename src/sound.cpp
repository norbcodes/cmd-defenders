#include "headers/sound.hpp"

#include <windows.h>
#include <mmsystem.h>
#include <string>

#include "headers/resdir.hpp"

/*
Playing SFX during gameplay.
HELL YEAH!
*/

namespace DefendersSound
{
    void PlaySFX(const char sound[])
    {
        // Play a .wav sound.
        const std::string Filename = SFXDIR + std::string(sound) + std::string(".wav");

        PlaySoundA(LPCSTR(Filename.c_str()), NULL, SND_ASYNC | SND_FILENAME);
    }

    void StopSFX()
    {
        // Stops all currently playing sounds.
        PlaySoundA(NULL, 0, 0);
    }
}