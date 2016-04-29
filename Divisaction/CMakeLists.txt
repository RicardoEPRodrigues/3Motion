cmake_minimum_required(VERSION 3.5)
project(Divisaction)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g3 -O0 -fPIC -std=c++14")

include_directories(Actions Agents Exceptions Extra Stages Emotions)

set(SOURCE_FILES Action.cpp Action.h Agent.cpp Agent.h Emotion.cpp Emotion.h Event.cpp Event.h Executable.h
        Extra/Looper.cpp Extra/Looper.h Stage.cpp Stage.h StageType.h WorldManager.cpp WorldManager.h
        Actions/LongWalk.cpp Actions/LongWalk.h Agents/SingleActionAgent.cpp Agents/SingleActionAgent.h
        Agents/SingleReplyAgent.cpp Agents/SingleReplyAgent.h Agents/InteractiveReplyAgent.cpp Agents/InteractiveReplyAgent.h
        Exceptions/InvalidArgumentException.h Exceptions/NullPointerException.h Extra/StdExtras.cpp Extra/StdExtras.h Time.cpp Time.h
        Extra/Examples.cpp Extra/Examples.h Stages/TimeProgressiveStage.cpp Stages/TimeProgressiveStage.h TimeCalculator.h
        Extra/ChronoTimeCalculator.cpp Extra/ChronoTimeCalculator.h Emotions/Confidence.cpp Emotions/Confidence.h IAgent.h)

add_library(Divisaction SHARED ${SOURCE_FILES})
