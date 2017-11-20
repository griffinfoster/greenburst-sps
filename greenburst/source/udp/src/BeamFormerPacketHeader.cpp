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
#include "greenburst/source/udp/BeamFormerPacketHeader.h"
#include "greenburst/source/udp/BeamFormerPacket.h"


namespace greenburst {
namespace source {
namespace udp {


BeamFormerPacketHeader::BeamFormerPacketHeader()
{
}

BeamFormerPacketHeader::BeamFormerPacketHeader(BeamFormerPacket const& packet)
{
    unsigned char* header_bytes = reinterpret_cast<unsigned char*>(&_header);
    for(unsigned i=0; i < sizeof(uint64_t); ++i) {
        header_bytes[i] = packet.sample(i).header();
    }
}

BeamFormerPacketHeader::~BeamFormerPacketHeader()
{
}

uint64_t const& BeamFormerPacketHeader::data() const
{
    return _header;
}

unsigned short BeamFormerPacketHeader::channel() const
{
    return _header & 0x3ff;
}

void BeamFormerPacketHeader::sequence_number(uint64_t number)
{
    _header = (_header & 0x3ff ) | (number << 10);
}

void BeamFormerPacketHeader::channel(unsigned short channel)
{
    //if(channel > 0x3fff) throw panda::Error("channel max exceeded (0x3fff)");
    _header = (_header & ~0x3ff) | (channel & 0x3ff);
}

} // namespace udp
} // namespace source
} // namespace greenburst
