
/*
 * File DTimerManager.h in project ThreeMotion
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DTIMERMANAGER_H
#define DIVISACTION_DTIMERMANAGER_H

#include <vector>
#include <memory>
#include <functional>
#include "TTimer.h"

namespace ThreeMotion {

    class TTimerManager {
        private:
            std::vector<std::shared_ptr<TTimer>> timers;
        public:
            TTimerManager();

            virtual ~TTimerManager();

            void UpdateTimers();

            std::shared_ptr<TTimer>
            Wait(milliseconds duration,
                 std::function<void()> onCompleteCallback);

            std::shared_ptr<TTimer>
            IfWait(milliseconds duration,
                   std::function<void()> onCompleteCallback,
                   std::function<bool(milliseconds)> onUpdateCallback);

    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_DTIMERMANAGER_H
