/* mbed Microcontroller Library
 * Copyright (c) 2017 Nuvoton
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MBED_NAU88L25_H
#define MBED_NAU88L25_H

#include "mbed.h"

#include "I2S.h"

namespace mbed_nuvoton {

class NAU88L25
{        
    public:
        NAU88L25(PinName i2c_sda, PinName i2c_scl, int i2c_addr, PinName i2s_do, PinName i2s_di, PinName i2s_bclk, PinName i2s_mclk, PinName i2s_lrck);
        NAU88L25(PinName i2c_sda, PinName i2c_scl, int i2c_addr, PinName i2s_do, PinName i2s_di, PinName i2s_bclk, PinName i2s_mclk, PinName i2s_lrck, char i2s_master_enable, char codec_master_enable);
        void power(void);
        void start(void);
        void record(void);
        void stop(void);
        void write(int *buffer, int from, int length);
        void read(void);
        void attach(void(*fptr)(void));
        void attach(Callback<void()> func);
        void format(int rate, char count, char length);
        void lock(void);
        void unlock(void);
        void loopback(void);
        void readwrite(void);
        
        int  *rxBuffer;
        
    private:
        int  m_addr;
        char m_masterMode;
        
        I2C         m_I2C;
        NuI2SDevice m_I2S;
        
        void I2C_WriteNAU88L25(uint16_t u16addr, uint16_t u16data);
        
};

}   /* namespace mbed_nuvoton */

#endif
