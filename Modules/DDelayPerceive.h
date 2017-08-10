/*
 * File DelayPerceive.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_DELAYPERCEIVE_H
#define DIVISACTION_DELAYPERCEIVE_H

#include "../DTime.h"
#include "../DModule.h"

namespace Divisaction {

    class DDelayPerceive : public PerceiveModule {

        protected:
            virtual void _execute(const std::vector<std::shared_ptr<DEvent>>& param) override;
    };

} /* namespace Divisaction */

#endif //DIVISACTION_DELAYPERCEIVE_H
