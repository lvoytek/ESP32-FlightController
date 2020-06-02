#ifndef MPU6050ACCELEROMETER_H
#define MPU6050ACCELEROMETER_H

#include "BaseAccelerometer.h"
#include <driver/i2c.h>

#define MPU6050_ADDR 0x68
#define MPU6050_SMPLRT_DIV 0x19
#define MPU6050_CONFIG 0x1a
#define MPU6050_GYRO_CONFIG 0x1b
#define MPU6050_ACCEL_CONFIG 0x1c
#define MPU6050_WHO_AM_I 0x75
#define MPU6050_PWR_MGMT_1 0x6b
#define MPU6050_TEMP_H 0x41
#define MPU6050_TEMP_L 0x42

class MPU6050Accelerometer : BaseAccelerometer
{
private:
	i2c_config_t i2cConf;

public:
	MPU6050Accelerometer() : BaseAccelerometer(MPU6050_ADDR)
	{
		i2cConf.mode = I2C_MODE_MASTER;
	};

	bool begin()
	{

	};
};

#endif