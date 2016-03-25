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

void callback() {
//	cout << counter << endl;
	cout << progressState->update() << endl;
	if (counter >= 30) {
		looper->stop();
	}
	counter++;
}

int main() {

	progressState->start(10000, "My Action");
	looper->start(callback);

//	mamma * mom = new mamma();
//	mom->screamMom();
//	function<void()> callbackFunc = bind(&mamma::screamMom, mom);
//	looper->start(callbackFunc);

	return 0;
}
