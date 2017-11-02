/*
 * File SingleReplyReact.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_SINGLEREPLYREACT_H
#define DIVISACTION_SINGLEREPLYREACT_H

#include "../TModule.h"

namespace ThreeMotion {

    class DSingleReplyReact : public InterpretModule {

        protected:
            virtual void _execute() override;
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_SINGLEREPLYREACT_H
