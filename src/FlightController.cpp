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

#include "FlightController.h"

FlightController::FlightController(int frontLeftMotorPin, int frontRightMotorPin, int backLeftMotorPin, int backRightMotorPin)
{
	this->escs[FRONT_LEFT_MOTOR] = new ESCControl(frontLeftMotorPin, MCPWM_UNIT_0, MCPWM_TIMER_0);
	this->escs[FRONT_RIGHT_MOTOR] = new ESCControl(frontRightMotorPin, MCPWM_UNIT_0, MCPWM_TIMER_1);
	this->escs[BACK_LEFT_MOTOR] = new ESCControl(backLeftMotorPin, MCPWM_UNIT_1, MCPWM_TIMER_0);
	this->escs[BACK_RIGHT_MOTOR] = new ESCControl(backRightMotorPin, MCPWM_UNIT_1, MCPWM_TIMER_1);
}

bool FlightController::init()
{
	for(int i = 0; i < NUM_MOTORS; i++)
	{
		if(!this->escs[i]->init())
			return false;
	}

	return true;
}

bool FlightController::arm()
{
	for(int i = 0; i < NUM_MOTORS; i++)
	{
		if(!this->escs[i]->start())
			return false;
	}

	return true;
}

bool FlightController::kill()
{
	for(int i = 0; i < NUM_MOTORS; i++)
	{
		if(!this->escs[i]->stop())
			return false;
	}

	return true;
}

bool FlightController::throttleAll(float speed)
{
	for(uint8_t i = 0; i < NUM_MOTORS; i++)
	{
		if(!this->escs[i]->setRPMPercentage(speed))
			return false;
	}

	return true;
}