cmake_minimum_required(VERSION 3.6)
project(ThreeMotion)

find_package(Doxygen)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# setting the c++ compiler like this doesn't seem to work...
# see this page: https://stackoverflow.com/questions/30399654/how-to-switch-between-gcc-and-clang-in-clion-from-within-cmakelists-txt-using-wi
# -D CMAKE_C_COMPILER=/usr/bin/clang -D CMAKE_CXX_COMPILER=/usr/bin/clang++
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    message(STATUS "CLang Compiler")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic -Wuninitialized")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message(STATUS "GCC Compiler")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic -g3 -Og -Wuninitialized")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ofast")
endif ()

include_directories(Actions Agents Exceptions Extra Stages Emotions Events)

set(SOURCE_FILES
        TWorldManager.cpp TWorldManager.h
        TIAgent.h
        TAction.cpp TAction.h
        TAgent.cpp TAgent.h
        TEmotion.cpp TEmotion.h
        TEvent.cpp TEvent.h
        TExecutable.h TExecutable.cpp
        TITimeCalculator.h
        TStageType.h
        TStage.cpp TStage.h
        TTime.cpp TTime.h
        TMentalState.cpp TMentalState.h
        Extra/StdExtras.h
        Extra/TTimeProgressiveStage.cpp Extra/TTimeProgressiveStage.h
        Extra/TChronoTimeCalculator.cpp Extra/TChronoTimeCalculator.h
        Events/TActionEvent.cpp Events/TActionEvent.h
        Events/TEmotionEvent.cpp Events/TEmotionEvent.h
        TTheoryOfMind.cpp TTheoryOfMind.h
        ThreeMotion.h
        MentalStates/TSelfMentalState.cpp MentalStates/TSelfMentalState.h
        MentalStates/TOtherMentalState.cpp MentalStates/TOtherMentalState.h
        TModule.h
        Extra/IModule.h
        Modules/DDelayPerceive.cpp Modules/DDelayPerceive.h
        Modules/DPerform.cpp Modules/DPerform.h
        Modules/DSingleActionDecide.cpp Modules/DSingleActionDecide.h
        Modules/DSingleEmotionReact.cpp Modules/DSingleEmotionReact.h
        Modules/DSingleReplyReact.cpp Modules/DSingleReplyReact.h
        Modules/DReplyReact.cpp Modules/DReplyReact.h
        Modules/DDelayedDecide.cpp Modules/DDelayedDecide.h
        TimeUtils/TTimer.cpp TimeUtils/TTimer.h
        TimeUtils/TTimerWait.cpp TimeUtils/TTimerWait.h
        TimeUtils/TTimerIfWait.cpp TimeUtils/TTimerIfWait.h
        TimeUtils/TTimerManager.cpp TimeUtils/TTimerManager.h
        Extra/TSimpleTimeCalculator.cpp Extra/TSimpleTimeCalculator.h
        TDefine.h)

add_library(ThreeMotion SHARED ${SOURCE_FILES})

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

add_custom_target(UE4PLUGIN
        COMMAND cd ${PROJECT_SOURCE_DIR} && find . -name '*.h' -o -name '*.cpp' | cpio -updm ../ThreeMotionIntegration/Source/ThreeMotionIntegration/Public/
        )

