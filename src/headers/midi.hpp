#pragma

#include "midi_io.hpp"

/*
Functions from midi.cpp and stuff
*/

// Just in case so we don't clash with RtMidi and its stuff
namespace DefendersMidi
{
    struct Midi
    {
        DefendersMidiIO::HeaderChunk header;
        DefendersMidiIO::TrackChunk track;

        Midi() : header( DefendersMidiIO::HeaderChunk() ), track( DefendersMidiIO::TrackChunk() ) {}
    };
}