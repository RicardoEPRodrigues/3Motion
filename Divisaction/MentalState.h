/*
 * File MentalState.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_MENTALSTATE_H
#define DIVISACTION_MENTALSTATE_H

#include <memory>

#include "MentalRepresentation.h"
#include "Events/ActionEvent.h"
#include "Events/EmotionEvent.h"
#include "Events/ReplyEvent.h"

namespace Divisaction {

    class MentalState {
        private:
            typedef std::vector<std::pair<std::weak_ptr<class IAgent>, MentalRepresentation>> MentalRepresentations;
        public:
            virtual ~MentalState();
            MentalRepresentation self;
            MentalRepresentations others;

            void update(std::shared_ptr<class Event>& event);
    };

} /* namespace Divisaction */

#endif //DIVISACTION_MENTALSTATE_H
