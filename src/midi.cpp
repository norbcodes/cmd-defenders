#include <string>

#include "headers/fluidsynth_player/fluidsynth.h"
#include "headers/resdir.hpp"

/*
Now comes the time for midi playback.
Oh boy!
*/

// for searching for soundfonts
#define SF2path std::string(RESDIR) + std::string("sf2\\")

static fluid_settings_t*        SynthSettings;
static fluid_synth_t*           Synth;
static fluid_player_t*          SynthPlayer;
static fluid_audio_driver_t*    SynthDriver;

void InitializeSynth()
{
    SynthSettings = new_fluid_settings();
    Synth = new_fluid_synth(SynthSettings);
    SynthPlayer = new_fluid_player(Synth);
}

void DeleteSynth()
{
    delete_fluid_audio_driver(SynthDriver);
    delete_fluid_player(SynthPlayer);
    delete_fluid_synth(Synth);
    delete_fluid_settings(SynthSettings);
}