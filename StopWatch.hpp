//
// Created by aleks on 01/28/21.
//

#ifndef HOMEWORK1_STOPWATCH_HPP
#define HOMEWORK1_STOPWATCH_HPP
#include <chrono>
using std::chrono::system_clock;
using std::chrono::time_point;

class StopWatch {
public:
	StopWatch();
	void start();
	void stop();
	double getTimeSec();
	double getTimeMilli();
private:
	time_point<system_clock> strtTime_;
	time_point<system_clock> endTime_;
};


#endif //HOMEWORK1_STOPWATCH_HPP
