/*
* Copyright (c) 2020 Lena Voytek
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

#ifndef BASEACCELEROMETER_H
#define BASEACCELEROMETER_H

#include <stdint.h>

/**
 * @brief A parent class for all supported accelerometer sensors
 */
class BaseAccelerometer
{
protected:

    //The I2C address of the accelerometer
    uint8_t address;

public:
    /**
     * @brief Initialize an accelerometer object with a given I2C address
     *
     * @param address The I2C address of the sensor
     */
     BaseAccelerometer(uint8_t address)
     {
        this->address = address;
     };

	/**
	 * @brief Activate the I2C connection with the accelerometer
	 * 
	 * @return
	 * 		- true accelerometer activated
	 * 		- accelerometer unavailable
	 */
    virtual bool begin();

    /**
     * @brief Read a byte from the accelerometer at a given register
     *
     * @param reg The register location to read from
     *
     * @return The byte stored in the given accelerometer register
     */
    virtual uint8_t read(uint8_t reg);
    
    /**
     * @brief Write a byte to an accelerometer register
     *
     * @param reg The register location to write to
     * @param data The byte to write to the register
     */
    virtual void write(uint8_t reg, uint8_t data);
};

#endif