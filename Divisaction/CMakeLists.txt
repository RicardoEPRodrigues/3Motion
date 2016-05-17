cmake_minimum_required(VERSION 3.5)
project(Divisaction)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g3 -O0 -fPIC -Wuninitialized -std=c++14")

include_directories(Actions Agents Exceptions Extra Stages Emotions Events)

set(SOURCE_FILES
        WorldManager.cpp WorldManager.h
        IAgent.h
        Action.cpp Action.h
        Agent.cpp Agent.h
        Emotion.cpp Emotion.h
        Event.cpp Event.h
        Executable.h
        TimeCalculator.h
        StageType.h
        Stage.cpp Stage.h
        Time.cpp Time.h
        MentalRepresentation.h
        Extra/Looper.cpp Extra/Looper.h
        Actions/LongWalk.cpp Actions/LongWalk.h
        Agents/SingleActionAgent.cpp Agents/SingleActionAgent.h
        Agents/SingleReplyAgent.cpp Agents/SingleReplyAgent.h
        Exceptions/InvalidArgumentException.h
        Exceptions/NullPointerException.h
        Extra/StdExtras.cpp Extra/StdExtras.h
        Extra/Examples.cpp Extra/Examples.h
        Stages/TimeProgressiveStage.cpp Stages/TimeProgressiveStage.h
        Extra/ChronoTimeCalculator.cpp Extra/ChronoTimeCalculator.h
        Emotions/Confidence.cpp Emotions/Confidence.h
        Events/ActionEvent.cpp Events/ActionEvent.h
        Events/EmotionEvent.cpp Events/EmotionEvent.h
        Events/ReplyEvent.cpp Events/ReplyEvent.h
        MentalState.cpp MentalState.h)

add_library(Divisaction SHARED ${SOURCE_FILES})
