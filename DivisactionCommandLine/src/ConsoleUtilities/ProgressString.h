/*
 * File ProgressString.h in project DivisactionCommandLine
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef CONSOLEUTILITIES_PROGRESSSTRING_H_
#define CONSOLEUTILITIES_PROGRESSSTRING_H_

#include <string>
#include <chrono>
using namespace std::chrono;

namespace DivisactionCommandLine {

class ProgressString {
private:
	system_clock::time_point startTime;

	std::string getProgress(system_clock::time_point now);
public:
	std::string name;
	unsigned nameMaxSize;
	unsigned progressMaxSize;
	long int durationInMilliseconds;

	ProgressString();
	virtual ~ProgressString();

	std::string start(long int durationInMilliseconds, std::string name = std::string());
	std::string update();
	std::string restart();

};

} /* namespace DivisactionCommandLine */

#endif /* CONSOLEUTILITIES_PROGRESSSTRING_H_ */
