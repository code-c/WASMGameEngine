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

add_executable(FernQuest FernQuest.cpp
        Item.cpp Item.h
        Player.cpp Player.h
        Game.cpp Game.h
        QuestLog.cpp QuestLog.h)


if(Boost_FOUND)
    target_link_libraries(FernQuest)
    target_link_libraries(FernQuest ${Boost_LIBRARIES})

endif()
