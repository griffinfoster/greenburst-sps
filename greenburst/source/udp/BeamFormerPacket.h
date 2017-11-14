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
#ifndef GREENBURST_SOURCE_UDP_BEAMFORMERPACKET_H
#define GREENBURST_SOURCE_UDP_BEAMFORMERPACKET_H

#include "Sample.h"
#include <cstddef>


namespace greenburst {
namespace source {
namespace udp {

/**
 * @brief
 *     The bit representation of the UDP packet
 * @details
 *     designed to be reinterpret_cast from a bit pattern
 */

class BeamFormerPacket
{
    public:
        BeamFormerPacket();
        ~BeamFormerPacket();

        /**
         * @brief the total size in bytes of the packet (less the headers)
         */
        constexpr static std::size_t payload_size();

        /**
         * @brief the number of channel samples in each packet
         */
        constexpr static unsigned number_of_samples();

        /**
         * @brief access the sample_number sample from the begininning of the packet (starting at 0)
         */
        Sample const& sample(unsigned sample_number) const;

    private:
        Sample _samples[8];
};

constexpr std::size_t BeamFormerPacket::payload_size()
{
    return 768;
}

constexpr unsigned BeamFormerPacket::number_of_samples()
{
    return payload_size()/sizeof(Sample);
}

} // namespace udp
} // namespace source
} // namespace greenburst

#endif // GREENBURST_SOURCE_UDP_BEAMFORMERPACKET_H
