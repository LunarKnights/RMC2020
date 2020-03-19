#ifndef _LK_HEARTBEAT_H
#define _LK_HEARTBEAT_H

#include <thread>
#include <atomic>

class Heartbeat
{
	private:
		std::thread thr;
		std::atomic<bool> running;
	public:
		Heartbeat();
		void init();
		void start();
		void stop();
};

#endif