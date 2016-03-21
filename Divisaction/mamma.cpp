/*
 * File mamma.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "mamma.h"
#include <iostream>

using namespace std;

namespace Divisaction {

mamma::mamma() {
	// TODO Auto-generated constructor stub

}

mamma::~mamma() {
	// TODO Auto-generated destructor stub
}


void mamma::screamMom() {
	string * mom = nullptr;
	mom = new string("Your MOMO!");
	cout << *mom << endl;
}

} /* namespace Divisaction */
