/*
 * File Perform.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_PERFORM_H
#define DIVISACTION_PERFORM_H

#include "../DModule.h"

namespace Divisaction {

    class DPerform : public PerformModule {

        protected:
            virtual void _execute(std::vector<std::shared_ptr<DEvent>>&) override;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_PERFORM_H
