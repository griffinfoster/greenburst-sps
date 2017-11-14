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
#include "greenburst/pipeline/GreenburstConfiguration.h"


namespace greenburst {
namespace pipeline {


GreenburstConfiguration::GreenburstConfiguration()
    : BaseT("greenburst")
{
    add(_sources_config);
    add(_cheetah_config);
}

GreenburstConfiguration::~GreenburstConfiguration()
{
}

void GreenburstConfiguration::add_options(OptionsDescriptionEasyInit&) 
{
}

std::string const& GreenburstConfiguration::source_name() const
{
    return _cheetah_config.stream_name();
}

source::Config const& GreenburstConfiguration::source_config() const
{
    return _sources_config;
}

ska::cheetah::exporters::DataExportConfig const& GreenburstConfiguration::sink_config() const
{
    return _cheetah_config.data_config().data_export_config();
}

ska::cheetah::pipeline::CheetahConfig const& GreenburstConfiguration::cheetah_config() const
{
    return _cheetah_config;
}

} // namespace pipeline
} // namespace greenburst
