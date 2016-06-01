/*
 * File DelayPerceive.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DELAYPERCEIVE_H
#define DIVISACTION_DELAYPERCEIVE_H

#include "../Time.h"
#include "../Module.h"

namespace Divisaction {

    class DelayPerceive : public PerceiveModule {
        private:
            std::vector<std::pair<double, std::shared_ptr<Event>>> eventsBeingPerceived;
        public:
            virtual void execute(const std::vector<std::shared_ptr<Event>>& param) override;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_DELAYPERCEIVE_H
