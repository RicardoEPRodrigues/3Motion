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

set(SOURCE_FILES
        Source/TWorldManager.cpp Source/TWorldManager.h
        Source/TIAgent.h
        Source/TAction.cpp Source/TAction.h
        Source/TAgent.cpp Source/TAgent.h
        Source/TEmotion.cpp Source/TEmotion.h
        Source/TEvent.cpp Source/TEvent.h
        Source/TExecutable.h Source/TExecutable.cpp
        Source/TITimeCalculator.h
        Source/TStageType.h
        Source/TStage.cpp Source/TStage.h
        Source/TTime.cpp Source/TTime.h
        Source/TMentalState.cpp Source/TMentalState.h
        Source/Extra/StdExtras.h
        Source/Extra/TTimeProgressiveStage.cpp Source/Extra/TTimeProgressiveStage.h
        Source/Extra/TChronoTimeCalculator.cpp Source/Extra/TChronoTimeCalculator.h
        Source/Events/TActionEvent.cpp Source/Events/TActionEvent.h
        Source/Events/TEmotionEvent.cpp Source/Events/TEmotionEvent.h
        Source/TTheoryOfMind.cpp Source/TTheoryOfMind.h
        Source/ThreeMotion.h
        Source/MentalStates/TSelfMentalState.cpp Source/MentalStates/TSelfMentalState.h
        Source/MentalStates/TOtherMentalState.cpp Source/MentalStates/TOtherMentalState.h
        Source/TModule.h
        Source/Extra/IModule.h
        Source/Modules/DDelayPerceive.cpp Source/Modules/DDelayPerceive.h
        Source/Modules/DPerform.cpp Source/Modules/DPerform.h
        Source/Modules/DSingleActionDecide.cpp Source/Modules/DSingleActionDecide.h
        Source/Modules/DSingleEmotionReact.cpp Source/Modules/DSingleEmotionReact.h
        Source/Modules/DSingleReplyReact.cpp Source/Modules/DSingleReplyReact.h
        Source/Modules/DReplyReact.cpp Source/Modules/DReplyReact.h
        Source/Modules/DDelayedDecide.cpp Source/Modules/DDelayedDecide.h
        Source/TimeUtils/TTimer.cpp Source/TimeUtils/TTimer.h
        Source/TimeUtils/TTimerWait.cpp Source/TimeUtils/TTimerWait.h
        Source/TimeUtils/TTimerIfWait.cpp Source/TimeUtils/TTimerIfWait.h
        Source/TimeUtils/TTimerManager.cpp Source/TimeUtils/TTimerManager.h
        Source/Extra/TSimpleTimeCalculator.cpp Source/Extra/TSimpleTimeCalculator.h
        Source/TDefine.h)

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

