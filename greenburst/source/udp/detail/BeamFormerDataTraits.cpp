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

// recursive part of chunk filling.
// This function will keep requesting new chunks until the packet is consumed
template<typename ContextType, typename IteratorType>
static
void do_deserialise_packet(ContextType& context, BeamFormerDataTraits::Packet const& packet, unsigned const sample_number, IteratorType&& it)
{
    auto& chunk = context.chunk();
    auto sample_num = sample_number;

    PANDA_LOG_DEBUG << "do_deserialise_packet: sample_number=" << sample_number << " " << context;
    while(sample_num < packet.number_of_samples()) {
        auto end = chunk->end();
        if(it == end) {
            auto next = context.next();
            do_deserialise_packet<ContextType, IteratorType>(*next, packet, sample_num, std::move(next->chunk()->begin()));
            return;
        }
        auto const& sample = packet.sample(sample_num);
        // Stokes I only
        *it = sample.xx();
        ++sample_num;
        ++it;
    }
}

template<typename ContextType>
void BeamFormerDataTraits::deserialise_packet(ContextType& context, Packet const& packet)
{
    // case I: packet > chunk
    // [-- Packet 0 --][-- Packet 1 --][-- Packet 2 --]
    // [Chunk 0][Chunk 1][Chunk 2]
    // chunk_len * chunk_number = packet_num * packet_data
    // chunk_len * chunk_number = packet_num * (chunk_len + delta) + offset
    // offset = chunk_len * chunk_number - packet_num * (chunk_len + delta)
    //        = chunk_len(chunk_number - packet_num) - packet_num * delta
    //
    unsigned offset = context.offset(); // * (context.chunk().number_of_channels() * context.chunk().number_of_samples())  - (context.sequence_number() * context.data().packet_size());
    PANDA_LOG_DEBUG << " --- deserialise_packet: sequence_number=" << context.sequence_number(packet) << " " << context;
    auto it=context.chunk()->begin() + offset; //(BeamFormerDataTraits::sequence_number(packet) - context.start()) + offset;
    do_deserialise_packet(context, packet, 0U, std::move(it));
}

template<typename ContextType>
void BeamFormerDataTraits::process_missing_slice(ContextType& context)
{
    PANDA_LOG_DEBUG << "processing missing packet: " << context;
}

constexpr uint64_t BeamFormerDataTraits::max_sequence_number()
{
    return 0xffffffff >> 10;
}

} // namespace udp
} // namespace source
} // namespace greenburst
