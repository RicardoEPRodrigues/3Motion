/*
 * File MentalState.cpp in project Divisaction
 * 
 * Copyright (C) Ricardo Rodrigues 2016 - All Rights Reserved
 */
#include "TTheoryOfMind.h"

using namespace std;

namespace ThreeMotion {
    TTheoryOfMind::TTheoryOfMind() = default;

    TTheoryOfMind::TTheoryOfMind(weak_ptr<TIAgent> const& selfAgent) {
        Initialize(selfAgent);
    }

    TTheoryOfMind::~TTheoryOfMind() = default;

    void TTheoryOfMind::Initialize(std::weak_ptr<TIAgent> const& selfAgent) {
        this->self.agent = selfAgent;
    }

    void TTheoryOfMind::Update(std::shared_ptr<struct TEvent>& event) {
        if (auto selfAgent = self.agent.lock()) {
            if (auto eventAgent = event->sender.lock()) {
                // if the event is from this agent then ignore
                if (selfAgent == eventAgent) {
                    return;
                }

                // find the mental state record for the agent that sent the event
                auto otherIter = find_if(others.begin(), others.end(),
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
                    TOtherMentalState other = TOtherMentalState();
                    other.agent = event->sender;
                    otherIter = others.insert(otherIter, other);
                }

                // update the record with the information from the event
                event->update(self, *otherIter);
            }
        }
    }

    TOtherMentalState* TTheoryOfMind::GetOther(const std::string& agentName) {
        if (agentName.empty()) {
            return nullptr;
        }
        auto otherIter = std::find_if(others.begin(), others.end(),
                                      [agentName](
                                              const TOtherMentalState other) {
                                          return other.agentHasName(agentName);
                                      });
        if (otherIter == others.end()) {
            return nullptr;
        }

        return &(*otherIter);
    }
} /* namespace ThreeMotion */
