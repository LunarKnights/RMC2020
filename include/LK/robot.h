#ifndef _LK_ROBOT_H
#define _LK_ROBOT_H

#include "LK/hardware/Motor.h"
#include "LK/subsystems/Base.h"
#include "LK/Heartbeat.h"

/*
extern Heartbeat *beat;
extern Motor *front_left, *back_left, *front_right, *back_right;
extern Base *base;
*/

enum commands {LeftX, LeftY, RightX, RightY, LeftTrigger, RightTrigger, A, B, X, Y, BACK, XBOX, START, JoyL, JoyR, LeftBumper, RightBumper, Up, Down, Left, Right};

void init();

void start();

void teleop(int key, double value);

void stop();

double get_current(int id);

#endif
