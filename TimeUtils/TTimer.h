
/*
 * File DTimer.h in project ThreeMotion
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DTIMER_H
#define DIVISACTION_DTIMER_H

#include "../TTime.h"

namespace ThreeMotion {

    class TTimer {
        private:

            milliseconds counter;

            milliseconds duration;

            bool playing;

        protected:
            /**
             * Called when the Timer completes it's cycle
             */
            virtual void OnComplete();

            /**
             * Called when the Timer is updated, but has not yet completed it's cycle
             * @param counter current time of the cycle
             * @return True if the Timer should stop it's cycle, false otherwise.
             */
            virtual bool OnUpdate(milliseconds counter);

        public:
            explicit TTimer(milliseconds duration = 1000);

            virtual ~TTimer();

            /**
             * Updates the time and checks if the timer has completed
             * @return True if the Timer has completed, false otherwise.
             */
            bool Update();

            bool IsPaused() const;

            void Play();

            void Pause();

            milliseconds GetDuration() const;

            void SetDuration(milliseconds duration);

    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_DTIMER_H
