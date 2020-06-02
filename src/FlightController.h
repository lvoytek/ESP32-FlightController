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

	/**
	 * @brief Throttle all motors on the aircraft to a certain percentage
	 * 
	 * @param speed The throttle percentage of the motors
	 * 
	 * @return
	 * 		- true Speed change success
	 * 		- false Speed change failure
	 */
	bool throttleAll(float speed);

	/**
	 * @brief Make a series of throttle changes to reorient the aircraft to have no tilt and level out altitude
	 * 
	 * @return
	 * 		- true Drone managed to reorient itself automatically
	 * 		- false reorientation failed
	 */
	bool reorient();

	/**
	 * @brief Tilt the aircraft and begin moving forward while maintaining altitude
	 * 
	 * @param speed The forward speed percentage corresponding to tilt angle and motor speed
	 * 
	 * @return
	 * 		- true tilt and speed adjust success
	 * 		- false tilt unsucessful or undetected
	 */
	bool forward(float speed);

	/**
	 * @brief Tilt the aircraft and begin moving backward while maintaining altitude
	 * 
	 * @param speed The reverse speed percentage corresponding to tilt angle and motor speed
	 * 
	 * @return
	 * 		- true tilt and speed adjust success
	 * 		- false tilt unsucessful or undetected
	 */
	bool reverse(float speed);

	/**
	 * @brief Tilt the aircraft and begin moving left while maintaining altitude
	 * 
	 * @param speed The leftward speed percentage corresponding to tilt angle and motor speed
	 * 
	 * @return
	 * 		- true tilt and speed adjust success
	 * 		- false tilt unsucessful or undetected
	 */
	bool left(float speed);

	/**
	 * @brief Tilt the aircraft and begin moving right while maintaining altitude
	 * 
	 * @param speed The rightward speed percentage corresponding to tilt angle and motor speed
	 * 
	 * @return
	 * 		- true tilt and speed adjust success
	 * 		- false tilt unsucessful or undetected
	 */
	bool right(float speed);

	/**
	 * @brief Yaw the aircraft clockwise by increasing cw-oriented motor throttle and decreasing ccw-oriented motor throttle
	 * 
	 * @param speed The clockwise speed corresponding to the variation in throttle between cw and ccw motors
	 * 
	 * @return
	 * 		- true motor speeds changed
	 * 		- false rotation initialization unsuccessful
	 */
	bool yawCW(float speed);

	/**
	 * @brief Yaw the aircraft counter-clockwise by increasing ccw-oriented motor throttle and decreasing cw-oriented motor throttle
	 * 
	 * @param speed The counter-clockwise speed corresponding to the variation in throttle between ccw and cw motors
	 * 
	 * @return
	 * 		- true motor speeds changed
	 * 		- false rotation initialization unsuccessful
	 */
	bool yawCCW(float speed);
};

#endif