cmake_minimum_required(VERSION 3.5)
project(Divisaction)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(Actions Agents Exceptions Extra Stages)

set(SOURCE_FILES Action.cpp Action.h Agent.cpp Agent.h Emotion.cpp Emotion.h Event.cpp Event.h Executable.h
        Looper.cpp Looper.h Stage.cpp Stage.h StageType.h WorldManager.cpp WorldManager.h
        Actions/LongWalk.cpp Actions/LongWalk.h Agents/SingleActionAgent.cpp Agents/SingleActionAgent.h
        Agents/SingleReplyAgent.cpp Agents/SingleReplyAgent.h Exceptions/InvalidArgumentException.h
        Exceptions/NullPointerException.h Extra/StdExtras.cpp Extra/StdExtras.h Extra/Time.cpp Extra/Time.h
        Extra/Examples.cpp Extra/Examples.h Stages/TimeProgressiveStage.cpp Stages/TimeProgressiveStage.h)
add_library(Divisaction SHARED ${SOURCE_FILES})
