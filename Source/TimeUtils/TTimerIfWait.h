
/*
 * File DTimerIfWait.h in project ThreeMotion
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DTIMERIFWAIT_H
#define DIVISACTION_DTIMERIFWAIT_H

#include "TTimerWait.h"

namespace ThreeMotion {

    class TTimerIfWait : public TTimerWait {
        protected:
            bool OnUpdate(milliseconds counter) override;

        public:
            std::function<bool(milliseconds)> onUpdateCallback;

            explicit TTimerIfWait(
                    std::function<void()> const& onCompleteCallback,
                    std::function<bool(milliseconds)> const& onUpdateCallback,
                    milliseconds duration = 1000);
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_DTIMERIFWAIT_H
