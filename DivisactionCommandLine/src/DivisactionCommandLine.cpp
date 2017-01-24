//============================================================================
// Name        : DivisactionCommandLine.cpp
// Author      : Ricardo Rodrigues
// Version     :
// Copyright   : Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Divisaction.h"

#include "Extra/Looper.h"
#include "Extra/Examples.h"

#include "ConsoleUtilities/ProgressString.h"
using namespace std;
using namespace Divisaction;
using namespace DivisactionCommandLine;

int counter = 0;
ProgressString * progressState = new ProgressString();
Looper * looper = new Looper();

std::shared_ptr<WorldManager> worldManager = nullptr;

void basicExample() {
//  cout << counter << endl;
    cout << progressState->update() << endl;

    if (counter >= 30) {
        looper->stop();
    }
    counter++;
}

//Event currentEvent;
bool hasEvent = false;

void worldManagerTesting() {
    worldManager->update();

    if (counter == 10) {
        looper->stop();
    }
    counter++;
}

int main() {
    worldManager = Examples::example1();
//	progressState->start(10000, "My Action");
	looper->setInterval(100);
	looper->start(worldManagerTesting);

//	mamma * mom = new mamma();
//	mom->screamMom();
//	function<void()> callbackFunc = bind(&mamma::screamMom, mom);
//	looper->start(callbackFunc);

	return 0;
}
