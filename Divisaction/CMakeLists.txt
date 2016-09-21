cmake_minimum_required(VERSION 3.5)
project(Divisaction)

find_package(Doxygen)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g3 -O0 -fPIC -Wuninitialized -std=c++14")

include_directories(Actions Agents Exceptions Extra Stages Emotions Events)

set(SOURCE_FILES
        WorldManager.cpp WorldManager.h
        IAgent.h
        Action.cpp Action.h
        Agent.cpp Agent.h
        Emotion.cpp Emotion.h
        Event.cpp Event.h
        Executable.h Executable.cpp
        TimeCalculator.h
        StageType.h
        Stage.cpp Stage.h
        Time.cpp Time.h
        MentalRepresentation.h MentalRepresentation.cpp
        Extra/Looper.cpp Extra/Looper.h
        Actions/Actions.cpp Actions/Actions.h
        Emotions/Emotions.cpp Emotions/Emotions.h
        Agents/SingleActionAgent.cpp Agents/SingleActionAgent.h
        Agents/SingleReplyAgent.cpp Agents/SingleReplyAgent.h
        Agents/CoopSceneBob.cpp Agents/CoopSceneBob.h
        Agents/CoopSceneHanna.cpp Agents/CoopSceneHanna.h
        Exceptions/InvalidArgumentException.h
        Exceptions/NullPointerException.h
        Extra/StdExtras.cpp Extra/StdExtras.h
        Extra/Examples.cpp Extra/Examples.h
        Stages/TimeProgressiveStage.cpp Stages/TimeProgressiveStage.h
        Extra/ChronoTimeCalculator.cpp Extra/ChronoTimeCalculator.h
        Events/ActionEvent.cpp Events/ActionEvent.h
        Events/EmotionEvent.cpp Events/EmotionEvent.h
        MentalState.cpp MentalState.h
        Divisaction.h
        DivisactionExtras.h
        MentalRepresentations/SelfMentalRepresentation.cpp MentalRepresentations/SelfMentalRepresentation.h
        MentalRepresentations/OtherMentalRepresentation.cpp MentalRepresentations/OtherMentalRepresentation.h
        DModule.cpp DModule.h
        Module.h
        Modules/DelayPerceive.cpp Modules/DelayPerceive.h
        Modules/Perform.cpp Modules/Perform.h
        Modules/SingleActionDecide.cpp Modules/SingleActionDecide.h
        Modules/SingleEmotionReact.cpp Modules/SingleEmotionReact.h
        Modules/SingleReplyReact.cpp Modules/SingleReplyReact.h
        Modules/ReplyReact.cpp Modules/ReplyReact.h
        Modules/CoopSceneBobReact.cpp Modules/CoopSceneBobReact.h
        Modules/CoopSceneHannaReact.cpp Modules/CoopSceneHannaReact.h
        Modules/CoopSceneHannaDecide.cpp Modules/CoopSceneHannaDecide.h
        Modules/DelayedDecide.cpp Modules/DelayedDecide.h
        TimeUtils/DTimer.cpp TimeUtils/DTimer.h
        TimeUtils/DTimerWait.cpp TimeUtils/DTimerWait.h
        TimeUtils/DTimerIfWait.cpp TimeUtils/DTimerIfWait.h
        TimeUtils/DTimerManager.cpp TimeUtils/DTimerManager.h
        Modules/CoopSceneBobDecide.cpp Modules/CoopSceneBobDecide.h Extra/NoAnticipationExample/NoAnticipationActions.cpp Extra/NoAnticipationExample/NoAnticipationActions.h)

add_library(Divisaction SHARED ${SOURCE_FILES})

if (DOXYGEN_FOUND)

    set(DOXYGEN_INPUT ${CMAKE_CURRENT_SOURCE_DIR}/project-Divisaction.cfg)
    set(DOXYFILE ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${DOXYGEN_INPUT} ${DOXYFILE} @ONLY)

    add_custom_target(apidoc
            COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation...\n"
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE}
            COMMAND ${CMAKE_COMMAND} -E echo "Done."
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            DEPENDS ${DOXYGEN_INPUT}
            )

    add_custom_target(apidoc_forced
            COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation...\n"
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE}
            COMMAND ${CMAKE_COMMAND} -E echo "Done."
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            )

endif (DOXYGEN_FOUND)