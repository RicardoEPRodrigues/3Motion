/*
 * File ReplyReact.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_REPLYREACT_H
#define DIVISACTION_REPLYREACT_H

#include "../TModule.h"

namespace ThreeMotion {

    class DReplyReact : public InterpretModule {
        protected:
            virtual void _execute() override;
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_REPLYREACT_H
