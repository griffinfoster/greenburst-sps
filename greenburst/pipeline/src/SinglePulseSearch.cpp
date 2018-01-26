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
#include "greenburst/pipeline/SinglePulseSearch.h"


namespace greenburst {
namespace pipeline {


SinglePulseSearch::SinglePulseSearch(GreenburstConfiguration const& config, typename ProcessingPipeline::Exporter& exporter)
    : ProcessingPipeline(exporter)
    , _sps(config.module_config<ska::cheetah::sps::Config>(), 
            [](std::shared_ptr<Sps::DmTrialType>) {},
            [this](std::shared_ptr<Sps::SpType> data) {
                // send to the exporter
                out().send(ska::panda::ChannelId("sps"), *data);
                for(auto& time_freq : data->tf_blocks())
                {
                    out().send(ska::panda::ChannelId("sps"), time_freq);
                }
            }
            )
    , _rfim(config.module_config<ska::cheetah::rfim::Config>() , _sps)
{
}

SinglePulseSearch::~SinglePulseSearch()
{
}

void SinglePulseSearch::operator()(TimeFrequencyType& data)
{
    _rfim.run(data);
    _sps(data);
}

} // namespace pipeline
} // namespace greenburst
