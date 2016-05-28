/*
 * File SingleReplyAgent.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "SingleReplyAgent.h"

namespace Divisaction {

    SingleReplyAgent::SingleReplyAgent() {
        perceiveModules.push_back(std::make_unique<DelayPerceive>());

        reactModules.push_back(std::make_unique<SingleReplyReact>());

        performModules.push_back(std::make_unique<Perform>());
    }

} /* namespace Divisaction */
