#include "headers/sound.hpp"

#include <windows.h>
#include <mmsystem.h>
#include <string>

#include "headers/resdir.hpp"

#define SFXDIR "sounds\\"

/*
Playing SFX during gameplay.
HELL YEAH!
*/

namespace DefenderSound
{
    void PlaySFX(const char sound[])
    {
        // Play a .wav sound.
        const std::string Filename = std::string(RESDIR) + std::string(SFXDIR) + std::string(sound) + ".wav";

        PlaySoundA(LPCSTR(Filename.c_str()), NULL, SND_ASYNC | SND_FILENAME);
    }

    void StopSounds()
    {
        // Stops all currently playing sounds.
        PlaySoundA(NULL, 0, 0);
    }
}