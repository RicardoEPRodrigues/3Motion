/*
 * File ProgressString.cpp in project DivisactionCommandLine
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "ProgressString.h"
#include <math.h>
using namespace std;

namespace DivisactionCommandLine {

ProgressString::ProgressString() {
	startTime = system_clock::now();
	name = string();
	nameMaxSize = 20;
	progressMaxSize = 40;
	durationInMilliseconds = 0;
}

ProgressString::~ProgressString() {
}

std::string ProgressString::start(long int durationInMilliseconds,
		std::string name) {
	this->name = name;
	this->durationInMilliseconds = durationInMilliseconds;
	this->startTime = system_clock::now();

	return getProgress(system_clock::now());
}

std::string ProgressString::update() {
	return getProgress(system_clock::now());
}

std::string ProgressString::getProgress(system_clock::time_point now) {
	if (name.length() <= 0 || name.length() >= nameMaxSize
			|| durationInMilliseconds <= 0) {
		return string("ERROR");
	}

	string actionProgress = string(name);
	actionProgress += string(nameMaxSize - name.length(), ' ');
	actionProgress += '[';
	double difference = chrono::duration_cast<chrono::milliseconds>(now - startTime).count();
	if (difference > durationInMilliseconds) {
		actionProgress += string(progressMaxSize, '*');
	} else {
		unsigned progress = floor((difference/(double) durationInMilliseconds) * (double) progressMaxSize);
		actionProgress += string(progress, '*');
		actionProgress += string(progressMaxSize - progress, ' ');
	}
	actionProgress += ']';

	return actionProgress;
}

std::string ProgressString::restart() {
	this->startTime = system_clock::now();
	return getProgress(system_clock::now());
}

} /* namespace DivisactionCommandLine */
