/*
 * File CoopSceneHannaReact.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_COOPSCENEHANNAREACT_H
#define DIVISACTION_COOPSCENEHANNAREACT_H

#include "../Module.h"

namespace Divisaction {

    class CoopSceneHannaReact : public ReactModule {
        private:
            std::vector<bool> alreadyFelt;
        public:
            CoopSceneHannaReact();
            virtual void execute() override;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_COOPSCENEHANNAREACT_H
