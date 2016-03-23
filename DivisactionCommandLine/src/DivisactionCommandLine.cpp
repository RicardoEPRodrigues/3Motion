//============================================================================
// Name        : DivisactionCommandLine.cpp
// Author      : Ricardo Rodrigues
// Version     :
// Copyright   : Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <functional>
#include "mamma.h"
#include "Looper.h"
using namespace std;
using namespace Divisaction;
using namespace DivisactionCommandLine;

int counter = 0;
Looper * looper = new Looper();

void callback() {
	cout << counter << endl;
	if (counter >= 10) {
		looper->stop();
	}
	counter++;
}

int main() {
	mamma * mom = new mamma();
	mom->screamMom();

	looper->start(callback);

	function<void()> callbackFunc = bind(&mamma::screamMom, mom);
	looper->start(callbackFunc);

	return 0;
}
