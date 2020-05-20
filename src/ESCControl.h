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

#ifndef ESCCONTROL_H
#define ESCCONTROL_H

#include <driver/mcpwm.h>

#define ESC_DEFAULT_PERIOD_S .02
#define ESC_DEFAULT_FREQUENCY_HZ 50
#define ESC_DEFAULT_MIN_DUTY 5
#define ESC_DEFAULT_MAX_DUTY 10

/**
 * @brief Enumeration of MCPWM capable pins on the Adafruit ESP32 Feather
 */
typedef enum
{
	PIN_A0 = 26,
	PIN_A1 = 25,
	PIN_A5 = 4,
	PIN_21 = 21,
	PIN_13 = 13,
	PIN_12 = 12,
	PIN_27 = 27,
	PIN_33 = 33,
	PIN_15 = 15,
	PIN_32 = 32,
	PIN_14 = 14
} esp32_feather_pwm_capable_pins;


class ESCControl
{
protected:
	//The number of the GPIO pin using PWM control on the ESC
	int escPin;

	//ESP-32 motor PWM unit used to control this pin
	mcpwm_unit_t pwmUnit;

	//The number of the PWM Timer used on the given pwm unit (use unique timer for each ESC, operator A always used)
	mcpwm_timer_t pwmTimer;

	//The configuration settings for the PWM unit
	mcpwm_config_t confData;

	//The active duty percentage for this ESC
	float activeDuty;

	//The timer + operator being used for this ESC
	mcpwm_io_signals_t mcpwmSignal;

public:
	/**
	 * @brief Setup specified PWM pin using a given MCPWM unit and timer 
	 * 
	 * @param escPin The GPIO pin to send PWM signals through
	 * @param pwmUnit The MCPWM unit to use for timing for this ESC
	 * @param pwmTimer The MCPWM timer to use
	 */
	ESCControl(int escPin, mcpwm_unit_t pwmUnit, mcpwm_timer_t pwmTimer);

	/**
	 * @brief Initialize the mcpwm unit and prepare for gpio output use

	 * @return
	 *     - true Initialization successful
	 *     - false MCPWMn failure
	 */
	bool init();

	/**
	 * @brief Activate the PWM output in current configuration
	 * 
	 * @return
	 *     - true Successful start
	 *     - false Activation failed
	 */
	bool start();

	/**
	 * @brief Deactivate all PWM outputs in current configuration
	 * 
	 * @return
	 *     - true Successful stop
	 *     - false Deactivation failed
	 */
	bool stop();

	/**
	 * @brief Set the RPM percentage
	 * 
	 * @param rpmPercentage The speed percentage to set the motor to, 0 is off and 100 is max
	 * 
	 * @return
	 *      - true Successful speed change
	 *      - false Speed change failed
	 */
	bool setRPMPercentage(float rpmPercentage);
};

#endif