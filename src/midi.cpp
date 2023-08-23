#include "headers/fluidsynth_player/fluidsynth.h"

/*
Now comes the time for midi playback.
Oh boy!
*/

static fluid_settings_t*        SynthSettings;
static fluid_synth_t*           Synth;
static fluid_player_t*          SynthPlayer;
static fluid_audio_driver_t*    SynthDriver;