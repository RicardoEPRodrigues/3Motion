/*
 * File MentalState.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_THEORYOFMIND_H
#define DIVISACTION_THEORYOFMIND_H

#include <memory>

#include "DMentalState.h"
#include "Events/DActionEvent.h"
#include "Events/DEmotionEvent.h"
#include "MentalRepresentations/DSelfMentalState.h"
#include "MentalRepresentations/DOtherMentalState.h"

namespace ThreeMotion {

    class DTheoryOfMind {
        public:
            typedef std::vector<DOtherMentalState> OthersMentalStates;

            DTheoryOfMind();

            DTheoryOfMind(std::weak_ptr<DIAgent> selfAgent);

            virtual ~DTheoryOfMind();

            DSelfMentalState self;
            OthersMentalStates others;

            void initialize(std::weak_ptr<DIAgent> selfAgent);

            void update(std::shared_ptr<struct DEvent>& event);

            DOtherMentalState* getOther(const std::string agentName);
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_THEORYOFMIND_H
