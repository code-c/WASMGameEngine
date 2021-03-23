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
    	../src/QuestLog.h
		../src/Entity.cpp
		../src/Entity.h)


SET(CMAKE_C_COMPILER emcc)
SET(CMAKE_CPP_COMPILER em++)


add_executable(FernQuest ${FQ_SRCS})

if(JS_ONLY)
message(STATUS "Setting compilation target to native JavaScript")
set(CMAKE_EXECUTABLE_SUFFIX ".js")
set_target_properties(FernQuest PROPERTIES COMPILE_FLAGS "-s USE_BOOST_HEADERS=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0" LINK_FLAGS "-s USE_BOOST_HEADERS=1 -s WASM=0 -s EXPORTED_FUNCTIONS='[_main]' -s ERROR_ON_UNDEFINED_SYMBOLS=0")
else(JS_ONLY)
message(STATUS "Setting compilation target to WASM")
set(CMAKE_EXECUTABLE_SUFFIX ".js")
set_target_properties(FernQuest PROPERTIES COMPILE_FLAGS "-s USE_BOOST_HEADERS=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0" LINK_FLAGS " -s USE_BOOST_HEADERS=1 -s WASM=1 -s EXPORTED_FUNCTIONS='[_main]' -s ERROR_ON_UNDEFINED_SYMBOLS=0")
endif(JS_ONLY)
