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

#include "greenburst/pipeline/Factory.h"
#include "greenburst/pipeline/EmptyPipeline.h"
#include "greenburst/pipeline/SinglePulseSearch.h"
#include "greenburst/pipeline/RfimPipeline.h"


namespace greenburst {
namespace pipeline {

Factory::Factory(GreenburstConfiguration& config, Exporter& exporter)
    : BaseT("pipeline::Factory")
    , _config(config)
{
    add_type("empty", [&, this]() { return new EmptyPipeline(_config, exporter); });
    add_type("rfim", [&, this]() { return new RfimPipeline(_config, exporter); });
    add_type("sps", [&, this]() { return new SinglePulseSearch(_config, exporter); });
}

Factory::~Factory()
{
}

} // namespace pipeline
} // namespace greenburst
