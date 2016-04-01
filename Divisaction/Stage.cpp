/*
 * File Stage.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Stage.h"
#include <math.h>
using namespace std;

namespace Divisaction {

Stage::Stage() {
	startTime = system_clock::now();
	name = string();
	durationInMilliseconds = 0;
}

Stage::~Stage() {
}

void Stage::start(double durationInMilliseconds, std::string name) {
	this->name = name;
	this->durationInMilliseconds = durationInMilliseconds;
	this->startTime = system_clock::now();

}

double Stage::getProgress() {
	return getProgress(system_clock::now());
}

double Stage::getProgress(system_clock::time_point now) {
	return getProgress(startTime, now, durationInMilliseconds);
}

double Stage::getProgress(system_clock::time_point start,
		system_clock::time_point now, double durationInMilliseconds) {
	if (durationInMilliseconds <= 0) {
		return 0;
	}
	double difference =
			chrono::duration_cast<chrono::milliseconds>(now - start).count();

	if (difference > durationInMilliseconds) {
		return 1;
	} else {
		return (difference / (double) durationInMilliseconds);
	}
}

double Stage::restart() {
	this->startTime = system_clock::now();
	return getProgress();
}

} /* namespace Divisaction */
