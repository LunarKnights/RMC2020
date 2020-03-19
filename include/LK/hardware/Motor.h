#ifndef _LK_MOTOR_H
#define _LK_MOTOR_H

#include "ctre/phoenix/motorcontrol/can/TalonSRX.h"

class Motor
{
	private:
		ctre::phoenix::motorcontrol::can::TalonSRX internal_motor;
	public:
		Motor(int id);
		void reverse();
		void set(double power);
		void kill();
		double get_current();
};

#endif
