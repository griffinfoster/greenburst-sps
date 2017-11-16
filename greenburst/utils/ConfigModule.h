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
#ifndef GREENBURST_UTILS_CONFIGMODULE_H
#define GREENBURST_UTILS_CONFIGMODULE_H


#include "panda/ConfigModule.h"
#include "panda/Config.h"
#include "cheetah/utils/System.h"
#include "panda/arch/nvidia/Nvidia.h"
#include "panda/Cpu.h"
#include <string>

namespace greenburst {
namespace utils {

/**
 * @brief
 * @details
 */

class ConfigModule : public ska::panda::ConfigModule
{
    public:
        typedef ska::panda::Config<ska::panda::nvidia::Cuda, ska::panda::Cpu> ConfigType;
        typedef typename ConfigType::PoolManagerType PoolManagerType;

    public:
        ConfigModule(std::string const&);
        ~ConfigModule();

    private:
};


} // namespace utils
} // namespace greenburst

#endif // GREENBURST_UTILS_CONFIGMODULE_H
