/*
 * File MentalState.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_THEORYOFMIND_H
#define DIVISACTION_THEORYOFMIND_H

#include <memory>

#include "MentalState.h"
#include "Events/ActionEvent.h"
#include "Events/EmotionEvent.h"
#include "MentalRepresentations/SelfMentalState.h"
#include "MentalRepresentations/OtherMentalState.h"

namespace Divisaction {

    class TheoryOfMind {
        public:
            typedef std::vector<OtherMentalState> OthersMentalStates;

            TheoryOfMind();

            TheoryOfMind(std::weak_ptr<IAgent> selfAgent);

            virtual ~TheoryOfMind();

            SelfMentalState self;
            OthersMentalStates others;

            void initialize(std::weak_ptr<IAgent> selfAgent);

            void update(std::shared_ptr<class Event>& event);

            OtherMentalState* getOther(const std::string agentName);
    };

} /* namespace Divisaction */

#endif //DIVISACTION_THEORYOFMIND_H
