/*
 * File Event.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Event.h"

namespace Divisaction {

    Event::Event() {
        type = EventType::ACTION;
        sender = nullptr;
        stageType = StageType::size;
        stage = nullptr;
        reply = nullptr;
    }

    Event::Event(EventType type, class Agent *sender) :
            Event::Event() {
        this->type = type;
        this->sender = sender;
    }

    Event::Event(EventType type, class Agent *sender, StageType stageType,
                 class Stage *stage) :
            Event::Event(type, sender) {
        this->stageType = stageType;
        this->stage = stage;
    }


    Event::Event(EventType type, class Agent *sender, StageType stageType, class Stage *stage, Event reply) :
            Event::Event(type, sender, stageType, stage) {
        CopyReply(reply);
    }

    Event::Event(const Event &event) : type(event.type), sender(event.sender), stageType(event.stageType),
                                       stage(event.stage) {
        if (event.reply && event.reply != nullptr) {
            CopyReply(*event.reply);
        } else {
            reply = nullptr;
        }
    }

    void Event::CopyReply(Event &reply) {
        this->reply = (Event *) malloc(sizeof(reply));
        memcpy(this->reply, &reply, sizeof(reply));
    }

    Event::~Event() {
        if (reply) {
            free(reply);
        }
    }

    Event& Event::operator=(const Event& event) {
        type = event.type;
        sender = event.sender;
        stageType = event.stageType;
        stage = event.stage;
        if (event.reply && event.reply != nullptr) {
            CopyReply(*event.reply);
        } else {
            reply = nullptr;
        }
        return *this;
    }

} /* namespace Divisaction */
