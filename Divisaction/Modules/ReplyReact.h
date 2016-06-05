/*
 * File ReplyReact.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_REPLYREACT_H
#define DIVISACTION_REPLYREACT_H

#include "../Module.h"

namespace Divisaction {

    class ReplyReact : public ReactModule {

        public:
            virtual void execute() override;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_REPLYREACT_H
