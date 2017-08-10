/*
 * File MentalState.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "DTheoryOfMind.h"

using namespace std;

namespace Divisaction {
    DTheoryOfMind::DTheoryOfMind() {}

    DTheoryOfMind::DTheoryOfMind(weak_ptr<DIAgent> selfAgent) {
        initialize(selfAgent);
    }

    DTheoryOfMind::~DTheoryOfMind() {

    }

    void DTheoryOfMind::initialize(std::weak_ptr<DIAgent> selfAgent) {
        this->self.agent = selfAgent;
    }

    void DTheoryOfMind::update(std::shared_ptr<struct DEvent>& event) {
        if (auto selfAgent = self.agent.lock()) {
            if (auto eventAgent = event->sender.lock()) {
                // if the event is from this agent then ignore
                if (selfAgent == eventAgent) {
                    return;
                }

                // find the mental state record for the agent that sent the event
                OthersMentalStates::iterator otherIter = find_if(others.begin(), others.end(),
                                                                 [&eventAgent](
                                                                         const OthersMentalStates::value_type& stored) {
                                                                     if (auto storedEventAgent = stored.agent.lock()) {
                                                                         return storedEventAgent ==
                                                                                eventAgent;
                                                                     } else {
                                                                         return false;
                                                                     }
                                                                 });

                // if there is no record of this event agent, create a record
                if (otherIter == others.end()) {
                    DOtherMentalState other = DOtherMentalState();
                    other.agent = event->sender;
                    otherIter = others.insert(otherIter, other);
                }

                // update the record with the information from the event
                event->update(self, *otherIter);
            }
        }
    }

    DOtherMentalState* DTheoryOfMind::getOther(const std::string agentName) {
        if (agentName.empty()) {
            return nullptr;
        }
        auto otherIter = std::find_if(others.begin(), others.end(),
                                      [agentName](const DOtherMentalState other) {
                                          return other.agentHasName(agentName);
                                      });
        if (otherIter == others.end()) {
            return nullptr;
        }

        return &(*otherIter);
    }
} /* namespace Divisaction */
