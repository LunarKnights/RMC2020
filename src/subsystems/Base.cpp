/**
 * Lunar Knights
 *
 * Sachin Shah
 * February 08, 2020
 *
 * Base subsystem movements, 4 TalonSRX motors
 */

#include "LK/hardware/Motor.h"
#include "LK/subsystems/Base.h"

// Construct the base with 4 motors
Base::Base(Motor &fl, Motor &bl, Motor &fr, Motor &br) : front_left(fl), back_left(bl), front_right(fr), back_right(br) {}

void Base::set_left(double power)
{
	front_left.set(power);
	back_left.set(power);
}

void Base::set_right(double power)
{
	front_right.set(power);
	back_right.set(power);
}

// Tank drive, each side is controlled independently
void Base::tank_drive(double left, double right)
{
	set_left(left);
	set_right(right);
}

// Aracade drive, seperate turning and forward values
void Base::arcade_drive(double forward, double turn)
{
	double left = forward - turn;
	double right = forward + turn;

	tank_drive(left, right);
}

// Stop the base
void Base::kill()
{
	tank_drive(0, 0);
}