/**
 * Lunar Knights
 *
 * Sachin Shah
 * February 20, 2020
 *
 * Control Nema 23 stepper motors
 *
 */

// Create a stepper motor with 2 pins
StepperMotor::StepperMotor(int out, int dir)
{
	pin_out = out;
	pin_dir = dir;
	direction = 1;

	pinMode(pin_out, OUTPUT);
	pinMode(pint_dir, OUTPUT);
}

// Set the motor pulse to high
void StepperMotor::step_up()
{
	digitalWrite(pin_out, HIGH);
	if (direction) steps++;
	else steps--;
}

// Set the motor pulse to low
void StepperMotor::step_down()
{
	digitalWrite(pin_out, LOW);
}

// Get the number of steps taken
int StepperMotor::get_steps()
{
	return steps;
}

// Set the direction of the motor true=forward false=reverse
void StepperMotor::set_direction(bool forward)
{
	direction = forward;
	digitalWrite(pin_dir, forward ? HIGH : LOW);
}

// Turn the motor a set number of revolutions at a certain speed
void StepperMotor::turn(double revolutions, double speed)
{
	double start_revs = steps / 200.0;
	while (start_revs + revolutions > steps / 200.0)
	{
		step_up();
		delay(100 * speed);
		step_down();
		delay(100 * speed);
	}
}

