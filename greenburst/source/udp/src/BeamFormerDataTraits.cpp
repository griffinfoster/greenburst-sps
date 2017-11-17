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
#include "greenburst/source/udp/detail/BeamFormerDataTraits.h"


namespace greenburst {
namespace source {
namespace udp {


BeamFormerDataTraits::BeamFormerDataTraits()
{
}

BeamFormerDataTraits::~BeamFormerDataTraits()
{
}

uint64_t BeamFormerDataTraits::sequence_number(PacketInspector const& packet) const
{
    return packet.sequence_number();
}

std::size_t BeamFormerDataTraits::chunk_size(DataType const& chunk)
{
    return chunk.size();
}


std::size_t BeamFormerDataTraits::packet_size()
{
    return Packet::number_of_samples * sizeof(uint8_t);
}

bool BeamFormerDataTraits::align_packet(PacketInspector const& packet ) const
{
    if(packet.channel() == 00) return true; // must align to start of channels
    return false;
}

} // namespace udp
} // namespace source
} // namespace greenburst
