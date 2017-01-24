/*
 * File ReplyReact.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_REPLYREACT_H
#define DIVISACTION_REPLYREACT_H

#include "../DModule.h"

namespace Divisaction {

    class ReplyReact : public ReactModule {
        protected:
            virtual void _execute() override;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_REPLYREACT_H
