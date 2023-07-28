#pragma once

#include <cstdint>

enum EventTypes
{
    MIDI,
    META,
    SYSEX  
    // call me childish but... Sy-sex LMAO
    // Errrr... professionalism Norb.
};

struct HeaderChunk
{
    // A midi header chunk.
    private:
        unsigned short format;
        unsigned short track_chunks;
        short division;
    
    public:
        HeaderChunk() : format(UINT16_MAX), track_chunks(UINT16_MAX), division(INT16_MAX) {}

        HeaderChunk(unsigned short format, unsigned short track_chunks, short division)
        : format(format), track_chunks(track_chunks), division(division)
        {}
};

struct MidiEvent
{
    // A midi event.
    private:
        unsigned char param1;
        unsigned char param2;
        unsigned char param3;
        // Midi parameters etc. etc. y'know all the good stuff

    public:
        MidiEvent() : param1(UINT8_MAX), param2(UINT8_MAX), param3(UINT8_MAX) {}

        MidiEvent(unsigned char a, unsigned char b, unsigned char c)
        : param1(a), param2(b), param3(c) {}

        unsigned char GetParam(char a) const
        {
            switch (a)
            {
                case 1:
                    return this->param1;
                case 2:
                    return this->param2;
                case 3:
                    return this->param3;
            }
        }
};

// TODO: MetaEvent
// TODO: SysexEvent

struct TrackEvent
{
    // What the hell happens on this delightful track?
    private:
        unsigned int delta;  // Elapsed time since last track event??
        EventTypes event_type;
        MidiEvent midi_data;
};