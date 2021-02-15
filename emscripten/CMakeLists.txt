cmake_minimum_required(VERSION 3.17)
project(FernQuest) #emscripten version

if (${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
	message(STATUS "using emscripten")
endif ()
if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
	message(STATUS "using cmake")
endif ()

#options
option(JS_ONLY "Compiles to native JS (No WASM)" OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out)

include_directories(.)
include_directories(/usr/local/include) #where boost in located

message(STATUS "finding boost!")
find_package(Boost 1.74.0 REQUIRED serialization system filesystem COMPONENTS serialization system filesystem)

if(Boost_FOUND)
    message(STATUS "found boost!")
endif()

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

message(STATUS "setting sources")
SET(FQ_SRCS
    ../src/FernQuest.cpp
    ../src/Item.cpp
    ../src/Item.h
    ../src/Player.cpp
    ../src/Player.h
    ../src/Game.cpp
    ../src/Game.h
    ../src/QuestLog.cpp
    ../src/QuestLog.h)


SET(CMAKE_C_COMPILER emcc)
SET(CMAKE_CPP_COMPILER em++)


add_executable(FernQuest ${FQ_SRCS})


if(Boost_FOUND)
  if(JS_ONLY)
  	message(STATUS "Setting compilation target to native JavaScript")
  	set(CMAKE_EXECUTABLE_SUFFIX ".js")
  	set_target_properties(FernQuest PROPERTIES COMPILE_FLAGS "-s USE_BOOST_HEADERS=1" LINK_FLAGS "-s USE_BOOST_HEADERS=1 -s WASM=0 -s EXPORTED_FUNCTIONS='[_main]'")
  else(JS_ONLY)
  	message(STATUS "Setting compilation target to WASM")
  	set(CMAKE_EXECUTABLE_SUFFIX ".wasm.js")
  	set_target_properties(FernQuest PROPERTIES COMPILE_FLAGS "-s USE_BOOST_HEADERS=1" LINK_FLAGS " -s USE_BOOST_HEADERS=1 -s WASM=1 -s EXPORTED_FUNCTIONS='[_main]'")
  endif(JS_ONLY)
endif()
