/*
 * File Example1.h in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#ifndef EXTRA_EXAMPLES_H_
#define EXTRA_EXAMPLES_H_

#include <memory>

#include "../Divisaction.h"
#include "../DivisactionExtras.h"

#include "../Extra/NoAnticipation/Actions.h"
#include "../Extra/Screening/Actions.h"

namespace Divisaction {

    class Examples {
        private:
            Examples();

            virtual ~Examples();

        public:
            static std::shared_ptr<WorldManager> example1();

            static std::shared_ptr<WorldManager> exampleCoop();

            static std::shared_ptr<WorldManager> exampleCoopNoAnticipation();

            static std::shared_ptr<WorldManager> exampleCoopScreening();

    };

} /* namespace Divisaction */

#endif /* EXTRA_EXAMPLES_H_ */