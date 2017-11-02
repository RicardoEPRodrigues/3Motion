/*
 * File SingleEmotionReact.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_SINGLEEMOTIONREACT_H
#define DIVISACTION_SINGLEEMOTIONREACT_H

#include "../TModule.h"

namespace ThreeMotion {

    class DSingleEmotionReact : public InterpretModule {
        private:
            bool alreadyFelt;
        protected:
            virtual void _execute() override;
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_SINGLEEMOTIONREACT_H
