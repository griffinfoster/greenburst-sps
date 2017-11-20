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
#include "greenburst/source/udp/BeamFormerPacket.h"
#include "greenburst/source/udp/BeamFormerPacketHeader.h"


namespace greenburst {
namespace source {
namespace udp {


BeamFormerPacket::BeamFormerPacket()
{
}

BeamFormerPacket::~BeamFormerPacket()
{
}

Sample const& BeamFormerPacket::sample(unsigned sample_number) const
{
    return _samples[sample_number];
}

void BeamFormerPacket::set_header(BeamFormerPacketHeader const& h)
{
    const unsigned char* header_bytes = reinterpret_cast<const unsigned char*>(&h.data());
    for(unsigned i=0; i < sizeof(uint64_t); ++i) {
        _samples[i]._h = header_bytes[i];
    }
}

} // namespace udp
} // namespace source
} // namespace greenburst
