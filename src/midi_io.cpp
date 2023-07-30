#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <memory>

#ifdef _NORB_DEBUG_
#include <iostream>
#endif // _NORB_DEBUG_

#include "headers/debug.hpp"

#include "headers/midi_io.hpp"
#include "headers/midi.hpp"

#define HEX(a,b) ((int)a *0x0100) + (int)b

#define isMidiValid(midi)   ( ((int)midi.get() == 0x4D) && ((int)midi.get() == 0x54) && ((int)midi.get() == 0x68) && ((int)midi.get() == 0x64) )
#define isTrackChunk(midi)  ( ((int)midi.get() == 0x4D) && ((int)midi.get() == 0x54) && ((int)midi.get() == 0x72) && ((int)midi.get() == 0x6B) )
#define isMSBset(byte)      ( (byte % 0b10000000) == 0b10000000 )

/*
Wanted to use a library to read and parse midi files
Didn't work so fuck it, i'm making my own
*/

void ReadMidiFile(const std::string& path, DefendersMidi::Midi& write_to)
{
    std::ifstream MidiFile(path, std::ifstream::binary);

    #ifdef _NORB_DEBUG_
    std::ifstream debuggg(path, std::ifstream::binary);
    do
    {
        std::cout << (int)debuggg.get() << ".";
    }
    while (!debuggg.eof());
    std::cout << std::endl;
    #endif // _NORB_DEBUG_

    DEBUG_PRINT("Check if valid");

    if (!isMidiValid(MidiFile)) { return; }

    DEBUG_PRINT("We passed");

    // Get rid of the next 4 bytes, they are the same in all midi files
    for (int i = 0; i != 4; i++) { MidiFile.get(); }

    // Read header data
    write_to.header.SetFormat               ( HEX(MidiFile.get(), MidiFile.get()) );
    write_to.header.SetTrackChunkAmount     ( HEX(MidiFile.get(), MidiFile.get()) );
    write_to.header.SetDivision             ( HEX(MidiFile.get(), MidiFile.get()) );

    DEBUG_PRINT(write_to.header.GetFormat());
    DEBUG_PRINT(write_to.header.GetTrackChunkAmount());
    DEBUG_PRINT(write_to.header.GetDivision());

    DEBUG_PRINT_WAIT("Header info set");

    // Read track chunk data
    if (!isTrackChunk(MidiFile))
    {
        return;
        // just return for now
    }
}