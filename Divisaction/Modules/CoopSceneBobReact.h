/*
 * File CoopSceneBobReact.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_COOPSCENEBOBREACT_H
#define DIVISACTION_COOPSCENEBOBREACT_H

#include "../Module.h"

namespace Divisaction {

    class CoopSceneBobReact : public ReactModule {
        private:
            std::vector<bool> alreadyFelt;
        public:
            CoopSceneBobReact();
            virtual void execute() override;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_COOPSCENEBOBREACT_H
