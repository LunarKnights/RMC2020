/**
 * Lunar Knights
 *
 * Sachin Shah
 * February 10, 2020
 *
 * Wrapper for all robot subsystems and controls.
 */

#include "LK/robot.h"
#include "LK/comm/Log.h"

#include "LK/hardware/Motor.h"
#include "LK/subsystems/Base.h"
#include "LK/Heartbeat.h"

Heartbeat *beat;
Motor *front_left, *front_right, *back_left, *back_right;
Base *base;

void init()
{
	beat = new Heartbeat();
	beat->init();

	front_left = new Motor(2);
	back_left = new Motor(3);
	front_right = new Motor(4);
	back_right = new Motor(5);

	base = new Base(*front_left, *back_left, *front_right, *back_right);

	info("Initalized");
}

double get_current(int id)
{
	switch (id)
	{
		case 1: return front_left->get_current();
		case 2: return back_left->get_current();
		case 3: return front_right->get_current();
		case 4: return back_right->get_current();
		default: return 0;
	}
}

void start()
{
	beat->start();
	info("Started");
}

void teleop(int key, double value)
{
	switch(key)
	{
		case LeftX: break;
		case LeftY:
			base->set_left(value);
			break;
		case RightX: break;
		case RightY:
			base->set_right(value);
			break;
		case LeftTrigger: break;
		case RightTrigger: break;
		case A: break;
		case B: break;
		case X: break;
		case Y: break;
		case BACK: break;
		case XBOX: break;
		case START: break;
		case JoyL: break;
		case JoyR: break;
		case LeftBumper:
			stop();
			break;
		case RightBumper: break;
		case Up: break;
		case Down: break;
		case Left: break;
		case Right: break;
		default: break;
	}
}

void stop()
{
	base->kill();
	beat->stop();
}


