
/*
 * File DTimerWait.h in project ThreeMotion
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DTIMERWAIT_H
#define DIVISACTION_DTIMERWAIT_H

#include <memory>
#include <functional>
#include "DTimer.h"

namespace ThreeMotion {

    class DTimerWait : public DTimer {
        public:
            DTimerWait(milliseconds duration = 1000,
                       std::function<void()> onCompleteCallback = []() {});

            const std::function<void()>& getOnCompleteCallback() const;

            void setOnCompleteCallback(const std::function<void()>& onCompleteCallback);

        protected:
            void onComplete() override;

        private:
            std::function<void()> onCompleteCallback;
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_DTIMERWAIT_H
