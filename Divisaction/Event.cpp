/*
 * File Event.cpp in project Divisaction
 * 
 * Copyright (C) ricardo 2016 - All Rights Reserved
 */

#include "Event.h"

namespace Divisaction {

    Event::Event() {
        type = Type::ACTION;
        sender = nullptr;
        action = nullptr;
        emotion = nullptr;
        reply = nullptr;
    }

    Event::Event(Type type, class Agent* sender) :
            Event::Event() {
        this->type = type;
        this->sender = sender;
    }

    // Action
    Event::Event(Type type, class Agent* sender, class Action* action) :
            Event::Event(type, sender) {
        this->action = action;
    }

    // Emotion
    Event::Event(Type type, class Agent* sender, class Emotion* emotion) :
            Event::Event(type, sender) {
        this->emotion = emotion;
    }

    // Reply
    Event::Event(Type type, class Agent* sender, class Emotion* emotion, Event reply) :
            Event::Event(type, sender, emotion) {
        CopyReply(reply);
    }

    Event::Event(const Event &event) : type(event.type), sender(event.sender), action(event.action),
                                       emotion(event.emotion) {
        if (event.reply && event.reply != nullptr) {
            CopyReply(*event.reply);
        } else {
            reply = nullptr;
        }
    }

    void Event::CopyReply(Event &reply) {
        this->reply = (Event*) malloc(sizeof(reply));
        memcpy(this->reply, &reply, sizeof(reply));
    }

    Event::~Event() {
        if (reply) {
            free(reply);
        }
    }

    Event &Event::operator=(const Event &event) {
        type = event.type;
        sender = event.sender;
        emotion = event.emotion;
        action = event.action;
        if (event.reply && event.reply != nullptr) {
            CopyReply(*event.reply);
        } else {
            reply = nullptr;
        }
        return *this;
    }

} /* namespace Divisaction */
