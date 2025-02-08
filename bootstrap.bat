echo off

echo "Initializing submodules"
call git submodule update --init --recursive

echo "Building raylib"
cd external/raylib
mkdir build
cd build
call cmake ..
call cmake --build . --config Release