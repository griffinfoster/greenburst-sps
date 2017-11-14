/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2018 Oxford Astrophysics
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef GREENBURST_SOURCE_UDP_BEAMFORMERDATATRAITS_H
#define GREENBURST_SOURCE_UDP_BEAMFORMERDATATRAITS_H

#include "greenburst/source/udp/BeamFormerPacket.h"
#include "cheetah/data/TimeFrequency.h"

namespace greenburst {
namespace source {
namespace udp {

/**
 * @brief
 *    Traits describing the BeamFormer Data Stream to the panda::PacketSream system
 * @details
 */

class BeamFormerDataTraits
{
    public:
        typedef ska::cheetah::data::TimeFrequency<ska::panda::Cpu, uint8_t> DataType;
        typedef BeamFormerPacket Packet;

    public:
        BeamFormerDataTraits();
        ~BeamFormerDataTraits();

        /**
         * @brief returns the sequential number of the chunk that the packet belongs to
         * @details do not call this function before a call to packets_per_chunk has been made at least once
         */
        uint64_t sequence_number(Packet const& packet) const;

        /**
         * @brief the maximum value a packet sequence number will reach
         */
        static constexpr uint64_t max_sequence_number();

        /**
         * @brief return the number of signal samples in a packet
         */
        static std::size_t packet_size();

        /**
         * @brief return the total number of samples (time_samples * channels) in the data 
         */
        static std::size_t chunk_size(DataType const& data);

        /**
         * @brief ignore all packets other than the StokesI
         */
        bool ignore(Packet const& packet) const;

        /**
         * @brief function responsible for transfering data from the packet in to the
         *        data structure
         */
        template<typename ContextType>
        void deserialise_packet(ContextType& context, Packet const&);

        /**
         * @brief perform operations to compenste for a missing packet
         * @details currently this does nothing, but this is expected to change
         */
        template<typename ContextType>
        void process_missing_slice(ContextType& context);
};


} // namespace udp
} // namespace source
} // namespace greenburst
#include "BeamFormerDataTraits.cpp"

#endif // GREENBURST_SOURCE_UDP_BEAMFORMERDATATRAITS_H
