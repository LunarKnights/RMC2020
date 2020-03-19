#ifndef _LK_STEPPERMOTOR_H
#define _LK_STEPPERMOTOR_H

#include <wiringPi.h>

class StepperMotor
{
	private:
		int pin_out;
		int pin_dir;
		int steps;
		bool direction;
	public:
		StepperMotor(int out, int dir);
		void step_up();
		void step_down();
		int get_steps();
		void set_direction(bool forward);
		void turn(double revolutions, double speed);

#endif
