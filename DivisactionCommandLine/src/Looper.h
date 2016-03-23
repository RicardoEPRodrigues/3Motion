/*
 * File Looper.h in project DivisactionCommandLine
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef LOOPER_H_
#define LOOPER_H_

#include <functional>

namespace DivisactionCommandLine {

class Looper {
private:
	bool continueLoop;
	std::function<void()> callback;

public:
	Looper();
	virtual ~Looper();

	/**
	 * interval in which the loop will run in milliseconds.
	 * It's default value is 250 milliseconds.
	 */
	long int interval;

	/**
	 * Starts the loop and on each loop it calls the function callback.
	 *
	 * @param callback function, it is called at each loop of the looper.
	 */
	void start(std::function<void()> callback);

	void stop();
};

} /* namespace Divisaction */

#endif /* LOOPER_H_ */
