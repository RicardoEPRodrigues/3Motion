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
#include "ConsoleUtilities/ProgressString.h"
using namespace std;
using namespace Divisaction;
using namespace DivisactionCommandLine;

int counter = 0;
ProgressString * progressState = new ProgressString();
Looper * looper = new Looper();
clock_t clocky = clock();

void callback() {
	cout << counter << endl;
	cout << progressState->update() << endl;
	cout << ((clock() - clocky)/ (double) ( CLOCKS_PER_SEC / 1000)) << endl;
	if (counter >= 10) {
		looper->stop();
	}
	counter++;
}

int main() {
	mamma * mom = new mamma();
	mom->screamMom();

	clocky = clock();
	cout << progressState->start(1000, "My Action") << endl;


	looper->start(callback);

//	function<void()> callbackFunc = bind(&mamma::screamMom, mom);
//	looper->start(callbackFunc);

	return 0;
}
