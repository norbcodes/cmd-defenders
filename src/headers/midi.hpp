#pragma once

#include "midi_io.hpp"
#include <memory>

/*
Functions from midi.cpp and stuff
*/

// Just in case so we don't clash with RtMidi and its stuff
namespace DefendersMidi
{
    struct Midi
    {
        DefendersMidiIO::HeaderChunk header;
        std::unique_ptr< std::vector<DefendersMidiIO::TrackChunk> > track;

        Midi()
        : header( DefendersMidiIO::HeaderChunk() ), track( std::make_unique<std::vector<DefendersMidiIO::TrackChunk>>() ) 
        {
            this->track->reserve(INT8_MAX);  // 127 should be enough, hopefully
        }
    };
}

void ReadMidiFile(const std::string& path, DefendersMidi::Midi& write_to);