/*
 * File SelfMentalRepresentation.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_SELFMENTALREPRESENTATION_H
#define DIVISACTION_SELFMENTALREPRESENTATION_H

#include <vector>
#include "../Events/ReplyEvent.h"
#include "../MentalRepresentation.h"
#include "../IAgent.h"

namespace Divisaction {

    struct SelfMentalRepresentation : public MentalRepresentation {
        typedef std::vector<std::shared_ptr<ReplyEvent>> AgentsReplies;

        AgentsReplies replies;

        bool updateReplies;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_SELFMENTALREPRESENTATION_H
