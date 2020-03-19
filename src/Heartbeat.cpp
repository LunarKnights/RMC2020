/**
 * Lunar Knights
 *
 * Sachin Shah
 * February 08, 2020
 *
 * The TalonSRX motors require the enable
 * signal every 200ms, this maintains that thread 
 */

#define Phoenix_No_WPI
#include "ctre/Phoenix.h"
#include "ctre/phoenix/platform/Platform.h"
#include "ctre/phoenix/unmanaged/Unmanaged.h"
#include <iostream>
#include <chrono>
#include <thread>

#include "LK/comm/Log.h"
#include "LK/Heartbeat.h"

// default constructor, heartbeat is not running
Heartbeat::Heartbeat() : running(false) {}

// initalize the can bus
void Heartbeat::init()
{
	info("Initalizing can0");
	ctre::phoenix::platform::can::SetCANInterface("can0");
}

// start the heartbeat thread
void Heartbeat::start()
{
	info("Starting heartbeat");
	running = true;
	thr = std::thread([&]() {
		while (running)
		{
			ctre::phoenix::unmanaged::FeedEnable(100);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	});
}

// stop the heartbeat thread and wait for finish
void Heartbeat::stop()
{
	running = false;
	thr.join();
	info("Heartbeat stopped");
}