/*
 * File CoopSceneHanna.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "CoopSceneHanna.h"

using namespace std;
using namespace placeholders;

namespace Divisaction {
    Screening::CoopSceneHanna::CoopSceneHanna() : Agent() {
        perceiveModules.push_back(std::make_unique<DelayPerceive>());

        reactModules.push_back(std::make_unique<Screening::CoopSceneHannaReact>());

        decideModules.push_back(std::make_unique<CoopSceneHannaDecide>());

        performModules.push_back(std::make_unique<Perform>());
    }
} /* namespace Divisaction */