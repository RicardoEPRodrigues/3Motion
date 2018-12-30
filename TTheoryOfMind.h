/*
 * File MentalState.h in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#ifndef DIVISACTION_THEORYOFMIND_H
#define DIVISACTION_THEORYOFMIND_H

#include <memory>

#include "TMentalState.h"
#include "Events/TActionEvent.h"
#include "Events/TEmotionEvent.h"
#include "MentalStates/TSelfMentalState.h"
#include "MentalStates/TOtherMentalState.h"

namespace ThreeMotion {

    class TTheoryOfMind {
        public:
            typedef std::vector<TOtherMentalState> OthersMentalStates;

            TTheoryOfMind();

            explicit TTheoryOfMind(std::weak_ptr<TIAgent> const & selfAgent);

            virtual ~TTheoryOfMind();

            TSelfMentalState self;
            OthersMentalStates others;

            void Initialize(std::weak_ptr<TIAgent> const& selfAgent);

            void Update(std::shared_ptr<struct TEvent>& event);

            TOtherMentalState* GetOther(const std::string& agentName);
    };

} /* namespace ThreeMotion */

#endif //DIVISACTION_THEORYOFMIND_H
