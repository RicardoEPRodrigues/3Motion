/*
 * File SingleEmotionReact.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_SINGLEEMOTIONREACT_H
#define DIVISACTION_SINGLEEMOTIONREACT_H

#include "../DModule.h"

namespace Divisaction {

    class SingleEmotionReact : public ReactModule {
        private:
            bool alreadyFelt;
        protected:
            virtual void _execute() override ;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_SINGLEEMOTIONREACT_H
