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
#include "MentalRepresentations/SelfMentalRepresentation.h"
#include "MentalRepresentations/OthersMentalRepresentation.h"

namespace Divisaction {

    class MentalState {
        private:
            typedef std::vector<OthersMentalRepresentation> MentalRepresentations;
        public:
            MentalState();

            MentalState(std::weak_ptr<IAgent> selfAgent);

            virtual ~MentalState();

            SelfMentalRepresentation self;
            MentalRepresentations others;

            void initialize(std::weak_ptr<IAgent> selfAgent);

            void update(std::shared_ptr<class Event>& event);
    };

} /* namespace Divisaction */

#endif //DIVISACTION_MENTALSTATE_H
