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

#include "ESCControl.h"

ESCControl::ESCControl(int escPin, mcpwm_unit_t pwmUnit, mcpwm_timer_t pwmTimer)
{
	this->escPin = escPin;
	this->pwmUnit = pwmUnit;
	this->pwmTimer = pwmTimer;
	this->activeDuty = 0;

	this->confData.frequency = ESC_DEFAULT_FREQUENCY_HZ;
	this->confData.cmpr_a = 0.0;
	this->confData.cmpr_b = 0.0;
	this->confData.duty_mode = MCPWM_DUTY_MODE_0;
	this->confData.counter_mode = MCPWM_UP_COUNTER;
}

bool ESCControl::setRPMPercentage(float rpmPercentage)
{
	if(rpmPercentage > 100)
		rpmPercentage = 100.0;
	else if(rpmPercentage < 0)
		rpmPercentage = 0.0;

	float previousActiveDuty = this->activeDuty;

	//Turn off completely on 0 input
	if(rpmPercentage < .01)
		this->activeDuty = 0;
	else
		this->activeDuty = (ESC_DEFAULT_MAX_DUTY - ESC_DEFAULT_MIN_DUTY) * .01 * rpmPercentage + ESC_DEFAULT_MIN_DUTY;

	if (mcpwm_set_duty(this->pwmUnit, this->pwmTimer, MCPWM_OPR_A, this->activeDuty) != ESP_OK)
	{
		this->activeDuty = previousActiveDuty;
		return false;
	}

	return true;
}