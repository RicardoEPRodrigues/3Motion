/*
 * File SingleEmotionReact.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_SINGLEEMOTIONREACT_H
#define DIVISACTION_SINGLEEMOTIONREACT_H

#include "../Module.h"

namespace Divisaction {

    class SingleEmotionReact : public Module<void, void> {
        private:
            bool alreadyFelt;
        public:
            virtual void execute() override;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_SINGLEEMOTIONREACT_H
