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


#include "greenburst/pipeline/ModulesConfig.h"
#include "greenburst/utils/ConfigModule.h"
#include "greenburst/source/Config.h"

namespace greenburst {
namespace pipeline {

/**
 * @brief
 *    Configuration for the greenburst pipelines
 *
 * @details
 */

class GreenburstConfiguration : public utils::ConfigModule::ConfigType
{
        typedef utils::ConfigModule::ConfigType BaseT;

    public:
        GreenburstConfiguration();
        ~GreenburstConfiguration();

        source::Config const& source_config() const;

        /// get the configuration for the specified module
        template<typename T>
        ska::panda::PoolSelector<BaseT::PoolManagerType, T> const& module_config() const { return _modules.template config<T>(); }

    protected:
        void add_options(OptionsDescriptionEasyInit& add_options) override;

    private:
        source::Config _sources_config;
        ModulesConfig<BaseT::PoolManagerType>  _modules;
};


} // namespace pipeline
} // namespace greenburst

#endif // GREENBURST_PIPELINE_GREENBURSTCONFIGURATION_H
