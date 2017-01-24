/*
 * File CoopSceneBobDecide.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_COOPSCENEBOBDECIDE_H
#define DIVISACTION_COOPSCENEBOBDECIDE_H

#include "../DModule.h"

namespace Divisaction {

    class CoopSceneBobDecide : public DecideModule {
        public:
            CoopSceneBobDecide();

            virtual ~CoopSceneBobDecide();

        protected:
            virtual void _execute();

        private:
            bool alreadyActed;
            std::shared_ptr<DTimer> timer;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_COOPSCENEBOBDECIDE_H
