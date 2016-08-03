
/*
 * File DTimerWait.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DTIMERWAIT_H
#define DIVISACTION_DTIMERWAIT_H

#include <memory>
#include "DTimer.h"

namespace Divisaction {

    class DTimerWait : public DTimer {
        public:
            DTimerWait(milliseconds duration = 1000, std::function<void()> onCompleteCallback = []() {});

            const std::function<void()>& getOnCompleteCallback() const;

            void setOnCompleteCallback(const std::function<void()>& onCompleteCallback);

        protected:
            void onComplete() override;

        private:
            std::function<void()> onCompleteCallback;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_DTIMERWAIT_H
