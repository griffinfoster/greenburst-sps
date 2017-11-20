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
#ifndef GREENBURST_SOURCE_UDP_BEAMFORMERPACKETHEADER_H
#define GREENBURST_SOURCE_UDP_BEAMFORMERPACKETHEADER_H

#include <cstdint>

namespace greenburst {
namespace source {
namespace udp {
class BeamFormerPacket;

/**
 * @brief
 *     Coding and decoding of a BeamFormerPacket meta information
 * @details
 */

class BeamFormerPacketHeader
{
    public:
        BeamFormerPacketHeader();
        BeamFormerPacketHeader(BeamFormerPacket const&);
        ~BeamFormerPacketHeader();

       /**
        * @brief the packet sequence number
        */
        inline uint64_t sequence_number() const { return _header >> 10; }

       /**
        * @brief get the channel number of the first sample
        */
        unsigned short channel() const;

       /**
        * @brief set the packet sequence number
        */
        void sequence_number(uint64_t number);

       /**
        * @brief set the channel number of the first sample in the packet
        */
        void channel(unsigned short);

        /**
         * @brief return the encoded packet inforamtion
         */
        uint64_t const& data() const;

    private:
        uint64_t _header;
};


} // namespace udp
} // namespace source
} // namespace greenburst

#endif // GREENBURST_SOURCE_UDP_BEAMFORMERPACKETHEADER_H
