
/*
 * File DTimerWait.h in project ThreeMotion
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DTIMERWAIT_H
#define DIVISACTION_DTIMERWAIT_H

#include <memory>
#include <functional>
#include "TTimer.h"

namespace ThreeMotion {

    class TTimerWait : public TTimer {
        protected:
            void OnComplete() override;

        public:
            std::function<void()> onCompleteCallback;

            explicit TTimerWait(std::function<void()> const& onCompleteCallback,
                                milliseconds duration = 1000);
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_DTIMERWAIT_H
