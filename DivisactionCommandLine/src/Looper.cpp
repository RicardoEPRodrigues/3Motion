/*
 * File Looper.cpp in project DivisactionCommandLine
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Looper.h"
#include <chrono>
#include <thread>

namespace DivisactionCommandLine {

using namespace std;

Looper::Looper() {
	continueLoop = false;
	interval = 250;
}

Looper::~Looper() {

}

void Looper::start(std::function<void()> callback) {
	this->continueLoop = true;

	this->callback = callback;

	chrono::milliseconds intervalMilliseconds(this->interval); // 1/4 second

	while (this->continueLoop) {
		this->callback();
		this_thread::sleep_for(intervalMilliseconds);
	}
}

void Looper::stop() {
	this->continueLoop = false;
}

} /* namespace Divisaction */
