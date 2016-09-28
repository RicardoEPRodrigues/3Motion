/*
 * File CoopSceneBobReact.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_NOANTICIPATION_COOPSCENEBOBREACT_H
#define DIVISACTION_NOANTICIPATION_COOPSCENEBOBREACT_H

#include "../../../Module.h"

namespace Divisaction {
    namespace NoAnticipation {
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

#endif //DIVISACTION_NOANTICIPATION_COOPSCENEBOBREACT_H
