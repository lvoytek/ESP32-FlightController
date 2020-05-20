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

#ifndef FLIGHTCONTROLLER_H
#define FLIGHTCONTROLLER_H

#include "ESCControl.h"

#define NUM_MOTORS 4
#define FRONT_LEFT_MOTOR 0
#define FRONT_RIGHT_MOTOR 1
#define BACK_LEFT_MOTOR 2
#define BACK_RIGHT_MOTOR 3

class FlightController
{
protected:
	ESCControl * escs[NUM_MOTORS];

public:
	/**
	 * @brief Initialize the ESCs and the accelerometer objects
	 * 
	 * @param frontLeftMotorPin The ESC PWM pin for controlling the front left motor
	 * @param frontRightMotorPin The ESC PWM pin for controlling the front right motor
	 * @param backLeftMotorPin The ESC PWM pin for controlling the back left motor
	 * @param backRightMotorPin The ESC PWM pin for controlling the back right motor
	 */
	FlightController(int frontLeftMotorPin, int frontRightMotorPin, int backLeftMotorPin, int backRightMotorPin);

	/**
	 * @brief Initialize ESC PWM connections and start the I2C accelerometer connection
	 * 
	 * @return
	 *     - true Successful start
	 *     - false Activation failed
	 */
	bool init();

	/**
	 * @brief Arm the motors
	 * 
	 * @return
	 * 		- true Successful arming
	 * 		- false motors are still disarmed
	 */
	bool arm();

	/**
	 * @brief Kill motor movement
	 * 
	 * @return
	 * 		- true all motors killed
	 * 		- false some motors still armed
	 */
	bool kill();
};

#endif