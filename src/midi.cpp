#include <string>

#include "headers/fluidsynth_player/fluidsynth.h"
#include "headers/resdir.hpp"

/*
Now comes the time for midi playback.
Oh boy!
*/

#define GAIN 2.5  // The output volume gain, probably gonna make this be changeable someday

static fluid_settings_t*        SynthSettings;
static fluid_synth_t*           Synth;
static fluid_player_t*          SynthPlayer;
static fluid_audio_driver_t*    SynthDriver;

void InitializeSynth()
{
    SynthSettings = new_fluid_settings();
    Synth = new_fluid_synth(SynthSettings);
    SynthPlayer = new_fluid_player(Synth);
    // Cannot create driver yet, load SF2 and midi(s) first
}

void DeleteSynth()
{
    // Should only be ran when out of gameplay loop
    delete_fluid_audio_driver(SynthDriver);
    delete_fluid_player(SynthPlayer);
    delete_fluid_synth(Synth);
    delete_fluid_settings(SynthSettings);
}

void LoadSoundfont(const std::string& path)
{
    // Construct full path to the sf2
    const std::string fullpath = std::string(SF2DIR) + path;

    // Load it
    if(fluid_is_soundfont(fullpath.c_str()))
    {
        fluid_synth_sfload(Synth, fullpath.c_str(), 1);
    }
}

void LoadMidi(const std::string& path)
{
    // Construct full path to the midi
    const std::string fullpath = std::string(MUSDIR) + path;
    // Load it
    if(fluid_is_midifile(fullpath.c_str()))
    {
        fluid_player_add(SynthPlayer, fullpath.c_str());
    }
}

void StartPlayback()
{
    // Start playing the queued midis
    SynthDriver = new_fluid_audio_driver(SynthSettings, Synth);
    fluid_settings_setnum(SynthSettings, "synth.gain", GAIN);
    fluid_player_set_loop(SynthPlayer, -1);  // Loop forever until StopPlayback is called
    fluid_player_play(SynthPlayer);
}

void TogglePause()
{
    // Pause / unpause playback
    static bool pause = false;
    pause = !pause;
    pause ? fluid_player_play(SynthPlayer) : fluid_player_stop(SynthPlayer);
}

void StopPlayback()
{
    // Stop playback all together.
    fluid_player_stop(SynthPlayer);
}