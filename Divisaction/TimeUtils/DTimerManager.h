
/*
 * File DTimerManager.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DTIMERMANAGER_H
#define DIVISACTION_DTIMERMANAGER_H

#include <vector>
#include <memory>
#include "DTimer.h"

namespace Divisaction {

    class DTimerManager {
        public:
            DTimerManager();

            virtual ~DTimerManager();

        protected:
            void timersUpdate();

            std::shared_ptr<DTimer>
            wait(milliseconds duration, std::function<void()> onCompleteCallback);

            std::shared_ptr<DTimer>
            ifWait(milliseconds duration, std::function<void()> onCompleteCallback,
                   std::function<bool(milliseconds)> onUpdateCallback);

        private:
            std::vector<std::shared_ptr<DTimer>> timers;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_DTIMERMANAGER_H
