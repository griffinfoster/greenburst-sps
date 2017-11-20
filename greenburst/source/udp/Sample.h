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
#ifndef GREENBURST_SOURCE_UDP_SAMPLE_H
#define GREENBURST_SOURCE_UDP_SAMPLE_H

#include <cstdlib>
#include <cstdint>

namespace greenburst {
namespace source {
namespace udp {

/**
 * @brief
 *    The representation of each channel sample in the udp packet
 * @details
 */

class Sample
{
        friend class BeamFormerPacket;

    public:
        Sample();
        Sample(uint8_t xx, uint8_t yy);
        ~Sample();
        uint8_t header() const;
        uint8_t xx() const;
        uint8_t yy() const;

    private:
        uint8_t _h;
        uint8_t _xx;
        uint8_t _yy;
};


} // namespace udp
} // namespace source
} // namespace greenburst

#endif // GREENBURST_SOURCE_UDP_SAMPLE_H
