#ifndef _LK_BASE_H
#define _LK_BASE_H

#include "LK/hardware/Motor.h"

class Base
{
	private:
		Motor &front_left, &back_left, &front_right, &back_right;
	public:
		Base(Motor &fl, Motor &bl, Motor &fr, Motor &br);
		void set_left(double power);
		void set_right(double power);
		void tank_drive(double left, double right);
		void arcade_drive(double foward, double turn);
		void kill();
};

#endif
