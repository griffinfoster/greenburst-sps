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
#include "pipeline/GreenburstConfiguration.h"


namespace greenburst {
namespace pipeline {


GreenburstConfiguration::GreenburstConfiguration()
    : BaseT("greenburst", "pipeline launcher")
    , _stream_name("udp")
{
    add(_sigproc_stream_config);
}

GreenburstConfiguration::~GreenburstConfiguration()
{
}

void GreenburstConfiguration::add_options(OptionsDescriptionEasyInit& add_options) 
{
    add_options
        ("timer", boost::program_options::value<bool>(&_handler_timing)->default_value(false), "record execution time for each invocation of the computation part of the pipeline")
        ("input-stream,s", boost::program_options::value<std::string>(&_stream_name)->default_value("udp"), "select the input stream for the pipeline")
        ("list-input-streams", "list the available input streams for the pipeline and exit")
        ("list-pipeline", "list the available computational pipeline and exit")
        ("pipeline,p", boost::program_options::value<std::string>(&_pipeline_name), "specify the computational pipeline to run");
}

std::string const& GreenburstConfiguration::stream_name() const
{
    return _stream_name;
}

std::string const& GreenburstConfiguration::pipeline_name() const
{
    return _pipeline_name;
}

sigproc::Config const& GreenburstConfiguration::sigproc_stream_config() const 
{
    return _sigproc_stream_config;
}

} // namespace pipeline
} // namespace greenburst
