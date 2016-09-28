/*
 * File CoopSceneBob.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "CoopSceneBob.h"

using namespace std;
using namespace placeholders;

namespace Divisaction {
    NoAnticipation::CoopSceneBob::CoopSceneBob() : Agent() {
        perceiveModules.push_back(std::make_unique<DelayPerceive>());

        reactModules.push_back(std::make_unique<NoAnticipation::CoopSceneBobReact>());

        decideModules.push_back(std::make_unique<CoopSceneBobDecide>());

        performModules.push_back(std::make_unique<Perform>());
    }

} /* namespace Divisaction */