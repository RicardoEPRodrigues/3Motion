/*
 * File SingleActionDecide.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_SINGLEACTIONDECIDE_H
#define DIVISACTION_SINGLEACTIONDECIDE_H

#include "../Module.h"

namespace Divisaction {

    class SingleActionDecide : public DecideModule {
        private:
            bool alreadyActed;
        public:
            virtual void execute() override;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_SINGLEACTIONDECIDE_H