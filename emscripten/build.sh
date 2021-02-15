#!/bin/bash

# Make sure we have a 'build' folder.
if [ ! -d "build" ]; then
    mkdir build
fi

# Remove the 'out' folder if it exists.
if [ -d "out" ]; then
    rm -rf out
fi


# Hop into the 'build' folder
cd build

# build project -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=~/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake
rm -rf CMakeCache.txt CMakeFiles/
emcmake cmake ..
emmake make
