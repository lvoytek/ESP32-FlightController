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

#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include "Accelerometers/BaseAccelerometer.h"

/**
 * @brief Accelerometer class supports the following sensors when specified
 */
typedef enum
{
	MPU6050 = 0
} SupportedSensor;


class Accelerometer
{
protected:

	BaseAccelerometer * accel;
	SupportedSensor sensorType;

	//Callibration offsets for angles
	float pitchOffset;
	float rollOffset;
	float yawOffset;

	//Callibration offsets for acceleration
	float upwardAccelOffset;
	float forwardAccelOffset;
	float lrAccelOffset;

	//Most recent angle measurements
	float currentPitch;
	float currentRoll;
	float currentYaw;

	//Most recent acceleration measurements
	float currentUp;
	float currentLeft;
	float currentForward;

public:
	/**
	 * @brief Initialize the sensor object matching the given type
	 *
	 * @param sensorType The enum for the type of sensor being used
	 */
	Accelerometer(SupportedSensor sensorType);

	/**
	 * @brief Attempt to initialize communication with the given accelerometer
	 *
	 * @return
	 * 		- true accelerometer activated
	 * 		- accelerometer unavailable
	 */
	bool init();

	/**
	 * @brief Callibrate the accelerometer by getting current values assuming the drone is on a perfectly flat surface and not moving
	 */
	void callibrate();

	/**
	 * @brief Read all angles and accelerations and store locally
	 */
	void update();

	/**
	 * @brief Get the current pitch angle in degrees
	 *
	 * @return The current pitch in degrees
	 */
	float getPitch();

	/**
	 * @brief Get the current roll angle in degrees
	 *
	 * @return The current roll angle in degrees
	 */
	float getRoll();

	/**
	 * @brief Get the current yaw offset from startup in degrees
	 *
	 * @return The current yaw angle in degrees
	 */
	float getYaw();

	/**
	 * @brief Get the current forward acceleration (Gs)
	 *
	 * @return The current forward acceleration as compared to 1G
	 */
	float getAccelForward();

	/**
	 * @brief Get the current left-right acceleration (Gs)
	 *
	 * @return The current left-right acceleration as compared to 1G (left is positive)
	 */
	float getAccelLR();

	/**
	 * @brief Get the current upward acceleration (Gs)
	 *
	 * @return The current upward acceleration as compared to 1G
	 */
	float getAccelZ();
};

#endif