/*
 * File CoopSceneBobReact.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_SCREENING_COOPSCENEBOBREACT_H
#define DIVISACTION_SCREENING_COOPSCENEBOBREACT_H

#include "../../../DModule.h"

namespace Divisaction {
    namespace Screening {
        class CoopSceneBobReact : public ReactModule {
            public:
                CoopSceneBobReact();

            protected:
                virtual void _execute() override;

            private:
                std::vector<bool> alreadyFelt;
        };
    }

} /* namespace Divisaction */

#endif //DIVISACTION_SCREENING_COOPSCENEBOBREACT_H