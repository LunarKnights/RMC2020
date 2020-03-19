/**
 * Lunar Knights
 *
 * Sachin Shah
 * February 08, 2020
 *
 * Implementation of the TalonSRX motor
 */

#define Phoenix_No_WPI
#include "ctre/Phoenix.h"

#include "LK/comm/Log.h"
#include "LK/hardware/Motor.h"

// Create a TalonSRX with id
Motor::Motor(int id) : internal_motor(id) {}

// Reverse the direction of the motor
void Motor::reverse()
{
	info("Reversing motor " + std::to_string(internal_motor.GetDeviceID()));
	internal_motor.SetInverted(true);
}

// Set the power of the motor on [-1, 1]
void Motor::set(double power)
{
	if (power > 1 || power < -1)
	{
		error(std::to_string(power) + " is out of bounds for motor " + std::to_string(internal_motor.GetDeviceID()));
	}
	else
	{
		internal_motor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, power);
	}
}

// Stop the motor
void Motor::kill()
{
	set(0);
}

double Motor::get_current()
{
	return internal_motor.GetOutputCurrent();
}
