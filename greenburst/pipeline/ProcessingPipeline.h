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
#ifndef GREENBURST_PIPELINE_PROCESSINGPIPELINE_H
#define GREENBURST_PIPELINE_PROCESSINGPIPELINE_H

#include "greenburst/pipeline/GreenburstConfiguration.h"
#include "cheetah/data/TimeFrequency.h"
#include "panda/Pipeline.h"


namespace greenburst {
namespace pipeline {

typedef ska::cheetah::data::TimeFrequency<ska::panda::Cpu, uint8_t> TimeFrequencyType;

/**
 * @brief
 * @details
 */

class ProcessingPipeline
{
    public:
        ProcessingPipeline();

        virtual ~ProcessingPipeline() = 0;

        virtual void operator()(TimeFrequencyType&) =0;

    private:
};

template<typename InputStreamType>
int exec_pipeline(InputStreamType& data_stream, GreenburstConfiguration const& , std::shared_ptr<ProcessingPipeline> const& runtime_handler)
{
    return ska::panda::Pipeline<InputStreamType>(data_stream, [runtime_handler](TimeFrequencyType& d1){ runtime_handler->operator()(d1); } ).exec();
}

} // namespace pipeline
} // namespace greenburst

#endif // GREENBURST_PIPELINE_PROCESSINGPIPELINE_H
