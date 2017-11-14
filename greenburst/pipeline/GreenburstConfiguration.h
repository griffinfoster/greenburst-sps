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
#ifndef GREENBURST_PIPELINE_GREENBURSTCONFIGURATION_H
#define GREENBURST_PIPELINE_GREENBURSTCONFIGURATION_H


#include "greenburst/utils/ConfigModule.h"
#include "greenburst/source/Config.h"
#include "cheetah/pipeline/CheetahConfig.h"

namespace greenburst {
namespace pipeline {

/**
 * @brief
 * @details
 */

class GreenburstConfiguration : public ska::cheetah::pipeline::CheetahConfig //: public utils::ConfigModule::ConfigType
{
        //typedef utils::ConfigModule::ConfigType BaseT;
        typedef ska::cheetah::pipeline::CheetahConfig BaseT;

    public:
        GreenburstConfiguration();
        ~GreenburstConfiguration();

        std::string const& source_name() const;
        source::Config const& source_config() const;
        ska::cheetah::exporters::DataExportConfig const& sink_config() const;
        ska::cheetah::pipeline::CheetahConfig const& cheetah_config() const;

    protected:
        void add_options(OptionsDescriptionEasyInit& add_options) override;

    private:
        source::Config _sources_config;
        ska::cheetah::pipeline::CheetahConfig _cheetah_config;
};


} // namespace pipeline
} // namespace greenburst

#endif // GREENBURST_PIPELINE_GREENBURSTCONFIGURATION_H
