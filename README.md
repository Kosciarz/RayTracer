# RayTracer

A Ray Tracer written in C++. 

## build and installation

1. Clone the repository with submodules
 
    ```
    git clone --recurse-submodules https://github.com/Kociarz/RayTracer.git
    ```

2. Bootrap the project

   - Windows
        ```
        ./bootstrap.bat
        ```
    
    - Linux
        ```
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

- How to use raylib for opening windows and drawing pixels
- How to ray tracing works
