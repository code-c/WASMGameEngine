cmake_minimum_required(VERSION 3.17)
project(FernQuest)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

message(STATUS "start running cmake...")

find_package(Boost REQUIRED serialization system filesystem COMPONENTS serialization system filesystem)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

add_executable(FernQuest src/FernQuest.cpp
        src/Item.cpp src/Item.h
        src/Player.cpp src/Player.h
        src/Game.cpp src/Game.h
        src/QuestLog.cpp src/QuestLog.h
        src/Entity.cpp src/Entity.h
        src/Key.cpp src/Key.h
        src/Chest.cpp src/Chest.h
        src/Bridge.cpp src/Bridge.h)


if(Boost_FOUND)
    if (${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
        if(JS_ONLY)
            message(STATUS "Setting compilation target to native JavaScript")
            set(CMAKE_EXECUTABLE_SUFFIX ".js")
            set_target_properties(FernQuest PROPERTIES COMPILE_FLAGS "-s USE_BOOST_HEADERS=1" LINK_FLAGS "-s USE_BOOST_HEADERS=1 -s WASM=0 -s EXPORTED_FUNCTIONS='[_main]'")
        else(JS_ONLY)
            message(STATUS "Setting compilation target to WASM")
            set(CMAKE_EXECUTABLE_SUFFIX ".wasm.js")
            set_target_properties(FernQuest PROPERTIES COMPILE_FLAGS "-s USE_BOOST_HEADERS=1" LINK_FLAGS " -s USE_BOOST_HEADERS=1 -s WASM=1 -s EXPORTED_FUNCTIONS='[_main]'")
        endif(JS_ONLY)
    else()
        target_link_libraries(FernQuest)
        target_link_libraries(FernQuest ${Boost_LIBRARIES})
    endif ()
endif()
