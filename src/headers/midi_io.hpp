#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <memory>

namespace DefendersMidiIO
{
    struct VariableLength
    {
        // Midi has this thing that sometimes when specifying length of events etc.
        // If the most significant byte is set, we need to read another byte.
        // This means 0x81 0x7F translates to 255 because why not apparently??
        private:
            unsigned int length;

        public:
            VariableLength() : length(0) {}

            VariableLength(unsigned int length) : length(length) {}

            unsigned int GetLength() const
            {
                return this->length;
            }
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

            void SetFormat(unsigned short n)
            {
                this->format = n;
            }

            unsigned short GetFormat() const
            {
                return this->format;
            }

            void SetDivision(short n)
            {
                this->division = n;
            }

            short GetDivision() const
            {
                return this->division;
            }

            void SetTrackChunkAmount(unsigned short n)
            {
                this->track_chunks = n;
            }

            unsigned short GetTrackChunkAmount() const
            {
                return this->track_chunks;
            }
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

    struct MetaEvent
    {
        private:
            unsigned char meta_type;
            std::unique_ptr< std::vector<char> > data;
        public:
            MetaEvent(unsigned char meta_type, const VariableLength& var_length)
            : meta_type(meta_type), data( std::make_unique< std::vector<char> >() )
            {
                this->data->reserve(var_length.GetLength());
            }
    };

    // Pretty sure that Sysex won't be needed since we just need to play a midi file

    struct TrackEvent
    {
        // What the hell happens on this delightful track?
        private:
            VariableLength delta;  // Elapsed time since last track event??
            MidiEvent midi_data;

        public:
            TrackEvent() : delta(0) {}

            TrackEvent(const VariableLength& delta, const MidiEvent& midi_data)
            : delta(delta), midi_data(midi_data) {}
    };

    struct TrackChunk
    {
        // Contains TrackEvents
        private:
            std::unique_ptr< std::vector<TrackEvent> > events;
        
        public:
            TrackChunk() : events( std::make_unique<std::vector<TrackEvent>>() )
            {
                this->events->reserve(UINT16_MAX);
            }

            void PushBackEvent(const TrackEvent& event)
            {
                this->events->emplace_back(event);
            }
    };
}