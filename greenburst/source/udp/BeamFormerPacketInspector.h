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
#ifndef GREENBURST_SOURCE_UDP_BEAMFORMERPACKETINSPECTOR_H
#define GREENBURST_SOURCE_UDP_BEAMFORMERPACKETINSPECTOR_H

#include "greenburst/source/udp/BeamFormerPacket.h"
#include "greenburst/source/udp/BeamFormerPacketHeader.h"


namespace greenburst {
namespace source {
namespace udp {


/**
 * @brief
 * @details
 */

class BeamFormerPacketInspector
{
    public:
        typedef BeamFormerPacket Packet;

    public:
        BeamFormerPacketInspector(Packet const& packet);
        ~BeamFormerPacketInspector();

        inline uint64_t sequence_number() const {
            return _header.sequence_number();
        }

        inline unsigned channel() const {
            return _header.channel();
        }

        Packet const& packet() const { return _packet; }

        inline bool ignore() { return false; }

    private:
        BeamFormerPacket const& _packet;
        BeamFormerPacketHeader _header;
};


} // namespace udp
} // namespace source
} // namespace greenburst

#endif // GREENBURST_SOURCE_UDP_BEAMFORMERPACKETINSPECTOR_H
