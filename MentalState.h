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
#include "MentalRepresentations/SelfMentalRepresentation.h"
#include "MentalRepresentations/OtherMentalRepresentation.h"

namespace Divisaction {

    class MentalState {
        public:
            typedef std::vector<OtherMentalRepresentation> OthersMentalRep;

            MentalState();

            MentalState(std::weak_ptr<IAgent> selfAgent);

            virtual ~MentalState();

            SelfMentalRepresentation self;
            OthersMentalRep others;

            void initialize(std::weak_ptr<IAgent> selfAgent);

            void update(std::shared_ptr<class Event>& event);

            OtherMentalRepresentation* getOther(const std::string agentName);
    };

} /* namespace Divisaction */

#endif //DIVISACTION_MENTALSTATE_H
