//
// Created by aleks on 01/28/21.
//

#include "StopWatch.hpp"
#include <chrono>
using std::chrono::steady_clock;
using std::chrono::system_clock;
using std::chrono::duration;


StopWatch::StopWatch():endTime_() {
	start();
}

void StopWatch::start() {
	strtTime_ = system_clock::now();
}

void StopWatch::stop() {
	endTime_ = system_clock::now();
}

double StopWatch::getTimeSec() {
	auto timeDiff = endTime_ - strtTime_;
	return duration<double>(timeDiff).count();
}

double StopWatch::getTimeMilli() {
	auto timeDiff = endTime_ - strtTime_;
	return duration<double,std::milli>(timeDiff).count();
}
