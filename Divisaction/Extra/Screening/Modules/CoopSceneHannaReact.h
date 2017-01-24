/*
 * File CoopSceneHannaReact.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_NOANTICIPATION_COOPSCENEHANNAREACT_H
#define DIVISACTION_NOANTICIPATION_COOPSCENEHANNAREACT_H

#include "../../../DModule.h"

namespace Divisaction {
    namespace Screening {
        class CoopSceneHannaReact : public ReactModule {
            public:
                CoopSceneHannaReact();

            protected:
                virtual void _execute() override;

            private:
                std::vector<bool> alreadyFelt;
        };
    }

} /* namespace Divisaction */

#endif //DIVISACTION_SCREENING_COOPSCENEHANNAREACT_H
