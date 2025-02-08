#!/bin/sh

echo "Initializing submodules"
git submodule update --init --recursive

echo "Building raylib"
cd external/raylib
mkdir build
cd build
cmake ..
cmake --build . --config Release
