/*
 * File SingleActionDecide.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_SINGLEACTIONDECIDE_H
#define DIVISACTION_SINGLEACTIONDECIDE_H

#include "../DModule.h"

namespace Divisaction {

    class SingleActionDecide : public InterpretModule {
        private:
            bool alreadyActed;
        protected:
            virtual void _execute() override;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_SINGLEACTIONDECIDE_H
