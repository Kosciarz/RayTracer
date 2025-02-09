# RayTracer

A Ray Tracer written in C++. 

## Requirements

- [Git](https://git-scm.com/)
- [CMake](https://cmake.org/download/) version **3.25** or higher
- [RayLib requirements](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux)

## Build

1. Clone the repository with submodules
 
    ```
    git clone --depth=1 --recurse-submodules https://github.com/Kociarz/RayTracer.git
    ```

2. Bootrap the project

   - Windows
        ```
        .\bootstrap.bat
        ```
    
    - Linux
        ```
        chmod +x bootstrap.sh
        ./bootstrap.sh
        ```

3. Build the project
    
    ```
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ```

## What I learned from this project

- How to use raylib for opening windows and drawing stuff on the screen
- How to ray tracing works
