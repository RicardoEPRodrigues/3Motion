
/*
 * File DTimerIfWait.h in project ThreeMotion
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DTIMERIFWAIT_H
#define DIVISACTION_DTIMERIFWAIT_H

#include "DTimerWait.h"

namespace ThreeMotion {

    class DTimerIfWait : public DTimerWait {
        public:
            DTimerIfWait(milliseconds duration = 1000,
                         std::function<void()> onCompleteCallback = []() {},
                         std::function<bool(milliseconds)> onUpdateCallback = [](
                                 milliseconds) { return false; });

            const std::function<bool(milliseconds)>& getOnUpdateCallback() const;

            void setOnUpdateCallback(const std::function<bool(milliseconds)>& onUpdateCallback);

        protected:
            bool onUpdate(milliseconds counter) override;

        private:
            std::function<bool(milliseconds)> onUpdateCallback;
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_DTIMERIFWAIT_H
