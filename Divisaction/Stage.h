/*
 * File Stage.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef STAGE_H_
#define STAGE_H_

#include <string>
#include <chrono>
using namespace std::chrono;

namespace Divisaction {

class Stage {
private:
	system_clock::time_point startTime;

	double getProgress(system_clock::time_point now);
public:
	std::string name;
	double durationInMilliseconds;

	Stage();
	virtual ~Stage();

	void start(double durationInMilliseconds, std::string name = std::string());
	double restart();

	/**
	 * Return the current progress of the action.
	 * @return Progress value between 0 and 1. If the stage hasn't been started it'll return 0. If the stage is complete it'll always return 1.
	 */
	double getProgress();
	static double getProgress(system_clock::time_point start,
			system_clock::time_point now, double durationInMilliseconds);
};

} /* namespace Divisaction */

#endif /* STAGE_H_ */
