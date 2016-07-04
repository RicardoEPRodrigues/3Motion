/*
 * File SingleActionAgent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "SingleActionAgent.h"

using namespace std;
using namespace std::placeholders;

namespace Divisaction {

    SingleActionAgent::SingleActionAgent()
            : Agent() {
        perceiveModules.push_back(std::make_unique<DelayPerceive>());

        reactModules.push_back(std::make_unique<SingleEmotionReact>());
        reactModules.push_back(std::make_unique<ReplyReact>());

        decideModules.push_back(std::make_unique<SingleActionDecide>());

        performModules.push_back(std::make_unique<Perform>());
    }

} /* namespace Divisaction */
