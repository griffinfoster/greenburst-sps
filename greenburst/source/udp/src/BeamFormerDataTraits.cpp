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

/*
Sample const BeamFormerDataTraits::sample(unsigned sample_number) const
{
    return packet.sample(sample_number);
}
*/

uint64_t BeamFormerDataTraits::sequence_number(Packet const& packet) const
{
    // create header
    //unsigned char[Packet::number_of_samples()] header_bytes;
    unsigned char header_bytes[Packet::number_of_samples()];
    for(unsigned i=0; i < Packet::number_of_samples(); ++i) {
        header_bytes[i] = packet.sample(i).header();
    }
    uint64_t& header = *reinterpret_cast<uint64_t*>(&header_bytes);
    return header >> 10;
}

std::size_t BeamFormerDataTraits::chunk_size(DataType const& chunk)
{
    return chunk.number_of_samples() * chunk.number_of_channels();
}


std::size_t BeamFormerDataTraits::packet_size()
{
    return Packet::number_of_samples() * sizeof(uint8_t);
}

bool BeamFormerDataTraits::ignore(Packet const&) const
{
    return false;
}

} // namespace udp
} // namespace source
} // namespace greenburst
