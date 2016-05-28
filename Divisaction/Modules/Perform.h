/*
 * File Perform.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_PERFORM_H
#define DIVISACTION_PERFORM_H

#include "../Module.h"

namespace Divisaction {

    class Perform : public Module<const std::vector<std::shared_ptr<Event>>, void> {

        public:
            virtual const std::vector<std::shared_ptr<Event>> execute() override;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_PERFORM_H
